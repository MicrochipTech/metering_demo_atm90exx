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
    app_display.c

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
#include "time.h"
#include "app_display.h"
#include "app_energy.h"
#include "definitions.h"
#include "user.h"

#ifdef OLED1_XPLAINED_PRO_SUPPORT
#include "oled1_display.h"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Macro Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_DISPLAY_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DISPLAY_DATA CACHE_ALIGN app_displayData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
static void _APP_DISPLAY_ScrollUp_Callback ( uintptr_t context)
{
    app_displayData.scrup_pressed = true;
}

static void _APP_DISPLAY_ScrollDown_Callback ( uintptr_t context)
{
    app_displayData.scrdown_pressed = true;
}

static void _APP_DISPLAY_Timer_Callback ( uintptr_t context)
{
    if (--app_displayData.display_time == 0)
    {
        app_displayData.timerFlag = true;
        app_displayData.display_time = app_displayData.reload_display_time;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    Init LCD module.
 */

static status_code_t APP_DISPLAY_InitLCD(void)
{
    /* Initialize the OLED1 Xplained PRO LCD */
#ifdef OLED1_XPLAINED_PRO_SUPPORT
    gfx_mono_init();
#else
    status_code_t status;
    
    status = cl010_init();    
    if (status != STATUS_OK)
    {
        return STATUS_ERR_BUSY;
    }
#endif
    
    /* Show all symbols */
#ifdef OLED1_XPLAINED_PRO_SUPPORT
    //TBD
#else
    cl010_show_all();
#endif    
    return STATUS_OK;
}

/*******************************************************************************
  Function:
    Update the status of the external communication signal.
 */
static void _APP_DISPLAY_UpdateComSignal (APP_DISPLAY_COM_SIGNAL signal)
{
#ifdef OLED1_XPLAINED_PRO_SUPPORT
#else
    if (signal == APP_DISPLAY_COM_SIGNAL_OFF)
    {
        cl010_clear_icon(CL010_ICON_COMM_SIGNAL_LOW);
        cl010_clear_icon(CL010_ICON_COMM_SIGNAL_MED);
        cl010_clear_icon(CL010_ICON_COMM_SIGNAL_HIG);
    }
    else
    {
        if (signal >= APP_DISPLAY_COM_SIGNAL_LOW)
        {
            cl010_show_icon(CL010_ICON_COMM_SIGNAL_LOW);
        }

        if (signal >= APP_DISPLAY_COM_SIGNAL_MED)
        {
            cl010_show_icon(CL010_ICON_COMM_SIGNAL_MED);
        }

        if (signal == APP_DISPLAY_COM_SIGNAL_HIG)
        {
            cl010_show_icon(CL010_ICON_COMM_SIGNAL_HIG);

        }
    }
#endif
}

/*******************************************************************************
  Function:
    Timer in milliseconds for creating and waiting the delay.
 */

static bool APP_DISPLAY_TaskDelay(uint32_t ms, SYS_TIME_HANDLE* handle)
{
    // Check if there is the timer has been created and running
    if (*handle == SYS_TIME_HANDLE_INVALID)
    {
        // Create timer
        if (SYS_TIME_DelayMS(ms, handle) != SYS_TIME_SUCCESS)
        {
            return false;
        }
    }
    else
    {
        // Check timer
        if (SYS_TIME_DelayIsComplete(*handle) == true)
        {
            *handle = SYS_TIME_HANDLE_INVALID;
            return true;
        }
    }

    return false;
}

/*******************************************************************************
  Function:
    Timer in seconds for changing the info in loop mode.
 */

static void APP_DISPLAY_SetTimerLoop(uint32_t time_sec)
{
    if (time_sec)
    {
        /* Set the new time for loop mode */
        app_displayData.display_time = time_sec;
        app_displayData.reload_display_time = time_sec;

        /* Check timer to cancel it */
        if (app_displayData.timer != SYS_TIME_HANDLE_INVALID)
        {
            /* Cancel Timer */
            SYS_TIME_TimerDestroy(app_displayData.timer);

            /* Clear timer flag */
            app_displayData.timerFlag = false;
        }

        /* Create Task Timer */
        app_displayData.timer = SYS_TIME_CallbackRegisterMS(_APP_DISPLAY_Timer_Callback, 0,
                1000, SYS_TIME_PERIODIC);

    }
}

/*******************************************************************************
  Function:
    Add display info to the display loop.
 */

static void APP_DISPLAY_AddLoopInfo(APP_DISPLAY_INFO info)
{
    if ((info < APP_DISPLAY_MAX_TYPE) && (app_displayData.loop_max < APP_DISPLAY_MAX_TYPE))
    {
        /* Add info to display */
        app_displayData.loop_info[app_displayData.loop_max++] = info;
    }
}

/*******************************************************************************
  Function:
    Change the information in the display.
 */

static void APP_DISPLAY_ChangeInfo(void)
{
    if (app_displayData.loop_max <= APP_DISPLAY_MAX_TYPE)
    {
        if ((app_displayData.direction & APP_DISPLAY_FORWARD) == APP_DISPLAY_FORWARD)
        {
            if (++app_displayData.loop_idx >= app_displayData.loop_max)
            {
                app_displayData.loop_idx = 0;
            }
        }
        else if ((app_displayData.direction & APP_DISPLAY_BACKWARD) == APP_DISPLAY_BACKWARD)
        {
            if (--app_displayData.loop_idx >= app_displayData.loop_max)
            {
                app_displayData.loop_idx = app_displayData.loop_max - 1;
            }
        }

        app_displayData.display_info = app_displayData.loop_info[app_displayData.loop_idx];
    }
}

/*******************************************************************************
  Function:
    Show Energy data and units depending on its value
 */

static void APP_DISPLAY_ShowEnergyDataUnits(uint64_t value)
{
    uint8_t buff1[9];

    /* Check magnitude to select units to show */
    if (value > 999999999) {
        /* Format: xxxxxx.xx kWh */
        value = value/100000;
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        oled1_show_units(OLED1_UNIT_kWh);
        snprintf((char *)buff1,  (volatile size_t){sizeof(buff1)}, "%5u.%02u", (unsigned int)(value/100),
                 (unsigned int)(value%100));
#else
        cl010_show_units(CL010_UNIT_kWh);
        sprintf((char *)buff1, "%6u%02u", (unsigned int)(value/100),
                 (unsigned int)(value%100));
        cl010_show_icon(CL010_ICON_DOT_2);
#endif
    }
    else
    {
        /* Format: xxxxx.xxx Wh */
        value = value/10;
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        oled1_show_units(OLED1_UNIT_Wh);
        snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%5u.%02u", (unsigned int)(value/1000),
                 (unsigned int)(value%1000));     
#else
        cl010_show_units(CL010_UNIT_Wh);
        sprintf((char *)buff1, "%5u%03u", (unsigned int)(value/1000),
                 (unsigned int)(value%1000));
        cl010_show_icon(CL010_ICON_DOT_1);
#endif
    }

#ifdef OLED1_XPLAINED_PRO_SUPPORT
    oled1_show_numeric_string((char *)buff1);
#else    
    cl010_show_numeric_string(CL010_LINE_UP, buff1);
#endif
}

/*******************************************************************************
  Function:
    Process information for the display.
 */

static void APP_DISPLAY_Process(void)
{
    uint64_t total;
    uint64_t upd_symbols = 1;
    uint32_t rmsValue;
    uint8_t buff1[9];
    uint8_t idx;
    struct tm current_time;
    APP_ENERGY_ACCUMULATORS EnergyAcc;
    APP_ENERGY_MAX_DEMAND MaxDemand;

    if (app_displayData.display_info != 0xFF)
    {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        oled1_clear_all(); 
#else
        cl010_clear_all();
#endif
    }

    /* Init internal buffer */
    memset(buff1, '\0', (volatile size_t){sizeof(buff1)});
    memset (&EnergyAcc, 0, sizeof(APP_ENERGY_ACCUMULATORS));
    memset (&MaxDemand, 0, sizeof(APP_ENERGY_MAX_DEMAND));

    switch (app_displayData.display_info)
    {
        case APP_DISPLAY_TOTAL_ENERGY:
        {
            APP_ENERGY_GetCurrentEnergy(&EnergyAcc);
            total = 0;
            for (idx = 0; idx < TARIFF_NUM_TYPE; idx++)
            {
                total += EnergyAcc.tariff[idx];
            }
            APP_DISPLAY_ShowEnergyDataUnits(total);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_1234_CUM);     
#else
            cl010_show_icon(CL010_ICON_CUM);
            sprintf((char *)buff1, "   1234");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU1_ENERGY:
        {
            //APP_ENERGY_GetCurrentEnergy(&EnergyAcc);
            total = EnergyAcc.tariff[0];
            APP_DISPLAY_ShowEnergyDataUnits(total);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_1_CUM); 
#else
            cl010_show_icon(CL010_ICON_CUM);
            sprintf((char *)buff1, "      1");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU2_ENERGY:
        {
            APP_ENERGY_GetCurrentEnergy(&EnergyAcc);
            total = EnergyAcc.tariff[1];
            APP_DISPLAY_ShowEnergyDataUnits(total);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_2_CUM); 
#else
            cl010_show_icon(CL010_ICON_CUM);
            sprintf((char *)buff1, "      2");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU3_ENERGY:
        {
            APP_ENERGY_GetCurrentEnergy(&EnergyAcc);
            total = EnergyAcc.tariff[2];
            APP_DISPLAY_ShowEnergyDataUnits(total);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_3_CUM); 
#else
            cl010_show_icon(CL010_ICON_CUM);
            sprintf((char *)buff1, "      3");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU4_ENERGY:
        {
            APP_ENERGY_GetCurrentEnergy(&EnergyAcc);
            total = EnergyAcc.tariff[3];
            APP_DISPLAY_ShowEnergyDataUnits(total);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_4_CUM); 
#else
            cl010_show_icon(CL010_ICON_CUM);
            sprintf((char *)buff1, "      4");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_VA_RMS:
        {
            METROLOGY_API_get_Vrms(METROLOGY_VLINE_UA, &rmsValue, 0);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%4u.%03u",
                    (unsigned int)(rmsValue/ATM90EXX_V_ACCURACY_INT),
                    (unsigned int)((rmsValue%ATM90EXX_V_ACCURACY_INT)/10));
            oled1_show_icon_string(OLED1_STRING_VA); 
            oled1_show_units(OLED1_UNIT_Vrms);
            oled1_show_numeric_string((char *)buff1);
#else
            sprintf((char *)buff1, "%5u%03u",
                    (unsigned int)(rmsValue/10000),
                    (unsigned int)((rmsValue%10000)/10));
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_V);
            cl010_show_icon(CL010_ICON_DOT_1);
            cl010_show_icon(CL010_ICON_L1);
#endif
            break;
        }

        case APP_DISPLAY_VB_RMS:
        {
            METROLOGY_API_get_Vrms(METROLOGY_VLINE_UB, &rmsValue, 0);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%4u.%03u",
                    (unsigned int)(rmsValue/ATM90EXX_V_ACCURACY_INT),
                    (unsigned int)((rmsValue%ATM90EXX_V_ACCURACY_INT)/10));
            oled1_show_icon_string(OLED1_STRING_VB); 
            oled1_show_units(OLED1_UNIT_Vrms);
            oled1_show_numeric_string((char *)buff1);
#else
            sprintf((char *)buff1, "%5u%03u",
                    (unsigned int)(rmsValue/10000),
                    (unsigned int)((rmsValue%10000)/10));
        
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_V);
            cl010_show_icon(CL010_ICON_DOT_1);
            cl010_show_icon(CL010_ICON_L2);
