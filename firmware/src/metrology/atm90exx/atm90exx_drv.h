/*******************************************************************************
  Interface definition of ATM90EXX Driver.

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_drv.h

  Summary:
    Interface definition of the ATM90EXX Driver.

  Description:
    This file defines the interface for the ATM90EXX driver.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END

#ifndef ATM90EXX_DRV_H
#define ATM90EXX_DRV_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "system/system.h"
#include "device.h"
#include "configuration.h"
#include "../metrology_conf.h"
#include "../metrology_defs.h"
#include "../metrology_api.h"
#include "atm90exx_conf.h"
#include "atm90exx_defs.h"
#include "atm90exx_regs.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

#define ATM90EXX_SET_FLAG(n, f) ((n) |= (f)) 
#define ATM90EXX_CLR_FLAG(n, f) ((n) &= ~(f)) 
#define ATM90EXX_TGL_FLAG(n, f) ((n) ^= (f)) 
#define ATM90EXX_CHK_FLAG(n, f) ((n) & (f))
        
#define MET_CAPTURE_BUF_SIZE     DRV_ATM90EXX_CAPTURE_BUF_SIZE

#define ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW_DELAY_MS  100       
#define ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW_DELAY_MS  100
        
// *****************************************************************************
/* ATM90EXX Driver Result

  Summary:
    Result of a ATM90EXX driver interface operation.

  Description:
    Identifies the result of certain ATM90EXX driver operations.
*/

typedef enum {
    ATM90EXX_DRV_SUCCESS,
    ATM90EXX_DRV_ERROR
} ATM90EXX_DRV_RESULT;

// *****************************************************************************
/* ATM90EXX Driver Start mode

  Summary:
    Describes how the startup process is.

  Description:
    HARD mode implies a full reload of Core 1 application. SOFT mode does not
    any effects on Core 1 application.
*/
typedef enum {
    ATM90EXX_DRV_START_SOFT,
    ATM90EXX_DRV_START_HARD
} ATM90EXX_DRV_START_MODE;

/* ATM90EXX Driver Status

  Summary:
    Defines the status of the DRV_METROLOGY driver.

  Description:
    This enumeration defines the status of the DRV_METROLOGY Driver:
        - METROLOGY_DRV_STATUS_UNINITIALIZED: Metrology driver has not been initialized.
        - METROLOGY_DRV_STATUS_BUSY
        - METROLOGY_DRV_STATUS_READY: Metrology driver is ready to be used.
        - METROLOGY_DRV_STATUS_STOP: Metrology driver has been initialized but not opened.
        - METROLOGY_DRV_STATUS_CONFIGURING: Metrology driver is waiting the init IPC interrupt
        from the metrology lib as part of the opening routine.
        - METROLOGY_DRV_STATUS_CALIBRATING: IPC interrupt has been triggered indicating that DSP
        filters has been stabilized to full accuracy.
        - DRV_METROLOGY_STATUS_RUNNING: Metrology library is running and periodic data
        acquisition is performed.

  Remarks:
    None.
*/
typedef enum {
    METROLOGY_DRV_STATUS_UNINITIALIZED = SYS_STATUS_UNINITIALIZED,
    METROLOGY_DRV_STATUS_BUSY = SYS_STATUS_BUSY,
    METROLOGY_DRV_STATUS_READY = SYS_STATUS_READY,
    METROLOGY_DRV_STATUS_RUNNING = SYS_STATUS_READY_EXTENDED + 1U,
    METROLOGY_DRV_STATUS_STOP = SYS_STATUS_READY_EXTENDED + 2U,            
    METROLOGY_DRV_STATUS_CONFIGURING = SYS_STATUS_READY_EXTENDED + 3U,
    METROLOGY_DRV_STATUS_CALIBRATING = SYS_STATUS_READY_EXTENDED + 4U, 
    METROLOGY_DRV_STATUS_ERROR = SYS_STATUS_ERROR
} ATM90EXX_DRV_STATUS;

typedef enum {
    ATM90EXX_DRV_MAIN_TASK_STATE_INIT,
    ATM90EXX_DRV_MAIN_TASK_STATE_CONFIGURE_INIT,
    ATM90EXX_DRV_MAIN_TASK_STATE_CONFIGURE,
    ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_START,
    ATM90EXX_DRV_MAIN_TASK_STATE_WAITING_INT,
#ifdef ATM90EXX_IRQ_SUPPORT  
#if defined(ATM90EXX_IRQ_COMMON_SUPPORT)  
    ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT_INIT,
    ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT,
#else
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT  
    ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT0_INIT,
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT  
    ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_INT1_INIT,
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT  
    ATM90EXX_DRV_MAIN_TASK_STATE_CHECK_WARNOUT_INIT,
#endif
#endif
#endif
    ATM90EXX_DRV_MAIN_TASK_STATE_REFRESH_INFO_INIT,
    ATM90EXX_DRV_MAIN_TASK_STATE_REFRESH_INFO,
    ATM90EXX_DRV_MAIN_TASK_STATE_CALIBRATION_INIT,
    ATM90EXX_DRV_MAIN_TASK_STATE_CALIBRATION,
    ATM90EXX_DRV_MAIN_TASK_STATE_CALIBRATION_END,
    ATM90EXX_DRV_MAIN_TASK_STATE_FINISHED,
    ATM90EXX_DRV_MAIN_TASK_STATE_ERROR
} ATM90EXX_DRV_MAIN_TASK_STATE;

typedef enum {
    ATM90EXX_DRV_CONFIG_TASK_STATE_INIT,
#ifdef ATM90E26_SUPPORT
    ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW,
    ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CALSTART,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CS1,
    ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CS2,
#endif
#ifdef ATM90E32_SUPPORT
    ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW,
    ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW,
    ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_CFG,
    ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIG_REGS,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CAL_REGS,
    ATM90EXX_DRV_CONFIG_TASK_STATE_FUN_CAL_REGS,
    ATM90EXX_DRV_CONFIG_TASK_STATE_MEAS_CAL_REGS,
    ATM90EXX_DRV_CONFIG_TASK_STATE_METEREN,
    ATM90EXX_DRV_CONFIG_TASK_STATE_ENDCFG,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CRCDIGEST,
#endif
#ifdef ATM90E36_SUPPORT
    ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_HW,
    ATM90EXX_DRV_CONFIG_TASK_STATE_INIT_SW,
    ATM90EXX_DRV_CONFIG_TASK_STATE_SPECIAL_REGS,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CONFIGSTART,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CS0,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CALSTART,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CS1,
    ATM90EXX_DRV_CONFIG_TASK_STATE_ADJSTART,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CS2,
    ATM90EXX_DRV_CONFIG_TASK_STATE_HARMSTART,
    ATM90EXX_DRV_CONFIG_TASK_STATE_CS3,
#endif
    ATM90EXX_DRV_CONFIG_TASK_STATE_DELAY,        
    ATM90EXX_DRV_CONFIG_TASK_STATE_END,
    ATM90EXX_DRV_CONFIG_TASK_STATE_ERROR
} ATM90EXX_DRV_CONFIG_TASK_STATE;

