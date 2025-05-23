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
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_events.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <time.h>
#include "definitions.h"
#include "app_datalog.h"
#include "app_events.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

/* Define a queue to signal the Events Task to handle metrology events */
APP_EVENTS_QUEUE CACHE_ALIGN appEventsQueue;

extern APP_DATALOG_QUEUE appDatalogQueue;
APP_DATALOG_QUEUE_DATA CACHE_ALIGN appEventsDatalogQueueData;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_EVENTS_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_EVENTS_DATA CACHE_ALIGN app_eventsData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static void _APP_EVENTS_InitEventsQueue(void)
{
    /* Clear DataLog Queue data */
    memset(&appEventsQueue, 0, sizeof(appEventsQueue));

    /* Init Queue pointers */
    appEventsQueue.dataRd = &appEventsQueue.data[0];
    appEventsQueue.dataWr = appEventsQueue.dataRd;
}

static bool _APP_EVENTS_ReceiveEventsData(APP_EVENTS_QUEUE_DATA *eventsData)
{
    if (appEventsQueue.dataSize)
    {
        /* Copy data to the data pointer */
        memcpy(eventsData, appEventsQueue.dataRd, sizeof(APP_EVENTS_QUEUE_DATA));

        /* Update Queue as a circular buffer */
        appEventsQueue.dataSize--;
        if (appEventsQueue.dataRd == &appEventsQueue.data[APP_EVENTS_QUEUE_DATA_SIZE - 1])
        {
            appEventsQueue.dataRd = &appEventsQueue.data[0];
        }
        else
        {
            appEventsQueue.dataRd++;
        }

        return true;
    }

    return false;
}

void _APP_EVENTS_GetDataLogCallback(APP_DATALOG_RESULT result)
{
    if (result == APP_DATALOG_RESULT_SUCCESS)
    {
        app_eventsData.dataIsRdy = true;
    }

    // Set Data response flag
    app_eventsData.dataResponseFlag = true;
}

static void _APP_EVENTS_LoadEvenstDataFromMemory(void)
{
    appEventsDatalogQueueData.userId = APP_DATALOG_USER_EVENTS;
    appEventsDatalogQueueData.operation = APP_DATALOG_READ;
    appEventsDatalogQueueData.pData = (uint8_t *)&app_eventsData.events;
    appEventsDatalogQueueData.dataLen = sizeof(APP_EVENTS_DATA);
    appEventsDatalogQueueData.endCallback = _APP_EVENTS_GetDataLogCallback;
    appEventsDatalogQueueData.date.month = APP_DATALOG_INVALID_MONTH;
    appEventsDatalogQueueData.date.year = APP_DATALOG_INVALID_YEAR;

    APP_DATALOG_SendDatalogData(&appEventsDatalogQueueData);
}

static void _APP_EVENTS_StoreEventsDataInMemory(void)
{
    appEventsDatalogQueueData.userId = APP_DATALOG_USER_EVENTS;
    appEventsDatalogQueueData.operation = APP_DATALOG_WRITE;
    appEventsDatalogQueueData.pData = (uint8_t *)&app_eventsData.events;
    appEventsDatalogQueueData.dataLen = sizeof(APP_EVENTS_DATA);
    appEventsDatalogQueueData.endCallback = NULL;
    appEventsDatalogQueueData.date.month = APP_DATALOG_INVALID_MONTH;
    appEventsDatalogQueueData.date.year = APP_DATALOG_INVALID_YEAR;

    APP_DATALOG_SendDatalogData(&appEventsDatalogQueueData);
}