#endif
            break;
        }

        case APP_DISPLAY_VC_RMS:
        {
            METROLOGY_API_get_Vrms(METROLOGY_VLINE_UC, &rmsValue, 0);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%4u.%03u",
                    (unsigned int)(rmsValue/ATM90EXX_V_ACCURACY_INT),
                    (unsigned int)((rmsValue%ATM90EXX_V_ACCURACY_INT)/10));
            oled1_show_icon_string(OLED1_STRING_VC); 
            oled1_show_units(OLED1_UNIT_Vrms);
            oled1_show_numeric_string((char *)buff1);
#else
            sprintf((char *)buff1, "%5u%03u",
                    (unsigned int)(rmsValue/10000),
                    (unsigned int)((rmsValue%10000)/10));
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_V);
            cl010_show_icon(CL010_ICON_DOT_1);
            cl010_show_icon(CL010_ICON_L3);
#endif
            break;
        }

        case APP_DISPLAY_IA_RMS:
        {
            METROLOGY_API_get_Irms(METROLOGY_CLINE_IA, &rmsValue, 0);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%4u.%03u",
                    (unsigned int)(rmsValue/ATM90EXX_I_ACCURACY_INT),
                    (unsigned int)((rmsValue%ATM90EXX_I_ACCURACY_INT)/10));
            oled1_show_icon_string(OLED1_STRING_IA); 
            oled1_show_units(OLED1_UNIT_Arms);
            oled1_show_numeric_string((char *)buff1);        
