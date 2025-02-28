/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_regs.h

  Summary:
    This header file provides prototypes and definitions for the atm90exx regs.

  Description:
    This header file provides prototypes and definitions for the atm90exx regs.
    
*******************************************************************************/

#ifndef ATM90EXX_REGS_H
#define ATM90EXX_REGS_H

#include <stdbool.h>
#include "driver/driver.h"
#include "system/system.h"

#ifdef METROLOGY_ATM90E26_SUPPORT
#include "atm90e26_regs.h"
#endif

#ifdef METROLOGY_ATM90E32_SUPPORT
#include "atm90e32_regs.h"
#endif

#ifdef METROLOGY_ATM90E36_SUPPORT
#include "atm90e36_regs.h"
#endif

#endif /* ATM90EXX_REGS_H */
