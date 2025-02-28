/*******************************************************************************
  Interface definition of Metrology Driver.

  Company:
    Microchip Technology Inc.

  File Name:
    metrology_api.h

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

#ifndef METROLOGY_API_H
#define METROLOGY_API_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "driver/driver.h"
#include "system/system.h"
#include "device.h"
#include "configuration.h"
#include "metrology_conf.h"
#ifdef METROLOGY_ATM90EXX_SUPPORT
#include "atm90exx/atm90exx_conf.h"
#include "atm90exx/atm90exx_defs.h"
#include "atm90exx/atm90exx_regs.h"
#include "atm90exx/atm90exx_api.h"
#include "atm90exx/atm90exx_api_events.h"
#include "atm90exx/atm90exx_drv.h"
#endif

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

#ifdef METROLOGY_ATM90EXX_SUPPORT
// DEFINITIONS
#define METROLOGY_CONF                                  ATM90EXX_CONF
#define METROLOGY_REGS_CONTROL                          ATM90EXX_CONF
#define METROLOGY_REGS_STATUS                           ATM90EXX_REGS_STATUS
#define METROLOGY_REGS_ACC                              ATM90EXX_ACC
#define METROLOGY_API_INTEGRATION_CALLBACK              ATM90EXX_DRV_INTEGRATION_CALLBACK
#define METROLOGY_API_EVENT_CALLBACK                    ATM90EXX_DRV_EVENT_CALLBACK
//#define METROLOGY_API_EVENTS                            ATM90EXX_API_EVENTS
// DRIVER FUNCTIONS
#define METROLOGY_DRV_Open(X...)                        ATM90EXX_DRV_Open(X)
#define METROLOGY_DRV_Init(X...)                        ATM90EXX_DRV_Init(X)
#define METROLOGY_DRV_Close(X...)                       ATM90EXX_DRV_Close(X)
#define METROLOGY_DRV_Start(X...)                       ATM90EXX_DRV_Start(X)
#define METROLOGY_DRV_GetStatus(X...)                   ATM90EXX_DRV_GetStatus(X)
#define METROLOGY_DRV_Tasks(X...)                       ATM90EXX_DRV_Tasks(X)
#define METROLOGY_DRV_read_reg(X...)                    ATM90EXX_DRV_read_reg(X)
#define METROLOGY_DRV_write_reg(X...)                   ATM90EXX_DRV_write_reg(X)
#define METROLOGY_DRV_IntegrationCallbackRegister(X...) ATM90EXX_DRV_IntegrationCallbackRegister(X)
#define METROLOGY_DRV_EventCallbackRegister(X...)       ATM90EXX_DRV_EventCallbackRegister(X)
// API FUNCTIONS
#define METROLOGY_API_get_scale_factor(X...)            ATM90EXX_API_get_scale_factor(X)
#define METROLOGY_API_set_scale_factor(X...)            ATM90EXX_API_set_scale_factor(X)
#define METROLOGY_API_SetConfiguration(X...)            ATM90EXX_API_SetConfiguration(X)
#define METROLOGY_API_GetConfigurationByDefault(X...)   ATM90EXX_API_GetConfigurationByDefault(X)
#define METROLOGY_API_SetConfigurationByDefault(X...)   ATM90EXX_API_SetConfigurationByDefault(X)
#define METROLOGY_API_SetBasicConfiguration(X...)       ATM90EXX_API_SetBasicConfiguration(X)

// METROLOGY ACCURACY        
#define METROLOGY_V_ACCURACY_INT                        ATM90EXX_V_ACCURACY_INT
#define METROLOGY_I_ACCURACY_INT                        ATM90EXX_I_ACCURACY_INT        
#define METROLOGY_PQS_ACCURACY_INT                      ATM90EXX_PQS_ACCURACY_INT
#define METROLOGY_PF_ACCURACY_INT                       ATM90EXX_PF_ACCURACY_INT            
#define METROLOGY_ANGLE_ACCURACY_INT                    ATM90EXX_ANGLE_ACCURACY_INT
#define METROLOGY_SECS_IN_HOUR_INT                      ATM90EXX_SECS_IN_HOUR_INT
#define METROLOGY_FREQ_ACCURACY_INT                     ATM90EXX_FREQ_ACCURACY_INT
#define METROLOGY_TEMP_ACCURACY_INT                     ATM90EXX_TEMP_ACCURACY_INT
#endif

#ifdef METROLOGY_ATM90E26_SUPPORT
#define METROLOGY_API_VOLTAGE_LINES  1
#define METROLOGY_API_CURRENT_LINES  2
#define METROLOGY_API_POWER_LINES    2
#define METROLOGY_API_PULSE_LINES    2
#endif

#ifdef METROLOGY_ATM90E32_SUPPORT
#define METROLOGY_API_VOLTAGE_LINES  3
#define METROLOGY_API_CURRENT_LINES  3
#define METROLOGY_API_POWER_LINES    3
#define METROLOGY_API_PULSE_LINES    4
#endif

#ifdef METROLOGY_ATM90E36_SUPPORT
#define METROLOGY_API_VOLTAGE_LINES  3
#define METROLOGY_API_CURRENT_LINES  4
#define METROLOGY_API_POWER_LINES    4
#define METROLOGY_API_PULSE_LINES    4
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
#if 0
typedef enum {
  DECIMAL_NOTATION,
  Q_NOTATION,
  BCD_NOTATION
} METROLOGY_API_VALUE_FORMAT;

typedef struct {
  METROLOGY_API_NOTATION type;  /* 0: Q Notation, 1: Decimal, 2: BCD notation */
  uint32_t m;     /* Integer Part    */
  uint32_t n;     /* Fractional Part */
  uint32_t s;     /* Signed ?        */
} METROLOGY_API_VALUE_FORMAT;
#endif

