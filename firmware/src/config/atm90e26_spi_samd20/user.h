/*******************************************************************************
  User Configuration Header

  File Name:
    user.h

  Summary:
    Build-time configuration header for the user defined by this project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    It only provides macro definitions for build-time configuration options

*******************************************************************************/

#ifndef USER_H
#define USER_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: User Configuration macros
// *****************************************************************************
// *****************************************************************************
#define METROLOGY_ATM90EXX_SUPPORT
#define METROLOGY_ATM90E26_SUPPORT
#define METROLOGY_ATM90E26_SPI_SUPPORT
#define OLED1_XPLAINED_PRO_SUPPORT

#define RTC_TimeSet RTC_RTCCTimeSet
#define RTC_TimeGet RTC_RTCCTimeGet
    
// *****************************************************************************
/* Metrology Configuration Filename

  Summary:
    Metrology Configuration Filename.

  Description:
    This is the Metrology Configuration Filename.
*/       
#define METROLOGY_FILENAME "atm90e26"
#define DATALOG_NVM
      
#define SWITCH_SCRUP_EIC_PIN   14
#define SWITCH_SCRDOWN_EIC_PIN 10

// *****************************************************************************
/* Display board identifier

  Summary:
    Display board identifier.

  Description:
    This is the display board identifier.
*/

#define APP_DISPLAY_BOARD_VERSION           0x0001
    
// *****************************************************************************
/* Demo application major version

  Summary:
    Demo application major version.

  Description:
    This is the demo application major version.
    99 is the default value for the development version.
*/
    
#define DEMO_APP_MAJOR_VERSION   1

// *****************************************************************************
/* Demo application minor version

  Summary:
    Demo application minor version.

  Description:
    This is the demo application minor version.
    99 is the default value for the development version.
*/
#define DEMO_APP_MINOR_VERSION   1

// *****************************************************************************
/* Demo application patch version

  Summary:
    Demo application patch version.

  Description:
    This is the demo application patch version.
    99 is the default value for the development version.
*/

#define DEMO_APP_PATCH_VERSION   0

// *****************************************************************************
/* Demo application version

  Summary:
    Demo application version.

  Description:
    This is the demo application version: (MMmmpp - M(Major); m(minor); p(patch)).
    999999 is the default value for the development version.
*/

#define DEMO_APP_VERSION ((DEMO_APP_MAJOR_VERSION)*10000 + (DEMO_APP_MINOR_VERSION)*100 + (DEMO_APP_PATCH_VERSION))
    
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // USER_H
/*******************************************************************************
 End of File
*/