typedef enum {
    ATM90EXX_DRV_CHECK_INT_TASK_STATE_INIT,
    ATM90EXX_DRV_CHECK_INT_TASK_STATE_END,
    ATM90EXX_DRV_CHECK_INT_TASK_STATE_ERROR
} ATM90EXX_DRV_CHECK_INT_TASK_STATE;

typedef enum {
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_INIT,
#ifdef ATM90EXX_DRV_POLL_INT_STATUS
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_STATUS,
#endif
#ifdef ATM90E26_SUPPORT
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_LINE,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_NEUTRAL,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING,
#endif
#ifdef ATM90E3X_SUPPORT
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_A,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_B,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_C,
#ifdef METROLOGY_MEASURING_TOTAL_SUPPORT
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_MEASURING_TOTAL,
#endif
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_A,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_B,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_C,
#ifdef METROLOGY_METERING_TOTAL_SUPPORT
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_METERING_TOTAL, 
#endif
#endif
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_POLL_OTHERS,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_END,
    ATM90EXX_DRV_REFRESH_INFO_TASK_STATE_ERROR
} ATM90EXX_DRV_REFRESH_INFO_TASK_STATE;

#ifdef ATM90EXX_CALIBRATION_SUPPORT
typedef enum {
    ATM90EXX_DRV_CALIBRATION_TASK_STATE_INIT,
    ATM90EXX_DRV_CALIBRATION_TASK_STATE_END,
    ATM90EXX_DRV_CALIBRATION_TASK_STATE_ERROR
} ATM90EXX_DRV_CALIBRATION_TASK_STATE;
#endif

// *****************************************************************************
/* ATM90EXX Interrupt Callback Function Pointer

  Summary:
    Defines the data type and function signature for the ATM90EXX interrupt
    callback function.

  Description:
    The ATM90EXX driver will call back the client's function with this signature
    when after Interrupt event has occurred.

  Remarks:
    None.
*/
typedef void (* ATM90EXX_DRV_EVENT_CALLBACK)( uint32_t events );

// *****************************************************************************
/* ATM90EXX Integration Period Callback Function Pointer

  Summary:
    Defines the data type and function signature for the ATM90EXX driver
    callback function.

  Description:
    The ATM90EXX driver will call back the client's function with this signature
    when after Measure Period Interrupt event has occurred.

  Remarks:
    None.
*/
typedef void (* ATM90EXX_DRV_INTEGRATION_CALLBACK)( void );

#ifdef ATM90EXX_CALIBRATION_SUPPORT
// *****************************************************************************
/* ATM90EXX Calibration Callback Function Pointer

  Summary:
    Defines the data type and function signature for the callback function of the
    calibration procedure.

  Description:
    The ATM90EXX driver will call back the client's function with this signature
    when the Calibration procedure has been completed.

  Parameters:
    result  - Flag o indicate if at least one phase has been calibrated successfully.
    Otherwise none of the phases have been calibrated.

  Remarks:
    None.
*/
typedef void (* ATM90EXX_DRV_CALIBRATION_CALLBACK) ( bool result );
#endif

#ifdef ATM90E36_HARMONICS_SUPPORT
// *****************************************************************************
/* ATM90EXX Harmonics Callback Function Pointer

  Summary:
    Defines the data type and function signature for the callback function of the
    harmonics analysis.

  Description:
    The ATM90EXX driver will call back the client's function with this signature
    when the Harmonics analysis has been completed.

  Parameters:
    harmonicNum  - The number of the harmonic that has been analyzed.

  Remarks:
    None.
*/
typedef void (* ATM90EXX_DRV_HARMONICS_CALLBACK) (uint8_t harmonicNum);
#endif

