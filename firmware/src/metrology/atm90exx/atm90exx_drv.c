/*******************************************************************************
  Interface definition of ATM90EXX Driver.

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_drv.c

  Summary:
    Interface definition of the ATM90EXX Driver.

  Description:
    This file defines the interface for the ATM90EXX driver.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "definitions.h"
#include "../metrology_conf.h"
#include "../metrology_defs.h"
#include "../metrology_api.h"
#include "../metrology_api_events.h"
#include "atm90exx_conf.h"
#include "atm90exx_regs.h"
#include "atm90exx_defs.h"
#include "atm90exx_api.h"
#include "atm90exx_api_events.h"
#include "atm90exx_drv.h"
#include "atm90exx_hal.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

/* This is the driver instance object */
ATM90EXX_DRV_OBJ CACHE_ALIGN gATM90ExxDrvObj;
ATM90EXX_CONF CACHE_ALIGN atm90ExxObjDfltConf;
METROLOGY_API_EVENTS atm90ExxEvents;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_TEST_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static bool ATM90EXX_DRV_TaskDelay(uint32_t mseg, SYS_TIME_HANDLE* handle)
{
    // Check if there is the timer has been created and running
    if (*handle == SYS_TIME_HANDLE_INVALID)
    {
        // Create timer
        if (SYS_TIME_DelayMS(mseg, handle) != SYS_TIME_SUCCESS)
        {
            return false;
        }
    }
    else
    {
        // Check timer
        if (SYS_TIME_DelayIsComplete(*handle) == true)
        {
            *handle = SYS_TIME_HANDLE_INVALID;
            return true;
        }
    }

    return false;
}

#ifdef ATM90E3X_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E3X_DRV_set_PowerMode ( ATM90E3X_POWER_MODE_STATES pm )

  Remarks:
    Set ATM90E3X power mode.
 */
ATM90EXX_DRV_RESULT ATM90E3X_DRV_set_PowerMode(ATM90E3X_POWER_MODE_STATES pm)
{
#ifdef ATM90E3X_HAL_PMX_PIO_SUPPORT   
  ATM90E3X_HAL_set_PowerMode(pm);
  gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.PM = pm;
#endif
  return ATM90EXX_DRV_SUCCESS;
}
#endif

#ifdef ATM90E36_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E36_DRV_ConfigureTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E3X_DRV_set_DMACtrlMode(ATM90E36_DMA_MODE mode, uint16_t dmactrl)
{
  if (mode == ATM90E3X_DMA_MODE_ON)
  {
    // First need to write DMACTRL register
    ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, DMACTRL_ADDR, dmactrl);
  }
#ifdef ATM90E3X_HAL_DMACTRL_PIO_SUPPORT   
  ATM90E3X_HAL_set_DMACtrlMode(mode);
#endif
  return ATM90EXX_DRV_SUCCESS;
}
#endif

#ifdef ATM90EXX_IRQ_SUPPORT
#if defined(ATM90EXX_IRQ_COMMON_SUPPORT) 
/*******************************************************************************
  Function:
    static void _ATM90EXX_DRV_Int_Callback ( uintptr_t context )

  Remarks:
    Different Information depending on ATM90Exx - Only 1 HW Interrupt Line IRQ0
        - ATM90E26: corresponds with pin IRQ, WarnOut => SysStatus Register need to be read  -  Events
        - ATM90E32: corresponds with pin IRQ0, IRQ1, WarnOut => EMMIntState0-1 Register need to be read
        - ATM90E36: corresponds with pin IRQ0, IRQ1, WarnOut => SysStatus0,  Register need to be read - Events
 */
void _ATM90EXX_DRV_Int_Callback ( uintptr_t context )
{
    /* Same Operations at Driver Level independently of interrupt IRQ0, IRQ1, WarnOut */
    gATM90ExxDrvObj.interruptFlag = true;
    gATM90ExxDrvObj.interrupts++;

    /* Operations at Application Level */
    //if ((gATM90ExxDrvObj.interruptCallback != NULL))
    //{
    //    gATM90ExxDrvObj.interruptCallback(gATM90ExxDrvObj.interruptContext);
    //}
}
#else
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
/*******************************************************************************
  Function:
    static void _ATM90EXX_DRV_Irq0Int_Callback ( uintptr_t context )

  Remarks:
    Different Information depending on ATM90Exx
        - ATM90E26: corresponds with pin IRQ => SysStatus Register need to be read  -  Events
        - ATM90E32: corresponds with pin IRQ0 => EMMIntState0 Register need to be read
        - ATM90E36: corresponds with pin IRQ0 => SysStatus0 Register need to be read - Events
 */
static void _ATM90EXX_DRV_Irq0Int_Callback ( uintptr_t context )
{
    /* Operations at Driver Level */
    gATM90ExxDrvObj.int0InterruptFlag = true;
    //gATM90ExxDrvObj.int0Interrupts++;
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[ATM90EXX_DRV] IRQ0 Interrupt\r\n");

    /* Operations at Application Level */
    //if ((gATM90ExxDrvObj.interruptCallback != NULL))
    //{
    //   gATM90ExxDrvObj.interruptCallback(gATM90ExxDrvObj.interruptContext);
    //}
}
#endif

#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
/*******************************************************************************
  Function:
    static void lATM90Exx_DRV_Irq1Int_Handler ( uintptr_t context )

  Remarks:
    Different Information depending on ATM90Exx
        - ATM90E26: doesn't exist
        - ATM90E32: corresponds with pin IRQ1 => EMMIntState1 Register need to be read
        - ATM90E36: corresponds with pin IRQ1 => SysStatus1 Register need to be read - Events
 */
static void _ATM90Exx_DRV_Irq1Int_Callback ( uintptr_t context )
{
    gATM90ExxDrvObj.int1InterruptFlag = true;
    gATM90ExxDrvObj.int1Interrupts++;
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[ATM90EXX_DRV] IRQ1 Interrupt\r\n");

    /* Operations at Application Level */
    //if ((gATM90ExxDrvObj.interruptCallback != NULL))
    //{
    //  gATM90ExxDrvObj.interruptCallback(gATM90ExxDrvObj.interruptContext);
    //}
}
#endif

#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
/*******************************************************************************
  Function:
    static void lATM90Exx_DRV_WarnoutInt_Handler ( uintptr_t context )

  Remarks:
    Different Information depending on ATM90Exx
        - ATM90E26: corresponds with pin WARNOUT => SysStatus0 Register need to be read - Internal + Checksum Errors
        - ATM90E32: corresponds with pin WARNOUT => Internal + Checksum Errors - Could be ORed with INT0 -> IRQ0MergeCfg register
        - ATM90E36: corresponds with pin WARNOUT => SysStatus0 Register need to be read - Internal + Checksum Errors
 */
static void _ATM90EXX_DRV_WarnOutInt_Callback ( uintptr_t context )
{
    gATM90ExxDrvObj.warnoutInterruptFlag = true;
    gATM90ExxDrvObj.warnoutInterrupts++;
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[ATM90EXX_DRV] WarnOut Interrupt\r\n");

    /* Operations at Application Level */
    //if ((gATM90ExxDrvObj.interruptCallback != NULL))
    //{
    //  gATM90ExxDrvObj.interruptCallback(gATM90ExxDrvObj.interruptContext);
    //}
}
#endif
#endif
#endif

/*******************************************************************************
  Function:
    SYS_MODULE_OBJ DRIVER_ATM90EXX_Initialize ( void )

  Remarks:
    See prototype in app_test.h.
 */

SYS_MODULE_OBJ ATM90EXX_DRV_Init(SYS_MODULE_INIT * init, uint32_t resetCause)
{
    /* MISRA C-2012 deviation block start */
    /* MISRA C-2012 Rule 11.3 deviated once. Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    //ATM90EXX_DRV_INIT *atm90exxInit = (ATM90EXX_DRV_INIT *)init;
    /* MISRA C-2012 deviation block end */

    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][INIT]\r\n");

    
    //if ((gATM90ExxDrvObj.inUse == true) || (init == NULL))
    //{
    //    return SYS_MODULE_OBJ_INVALID;
    //}

    /* Initialization of the interface with Metrology Lib */
    gATM90ExxDrvObj.inUse = true;
    //gATM90ExxDrvObj.integrationCallback = NULL;

    /* Structures Initialization */
    (void) memset(&gATM90ExxDrvObj.atm90ExxObj.ctrlInfo, 0, sizeof(ATM90EXX_REGS_CONTROL));
    (void) memset(&gATM90ExxDrvObj.atm90ExxObj.thresholdInfo, 0, sizeof(ATM90EXX_REGS_THRESHOLDS));
    (void) memset(&gATM90ExxDrvObj.atm90ExxObj.statusInfo, 0, sizeof(ATM90EXX_REGS_STATUS));
    (void) memset(&gATM90ExxDrvObj.atm90ExxObj.measInfo, 0, sizeof(ATM90EXX_REGS_MEAS));
    (void) memset(&gATM90ExxDrvObj.atm90ExxObj.metInfo, 0, sizeof(ATM90EXX_REGS_MET));
    (void) memset(&gATM90ExxDrvObj.atm90ExxObj.calMeasInfo, 0, sizeof(ATM90EXX_REGS_CAL_MEAS));
    (void) memset(&gATM90ExxDrvObj.atm90ExxObj.calMetInfo, 0, sizeof(ATM90EXX_REGS_CAL_MET));

    /* Default Configuration */
    ATM90EXX_DRV_Init_DefaultConfig(&gATM90ExxDrvObj.atm90ExxObjConf);    
    /* Configure Full set of registers */
    gATM90ExxDrvObj.configureFlags = CONFIG_FLAG_ALL;
    /* Initialization of the Metrology Status  */
    gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_UNINITIALIZED;
    /* Initialization of the Metrology State  */
    gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_INIT;
    /* Initialization of the Timer for Delays  */
    gATM90ExxDrvObj.timer = SYS_TIME_HANDLE_INVALID;

#ifdef ATM90EXX_IRQ_SUPPORT
#ifdef ATM90EXX_IRQ_COMMON_SUPPORT
    /* All the interrupts managed at the same time */
    gATM90ExxDrvObj.interruptFlag = false;   
#endif
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT    
#ifdef ATM90EXX_IRQ_COMMON_SUPPORT
    /* All the interrupts managed at the same time */
    ATM90EXX_HAL_Set_Irq0Int_Handler(_ATM90EXX_DRV_Int_Callback, (uintptr_t)NULL);
#else 
    /* Interrupts managed independently */
    /* Clean the IRQ0 interrupt flags */
    gATM90ExxDrvObj.int0InterruptFlag = false;
    ATM90EXX_HAL_Set_Irq0Int_Handler(_ATM90EXX_DRV_Irq0Int_Callback, (uintptr_t)NULL);
#endif
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT   
#ifdef ATM90EXX_IRQ_COMMON_SUPPORT
    /* All the interrupts managed at the same time */
    ATM90EXX_HAL_Set_Irq1Int_Handler(_ATM90EXX_DRV_Int_Callback, (uintptr_t)NULL);
#else 
    /* Clean the IRQ1 interrupt flags */
    gATM90ExxDrvObj.int1InterruptFlag = false;
    ATM90Exx_HAL_Set_Irq1Int_Handler(_ATM90EXX_DRV_Irq1Int_Callback, (uintptr_t)NULL);
#endif  
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT    
#ifdef ATM90EXX_IRQ_COMMON_SUPPORT
    ATM90Exx_HAL_Set_WarnOut_Handler(_ATM90EXX_DRV_Int_Callback, (uintptr_t)NULL);
#else 
    ATM90Exx_HAL_Set_WarnOut_Handler(_ATM90EXX_DRV_WarnOutInt_Callback, (uintptr_t)NULL);
#endif
#endif
#endif

    /* Clean the Start Integration Period flag */
    gATM90ExxDrvObj.startFlag = false;
    
	/* Clean the Integration Period interrupt flags */
    gATM90ExxDrvObj.integrationFlag = false;

    /* Initialize the HAL to access ATM90Exx */
    ATM90EXX_HAL_Init();

    return (SYS_MODULE_OBJ)&gATM90ExxDrvObj;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT DRV_ATM90EXX_Close ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Open (ATM90EXX_DRV_START_MODE mode, ATM90EXX_CONF *pConf)
{
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][OPEN]\r\n");

    /* Update Driver state */
    gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_UNINITIALIZED;
    
    if (pConf != NULL)
    {
        /* Store the configuration to be sent to ATM90EXX */
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.ctrlInfo, &pConf->ctrlInfo, sizeof(ATM90EXX_REGS_CONTROL));
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.thresholdInfo, &pConf->thresholdInfo, sizeof(ATM90EXX_REGS_THRESHOLDS));
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.calMeasInfo, &pConf->calMeasInfo, sizeof(ATM90EXX_REGS_CAL_MEAS));
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.calMetInfo, &pConf->calMetInfo, sizeof(ATM90EXX_REGS_CAL_MET));
    }
    else
    {
        /* Default Configuration - Obtained from Default Config */
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][OPEN] - Dflt Conf\r\n");
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.ctrlInfo, &gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo, sizeof(ATM90EXX_REGS_CONTROL));
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.thresholdInfo, &gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo, sizeof(ATM90EXX_REGS_THRESHOLDS));
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.calMeasInfo, &gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo, sizeof(ATM90EXX_REGS_CAL_MEAS));
        memcpy(&gATM90ExxDrvObj.atm90ExxObj.calMetInfo, &gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo, sizeof(ATM90EXX_REGS_CAL_MET));
    }
    /* Open the HAL to access the ATM90EXX */
    gATM90ExxDrvObj.handle = ATM90EXX_HAL_Open();
    if (gATM90ExxDrvObj.handle == DRV_HANDLE_INVALID)
    {
        return ATM90EXX_DRV_ERROR;
    }
    
    /* ATM90EXX Driver Tasks - Initialize Registers */
    gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CONFIGURE;
    gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_CONFIGURING;

    return ATM90EXX_DRV_SUCCESS;
}

