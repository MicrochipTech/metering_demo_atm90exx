/*******************************************************************************
  Interface definition of ATM90EXX events API.

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_events_api.c

  Summary:
    Interface definition of the ATM90EXX events API.

  Description:
    This file defines the interface for the ATM90EXX Events API.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"
#include "user.h"
#include "atm90exx_regs.h"
#include "../metrology_conf.h"
#include "../metrology_defs.h"
#include "../metrology_api.h"
#include "../metrology_api_events.h"
#include "atm90exx_conf.h"
#include "atm90exx_defs.h"
#include "atm90exx_api.h"
#include "atm90exx_drv.h"
#include "atm90exx_regs.h"
#include "atm90exx_api_events.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
extern METROLOGY_API_EVENTS atm90ExxEvents;
extern ATM90EXX_DRV_OBJ gATM90ExxDrvObj;

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
// Section: ATM90EXX API event Functions
// *****************************************************************************

ATM90EXX_API_RESULT ATM90EXX_API_get_events (METROLOGY_API_EVENTS *events)
{
    *events = atm90ExxEvents;
    return ATM90EXX_API_SUCCESS;
}

// *****************************************************************************
#ifdef ATM90EXX_SAG_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_sag ( ATM90EXX_API_VOLTAGE_LINE phase )

  Remarks:
    Depends on the implementation
    - SAG Detection is always running, the enable is of the interrupt
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_sag (ATM90EXX_API_VOLTAGE_LINE line)
{
    uint16_t value;
    bool NOTok = false;

#ifdef ATM90E26_SUPPORT
    if (line != ATM90EXX_VLINE_UA)
    { 
        SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "ATM90E26 only supports UA voltage");
        return ATM90EXX_API_ERROR;
    }
    /* Last version of the control */
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn;
    value |= FUNCEN_SAGEN_Msk ;
    // Direct access to register is possible for this feature
    NOTok |= ATM90EXX_DRV_write_reg( FUNCEN_ADDR, value );
    if (!NOTok)
    { 
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E32_SUPPORT
    
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1;

    switch (line)
    {
        case ATM90EXX_VLINE_UA:
            value |= EMMINTEN1_SAGPHASEAINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UB:
            value |= EMMINTEN1_SAGPHASEBINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UC:
            value |= EMMINTEN1_SAGPHASECINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_ALL:
            value |= EMMINTEN1_SAGALLINTEN_Msk ;
            break;
    }
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN1_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E36_SUPPORT
    /* Last version of the control */
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0;
    value |= FUNCEN0_SAGWNEN_Msk ;
    // Direct access to register is possible for this feature
    NOTok |= ATM90EXX_DRV_write_reg( FUNCEN0_ADDR, value );
    if (!NOTok)
    { 
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
  return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT METROLOGY_API_disable_sag ( ATM90EXX_API_VOLTAGE_LINE phase )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_sag (ATM90EXX_API_VOLTAGE_LINE line)
{
    uint16_t value;
    bool NOTok = false;

#ifdef ATM90E26_SUPPORT
    if (line != ATM90EXX_VLINE_UA)
    { 
        SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "ATM90E26 only supports UA voltage");
        return ATM90EXX_API_ERROR;
    }
    /* Last version of the control */
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn;
    value &= ~FUNCEN_SAGEN_Msk ;
    // Direct access for this register is allowed
    NOTok |= ATM90EXX_DRV_write_reg( FUNCEN_ADDR, value );
    if (!NOTok)
    { 
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E32_SUPPORT
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1;

    switch (line)
    {
        case ATM90EXX_VLINE_UA:
            value &= ~EMMINTEN1_SAGPHASEAINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UB:
            value &= ~EMMINTEN1_SAGPHASEBINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UC:
            value &= ~EMMINTEN1_SAGPHASECINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_ALL:
            value &= ~EMMINTEN1_SAGALLINTEN_Msk ;
            break;
    }
    
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN1_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E36_SUPPORT
    /* Last version of the control */
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0;
    value &= ~FUNCEN0_SAGWNEN_Msk ;
    // Direct access for this register is allowed
    NOTok |= ATM90EXX_DRV_write_reg( FUNCEN0_ADDR, value );
    if (!NOTok)
    { 
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 = value;
        return ATM90EXX_API_SUCCESS;
}
#endif
  return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API ATM90EXX_API_set_sag_threshold ( uint32_t threshold )
      - threshold_rms: Expected Vrms Threshold in decimal format 000.0001V resolution (ATM90EXX_V_ACCURACY_INT)
  Remarks:
    Depends on the implementation
    - ATM90E26:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 cycle after ZC
      Detect Condition: three 8K voltage samples bellow the threshold
      Value: SagTh = (100*Un*sqrt(2)* x%) / (4*Ugain/32768)
      - ATM90E32:
      OVth Register: Over Voltage Threshold, default= 0xC000
      Detect: any phase's absolute voltage sample instantaneous value goes over the threshold
      Value: 0xFFFF maps to ADC output full-scale peak.
             xxThRegValue = RmsRegValue*sqrt(2)/([U|I]gain/2^14)
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_sag_threshold ( uint32_t threshold )
{
    uint32_t value;
    uint64_t value_ext;
    bool NOTok = false;
    
    // Internal Register Voltage Resolution is 000.01V
    value = threshold / 100;
    // Remove Scale Factor to the value
    value_ext = ATM90EXX_API_remove_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);
    
#ifdef ATM90E26_SUPPORT
    /* Set the threshold according with datasheet */
    /* Voltage sag threshold configuration. Internal Representation. */
    // value = (uint32_t) (rms / ((gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.Ugain) / (32768/4)));
    value_ext = (value_ext << 13);   // 32768/4 = 8192 => << 13
    value_ext /= gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.Ugain;
    value = (uint32_t) value_ext;
    // Direct access to this register is allowed
    NOTok |= ATM90EXX_DRV_write_reg( SAGTH_ADDR, (uint16_t) value );
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E3X_SUPPORT
    // 
    value_ext = (value_ext << 14);
    value = (uint32_t) ((SQRT2 * value_ext) / gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA);
#endif
#ifdef ATM90E32_SUPPORT    
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(SAGTH_ADDR, (uint16_t) value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
#endif    
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh = value;
        return ATM90EXX_API_SUCCESS;
    }
   return ATM90EXX_API_ERROR; 
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_sag_threshold ( uint32_t *rms )

  Remarks:
    Depends on the implementation
    - ATM90E26:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 cycle after ZC
      Detect Condition: three 8K voltage samples bellow the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_sag_threshold ( uint32_t *threshold )
{
    uint32_t value;
    uint64_t value_ext;

#ifdef ATM90E26_SUPPORT
    /* Last version of the control */
    value = (uint32_t) (gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.Ugain * gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh / 8192 /* 32768/4 */);
#endif
#ifdef ATM90E3X_SUPPORT
    // PENDING TO CALCULATE
    value_ext = (uint64_t) (gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.SagTh * gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA / SQRT2) ;
    value = (uint32_t) (value_ext >> 14);
#endif
    // ATM90EXX Voltage Resolution is 000.0001V
    value *= 100;
    // Apply Scale Factor to the value
    value_ext = ATM90EXX_API_apply_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);
    *threshold = (uint32_t)value_ext;

    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_sag_period ( uint32_t period_ms )

  Remarks:
    Depends on the implementation
    - ATM90E26:
      Measurement Period: Fixed. 1 cycle after ZC
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_sag_period ( uint32_t period_ms)
{ 
#ifdef ATM90E26_SUPPORT
    /* Fixed - Voltage sag is detected when voltage is continuously below the voltage sag 
     threshold for one cycle which starts from any zero-crossing point */
    SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "ATM90E26 sag period is fixed");
#endif
#ifdef ATM90E32_SUPPORT
    /* Configurable - The M90E32AS generates Sag event when there are less than three 8KHz 
     samples (absolute value) greater than the sag threshold in one detecting period */
#endif
#ifdef ATM90E36_SUPPORT
    /* Fixed - The M90E36A generates Sag event when there are less than three 8KHz samples 
    (absolute value) greater than the sag threshold during two continuous 11ms time-window */
    SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "ATM90E36 sag period is fixed");
#endif
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_sag_period ( uint32_t *period_ms )

  Remarks:
    Depends on the implementation:
    - ATM90E26:
      Measurement Period: Fixed. 1 cycle after ZC. Depends on the frequency (FREQ_ADDR - Format XX.XX)
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_sag_period (uint32_t *period_ms)
{
#ifdef ATM90E26_SUPPORT
  /* Fixed - Voltage sag is detected when voltage is continuously below the voltage sag 
   threshold for one cycle which starts from any zero-crossing point */
  SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "ATM90E26 sag period is fixed");
#endif
#ifdef ATM90E32_SUPPORT
  /* Configurable - The M90E32AS generates Sag event when there are less than three 8KHz 
   samples (absolute value) greater than the sag threshold in one detecting period */
#endif
#ifdef ATM90E36_SUPPORT
  /* Fixed - The M90E36A generates Sag event when there are less than three 8KHz samples 
  (absolute value) greater than the sag threshold during two continuous 11ms time-window */
  SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "ATM90E36 sag period is fixed");
#endif
  return ATM90EXX_API_SUCCESS;
}
#endif // ATM90EXX_SAG_SUPPORT