typedef struct
{
    /* SPI/USART Driver Handle */
    DRV_HANDLE                                    handle;

    /* ATM90EXX object register structure */
    ATM90EXX_REGS                                 atm90ExxObj;

    /* ATM90EXX configuration register structure */
    ATM90EXX_CONF                                 atm90ExxObjConf;    
         
    /* Integration Period in milliseconds */
    uint32_t                                      integrationPeriod;
    
    SYS_TIME_HANDLE                               integrationPeriodHandle;  

    /* Configure Flags */
    volatile ATM90EXX_CONFIG_FLAGS                configureFlags;
    
    /* Events Callback */
    ATM90EXX_DRV_EVENT_CALLBACK                   eventCallback;
    
    /* IPC metrology lib integration Callback */
    ATM90EXX_DRV_INTEGRATION_CALLBACK             integrationCallback;

#ifdef ATM90EXX_CALIBRATION_SUPPORT
    /* Calibration Process Callback */
    ATM90EXX_DRV_CALIBRATION_CALLBACK             calibrationCallback;
#endif    
#ifdef ATM90E36_HARMONICS_SUPPORT
    /* Harmonic Analysis Callback */
    ATM90EXX_DRV_HARMONICS_CALLBACK               harmonicAnalysisCallback;
#endif
    
#ifdef ATM90EXX_IRQ_SUPPORT
    /* Number of Interrupts */
    uint32_t                                      interrupts;  
    
#if defined(ATM90EXX_IRQ_COMMON_SUPPORT)
    /* Flag to indicate that a new INT0 interrupt has been triggered */
    volatile bool                                 interruptFlag;    
#else
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT    
    /* Flag to indicate that a new INT0 interrupt has been triggered */
    volatile bool                                 int0InterruptFlag;
    /* Number of Interrupts */
    uint32_t                                      int0Interrupts; 
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT   
    /* Flag to indicate that a new INT1 interrupt has been triggered */
    volatile bool                                 int1InterruptFlag;
    /* Number of Interrupts */
    uint32_t                                      int1Interrupts; 
#endif    
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT  
    /* Flag to indicate that a new WARNOUT interrupt has been triggered */
    volatile bool                                 warnoutInterruptFlag;
    /* Number of Interrupts */
    uint32_t                                      warnoutInterrupts; 
#endif
#endif
#endif
    
    /* The status of the driver */
    volatile ATM90EXX_DRV_STATUS                  status;

    /* The Main Task State of the driver */
    volatile ATM90EXX_DRV_MAIN_TASK_STATE         state;

    /* The Task State of the driver configuration */
    volatile ATM90EXX_DRV_CONFIG_TASK_STATE       confState;
    
    /* The Task State of the driver configuration */
    volatile ATM90EXX_DRV_CONFIG_TASK_STATE       confNextState;
    
    /* Timer handler to drive delay function */
    SYS_TIME_HANDLE                               timer;

    /* Delay time in milliseconds */
    uint32_t                                      delayMs;    
    
    /* The Task State of the driver configuration */
    volatile ATM90EXX_DRV_CHECK_INT_TASK_STATE    checkIntState;
    
    /* The Task State of the driver configuration */
    volatile ATM90EXX_DRV_REFRESH_INFO_TASK_STATE refreshInfoState;
    
#ifdef ATM90EXX_CALIBRATION_SUPPORT
    /* The Task State of the driver calibration */
    volatile ATM90EXX_DRV_CALIBRATION_TASK_STATE  calibrationState;
#endif
    
    /* Flag to indicate this object is in use */
    bool                                          inUse;
    
    /* Flag to indicate that a new integration period has been completed */
    volatile bool                                 startFlag;
    
    /* Flag to indicate that a new integration period has been completed */
    volatile bool                                 integrationFlag;
    
    /* Reconfigure Flag */
    volatile bool                                 reconfigureFlag;
    
} ATM90EXX_DRV_OBJ;

typedef struct
{
    
} ATM90EXX_DRV_INIT;

// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Driver System Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_ATM90EXX_Initialize (
        SYS_MODULE_INIT * init,
        uint32_t resetCause
    );

  Summary:
    Initializes the ATM90EXX driver according to the init parameter and the cause of the reset of the main processor.

  Description:
    This routine initializes the ATM90EXX driver making it ready for clients to open and use.
    The initialization data is specified by the init parameter.
    It is a single instance driver.

  Precondition:
    The low-level processor and board initialization must be completed before the
    system can call the initialization functions for any modules.

  Parameters:
    init  - Pointer to the init data structure containing any data necessary to initialize the driver.
    resetCause - Reset cause of the main processor.

  Returns:
    If successful, returns a valid handle to a driver instance object.
    Otherwise, it returns SYS_MODULE_OBJ_INVALID.

  Example:
    <code>
    bool   InitOK;

    DRIVER_ATM90EXX_INIT drvMetrologyInitData = {
        .regBaseAddress = DRV_ATM90EXX_REG_BASE_ADDRESS,
        .binStartAddress = (uint32_t)&met_bin_start,
        .binEndAddress = (uint32_t)&met_bin_end,

    };

    InitOK = DRV_ATM90EXX_Initialize((DRIVER_ATM90EXX_INIT *)&drvATM90ExxInitData, RSTC_ResetCauseGet());
    </code>

  Remarks:
    This routine must be called before any other DRV_ATM90EXX routine is called.
*/
SYS_MODULE_OBJ ATM90EXX_DRV_Init( SYS_MODULE_INIT * init, uint32_t resetCause );

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_ATM90EXX_Reinitialize (
        SYS_MODULE_INIT * init,
    );

  Summary:
    Reinitializes the ATM90EXX driver according to the init parameter.

  Description:
    This routine reinitializes the ATM90EXX driver making it ready for clients to open and use.
    The initialization data is specified by the init parameter.
    It is a single instance driver.

  Precondition:
    The low-level board initialization must have been completed and the
    module's initialization function must have been called before the system.

  Parameters:
    init  - Pointer to the init data structure containing any data necessary to initialize the driver.

  Returns:
    If successful, returns a valid handle to a driver instance object.
    Otherwise, it returns SYS_MODULE_OBJ_INVALID.

  Example:
    <code>
    SYS_MODULE_OBJ   sysObjDrvMet;

    extern uint8_t met_bin_start;
    extern uint8_t met_bin_end;

    DRV_ATM90EXX_INIT drvMetrologyInitData = {
        .regBaseAddress = DRV_ATM90EXX_REG_BASE_ADDRESS,
        .binStartAddress = (uint32_t)&met_bin_start,
        .binEndAddress = (uint32_t)&met_bin_end,

    };

    sysObjDrvMet = DRV_ATM90EXX_Reinitialize((SYS_MODULE_INIT *)&drvMetrologyInitData);
    </code>

  Remarks:
    DRV_ATM90EXX_Initialize routine has to be called at some point before this routine is called.
