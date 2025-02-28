/*******************************************************************************
  ATM90EXX Data Definitions

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_defs.h

  Summary:
    ATM90EXX Data Definitions

  Description:
    ATM90EXX Data Definitions
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2024, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#ifndef ATM90EXX_DEFS_H
#define ATM90EXX_DEFS_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdbool.h>
#include "driver/driver.h"
#include "system/system.h"
#include "atm90exx_regs.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

#define ATM90EXX_DEBUG_PRINT(level, format, ...)      SYS_DEBUG_MESSAGE(level, format, ##__VA_ARGS__)
#define ATM90EXX_DEBUG_MESSAGE(level, message)        SYS_DEBUG_MESSAGE(level, message)

/* ATM90E3X Power Mode Definitions */
typedef enum
{
  ATM90EXX_POWER_MODE_IDLE = 0,
	ATM90EXX_POWER_MODE_DETECT,
	ATM90EXX_POWER_MODE_PARTIAL,
	ATM90EXX_POWER_MODE_NORMAL
} ATM90EXX_POWER_MODE_STATES;

typedef	enum
{
	ATM90E2X_CHIPID_ADDR	= 0x005,
	ATM90E3X_CHIPID_ADDR	= 0x2F0
} ATM90EXX_CHIPID_ADDR;
typedef enum
{
	AT90E23_CHIPID		  = 0x2612,
  AT90E25_CHIPID      = 0x2613,
	AT90E32AS_VA_CHIPID	= 0x0000,
	AT90E32AS_VB_CHIPID	= 0x0001,
	AT90E32_CHIPID		  = 0x0001,
	AT90E32A_CHIPID		  = 0x0003,
	AT90E36_CHIPID		  = 0x8001,
	AT90E36A_CHIPID		  = 0x8003	
} ATM90EXX_CHIPID;
typedef	enum
{	
	AT90E32_TYPE		    = 0x02,
	AT90E36_TYPE		    = 0x06,
	AT90E32A_TYPE 		  = 0x12,
	AT90E36A_TYPE 		  = 0x16,
	AT90E25_TYPE  		  = 0x40,
  AT90E24_TYPE  		  = 0x41,
  AT90E23_TYPE  		  = 0x42,
	AT90E32AS_TYPE		  = 0x82		
} ATM90EXX_TYPE;

// *****************************************************************************
/* Metrology Driver Instance Object

  Summary:
    Object used to keep any data required for an instance of the metrology driver.

  Description:
    None.

  Remarks:
    None.
*/

typedef struct
{
    /* Flag to indicate this object is in use */
    bool                                          inUse;

    /* The status of the driver */
    volatile ATM90EXX_DRV_STATUS                  status;

    /* The status of the driver */
    volatile ATM90EXX_DRV_STATE                   state;

    /* The status of the driver configuration */
    volatile ATM90EXX_DRV_CONFIG_STATE            config_state;

    /* ATM90EXX register structure - depends on the device in use */
    ATM90EXX_REGS                                 atm90ExxObj;

#ifdef ATM90EXX_HAL_IRQ_SUPPORT
    /* Flag to indicate that a new INT0 interrupt has been triggered */
    volatile bool                                 interruptFlag;
#else
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT    
    /* Flag to indicate that a new INT0 interrupt has been triggered */
    volatile bool                                 int0InterruptFlag;
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT   
    /* Flag to indicate that a new INT1 interrupt has been triggered */
    volatile bool                                 int1InterruptFlag;
#endif    
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT  
    /* Flag to indicate that a new WARNOUT interrupt has been triggered */
    volatile bool                                 warnoutInterruptFlag;
#endif

    /* Flag to indicate that a new integration period has been completed */
    volatile bool                                 integrationFlag;

    /* Metrology Analog Front End Data */
    DRV_METROLOGY_AFE_DATA                        metAFEData;

    /* Metrology Calibration interface */
    DRV_METROLOGY_CALIBRATION                     calibrationData;

    /* Harmonic Analysis Data */
    //DRV_METROLOGY_HARMONIC_ANALYSIS               harmonicAnalysisData;
    
    /* HW Interrupt Metrology Callback */
    ATM90EXX_INTERRUPT_CALLBACK                   interruptCallback;

    /* IPC metrology lib integration Callback */
    DRV_METROLOGY_CALLBACK                        integrationCallback;

    /* Calibration Process Callback */
    DRV_METROLOGY_CALIBRATION_CALLBACK            calibrationCallback;

    /* Harmonic Analysis Callback */
    //DRV_METROLOGY_HARMONICS_CALLBACK              harmonicAnalysisCallback;

} ATM90EXX_DRV_OBJ;

#ifdef __cplusplus
}
#endif

#endif // #ifndef DRV_METROLOGY_LOCAL_H
/*******************************************************************************
 End of File
*/
