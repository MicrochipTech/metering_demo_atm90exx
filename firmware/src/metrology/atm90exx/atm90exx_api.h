/*******************************************************************************
  Interface definition of ATM90EXX API.

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_api.h

  Summary:
    Interface definition of the ATM90EXX API.

  Description:
    This file defines the interface for the ATM90EXX API.
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

#ifndef ATM90EXX_API_H
#define ATM90EXX_API_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "device.h"
#include "definitions.h"

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

typedef enum {
    ATM90EXX_API_SUCCESS,
    ATM90EXX_API_ERROR
} ATM90EXX_API_RESULT;

typedef enum {
    ATM90EXX_VLINE_UA  = 0x01,
    ATM90EXX_VLINE_UB  = 0x02,
    ATM90EXX_VLINE_UC  = 0x04,
    ATM90EXX_VLINE_ALL = 0x1F
} ATM90EXX_API_VOLTAGE_LINE;

typedef enum {
    ATM90EXX_CLINE_IN  = 0x00,
    ATM90EXX_CLINE_IA  = 0x01,
    ATM90EXX_CLINE_IB  = 0x02,
    ATM90EXX_CLINE_IC  = 0x04, 
    ATM90EXX_CLINE_ALL = 0x1F,
#ifdef ATM90E36_SUPPORT
    ATM90EXX_CLINE_INS = 0x20
#endif
} ATM90EXX_API_CURRENT_LINE;

typedef enum {
    ATM90EXX_PMEANA  = 0x01,
    ATM90EXX_PMEANB  = 0x02,
    ATM90EXX_PMEANC  = 0x04,
    ATM90EXX_PMEANT  = 0x1F            
} ATM90EXX_API_PMEAN_LINE;

typedef enum {
    ATM90EXX_QMEANA  = 0x01,
    ATM90EXX_QMEANB  = 0x02,
    ATM90EXX_QMEANC  = 0x04,
    ATM90EXX_QMEANT  = 0x1F            
} ATM90EXX_API_QMEAN_LINE;

typedef enum {
    ATM90EXX_SMEANA  = 0x01,
    ATM90EXX_SMEANB  = 0x02,
    ATM90EXX_SMEANC  = 0x04,
    ATM90EXX_SAMEANT = 0x1F,   
#ifdef ATM90E36_SUPPORT            
    ATM90EXX_SVMEANT = 0x20
#endif
} ATM90EXX_API_SMEAN_LINE;

typedef enum {
    ATM90EXX_PMEANAF  = 0x01,
    ATM90EXX_PMEANBF  = 0x02,
    ATM90EXX_PMEANCF  = 0x04,
    ATM90EXX_PMEANTF  = 0x1F            
} ATM90EXX_API_PMEANF_LINE;

typedef enum {
    ATM90EXX_PMEANAH  = 0x01,
    ATM90EXX_PMEANBH  = 0x02,
    ATM90EXX_PMEANCH  = 0x04,
    ATM90EXX_PMEANCT  = 0x1F
} ATM90EXX_API_PMEANH_LINE;

typedef enum {
    ATM90EXX_AENERGYA  = 0x0001,      /* Total Active Energy Phase A. Only Exists in ATM90E26 and Metrology Classical */
    ATM90EXX_AENERGYB  = 0x0002,      /* Total Active Energy Phase C */
    ATM90EXX_AENERGYC  = 0x0004,      /* Total Active Energy Phase B */
    ATM90EXX_AENERGY   = 0x001F       /* Total Active Energy */
}ATM90EXX_API_AENERGY_TYPE;

typedef enum {
    ATM90EXX_AFENERGYA  = 0x0001,     /* Total Active Fundamental Energy Phase A. Like on Classical Metrology */
    ATM90EXX_AFENERGYB  = 0x0002,     /* Total Active Fundamental Energy Phase C. Like on Classical Metrology */
    ATM90EXX_AFENERGYC  = 0x0004,     /* Total Active Fundamental Energy Phase B. Like on Classical Metrology */
    ATM90EXX_AFENERGY   = 0x001F      /* Total Active Fundamental Energy */
}ATM90EXX_API_AFENERGY_TYPE;

typedef enum {
    ATM90EXX_AHENERGYA  = 0x0001,     /* Total Active Harmonics Energy Phase A */
    ATM90EXX_AHENERGYB  = 0x0002,     /* Total Active Harmonics Energy Phase C */
    ATM90EXX_AHENERGYC  = 0x0004,     /* Total Active Harmonics Energy Phase B */
    ATM90EXX_AHENERGY   = 0x001F      /* Total Active Harmonics Energy */
}ATM90EXX_API_AHENERGY_TYPE;

typedef enum {
    ATM90EXX_QENERGYA  = 0x0001,      /* Total Reactive Energy Phase A */
    ATM90EXX_QENERGYB  = 0x0002,      /* Total Reactive Energy Phase C */
    ATM90EXX_QENERGYC  = 0x0004,      /* Total Reactive Energy Phase B */
    ATM90EXX_QENERGY   = 0x001F      /* Total Reactive Energy */
}ATM90EXX_API_QENERGY_TYPE;

