/*******************************************************************************
  Interface definition of ATM90EXX API.

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_api.c

  Summary:
    Interface definition of the ATM90EXX API.

  Description:
    This file defines the interface for the ATM90EXX API.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"
#include "user.h"
#include "../metrology_conf.h"
#include "../metrology_defs.h"
#include "../metrology_api.h"
#include "../metrology_api_events.h"
#include "atm90exx_conf.h"
#include "atm90exx_defs.h"
#include "atm90exx_regs.h"
#include "atm90exx_hal.h"
#include "atm90exx_drv.h"
#include "atm90exx_api.h"

#ifdef METROLOGY_ATM90E26_SUPPORT
#include "atm90e26_regs.c"
#endif

#ifdef METROLOGY_ATM90E32_SUPPORT
#include "atm90e32_regs.c"
#endif

#ifdef METROLOGY_ATM90E36_SUPPORT
#include "atm90e36_regs.c"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

extern ATM90EXX_DRV_OBJ gATM90ExxDrvObj;
extern ATM90EXX_CONF atm90ExxObjDfltConf;
//extern ATM90EXX_REG_INFO *atm90exxRegsInfo;
        
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
// Section: Metrology API Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    METROLOGY_SCALE_FACTOR ATM90EXX_API_get_scale_factor ( METROLOGY_SCALE_FACTOR type )
      - Get Scale Factor for Voltage/Current 
 */
METROLOGY_SCALE_FACTOR ATM90EXX_API_get_scale_factor(METROLOGY_API_LINE_TYPE type)
{
    METROLOGY_SCALE_FACTOR lscale;
    
    switch (type)
    {
        case METROLOGY_LINE_TYPE_VOLTAGE:
            lscale = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale;
            break;
        case METROLOGY_LINE_TYPE_CURRENT:
            lscale = gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale;
            break;
        default:
            lscale = SCALE_FACTOR_1;
            break;
    }
    return lscale;
}


/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_set_scale_factor ( METROLOGY_API_LINE_TYPE type, METROLOGY_SCALE_FACTOR factor )
      - Set Scale Factor for Voltage/Current 
      - Variables depending on the scale show change too...(PLconstant)   => TBD
 */
ATM90EXX_API_RESULT ATM90EXX_API_set_scale_factor(METROLOGY_API_LINE_TYPE type, METROLOGY_SCALE_FACTOR factor)
{
    switch (type)
    {
        case METROLOGY_LINE_TYPE_VOLTAGE:
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale = factor;
            break;
        case METROLOGY_LINE_TYPE_CURRENT:
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale = factor;
            break;
        case METROLOGY_LINE_TYPE_ALL:
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale = factor;
            gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale = factor;
            break;
    }
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_SCALE_FACTOR ATM90EXX_API_remove_scale_factor ( uint32_t value, METROLOGY_SCALE_FACTOR factor )
      - Get Scale Factor for Voltage/Current 
      - By now, loss accuracy returning on the same type
 */
uint64_t ATM90EXX_API_remove_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor)
{
    
    uint32_t lvalue;
    
    if (factor == SCALE_FACTOR_1)
    {
        lvalue = (uint32_t) value;
    }
    else
    {
        lvalue = (factor & 0x08) ? (((uint64_t) value) << (factor & 0x07)) : ((uint64_t) (value >> factor));
    }
    
    return lvalue;
}

/*******************************************************************************
  Function:
    uint64_t ATM90EXX_API_apply_scale_factor ( uint32_t value, METROLOGY_SCALE_FACTOR factor )
      - Get Scale Factor for Voltage/Current 
      - By now, loss accuracy returning on the same type
 */
uint64_t ATM90EXX_API_apply_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor)
{
    
    uint64_t lvalue;
    
    if (factor == SCALE_FACTOR_1)
    {
        lvalue = (uint64_t) value;
    }
    else
    {
        lvalue = (factor & 0x08) ? (((uint64_t) value) >> (factor & 0x07)) : (((uint64_t) value) << factor);
    }
    
    return lvalue;
}

/*******************************************************************************
  Function:
    uint64_t ATM90EXX_API_apply_inverse_scale_factor ( uint32_t value, METROLOGY_SCALE_FACTOR factor )
      - Get Scale Factor for Voltage/Current 
      - By now, loss accuracy returning on the same type
 */
uint64_t ATM90EXX_API_apply_inverse_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor)
{   
    return ATM90EXX_API_apply_scale_factor(value, (factor & 0x08)? (factor & 0x07) : (factor | 0x08));
}

/*******************************************************************************
  Function:
    uint64_t ATM90EXX_API_remove_inverse_scale_factor ( uint32_t value, METROLOGY_SCALE_FACTOR factor )
      - Get Scale Factor for Voltage/Current 
      - By now, loss accuracy returning on the same type
 */
uint64_t ATM90EXX_API_remove_inverse_scale_factor(uint32_t value, METROLOGY_SCALE_FACTOR factor)
{   
    return ATM90EXX_API_remove_scale_factor(value, (factor & 0x08)? (factor & 0x07) : (factor | 0x08));
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_Vrms ( ATM90EXX_API_VOLTAGE_LINE line, uint32_t *rms )
    Remarks:
      - ATM90E26: 16 bits XXX.XX Format. Range [0~655.35V] Resolution 0.01V + Common LSB (8 bits) - Resolution 0.01V/256
      - ATM90E3X: 16 bits XXX.XX Format. Range [0~655.35V] Resolution 0.01V + LSB (8 bits) - Resolution 0.01V/256 
      - Adaptation to ATM90EXX resolution ATM90EXX_VI_ACCURACY_INT 0.0001 V
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_Vrms(ATM90EXX_API_VOLTAGE_LINE line, uint32_t *rms)
{
    uint32_t lrms = 0;
    uint64_t lrms_ext;
    
    /* From Last Read */
    switch (line)
    {
#ifdef ATM90E26_SUPPORT
        case METROLOGY_VLINE_UA:
#ifdef ATM90E26_LSB_SUPPORT
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsLSB >> 8);
            lrms *= 100;
            lrms /= 256;
#endif
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.Urms * 100);
            break;
#endif
#ifdef ATM90E3X_SUPPORT
        case METROLOGY_VLINE_UA:
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsALSB >> 8);
            lrms *= 100;
            lrms /= 256;
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsA * 100);
            break;
        case METROLOGY_VLINE_UB:
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsBLSB >> 8);
            lrms *= 100;
            lrms /= 256;
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsB * 100);
            break;
        case METROLOGY_VLINE_UC:
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsCLSB >> 8);
            lrms *= 100;
            lrms /= 256;
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.UrmsC * 100);
            break;
