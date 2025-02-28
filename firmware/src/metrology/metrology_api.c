/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    metrology_api.c

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

#include "definitions.h"
#include "metrology_conf.h"
#include "metrology_defs.h"
#include "metrology_api.h"
#ifdef METROLOGY_ATM90EXX_SUPPORT
#include "atm90exx/atm90exx_conf.h"
#include "atm90exx/atm90exx_api.h"
#endif

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
    This structure should be initialized by the APP_TEST_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Metrology API Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Metrology API Local Functions
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
  Function:
    uitn32_t lUint32_2_BCD ( uint32_t bin, uint32_t *bcd, uint8_t max )
      - bin: binary to be converted
      - bcd: bcd converted
      - max: 
  Remarks:
    Same format on all ATM90EXX
 */
uint32_t lbin2bcd(uint32_t binary)
{
    uint32_t bcd = 0;
    uint32_t factor = 1;

    while (binary) {
        bcd += (binary % 10) * factor;
        binary /= 10;
        factor <<= 4;
    }
    return bcd;
}

/*******************************************************************************
  Function:
    uitn32_t lUint32_2_BCD ( uint32_t bin, uint32_t *bcd, uint8_t max )
      - bin: binary to be converted
      - format: Q Format structure
      - max: 
  Remarks:
    Same format on all ATM90EXX
 */
uint32_t lbin2qformat(uint32_t int_part, uint32_t fraq_part, METROLOGY_API_VALUE_FORMAT format)
{
    return 0;
}

METROLOGY_API_RESULT METROLOGY_DRV_Restart(uint32_t period_ms)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    ATM90EXX_DRV_Stop();
    return ATM90EXX_DRV_Start(period_ms);
#else
  return METROLOGY_API_ERROR;
#endif    
}

bool METROLOGY_API_CheckPhaseEnabled(METROLOGY_API_VOLTAGE_LINE line)
{
    return ATM90EXX_API_CheckPhaseEnabled(line);
}

bool METROLOGY_API_get_regInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return ATM90EXX_API_get_regInfo(index, reg_addr, reg_value, reg_name);
#endif
    return false;
}

bool METROLOGY_API_get_regControlInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return ATM90EXX_API_get_regInfo(ATM90EXX_REG_CTRL_INFO_OFFSET + index, reg_addr, reg_value, reg_name);
#endif
    return false;
}

uint16_t METROLOGY_API_get_regControlInfoEntries()
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return (uint16_t) (sizeof(METROLOGY_REGS_CONTROL) >> 1);
#endif
    return 0;
}

bool METROLOGY_API_get_regStatusInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return ATM90EXX_API_get_regInfo(ATM90EXX_REG_STATUS_INFO_OFFSET + index, reg_addr, reg_value, reg_name);
#endif
    return false;
}

uint16_t METROLOGY_API_get_regStatusInfoEntries()
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return (uint16_t)(sizeof(METROLOGY_REGS_STATUS) >> 1);
#endif
    return 0;    
}

bool METROLOGY_API_get_regAccumulatorsInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return ATM90EXX_API_get_regInfo(ATM90EXX_REG_MEAS_INFO_OFFSET + index, reg_addr, reg_value, reg_name);
#endif
    return false;
}

uint16_t METROLOGY_API_get_regAccumulatorsInfoEntries()
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return (uint16_t) (sizeof(METROLOGY_REGS_ACC) >> 1);
#endif
    return 0;
}

METROLOGY_CONF * METROLOGY_API_GetConfigData( void )
{
#ifdef METROLOGY_ATM90EXX_SUPPORT  
    return ATM90EXX_API_GetConfigData();
#endif
}

/*******************************************************************************
  Function:
    void lATM90EXX_API_get_frequency ( uint32_t *freq, METROLOGY_API_VALUE_FORMAT format )
      - freq: Frequency
  Remarks:
      - ATM90EXX resolution is 0.01 Hz
 */