#else
            sprintf((char *)buff1, "%5u%03u",
                    (unsigned int)(rmsValue/10000),
                    (unsigned int)((rmsValue%10000)/10));
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_A);
            cl010_show_icon(CL010_ICON_DOT_1);
            cl010_show_icon(CL010_ICON_L1);
#endif
            break;
        }

        case APP_DISPLAY_IB_RMS:
        {
            METROLOGY_API_get_Irms(METROLOGY_CLINE_IB, &rmsValue, 0);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%4u.%03u",
                    (unsigned int)(rmsValue/ATM90EXX_I_ACCURACY_INT),
                    (unsigned int)((rmsValue%ATM90EXX_I_ACCURACY_INT)/10));
            oled1_show_icon_string(OLED1_STRING_IB); 
            oled1_show_units(OLED1_UNIT_Arms);
            oled1_show_numeric_string((char *)buff1);        
#else
            sprintf((char *)buff1, "%5u%03u",
                    (unsigned int)(rmsValue/10000),
                    (unsigned int)((rmsValue%10000)/10));
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_A);
            cl010_show_icon(CL010_ICON_DOT_1);
            cl010_show_icon(CL010_ICON_L2);
#endif
            break;
        }

        case APP_DISPLAY_IC_RMS:
        {
            METROLOGY_API_get_Irms(METROLOGY_CLINE_IC, &rmsValue, 0);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%4u.%03u",
                    (unsigned int)(rmsValue/ATM90EXX_I_ACCURACY_INT),
                    (unsigned int)((rmsValue%ATM90EXX_I_ACCURACY_INT)/10));
            oled1_show_icon_string(OLED1_STRING_IC); 
            oled1_show_units(OLED1_UNIT_Arms);
            oled1_show_numeric_string((char *)buff1);        
