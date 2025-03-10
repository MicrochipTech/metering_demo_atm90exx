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

/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_datalog.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_DATALOG_Initialize" and "APP_DATALOG_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_DATALOG_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_DATALOG_H
#define _APP_DATALOG_H

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

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
#if SYS_FS_AUTOMOUNT_ENABLE
    /* Wait for disk Mount */
    APP_DATALOG_STATE_MOUNT_WAIT = 0,
#else
    /* Mount the disk */
    APP_DATALOG_STATE_MOUNT_DISK = 0,
#endif

    /* The app formats the disk. */
    APP_DATALOG_STATE_FORMAT_DISK,

    /* The app checks directories for storage. */
    APP_DATALOG_STATE_CHECK_DIRECTORIES,

    /* The app reads data from file */
    APP_DATALOG_STATE_READ_FROM_FILE,

    /* The app writes data to a file from the beginning */
    APP_DATALOG_STATE_WRITE_TO_FILE,

    /* The app closes the file. */
    APP_DATALOG_STATE_CLOSE_FILE,

    /* The app reports the result from file operation. */
    APP_DATALOG_STATE_REPORT_RESULT,

    /* The app is ready to accept requests */
    APP_DATALOG_STATE_READY,

    /* An app error has occurred */
    APP_DATALOG_STATE_ERROR,

#if SYS_FS_AUTOMOUNT_ENABLE
    /* Wait for delay */
    APP_DATALOG_STATE_DELAY,
#endif

} APP_DATALOG_STATES;


// *****************************************************************************
/* Application Datalog Users

  Summary:
    Potential Datalog Users enumeration

  Description:
    This enumeration defines the different users of the datalog service in
    order to tag the store queue elements by their requester.
*/

typedef enum
{
    /* Metrology data */
    APP_DATALOG_USER_METROLOGY = 0,

    /* Calibration data */
    APP_DATALOG_USER_CALIBRATION,

    /* TOU data */
    APP_DATALOG_USER_TOU,

    /* RTC data */
    APP_DATALOG_USER_RTC,

    /* Console data */
    APP_DATALOG_USER_CONSOLE,

    /* Events data */
    APP_DATALOG_USER_EVENTS,

    /* Energy data */
    APP_DATALOG_USER_ENERGY,

    /* Demand data */
    APP_DATALOG_USER_DEMAND,

    /* Last value used to get number of Users */
    APP_DATALOG_USER_NUM

} APP_DATALOG_USER;


// *****************************************************************************
/* Application Datalog Available Operations

  Summary:
    List of Operations to perform by Datalog

*/

typedef enum
{
    /* Read operation */
    APP_DATALOG_READ = 0,

    /* Append operation */
    APP_DATALOG_APPEND,

    /* Read operation */
    APP_DATALOG_WRITE

} APP_DATALOG_OPERATION;


// *****************************************************************************
/* Application Datalog Possible results

  Summary:
    List of possible results for Datalog Operations

*/

typedef enum
{
    /* Result Success */
    APP_DATALOG_RESULT_SUCCESS = 0,

    /* Result Error */
    APP_DATALOG_RESULT_ERROR

} APP_DATALOG_RESULT;


// *****************************************************************************
/* Invalid year and month definitions

*/
#define APP_DATALOG_INVALID_YEAR   0xFF
#define APP_DATALOG_INVALID_MONTH  0xFF

// *****************************************************************************
/* Application Year/Mont structure

  Summary:
    Holds a year and month value

  Description:
    Information in this structure is used to index files in filesystem.

  Remarks:
    None.
 */

typedef struct
{
    // Year (from 2000)
    uint8_t year;

    // Month (range 1-12)
    uint8_t month;

} APP_DATALOG_DATE;


// *****************************************************************************
/* Callback to report Datalog Operation end and its result

*/
typedef void (*APP_DATALOG_END_CALLBACK)(APP_DATALOG_RESULT result);


// *****************************************************************************
/* Application Queue Data

  Summary:
    Defines data to store in the Datalog Queue

  Description:
    This structure will be used by any module willing to use the Datalog service
    to indicate data to be stored.

  Remarks:
    None.
 */

typedef struct
{
    // Datalog User ID
    APP_DATALOG_USER userId;

    // Read/ReadPrevious/Write/Append operation
    APP_DATALOG_OPERATION operation;

    // Callback to be invoked at the end of Datalog operation
    APP_DATALOG_END_CALLBACK endCallback;

    // Date to index the proper file to read/write
    APP_DATALOG_DATE date;

    // Length of data to be read/written
    uint16_t dataLen;

    // Pointer to data to be written or to store read data
    uint8_t *pData;

} APP_DATALOG_QUEUE_DATA;

#define APP_DATALOG_QUEUE_DATA_SIZE     4

typedef struct {
  APP_DATALOG_QUEUE_DATA data[APP_DATALOG_QUEUE_DATA_SIZE];
  APP_DATALOG_QUEUE_DATA * dataRd;
  APP_DATALOG_QUEUE_DATA * dataWr;
  uint8_t dataSize;
} APP_DATALOG_QUEUE;

// *****************************************************************************
/* Application Queue Data in Process

  Summary:
    Defines data in process by Datalog tasks

  Description:
    This structure will be used by Datalog service to process the income request.

  Remarks:
    None.
 */