#endif
        default:
            *rms = 0;
            return ATM90EXX_API_ERROR;
    }
    // Apply Scale Factor to Current 
    lrms_ext = ATM90EXX_API_apply_scale_factor(lrms, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);
    *rms = (uint32_t) lrms_ext;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_Irms(ATM90EXX_API_CURRENT_LINE line, uint32_t *rms)
      - ATM90E26: 16 bits XXX.XX Format. Range [0~65.535A] Resolution 0.001A + Common LSB (8 bits) - Resolution 0.001A/256
      - ATM90E3X: 16 bits XXX.XX Format. Range [0~65.535A] Resolution 0.001A + LSB (8 bits) - Resolution 0.001A/256 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_Irms(ATM90EXX_API_CURRENT_LINE line, uint32_t *rms)
{
    uint32_t lrms = 0;
    uint64_t lrms_ext = 0;

    /* From Last Read */
    switch (line)
    {
#ifdef ATM90E26_SUPPORT
        case METROLOGY_CLINE_IA:
        case METROLOGY_CLINE_ALL:
#ifdef ATM90E26_LSB_SUPPORT
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsLSB >> 8);
            lrms *= 100;
            lrms /= 256;
#endif
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms * 100);
            break;
        case METROLOGY_CLINE_IN:
#ifdef ATM90E26_LSB_SUPPORT
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms2LSB >> 8);
            lrms *= 100;
            lrms /= 256;
#endif
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.Irms2 * 100);
            break;
#endif
#ifdef ATM90E3X_SUPPORT          
        case METROLOGY_CLINE_IA:
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsALSB >> 8);
            lrms *= 100;
            lrms /= 256;
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsA * 100);
            break;
        case METROLOGY_CLINE_IB:
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsBLSB >> 8);
            lrms *= 100;
            lrms /= 256;
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsB * 100);
            break;
        case METROLOGY_CLINE_IC:
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsCLSB >> 8);
            lrms *= 100;
            lrms /= 256;
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsC * 100);
            break;
        case METROLOGY_CLINE_IN:
            // ATM90E3X Calculated
            // No LSB resolution
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsNC * 100);
            break;
#ifdef ATM90E36_SUPPORT
        case METROLOGY_CLINE_INS:
            // ATM90E36 Measured ??? No LSB resolution
            lrms = (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsNS * 100);
            break;
#endif
        case METROLOGY_CLINE_ALL:
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsALSB >> 8);
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsBLSB >> 8);
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsCLSB >> 8);
            lrms *= 100;
            lrms /= 256;
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsA * 100);
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsB * 100);
            lrms += (gATM90ExxDrvObj.atm90ExxObj.measInfo.IrmsC * 100);
            break;