#else
            sprintf((char *)buff1, "%5u%03u",
                    (unsigned int)(rmsValue/10000),
                    (unsigned int)((rmsValue%10000)/10));
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_A);
            cl010_show_icon(CL010_ICON_DOT_1);
            cl010_show_icon(CL010_ICON_L3);
#endif
            break;
        }

        case APP_DISPLAY_RTC_TIME:
        {
            RTC_TimeGet(&current_time);
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%02d:%02d:%02d",
                    (uint8_t)current_time.tm_hour,
                    (uint8_t)current_time.tm_min,
                    (uint8_t)current_time.tm_sec);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TIME); 
            oled1_show_units(OLED1_EMPTY_UNIT);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_icon(CL010_ICON_TIME);
            cl010_show_icon(CL010_ICON_COL_1);
            cl010_show_icon(CL010_ICON_COL_2);
#endif
            upd_symbols = 0;
            break;
        }

        case APP_DISPLAY_RTC_DATE:
        {
            RTC_TimeGet(&current_time);
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%02d-%02d-%02d",
                    (uint8_t)(current_time.tm_year - 100),
                    (uint8_t)(current_time.tm_mon + 1),
                    (uint8_t)(current_time.tm_mday));
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_DATE); 
            oled1_show_units(OLED1_EMPTY_UNIT); 
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_icon(CL010_ICON_DATE);
            cl010_show_icon(CL010_ICON_COL_1);
            cl010_show_icon(CL010_ICON_COL_2);