*/
SYS_MODULE_OBJ ATM90EXX_DRV_Reinitialize (/*SYS_MODULE_INIT * init*/);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_RESULT DRV_ATM90EXX_Open (
        DRV_ATM90EXX_START_MODE mode,
        DRV_ATM90EXX_CONTROL * pConfiguration
    );

  Summary:
    Opens the ATM90EXX driver according to the mode parameter.

  Description:
    This routine enables the IPC peripheral and, only if a HARD start mode has been selected,
    also handles the reset and clock lines for enabling the ATM90EXX library application.
    On the other hand, SOFT mode does not any effects on ATM90EXX library application running in the second processor.

  Precondition:
    None.

  Parameters:
    mode - ATM90EXX Driver Start mode
    pConfiguration - Pointer to CONTROL configuration. In case of NULL, the MCC default configuration will be loaded.

  Returns:
    If successful, returns DRV_ATM90EXX_SUCCESS. Otherwise, it returns DRV_ATM90EXX_ERROR.

  Example:
    <code>
        if (RSTC_ResetCauseGet() == RSTC_SR_RSTTYP(RSTC_SR_RSTTYP_WDT0_RST_Val))
        {
            app_metrologyData.startMode = DRV_ATM90EXX_START_SOFT;
        }
        else
        {
            app_metrologyData.startMode = DRV_ATM90EXX_START_HARD;
        }

        ...


        case APP_ATM90EXX_STATE_INIT:
        {
            if (DRV_ATM90EXX_Open(app_ATM90ExxData.startMode) == DRV_ATM90EXX_SUCCESS)
            {
                if (DRV_ATM90EXX_Open(app_ATM90ExxData.startMode,
                    NULL) == DRV_ATM90EXX_SUCCESS)
                {
                    app_ATM90ExxData.state = APP_ATM90EXX_STATE_START;
                }
                else
                {
                    app_ATM90ExxData.state = APP_ATM90EXX_STATE_RUNNING;
                }
            }
            else
            {
                app_ATM90ExxData.state = APP_ATM90EXX_STATE_ERROR;
            }

            break;
        }
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Open (ATM90EXX_DRV_START_MODE mode, ATM90EXX_CONF * conf);

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT DRV_ATM90EXX_Init_DefaultConfig ( void )

  Remarks:
    Default Configuration
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Init_DefaultConfig(ATM90EXX_CONF * conf);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_RESULT DRV_ATM90EXX_Close (void);

  Summary:
    Closes the ATM90EXX driver.

  Description:
    This routine closes the ATM90EXX driver making it unusable.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    If successful, returns DRV_ATM90EXX_SUCCESS. Otherwise, it returns DRV_ATM90EXX_ERROR.

  Example:
    <code>
        app_ATM90ExxData.state = APP_ATM90EXX_STATE_INIT;
        app_ATM90ExxData.startMode = DRV_ATM90EXX_START_HARD;

        DRV_ATM90EXX_Close();
        DRV_ATM90EXX_Initialize(NULL, RSTC_SR_RSTTYP(RSTC_SR_RSTTYP_SOFT_RST_Val));
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Close (void);