ATM90EXX_DRV_RESULT ATM90EXX_DRV_Reconfigure (ATM90EXX_CONF *config)
{
    // Stop Integration Period Periodic Timer
    ATM90EXX_HAL_stop_integration_period(gATM90ExxDrvObj.integrationPeriodHandle);
    memcpy(&gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo,&config->ctrlInfo, sizeof(ATM90EXX_REGS_CONTROL));
    memcpy(&gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo, &config->thresholdInfo, sizeof(ATM90EXX_REGS_THRESHOLDS));
    memcpy(&gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo, &config->calMeasInfo, sizeof(ATM90EXX_REGS_CAL_MEAS));
    memcpy(&gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo, &config->calMetInfo, sizeof(ATM90EXX_REGS_CAL_MET));
    
    //gATM90ExxDrvObj.status = ATM90EXX_DRV_STATUS_CONFIGURING;
    gATM90ExxDrvObj.configureFlags = CONFIG_FLAG_ALL;
    gATM90ExxDrvObj.reconfigureFlag = true;
    return ATM90EXX_DRV_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_Stop ( void )

  Remarks:TAM
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Stop (void)
{
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][Stop]\r\n");
    /* Update Driver state */
    
    ATM90EXX_HAL_stop_integration_period(gATM90ExxDrvObj.integrationPeriodHandle);
    gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_STOP;

    return ATM90EXX_DRV_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT DRV_ATM90EXX_Close ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Close (void)
{
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][Close]\r\n");
    /* Update Driver state */
    gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_UNINITIALIZED;
    
    ATM90EXX_HAL_Close(gATM90ExxDrvObj.handle);

    return ATM90EXX_DRV_SUCCESS;
}

ATM90EXX_DRV_RESULT ATM90EXX_DRV_EventCallbackRegister ( ATM90EXX_DRV_EVENT_CALLBACK callback )
{
    if (callback == NULL)
    {
        return ATM90EXX_DRV_ERROR;
    }

    gATM90ExxDrvObj.eventCallback = callback;
    return ATM90EXX_DRV_SUCCESS;
}

ATM90EXX_DRV_RESULT ATM90EXX_DRV_IntegrationCallbackRegister ( ATM90EXX_DRV_INTEGRATION_CALLBACK callback )
{
    if (callback == NULL)
    {
        return ATM90EXX_DRV_ERROR;
    }

    gATM90ExxDrvObj.integrationCallback = callback;
    return ATM90EXX_DRV_SUCCESS;
}

#ifdef ATM90EXX_CALIBRATION_SUPPORT
ATM90EXX_DRV_RESULT ATM90EXX_DRV_CalibrationCallbackRegister ( ATM90EXX_DRV_CALIBRATION_CALLBACK callback )
{
    if (callback == NULL)
    {
        return ATM90EXX_DRV_ERROR;
    }

    gATM90ExxDrvObj.calibrationCallback = callback;
    return ATM90EXX_DRV_SUCCESS;
}
#endif

/*******************************************************************************
  Function:
    void DRV_ATM90EXX_IntegrationPeriodCallback ( TC_TIMER_STATUS status, uintptr_t context )

  Remarks:
    
 */
static void ATM90EXX_DRV_IntegrationPeriodCallback(uintptr_t context)
{
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][IPC]\r\n");

    // Enable Integration Flag - To be considered in the task 
    gATM90ExxDrvObj.integrationFlag = true;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT DRV_ATM90EXX_Start ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Start(uint32_t period_ms)
{
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][Start]\r\n");
    
    // Configure callback and Start the Periodic Integration Period 
    gATM90ExxDrvObj.integrationPeriod = period_ms;
    gATM90ExxDrvObj.integrationPeriodHandle = ATM90EXX_HAL_start_integration_period(gATM90ExxDrvObj.integrationPeriod, ATM90EXX_DRV_IntegrationPeriodCallback, (uintptr_t) NULL);
    if (gATM90ExxDrvObj.integrationPeriodHandle != SYS_TIME_HANDLE_INVALID)
    {
        // Start Integration Period Mechanism
        //ATM90EXX_HAL_enable_integration_period();
        gATM90ExxDrvObj.startFlag = true; 
        gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_RUNNING;
        return ATM90EXX_DRV_SUCCESS;
    }    

#if 0    
    if (gATM90ExxDrvObj.metRegisters->MET_STATUS.STATUS == STATUS_STATUS_READY)
    {
        /* Set Metrology Lib state as Run */
        gDrvMetObj.metRegisters->MET_CONTROL.STATE_CTRL = STATE_CTRL_STATE_CTRL_RUN_Val;
        /* Wait until the metrology running */
        while (gDrvMetObj.metRegisters->MET_STATUS.STATUS != STATUS_STATUS_DSP_RUNNING)
        {
        }
        gDrvMetObj.status = DRV_METROLOGY_STATUS_RUNNING;

        return ATM90EXX_DRV_SUCCESS;
    }
#endif
    return ATM90EXX_DRV_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_Check_Type ( void )

  Remarks:
    NOT CHECKED!!!!.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Check_Type(ATM90EXX_TYPE type)
{
	uint16_t	value;
	uint16_t	addr;

#ifdef ATM90E2X_SUPPORT
  addr = ATM90E2X_CHIPID_ADDR
#else 
  addr = ATM90E2X_CHIPID_ADDR;
#endif
  if (ATM90EXX_HAL_read_reg( gATM90ExxDrvObj.handle, addr, &value))
  {
    SYS_DEBUG_PRINT(SYS_ERROR_DEBUG, "[ATM90EXX_DRV] ChipID addr=%0x04X, value=%0x04X\r\n", addr, value);

    switch(value)
    {
      case	AT90E25_CHIPID:
        if (ATM90EXX_HAL_read_reg( gATM90ExxDrvObj.handle, 0x0016, &value))
        {
          SYS_DEBUG_PRINT(SYS_ERROR_DEBUG, "ATM90EXX ChipID addr=%0x04X, value=%0x04X\r\n", addr, value);
        }  
        break;
      case AT90E36_CHIPID:

        break;
      case AT90E32A_CHIPID:

        break;
    }
  }

  if (type == value)
    return true;

  SYS_DEBUG_MESSAGE(SYS_ERROR_ERROR, "[ATM90EXX_DRV] ChipID error\r\n");
  return false;
}

#ifdef ATM90E26_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_Init_DefaultConfig ( void )

  Remarks:
    Default Configuration
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Init_DefaultConfig(ATM90EXX_CONF *conf)
{
  SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD] - Default Config\r\n");
  
  conf->ctrlInfo.UScale = SCALE_FACTOR_1; /* Default */
  conf->ctrlInfo.IScale = SCALE_FACTOR_1; /* Default */
  conf->ctrlInfo.MMDx = ATM90EXX_METERING_MODE_ANTI_TAMPER;            /* Default */
  conf->ctrlInfo.FuncEn = 0x000C;         /* Default */
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT  
  conf->ctrlInfo.FuncEn |= FUNCEN_SAGWO_Msk;
#endif  
#ifdef ATM90EXX_SAG_SUPPORT  
  conf->ctrlInfo.FuncEn |= FUNCEN_SAGEN_Msk;
#endif  
  conf->ctrlInfo.SmallPMod = 0x0000;      /* Default */
  conf->ctrlInfo.MMode = 0x9422;          /* Lgain=1, Ngain=1, L Line, All ZC, AntiTamper threshold 3.125%*/
#ifdef ATM90EXX_ZC_SUPPORT  
  conf->ctrlInfo.MMode &= (~MMODE_ZXCON_Msk); 
  conf->ctrlInfo.MMode |= MMODE_ZXCON_(MMODE_ZXCON_ALL_Val);
#else
  conf->ctrlInfo.MMode &= (~MMODE_ZXCON_Msk); 
  conf->ctrlInfo.MMode |= MMODE_ZXCON_(MMODE_ZXCON_DIS_Val);
#endif
  
  conf->ctrlInfo.CS1 = 0x1E74;            /* Calculated */
  conf->ctrlInfo.CS2 = 0xDBC1;            /* Calculated */

  conf->thresholdInfo.SagTh = 0x1D6A;     /* Default */
  conf->thresholdInfo.PStartTh = 0x08BD;  /* Default */
  conf->thresholdInfo.PNolTh = 0x0000;    /* Default */
  conf->thresholdInfo.QStartTh = 0x0AEC;  /* Default */
  conf->thresholdInfo.QNolTh = 0x0000;    /* Default */

  conf->calMetInfo.MC = 3200;             /* MC=3200 */
  conf->calMetInfo.PLconstH = 0x0010;     /* MC=3200 */
  conf->calMetInfo.PLconstL = 0x0000;     /* MC=3200 */
  conf->calMetInfo.Lgain = 0x050E;        /* Calibrated */
  conf->calMetInfo.Lphi = 0x0000;         /* Default */
  conf->calMetInfo.Ngain = 0x0000;        /* Default */
  conf->calMetInfo.Nphi = 0x0000;         /* Default */

  conf->calMeasInfo.Ugain = 0x67D6;       /* Calibrated */
  conf->calMeasInfo.IgainL = 0x55F8;      /* Calibrated */
  conf->calMeasInfo.IgainN = 0x3FF8;      /* Calibrated */
  conf->calMeasInfo.Uoffset = 0x0000;     /* Default */
  conf->calMeasInfo.IoffsetL = 0x0000;    /* Default */
  conf->calMeasInfo.IoffsetN = 0x0000;    /* Default */
  conf->calMeasInfo.PoffsetL = 0x0000;    /* Default */
  conf->calMeasInfo.QoffsetL = 0x0000;    /* Default */
  conf->calMeasInfo.PoffsetN = 0x0000;    /* Default */
  conf->calMeasInfo.QoffsetN = 0x0000;    /* Default */
  return ATM90EXX_DRV_SUCCESS;
}

#if defined (ATM90EXX_IRQ_SUPPORT) || defined (ATM90EXX_DRV_POLL_INT_STATUS)
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E26_DRV_CheckInterrupt ( void )

  Remarks:
    See prototype in app_test.h.
 */
bool ATM90E26_DRV_CheckInterruptsTask (void)
{
    bool updateFlag = false;

    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][INT]\r\n");
    /* Write LastData Register - The ATM90EXX apparently sometimes fail reading if there is not a previous writting */
    //ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, LASTSPIDATA_ADDR, 0);
    
    /* Read SysStatus Register */
    ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SYSSTATUS_ADDR, (uint16_t *) &gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus);

    /* Read EnStatus Register */
    ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ENSTATUS_ADDR, (uint16_t *) &gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus);

#ifdef ATM90EXX_SAG_SUPPORT  
    if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn & FUNCEN_SAGEN_Msk)
    {
        if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus & SYSSTATUS_SAGWARN_Msk) == SYSSTATUS_SAGWARN_Msk)
        {
            /* SAG Event */
            /* Create EVENT to notify */
            atm90ExxEvents.BIT.sagA = 1;
            updateFlag = true;
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] SAG\r\n");
        }
    }
#endif
    if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn & FUNCEN_REVPEN_Msk)
    {
        if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus & SYSSTATUS_REVPCHG_Msk) == SYSSTATUS_REVPCHG_Msk)
        {
            /* Change in Active Energy Direction */
            /* Refresh the information about the Active Energy Direction */
            /* Create EVENT to notify */
            atm90ExxEvents.BIT.paDir = 1;
            updateFlag = true;
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] PaDIR\r\n");
        }
    }
    
    if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn & FUNCEN_REVQEN_Msk)
    {
        if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus & SYSSTATUS_REVQCHG_Msk) == SYSSTATUS_REVQCHG_Msk)
        {
            /* Change in Reactive Energy Direction */
            /* Refresh the information about the Reactive Energy Direction */
            /* Create EVENT to notify */
            atm90ExxEvents.BIT.qaDir = 1;
            updateFlag = true;
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] QaDIR\r\n");
        }
    }
    
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus & SYSSTATUS_LNCHANGE_Msk) == SYSSTATUS_LNCHANGE_Msk)
    {
        /* Change in the Metering Line */
        /* Check the Configuration and decide */
        /* Create EVENT to notify */
        //atm90ExxEvents.BIT. = 1;
        //updateFlag = true;
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] LNchange\r\n");
    }
#ifdef ATM90EXX_NOLOAD_SUPPORT
#ifdef ATM90EXX_NOLOAD_ACTIVE_SUPPORT
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus & ENSTATUS_PNLOAD_Msk) == ENSTATUS_PNLOAD_Msk)
    {
        /* Active No-load status */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.noloadAP = 1;
        updateFlag = true;
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] noloadAP\r\n");
    }
#endif
#ifdef ATM90EXX_NOLOAD_REACTIVE_SUPPORT
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus & ENSTATUS_QNLOAD_Msk) == ENSTATUS_QNLOAD_Msk)
    {
        /* Reactive No-load Status */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.noloadAQ = 1;
        updateFlag = true;
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] noloadAQ\r\n");
    }
#endif
#endif

#ifdef ATM90EXX_HARD_ERR_SUPPORT
    if (((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus & SYSSTATUS_ADJERR_Msk) == SYSSTATUS_ADJERR_Msk) || 
        ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus & SYSSTATUS_CALERR_Msk) == SYSSTATUS_CALERR_Msk))
    {
        /* Configuration Error requires reload configuration */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.hardErr = 1;
        updateFlag = true;
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] hardErr\r\n");      
    }