#endif            
        default:
            *rms = 0;
            return ATM90EXX_API_ERROR;
    }
    // Apply Scale Factor to Current 
    lrms_ext = ATM90EXX_API_apply_scale_factor(lrms, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);
    *rms = (uint32_t) lrms_ext;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_PAngle(ATM90EXX_API_VOLTAGE_LINE line, int32_t *phase)
      - ATM90EX6: 16 bits XXX.XX Format. Signed, MSB is the sign bit. Data format is XXX.X. Angle range: -180.0~+180.0 degree
      - ATM90E32: 16 bits XXX.XX Format. Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_PAngle(ATM90EXX_API_CURRENT_LINE line, uint32_t *phase, METROLOGY_MEASURE_SIGN *sign)
{
    uint16_t lphase = 0;
    
    /* From Last Read */
    switch (line)
    {
#ifdef ATM90E26_SUPPORT
        case METROLOGY_CLINE_IA:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.Pangle;
            break;
        case METROLOGY_CLINE_IB:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.Pangle2;
            break;            
#endif
#ifdef ATM90E3X_SUPPORT
        case METROLOGY_CLINE_IA:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.PAngleA;
            break;
        case METROLOGY_CLINE_IB:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.PAngleB;
            break;
        case METROLOGY_CLINE_IC:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.PAngleC;
            break;
#endif         
        default:
            lphase = 0;
            return ATM90EXX_API_ERROR;
    }
    if ((lphase & 0x8000) & 0x8000)
    {
        lphase = ((~lphase) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }    
    *phase = lphase;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_UAngle(ATM90EXX_API_VOLTAGE_LINE line, int32_t *phase)
      - ATM90E36: 16 bits XXX.XX Format. Signed, MSB is the sign bit. Data format is XXX.X. Angle range: -180.0~+180.0 degree
      - ATM90E32: 16 bits XXX.XX Format. Unsigned, 1LSB corresponds to 0.1 degree, 0�~+360.0� 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_UAngle(ATM90EXX_API_VOLTAGE_LINE line, uint32_t *phase, METROLOGY_MEASURE_SIGN *sign)
{
    uint16_t lphase = 0;
    
#ifdef ATM90E3X_SUPPORT    
    /* From Last Read */
    switch (line)
    {
        case METROLOGY_VLINE_UA:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.UAngleA;
            break;
        case METROLOGY_VLINE_UB:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.UAngleB;
            break;        
        case METROLOGY_VLINE_UC:
            lphase = gATM90ExxDrvObj.atm90ExxObj.measInfo.UAngleC;
            break;
        default:
            lphase = 0;
            break;
    }
    if ((lphase & 0x8000) & 0x8000)
    {
        lphase = ((~lphase) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
#endif    
    *phase = (uint32_t) lphase;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_Pmean ( ATM90EXX_API_POWER_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign )
      - ATM90E3x: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
      - Output decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_Pmean(ATM90EXX_API_PMEAN_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t lpmean = 0;
    uint64_t lpmean_ext = 0;

#ifdef ATM90E26_SUPPORT
    /* From Last Read */
    switch (line)
    {
        case METROLOGY_PMEANA:
        case METROLOGY_PMEANT:
            if ((gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean & 0x8000) == 0x8000)
            {
                lpmean = ((~gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean) + 1);
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            else
            {
                lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean & 0x7FFF);
                *sign = MEASURE_SIGN_POSITIVE;
            }
            break;
        case METROLOGY_PMEANB: /* Channel 2 */
            if ((gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean2 & 0x8000) == 0x8000)
            {
                lpmean = ((~gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean2) + 1);
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            else
            {
                lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.Pmean2 & 0x7FFF);
                *sign = MEASURE_SIGN_POSITIVE;
            }
            break;
        default:
            lpmean = 0;
            break;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
    lpmean *= 1000;
#endif
#ifdef ATM90E32_SUPPORT    
    switch (line)
    {    
        case METROLOGY_PMEANA:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanALSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanA << 16);
            break;
        case METROLOGY_PMEANB:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanB << 16);
            break;
        case METROLOGY_PMEANC:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanC << 16);
            break;
        case METROLOGY_PMEANT:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanT << 16);
            break;
        default:
            *pmean = 0;
            break;
    }
    if ((lpmean & 0x80000000) == 0x80000000)
    {
        lpmean = ((~lpmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
    lpmean_ext = ((uint64_t) lpmean) * 1000;
    lpmean_ext /= 3125;
    lpmean = (uint32_t) lpmean_ext;
#endif    
#ifdef ATM90E36_SUPPORT
    uint32_t resolution = 1;

    switch (line)
    {    
        case METROLOGY_PMEANA:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanALSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanA << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_PMEANB:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanB << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_PMEANC:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanC << 16);
            break;
        case METROLOGY_PMEANT:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanT << 16);
            resolution = 32 ; // 4/256 W
            break;
        default:
            *pmean = 0;
            break;
    }
    if ((lpmean & 0x80000000) == 0x80000000)
    {
        lpmean = ((~lpmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W (1mW)
    // Value = (Value >> 8) * (1 / resolution W) * 1000 (mW/W)
    lpmean = lpmean >> 8;   // Remove last 8 bits (all 0's)
    lpmean *= 1000;         // mW/W
    lpmean /= resolution;   // Resolution in W/Var/VA
#endif    

    // Apply Scale Factor to Voltage 
    lpmean_ext = ATM90EXX_API_apply_scale_factor(lpmean, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);  /* V_SCALE_FACTOR use to be NONE (x1) */
    // Apply Scale Factor to Current 
    lpmean_ext = ATM90EXX_API_apply_scale_factor((uint32_t)lpmean_ext, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);

    *pmean = (uint32_t) lpmean_ext;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_PmeanF ( ATM90EXX_API_POWER_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign )
      - ATM90E3x: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
      - Output decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_PmeanF(ATM90EXX_API_PMEANF_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t lpmean = 0;
    uint64_t lpmean_ext = 0;

#ifdef ATM90E32_SUPPORT    
    switch (line)
    {    
        case METROLOGY_PMEANAF:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAFLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAF << 16);
            break;
        case METROLOGY_PMEANBF:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBFLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBF << 16);
            break;
        case METROLOGY_PMEANCF:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCFLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCF << 16);
            break;
        case METROLOGY_PMEANTF:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTFLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTF << 16);
            break;
        default:
            *pmean = 0;
            break;
    }
    if ((lpmean & 0x80000000) == 0x80000000)
    {
        lpmean = ((~lpmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
    lpmean_ext = ((uint64_t) lpmean) * 1000;
    lpmean_ext /= 3125;
    lpmean = (uint32_t) lpmean_ext;
#endif    
#ifdef ATM90E36_SUPPORT
    uint32_t resolution = 1;

    switch (line)
    {    
        case METROLOGY_PMEANAF:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAFLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAF << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_PMEANBF:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBFLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBF << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_PMEANCF:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCFLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCF << 16);
            break;
        case METROLOGY_PMEANTF:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTFLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTF << 16);
            resolution = 32 ; // 4/256 W
            break;
        default:
            *pmean = 0;
            break;
    }
    if ((lpmean & 0x80000000) == 0x80000000)
    {
        lpmean = ((~lpmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W (1mW)
    // Value = (Value >> 8) * (1 / resolution W) * 1000 (mW/W)
    lpmean = lpmean >> 8;   // Remove last 8 bits (all 0's)
    lpmean *= 1000;         // mW/W
    lpmean /= resolution;   // Resolution in W/Var/VA
#endif    

    // Apply Scale Factor to Voltage 
    lpmean_ext = ATM90EXX_API_apply_scale_factor(lpmean, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);  /* V_SCALE_FACTOR use to be NONE (x1) */
    // Apply Scale Factor to Current 
    lpmean_ext = ATM90EXX_API_apply_scale_factor((uint32_t)lpmean_ext, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);

    *pmean = (uint32_t) lpmean_ext;
    return ATM90EXX_API_SUCCESS;
}


/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_PmeanF ( ATM90EXX_API_POWER_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign )
      - ATM90E32: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
      - Output decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_PmeanH(ATM90EXX_API_PMEANH_LINE line, uint32_t *pmean, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t lpmean = 0;
    uint64_t lpmean_ext = 0;

#ifdef ATM90E32_SUPPORT    
    switch (line)
    {    
        case METROLOGY_PMEANAH:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAHLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAH << 16);
            break;
        case METROLOGY_PMEANBH:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBHLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBH << 16);
            break;
        case METROLOGY_PMEANCH:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCHLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCH << 16);
            break;
        case METROLOGY_PMEANTH:
            lpmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTHLSB);
            lpmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTH << 16);
            break;
        default:
            *pmean = 0;
            break;
    }
    if ((lpmean & 0x80000000) == 0x80000000)
    {
        lpmean = ((~lpmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
    lpmean_ext = ((uint64_t) lpmean) * 1000;
    lpmean_ext /= 3125;
    lpmean = (uint32_t) lpmean_ext;
#endif    
#ifdef ATM90E36_SUPPORT
    uint32_t resolution=1;

    switch (line)
    {    
        case METROLOGY_PMEANAH:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAHLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanAH << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_PMEANBH:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBHLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanBH << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_PMEANCH:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCHLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanCH << 16);
            break;
        case METROLOGY_PMEANTH:
            lpmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTHLSB;
            lpmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.PmeanTH << 16);
            resolution = 32 ; // 4/256 W
            break;
        default:
            *pmean = 0;
            break;
    }
    if ((lpmean & 0x80000000) == 0x80000000)
    {
        lpmean = ((~lpmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W (1mW)
    // Value = (Value >> 8) * (1 / resolution W) * 1000 (mW/W)
    lpmean = lpmean >> 8;   // Remove last 8 bits (all 0's)
    lpmean *= 1000;         // mW/W
    lpmean /= resolution;   // Resolution in W/Var/VA
#endif    

    // Apply Scale Factor to Voltage 
    lpmean_ext = ATM90EXX_API_apply_scale_factor(lpmean, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);  /* V_SCALE_FACTOR use to be NONE (x1) */
    // Apply Scale Factor to Current 
    lpmean_ext = ATM90EXX_API_apply_scale_factor((uint32_t)lpmean_ext, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);

    *pmean = (uint32_t) lpmean_ext;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_Qmean ( ATM90EXX_API_QMEAN line, uint32_t *qmean, METROLOGY_MEASURE_SIGN *sign )
      - ATM90E3x: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_Qmean(ATM90EXX_API_QMEAN_LINE line, uint32_t *qmean, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t lqmean = 0;
    uint64_t lqmean_ext = 0;

#ifdef ATM90E26_SUPPORT   
    /* From Last Read */
    switch (line)
    {
        case METROLOGY_QMEANA:
        case METROLOGY_QMEANT:
            if ((gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean & 0x8000) == 0x8000)
            {
                lqmean = ((~gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean) + 1);
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            else
            {
                lqmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean & 0x7FFF);
                *sign = MEASURE_SIGN_POSITIVE;
            }           
            break;
        case METROLOGY_QMEANB: /* Channel 2 */
            if ((gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean2 & 0x8000) == 0x8000)
            {
                lqmean = ((~gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean2) + 1);
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            else
            {
                lqmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.Qmean2 & 0x7FFF);
                *sign = MEASURE_SIGN_POSITIVE;
            }
            break;
        default:
            lqmean = 0;
            break;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
    lqmean *= 1000;
#endif
#ifdef ATM90E32_SUPPORT
    /* From Last Read */
    switch (line)
    {    
        case METROLOGY_QMEANA:
            lqmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanALSB);
            lqmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanA << 16);
            break;
        case METROLOGY_QMEANB:
            lqmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanBLSB);
            lqmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanB << 16);
            break;
        case METROLOGY_QMEANC:
            lqmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanCLSB);
            lqmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanC << 16);
            break;
        case METROLOGY_QMEANT:
            lqmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanTLSB);
            lqmean |= (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanT << 16);
            break;
        default:
            lqmean = 0;
            break;
    }
    if ((lqmean & 0x80000000) == 0x80000000)
    {
        lqmean = ((~lqmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001VAr
    lqmean_ext =  ((uint64_t) lqmean) * 1000;
    lqmean_ext /= 3125;
    lqmean = (uint32_t) lqmean_ext;
#endif
#ifdef ATM90E36_SUPPORT
    uint32_t resolution = 1;

    switch (line)
    {    
        case METROLOGY_QMEANA:
            lqmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanALSB;
            lqmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanA << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_QMEANB:
            lqmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanBLSB;
            lqmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanB << 16);
            resolution = 256; // 1/256 W
            break;
        case METROLOGY_QMEANC:
            lqmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanCLSB;
            lqmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanC << 16);
            break;
        case METROLOGY_QMEANT:
            lqmean += gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanTLSB;
            lqmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.QmeanT << 16);
            resolution = 32 ; // 4/256 W
            break;
        default:
            *qmean = 0;
            break;
    }
    if ((lqmean & 0x80000000) == 0x80000000)
    {
        lqmean = ((~lqmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W (1mW)
    // Value = (Value >> 8) * (1 / resolution W) * 1000 (mW/W)
    lqmean = lqmean >> 8;   // Remove last 8 bits (all 0's)
    lqmean *= 1000;         // mW/W
    lqmean /= resolution;   // Resolution in W/Var/VA
#endif
    // Apply Scale Factor to Voltage 
    lqmean_ext = ATM90EXX_API_apply_scale_factor(lqmean, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);  /* V_SCALE_FACTOR use to be NONE (x1) */
    // Apply Scale Factor to Current 
    lqmean_ext = ATM90EXX_API_apply_scale_factor((uint32_t)lqmean_ext, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);

    *qmean = (uint32_t) lqmean_ext;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_Smean ( ATM90EXX_API_SMEAN line, uint32_t *smean )
      - ATM90E3x: Complement, Power=32-bit register value* 0.00032 W
      - ATM90E2x: Complement, MSB is the sign bit. Data format is XX.XXX, which corresponds to -32.768~+32.768kW.
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_Smean(ATM90EXX_API_SMEAN_LINE line, uint32_t *smean, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t lsmean = 0;
    uint64_t lsmean_ext = 0;
    
#ifdef ATM90E26_SUPPORT
    /* From Last Read */
    switch (line)
    {
        case METROLOGY_SMEANA:
            if ((gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean & 0x8000) == 0x8000)
            {
                lsmean = ((~gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean) + 1);
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            else
            {
                lsmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean & 0x7FFF);
                *sign = MEASURE_SIGN_POSITIVE;
            }           
            break;
        case METROLOGY_SMEANB: /* Channel 2 */
            if ((gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean2 & 0x8000) == 0x8000)
            {
                lsmean = ((~gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean2) + 1);
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            else
            {
                lsmean = (gATM90ExxDrvObj.atm90ExxObj.measInfo.Smean2 & 0x7FFF);
                *sign = MEASURE_SIGN_POSITIVE;
            }
            break;
        default:
            lsmean = 0;
            break;
    }
    // Adaptation to ATM90EXX decimal resolution ATM90EXX_PQS_ACCURACY_INT = 0.001W
    lsmean *= 1000;
#endif    
#ifdef ATM90E3X_SUPPORT
    switch (line)
    {            
        case METROLOGY_SMEANA:
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanALSB);
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanA << 16);
            break;
        case METROLOGY_SMEANB:
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanBLSB);
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanB << 16);
            break;
        case METROLOGY_SMEANC:
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanCLSB);
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SmeanC << 16);
            break;
        case METROLOGY_SAMEANT:
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SAmeanTLSB);
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SAmeanT << 16);            
            break;