void METROLOGY_API_get_frequency(uint32_t *freq, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    uint16_t lfreq;

    if (ATM90EXX_API_get_frequency(&lfreq) == ATM90EXX_API_SUCCESS)
    {
        // Adaptation to Metrology Resolution - None, it's the same
        *freq = lfreq;
    }    
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_temperature ( uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - temp: temperature in format (uQ20.12)
  Remarks:
    Same format on all ATM90E3X: 
      - 1LSB corresponds to 1 °C Signed, MSB as the sign bit
 */
void METROLOGY_API_get_temperature(uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90E3X_SUPPORT
    uint16_t ltemp = 0;
    METROLOGY_MEASURE_SIGN lsign;

    if (ATM90EXX_API_get_temp(&ltemp, &lsign) == ATM90EXX_API_SUCCESS)
    {
        *value = (ltemp * 10);
        if (sign != NULL)
            *sign = lsign;
    }
#else
    *value = 0xFFFF;
    *sign = MEASURE_SIGN_POSITIVE;
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_Vrms(METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_API_VALUE_FORMAT format)
    Remarks:
      - ATM90EXX: Same format on all ATM90EXX -> (0xxx.xxxx) V
 */
void METROLOGY_API_get_Vrms(METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    uint32_t rms;
    
    if (ATM90EXX_API_get_Vrms(line, &rms) == ATM90EXX_API_SUCCESS)
    {
        *value = rms;
    }
#endif
}

/*******************************************************************************
  Function:
    uint32_t METROLOGY_API_get_Irms ( METROLOGY_API_CURRENT_LINE line, uint32_t *value, METROLOGY_API_VALUE_FORMAT format )
      - freq: Active Line Voltage Fundamental Harmonic Frequency to (uQ20.12)
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_Irms(METROLOGY_API_CURRENT_LINE line, uint32_t *value, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    uint32_t rms;
    
    if (ATM90EXX_API_get_Irms(line, &rms) == ATM90EXX_API_SUCCESS)
    {
        *value = rms;
    }
#endif 
}

/*******************************************************************************
  Function:
    int32_t METROLOGY_API_get_PAngle ( METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - line: Angle between Voltage and Current of "line"
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_PAngle(METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    uint32_t phase;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_PAngle(line, &phase, &lsign) == ATM90EXX_API_SUCCESS)
    {
        *value = phase;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    int32_t METROLOGY_API_get_UAngle ( METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - line: Angle between Voltage line and Voltage A.
      -
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_UAngle(METROLOGY_API_VOLTAGE_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    uint32_t phase;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_UAngle(line, &phase, &lsign) == ATM90EXX_API_SUCCESS)
    {
        *value = phase;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_Pmean ( METROLOGY_API_PMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - line: Active Power Line 
  Remarks:
      - ATM90E32: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
 */
void METROLOGY_API_get_Pmean(METROLOGY_API_PMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    
    uint32_t pmean;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_Pmean(line, &pmean, &lsign) == ATM90EXX_API_SUCCESS)
    {        
        *value = pmean;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_PmeanF ( METROLOGY_API_PMEANF_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - line: Active Power Line 
  Remarks:
      - ATM90E32: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
 */
void METROLOGY_API_get_PmeanF(METROLOGY_API_PMEANF_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    
    uint32_t pmean;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_PmeanF(line, &pmean, &lsign) == ATM90EXX_API_SUCCESS)
    {        
        *value = pmean;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_PmeanH ( METROLOGY_API_PMEANH_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - line: Active Power Line 
  Remarks:
      - ATM90E32: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
 */
void METROLOGY_API_get_PmeanH(METROLOGY_API_PMEANH_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    
    uint32_t pmean;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_PmeanH(line, &pmean, &lsign) == ATM90EXX_API_SUCCESS)
    {        
        *value = pmean;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_Qmean ( METROLOGY_API_QMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - ATM90E3x: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
 */
void METROLOGY_API_get_Qmean(METROLOGY_API_QMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT

    uint32_t qmean;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_Qmean(line, &qmean, &lsign) == ATM90EXX_API_SUCCESS)
    {    
        *value = qmean;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_Smean ( METROLOGY_API_SMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - ATM90E3x: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is always '0'. Data format is XX.XXX, which corresponds to 0~+32.767kVA.
 */
void METROLOGY_API_get_Smean(METROLOGY_API_SMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT

    uint32_t smean;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_Smean(line, &smean, &lsign) == ATM90EXX_API_SUCCESS)
    {              
        *value = smean;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_PFmean ( METROLOGY_API_PMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format )
      - line: Active Power Line 
  Remarks:
      - ATM90EXX: Signed with complement format, X.XXX. LSB is 0.001. Range from -1000 to +1000
 */
void METROLOGY_API_get_PFmean(METROLOGY_API_PMEAN_LINE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    
    uint32_t pfmean;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_PFmean(line, &pfmean, &lsign) == ATM90EXX_API_SUCCESS)
    {
        *value = pfmean;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_AEnergy ( METROLOGY_API_AENERGY_TYPE line, METROLOGY_API_VALUE_FORMAT format )
      - type: energy type 
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_AEnergy(METROLOGY_API_AENERGY_TYPE type, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT

    uint32_t lenergy;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_AEnergy(type, &lenergy, &lsign) == ATM90EXX_API_SUCCESS)
    {
        if (clearFlag)
            ATM90EXX_API_clear_AEnergy(type);

        *value = lenergy;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_AEnergy ( METROLOGY_API_AENERGYF_TYPE line, METROLOGY_API_VALUE_FORMAT format )
      - freq: Active Line Voltage Fundamental Harmonic Frequency to (uQ20.12)
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_AFEnergy(METROLOGY_API_AFENERGY_TYPE type, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT

    uint32_t lenergy;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_AFEnergy(type, &lenergy, &lsign) == ATM90EXX_API_SUCCESS)
    {
        if (clearFlag)
            ATM90EXX_API_clear_AFEnergy(type);

        *value = lenergy;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_AEnergy ( METROLOGY_API_AENERGYH_TYPE line, METROLOGY_API_VALUE_FORMAT format )
      - freq: Active Line Voltage Fundamental Harmonic Frequency to (uQ20.12)
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_AHEnergy(METROLOGY_API_AHENERGY_TYPE type, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT

    uint32_t lenergy;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_AHEnergy(type, &lenergy, &lsign) == ATM90EXX_API_SUCCESS)
    {
        if (clearFlag)
            ATM90EXX_API_clear_AHEnergy(type);

        *value = lenergy;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_Qenergy ( METROLOGY_API_QENERGY_TYPE line, uint32_t *smean, METROLOGY_API_VALUE_FORMAT format )
      - freq: Active Line Voltage Fundamental Harmonic Frequency to (uQ20.12)
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_QEnergy(METROLOGY_API_QENERGY_TYPE type, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT

    uint32_t lenergy;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_QEnergy(type, &lenergy, &lsign) == ATM90EXX_API_SUCCESS)
    {
        if (clearFlag)
            ATM90EXX_API_clear_QEnergy(type);

        *value = lenergy;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

/*******************************************************************************
  Function:
    void METROLOGY_API_get_SEnergy ( METROLOGY_API_SENERGY_TYPE line, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format )
      - type
  Remarks:
    Same format on all ATM90EXX
 */
void METROLOGY_API_get_SEnergy(METROLOGY_API_SENERGY_TYPE type, uint32_t *value, METROLOGY_MEASURE_SIGN *sign, bool clearFlag, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT

    uint32_t lenergy;
    METROLOGY_MEASURE_SIGN lsign;
    
    if (ATM90EXX_API_get_SEnergy(type, &lenergy, &lsign) == ATM90EXX_API_SUCCESS)
    {
        if (clearFlag)
            ATM90EXX_API_clear_SEnergy(type);

        *value = lenergy;
        if (sign != NULL)
            *sign = lsign;
    }
#endif
}

void METROLOGY_API_clear_AEnergy(METROLOGY_API_AENERGY_TYPE type)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    ATM90EXX_API_clear_AEnergy(type);
#endif    
}

void METROLOGY_API_clear_AFEnergy(METROLOGY_API_AFENERGY_TYPE type)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    ATM90EXX_API_clear_AFEnergy(type);
#endif    
}

void METROLOGY_API_clear_AHEnergy(METROLOGY_API_AHENERGY_TYPE type)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    ATM90EXX_API_clear_AHEnergy(type);
#endif    
}

void METROLOGY_API_clear_QEnergy(METROLOGY_API_QENERGY_TYPE type)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    ATM90EXX_API_clear_QEnergy(type);
#endif    
}

void METROLOGY_API_clear_SEnergy(METROLOGY_API_SENERGY_TYPE type)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    ATM90EXX_API_clear_SEnergy(type);
#endif    
}

/*******************************************************************************
 End of File
 */
