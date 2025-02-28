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

/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_metrology.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define METROLOGY_INTEGRATION_PERIOD_MS 5000

extern APP_DATALOG_QUEUE appDatalogQueue;
APP_DATALOG_QUEUE_DATA appMetrologyDatalogQueueData;

extern APP_ENERGY_QUEUE appEnergyQueue;
extern APP_EVENTS_QUEUE appEventsQueue;

//extern DRV_METROLOGY_INIT drvMetrologyInitData;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_METROLOGY_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_METROLOGY_DATA CACHE_ALIGN app_metrologyData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
static void _APP_METROLOGY_GetNVMDataCallback(APP_DATALOG_RESULT result);

static void _APP_METROLOGY_LoadConfigFromMemory(METROLOGY_CONF * config)
{
    appMetrologyDatalogQueueData.userId = APP_DATALOG_USER_METROLOGY;
    appMetrologyDatalogQueueData.operation = APP_DATALOG_READ;
    appMetrologyDatalogQueueData.pData = (uint8_t *)config;
    appMetrologyDatalogQueueData.dataLen = sizeof(METROLOGY_CONF);
    appMetrologyDatalogQueueData.endCallback = _APP_METROLOGY_GetNVMDataCallback;
    appMetrologyDatalogQueueData.date.month = APP_DATALOG_INVALID_MONTH;
    appMetrologyDatalogQueueData.date.year = APP_DATALOG_INVALID_YEAR;

    APP_DATALOG_SendDatalogData(&appMetrologyDatalogQueueData);
}