#ifdef ATM90E36_SUPPORT
        case METROLOGY_SVMEANT:
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SVmeanTLSB);
            lsmean += (gATM90ExxDrvObj.atm90ExxObj.measInfo.SVmeanT << 16);            
            break;
#endif
        default:
            break;
    }
    if ((lsmean & 0x80000000) == 0x80000000)
    {
        lsmean = ((~lsmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }    
    lsmean_ext = ((uint64_t) lsmean) * 1000;
    lsmean_ext /= 3125;
    lsmean = (uint32_t) lsmean_ext;
#endif    
    // Apply Scale Factor to Voltage 
    lsmean_ext = ATM90EXX_API_apply_scale_factor(lsmean, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale);  /* V_SCALE_FACTOR use to be NONE (x1) */
    // Apply Scale Factor to Current 
    lsmean_ext = ATM90EXX_API_apply_scale_factor((uint32_t)lsmean_ext, gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);

    *smean = (uint32_t) lsmean_ext;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_Pmean ( ATM90EXX_API_POWER_LINE line, uint32_t *pfmean, METROLOGY_MEASURE_SIGN *sign )
      - ATM90Exx: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_PFmean(ATM90EXX_API_PMEAN_LINE line, uint32_t *pfmean, METROLOGY_MEASURE_SIGN *sign)
{
    uint16_t lpfmean = 0;

#ifdef ATM90E26_SUPPORT
    /* From Last Read */
    switch (line)
    {
        case METROLOGY_PMEANA:
            lpfmean = gATM90ExxDrvObj.atm90ExxObj.measInfo.PowerF;            
            break;
        case METROLOGY_PMEANB: /* Channel 2 */
            lpfmean = gATM90ExxDrvObj.atm90ExxObj.measInfo.PowerF2;
            break;
        default:
            lpfmean = 0;
            break;
    }
    if ((lpfmean & 0x8000) == 0x8000)
    {
        lpfmean = ((~lpfmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        lpfmean = (lpfmean & 0x7FFF);
        *sign = MEASURE_SIGN_POSITIVE;
    }
#endif
#ifdef ATM90E32_SUPPORT
    
    switch (line)
    {    
        case METROLOGY_PMEANA:
            lpfmean = gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanA;
            break;
        case METROLOGY_PMEANB:
            lpfmean = gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanB;
            break;
        case METROLOGY_PMEANC:
            lpfmean = gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanC;
            break;
        case METROLOGY_PMEANT:
            lpfmean = gATM90ExxDrvObj.atm90ExxObj.measInfo.PFmeanT;
            break;
        default:
            lpfmean = 0;
            break;
    }
    if ((lpfmean & 0x80000000) == 0x80000000)
    {
        lpfmean = ((~lpfmean) + 1);
        *sign = MEASURE_SIGN_NEGATIVE;
    }
    else
    {
        *sign = MEASURE_SIGN_POSITIVE;
    }
#endif    
    *pfmean = lpfmean;
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_AEnergy(ATM90EXX_API_AENERGY_TYPE type, int32_t *energy)
      - ATM90E26: 16 Bits. Data format is XXXX.X pulses. Resolution is 0.1 pulse. Maximum is 6553.5 pulses.
      - ATM90E3X: 32 Bits. Resolution is 0.01 pulse. 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_AEnergy(ATM90EXX_API_AENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t pulses;
    uint32_t CFres;
    
    /* From Last Read */
    switch (type)
    {
#ifdef ATM90E26_SUPPORT
        case METROLOGY_AENERGYA:
        // Absolute Energy Phase A
        case METROLOGY_AENERGY:
        // Absolute Energy Total
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergy >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergy)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergy;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergy;  
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergy;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergy;  
                *sign = MEASURE_SIGN_NEGATIVE;
            }           
            break;
#endif
#ifdef ATM90E3X_SUPPORT
        case METROLOGY_AENERGYA:
        // Total Energy Phase A
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyA >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyA)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyA;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyA;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyA;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyA;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AENERGYB:
        // Total Energy Phase B
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyB >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyB)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyB;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyB;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyB;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyB;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AENERGYC:
        // Total Energy Phase C
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyC >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyC)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyC;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyC;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyC;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyC;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AENERGY:
        // Total Energy
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyT >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyT)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyT;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyT;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyT;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyT;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
#endif
        default:
            pulses = 0;
            *sign = MEASURE_SIGN_POSITIVE;
            break;
    }