#endif
    gATM90ExxDrvObj.checkIntState = ATM90EXX_DRV_CHECK_INT_TASK_STATE_END;
    return updateFlag;
}
#endif

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT DRV_ATM90EXX_Start ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E26_DRV_ConfigureTask()
{
  uint16_t value;
  bool NOTok = false;
  
    /* Check the application's current state. */
  switch ( gATM90ExxDrvObj.confState )
  {
      case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT:
        gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW;
        break;

      case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_INIT))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] INIT\r\n");
          /* Read MMDx HW configuration from EnStatus Register */
          //ATM90EXX_DRV_MeterMode();
        
          /* Reset the Device */
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SOFTRESET_ADDR, SOFTRESET_DEFAULT_Val);
        }
        if (NOTok)
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY;  
          gATM90ExxDrvObj.confNextState = ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS;
          gATM90ExxDrvObj.delayMs = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW_DELAY_MS;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_INIT);
        }
        break;
      }
      /* Application's initial state. */
      case ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_NOSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] SPECIAL_REGS\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, FUNCEN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.FuncEn);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SAGTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SagTh);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SMALLPMOD_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.SmallPMod);
        }
        if (NOTok)
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
            // Update Status of registers
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.FuncEn;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SagTh;
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.SmallPMod = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.SmallPMod;
            
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CALSTART;
            ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_NOSTART);
        }

        break;  
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CALSTART:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_CALSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CALSTART\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CALSTART_ADDR, 0x5678);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PLCONSTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstH);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PLCONSTL_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstL);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, LGAIN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Lgain);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, LPHI_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Lphi);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, NGAIN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Ngain);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, NPHI_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Nphi);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PSTARTTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PStartTh);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PNOLTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PNolTh); 
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QSTARTTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QStartTh);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, MMODE_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode); 
          if (NOTok)
          {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
          }
          else
          {
            // Update Status of registers
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstH = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstH;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstL = gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstH = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstL;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Lgain = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Lgain;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Lphi = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Lphi;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Ngain = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Ngain;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Nphi = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.Nphi;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PStartTh;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PNolTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PNolTh;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.QStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QStartTh;
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode;
                    
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CS1;
          }
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART; 
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CS1:
      {

        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CS1\r\n");
#ifdef ATM90EXX_DRV_CHECKSUM_CALC
        // TBD
#else
        NOTok |= ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CS1_ADDR, &value);
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CS1_ADDR, value /*gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS1*/);
#endif
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CALSTART_ADDR, 0x8765);
        if (NOTok)
        { 
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS1 = value;
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_CALSTART);
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_ADJSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] ADJSTART\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, ADJSTART_ADDR, 0x5678);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UGAIN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.Ugain);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINL_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainL);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainN);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UOFFSET_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.Uoffset);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETL_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetL);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetN);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETL_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.PoffsetL);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.QoffsetL);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETL_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.PoffsetN);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.QoffsetN);
          if (NOTok)
          {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
          }
          else
          {
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.Ugain = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.Ugain;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainL = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainL;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainN = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainN;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.Uoffset = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.Uoffset;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetL = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetL;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetN = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetN;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.PoffsetL = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.PoffsetL;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.QoffsetL = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.QoffsetL;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.PoffsetN = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.PoffsetN;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.QoffsetN = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.QoffsetN;
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CS2;
          }
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_END;
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CS2:
      {
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CS2\r\n");
#ifdef ATM90EXX_DRV_CHECKSUM_CALC
      // TBD - Calculate Checksum
#else
        NOTok |= ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CS2_ADDR, &value);
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CS2_ADDR, value);
#endif
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, ADJSTART_ADDR, 0x8765);

        if (NOTok)
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS2 = value;  
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_END;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_ADJSTART);
        }        
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_END:
      {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] END\r\n");
          break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY:
        {
            // Wait delay time
            if (ATM90EXX_DRV_TaskDelay(gATM90ExxDrvObj.delayMs, &gATM90ExxDrvObj.timer))
            {
                // Set next app state
                gATM90ExxDrvObj.confState = gATM90ExxDrvObj.confNextState;
            }
            break;
        }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR:
      {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_FATAL, "[AD][CFG] ERROR\r\n");
          // Impossible to configure the device, requires full reconfiguration
          ATM90EXX_SET_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_ALL);
          return ATM90EXX_DRV_ERROR;
      }
      /* The default state should never be executed. */
      default:
      {
          /* Nothing to do. */
          break;
      }
  }
  return ATM90EXX_DRV_SUCCESS;
}

#ifdef ATM90EXX_CALIBRATION_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E26_DRV_CalibrationTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E26_DRV_CalibrationTask (void)
{
    /* Check the application's calibration state. */
    switch ( gATM90ExxDrvObj.calibrationState )
    {
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_INIT:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CAL] INIT\r\n");
            gATM90ExxDrvObj.calibrationState = ATM90EXX_DRV_CALIBRATION_TASK_STATE_END;
            break;
        }
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_END:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CAL] END\r\n");
            break;
        }
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_ERROR:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_FATAL, "[AD][CAL] ATM90E3x driver error\r\n");
            return ATM90EXX_DRV_ERROR;
        }
    }
    return ATM90EXX_DRV_SUCCESS;
}
#endif

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E26_DRV_RefreshInfoTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E26_DRV_RefreshInfoTask(void)
{
    uint16_t value;
    
    /* Check the application's Refresh Information state. */
    switch ( gATM90ExxDrvObj.refreshInfoState )
    {
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_INIT:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][RI] INIT\r\n");
#ifdef ATM90EXX_DRV_POLL_INT_STATUS
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_STATUS;
#else
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_LINE;
#endif
            break;
        }
#ifdef ATM90EXX_DRV_POLL_INT_STATUS
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_STATUS:
        {
            ATM90EXX_DRV_CheckInterruptsTask();
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_LINE;
            break;
        }       
#endif        
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_LINE:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] POLL_MEASURING_LINE\r\n");

            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMS_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsLSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, URMS_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Urms = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsLSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEAN_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanLSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEAN_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanLSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEAN_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanLSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, POWERF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PowerF = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PANGLE_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Pangle = value;
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_NEUTRAL;
            break;
        }
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_NEUTRAL:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] POLL MEASURING NEUTRAL\r\n");
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMS2_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms2 = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms2LSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEAN2_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean2 = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean2LSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEAN2_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean2 = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean2LSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEAN2_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean2 = value;
#ifdef ATM90E26_LSB_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, LSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean2LSB = value;
#endif
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, POWERF2_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PowerF2 = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PANGLE2_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Pangle2 = value;
            
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING;
            break;
        }
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] POLL METERING\r\n");
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGY_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergy += value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGY_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergy += value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ATENERGY_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ATEnergy += value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RPENERGY_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergy += value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RNENERGY_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergy += value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RTENERGY_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RTEnergy += value;
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_OTHERS;
            break;
        }
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_OTHERS:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] POLL OTHERS\r\n");
            // Frequency 
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, FREQ_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Freq = value;
            // Next State
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_END;
            break;
        }         
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_END:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][RI] END\r\n");
            break;
        }
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_ERROR:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_FATAL, "[AD][RI] ERROR\r\n");
            return ATM90EXX_DRV_ERROR;
        }
    }
    return ATM90EXX_DRV_SUCCESS;
} 
#endif

#ifdef ATM90E32_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_Init_DefaultConfig ( ATM90EXX_CONF *conf )

  Remarks:
    Obtained in ATM90E32-DB Calibration process.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Init_DefaultConfig(ATM90EXX_CONF * conf)
{
  conf->ctrlInfo.UScale = SCALE_FACTOR_1;   /* Default No Scale */
  conf->ctrlInfo.IScale = SCALE_FACTOR_1;   /* Default No Scale */
  conf->ctrlInfo.PM = ATM90E3X_POWER_MODE_NORMAL; /* Default */
  conf->ctrlInfo.MeterEn = 0x00FF;          /* Default Enable */
  conf->ctrlInfo.ChannelMapI = 0x0210;      /* ATM90EXX-DB Configuration*/
  conf->ctrlInfo.ChannelMapU = 0x0654;      /* ATM90EXX-DB Configuration */
  conf->ctrlInfo.SagPeakDetCfg = 0x143F;    /* Default */
  conf->ctrlInfo.ZXConfig = 0x0001;         /* Calculated */
#ifdef ATM90EXX_IRQ_ALL1ONE_SUPPORT  
  conf->ctrlInfo.IRQ0MergeCfg = 0x0003;     /* ORed INT1 and WARNOUT in INT0 */
#endif
  conf->ctrlInfo.MMode0 = 0x0087;           /* 50Hz, 3P4W, CF2 reactive, Sum Arithmetic, All Phases */
#ifdef ATM90EXX_60HZ_SUPPORT
  conf->ctrlInfo.MMode0 |= MMODE0_FREQ60HZ_Msk;
#endif
  conf->ctrlInfo.MMode1 = 0x0000;           /* Gain 1 for All ADC Channels */
  
  conf->ctrlInfo.EMMIntEn0 = EMMINTEN0_DEFAULT_Val; /* Default Value 0x0000 */

#ifdef ATM90EXX_OVER_CURRENT_SUPPORT
  conf->ctrlInfo.EMMIntEn0 |= EMMINTEN0_OIALLINTEN_Msk;
#endif // ATM90EXX_OVERCURRENT_SUPPORT

#ifdef ATM90EXX_SWELL_SUPPORT
  conf->ctrlInfo.EMMIntEn0 |= EMMINTEN0_OVALLINTEN_Msk;
#endif // ATM90EXX_SWELL_SUPPORT

#ifdef ATM90EXX_NOLOAD_SUPPORT
#ifdef ATM90EXX_NOLOAD_ACTIVE_SUPPORT
  conf->ctrlInfo.EMMIntEn0 |= EMMINTEN0_TPNOLOADINTEN_Msk;
#endif
#ifdef ATM90EXX_NOLOAD_REACTIVE_SUPPORT
  conf->ctrlInfo.EMMIntEn0 |= EMMINTEN0_TQNOLOADINTEN_Msk;
#endif
#ifdef ATM90EXX_NOLOAD_APPARENT_SUPPORT
  conf->ctrlInfo.EMMIntEn0 |= EMMINTEN0_TASNOLOADINTEN_Msk;
#endif
#endif // ATM90EXX_NOLOAD_SUPPORT

#ifdef ATM90EXX_PHASE_SEQUENCE_SUPPORT
  conf->ctrlInfo.EMMIntEn0 |= EMMINTEN0_IREVWNINTEN_Msk;
  conf->ctrlInfo.EMMIntEn0 |= EMMINTEN0_UREVWNINTEN_Msk;
#endif

  conf->ctrlInfo.EMMIntEn1 = EMMINTEN1_DEFAULT_Val; /* Default Value 0x0000 */
#ifdef ATM90EXX_SAG_SUPPORT    
  conf->ctrlInfo.EMMIntEn1 |= EMMINTEN1_SAGALLINTEN_Msk; 
#endif // ATM90EXX_SAG_SUPPORT

#ifdef ATM90EXX_PHASE_LOSS_SUPPORT
  conf->ctrlInfo.EMMIntEn1 |= EMMINTEN1_PHASELOSSALLINTEN_Msk; 
#endif // ATM90EXX_PHASELOSS_SUPPORT

#ifdef ATM90EXX_FREQ_RANGE_ERROR_SUPPORT
  conf->ctrlInfo.EMMIntEn1 |= EMMINTEN1_FREQHIINTEN_Msk;
  conf->ctrlInfo.EMMIntEn1 |= EMMINTEN1_FREQLOINTEN_Msk;
#endif

  conf->thresholdInfo.SagTh = 0x1000;       /* Default */
  conf->thresholdInfo.OVth = 0xC000;        /* Default */
  conf->thresholdInfo.PhaseLossTh = 0x0400; /* Default */
  conf->thresholdInfo.InWarnTh = 0xFFFF;    /* Default */
  conf->thresholdInfo.OIth = 0xC000;        /* Default */
  conf->thresholdInfo.FreqLoTh = 0x1324;    /* Default */
  conf->thresholdInfo.FreqHighTh = 0x13EC;  /* Default */
  conf->thresholdInfo.PStartTh = 0x0000;    /* Default */
  conf->thresholdInfo.QStartTh = 0x0000;    /* Default */
  conf->thresholdInfo.SStartTh = 0x0000;    /* Default */
  conf->thresholdInfo.PPhaseTh = 0x0000;    /* Default */
  conf->thresholdInfo.QPhaseTh = 0x0000;    /* Default */
  conf->thresholdInfo.SPhaseTh = 0x0000;    /* Default */

  conf->calMeasInfo.UgainA = 0xC544;        /* Calibrated */
  conf->calMeasInfo.UgainB = 0xC578;        /* Calibrated */
  conf->calMeasInfo.UgainC = 0xC557;        /* Calibrated */
  conf->calMeasInfo.IgainA = 0x7C4E;        /* Calibrated */
  conf->calMeasInfo.IgainB = 0x793E;        /* Calibrated */
  conf->calMeasInfo.IgainC = 0x7D31;        /* Calibrated */
  conf->calMeasInfo.UoffsetA = 0x0000;      /* Default */
  conf->calMeasInfo.UoffsetB = 0x0000;      /* Default */
  conf->calMeasInfo.UoffsetC = 0x0000;      /* Default */
  conf->calMeasInfo.IoffsetA = 0x0000;      /* Default */
  conf->calMeasInfo.IoffsetB = 0x0000;      /* Default */
  conf->calMeasInfo.IoffsetC = 0x0000;      /* Default */  

  conf->calMetInfo.MC = 3200;               /* MC=3200 */
  conf->calMetInfo.PLconstH = 0x0430;       /* MC=3200 */
  conf->calMetInfo.PLconstL = 0xE234;       /* MC=3200 */
  conf->calMetInfo.PoffsetA = 0x0000;       /* Default */
  conf->calMetInfo.QoffsetA = 0x0000;       /* Default */
  conf->calMetInfo.PoffsetB = 0x0000;       /* Default */
  conf->calMetInfo.QoffsetB = 0x0000;       /* Default */
  conf->calMetInfo.PoffsetC = 0x0000;       /* Default */
  conf->calMetInfo.QoffsetC = 0x0000;       /* Default */  
  conf->calMetInfo.PgainA = 0x0000;         /* Default */
  conf->calMetInfo.PgainB = 0x0000;         /* Default */
  conf->calMetInfo.PgainC = 0x0000;         /* Default */
  conf->calMetInfo.PhiA = 0x0000;           /* Default */
  conf->calMetInfo.PhiB = 0x0000;           /* Default */
  conf->calMetInfo.PhiC = 0x0000;           /* Default */
  conf->calMetInfo.PoffsetAF = 0x0000;      /* Default */
  conf->calMetInfo.PoffsetBF = 0x0000;      /* Default */  
  conf->calMetInfo.PoffsetCF = 0x0000;      /* Default */  
  conf->calMetInfo.PgainAF = 0x0000;        /* Default */
  conf->calMetInfo.PgainBF = 0x0000;        /* Default */
  conf->calMetInfo.PgainCF = 0x0000;        /* Default */
  return ATM90EXX_DRV_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E32_DRV_ConfigureTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E32_DRV_ConfigureTask(void)
{
    bool NOTok = false;
    
    /* Check the application's current state. */
    switch ( gATM90ExxDrvObj.confState )
    {
        case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT:
        {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW;
            break;
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] INIT HW\r\n");
#ifdef ATM90E3X_HAL_PMX_PIO_SUPPORT
            /* Set PM0-1 HW configuration in Normal Mode */
            ATM90E3X_DRV_set_PowerMode(ATM90E3X_POWER_MODE_NORMAL);
#endif
            // ADDITIONAL TIME NEEDED AFTER HW INIT
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY;
            gATM90ExxDrvObj.confNextState = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW;
            gATM90ExxDrvObj.delayMs = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW_DELAY_MS;
            break;
        }    
        case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] INIT SW\r\n");
            /* Reset the Device */
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SOFTRESET_ADDR, SOFTRESET_RESET_Val);
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                // ADDITIONAL TIME NEEDED AFTER RESET
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY;
                gATM90ExxDrvObj.confNextState = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_CFG;
                gATM90ExxDrvObj.delayMs = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW_DELAY_MS;            
            }
            break;
        }
        /* Application's initial state. */
        case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_CFG:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] INIT CFG\r\n");
            /* Allow Register Access Configuration */
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                // Check Flags, maybe only 1 register configuration
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS;
            }
            //break; /* Don't break to allow 1 register configuration on 1 loop */
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] SPECIAL_REGS\r\n");
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CHANNELMAPI_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ChannelMapI);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CHANNELMAPU_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ChannelMapU);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SAGPEAKDETCFG_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.SagPeakDetCfg);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, ZXCONFIG_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ZXConfig);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, OVTH_ADDR         , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.OVth);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SAGTH_ADDR        , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SagTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHASELOSSTH_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PhaseLossTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, INWARNTH_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.InWarnTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, OITH_ADDR         , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.OIth);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, FREQLOTH_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.FreqLoTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, FREQHITH_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.FreqHighTh);
            //NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PMPWRCTRL_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.PmPwrCtrl);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IRQ0MERGECFG_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.IRQ0MergeCfg);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, EMMINTEN0_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.EMMIntEn0);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, EMMINTEN1_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.EMMIntEn1);
            
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                // Update Register Information
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIG_REGS;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MeterEn          = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MeterEn;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.ChannelMapI      = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ChannelMapI;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.ChannelMapU      = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ChannelMapU;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.SagPeakDetCfg    = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.SagPeakDetCfg;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.ZXConfig         = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ZXConfig;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.OVth        = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.OVth;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh       = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SagTh;        
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PhaseLossTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PhaseLossTh;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh    = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.InWarnTh;  
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.OIth        = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.OIth;        
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.FreqLoTh    = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.FreqLoTh;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.FreqHighTh  = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.FreqHighTh;   
                //gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.PmPwrCtrl        = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.PmPwrCtrl;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IRQ0MergeCfg     = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.IRQ0MergeCfg; 
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0        = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.EMMIntEn0;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1        = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.EMMIntEn1;
                // Next State
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIG_REGS;
            }
            break;  
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIG_REGS:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CONFIG_REGS\r\n");
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PLCONSTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstH   );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PLCONSTL_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstL   );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, MMODE0_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode0       );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, MMODE1_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode1       );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PSTARTTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PStartTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QSTARTTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QStartTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SSTARTTH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SStartTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PPHASETH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PPhaseTh);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QPHASETH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QPhaseTh); 
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SPHASETH_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SPhaseTh); 
            
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstH    = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstH;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstL    = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstL;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode0        = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode0;
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode1        = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode1;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PStartTh;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.QStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QStartTh;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SStartTh;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PPhaseTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PPhaseTh;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.QPhaseTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QPhaseTh;
                gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SPhaseTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SPhaseTh; 
                // Next State
                gATM90ExxDrvObj.confState =  ATM90EXX_DRV_CONFIG_TASK_STATE_CAL_REGS;      
            }
            break;
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_CAL_REGS:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CAL_REGS\r\n");
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETA_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetA);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETA_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetA);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETB_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetB);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETB_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetB);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETC_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetC);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETC_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetC);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PQGAINA_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainA  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHIA_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiA    );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PQGAINB_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainB  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHIB_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiB    );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PQGAINC_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainC  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHIC_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiC    );
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                // Update Register Information
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetA = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetA;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.QoffsetA = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetA;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetB = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetB;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.QoffsetB = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetB;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetC = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetC;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.QoffsetC = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetC;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainA   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainA  ;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PhiA      = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiA   ;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainB   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainB  ;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PhiB      = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiB   ;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainC   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainC  ;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PhiC      = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiC   ;
                // Next State
                gATM90ExxDrvObj.confState =  ATM90EXX_DRV_CONFIG_TASK_STATE_FUN_CAL_REGS; 
            }
            break;
        }    
        case ATM90EXX_DRV_CONFIG_TASK_STATE_FUN_CAL_REGS:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] FUND_CAL_REGS\r\n");
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETAF_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetAF);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETBF_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetBF);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETCF_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetCF);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PGAINAF_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainAF   );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PQGAINB_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainBF   );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PQGAINC_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainCF   );      
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                // Update Register Information
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetAF = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetAF;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetBF = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetBF;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetCF = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetCF;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainAF    = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainAF   ;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainBF    = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainBF   ;
                gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainCF    = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainCF   ;
                // Next State
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_MEAS_CAL_REGS;
            }
            break;
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_MEAS_CAL_REGS:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] MEAS_CAL_REGS\r\n");
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UGAINA_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainA  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINA_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainA  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UOFFSETA_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetA);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETA_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetA);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UGAINB_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainB  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINB_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainB  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UOFFSETB_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetB);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETB_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetB);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UGAINC_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainC  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINC_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainC  );
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UOFFSETC_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetC);
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETC_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetC);
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA   = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainA  ;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainA   = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainA  ;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UoffsetA = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetA;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetA = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetA;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainB   = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainB  ;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainB   = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainB  ;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UoffsetB = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetB;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetB = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetB;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainC   = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainC  ;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainC   = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainC  ;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UoffsetC = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetC;
                gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetC = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetC;
                // Next State
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_METEREN;
            }
            break;
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_METEREN:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] METEREN\r\n");
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, METEREN_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MeterEn);
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MeterEn = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MeterEn;
                // Next State
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ENDCFG;
            }
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_ENDCFG:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] NORMAL MODE\r\n");  
            /* Normal Mode Configuration */
            NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
            if (NOTok)
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
            }
            else
            {
                gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CRCDIGEST;
            }
            break;
        }    

        case ATM90EXX_DRV_CONFIG_TASK_STATE_CRCDIGEST:
        {
            // Get CRC Digest value
            uint16_t value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CRCDIGEST_ADDR, &value);
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_END;
            //break;
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_END:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] END\r\n");  
            break;
        }
        
        case ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY:
        {
            // Wait delay time
            if (ATM90EXX_DRV_TaskDelay(gATM90ExxDrvObj.delayMs, &gATM90ExxDrvObj.timer))
            {
                // Set next app state
                gATM90ExxDrvObj.confState = gATM90ExxDrvObj.confNextState;
            }
            break;
        }
        case ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR:
        {
            SYS_DEBUG_PRINT(SYS_ERROR_FATAL, "ATM90E3x driver error\r\n");
            break;
        }
        /* The default state should never be executed. */
        default:
        {
            /* Nothing to do. */
            break;
        }
    }
  return ATM90EXX_DRV_SUCCESS;
}