static void _APP_METROLOGY_StoreConfigInMemory(METROLOGY_CONF * config)
{
    appMetrologyDatalogQueueData.userId = APP_DATALOG_USER_METROLOGY;
    appMetrologyDatalogQueueData.operation = APP_DATALOG_WRITE;
    appMetrologyDatalogQueueData.pData = (uint8_t *)config;
    appMetrologyDatalogQueueData.dataLen = sizeof(METROLOGY_CONF);
    appMetrologyDatalogQueueData.endCallback = NULL;
    appMetrologyDatalogQueueData.date.month = APP_DATALOG_INVALID_MONTH;
    appMetrologyDatalogQueueData.date.year = APP_DATALOG_INVALID_YEAR;

    APP_DATALOG_SendDatalogData(&appMetrologyDatalogQueueData);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void _APP_METROLOGY_IntegrationCallback(void)
{
    if ((app_metrologyData.state == APP_METROLOGY_STATE_RUNNING) ||
        (app_metrologyData.state == APP_METROLOGY_STATE_CHECK_CALIBRATION))
    {
        /* Signal Metrology thread to update measurements for an integration period */
        app_metrologyData.integrationFlag = true;
        LED_Toggle();
    }
}
#ifdef METROLOGY_CALIBRATION_SUPPORT
static void _APP_METROLOGY_CalibrationCallback(bool result)
{
    if (result == true)
    {
        /* Store CONTROL Regs in NVM */
        _APP_METROLOGY_StoreConfigInMemory(app_metrologyData.pMetControl);
    }

    if (app_metrologyData.pCalibrationCallback)
    {
        app_metrologyData.pCalibrationCallback(result);
    }

    /* Signal Metrology to exit calibration status */
    app_metrologyData.calibrationFlag = true;
}
#endif

#ifdef METROLOGY_HARMONICS_SUPPORT

static void _APP_METROLOGY_HarmonicAnalysisCallback(uint8_t harmonicNum)
{
    if (app_metrologyData.pHarmonicAnalysisCallback)
    {
        app_metrologyData.harmonicAnalysisPending = false;
        app_metrologyData.pHarmonicAnalysisCallback(harmonicNum);
    }
}
#endif

static void _APP_METROLOGY_GetNVMDataCallback(APP_DATALOG_RESULT result)
{
    if (result == APP_DATALOG_RESULT_SUCCESS)
    {
        app_metrologyData.dataIsRdy = true;
    }

    // Handle task state
    app_metrologyData.dataFlag = true;
}

static void _APP_METROLOGY_EventsCallback(METROLOGY_API_EVENTS eventFlags)
{
    // Send new Events to the Events Task
    APP_EVENTS_QUEUE_DATA newEvent;

    RTC_TimeGet(&newEvent.eventTime);
    newEvent.eventFlags.events = eventFlags.events;
    if (APP_EVENTS_SendEventsData(&newEvent) == false)
    {
        SYS_CMD_MESSAGE("EVENTS Queue is FULL!!!\r\n");
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_METROLOGY_Initialize (void)

  Remarks:
    See prototype in app_metrology.h.
 */

void APP_METROLOGY_Initialize (void)
{
    /* Place the App state machine in its initial state. */
    app_metrologyData.state = APP_METROLOGY_STATE_INIT;

    /* Flag to indicate if configuration should be applied */
    app_metrologyData.setConfiguration = false;

    app_metrologyData.startMode = METROLOGY_API_START_HARD;

    /* Detection of the WDOG/SYSTEM Reset */
    PM_RESET_CAUSE ResetCause = PM_ResetCauseGet();

    if ((ResetCause == PM_RESET_CAUSE_WDT_RESET) || (ResetCause == PM_RESET_CAUSE_SYST_RESET))
    {
        app_metrologyData.startMode = METROLOGY_API_START_SOFT;
    }
    else
    {
        app_metrologyData.startMode = METROLOGY_API_START_HARD;
    }

    /* Get Pointers to metrology data regions */
    app_metrologyData.pMetConfig = METROLOGY_API_GetConfigData();
    //app_metrologyData.pMetStatus = METROLOGY_API_GetStatusData();
    //app_metrologyData.pMetAccData = METROLOGY_API_GetAccData();
#ifdef METROLOGY_HARMONICS_SUPPORT   
    //app_metrologyData.pMetHarData = METROLOGY_API_GetHarData();
#endif
    
    /* Initialize the Metrology */
    GPIO_PB31_Set();
    EXT2_LED1_OLED1_XPRO_Clear();
    EXT2_LED2_OLED1_XPRO_Clear();
    EXT2_LED3_OLED1_XPRO_Clear();
            
#ifdef METROLOGY_CALIBRATION_SUPPORT
    /* Set Callback for calibration process */
    DRV_METROLOGY_CalibrationCallbackRegister(_APP_METROLOGY_CalibrationCallback);
    /* Clear Calibration Data */
    app_metrologyData.pCalibrationCallback = NULL;
    app_metrologyData.calibrationFlag = false;
#endif
#ifdef METROLOGY_HARMONICS_SUPPORT
    /* Set Callback for harmonic analysis process */
    DRV_METROLOGY_HarmonicAnalysisCallbackRegister(_APP_METROLOGY_HarmonicAnalysisCallback);
    /* Clear Harmonic Analysis Data */
    app_metrologyData.harmonicAnalysisPending = false;
    app_metrologyData.pHarmonicAnalysisCallback = NULL;
    app_metrologyData.pHarmonicAnalysisResponse = NULL;
#endif
            
    /* Initialize integration Flag */
    app_metrologyData.integrationFlag = false;
    app_metrologyData.dataFlag = false;

}

/******************************************************************************
  Function:
    void APP_METROLOGY_Tasks (void)

  Remarks:
    See prototype in app_metrology.h.
 */
void APP_METROLOGY_Tasks (void)
{
    APP_ENERGY_QUEUE_DATA newMetrologyData;
    
    /* Call to the METROLOGY DRIVER before any action */
    METROLOGY_DRV_Tasks();

    /* Check the application's current state. */
    switch (app_metrologyData.state)
    {
        case APP_METROLOGY_STATE_INIT:
        {
            /* Init Metrology */
            METROLOGY_DRV_Init(NULL,0);
            /* Set Callback for each metrology event process */            
            METROLOGY_DRV_EventCallbackRegister((METROLOGY_API_EVENT_CALLBACK) _APP_METROLOGY_EventsCallback);
            /* Set Callback for each metrology integration process */
            METROLOGY_DRV_IntegrationCallbackRegister((METROLOGY_API_INTEGRATION_CALLBACK) _APP_METROLOGY_IntegrationCallback);
            /* Next State */
            app_metrologyData.state = APP_METROLOGY_STATE_WAITING_DATALOG;
            
            break;
        }
        /* Application's initial state. */
        case APP_METROLOGY_STATE_WAITING_DATALOG:
        {
            if (APP_DATALOG_GetStatus() == APP_DATALOG_STATE_READY)
            {
                /* Check if there are Metrology data in memory */
                if (APP_DATALOG_FileExists(APP_DATALOG_USER_METROLOGY, NULL))
                {
                    /* Metrology data exists */
                    _APP_METROLOGY_LoadConfigFromMemory(app_metrologyData.pMetConfig);
                    /* Wait for the loading data from memory */
                    app_metrologyData.state = APP_METROLOGY_STATE_WAIT_DATA;
                }
                else
                {
                    app_metrologyData.state = APP_METROLOGY_STATE_OPEN_METROLOGY;
                }
            }

            break;
        }

        case APP_METROLOGY_STATE_WAIT_DATA:
        {
            /* Apply Configuration Data */
            if (app_metrologyData.dataIsRdy)
            {
                /* Update Flag to apply external configuration */
                app_metrologyData.setConfiguration = true;
                app_metrologyData.state = APP_METROLOGY_STATE_OPEN_METROLOGY;
            }
            break;
        }

        case APP_METROLOGY_STATE_OPEN_METROLOGY:
        {
            METROLOGY_CONF * pConfig = NULL;

            /* Check if external configuration should be applied */
            if (app_metrologyData.setConfiguration)
            {
                pConfig = app_metrologyData.pMetConfig;
            }

            if (METROLOGY_DRV_Open(app_metrologyData.startMode, pConfig) == 0)
            {
                if (app_metrologyData.startMode == METROLOGY_API_START_HARD)
                {
                    app_metrologyData.state = APP_METROLOGY_STATE_START_METROLOGY;
                }
                else
                {
                    app_metrologyData.state = APP_METROLOGY_STATE_START_METROLOGY; //APP_METROLOGY_STATE_RUNNING;
                }
            }
            else
            {
                app_metrologyData.state = APP_METROLOGY_STATE_ERROR;
            }

            break;
        }

        case APP_METROLOGY_STATE_START_METROLOGY:
        {
            if (METROLOGY_DRV_GetStatus() == METROLOGY_DRV_STATUS_READY)
            {
                /* Check if there are Metrology data in memory */
                if (APP_DATALOG_FileExists(APP_DATALOG_USER_METROLOGY, NULL) == false)
                {
                    /* Metrology data does not exists. Store in NVM */
                    _APP_METROLOGY_StoreConfigInMemory(app_metrologyData.pMetConfig);
                }
                
                if (METROLOGY_DRV_Start(METROLOGY_INTEGRATION_PERIOD_MS) == 0)
                {
                    app_metrologyData.state = APP_METROLOGY_STATE_RUNNING;
                }
                else
                {
                    app_metrologyData.state = APP_METROLOGY_STATE_ERROR;
                }

            }

            break;
        }

        case APP_METROLOGY_STATE_RUNNING:
        {
            /* Wait for the integration flag to get measurements at the end of the integration period. */
            if (app_metrologyData.integrationFlag)
            {
                app_metrologyData.integrationFlag = false;

                // Send new Energy values to the Energy Task
                METROLOGY_API_get_AEnergy(METROLOGY_AENERGY, &newMetrologyData.energy, NULL, true, 0);
                METROLOGY_API_get_Pmean(METROLOGY_PMEANT, &newMetrologyData.Pt, NULL, 0);
                if (APP_ENERGY_SendEnergyData(&newMetrologyData) == false)
                {
                    SYS_CMD_MESSAGE("ENERGY Queue is FULL!!!\r\n");
                }

#ifdef METROLOGY_POLL_INT_SUPPORT               
                APP_EVENTS_QUEUE_DATA newEvent;
                // Send new Events to the Events Task
                RTC_TimeGet(&newEvent.eventTime);
                METROLOGY_API_get_events(&newEvent.eventFlags);
                if (APP_EVENTS_SendEventsData(&newEvent) == false)
                {
                    SYS_CMD_MESSAGE("EVENTS Queue is FULL!!!\r\n");
                }
#endif
            }

            break;
        }
#ifdef METROLOGY_CALIBRATION_SUPPORT
        case APP_METROLOGY_STATE_CHECK_CALIBRATION:
        {
            /* Wait for the metrology semaphore to wait calibration ends. */
            if (app_metrologyData.calibrationFlag)
            {
                app_metrologyData.calibrationFlag = false;
                app_metrologyData.state = APP_METROLOGY_STATE_RUNNING;
            }

            break;
        }
#endif
        /* The default state should never be executed. */
        case APP_METROLOGY_STATE_ERROR:
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

APP_METROLOGY_STATE APP_METROLOGY_GetState(void)
{
    return app_metrologyData.state;
}

bool APP_METROLOGY_GetControlRegister(uint16_t regId, uint16_t * regValue, char *regName)
{
    uint16_t regAddr;
    METROLOGY_API_RESULT result;

    if (regId > METROLOGY_API_get_regControlInfoEntries())
    {
        return false;
    }

    result = METROLOGY_API_get_regControlInfo(regId, &regAddr, regValue, regName);
    
    if (result == METROLOGY_API_SUCCESS)
    {
        return true;
    }

    return false;

}

bool APP_METROLOGY_SetControlRegister(uint16_t regId, uint16_t value)
{
#if 0    
    uint16_t *pData;
    
    if (regId > METROLOGY_API_get_regControlInfoEntries())
    {
        return false;
    }

    pData = (uint16_t *)app_metrologyData.pMetControl;
    pData += regId;
    *pData = value;
#endif
    return true;
}

bool APP_METROLOGY_GetStatusRegister(uint16_t regId, uint16_t * regValue, char *regName)
{
    uint16_t regAddr;
    METROLOGY_API_RESULT result;

    if (regId > METROLOGY_API_get_regStatusInfoEntries())
    {
        return false;
    }

    result = METROLOGY_API_get_regStatusInfo(regId, &regAddr, regValue, regName);
    
    if (result == METROLOGY_API_SUCCESS)
    {
        return true;
    }

    return false;
}

bool APP_METROLOGY_GetAccumulatorRegister(uint16_t regId, uint16_t * regValue, char *regName)
{
    uint16_t regAddr;
    METROLOGY_API_RESULT result;

    if (regId > METROLOGY_API_get_regAccumulatorsInfoEntries())
    {
        return false;
    }

    result = METROLOGY_API_get_regAccumulatorsInfo(regId, &regAddr, regValue, regName);
    
    if (result == METROLOGY_API_SUCCESS)
    {
        return true;
    }

    return false;
}

#ifdef METROLOGY_HARMONICS_SUPPORT
bool APP_METROLOGY_GetHarmonicsRegister(HARMONICS_REG_ID regId, uint16_t * regValue, char *regName)
{
    uint16_t *pData;

    if (regId >= HARMONICS_REG_NUM)
    {
        return false;
    }

    pData = (uint32_t *)app_metrologyData.pMetHarData;
    pData += regId;
    *regValue = *pData;

    if (regName)
    {
        sprintf(regName,"%s",_met_har_desc[regId]);
    }

    return true;
}
#endif

#if 0
bool APP_METROLOGY_GetRMS(METROLOGY_RMS_TYPE rmsId, uint32_t * rmsValue, METROLOGY_RMS_SIGN * sign)
{
    if (rmsId >= RMS_TYPE_NUM)
    {
        return false;
    }

    if (sign != NULL)
    {
        *sign = DRV_METROLOGY_GetRMSSign(rmsId);
    }

    *rmsValue = DRV_METROLOGY_GetRMSValue(rmsId);
    return true;
}
#endif

void APP_METROLOGY_SetConfigByDefault(void)
{
    METROLOGY_CONF pSrc;

    METROLOGY_API_GetConfigurationByDefault(&pSrc);
    METROLOGY_API_SetConfiguration(&pSrc);
}

void APP_METROLOGY_StoreMetrologyData(void)
{
    _APP_METROLOGY_StoreConfigInMemory(app_metrologyData.pMetConfig);
}

void APP_METROLOGY_SetConfiguration(METROLOGY_CONF * config)
{
    METROLOGY_API_SetConfiguration(config);

    _APP_METROLOGY_StoreConfigInMemory(app_metrologyData.pMetConfig);
}
#ifdef METROLOGY_CALIBRATION_SUPPORT
void APP_METROLOGY_StartCalibration(APP_METROLOGY_CALIBRATION * calibration)
{
    if (app_metrologyData.state == APP_METROLOGY_STATE_RUNNING)
    {
        DRV_METROLOGY_CALIBRATION_REFS * pCalibrationRefs;

        pCalibrationRefs = METROLOGY_GetCalibrationReferences();
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

        app_metrologyData.state = APP_METROLOGY_STATE_CHECK_CALIBRATION;
        METROLOGY_API_StartCalibration();
    }
}

void APP_METROLOGY_SetCalibrationCallback(METROLOGY_CALIBRATION_CALLBACK callback)
{
    app_metrologyData.pCalibrationCallback = callback;
}
#endif
#ifdef METROLOGY_WAVEFORM_CAPTURE_SUPPORT
size_t APP_METROLOGY_GetWaveformCaptureData(uint32_t *address)
{
    *address = (uint32_t)app_metrologyData.pMetControl->CAPTURE_ADDR;
    return (size_t)app_metrologyData.pMetControl->CAPTURE_BUFF_SIZE;
}
#endif
#ifdef METROLOGY_HARMONICS_SUPPORT
bool APP_METROLOGY_StartHarmonicAnalysis(uint8_t harmonicNum)
{
    if (app_metrologyData.harmonicAnalysisPending)
    {
        return false;
    }

    if (app_metrologyData.pHarmonicAnalysisCallback == NULL)
    {
        return false;
    }

    if (app_metrologyData.pHarmonicAnalysisResponse == NULL)
    {
        return false;
    }

    app_metrologyData.harmonicAnalysisPending = true;

    METROLOGY_StartHarmonicAnalysis(harmonicNum, app_metrologyData.pHarmonicAnalysisResponse);

    return true;
}

void APP_METROLOGY_SetHarmonicAnalysisCallback(METROLOGY_HARMONICS_CALLBACK callback,
        DRV_METROLOGY_HARMONICS_RMS * pHarmonicAnalysisResponse)
{
    app_metrologyData.pHarmonicAnalysisCallback = callback;
    app_metrologyData.pHarmonicAnalysisResponse = pHarmonicAnalysisResponse;
}
#endif

#ifndef METROLOGY_ATM90EXX_SUPPORT   
void APP_METROLOGY_Restart (void)
{
    METROLOGY_API_RESULT result;

    result = METROLOGY_DRV_Close();
    if (result == METROLOGY_API_SUCCESS)
    {
        app_metrologyData.state = APP_METROLOGY_STATE_INIT;
        app_metrologyData.startMode = METROLOGY_START_HARD;

        sysObj.drvMet = METROLOGY_DRV_Reinitialize((SYS_MODULE_INIT *)&drvMetrologyInitData);
    }
}
#endif

void APP_METROLOGY_SetLowPowerMode (void)
{
    METROLOGY_DRV_Close();
    PM_StandbyModeEnter();
}

#ifndef METROLOGY_ATM90EXX_SUPPORT   
bool APP_METROLOGY_CheckPhaseEnabled (APP_METROLOGY_PHASE_ID phase)
{
    uint32_t regValue = app_metrologyData.pMetControl->FEATURE_CTRL0;

    if (regValue & phase)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif

/*******************************************************************************
 End of File
 */