#ifdef ATM90E26_SUPPORT
    /* Pulses resultion 0.1CF */
    CFres = 10;
#endif
#ifdef ATM90E32_SUPPORT
    /* Pulses resolution is 0.01CF */
    CFres= 100;
#endif
#ifdef ATM90E36_SUPPORT
    /* Pulses resolution 0.1/0.01CF */
    CFres = (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode0 & MMODE0_001LSB_Msk)? 100 : 10;
#endif  
    // Energy (Kwh) = Pulses/MC(pulses/KWh)
    pulses *= (ATM90EXX_ENERGY_ACCURACY_INT / CFres);     // Move to 0.1Wh resolution
    
    // To avoid loosing some resolution move to float
    *energy = (uint32_t) (pulses/((double)gATM90ExxDrvObj.atm90ExxObj.calMetInfo.MC));
    
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_AFEnergy(ATM90EXX_API_AFENERGY_TYPE type, int32_t *energy)
      - ATM90E26: 16 Bits. Data format is XXXX.X pulses. Resolution is 0.1 pulse. Maximum is 6553.5 pulses.
      - ATM90E3X: 32 Bits. Resolution is 0.1/0.01 pulse. 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_AFEnergy(ATM90EXX_API_AFENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t pulses;
    uint32_t CFres;
    
    /* From Last Read */
    switch (type)
    {
#ifdef ATM90E3X_SUPPORT        
        case METROLOGY_AFENERGYA:
        // Total Active Fundamental Energy Phase A
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAF >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAF)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAF;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAF;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AFENERGYB:
        // Total Active Fundamental Energy Phase B
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBF >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBF)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBF;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBF;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AFENERGYC:
        // Total Active Fundamental Energy Phase C
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCF >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCF)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCF;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCF;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AFENERGY:
            // Total Active Fundamental Energy
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTF >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTF)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTF;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTF;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTF;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
#endif
        default:
            pulses = 0;
            *sign = MEASURE_SIGN_POSITIVE;
            break;
    }
    
#ifdef ATM90E26_SUPPORT
    /* Pulses resultion 0.1CF */
    CFres = 10;
#endif
#ifdef ATM90E32_SUPPORT
    /* Pulses resolution is 0.01CF */
    CFres= 100;
#endif
#ifdef ATM90E36_SUPPORT
    /* Pulses resolution 0.1/0.01CF */
    CFres = (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode0 & MMODE0_001LSB_Msk)? 100 : 10;
#endif  
    // Energy (Kwh) = Pulses/MC(pulses/KWh)
    pulses *= (ATM90EXX_ENERGY_ACCURACY_INT / CFres);     // Move to 0.1Wh resolution
    
    // To avoid loosing some resolution move to float
    *energy = (uint32_t) (pulses/((double) gATM90ExxDrvObj.atm90ExxObj.calMetInfo.MC));

    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_AHEnergy(ATM90EXX_API_AHENERGY_TYPE type, int32_t *energy)
      - ATM90E3X: 16 Bits. Resolution is 0.1/0.01 pulse. 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_AHEnergy(ATM90EXX_API_AHENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t pulses;
    uint32_t CFres;
    
    /* From Last Read */
    switch (type)
    {
#ifdef ATM90E3X_SUPPORT       
        case METROLOGY_AHENERGYA:
        // Total Active Harmonics Energy Phase A
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAH >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAH)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAH;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAH;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AHENERGYB:
        // Total Active Harmonics Energy Phase B
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBH >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBH)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBH;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBH;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AHENERGYC:
        // Total Active Harmonics Energy Phase C
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCH >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCH)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCH;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCH;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_AHENERGY:
        // Total Active Harmonics Energy Total
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTH >= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTH)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTH;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTH;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTH;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
#endif
        default:
            pulses= 0;
            *sign = MEASURE_SIGN_POSITIVE;
            break;
    }
    
#ifdef ATM90E26_SUPPORT
    /* Pulses resultion 0.1CF */
    CFres = 10;
#endif
#ifdef ATM90E32_SUPPORT
    /* Pulses resolution is 0.01CF */
    CFres= 100;
#endif
#ifdef ATM90E36_SUPPORT
    /* Pulses resolution 0.1/0.01CF */
    CFres = (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode0 & MMODE0_001LSB_Msk)? 100 : 10;
#endif  
    // Energy (Kwh) = Pulses/MC(pulses/KWh)
    pulses *= (ATM90EXX_ENERGY_ACCURACY_INT / CFres);     // Move to 0.1Wh resolution

    // To avoid loosing some resolution move to float
    *energy = (uint32_t) (pulses/ ((double)gATM90ExxDrvObj.atm90ExxObj.calMetInfo.MC));

    return ATM90EXX_API_ERROR;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_QEnergy(ATM90EXX_API_QENERGY_TYPE type, int32_t *energy)
      - ATM90E26: 16 Bits. Data format is XXXX.X pulses. Resolution is 0.1 pulse. Maximum is 6553.5 pulses.
      - ATM90E3X: 32 Bits. Resolution is 0.01 pulse. 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_QEnergy(ATM90EXX_API_QENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign)
{
    uint32_t pulses;
    uint32_t CFres;
    
    /* From Last Read */
    switch (type)
    {
#ifdef ATM90E26_SUPPORT
        case METROLOGY_QENERGYA:
        // Absolute Energy Phase A
        case METROLOGY_QENERGY:
        // Absolute Energy Total
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergy >= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergy)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergy;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergy;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergy;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergy;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
#endif
#ifdef ATM90E3X_SUPPORT
        case METROLOGY_QENERGYA:
        // Total Reactive Energy Phase A
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyA >= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyA)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyA;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyA;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyA;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyA;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_QENERGYB:
        // Total Reactive Energy Phase B
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyB >= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyB)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyB;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyB;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyB;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyB;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_QENERGYC:
        // Total Reactive Energy Phase C
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyC >= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyC)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyC;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyC;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyC;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyC;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
        case METROLOGY_QENERGY:
        // Total Reactive Energy Total
            if (gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyT >= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyT)
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyT;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyT;
                *sign = MEASURE_SIGN_POSITIVE;
            }
            else
            {
                pulses += gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyT;
                pulses -= gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyT;
                *sign = MEASURE_SIGN_NEGATIVE;
            }
            break;