typedef enum {
  DECIMAL_NOTATION,
  Q_NOTATION,        
  BCD_NOTATION
} METROLOGY_API_VALUE_FORMAT;

void METROLOGY_API_get_Vrms(METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_API_VALUE_FORMAT format);

void METROLOGY_API_get_Irms(METROLOGY_API_CURRENT_LINE line, uint32_t *value, METROLOGY_API_VALUE_FORMAT format);

void METROLOGY_API_get_PAngle(METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void METROLOGY_API_get_UAngle(METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_Pmean(METROLOGY_API_PMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_PmeanF(METROLOGY_API_PMEANF_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_PmeanH(METROLOGY_API_PMEANH_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_Qmean(METROLOGY_API_QMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_Smean(METROLOGY_API_SMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_PFmean(METROLOGY_API_PMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_AEnergy(METROLOGY_API_AENERGY_TYPE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_AFEnergy(METROLOGY_API_AFENERGY_TYPE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_AHEnergy(METROLOGY_API_AHENERGY_TYPE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_QEnergy(METROLOGY_API_QENERGY_TYPE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format);

void  METROLOGY_API_get_SEnergy(METROLOGY_API_SENERGY_TYPE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format);

void METROLOGY_API_clear_AEnergy(METROLOGY_API_AENERGY_TYPE type);

void METROLOGY_API_clear_AFEnergy(METROLOGY_API_AFENERGY_TYPE type);

void METROLOGY_API_clear_AHEnergy(METROLOGY_API_AHENERGY_TYPE type);

void METROLOGY_API_clear_QEnergy(METROLOGY_API_QENERGY_TYPE type);

void METROLOGY_API_clear_SEnergy(METROLOGY_API_SENERGY_TYPE type);

bool METROLOGY_API_CheckPhaseEnabled(METROLOGY_API_VOLTAGE_LINE line);

bool METROLOGY_API_get_regInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name);

bool METROLOGY_API_get_regControlInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name);

bool METROLOGY_API_get_regStatusInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name);

bool METROLOGY_API_get_regAccumulatorsInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name);

uint16_t METROLOGY_API_get_regControlInfoEntries(void);

uint16_t METROLOGY_API_get_regStatusInfoEntries(void);

uint16_t METROLOGY_API_get_regAccumulatorsInfoEntries(void);

METROLOGY_CONF * METROLOGY_API_GetConfigData( void );

/*******************************************************************************
  Function:
    void METROLOGY_API_get_temperature ( uint32_t *temp )
      - temp: temperature in format (uQ20.12)
  Remarks:
    Same format on all ATM90E3X: 
      - 1LSB corresponds to 1 °C Signed, MSB as the sign bit
 */
void METROLOGY_API_get_temperature(uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format);

/*******************************************************************************
  Function:
    void METROLOGY_API_get_frequency ( uint32_t *freq )
      - freq: Active Line Voltage Fundamental Harmonic Frequency to (uQ20.12)
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_frequency(uint32_t *value, METROLOGY_API_VALUE_FORMAT format);


#ifdef __cplusplus
 }
#endif

#endif // #ifndef METROLOGY_API_H
/*******************************************************************************
 End of File
*/