#ifdef ATM90EXX_CALIBRATION_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E32_DRV_CalibrationTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E32_DRV_CalibrationTask (void)
{
    /* Check the application's calibration state. */
    switch ( gATM90ExxDrvObj.calibrationState )
    {
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_INIT:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CAL] INIT\r\n");
            gATM90ExxDrvObj.calibrationState = ATM90EXX_DRV_CALIBRATION_TASK_STATE_END;
            break;
        }
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_END:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CAL] END\r\n");
            break;
        }
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_ERROR:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_FATAL, "[AD][CAL] ERROR\r\n");
            return ATM90EXX_DRV_ERROR;
        }
    }
    return ATM90EXX_DRV_SUCCESS;
}
#endif

#if defined (ATM90EXX_IRQ_SUPPORT) || defined (ATM90EXX_DRV_POLL_INT_STATUS)
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E32_DRV_CheckInterruptsTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
bool ATM90E32_DRV_CheckInterruptsTask (void)
{
  uint16_t CRCErrStatus;
  bool updateFlag = false;

  ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][INT] INIT\r\n");
  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 != EMMINTSTATE0_DEFAULT_Val)
  {
      /* Read EMMState0 Register */
      ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, EMMSTATE0_ADDR, (uint16_t *) &gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0);
      /* Read EMMIntState0 Register */
      ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, EMMINTSTATE0_ADDR, (uint16_t *) &gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0);

#ifdef ATM90EXX_CFX_SUPPORT
#ifdef ATM90EXX_CF4_SUPPORT
  if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_CF4REVINTST_Msk) == EMMINTSTATE0_CF4REVINTST_Msk)
  {
      /* Energy for CF4 Forward/Reverse status change */
      /* Create EVENT to notify */
  }  
#endif
#ifdef ATM90EXX_CF3_SUPPORT
  if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_CF3REVINTST_Msk) == EMMINTSTATE0_CF3REVINTST_Msk)
  {
    /* Energy for CF3 Forward/Reverse status change */
    /* Create EVENT to notify */
  } 
#endif
#ifdef ATM90EXX_CF2_SUPPORT
  if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_CF2REVINTST_Msk) == EMMINTSTATE0_CF2REVINTST_Msk)
  {
    /* Energy for CF2 Forward/Reverse status change */
    /* Create EVENT to notify */
  } 
#endif
#ifdef ATM90EXX_CF1_SUPPORT
  if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_CF1REVINTST_Msk) == EMMINTSTATE0_CF1REVINTST_Msk)
  {
    /* Energy for CF1 Forward/Reverse status change */
    /* Create EVENT to notify */
  } 
#endif
#endif // ATM90EXX_CFX_SUPPORT

#ifdef ATM90EXX_NOLOAD_SUPPORT
#ifdef ATM90EXX_NOLOAD_ACTIVE_SUPPORT
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_TPNOLOADINTST_Msk) == EMMINTSTATE0_TPNOLOADINTST_Msk)
    {
        /* Active No-load status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.noloadAP = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_TPNOLOADST_Msk) >> EMMSTATE0_TPNOLOADST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] noloadAP=%d\r\n",atm90ExxEvents.BIT.noloadAP);
    }
#endif // ATM90EXX_NOLOAD_ACTIVE_SUPPORT
#ifdef ATM90EXX_NOLOAD_REACTIVE_SUPPORT
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_TQNOLOADINTST_Msk) == EMMINTSTATE0_TQNOLOADINTST_Msk)
    {
        /* Reactive No-load status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.noloadAQ = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_TQNOLOADST_Msk) >> EMMSTATE0_TQNOLOADST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] noloadAQ=%d\r\n",atm90ExxEvents.BIT.noloadAQ);
    }
#endif // ATM90EXX_NOLOAD_REACTIVE_SUPPORT
#ifdef ATM90EXX_NOLOAD_APPARENT_SUPPORT
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_TASNOLOADINTST_Msk) == EMMINTSTATE0_TASNOLOADINTST_Msk)
    {
        /* Total Sum Apparent No-load status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.noloadAS = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_TASNOLOADST_Msk) >> EMMSTATE0_TASNOLOADST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] noloadAS=%d\r\n",atm90ExxEvents.BIT.noloadAS);
    } 
#endif // ATM90EXX_NOLOAD_APPARENT_SUPPORT
#endif // ATM90EXX_NOLOAD_SUPPORT

#ifdef ATM90EXX_PHASE_SEQUENCE_SUPPORT
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_UREVWNINTST_Msk) == EMMINTSTATE0_UREVWNINTST_Msk)
    {
        /* Voltage Phase Sequence status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.phaseSeqV = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_UREVWNST_Msk) >> EMMSTATE0_UREVWNST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] phaseSeqV=%d\r\n",atm90ExxEvents.BIT.phaseSeqV);
    }  
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_IREVWNINTST_Msk) == EMMINTSTATE0_IREVWNINTST_Msk)
    {
        /* Current Phase Sequence status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.phaseSeqC = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_IREVWNST_Msk) >> EMMSTATE0_IREVWNST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] phaseSeqC=%d\r\n",atm90ExxEvents.BIT.phaseSeqC);
    } 
#endif // ATM90EXX_PHASE_SEQUENCE_SUPPORT
  
#ifdef ATM90EXX_SWELL_SUPPORT 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_OVPHASEAINTST_Msk) == EMMINTSTATE0_OVPHASEAINTST_Msk)
    {
        /* Voltage A Over Voltage status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.swellA = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_OVPHASEAST_Msk) >> EMMSTATE0_OVPHASEAST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] swellA=%d\r\n",atm90ExxEvents.BIT.swellA);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_OVPHASEBINTST_Msk) == EMMINTSTATE0_OVPHASEBINTST_Msk)
    {
        /* Voltage B Over Voltage status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.swellB = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_OVPHASEBST_Msk) >> EMMSTATE0_OVPHASEBST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] swellB=%d\r\n",atm90ExxEvents.BIT.swellB);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_OVPHASECINTST_Msk) == EMMINTSTATE0_OVPHASECINTST_Msk)
    {
        /* Voltage C Over Voltage status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.swellC = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_OVPHASECST_Msk) >> EMMSTATE0_OVPHASECST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] swellC=%d\r\n",atm90ExxEvents.BIT.swellC);
    }
#endif // ATM90EXX_SWELL_SUPPORT
  
#ifdef ATM90EXX_OVER_CURRENT_SUPPORT 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_OIPHASEAINTST_Msk) == EMMINTSTATE0_OIPHASEAINTST_Msk)
    {
        /* Line A Over Current status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.overCA = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_OIPHASEAST_Msk) >> EMMSTATE0_OIPHASEAST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] overCA=%d\r\n",atm90ExxEvents.BIT.overCA);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_OIPHASEBINTST_Msk) == EMMINTSTATE0_OIPHASEBINTST_Msk)
    {
        /* Line B Over Current status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.overCB = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_OIPHASEBST_Msk) >> EMMSTATE0_OIPHASEBST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] overCB=%d\r\n",atm90ExxEvents.BIT.overCB);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_OIPHASECINTST_Msk) == EMMINTSTATE0_OIPHASECINTST_Msk)
    {
        /* Line C Over Current status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.overCC = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_OIPHASECST_Msk) >> EMMSTATE0_OIPHASECST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] overCC=%d\r\n",atm90ExxEvents.BIT.overCC);
    }
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0 & EMMINTSTATE0_INOV0INTST_Msk) == EMMINTSTATE0_INOV0INTST_Msk)
    {
        /* Line N Over Current status change  */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.overCN = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState0 & EMMSTATE0_INOV0ST_Msk) >> EMMSTATE0_INOV0ST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] overCN=%d\r\n",atm90ExxEvents.BIT.overCN);
    }
