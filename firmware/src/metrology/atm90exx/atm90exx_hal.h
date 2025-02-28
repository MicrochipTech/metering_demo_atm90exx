/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_hal.h

  Summary:
    This header file provides prototypes and definitions for the atm90exx HAL.

  Description:
    This header file provides prototypes and definitions for the atm90exx HAL.

*******************************************************************************/

#ifndef _ATM90EXX_HAL_H
#define _ATM90EXX_HAL_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"
#include "atm90exx_defs.h"

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

#define ATM90EXX_MAX_RETRIES 3    
    
typedef enum {
    ATM90EXX_HAL_SUCCESS,
    ATM90EXX_HAL_ERROR
} ATM90EXX_HAL_RESULT;

typedef enum {
    ATM90EXX_HAL_SERIAL,
    ATM90EXX_HAL_SPI
} ATM90EXX_HAL_IFACE_TYPE;

typedef enum {
    ATM90EXX_SPI_TRANSFER_IN_PROGRESS,
    ATM90EXX_SPI_TRANSFER_COMPLETED,
    ATM90EXX_SPI_TRANSFER_ERROR
} ATM90EXX_SPI_TRANSFER_STATE;

#define ATM90EXX_HAL_RESET_CLEAR()          ATM90EXX_RESET_PIO_Clear()
#define ATM90EXX_HAL_RESET_SET()            ATM90EXX_RESET_PIO_Set()

#define ATM90EXX_RESET_TIMEOUT_MS           5
#define ATM90EXX_RESET_AFTER_POR_MS         1
#define ATM90EXX_RESET_OUT_TIMEOUT_MS       1
#define ATM90EXX_IDLE_TIMEOUT_MS            1

#ifdef ATM90E3X_HAL_PMX_PIO_SUPPORT   
#define ATM90E3X_PM0_CLEAR()                ATM90E3X_PM0_PIO_Clear() 
#define ATM90E3X_PM0_SET()                  ATM90E3X_PM0_PIO_Set()
#define ATM90E3X_PM1_CLEAR()                ATM90E3X_PM1_PIO_Clear() 
#define ATM90E3X_PM1_SET()                  ATM90E3X_PM1_PIO_Set()
#endif

#ifdef ATM90E3X_HAL_DMA_CTRL_PIO_SUPPORT   
#define ATM90E3X_DMA_CTRL_CLEAR()           ATM90E36_DMA_CTRL_PIO_Clear() 
#define ATM90E3X_DMA_CTRL_SET()             ATM90E36_DMA_CTRL_PIO_Set()
#endif

#ifdef ATM90EXX_HAL_MMDX_PIO_SUPPORT
#define ATM90EXX_MMD0_CLEAR()               ATM90EXX_MMD0_PIO_Clear()
#define ATM90EXX_MMD0_SET()                 ATM90EXX_MMD0_PIO_Set()
#define ATM90EXX_MMD1_CLEAR()               ATM90EXX_MMD1_PIO_Clear()
#define ATM90EXX_MMD1_SET()                 ATM90EXX_MMD1_PIO_Set()
#endif

#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
#define ATM90EXX_IRQ0_INT_MSK               EIC_PIN_8
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
#define ATM90EXX_IRQ1_INT_MSK               EIC_PIN_2
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
#define ATM90EXX_WARNOUT_INT_MSK            EIC_PIN_3
#endif

#ifdef ATM90E26_HAL_USEL_PIO_SUPPORT
#define ATM90EXX_USEL_SET()                 ATM90E26_USEL_PIO_Set()
#define ATM90EXX_USEL_CLEAR()               ATM90E26_USEL_PIO_Clear()
#endif


typedef void (*ATM90EXX_HAL_INT_CALLBACK) (uint32_t context);

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

#if defined (ATM90EXX_SPI_DRIVER)
#define ATM90EXX_TX_BUFF_SIZE 4
#define ATM90EXX_RX_BUFF_SIZE 4
#else
#define ATM90EXX_TX_BUFF_SIZE 5
#define ATM90EXX_RX_BUFF_SIZE 3
#endif


#define ATM90EXX_TRANSFER_TIMEOUT_MS 20

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void ATM90EXX_HAL_Initialize ( void )

  Summary:
     ATM90EXX Hardware Abstraction Layer Initialization

  Description:
    This function initializes the ATM90EXX Hardware Abstraction Layer (HAL).  
    It places the HAL in its initial state and prepares it to run so that its
    ATM90EXX_HAL_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    ATM90EXX_HAL_Initialize ();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

ATM90EXX_HAL_RESULT ATM90EXX_HAL_Init ( void );

DRV_HANDLE ATM90EXX_HAL_Open ( void );

ATM90EXX_HAL_RESULT ATM90EXX_HAL_Close ( DRV_HANDLE handle );

ATM90EXX_HAL_RESULT ATM90EXX_HAL_read_reg ( DRV_HANDLE handle, uint16_t reg, uint16_t *val );

ATM90EXX_HAL_RESULT ATM90EXX_HAL_write_reg ( DRV_HANDLE handle, uint16_t reg, uint16_t val );

#if defined(ATM90EXX_IRQ_SUPPORT)
void ATM90EXX_HAL_enable_interrupts (void);
void ATM90EXX_HAL_disable_interrupts (void);
#endif

#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
void ATM90EXX_HAL_Set_Irq0Int_Handler ( void *callback, uintptr_t context );
#endif

#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
void ATM90EXX_HAL_Set_Irq1Int_Handler ( void *callback, uintptr_t context );
#endif

#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
void ATM90EXX_HAL_Set_WarnoutInt_Handler ( void *callback, uintptr_t context );
#endif

#ifdef ATM90EXX_HAL_MMDX_PIO_SUPPORT
void ATM90EXX_HAL_set_MeterMode (ATM90EXX_METERING_MODE_STATES mode);
#endif

#ifdef ATM90E3X_HAL_PMX_PIO_SUPPORT   
ATM90EXX_HAL_RESULT ATM90E3X_HAL_set_PowerMode (ATM90E3X_POWER_MODE_STATES mode);
#endif

#ifdef ATM90E26_HAL_USEL_PIO_SUPPORT   
/*******************************************************************************
  Function:
    ATM90EXX_HAL_RESULT ATM90EXX_HAL_set_Usel ( ATM90EXX_USEL_MODE usel )

  Remarks:
    Sets the ATM90E32/36 Power Mode configuring PM0-1 HW pins
 */
ATM90EXX_HAL_RESULT ATM90EXX_HAL_set_Usel (ATM90EXX_HAL_IFACE_TYPE usel);
#endif

/*******************************************************************************
  Function:
    void ATM90EXX_HAL_disable_integration_period ( void )

  Remarks:
    Depends on the implementation
 */
void ATM90EXX_HAL_stop_integration_period( SYS_TIME_HANDLE handle );

/*******************************************************************************
  Function:
    void ATM90EXX_HAL_set_integration_period( uint32_t period_ms, TC_TIMER_CALLBACK callback, uintptr_t context )

  Remarks:
    Depends on the implementation
 */
SYS_TIME_HANDLE ATM90EXX_HAL_start_integration_period(uint32_t period_ms, SYS_TIME_CALLBACK callback, uintptr_t context );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _DRIVER_ATM90EXX_H */

/*******************************************************************************
 End of File
 */