// *****************************************************************************
/* Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_Start (void);

  Summary:
    Starts the ATM90EXX driver.

  Description:
    This routine shoud be called until the ATM90EXX library application running in the second processor is ready to be used.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Returns ATM90EXX_DRV_SUCCESS when the ATM90EXX library application is ready to be used. Otherwise, it returns DRV_ATM90EXX_ERROR.

  Example:
    <code>
        case APP_ATM90EXX_STATE_START:
        {
            if (DRV_ATM90EXX_Start() == DRV_ATM90EXX_SUCCESS)
            {
                app_ATM90ExxData.state = APP_ATM90EXX_STATE_RUNNING;
            }
            else
            {
                app_ATM90ExxData.state = APP_ATM90EXX_STATE_ERROR;
            }

            break;
        }
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_RESULT ATM90EXX_DRV_Start(uint32_t period_ms);

ATM90EXX_DRV_RESULT ATM90EXX_DRV_Stop (void);

ATM90EXX_DRV_RESULT ATM90EXX_DRV_Reconfigure (ATM90EXX_CONF *config);

// *****************************************************************************
/* Function:
    ATM90EXX_DRV_RESULT DRV_ATM90EXX_eventCallbackRegister (
        ATM90EXX_DRV_EVENT_CALLBACK callback
    );

  Summary:
    Allows a client to set a ATM90EXX event event handling function.

  Description:
    This function allows a client to register an event handling function with the driver to call back when a integration period has completed.

  Precondition:
    ATM90EXX_DRV_Initialize routine must have been called before.

  Parameters:
    callback - Pointer to the callback function.

  Returns:
    If successful, returns ATM90EXX_DRV_SUCCESS. Otherwise, it returns ATM90EXX_DRV_ERROR.

  Example:
    <code>
        static void lAPP_ATM90EXX_NewEventCallback(void)
        {
            if (app_ATM90ExxData.state == APP_ATM90EXX_STATE_RUNNING)
            {
                app_ATM90ExxData.eventFlag = true;
            }
        }

        (...)

        DRV_ATM90EXX_EventCallbackRegister(lAPP_ATM90EXX_NewEventCallback);
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_RESULT ATM90EXX_DRV_EventCallbackRegister(ATM90EXX_DRV_EVENT_CALLBACK callback);

// *****************************************************************************
/* Function:
    ATM90EXX_DRV_RESULT DRV_ATM90EXX_IntegrationCallbackRegister (
        DRV_ATM90EXX_CALLBACK callback
    );

  Summary:
    Allows a client to set a ATM90EXX integration event handling function for the driver to call back when a integration period has completed.

  Description:
    This function allows a client to register an integration period event handling function with the driver to call back when a integration period has completed.
    This function must be always called after DRV_ATM90EXX_Initialize routine is called, since the initialization routine sets a NULL pointer to indicate no callback.

  Precondition:
    DRV_ATM90EXX_Initialize routine must have been called before.

  Parameters:
    callback - Pointer to the callback function.

  Returns:
    If successful, returns DRV_ATM90EXX_SUCCESS. Otherwise, it returns DRV_ATM90EXX_ERROR.

  Example:
    <code>
        static void lAPP_ATM90EXX_NewIntegrationCallback(void)
        {
            if (app_ATM90ExxData.state == APP_ATM90EXX_STATE_RUNNING)
            {
                app_ATM90ExxData.integrationFlag = true;
            }
        }

        (...)

        DRV_ATM90EXX_IntegrationCallbackRegister(lAPP_ATM90EXX_NewIntegrationCallback);
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_RESULT ATM90EXX_DRV_IntegrationCallbackRegister(ATM90EXX_DRV_INTEGRATION_CALLBACK callback);

#ifdef ATM90EXX_CALIBRATION_SUPPORT
// *****************************************************************************
/* Function:
    DRV_ATM90EXX_RESULT DRV_ATM90EXX_CalibrationCallbackRegister (
        DRV_ATM90EXX_CALIBRATION_CALLBACK callback
    );

  Summary:
    Registers a function with the ATM90EXX driver to be called back when the calibration process has completed.

  Description:
    This function allows a client to register a handling function with the driver to call back when a calibration process has completed.
    This function must be always called after DRV_ATM90EXX_Initialize routine is called, since the initialization routine sets a NULL pointer to indicate no callback.

  Precondition:
    DRV_ATM90EXX_Initialize routine must have been called before.

  Parameters:
    callback - Pointer to the function to be called.

  Returns:
    If successful, returns DRV_ATM90EXX_SUCCESS. Otherwise, it returns DRV_ATM90EXX_ERROR.

  Example:
    <code>
        static void lAPP_ATM90EXX_CalibrationCallback(bool result)
        {
            if (app_metrologyData.pCalibrationCallback)
            {
                app_metrologyData.pCalibrationCallback(result);
            }

            OSAL_SEM_Post(&appMetrologyCalibrationSemID);
        }

        (...)

        DRV_ATM90EXX_CalibrationCallbackRegister(lAPP_ATM90EXX_CalibrationCallback);
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_RESULT ATM90EXX_DRV_CalibrationCallbackRegister(ATM90EXX_DRV_CALIBRATION_CALLBACK callback);
#endif

#ifdef ATM90E36_HARMONICS_SUPPORT
// *****************************************************************************
/* Function:
    DRV_ATM90EXX_RESULT DRV_ATM90EXX_HarmonicAnalysisCallbackRegister (
        DRV_ATM90EXX_HARMONICS_CALLBACK callback
    );

  Summary:
    Registers a function with the ATM90EXX driver to be called back when the harmonic analysis has completed.

  Description:
    This function allows a client to register a handling function with the driver to call back when the harmonic analysis has completed.
    This function must be always called after DRV_ATM90EXX_Initialize routine is called, since the initialization routine sets a NULL pointer to indicate no callback.

  Precondition:
    DRV_ATM90EXX_Initialize routine must have been called before.

  Parameters:
    callback - Pointer to the function to be called.

  Returns:
    If successful, returns DRV_ATM90EXX_SUCCESS. Otherwise, it returns DRV_ATM90EXX_ERROR.

  Example:
    <code>
        static void lAPP_ATM90EXX_HarmonicAnalysisCallback(uint8_t harmonicNum)
        {
            if (app_metrologyData.pHarmonicAnalysisCallback)
            {
                app_metrologyData.harmonicAnalysisPending = false;
                app_metrologyData.pHarmonicAnalysisCallback(harmonicNum);
            }
        }

        (...)

        DRV_ATM90EXX_HarmonicAnalysisCallbackRegister(lAPP_ATM90EXX_HarmonicAnalysisCallback);
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_RESULT DRV_ATM90EXX_HarmonicAnalysisCallbackRegister(ATM90EXX_DRV_HARMONICS_CALLBACK callback);
#endif

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_STATUS DRV_ATM90EXX_GetStatus(void);

  Summary:
    Get the status of the ATM90EXX driver.

  Description:
    ATM90EXX function status:
        - DRV_ATM90EXX_STATUS_UNINITIALIZED: ATM90EXX driver has not been initialized.
        - DRV_ATM90EXX_STATUS_READY: ATM90EXX driver is ready to be used.
        - DRV_ATM90EXX_STATUS_HALT: ATM90EXX driver has been initialized but not opened.
        - DRV_ATM90EXX_STATUS_WAITING_IPC: ATM90EXX driver is waiting the init IPC interrupt
        from the ATM90EXX lib as part of the opening routine.
        - DRV_ATM90EXX_STATUS_INIT_DSP: IPC interrupt has been triggered indicating that DSP
        filters has been stabilized to full accuracy.
        - DRV_ATM90EXX_STATUS_RUNNING: ATM90EXX library is running and periodic data
        acquisition is performed.

    These status values are closely related to the ATM90EXX library states.
    For further information about the ATM90EXX library state diagram, refer to online documentation.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Returns the status of the ATM90EXX driver.

  Example:
    <code>
        case APP_ATM90EXX_STATE_START:
        {
            if (DRV_ATM90EXX_GetStatus() == DRV_ATM90EXX_STATUS_READY)
            {
                if (DRV_ATM90EXX_Start() == DRV_ATM90EXX_SUCCESS)
                {
                    app_metrologyData.state = APP_ATM90EXX_STATE_RUNNING;
                }
                else
                {
                    app_metrologyData.state = APP_ATM90EXX_STATE_ERROR;
                }
            }

            break;
        }
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_STATUS ATM90EXX_DRV_GetStatus(void);

/* Function:
    SYS_MODULE_OBJ DRV_ATM90EXX_Tasks (
        SYS_MODULE_OBJ object
    );

  Summary:
    Routine that performs the tasks necessary to maintain a state machine in
    the ATM90EXX driver.

  Description:
    Routine that performs the tasks necessary to maintain a state machine in
    the ATM90EXX driver.

  Precondition:
    The low-level board initialization must have been completed and
    the module's initialization function must have been called before
    the system can call the tasks routine for any module.

  Parameters:
    object - Handle to the module instance

  Returns:
    None.

  Example:
    <code>

    DRV_ATM90EXX_Tasks(sysObj.drvMet);
    </code>

  Remarks:
    None.
*/
void ATM90EXX_DRV_Tasks(void);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_REGS_CONTROL * DRV_ATM90EXX_GetControlData (void);

  Summary:
    Get the pointer to the control registers of the ATM90EXX library application running on the second processor.

  Description:
    Control registers are acting as 32-bit ATM90EXX input control registers.
    For a detailed description of the control registers, refer to "drv_atm90exx_regs.h" header file.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Pointer to the 32-bit ATM90EXX input control registers..

  Example:
    <code>
        app_ATM90ExxData.pMetControl = DRV_ATM90EXX_GetControlData();
        app_ATM90ExxData.pMetStatus  = DRV_ATM90EXX_GetStatusData();
        app_ATM90ExxData.pMetAccData = DRV_ATM90EXX_GetAccData();
        app_ATM90ExxData.pMetHarData = DRV_ATM90EXX_GetHarData();
    </code>

  Remarks:
    None.
*/
//ATM90EXX_REGS_CONTROL * ATM90EXX_DRV_GetControlData(void);

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_read_reg ( uint16_t reg, uint16_t *value )

  Remarks:
    Direct Access To read HW registers 
 */
ATM90EXX_DRV_RESULT ATM90EXX_DRV_read_reg ( uint16_t addr, uint16_t *val );

/*******************************************************************************
  Function:
    ATM90EXX_DRV_RESULT ATM90EXX_DRV_write_reg ( uint16_t reg, uint16_t *value )

  Remarks:
    Direct Access To write HW registers
 */
