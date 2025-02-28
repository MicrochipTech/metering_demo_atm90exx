#include "stdint.h"

enum status_code {
	STATUS_OK               =  0, //!< Success
	STATUS_ERR_BUSY         =  1
};

typedef enum status_code status_code_t;

/**
 * \name Display Lines
 * @{
 */
typedef enum  {
	/** Up Line (Symbols from 1 to 8) */
	OLED1_LINE_UP = 0,
	/** Down Line (Symbols from 9 to 15 */
	OLED1_LINE_DOWN,
}oled1_line;

/**
 * \name Value for Communication Icon setting
 * @{
 */
typedef enum  {
	OLED1_ICON_NONE = 0,
    OLED1_ICON_NUM
}oled1_icon;

/**
 * \name Value for Communication Icon setting
 * @{
 */
typedef enum  {
	OLED1_FLAG_NONE = 0,
    OLED1_FLAG_NUM
}OLED1_FLAG;

/**
 * \name Display String Units
 * @{
 */
typedef enum  {
	/** VA */
	OLED1_STRING_VA = 0,
	/** VB */
	OLED1_STRING_VB,
	/** VC */
	OLED1_STRING_VC,
	/** IA */
	OLED1_STRING_IA,
	/** IB */
	OLED1_STRING_IB,
	/** IC */
	OLED1_STRING_IC,
	/** IN */
	OLED1_STRING_IN,
    /** Phase Angle VA_IA */
	OLED1_STRING_PA_VA_IA,
	/** Phase Angle VB_IB */
	OLED1_STRING_PA_VB_IB,
	/** Phase Angle VC_IC */
	OLED1_STRING_PA_VC_IC,
    /** Phase Angle VA_VA */
	OLED1_STRING_PA_VA_VA,
	/** Phase Angle VB_VA */
	OLED1_STRING_PA_VB_VA,
	/** Phase Angle VC_VA */
	OLED1_STRING_PA_VC_VA,
	/** Active Power A */
	OLED1_STRING_PMEANA,
	/** Active Power B */
	OLED1_STRING_PMEANB,
	/** Active Power C */
	OLED1_STRING_PMEANC,
	/** Active Power T */
	OLED1_STRING_PMEANT,
	/** Reactive Power A */
	OLED1_STRING_QMEANA,
	/** Reactive Power B */
	OLED1_STRING_QMEANB,
	/** Reactive Power C */
	OLED1_STRING_QMEANC,
	/** Reactive Power T */
	OLED1_STRING_QMEANT,
	/** Apparent Power A */
	OLED1_STRING_SMEANA,
	/** Apparent Power B */
	OLED1_STRING_SMEANB,
	/** Apparent Power C */
	OLED1_STRING_SMEANC,
	/** Apparent Power T */
	OLED1_STRING_SMEANT,
    /** Fundamental Active Power Phase A */
	OLED1_STRING_PMEANAF,
	/** Fundamental Active Power Phase B */
	OLED1_STRING_PMEANBF,
	/** Fundamental Active Power Phase C */
	OLED1_STRING_PMEANCF,
	/** Fundamental Active Power Total */
	OLED1_STRING_PMEANTF,
	/** Harmonics Active Power Phase A */
	OLED1_STRING_PMEANAH,
	/** Harmonics Active Power Phase B */
	OLED1_STRING_PMEANBH,
	/** Harmonics Active Power Phase C */
	OLED1_STRING_PMEANCH,
	/** Harmonics Active Power Total */
	OLED1_STRING_PMEANTH,
    /** Power Factor Phase A */
	OLED1_STRING_PFMEANA,
	/** Power Factor Phase B */
	OLED1_STRING_PFMEANB,
	/** Power Factor Phase C */
	OLED1_STRING_PFMEANC,
	/** Power Factor Total */
	OLED1_STRING_PFMEANT,
	/** Active Power Energy Phase A */
	OLED1_STRING_AENERGYA,
	/** Active Power Energy Phase B */
	OLED1_STRING_AENERGYB,
    /** Active Power Energy Phase C */
	OLED1_STRING_AENERGYC,
    /** Active Power Energy Total */
	OLED1_STRING_AENERGYT,
	/** Fundamental Active Power Energy Phase A */
	OLED1_STRING_AENERGYAF,
	/** Fundamental Active Power Energy Phase B */
	OLED1_STRING_AENERGYBF,
    /** Fundamental ctive Power Energy Phase C */
	OLED1_STRING_AENERGYCF,
    /** Fundamental Active Power Energy Total */
	OLED1_STRING_AENERGYTF,
	/** Harmonics Active Power Energy Phase A */
	OLED1_STRING_AENERGYAH,
	/** Harmonics Active Power Energy Phase B */
	OLED1_STRING_AENERGYBH,
    /** Harmonics Active Power Energy Phase C */
	OLED1_STRING_AENERGYCH,
    /** Harmonics Active Power Energy Total */
	OLED1_STRING_AENERGYTH,
	/**  Reactive Power Energy Phase A */
	OLED1_STRING_RENERGYA,
	/** Reactive Power Energy Phase B */
	OLED1_STRING_RENERGYB,
    /** Reactive Power Energy Phase C */
	OLED1_STRING_RENERGYC,
    /** Reactive Power Energy Total */
	OLED1_STRING_RENERGYT,
    /** Apparent Power Energy Phase A */
	OLED1_STRING_SAENERGYA,
	/** Apparent Power Energy Phase B */
	OLED1_STRING_SAENERGYB,
    /** Apparent Power Energy Phase C */
	OLED1_STRING_SAENERGYC,
    /** Apparent Power Energy Total */
	OLED1_STRING_SAENERGYT,
	/** Frequency */
	OLED1_STRING_FREQUENCY,
	/** Temperature */
	OLED1_STRING_TEMPERATURE,
    /** Time */
    OLED1_STRING_TIME,
    /** Date */
    OLED1_STRING_DATE,        
    /** Empty */
	OLED1_STRING_EMPTY,
    /** TOU Total */
    OLED1_STRING_TOU_1234_CUM,
    /** TOU 1 */
    OLED1_STRING_TOU_1_CUM,
    /** TOU 2 */
    OLED1_STRING_TOU_2_CUM,
    /** TOU 3 */
    OLED1_STRING_TOU_3_CUM,
    /** TOU 4 */
    OLED1_STRING_TOU_4_CUM,
    /** TOU Total Maximum Demand */
    OLED1_STRING_TOU_1234_MD,
    /** TOU 1 Maximum Demand */
    OLED1_STRING_TOU_1_MD,
    /** TOU 2 Maximum Demand */
    OLED1_STRING_TOU_2_MD,
    /** TOU 3 Maximum Demand */
    OLED1_STRING_TOU_3_MD,
    /** TOU 4 Maximum Demand */
    OLED1_STRING_TOU_4_MD,
    /** Application Info */
    OLED1_STRING_APP_INFO,  
    /** Application Version */
    OLED1_STRING_APP_VERSION,
    /** Board Info */
    OLED1_STRING_BOARD_INFO,
	/** Number of Strings */            
	OLED1_STRING_NUM
}oled1_string;