#endif            
        default:
            pulses = 0;
            *sign = MEASURE_SIGN_POSITIVE;
            break;
    }
   
#ifdef ATM90E26_SUPPORT
    /* Pulses resultion 0.1CF */
    CFres = 10;
#endif
#ifdef ATM90E32_SUPPORT
    /* Pulses resolution is 0.01CF */
    CFres= 100;
#endif
#ifdef ATM90E36_SUPPORT
    /* Pulses resolution 0.1/0.01CF */
    CFres = (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode0 & MMODE0_001LSB_Msk)? 100 : 10;
#endif  
    // Energy (Kwh) = Pulses/MC(pulses/KWh)
    pulses *= (ATM90EXX_ENERGY_ACCURACY_INT / CFres);     // Move to 0.11Wh resolution
    
    *energy = (uint32_t) (pulses/((double) gATM90ExxDrvObj.atm90ExxObj.calMetInfo.MC));

    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_SEnergy(ATM90EXX_API_SENERGY_TYPE type, uint32_t *energy)
      - ATM90E26: Not Supported
      - ATM90E3X: 32 Bits. Resolution is 0.01 pulse. 
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_SEnergy(ATM90EXX_API_SENERGY_TYPE type, uint32_t *energy, METROLOGY_MEASURE_SIGN *sign)
{   
    uint32_t pulses;
    uint32_t CFres;
    
    switch (type)            
    {   
#ifdef ATM90E3X_SUPPORT  
        case ATM90EXX_SENERGYA:
        // Total Energy Phase A
            pulses  = gATM90ExxDrvObj.atm90ExxObj.metInfo.SEnergyA;
            break;
        case ATM90EXX_SENERGYB:
        // Reverse Energy Phase B
            pulses  = gATM90ExxDrvObj.atm90ExxObj.metInfo.SEnergyB;
            break;
        case ATM90EXX_SENERGYC:
        // Reverse Energy Phase C
            pulses  = gATM90ExxDrvObj.atm90ExxObj.metInfo.SEnergyC;
            break;
        case ATM90EXX_SAENERGY:
            pulses = gATM90ExxDrvObj.atm90ExxObj.metInfo.SAEnergyT;
            break;
#ifdef ATM90E36_SUPPORT              
        case ATM90EXX_SVENERGY:
        // Vectorial Sum Total Apparent Energy
            pulses = gATM90ExxDrvObj.atm90ExxObj.metInfo.SVEnergyT;
            break;
#endif
#endif             
        default:
            pulses = 0;
            *sign = MEASURE_SIGN_POSITIVE;
            break;
    }

#ifdef ATM90E26_SUPPORT  
    CFres= 10;
#endif    
#ifdef ATM90E32_SUPPORT
    /* Pulses resolution is 0.01CF */
    CFres= 100;
#endif
#ifdef ATM90E36_SUPPORT
    /* Pulses resolution 0.1/0.01CF */
    CFres = (gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode0 & MMODE0_001LSB_Msk)? 100 : 10;
#endif    
    
    // Energy (Kwh) = Pulses/MC(pulses/KWh)
    pulses *= (ATM90EXX_ENERGY_ACCURACY_INT / CFres);     // Move to 0.1Wh resolution
   
    *energy = (uint32_t) (pulses/((double)gATM90ExxDrvObj.atm90ExxObj.calMetInfo.MC));
    
    return ATM90EXX_API_SUCCESS;
}

bool ATM90EXX_API_CheckPhaseEnabled(ATM90EXX_API_VOLTAGE_LINE line)
{
#ifdef ATM90E26_SUPPORT
    if (line == ATM90EXX_VLINE_UA)
    {
        return true;
    } 
#else
    if ((line == ATM90EXX_VLINE_UA) || (line == ATM90EXX_VLINE_UB) || (line == ATM90EXX_VLINE_UC))
    {
        return true;
    }
#endif    
    return false;
}

ATM90EXX_API_RESULT ATM90EXX_API_clear_AEnergy(METROLOGY_API_AENERGY_TYPE type)
{
    /* From Last Read */
    switch (type)
    {
#ifdef ATM90E26_SUPPORT
        case METROLOGY_AENERGYA:
        // Absolute Energy Phase A
        case METROLOGY_AENERGY:
        // Absolute Energy Total
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergy = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergy = 0;
            break;
#endif
#ifdef ATM90E3X_SUPPORT
        case METROLOGY_AENERGYA:
        // Total Energy Phase A
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyA = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyA = 0;
            break;
        case METROLOGY_AENERGYB:
        // Total Energy Phase B
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyB = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyB = 0;
            break;
        case METROLOGY_AENERGYC:
        // Total Energy Phase C
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyC = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyC = 0;
            break;
        case METROLOGY_AENERGY:
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyT = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyT = 0;
            break;
#endif
        default:
            break;
    }
    return ATM90EXX_API_SUCCESS;

}

ATM90EXX_API_RESULT ATM90EXX_API_clear_AFEnergy(METROLOGY_API_AFENERGY_TYPE type)
{
#ifdef ATM90E3X_SUPPORT
    switch (type)
    {
        case METROLOGY_AFENERGYA:
        // Total Active Fundamental Energy Phase A
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAF = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAF = 0;
            break;
        case METROLOGY_AFENERGYB:
        // Total Active Fundamental Energy Phase B
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBF = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBF = 0;
            break;
        case METROLOGY_AFENERGYC:
        // Total Active Fundamental Energy Phase C
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCF = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCF = 0;
            break;
        case METROLOGY_AFENERGY:
        // Total Active Fundamental Energy Total
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTF = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTF = 0;
            break;
        default:
            break;
    }
    return ATM90EXX_API_SUCCESS;
#endif
    return ATM90EXX_API_ERROR;
}

ATM90EXX_API_RESULT ATM90EXX_API_clear_AHEnergy(METROLOGY_API_AHENERGY_TYPE type)
{
#ifdef ATM90E3X_SUPPORT
    switch (type)
    {
        case METROLOGY_AHENERGYA:
        // Total Active Harmonics Energy Phase A
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyAH = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyAH = 0;
            break;
        case METROLOGY_AHENERGYB:
        // Total Active Harmonics Energy Phase B
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyBH = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyBH = 0;
            break;
        case METROLOGY_AHENERGYC:
        // Total Active Harmonics Energy Phase C
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyCH = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyCH = 0;
            break;
        case METROLOGY_AHENERGY:
        // Total Active Harmonics Energy Total
            gATM90ExxDrvObj.atm90ExxObj.metInfo.APEnergyTH = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.ANEnergyTH = 0;
            break;
        default:
            break;
    }
    return ATM90EXX_API_SUCCESS;
#endif
    return ATM90EXX_API_ERROR;
}

