/*
Copyright (C) 2025, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "definitions.h"
#include "atm90e26_regs.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

const ATM90EXX_REG_INFO CACHE_ALIGN atm90exxRegsInfo[] = {   
    // Default Value                    , Register Address  , Refresh Flas Config  , Register Name
    // ATM90EXX_REGS_CONTROL
    { 0x0000 /* SCALE_FACTOR_1   - 1*/  , INVALID_ADDR      , CONFIG_FLAG_ALL      , "USCALE   " },
    { 0x0000 /* SCALE_FACTOR_1   - 1*/  , INVALID_ADDR      , CONFIG_FLAG_ALL      , "ISCALE   " },
    { ATM90EXX_METERING_MODE_ANTI_TAMPER, INVALID_ADDR      , CONFIG_FLAG_ALL      , "MMDX     " },
    { ATM90EXX_METERING_MODE_ANTI_TAMPER, INVALID_ADDR      , CONFIG_FLAG_ALL      , "MMDX     " },
    { SOFTRESET_DEFAULT_Val             , SOFTRESET_ADDR    , CONFIG_FLAG_ALL      , "SOFTRST  " },
    { FUNCEN_DEFAULT_Val                , FUNCEN_ADDR       , CONFIG_FLAG_NONE     , "FUNCEN   " },
    { SMALLPMOD_DEFAULT_Val             , SMALLPMOD_ADDR    , CONFIG_FLAG_NONE     , "SMALLPMOD" },
    { 0x7422                            , MMODE_ADDR        , CONFIG_FLAG_CALSTART , "MMODE    " },
    { 0x1E74                            , CS1_ADDR          , CONFIG_FLAG_NONE     , "CS1      " },
    { 0xDBC1                            , CS2_ADDR          , CONFIG_FLAG_NONE     , "CS2      " },
    { 0x0000                            , LASTSPIDATA_ADDR  , CONFIG_FLAG_NONE     , "LASTDATA " },
    // ATM90EXX_REGS_THRESHOLDS
    { SAGTH_DEFAULT_Val                 , SAGTH_ADDR        , CONFIG_FLAG_NONE     , "SAGTH    " },
    { PSTARTTH_DEFAULT_Val              , PSTARTTH_ADDR     , CONFIG_FLAG_CALSTART , "PSTARTTH " },
    { PNOLTH_DEFAULT_Val                , PNOLTH_ADDR       , CONFIG_FLAG_CALSTART , "PNOLTH   " },
    { QSTARTTH_DEFAULT_Val              , QSTARTTH_ADDR     , CONFIG_FLAG_CALSTART , "QSTARTTH " },
    { QNOLTH_DEFAULT_Val                , QNOLTH_ADDR       , CONFIG_FLAG_CALSTART , "QNOLTH   " },
    // ATM90EXX_REGS_CAL_MEAS
    { 0x67D6                            , UGAIN_ADDR        , CONFIG_FLAG_ADJSTART , "UGAIN    " },
    { 0x55F8                            , IGAINL_ADDR       , CONFIG_FLAG_ADJSTART , "IGAINL   " },
    { 0x3FF8                            , IGAINN_ADDR       , CONFIG_FLAG_ADJSTART , "IGAINN   " },
    { UOFFSET_DEFAULT_Val               , UOFFSET_ADDR      , CONFIG_FLAG_ADJSTART , "UOFFSET  " },
    { IOFFSETL_DEFAULT_Val              , IOFFSETL_ADDR     , CONFIG_FLAG_ADJSTART , "IOFFSETL " },
    { IOFFSETN_DEFAULT_Val              , IOFFSETN_ADDR     , CONFIG_FLAG_ADJSTART , "IOFFSETN " },
    { POFFSETL_DEFAULT_Val              , POFFSETL_ADDR     , CONFIG_FLAG_ADJSTART , "POFFSETL " },
    { QOFFSETL_DEFAULT_Val              , QOFFSETL_ADDR     , CONFIG_FLAG_ADJSTART , "QOFFSETL " },
    { POFFSETN_DEFAULT_Val              , POFFSETN_ADDR     , CONFIG_FLAG_ADJSTART , "POFFSETN " },
    { QOFFSETN_DEFAULT_Val              , QOFFSETN_ADDR     , CONFIG_FLAG_ADJSTART , "QOFFSETN " },    
    // ATM90EXX_REGS_CAL_MET
    { 3200                              , INVALID_ADDR      , CONFIG_FLAG_CALSTART , "METER C  " },
    { PLCONSTH_DEFAULT_Val              , PLCONSTH_ADDR     , CONFIG_FLAG_CALSTART , "PLCONSTH " },
    { PLCONSTL_DEFAULT_Val              , PLCONSTL_ADDR     , CONFIG_FLAG_CALSTART , "PLCONSTL " },
    { LGAIN_DEFAULT_Val                 , LGAIN_ADDR        , CONFIG_FLAG_CALSTART , "LGAIN    " },
    { LPHI_DEFAULT_Val                  , LPHI_ADDR         , CONFIG_FLAG_CALSTART , "LPHI     " },
    { NGAIN_DEFAULT_Val                 , NGAIN_ADDR        , CONFIG_FLAG_CALSTART , "NGAIN    " },
    { NGAIN_DEFAULT_Val                 , NPHI_ADDR         , CONFIG_FLAG_CALSTART , "NPHI     " },
    // ATM90EXX_REGS_STATUS
    { SYSSTATUS_DEFAULT_Val             , SYSSTATUS_ADDR    , CONFIG_FLAG_NONE     , "SYSSTATUS" },
    { ENSTATUS_DEFAULT_Val              , ENSTATUS_ADDR     , CONFIG_FLAG_NONE     , "ENSTATUS " }, 
    // ATM90EXX_REGS_MEAS   
    { IRMS_DEFAULT_Val                  , IRMS_ADDR         , CONFIG_FLAG_NONE     , "IRMS     " },
    { URMS_DEFAULT_Val                  , URMS_ADDR         , CONFIG_FLAG_NONE     , "URMS     " },
    { PMEAN_DEFAULT_Val                 , PMEAN_ADDR        , CONFIG_FLAG_NONE     , "PMEAN    " },
    { QMEAN_DEFAULT_Val                 , QMEAN_ADDR        , CONFIG_FLAG_NONE     , "QMEAN    " },
    { SMEAN_DEFAULT_Val                 , SMEAN_ADDR        , CONFIG_FLAG_NONE     , "SMEAN    " },
    { POWERF_DEFAULT_Val                , POWERF_ADDR       , CONFIG_FLAG_NONE     , "POWERF   " },
    { PANGLE_DEFAULT_Val                , PANGLE_ADDR       , CONFIG_FLAG_NONE     , "PANGLE   " },
    { IRMS2_DEFAULT_Val                 , IRMS2_ADDR        , CONFIG_FLAG_NONE     , "IRMS2    " },
    { PMEAN2_DEFAULT_Val                , PMEAN2_ADDR       , CONFIG_FLAG_NONE     , "PMEAN2   " },
    { QMEAN2_DEFAULT_Val                , QMEAN2_ADDR       , CONFIG_FLAG_NONE     , "QMEAN2   " },
    { POWERF2_DEFAULT_Val               , POWERF2_ADDR      , CONFIG_FLAG_NONE     , "POWERF2  " },
    { PANGLE2_DEFAULT_Val               , PANGLE2_ADDR      , CONFIG_FLAG_NONE     , "PANGLE2  " },
    { SMEAN2_DEFAULT_Val                , SMEAN2_ADDR       , CONFIG_FLAG_NONE     , "SMEAN2   " },
    { FREQ_DEFAULT_Val                  , FREQ_ADDR         , CONFIG_FLAG_NONE     , "FREQ     " },
    { IRMS_DEFAULT_Val                  , INVALID_ADDR      , CONFIG_FLAG_NONE     , "IRMSLSB  " },
    { URMS_DEFAULT_Val                  , INVALID_ADDR      , CONFIG_FLAG_NONE     , "URMSLSB  " },
    { PMEAN_DEFAULT_Val                 , INVALID_ADDR      , CONFIG_FLAG_NONE     , "PMEANLSB " },
    { QMEAN_DEFAULT_Val                 , INVALID_ADDR      , CONFIG_FLAG_NONE     , "QMEANLSB " },
    { SMEAN_DEFAULT_Val                 , INVALID_ADDR      , CONFIG_FLAG_NONE     , "SMEANLSB " },
    { IRMS2_DEFAULT_Val                 , INVALID_ADDR      , CONFIG_FLAG_NONE     , "IRMS2LSB " },
    { PMEAN2_DEFAULT_Val                , INVALID_ADDR      , CONFIG_FLAG_NONE     , "PMEAN2LSB" },
    { QMEAN2_DEFAULT_Val                , INVALID_ADDR      , CONFIG_FLAG_NONE     , "QMEAN2LSB" },
    { SMEAN2_DEFAULT_Val                , INVALID_ADDR      , CONFIG_FLAG_NONE     , "SMEAN2LSB" },
    // ATM90EXX_REGS_MET
    { APENERGY_DEFAULT_Val              , INVALID_ADDR      , CONFIG_FLAG_NONE     , "APENERGY " },
    { ANENERGY_DEFAULT_Val              , INVALID_ADDR      , CONFIG_FLAG_NONE     , "ANENERGY " },
    { ATENERGY_DEFAULT_Val              , INVALID_ADDR      , CONFIG_FLAG_NONE     , "ATENERGY " },
    { RPENERGY_DEFAULT_Val              , INVALID_ADDR      , CONFIG_FLAG_NONE     , "RPENERGY " },
    { RNENERGY_DEFAULT_Val              , INVALID_ADDR      , CONFIG_FLAG_NONE     , "RNENERGY " },
    { RTENERGY_DEFAULT_Val              , INVALID_ADDR      , CONFIG_FLAG_NONE     , "RTENERGY " },
};