#ifdef METROLOGY_ATM90EXX_SUPPORT
static bool _APP_EVENTS_RegisterEvent(APP_EVENTS_EVENT_ID type, bool enabled, struct tm * timeEvent)
{
    bool registered = false;
    APP_EVENTS_EVENT_DATA * eventData;

    eventData = &app_eventsData.events.event[type];

    switch (eventData->status)
    {
        case NO_EVENT:
        {
            APP_EVENTS_EVENT_INFO * eventInfo;

            /* Register Starting Event */
            eventInfo = &eventData->data[eventData->dataIndex];

            if (enabled)
            {
                /* Register Starting Event */
                eventInfo->startTime = *timeEvent;
                memset(&eventInfo->endTime, 0, sizeof(struct tm));
                eventData->status = EVENT_START;
            }
            break;
        }
        case EVENT_START:
        {
            if (enabled == 0)
            {
                APP_EVENTS_EVENT_INFO * eventInfo;

                /* Register Ending Event */
                eventInfo = &eventData->data[eventData->dataIndex];
                eventInfo->endTime = *timeEvent;

                /* Set index to next logged data */
                eventData->dataIndex++;
                eventData->dataIndex %= EVENT_LOG_MAX_NUMBER;

                /* Clear data of the next index */
                eventInfo = &eventData->data[eventData->dataIndex];
                memset(eventInfo, 0, sizeof(APP_EVENTS_EVENT_INFO));

                eventData->counter++;
                eventData->status = NO_EVENT;

                /* Register event is completed */
                registered = true;                
            }
            break;
        }
    }

    return registered;
}
#else
static bool _APP_EVENTS_RegisterEvent(APP_EVENTS_EVENT_ID type, bool enabled, struct tm * timeEvent)
{
    bool registered = false;
    APP_EVENTS_EVENT_DATA * eventData;

    eventData = &app_eventsData.events.event[type];

    switch (eventData->status)
    {
        case NO_EVENT:
        {
            if (enabled)
            {
                /* Start Holding Start time */
                eventData->status = EVENT_HOLDING_START;
                eventData->holdingCounter = EVENT_HOLDING_START_COUNTER;
            }
            break;
        }

        case EVENT_HOLDING_START:
        {
            APP_EVENTS_EVENT_INFO * eventInfo;

            /* Register Starting Event */
            eventInfo = &eventData->data[eventData->dataIndex];

            if (enabled)
            {
                eventData->holdingCounter--;
                if (eventData->holdingCounter == 0)
                {
                    /* Register Starting Event */
                    eventInfo->startTime = *timeEvent;
                    memset(&eventInfo->endTime, 0, sizeof(struct tm));

                    eventData->status = EVENT_START;
                }
            }
            else
            {
                /* Cancel Starting event */
                eventData->status = NO_EVENT;
                /* Clean starting time */
                memset(&eventInfo->startTime, 0, sizeof(struct tm));
            }

            break;
        }

        case EVENT_START:
        {
            if (enabled == 0)
            {
                /* Start Holding End time */
                eventData->status = EVENT_HOLDING_END;
                eventData->holdingCounter = EVENT_HOLDING_END_COUNTER;
            }
            break;
        }

        case EVENT_HOLDING_END:
        {
            if (enabled == 0)
            {
                eventData->holdingCounter--;
                if (eventData->holdingCounter == 0)
                {
                    APP_EVENTS_EVENT_INFO * eventInfo;

                    /* Register Ending Event */
                    eventInfo = &eventData->data[eventData->dataIndex];
                    eventInfo->endTime = *timeEvent;

                    /* Set index to next logged data */
                    eventData->dataIndex++;
                    eventData->dataIndex %= EVENT_LOG_MAX_NUMBER;

                    /* Clear data of the next index */
                    eventInfo = &eventData->data[eventData->dataIndex];
                    memset(eventInfo, 0, sizeof(APP_EVENTS_EVENT_INFO));

                    eventData->counter++;
                    eventData->status = NO_EVENT;

                    /* Register event is completed */
                    registered = true;
                }
            }
            else
            {
                /* Cancel Ending event */
                eventData->status = EVENT_START;
            }

            break;
        }
    }

    return registered;
}
#endif
static bool _APP_EVENTS_UpdateEvents(APP_EVENTS_QUEUE_DATA * newEvent)
{
    bool update = false;

    if (_APP_EVENTS_RegisterEvent(SAG_UA_EVENT_ID, newEvent->eventFlags.BIT.sagA, &newEvent->eventTime))
    {
        update = true;
    }

    if (_APP_EVENTS_RegisterEvent(SAG_UB_EVENT_ID, newEvent->eventFlags.BIT.sagB, &newEvent->eventTime))
    {
        update = true;
    }

    if (_APP_EVENTS_RegisterEvent(SAG_UC_EVENT_ID, newEvent->eventFlags.BIT.sagC, &newEvent->eventTime))
    {
        update = true;
    }

    if (_APP_EVENTS_RegisterEvent(POW_UA_EVENT_ID, newEvent->eventFlags.BIT.paDir, &newEvent->eventTime))
    {
        update = true;
    }

    if (_APP_EVENTS_RegisterEvent(POW_UB_EVENT_ID, newEvent->eventFlags.BIT.pbDir, &newEvent->eventTime))
    {
        update = true;
    }

    if (_APP_EVENTS_RegisterEvent(POW_UC_EVENT_ID, newEvent->eventFlags.BIT.pcDir, &newEvent->eventTime))
    {
        update = true;
    }

    /* Update Event Flags */
    app_eventsData.flags.events = newEvent->eventFlags.events;

    return update;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_EVENTS_Initialize ( void )

  Remarks:
    See prototype in app_events.h.
 */

void APP_EVENTS_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_eventsData.state = APP_EVENTS_STATE_WAITING_DATALOG;

    /* Initialize Events data */
    memset(&app_eventsData.events, 0, sizeof(APP_EVENTS_EVENTS));

    /* Initialize data response Flag */
    app_eventsData.dataResponseFlag = false;

    /* Init Queue data */
    _APP_EVENTS_InitEventsQueue();
}