ATM90EXX_API_RESULT ATM90EXX_API_clear_QEnergy(METROLOGY_API_QENERGY_TYPE type)
{
    /* From Last Read */
    switch (type)
    {
#ifdef ATM90E26_SUPPORT
        case METROLOGY_QENERGYA:
        // Absolute Energy Phase A
        case METROLOGY_QENERGY:
        // Absolute Energy Total
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergy = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergy = 0;
            break;
#endif
#ifdef ATM90E3X_SUPPORT
        case METROLOGY_QENERGYA:
        // Total Reactive Energy Phase A
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyA = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyA = 0;
            break;
        case METROLOGY_QENERGYB:
        // Total Reactive Energy Phase B
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyB = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyB = 0;
            break;
        case METROLOGY_QENERGYC:
        // Total Reactive Energy Phase C
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyC = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyC = 0;
            break;
        case METROLOGY_QENERGY:
        // Total Reactive Energy Total
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RPEnergyT = 0;
            gATM90ExxDrvObj.atm90ExxObj.metInfo.RNEnergyT = 0;
            break;
#endif            
        default:
            break;
    }
    return ATM90EXX_API_SUCCESS;
}

ATM90EXX_API_RESULT ATM90EXX_API_clear_SEnergy(METROLOGY_API_SENERGY_TYPE type)
{
#ifdef ATM90E3X_SUPPORT  
    switch (type)
    {   case ATM90EXX_SENERGYA:
        // Total Energy Phase A
            gATM90ExxDrvObj.atm90ExxObj.metInfo.SEnergyA = 0;
            break;
        case ATM90EXX_SENERGYB:
        // Reverse Energy Phase B
            gATM90ExxDrvObj.atm90ExxObj.metInfo.SEnergyB = 0;
            break;
        case ATM90EXX_SENERGYC:
        // Reverse Energy Phase C
            gATM90ExxDrvObj.atm90ExxObj.metInfo.SEnergyC = 0;
            break;
        case ATM90EXX_SAENERGY:
            gATM90ExxDrvObj.atm90ExxObj.metInfo.SAEnergyT = 0;
            break;
#ifdef ATM90E36_SUPPORT              
        case ATM90EXX_SVENERGY:
            // Vectorial Sum Total Apparent Energy
            gATM90ExxDrvObj.atm90ExxObj.metInfo.SVEnergyT = 0;
            break;
#endif           
        default:
            break;
    } 
#endif
    return ATM90EXX_API_SUCCESS;
}

/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT lATM90EXX_API_get_frequency ( uint32_t *freq )
      - freq: Converted frequency to (uQ0.32)
  Remarks:
    Same format on all ATM90EXX
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_frequency(uint16_t *freq)
{
  /* From Last Read */
  *freq = gATM90ExxDrvObj.atm90ExxObj.measInfo.Freq;
  return ATM90EXX_API_SUCCESS;
}

#ifdef ATM90E3X_SUPPORT
/*******************************************************************************
  Function:
    ATM90EXX_API_RESULT ATM90EXX_API_get_temp ( uint32_t *temp, METROLOGY_MEASURE_SIGN *sign )
      - temp: Converted Temperature to (uQ0.32)
  Remarks:
    Same format on all ATM90EXX
    1LSB corresponds to 1�C Signed, MSB as the sign bit
 */
ATM90EXX_API_RESULT ATM90EXX_API_get_temp(uint16_t *temp, METROLOGY_MEASURE_SIGN *sign)
{
  /* From Last Read */
  if ((gATM90ExxDrvObj.atm90ExxObj.measInfo.Temp & 0x8000) & 0x8000)
  {
    *temp = ((~gATM90ExxDrvObj.atm90ExxObj.measInfo.Temp) + 1);
    *sign = MEASURE_SIGN_NEGATIVE;
  }else
  {
    *temp = gATM90ExxDrvObj.atm90ExxObj.measInfo.Temp;
    *sign = MEASURE_SIGN_POSITIVE;
  }
  return ATM90EXX_API_SUCCESS;
}
#endif

#ifdef ATM90E26_SUPPORT
/*******************************************************************************
  Function:
    ATM90E26_API_RESULT ATM90EXX_API_get_active_line (void )
      - Returns active line
  Remarks:

 */
ATM90EXX_API_CURRENT_LINE ATM90E26_API_get_active_cline(void)
{
  uint8_t lnmode;
  ATM90EXX_API_CURRENT_LINE cline = ATM90EXX_CLINE_IA;

  lnmode = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus & ENSTATUS_LNMODE_Msk) >> ENSTATUS_LNMODE_Pos);
  /* Check PIN configuration */
  switch (lnmode)
  {
    case ENSTATUS_LNMODE_ANTITMP_Val:
      cline = ((gATM90ExxDrvObj.atm90ExxObj.statusInfo.EnStatus & ENSTATUS_LLINE_Msk) >> ENSTATUS_LLINE_Pos) ? ATM90EXX_CLINE_IA : ATM90EXX_CLINE_IN;
      break;
    case ENSTATUS_LNMODE_FLEX_Val:
      cline = ((gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.MMode & MMODE_LNSEL_Msk) >> MMODE_LNSEL_Pos) ? ATM90EXX_CLINE_IA : ATM90EXX_CLINE_IN;
      break;
    case ENSTATUS_LNMODE_LLINE_Val:
      cline = ATM90EXX_CLINE_IA;
      break;
    case ENSTATUS_LNMODE_LN_Val:
      /* Both Currents contribute - 1P3W Configuration */
      cline = ATM90EXX_CLINE_IA | ATM90EXX_CLINE_IB;
      break;
  }
  return cline;
}

uint16_t ATM90E26_API_get_powermode(void)
{
    return gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.SmallPMod;
}

ATM90EXX_API_RESULT ATM90E26_API_set_powermode(uint16_t mode)
{
    // Direct access to the register is allowed on this case
    if (ATM90EXX_DRV_write_reg(SMALLPMOD_ADDR, mode) == ATM90EXX_API_SUCCESS)
    { 
        gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.SmallPMod = mode;
        return ATM90EXX_API_SUCCESS;
    }  
    return ATM90EXX_API_ERROR;
}
#endif

ATM90EXX_API_RESULT  ATM90EXX_API_SetConfiguration(ATM90EXX_CONF * config)
{
    ATM90EXX_DRV_Reconfigure(config);
    return ATM90EXX_API_SUCCESS;
}

ATM90EXX_API_RESULT  ATM90EXX_API_SetConfigurationByDefault()
{
    ATM90EXX_DRV_Init_DefaultConfig(&gATM90ExxDrvObj.atm90ExxObjConf);
    ATM90EXX_DRV_Reconfigure(&gATM90ExxDrvObj.atm90ExxObjConf);
    return ATM90EXX_API_SUCCESS;
}

