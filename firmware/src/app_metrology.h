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
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_metrology.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_METROLOGY_Initialize" and "APP_METROLOGY_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_METROLOGY_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_METROLOGY_H
#define _APP_METROLOGY_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
typedef enum
{
    APP_METROLOGY_PHASE_A = (1 << 8),
    APP_METROLOGY_PHASE_B = (1 << 9),
    APP_METROLOGY_PHASE_C = (1 << 10)
} APP_METROLOGY_PHASE_ID;

#ifdef METROLOGY_HARMONICS_SUPPORT
typedef enum
{
    HARMONICS_I_A_m_R_ID = 0,
    HARMONICS_REG_NUM,
} HARMONICS_REG_ID;
#endif

#ifdef METROLOGY_CALIBRATION_SUPPORT
typedef struct
{
    double aimVA;
    double aimIA;
    double angleA;
    double aimVB;
    double aimIB;
    double angleB;
    double aimVC;
    double aimIC;
    double angleC;
    DRV_METROLOGY_PHASE_ID lineId;
} APP_METROLOGY_CALIBRATION;
#endif

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_METROLOGY_STATE_INIT,
    APP_METROLOGY_STATE_WAITING_DATALOG,
    APP_METROLOGY_STATE_OPEN_METROLOGY,
    APP_METROLOGY_STATE_START_METROLOGY,
    APP_METROLOGY_STATE_RUNNING,
    APP_METROLOGY_STATE_CHECK_CALIBRATION,
    APP_METROLOGY_STATE_WAIT_DATA,
    APP_METROLOGY_STATE_ERROR

} APP_METROLOGY_STATE;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_METROLOGY_STATE state;

    METROLOGY_API_START_MODE startMode;
   
    METROLOGY_CONF * pMetConfig;
    //METROLOGY_REGS_STATUS * pMetStatus;
    //METROLOGY_REGS_ACC * pMetAccData;

#ifdef METROLOGY_HARMONICS_SUPPORT
    DRV_METROLOGY_REGS_HARMONICS * pMetHarData;

    bool harmonicAnalysisPending;
    DRV_METROLOGY_HARMONICS_RMS * pHarmonicAnalysisResponse;
    DRV_METROLOGY_HARMONICS_CALLBACK pHarmonicAnalysisCallback;
#endif
#ifdef METROLOGY_CALIBRATION_SUPPORT
    DRV_METROLOGY_CALIBRATION_CALLBACK pCalibrationCallback;

    bool calibrationFlag;
#endif
    uint32_t queueFree;

    bool setConfiguration;

    bool dataIsRdy;

    volatile bool integrationFlag;

    bool dataFlag;

} APP_METROLOGY_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_METROLOGY_Initialize (void)

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_METROLOGY_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_METROLOGY_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_METROLOGY_Initialize (void);


/*******************************************************************************
  Function:
    void APP_METROLOGY_Tasks (void)

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_METROLOGY_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_METROLOGY_Tasks(void);
APP_METROLOGY_STATE APP_METROLOGY_GetState(void);
bool APP_METROLOGY_GetControlRegister(uint16_t regId, uint16_t * regValue, char *regName);
bool APP_METROLOGY_SetControlRegister(uint16_t regId, uint16_t value);
bool APP_METROLOGY_GetStatusRegister(uint16_t regId, uint16_t * regValue, char *regName);
bool APP_METROLOGY_GetAccumulatorRegister(uint16_t regId, uint16_t * regValue, char *regName);
#ifdef METROLOGY_HARMONICS_SUPPORT
bool APP_METROLOGY_GetHarmonicsRegister(uint16_t regId, uint16_t * regValue, char *regName);
#endif
//bool APP_METROLOGY_GetRMS(uint16_t rmsId, uint16_t * rmsValue, DRV_METROLOGY_RMS_SIGN * sign);
void APP_METROLOGY_SetControlByDefault(void);
void APP_METROLOGY_StoreMetrologyData(void);
void APP_METROLOGY_SetConfiguration(METROLOGY_CONF * config);
#ifdef METROLOGY_CALIBRATION_SUPPORT
void APP_METROLOGY_StartCalibration(APP_METROLOGY_CALIBRATION * calibration);
void APP_METROLOGY_SetCalibrationCallback(DRV_METROLOGY_CALIBRATION_CALLBACK callback);
#endif 
#ifdef METROLOGY_WAVEFORM_CAPTURE_SUPPORT
size_t APP_METROLOGY_GetWaveformCaptureData(uint32_t *pData);
#endif 
#ifdef METROLOGY_HARMONICS_SUPPORT
bool APP_METROLOGY_StartHarmonicAnalysis(uint8_t harmonicNum);
void APP_METROLOGY_SetHarmonicAnalysisCallback(METROLOGY_HARMONICS_CALLBACK callback,
        METROLOGY_HARMONICS_RMS * pHarmonicAnalysisResponse);
#endif
void APP_METROLOGY_Restart(void);
void APP_METROLOGY_SetLowPowerMode (void);
bool APP_METROLOGY_CheckPhaseEnabled (APP_METROLOGY_PHASE_ID phase);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_METROLOGY_H */

/*******************************************************************************
 End of File
 */

