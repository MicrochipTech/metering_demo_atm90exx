
/*
           -----------------------------------------------
LINEUP    | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|
            -----------------------------------------------
LINEDOWN  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|
           -----------------------------------------------

STRING: LINEUP0-9, 10 EMPTY
VALUE:  LINEDOWN0-9, 10 EMPTY
FLAGS:  LINEUP11-15
UNITS:  LINEDOWN11-15 

*/

#include "definitions.h"
#include "oled1_display.h"

static const char * oled1_string_str[OLED1_STRING_NUM] = {
	"VA      ", "VB      ", "VC      ", \
    "IA      ", "IB      ", "IC      ", "IN      ", \
    "PA V-I A", "PA V-I B", "PA V-I C", \
    "PA VA-VA", "PA VA-VB", "PA VA-VC", \
    "PMEANA  ", "PMEANB  ", "PMEANC  ", "PMEANT  ", \
    "QMEANA  ", "QMEANB  ", "QMEANC  ", "QMEANT  ", \
    "SMEANA  ", "SMEANB  ", "SMEANC  ", "SMEANT  ", \
    "PMEANAF ", "PMEANBF ", "PMEANCF ", "PMEANTF ", \
    "PMEANAH ", "PMEANBH ", "PMEANCH ", "PMEANTH ", \
    "PFMEANA ", "PFMEANB ", "PFMEANC ", "PFMEANT ", \
    "AENERGYA", "AENERGYB", "AENERGYC", "AENERGYT", \
    "AENERGAF", "AENERGBF", "AENERGCF", "AENERGTF", \
    "AENERGAH", "AENERGBH", "AENERGCH", "AENERGTH", \
    "RENERGYA", "RENERGYB", "RENERGYC", "RENERGYT", \
    "SENERGYA", "SENERGYB", "SENERGYC", "SENERGYT", \
    "FREQ    ", "TEMP    ", "TIME    ", "DATE    ", "        ", \
    "CUM 1234", "CUM T1  ", "CUM T2  ", "CUM T3  ", "CUM T4  ", \
    "MD  1234", "MD T1   ", "MD T2   ", "MD T3   ", "MD T4   ", \
    "APPINFO ", "APP VER ", "BOARD   " \
};

static const char * oled1_unit_str[OLED1_UNIT_NUM] = {
	"Wh   ", "kWh  ", "MWh  ", "VAh  ", "kVAh ", "MVAh ", "Ah   ", "kAh  ", "MAh  ",      \
    "Vrms ", "Arms ", "W    ", "kW   ", "VA   ", "VAr  ", "VArh ", "kVArh", "MVArh",   \
    "Hz   ", "kHz  ", "MHz  ", "     " \
};
/**
 * \brief Write string to OLED1 LCD glass string field.
 *
 * This function will write the disp_string to the string field of the
 * lcd glass.
 *
 * \param data Pointer to the input string(max length is 10)
 */
void oled1_show_icon_string(oled1_string disp_string)
{
    gfx_mono_draw_string(&oled1_string_str[disp_string][0],0, 0, &sysfont);
}

/**
 * \brief Clear a specific flag on the OLED1 glass.
 *
 * This function will clear a specific flag.
 *
 * \param OLED1_FLAG  Clear Flag
 *
 * \note Use the flag define in header file.
 */
void oled1_clear_flag(OLED1_FLAG flag)
{
}

/**
 * \brief Show a specific flag on the OLED1 glass.
 *
 * This function will show a specific flag.
 *
 * \param oled1_icon  Show Flag
 *
 * \note Use the flag define in header file.
 */
void oled1_show_flag(OLED1_FLAG flag)
{
}

/**
 * \brief Clear events on the OLED1 glass.
 *
 * This function will clear events.
 *
 * \param OLED1_FLAG  Clear Events
 *
 * \note Use the events define in header file.
 */
void oled1_clear_events(METROLOGY_API_EVENTS events)
{
}

/**
 * \brief Show events on the OLED1 glass.
 *
 * This function will show events.
 *
 * \param events  Show events
 *
 * \note Use the events define in header file.
 */
void oled1_show_events(METROLOGY_API_EVENTS events)
{
}

/**
 * \brief Clear all content of the LCD glass.
 *
 * This function clears all pixels and areas of the LCD glass OLED1.
 *
 */
void oled1_clear_all(void)
{

}

/**
 * \brief Clear all content of the LCD glass.
 *
 * This function clears all pixels and areas of the LCD glass OLED1.
 *
 */
void oled1_display_off(void)
{
    gfx_mono_sleep_enable();
}

/**
 * \brief Write string to OLED1 LCD glass numeric field.
 *
 * This function will write the input string to the value field of the
 * lcd glass.
 *
 * \param data Pointer to the input string(max length is 10)
 */
void oled1_show_numeric_string(char *data)
{
    gfx_mono_draw_string(data,0, 16, &sysfont);
}

/**
 * \brief Show a measurement unit symbol to LCD glass.
 *
 * This function set all pixels needed to show a measurment unit to the LCD glass.
 *
 */
void oled1_show_units(OLED1_UNIT disp_unit)
{
    gfx_mono_draw_string(oled1_unit_str[disp_unit], 88, 16, &sysfont);
}

/**
 * \brief Clear all measurement unit symbols of the LCD glass.
 *
 * This function will clear all pixels related to measurment unit of the LCD glass.
 *
 */
void oled1_clear_units(void)
{
    oled1_show_units(OLED1_EMPTY_UNIT);
}
