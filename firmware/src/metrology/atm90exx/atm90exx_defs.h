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
#include "atm90exx_regs.h"
#include "atm90exx_conf.h"

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

#define ATM90EXX_DEBUG_PRINT(level, format, ...)      SYS_DEBUG_PRINT(level, format, ##__VA_ARGS__)
#define ATM90EXX_DEBUG_MESSAGE(level, message)        SYS_DEBUG_MESSAGE(level, message)

#ifdef ATM90E3X_SUPPORT
/* ATM90E3X Power Mode Definitions */
typedef enum
{
    ATM90E3X_POWER_MODE_IDLE = 0,
    ATM90E3X_POWER_MODE_DETECT,
	  ATM90E3X_POWER_MODE_PARTIAL,
	  ATM90E3X_POWER_MODE_NORMAL
} ATM90E3X_POWER_MODE_STATES;
#endif

#ifdef ATM90E36_SUPPORT
/* ATM90E36 DMA Mode Definitions */
typedef enum
{
    ATM90E3X_DMA_MODE_OFF = 0,
    ATM90E3X_DMA_MODE_ON = 1
} ATM90E36_DMA_MODE;
#endif

typedef	enum
{
	  ATM90E2X_CHIPID_ADDR	= 0x005,
	  ATM90E3X_CHIPID_ADDR	= 0x2F0
} ATM90EXX_CHIPID_ADDR;

typedef enum
{
	AT90E23_CHIPID          = 0x2612,
  AT90E25_CHIPID          = 0x2613,
	AT90E32AS_VA_CHIPID     = 0x0000,
	AT90E32AS_VB_CHIPID     = 0x0001,
	AT90E32_CHIPID          = 0x0001,
	AT90E32A_CHIPID         = 0x0003,
	AT90E36_CHIPID          = 0x8001,
	AT90E36A_CHIPID         = 0x8003	
} ATM90EXX_CHIPID;
typedef	enum
{	
	AT90E32_TYPE		        = 0x02,
	AT90E36_TYPE		        = 0x06,
	AT90E32A_TYPE           = 0x12,
	AT90E36A_TYPE           = 0x16,
	AT90E25_TYPE            = 0x40,
  AT90E24_TYPE            = 0x41,
  AT90E23_TYPE            = 0x42,
	AT90E32AS_TYPE          = 0x82		
} ATM90EXX_TYPE;

typedef enum {
    CONFIG_FLAG_NONE        = 0x0000,    // Inmediate changes apply
    CONFIG_FLAG_INIT        = 0x0001,    
    CONFIG_FLAG_INIT_HW     = 0x0002,    
    CONFIG_FLAG_INIT_SW     = 0x0004,    
    CONFIG_FLAG_NOSTART     = 0x0008,    
    CONFIG_FLAG_CFGSTART    = 0x0010,    
    CONFIG_FLAG_CALSTART    = 0x0020,    
    CONFIG_FLAG_ADJSTART    = 0x0040,    
    CONFIG_FLAG_CFGSTOP     = 0x0080,
    CONFIG_FLAG_HARMSTART   = 0x0100,    
    CONFIG_FLAG_ALL         = 0xFFFF     
} ATM90EXX_CONFIG_FLAGS;

typedef struct {
    uint16_t                dftValue;
    ATM90EXX_REGISTERS_ADDR addr;
    ATM90EXX_CONFIG_FLAGS   configFlags;
    char                    name[10];
} ATM90EXX_REG_INFO;

// atm90exxRegsInfo var and ATM90EXX_REGS structure MUST follow that ORDER!!!!
#define ATM90EXX_REG_CTRL_INFO_OFFSET       0
#define ATM90EXX_REG_THRESHOLD_INFO_OFFSET (ATM90EXX_REG_CTRL_INFO_OFFSET + (sizeof(ATM90EXX_REGS_CONTROL) >> 1))
#define ATM90EXX_REG_CAL_MEAS_INFO_OFFSET  (ATM90EXX_REG_THRESHOLD_INFO_OFFSET + (sizeof(ATM90EXX_REGS_THRESHOLDS) >> 1))
#define ATM90EXX_REG_CAL_MET_INFO_OFFSET   (ATM90EXX_REG_CAL_MEAS_INFO_OFFSET + (sizeof(ATM90EXX_REGS_CAL_MEAS) >> 1))
#define ATM90EXX_REG_STATUS_INFO_OFFSET    (ATM90EXX_REG_CAL_MET_INFO_OFFSET + (sizeof(ATM90EXX_REGS_CAL_MET) >> 1))
#define ATM90EXX_REG_MEAS_INFO_OFFSET      (ATM90EXX_REG_STATUS_INFO_OFFSET + (sizeof(ATM90EXX_REGS_STATUS) >> 1))
#define ATM90EXX_REG_MET_INFO_OFFSET       (ATM90EXX_REG_MEAS_INFO_OFFSET + (sizeof(ATM90EXX_REGS_MEAS) >> 1))
 
#define ATM90EXX_V_ACCURACY_INT        10000U    // Decimal Resolution 0.0001 V
#define ATM90EXX_I_ACCURACY_INT       100000U    // Decimal Resolution 0.00001 A
#define ATM90EXX_PQS_ACCURACY_INT       1000U    // Decimal Resolution 0.001 W/Var/VA
#define ATM90EXX_ANGLE_ACCURACY_INT       10U    // Decimal Resolution 0.1 degree
#define ATM90EXX_PF_ACCURACY_INT        1000U    // Decimal Resolution 0.001 
#define ATM90EXX_SECS_IN_HOUR_INT       3600U    // Decimal Resolution 1 second
#define ATM90EXX_FREQ_ACCURACY_INT       100U    // Decimal Resolution 0.01 Hz
#define ATM90EXX_TEMP_ACCURACY_INT        10U    // Decimal Resolution 0.1 degree
#define ATM90EXX_ENERGY_ACCURACY_INT   10000U    // Decimal Resolution 0.0001 KWh

#define SQRT2  1.4142

#ifdef __cplusplus
}
#endif

#endif // #ifndef DRV_METROLOGY_LOCAL_H
/*******************************************************************************
 End of File
*/