/**
 * \name Display Units
 * @{
 */
/* Wh, kWh, MWh, VAh, kVAh, MVAh, Ah, kAh, MAh, V, A, W, VA, VAr, VArh, kVArh, MVArh, Hz */
typedef enum {
	/** Wh */
	OLED1_UNIT_Wh = 0,
	/** kWh */
	OLED1_UNIT_kWh,
	/** MWh */
	OLED1_UNIT_MWh,
	/** VAh */
	OLED1_UNIT_VAh,
	/** kVAh */
	OLED1_UNIT_kVAh,
	/** MVAh */
	OLED1_UNIT_MVAh,
	/** Ah */
	OLED1_UNIT_Ah,
	/** kAh */
	OLED1_UNIT_kAh,
	/** MAh */
	OLED1_UNIT_MAh,
	/** Vrms */
	OLED1_UNIT_Vrms,
	/** Arms */
	OLED1_UNIT_Arms,
	/** W */
	OLED1_UNIT_W,
	/** kW */
	OLED1_UNIT_kW,
	/** VA */
	OLED1_UNIT_VA,
	/** VAr */
	OLED1_UNIT_VAr,
	/** VArh */
	OLED1_UNIT_VArh,
	/** kVArh */
	OLED1_UNIT_kVArh,
	/** MVArh */
	OLED1_UNIT_MVArh,
	/** Hz */
	OLED1_UNIT_Hz,
	/** kHz */
	OLED1_UNIT_kHz,
	/** MHz */
	OLED1_UNIT_MHz,
    /** Empty Unit */
    OLED1_EMPTY_UNIT,
	/** Number of UNITS */
	OLED1_UNIT_NUM
}OLED1_UNIT;

/**
 * \brief Write string measure to OLED1 LCD glass.
 *
 * This function will write the input measure index value to the string part of
 * lcd glass.
 *
 * \param measure Measure index to show 
 */
void oled1_show_icon_string(oled1_string measure);

/**
 * \brief Clear a specific flag on the OLED1 glass.
 *
 * This function will clear a specific flag.
 *
 * \param OLED1_FLAG  Flag
 *
 * \note Use the flag define in header file.
 */
void oled1_clear_flag(OLED1_FLAG flag);

/**
 * \brief Show a specific flag on the OLED1 glass.
 *
 * This function will show a specific flag.
 *
 * \param OLED1_FLAG  Flag
 *
 * \note Use the icon define in header file.
 */
void oled1_show_flag(OLED1_FLAG flag);

/**
 * \brief Clear events on the OLED1 glass.
 *
 * This function will clear events.
 *
 * \param METROLOGY_API_EVENTS  Clear Events
 *
 * \note Use the events define in header file.
 */
void oled1_clear_events(METROLOGY_API_EVENTS events);

/**
 * \brief Show events on the OLED1 glass.
 *
 * This function will show events.
 *
 * \param events  Show events
 *
 * \note Use the events define in header file.
 */
void oled1_show_events(METROLOGY_API_EVENTS events);

/**
 * \brief Show all content of the OLED1 glass.
 *
 * This function sets all pixels and areas of the LCD glass OLED1.
 *
 */
void oled1_show_all(void);

/**
 * \brief Clear all content of the LCD glass.
 *
 * This function clears all pixels and areas of the LCD glass OLED1.
 *
 */
void oled1_clear_all(void);
void oled1_display_off(void);

/**
 * \brief Show a decimal numeric value to LCD glass.
 *
 * This function displays an int32 value to the LCD numeric field of the glass.
 *
 * \param value The int32_t value to be displayed
 *
 * \note The value range is [-32768, 32767].
 */
void oled1_show_numeric_string(char *data);

/**
 * \brief Show a measurement unit symbol to LCD glass.
 *
 * This function set all pixels needed to show a measurment unit to the LCD glass.
 *
 */
void oled1_show_units(OLED1_UNIT disp_unit);

/**
 * \brief Clear all measurement unit symbols of the LCD glass.
 *
 * This function will clear all pixels related to measurment unit of the LCD glass.
 *
 */
void oled1_clear_units(void);

/**
 * \brief Clear line of OLED1 LCD glass and the dots icons.
 *
 * This function will clear the full line of the LCD glass.
 */
void oled1_clear_line(oled1_line disp_line);