#endif
            upd_symbols = 0;
            break;
        }

        case APP_DISPLAY_TOTAL_MAX_DEMAND:
        {
            APP_ENERGY_GetCurrentMaxDemand(&MaxDemand);
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%8u", (unsigned int)MaxDemand.maxDemad.value);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_1234_MD); 
            oled1_show_units(OLED1_UNIT_W);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_W);
            cl010_show_icon(CL010_ICON_MD);
            sprintf((char *)buff1, "   1234");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU1_MAX_DEMAND:
        {
            //APP_ENERGY_GetCurrentMaxDemand(&MaxDemand);
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%8u", (unsigned int)MaxDemand.tariff[0].value);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_1_MD); 
            oled1_show_units(OLED1_UNIT_W);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_W);
            cl010_show_icon(CL010_ICON_MD);
            sprintf((char *)buff1, "     01");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU2_MAX_DEMAND:
        {
            APP_ENERGY_GetCurrentMaxDemand(&MaxDemand);
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%8u", (unsigned int)MaxDemand.tariff[1].value);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_2_MD); 
            oled1_show_units(OLED1_UNIT_W);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_W);
            cl010_show_icon(CL010_ICON_MD);
            sprintf((char *)buff1, "     02");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU3_MAX_DEMAND:
        {
            APP_ENERGY_GetCurrentMaxDemand(&MaxDemand);
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%8u", (unsigned int)MaxDemand.tariff[2].value);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_3_MD); 
            oled1_show_units(OLED1_UNIT_W);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_W);
            cl010_show_icon(CL010_ICON_MD);
            sprintf((char *)buff1, "     03");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_TOU4_MAX_DEMAND:
        {
            APP_ENERGY_GetCurrentMaxDemand(&MaxDemand);
            snprintf((char *)buff1, (volatile size_t){sizeof(buff1)}, "%8u", (unsigned int)MaxDemand.tariff[3].value);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_TOU_4_MD); 
            oled1_show_units(OLED1_UNIT_W);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
            cl010_show_units(CL010_UNIT_W);
            cl010_show_icon(CL010_ICON_MD);
            sprintf((char *)buff1, "     04");
            cl010_show_numeric_string(CL010_LINE_DOWN, buff1);
#endif
            break;
        }

        case APP_DISPLAY_APP_INFO:
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_APP_INFO); 
            oled1_show_units(OLED1_EMPTY_UNIT);
            oled1_show_numeric_string((char *)app_displayData.app_info);
#else
            cl010_show_numeric_string(CL010_LINE_UP, app_displayData.app_info);
#endif
            upd_symbols = 0;

            break;
        }

        case APP_DISPLAY_BOARD_ID:
        {
            sprintf((char *)buff1, "0x%06X", APP_DISPLAY_BOARD_VERSION);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_BOARD_INFO); 
            oled1_show_units(OLED1_EMPTY_UNIT);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