#endif // ATM90EXX_OVERCURRENT_SUPPORT
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1 != EMMINTSTATE1_DEFAULT_Val)
  {
      /* Read EMMState1 Register */
      ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, EMMSTATE1_ADDR, (uint16_t *) &gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1);

      /* Read EMMIntState1 Register */
      ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, EMMINTSTATE1_ADDR, (uint16_t *) &gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1);

#ifdef ATM90EXX_SAG_SUPPORT    
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_SAGPHASEAINTST_Msk) == EMMINTSTATE1_SAGPHASEAINTST_Msk)
    {
        /* Voltage A sag status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.sagA = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_SAGPHASEAST_Msk) >> EMMSTATE1_SAGPHASEAST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] sagA=%d\r\n",atm90ExxEvents.BIT.sagA);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_SAGPHASEBINTST_Msk) == EMMINTSTATE1_SAGPHASEBINTST_Msk)
    {
        /* Voltage B sag status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.sagB = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_SAGPHASEBST_Msk) >> EMMSTATE1_SAGPHASEBST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] sagB=%d\r\n",atm90ExxEvents.BIT.sagB);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_SAGPHASECINTST_Msk) == EMMINTSTATE1_SAGPHASECINTST_Msk)
    {
        /* Voltage C sag status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.sagC = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_SAGPHASECST_Msk) >> EMMSTATE1_SAGPHASECST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] sagC=%d\r\n",atm90ExxEvents.BIT.sagC);
    }
#endif // ATM90EXX_SAG_SUPPORT
  
#ifdef ATM90EXX_PHASE_LOSS_SUPPORT    
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_PHASELOSSAINTST_Msk) == EMMINTSTATE1_PHASELOSSAINTST_Msk)
    {
        /* Voltage A loss status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.pLossVA = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_PHASELOSSAST_Msk) >> EMMSTATE1_PHASELOSSAST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] pLossVA=%d\r\n",atm90ExxEvents.BIT.pLossVA);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_PHASELOSSBINTST_Msk) == EMMINTSTATE1_PHASELOSSBINTST_Msk)
    {
        /* Voltage B loss status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.pLossVB = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_PHASELOSSBST_Msk) >> EMMSTATE1_PHASELOSSBST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] pLossVB=%d\r\n",atm90ExxEvents.BIT.pLossVB);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_PHASELOSSCINTST_Msk) == EMMINTSTATE1_PHASELOSSCINTST_Msk)
    {
        /* Voltage C loss status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.pLossVC = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_PHASELOSSCST_Msk) >> EMMSTATE1_PHASELOSSCST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] pLossVC=%d\r\n",atm90ExxEvents.BIT.pLossVC);
    }
#endif // ATM90EXX_PHASE_LOSS_SUPPORT  

#ifdef ATM90EXX_FREQ_RANGE_ERROR_SUPPORT    
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_FREQLOINTST_Msk) == EMMINTSTATE1_FREQLOINTST_Msk)
    {
        /* Frequency below the range active status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.freqRange = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_FREQLOST_Msk) >> EMMSTATE1_FREQLOST_Pos); 
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] freqRangeLo=%d\r\n",atm90ExxEvents.BIT.freqRange);
    } 
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1 & EMMINTSTATE1_FREQHIINTST_Msk) == EMMINTSTATE1_FREQHIINTST_Msk)
    {
        /* Frequency above the range active status change */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.freqRange = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMState1 & EMMSTATE1_FREQHIST_Msk) >> EMMSTATE1_FREQHIST_Pos);
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] freqRangeHi=%d\r\n",atm90ExxEvents.BIT.freqRange);
    } 
#endif // ATM90EXX_FREQ_RANGE_ERROR_SUPPORT 
  }
#ifdef ATM90EXX_HARD_ERR_SUPPORT
    /* Read CRCErrStatus Register */
    ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CRCERRSTATUS_ADDR, &CRCErrStatus);
    if (CRCErrStatus != 0)
    {
        // TBD - Hardware Errors
        atm90ExxEvents.BIT.hardErr = 1;
        updateFlag = true;
        ATM90EXX_DEBUG_PRINT(SYS_ERROR_INFO, "[AD][INT] Error=%d\r\n",CRCErrStatus);
    }    
#endif    
    if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 != EMMINTSTATE0_DEFAULT_Val)
    {
        // Registers are R/W1C
        ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, EMMINTSTATE0_ADDR, gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState0);
    }

    if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1 != EMMINTSTATE1_DEFAULT_Val)
    {
        // Registers are R/W1C
        ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, EMMINTSTATE1_ADDR, gATM90ExxDrvObj.atm90ExxObj.statusInfo.EMMIntState1);
    }
    
    gATM90ExxDrvObj.checkIntState = ATM90EXX_DRV_CHECK_INT_TASK_STATE_END;
    ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][INT] END\r\n");
    return updateFlag;
}
#endif // ATM90EXX_IRQ_SUPPORT || ATM90EXX_DRV_POLL_INT_STATUS
#endif // ATM90E32_SUPPORT

#ifdef ATM90E36_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_Init_DefaultConfig ( ATM90EXX_CONF *conf )

  Remarks:
    Obtained in ATM90E36-DB Calibration process.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Init_DefaultConfig(ATM90EXX_CONF * conf)
{
  conf->ctrlInfo.UScale = SCALE_FACTOR_1;             /* Default No Scale */
  conf->ctrlInfo.IScale = SCALE_FACTOR_1;             /* Default No Scale */
  conf->ctrlInfo.PM = ATM90E3X_POWER_MODE_NORMAL;     /* Default */
  conf->ctrlInfo.FuncEn0 = FUNCEN0_DEFAULT_Val;
#ifdef ATM90EXX_SAG_SUPPORT    
  conf->ctrlInfo.FuncEn0 |= FUNCEN0_SAGWNEN_Msk;
#endif
#ifdef ATM90EXX_PHASE_LOSS_SUPPORT    
  conf->ctrlInfo.FuncEn0 |= FUNCEN0_PHASELOSSWNEN_Msk;
#endif
#ifdef ATM90EXX_PHASE_SEQUENCE_SUPPORT
  conf->ctrlInfo.FuncEn0 |= FUNCEN0_IREVWNEN_Msk;
  conf->ctrlInfo.FuncEn0 |= FUNCEN0_UREVWNEN_Msk;
#endif
  conf->ctrlInfo.FuncEn1 = FUNCEN1_DEFAULT_Val;
#ifdef ATM90EXX_OVER_CURRENT_NC_SUPPORT  
  conf->ctrlInfo.FuncEn1 |= FUNCEN1_INOV0EN_Msk;
#endif  
#ifdef ATM90EXX_OVER_CURRENT_NS_SUPPORT  
  conf->ctrlInfo.FuncEn1 |= FUNCEN1_INOV1EN_Msk;
#endif
#ifdef ATM90EXX_THDN_SUPPORT
  conf->ctrlInfo.FuncEn1 |= FUNCEN1_THDUOVEN_Msk;
  conf->ctrlInfo.FuncEn1 |= FUNCEN1_THDIOVEN_Msk;
#endif

  conf->ctrlInfo.ZXconfig = ZXCONFIG_DEFAULT_Val;     /* Calculated */
  conf->ctrlInfo.MMode0 = MMODE0_DEFAULT_Val;         /* 50Hz, 3P4W, CF2 reactive, Sum Arithmetic, All Phases */
#ifdef ATM90EXX_60HZ_SUPPORT
  conf->ctrlInfo.MMode0 |= MMODE0_FREQ60HZ_Msk;
#endif
#ifdef ATM90EXX_I1I3SWAP_SUPPORT
  conf->ctrlInfo.MMode0 |= MMODE0_I1I3SWAP_Msk;
#endif
  conf->ctrlInfo.MMode1 = 0x0000;           /* Gain 1 for All ADC Channels */
  conf->ctrlInfo.DMACtrl = DMACTRL_DEFAULT_Val;

  conf->thresholdInfo.SagTh = SAGTH_DEFAULT_Val;                /* Default */
  conf->thresholdInfo.PhaseLossTh = PHASELOSSTH_DEFAULT_Val;    /* Default */
  conf->thresholdInfo.InWarnTh = INWARNTH0_DEFAULT_Val;         /* Default */
  conf->thresholdInfo.InWarnTh1 = INWARNTH1_DEFAULT_Val;        /* Default */
  conf->thresholdInfo.ThdNuTh = THDNUTH_DEFAULT_Val;
  conf->thresholdInfo.ThdNiTh = THDNITH_DEFAULT_Val;
  conf->thresholdInfo.PStartTh = PSTARTTH_DEFAULT_Val;          /* Default */
  conf->thresholdInfo.QStartTh = QSTARTTH_DEFAULT_Val;          /* Default */
  conf->thresholdInfo.SStartTh = SSTARTTH_DEFAULT_Val;          /* Default */
  conf->thresholdInfo.PPhaseTh = PPHASETH_DEFAULT_Val;          /* Default */
  conf->thresholdInfo.QPhaseTh = QPHASETH_DEFAULT_Val;          /* Default */
  conf->thresholdInfo.SPhaseTh = SPHASETH_DEFAULT_Val;          /* Default */

  conf->calMeasInfo.UgainA = UGAINA_GAIN_DEFAULT_Val;           /* Calibrated */
  conf->calMeasInfo.UgainB = UGAINB_GAIN_DEFAULT_Val;           /* Calibrated */
  conf->calMeasInfo.UgainC = UGAINC_GAIN_DEFAULT_Val;           /* Calibrated */
  conf->calMeasInfo.IgainA = IGAINA_GAIN_DEFAULT_Val;           /* Calibrated */
  conf->calMeasInfo.IgainB = IGAINB_GAIN_DEFAULT_Val;           /* Calibrated */
  conf->calMeasInfo.IgainC = IGAINC_GAIN_DEFAULT_Val;           /* Calibrated */
  conf->calMeasInfo.IgainNS = IGAINN_GAIN_DEFAULT_Val;
  conf->calMeasInfo.UoffsetA = UOFFSETA_OFFSET_DEFAULT_Val;     /* Default */
  conf->calMeasInfo.UoffsetB = UOFFSETB_OFFSET_DEFAULT_Val;     /* Default */
  conf->calMeasInfo.UoffsetC = UOFFSETC_OFFSET_DEFAULT_Val;     /* Default */
  conf->calMeasInfo.IoffsetA = IOFFSETA_OFFSET_DEFAULT_Val;     /* Default */
  conf->calMeasInfo.IoffsetB = IOFFSETB_OFFSET_DEFAULT_Val;     /* Default */
  conf->calMeasInfo.IoffsetC = IOFFSETC_OFFSET_DEFAULT_Val;     /* Default */
  conf->calMeasInfo.IoffsetNS = IOFFSETN_OFFSET_DEFAULT_Val; 

  conf->calMetInfo.MC = 3200;                                   /* MC=3200 */
  conf->calMetInfo.PLconstH = 0x0430;                           /* MC=3200 */
  conf->calMetInfo.PLconstL = 0xE234;                           /* MC=3200 */
  conf->calMetInfo.PoffsetA = POFFSETA_OFFSET_DEFAULT_Val;      /* Default */
  conf->calMetInfo.QoffsetA = QOFFSETA_OFFSET_DEFAULT_Val;      /* Default */
  conf->calMetInfo.PoffsetB = POFFSETB_OFFSET_DEFAULT_Val;      /* Default */
  conf->calMetInfo.QoffsetB = QOFFSETB_OFFSET_DEFAULT_Val;      /* Default */
  conf->calMetInfo.PoffsetC = POFFSETC_OFFSET_DEFAULT_Val;      /* Default */
  conf->calMetInfo.QoffsetC = QOFFSETC_OFFSET_DEFAULT_Val;      /* Default */
  conf->calMetInfo.PgainA = PQGAINA_GAIN_DEFAULT_Val;           /* Default */
  conf->calMetInfo.PgainB = PQGAINB_GAIN_DEFAULT_Val;           /* Default */
  conf->calMetInfo.PgainC = PQGAINC_GAIN_DEFAULT_Val;           /* Default */
  conf->calMetInfo.PhiA = PHIA_DEFAULT_Val;                     /* Default */
  conf->calMetInfo.PhiB = PHIB_DEFAULT_Val;                     /* Default */
  conf->calMetInfo.PhiC = PHIC_DEFAULT_Val;                     /* Default */
  conf->calMetInfo.PoffsetAF = POFFSETAF_OFFSET_DEFAULT_Val;    /* Default */
  conf->calMetInfo.PoffsetBF = POFFSETBF_OFFSET_DEFAULT_Val;    /* Default */  
  conf->calMetInfo.PoffsetCF = POFFSETCF_OFFSET_DEFAULT_Val;    /* Default */   
  conf->calMetInfo.PgainAF = PGAINAF_GAIN_DEFAULT_Val;          /* Default */
  conf->calMetInfo.PgainBF = PGAINBF_GAIN_DEFAULT_Val;          /* Default */
  conf->calMetInfo.PgainCF = PGAINCF_GAIN_DEFAULT_Val;          /* Default */
  return ATM90EXX_DRV_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E36_DRV_ConfigureTask ( void )

 */
ATM90EXX_DRV_RESULT ATM90E36_DRV_ConfigureTask(void)
{
  uint16_t value;
  bool NOTok = false;
  
    /* Check the application's current state. */
  switch ( gATM90ExxDrvObj.confState )
  {
      case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT:
      {
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] INIT\r\n");
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW;
          break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_INIT_HW))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] INIT HW\r\n");
  #ifdef ATM90E3X_HAL_PMX_PIO_SUPPORT
          /* Set PM0-1 HW configuration in Normal Mode */
          ATM90E3X_DRV_set_PowerMode(ATM90E3X_POWER_MODE_NORMAL);
  #endif
          // ADDITIONAL TIME NEEDED AFTER HW INIT
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY;
          gATM90ExxDrvObj.confNextState = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW;
          gATM90ExxDrvObj.delayMs = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW_DELAY_MS;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_INIT_HW);
          break;
        }
      }   
      case ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_INIT_SW))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] INIT SW\r\n");
          /* Read MMDx HW configuration from EnStatus Register */
          //ATM90EXX_DRV_MeterMode();
        
          /* Reset the Device */
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SOFTRESET_ADDR, SOFTRESET_DEFAULT_Val);
        }
        if (NOTok)
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY;  
          gATM90ExxDrvObj.confNextState = ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS;
          gATM90ExxDrvObj.delayMs = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW_DELAY_MS;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_INIT_SW);
        }
        break;
      }
      /* Application's initial state. */
      case ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_NOSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] SPECIAL_REGS\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, FUNCEN0_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.FuncEn0);             
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, FUNCEN1_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.FuncEn1);             
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, ZXCONFIG_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ZXconfig);           
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SAGTH_ADDR       , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SagTh);            
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHASELOSSTH_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PhaseLossTh);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, INWARNTH_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.InWarnTh);      
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, INWARNTH1_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.InWarnTh1);    
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, THDNUTH_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.ThdNuTh);        
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, THDNITH_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.ThdNiTh);        
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, DMACTRL_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.DMACtrl);             
          if (NOTok)
          {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
          }
          else
          {
              // Update Status of registers
              gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0          = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.FuncEn0;       
              gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1          = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.FuncEn1;       
              gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.ZXconfig         = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.ZXconfig;      
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh       = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SagTh;    
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PhaseLossTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PhaseLossTh;
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh    = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.InWarnTh; 
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh1   = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.InWarnTh1;
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.ThdNuTh     = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.ThdNuTh;  
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.ThdNiTh     = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.ThdNiTh;  
              gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.DMACtrl          = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.DMACtrl;       
              // Change State
              gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIGSTART;
              ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_NOSTART);
          }
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIGSTART;
        }
        break;  
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIGSTART:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_CFGSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CFGSTART\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CONFIGSTART_ADDR, CONFIGSTART_STARTUP_Val);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PLCONSTH_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstH);   
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PLCONSTL_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstL);   
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, MMODE0_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode0);        
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, MMODE1_ADDR     , gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode1);       
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PSTARTTH_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PStartTh);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QSTARTTH_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QStartTh);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SSTARTTH_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SStartTh);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PPHASETH_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PPhaseTh); 
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QPHASETH_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QPhaseTh); 
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, SPHASETH_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SPhaseTh); 
          if (NOTok)
          {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
          }
          else
          {
            // Update Status of registers
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstH    = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstH;   
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstL    = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PLconstL;  
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode0        = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode0;       
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode1        = gATM90ExxDrvObj.atm90ExxObjConf.ctrlInfo.MMode1;            
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PStartTh;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.QStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QStartTh;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SStartTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SStartTh;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PPhaseTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.PPhaseTh;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.QPhaseTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.QPhaseTh;
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SPhaseTh = gATM90ExxDrvObj.atm90ExxObjConf.thresholdInfo.SPhaseTh;
            // Next State        
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CS0;
          }
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART; 
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CS0:
      {

        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CS0\r\n");
#ifdef ATM90EXX_DRV_CHECKSUM_CALC
        // TBD
#else
        NOTok |= ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CS0_ADDR, &value);
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CS0_ADDR, value);
#endif
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CONFIGSTART_ADDR, CONFIGSTART_FINISH_Val);
        if (NOTok)
        { 
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS0 = value;
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CALSTART;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_CFGSTART);
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CALSTART:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_CALSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CALSTART\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CALSTART_ADDR, CALSTART_STARTUP_Val);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETA_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETA_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETB_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETB_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETC_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetC);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, QOFFSETC_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetC);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PGAINA_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHIA_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PGAINB_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHIB_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PGAINC_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainC);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PHIC_ADDR    , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiC);             
          if (NOTok)
          {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
          }
          else
          {
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetA = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetA;
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetA = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetA;
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetB = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetB;
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetB = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetB;
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetC = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetC;
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetC = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.QoffsetC; 
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainA   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainA;    
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiA     = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiA;     
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainB   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainB;    
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiB     = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiB;     
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainC   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainC;    
            gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiC     = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PhiC;
            // Next State        
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CS1;    
          }
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_HARMSTART;
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CS1:
      {
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CS1\r\n");
#ifdef ATM90EXX_DRV_CHECKSUM_CALC
      // TBD - Calculate Checksum
#else
        NOTok |= ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CS1_ADDR, &value);
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CS1_ADDR, value);
#endif
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CALSTART_ADDR, CALSTART_FINISH_Val);

        if (NOTok)
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS1 = value;  
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_HARMSTART;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_CALSTART);
        }        
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_HARMSTART:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_HARMSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] HARMSTART\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, HARMSTART_ADDR, HARMSTART_STARTUP_Val);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETAF_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetAF);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETBF_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetBF);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, POFFSETCF_ADDR, gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetCF);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PGAINAF_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainAF);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PGAINBF_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainBF);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, PGAINCF_ADDR  , gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainCF);
          if (NOTok)
          {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
          }
          else
          {
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetAF = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetAF;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetBF = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetBF;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PoffsetCF = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PoffsetCF;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainAF   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainAF;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainBF   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainBF;
            gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PgainCF   = gATM90ExxDrvObj.atm90ExxObjConf.calMetInfo.PgainCF; 
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CS2;
          }
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART;
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CS2:
      {
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CS2\r\n");
#ifdef ATM90EXX_DRV_CHECKSUM_CALC
      // TBD - Calculate Checksum
#else
        NOTok |= ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CS2_ADDR, &value);
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CS2_ADDR, value);
#endif
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, HARMSTART_ADDR, HARMSTART_FINISH_Val);

        if (NOTok)
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS2 = value;  
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_HARMSTART);
        }        
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART:
      {
        if (ATM90EXX_CHK_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_ADJSTART))
        {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] ADJSTART\r\n");
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, ADJSTART_ADDR, ADJSTART_STARTUP_Val);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UGAINA_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINA_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UOFFSETA_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETA_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetA);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UGAINB_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINB_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UOFFSETB_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETB_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetB);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UGAINC_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainC);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINC_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainC);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, UOFFSETC_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetC);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETC_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetC);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IGAINN_ADDR   , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetNS);
          NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, IOFFSETN_ADDR , gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetNS);
          if (NOTok)
          {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
          }
          else
          {
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA    = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainA   ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainA    = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainA   ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UoffsetA  = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetA ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetA  = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetA ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainB    = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainB   ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainB    = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainB   ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UoffsetB  = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetB ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetB  = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetB ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainC    = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UgainC   ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainC    = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IgainC   ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UoffsetC  = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.UoffsetC ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetC  = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetC ;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetNS = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetNS;
            gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetNS = gATM90ExxDrvObj.atm90ExxObjConf.calMeasInfo.IoffsetNS;
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_CS3;
          }
        }
        else
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_END;
        }
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_CS3:
      {
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] CS3\r\n");
#ifdef ATM90EXX_DRV_CHECKSUM_CALC
      // TBD - Calculate Checksum