bool ATM90EXX_DRV_write_reg ( uint16_t reg, uint16_t value );

ATM90EXX_DRV_RESULT ATM90EXX_DRV_CheckInterruptsTask(void);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_CONTROL * DRV_ATM90EXX_GetControlByDefault (void);

  Summary:
    Get the pointer to the control registers defined by default via the Microchip Code Configurator (MCC) included in Harmony 3 framework.

  Description:
    After generating the code application via MCC, a struct data is defined as a constant. It includes all control registers obtained according to the MCC configuration established in the Harmony 3 project.
    The content of each control register is defined in "configuration.h" header file.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Pointer to the control registers defined as the default configuration.

  Example:
    <code>
      const DRV_ATM90EXX_CONTROL gDrvMetControlDefault =
        {
            STATE_CTRL_STATE_CTRL_RESET_Val,
            (uint32_t)(DRV_ATM90EXX_CONF_FCTRL0),
            (uint32_t)(DRV_ATM90EXX_CONF_FCTRL1),
            (uint32_t)(DRV_ATM90EXX_CONF_MT),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00001130),
            (uint32_t)(DRV_ATM90EXX_CONF_PULSE0_CTRL),
            (uint32_t)(DRV_ATM90EXX_CONF_PULSE1_CTRL),
            (uint32_t)(DRV_ATM90EXX_CONF_PULSE2_CTRL),
            (uint32_t)(DRV_ATM90EXX_CONF_PKT),
            (uint32_t)(DRV_ATM90EXX_CONF_PKT),
            (uint32_t)(DRV_ATM90EXX_CONF_PKT),
            (uint32_t)(DRV_ATM90EXX_CONF_CREEP_P),
            (uint32_t)(DRV_ATM90EXX_CONF_CREEP_Q),
            (uint32_t)(DRV_ATM90EXX_CONF_CREEP_I),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(DRV_ATM90EXX_CONF_SWELL),
            (uint32_t)(DRV_ATM90EXX_CONF_SWELL),
            (uint32_t)(DRV_ATM90EXX_CONF_SWELL),
            (uint32_t)(DRV_ATM90EXX_CONF_SAG),
            (uint32_t)(DRV_ATM90EXX_CONF_SAG),
            (uint32_t)(DRV_ATM90EXX_CONF_SAG),
            (uint32_t)(DRV_ATM90EXX_CONF_KI),
            (uint32_t)(DRV_ATM90EXX_CONF_KV),
            (uint32_t)(DRV_ATM90EXX_CONF_KI),
            (uint32_t)(DRV_ATM90EXX_CONF_KV),
            (uint32_t)(DRV_ATM90EXX_CONF_KI),
            (uint32_t)(DRV_ATM90EXX_CONF_KV),
            (uint32_t)(DRV_ATM90EXX_CONF_KI),
            (uint32_t)(0x20000000),
            (uint32_t)(0x20000000),
            (uint32_t)(0x20000000),
            (uint32_t)(0x20000000),
            (uint32_t)(0x20000000),
            (uint32_t)(0x20000000),
            (uint32_t)(0x20000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(DRV_ATM90EXX_CONF_WAVEFORM),
            (uint32_t)(DRV_ATM90EXX_CAPTURE_BUF_SIZE),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(DRV_ATM90EXX_CONF_ATS2023),
            (uint32_t)(DRV_ATM90EXX_CONF_ATS2427),
            (uint32_t)(0x00000003),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000),
            (uint32_t)(0x00000000)
        };

        (...)

        DRV_ATM90EXX_CONTROL *pSrc;

        pSrc = DRV_ATM90EXX_GetControlByDefault();

    </code>

  Remarks:
    None.
*/
//ATM90EXX_REGS_CONTROL * ATM90EXX_DRV_GetControlByDefault(void);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_REGS_STATUS * DRV_ATM90EXX_GetStatusData (void);

  Summary:
    Get the pointer to the status registers of the ATM90EXX library application running on the second processor.

  Description:
    The ATM90EXX library generates primary 32-bit output measurement quantities for each measurement interval.
    For a detailed description of the status registers, refer to "drv_metrology_regs.h" header file.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Pointer to the 32-bit ATM90EXX output measurement quantities for each measurement interval.

  Example:
    <code>
        app_metrologyData.pMetControl = DRV_ATM90EXX_GetControlData();
        app_metrologyData.pMetStatus = DRV_ATM90EXX_GetStatusData();
        app_metrologyData.pMetAccData = DRV_ATM90EXX_GetAccData();
        app_metrologyData.pMetHarData = DRV_ATM90EXX_GetHarData();
    </code>

  Remarks:
    None.
*/
//ATM90EXX_REGS_STATUS * ATM90EXX_DRV_GetStatusData(void);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_ACCUMULATORS * DRV_ATM90EXX_GetAccData (void);

  Summary:
    Get the pointer to the accumulator registers of the ATM90EXX library application running on the second processor.

  Description:
    Accumulator registers are acting as 64-bit ATM90EXX output accumulator registers.
    All values are integrated at an equivalent sampling rate of 4.000KHz. The ATM90EXX library shall
    generate the following primary output measurement quantities for each measurement interval, per-phase quantities
    with each phase designated by the subscript '_x' (where x = [A, B, or C] for voltage channels and x = [A, B, C or N]
    for current channels)
    For a detailed description of the control registers, refer to "drv_metrology_regs.h" header file.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Pointer to the 32-bit ATM90EXX input control registers.

  Example:
    <code>
        app_metrologyData.pMetControl = DRV_ATM90EXX_GetControlData();
        app_metrologyData.pMetStatus = DRV_ATM90EXX_GetStatusData();
        app_metrologyData.pMetAccData = DRV_ATM90EXX_GetAccData();
        app_metrologyData.pMetHarData = DRV_ATM90EXX_GetHarData();
    </code>

  Remarks:
    None.