#endif
            upd_symbols = 0;

            break;
        }

        case APP_DISPLAY_DEMO_VERSION:
        {
            sprintf((char *)buff1, "0x%06X", DEMO_APP_VERSION);
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            oled1_show_icon_string(OLED1_STRING_APP_VERSION); 
            oled1_show_units(OLED1_EMPTY_UNIT);
            oled1_show_numeric_string((char *)buff1);
#else
            cl010_show_numeric_string(CL010_LINE_UP, buff1);
#endif
            upd_symbols = 0;

            break;
        }

        default:
            break;
    }

    if (upd_symbols)
    {
        METROLOGY_API_EVENTS eventFlags;
        APP_EVENTS_GetLastEventFlags(&eventFlags);

        if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_VLINE_UA) && (eventFlags.BIT.sagA))
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
            /* "A alarm" phase */
#else
            /* "A alarm" phase */
            cl010_show_icon(CL010_ICON_PHASE_1);
#endif
        }

        if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_VLINE_UB) && (eventFlags.BIT.sagB))
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        
#else
            /* "A alarm" phase */
            cl010_show_icon(CL010_ICON_PHASE_2);
#endif
        }

        if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_VLINE_UC) && (eventFlags.BIT.sagC))
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        
#else
            /* "A alarm" phase */
            cl010_show_icon(CL010_ICON_PHASE_3);
#endif
        }

        if (eventFlags.BIT.ptDir)
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        
#else
            /* active power is reverse */
            cl010_show_icon(CL010_ICON_P_MINUS);
#endif
        }
        else
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        
#else
            /* active power is forward */
            cl010_show_icon(CL010_ICON_P_PLUS);
#endif
        }

        if (eventFlags.BIT.qtDir)
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        
#else
            /* reactive power is reverse */
            cl010_show_icon(CL010_ICON_Q_MINUS);
#endif
        }
        else
        {
#ifdef OLED1_XPLAINED_PRO_SUPPORT
        
#else
            /* reactive power is forward */
            cl010_show_icon(CL010_ICON_Q_PLUS);
#endif
        }

    }

#ifdef OLED1_XPLAINED_PRO_SUPPORT
        
#else
    /* Display MCHP logo */
    cl010_show_icon(CL010_ICON_MICROCHIP);
#endif

    /* Update External Communication signal status */
    if (app_displayData.comm_signal > APP_DISPLAY_COM_SIGNAL_OFF)
    {
        _APP_DISPLAY_UpdateComSignal(app_displayData.comm_signal);
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_DISPLAY_Initialize ( void )

  Remarks:
    See prototype in app_display.h.
 */

void APP_DISPLAY_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_displayData.state = APP_DISPLAY_STATE_INIT_DISPLAY;
 
#ifdef OLED1_XPLAINED_PRO_SUPPORT    
    /* Reset the SSD1306 and disable the "ssd1306_hard_reset()" call */
    OLED_DISP_RESET_Clear();
#endif

    /* Init Display Timer */
    app_displayData.timer = SYS_TIME_HANDLE_INVALID;

    /* No buttons pressed */
    app_displayData.scrdown_pressed = false;
    app_displayData.scrup_pressed = false;

    /* Set startup display information */
    app_displayData.loop_max = 0;
    app_displayData.loop_idx = 0;

    /* Clear flag to disable application message */
    app_displayData.app_info_en = false;
    memset(app_displayData.app_info, '\0', 8);

    /* Set display loop direction by default */
    app_displayData.direction = APP_DISPLAY_FORWARD;

    /* Init display info */
    app_displayData.display_info = (APP_DISPLAY_INFO)0xFF;

    /* Disable external communication signal */
    app_displayData.comm_signal = APP_DISPLAY_COM_SIGNAL_OFF;

    /* Configure Switches */
#ifdef OLED1_XPLAINED_PRO_SUPPORT    
    EIC_CallbackRegister(SWITCH_SCRUP_EIC_PIN,
            _APP_DISPLAY_ScrollUp_Callback, (uintptr_t)NULL);
    EIC_CallbackRegister(SWITCH_SCRDOWN_EIC_PIN,
            _APP_DISPLAY_ScrollDown_Callback, (uintptr_t)NULL);
#else            
    PIO_PinInterruptCallbackRegister(SWITCH_SCRUP_PIN,
            _APP_DISPLAY_ScrollUp_Callback, (uintptr_t)NULL);

    PIO_PinInterruptCallbackRegister(SWITCH_SCRDOWN_PIN,
            _APP_DISPLAY_ScrollDown_Callback, (uintptr_t)NULL);
#endif
    /* Reload WDT at startup */
    WDT_Clear();
    app_displayData.reloadWDT = true;
}

