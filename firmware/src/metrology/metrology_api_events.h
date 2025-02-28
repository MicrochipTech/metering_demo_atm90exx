/*******************************************************************************
  Interface definition of METROLOGY_API_EVENTS.

  Company:
    Microchip Technology Inc.

  File Name:
    metrology_api_events.h

  Summary:
    Interface definition of the Metrology Events Driver.

  Description:
    This file defines the interface for the Metrology Events driver.
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

#ifndef METROLOGY_API_EVENTS_H
#define METROLOGY_API_EVENTS_H

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
#include "metrology_api.h"
#include "metrology_api_events.h"

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

#ifdef METROLOGY_ATM90EXX_SUPPORT
#define METROLOGY_API_get_events(X...)                  ATM90EXX_API_get_events(X)
#endif

#ifdef METROLOGY_API_SAG_SUPPORT
#ifdef METROLOGY_ATM90EXX_SUPPORT
#define METROLOGY_API_enable_sag(X...)                  ATM90EXX_API_enable_sag(X)
#define METROLOGY_API_disable_sag(X...)                 ATM90EXX_API_disable_sag(X)
#endif
#else
#define METROLOGY_API_enable_sag(X...)                  METROLOGY_API_error(X)
#define METROLOGY_API_disable_sag(X...)                 METROLOGY_API_error(X)
#define METROLOGY_API_set_sag_threshold(X...)           METROLOGY_API_error(X)
#define METROLOGY_API_get_sag_threshold(X...)           METROLOGY_API_error(X)
#define METROLOGY_API_set_sag_period(X...)              METROLOGY_API_error(X)
#define METROLOGY_API_get_sag_period(X...)              METROLOGY_API_error(X)
#endif

#if defined(METROLOGY_API_SWELL_SUPPORT) 
#ifdef METROLOGY_ATM90E32_SUPPORT
#define METROLOGY_API_enable_swell(X...)                ATM90EXX_API_enable_swell(X)
#define METROLOGY_API_disable_swell(X...)               ATM90EXX_API_disable_swell(X)
#endif
#else
#define METROLOGY_API_enable_swell(X...)                METROLOGY_API_error(X)
#define METROLOGY_API_disable_swell(X...)               METROLOGY_API_error(X)
#define METROLOGY_API_set_swell_threshold(X...)         METROLOGY_API_error(X)
#define METROLOGY_API_get_swell_threshold(X...)         METROLOGY_API_error(X)
#endif

#if defined(METROLOGY_API_OVER_CURRENT_SUPPORT)
#ifdef METROLOGY_ATM90EXX_SUPPORT
#define METROLOGY_API_enable_overcurrent(X...)          ATM90EXX_API_enable_overcurrent(X)
#define METROLOGY_API_disable_overcurrent(X...)         ATM90EXX_API_disable_overcurrent(X)
#endif
#else
#define METROLOGY_API_enable_overcurrent(X...)          METROLOGY_API_error(X)
#define METROLOGY_API_disable_overcurrent(X...)         METROLOGY_API_error(X)
#define METROLOGY_API_set_overcurrent_threshold(X...)   METROLOGY_API_error(X)
#define METROLOGY_API_get_overcurrent_threshold(X...)   METROLOGY_API_error(X)
#endif

#if defined(METROLOGY_API_PHASE_LOSS_SUPPORT)
#ifdef METROLOGY_ATM90EXX_SUPPORT
#define METROLOGY_API_enable_phase_loss(X...)           ATM90EXX_API_enable_phase_loss(X)
#define METROLOGY_API_disable_phase_loss(X...)          ATM90EXX_API_disable_phase_loss(X)
#endif
#else
#define METROLOGY_API_enable_phase_loss(X...)           METROLOGY_API_error(X)
#define METROLOGY_API_disable_phase_loss(X...)          METROLOGY_API_error(X)
#define METROLOGY_API_set_phase_loss_threshold(X...)    METROLOGY_API_error(X)
#define METROLOGY_API_get_phase_loss_threshold(X...)    METROLOGY_API_error(X)
#endif


#if defined(METROLOGY_API_PHASE_SEQUENCE_ERROR_SUPPORT)
#ifdef METROLOGY_ATM90EXX_SUPPORT
#define METROLOGY_API_enable_phase_loss(X...)           ATM90EXX_API_enable_phase_sequence_err(X)
#define METROLOGY_API_disable_phase_loss(X...)          ATM90EXX_API_disable_phase_sequence_err(X)
#endif
#else
#define METROLOGY_API_enable_phase_sequence_err(X...)   METROLOGY_API_error(X)
#define METROLOGY_API_disable_phase_sequence_err(X...)  METROLOGY_API_error(X)
#endif

#ifdef __cplusplus
 }
#endif

#endif // #ifndef DRV_ATM90EXX_H
/*******************************************************************************
 End of File
*/