*/
//ATM90EXX_REGS_MEASURING * ATM90EXX_DRV_GetMeasData(void);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_HARMONICS * DRV_ATM90EXX_GetHarData (void);

  Summary:
    Get the pointer to the harmonic analysis registers of the ATM90EXX library application running on the second processor.

  Description:
    Harmonic analysis registers are acting as 32-bit ATM90EXX harmonic analysis registers.
    The ATM90EXX module shall generate the following primary output measurement quantities for each measurement interval,
    per-phase quantities with each phase designated by the subscript '_x' (where x = [A, B, or C] for voltage channels
    and x = [A, B, C] for current channels).
    Internal scaling allows accurate harmonic analysis for integration periods of up to 16 seconds for up to full-scale magnitude input waveforms.
    For a detailed description of the harmonic analysis registers, refer to "drv_metrology_regs.h" header file.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Pointer to the 32-bit ATM90EXX harmonic analysis registers.

  Example:
    <code>
        app_metrologyData.pMetControl = DRV_ATM90EXX_GetControlData();
        app_metrologyData.pMetStatus = DRV_ATM90EXX_GetStatusData();
        app_metrologyData.pMetAccData = DRV_ATM90EXX_GetAccData();
        app_metrologyData.pMetHarData = DRV_ATM90EXX_GetHarData();
    </code>

  Remarks:
    None.
*/
//ATM90EXX_REGS_HARMONICS * ATM90EXX_DRV_GetHarData(void);

// *****************************************************************************
/* Function:
    void DRV_ATM90EXX_SetControl (DRV_ATM90EXX_REGS_CONTROL * pControl);

  Summary:
    Establishes the content of all control registers at once.

  Description:
    Overwrite the value of the every control register in the shared memory at once.

  Precondition:
    None.

  Parameters:
    pControl - Pointer to data of the new control registers to overwrite the old ones.

  Returns:
    None.

  Example:
    <code>
        void APP_ATM90EXX_SetControlByDefault(void)
       {
           DRV_ATM90EXX_REGS_CONTROL *pSrc;

           pSrc = DRV_ATM90EXX_GetControlByDefault();
           DRV_ATM90EXX_SetControl(pSrc);
       }
    </code>

  Remarks:
    None.
*/
//void ATM90EXX_DRV_SetControl(ATM90EXX_REGS_CONTROL * pControl);

// *****************************************************************************
/* Function:
    uint32_t DRV_ATM90EXX_GetEnergyValue(bool restartEnergy);

  Summary:
    Gets the active energy value.

  Description:
    Gets the active energy value. Energy value should be previously updated by the DRV_ATM90EXX_UpdateMeasurements() routine.

  Precondition:
    None.

  Parameters:
    restartEnergy - Flag to indicate if the energy value should be restarted or accumulated to the previous calculated value.

  Returns:
    The active energy value obtained according to the last call to DRV_ATM90EXX_UpdateMeasurements() routine..

  Example:
    <code>
        DRV_ATM90EXX_UpdateMeasurements();

        app_metrologyData.queueFree = uxQueueSpacesAvailable(appEnergyQueueID);
        if (app_metrologyData.queueFree)
        {
            newMetrologyData.energy = DRV_ATM90EXX_GetEnergyValue(true);
            newMetrologyData.Pt = DRV_ATM90EXX_GetRMSValue(RMS_PT);
            xQueueSend(appEnergyQueueID, &newMetrologyData, (TickType_t) 0);
        }
        else
        {
            SYS_CMD_MESSAGE("ENERGY Queue is FULL!!!\n\r");
        }
    </code>

  Remarks:
    None.
*/
//uint32_t ATM90EXX_DRV_GetEnergyValue(bool restartEnergy);

// *****************************************************************************
/* Function:
    uint32_t DRV_ATM90EXX_GetRMSValue(DRV_ATM90EXX_RMS_TYPE type);

  Summary:
    Gets the last RMS value of the selected measurement type.

  Description:
    RMS values should be previously updated by the DRV_ATM90EXX_UpdateMeasurements() routine.
    For further information about RMS types, refer to DRV_ATM90EXX_RMS_TYPE definition.

  Precondition:
    None.

  Parameters:
    type - Indicate what type of measurement is obtained.

  Returns:
    The RMS value of the selected type.

  Example:
    <code>
        DRV_ATM90EXX_UpdateMeasurements();

        app_metrologyData.queueFree = uxQueueSpacesAvailable(appEnergyQueueID);
        if (app_metrologyData.queueFree)
        {
            newMetrologyData.energy = DRV_ATM90EXX_GetEnergyValue(true);
            newMetrologyData.Pt = DRV_ATM90EXX_GetRMSValue(RMS_PT);
            xQueueSend(appEnergyQueueID, &newMetrologyData, (TickType_t) 0);
        }
        else
        {
            SYS_CMD_MESSAGE("ENERGY Queue is FULL!!!\n\r");
        }
    </code>

  Remarks:
    None.
*/
//uint32_t ATM90EXX_DRV_GetRMSValue(DRV_ATM90EXX_RMS_TYPE type);

// *****************************************************************************
/* Function:
    DRV_ATM90EXX_RMS_SIGN DRV_ATM90EXX_GetRMSSign(DRV_ATM90EXX_RMS_TYPE type);

  Summary:
    Gets the sign of the last RMS value of the selected measurement type.

  Description:
    RMS sign values should be previously updated by the DRV_ATM90EXX_UpdateMeasurements() routine.
    For further information about RMS types, refer to DRV_ATM90EXX_RMS_TYPE definition.

  Precondition:
    None.

  Parameters:
    type - Indicate what type of measurement is obtained.

  Returns:
    The RMS sign of the last RMS value. Positive sign is identified as RMS_SIGN_POSITIVE (0), negative sign as RMS_SIGN_NEGATIVE (1).

  Example:
    <code>

    </code>

  Remarks:
    None.
*/
//DRV_ATM90EXX_RMS_SIGN DRV_ATM90EXX_GetRMSSign(DRV_ATM90EXX_RMS_TYPE type);