ATM90EXX_API_RESULT ATM90EXX_API_GetConfigurationByDefault(ATM90EXX_CONF * config)
{
    ATM90EXX_DRV_Init_DefaultConfig(config);
    return ATM90EXX_API_SUCCESS;
}

// *****************************************************************************
// *****************************************************************************
// Section: Metrology API Global Functions
// *****************************************************************************
// *****************************************************************************

ATM90EXX_API_RESULT ATM90EXX_API_SetBasicConfiguration(METROLOGY_BASIC_CONF * config)
{
    ATM90EXX_CONF dfltConfig;
    uint32_t PLconstant = 0;
    uint64_t PLconstant_ext = 0;

    // Get Default Configuration
    ATM90EXX_API_GetConfigurationByDefault(&dfltConfig);
    
    gATM90ExxDrvObj.atm90ExxObj.calMetInfo.MC = config->mc;
    gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale = config->UScale;
    gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale = config->IScale;

#ifdef ATM90E3X_SUPPORT
    /* Update ATM90E3X parameters */
    if (config->freq == 60 )
    {
      dfltConfig.ctrlInfo.MMode0 |= MMODE0_FREQ60HZ_Msk;
    }
    if (config->st == SENSOR_ROGOWSKI)
    {
      dfltConfig.ctrlInfo.MMode0 |= MMODE0_DIDTEN_Msk;
    }
    if (config->PGA_Igain == GAIN_2)
    {
      dfltConfig.ctrlInfo.MMode1 |= MMODE1_PGA_GAIN_I1(MMODE1_PGA_GAIN_2_Val);
      dfltConfig.ctrlInfo.MMode1 |= MMODE1_PGA_GAIN_I2(MMODE1_PGA_GAIN_2_Val);
      dfltConfig.ctrlInfo.MMode1 |= MMODE1_PGA_GAIN_I3(MMODE1_PGA_GAIN_2_Val);
    } 
    else if (config->PGA_Igain == GAIN_4)
    {
      dfltConfig.ctrlInfo.MMode1 |= MMODE1_PGA_GAIN_I1(MMODE1_PGA_GAIN_4_Val);
      dfltConfig.ctrlInfo.MMode1 |= MMODE1_PGA_GAIN_I2(MMODE1_PGA_GAIN_4_Val);
      dfltConfig.ctrlInfo.MMode1 |= MMODE1_PGA_GAIN_I3(MMODE1_PGA_GAIN_4_Val);
    }
    
    PLconstant_ext  = 450000000000 ;
    PLconstant_ext /= (config->mc * gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.UScale * gATM90ExxDrvObj.atm90ExxObj.ctrlInfo.IScale);
#else
    // Update ATM90E2X Parameters
    if (config->PGA_Igain == GAIN_4)
    {
      dfltConfig.ctrlInfo.MMode &= (~MMODE_LGAIN_Msk);
      dfltConfig.ctrlInfo.MMode |= MMODE_LGAIN_(MMODE_LGAIN_4_Val);
    } 
    else if (config->PGA_Igain == GAIN_8)
    {
      dfltConfig.ctrlInfo.MMode &= (~MMODE_LGAIN_Msk);
      dfltConfig.ctrlInfo.MMode |= MMODE_LGAIN_(MMODE_LGAIN_8_Val);
    }
    else if (config->PGA_Igain == GAIN_16)
    {
      dfltConfig.ctrlInfo.MMode &= (~MMODE_LGAIN_Msk);
      dfltConfig.ctrlInfo.MMode |= MMODE_LGAIN_(MMODE_LGAIN_16_Val);
    }
    else if (config->PGA_Igain == GAIN_24)
    {
      dfltConfig.ctrlInfo.MMode &= (~MMODE_LGAIN_Msk);
      dfltConfig.ctrlInfo.MMode |= MMODE_LGAIN_(MMODE_LGAIN_24_Val);
    }

    /* PLconstant = int(838860800 * Gl * Vu * Vl / MC * Un * Ib)*/
    /* Uratio = Un(V)/Vu(mv) = ku (kOhms) */
    /* Ib(A)/Vl(mv) = Depends on the SENSOR TYPE */
    if (config->st == SENSOR_CT)
    {
        /* Iratio = Ib(A)/Vl(mv) = tr / ( Rburden(mOhms) * 2 ) */
        PLconstant_ext  = (uint64_t) (838860800 * config->PGA_Igain * (config->rl << 1));
        PLconstant_ext /= ( config->mc * config->ku * config->tr );
    }
    else if (config->st == SENSOR_ROGOWSKI)
    {
        /* Ib(A)/Vl(mv) = 1000 / RogowskyRatio (uV/A) */
        PLconstant_ext  = (uint64_t) (838860800 * config->PGA_Igain * config->tr);
        PLconstant_ext /= ( config->mc * config->ku * 1000);
    }
    else if (config->st == SENSOR_SHUNT)
    {
        /* Ib(A)/Vl(mv) = 1 / Rshunt(mOhms) */
        PLconstant_ext  = (uint64_t) (838860800 * config->PGA_Igain * config->rl);
        PLconstant_ext /= ( config->mc * config->ku );
    }
#endif
    PLconstant = ( uint32_t ) PLconstant_ext;
    /* According with Datasheet: 
       It is suggested to set PL_constant as a multiple of 4 so as to double or 
       redouble Meter Constant in low current state to save verification time. */
    dfltConfig.calMetInfo.PLconstL = (uint16_t) (PLconstant & 0x0000FFFC);
    dfltConfig.calMetInfo.PLconstH = (uint16_t) ((PLconstant >> 16) & 0x0000FFFF);
    
    ATM90EXX_DRV_Reconfigure(&dfltConfig);
    return ATM90EXX_API_SUCCESS;
}


bool ATM90EXX_API_get_regInfo(uint16_t index, uint16_t *reg_addr, uint16_t *reg_value, char *reg_name)
{
    uint16_t *addr = (uint16_t *)(&gATM90ExxDrvObj.atm90ExxObj);
    
    //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[API][REGINFO][%d], size=%d, addr=%p\r\n", index, (sizeof(ATM90EXX_REGS) >> 1), addr);
    
    if (index < (sizeof(ATM90EXX_REGS) >> 1))
    {
        *reg_addr = atm90exxRegsInfo[index].addr;
        *reg_value = *(addr + index);
        strncpy(reg_name,&atm90exxRegsInfo[index].name[0],10);
        //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[API][REGINFO] addr:0x%04X value:0x%04X str=%s\r\n", *reg_addr, *reg_value, reg_name);
        return true;
    }
    return false;
}

ATM90EXX_CONF * ATM90EXX_API_GetConfigData(void)
{
    return &gATM90ExxDrvObj.atm90ExxObjConf;
}

// *****************************************************************************
// *****************************************************************************
// Section: Metrology Local Functions
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
 End of File
 */