/******************************************************************************
  Function:
    void APP_DISPLAY_Tasks ( void )

  Remarks:
    See prototype in app_display.h.
 */

void APP_DISPLAY_Tasks ( void )
{
    if (app_displayData.reloadWDT)
    {
        WDT_Clear();
    }

    switch ( app_displayData.state )
    {
        case APP_DISPLAY_STATE_INIT_DISPLAY:
        {
            /* Init LCD */
            APP_DISPLAY_InitLCD();
            app_displayData.state = APP_DISPLAY_STATE_INIT;
            break;
        }
           
        case APP_DISPLAY_STATE_INIT:
        {
            
            if (METROLOGY_DRV_GetStatus() == METROLOGY_DRV_STATUS_RUNNING)
            {
                
                /* Configure display measurements */
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_BOARD_ID);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_DEMO_VERSION);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOTAL_ENERGY);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU1_ENERGY);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU2_ENERGY);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU3_ENERGY);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU4_ENERGY);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_RTC_TIME);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_RTC_DATE);

                if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_VLINE_UA))
                {
                    APP_DISPLAY_AddLoopInfo(APP_DISPLAY_VA_RMS);
                }

                if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_VLINE_UB))
                {
                    APP_DISPLAY_AddLoopInfo(APP_DISPLAY_VB_RMS);
                }

                if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_VLINE_UC))
                {
                    APP_DISPLAY_AddLoopInfo(APP_DISPLAY_VC_RMS);
                }

                if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_CLINE_IA))
                {
                    APP_DISPLAY_AddLoopInfo(APP_DISPLAY_IA_RMS);
                }

                if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_CLINE_IB))
                {
                    APP_DISPLAY_AddLoopInfo(APP_DISPLAY_IB_RMS);
                }

                if (METROLOGY_API_CheckPhaseEnabled(METROLOGY_CLINE_IC))
                {
                    APP_DISPLAY_AddLoopInfo(APP_DISPLAY_IC_RMS);
                }

                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOTAL_MAX_DEMAND);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU1_MAX_DEMAND);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU2_MAX_DEMAND);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU3_MAX_DEMAND);
                APP_DISPLAY_AddLoopInfo(APP_DISPLAY_TOU4_MAX_DEMAND);

                /* Enable Switches interrupts */
#ifdef OLED1_XPLAINED_PRO_SUPPORT    
                EIC_InterruptEnable(SWITCH_SCRUP_EIC_PIN);
                EIC_InterruptEnable(SWITCH_SCRDOWN_EIC_PIN);
#else
                PIO_PinInterruptEnable(SWITCH_SCRUP_PIN);
                PIO_PinInterruptEnable(SWITCH_SCRDOWN_PIN);