#ifdef ATM90EXX_SWELL_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_swell ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
    Depends on the implementation
    - SWELL Detection is always running, the enable is of the interrupt
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_swell (ATM90EXX_API_VOLTAGE_LINE line)
{

#ifdef ATM90E32_SUPPORT
    uint16_t value;

    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0;

    switch (line)
    {
        case ATM90EXX_VLINE_UA:
            value |= EMMINTEN0_OVPHASEAINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UB:
            value |= EMMINTEN0_OVPHASEBINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UC:
            value |= EMMINTEN0_OVPHASECINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_ALL:
            value |= EMMINTEN0_OVALLINTEN_Msk ;
            break;
    }
    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN0_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_swell ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_swell ( ATM90EXX_API_VOLTAGE_LINE line)
{
#ifdef ATM90E32_SUPPORT
    
    uint16_t value;

    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0;

    switch (line)
    {
        case ATM90EXX_VLINE_UA:
            value &= ~EMMINTEN0_OVPHASEAINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UB:
            value &= ~EMMINTEN0_OVPHASEBINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UC:
            value &= ~EMMINTEN0_OVPHASECINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_ALL:
            value &= ~EMMINTEN0_OVALLINTEN_Msk ;
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN0_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_swell_threshold ( uint32_t threshold_rms )
      - threshold_rms: Volts - Format??
  Remarks:
    Depends on the implementation
    - ATM90E32:
      OVth Register: Over Voltage Threshold, default= 0xC000
      Detect: any phase's absolute voltage sample instantaneous value goes over the threshold
      Value: 0xFFFF maps to ADC output full-scale peak.
             xxThRegValue = RmsRegValue*sqrt(2)/(Vgain/2^14)
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_swell_threshold (uint32_t threshold)
{
#ifdef ATM90E32_SUPPORT
  
    uint32_t value;
    uint64_t value_ext;
    bool NOTok = false;
    
    // Internal Register Voltage Resolution is 000.01V
    value = threshold / 100;
    // Remove Scale Factor to the value
    value_ext = ATM90EXX_API_remove_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);  

    value_ext = (value_ext << 14);
    value = (uint32_t) ((SQRT2 * value_ext) / gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(OVTH_ADDR, (uint16_t) value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.OVth = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_swell_threshold ( uint32_t threshold_rms )

  Remarks:
    Depends on the implementation
    - ATM90E32:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 instantaneous voltage sample
      Detect Condition: 1 instantaneous voltage sample over the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_swell_threshold ( uint32_t *threshold )
{
#ifdef ATM90E32_SUPPORT    
    uint32_t value;
    uint64_t value_ext;

    // PENDING TO CALCULATE
    value_ext = (uint64_t) (gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.OVth * gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA / SQRT2) ;
    value = (uint32_t) (value_ext >> 14);

    // ATM90EXX Voltage Resolution is 000.0001V
    value *= 100;
    // Apply Scale Factor to the value
    value_ext = ATM90EXX_API_apply_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);
    *threshold = (uint32_t)value_ext;

    return ATM90EXX_API_SUCCESS;
#endif    
    return ATM90EXX_API_ERROR;
}
#endif

#ifdef ATM90EXX_OVER_CURRENT_SUPPORT

// *****************************************************************************
// *****************************************************************************
// OVERCURRENT EVENT
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_overcurrent ( ATM90EXX_API_CURRENT_LINE line )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_overcurrent (ATM90EXX_API_CURRENT_LINE line )
{
    uint16_t value;

#ifdef ATM90E32_SUPPORT
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0;

    switch (line)
    {
        case ATM90EXX_CLINE_IA:
            value |= EMMINTEN0_OIPHASEAINTEN_Msk ;
            break;
        case ATM90EXX_CLINE_IB:
            value |= EMMINTEN0_OIPHASEBINTEN_Msk ;
            break;
        case ATM90EXX_CLINE_IC:
            value |= EMMINTEN0_OIPHASECINTEN_Msk ;
            break;
        case ATM90EXX_CLINE_IN:
            value |= EMMINTEN0_INOV0INTEN_Msk ;
            break;
        case ATM90EXX_CLINE_ALL:
            value |= EMMINTEN0_OIALLINTEN_Msk ;
            value |= EMMINTEN0_INOV0INTEN_Msk ;
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN0_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
  return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_overcurrent ( ATM90EXX_API_CURRENT_LINE line )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_overcurrent ( ATM90EXX_API_CURRENT_LINE line )
{
    uint16_t value;

#ifdef ATM90E32_SUPPORT
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0;

    switch (line)
    {
        case ATM90EXX_CLINE_IA:
            value &= ~EMMINTEN0_OIPHASEAINTEN_Msk ;
            break;
        case ATM90EXX_CLINE_IB:
            value &= ~EMMINTEN0_OIPHASEBINTEN_Msk ;
            break;
        case ATM90EXX_CLINE_IC:
            value &= ~EMMINTEN0_OIPHASECINTEN_Msk ;
            break;
        case ATM90EXX_CLINE_IN:
            value &= ~EMMINTEN0_INOV0INTEN_Msk ;
            break;
        case ATM90EXX_CLINE_ALL:
            value &= ~EMMINTEN0_OIALLINTEN_Msk ;
            value &= ~EMMINTEN0_INOV0INTEN_Msk ;
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN0_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_overcurrent_threshold ( uint32_t threshold_rms )
      - threshold_rms: Volts - Format??
  Remarks:
    Depends on the implementation
    - ATM90E32:
      OVth Register: Over Voltage Threshold, default= 0xC000
      Detect: any phase's absolute voltage sample instantaneous value goes over the threshold
      Value: 0xFFFF maps to ADC output full-scale peak.
             xxThRegValue = RmsRegValue*sqrt(2)/(Vgain/2^14)
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_overcurrent_threshold (ATM90EXX_API_CURRENT_LINE line, uint32_t threshold)
{
  uint32_t value;
  uint64_t value_ext;
  bool NOTok = false;
    
  // Internal Register Voltage Resolution is 000.01V
  value = threshold / 100;
  // Remove Scale Factor to the value
  value_ext = ATM90EXX_API_remove_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);  

#ifdef ATM90E3X_SUPPORT
    // 
    value_ext = (value_ext << 14);
    value = (uint32_t) ((SQRT2 * value_ext) / gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainA);
#ifdef ATM90E32_SUPPORT    
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
#endif    
    switch (line)
    {
#ifdef ATM90E32_SUPPORT            
        case (ATM90EXX_CLINE_IA):
        case (ATM90EXX_CLINE_IB):
        case (ATM90EXX_CLINE_IC):    
            NOTok |= ATM90EXX_DRV_write_reg(OITH_ADDR, (uint16_t) value);
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.OIth = value;
            break;
#endif            
        case (ATM90EXX_CLINE_IN): 
            NOTok |= ATM90EXX_DRV_write_reg(INWARNTH_ADDR, (uint16_t) value);
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh = value;
            break;
#ifdef ATM90E36_SUPPORT
        case (ATM90EXX_CLINE_INS): 
            NOTok |= ATM90EXX_DRV_write_reg(INWARNTH1_ADDR, (uint16_t) value);
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh1 = value;
            break;            
#endif            
        case (ATM90EXX_CLINE_ALL):
#ifdef ATM90E32_SUPPORT
            NOTok |= ATM90EXX_DRV_write_reg(OITH_ADDR, (uint16_t) value);
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.OIth = value;
#endif            
            NOTok |= ATM90EXX_DRV_write_reg(INWARNTH_ADDR, (uint16_t) value);
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh = value;
#ifdef ATM90E36_SUPPORT
            NOTok |= ATM90EXX_DRV_write_reg(INWARNTH1_ADDR, (uint16_t) value);
            gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh1 = value;
#endif                        
            break;
    }
#ifdef ATM90E32_SUPPORT        
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
#endif    
    if (!NOTok)
    {    
        return ATM90EXX_API_SUCCESS;
    }
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_overcurrent_threshold ( uint32_t threshold_rms )

  Remarks:
    Depends on the implementation
    - ATM90E32:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 instantaneous voltage sample
      Detect Condition: 1 instantaneous voltage sample over the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_overcurrent_threshold ( ATM90EXX_API_CURRENT_LINE line, uint32_t *threshold )
{
  uint32_t value;
  uint64_t value_ext;

#ifdef ATM90E32_SUPPORT
    if (line != ATM90EXX_CLINE_IN)
    {
        value_ext = (uint64_t) (gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.OIth * gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainA / SQRT2) ;
    }
    else
    {   
        value_ext = (uint64_t) (gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.InWarnTh * gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.IgainA / SQRT2) ;
    }
    value = (uint32_t) (value_ext >> 14);
#endif
    

    // ATM90EXX Voltage Resolution is 000.0001V
    value *= 100;
    // Apply Scale Factor to the value
    value_ext = ATM90EXX_API_apply_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);
    *threshold = (uint32_t)value_ext;

    return ATM90EXX_API_SUCCESS;
}
#endif

#ifdef ATM90EXX_PHASE_LOSS_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_loss ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
    Depends on the implementation
    - ATM90E26: doesn't exist
    - ATM90E32: enable for each line
    - ATM90E36: enable for all lines
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_loss (ATM90EXX_API_VOLTAGE_LINE line)
{

#ifdef ATM90E32_SUPPORT
    uint16_t value;

    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1;

    switch (line)
    {
        case ATM90EXX_VLINE_UA:
            value |= EMMINTEN1_PHASELOSSAINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UB:
            value |= EMMINTEN1_PHASELOSSBINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UC:
            value |= EMMINTEN1_PHASELOSSCINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_ALL:
            value |= EMMINTEN1_PHASELOSSALLINTEN_Msk ;
            break;
    }
    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN1_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn1 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E36_SUPPORT
    uint16_t value;
    bool NOTok = false;
    
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0;
    value |= FUNCEN0_PHASELOSSWNEN_Msk;
    NOTok |= ATM90EXX_DRV_write_reg(FUNCEN0_ADDR, value);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_loss ( ATM90EXX_API_VOLTAGE_LINE line )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_loss ( ATM90EXX_API_VOLTAGE_LINE line)
{
#ifdef ATM90E32_SUPPORT
    
    uint16_t value;

    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0;

    switch (line)
    {
        case ATM90EXX_VLINE_UA:
            value &= ~EMMINTEN0_OVPHASEAINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UB:
            value &= ~EMMINTEN0_OVPHASEBINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_UC:
            value &= ~EMMINTEN0_OVPHASECINTEN_Msk ;
            break;
        case ATM90EXX_VLINE_ALL:
            value &= ~EMMINTEN0_OVALLINTEN_Msk ;
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN0_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E36_SUPPORT
    uint16_t value;
    bool NOTok = false;

    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0;
    value &= ~FUNCEN0_PHASELOSSWNEN_Msk;
    NOTok |= ATM90EXX_DRV_write_reg(FUNCEN0_ADDR, value);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_swell_threshold ( uint32_t threshold_rms )
      - threshold_rms: Volts - Format??
  Remarks:
    Depends on the implementation
    - ATM90E26: doesn't exist - maybe by application
    - ATM90E3X:
      Phase Loss Register: Phase Loss Threshold
      Detect: any phase's absolute voltage sample instantaneous value goes over the threshold
      Value: 0xFFFF maps to ADC output full-scale peak.
             xxThRegValue = RmsRegValue*sqrt(2)/(Vgain/2^14)
    - ATM90E36:

 */
ATM90EXX_API_RESULT ATM90EXX_API_set_phase_loss_threshold (uint32_t threshold)
{
#ifdef ATM90E3X_SUPPORT
  uint32_t value;
  uint64_t value_ext;
  bool NOTok = false;
  
  // Internal Register Voltage Resolution is 000.01V
  value = threshold / 100;
  // Remove Scale Factor to the value
  value_ext = ATM90EXX_API_remove_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);
    // 
  value_ext = (value_ext << 14);
  value = (uint32_t) ((SQRT2 * value_ext) / gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA);
#ifdef ATM90E32_SUPPORT    
  NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
  NOTok |= ATM90EXX_DRV_write_reg(PHASELOSSTH_ADDR, (uint16_t) value);
  NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
#endif    
#ifdef ATM90E36_SUPPORT    
NOTok |= ATM90EXX_DRV_write_reg(PHASELOSSTH_ADDR, (uint16_t) value);
#endif
  if (!NOTok)
  {
      gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PhaseLossTh = value;
      return ATM90EXX_API_SUCCESS;
  }
#endif
 return ATM90EXX_API_ERROR; 
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_phase_loss_threshold ( uint32_t *threshold_rms )

  Remarks:
    Depends on the implementation
    - ATM90E32:
      Disabled by default. Enabled setting FuncEn.SagEn and SagTh.SagTh
      Measurement Period: Fixed. 1 instantaneous voltage sample
      Detect Condition: 1 instantaneous voltage sample over the threshold
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_phase_loss_threshold ( uint32_t *threshold )
{
#ifdef ATM90E3X_SUPPORT    
    uint32_t value;
    uint64_t value_ext;

    value_ext = (uint64_t) (gATM90ExxDrvObj.atm90ExxObj.thresholdInfo.PhaseLossTh * gATM90ExxDrvObj.atm90ExxObj.calMeasInfo.UgainA / SQRT2) ;
    value = (uint32_t) (value_ext >> 14);

    // ATM90EXX Voltage Resolution is 000.0001V
    value *= 100;
    // Apply Scale Factor to the value
    value_ext = ATM90EXX_API_apply_scale_factor(value, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);
    *threshold = (uint32_t)value_ext;

    return ATM90EXX_API_SUCCESS;
#endif    
    return ATM90EXX_API_ERROR;
}
#endif

#ifdef ATM90EXX_PHASE_SEQUENCE_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_sequence_err ( ATM90EXX_API_LINE_TYPE type )

  Remarks:
    Depends on the implementation
    - Phase Sequence Error Detection is always running, the enable is of the interrupt
 */
ATM90EXX_API_RESULT ATM90EXX_API_enable_phase_sequence_err ( ATM90EXX_API_LINE_TYPE type )
{
    uint16_t value;

#ifdef ATM90E32_SUPPORT
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0;

    switch (type)
    {
        case ATM90EXX_LINE_TYPE_VOLTAGE:
            value |= EMMINTEN0_UREVWNINTEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_CURRENT:
            value |= EMMINTEN0_IREVWNINTEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_ALL:
            value |= (EMMINTEN0_UREVWNINTEN_Msk | EMMINTEN0_IREVWNINTEN_Msk);
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN0_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E36_SUPPORT
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0;

    switch (type)
    {
        case ATM90EXX_LINE_TYPE_VOLTAGE:
            value |= FUNCEN0_UREVWNEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_CURRENT:
            value |= FUNCEN0_IREVWNEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_ALL:
            value |= (FUNCEN0_UREVWNEN_Msk | FUNCEN0_IREVWNEN_Msk);
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(FUNCEN0_ADDR, value);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }    
    return ATM90EXX_API_SUCCESS;
#endif
    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_sequence_err ( ATM90EXX_API_LINE_TYPE type )

  Remarks:
    Depends on the implementation
 */
ATM90EXX_API_RESULT ATM90EXX_API_disable_phase_sequence_err ( ATM90EXX_API_LINE_TYPE type )
{
#ifdef ATM90E32_SUPPORT
    uint16_t value;

    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0;

    switch (type)
    {
        case ATM90EXX_LINE_TYPE_VOLTAGE:
            value &= ~EMMINTEN0_UREVWNINTEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_CURRENT:
            value &= ~EMMINTEN0_IREVWNINTEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_ALL:
            value &= ~(EMMINTEN0_UREVWNINTEN_Msk | EMMINTEN0_IREVWNINTEN_Msk);
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_CONFIG_Val);
    NOTok |= ATM90EXX_DRV_write_reg(EMMINTEN0_ADDR, value);
    NOTok |= ATM90EXX_DRV_write_reg(CFGREGACCEN_ADDR, CFGREGACCEN_NORMAL_Val);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.EMMIntEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }
#endif
#ifdef ATM90E36_SUPPORT
    uint16_t value;
    
    value = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0;

    switch (type)
    {
        case ATM90EXX_LINE_TYPE_VOLTAGE:
            value &= ~FUNCEN0_UREVWNEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_CURRENT:
            value &= ~FUNCEN0_IREVWNEN_Msk ;
            break;
        case ATM90EXX_LINE_TYPE_ALL:
            value &= ~(FUNCEN0_UREVWNEN_Msk | FUNCEN0_IREVWNEN_Msk);
            break;
    }

    bool NOTok = false;
    NOTok |= ATM90EXX_DRV_write_reg(FUNCEN0_ADDR, value);
    if (!NOTok)
    {
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.FuncEn0 = value;
        return ATM90EXX_API_SUCCESS;
    }    
    return ATM90EXX_API_SUCCESS;
#endif
    return ATM90EXX_API_ERROR;
}

#endif // ATM90EXX_PHASE_SEQUENCE_SUPPORT

ATM90EXX_API_RESULT ATM90EXX_API_handle_events ( void )
{
    return ATM90EXX_API_SUCCESS;
}


// *****************************************************************************
// *****************************************************************************
// Section: Metrology Local Functions
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
 End of File
 */