typedef struct
{
    // Datalog Queue in process
    APP_DATALOG_QUEUE_DATA data;

    // File Handle
    SYS_FS_HANDLE fileHandle;

    // File Name
    char fileName[32];

} APP_DATALOG_DATA_IN_PROCESS;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_DATALOG_STATES state;

    /* Format Options */
    SYS_FS_FORMAT_PARAM formatOpt;

    /* Element extracted from Queue to be processed */
    APP_DATALOG_DATA_IN_PROCESS newData;

    /* Current File Name */
    char fileName[32];

    /* Result from file operation */
    APP_DATALOG_RESULT result;

    /* Flag to indicate whether disk is mounted */
    bool diskMounted;

    /* Flag to indicate whether disk needs format */
    bool diskFormatRequired;

    /* Path File Name Buffer used in clear data routine */
    char filePath[257];

    /* SYS FS File status structure used in clear data routine */
    SYS_FS_FSTAT stat;

#if SYS_FS_AUTOMOUNT_ENABLE
    /* The application's next state */
    APP_DATALOG_STATES nextState;

    /* Timer handler to drive delay function */
    SYS_TIME_HANDLE timer;

    /* Delay time in milliseconds */
    uint32_t delayMs;
#endif

} APP_DATALOG_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_DATALOG_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_DATALOG_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_DATALOG_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_DATALOG_Initialize(void);


/*******************************************************************************
  Function:
    void APP_DATALOG_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_DATALOG_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_DATALOG_Tasks(void);


/*******************************************************************************
  Function:
    APP_DATALOG_STATES APP_DATALOG_GetStatus(void)

  Summary:
    Provides current state of Datalog module.

  Description:
    This routine provides the current state of Datalog module.
    Available states are defined by APP_DATALOG_STATES Enum.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    Datalog module state as defined in APP_DATALOG_STATES Enum.

  Example:
    <code>
    if (APP_DATALOG_GetStatus() == APP_DATALOG_STATE_READY)
      // Store last metrology data
    }
    </code>

  Remarks:
    None.
 */

APP_DATALOG_STATES APP_DATALOG_GetStatus(void);


/*******************************************************************************
  Function:
    bool APP_DATALOG_FileExists(APP_DATALOG_USER userId, APP_DATALOG_DATE *date)

  Summary:
    Checks whether a file exists.

  Description:
    This routine returns whether a file exists in synchronous mode,
    filename is obtained given its parameters.

  Precondition:
    None.

  Parameters:
    userId - ID of module to which file is associated to.
    date - Pointer to Date structure to derive filename from.
           NULL to avoid indexing by date.

  Returns:
    True if file exists. Otherwise False.

  Example:
    <code>
    APP_DATALOG_DATE date;
    date.year = 22;
    date.month = 1;

    if (APP_DATALOG_FileExists(APP_DATALOG_USER_DEMAND, &date))
      // Put element in Datalog queue for file read/write operation
    }
    </code>

  Remarks:
    None.
 */

bool APP_DATALOG_FileExists(APP_DATALOG_USER userId, APP_DATALOG_DATE *date);

/*******************************************************************************
  Function:
    void APP_DATALOG_ClearData(APP_DATALOG_USER userId)

  Summary:
    Clears all stored data for a given user (module).

  Description:
    This routine clears all data for a given user id.
    As users ids have their own directory, it clear all files in it.

  Precondition:
    None.

  Parameters:
    userId - ID of module to clear data.

  Returns:
    None.

  Example:
    <code>
    // Clear all stored energy data
    APP_DATALOG_ClearData(APP_DATALOG_USER_ENERGY)
    </code>

  Remarks:
    None.
 */

void APP_DATALOG_ClearData(APP_DATALOG_USER userId);

/*******************************************************************************
  Function:
    bool APP_DATALOG_SendDatalogData(APP_DATALOG_QUEUE_DATA *datalogData)

  Summary:
    Send new Datalog data to be processed.

  Description:
    This routine inserts the new Datalog data in an internal queue.
    The insertion of the new item in the internal queue is done by copying data.
    All items included in the internal queue are processed by the Datalog task.

  Precondition:
    None.

  Parameters:
    datalogData - Pointer to the data to store in the Datalog Queue.

  Returns:
    None.

  Example:
    <code>
    appEnergyDatalogQueueData.userId = APP_DATALOG_USER_RTC;
    appEnergyDatalogQueueData.operation = APP_DATALOG_READ;
    appEnergyDatalogQueueData.pData = (uint8_t *)&app_energyData.time;
    appEnergyDatalogQueueData.dataLen = sizeof(struct tm);
    appEnergyDatalogQueueData.endCallback = _APP_ENERGY_GetRTCDataLogCallback;
    appEnergyDatalogQueueData.date.month = APP_DATALOG_INVALID_MONTH;
    appEnergyDatalogQueueData.date.year = APP_DATALOG_INVALID_YEAR;

    APP_DATALOG_SendDatalogData(&appEnergyDatalogQueueData);
    </code>

  Remarks:
    None.
 */

bool APP_DATALOG_SendDatalogData(APP_DATALOG_QUEUE_DATA *datalogData);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_DATALOG_H */

/*******************************************************************************
 End of File
 */