/******************************************************************************
  Function:
    void APP_EVENTS_Tasks ( void )

  Remarks:
    See prototype in app_events.h.
 */

void APP_EVENTS_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( app_eventsData.state )
    {
        case APP_EVENTS_STATE_WAITING_DATALOG:
        {
            if (APP_DATALOG_GetStatus() == APP_DATALOG_STATE_READY)
            {
                app_eventsData.state = APP_EVENTS_STATE_INIT;
            }

            break;
        }

        case APP_EVENTS_STATE_INIT:
        {
            /* Reset flag to request data to datalog app */
            app_eventsData.dataIsRdy = false;

            /* Check if there are EVENTS data in memory */
            if (APP_DATALOG_FileExists(APP_DATALOG_USER_EVENTS, NULL))
            {
                /* EVENTS data exists */
                _APP_EVENTS_LoadEvenstDataFromMemory();

                app_eventsData.state = APP_EVENTS_STATE_WAIT_DATA;
            }
            else
            {
                /* There is no valid data in memory. Create Events Data in memory. */
                _APP_EVENTS_StoreEventsDataInMemory();

                app_eventsData.state = APP_EVENTS_STATE_RUNNING;
            }

            break;
        }

        case APP_EVENTS_STATE_WAIT_DATA:
        {
            if (app_eventsData.dataResponseFlag)
            {
                app_eventsData.dataResponseFlag = false;
                app_eventsData.state = APP_EVENTS_STATE_RUNNING;
            }

            break;
        }

        case APP_EVENTS_STATE_RUNNING:
        {
            if (_APP_EVENTS_ReceiveEventsData(&app_eventsData.newEvent))
            {
                if (_APP_EVENTS_UpdateEvents(&app_eventsData.newEvent))
                {
                    _APP_EVENTS_StoreEventsDataInMemory();
                }
            }

            break;
        }

        /* The default state should never be executed. */
        case APP_EVENTS_STATE_ERROR:
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

void APP_EVENTS_ClearEvents(void)
{
    /* Erase all the event records stored in non volatile memory */
    APP_DATALOG_ClearData(APP_DATALOG_USER_EVENTS);

    /* Clear all events data */
    memset(&app_eventsData.events, 0, sizeof(APP_EVENTS_EVENTS));
}

bool APP_EVENTS_GetNumEvents(APP_EVENTS_EVENT_ID eventId, uint8_t * counter)
{
    if (eventId >= EVENTS_NUM_ID)
    {
        return false;
    }

    *counter = app_eventsData.events.event[eventId].counter;

    return true;
}

bool APP_EVENTS_GetEventInfo(APP_EVENTS_EVENT_ID eventId, uint8_t offset, APP_EVENTS_EVENT_INFO *eventInfo)
{
    APP_EVENTS_EVENT_DATA *pEvent;
    uint8_t index;

    if (eventId >= EVENTS_NUM_ID)
    {
        return false;
    }

    if (offset >= EVENT_LOG_MAX_NUMBER)
    {
        return false;
    }

    pEvent = &app_eventsData.events.event[eventId];

    // Get index from the last event offset
    index = pEvent->dataIndex - offset;
    if (offset > pEvent->dataIndex)
    {
        index += EVENT_LOG_MAX_NUMBER;
    }

    *eventInfo = pEvent->data[index];

    return true;
}

void APP_EVENTS_GetLastEventFlags(METROLOGY_API_EVENTS *eventFlags)
{
    if (eventFlags)
    {
        *eventFlags = app_eventsData.flags;
    }
}

bool APP_EVENTS_SendEventsData(APP_EVENTS_QUEUE_DATA *eventsData)
{
    if (appEventsQueue.dataSize < APP_EVENTS_QUEUE_DATA_SIZE)
    {
        /* Copy Energy data to the data queue */
        memcpy(appEventsQueue.dataWr, eventsData, sizeof(APP_EVENTS_QUEUE_DATA));

        /* Update Queue as a circular buffer */
        appEventsQueue.dataSize++;
        if (appEventsQueue.dataWr == &appEventsQueue.data[APP_EVENTS_QUEUE_DATA_SIZE - 1])
        {
            appEventsQueue.dataWr = &appEventsQueue.data[0];
        }
        else
        {
            appEventsQueue.dataWr++;
        }

        return true;
    }

    return false;
}

/*******************************************************************************
 End of File
 */