typedef enum {
    ATM90EXX_SENERGYA  = 0x0001,       /* Total Apparent Energy Phase A */
    ATM90EXX_SENERGYB  = 0x0002,       /* Total Apparent Energy Phase C */
    ATM90EXX_SENERGYC  = 0x0004,       /* Total Apparent Energy Phase B */
    ATM90EXX_SAENERGY  = 0x001F,       /* Total Arithmetic Apparent Energy */
    ATM90EXX_SVENERGY  = 0x0020        /* Total Vectorial Sum Apparent Energy */
}ATM90EXX_API_SENERGY_TYPE;

typedef enum {
    ATM90EXX_LINE_TYPE_VOLTAGE = 0,
    ATM90EXX_LINE_TYPE_CURRENT = 1,
    ATM90EXX_LINE_TYPE_ALL = 2
} ATM90EXX_API_LINE_TYPE;

METROLOGY_SCALE_FACTOR ATM90EXX_API_get_scale_factor(METROLOGY_API_LINE_TYPE type);

ATM90EXX_API_RESULT ATM90EXX_API_set_scale_factor(METROLOGY_API_LINE_TYPE type, METROLOGY_SCALE_FACTOR factor);

uint64_t ATM90EXX_API_apply_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor);

uint64_t ATM90EXX_API_remove_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor);

uint64_t ATM90EXX_API_apply_inverse_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor);

uint64_t ATM90EXX_API_remove_inverse_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor);

ATM90EXX_API_RESULT ATM90EXX_API_get_Vrms(ATM90EXX_API_VOLTAGE_LINE line, uint32_t *rms);

ATM90EXX_API_RESULT ATM90EXX_API_get_Irms(ATM90EXX_API_CURRENT_LINE line, uint32_t *rms);

ATM90EXX_API_RESULT ATM90EXX_API_get_PAngle(ATM90EXX_API_CURRENT_LINE line, uint32_t *phase, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_UAngle(ATM90EXX_API_VOLTAGE_LINE line, uint32_t *phase, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_Pmean(ATM90EXX_API_PMEAN_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_PmeanF(ATM90EXX_API_PMEANF_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_PmeanH(ATM90EXX_API_PMEANH_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_Qmean(ATM90EXX_API_QMEAN_LINE line, uint32_t *qmean, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_Smean(ATM90EXX_API_SMEAN_LINE line, uint32_t *smean, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_PFmean(ATM90EXX_API_PMEAN_LINE line, uint32_t *pfmean, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_AEnergy(ATM90EXX_API_AENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_AFEnergy(ATM90EXX_API_AFENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_AHEnergy(ATM90EXX_API_AHENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_QEnergy(ATM90EXX_API_QENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_get_SEnergy(ATM90EXX_API_SENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign);

ATM90EXX_API_RESULT ATM90EXX_API_clear_AEnergy(METROLOGY_API_AENERGY_TYPE type);

ATM90EXX_API_RESULT ATM90EXX_API_clear_AFEnergy(METROLOGY_API_AFENERGY_TYPE type);

ATM90EXX_API_RESULT ATM90EXX_API_clear_AHEnergy(METROLOGY_API_AHENERGY_TYPE type);

ATM90EXX_API_RESULT ATM90EXX_API_clear_QEnergy(METROLOGY_API_QENERGY_TYPE type);

ATM90EXX_API_RESULT ATM90EXX_API_clear_SEnergy(METROLOGY_API_SENERGY_TYPE type);

bool ATM90EXX_API_CheckPhaseEnabled(ATM90EXX_API_VOLTAGE_LINE line);

ATM90EXX_API_RESULT ATM90EXX_API_SetConfiguration(ATM90EXX_CONF * config);

ATM90EXX_API_RESULT ATM90EXX_API_GetConfigurationByDefault(ATM90EXX_CONF * config);

ATM90EXX_API_RESULT ATM90EXX_API_SetConfigurationByDefault();

ATM90EXX_API_RESULT ATM90EXX_API_SetBasicConfiguration(METROLOGY_BASIC_CONF * config);

ATM90EXX_CONF * ATM90EXX_API_GetConfigData( void );

bool ATM90EXX_API_get_regInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT lATM90EXX_API_get_frequency ( uint32_t *freq )
      - freq: Converted frequency to (uQ0.32)
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_frequency(uint16_t *freq);

#ifdef ATM90E3X_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_temp ( uint16_t *temp, METROLOGY_MEASURE_SIGN *sign )
      - freq: Converted Temperature to (uQ0.32)
  Remarks:
    Same format on all ATM90EXX
    1LSB corresponds to 1 °C Signed, MSB as the sign bit
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_temp(uint16_t *temp, METROLOGY_MEASURE_SIGN *sign);
#endif

#ifdef ATM90E2X_SUPPORT
ATM90EXX_API_CURRENT_LINE ATM90E26_API_get_active_cline(void)
#endif

#ifdef __cplusplus
 }
#endif

#endif // #ifndef DRV_ATM90EXX_H
/*******************************************************************************
 End of File
*/