#endif

                /* Configure display timer loop */
                APP_DISPLAY_SetTimerLoop(3);

                app_displayData.state = APP_DISPLAY_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_DISPLAY_STATE_SERVICE_TASKS:
        {
                bool updateDisplay = false;

                /* If any button has been pressed, change the information */
                if (app_displayData.scrdown_pressed)
                {
                    if (SWITCH_SCRUP_Get() == 0)
                    {
                        SYS_CMD_MESSAGE("Entering Low Power... Press FWUP/TAMPER switch to wake up.\r\n");

                        // Update display info
                        APP_DISPLAY_ShowLowPowerMode();

                        // Wait time to show message through the Console
                        app_displayData.state = APP_DISPLAY_STATE_DELAY_LOW_POWER;
                        break;
                    }

                    app_displayData.scrdown_pressed = false;
                    app_displayData.direction = APP_DISPLAY_BACKWARD;

                    updateDisplay = true;
                }

                if (app_displayData.scrup_pressed)
                {
                    if (SWITCH_SCRDOWN_Get() == 0)
                    {
                        SYS_CMD_MESSAGE("Emulating application holds ... Resetting by WDT.\r\n");

                        // Forcing no reload WDT
                        app_displayData.reloadWDT = false;
                    }

                    app_displayData.scrup_pressed = false;
                    app_displayData.direction = APP_DISPLAY_FORWARD;

                    updateDisplay = true;
                }

                if (updateDisplay)
                {
                    /* Update display because any switch has been pressed */
                    APP_DISPLAY_ChangeInfo();
                    APP_DISPLAY_Process();

                    /* Reload time */
                    APP_DISPLAY_SetTimerLoop(app_displayData.reload_display_time);
                }

                if (app_displayData.timerFlag)
                {
                    app_displayData.timerFlag = false;

                    APP_DISPLAY_ChangeInfo();
                    APP_DISPLAY_Process();

                    /* Reload time */
                    app_displayData.display_time = app_displayData.reload_display_time;
                }

                /* Show information in display */
                if (app_displayData.timerFlag)
                {
                    app_displayData.timerFlag = false;

                    APP_DISPLAY_ChangeInfo();
                    APP_DISPLAY_Process();
                }

            break;
        }
        case APP_DISPLAY_STATE_DELAY_LOW_POWER:
        {
            // Wait time to show message through the Console
            if (APP_DISPLAY_TaskDelay(100, &app_displayData.timer))
            {
                // Go to Low Power mode
                APP_METROLOGY_SetLowPowerMode();

                // Execution should not come here during normal operation
            }
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

/******************************************************************************
  Function:
    void APP_DISPLAY_SetAppInfo(const char *msg, uint8_t len)

  Remarks:
    See prototype in app_display.h.
 */

void APP_DISPLAY_SetAppInfo(const char *msg, uint8_t len)
{
    if (len > sizeof(app_displayData.app_info))
    {
        len = sizeof(app_displayData.app_info);
    }

    memcpy(app_displayData.app_info, msg, len);

    if (!app_displayData.app_info_en)
    {
        /* Set enable flag */
        app_displayData.app_info_en = true;
        /* Add APP display info */
        APP_DISPLAY_AddLoopInfo(APP_DISPLAY_APP_INFO);
    }

    /* Change display information and reload time */
    app_displayData.display_time = app_displayData.reload_display_time;
    app_displayData.display_info = APP_DISPLAY_APP_INFO;
}

/******************************************************************************
  Function:
    void APP_DISPLAY_SetSerialCommIcon(void)

  Remarks:
    See prototype in app_display.h.
 */

void APP_DISPLAY_SetSerialCommunication(void)
{
#ifdef OLED1_XPLAINED_PRO_SUPPORT
    EXT2_LED1_OLED1_XPRO_Toggle();
#else
    cl010_show_icon(CL010_ICON_ARROW_LEFT);
#endif    
}

/******************************************************************************
  Function:
    void APP_DISPLAY_SetCommnicationSignal(APP_DISPLAY_COM_SIGNAL signal)

  Remarks:
    See prototype in app_display.h.
 */

void APP_DISPLAY_SetCommnicationSignal(APP_DISPLAY_COM_SIGNAL signal)
{
    app_displayData.comm_signal = signal;
    _APP_DISPLAY_UpdateComSignal(signal);
}

/******************************************************************************
  Function:
    void APP_DISPLAY_ShowLowPowerMode(void)

  Remarks:
    See prototype in app_display.h.
 */

void APP_DISPLAY_ShowLowPowerMode(void)
{
#ifdef OLED1_XPLAINED_PRO_SUPPORT
    oled1_display_off();
#else
    cl010_clear_all();
    cl010_show_icon(CL010_ICON_BATTERY_LOW);
#endif
}

/*******************************************************************************
 End of File
 */
