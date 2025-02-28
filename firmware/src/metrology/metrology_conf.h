/*******************************************************************************
  Interface Configuration of Metrology Driver.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_metrology.h

  Summary:
    Interface configuration of the Metrology Driver.

  Description:
    This file configures the interface for the METROLOGY driver.
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

#ifndef METROLOGY_CONF_H
#define METROLOGY_CONF_H

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
#include "user.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Defines to configure Metrology API
// *****************************************************************************
// *****************************************************************************

#ifdef METROLOGY_ATM90EXX_SUPPORT

#ifdef METROLOGY_ATM90E26_SUPPORT
// ATM90EXX DEVICE SUPPORT
#define METROLOGY_ATM90E2X_SUPPORT
#endif

#if defined(METROLOGY_ATM90E32_SUPPORT) || defined(METROLOGY_ATM90E36_SUPPORT)
#define  METROLOGY_ATM90E3X_SUPPORT
#endif
        
#ifdef METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_API_TEMP_SUPPORT
#endif

// INFORMATION REFRESH SUPPORT
// MEASURING
#define METROLOGY_URMS_SUPPORT                          // Voltage  
#define METROLOGY_IRMS_SUPPORT                          // Current
#define METROLOGY_PFMEAN_SUPPORT                        // Power Factor
        
#ifdef  METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_PFMEANT_SUPPORT                       // Total Power Factor   
#endif
        
#define METROLOGY_PMEAN_SUPPORT                         // Active Power
#ifdef  METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_PMEANT_SUPPORT                        // Total Active Power
#define METROLOGY_PMEANF_SUPPORT                        // Fundamental Active Power
#define METROLOGY_PMEANFT_SUPPORT                       // Total Fundamental Active Power
#define METROLOGY_PMEANH_SUPPORT                        // Harmonics Active Power
#define METROLOGY_PMEANHT_SUPPORT                       // Total Harmonics Active Power
#endif
        
#define METROLOGY_QMEAN_SUPPORT                         // Reactive Power
#ifdef  METROLOGY_ATM90E3X_SUPPORT                      
#define METROLOGY_QMEANT_SUPPORT                        // Total Reactive Power.
#undef  METROLOGY_QMEANF_SUPPORT                        // Fundamental Reactive Power. Not Supported on ATMs
#undef  METROLOGY_QMEANH_SUPPORT                        // Harmonics Reactive Power. Not Supported on ATMs
#endif
        
#define METROLOGY_SMEAN_SUPPORT                         // Apparent Power
#ifdef  METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_SMEANT_SUPPORT                        // Total Apparent Power.
#undef  METROLOGY_SMEANF_SUPPORT                        // Fundamental Apparent Power. Not Supported on ATMs
#undef  METROLOGY_SMEANH_SUPPORT                        // Harmonics Apparent Power. Not Supported on ATMs
#endif
        
#ifdef  METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_MEASURING_TOTAL_SUPPORT
#endif
#if defined(METROLOGY_ATM90E3X_SUPPORT)
#define METROLOGY_PHASE_VX_IX_SUPPORT                   // Phase Between Voltage and Current for the same Phase
#define METROLOGY_PHASE_VX_VA_SUPPORT                   // Phase Between VoltageA and PhaseX
#endif

// METERING
#define METROLOGY_APENERGY_SUPPORT                    // Fordward Active Energy
#ifdef  METROLOGY_ATM90E3X_SUPPORT
 #define METROLOGY_APENERGYT_SUPPORT
 #define METROLOGY_APENERGYF_SUPPORT
 #define METROLOGY_APENERGYFT_SUPPORT
 #define METROLOGY_APENERGYH_SUPPORT
 #define METROLOGY_APENERGYHT_SUPPORT        
#endif
#define METROLOGY_ANENERGY_SUPPORT                    // Reverse Active Energy
#ifdef  METROLOGY_ATM90E3X_SUPPORT
 #define METROLOGY_ANENERGYT_SUPPORT
 #define METROLOGY_ANENERGYF_SUPPORT
 #define METROLOGY_ANENERGYFT_SUPPORT
 #define METROLOGY_ANENERGYH_SUPPORT
 #define METROLOGY_ANENERGYHT_SUPPORT         
#endif
#define METROLOGY_RPENERGY_SUPPORT                    // Fordward Reactive Energy
#ifdef  METROLOGY_ATM90E3X_SUPPORT
 #define METROLOGY_RPENERGYT_SUPPORT  
 #undef  METROLOGY_RPENERGYF_SUPPORT                   // Fundamental Fordward Reactive Energy. Not Supported on ATMs
 #undef  METROLOGY_RPENERGYFT_SUPPORT                  // Total Fundamental Fordward Reactive Energy. Not Supported on ATMs
 #undef  METROLOGY_RPENERGYH_SUPPORT                   // Harmonics Fordward Reactive Energy. Not Supported on ATMs
 #undef  METROLOGY_RPENERGYHT_SUPPORT                  // Total Harmonics Fordward Reactive Energy. Not Supported on ATMs
#endif
#define METROLOGY_RNENERGY_SUPPORT                    // Reverse Reactive Energy
#ifdef  METROLOGY_ATM90E3X_SUPPORT
 #define METROLOGY_RNENERGYT_SUPPORT  
 #undef  METROLOGY_RNENERGYF_SUPPORT                   // Fundamental Reverse Reactive Energy. Not Supported on ATMs
 #undef  METROLOGY_RNENERGYFT_SUPPORT                  // Total Fundamental Reverse Reactive Energy. Not Supported on ATMs
 #undef  METROLOGY_RNENERGYH_SUPPORT                   // Harmonics Reverse Reactive Energy. Not Supported on ATMs
 #undef  METROLOGY_RNENERGYHT_SUPPORT                  // Total Harmonics Reverse Reactive Energy. Not Supported on ATMs
#endif
        
#if defined(METROLOGY_APENERGYT_SUPPORT) || defined(METROLOGY_ANENERGYT_SUPPORT) || defined(METROLOGY_RPENERGYT_SUPPORT) || defined(METROLOGY_RNENERGYT_SUPPORT)
#define METROLOGY_METERING_TOTAL_SUPPORT
#endif
        
// EVENTS SUPPORT
// SAG
#define METROLOGY_API_SAG_SUPPORT

// SWELL
#ifdef METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_API_SWELL_SUPPORT                     // TBD
#endif
        
// NO LOAD
#define METROLOGY_API_NOLOAD_SUPPORT                    // TBD
        
// OVERCURRENT
#ifdef METROLOGY_ATM90E3X_SUPPORT     
#define METROLOGY_API_OVER_CURRENT_SUPPORT              // TBD
#undef METROLOGY_API_OVER_CURRENT_NC_SUPPORT
#undef METROLOGY_API_OVER_CURRENT_NS_SUPPORT            // TBD
#endif        
        
// PHASE LOSS
#ifdef METROLOGY_ATM90E3X_SUPPORT       
#define METROLOGY_API_PHASE_LOSS_SUPPORT                // TBD
#endif
        
// PHASE SEQUENCE ERROR
#ifdef METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_API_PHASE_SEQUENCE_SUPPORT            // TBD
#endif
        
// FREQ RANGE ERROR
#ifdef METROLOGY_ATM90E32_SUPPORT
#define METROLOGY_API_FREQ_RANGE_SUPPORT                // TBD
#endif

// THD+N
#ifdef METROLOGY_ATM90E36_SUPPORT 
#undef METROLOGY_API_THDN_SUPPORT                       // To be developped
#endif

// HARD ERR
#ifdef METROLOGY_ATM90E3X_SUPPORT
#define METROLOGY_API_HARD_ERR_SUPPORT                  // TBD
#endif

#undef METROLOGY_API_CALIBRATION_SUPPORT                // To be developped

#ifdef METROLOGY_ATM90E36_SUPPORT
#undef METROLOGY_API_HARMONICS_SUPPORT                  // To be developped
#endif

// POWER QUALITY SUPPORT
#ifdef METROLOGY_ATM90E32_SUPPORT
#define METROLOGY_UPEAK_SUPPORT
#define METROLOGY_IPEAK_SUPPORT
#endif

// INTERRUPT POLLING SUPPORT
#define METROLOGY_POLL_INT_SUPPORT


#endif // METROLOGY_ATM90EXX_SUPPORT

#ifdef __cplusplus
 }
#endif

#endif // #ifndef DRV_ATM90EXX_H
/*******************************************************************************
 End of File
*/
