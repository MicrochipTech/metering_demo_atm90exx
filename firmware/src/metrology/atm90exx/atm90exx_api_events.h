/*******************************************************************************
  Interface definition of ATM90EXX Events API.

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_events_api.h

  Summary:
    Interface definition of the ATM90EXX Events API.

  Description:
    This file defines the interface for the ATM90EXX Events API.
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

#ifndef ATM90EXX_API_EVENTS_H
#define ATM90EXX_API_EVENTS_H

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
#include "atm90exx_defs.h"

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
      
ATM90EXX_API_RESULT ATM90EXX_API_get_events (METROLOGY_API_EVENTS *events);
        
#ifdef ATM90EXX_SAG_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_sag ( ATM90EXX_API_VOLTAGE_LINE phase )

  Remarks:
    Depends on the implementation
    - SAG Detection is always running, the enable is of the interrupt
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_sag ( ATM90EXX_API_VOLTAGE_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT METROLOGY_API_disable_sag ( ATM90EXX_API_VOLTAGE_LINE phase )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_sag ( ATM90EXX_API_VOLTAGE_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_sag_threshold ( uint32_t threshold_rms )
      - line
      - threshold_rms: Format uQ3.29 ????
(uQ0.32)
  Remarks:
    Depends on the implementation
    - ATM90E26:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 cycle after ZC
      Detect Condition: three 8K voltage samples bellow the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_sag_threshold ( uint32_t threshold);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_sag_threshold ( uint32_t threshold_rms )

  Remarks:
    Depends on the implementation
    - ATM90E26:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 cycle after ZC
      Detect Condition: three 8K voltage samples bellow the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_sag_threshold ( uint32_t *threshold );

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_sag_period ( uint32_t period_ms )

  Remarks:
    Depends on the implementation
    - ATM90E26:
      Measurement Period: Fixed. 1 cycle after ZC
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_sag_period ( uint32_t period_ms);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_sag_period ( uint32_t *period_ms )

  Remarks:
    Depends on the implementation:
    - ATM90E26:
      Measurement Period: Fixed. 1 cycle after ZC. Depends on the frequency (FREQ_ADDR - Format XX.XX)
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_sag_period ( uint32_t *period_ms);
#endif // ATM90EXX_SAG_SUPPORT

#ifdef ATM90EXX_SWELL_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_swell ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
    Depends on the implementation
    - SWELL Detection is always running, the enable is of the interrupt
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_swell (ATM90EXX_API_VOLTAGE_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_swell ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_swell ( ATM90EXX_API_VOLTAGE_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_swell_threshold ( uint32_t threshold_rms )
      - threshold_rms: Volts
  Remarks:
    Depends on the implementation
    - ATM90E32:
      OVth Register: Over Voltage Threshold, default= 0xC000
      Detect: any phase's absolute voltage sample instantaneous value goes over the threshold
      Value: 0xFFFF maps to ADC output full-scale peak.
             xxThRegValue = RmsRegValue*sqrt(2)/(Vgain/2^14)
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_swell_threshold (uint32_t threshold);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_swell_threshold ( uint32_t threshold_rms )

  Remarks:
    Depends on the implementation
    - ATM90E32:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 instantaneous voltage sample
      Detect Condition: 1 instantaneous voltage sample over the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_swell_threshold ( uint32_t *threshold );
#endif // ATM90EXX_SWELL_SUPPORT

#ifdef ATM90EXX_OVER_CURRENT_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_overcurrent ( ATM90EXX_API_CURRENT_LINE line )

  Remarks:
    Depends on the implementation
    - OVERCURRENT Detection is always running, the enable is of the interrupt
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_overcurrent (ATM90EXX_API_CURRENT_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_overcurrent ( ATM90EXX_API_CURRENT_LINE line )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_overcurrent ( ATM90EXX_API_CURRENT_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_overcurrent_threshold ( uint32_t threshold_rms )
      - threshold_rms: Volts - Format??
  Remarks:
    Depends on the implementation
    - ATM90E32:
      OVth Register: Over Voltage Threshold, default= 0xC000
      Detect: any phase's absolute voltage sample instantaneous value goes over the threshold
      Value: 0xFFFF maps to ADC output full-scale peak.
             xxThRegValue = RmsRegValue*sqrt(2)/(Vgain/2^14)
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_overcurrent_threshold ( ATM90EXX_API_CURRENT_LINE line, uint32_t threshold );

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_overcurrent_threshold ( uint32_t threshold_rms )

  Remarks:
    Depends on the implementation
    - ATM90E32:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 instantaneous voltage sample
      Detect Condition: 1 instantaneous voltage sample over the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_overcurrent_threshold ( ATM90EXX_API_CURRENT_LINE line, uint32_t *threshold );
#endif // ATM90EXX_OVER_CURRENT_SUPPORT

#ifdef ATM90EXX_PHASE_LOSS_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_loss ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
      Phase Loss Detection. Depends on the implementation
      - ATM90E26: Doesn't exist
      - ATM90E32: Phase configurable
      - ATM90E36: All together
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_loss (ATM90EXX_API_VOLTAGE_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_loss ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
      Phase Loss Detection. Depends on the implementation
      - ATM90E26: Doesn't exist
      - ATM90E32: Phase configurable
      - ATM90E36: All together
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_loss ( ATM90EXX_API_VOLTAGE_LINE line);

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_phase_loss_threshold ( uint32_t threshold )
      - threshold_rms: Volts - Format??
  Remarks:
    Depends on the implementation
    - ATM90E26: Doesn't exist
    - ATM90E32:
      OVth Register: Over Voltage Threshold, default= 0xC000
      Detect: any phase's absolute voltage sample instantaneous value goes over the threshold
      Value: 0xFFFF maps to ADC output full-scale peak.
             xxThRegValue = RmsRegValue*sqrt(2)/(Vgain/2^14)
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_phase_loss_threshold ( uint32_t threshold );

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_phaseloss_threshold ( uint32_t *threshold_rms )

  Remarks:
    Depends on the implementation
    - ATM90E26: Doesn't exist
    - ATM90E3X:

 */
ATM90EXX_API_RESULT ATM90EXX_API_get_phase_loss_threshold ( uint32_t *threshold );
#endif // ATM90EXX_PHASE_LOSS_SUPPORT

#ifdef ATM90EXX_PHASE_SEQUENCE_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_sequence_err ( ATM90EXX_API_LINE_TYPE type )

  Remarks:
    Depends on the implementation
    - Phase Sequence Error Detection is always running, the enable is of the interrupt
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_sequence_err ( ATM90EXX_API_LINE_TYPE type );

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_sequence_err ( void )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_sequence_err ( ATM90EXX_API_LINE_TYPE type );
#endif // ATM90EXX_PHASE_SEQUENCE_SUPPORT

#ifdef __cplusplus
 }
#endif

#endif // #ifndef DRV_ATM90EXX_H
/*******************************************************************************
 End of File
*/
