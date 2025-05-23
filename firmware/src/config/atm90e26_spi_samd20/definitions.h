/*******************************************************************************
  System Definitions

  File Name:
    definitions.h

  Summary:
    project system definitions.

  Description:
    This file contains the system-wide prototypes and definitions for a project.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <time.h>
#include "peripheral/nvmctrl/plib_nvmctrl.h"
#include "driver/memory/drv_memory.h"
#include "driver/memory/drv_memory_nvmctrl.h"
#include "peripheral/tc/plib_tc0.h"
#include "peripheral/rtc/plib_rtc.h"
#include "system/time/sys_time.h"
#include "bsp/bsp.h"
#include "driver/spi/drv_spi.h"
#include "system/int/sys_int.h"
#include "system/ports/sys_ports.h"
#include "system/dma/sys_dma.h"
#include "system/reset/sys_reset.h"
#include "osal/osal.h"
#include "system/debug/sys_debug.h"
#include "peripheral/sercom/usart/plib_sercom3_usart.h"
#include "peripheral/sercom/spi_master/plib_sercom1_spi_master.h"
#include "peripheral/evsys/plib_evsys.h"
#include "system/command/sys_command.h"
#include "peripheral/port/plib_port.h"
#include "peripheral/clock/plib_clock.h"
#include "peripheral/nvic/plib_nvic.h"
#include "peripheral/wdt/plib_wdt.h"
#include "peripheral/sercom/spi_master/plib_sercom5_spi_master.h"
#include "driver/memory/drv_memory.h"
#include "peripheral/pm/plib_pm.h"
#include "peripheral/eic/plib_eic.h"
#include "system/fs/sys_fs.h"
#include "system/fs/sys_fs_media_manager.h"
#include "system/fs/sys_fs_fat_interface.h"
#include "system/fs/fat_fs/file_system/ff.h"
#include "system/fs/fat_fs/file_system/ffconf.h"
#include "system/fs/fat_fs/hardware_access/diskio.h"
#include "system/console/sys_console.h"
#include "system/console/src/sys_console_uart_definitions.h"
#include "./gfx_mono/gfx_definitions.h"
#include "./metrology/metrology_conf.h"
#include "./metrology/metrology_defs.h"
#include "./metrology/metrology_api.h"
#include "./metrology/metrology_api_events.h"
#include "app_metrology.h"
#include "app_datalog.h"
#include "app_events.h"
#include "app_display.h"
#include "app_console.h"
#include "app_energy.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

/* Device Information */
#define DEVICE_NAME          "ATSAMD20J18"
#define DEVICE_ARCH          "CORTEX-M0PLUS"
#define DEVICE_FAMILY        "SAMD"
#define DEVICE_SERIES        "SAMD20"

/* CPU clock frequency */
#define CPU_CLOCK_FREQUENCY 48000000U

// *****************************************************************************
// *****************************************************************************
// Section: System Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* System Initialization Function

  Function:
    void SYS_Initialize( void *data )

  Summary:
    Function that initializes all modules in the system.

  Description:
    This function initializes all modules in the system, including any drivers,
    services, middleware, and applications.

  Precondition:
    None.

  Parameters:
    data            - Pointer to the data structure containing any data
                      necessary to initialize the module. This pointer may
                      be null if no data is required and default initialization
                      is to be used.

  Returns:
    None.

  Example:
    <code>
    SYS_Initialize ( NULL );

    while ( true )
    {
        SYS_Tasks ( );
    }
    </code>

  Remarks:
    This function will only be called once, after system reset.
*/

void SYS_Initialize( void *data );

// *****************************************************************************
/* System Tasks Function

Function:
    void SYS_Tasks ( void );

Summary:
    Function that performs all polled system tasks.

Description:
    This function performs all polled system tasks by calling the state machine
    "tasks" functions for all polled modules in the system, including drivers,
    services, middleware and applications.

Precondition:
    The SYS_Initialize function must have been called and completed.

Parameters:
    None.

Returns:
    None.

Example:
    <code>
    SYS_Initialize ( NULL );

    while ( true )
    {
        SYS_Tasks ( );
    }
    </code>

Remarks:
    If the module is interrupt driven, the system will call this routine from
    an interrupt context.
*/

void SYS_Tasks ( void );

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* System Objects

Summary:
    Structure holding the system's object handles

Description:
    This structure contains the object handles for all objects in the
    MPLAB Harmony project's system configuration.

Remarks:
    These handles are returned from the "Initialize" functions for each module
    and must be passed into the "Tasks" function for each module.
*/

typedef struct
{
    SYS_MODULE_OBJ  sysTime;
    SYS_MODULE_OBJ  drvMemory0;

    SYS_MODULE_OBJ  sysConsole0;

    SYS_MODULE_OBJ sysCommand;

    /* SPI0 Driver Object */
    SYS_MODULE_OBJ drvSPI0;

    SYS_MODULE_OBJ  sysDebug;


} SYSTEM_OBJECTS;

// *****************************************************************************
// *****************************************************************************
// Section: extern declarations
// *****************************************************************************
// *****************************************************************************



extern SYSTEM_OBJECTS sysObj;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* DEFINITIONS_H */
/*******************************************************************************
 End of File
*/