#else
        NOTok |= ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, CS3_ADDR, &value);
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, CS3_ADDR, value);
#endif
        NOTok |= ATM90EXX_HAL_write_reg(gATM90ExxDrvObj.handle, ADJSTART_ADDR, ADJSTART_FINISH_Val);

        if (NOTok)
        {
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR;
        }
        else
        {
          gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS3 = value;  
          gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_END;
          ATM90EXX_CLR_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_ADJSTART);
        }        
        break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_END:
      {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][CFG] END\r\n");
          break;
      }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY:
        {
            // Wait delay time
            if (ATM90EXX_DRV_TaskDelay(gATM90ExxDrvObj.delayMs, &gATM90ExxDrvObj.timer))
            {
                // Set next app state
                gATM90ExxDrvObj.confState = gATM90ExxDrvObj.confNextState;
            }
            break;
        }
      case ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR:
      {
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_FATAL, "[AD][CFG] ERROR\r\n");
          // Impossible to configure the device, requires full reconfiguration
          ATM90EXX_SET_FLAG(gATM90ExxDrvObj.configureFlags, CONFIG_FLAG_ALL);
          return ATM90EXX_DRV_ERROR;
      }
      /* The default state should never be executed. */
      default:
      {
          /* Nothing to do. */
          break;
      }
  }
  return ATM90EXX_DRV_SUCCESS;

}

#ifdef ATM90EXX_CALIBRATION_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E36_DRV_CalibrationTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E36_DRV_CalibrationTask (void)
{
    /* Check the application's calibration state. */
    switch ( gATM90ExxDrvObj.calibrationState )
    {
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_INIT:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][CAL] INIT\r\n");
            gATM90ExxDrvObj.calibrationState = ATM90EXX_DRV_CALIBRATION_TASK_STATE_END;
            break;
        }
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_END:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][CAL] END\r\n");
            break;
        }
        case ATM90EXX_DRV_CALIBRATION_TASK_STATE_ERROR:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_FATAL, "[AD][CAL] ERROR\r\n");
            return ATM90EXX_DRV_ERROR;
        }
    }
    return ATM90EXX_DRV_SUCCESS;
}
#endif

#if defined (ATM90EXX_IRQ_SUPPORT) || defined (ATM90EXX_DRV_POLL_INT_STATUS)
/*******************************************************************************
  Function:
    ATM90E36_DRV_RESULT ATM90EXX_DRV_CheckInterrupt ( void )

 */
ATM90EXX_DRV_RESULT ATM90E36_DRV_CheckInterruptsTask (void)
{
  bool updateFlag = false;

  ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][INT]\r\n");
  
  /* Read SysStatus0-1 Registers */
  ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SYSSTATUS0_ADDR, (uint16_t *)&gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0);
  ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SYSSTATUS1_ADDR, (uint16_t *)&gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1);
  /* Read EnStatus0-1 Registers */
  ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ENSTATUS0_ADDR, (uint16_t *)&gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus0);
  ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ENSTATUS1_ADDR, (uint16_t *)&gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus1);

#ifdef ATM90EXX_SAG_SUPPORT  
  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 & FUNCEN0_SAGWNEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_SAGWARN_Msk) == SYSSTATUS0_SAGWARN_Msk)
      {
          /* SAG Event */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.sagA = (gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus1 & ENSTATUS1_SAGPHASEA_Msk) ? 1 : 0;
          atm90ExxEvents.BIT.sagB = (gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus1 & ENSTATUS1_SAGPHASEB_Msk) ? 1 : 0;
          atm90ExxEvents.BIT.sagC = (gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus1 & ENSTATUS1_SAGPHASEC_Msk) ? 1 : 0;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] SAG\r\n");
      }
  }
#endif
#ifdef ATM90EXX_PHASE_LOSS_SUPPORT  
  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 & FUNCEN0_PHASELOSSWNEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_PHASELOSEWN_Msk) == SYSSTATUS0_PHASELOSEWN_Msk)
      {
          /* Phase Loss Event */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.pLossVA = (gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus1 & ENSTATUS1_PHASELOSSA_Msk) ? 1 : 0;
          atm90ExxEvents.BIT.pLossVB = (gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus1 & ENSTATUS1_PHASELOSSB_Msk) ? 1 : 0;
          atm90ExxEvents.BIT.pLossVC = (gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus1 & ENSTATUS1_PHASELOSSC_Msk) ? 1 : 0;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] Phase Loss X\r\n");
      }
  }
#endif

#ifdef ATM90EXX_PHASE_SEQUENCE_SUPPORT  
  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 & FUNCEN0_UREVWNEN_Msk)
  {
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_UREVWN_Msk) == SYSSTATUS0_UREVWN_Msk)
    {
        /* Voltage Sequence Error Event */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.phaseSeqV = 1;
        updateFlag = true;
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] Voltage Phase Sequence\r\n");
    }
  }
  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 & FUNCEN0_IREVWNEN_Msk)
  {
    if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_IREVWN_Msk) == SYSSTATUS0_IREVWN_Msk)
    {
        /* Current Sequence Error Event */
        /* Create EVENT to notify */
        atm90ExxEvents.BIT.phaseSeqC = 1;
        updateFlag = true;
        ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] Current Phase Sequence\r\n");
    }
  }
#endif

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVPCHGTEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVPCHGT_Msk) == SYSSTATUS1_REVPCHGT_Msk)
      {
          /* Change in Active Energy Direction */
          /* Refresh the information about the Active Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.ptDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] ptDir\r\n");
      }
  }
  
  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVPCHGAEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVPCHGA_Msk) == SYSSTATUS1_REVPCHGA_Msk)
      {
          /* Change in Active Energy Direction */
          /* Refresh the information about the Active Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.paDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] paDir\r\n");
      }
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVPCHGBEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVPCHGB_Msk) == SYSSTATUS1_REVPCHGB_Msk)
      {
          /* Change in Active Energy Direction */
          /* Refresh the information about the Active Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.pbDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] pbDir\r\n");
      }
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVPCHGCEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVPCHGC_Msk) == SYSSTATUS1_REVPCHGC_Msk)
      {
          /* Change in Active Energy Direction */
          /* Refresh the information about the Active Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.pcDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] pcDir\r\n");
      }
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVQCHGTEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVQCHGT_Msk) == SYSSTATUS1_REVQCHGT_Msk)
      {
          /* Change in Reactive Energy Direction */
          /* Refresh the information about the Reactive Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.qtDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] QDIR\r\n");
      }
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVQCHGAEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVQCHGA_Msk) == SYSSTATUS1_REVQCHGA_Msk)
      {
          /* Change in Reactive Energy Direction */
          /* Refresh the information about the Reactive Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.qaDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] qaDir\r\n");
      }
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVQCHGBEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVQCHGB_Msk) == SYSSTATUS1_REVQCHGB_Msk)
      {
          /* Change in Reactive Energy Direction */
          /* Refresh the information about the Reactive Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.qbDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] qbDir\r\n");
      }
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_REVQCHGCEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_REVQCHGC_Msk) == SYSSTATUS1_REVQCHGC_Msk)
      {
          /* Change in Reactive Energy Direction */
          /* Refresh the information about the Reactive Energy Direction */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.qcDir = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] qcDir\r\n");
      }
  }

#ifdef ATM90EXX_THD_SUPPORT
  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_THDIOVEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_THDIO_Msk) == SYSSTATUS1_THDIO_Msk)
      {
          /* THD in Current higher than threshold */
          /* Refresh the information */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.thdi = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] THD Current\r\n");
      }
  }

  if (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_THDUOVEN_Msk)
  {
      if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_THDUO_Msk) == SYSSTATUS1_THDUO_Msk)
      {
          /* THD in Current higher than threshold */
          /* Refresh the information */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.thdu = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] THD Voltage\r\n");
      }
  }
#endif