// *****************************************************************************
/* Function:
    void DRV_ATM90EXX_SetConfiguration(DRV_ATM90EXX_CONFIGURATION * config);

  Summary:
    Set ATM90EXX configuration.

  Description:
    This routine is used to configure the ATM90EXX library according to the hardware
    in the input networks, as well as the programmable gain of the internal amplifiers.
    This function has to be called before the DRV_ATM90EXX_StartCalibration() routine,
    in order to ensure that the proper configuration has been applied before calibrating the system.
    If the programmable gain of the internal amplifiers changes, then the ATM90EXX library must be
    reinitialized in order to apply the changes.
    The ATM90EXX driver code receives the parameters and writes the proper ATM90EXX control registers.

  Precondition:
    None.

  Parameters:
    config - Pointer to configuration data to be used by the ATM90EXX library.

  Returns:
    None.

  Example:
    <code>
        DRV_ATM90EXX_CONFIGURATION newConf;

        newConf.mc = 800;
        newConf.st = SENSOR_CT;
        newConf.freq = 50;
        newConf.gain = GAIN_1;
        newConf.tr = 1000;
        newConf.rl = 3.24;
        newConf.ku = 1651;

        DRV_ATM90EXX_SetConfiguration(&newConf);
    </code>

  Remarks:
    None.
*/
//void ATM90EXX_DRV_SetConfiguration(DRV_ATM90EXX_CONFIGURATION * config);

// *****************************************************************************
/* Function:
    void DRV_ATM90EXX_GetEventsData(DRV_ATM90EXX_AFE_EVENTS * events);

  Summary:
    Gets the last ATM90EXX AFE events data.

  Description:
    Events data should be previously updated by the DRV_ATM90EXX_UpdateMeasurements() routine.
    For further information about the event data, refer to DRV_ATM90EXX_AFE_EVENTS definition.

  Precondition:
    None.

  Parameters:
    events - Pointer to the data where the events related information will be written.

  Returns:
    None.

  Example:
    <code>
        DRV_ATM90EXX_UpdateMeasurements();

        app_metrologyData.queueFree = uxQueueSpacesAvailable(appEventsQueueID);
        if (app_metrologyData.queueFree)
        {
            RTC_TimeGet(&newEvent.eventTime);
            DRV_ATM90EXX_GetEventsData(&newEvent.eventFlags);
            xQueueSend(appEventsQueueID, &newEvent, (TickType_t) 0);
        }
        else
        {
            SYS_CMD_MESSAGE("EVENTS Queue is FULL!!!\n\r");
        }
    </code>

  Remarks:
    None.
*/
//void ATM90EXX_DRV_GetEventsData(ATM90EXX_DRV_EVENTS * events);

#ifdef ATM90EXX_CALIBRATION_SUPPORT
// *****************************************************************************
/* Function:
    DRV_ATM90EXX_CALIBRATION_REFS * DRV_ATM90EXX_GetCalibrationReferences (void);

  Summary:
    Get the pointer to the calibration references used in the internal
    calibration process of the ATM90EXX library.

  Description:
    These internal calibration values are used to obtain the RMS values correctly.
    They also includes the result of the calibration process to be checked by the main application.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Pointer to the internal calibration data.

  Example:
    <code>
        void APP_ATM90EXX_StartCalibration(APP_ATM90EXX_CALIBRATION * calibration)
        {
            DRV_ATM90EXX_CALIBRATION_REFS * pCalibrationRefs;

            pCalibrationRefs = DRV_ATM90EXX_GetCalibrationReferences();
            pCalibrationRefs->aimIA = calibration->aimIA;
            pCalibrationRefs->aimVA = calibration->aimVA;
            pCalibrationRefs->angleA = calibration->angleA;
            pCalibrationRefs->aimIB = calibration->aimIB;
            pCalibrationRefs->aimVB = calibration->aimVB;
            pCalibrationRefs->angleB = calibration->angleB;
            pCalibrationRefs->aimIC = calibration->aimIC;
            pCalibrationRefs->aimVC = calibration->aimVC;
            pCalibrationRefs->angleC = calibration->angleC;
            pCalibrationRefs->lineId = calibration->lineId;

            app_metrologyData.state = APP_ATM90EXX_STATE_CHECK_CALIBRATION;
            DRV_ATM90EXX_StartCalibration();
        }
    </code>

  Remarks:
    None.
*/
ATM90EXX_DRV_CALIBRATION_REFS * ATM90EXX_DRV_GetCalibrationReferences(void);

// *****************************************************************************
/* Function:
    void APP_ATM90EXX_StartCalibration(APP_ATM90EXX_CALIBRATION * calibration);

  Summary:
    Starts internal calibration process.

  Description:
    This routine is used to automatically calibrate the board.
    It requires accurate and stable voltage and current sources and loads, which can be
    provided by a meter test bench like the WECO (or equivalent equipment).
    This routine must be called after a configuration routine (APP_ATM90EXX_SetConfiguration),
    in order to ensure that the proper configuration has been applied.

  Precondition:
    None.

  Parameters:
    calibration - Pointer to calibration data to be used by the ATM90EXX library.

  Returns:
    None.

  Example:
    <code>
        APP_ATM90EXX_CALIBRATION newCal;

        newCal.aimVA = 220.00;
        newCal.aimIA = 5.000;
        newCal.angleA = 60.00;

        APP_ATM90EXX_StartCalibration(&newCal);
    </code>

  Remarks:
    None.
*/
void ATM90EXX_DRV_StartCalibration(void);
#endif

#ifdef ATM90E36_HARMONICS_SUPPORT
// *****************************************************************************
/* Function:
    void DRV_ATM90EXX_StartHarmonicAnalysis(
        uint8_t harmonicNum,
        DRV_ATM90EXX_HARMONIC *pHarmonicResponse
    );

  Summary:
    Starts the harmonic Analysis process.

  Description:
    This routine configures the ATM90EXX library to enable the harmonics computation
    and to calculate the data corresponding to the harmonic number n.
    Then, the ATM90EXX driver receives the data from the ATM90EXX library and
    computes the RMS currents and voltages of the selected harmonic.

  Precondition:
    None.

  Parameters:
    harmonicNum - Harmonic number.
    pHarmonicResponse - Pointer to the harmonic analysis struct data to store the harmonic data result.

  Returns:
    None.

  Example:
    <code>
        DRV_ATM90EXX_HARMONIC harmonicAnalysisResponse;

        DRV_ATM90EXX_StartHarmonicAnalysis(3, &harmonicAnalysisResponse);
    </code>

  Remarks:
    None.
*/
void ATM90EXX_DRV_StartHarmonicAnalysis(uint8_t harmonicNum, DRV_ATM90EXX_HARMONICS_RMS *pHarmonicResponse);
#endif

#ifdef __cplusplus
 }
#endif

#endif // #ifndef DRV_ATM90EXX_H
/*******************************************************************************
 End of File
*/