#ifdef ATM90EXX_OVER_CURRENT_SUPPORT  
  // Only overcurrent on Neutral Calculated/Measured
  if ((gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_INOV0EN_Msk) ||
      (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn1 & FUNCEN1_INOV1EN_Msk))
  {
      if (((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_INOV0_Msk) == SYSSTATUS1_INOV0_Msk) ||
          ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus1 & SYSSTATUS1_INOV1_Msk) == SYSSTATUS1_INOV1_Msk))
      {
          /* Over Current in Neutral Current */
          /* Create EVENT to notify */
          atm90ExxEvents.BIT.overCN = 1;
          updateFlag = true;
          ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] OverCN\r\n");
      }
  }
#endif

#ifdef ATM90EXX_NOLOAD_SUPPORT
#ifdef ATM90EXX_NOLOAD_ACTIVE_SUPPORT
  if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus0 & ENSTATUS0_TPNOLOAD_Msk) == ENSTATUS0_TPNOLOAD_Msk)
  {
      /* Active No-load status */
      /* Create EVENT to notify */
      atm90ExxEvents.BIT.noloadAP = 1;
      updateFlag = true;
      ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] noloadAP\r\n");
  }
#endif
#ifdef ATM90EXX_NOLOAD_REACTIVE_SUPPORT
  if ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus0 & ENSTATUS0_TQNOLOAD_Msk) == ENSTATUS0_TQNOLOAD_Msk)
  {
      /* Reactive No-load Status */
      /* Create EVENT to notify */
      atm90ExxEvents.BIT.noloadAQ = 1;
      updateFlag = true;
      ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] noloadAQ\r\n");
  }
#endif
#ifdef ATM90EXX_NOLOAD_APPARENT_SUPPORT
  if (((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus0 & ENSTATUS0_TASNOLOAD_Msk) == ENSTATUS0_TASNOLOAD_Msk) ||
      ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus0 & ENSTATUS0_TVSNOLOAD_Msk) == ENSTATUS0_TVSNOLOAD_Msk))
  {
      /* Reactive No-load Status */
      /* Create EVENT to notify */
      atm90ExxEvents.BIT.noloadAS = 1;
      updateFlag = true;
      ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] noloadAS\r\n");
  }
#endif
#endif

#ifdef ATM90EXX_HARD_ERR_SUPPORT
  if (((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_CS3_Msk) == SYSSTATUS0_CS3_Msk) || 
      ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_CS2_Msk) == SYSSTATUS0_CS2_Msk) || 
      ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_CS1_Msk) == SYSSTATUS0_CS1_Msk) || 
      ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus0 & SYSSTATUS0_CS0_Msk) == SYSSTATUS0_CS0_Msk))
  {
      /* Configuration Error requires reload configuration */
      /* Create EVENT to notify */
      atm90ExxEvents.BIT.hardErr = 1;
      updateFlag = true;
      ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][INT] hardErr\r\n");      
  }
#endif
  gATM90ExxDrvObj.checkIntState = ATM90EXX_DRV_CHECK_INT_TASK_STATE_END;
  return updateFlag;
}
#endif
#endif

#ifdef ATM90E3X_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90E32_DRV_RefreshInfoTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90E3X_DRV_RefreshInfoTask(void)
{
    uint16_t value;
    
    /* Check the application's refresh info state. */
    switch ( gATM90ExxDrvObj.refreshInfoState )
    {
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_INIT:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] INIT\r\n");
#ifdef ATM90EXX_DRV_POLL_INT_STATUS
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_STATUS;
#else
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_A;
#endif
            break;
        }
#ifdef ATM90EXX_DRV_POLL_INT_STATUS
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_STATUS:
        {
            ATM90EXX_DRV_CheckInterruptsTask();
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_A;
            break;
        }       
#endif  
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_A:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MEAS A\r\n");
#ifdef METROLOGY_URMS_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, URMSA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsA = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, URMSALSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsALSB = value;
#endif
#ifdef METROLOGY_UPEAK_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, UPEAKA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UPeakA = value;
#endif
#ifdef METROLOGY_IRMS_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsA = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSALSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsALSB = value;
#endif
#ifdef METROLOGY_IPEAK_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IPEAKA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IPeakA = value;
#endif
#ifdef METROLOGY_PMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanA = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANALSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanALSB = value;
#ifdef METROLOGY_PMEANF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANAF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAF = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANAFLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAFLSB = value;
#endif
#ifdef METROLOGY_PMEANH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANAH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAH = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANAHLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAHLSB = value;
#endif            
#endif
#ifdef METROLOGY_QMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanA = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANALSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanALSB = value;
#endif
#ifdef METROLOGY_SMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEANA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanA = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEANALSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanALSB = value;
#endif
#ifdef METROLOGY_PFMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PFMEANA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanA = value;
#endif
#ifdef METROLOGY_PHASE_VX_IX_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PANGLEA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PAngleA = value;
#endif
#ifdef METROLOGY_PHASE_VX_VA_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, UANGLEA_ADDR, &value);
            //gATM90ExxDrvObj.atm90ExxObj.measInfo.UAngleA = 0;
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UAngleA = value;
#endif           
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_B;
            break;
        }
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_B:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MEAS B\r\n");
#ifdef METROLOGY_URMS_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, URMSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsB = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, URMSBLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsBLSB = value;
#endif
#ifdef METROLOGY_UPEAK_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, UPEAKB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UPeakB = value;
#endif
#ifdef METROLOGY_IRMS_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsB = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSBLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsBLSB = value;
#endif
#ifdef METROLOGY_IPEAK_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IPEAKB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IPeakB = value;
#endif
#ifdef METROLOGY_PMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanB = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANBLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBLSB = value;
#ifdef METROLOGY_PMEANF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANBF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBF = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANBFLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBFLSB = value;
#endif
#ifdef METROLOGY_PMEANH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANBH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBH = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANBHLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBHLSB = value;
#endif            
#endif
#ifdef METROLOGY_QMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanB = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANBLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanBLSB = value;
#endif
#ifdef METROLOGY_SMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEANB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanB = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEANBLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanBLSB = value;
#endif
#ifdef METROLOGY_PFMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PFMEANB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanB = value;
#endif
#ifdef METROLOGY_PHASE_VX_IX_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PANGLEB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PAngleB = value;
#endif
#ifdef METROLOGY_PHASE_VX_VA_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, UANGLEB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UAngleB = value;
#endif
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_C;
            break;
        }
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_C:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MEAS C\r\n");
#ifdef METROLOGY_URMS_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, URMSC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsC = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, URMSCLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsCLSB = value;
#endif
#ifdef METROLOGY_UPEAK_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, UPEAKC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UPeakC = value;
#endif
#ifdef METROLOGY_IRMS_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsC = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSCLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsCLSB = value;
#endif
#ifdef METROLOGY_IPEAK_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IPEAKC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IPeakC = value;
#endif
#ifdef METROLOGY_PMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanC = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANCLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCLSB = value;
#ifdef METROLOGY_PMEANF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANCF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBF = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANCFLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBFLSB = value;
#endif
#ifdef METROLOGY_PMEANH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANCH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCH = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANCHLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCHLSB = value;
#endif            
#endif
#ifdef METROLOGY_QMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanC = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANCLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanCLSB = value;
#endif
#ifdef METROLOGY_SMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEANC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanC = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SMEANCLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanCLSB = value;
#endif
#ifdef METROLOGY_PFMEAN_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PFMEANC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanC = value;
#endif
#ifdef METROLOGY_PHASE_VX_IX_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PANGLEC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PAngleC = value;
#endif
#ifdef METROLOGY_PHASE_VX_VA_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, UANGLEC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.UAngleC = value;
#endif
#ifdef METROLOGY_MEASURING_TOTAL_SUPPORT
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_TOTAL;
#else
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_A;
#endif
            break;
        }
#ifdef METROLOGY_MEASURING_TOTAL_SUPPORT
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_TOTAL:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MEAS TOTAL\r\n");
#ifdef METROLOGY_PMEANT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanT = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PMEANTLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTLSB = value;
#endif
#ifdef METROLOGY_QMEANT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanT = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, QMEANTLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanTLSB = value;
#endif
#ifdef METROLOGY_SMEANT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SAMEANT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SAmeanT = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SAMEANTLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SAmeanTLSB = value; 
#ifdef ATM90E36_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SVMEANT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SAmeanT = value;
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, SVMEANTLSB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.SAmeanTLSB = value;
#endif 
#endif
#ifdef METROLOGY_PFMEANT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, PFMEANT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanT = value;
#endif  
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_A;
            break;
        }
#endif
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_A:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MET A\r\n");
#ifdef METROLOGY_APENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyA += value;
#ifdef METROLOGY_APENERGYF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYAF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAF += value;
#endif // METROLOGY_APENERGYF_SUPPORT
#ifdef METROLOGY_APENERGYH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYAH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAH += value;
#endif // METROLOGY_APENERGYH_SUPPORT
#endif // METROLOGY_APENERGY_SUPPORT
#ifdef METROLOGY_ANENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyA += value;
#ifdef METROLOGY_ANENERGYF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYAF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAF += value;
#endif // METROLOGY_ANENERGYF_SUPPORT
#ifdef METROLOGY_ANENERGYH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYAH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAH += value;
#endif // METROLOGY_ANENERGYH_SUPPORT
#endif // METROLOGY_ANENERGY_SUPPORT
#ifdef METROLOGY_RPENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RPENERGYA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyA += value;
#endif
#ifdef METROLOGY_RNENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RNENERGYA_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyA += value;
#endif      
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_B;
            break;
        }  
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_B:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MET B\r\n");
#ifdef METROLOGY_APENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyB += value;
#ifdef METROLOGY_APENERGYF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYBF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBF += value;
#endif // METROLOGY_APENERGYF_SUPPORT
#ifdef METROLOGY_APENERGYH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYBH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBH += value;
#endif // METROLOGY_APENERGYH_SUPPORT
#endif // METROLOGY_APENERGY_SUPPORT
#ifdef METROLOGY_ANENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyB += value;
#ifdef METROLOGY_ANENERGYF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYBF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBF += value;
#endif // METROLOGY_ANENERGYF_SUPPORT
#ifdef METROLOGY_ANENERGYH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYBH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBH += value;
#endif // METROLOGY_ANENERGYH_SUPPORT
#endif // METROLOGY_ANENERGY_SUPPORT
#ifdef METROLOGY_RPENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RPENERGYB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyB += value;
#endif
#ifdef METROLOGY_RNENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RNENERGYB_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyB += value;
#endif  
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_C;
            break;
        } 
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_C:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MET C\r\n");
#ifdef METROLOGY_APENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyC += value;
#ifdef METROLOGY_APENERGYF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYCF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCF += value;
#endif // METROLOGY_APENERGYF_SUPPORT
#ifdef METROLOGY_APENERGYH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYCH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCH += value;
#endif // METROLOGY_APENERGYH_SUPPORT
#endif // METROLOGY_APENERGY_SUPPORT
#ifdef METROLOGY_ANENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyC += value;
#ifdef METROLOGY_ANENERGYF_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYCF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCF += value;
#endif // METROLOGY_ANENERGYF_SUPPORT
#ifdef METROLOGY_ANENERGYH_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYCH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCH += value;
#endif // METROLOGY_ANENERGYH_SUPPORT
#endif // METROLOGY_ANENERGY_SUPPORT
#ifdef METROLOGY_RPENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RPENERGYC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyC += value;
#endif
#ifdef METROLOGY_RNENERGY_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RNENERGYC_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyC += value;
#endif
#ifdef METROLOGY_METERING_TOTAL_SUPPORT
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_TOTAL;
#else
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_OTHERS;
#endif
            break;
        }
#ifdef METROLOGY_METERING_TOTAL_SUPPORT
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_TOTAL:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] MET TOTAL\r\n");
#ifdef METROLOGY_APENERGYT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyT += value;
#ifdef METROLOGY_APENERGYFT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYTF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTF += value;
#endif // METROLOGY_APENERGYF_SUPPORT
#ifdef METROLOGY_APENERGYHT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, APENERGYTH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTH += value;
#endif // METROLOGY_APENERGYH_SUPPORT
#endif // METROLOGY_APENERGY_SUPPORT
#ifdef METROLOGY_ANENERGYT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyT += value;
#ifdef METROLOGY_ANENERGYFT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYTF_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTF += value;
#endif // METROLOGY_ANENERGYF_SUPPORT
#ifdef METROLOGY_ANENERGYHT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, ANENERGYTH_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTH += value;
#endif // METROLOGY_ANENERGYHT_SUPPORT
#endif // METROLOGY_ANENERGYT_SUPPORT
#ifdef METROLOGY_RPENERGYT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RPENERGYT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyT += value;
#endif // METROLOGY_RPENERGYT_SUPPORT
#ifdef METROLOGY_RNENERGYT_SUPPORT
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, RNENERGYT_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyT += value;
#endif
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_OTHERS;
            //break; /* Go Directly to STATE_END */
        }
#endif
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_OTHERS:
        {
#ifdef METROLOGY_IRMS_SUPPORT
            // Neutral Current Calculated
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSN_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsNC = value;
#ifdef ATM90E36_SUPPORT
            // Neutral Current Sampled
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, IRMSNS_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsNS = value;
#endif
#endif          
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[AD][RI] OTHERS\r\n");
            // Frequency 
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, FREQ_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Freq = value;
            // Temperature
            ATM90EXX_HAL_read_reg(gATM90ExxDrvObj.handle, TEMP_ADDR, &value);
            gATM90ExxDrvObj.atm90ExxObj.measInfo.Temp = value;            
            // Next State
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_END;
            break;
        }        
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_END:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_INFO, "[AD][RI] END\r\n");
            break;
        }
        case ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_ERROR:
        {
            ATM90EXX_DEBUG_MESSAGE(SYS_ERROR_FATAL, "[AD][RI] ERROR\r\n");
            return ATM90EXX_DRV_ERROR;
        }
    }
    return ATM90EXX_DRV_SUCCESS;
} 
#endif

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_ConfigureTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_CheckInterruptsTask(void)
{
    bool updateFlag;
#ifdef ATM90E26_SUPPORT
    updateFlag = ATM90E26_DRV_CheckInterruptsTask();
#endif
#ifdef ATM90E32_SUPPORT
    updateFlag = ATM90E32_DRV_CheckInterruptsTask();
#endif
#ifdef ATM90E36_SUPPORT
    updateFlag = ATM90E36_DRV_CheckInterruptsTask();
#endif
    if (updateFlag)
    {
        /* Operations at Application Level */
        if ((gATM90ExxDrvObj.eventCallback != NULL))
        {
            gATM90ExxDrvObj.eventCallback(atm90ExxEvents.events);
        }
    }
    return updateFlag;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_ConfigureTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_ConfigureTask(void)
{
#ifdef ATM90E26_SUPPORT
  return ATM90E26_DRV_ConfigureTask();
#endif
#ifdef ATM90E32_SUPPORT
  return ATM90E32_DRV_ConfigureTask();
#endif
#ifdef ATM90E36_SUPPORT
  return ATM90E36_DRV_ConfigureTask();
#endif
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_RefreshInfoTask ( void )

  Remarks:
    See prototype in app_test.h.
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_RefreshInfoTask(void)
{
#ifdef ATM90E26_SUPPORT
  return ATM90E26_DRV_RefreshInfoTask();
#endif
#ifdef ATM90E32_SUPPORT
  return ATM90E3X_DRV_RefreshInfoTask();
#endif
#ifdef ATM90E36_SUPPORT
  return ATM90E3X_DRV_RefreshInfoTask();
#endif
}


/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_read_reg ( uint16_t reg, uint16_t *value )

  Remarks:
    Direct Access To read HW registers 
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_read_reg ( uint16_t addr, uint16_t *val )
{

  if (val != NULL)
  {
    return ATM90EXX_HAL_read_reg( gATM90ExxDrvObj.handle, addr, val);
  }

  uint16_t lvalue;
  uint16_t *value = &lvalue;

    if (ATM90EXX_HAL_read_reg( gATM90ExxDrvObj.handle, addr, value) == ATM90EXX_HAL_SUCCESS)
    {
        /* Update Information on ATM90EXX Structure to synchro information */
        switch (addr)
        {
#ifdef ATM90E26_SUPPORT
            case SYSSTATUS_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.statusInfo.SysStatus = *value;
              break;
            case FUNCEN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn = *value;
              break;
            case SAGTH_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh = *value;
              break;
            case SMALLPMOD_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.SmallPMod = *value;
              break; 
            case PLCONSTH_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstH = *value;
              break;
            case PLCONSTL_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMetInfo.PLconstL = *value;
              break;   
            case LGAIN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Lgain = *value;
              break;      
            case LPHI_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Lphi = *value;
              break;     
            case NGAIN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Ngain = *value;
              break;       
            case NPHI_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMetInfo.Nphi = *value;
              break; 
            case PSTARTTH_ADDR:  
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PStartTh = *value; 
              break;  
            case PNOLTH_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PNolTh = *value;
              break;  
            case QSTARTTH_ADDR:  
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.QStartTh = *value;
              break;
            case QNOLTH_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.QNolTh = *value;
              break;     
            case MMODE_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode = *value;
              break;
            case UGAIN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.Ugain = *value;
              break;
            case IGAINL_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainL = *value;
              break;
            case IGAINN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainN = *value;
              break;     
            case UOFFSET_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.Uoffset = *value;
              break;    
            case IOFFSETL_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetL = *value;
              break;
            case IOFFSETN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IoffsetN = *value;
              break;   
            case POFFSETL_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.PoffsetL = *value;
              break;      
            case POFFSETN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.PoffsetN = *value;
              break;     
            case QOFFSETL_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.QoffsetL = *value;
              break;   
            case QOFFSETN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.QoffsetN = *value;
              break;    
            case APENERGY_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergy += *value;
              break;    
            case ANENERGY_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergy += *value;
              break;   
            case ATENERGY_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.metInfo.ATEnergy += *value;
              break;   
            case RPENERGY_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergy += *value;
              break;   
            case RNENERGY_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergy += *value;
              break;   
            case RTENERGY_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.metInfo.RTEnergy += *value;
              break;   
            case ENSTATUS_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus = *value;
              break;   		
            case IRMS_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms = *value;
              break;          
            case URMS_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Urms = *value;
              break;        
            case PMEAN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean = *value;
              break;       
            case QMEAN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean = *value;
              break;       
            case FREQ_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Freq = *value;
              break;        
            case POWERF_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.PowerF = *value;
              break;      
            case PANGLE_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Pangle = *value;
              break;      
            case SMEAN_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean = *value;
              break;       	
            case IRMS2_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms2 = *value;
              break;       
            case PMEAN2_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean2 = *value;
              break;      
            case QMEAN2_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean2 = *value;
              break;      
            case POWERF2_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.PowerF2 = *value;
              break;     
            case PANGLE2_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Pangle2 = *value;
              break;     
            case SMEAN2_ADDR:
              gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean2 = *value;
              break;     	
            case CS1_ADDR:
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS1 = *value;
                break;
            case CS2_ADDR:
                gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.CS2 = *value;
                break;
            case LASTSPIDATA_ADDR: 
            case CALSTART_ADDR:
            case ADJSTART_ADDR:
                break;
#endif
        default:
            break;
    }
    return ATM90EXX_DRV_SUCCESS;
  }

  return ATM90EXX_DRV_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_write_reg ( uint16_t reg, uint16_t *value )

  Remarks:
    Direct Access To write HW registers
 */
bool ATM90EXX_DRV_write_reg ( uint16_t addr, uint16_t value )
{
  return ATM90EXX_HAL_write_reg( gATM90ExxDrvObj.handle, addr, value );
}

/*******************************************************************************
  Function:
    void DRV_ATM90EXX_GetStatus ( void )

  Remarks:
    Get Task Status
 */
ATM90EXX_DRV_STATUS ATM90EXX_DRV_GetStatus(void)
{
    return gATM90ExxDrvObj.status;
}

//ATM90EXX_DRV_RESULT DRV_ATM90EXX_CalibrationCallbackRegister(DRV_ATM90EXX_CALIBRATION_CALLBACK callback);

//DRV_ATM90EXX_REGS_CONTROL * DRV_ATM90EXX_GetControlData(void);

//DRV_ATM90EXX_REGS_CONTROL * DRV_ATM90EXX_GetControlByDefault(void);

//DRV_ATM90EXX_REGS_STATUS * DRV_ATM90EXX_GetStatusData(void);

//DRV_ATM90EXX_REGS_ACCUMULATORS * DRV_ATM90EXX_GetAccData(void);

//void DRV_ATM90EXX_SetControl(DRV_ATM90EXX_REGS_CONTROL * pControl);

//uint32_t DRV_ATM90EXX_GetEnergyValue(bool restartEnergy);

//uint32_t DRV_ATM90EXX_GetRMSValue(DRV_ATM90EXX_RMS_TYPE type);

//DRV_ATM90EXX_RMS_SIGN DRV_ATM90EXX_GetRMSSign(DRV_ATM90EXX_RMS_TYPE type);

//void DRV_ATM90EXX_SetConfiguration(DRV_ATM90EXX_CONFIGURATION * config);

//void DRV_ATM90EXX_GetEventsData(DRV_ATM90EXX_AFE_EVENTS * events)

//DRV_ATM90EXX_CALIBRATION_REFS * DRV_ATM90EXX_GetCalibrationReferences(void);


/******************************************************************************
  Function:
    void APP_TEST_Tasks ( void )

  Remarks:
    See prototype in app_test.h.
 */

void ATM90EXX_DRV_Tasks ( void )
{

  //  if (object == SYS_MODULE_OBJ_INVALID)
  //  {
  //      /* Invalid system object */
  //      return;
  //  }

    /* Check the application's current state. */
    switch ( gATM90ExxDrvObj.state )
    {
        case ATM90EXX_DRV_MAIN_TASK_STATE_INIT:
        {
          break;
        }
        case ATM90EXX_DRV_MAIN_TASK_STATE_CONFIGURE_INIT:
        {
            gATM90ExxDrvObj.confState = ATM90EXX_DRV_CONFIG_TASK_STATE_INIT;
            gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CONFIGURE;
            gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_CONFIGURING;
            
            /* Disable Integration Period Process */
            ATM90EXX_HAL_stop_integration_period(gATM90ExxDrvObj.integrationPeriodHandle);
            gATM90ExxDrvObj.integrationFlag = 0;

#ifdef ATM90EXX_IRQ_SUPPORT            
            /* Disable HW Interrupts */
            ATM90EXX_HAL_disable_interrupts();
#if defined(ATM90EXX_IRQ_COMMON_SUPPORT)            
            gATM90ExxDrvObj.interruptFlag = 0;
#else
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT  
            gATM90ExxDrvObj.int0InterruptFlag = 0;
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT  
            gATM90ExxDrvObj.int1InterruptFlag = 0;
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT  
            gATM90ExxDrvObj.warnoutInterruptFlag = 0;
#endif  
#endif
#endif
            break;
        }
        /* Application's initial state. */
        case ATM90EXX_DRV_MAIN_TASK_STATE_CONFIGURE:
        {
          ATM90EXX_DRV_ConfigureTask();
          if (gATM90ExxDrvObj.confState == ATM90EXX_DRV_CONFIG_TASK_STATE_END)
          {
              gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_READY;
              gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_START;
#ifdef ATM90EXX_IRQ_SUPPORT
              ATM90EXX_HAL_enable_interrupts();
#endif              
              if (gATM90ExxDrvObj.reconfigureFlag == true)
              {
                  // We came from a reconfiguration process, so starts automatically
                  ATM90EXX_DRV_Start(gATM90ExxDrvObj.integrationPeriod);
                  gATM90ExxDrvObj.reconfigureFlag = false;
              }
          } 
          break;  
        }
        case ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_START:
        {
            if (gATM90ExxDrvObj.startFlag)
            {
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT;
                gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_RUNNING;
                break;
            }
            break;
        }
        case ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT:
        {
            if (!gATM90ExxDrvObj.startFlag)
            {
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_START;
                gATM90ExxDrvObj.status = METROLOGY_DRV_STATUS_STOP;
            }
            if (gATM90ExxDrvObj.reconfigureFlag)
            {
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CONFIGURE_INIT;
                break;
            }
            if (gATM90ExxDrvObj.integrationFlag)
            {
                gATM90ExxDrvObj.integrationFlag = false;
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_REFRESH_INFO_INIT;
                break;
            }
#ifdef ATM90EXX_IRQ_SUPPORT
#ifdef ATM90EXX_IRQ_COMMON_SUPPORT
            if (gATM90ExxDrvObj.interruptFlag)
            {
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT_INIT;
                break;
            }
#else
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT  
            if (gATM90ExxDrvObj.int0InterruptFlag)
            {
                //gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT0_INIT;
                break;
            }              
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT  
            if (gATM90ExxDrvObj.int1InterruptFlag)
            {
                //gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT1_INIT;
                break;
            }
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT  
            if (gATM90ExxDrvObj.warnoutInterruptFlag)
            {
                //gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_WARNOUT_INIT;
                break;
            }
#endif              
#endif
#endif
#ifdef ATM90EXX_CALIBRATION_SUPPORT
            if (gATM90ExxDrvObj.calibrationFlag)
            {
                gATM90ExxDrvObj.state = ATM90EXX_DRV_TASK_STATE_CALIBRATION_INIT;
                break;
            }
#endif
            break;
        }
#ifdef ATM90EXX_IRQ_SUPPORT    
#if defined(ATM90EXX_IRQ_COMMON_SUPPORT)
        case ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT_INIT:
        {
          gATM90ExxDrvObj.checkIntState = ATM90EXX_DRV_CHECK_INT_TASK_STATE_INIT;
          gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT;
          break;
        }
        case ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT:
        {
            /* Check HW ATM90EXX Interrupt */
            ATM90EXX_DRV_CheckInterruptsTask();
            if (gATM90ExxDrvObj.checkIntState == ATM90EXX_DRV_CHECK_INT_TASK_STATE_END)
            {
                gATM90ExxDrvObj.interruptFlag = 0;
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT;
            }
            break;
        }
#else      
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT  
        case ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT0_INIT:
        {
          gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT;
          gATM90ExxDrvObj.int0InterruptFlag = 0;
          break;
        }
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT  
        case ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT1_INIT:
        {
          gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT;
          gATM90ExxDrvObj.int1InterruptFlag = 0;
          break;
        }
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT  
        case ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_WARNOUT_INIT:
        {
          gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT;
          gATM90ExxDrvObj.warnoutInterruptFlag = 0;
          break;
        }
#endif
#endif 
#endif
        case ATM90EXX_DRV_MAIN_TASK_STATE_REFRESH_INFO_INIT:
        {
            gATM90ExxDrvObj.refreshInfoState = ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_INIT;
            gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_REFRESH_INFO;
            break;
        }
        case ATM90EXX_DRV_MAIN_TASK_STATE_REFRESH_INFO:
        {
            /* Integration Period Interrupt, refresh ATM90EXX info */
            ATM90EXX_DRV_RefreshInfoTask();
            if (gATM90ExxDrvObj.refreshInfoState == ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_END)
            {
                gATM90ExxDrvObj.integrationFlag = 0;
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT;
                if (gATM90ExxDrvObj.integrationCallback != NULL){
                    gATM90ExxDrvObj.integrationCallback();
                }
            }
            break;
        }
#ifdef ATM90EXX_CALIBRATION_SUPPORT
        case ATM90EXX_DRV_MAIN_TASK_STATE_CALIBRATION_INIT:
        {
            /* Calibrating */
            gATM90ExxDrvObj.calibrationState = ATM90EXX_DRV_TASK_CALIBRATION_STATE_INIT;
            gATM90ExxDrvObj.state = ATM90EXX_DRV_TASK_STATE_CALIBRATION;
            /* Disable Integration Period */
            //ATM90EXX_HAL_stop_integration_period();
            //ATM90EXX_HAL_disable_interrupts();
            break;
        }  
        case ATM90EXX_DRV_MAIN_TASK_STATE_CALIBRATION:
        {
            /* Calibrating */
            ATM90EXX_DRV_CalibrateTask();
            if (gATM90ExxDrvObj.calibrationState == ATM90EXX_DRV_CAL_TASK_STATE_FINISHED)
            {
                gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_CALIBRATION_END;
            }
            break;
        } 
        case ATM90EXX_DRV_MAIN_TASK_STATE_CALIBRATION_END:
        {
            gATM90ExxDrvObj.calibrationFlag = 0;
            gATM90ExxDrvObj.state = ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT;
            if (gATM90ExxDrvObj.calibrationCallback != NULL){
                    gATM90ExxDrvObj.calibrationCallback();
            }
            break;
        } 
#endif
        case ATM90EXX_DRV_MAIN_TASK_STATE_ERROR:
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_FATAL, "ATM90EXX driver error\r\n");
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
