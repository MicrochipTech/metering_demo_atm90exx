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

#ifndef ATM90E32_REGS_H
#define ATM90E32_REGS_H

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR METROLOGY REGISTERS                          */
/* ************************************************************************** */
/* MISRA C-2012 deviation block start */
/* MISRA C-2012 Rule 5.4 deviated 64 times.  Deviation record ID - H3_MISRAC_2012_R_5_4_DR_1 */

/* ************************************************************************** */
/*   MEASUREMENT REGISTER                                                     */
/* ************************************************************************** */

/* -------- Meter Enable : (Meter Enable Offset: 0x00) (W - 16 bits) ATM90E32 Metering Enable Register -------- */
#define METEREN_Pos                                     _UINT16_(0)                                   /* (METEREN) Metering Enable Position */
#define METEREN_Msk                                     (_UINT16_(0xFFFF) << METEREN_Pos)             /* (METEREN) Metering Enable Mask */
#define METEREN(value)                                  (METEREN_Msk & (_UINT16_(value) << METEREN_Pos))
#define METEREN_EN_Val                                  _UINT16_(0xFF)                                /* (METEREN) Enable Metering */
#define METEREN_DIS_Val                                 _UINT16_(0x00)                                /* (METEREN) Disable Metering */
#define METEREN_DIS_Val                                 _UINT16_(0x00)                                /* (METEREN) Disable Metering */
#define METEREN_DEFAULT_Val                             _UINT16_(0x00)

/* -------- CHANNELMAPI : (CHANNELMAPI Offset: 0x01) (R/W - 16 bits) ATM90E32 Current Channel Mapping Configuration -------- */
#define CHANNELMAPI_IA_SRC_Pos                          _UINT16_(0)                                   /* (CHANNELMAPI) ADC Input source for phase A current channel Position */
#define CHANNELMAPI_IA_SRC_Msk                          (_UINT16_(0x7) << CHANNELMAPI_IA_SRC_Pos)     /* (CHANNELMAPI) ADC Input source for phase A current channel Mask */
#define CHANNELMAPI_IA_SRC_(value)                      (CHANNELMAPI_IA_SRC_Msk & (_UINT16_(value) << CHANNELMAPI_IA_SRC_Pos))
#define   CHANNELMAPI_IA_SRC_I0_Val                     _UINT16_(0x0)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel I0 (default) */
#define   CHANNELMAPI_IA_SRC_I1_Val                     _UINT16_(0x1)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel I1 */
#define   CHANNELMAPI_IA_SRC_I2_Val                     _UINT16_(0x2)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel I2 */
#define   CHANNELMAPI_IA_SRC_FIXED0_Val                 _UINT16_(0x3)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel Fixed0 */
#define   CHANNELMAPI_IA_SRC_U0_Val                     _UINT16_(0x4)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel U0 */
#define   CHANNELMAPI_IA_SRC_U1_Val                     _UINT16_(0x5)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel U1 */
#define   CHANNELMAPI_IA_SRC_U2_Val                     _UINT16_(0x6)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel U2 */
//#define   CHANNELMAPI_IA_SRC_FIXED0_Val                 _UINT16_(0x7)                                 /* (CHANNELMAPI) ADC Input source for phase A current channel Fixed0 */
#define CHANNELMAPI_IB_SRC_Pos                          _UINT16_(4)                                   /* (CHANNELMAPI) ADC Input source for phase B current channel Position */
#define CHANNELMAPI_IB_SRC_Msk                          (_UINT16_(0x7) << CHANNELMAPI_IB_SRC_Pos)     /* (CHANNELMAPI) ADC Input source for phase B current channel Mask */
#define CHANNELMAPI_IB_SRC_(value)                      (CHANNELMAPI_IB_SRC_Msk & (_UINT16_(value) << CHANNELMAPI_IB_SRC_Pos))
#define   CHANNELMAPI_IB_SRC_I0_Val                     _UINT16_(0x0)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel I0 (default) */
#define   CHANNELMAPI_IB_SRC_I1_Val                     _UINT16_(0x1)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel I1 */
#define   CHANNELMAPI_IB_SRC_I2_Val                     _UINT16_(0x2)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel I2 */
#define   CHANNELMAPI_IB_SRC_FIXED0_Val                 _UINT16_(0x3)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel Fixed0 */
#define   CHANNELMAPI_IB_SRC_U0_Val                     _UINT16_(0x4)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel U0 */
#define   CHANNELMAPI_IB_SRC_U1_Val                     _UINT16_(0x5)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel U1 */
#define   CHANNELMAPI_IB_SRC_U2_Val                     _UINT16_(0x6)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel U2 */
//#define   CHANNELMAPI_IB_SRC_FIXED0_Val                 _UINT16_(0x7)                                 /* (CHANNELMAPI) ADC Input source for phase B current channel Fixed0 */
#define CHANNELMAPI_IC_SRC_Pos                          _UINT16_(8)                                   /* (CHANNELMAPI) ADC Input source for phase C current channel Position */
#define CHANNELMAPI_IC_SRC_Msk                          (_UINT16_(0x7) << CHANNELMAPI_IC_SRC_Pos)     /* (CHANNELMAPI) ADC Input source for phase B current channel Mask */
#define CHANNELMAPI_IC_SRC_(value)                      (CHANNELMAPI_IC_SRC_Msk & (_UINT16_(value) << CHANNELMAPI_IC_SRC_Pos))
#define   CHANNELMAPI_IC_SRC_I0_Val                     _UINT16_(0x0)                                 /* (CHANNELMAPI) ADC Input source for phase C current channel I0 (default) */
#define   CHANNELMAPI_IC_SRC_I1_Val                     _UINT16_(0x1)                                 /* (CHANNELMAPI) ADC Input source for phase C current channel I1 */
#define   CHANNELMAPI_IC_SRC_I2_Val                     _UINT16_(0x2)                                 /* (CHANNELMAPI) ADC Input source for phase C current channel I2 */
#define   CHANNELMAPI_IC_SRC_FIXED0_Val                 _UINT16_(0x3)                                 /* (CHANNELMAPI) ADC Input source for phase C current channel Fixed0 */
#define   CHANNELMAPI_IC_SRC_U0_Val                     _UINT16_(0x4)                                 /* (CHANNELMAPI) ADC Input source for phase C current channel U0 */
#define   CHANNELMAPI_IC_SRC_U1_Val                     _UINT16_(0x5)                                 /* (CHANNELMAPI) ADC Input source for phase C current channel U1 */
#define   CHANNELMAPI_IC_SRC_U2_Val                     _UINT16_(0x6)                                 /* (CHANNELMAPI) ADC Input source for phase C current channel U2 */
//#define   CHANNELMAPI_IC_SRC_FIXED0_Val                 _UINT16_(0x7)                               /* (CHANNELMAPI) ADC Input source for phase C current channel Fixed0 */
#define   CHANNELMAPI_DEFAULT_Val                       _UINT16_(0x0210)                              /* (CHANNELMAPI) Default Register Value */

/* -------- CHANNELMAPU : (CHANNELMAPU Offset: 0x02) (R/W - 16 bits) ATM90E32 Voltage Channel Mapping Configuration -------- */
#define CHANNELMAPU_UA_SRC_Pos                          _UINT16_(0)                                   /* (CHANNELMAPU) ADC Input source for phase A current channel Position */
#define CHANNELMAPU_UA_SRC_Msk                          (_UINT16_(0x7) << CHANNELMAPU_UA_SRC_Pos)     /* (CHANNELMAPU) ADC Input source for phase A current channel Mask */
#define CHANNELMAPU_UA_SRC_(value)                      (CHANNELMAPU_UA_SRC_Msk & (_UINT16_(value) << CHANNELMAPU_UA_SRC_Pos))
#define   CHANNELMAPU_UA_SRC_I0_Val                     _UINT16_(0x0)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel I0 (default) */
#define   CHANNELMAPU_UA_SRC_I1_Val                     _UINT16_(0x1)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel I1 */
#define   CHANNELMAPU_UA_SRC_I2_Val                     _UINT16_(0x2)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel I2 */
#define   CHANNELMAPU_UA_SRC_FIXED0_Val                 _UINT16_(0x3)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel Fixed0 */
#define   CHANNELMAPU_UA_SRC_U0_Val                     _UINT16_(0x4)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel U0 */
#define   CHANNELMAPU_UA_SRC_U1_Val                     _UINT16_(0x5)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel U1 */
#define   CHANNELMAPU_UA_SRC_U2_Val                     _UINT16_(0x6)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel U2 */
//#define   CHANNELMAPU_UA_SRC_FIXED0_Val                 _UINT16_(0x7)                                 /* (CHANNELMAPU) ADC Input source for phase A voltage channel Fixed0 */
#define CHANNELMAPU_UB_SRC_Pos                          _UINT16_(4)                                   /* (CHANNELMAPU) ADC Input source for phase B voltage channel Position */
#define CHANNELMAPU_UB_SRC_Msk                          (_UINT16_(0x7) << CHANNELMAPU_UB_SRC_Pos)     /* (CHANNELMAPU) ADC Input source for phase B voltage channel Mask */
#define CHANNELMAPU_UB_SRC_(value)                      (CHANNELMAPU_UB_SRC_Msk & (_UINT16_(value) << CHANNELMAPU_UB_SRC_Pos))
#define   CHANNELMAPU_UB_SRC_I0_Val                     _UINT16_(0x0)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel I0 (default) */
#define   CHANNELMAPU_UB_SRC_I1_Val                     _UINT16_(0x1)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel I1 */
#define   CHANNELMAPU_UB_SRC_I2_Val                     _UINT16_(0x2)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel I2 */
#define   CHANNELMAPU_UB_SRC_FIXED0_Val                 _UINT16_(0x3)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel Fixed0 */
#define   CHANNELMAPU_UB_SRC_U0_Val                     _UINT16_(0x4)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel U0 */
#define   CHANNELMAPU_UB_SRC_U1_Val                     _UINT16_(0x5)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel U1 */
#define   CHANNELMAPU_UB_SRC_U2_Val                     _UINT16_(0x6)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel U2 */
//#define   CHANNELMAPU_UB_SRC_FIXED0_Val                 _UINT16_(0x7)                                 /* (CHANNELMAPU) ADC Input source for phase B voltage channel Fixed0 */
#define CHANNELMAPU_UC_SRC_Pos                          _UINT16_(8)                                   /* (CHANNELMAPU) ADC Input source for phase C voltage channel Position */
#define CHANNELMAPU_UC_SRC_Msk                          (_UINT16_(0x7) << CHANNELMAPI_IC_SRC_Pos)     /* (CHANNELMAPU) ADC Input source for phase C voltage channel Mask */
#define CHANNELMAPU_UC_SRC_(value)                      (CHANNELMAPU_UC_SRC_Msk & (_UINT16_(value) << CHANNELMAPU_UC_SRC_Pos))
#define   CHANNELMAPU_UC_SRC_I0_Val                     _UINT16_(0x0)                                 /* (CHANNELMAPU) ADC Input source for phase C voltage channel I0 (default) */
#define   CHANNELMAPU_UC_SRC_I1_Val                     _UINT16_(0x1)                                 /* (CHANNELMAPU) ADC Input source for phase C voltage channel I1 */
#define   CHANNELMAPU_UC_SRC_I2_Val                     _UINT16_(0x2)                                 /* (CHANNELMAPU) ADC Input source for phase C voltage channel I2 */
#define   CHANNELMAPU_UC_SRC_FIXED0_Val                 _UINT16_(0x3)                                 /* (CHANNELMAPU) ADC Input source for phase C voltage channel Fixed0 */
#define   CHANNELMAPU_UC_SRC_U0_Val                     _UINT16_(0x4)                                 /* (CHANNELMAPU) ADC Input source for phase C voltage channel U0 */
#define   CHANNELMAPU_UC_SRC_U1_Val                     _UINT16_(0x5)                                 /* (CHANNELMAPU) ADC Input source for phase C voltage channel U1 */
#define   CHANNELMAPU_UC_SRC_U2_Val                     _UINT16_(0x6)                                 /* (CHANNELMAPU) ADC Input source for phase C voltage channel U2 */
//#define   CHANNELMAPU_UC_SRC_FIXED0_Val                 _UINT16_(0x7)                               /* (CHANNELMAPU) ADC Input source for phase C voltage channel Fixed0 */
#define   CHANNELMAPU_DEFAULT_Val                       _UINT16_(0x0654)                              /* (CHANNELMAPI) Default Register Value */

/* -------- SAGPEAKDETCFG : (SAGPEAKDETCFG Offset: 0x05) (R/W - 16 bits) Sag and Peak Detector Period Configuration -------- */
#define SAGPEAKDETCFG_SAG_PERIOD_Pos                    _UINT16_(0)                                      /* (SAGPEAKDETCFG_SAG_PERIOD) Period below the SagTh before to assert the Sag. Unit is ms. Position */
#define SAGPEAKDETCFG_SAG_PERIOD_Msk                    (_UINT16_(0xFF) << SAGPEAKDETCFG_SAG_PERIOD_Pos) /* (SAGPEAKDETCFG_SAG_PERIOD) Period below the SagTh before to assert the Sag. Unit is ms. Mask */
#define SAGPEAKDETCFG_SAG_PERIOD_(value)                (SAGPEAKDETCFG_SAG_PERIOD_Msk & (_UINT16_(value) << SAGPEAKDETCFG_SAG_PERIOD_Pos))
#define SAGPEAKDETCFG_PEAKDET_PERIOD_Pos                _UINT16_(8)                                          /* (SAGPEAKDETCFG_PEAKDET_PERIOD) Period below the SagTh before to assert the Sag. Unit is ms. Position */
#define SAGPEAKDETCFG_PEAKDET_PERIOD_Msk                (_UINT16_(0xFF) << SAGPEAKDETCFG_PEAKDET_PERIOD_Pos) /* (SAGPEAKDETCFG_PEAKDET_PERIOD) Period below the SagTh before to assert the Sag. Unit is ms. Mask */
#define SAGPEAKDETCFG_PEAKDET_PERIOD_(value)            (SAGPEAKDETCFG_PEAKDET_PERIOD_Msk & (_UINT16_(value) << SAGPEAKDETCFG_PEAKDET_PERIOD_Pos))
#define SAGPEAKDETCFG_DEFAULT_Val                       _UINT16_(0x143F)                              /* Default Reg Value */

/* -------- Over Voltage/ Swell Threshold : (OVTH Offset: 0x06) (R/W - 16 bits) Over Voltage/ Swell Threshold  -------- */
#define OVTH_Pos                                        _UINT16_(0)                                   /* (OVTH) Over Voltage/ Swell Threshold. Position */
#define OVTH_Msk                                        (_UINT16_(0xFFFF) << OVTH_Pos)                /* (OVTH) Over Voltage/ Swell Threshold. Mask */
#define OVTH(value)                                     (OVTH_Msk & (_UINT16_(value) << OVTH_Pos))
#define   OVTH_DEFAULT_Val                              _UINT16_(0xC000)                              /* (OVTH) Over Voltage Threshold Default Value */

/* -------- Zero-Crossing Configuration : (ZXConfig Offset: 0x07) (R/W - 16 bits) Zero-Crossing Configuration -------- */
#define ZXCONFIG_ZXDIS_Pos                              _UINT16_(0)                                   /* (ZXCONFIG_ZXDIS) This bit determines whether to disable the ZX signals. Position */
#define ZXCONFIG_ZXDIS_Msk                              (_UINT16_(0x1) << ZXCONFIG_ZXDIS_Pos)         /* (ZXCONFIG_ZXDIS) This bit determines whether to disable the ZX signals. Mask */
#define ZXCONFIG_ZXDIS_(value)                          (ZXCONFIG_ZXDIS_Msk & (_UINT16_(value) << ZXCONFIG_ZXDIS_Pos))
#define   ZXCONFIG_ZXDIS_EN_Val                         _UINT16_(0x0)                                 /* (ZXCONFIG_ZXDIS) Enable */
#define   ZXCONFIG_ZXDIS_DIS_Val                        _UINT16_(0x1)                                 /* (ZXCONFIG_ZXDIS) Disable all the ZX signals to ‘0’ (default) */
#define ZXCONFIG_ZX0CON_Pos                             _UINT16_(1)                                   /* (ZXCONFIG_ZX0CON) Configure zero-crossing type for the ZX0 pin. Position */
#define ZXCONFIG_ZX0CON_Msk                             (_UINT16_(0x3) << ZXCONFIG_ZX0CON_Pos)        /* (ZXCONFIG_ZX0CON) Configure zero-crossing type for the ZX0 pin. Mask */
#define ZXCONFIG_ZX0CON_(value)                         (ZXCONFIG_ZX0CON_Msk & (_UINT16_(value) << ZXCONFIG_ZX0CON_Pos))
#define   ZXCONFIG_ZX0CON_POS_Val                       _UINT16_(0x0)                                 /* (ZXCONFIG_ZX0CON) Positive Zero-crossing */
#define   ZXCONFIG_ZX0CON_NEG_Val                       _UINT16_(0x1)                                 /* (ZXCONFIG_ZX0CON) Negative Zero-crossing */
#define   ZXCONFIG_ZX0CON_ALL_Val                       _UINT16_(0x2)                                 /* (ZXCONFIG_ZX0CON) All Zero-crossing */
#define   ZXCONFIG_ZX0CON_NO_Val                        _UINT16_(0x3)                                 /* (ZXCONFIG_ZX0CON) No Zero-crossing Output */
#define ZXCONFIG_ZX1CON_Pos                             _UINT16_(3)                                   /* (ZXCONFIG_ZX1CON) Configure zero-crossing type for the ZX0 pin. Position */
#define ZXCONFIG_ZX1CON_Msk                             (_UINT16_(0x3) << ZXCONFIG_ZX1CON_Pos)        /* (ZXCONFIG_ZX1CON) Configure zero-crossing type for the ZX0 pin. Mask */
#define ZXCONFIG_ZX1CON_(value)                         (ZXCONFIG_ZX1CON_Msk & (_UINT16_(value) << ZXCONFIG_ZX1CON_Pos))
#define   ZXCONFIG_ZX1CON_POS_Val                       _UINT16_(0x0)                                 /* (ZXCONFIG_ZX1CON) Positive Zero-crossing */
#define   ZXCONFIG_ZX1CON_NEG_Val                       _UINT16_(0x1)                                 /* (ZXCONFIG_ZX1CON) Negative Zero-crossing */
#define   ZXCONFIG_ZX1CON_ALL_Val                       _UINT16_(0x2)                                 /* (ZXCONFIG_ZX1CON) All Zero-crossing */
#define   ZXCONFIG_ZX1CON_NO_Val                        _UINT16_(0x3)                                 /* (ZXCONFIG_ZX1CON) No Zero-crossing Output */
#define ZXCONFIG_ZX2CON_Pos                             _UINT16_(5)                                   /* (ZXCONFIG_ZX2CON) Configure zero-crossing type for the ZX0 pin. Position */
#define ZXCONFIG_ZX2CON_Msk                             (_UINT16_(0x3) << ZXCONFIG_ZX2CON_Pos)        /* (ZXCONFIG_ZX2CON) Configure zero-crossing type for the ZX0 pin. Mask */
#define ZXCONFIG_ZX2CON_(value)                         (ZXCONFIG_ZX2CON_Msk & (_UINT16_(value) << ZXCONFIG_ZX2CON_Pos))
#define   ZXCONFIG_ZX2CON_POS_Val                       _UINT16_(0x0)                                 /* (ZXCONFIG_ZX2CON) Positive Zero-crossing */
#define   ZXCONFIG_ZX2CON_NEG_Val                       _UINT16_(0x1)                                 /* (ZXCONFIG_ZX2CON) Negative Zero-crossing */
#define   ZXCONFIG_ZX2CON_ALL_Val                       _UINT16_(0x2)                                 /* (ZXCONFIG_ZX2CON) All Zero-crossing */
#define   ZXCONFIG_ZX2CON_NO_Val                        _UINT16_(0x3)                                 /* (ZXCONFIG_ZX2CON) No Zero-crossing Output */
#define ZXCONFIG_ZX0SRC_Pos                             _UINT16_(7)                                   /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin. Position */
#define ZXCONFIG_ZX0SRC_Msk                             (_UINT16_(0x7) << ZXCONFIG_ZX0SRC_Pos)        /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin. Mask */
#define ZXCONFIG_ZX0SRC_(value)                         (ZXCONFIG_ZX0SRC_Msk & (_UINT16_(value) << ZXCONFIG_ZX0SRC_Pos))
#define   ZXCONFIG_ZX0SRC_UA_Val                       _UINT16_(0x0)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin Ua */
#define   ZXCONFIG_ZX0SRC_UB_Val                       _UINT16_(0x1)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin Ub */
#define   ZXCONFIG_ZX0SRC_UC_Val                       _UINT16_(0x2)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin Uc */
#define   ZXCONFIG_ZX0SRC_IA_Val                       _UINT16_(0x4)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin Ia */
#define   ZXCONFIG_ZX0SRC_IB_Val                       _UINT16_(0x5)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin Ib */
#define   ZXCONFIG_ZX0SRC_IC_Val                       _UINT16_(0x6)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 pin Ic */
#define   ZXCONFIG_ZX0SRC_FIXED0_Val                   _UINT16_(0x3)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX0 fixed-0 */
#define ZXCONFIG_ZX1SRC_Pos                            _UINT16_(10)                                  /* (ZXCONFIG_ZX1SRC) Signal source for the ZX1 pin. Position */
#define ZXCONFIG_ZX1SRC_Msk                            (_UINT16_(0x7) << ZXCONFIG_ZX1SRC_Pos)        /* (ZXCONFIG_ZX1SRC) Signal source for the ZX1 pin. Mask */
#define ZXCONFIG_ZX1SRC_(value)                        (ZXCONFIG_ZX1SRC_Msk & (_UINT16_(value) << ZXCONFIG_ZX1SRC_Pos))
#define   ZXCONFIG_ZX1SRC_UA_Val                       _UINT16_(0x0)                                 /* (ZXCONFIG_ZX1SRC) Signal source for the ZX1 pin Ua */
#define   ZXCONFIG_ZX1SRC_UB_Val                       _UINT16_(0x1)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX1 pin Ub */
#define   ZXCONFIG_ZX1SRC_UC_Val                       _UINT16_(0x2)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX1 pin Uc */
#define   ZXCONFIG_ZX1SRC_IA_Val                       _UINT16_(0x4)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX1 pin Ia */
#define   ZXCONFIG_ZX1SRC_IB_Val                       _UINT16_(0x5)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX1 pin Ib */
#define   ZXCONFIG_ZX1SRC_IC_Val                       _UINT16_(0x6)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX1 pin Ic */
#define   ZXCONFIG_ZX1SRC_FIXED0_Val                   _UINT16_(0x3)                                 /* (ZXCONFIG_ZX0SRC) Signal source for the ZX1 fixed-0 */
#define ZXCONFIG_ZX2SRC_Pos                            _UINT16_(13)                                  /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin. Position */
#define ZXCONFIG_ZX2SRC_Msk                            (_UINT16_(0x7) << ZXCONFIG_ZX2SRC_Pos)        /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin. Mask */
#define ZXCONFIG_ZX2SRC_(value)                        (ZXCONFIG_ZX2SRC_Msk & (_UINT16_(value) << ZXCONFIG_ZX2SRC_Pos))
#define   ZXCONFIG_ZX2SRC_UA_Val                       _UINT16_(0x0)                                 /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin Ua */
#define   ZXCONFIG_ZX2SRC_UB_Val                       _UINT16_(0x1)                                 /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin Ub */
#define   ZXCONFIG_ZX2SRC_UC_Val                       _UINT16_(0x2)                                 /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin Uc */
#define   ZXCONFIG_ZX2SRC_IA_Val                       _UINT16_(0x4)                                 /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin Ia */
#define   ZXCONFIG_ZX2SRC_IB_Val                       _UINT16_(0x5)                                 /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin Ib */
#define   ZXCONFIG_ZX2SRC_IC_Val                       _UINT16_(0x6)                                 /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 pin Ic */
#define   ZXCONFIG_ZX2SRC_FIXED0_Val                   _UINT16_(0x3)                                 /* (ZXCONFIG_ZX2SRC) Signal source for the ZX2 fixed-0 */
#define ZXCONFIG_DEFAULT_Val                           _UINT16_(0x0001)                              /* Default Register Value */

/* -------- Voltage Sag Threshold : (SAGTH Offset: 0x08H) (R/W - 16 bits) Voltage sag threshold. 0xFFFF map to ADC output full-scale peak. -------- */
#define SAGTH_Pos                                      _UINT16_(0)                                   /* (SAGTH) SAG Threshold Position */
#define SAGTH_Msk                                      (_UINT16_(0xFFFF) << SAGTH_Pos)         /* (SAGTH) SAG Threshold Mask */
#define SAGTH_Val(value)                               (SAGTH_Msk & (_UINT16_(value) << SAGTH_Pos))
#define   SAGTH_DEFAULT_Val                            _UINT16_(0x1000)                              /* (SAGTH) SAG Threshold Default Value */

/* -------- Voltage Phase Losing Threshold : (PhaseLossTh Offset: 0x09H) (R/W - 16 bits) PhaseLoss threshold level. 0xFFFF map to ADC output full-scale peak. -------- */
#define PHASELOSSTH_Pos                                _UINT16_(0)                                   /* (PHASELOSSTH) Phase Loss Threshold Position */
#define PHASELOSSTH_Msk                                (_UINT16_(0xFFFF) << PHASELOSSTH_Pos) /* (PHASELOSSTH) Phase Loss Threshold Mask */
#define PHASELOSSTH_Val(value)                         (PHASELOSSTH_Msk & (_UINT16_(value) << PHASELOSSTH_Pos))
#define   PHASELOSSTH_DEFAULT_Val                      _UINT16_(0x0400)                              /* (PHASELOSSTH) Phase Loss Threshold Default Value */

/* -------- Neutral Current (Calculated) Warning Threshold : (InWarnTh Offset: 0x0AH) (R/W - 16 bits) . Threshold for calculated (Ia + Ib +Ic) N line rms current. Unsigned 16 bit, unit 1mA. -------- */
#define INWARNTH_Pos                                   _UINT16_(0)                                   /* (INWARNTH0) Neutral Current (Calculated) Warning Threshold Position */
#define INWARNTH_Msk                                   (_UINT16_(0xFFFF) << INWARNTH0_Pos)           /* (INWARNTH0) Neutral Current (Calculated) Warning Threshold Mask */
#define INWARNTH_Val(value)                            (INWARNTH0_Msk & (_UINT16_(value) << INWARNTH0_Pos))
#define   INWARNTH_DEFAULT_Val                         _UINT16_(0x0400)                              /* (INWARNTH0) Neutral Current (Calculated) Warning Threshold Default Value */

/* -------- Over Current Threshold : (OITH Offset: 0x0B) (R/W - 16 bits) Over Current Threshold -------- */
#define OITH_Pos                                       _UINT16_(0)                                    /* (OITH) Over Current Threshold. Position */
#define OITH_Msk                                       (_UINT16_(0xFFFF) << OITH_Pos)                 /* (OITH) Over Current Threshold. Mask */
#define OITH(value)                                    (OITH_Msk & (_UINT16_(value) << OITH_Pos))
#define   OITH_DEFAULT_Val                             _UINT16_(0xC000)                               /* (OITH) Over Current Threshold. Default Value */

/* -------- Low Threshold for Frequency Detection : (FreqLoTh Offset: 0x0C) (R/W - 16 bits) Low Threshold for Frequency Detection -------- */
#define FREQLOTH_Pos                                   _UINT16_(0)                                    /* (FREQLOTH) Low Threshold for Frequency Detection. Position */
#define FREQLOTH_Msk                                   (_UINT16_(0xFFFF) << FREQLOTH_Pos)             /* (FREQLOTH) Low Threshold for Frequency Detection. Mask */
#define FREQLOTH(value)                                (FREQLOTH_Msk & (_UINT16_(value) << FREQLOTH_Pos))
#define   FREQLOTH_DEFAULT_Val                         _UINT16_(0x1324)                               /* (FREQLOTH) Low Threshold for Frequency Detection. Default Value. 49Hz */

/* -------- Low Threshold for Frequency Detection : (FreqLoTh Offset: 0x0D) (R/W - 16 bits) Low Threshold for Frequency Detection -------- */
#define FREQHITH_Pos                                   _UINT16_(0)                                    /* (FREQHITH) High Threshold for Frequency Detection. Position */
#define FREQHITH_Msk                                   (_UINT16_(0xFFFF) << FREQHITH_Pos)             /* (FREQHITH) High Threshold for Frequency Detection. Mask */
#define FREQHITH(value)                                (FREQHITH_Msk & (_UINT16_(value) << FREQHITH_Pos))
#define   FREQHITH_DEFAULT_Val                         _UINT16_(0x13EC)                               /* (FREQHITH) High Threshold for Frequency Detection. Default Value. 51Hz */

#define PMPWRCTRL_DEFAULT_Val                          _UINT16_(0x010F)                                /* Default Register Value */

/* -------- IRQ0 Merge Configuration : (IRQ0MergeCfg Offset: 0x0F) (R/W - 16 bits) IRQ0 Merge Configuration -------- */
#define IRQ0MERGECFG_IRQ1_OR_Pos                        _UINT16_(0)                                   /* (IRQ1_OR) IRQ1 transfer to IRQ0. Position */
#define IRQ0MERGECFG_IRQ1_OR_Msk                        (_UINT16_(0x1) << IRQ0MERGECFG_IRQ1_OR_Pos)   /* (IRQ1_OR) IRQ1 transfer to IRQ0. Mask */
#define IRQ0MERGECFG_IRQ1_OR_(value)                    (IRQ0MERGECFG_IRQ1_OR_Msk & (_UINT16_(value) << IRQ0MERGECFG_IRQ1_OR_Pos))
#define   IRQ0MERGECFG_IRQ1_ORED_Val                    _UINT16_(0x1)                                 /* (IRQ1_OR) IRQ1 transfer to IRQ0 */
#define   IRQ0MERGECFG_IRQ1_NORMAL_Val                  _UINT16_(0x0)                                 /* (IRQ1_OR) IRQ1 not ORed on IRQ0 */
#define IRQ0MERGECFG_WARN_OR_Pos                        _UINT16_(0)                                   /* (IRQ1_OR) WARN transfer to IRQ0. Position */
#define IRQ0MERGECFG_WARN_OR_Msk                        (_UINT16_(0x1) << IRQ0MERGECFG_WARN_OR_Pos)   /* (IRQ1_OR) WARN transfer to IRQ0. Mask */
#define IRQ0MERGECFG_WARN_OR_(value)                    (IRQ0MERGECFG_WARN_OR_Msk & (_UINT16_(value) << IRQ0MERGECFG_WARN_OR_Pos))
#define   IRQ0MERGECFG_WARN_ORED_Val                    _UINT16_(0x1)                                 /* (IRQ1_OR) WARN transfer to IRQ0 */
#define   IRQ0MERGECFG_WARN_NORMAL_Val                  _UINT16_(0x0)                                 /* (IRQ1_OR) WARN not ORed on IRQ0 */
#define IRQ0MERGECFG_DEFAULT_Val                        _UINT16_(0x0)                                 /* Default Register Value */

/* ************************************************************************** */
/*   LOW POWER MODES REGISTERS                                                */
/* ************************************************************************** */

/* ************************************************************************** */
/*   CONFIGURATION REGISTER                                                   */
/* ************************************************************************** */
/* -------- High Word of PL_Constant : (PLCONSTH Offset: 0x31H) (R/W  - 16 bits) - High Word of PL_Constant -------- */
#define PLCONSTH_Pos                                    _UINT16_(0)                                   /* (PLCONSTH) High Word of PL_Constant Value Position */
#define PLCONSTH_Msk                                    (_UINT16_(0xFFFF) << PLCONSTH_Pos)            /* (PLCONSTH) High Word of PL_Constant Value Mask */
#define PLCONSTH_Val(value)                             (PLCONSTH_Msk & (_UINT16_(value) << PLCONSTH_Pos))
#define   PLCONSTH_DEFAULT_Val                          _UINT16_(0x0861)                              /* (PLCONSTH) Default Value */

/* -------- Low Word of PL_Constant : (PLCONSTL Offset: 0x32H) (R/W  - 16 bits) - Low Word of PL_Constant -------- */
#define PLCONSTL_Pos                                    _UINT16_(0)                                   /* (PLCONSTL) Low Word of PL_Constant Value Position */
#define PLCONSTL_Msk                                    (_UINT16_(0xFFFF) << PLCONSTL_Pos)            /* (PLCONSTL) Low Word of PL_Constant Value Mask */
#define PLCONSTL_Val(value)                             (PLCONSTL_Msk & (_UINT16_(value) << PLCONSTL_Pos))
#define   PLCONSTL_DEFAULT_Val                          _UINT16_(0xC468)                              /* (PLCONSTL) Default Value */

/* -------- Metering Mode Configuration : (MMODE0 Offset: 0x33H) (R/W - 16 bits) - ATM90E32 Metering Mode 0 Configuration -------- */
#define MMODE0_ENPC_Pos                                 _UINT16_(0)                                   /* (ENPC) Configure if Phase C is counted into the all-phase sum energy/power (P/Q/S). Position  */
#define MMODE0_ENPC_Msk                                 (_UINT16_(0x1) << MMODE0_ENPC_Pos)            /* (ENPC) Configure if Phase C is counted into the all-phase sum energy/power (P/Q/S). Mask */
#define MMODE0_ENPC_(value)                             (MMODE0_ENPC_Msk & (_UINT16_(value) << MMODE0_ENPC_Pos))
#define   MMODE0_ENPC_COUNTED_Val                        _UINT16_(0x0)                                 /* (ENPC) Phase C is counted into the all-phase sum energy/power */
#define   MMODE0_ENPC_NOT_COUNTED_Val                    _UINT16_(0x1)                                 /* (ENPC) Phase C is NOT counted into the all-phase sum energy/power */
#define MMODE0_ENPB_Pos                                 _UINT16_(1)                                   /* (ENPB) Configure if Phase B is counted into the all-phase sum energy/power (P/Q/S). Position  */
#define MMODE0_ENPB_Msk                                 (_UINT16_(0x1) << MMODE0_ENPB_Pos)            /* (ENPB) Configure if Phase B is counted into the all-phase sum energy/power (P/Q/S). Mask */
#define MMODE0_ENPB_(value)                             (MMODE0_ENPB_Msk & (_UINT16_(value) << MMODE0_ENPB_Pos))
#define   MMODE0_ENPB_COUNTED_Val                        _UINT16_(0x0)                                 /* (ENPB) Phase B is counted into the all-phase sum energy/power */
#define   MMODE0_ENPB_NOT_COUNTED_Val                    _UINT16_(0x1)                                 /* (ENPB) Phase B is NOT counted into the all-phase sum energy/power */
#define MMODE0_ENPA_Pos                                 _UINT16_(2)                                   /* (ENPA) Configure if Phase A is counted into the all-phase sum energy/power (P/Q/S). Position  */
#define MMODE0_ENPA_Msk                                 (_UINT16_(0x1) << MMODE0_ENPA_Pos)            /* (ENPA) Configure if Phase A is counted into the all-phase sum energy/power (P/Q/S). Mask */
#define MMODE0_ENPA_(value)                             (MMODE0_ENPA_Msk & (_UINT16_(value) << MMODE0_ENPA_Pos))
#define   MMODE0_ENPA_COUNTED_Val                        _UINT16_(0x0)                                 /* (ENPA) Phase A is counted into the all-phase sum energy/power */
#define   MMODE0_ENPA_NOT_COUNTED_Val                    _UINT16_(0x1)                                 /* (ENPA) Phase A is NOT counted into the all-phase sum energy/power */
#define MMODE0_ABSENP_Pos                               _UINT16_(3)                                   /* (ABSENP) These bits configure the calculation method of total (all-phase-sum) reactive/active energy and power. Position  */
#define MMODE0_ABSENP_Msk                               (_UINT16_(0x1) << MMODE0_ABSENP_Pos)          /* (ABSENP) These bits configure the calculation method of total (all-phase-sum) reactive/active energy and power. Mask */
#define MMODE0_ABSENP_(value)                           (MMODE0_ABSENP_Msk & (_UINT16_(value) << MMODE0_ABSENP_Pos))
#define   MMODE0_ABSENP_ABS_Val                          _UINT16_(0x1)                                 /* (ABSENP) Absolute Sum - [E|P]T=|[E|P]A|*EnPA+ |[E|P]B|*EnPB+ |[E|P]C|*EnPC */
#define   MMODE0_ABSENP_ARITH_Val                        _UINT16_(0x0)                                 /* (ABSENP) Arithmetic sum - [E|P]T=[E|P]A*EnPA+ [E|P]B*EnPB+ [E|P]C*EnPC */
#define   MMODE0_ABSENP_DEFAULT_Val                      _UINT16_(0x0)                                 /* (ABSENP) Arithmetic sum - [E|P]T=[E|P]A*EnPA+ [E|P]B*EnPB+ [E|P]C*EnPC */
#define MMODE0_ABSENQ_Pos                               _UINT16_(4)                                   /* (ABSENP) These bits configure the calculation method of total (all-phase-sum) reactive/active energy and power. Position  */
#define MMODE0_ABSENQ_Msk                               (_UINT16_(0x1) << MMODE0_ABSENQ_Pos)          /* (ABSENQ) These bits configure the calculation method of total (all-phase-sum) reactive/active energy and power. Mask */
#define MMODE0_ABSENQ_(value)                           (MMODE0_ABSENQ_Msk & (_UINT16_(value) << MMODE0_ABSENQ_Pos))
#define   MMODE0_ABSENQ_ABS_Val                          _UINT16_(0x1)                                 /* (ABSENQ) Absolute Sum - [E|P]T=|[E|P]A|*EnPA+ |[E|P]B|*EnPB+ |[E|P]C|*EnPC */
#define   MMODE0_ABSENQ_ARITH_Val                        _UINT16_(0x0)                                 /* (ABSENQ) Arithmetic sum - [E|P]T=[E|P]A*EnPA+ [E|P]B*EnPB+ [E|P]C*EnPC. Default */
#define   MMODE0_ABSENQ_DEFAULT_Val                      _UINT16_(0x0)                                 /* (ABSENQ) Arithmetic sum - [E|P]T=[E|P]A*EnPA+ [E|P]B*EnPB+ [E|P]C*EnPC. Default */
#define MMODE0_CF2VARH_Pos                              _UINT16_(7)                                   /* (CF2VARH) CF2 pin source. Position  */
#define MMODE0_CF2VARH_Msk                              (_UINT16_(0x1) << MMODE0_CF2VARH_Pos)         /* (CF2VARH) CF2 pin source. Mask */
#define MMODE0_CF2VARH_(value)                          (MMODE0_CF2VARH_Msk & (_UINT16_(value) << MMODE0_CF2VARH_Pos))
#define   MMODE0_CF2VARH_APPARENT_Val                    _UINT16_(0x0)                                 /* (CF2VARH) CF2 pin source Apparent Power */
#define   MMODE0_CF2VARH_REACTIVE_Val                    _UINT16_(0x1)                                 /* (CF2VARH) CF2 pin source Reactive Power */
#define   MMODE0_CF2VARH_DEFAULT_Val                     _UINT16_(0x1)                                 /* (CF2VARH) CF2 pin source Reactive Power */
#define MMODE0_3P3W_Pos                                 _UINT16_(8)                                   /* (3P3W) This bit defines the voltage/current phase sequence detection mode. Position  */
#define MMODE0_3P3W_Msk                                 (_UINT16_(0x1) << MMODE0_3P3W_Pos)            /* (3P3W) This bit defines the voltage/current phase sequence detection mode. Mask */
#define MMODE0_3P3W_(value)                             (MMODE0_3P3W_Msk & (_UINT16_(value) << MMODE0_3P3W_Pos))
#define   MMODE0_3P3W_3P3W_Val                           _UINT16_(0x1)                                /* (3P3W) 3P3W (Ua is Uab, Uc is Ucb, Ub is not used) */
#define   MMODE0_3P3W_3P4W_Val                           _UINT16_(0x0)                                /* (3P3W) 3P4W */
#define   MMODE0_3P3W_DEFAULT_Val                        _UINT16_(0x0)                                /* (3P3W) 3P4W */
#define MMODE0_DIDTEN_Pos                               _UINT16_(10)                                 /* (DIDTEN) Enable Integrator for didt current sensor. Position  */
#define MMODE0_DIDTEN_Msk                               (_UINT16_(0x1) << MMODE0_DIDTEN_Pos)         /* (DIDTEN) Enable Integrator for didt current sensor. Mask */
#define MMODE0_DIDTEN_(value)                           (MMODE0_DIDTEN_Msk & (_UINT16_(value) << MMODE0_DIDTEN_Pos))
#define   MMODE0_DIDTEN_ENABLE_Val                       _UINT16_(0x1)                                /* (DIDTEN) Enable (Rogowski CT) */
#define   MMODE0_DIDTEN_DISABLE_Val                      _UINT16_(0x0)                                /* (DIDTEN) Disable */
#define   MMODE0_DIDTEN_DEFAULT_Val                      _UINT16_(0x0)                                /* (DIDTEN) Disable */
#define MMODE0_FREQ60HZ_Pos                             _UINT16_(11)                                  /* (FREQ60HZ) Current Grid operating line frequency.. Position  */
#define MMODE0_FREQ60HZ_Msk                             (_UINT16_(0x1) << MMODE0_FREQ60HZ_Pos)        /* (FREQ60HZ) Current Grid operating line frequency.. Mask */
#define MMODE0_FREQ60HZ_(value)                         (MMODE0_FREQ60HZ_Msk & (_UINT16_(value) << MMODE0_FREQ60HZ_Pos))
#define   MMODE0_FREQ60HZ_60HZ_Val                       _UINT16_(0x1)                                /* (FREQ60HZ) 60Hz  */
#define   MMODE0_FREQ60HZ_50HZ_Val                       _UINT16_(0x0)                                /* (FREQ60HZ) 50Hz */
#define   MMODE0_FREQ60HZ_DEFAULT_Val                    _UINT16_(0x0)                                /* (FREQ60HZ) 50Hz */
#define MMODE0_DEFAULT_Val                               _UINT16_(0x0087)                             /* Default Register Value */

/* -------- Metering Mode Configuration : (MMODE1 Offset: 0x34H) (R/W - 16 bits) - PGA Gain Configuration -------- */
#define MMODE1_PGA_GAIN_I1_Pos                          _UINT16_(0)                                  /* PGA Current I1 Gain Configuration. Position */
#define MMODE1_PGA_GAIN_I1_Msk                          (_UINT16_(0x3) << MMODE1_PGA_GAIN_I1_Pos)    /* PGA Current I1 Gain Configuration. Mask */
#define MMODE1_PGA_GAIN_I1(value)                       (MMODE1_PGA_GAIN_I1_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_I1_Pos))
#define MMODE1_PGA_GAIN_I2_Pos                          _UINT16_(2)                                  /* PGA Current I2 Gain Configuration. Position */
#define MMODE1_PGA_GAIN_I2_Msk                          (_UINT16_(0x3) << MMODE1_PGA_GAIN_I2_Pos)    /* PGA Current I2 Gain Configuration. Mask */
#define MMODE1_PGA_GAIN_I2(value)                       (MMODE1_PGA_GAIN_I2_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_I2_Pos))
#define MMODE1_PGA_GAIN_I3_Pos                          _UINT16_(4)                                  /* PGA Current I2 Gain Configuration. Position */
#define MMODE1_PGA_GAIN_I3_Msk                          (_UINT16_(0x3) << MMODE1_PGA_GAIN_I3_Pos)    /* PGA Current I2 Gain Configuration. Mask */
#define MMODE1_PGA_GAIN_I3(value)                       (MMODE1_PGA_GAIN_I3_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_I3_Pos))
#define   MMODE1_PGA_GAIN_1_Val                         _UINT16_(0x0)                                /* (PGA_GAIN_I1) Current I1 Gain 1 */
#define   MMODE1_PGA_GAIN_2_Val                         _UINT16_(0x1)                                /* (PGA_GAIN_I1) Current I1 Gain 2 */
#define   MMODE1_PGA_GAIN_4_Val                         _UINT16_(0x2)                                /* (PGA_GAIN_I1) Current I1 Gain 4 */
#define MMODE1_DEFAULT_Val                              _UINT16_(0x0)                                 /* Default Register Value */

/* -------- Active Startup Power Threshold : (PSTARTTH Offset: 0x35H) (R/W  - 16 bits) - Active Startup Power Threshold -------- */
/* -------- Note: 16 bit unsigned integer, Unit: 0.00032 Watt */
#define PSTARTTH_Pos                                    _UINT16_(0)                                   /* (PSTARTTH) Active Startup Power Threshold Value Position */
#define PSTARTTH_Msk                                    (_UINT16_(0xFFFF) << PSTARTTH_Pos)   /* (PSTARTTH) Active Startup Power Threshold Value Mask */
#define PSTARTTH_Val(value)                             (PSTARTTH_Msk & (_UINT16_(value) << PSTARTTH_Pos))
#define   PSTARTTH_DEFAULT_Val                          _UINT16_(0x0000)                              /* (PSTARTTH) Active Startup Power Threshold Default Value */

/* -------- Rective Startup Power Threshold : (QSTARTTH Offset: 0x36H) (R/W  - 16 bits) - Reactive Startup Power Threshold -------- */
/* -------- Note: 16 bit unsigned integer, Unit: 0.00032 var */
#define QSTARTTH_Pos                                    _UINT16_(0)                                   /* (QSTARTTH) Reactive Startup Power Threshold Value Position */
#define QSTARTTH_Msk                                    (_UINT16_(0xFFFF) << QSTARTTH_Pos)   /* (QSTARTTH) Reactive Startup Power Threshold Value Mask */
#define QSTARTTH_Val(value)                             (QSTARTTH_Msk & (_UINT16_(value) << QSTARTTH_Pos))
#define   QSTARTTH_DEFAULT_Val                          _UINT16_(0x0000)                              /* (QSTARTTH) Rective Startup Power Threshold Default Value */

/* -------- Apparent Startup Power Threshold : (SSTARTTH Offset: 0x37H) (R/W  - 16 bits) - Apparent Startup Power Threshold -------- */
/* -------- Note: 16 bit unsigned integer, Unit: 0.00032 VA */
#define SSTARTTH_Pos                                    _UINT16_(0)                                     /* (SSTARTTH) Apparent Startup Power Threshold Value Position */
#define SSTARTTH_SSTARTTH_Msk                           (_UINT16_(0xFFFF) << SSTARTTH_Pos)              /* (SSTARTTH) Apparent Startup Power Threshold Value Mask */
#define SSTARTTH_Val(value)                             (SSTARTTH_Msk & (_UINT16_(value) << SSTARTTH_Pos))
#define   SSTARTTH_DEFAULT_Val                          _UINT16_(0x0000)                                /* (SSTARTTH) Apparent Startup Power Threshold Default Value */

/* -------- Active No-Load Power Threshold : (PPHASETH Offset: 0x38H) (R/W  - 16 bits) - StartUp Power Threshold -------- */
#define PPHASETH_Pos                                    _UINT16_(0)                                     /* (PPHASETH) Active No-Load Power Threshold Value Position */
#define PPHASETH_Msk                                    (_UINT16_(0xFFFF) << PPHASETH_Pos)              /* (PPHASETH) Active No-Load Power Threshold Value Mask */
#define PPHASETH_Val(value)                             (PPHASETH_Msk & (_UINT16_(value) << PPHASETH_Pos))
#define   PPHASETH_DEFAULT_Val                          _UINT16_(0x0)                                        /* (PPHASETH) Active No-Load Power Threshold Default Value */

/* -------- Reactive No-Load Power Threshold : (QSTARTTH Offset: 0x39H) (R/W  - 16 bits) - Reactive No-Load Power Threshold -------- */
#define QPHASETH_Pos                                    _UINT16_(0)                                     /* (QPHASETH) Reactive No-Load Power Threshold Value Position */
#define QPHASETH_Msk                                    (_UINT16_(0xFFFF) << QPHASETH_Pos)              /* (QPHASETH) Reactive No-Load Power Threshold Value Mask */
#define QPHASETH_Val(value)                             (QPHASETH_Msk & (_UINT16_(value) << QPHASETH_Pos))
#define   QPHASETH_DEFAULT_Val                          _UINT16_(0x0)                                   /* (QPHASETH) Reactive No-Load Power Threshold Default Value */

/* -------- Apparent No-Load Power Threshold : (STARTTH Offset: 0x3AH) (R/W  - 16 bits) - Aparent No-Load Power Threshold -------- */
#define SPHASETH_Pos                                    _UINT16_(0)                                     /* (SPHASETH) Apparent No-Load Power Threshold Value Position */
#define SPHASETH_Msk                                    (_UINT16_(0xFFFF) << SPHASETH_Pos)              /* (SPHASETH) Apparent No-Load Power Threshold Value Mask */
#define SPHASETH_Val(value)                             (SPHASETH_Msk & (_UINT16_(value) << SPHASETH_Pos))
#define   SPHASETH_DEFAULT_Val                          _UINT16_(0x0)                                   /* (SPHASETH) Apparent No-Load Power Threshold Default Value */

/* ************************************************************************** */
/*   ENERGY CALIBRATION REGISTER                                              */
/* ************************************************************************** */
/* -------- Measurements Phase A Active Power Offset : (POFFSETA Offset: 0x41H) (R/W - 16 bits) - Phase A active power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETA_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase A Active Power Offset Value Position */
#define POFFSETA_OFFSET_Msk                             (_UINT16_(0xFFFF) << POFFSETA_OFFSET_Pos)     /* (OFFSET) Phase A Active Power Offset Value Mask */
#define POFFSETA_OFFSET_Val(value)                      (POFFSETA_OFFSET_Msk & (_UINT16_(value) << POFFSETA_OFFSET_Pos))
#define   POFFSETA_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase A Active Power Offset Default Value */

/* -------- Measurements Phase A Reactive Power Offset : (QOFFSETA Offset: 0x42H) (R/W - 16 bits) - Phase A reactive power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define QOFFSETA_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase A Rective Power Offset Value Position */
#define QOFFSETA_OFFSET_Msk                             (_UINT16_(0xFFFF) << QOFFSETA_OFFSET_Pos)     /* (OFFSET) Phase A Rective Power Offset Value Mask */
#define QOFFSETA_OFFSET_Val(value)                      (QOFFSETA_OFFSET_Msk & (_UINT16_(value) << QOFFSETA_OFFSET_Pos))
#define   QOFFSETA_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase A Rective Power Offset Default Value */

/* -------- Measurements Phase B Active Power Offset : (POFFSETB Offset: 0x43H) (R/W - 16 bits) - Phase B active power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETB_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase B Active Power Offset Value Position */
#define POFFSETB_OFFSET_Msk                             (_UINT16_(0xFFFF) << POFFSETB_OFFSET_Pos)     /* (OFFSET) Phase B Active Power Offset Value Mask */
#define POFFSETB_OFFSET_Val(value)                      (POFFSETB_OFFSET_Msk & (_UINT16_(value) << POFFSETB_OFFSET_Pos))
#define   POFFSETB_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase B Active Power Offset Default Value */

/* -------- Measurements Phase B Reactive Power Offset : (QOFFSETB Offset: 0x44H) (R/W - 16 bits) - Phase B reactive power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define QOFFSETB_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase B Rective Power Offset Value Position */
#define QOFFSETB_OFFSET_Msk                             (_UINT16_(0xFFFF) << QOFFSETB_OFFSET_Pos)     /* (OFFSET) Phase B Rective Power Offset Value Mask */
#define QOFFSETB_OFFSET_Val(value)                      (QOFFSETB_OFFSET_Msk & (_UINT16_(value) << QOFFSETB_OFFSET_Pos))
#define   QOFFSETB_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase B Rective Power Offset Default Value */

/* -------- Measurements Phase C Active Power Offset : (POFFSETC Offset: 0x45H) (R/W - 16 bits) - Phase C active power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETC_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase C Active Power Offset Value Position */
#define POFFSETC_OFFSET_Msk                             (_UINT16_(0xFFFF) << POFFSETB_OFFSET_Pos)     /* (OFFSET) Phase C Active Power Offset Value Mask */
#define POFFSETC_OFFSET_Val(value)                      (POFFSETC_OFFSET_Msk & (_UINT16_(value) << POFFSETC_OFFSET_Pos))
#define   POFFSETC_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase C Active Power Offset Default Value */

/* -------- Measurements Phase C Reactive Power Offset : (QOFFSETC Offset: 0x46H) (R/W - 16 bits) - Phase C reactive power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define QOFFSETC_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase C Rective Power Offset Value Position */
#define QOFFSETC_OFFSET_Msk                             (_UINT16_(0xFFFF) << QOFFSETC_OFFSET_Pos)     /* (OFFSET) Phase C Rective Power Offset Value Mask */
#define QOFFSETC_OFFSET_Val(value)                      (QOFFSETC_OFFSET_Msk & (_UINT16_(value) << QOFFSETC_OFFSET_Pos))
#define   QOFFSETC_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase C Rective Power Offset Default Value */

/* -------- Phase A Active/Reactive Energy Calibration Gain : (PQGAINA Offset: 0x47H) (R/W  - 16 bits) - Phase A Active/Reactive Energy Calibration Gain -------- */
#define PQGAINA_GAIN_Pos                                _UINT16_(0)                                   /* (GAIN) Phase A Active/Reactive Energy Calibration Gain Value Position */
#define PQGAINA_GAIN_Msk                                (_UINT16_(0xFFFF) << PQGAINA_GAIN_Pos)        /* (GAIN) Phase A Active/Reactive Energy Calibration Gain Value Mask */
#define PQGAINA_GAIN_Val(value)                         (PQGAINA_GAIN_Msk & (_UINT16_(value) << PQGAINA_GAIN_Pos))
#define   PQGAINA_GAIN_DEFAULT_Val                      _UINT16_(0)                                   /* (GAIN) Default Value */
/* -------- Phase A Active/Reactive Energy Calibration Phase Angle : (PHIA Offset: 0x48H) (R/W  - 16 bits) - Phase A Active/Reactive Energy Calibration Phase Angle -------- */
#define PHIA_DELAYCYCLES_Pos                            _UINT16_(0)                                   /* (PHIA) Number of delay cycles calculated in phase compensation. Position */
#define PHIA_DELAYCYCLES_Msk                            (_UINT16_(0xFF) << PHIA_DELAYCYCLES_Pos)      /* (PHIA) Number of delay cycles calculated in phase compensation. Mask */
#define PHIA_DELAYCYCLES_Val(value)                     (PHIA_DELAYCYCLES_Msk & (_UINT16_(value) << PHIA_DELAYCYCLES_Pos))
#define   PHIA_DELAYCYCLES_DEFAULT_Val                  _UINT16_(0)                                   /* (PHIA) Default Value. uint8_t */
#define PHIA_DELAYV_Pos                                 _UINT16_(15)                                   /* (PHIA) Phase A Active/Reactive Energy Calibration Phase Angle Value Position */
#define PHIA_DELAYV_Msk                                 (_UINT16_(0x1) << PHIA_DELAYV_Pos)           /* (PHIA) Phase A Active/Reactive Energy Calibration Phase Angle Value Mask */
#define PHIA_DELAYV_Val(value)                          (PHIA_DELAYV_Msk & (_UINT16_(value) << PHIA_DELAYV_Pos))
#define   PHIA_DELAYV_VOLTAGE_Val                       _UINT16_(1)                                   /* (PHIA) Delay Cycles are applied to voltage channel */
#define   PHIA_DELAYV_CURRENT_Val                       _UINT16_(0)                                   /* (PHIA) Delay Cycles are applied to current channel */
#define   PHIA_DELAYV_DEFAULT_Val                       _UINT16_(0)                                   /* (PHIA) Default Value */
#define   PHIA_DEFAULT_Val                              _UINT16_(0x0)                                 /* (PHIA) Default Register Value */

/* -------- Phase B Active/Reactive Energy Calibration Gain : (PQGAINB Offset: 0x49H) (R/W  - 16 bits) - Phase B Active/Reactive Energy Calibration Gain -------- */
#define PQGAINB_GAIN_Pos                                _UINT16_(0)                                   /* (GAIN) Phase B Active/Reactive Energy Calibration Gain Value Position */
#define PQGAINB_GAIN_Msk                                (_UINT16_(0xFFFF) << PQGAINB_GAIN_Pos)        /* (GAIN) Phase B Active/Reactive Energy Calibration Gain Value Mask */
#define PQGAINB_GAIN_Val(value)                         (PQGAINB_GAIN_Msk & (_UINT16_(value) << PQGAINB_GAIN_Pos))
#define   PQGAINB_GAIN_DEFAULT_Val                      _UINT16_(0)                                   /* (GAIN) Default Value. uint8_t */
/* -------- Phase B Active/Reactive Energy Calibration Phase Angle : (PHIB Offset: 0x4AH) (R/W  - 16 bits) - Phase B Active/Reactive Energy Calibration Phase Angle -------- */
#define PHIB_DELAYCYCLES_Pos                            _UINT16_(0)                                   /* (PHIB) Number of delay cycles calculated in phase compensation. Position */
#define PHIB_DELAYCYCLES_Msk                            (_UINT16_(0xFF) << PHIB_DELAYCYCLES_Pos)      /* (PHIB) Number of delay cycles calculated in phase compensation. Mask */
#define PHIB_DELAYCYCLES_Val(value)                     (PHIB_DELAYCYCLES_Msk & (_UINT16_(value) << PHIB_DELAYCYCLES_Pos))
#define   PHIB_DELAYCYCLES_DEFAULT_Val                  _UINT16_(0)                                   /* (PHIB) Default Value. uint8_t */
#define PHIB_DELAYV_Pos                                 _UINT16_(15)                                  /* (PHIB) Phase B Active/Reactive Energy Calibration Phase Angle Value Position */
#define PHIB_DELAYV_Msk                                 (_UINT16_(0x1) << PHIB_DELAYV_Pos)            /* (PHIB) Phase B Active/Reactive Energy Calibration Phase Angle Value Mask */
#define PHIB_DELAYV_Val(value)                          (PHIB_DELAYV_Msk & (_UINT16_(value) << PHIB_DELAYV_Pos))
#define   PHIB_DELAYV_VOLTAGE_Val                       _UINT16_(1)                                   /* (PHIB) Delay Cycles are applied to voltage channel */
#define   PHIB_DELAYV_CURRENT_Val                       _UINT16_(0)                                   /* (PHIB) Delay Cycles are applied to current channel */
#define   PHIB_DELAYV_DEFAULT_Val                       _UINT16_(0)                                   /* (PHIB) Default Value */
#define   PHIB_DEFAULT_Val                              _UINT16_(0x0)                                 /* (PHIB) Default Register Value */

/* -------- Phase C Active/Reactive Energy Calibration Gain : (PQGAINC Offset: 0x4BH) (R/W  - 16 bits) - Phase C Active/Reactive Energy Calibration Gain -------- */
#define PQGAINC_GAIN_Pos                                _UINT16_(0)                                   /* (GAIN) Phase C Active/Reactive Energy Calibration Gain Value Position */
#define PQGAINC_GAIN_Msk                                (_UINT16_(0xFFFF) << PQGAINC_GAIN_Pos)        /* (GAIN) Phase C Active/Reactive Energy Calibration Gain Value Mask */
#define PQGAINC_GAIN_Val(value)                         (PQGAINC_GAIN_Msk & (_UINT16_(value) << PQGAINC_GAIN_Pos))
#define   PQGAINC_GAIN_DEFAULT_Val                      _UINT16_(0)                                   /* (GAIN) Default Value */
/* -------- Phase C Active/Reactive Energy Calibration Phase Angle : (PHIC Offset: 0x4CH) (R/W  - 16 bits) - Phase C Active/Reactive Energy Calibration Phase Angle -------- */
#define PHIC_DELAYCYCLES_Pos                            _UINT16_(0)                                   /* (PHIC) Number of delay cycles calculated in phase compensation. Position */
#define PHIC_DELAYCYCLES_Msk                            (_UINT16_(0xFF) << PHIC_DELAYCYCLES_Pos)      /* (PHIC) Number of delay cycles calculated in phase compensation. Mask */
#define PHIC_DELAYCYCLES_Val(value)                     (PHIC_DELAYCYCLES_Msk & (_UINT16_(value) << PHIC_DELAYCYCLES_Pos))
#define   PHIC_DELAYCYCLES_DEFAULT_Val                  _UINT16_(0)                                   /* (PHIC) Default Value. uint8_t */
#define PHIC_DELAYV_Pos                                 _UINT16_(15)                                  /* (PHIC) Phase C Active/Reactive Energy Calibration Phase Angle Value Position */
#define PHIC_DELAYV_Msk                                 (_UINT16_(0x1) << PHIC_DELAYV_Pos)            /* (PHIC) Phase C Active/Reactive Energy Calibration Phase Angle Value Mask */
#define PHIC_DELAYV_Val(value)                          (PHIC_DELAYV_Msk & (_UINT16_(value) << PHIC_DELAYV_Pos))
#define   PHIC_DELAYV_VOLTAGE_Val                       _UINT16_(1)                                   /* (PHIC) Delay Cycles are applied to voltage channel */
#define   PHIC_DELAYV_CURRENT_Val                       _UINT16_(0)                                   /* (PHIC) Delay Cycles are applied to current channel */
#define   PHIC_DELAYV_DEFAULT_Val                       _UINT16_(0)                                   /* (PHIC) Default Value */
#define   PHIC_DEFAULT_Val                              _UINT16_(0x0)                                 /* (PHIC) Default Register Value */

/* ************************************************************************** */
/*   FUNDAMENTAL/HARMONIC ENERGY CALIBRATION REGISTER                         */
/* ************************************************************************** */
/* -------- Measurements Phase A Fundamental Active Power Offset : (POFFSETAF Offset: 0x51H) (R/W - 16 bits) - Phase A Fundamental active power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETAF_OFFSET_Pos                            _UINT16_(0)                                   /* (OFFSET) Phase A Fundamental Active Power Offset Value Position */
#define POFFSETAF_OFFSET_Msk                            (_UINT16_(0xFFFF) << POFFSETAF_OFFSET_Pos)    /* (OFFSET) Phase A Fundamental Active Power Offset Value Mask */
#define POFFSETAF_OFFSET_Val(value)                     (POFFSETAF_POFFSETAF_Msk & (_UINT16_(value) << POFFSETAF_OFFSET_Pos))
#define   POFFSETAF_OFFSET_DEFAULT_Val                  _UINT16_(0)                                   /* (OFFSET) Phase A Fundamental Active Power Offset Default Value */

/* -------- Measurements Phase B Fundamental Active Power Offset : (POFFSETB Offset: 0x52H) (R/W - 16 bits) - Phase B Fundamental active power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETBF_OFFSET_Pos                             _UINT16_(0)                                  /* (OFFSET) Phase B Fundamental Active Power Offset Value Position */
#define POFFSETBF_OFFSET_Msk                             (_UINT16_(0xFFFF) << POFFSETBF_OFFSET_Pos)   /* (OFFSET) Phase B Fundamental Active Power Offset Value Mask */
#define POFFSETBF_OFFSET_Val(value)                      (POFFSETBF_OFFSET_Msk & (_UINT16_(value) << POFFSETBF_OFFSET_Pos))
#define   POFFSETBF_OFFSET_DEFAULT_Val                   _UINT16_(0)                                  /* (OFFSET) Phase B Fundamental Active Power Offset Default Value */

/* -------- Measurements Phase C Fundamental Active Power Offset : (POFFSETC Offset: 0x53H) (R/W - 16 bits) - Phase C Fundamental active power offset, signed with complement format -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETCF_OFFSET_Pos                            _UINT16_(0)                                   /* (OFFSET) Phase C Fundamental Active Power Offset Value Position */
#define POFFSETCF_OFFSET_Msk                            (_UINT16_(0xFFFF) << POFFSETCF_OFFSET_Pos)    /* (OFFSET) Phase C Fundamental Active Power Offset Value Mask */
#define POFFSETCF_OFFSET_Val(value)                     (POFFSETCF_OFFSET_Msk & (_UINT16_(value) << POFFSETCF_OFFSET_Pos))
#define   POFFSETCF_OFFSET_DEFAULT_Val                  _UINT16_(0)                                   /* (OFFSET) Phase C Fundamental Active Power Offset Default Value */

/* -------- Phase A Active/Reactive Energy Calibration Gain : (PGAINAF Offset: 0x54H) (R/W  - 16 bits) - Phase A Active/Reactive Energy Calibration Gain -------- */
#define PGAINAF_GAIN_Pos                                _UINT16_(0)                                   /* (GAIN) Phase A Active/Reactive Energy Calibration Gain Value Position */
#define PGAINAF_GAIN_Msk                                (_UINT16_(0xFFFF) << PGAINAF_GAIN_Pos)        /* (GAIN) Phase A Active/Reactive Energy Calibration Gain Value Mask */
#define PGAINAF_GAIN_Val(value)                         (PGAINAF_GAIN_Msk & (_UINT16_(value) << PGAINAF_GAIN_Pos))
#define   PGAINAF_GAIN_DEFAULT_Val                      _UINT16_(0)                                   /* (GAIN) Default Value */

/* -------- Phase B Active/Reactive Energy Calibration Gain : (PGAINBF Offset: 0x55H) (R/W  - 16 bits) - Phase B Active/Reactive Energy Calibration Gain -------- */
#define PGAINBF_GAIN_Pos                                _UINT16_(0)                                   /* (GAIN) Phase B Active/Reactive Energy Calibration Gain Value Position */
#define PGAINBF_GAIN_Msk                                (_UINT16_(0xFFFF) << PGAINBF_GAIN_Pos)        /* (GAIN) Phase B Active/Reactive Energy Calibration Gain Value Mask */
#define PGAINBF_GAIN_Val(value)                         (PGAINBF_GAIN_Msk & (_UINT16_(value) << PGAINBF_GAIN_Pos))
#define   PGAINBF_GAIN_DEFAULT_Val                      _UINT16_(0)                                   /* (GAIN) Default Value */

/* -------- Phase C Active/Reactive Energy Calibration Gain : (PGAINCF Offset: 0x56H) (R/W  - 16 bits) - Phase C Active/Reactive Energy Calibration Gain -------- */
#define PGAINCF_GAIN_Pos                                _UINT16_(0)                                   /* (GAIN) Phase C Active/Reactive Energy Calibration Gain Value Position */
#define PGAINCF_GAIN_Msk                                (_UINT16_(0xFFFF) << PGAINCF_GAIN_Pos)        /* (GAIN) Phase C Active/Reactive Energy Calibration Gain Value Mask */
#define PGAINCF_GAIN_Val(value)                         (PGAINCF_GAIN_Msk & (_UINT16_(value) << PGAINCF_GAIN_Pos))
#define   PGAINCF_GAIN_DEFAULT_Val                      _UINT16_(0)                                   /* (GAIN) Default Value */

/* ************************************************************************** */
/*   MEASUREMENT CALIBRATION REGISTER                                         */
/* ************************************************************************** */
/* -------- Measurements Phase A Voltage rms Gain : (UGAINA Offset: 0x61H) (R/W - 16 bits) - ATM90E32 Measurements Phase A Voltage rms Gain -------- */
#define UGAINA_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase A Voltage rms Gain Value Position */
#define UGAINA_GAIN_Msk                                 (_UINT16_(0xFFFF) << UGAINA_GAIN_Pos)         /* (GAIN) Phase A Voltage rms Gain Value Mask */
#define UGAINA_GAIN_Val(value)                          (UGAINA_GAIN_Msk & (_UINT16_(value) << UGAINA_GAIN_Pos))
#define   UGAINA_GAIN_DEFAULT_Val                       _UINT16_(0x8000)                              /* (GAIN) Phase A Voltage rms Gain Default Value */

/* -------- Measurements Phase A Current rms Gain : (IGAINA Offset: 0x62H) (R/W - 16 bits) - ATM90E32 Measurements Phase A Current rms Gain -------- */
#define IGAINA_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase A Current rms Gain Value Position */
#define IGAINA_GAIN_Msk                                 (_UINT16_(0xFFFF) << IGAINA_GAIN_Pos)         /* (GAIN) Phase A Current rms Gain Value Mask */
#define IGAINA_GAIN_Val(value)                          (IGAINA_GAIN_Msk & (_UINT16_(value) << IGAINA_GAIN_Pos))
#define   IGAINA_GAIN_DEFAULT_Val                       _UINT16_(0x8000)                              /* (GAIN) Phase A Current rms Gain Default Value */

/* -------- Measurements Phase A Voltage Offset : (UOFFSETA Offset: 0x63H) (R/W - 16 bits) - ATM90E32 Measurements Phase A Voltage Offset -------- */
/* -------- Note: The voltage offset calibration should be performed at reference current and no offset. It is not applicable for self-powered meter.   */
#define UOFFSETA_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase A Voltage Offset Value Position */
#define UOFFSETA_OFFSET_Msk                             (_UINT16_(0xFFFF) << UOFFSETA_OFFSET_Pos)     /* (OFFSET) Phase A Voltage Offset Value Mask */
#define UOFFSETA_OFFSET_Val(value)                      (UOFFSETA_OFFSET_Msk & (_UINT16_(value) << UOFFSETA_OFFSET_Pos))
#define   UOFFSETA_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase A Voltage Offset Default Value */

/* -------- Measurements Phase A Current Offset : (IOFFSETA Offset: 0x64H) (R/W - 16 bits) - ATM90E32 Measurements Phase A Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETA_OFFSET_Pos                           _UINT16_(0)                                    /* (OFFSET) Phase A Current Offset Value Position */
#define IOFFSETA_OFFSET_Msk                           (_UINT16_(0xFFFF) << IOFFSETA_OFFSET_Pos)      /* (OFFSET) Phase A Current Offset Value Mask */
#define IOFFSETA_OFFSET_Val(value)                    (IOFFSETA_OFFSET_Msk & (_UINT16_(value) << IOFFSETA_OFFSET_Pos))
#define   IOFFSETA_OFFSET_DEFAULT_Val                 _UINT16_(0)                                    /* (OFFSET) Phase A Current Offset Default Value */

/* -------- Measurements Phase B Voltage rms Gain : (UGAINB Offset: 0x65H) (R/W - 16 bits) - ATM90E32 Measurements Phase B Voltage rms Gain -------- */
#define UGAINB_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase B Voltage rms Gain Value Position */
#define UGAINB_GAIN_Msk                                 (_UINT16_(0xFFFF) << UGAINB_GAIN_Pos)         /* (GAIN) Phase B Voltage rms Gain Value Mask */
#define UGAINB_GAIN_Val(value)                          (UGAINB_GAIN_Msk & (_UINT16_(value) << UGAINB_GAIN_Pos))
#define   UGAINB_GAIN_DEFAULT_Val                       _UINT16_(0x8000)                              /* (GAIN) Phase B Voltage rms Gain Default Value */

/* -------- Measurements Phase B Current rms Gain : (IGAINB Offset: 0x66H) (R/W - 16 bits) - ATM90E32 Measurements Phase B Current rms Gain -------- */
#define IGAINB_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase B Current rms Gain Value Position */
#define IGAINB_GAIN_Msk                                 (_UINT16_(0xFFFF) << IGAINB_GAIN_Pos)         /* (GAIN) Phase B Current rms Gain Value Mask */
#define IGAINB_GAIN_Val(value)                          (IGAINB_GAIN_Msk & (_UINT16_(value) << IGAINB_GAIN_Pos))
#define   IGAINB_GAIN_DEFAULT_Val                       _UINT16_(0x8000)                              /* (GAIN) Phase B Current rms Gain Default Value */

/* -------- Measurements Phase B Voltage Offset : (UOFFSETB Offset: 0x67H) (R/W - 16 bits) - ATM90E32 Measurements Phase B Voltage Offset -------- */
/* -------- Note: The voltage offset calibration should be performed at reference current and no offset. It is not applicable for self-powered meter.   */
#define UOFFSETB_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase B Voltage Offset Value Position */
#define UOFFSETB_OFFSET_Msk                             (_UINT16_(0xFFFF) << UOFFSETB_OFFSET_Pos)     /* (OFFSET) Phase B Voltage Offset Value Mask */
#define UOFFSETB_OFFSET_Val(value)                      (UOFFSETB_OFFSET_Msk & (_UINT16_(value) << UOFFSETB_OFFSET_Pos))
#define   UOFFSETB_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase B Voltage Offset Default Value */

/* -------- Measurements Phase B Current Offset : (IOFFSETB Offset: 0x64H) (R/W - 16 bits) - ATM90E32 Measurements Phase B Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETB_OFFSET_Pos                           _UINT16_(0)                                    /* (OFFSET) Phase B Current Offset Value Position */
#define IOFFSETB_OFFSET_Msk                           (_UINT16_(0xFFFF) << IOFFSETB_OFFSET_Pos)      /* (OFFSET) Phase B Current Offset Value Mask */
#define IOFFSETB_OFFSET_Val(value)                    (IOFFSETB_OFFSET_Msk & (_UINT16_(value) << IOFFSETB_OFFSET_Pos))
#define   IOFFSETB_OFFSET_DEFAULT_Val                 _UINT16_(0)                                    /* (OFFSET) Phase A Current Offset Default Value */

/* -------- Measurements Phase C Voltage rms Gain : (UGAIN Offset: 0x69H) (R/W - 16 bits) - ATM90E32 Measurements Phase C Voltage rms Gain -------- */
#define UGAINC_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase C Voltage rms Gain Value Position */
#define UGAINC_GAIN_Msk                                 (_UINT16_(0xFFFF) << UGAINC_GAIN_Pos)         /* (GAIN) Phase C Voltage rms Gain Value Mask */
#define UGAINC_GAIN_Val(value)                          (UGAINC_GAIN_Msk & (_UINT16_(value) << UGAINC_GAIN_Pos))
#define   UGAINC_GAIN_DEFAULT_Val                       _UINT16_(0x8000)                              /* (GAIN) Phase C Voltage rms Gain Default Value */

/* -------- Measurements Phase C Current rms Gain : (IGAINC Offset: 0x6AH) (R/W - 16 bits) - ATM90E32 Measurements Phase C Current rms Gain -------- */
#define IGAINC_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase C Current rms Gain Value Position */
#define IGAINC_GAIN_Msk                                 (_UINT16_(0xFFFF) << IGAINC_GAIN_Pos)         /* (GAIN) Phase C Current rms Gain Value Mask */
#define IGAINC_GAIN_Val(value)                          (IGAINC_GAIN_Msk & (_UINT16_(value) << IGAINC_GAIN_Pos))
#define   IGAINC_GAIN_DEFAULT_Val                       _UINT16_(0x8000)                              /* (GAIN) Phase C Current rms Gain Default Value */

/* -------- Measurements Phase C Voltage Offset : (UOFFSETA Offset: 0x6BH) (R/W - 16 bits) - ATM90E32 Measurements Phase C Voltage Offset -------- */
/* -------- Note: The voltage offset calibration should be performed at reference current and no offset. It is not applicable for self-powered meter.   */
#define UOFFSETC_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase C Voltage Offset Value Position */
#define UOFFSETC_OFFSET_Msk                             (_UINT16_(0xFFFF) << UOFFSETC_OFFSET_Pos)     /* (OFFSET) Phase C Voltage Offset Value Mask */
#define UOFFSETC_OFFSET_Val(value)                      (UOFFSETC_OFFSET_Msk & (_UINT16_(value) << UOFFSETC_OFFSET_Pos))
#define   UOFFSETC_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase C Voltage Offset Default Value */

/* -------- Measurements Phase C Current Offset : (IOFFSETC Offset: 0x6CH) (R/W - 16 bits) - ATM90E32 Measurements Phase C Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETC_OFFSET_Pos                             _UINT16_(0)                                    /* (OFFSET) Phase C Current Offset Value Position */
#define IOFFSETC_OFFSET_Msk                             (_UINT16_(0xFFFF) << IOFFSETC_OFFSET_Pos)      /* (OFFSET) Phase C Current Offset Value Mask */
#define IOFFSETC_OFFSET_Val(value)                      (IOFFSETC_OFFSET_Msk & (_UINT16_(value) << IOFFSETC_OFFSET_Pos))
#define   IOFFSETC_OFFSET_DEFAULT_Val                   _UINT16_(0)                                    /* (OFFSET) Phase C Current Offset Default Value */

/* ************************************************************************** */
/*   STATUS REGISTER                                                          */
/* ************************************************************************** */
/* -------- SOFT RESET : (SOFT RESET Offset: 0x70) (W - 16 bits) ATM90E32 Soft Reset Register -------- */
#define SOFTRESET_Pos                                   _UINT16_(0)                                   /* (SOFTRESET) Soft Reset Position */
#define SOFTRESET_Msk                                   (_UINT16_(0xFFFF) << SOFTRESET_SOFTRESET_Pos) /* (SOFTRESET) Soft Reset Mask */
#define SOFTRESET(value)                                (SOFTRESET_SOFTRESET_Msk & (_UINT16_(value) << SOFTRESET_SOFTRESET_Pos))
#define   SOFTRESET_RESET_Val                           _UINT16_(0x789A)                              /* (SOFTRESET) Soft Reset Command */
#define   SOFTRESET_DEFAULT_Val                         _UINT16_(0)                                   /* (OFFSET) Phase C Current Offset Default Value */

/* -------- EMM State 0 : (EMMState0 Offset: 0x71) (R - 16 bits) ATM90E32 EMM State 0 -------- */
#define EMMSTATE0_CF4REVST_Pos                          _UINT16_(0)                                   /* (CF4REVST) CF4 output Forward/Reverse Status Position */
#define EMMSTATE0_CF4REVST_Msk                          (_UINT16_(0x1) << EMMSTATE0_CF4REVST_Pos)     /* (CF4REVST) CF4 output Forward/Reverse Status Mask */
#define EMMSTATE0_CF4REVST_(value)                      (EMMSTATE0_CF4REVST_Msk & (_UINT16_(value) << EMMSTATE0_CF4REVST_Pos))
#define   EMMSTATE0_CF4REVST_FORWARD_Val                _UINT16_(0x0)                                 /* (CF4REVST) CF4 output forward */
#define   EMMSTATE0_CF4REVST_REVERSE_Val                _UINT16_(0x1)                                 /* (CF4REVST) CF4 output reverse */
#define EMMSTATE0_CF3REVST_Pos                          _UINT16_(1)                                   /* (CF3REVST) CF3 output Forward/Reverse Status Position */
#define EMMSTATE0_CF3REVST_Msk                          (_UINT16_(0x1) << EMMSTATE0_CF3REVST_Pos)     /* (CF3REVST) CF3 output Forward/Reverse Status Mask */
#define EMMSTATE0_CF3REVST_(value)                      (EMMSTATE0_CF3REVST_Msk & (_UINT16_(value) << EMMSTATE0_CF3REVST_Pos))
#define   EMMSTATE0_CF3REVST_FORWARD_Val                _UINT16_(0x0)                                 /* (CF3REVST) CF3 output forward */
#define   EMMSTATE0_CF3REVST_REVERSE_Val                _UINT16_(0x1)                                 /* (CF3REVST) CF3 output reverse */
#define EMMSTATE0_CF2REVST_Pos                          _UINT16_(2)                                   /* (CF2REVST) CF2 output Forward/Reverse Status Position */
#define EMMSTATE0_CF2EVST_Msk                          (_UINT16_(0x1) << EMMSTATE0_CF2REVST_Pos)      /* (CF2REVST) CF2 output Forward/Reverse Status Mask */
#define EMMSTATE0_CF2REVST_(value)                      (EMMSTATE0_CF2REVST_Msk & (_UINT16_(value) << EMMSTATE0_CF2REVST_Pos))
#define   EMMSTATE0_CF2REVST_FORWARD_Val                _UINT16_(0x0)                                 /* (CF2REVST) CF2 output forward */
#define   EMMSTATE0_CF2REVST_REVERSE_Val                _UINT16_(0x1)                                 /* (CF2REVST) CF2 output reverse */
#define EMMSTATE0_CF1REVST_Pos                          _UINT16_(3)                                   /* (CF1REVST) CF1 output Forward/Reverse Status Position */
#define EMMSTATE0_CF1REVST_Msk                          (_UINT16_(0x1) << EMMSTATE0_CF1REVST_Pos)     /* (CF1REVST) CF1 output Forward/Reverse Status Mask */
#define EMMSTATE0_CF1REVST_(value)                      (EMMSTATE0_CF1REVST_Msk & (_UINT16_(value) << EMMSTATE0_CF1REVST_Pos))
#define   EMMSTATE0_CF1REVST_FORWARD_Val                _UINT16_(0x0)                                 /* (CF1REVST) CF1 output forward */
#define   EMMSTATE0_CF1REVST_REVERSE_Val                _UINT16_(0x1)                                 /* (CF1REVST) CF1 output reverse */
#define EMMSTATE0_TASNOLOADST_Pos                       _UINT16_(4)                                   /* (TASNOLOADST) All phase arithmetic sum apparent power no-load condition Status Position */
#define EMMSTATE0_TASNOLOADST_Msk                       (_UINT16_(0x1) << EMMSTATE0_TASNOLOADST_Pos)  /* (TASNOLOADST) All phase arithmetic sum apparent power no-load condition Status Mask */
#define EMMSTATE0_TASNOLOADST_(value)                   (EMMSTATE0_TASNOLOADST_Msk & (_UINT16_(value) << EMMSTATE0_TASNOLOADST_Pos))
#define   EMMSTATE0_TASNOLOADST_FALSE_Val               _UINT16_(0x0)                                 /* (TASNOLOADST) No-load condition Status False */
#define   EMMSTATE0_TASNOLOADST_TRUE_Val                _UINT16_(0x1)                                 /* (TASNOLOADST) No-load condition Status True */
#define EMMSTATE0_TPNOLOADST_Pos                        _UINT16_(5)                                   /* (TPNOLOADST) All phase sum active power no-load condition Status Position */
#define EMMSTATE0_TPNOLOADST_Msk                       (_UINT16_(0x1) << EMMSTATE0_TPNOLOADST_Pos)    /* (TPNOLOADST) All phase sum active power no-load condition Status Mask */
#define EMMSTATE0_TPNOLOADST_(value)                   (EMMSTATE0_TPNOLOADST_Msk & (_UINT16_(value) << EMMSTATE0_TPNOLOADST_Pos))
#define   EMMSTATE0_TPNOLOADST_FALSE_Val               _UINT16_(0x0)                                  /* (TPNOLOADST) No-load condition Status False */
#define   EMMSTATE0_TPNOLOADST_TRUE_Val                _UINT16_(0x1)                                  /* (TPNOLOADST) No-load condition Status True */
#define EMMSTATE0_TQNOLOADST_Pos                        _UINT16_(6)                                   /* (TPNOLOADST) All phase sum reactive power no-load condition Status Position */
#define EMMSTATE0_TQNOLOADST_Msk                       (_UINT16_(0x1) << EMMSTATE0_TQNOLOADST_Pos)    /* (TQNOLOADST) All phase sum reactive power no-load condition Status Mask */
#define EMMSTATE0_TQNOLOADST_(value)                   (EMMSTATE0_TQNOLOADST_Msk & (_UINT16_(value) << EMMSTATE0_TQNOLOADST_Pos))
#define   EMMSTATE0_TQNOLOADST_FALSE_Val               _UINT16_(0x0)                                  /* (TQNOLOADST) No-load condition Status False */
#define   EMMSTATE0_TQNOLOADST_TRUE_Val                _UINT16_(0x1)                                  /* (TQNOLOADST) No-load condition Status True */
#define EMMSTATE0_INOV0ST_Pos                          _UINT16_(7)                                    /* (INOV0ST) N line current > InWarnTh Status Position */
#define EMMSTATE0_INOV0ST_Msk                          (_UINT16_(0x1) << EMMSTATE0_INOV0ST_Pos)       /* (INOV0ST) N line current > InWarnTh Status Mask */
#define EMMSTATE0_INOV0ST_(value)                      (EMMSTATE0_INOV0ST_Msk & (_UINT16_(value) << EMMSTATE0_INOV0ST_Pos))
#define   EMMSTATE0_INOV0ST_FALSE_Val                  _UINT16_(0x0)                                  /* (INOV0ST) N line current > InWarnTh Status False */
#define   EMMSTATE0_INOV0ST_TRUE_Val                   _UINT16_(0x1)                                  /* (INOV0ST) N line current > InWarnTh Status True */
#define EMMSTATE0_IREVWNST_Pos                          _UINT16_(8)                                   /* (IREVWNST) Current Phase Sequence Error status Position */
#define EMMSTATE0_IREVWNST_Msk                          (_UINT16_(0x1) << EMMSTATE0_IREVWNST_Pos)     /* (IREVWNST) Current Phase Sequence Error status Mask */
#define EMMSTATE0_IREVWNST_(value)                      (EMMSTATE0_IREVWNST_Msk & (_UINT16_(value) << EMMSTATE0_IREVWNST_Pos))
#define   EMMSTATE0_IREVWNST_FALSE_Val                  _UINT16_(0x0)                                 /* (IREVWNST) Current Phase Sequence Error status False */
#define   EMMSTATE0_IREVWNST_TRUE_Val                   _UINT16_(0x1)                                 /* (IREVWNST) Current Phase Sequence Error status True */
#define EMMSTATE0_UREVWNST_Pos                          _UINT16_(9)                                   /* (UREVWNST) Voltage Phase Sequence Error status Position */
#define EMMSTATE0_UREVWNST_Msk                          (_UINT16_(0x1) << EMMSTATE0_UREVWNST_Pos)     /* (UREVWNST) Voltage Phase Sequence Error status Mask */
#define EMMSTATE0_UREVWNST_(value)                      (EMMSTATE0_UREVWNST_Msk & (_UINT16_(value) << EMMSTATE0_UREVWNST_Pos))
#define   EMMSTATE0_UREVWNST_FALSE_Val                  _UINT16_(0x0)                                 /* (UREVWNST) Voltage Phase Sequence Error status False */
#define   EMMSTATE0_UREVWNST_TRUE_Val                   _UINT16_(0x1)                                 /* (UREVWNST) Voltage Phase Sequence Error status True */
#define EMMSTATE0_OVPHASECST_Pos                        _UINT16_(10)                                  /* (OVPHASECST) Overvoltage on Phase C status Position */
#define EMMSTATE0_OVPHASECST_Msk                        (_UINT16_(0x1) << EMMSTATE0_OVPHASECST_Pos)   /* (OVPHASECST) Overvoltage on Phase C status Mask */
#define EMMSTATE0_OVPHASECST_(value)                    (EMMSTATE0_OVPHASECST_Msk & (_UINT16_(value) << EMMSTATE0_OVPHASECST_Pos))
#define   EMMSTATE0_OVPHASECST_FALSE_Val                _UINT16_(0x0)                                 /* (OVPHASECST) Overvoltage on Phase C status False */
#define   EMMSTATE0_OVPHASECST_TRUE_Val                 _UINT16_(0x1)                                 /* (OVPHASECST) Overvoltage on Phase C status True */
#define EMMSTATE0_OVPHASEBST_Pos                        _UINT16_(12)                                  /* (OVPHASECST) Overvoltage on Phase B status Position */
#define EMMSTATE0_OVPHASEBST_Msk                        (_UINT16_(0x1) << EMMSTATE0_OVPHASEBST_Pos)   /* (OVPHASEBST) Overvoltage on Phase B status Mask */
#define EMMSTATE0_OVPHASEBST_(value)                    (EMMSTATE0_OVPHASEBST_Msk & (_UINT16_(value) << EMMSTATE0_OVPHASEBST_Pos))
#define   EMMSTATE0_OVPHASEBST_FALSE_Val                _UINT16_(0x0)                                 /* (OVPHASECST) Overvoltage on Phase B status False */
#define   EMMSTATE0_OVPHASEBST_TRUE_Val                 _UINT16_(0x1)                                 /* (OVPHASECST) Overvoltage on Phase B status True */
#define EMMSTATE0_OVPHASEAST_Pos                        _UINT16_(12)                                  /* (OVPHASEAST) Overvoltage on Phase A status Position */
#define EMMSTATE0_OVPHASEAST_Msk                        (_UINT16_(0x1) << EMMSTATE0_OVPHASEAST_Pos)   /* (OVPHASEAST) Overvoltage on Phase A status Mask */
#define EMMSTATE0_OVPHASEAST_(value)                    (EMMSTATE0_OVPHASEAST_Msk & (_UINT16_(value) << EMMSTATE0_OVPHASEAST_Pos))
#define   EMMSTATE0_OVPHASEAST_FALSE_Val                _UINT16_(0x0)                                 /* (OVPHASEAST) Overvoltage on Phase A status False */
#define   EMMSTATE0_OVPHASEAST_TRUE_Val                 _UINT16_(0x1)                                 /* (OVPHASEAST) Overvoltage on Phase A status True */
#define EMMSTATE0_OIPHASECST_Pos                        _UINT16_(13)                                  /* (OIPHASECST) Overcurrent on Phase C status Position */
#define EMMSTATE0_OIPHASECST_Msk                        (_UINT16_(0x1) << EMMSTATE0_OIPHASECST_Pos)   /* (OIPHASECST) Overcurrent on Phase C status Mask */
#define EMMSTATE0_OIPHASECST_(value)                    (EMMSTATE0_OIPHASECST_Msk & (_UINT16_(value) << EMMSTATE0_OIPHASECST_Pos))
#define   EMMSTATE0_OIPHASECST_FALSE_Val                _UINT16_(0x0)                                 /* (OIPHASECST) Overcurrent on Phase C status False */
#define   EMMSTATE0_OIPHASECST_TRUE_Val                 _UINT16_(0x1)                                 /* (OIPHASECST) Overcurrent on Phase C status True */
#define EMMSTATE0_OIPHASEBST_Pos                        _UINT16_(14)                                  /* (OIPHASECST) Overcurrent on Phase B status Position */
#define EMMSTATE0_OIPHASEBST_Msk                        (_UINT16_(0x1) << EMMSTATE0_OIPHASEBST_Pos)   /* (OIPHASEBST) Overcurrent on Phase B status Mask */
#define EMMSTATE0_OIPHASEBST_(value)                    (EMMSTATE0_OIPHASEBST_Msk & (_UINT16_(value) << EMMSTATE0_OIPHASEBST_Pos))
#define   EMMSTATE0_OIPHASEBST_FALSE_Val                _UINT16_(0x0)                                 /* (OIPHASECST) Overcurrent on Phase B status False */
#define   EMMSTATE0_OIPHASEBST_TRUE_Val                 _UINT16_(0x1)                                 /* (OIPHASECST) Overcurrent on Phase B status True */
#define EMMSTATE0_OIPHASEAST_Pos                        _UINT16_(15)                                  /* (OIPHASEAST) Overcurrent on Phase A status Position */
#define EMMSTATE0_OIPHASEAST_Msk                        (_UINT16_(0x1) << EMMSTATE0_OIPHASEAST_Pos)   /* (OIPHASEAST) Overcurrent on Phase A status Mask */
#define EMMSTATE0_OIPHASEAST_(value)                    (EMMSTATE0_OIPHASEAST_Msk & (_UINT16_(value) << EMMSTATE0_OIPHASEAST_Pos))
#define   EMMSTATE0_OIPHASEAST_FALSE_Val                _UINT16_(0x0)                                 /* (OIPHASEAST) Overcurrent on Phase A status False */
#define   EMMSTATE0_OIPHASEAST_TRUE_Val                 _UINT16_(0x1)                                 /* (OIPHASEAST) Overcurrent on Phase A status True */
#define EMMSTATE0_DEFAULT_Val                           _UINT16_(0x0)

/* -------- EMM State 1 : (EMMState1 Offset: 0x72) (R - 16 bits) ATM90E32 EMM State 1 -------- */
#define EMMSTATE1_PEREGCPST_Pos                         _UINT16_(0)                                   /* (PEREGCPST) Active Energy Channel C Positive Status Position */
#define EMMSTATE1_PEREGCPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_PEREGCPST_Pos)    /* (PEREGCPST) Active Energy Channel C Positive Status Mask */
#define EMMSTATE1_PEREGCPST_(value)                     (EMMSTATE1_PEREGCPST_Msk & (_UINT16_(value) << EMMSTATE1_PEREGCPST_Pos))
#define   EMMSTATE1_PEREGCPST_POS_Val                   _UINT16_(0x0)                                 /* (PEREGCPST) Positive */
#define   EMMSTATE1_PEREGCPST_NEG_Val                   _UINT16_(0x1)                                 /* (PEREGCPST) Negative */
#define EMMSTATE1_PEREGBPST_Pos                         _UINT16_(1)                                   /* (PEREGBPST) Active Energy Channel B Positive Status Position */
#define EMMSTATE1_PEREGBPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_PEREGBPST_Pos)    /* (PEREGBPST) Active Energy Channel B Positive Status Mask */
#define EMMSTATE1_PEREGBPST_(value)                     (EMMSTATE1_PEREGBPST_Msk & (_UINT16_(value) << EMMSTATE1_PEREGBPST_Pos))
#define   EMMSTATE1_PEREGBPST_POS_Val                   _UINT16_(0x0)                                 /* (PEREGBPST) Positive */
#define   EMMSTATE1_PEREGBPST_NEG_Val                   _UINT16_(0x1)                                 /* (PEREGBPST) Negative */
#define EMMSTATE1_PEREGAPST_Pos                         _UINT16_(2)                                   /* (PEREGAPST) Active Energy Channel A Positive Status Position */
#define EMMSTATE1_PEREGAPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_PEREGAPST_Pos)    /* (PEREGAPST) Active Energy Channel A Positive Status Mask */
#define EMMSTATE1_PEREGAPST_(value)                     (EMMSTATE1_PEREGAPST_Msk & (_UINT16_(value) << EMMSTATE1_PEREGAPST_Pos))
#define   EMMSTATE1_PEREGAPST_POS_Val                   _UINT16_(0x0)                                 /* (PEREGAPST) Positive */
#define   EMMSTATE1_PEREGAPST_NEG_Val                   _UINT16_(0x1)                                 /* (PEREGAPST) Negative */
#define EMMSTATE1_PEREGTPST_Pos                         _UINT16_(3)                                   /* (PEREGTPST) Active Energy Sum Channels Positive Status Position */
#define EMMSTATE1_PEREGTPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_PEREGTPST_Pos)    /* (PEREGTPST) Active Energy Sum Channels Positive Status Mask */
#define EMMSTATE1_PEREGTPST_(value)                     (EMMSTATE1_PEREGTPST_Msk & (_UINT16_(value) << EMMSTATE1_PEREGTPST_Pos))
#define   EMMSTATE1_PEREGTPST_POS_Val                   _UINT16_(0x0)                                 /* (PEREGTPST) Positive */
#define   EMMSTATE1_PEREGTPST_NEG_Val                   _UINT16_(0x1)                                 /* (PEREGTPST) Negative */
#define EMMSTATE1_QEREGCPST_Pos                         _UINT16_(4)                                   /* (QEREGCPST) Reactive Energy Channel C Positive Status Position */
#define EMMSTATE1_QEREGCPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_QEREGCPST_Pos)    /* (QEREGCPST) Reactive Energy Channel C Positive Status Mask */
#define EMMSTATE1_QEREGCPST_(value)                     (EMMSTATE1_QEREGCPST_Msk & (_UINT16_(value) << EMMSTATE1_QEREGCPST_Pos))
#define   EMMSTATE1_QEREGCPST_POS_Val                   _UINT16_(0x0)                                 /* (QEREGCPST) Positive */
#define   EMMSTATE1_QEREGCPST_NEG_Val                   _UINT16_(0x1)                                 /* (QEREGCPST) Negative */
#define EMMSTATE1_QEREGBPST_Pos                         _UINT16_(5)                                   /* (QEREGBPST) Reactive Energy Channel B Positive Status Position */
#define EMMSTATE1_QEREGBPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_QEREGBPST_Pos)    /* (QEREGBPST) Reactive Energy Channel B Positive Status Mask */
#define EMMSTATE1_QEREGBPST_(value)                     (EMMSTATE1_QEREGBPST_Msk & (_UINT16_(value) << EMMSTATE1_QEREGBPST_Pos))
#define   EMMSTATE1_QEREGBPST_POS_Val                   _UINT16_(0x0)                                 /* (QEREGBPST) Positive */
#define   EMMSTATE1_QEREGBPST_NEG_Val                   _UINT16_(0x1)                                 /* (QEREGBPST) Negative */
#define EMMSTATE1_QEREGAPST_Pos                         _UINT16_(6)                                   /* (QEREGAPST) Reactive Energy Channel A Positive Status Position */
#define EMMSTATE1_QEREGAPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_QEREGAPST_Pos)    /* (QEREGAPST) Reactive Energy Channel A Positive Status Mask */
#define EMMSTATE1_QEREGAPST_(value)                     (EMMSTATE1_QEREGAPST_Msk & (_UINT16_(value) << EMMSTATE1_QEREGAPST_Pos))
#define   EMMSTATE1_QEREGAPST_POS_Val                   _UINT16_(0x0)                                 /* (QEREGAPST) Positive */
#define   EMMSTATE1_QEREGAPST_NEG_Val                   _UINT16_(0x1)                                 /* (QEREGAPST) Negative */
#define EMMSTATE1_QEREGTPST_Pos                         _UINT16_(7)                                   /* (QEREGTPST) Reactive Energy Sum Channels Positive Status Position */
#define EMMSTATE1_QEREGTPST_Msk                         (_UINT16_(0x1) << EMMSTATE1_QEREGTPST_Pos)    /* (QEREGTPST) Reactive Energy Sum Channels Positive Status Mask */
#define EMMSTATE1_QEREGTPST_(value)                     (EMMSTATE1_QEREGTPST_Msk & (_UINT16_(value) << EMMSTATE1_QEREGTPST_Pos))
#define   EMMSTATE1_QEREGTPST_POS_Val                   _UINT16_(0x0)                                 /* (QEREGTPST) Positive */
#define   EMMSTATE1_QEREGTPST_NEG_Val                   _UINT16_(0x1)                                 /* (QEREGTPST) Negative */
#define EMMSTATE1_PHASELOSSCST_Pos                      _UINT16_(8)                                   /* (PHASELOSSCST) Phase C Loss Status Position */
#define EMMSTATE1_PHASELOSSCST_Msk                      (_UINT16_(0x1) << EMMSTATE1_PHASELOSSCST_Pos) /* (PHASELOSSCST) Phase C Loss Status Mask */
#define EMMSTATE1_PHASELOSSCST_(value)                  (EMMSTATE1_PHASELOSSCST_Msk & (_UINT16_(value) << EMMSTATE1_PHASELOSSCST_Pos))
#define   EMMSTATE1_PHASELOSSCST_FALSE_Val              _UINT16_(0x0)                                 /* (PHASELOSSCST) Phase C Loss Status False */
#define   EMMSTATE1_PHASELOSSCST_TRUE_Val               _UINT16_(0x1)                                 /* (PHASELOSSCST) Phase C Loss Status True */
#define EMMSTATE1_PHASELOSSBST_Pos                      _UINT16_(9)                                   /* (PHASELOSSBST) Phase B Loss Status Position */
#define EMMSTATE1_PHASELOSSBST_Msk                      (_UINT16_(0x1) << EMMSTATE1_PHASELOSSBST_Pos) /* (PHASELOSSBST) Phase B Loss Status Mask */
#define EMMSTATE1_PHASELOSSBST_(value)                  (EMMSTATE1_PHASELOSSBST_Msk & (_UINT16_(value) << EMMSTATE1_PHASELOSSBST_Pos))
#define   EMMSTATE1_PHASELOSSBST_FALSE_Val              _UINT16_(0x0)                                 /* (PHASELOSSBST) Phase B Loss Status False */
#define   EMMSTATE1_PHASELOSSBST_TRUE_Val               _UINT16_(0x1)                                 /* (PHASELOSSBST) Phase B Loss Status True */
#define EMMSTATE1_PHASELOSSAST_Pos                      _UINT16_(10)                                  /* (PHASELOSSAST) Phase A Loss Status Position */
#define EMMSTATE1_PHASELOSSAST_Msk                      (_UINT16_(0x1) << EMMSTATE1_PHASELOSSAST_Pos) /* (PHASELOSSAST) Phase A Loss Status Mask */
#define EMMSTATE1_PHASELOSSAST_(value)                  (EMMSTATE1_PHASELOSSAST_Msk & (_UINT16_(value) << EMMSTATE1_PHASELOSSAST_Pos))
#define   EMMSTATE1_PHASELOSSAST_FALSE_Val              _UINT16_(0x0)                                 /* (PHASELOSSAST) Phase A Loss Status False */
#define   EMMSTATE1_PHASELOSSAST_TRUE_Val               _UINT16_(0x1)                                 /* (PHASELOSSAST) Phase A Loss Status True */
#define EMMSTATE1_FREQLOST_Pos                          _UINT16_(11)                                  /* (FREQLOST) Frequency Below Range Status Position */
#define EMMSTATE1_FREQLOST_Msk                          (_UINT16_(0x1) << EMMSTATE1_FREQLOST_Pos)     /* (FREQLOST) Frequency Below Range Status Mask */
#define EMMSTATE1_FREQLOST_(value)                      (EMMSTATE1_FREQLOST_Msk & (_UINT16_(value) << EMMSTATE1_FREQLOST_Pos))
#define   EMMSTATE1_FREQLOST_FALSE_Val                  _UINT16_(0x0)                                 /* (FREQLOST) Frequency Below Range Status False */
#define   EMMSTATE1_FREQLOST_TRUE_Val                   _UINT16_(0x1)                                 /* (FREQLOST) Frequency Below Range Status True */
#define EMMSTATE1_SAGPHASECST_Pos                       _UINT16_(12)                                  /* (SAGPHASECST) Phase C SAG Status Position */
#define EMMSTATE1_SAGPHASECST_Msk                       (_UINT16_(0x1) << EMMSTATE1_SAGPHASECST_Pos)  /* (SAGPHASECST) Phase C SAG Status Mask */
#define EMMSTATE1_SAGPHASECST_(value)                   (EMMSTATE1_SAGPHASECST_Msk & (_UINT16_(value) << EMMSTATE1_SAGPHASECST_Pos))
#define   EMMSTATE1_SAGPHASECST_FALSE_Val               _UINT16_(0x0)                                 /* (SAGPHASECST) Phase C SAG Status False */
#define   EMMSTATE1_SAGPHASECST_TRUE_Val                _UINT16_(0x1)                                 /* (SAGPHASECST) Phase C SAG Range Status True */
#define EMMSTATE1_SAGPHASEBST_Pos                       _UINT16_(13)                                  /* (SAGPHASEBST) Phase B SAG Status Position */
#define EMMSTATE1_SAGPHASEBST_Msk                       (_UINT16_(0x1) << EMMSTATE1_SAGPHASEBST_Pos)  /* (SAGPHASEBST) Phase B SAG Status Mask */
#define EMMSTATE1_SAGPHASEBST_(value)                   (EMMSTATE1_SAGPHASEBST_Msk & (_UINT16_(value) << EMMSTATE1_SAGPHASEBST_Pos))
#define   EMMSTATE1_SAGPHASEBST_FALSE_Val               _UINT16_(0x0)                                 /* (SAGPHASEBST) Phase B SAG Status False */
#define   EMMSTATE1_SAGPHASEBST_TRUE_Val                _UINT16_(0x1)                                 /* (SAGPHASEBST) Phase B SAG Range Status True */
#define EMMSTATE1_SAGPHASEAST_Pos                       _UINT16_(14)                                  /* (SAGPHASEAST) Phase A SAG Status Position */
#define EMMSTATE1_SAGPHASEAST_Msk                       (_UINT16_(0x1) << EMMSTATE1_SAGPHASEAST_Pos)  /* (SAGPHASEAST) Phase A SAG Status Mask */
#define EMMSTATE1_SAGPHASEAST_(value)                   (EMMSTATE1_SAGPHASEAST_Msk & (_UINT16_(value) << EMMSTATE1_SAGPHASEAST_Pos))
#define   EMMSTATE1_SAGPHASEAST_FALSE_Val               _UINT16_(0x0)                                 /* (SAGPHASEAST) Phase A SAG Status False */
#define   EMMSTATE1_SAGPHASEAST_TRUE_Val                _UINT16_(0x1)                                 /* (SAGPHASEAST) Phase A SAG Range Status True */
#define EMMSTATE1_FREQHIST_Pos                          _UINT16_(15)                                  /* (FREQHIST) Frequency Above Range Status Position */
#define EMMSTATE1_FREQHIST_Msk                          (_UINT16_(0x1) << EMMSTATE1_FREQHIST_Pos)     /* (FREQHIST) Frequency Above Range Status Mask */
#define EMMSTATE1_FREQHIST_(value)                      (EMMSTATE1_FREQHIST_Msk & (_UINT16_(value) << EMMSTATE1_FREQHIST_Pos))
#define   EMMSTATE1_FREQHIST_FALSE_Val                  _UINT16_(0x0)                                 /* (FREQHIST) Frequency Above Range Status False */
#define   EMMSTATE1_FREQHIST_TRUE_Val                   _UINT16_(0x1)                                 /* (FREQHIST) Frequency Above Range Status True */
#define EMMSTATE1_DEFAULT_Val                           _UINT16_(0x0)

/* -------- EMM Int State 0 : (EMMIntState0 Offset: 0x73) (R - 16 bits) ATM90E32 EMM Interrupt State 0 -------- */
#define EMMINTSTATE0_CF4REVINTST_Pos                    _UINT16_(0)                                   /* (CF4REVINTST) CF4 output Forward/Reverse INT status change flag Position */
#define EMMINTSTATE0_CF4REVINTST_Msk                    (_UINT16_(0x1) << EMMINTSTATE0_CF4REVINTST_Pos)     /* (CF4REVINTST) CF4 output Forward/Reverse INT status change flag Mask */
#define EMMINTSTATE0_CF4REVINTST_(value)                (EMMINTSTATE0_CF4REVINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_CF4REVINTST_Pos))
#define   EMMINTSTATE0_CF4REVINTST_FORWARD_Val          _UINT16_(0x0)                                 /* (CF4REVINTST) CF4 output forward/reverse INT status change flag False */
#define   EMMINTSTATE0_CF4REVINTST_REVERSE_Val          _UINT16_(0x1)                                 /* (CF4REVINTST) CF4 output forward/reverse INT status change flag True */
#define EMMINTSTATE0_CF3REVINTST_Pos                    _UINT16_(1)                                   /* (CF3REVINTST) CF3 output Forward/Reverse INT status change flag Position */
#define EMMINTSTATE0_CF3REVINTST_Msk                    (_UINT16_(0x1) << EMMINTSTATE0_CF3REVINTST_Pos)     /* (CF3REVINTST) CF3 output Forward/Reverse INT status change flag Mask */
#define EMMINTSTATE0_CF3REVINTST_(value)                (EMMINTSTATE0_CF3REVINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_CF3REVINTST_Pos))
#define   EMMINTSTATE0_CF3REVINTST_FORWARD_Val          _UINT16_(0x0)                                 /* (CF3REVINTST) CF3 output forward/reverse INT status change flag False */
#define   EMMINTSTATE0_CF3REVINTST_REVERSE_Val          _UINT16_(0x1)                                 /* (CF3REVINTST) CF3 output forward/reverse INT status change flag True */
#define EMMINTSTATE0_CF2REVINTST_Pos                    _UINT16_(2)                                   /* (CF2REVINTST) CF2 output Forward/Reverse INT status change flag Position */
#define EMMINTSTATE0_CF2EVINTST_Msk                     (_UINT16_(0x1) << EMMINTSTATE0_CF2REVINTST_Pos)      /* (CF2REVINTST) CF2 output Forward/Reverse INT status change flag Mask */
#define EMMINTSTATE0_CF2REVINTST_(value)                (EMMINTSTATE0_CF2REVINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_CF2REVINTST_Pos))
#define   EMMINTSTATE0_CF2REVINTST_FORWARD_Val          _UINT16_(0x0)                                 /* (CF2REVINTST) CF2 output forward/reverse INT status change flag False */
#define   EMMINTSTATE0_CF2REVINTST_REVERSE_Val          _UINT16_(0x1)                                 /* (CF2REVINTST) CF2 output forward/reverse INT status change flag True */
#define EMMINTSTATE0_CF1REVINTST_Pos                    _UINT16_(3)                                   /* (CF1REVINTST) CF1 output Forward/Reverse INT status change flag Position */
#define EMMINTSTATE0_CF1REVINTST_Msk                    (_UINT16_(0x1) << EMMINTSTATE0_CF1REVINTST_Pos)     /* (CF1REVINTST) CF1 output Forward/Reverse INT status change flag Mask */
#define EMMINTSTATE0_CF1REVINTST_(value)                (EMMINTSTATE0_CF1REVINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_CF1REVINTST_Pos))
#define   EMMINTSTATE0_CF1REVINTST_FORWARD_Val          _UINT16_(0x0)                                 /* (CF1REVINTST) CF1 output forward/reverse INT status change flag False */
#define   EMMINTSTATE0_CF1REVINTST_REVERSE_Val          _UINT16_(0x1)                                 /* (CF1REVINTST) CF1 output forward/reverse INT status change flag True */
#define EMMINTSTATE0_TASNOLOADINTST_Pos                 _UINT16_(4)                                   /* (TASNOLOADINTST) All phase arithmetic sum apparent power no-load condition INT status change flag Position */
#define EMMINTSTATE0_TASNOLOADINTST_Msk                 (_UINT16_(0x1) << EMMINTSTATE0_TASNOLOADINTST_Pos)  /* (TASNOLOADINTST) All phase arithmetic sum apparent power no-load condition INT status change flag Mask */
#define EMMINTSTATE0_TASNOLOADINTST_(value)             (EMMINTSTATE0_TASNOLOADINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_TASNOLOADINTST_Pos))
#define   EMMINTSTATE0_TASNOLOADINTST_FALSE_Val         _UINT16_(0x0)                                 /* (TASNOLOADINTST) No-load condition INT status change flag False */
#define   EMMINTSTATE0_TASNOLOADINTST_TRUE_Val          _UINT16_(0x1)                                 /* (TASNOLOADINTST) No-load condition INT status change flag True */
#define EMMINTSTATE0_TPNOLOADINTST_Pos                  _UINT16_(5)                                   /* (TPNOLOADINTST) All phase sum active power no-load condition INT status change flag Position */
#define EMMINTSTATE0_TPNOLOADINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_TPNOLOADINTST_Pos)    /* (TPNOLOADINTST) All phase sum active power no-load condition INT status change flag Mask */
#define EMMINTSTATE0_TPNOLOADINTST_(value)              (EMMINTSTATE0_TPNOLOADINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_TPNOLOADINTST_Pos))
#define   EMMINTSTATE0_TPNOLOADINTST_FALSE_Val          _UINT16_(0x0)                                  /* (TPNOLOADINTST) No-load condition INT status change flag False */
#define   EMMINTSTATE0_TPNOLOADINTST_TRUE_Val           _UINT16_(0x1)                                  /* (TPNOLOADINTST) No-load condition INT status change flag True */
#define EMMINTSTATE0_TQNOLOADINTST_Pos                  _UINT16_(6)                                   /* (TPNOLOADINTST) All phase sum reactive power no-load condition INT status change flag Position */
#define EMMINTSTATE0_TQNOLOADINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_TQNOLOADINTST_Pos)    /* (TQNOLOADINTST) All phase sum reactive power no-load condition INT status change flag Mask */
#define EMMINTSTATE0_TQNOLOADINTST_(value)              (EMMINTSTATE0_TQNOLOADINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_TQNOLOADINTST_Pos))
#define   EMMINTSTATE0_TQNOLOADINTST_FALSE_Val          _UINT16_(0x0)                                  /* (TQNOLOADINTST) No-load condition INT status change flag False */
#define   EMMINTSTATE0_TQNOLOADINTST_TRUE_Val           _UINT16_(0x1)                                  /* (TQNOLOADINTST) No-load condition INT status change flag True */
#define EMMINTSTATE0_INOV0INTST_Pos                     _UINT16_(7)                                    /* (INOV0INTST) N line current > InWarnTh INT status change flag Position */
#define EMMINTSTATE0_INOV0INTST_Msk                     (_UINT16_(0x1) << EMMINTSTATE0_INOV0INTST_Pos)       /* (INOV0INTST) N line current > InWarnTh INT status change flag Mask */
#define EMMINTSTATE0_INOV0INTST_(value)                 (EMMINTSTATE0_INOV0INTST_Msk & (_UINT16_(value) << EMMINTSTATE0_INOV0INTST_Pos))
#define   EMMINTSTATE0_INOV0INTST_FALSE_Val             _UINT16_(0x0)                                  /* (INOV0INTST) N line current > InWarnTh INT status change flag False */
#define   EMMINTSTATE0_INOV0INTST_TRUE_Val              _UINT16_(0x1)                                  /* (INOV0INTST) N line current > InWarnTh INT status change flag True */
#define EMMINTSTATE0_IREVWNINTST_Pos                    _UINT16_(8)                                   /* (IREVWNINTST) Current Phase Sequence Error INT status change flag Position */
#define EMMINTSTATE0_IREVWNINTST_Msk                    (_UINT16_(0x1) << EMMINTSTATE0_IREVWNINTST_Pos)     /* (IREVWNINTST) Current Phase Sequence Error INT status change flag Mask */
#define EMMINTSTATE0_IREVWNINTST_(value)                (EMMINTSTATE0_IREVWNINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_IREVWNINTST_Pos))
#define   EMMINTSTATE0_IREVWNINTST_FALSE_Val            _UINT16_(0x0)                                 /* (IREVWNINTST) Current Phase Sequence Error INT status change flag False */
#define   EMMINTSTATE0_IREVWNINTST_TRUE_Val             _UINT16_(0x1)                                 /* (IREVWNINTST) Current Phase Sequence Error INT status change flag True */
#define EMMINTSTATE0_UREVWNINTST_Pos                    _UINT16_(9)                                   /* (UREVWNINTST) Voltage Phase Sequence Error INT status change flag Position */
#define EMMINTSTATE0_UREVWNINTST_Msk                    (_UINT16_(0x1) << EMMINTSTATE0_UREVWNINTST_Pos)     /* (UREVWNINTST) Voltage Phase Sequence Error INT status change flag Mask */
#define EMMINTSTATE0_UREVWNINTST_(value)                (EMMINTSTATE0_UREVWNINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_UREVWNINTST_Pos))
#define   EMMINTSTATE0_UREVWNINTST_FALSE_Val            _UINT16_(0x0)                                 /* (UREVWNINTST) Voltage Phase Sequence Error INT status change flag False */
#define   EMMINTSTATE0_UREVWNINTST_TRUE_Val             _UINT16_(0x1)                                 /* (UREVWNINTST) Voltage Phase Sequence Error INT status change flag True */
#define EMMINTSTATE0_OVPHASECINTST_Pos                  _UINT16_(10)                                  /* (OVPHASECINTST) Overvoltage on Phase C INT status change flag Position */
#define EMMINTSTATE0_OVPHASECINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_OVPHASECINTST_Pos)   /* (OVPHASECINTST) Overvoltage on Phase C INT status change flag Mask */
#define EMMINTSTATE0_OVPHASECINTST_(value)              (EMMINTSTATE0_OVPHASECINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_OVPHASECINTST_Pos))
#define   EMMINTSTATE0_OVPHASECINTST_FALSE_Val          _UINT16_(0x0)                                 /* (OVPHASECINTST) Overvoltage on Phase C INT status change flag False */
#define   EMMINTSTATE0_OVPHASECINTST_TRUE_Val           _UINT16_(0x1)                                 /* (OVPHASECINTST) Overvoltage on Phase C INT status change flag True */
#define EMMINTSTATE0_OVPHASEBINTST_Pos                  _UINT16_(12)                                  /* (OVPHASECINTST) Overvoltage on Phase B INT status change flag Position */
#define EMMINTSTATE0_OVPHASEBINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_OVPHASEBINTST_Pos)   /* (OVPHASEBINTST) Overvoltage on Phase B INT status change flag Mask */
#define EMMINTSTATE0_OVPHASEBINTST_(value)              (EMMINTSTATE0_OVPHASEBINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_OVPHASEBINTST_Pos))
#define   EMMINTSTATE0_OVPHASEBINTST_FALSE_Val          _UINT16_(0x0)                                 /* (OVPHASECINTST) Overvoltage on Phase B INT status change flag False */
#define   EMMINTSTATE0_OVPHASEBINTST_TRUE_Val           _UINT16_(0x1)                                 /* (OVPHASECINTST) Overvoltage on Phase B INT status change flag True */
#define EMMINTSTATE0_OVPHASEAINTST_Pos                  _UINT16_(12)                                  /* (OVPHASEAINTST) Overvoltage on Phase A INT status change flag Position */
#define EMMINTSTATE0_OVPHASEAINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_OVPHASEAINTST_Pos)   /* (OVPHASEAINTST) Overvoltage on Phase A INT status change flag Mask */
#define EMMINTSTATE0_OVPHASEAINTST_(value)              (EMMINTSTATE0_OVPHASEAINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_OVPHASEAINTST_Pos))
#define   EMMINTSTATE0_OVPHASEAINTST_FALSE_Val          _UINT16_(0x0)                                 /* (OVPHASEAINTST) Overvoltage on Phase A INT status change flag False */
#define   EMMINTSTATE0_OVPHASEAINTST_TRUE_Val           _UINT16_(0x1)                                 /* (OVPHASEAINTST) Overvoltage on Phase A INT status change flag True */
#define EMMINTSTATE0_OIPHASECINTST_Pos                  _UINT16_(13)                                  /* (OIPHASECINTST) Overcurrent on Phase C INT status change flag Position */
#define EMMINTSTATE0_OIPHASECINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_OIPHASECINTST_Pos)   /* (OIPHASECINTST) Overcurrent on Phase C INT status change flag Mask */
#define EMMINTSTATE0_OIPHASECINTST_(value)              (EMMINTSTATE0_OIPHASECINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_OIPHASECINTST_Pos))
#define   EMMINTSTATE0_OIPHASECINTST_FALSE_Val          _UINT16_(0x0)                                 /* (OIPHASECINTST) Overcurrent on Phase C INT status change flag False */
#define   EMMINTSTATE0_OIPHASECINTST_TRUE_Val           _UINT16_(0x1)                                 /* (OIPHASECINTST) Overcurrent on Phase C INT status change flag True */
#define EMMINTSTATE0_OIPHASEBINTST_Pos                  _UINT16_(14)                                  /* (OIPHASECINTST) Overcurrent on Phase B INT status change flag Position */
#define EMMINTSTATE0_OIPHASEBINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_OIPHASEBINTST_Pos)   /* (OIPHASEBINTST) Overcurrent on Phase B INT status change flag Mask */
#define EMMINTSTATE0_OIPHASEBINTST_(value)              (EMMINTSTATE0_OIPHASEBINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_OIPHASEBINTST_Pos))
#define   EMMINTSTATE0_OIPHASEBINTST_FALSE_Val          _UINT16_(0x0)                                 /* (OIPHASECINTST) Overcurrent on Phase B INT status change flag False */
#define   EMMINTSTATE0_OIPHASEBINTST_TRUE_Val           _UINT16_(0x1)                                 /* (OIPHASECINTST) Overcurrent on Phase B INT status change flag True */
#define EMMINTSTATE0_OIPHASEAINTST_Pos                  _UINT16_(15)                                  /* (OIPHASEAINTST) Overcurrent on Phase A INT status change flag Position */
#define EMMINTSTATE0_OIPHASEAINTST_Msk                  (_UINT16_(0x1) << EMMINTSTATE0_OIPHASEAINTST_Pos)   /* (OIPHASEAINTST) Overcurrent on Phase A INT status change flag Mask */
#define EMMINTSTATE0_OIPHASEAINTST_(value)              (EMMINTSTATE0_OIPHASEAINTST_Msk & (_UINT16_(value) << EMMINTSTATE0_OIPHASEAINTST_Pos))
#define   EMMINTSTATE0_OIPHASEAINTST_FALSE_Val          _UINT16_(0x0)                                 /* (OIPHASEAINTST) Overcurrent on Phase A INT status change flag False */
#define   EMMINTSTATE0_OIPHASEAINTST_TRUE_Val           _UINT16_(0x1)                                 /* (OIPHASEAINTST) Overcurrent on Phase A INT status change flag True */
#define EMMINTSTATE0_DEFAULT_Val                        _UINT16_(0x0)

/* -------- EMM INT STate 1 : (EMMINTSTate1 Offset: 0x74) (R - 16 bits) ATM90E32 EMM INT State 1 -------- */
#define EMMINTSTATE1_PEREGCPINTST_Pos                   _UINT16_(0)                                   /* (PEREGCPINTST) Active Energy Channel C Positive/negative INT Status change flag Position */
#define EMMINTSTATE1_PEREGCPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_PEREGCPINTST_Pos)    /* (PEREGCPINTST) Active Energy Channel C Positive/negative INT Status change flag Mask */
#define EMMINTSTATE1_PEREGCPINTST_(value)               (EMMINTSTATE1_PEREGCPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_PEREGCPINTST_Pos))
#define   EMMINTSTATE1_PEREGCPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (PEREGCPINTST) Positive/negative INT Status change flag false */
#define   EMMINTSTATE1_PEREGCPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (PEREGCPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_PEREGBPINTST_Pos                   _UINT16_(1)                                   /* (PEREGBPINTST) Active Energy Channel B Positive/negative INT Status change flagPosition */
#define EMMINTSTATE1_PEREGBPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_PEREGBPINTST_Pos)    /* (PEREGBPINTST) Active Energy Channel B Positive/negative INT Status change flag Mask */
#define EMMINTSTATE1_PEREGBPINTST_(value)               (EMMINTSTATE1_PEREGBPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_PEREGBPINTST_Pos))
#define   EMMINTSTATE1_PEREGBPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (PEREGBPINTST) Positive/negative INT Status change flag false*/
#define   EMMINTSTATE1_PEREGBPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (PEREGBPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_PEREGAPINTST_Pos                   _UINT16_(2)                                   /* (PEREGAPINTST) Active Energy Channel A Positive/negative INT Status change flag Position */
#define EMMINTSTATE1_PEREGAPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_PEREGAPINTST_Pos)    /* (PEREGAPINTST) Active Energy Channel A Positive/negative INT Status change flag Mask */
#define EMMINTSTATE1_PEREGAPINTST_(value)               (EMMINTSTATE1_PEREGAPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_PEREGAPINTST_Pos))
#define   EMMINTSTATE1_PEREGAPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (PEREGAPINTST) Positive/negative INT Status change flag false  */
#define   EMMINTSTATE1_PEREGAPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (PEREGAPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_PEREGTPINTST_Pos                   _UINT16_(3)                                   /* (PEREGTPINTST) Active Energy Sum Channels Positive INT Status change flag Position */
#define EMMINTSTATE1_PEREGTPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_PEREGTPINTST_Pos)    /* (PEREGTPINTST) Active Energy Sum Channels Positive INT Status change flag Mask */
#define EMMINTSTATE1_PEREGTPINTST_(value)               (EMMINTSTATE1_PEREGTPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_PEREGTPINTST_Pos))
#define   EMMINTSTATE1_PEREGTPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (PEREGTPINTST) Positive/negative INT Status change flag false */
#define   EMMINTSTATE1_PEREGTPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (PEREGTPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_QEREGCPINTST_Pos                   _UINT16_(4)                                   /* (QEREGCPINTST) Reactive Energy Channel C Positive INT Status change flag Position */
#define EMMINTSTATE1_QEREGCPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_QEREGCPINTST_Pos)    /* (QEREGCPINTST) Reactive Energy Channel C Positive INT Status change flag Mask */
#define EMMINTSTATE1_QEREGCPINTST_(value)               (EMMINTSTATE1_QEREGCPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_QEREGCPINTST_Pos))
#define   EMMINTSTATE1_QEREGCPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (QEREGCPINTST) Positive/negative INT Status change flag false */
#define   EMMINTSTATE1_QEREGCPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (QEREGCPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_QEREGBPINTST_Pos                   _UINT16_(5)                                   /* (QEREGBPINTST) Reactive Energy Channel B Positive INT Status change flag Position */
#define EMMINTSTATE1_QEREGBPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_QEREGBPINTST_Pos)    /* (QEREGBPINTST) Reactive Energy Channel B Positive INT Status change flag Mask */
#define EMMINTSTATE1_QEREGBPINTST_(value)               (EMMINTSTATE1_QEREGBPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_QEREGBPINTST_Pos))
#define   EMMINTSTATE1_QEREGBPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (QEREGBPINTST) Positive/negative INT Status change flag false */
#define   EMMINTSTATE1_QEREGBPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (QEREGBPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_QEREGAPINTST_Pos                   _UINT16_(6)                                   /* (QEREGAPINTST) Reactive Energy Channel A Positive INT Status change flag Position */
#define EMMINTSTATE1_QEREGAPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_QEREGAPINTST_Pos)    /* (QEREGAPINTST) Reactive Energy Channel A Positive INT Status change flag Mask */
#define EMMINTSTATE1_QEREGAPINTST_(value)               (EMMINTSTATE1_QEREGAPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_QEREGAPINTST_Pos))
#define   EMMINTSTATE1_QEREGAPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (QEREGAPINTST) Positive/negative INT Status change flag false */
#define   EMMINTSTATE1_QEREGAPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (QEREGAPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_QEREGTPINTST_Pos                   _UINT16_(7)                                   /* (QEREGTPINTST) Reactive Energy Sum Channels Positive INT Status change flag Position */
#define EMMINTSTATE1_QEREGTPINTST_Msk                   (_UINT16_(0x1) << EMMINTSTATE1_QEREGTPINTST_Pos)    /* (QEREGTPINTST) Reactive Energy Sum Channels Positive INT Status change flag Mask */
#define EMMINTSTATE1_QEREGTPINTST_(value)               (EMMINTSTATE1_QEREGTPINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_QEREGTPINTST_Pos))
#define   EMMINTSTATE1_QEREGTPINTST_FALSE_Val           _UINT16_(0x0)                                 /* (QEREGTPINTST) Positive/negative INT Status change flag false */
#define   EMMINTSTATE1_QEREGTPINTST_TRUE_Val            _UINT16_(0x1)                                 /* (QEREGTPINTST) Positive/negative INT Status change flag true */
#define EMMINTSTATE1_PHASELOSSCINTST_Pos                _UINT16_(8)                                   /* (PHASELOSSCINTST) Phase C Loss INT Status change flag Position */
#define EMMINTSTATE1_PHASELOSSCINTST_Msk                (_UINT16_(0x1) << EMMINTSTATE1_PHASELOSSCINTST_Pos) /* (PHASELOSSCINTST) Phase C Loss INT Status change flag Mask */
#define EMMINTSTATE1_PHASELOSSCINTST_(value)            (EMMINTSTATE1_PHASELOSSCINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_PHASELOSSCINTST_Pos))
#define   EMMINTSTATE1_PHASELOSSCINTST_FALSE_Val        _UINT16_(0x0)                                 /* (PHASELOSSCINTST) Phase C Loss INT Status change flag False */
#define   EMMINTSTATE1_PHASELOSSCINTST_TRUE_Val         _UINT16_(0x1)                                 /* (PHASELOSSCINTST) Phase C Loss INT Status change flag True */
#define EMMINTSTATE1_PHASELOSSBINTST_Pos                _UINT16_(9)                                   /* (PHASELOSSBINTST) Phase B Loss INT Status change flag Position */
#define EMMINTSTATE1_PHASELOSSBINTST_Msk                (_UINT16_(0x1) << EMMINTSTATE1_PHASELOSSBINTST_Pos) /* (PHASELOSSBINTST) Phase B Loss INT Status change flag Mask */
#define EMMINTSTATE1_PHASELOSSBINTST_(value)            (EMMINTSTATE1_PHASELOSSBINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_PHASELOSSBINTST_Pos))
#define   EMMINTSTATE1_PHASELOSSBINTST_FALSE_Val        _UINT16_(0x0)                                 /* (PHASELOSSBINTST) Phase B Loss INT Status change flag False */
#define   EMMINTSTATE1_PHASELOSSBINTST_TRUE_Val         _UINT16_(0x1)                                 /* (PHASELOSSBINTST) Phase B Loss INT Status change flag True */
#define EMMINTSTATE1_PHASELOSSAINTST_Pos                _UINT16_(10)                                  /* (PHASELOSSAINTST) Phase A Loss INT Status change flag Position */
#define EMMINTSTATE1_PHASELOSSAINTST_Msk                (_UINT16_(0x1) << EMMINTSTATE1_PHASELOSSAINTST_Pos) /* (PHASELOSSAINTST) Phase A Loss INT Status change flag Mask */
#define EMMINTSTATE1_PHASELOSSAINTST_(value)            (EMMINTSTATE1_PHASELOSSAINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_PHASELOSSAINTST_Pos))
#define   EMMINTSTATE1_PHASELOSSAINTST_FALSE_Val        _UINT16_(0x0)                                 /* (PHASELOSSAINTST) Phase A Loss INT Status change flag False */
#define   EMMINTSTATE1_PHASELOSSAINTST_TRUE_Val         _UINT16_(0x1)                                 /* (PHASELOSSAINTST) Phase A Loss INT Status change flag True */
#define EMMINTSTATE1_FREQLOINTST_Pos                    _UINT16_(11)                                  /* (FREQLOINTST) Frequency Below Range INT Status change flag Position */
#define EMMINTSTATE1_FREQLOINTST_Msk                    (_UINT16_(0x1) << EMMINTSTATE1_FREQLOINTST_Pos)     /* (FREQLOINTST) Frequency Below Range INT Status change flag Mask */
#define EMMINTSTATE1_FREQLOINTST_(value)                (EMMINTSTATE1_FREQLOINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_FREQLOINTST_Pos))
#define   EMMINTSTATE1_FREQLOINTST_FALSE_Val            _UINT16_(0x0)                                 /* (FREQLOINTST) Frequency Below Range INT Status change flag False */
#define   EMMINTSTATE1_FREQLOINTST_TRUE_Val             _UINT16_(0x1)                                 /* (FREQLOINTST) Frequency Below Range INT Status change flag True */
#define EMMINTSTATE1_SAGPHASECINTST_Pos                 _UINT16_(12)                                  /* (SAGPHASECINTST) Phase C SAG INT Status change flag Position */
#define EMMINTSTATE1_SAGPHASECINTST_Msk                 (_UINT16_(0x1) << EMMINTSTATE1_SAGPHASECINTST_Pos)  /* (SAGPHASECINTST) Phase C SAG INT Status change flag Mask */
#define EMMINTSTATE1_SAGPHASECINTST_(value)             (EMMINTSTATE1_SAGPHASECINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_SAGPHASECINTST_Pos))
#define   EMMINTSTATE1_SAGPHASECINTST_FALSE_Val         _UINT16_(0x0)                                 /* (SAGPHASECINTST) Phase C SAG INT Status change flag False */
#define   EMMINTSTATE1_SAGPHASECINTST_TRUE_Val          _UINT16_(0x1)                                 /* (SAGPHASECINTST) Phase C SAG Range INT Status change flag True */
#define EMMINTSTATE1_SAGPHASEBINTST_Pos                 _UINT16_(13)                                  /* (SAGPHASEBINTST) Phase B SAG INT Status change flag Position */
#define EMMINTSTATE1_SAGPHASEBINTST_Msk                 (_UINT16_(0x1) << EMMINTSTATE1_SAGPHASEBINTST_Pos)  /* (SAGPHASEBINTST) Phase B SAG INT Status change flag Mask */
#define EMMINTSTATE1_SAGPHASEBINTST_(value)             (EMMINTSTATE1_SAGPHASEBINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_SAGPHASEBINTST_Pos))
#define   EMMINTSTATE1_SAGPHASEBINTST_FALSE_Val         _UINT16_(0x0)                                 /* (SAGPHASEBINTST) Phase B SAG INT Status change flag False */
#define   EMMINTSTATE1_SAGPHASEBINTST_TRUE_Val          _UINT16_(0x1)                                 /* (SAGPHASEBINTST) Phase B SAG Range INT Status change flag True */
#define EMMINTSTATE1_SAGPHASEAINTST_Pos                 _UINT16_(14)                                  /* (SAGPHASEAINTST) Phase A SAG INT Status change flag Position */
#define EMMINTSTATE1_SAGPHASEAINTST_Msk                 (_UINT16_(0x1) << EMMINTSTATE1_SAGPHASEAINTST_Pos)  /* (SAGPHASEAINTST) Phase A SAG INT Status change flag Mask */
#define EMMINTSTATE1_SAGPHASEAINTST_(value)             (EMMINTSTATE1_SAGPHASEAINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_SAGPHASEAINTST_Pos))
#define   EMMINTSTATE1_SAGPHASEAINTST_FALSE_Val         _UINT16_(0x0)                                 /* (SAGPHASEAINTST) Phase A SAG INT Status change flag False */
#define   EMMINTSTATE1_SAGPHASEAINTST_TRUE_Val          _UINT16_(0x1)                                 /* (SAGPHASEAINTST) Phase A SAG Range INT Status change flag True */
#define EMMINTSTATE1_FREQHIINTST_Pos                    _UINT16_(15)                                  /* (FREQHIINTST) Frequency Above Range INT Status change flag Position */
#define EMMINTSTATE1_FREQHIINTST_Msk                    (_UINT16_(0x1) << EMMINTSTATE1_FREQHIINTST_Pos)     /* (FREQHIINTST) Frequency Above Range INT Status change flag Mask */
#define EMMINTSTATE1_FREQHIINTST_(value)                (EMMINTSTATE1_FREQHIINTST_Msk & (_UINT16_(value) << EMMINTSTATE1_FREQHIINTST_Pos))
#define   EMMINTSTATE1_FREQHIINTST_FALSE_Val            _UINT16_(0x0)                                 /* (FREQHIINTST) Frequency Above Range INT Status change flag False */
#define   EMMINTSTATE1_FREQHIINTST_TRUE_Val             _UINT16_(0x1)                                 /* (FREQHIINTST) Frequency Above Range INT Status change flag True */
#define EMMINTSTATE1_DEFAULT_Val                        _UINT16_(0x0)

/* -------- EMM Int Enable 0 : (EMMIntEn0 Offset: 0x75) (R - 16 bits) ATM90E32 EMM Interrupt Enable 0 -------- */
#define EMMINTEN0_CF4REVINTEN_Pos                    _UINT16_(0)                                     /* (CF4REVINTEN) CF4 output Forward/Reverse change status INT flag Position */
#define EMMINTEN0_CF4REVINTEN_Msk                    (_UINT16_(0x1) << EMMINTEN0_CF4REVINTEN_Pos)    /* (CF4REVINTEN) CF4 output Forward/Reverse change status INT flag Mask */
#define EMMINTEN0_CF4REVINTEN_(value)                (EMMINTEN0_CF4REVINTEN_Msk & (_UINT16_(value) << EMMINTEN0_CF4REVINTEN_Pos))
#define   EMMINTEN0_CF4REVINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (CF4REVINTEN) CF4 output forward/reverse change status INT flag Disable */
#define   EMMINTEN0_CF4REVINTEN_EN_Val          	 _UINT16_(0x1)                                   /* (CF4REVINTEN) CF4 output forward/reverse change status INT flag Enable */
#define EMMINTEN0_CF3REVINTEN_Pos                    _UINT16_(1)                                     /* (CF3REVINTEN) CF3 output Forward/Reverse change status INT flag Position */
#define EMMINTEN0_CF3REVINTEN_Msk                    (_UINT16_(0x1) << EMMINTEN0_CF3REVINTEN_Pos)    /* (CF3REVINTEN) CF3 output Forward/Reverse change status INT flag Mask */
#define EMMINTEN0_CF3REVINTEN_(value)                (EMMINTEN0_CF3REVINTEN_Msk & (_UINT16_(value) << EMMINTEN0_CF3REVINTEN_Pos))
#define   EMMINTEN0_CF3REVINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (CF3REVINTEN) CF3 output forward/reverse change status INT flag Disable */
#define   EMMINTEN0_CF3REVINTEN_EN_Val          	 _UINT16_(0x1)                                   /* (CF3REVINTEN) CF3 output forward/reverse change status INT flag Enable */
#define EMMINTEN0_CF2REVINTEN_Pos                    _UINT16_(2)                                     /* (CF2REVINTEN) CF2 output Forward/Reverse change status INT flag Position */
#define EMMINTEN0_CF2EVINTEN_Msk                     (_UINT16_(0x1) << EMMINTEN0_CF2REVINTEN_Pos)    /* (CF2REVINTEN) CF2 output Forward/Reverse change status INT flag Mask */
#define EMMINTEN0_CF2REVINTEN_(value)                (EMMINTEN0_CF2REVINTEN_Msk & (_UINT16_(value) << EMMINTEN0_CF2REVINTEN_Pos))
#define   EMMINTEN0_CF2REVINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (CF2REVINTEN) CF2 output forward/reverse change status INT flag Disable */
#define   EMMINTEN0_CF2REVINTEN_EN_Val          	 _UINT16_(0x1)                                   /* (CF2REVINTEN) CF2 output forward/reverse change status INT flag Enable */
#define EMMINTEN0_CF1REVINTEN_Pos                    _UINT16_(3)                                     /* (CF1REVINTEN) CF1 output Forward/Reverse change status INT flag Position */
#define EMMINTEN0_CF1REVINTEN_Msk                    (_UINT16_(0x1) << EMMINTEN0_CF1REVINTEN_Pos)    /* (CF1REVINTEN) CF1 output Forward/Reverse change status INT flag Mask */
#define EMMINTEN0_CF1REVINTEN_(value)                (EMMINTEN0_CF1REVINTEN_Msk & (_UINT16_(value) << EMMINTEN0_CF1REVINTEN_Pos))
#define   EMMINTEN0_CF1REVINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (CF1REVINTEN) CF1 output forward/reverse change status INT flag Disable */
#define   EMMINTEN0_CF1REVINTEN_EN_Val          	 _UINT16_(0x1)                                   /* (CF1REVINTEN) CF1 output forward/reverse change status INT flag Enable */
#define EMMINTEN0_TASNOLOADINTEN_Pos                 _UINT16_(4)                                     /* (TASNOLOADINTEN) All phase arithmetic sum apparent power no-load condition change status INT flag Position */
#define EMMINTEN0_TASNOLOADINTEN_Msk                 (_UINT16_(0x1) << EMMINTEN0_TASNOLOADINTEN_Pos) /* (TASNOLOADINTEN) All phase arithmetic sum apparent power no-load condition change status INT flag Mask */
#define EMMINTEN0_TASNOLOADINTEN_(value)             (EMMINTEN0_TASNOLOADINTEN_Msk & (_UINT16_(value) << EMMINTEN0_TASNOLOADINTEN_Pos))
#define   EMMINTEN0_TASNOLOADINTEN_DIS_Val         	 _UINT16_(0x0)                                   /* (TASNOLOADINTEN) No-load condition change status INT flag Disable */
#define   EMMINTEN0_TASNOLOADINTEN_EN_Val          	 _UINT16_(0x1)                                   /* (TASNOLOADINTEN) No-load condition change status INT flag Enable */
#define EMMINTEN0_TPNOLOADINTEN_Pos                  _UINT16_(5)                                     /* (TPNOLOADINTEN) All phase sum active power no-load condition change status INT flag Position */
#define EMMINTEN0_TPNOLOADINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_TPNOLOADINTEN_Pos)  /* (TPNOLOADINTEN) All phase sum active power no-load condition change status INT flag Mask */
#define EMMINTEN0_TPNOLOADINTEN_(value)              (EMMINTEN0_TPNOLOADINTEN_Msk & (_UINT16_(value) << EMMINTEN0_TPNOLOADINTEN_Pos))
#define   EMMINTEN0_TPNOLOADINTEN_DIS_Val            _UINT16_(0x0)                                   /* (TPNOLOADINTEN) No-load condition change status INT flag Disable */
#define   EMMINTEN0_TPNOLOADINTEN_EN_Val           	 _UINT16_(0x1)                                   /* (TPNOLOADINTEN) No-load condition change status INT flag Enable */
#define EMMINTEN0_TQNOLOADINTEN_Pos                  _UINT16_(6)                                     /* (TPNOLOADINTEN) All phase sum reactive power no-load condition change status INT flag Position */
#define EMMINTEN0_TQNOLOADINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_TQNOLOADINTEN_Pos)  /* (TQNOLOADINTEN) All phase sum reactive power no-load condition change status INT flag Mask */
#define EMMINTEN0_TQNOLOADINTEN_(value)              (EMMINTEN0_TQNOLOADINTEN_Msk & (_UINT16_(value) << EMMINTEN0_TQNOLOADINTEN_Pos))
#define   EMMINTEN0_TQNOLOADINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (TQNOLOADINTEN) No-load condition change status INT flag Disable */
#define   EMMINTEN0_TQNOLOADINTEN_EN_Val           	 _UINT16_(0x1)                                   /* (TQNOLOADINTEN) No-load condition change status INT flag Enable */
#define EMMINTEN0_INOV0INTEN_Pos                     _UINT16_(7)                                     /* (INOV0INTEN) N line current > InWarnTh change status INT flag Position */
#define EMMINTEN0_INOV0INTEN_Msk                     (_UINT16_(0x1) << EMMINTEN0_INOV0INTEN_Pos)     /* (INOV0INTEN) N line current > InWarnTh change status INT flag Mask */
#define EMMINTEN0_INOV0INTEN_(value)                 (EMMINTEN0_INOV0INTEN_Msk & (_UINT16_(value) << EMMINTEN0_INOV0INTEN_Pos))
#define   EMMINTEN0_INOV0INTEN_DIS_Val             	 _UINT16_(0x0)                                   /* (INOV0INTEN) N line current > InWarnTh change status INT flag Disable */
#define   EMMINTEN0_INOV0INTEN_EN_Val              	 _UINT16_(0x1)                                   /* (INOV0INTEN) N line current > InWarnTh change status INT flag Enable */
#define EMMINTEN0_IREVWNINTEN_Pos                    _UINT16_(8)                                     /* (IREVWNINTEN) Current Phase Sequence Error change status INT flag Position */
#define EMMINTEN0_IREVWNINTEN_Msk                    (_UINT16_(0x1) << EMMINTEN0_IREVWNINTEN_Pos)    /* (IREVWNINTEN) Current Phase Sequence Error change status INT flag Mask */
#define EMMINTEN0_IREVWNINTEN_(value)                (EMMINTEN0_IREVWNINTEN_Msk & (_UINT16_(value) << EMMINTEN0_IREVWNINTEN_Pos))
#define   EMMINTEN0_IREVWNINTEN_DIS_Val            	 _UINT16_(0x0)                                   /* (IREVWNINTEN) Current Phase Sequence Error change status INT flag Disable */
#define   EMMINTEN0_IREVWNINTEN_EN_Val             	 _UINT16_(0x1)                                   /* (IREVWNINTEN) Current Phase Sequence Error change status INT flag Enable */
#define EMMINTEN0_UREVWNINTEN_Pos                    _UINT16_(9)                                     /* (UREVWNINTEN) Voltage Phase Sequence Error change status INT flag Position */
#define EMMINTEN0_UREVWNINTEN_Msk                    (_UINT16_(0x1) << EMMINTEN0_UREVWNINTEN_Pos)    /* (UREVWNINTEN) Voltage Phase Sequence Error change status INT flag Mask */
#define EMMINTEN0_UREVWNINTEN_(value)                (EMMINTEN0_UREVWNINTEN_Msk & (_UINT16_(value) << EMMINTEN0_UREVWNINTEN_Pos))
#define   EMMINTEN0_UREVWNINTEN_DIS_Val            	 _UINT16_(0x0)                                   /* (UREVWNINTEN) Voltage Phase Sequence Error change status INT flag Disable */
#define   EMMINTEN0_UREVWNINTEN_EN_Val             	 _UINT16_(0x1)                                   /* (UREVWNINTEN) Voltage Phase Sequence Error change status INT flag Enable */
#define EMMINTEN0_OVPHASECINTEN_Pos                  _UINT16_(10)                                    /* (OVPHASECINTEN) Overvoltage on Phase C change status INT flag Position */
#define EMMINTEN0_OVPHASECINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_OVPHASECINTEN_Pos)  /* (OVPHASECINTEN) Overvoltage on Phase C change status INT flag Mask */
#define EMMINTEN0_OVPHASECINTEN_(value)              (EMMINTEN0_OVPHASECINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OVPHASECINTEN_Pos))
#define   EMMINTEN0_OVPHASECINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (OVPHASECINTEN) Overvoltage on Phase C change status INT flag Disable */
#define   EMMINTEN0_OVPHASECINTEN_EN_Val           	 _UINT16_(0x1)                                   /* (OVPHASECINTEN) Overvoltage on Phase C change status INT flag Enable */
#define EMMINTEN0_OVPHASEBINTEN_Pos                  _UINT16_(11)                                    /* (OVPHASECINTEN) Overvoltage on Phase B change status INT flag Position */
#define EMMINTEN0_OVPHASEBINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_OVPHASEBINTEN_Pos)  /* (OVPHASEBINTEN) Overvoltage on Phase B change status INT flag Mask */
#define EMMINTEN0_OVPHASEBINTEN_(value)              (EMMINTEN0_OVPHASEBINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OVPHASEBINTEN_Pos))
#define   EMMINTEN0_OVPHASEBINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (OVPHASECINTEN) Overvoltage on Phase B change status INT flag Disable */
#define   EMMINTEN0_OVPHASEBINTEN_EN_Val           	 _UINT16_(0x1)                                   /* (OVPHASECINTEN) Overvoltage on Phase B change status INT flag Enable */
#define EMMINTEN0_OVPHASEAINTEN_Pos                  _UINT16_(12)                                    /* (OVPHASEAINTEN) Overvoltage on Phase A change status INT flag Position */
#define EMMINTEN0_OVPHASEAINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_OVPHASEAINTEN_Pos)  /* (OVPHASEAINTEN) Overvoltage on Phase A change status INT flag Mask */
#define EMMINTEN0_OVPHASEAINTEN_(value)              (EMMINTEN0_OVPHASEAINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OVPHASEAINTEN_Pos))
#define   EMMINTEN0_OVPHASEAINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (OVPHASEAINTEN) Overvoltage on Phase A change status INT flag Disable */
#define   EMMINTEN0_OVPHASEAINTEN_EN_Val           	 _UINT16_(0x1)                                   /* (OVPHASEAINTEN) Overvoltage on Phase A change status INT flag Enable */
#define EMMINTEN0_OVALLINTEN_Pos                     _UINT16_(10)                                    /* (OVALLINTEN) Overvoltage on All Phases change status INT flag Position */
#define EMMINTEN0_OVALLINTEN_Msk                     (_UINT16_(0x7) << EMMINTEN0_OVALLINTEN_Pos)     /* (OVALLINTEN) Overvoltage on All Phases change status INT flag Mask */
#define EMMINTEN0_OVALLINTEN_(value)                 (EMMINTEN0_OVALLINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OVALLINTEN_Pos))
#define   EMMINTEN0_OVALLINTEN_DIS_Val               _UINT16_(0x0)                                   /* (OVALLINTEN) Overvoltage on All Phases change status INT flag Disable */
#define   EMMINTEN0_OVALLINTEN_EN_Val                _UINT16_(0x7)                                   /* (OVALLINTEN) Overvoltage on All Phases change status INT flag Enable */
#define EMMINTEN0_OIPHASECINTEN_Pos                  _UINT16_(13)                                    /* (OIPHASECINTEN) Overcurrent on Phase C change status INT flag Position */
#define EMMINTEN0_OIPHASECINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_OIPHASECINTEN_Pos)  /* (OIPHASECINTEN) Overcurrent on Phase C change status INT flag Mask */
#define EMMINTEN0_OIPHASECINTEN_(value)              (EMMINTEN0_OIPHASECINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OIPHASECINTEN_Pos))
#define   EMMINTEN0_OIPHASECINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (OIPHASECINTEN) Overcurrent on Phase C change status INT flag Disable */
#define   EMMINTEN0_OIPHASECINTEN_EN_Val           	 _UINT16_(0x1)                                   /* (OIPHASECINTEN) Overcurrent on Phase C change status INT flag Enable */
#define EMMINTEN0_OIPHASEBINTEN_Pos                  _UINT16_(14)                                    /* (OIPHASECINTEN) Overcurrent on Phase B change status INT flag Position */
#define EMMINTEN0_OIPHASEBINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_OIPHASEBINTEN_Pos)  /* (OIPHASEBINTEN) Overcurrent on Phase B change status INT flag Mask */
#define EMMINTEN0_OIPHASEBINTEN_(value)              (EMMINTEN0_OIPHASEBINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OIPHASEBINTEN_Pos))
#define   EMMINTEN0_OIPHASEBINTEN_DIS_Val            _UINT16_(0x0)                                   /* (OIPHASECINTEN) Overcurrent on Phase B change status INT flag Disable */
#define   EMMINTEN0_OIPHASEBINTEN_EN_Val           	 _UINT16_(0x1)                                   /* (OIPHASECINTEN) Overcurrent on Phase B change status INT flag Enable */
#define EMMINTEN0_OIPHASEAINTEN_Pos                  _UINT16_(15)                                    /* (OIPHASEAINTEN) Overcurrent on Phase A change status INT flag Position */
#define EMMINTEN0_OIPHASEAINTEN_Msk                  (_UINT16_(0x1) << EMMINTEN0_OIPHASEAINTEN_Pos)  /* (OIPHASEAINTEN) Overcurrent on Phase A change status INT flag Mask */
#define EMMINTEN0_OIPHASEAINTEN_(value)              (EMMINTEN0_OIPHASEAINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OIPHASEAINTEN_Pos))
#define   EMMINTEN0_OIPHASEAINTEN_DIS_Val          	 _UINT16_(0x0)                                   /* (OIPHASEAINTEN) Overcurrent on Phase A change status INT flag Disable */
#define   EMMINTEN0_OIPHASEAINTEN_EN_Val          	 _UINT16_(0x1)                                   /* (OIPHASEAINTEN) Overcurrent on Phase A change status INT flag Enable */
#define EMMINTEN0_OIALLINTEN_Pos                     _UINT16_(13)                                    /* (OIPHASEAINTEN) Overcurrent on All Phases change status INT flag Position */
#define EMMINTEN0_OIALLINTEN_Msk                     (_UINT16_(0x7) << EMMINTEN0_OIALLINTEN_Pos)     /* (OIALLINTEN) Overcurrent on All Phases change status INT flag Mask */
#define EMMINTEN0_OIALLINTEN_(value)                 (EMMINTEN0_OIALLINTEN_Msk & (_UINT16_(value) << EMMINTEN0_OIALLINTEN_Pos))
#define   EMMINTEN0_OIALLINTEN_DIS_Val               _UINT16_(0x0)                                   /* (OIALLINTEN) Overcurrent on All Phases change status INT flag Disable */
#define   EMMINTEN0_OIALLINTEN_EN_Val                _UINT16_(0x7)                                   /* (OIALLINTEN) Overcurrent on Phase A change status INT flag Enable */
#define EMMINTEN0_DEFAULT_Val                        _UINT16_(0x0)

/* -------- EMM Int Enable 1 : (EMMIntEn1 Offset: 0x76) (R - 16 bits) ATM90E32 EMM Interrupt Enable 1 -------- */
#define EMMINTEN1_PEREGCPINTEN_Pos                   _UINT16_(0)                                   /* (PEREGCPINTEN) Active Energy Channel C Positive/negative INT Status change flag Position */
#define EMMINTEN1_PEREGCPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_PEREGCPINTEN_Pos)    /* (PEREGCPINTEN) Active Energy Channel C Positive/negative INT Status change flag Mask */
#define EMMINTEN1_PEREGCPINTEN_(value)               (EMMINTEN1_PEREGCPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PEREGCPINTEN_Pos))
#define   EMMINTEN1_PEREGCPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (PEREGCPINTEN) Positive/negative INT Status change flag false */
#define   EMMINTEN1_PEREGCPINTEN_EN_Val              _UINT16_(0x1)                                 /* (PEREGCPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_PEREGBPINTEN_Pos                   _UINT16_(1)                                   /* (PEREGBPINTEN) Active Energy Channel B Positive/negative INT Status change flagPosition */
#define EMMINTEN1_PEREGBPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_PEREGBPINTEN_Pos)    /* (PEREGBPINTEN) Active Energy Channel B Positive/negative INT Status change flag Mask */
#define EMMINTEN1_PEREGBPINTEN_(value)               (EMMINTEN1_PEREGBPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PEREGBPINTEN_Pos))
#define   EMMINTEN1_PEREGBPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (PEREGBPINTEN) Positive/negative INT Status change flag false*/
#define   EMMINTEN1_PEREGBPINTEN_EN_Val              _UINT16_(0x1)                                 /* (PEREGBPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_PEREGAPINTEN_Pos                   _UINT16_(2)                                   /* (PEREGAPINTEN) Active Energy Channel A Positive/negative INT Status change flag Position */
#define EMMINTEN1_PEREGAPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_PEREGAPINTEN_Pos)    /* (PEREGAPINTEN) Active Energy Channel A Positive/negative INT Status change flag Mask */
#define EMMINTEN1_PEREGAPINTEN_(value)               (EMMINTEN1_PEREGAPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PEREGAPINTEN_Pos))
#define   EMMINTEN1_PEREGAPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (PEREGAPINTEN) Positive/negative INT Status change flag false  */
#define   EMMINTEN1_PEREGAPINTEN_EN_Val              _UINT16_(0x1)                                 /* (PEREGAPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_PEREGTPINTEN_Pos                   _UINT16_(3)                                   /* (PEREGTPINTEN) Active Energy Sum Channels Positive INT Status change flag Position */
#define EMMINTEN1_PEREGTPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_PEREGTPINTEN_Pos)    /* (PEREGTPINTEN) Active Energy Sum Channels Positive INT Status change flag Mask */
#define EMMINTEN1_PEREGTPINTEN_(value)               (EMMINTEN1_PEREGTPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PEREGTPINTEN_Pos))
#define   EMMINTEN1_PEREGTPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (PEREGTPINTEN) Positive/negative INT Status change flag false */
#define   EMMINTEN1_PEREGTPINTEN_EN_Val              _UINT16_(0x1)                                 /* (PEREGTPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_QEREGCPINTEN_Pos                   _UINT16_(4)                                   /* (QEREGCPINTEN) Reactive Energy Channel C Positive INT Status change flag Position */
#define EMMINTEN1_QEREGCPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_QEREGCPINTEN_Pos)    /* (QEREGCPINTEN) Reactive Energy Channel C Positive INT Status change flag Mask */
#define EMMINTEN1_QEREGCPINTEN_(value)               (EMMINTEN1_QEREGCPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_QEREGCPINTEN_Pos))
#define   EMMINTEN1_QEREGCPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (QEREGCPINTEN) Positive/negative INT Status change flag false */
#define   EMMINTEN1_QEREGCPINTEN_EN_Val              _UINT16_(0x1)                                 /* (QEREGCPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_QEREGBPINTEN_Pos                   _UINT16_(5)                                   /* (QEREGBPINTEN) Reactive Energy Channel B Positive INT Status change flag Position */
#define EMMINTEN1_QEREGBPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_QEREGBPINTEN_Pos)    /* (QEREGBPINTEN) Reactive Energy Channel B Positive INT Status change flag Mask */
#define EMMINTEN1_QEREGBPINTEN_(value)               (EMMINTEN1_QEREGBPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_QEREGBPINTEN_Pos))
#define   EMMINTEN1_QEREGBPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (QEREGBPINTEN) Positive/negative INT Status change flag false */
#define   EMMINTEN1_QEREGBPINTEN_EN_Val              _UINT16_(0x1)                                 /* (QEREGBPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_QEREGAPINTEN_Pos                   _UINT16_(6)                                   /* (QEREGAPINTEN) Reactive Energy Channel A Positive INT Status change flag Position */
#define EMMINTEN1_QEREGAPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_QEREGAPINTEN_Pos)    /* (QEREGAPINTEN) Reactive Energy Channel A Positive INT Status change flag Mask */
#define EMMINTEN1_QEREGAPINTEN_(value)               (EMMINTEN1_QEREGAPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_QEREGAPINTEN_Pos))
#define   EMMINTEN1_QEREGAPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (QEREGAPINTEN) Positive/negative INT Status change flag false */
#define   EMMINTEN1_QEREGAPINTEN_EN_Val              _UINT16_(0x1)                                 /* (QEREGAPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_QEREGTPINTEN_Pos                   _UINT16_(7)                                   /* (QEREGTPINTEN) Reactive Energy Sum Channels Positive INT Status change flag Position */
#define EMMINTEN1_QEREGTPINTEN_Msk                   (_UINT16_(0x1) << EMMINTEN1_QEREGTPINTEN_Pos)    /* (QEREGTPINTEN) Reactive Energy Sum Channels Positive INT Status change flag Mask */
#define EMMINTEN1_QEREGTPINTEN_(value)               (EMMINTEN1_QEREGTPINTEN_Msk & (_UINT16_(value) << EMMINTEN1_QEREGTPINTEN_Pos))
#define   EMMINTEN1_QEREGTPINTEN_DIS_Val             _UINT16_(0x0)                                 /* (QEREGTPINTEN) Positive/negative INT Status change flag false */
#define   EMMINTEN1_QEREGTPINTEN_EN_Val              _UINT16_(0x1)                                 /* (QEREGTPINTEN) Positive/negative INT Status change flag true */
#define EMMINTEN1_PHASELOSSCINTEN_Pos                _UINT16_(8)                                   /* (PHASELOSSCINTEN) Phase C Loss INT Status change flag Position */
#define EMMINTEN1_PHASELOSSCINTEN_Msk                (_UINT16_(0x1) << EMMINTEN1_PHASELOSSCINTEN_Pos) /* (PHASELOSSCINTEN) Phase C Loss INT Status change flag Mask */
#define EMMINTEN1_PHASELOSSCINTEN_(value)            (EMMINTEN1_PHASELOSSCINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PHASELOSSCINTEN_Pos))
#define   EMMINTEN1_PHASELOSSCINTEN_DIS_Val          _UINT16_(0x0)                                 /* (PHASELOSSCINTEN) Phase C Loss INT Status change flag False */
#define   EMMINTEN1_PHASELOSSCINTEN_EN_Val           _UINT16_(0x1)                                 /* (PHASELOSSCINTEN) Phase C Loss INT Status change flag True */
#define EMMINTEN1_PHASELOSSBINTEN_Pos                _UINT16_(9)                                   /* (PHASELOSSBINTEN) Phase B Loss INT Status change flag Position */
#define EMMINTEN1_PHASELOSSBINTEN_Msk                (_UINT16_(0x1) << EMMINTEN1_PHASELOSSBINTEN_Pos) /* (PHASELOSSBINTEN) Phase B Loss INT Status change flag Mask */
#define EMMINTEN1_PHASELOSSBINTEN_(value)            (EMMINTEN1_PHASELOSSBINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PHASELOSSBINTEN_Pos))
#define   EMMINTEN1_PHASELOSSBINTEN_DIS_Val          _UINT16_(0x0)                                 /* (PHASELOSSBINTEN) Phase B Loss INT Status change flag False */
#define   EMMINTEN1_PHASELOSSBINTEN_EN_Val           _UINT16_(0x1)                                 /* (PHASELOSSBINTEN) Phase B Loss INT Status change flag True */
#define EMMINTEN1_PHASELOSSAINTEN_Pos                _UINT16_(10)                                  /* (PHASELOSSAINTEN) Phase A Loss INT Status change flag Position */
#define EMMINTEN1_PHASELOSSAINTEN_Msk                (_UINT16_(0x1) << EMMINTEN1_PHASELOSSAINTEN_Pos) /* (PHASELOSSAINTEN) Phase A Loss INT Status change flag Mask */
#define EMMINTEN1_PHASELOSSAINTEN_(value)            (EMMINTEN1_PHASELOSSAINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PHASELOSSAINTEN_Pos))
#define   EMMINTEN1_PHASELOSSAINTEN_DIS_Val          _UINT16_(0x0)                                 /* (PHASELOSSAINTEN) Phase A Loss INT Status change flag False */
#define   EMMINTEN1_PHASELOSSAINTEN_EN_Val           _UINT16_(0x1)                                 /* (PHASELOSSAINTEN) Phase A Loss INT Status change flag True */
#define EMMINTEN1_PHASELOSSALLINTEN_Pos              _UINT16_(8)                                   /* (PHASELOSSALL) All Phases Phase Loss Detection Interrupt enable/disable Position */
#define EMMINTEN1_PHASELOSSALLINTEN_Msk              (_UINT16_(0x7) << EMMINTEN1_PHASELOSSALLINTEN_Pos)  /* (PHASELOSSALL) All Phases Phase Loss Detection Interrupt enable/disable Mask */
#define EMMINTEN1_PHASELOSSALLINTEN_(value)          (EMMINTEN1_PHASELOSSPALLINTEN_Msk & (_UINT16_(value) << EMMINTEN1_PHASELOSSALLINTEN_Pos))
#define   EMMINTEN1_PHASELOSSALLINTEN_DIS_Val        _UINT16_(0x0)                                 /* (PHASELOSSALL) All Phases Phase Loss Detection Interrupt disabled */
#define   EMMINTEN1_PHASELOSSALLINTEN_EN_Val         _UINT16_(0x7)                                 /* (PHASELOSSALL) All Phases Phase Loss Detection Interrupt enabled */
#define EMMINTEN1_FREQLOINTEN_Pos                    _UINT16_(11)                                  /* (FREQLOINTEN) Frequency Below Range INT Status change flag Position */
#define EMMINTEN1_FREQLOINTEN_Msk                    (_UINT16_(0x1) << EMMINTEN1_FREQLOINTEN_Pos)     /* (FREQLOINTEN) Frequency Below Range INT Status change flag Mask */
#define EMMINTEN1_FREQLOINTEN_(value)                (EMMINTEN1_FREQLOINTEN_Msk & (_UINT16_(value) << EMMINTEN1_FREQLOINTEN_Pos))
#define   EMMINTEN1_FREQLOINTEN_DIS_Val              _UINT16_(0x0)                                 /* (FREQLOINTEN) Frequency Below Range INT Status change flag False */
#define   EMMINTEN1_FREQLOINTEN_EN_Val               _UINT16_(0x1)                                 /* (FREQLOINTEN) Frequency Below Range INT Status change flag True */
#define EMMINTEN1_SAGPHASECINTEN_Pos                 _UINT16_(12)                                  /* (SAGPHASECINTEN) Phase C SAG Detection Interrupt enable/disable Position */
#define EMMINTEN1_SAGPHASECINTEN_Msk                 (_UINT16_(0x1) << EMMINTEN1_SAGPHASECINTEN_Pos)  /* (SAGPHASECINTEN) Phase C SAG Detection Interrupt enable/disable Mask */
#define EMMINTEN1_SAGPHASECINTEN_(value)             (EMMINTEN1_SAGPHASECINTEN_Msk & (_UINT16_(value) << EMMINTEN1_SAGPHASECINTEN_Pos))
#define   EMMINTEN1_SAGPHASECINTEN_DIS_Val           _UINT16_(0x0)                                 /* (SAGPHASECINTEN) Phase C SAG Detection Interrupt disabled */
#define   EMMINTEN1_SAGPHASECINTEN_EN_Val            _UINT16_(0x1)                                 /* (SAGPHASECINTEN) Phase C SAG Detection Interrupt enabled */
#define EMMINTEN1_SAGPHASEBINTEN_Pos                 _UINT16_(13)                                  /* (SAGPHASEBINTEN) Phase B SAG Detection Interrupt enable/disable Position */
#define EMMINTEN1_SAGPHASEBINTEN_Msk                 (_UINT16_(0x1) << EMMINTEN1_SAGPHASEBINTEN_Pos)  /* (SAGPHASEBINTEN) Phase B SAG Detection Interrupt enable/disable Mask */
#define EMMINTEN1_SAGPHASEBINTEN_(value)             (EMMINTEN1_SAGPHASEBINTEN_Msk & (_UINT16_(value) << EMMINTEN1_SAGPHASEBINTEN_Pos))
#define   EMMINTEN1_SAGPHASEBINTEN_DIS_Val           _UINT16_(0x0)                                 /* (SAGPHASEBINTEN) Phase B SAG Detection Interrupt disabled */
#define   EMMINTEN1_SAGPHASEBINTEN_EN_Val            _UINT16_(0x1)                                 /* (SAGPHASEBINTEN) Phase B SAG Detection Interrupt enabled */
#define EMMINTEN1_SAGPHASEAINTEN_Pos                 _UINT16_(14)                                  /* (SAGPHASEAINTEN) Phase A SAG Detection Interrupt enable/disable Position */
#define EMMINTEN1_SAGPHASEAINTEN_Msk                 (_UINT16_(0x1) << EMMINTEN1_SAGPHASEAINTEN_Pos)  /* (SAGPHASEAINTEN) Phase A SAG INT Status change flag Mask */
#define EMMINTEN1_SAGPHASEAINTEN_(value)             (EMMINTEN1_SAGPHASEAINTEN_Msk & (_UINT16_(value) << EMMINTEN1_SAGPHASEAINTEN_Pos))
#define   EMMINTEN1_SAGPHASEAINTEN_DIS_Val           _UINT16_(0x0)                                 /* (SAGPHASEAINTEN) Phase A SAG Detection Interrupt disabled */
#define   EMMINTEN1_SAGPHASEAINTEN_EN_Val            _UINT16_(0x1)                                 /* (SAGPHASEAINTEN) Phase A SAG Detection Interrupt enabled */
#define EMMINTEN1_SAGALLINTEN_Pos                    _UINT16_(12)                                  /* (SAGALLINTEN) All Phases SAG Detection Interrupt enable/disable Position */
#define EMMINTEN1_SAGALLINTEN_Msk                    (_UINT16_(0x7) << EMMINTEN1_SAGALLINTEN_Pos)  /* (SAGALLINTEN) All Phases SAG Detection Interrupt enable/disable Mask */
#define EMMINTEN1_SAGALLINTEN_(value)                (EMMINTEN1_SAGPALLINTEN_Msk & (_UINT16_(value) << EMMINTEN1_SAGALLINTEN_Pos))
#define   EMMINTEN1_SAGALLINTEN_DIS_Val               _UINT16_(0x0)                                 /* (SAGALLINTEN) All Phases SAG Detection Interrupt disabled */
#define   EMMINTEN1_SAGALLINTEN_EN_Val                _UINT16_(0x7)                                 /* (SAGALLINTEN) All Phases SAG Detection Interrupt enabled */
#define EMMINTEN1_FREQHIINTEN_Pos                     _UINT16_(15)                                  /* (FREQHIINTEN) Frequency Above Range INT Status change flag Position */
#define EMMINTEN1_FREQHIINTEN_Msk                    (_UINT16_(0x1) << EMMINTEN1_FREQHIINTEN_Pos)     /* (FREQHIINTEN) Frequency Above Range INT Status change flag Mask */
#define EMMINTEN1_FREQHIINTEN_(value)                (EMMINTEN1_FREQHIINTEN_Msk & (_UINT16_(value) << EMMINTEN1_FREQHIINTEN_Pos))
#define   EMMINTEN1_FREQHIINTEN_DIS_Val              _UINT16_(0x0)                                 /* (FREQHIINTEN) Frequency Above Range INT Status change flag False */
#define   EMMINTEN1_FREQHIINTEN_EN_Val               _UINT16_(0x1)                                 /* (FREQHIINTEN) Frequency Above Range INT Status change flag True */
#define EMMINTEN1_DEFAULT_Val                        _UINT16_(0x0)

/* -------- Last Read/Write SPI/UART Value : (LASTDATA Offset: 0x78H) (R - 16 bits) Last Read/Write SPI Value -------- */
#define LASTSPIDATA_Pos                              _UINT16_(0)                                         /* (LASTSPIDATA) Last Read/Write SPI Value Position */
#define LASTSPIDATA_Msk                              (_UINT16_(0xFFFF) << LASTSPIDATA_LASTSPIDATA_Pos)   /* (LASTSPIDATA) Last Read/Write SPI Value Mask */
#define LASTSPIDATA_Val(value)                       (LASTSPIDATA_LASTSPIDATA_Msk & (_UINT16_(value) << LASTSPIDATA_LASTSPIDATA_Pos))
#define LASTSPIDATA_DEFAULT_Val                      _UINT16_(0x0)

/* -------- CRC Error Status Value : (CRCERRSTATUS Offset: 0x79H) (R - 16 bits) CRC Error Status -------- */
#define CRCERRSTATUS_CFGCRCERR_Pos                  _UINT16_(0)                                    /* (CFGCRCERR) Configuration registers CRC error Position */
#define CRCERRSTATUS_CFGCRCERR_Msk                  (_UINT16_(0x1) << CRCERRSTATUS_CFGCRCERR_Pos)  /* (CFGCRCERR) Configuration registers CRC error Mask */
#define CRCERRSTATUS_CFGCRCERR_Val(value)           (CRCERRSTATUS_CFGCRCERR_Msk & (_UINT16_(value) << CRCERRSTATUS_CFGCRCERR_Pos))
#define   CRCERRSTATUS_CFGCRCERR_FALSE_Val          _UINT16_(0x0)                                  /* (CFGCRCERR) Configuration registers CRC error flag False */
#define   CRCERRSTATUS_CFGCRCERR_TRUE_Val           _UINT16_(0x1)                                  /* (CFGCRCERR) Configuration registers CRC error flag True */
#define CRCERRSTATUS_INTERR_Pos                     _UINT16_(1)                                    /* (INTERR) Configuration registers CRC error Position */
#define CRCERRSTATUS_INTERR_Msk                     (_UINT16_(0x1) << CRCERRSTATUS_INTERR_Pos)     /* (INTERR) Configuration registers CRC error Mask */
#define CRCERRSTATUS_INTERR_Val(value)              (CRCERRSTATUS_INTERR_Msk & (_UINT16_(value) << CRCERRSTATUS_INTERR_Pos))
#define   CRCERRSTATUS_INTERR_FALSE_Val             _UINT16_(0x0)                                  /* (INTERR) Configuration registers CRC error flag False */
#define   CRCERRSTATUS_INTERR_TRUE_Val              _UINT16_(0x1)                                  /* (INTERR) Configuration registers CRC error flag True */
#define CRCERRSTATUS_DEFAULT_Val                    _UINT16_(0x0)

/* -------- CRC Digest Status Value : (CRCERRSTATUS Offset: 0x7AH) (R - 16 bits) CRC Digest -------- */
#define CRCDIGEST_Pos                               _UINT16_(0)                                    /* (CRCDIGEST) CRC Digest Status Value Position */
#define CRCDIGEST_Msk                               (_UINT16_(0xFFFF) << CRCDIGEST_Pos)  /* (CRCDIGEST) CRC Digest Status Value Mask */
#define CRCDIGEST_Val(value)                        (CRCDIGEST_Msk & (_UINT16_(value) << CRCDIGEST_Pos))
#define CRCDIGEST_DEFAULT_Val                       _UINT16_(0x0)

/* -------- Configure Register Access Enable Value : (CFGREGACCEN Offset: 0x7FH) (R - 16 bits) Configure Register Access Enable -------- */
#define CFGREGACCEN_Pos                             _UINT16_(0)                                    /* (CFGREGACCEN) Configure Register Access Enable Position */
#define CFGREGACCEN_Msk                             (_UINT16_(0xFFFF) << CFGREGACCEN_Pos)  /* (CFGREGACCEN) Configure Register Access Enable Mask */
#define CFGREGACCEN_Val(value)                      (CFGREGACCEN_Msk & (_UINT16_(value) << CFGREGACCEN_Pos))
#define   CFGREGACCEN_CONFIG_Val                    _UINT16_(0x55AA)                               /* (CFGREGACCEN) Configuration Mode Command */
#define   CFGREGACCEN_GOLDEN_CRC_Val                _UINT16_(0xAA55)                               /* (CFGREGACCEN) Write Golden CRC Mode Command */
#define   CFGREGACCEN_NORMAL_Val                    _UINT16_(0xA5A5)                               /* (CFGREGACCEN) Normal Mode Command */
#define CFGREGACCEN_DEFAULT_Val                     _UINT16_(0x0)

/* ************************************************************************** */
/*   ENERGY REGISTER - PULSES                                                 */
/* ************************************************************************** */
/* -------- Total Metering Forward Active Energy pulses : (APENERGYT Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYT_Pos                           _UINT16_(0)                                   /* (APENERGYT) Total Forward Active Energy Value Position */
#define APENERGYT_Msk                           (_UINT16_(0xFFFF) << APENERGYT_Pos) /* (APENERGYT) Total Forward Active Energy Value Mask */
#define APENERGYT_Val(value)                    APENERGYT_Msk & (_UINT16_(value) << APENERGYT_Pos))

/* -------- Phase A Metering Forward Active Energy pulses : (APENERGYA Offset: 0x81H) (R/C - 16 bits) - ATM90E32 Metering Phase A Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYA_Pos                           _UINT16_(0)                                   /* (APENERGYA) Phase A Forward Active Energy Value Position */
#define APENERGYA_Msk                           (_UINT16_(0xFFFF) << APENERGYA_Pos) /* (APENERGYA) Phase A Forward Active Energy Value Mask */
#define APENERGYA_Val(value)                    (APENERGYA_Msk & (_UINT16_(value) << APENERGYA_Pos)) /* -------- Phase A Metering Forward Active Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Active Energy pulses : (APENERGYB Offset: 0x82H) (R/C - 16 bits) - ATM90E32 Metering Phase B Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYB_Pos                           _UINT16_(0)                                   /* (APENERGYB) Phase B  Forward Active Energy Value Position */
#define APENERGYB_Msk                           (_UINT16_(0xFFFF) << APENERGYB_Pos) /* (APENERGYB) Phase B  Forward Active Energy Value Mask */
#define APENERGYB_Val(value)                    (APENERGYB_Msk & (_UINT16_(value) << APENERGYB_Pos)) /* -------- Phase B  Metering Forward Active Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Active Energy pulses : (APENERGYC Offset: 0x83H) (R/C - 16 bits) - ATM90E32 Metering Phase C Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYC_Pos                           _UINT16_(0)                                   /* (APENERGYC) Phase C Forward Active Energy Value Position */
#define APENERGYC_Msk                           (_UINT16_(0xFFFF) << APENERGYC_Pos) /* (APENERGYC) Phase C Forward Active Energy Value Mask */
#define APENERGYC_Val(value)                    (APENERGYC_Msk & (_UINT16_(value) << APENERGYC_Pos))

/* -------- Metering Total Reverse Active Energy pulses : (ANENERGYT Offset: 0x84H) (R/C - 16 bits) - ATM90E32 Metering Total Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYT_Pos                           _UINT16_(0)                                   /* (ANENERGYT) Total Reverse Active Energy Value Position */
#define ANENERGYT_Msk                           (_UINT16_(0xFFFF) << ANENERGYT_Pos) /* (ANENERGYT) Total Reverse Active Energy Value Mask */
#define ANENERGYT_Val(value)                    (ANENERGYT_Msk & (_UINT16_(value) << ANENERGYT_Pos))

/* -------- Metering Phase A Reverse Active Energy pulses : (ANENERGYA Offset: 0x85H) (R/C - 16 bits) - ATM90E32 Metering Phase A Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYA_Pos                           _UINT16_(0)                                   /* (ANENERGYA) Phase A Reverse Active Energy Value Position */
#define ANENERGYA_Msk                           (_UINT16_(0xFFFF) << ANENERGYA_Pos) /* (ANENERGYA) Phase A Reverse Active Energy Value Mask */
#define ANENERGYA_Val(value)                    (ANENERGYA_Msk & (_UINT16_(value) << ANENERGYA_Pos))

/* -------- Metering Phase B Reverse Active Energy pulses : (ANENERGYB Offset: 0x86H) (R/C - 16 bits) - ATM90E32 Metering Phase B Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYB_Pos                           _UINT16_(0)                                   /* (ANENERGYB) Phase B Reverse Active Energy Value Position */
#define ANENERGYB_Msk                           (_UINT16_(0xFFFF) << ANENERGYB_Pos) /* (ANENERGYB) Phase B Reverse Active Energy Value Mask */
#define ANENERGYB_Val(value)                    (ANENERGYB_ANENERGYB_Msk & (_UINT16_(value) << ANENERGYB_ANENERGYB_Pos))

/* -------- Metering Phase C Reverse Active Energy pulses : (ANENERGYC Offset: 0x87H) (R/C - 16 bits) - ATM90E32 Metering Phase C Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYC_Pos                           _UINT16_(0)                                   /* (ANENERGYA) Phase C Reverse Active Energy Value Position */
#define ANENERGYC_Msk                           (_UINT16_(0xFFFF) << ANENERGYC_Pos) /* (ANENERGYA) Phase C Reverse Active Energy Value Mask */
#define ANENERGYC_Val(value)                    (ANENERGYC_Msk & (_UINT16_(value) << ANENERGYC_Pos))

/* -------- Total Metering Forward Reactive Energy pulses : (RPENERGYT Offset: 0x88H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYT_Pos                           _UINT16_(0)                                   /* (APENERGYT) Total Forward Rective Energy Value Position */
#define RPENERGYT_Msk                           (_UINT16_(0xFFFF) << APENERGYT_Pos) /* (APENERGYT) Total Forward Rective Energy Value Mask */
#define RPENERGYT_Val(value)                    (APENERGYT_Msk & (_UINT16_(value) << APENERGYT_Pos))

/* -------- Phase A Metering Forward Reactive Energy pulses : (RPENERGYA Offset: 0x89H) (R/C - 16 bits) - ATM90E32 Metering Phase A Forward Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYA_Pos                           _UINT16_(0)                                   /* (APENERGYA) Phase A Forward Rective Energy Value Position */
#define RPENERGYA_Msk                           (_UINT16_(0xFFFF) << APENERGYA_Pos) /* (APENERGYA) Phase A Forward Rective Energy Value Mask */
#define RPENERGYA_Val(value)                    (APENERGYA_Msk & (_UINT16_(value) << APENERGYA_Pos)) /* -------- Phase A Metering Forward Reactive Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Reactive Energy pulses : (RPENERGYB Offset: 0x8AH) (R/C - 16 bits) - ATM90E32 Metering Phase B Forward Rective Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYB_Pos                           _UINT16_(0)                                   /* (APENERGYB) Phase B  Forward Reactive Energy Value Position */
#define RPENERGYB_Msk                           (_UINT16_(0xFFFF) << APENERGYB_Pos) /* (APENERGYB) Phase B  Forward Reactive Energy Value Mask */
#define RPENERGYB_Val(value)                    (APENERGYB_Msk & (_UINT16_(value) << APENERGYB_Pos)) /* -------- Phase B  Metering Forward Reactive Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Reactive Energy pulses : (RPENERGYC Offset: 0x8BH) (R/C - 16 bits) - ATM90E32 Metering Phase C Forward Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYC_Pos                           _UINT16_(0)                                   /* (RPENERGYC) Phase C Forward Reactive Energy Value Position */
#define RPENERGYC_Msk                           (_UINT16_(0xFFFF) << RPENERGYC_Pos) /* (RPENERGYC) Phase C Forward Reactive Energy Value Mask */
#define RPENERGYC_Val(value)                    (RPENERGYC_Msk & (_UINT16_(value) << APENERGYC_Pos))

/* -------- Metering Total Reverse Active Energy pulses : (RNENERGYT Offset: 0x8CH) (R/C - 16 bits) - ATM90E32 Metering Total Reverse Rective Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYT_Pos                           _UINT16_(0)                                   /* (RNENERGYT) Total Reverse Rective Energy Value Position */
#define RNENERGYT_Msk                           (_UINT16_(0xFFFF) << RNENERGYT_Pos) /* (RNENERGYT) Total Reverse Rective Energy Value Mask */
#define RNENERGYT_Val(value)                    (RNENERGYT_Msk & (_UINT16_(value) << RNENERGYT_Pos))

/* -------- Metering Phase A Reverse Active Energy pulses : (RNENERGYA Offset: 0x8DH) (R/C - 16 bits) - ATM90E32 Metering Phase A Reverse Rective Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYA_Pos                           _UINT16_(0)                                   /* (RNENERGYA) Phase A Reverse Reactive Energy Value Position */
#define RNENERGYA_Msk                           (_UINT16_(0xFFFF) << RNENERGYA_RNENERGYA_Pos) /* (RNENERGYA) Phase A Reverse Reactive Energy Value Mask */
#define RNENERGYA_Val(value)                    (RNENERGYA_RNENERGYA_Msk & (_UINT16_(value) << RNENERGYA_RNENERGYA_Pos))

/* -------- Metering Phase B Reverse Active Energy pulses : (RNENERGYB Offset: 0x8EH) (R/C - 16 bits) - ATM90E32 Metering Phase B Reverse Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYB_Pos                           _UINT16_(0)                                   /* (RNENERGYB) Phase B Reverse Reactive Energy Value Position */
#define RNENERGYB_Msk                           (_UINT16_(0xFFFF) << RNENERGYB_Pos) /* (RNENERGYB) Phase B Reverse Reactive Energy Value Mask */
#define RNENERGYB_Val(value)                    (RNENERGYB_Msk & (_UINT16_(value) << ANENERGYB_Pos))

/* -------- Metering Phase C Reverse Active Energy pulses : (RNENERGYC Offset: 0x8FH) (R/C - 16 bits) - ATM90E32 Metering Phase C Reverse Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYC_Pos                           _UINT16_(0)                                   /* (RNENERGYC) Phase C Reverse Reactive Energy Value Position */
#define NENERGYC_Msk                           (_UINT16_(0xFFFF) << RNENERGYC_Pos) /* (RNENERGYC) Phase C Reverse Reactive Energy Value Mask */
#define RNENERGYC_Val(value)                    (RNENERGYC_Msk & (_UINT16_(value) << RNENERGYC_Pos))

/* -------- Metering Total (Arithmetic Sum) Apparent Energy pulses : (SAENERGYT Offset: 0x90H) (R/C - 16 bits) - ATM90E36 Metering Total (Arithmetic Sum) Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SAENERGYT_Pos                           _UINT16_(0)                                   /* (SAENERGYT) Total (Arithmetic Sum) Apparent Energy Value Position */
#define SAENERGYT_Msk                           (_UINT16_(0xFFFF) << SAENERGYT_Pos) /* (SAENERGYT) Total (Arithmetic Sum) Apparent Energy Value Mask */
#define SAENERGYT_Val(value)                    (SAENERGYT_Msk & (_UINT16_(value) << SAENERGYT_Pos))

/* -------- Metering Phase A Apparent Energy pulses : (SENERGYA Offset: 0x91H) (R/C - 16 bits) - ATM90E32 Metering Phase A Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SENERGYA_Pos                            _UINT16_(0)                                   /* (SENERGYA) Phase A Apparent Energy Value Position */
#define SENERGYA_Msk                            (_UINT16_(0xFFFF) << SENERGYA_Pos)            /* (SENERGYA) Phase A Apparent Apparent Energy Value Mask */
#define SENERGYA_Val(value)                     (SENERGYA_Msk & (_UINT16_(value) << SENERGYA_Pos))

/* -------- Metering Phase B Apparent Energy pulses : (SENERGYB Offset: 0x92H) (R/C - 16 bits) - ATM90E32 Metering Phase B Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SENERGYB_Pos                            _UINT16_(0)                                   /* (SENERGYB) Phase B Apparent Energy Value Position */
#define SENERGYB_Msk                            (_UINT16_(0xFFFF) << SENERGYB_Pos)            /* (SENERGYB) Phase B Apparent Apparent Energy Value Mask */
#define SENERGYB_Val(value)                     (SENERGYB_Msk & (_UINT16_(value) << SENERGYB_Pos))

/* -------- Metering Phase C Apparent Energy pulses : (SENERGYC Offset: 0x93H) (R/C - 16 bits) - ATM90E32 Metering Phase C Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SENERGYC_Pos                            _UINT16_(0)                                   /* (SENERGYC) Phase C Apparent Energy Value Position */
#define SENERGYC_Msk                            (_UINT16_(0xFFFF) << SENERGYC_Pos)            /* (SENERGYC) Phase C Apparent Apparent Energy Value Mask */
#define SENERGYC_Val(value)                     (SENERGYC_Msk & (_UINT16_(value) << SENERGYC_Pos))

/* ************************************************************************** */
/*   FUNDAMENTAL / HARMONIC ENERGY REGISTER                                   */
/* ************************************************************************** */
/* -------- Total Metering Forward Active Fundamental Energy pulses : (APENERGYT Offset: 0xA0H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYTF_Pos                           _UINT16_(0)                                    /* (APENERGYTF) Total Forward Active Fundamental Energy Value Position */
#define APENERGYTF_Msk                           (_UINT16_(0xFFFF) << APENERGYTF_Pos)           /* (APENERGYTF) Total Forward Active Fundamental Energy Value Mask */
#define APENERGYTF_Val(value)                    (APENERGYTF_Msk & (_UINT16_(value) << APENERGYTF_Pos))

/* -------- Phase A Metering Forward Active Fundamental Energy pulses : (APENERGYA Offset: 0xA1H) (R/C - 16 bits) - ATM90E32 Metering Phase A Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYAF_Pos                           _UINT16_(0)                                    /* (APENERGYA) Phase A Forward Active Energy Fundamental Value Position */
#define APENERGYAF_Msk                           (_UINT16_(0xFFFF) << APENERGYAF_Pos)           /* (APENERGYA) Phase A Forward Active Energy Fundamental Value Mask */
#define APENERGYAF_Val(value)                    (APENERGYAF_Msk & (_UINT16_(value) << APENERGYAF_Pos)) /* -------- Phase A Metering Forward Active Fundamental Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Active Fundamental Energy pulses : (APENERGYB Offset: 0xA2H) (R/C - 16 bits) - ATM90E32 Metering Phase B Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYBF_Pos                           _UINT16_(0)                                    /* (APENERGYB) Phase B  Forward Active Fundamental Energy Value Position */
#define APENERGYBF_Msk                           (_UINT16_(0xFFFF) << APENERGYBF_Pos)           /* (APENERGYB) Phase B  Forward Active FundamentalEnergy Value Mask */
#define APENERGYBF_Val(value)                    (APENERGYBF_Msk & (_UINT16_(value) << APENERGYBF_Pos)) /* -------- Phase B  Metering Forward Active Fundamental Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Active Fundamental Energy pulses : (APENERGYC Offset: 0xA3H) (R/C - 16 bits) - ATM90E32 Metering Phase C Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYCF_Pos                           _UINT16_(0)                                    /* (APENERGYCF) Phase C Forward Active Fundamental Energy Value Position */
#define APENERGYCF_Msk                           (_UINT16_(0xFFFF) << APENERGYCF_Pos)           /* (APENERGYCF) Phase C Forward Active Fundamental Energy Value Mask */
#define APENERGYCF_Val(value)                    (APENERGYCF_Msk & (_UINT16_(value) << APENERGYCF_Pos))

/* -------- Metering Total Reverse Active Fundamental Energy pulses : (ANENERGYTH Offset: 0xA4H) (R/C - 16 bits) - ATM90E32 Metering Total Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYTF_Pos                           _UINT16_(0)                                    /* (ANENERGYTF) Total Reverse Active Fundamental Energy Value Position */
#define ANENERGYTF_Msk                           (_UINT16_(0xFFFF) << ANENERGYTF_Pos) /* (ANENERGYTF) Total Reverse Active Fundamental Energy Value Mask */
#define ANENERGYTF_Val(value)                    (ANENERGYTF_Msk & (_UINT16_(value) << ANENERGYTF_Pos))

/* -------- Metering Phase A Reverse Active Fundamental  Energy pulses : (ANENERGYAH Offset: 0xA5H) (R/C - 16 bits) - ATM90E32 Metering Phase A Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYAF_Pos                           _UINT16_(0)                                    /* (ANENERGYAF) Phase A Reverse Active Fundamental Energy Value Position */
#define ANENERGYAF_Msk                           (_UINT16_(0xFFFF) << ANENERGYAF_Pos)           /* (ANENERGYAF) Phase A Reverse Active Fundamental Energy Value Mask */
#define ANENERGYAF_Val(value)                    (ANENERGYAF_Msk & (_UINT16_(value) << ANENERGYAF_Pos))

/* -------- Metering Phase B Reverse Active Fundamental Energy pulses : (ANENERGYBH Offset: 0xA6H) (R/C - 16 bits) - ATM90E32 Metering Phase B Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYBF_Pos                           _UINT16_(0)                                    /* (ANENERGYBF) Phase B Reverse Active Fundamental Energy Value Position */
#define ANENERGYBF_Msk                           (_UINT16_(0xFFFF) << ANENERGYBF_Pos)           /* (ANENERGYBF) Phase B Reverse Active Fundamental Energy Value Mask */
#define ANENERGYBF_Val(value)                    (ANENERGYBF_Msk & (_UINT16_(value) << ANENERGYBF_Pos))

/* -------- Metering Phase C Reverse Active Fundamental Energy pulses : (ANENERGYCH Offset: 0xA7H) (R/C - 16 bits) - ATM90E32 Metering Phase C Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYCF_Pos                           _UINT16_(0)                                    /* (ANENERGYCF) Phase C Reverse Active Fundamental Energy Value Position */
#define ANENERGYCF_Msk                           (_UINT16_(0xFFFF) << ANENERGYCF_Pos)           /* (ANENERGYCF) Phase C Reverse Active Fundamental Energy Value Mask */
#define ANENERGYCF_Val(value)                    (ANENERGYCF_Msk & (_UINT16_(value) << ANENERGYCF_Pos))

/* -------- Total Metering Forward Active Harmonic Energy pulses : (APENERGYT Offset: 0xA8H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYTH_Pos                           _UINT16_(0)                                    /* (APENERGYTH) Total Forward Active Harmonic Energy Value Position */
#define APENERGYTH_Msk                           (_UINT16_(0xFFFF) << APENERGYTH_Pos)           /* (APENERGYTH) Total Forward Active Harmonic Energy Value Mask */
#define APENERGYTH_Val(value)                    (APENERGYTH_Msk & (_UINT16_(value) << APENERGYTH_Pos))

/* -------- Phase A Metering Forward Active Harmonic Energy pulses : (APENERGYA Offset: 0xA9H) (R/C - 16 bits) - ATM90E32 Metering Phase A Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYAH_Pos                           _UINT16_(0)                                    /* (APENERGYAH) Phase A Forward Active Energy Harmonic Value Position */
#define APENERGYAH_Msk                           (_UINT16_(0xFFFF) << APENERGYAH_Pos)           /* (APENERGYAH) Phase A Forward Active Energy Harmonic Value Mask */
#define APENERGYAH_Val(value)                    (APENERGYAH_Msk & (_UINT16_(value) << APENERGYAH_Pos)) /* -------- Phase A Metering Forward Active Harmonic Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Active Harmonic Energy pulses : (APENERGYBH Offset: 0xAAH) (R/C - 16 bits) - ATM90E32 Metering Phase B Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYBH_Pos                         _UINT16_(0)                                    /* (APENERGYBH) Phase B  Forward Active Harmonic Energy Value Position */
#define APENERGYBH_Msk                         (_UINT16_(0xFFFF) << APENERGYBH_Pos)           /* (APENERGYBH) Phase B  Forward Active Harmonic Energy Value Mask */
#define APENERGYBH_Val(value)                  (APENERGYB_Msk & (_UINT16_(value) << APENERGYBH_Pos)) /* -------- Phase B  Metering Forward Active Harmonic Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Active Harmonic Energy pulses : (APENERGYCH Offset: 0xABH) (R/C - 16 bits) - ATM90E32 Metering Phase C Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYCH_Pos                         _UINT16_(0)                                    /* (APENERGYCH) Phase C Forward Active Harmonic Energy Value Position */
#define APENERGYCH_Msk                         (_UINT16_(0xFFFF) << APENERGYCH_Pos)           /* (APENERGYCH) Phase C Forward Active Harmonic Energy Value Mask */
#define APENERGYCH_Val(value)                  (APENERGYCH_Msk & (_UINT16_(value) << APENERGYCH_Pos))

/* -------- Metering Total Reverse Active Harmonic Energy pulses : (ANENERGYTH Offset: 0xACH) (R/C - 16 bits) - ATM90E32 Metering Total Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYTH_Pos                         _UINT16_(0)                                    /* (ANENERGYTH) Total Reverse Active Harmonic Energy Value Position */
#define ANENERGYTH_Msk                         (_UINT16_(0xFFFF) << ANENERGYTH_Pos)           /* (ANENERGYTH) Total Reverse Active Harmonic Energy Value Mask */
#define ANENERGYTH_Val(value)                  (ANENERGYTH_Msk & (_UINT16_(value) << ANENERGYTH_Pos))

/* -------- Metering Phase A Reverse Active Harmonic  Energy pulses : (ANENERGYAH Offset: 0xADH) (R/C - 16 bits) - ATM90E32 Metering Phase A Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYAH_Pos                         _UINT16_(0)                                    /* (ANENERGYAH) Phase A Reverse Active Harmonic Energy Value Position */
#define ANENERGYAH_Msk                         (_UINT16_(0xFFFF) << ANENERGYAH_Pos)           /* (ANENERGYAH) Phase A Reverse Active Harmonic Energy Value Mask */
#define ANENERGYAH_Val(value)                  (ANENERGYAH_Msk & (_UINT16_(value) << ANENERGYAH_Pos))

/* -------- Metering Phase B Reverse Active Harmonic Energy pulses : (ANENERGYBH Offset: 0xAEH) (R/C - 16 bits) - ATM90E32 Metering Phase B Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYBH_Pos                         _UINT16_(0)                                    /* (ANENERGYBH) Phase B Reverse Active Harmonic Energy Value Position */
#define ANENERGYBH_Msk                         (_UINT16_(0xFFFF) << ANENERGYBH_Pos)           /* (ANENERGYBH) Phase B Reverse Active Harmonic Energy Value Mask */
#define ANENERGYBH_Val(value)                  (ANENERGYBF_Msk & (_UINT16_(value) << ANENERGYBF_Pos))

/* -------- Metering Phase C Reverse Active Harmonic Energy pulses : (ANENERGYCH Offset: 0xAFH) (R/C - 16 bits) - ATM90E32 Metering Phase C Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYCH_Pos                         _UINT16_(0)                                    /* (ANENERGYCH) Phase C Reverse Active Harmonic Energy Value Position */
#define ANENERGYCH_Msk                         (_UINT16_(0xFFFF) << ANENERGYCH_Pos)           /* (ANENERGYCH) Phase C Reverse Active Harmonic Energy Value Mask */
#define ANENERGYCH_Val(value)                  (ANENERGYCH_Msk & (_UINT16_(value) << ANENERGYCH_Pos))

#define ENERGY_DEFAULT_Val                     _UINT16_(0)

/* ************************************************************************** */
/*   MEASUREMENT REGISTER - POWER AND POWER FACTOR REGISTERS                  */
/* ************************************************************************** */
/* -------- Measurement Total (All phase sum) Active Power : (PMEAN Offset: 0xB0H) (R - 16 bits) - ATM90E32 Total (All-phase-sum) Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANT_Pos                             _UINT16_(0)                                 /* (PMEANT) Total (All-phase-sum) Active Power Position */
#define PMEANT_Msk                             (_UINT16_(0xFFFF) << PMEANT_Pos)            /* (PMEANT) Total (All-phase-sum) Active Power Mask */
#define PMEANT_Val(value)                      (PMEANT_Msk & (_UINT16_(value) << PMEANT_Pos))

/* -------- Measurement Phase A Active Power : (PMEANA Offset: 0xB1H) (R - 16 bits) - ATM90E32 Phase A Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANA_Pos                             _UINT16_(0)                                 /* (PMEANA) Phase A Active Power Position */
#define PMEANA_Msk                             (_UINT16_(0xFFFF) << PMEANA_Pos)            /* (PMEANA) Phase A Active Power Mask */
#define PMEANA_Val(value)                      (PMEANA_Msk & (_UINT16_(value) << PMEANA_Pos))

/* -------- Measurement Phase B Active Power : (PMEANB Offset: 0xB2H) (R - 16 bits) - ATM90E32 Phase B Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANB_Pos                             _UINT16_(0)                                 /* (PMEANB) Phase B Active Power Position */
#define PMEANB_Msk                             (_UINT16_(0xFFFF) << PMEANB_Pos)            /* (PMEANB) Phase B Active Power Mask */
#define PMEANB_Val(value)                      (PMEANB_Msk & (_UINT16_(value) << PMEANB_Pos))

/* -------- Measurement Phase C Active Power : (PMEAN Offset: 0xB3H) (R - 16 bits) - ATM90E32 Phase C Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANC_Pos                             _UINT16_(0)                                 /* (PMEANC) Phase C Active Power Position */
#define PMEANC_Msk                             (_UINT16_(0xFFFF) << PMEANC_Pos)            /* (PMEANC) Phase C Active Power Mask */
#define PMEANC_Val(value)                      (PMEANC_Msk & (_UINT16_(value) << PMEANC_Pos))

/* -------- Measurement Total (All-phase-sum) Reactive Power : (QMEAN Offset: 0xB4H) (R - 16 bits) - ATM90E32 Measurement Total (All-phase-sum) Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANT_Pos                             _UINT16_(0)                                 /* (QMEANT) Total (All-phase-sum) Reactive Power Position */
#define QMEANT_Msk                             (_UINT16_(0xFFFF) << QMEANT_Pos)            /* (QMEANT) Total (All-phase-sum) Reactive Power Mask */
#define QMEANT_Val(value)                      (QMEANT_Msk & (_UINT16_(value) << QMEANT_Pos))

/* -------- Measurement Phase A Reactive Power : (QMEAN Offset: 0xB5H) (R - 16 bits) - ATM90E32 Measurement Phase A Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANA_Pos                             _UINT16_(0)                                 /* (QMEANT) Phase A Reactive Power Position */
#define QMEANA_Msk                             (_UINT16_(0xFFFF) << QMEANA_Pos)            /* (QMEANT) Phase A Reactive Power Mask */
#define QMEANA_Val(value)                      (QMEANA_Msk & (_UINT16_(value) << QMEANA_Pos))

/* -------- Measurement Phase B Reactive Power : (QMEANB Offset: 0xB6H) (R - 16 bits) - ATM90E32 Measurement Phase B Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANB_Pos                             _UINT16_(0)                                 /* (QMEANB) Phase B Reactive Power Position */
#define QMEANB_Msk                             (_UINT16_(0xFFFF) << QMEANB_Pos)            /* (QMEANB) Phase B Reactive Power Mask */
#define QMEANB_Val(value)                      (QMEANB_Msk & (_UINT16_(value) << QMEANB_Pos))

/* -------- Measurement Phase C Reactive Power : (QMEANC Offset: 0xB7H) (R - 16 bits) - ATM90E32 Measurement Phase C Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANC_Pos                             _UINT16_(0)                                 /* (QMEANC) Phase C Reactive Power Position */
#define QMEANC_Msk                             (_UINT16_(0xFFFF) << QMEANC_Pos)     /* (QMEANC) Phase C Reactive Power Mask */
#define QMEANC_Val(value)                      (QMEANC_Msk & (_UINT16_(value) << QMEANC_Pos))

/* -------- Measurement Total (All-phase-sum) Apparent Power : (SAMEANT Offset: 0xB8H) (R - 16 bits) - ATM90E32 Measurement Total (All-phase-sum) Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SAMEANT_Pos                            _UINT16_(0)                                /* (SAMEANT) Total (All-phase-sum) Apparent Power Position */
#define SAMEANT_Msk                            (_UINT16_(0xFFFF) << SAMEANT_Pos)          /* (SAMEANT) Total (All-phase-sum) Apparent Power Mask */
#define SAMEANT_Val(value)                     (SAMEANT_Msk & (_UINT16_(value) << SAMEANT_Pos))

/* -------- Measurement Phase A Apparent Power : (SMEANA Offset: 0xB9H) (R - 16 bits) - ATM90E32 Measurement Phase A Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANA_Pos                             _UINT16_(0)                                 /* (SMEANA) Phase A Apparent Power Position */
#define SMEANA_Msk                             (_UINT16_(0xFFFF) << SMEANA_Pos)            /* (SMEANA) Phase A Apparent Power Mask */
#define SMEANA_Val(value)                      (SMEANA_Msk & (_UINT16_(value) << SMEANA_Pos))

/* -------- Measurement Phase B Apparent Power : (SMEANB Offset: 0xBAH) (R - 16 bits) - ATM90E32 Measurement Phase B Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANB_Pos                             _UINT16_(0)                                 /* (SMEANB) Phase B Apparent Power Position */
#define SMEANB_Msk                             (_UINT16_(0xFFFF) << SMEANB_Pos)            /* (SMEANB) Phase B Apparent Power Mask */
#define SMEANB_Val(value)                      (SMEANB_Msk & (_UINT16_(value) << SMEANB_Pos))

/* -------- Measurement Phase C Apparent Power : (SMEANC Offset: 0xBBH) (R - 16 bits) - ATM90E32 Measurement Phase C Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANC_Pos                             _UINT16_(0)                                 /* (SMEANC) Phase C Apparent Power Position */
#define SMEANC_Msk                             (_UINT16_(0xFFFF) << SMEANC_Pos)            /* (SMEANC) Phase C Apparent Power Mask */
#define SMEANC_Val(value)                      (SMEANC_Msk & (_UINT16_(value) << SMEANC_Pos))

/* -------- Measurement Total Power Factor : (POWERF Offset: 0xBCH) (R - 16 bits) - ATM90E32 Measurement Total Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANT_Pos                            _UINT16_(0)                                  /* (PFMEANT) Total Power Factor Position */
#define PFMEANT_Msk                            (_UINT16_(0xFFFF) << PFMEANT_Pos)            /* (PFMEANT) Total Power Factor Factor Mask */
#define PFMEANT_Val(value)                     (PFMEANT_Msk & (_UINT16_(value) << PFMEANT_Pos))

/* -------- Measurement Phase A Power Factor : (POWERF Offset: 0xBDH) (R - 16 bits) - ATM90E32 Measurement Phase A Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANA_Pos                            _UINT16_(0)                                 /* (PFMEANA) Phase A Power Factor Position */
#define PFMEANA_Msk                            (_UINT16_(0xFFFF) << PFMEANA_Pos)           /* (PFMEANA) Phase A Power Factor Factor Mask */
#define PFMEANA_Val(value)                     (PFMEANA_Msk & (_UINT16_(value) << PFMEANA_Pos))

/* -------- Measurement Phase B Power Factor : (POWERF Offset: 0xBEH) (R - 16 bits) - ATM90E32 Measurement Phase B Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANB_Pos                            _UINT16_(0)                                 /* (PFMEANB) Phase B Power Factor Position */
#define PFMEANB_Msk                            (_UINT16_(0xFFFF) << PFMEANB_Pos)           /* (PFMEANB) Phase B Power Factor Factor Mask */
#define PFMEANB_Val(value)                     (PFMEANB_Msk & (_UINT16_(value) << PFMEANB_Pos))

/* -------- Measurement Phase A Power Factor : (POWERF Offset: 0xBFH) (R - 16 bits) - ATM90E32 Measurement Phase C Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANC_Pos                            _UINT16_(0)                                 /* (PFMEANC) Phase C Power Factor Position */
#define PFMEANC_Msk                            (_UINT16_(0xFFFF) << PFMEANC_Pos)           /* (PFMEANC) Phase C Power Factor Factor Mask */
#define PFMEANC_Val(value)                     (PFMEANC_Msk & (_UINT16_(value) << PFMEANC_Pos))

/* -------- Measurement Total (All phase sum) Active Power LSB : (PMEAN Offset: 0xC0H) (R - 16 bits) - ATM90E32 Total (All-phase-sum) Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTLSB_Pos                          _UINT16_(0)                                   /* (PMEANTLSB) Total (All-phase-sum) Active Power Position */
#define PMEANTLSB_Msk                          (_UINT16_(0xFFFF) << PMEANTLSB_Pos)           /* (PMEANTLSB) Total (All-phase-sum) Active Power Mask */
#define PMEANTLSB_Val(value)                   (PMEANTLSB_Msk & (_UINT16_(value) << PMEANTLSB_Pos))

/* -------- Measurement Phase A Active Power LSB: (PMEANA Offset: 0xC1H) (R - 16 bits) - ATM90E32 Phase A Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANALSB_Pos                          _UINT16_(0)                                   /* (PMEANALSB) Phase A Active Power Position */
#define PMEANALSB_Msk                          (_UINT16_(0xFFFF) << PMEANALSB_Pos)           /* (PMEANALSB) Phase A Active Power Mask */
#define PMEANALSB_Val(value)                   (PMEANALSB_Msk & (_UINT16_(value) << PMEANALSB_Pos))

/* -------- Measurement Phase B Active Power LSB: (PMEANB Offset: 0xC2H) (R - 16 bits) - ATM90E32 Phase B Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBLSB_Pos                          _UINT16_(0)                                   /* (PMEANB) Phase B Active Power Position */
#define PMEANBLSB_Msk                          (_UINT16_(0xFFFF) << PMEANBLSB_Pos)           /* (PMEANB) Phase B Active Power Mask */
#define PMEANBLSB_Val(value)                   (PMEANBLSB_Msk & (_UINT16_(value) << PMEANBLSB_Pos))

/* -------- Measurement Phase C Active Power LSB : (PMEAN Offset: 0xC3H) (R - 16 bits) - ATM90E32 Phase C Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCLSB_Pos                          _UINT16_(0)                                   /* (PMEANC) Phase C Active Power Position */
#define PMEANCLSB_Msk                          (_UINT16_(0xFFFF) << PMEANCLSB_Pos)           /* (PMEANC) Phase C Active Power Mask */
#define PMEANCLSB_Val(value)                   (PMEANCLSB_Msk & (_UINT16_(value) << PMEANCLSB_Pos))

/* -------- Measurement Total (All-phase-sum) Reactive Power LSB: (QMEAN Offset: 0xC4H) (R - 16 bits) - ATM90E32 Measurement Total (All-phase-sum) Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANTLSB_Pos                          _UINT16_(0)                                   /* (QMEANT) Total (All-phase-sum) Reactive Power Position */
#define QMEANTLSB_Msk                          (_UINT16_(0xFFFF) << QMEANTLSB_Pos)           /* (QMEANT) Total (All-phase-sum) Reactive Power Mask */
#define QMEANTLSB_Val(value)                   (QMEANTLSB_Msk & (_UINT16_(value) << QMEANTLSB_Pos))

/* -------- Measurement Phase A Reactive Power LSB: (QMEAN Offset: 0xC5H) (R - 16 bits) - ATM90E32 Measurement Phase A Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANALSB_Pos                          _UINT16_(0)                                   /* (QMEANT) Phase A Reactive Power Position */
#define QMEANALSB_Msk                          (_UINT16_(0xFFFF) << QMEANALSB_Pos)           /* (QMEANT) Phase A Reactive Power Mask */
#define QMEANALSB_Val(value)                   (QMEANALSB_Msk & (_UINT16_(value) << QMEANALSB_Pos))

/* -------- Measurement Phase B Reactive Power LSB: (QMEANB Offset: 0xC6H) (R - 16 bits) - ATM90E32 Measurement Phase B Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANBLSB_Pos                          _UINT16_(0)                                   /* (QMEANB) Phase B Reactive Power Position */
#define QMEANBLSB_Msk                          (_UINT16_(0xFFFF) << QMEANBLSB_Pos)           /* (QMEANB) Phase B Reactive Power Mask */
#define QMEANBLSB_Val(value)                   (QMEANBLSB_Msk & (_UINT16_(value) << QMEANBLSB_Pos))

/* -------- Measurement Phase C Reactive Power LSB: (QMEANC Offset: 0xC7H) (R - 16 bits) - ATM90E32 Measurement Phase C Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANCLSB_Pos                           _UINT16_(0)                                   /* (QMEANC) Phase C Reactive Power Position */
#define QMEANCLSB_Msk                           (_UINT16_(0xFFFF) << QMEANCLSB_Pos)           /* (QMEANC) Phase C Reactive Power Mask */
#define QMEANCLSB_Val(value)                    (QMEANCLSB_Msk & (_UINT16_(value) << QMEANCLSB_Pos))

/* -------- Measurement Total (All-phase-sum) Apparent Power LSB: (SMEANT Offset: 0xC8H) (R - 16 bits) - ATM90E32 Measurement Total (All-phase-sum) Apparent Power LSB -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANTLSB_Pos                          _UINT16_(0)                                   /* (SMEANT) Total (All-phase-sum) Apparent Power Position */
#define SMEANTLSB_Msk                          (_UINT16_(0xFFFF) << SMEANTLSB_Pos)           /* (SMEANT) Total (All-phase-sum) Apparent Power Mask */
#define SMEANTLSB_Val(value)                   (SMEANTLSB_Msk & (_UINT16_(value) << SMEANTLSB_Pos))

/* -------- Measurement Phase A Apparent Power : (SMEANA Offset: 0xC9H) (R - 16 bits) - ATM90E32 Measurement Phase A Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANALSB_Pos                          _UINT16_(0)                                   /* (SMEANT) Phase A Apparent Power Position */
#define SMEANALSB_Msk                          (_UINT16_(0xFFFF) << SMEANALSB_Pos)           /* (SMEANT) Phase A Apparent Power Mask */
#define SMEANALSB_Val(value)                   (SMEANALSB_Msk & (_UINT16_(value) << SMEANALSB_Pos))

/* -------- Measurement Phase B Apparent Power : (SMEANB Offset: 0xCAH) (R - 16 bits) - ATM90E32 Measurement Phase B Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANBLSB_Pos                          _UINT16_(0)                                   /* (SMEANB) Phase B Apparent Power Position */
#define SMEANBLSB_Msk                          (_UINT16_(0xFFFF) << SMEANB_Pos)              /* (SMEANB) Phase B Apparent Power Mask */
#define SMEANBLSB_Val(value)                   (SMEANB_Msk & (_UINT16_(value) << SMEANB_Pos))

/* -------- Measurement Phase C Apparent Power : (SMEANC Offset: 0xCBH) (R - 16 bits) - ATM90E32 Measurement Phase C Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANCLSB_Pos                          _UINT16_(0)                                   /* (SMEANC) Phase C Apparent Power Position */
#define SMEANCLSB_Msk                          (_UINT16_(0xFFFF) << SMEANCLSB_Pos)           /* (SMEANC) Phase C Apparent Power Mask */
#define SMEANCLSB_Val(value)                   (SMEANCLSB_Msk & (_UINT16_(value) << SMEANCLSB_Pos))

#define PMEAN_DEFAULT_Val                      _UINT16_(0)
#define QMEAN_DEFAULT_Val                      _UINT16_(0)
#define SMEAN_DEFAULT_Val                      _UINT16_(0)

/* ************************************************************************** */
/*   FUNDAMENTAL/ HARMONIC POWER AND VOLTAGE/ CURRENT RMS REGISTERS           */
/* ************************************************************************** */
/* -------- Measurement Total (All phase sum) Active Fundamental Power : (PMEAN Offset: 0xD0H) (R - 16 bits) - ATM90E32 Total (All-phase-sum) Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTF_Pos                            _UINT16_(0)                                 /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Position */
#define PMEANTF_Msk                            (_UINT16_(0xFFFF) << PMEANTF_Pos)           /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Mask */
#define PMEANTF_Val(value)                     (PMEANTF_Msk & (_UINT16_(value) << PMEANTF_Pos))

/* -------- Measurement Phase A Active Fundamental Power : (PMEANA Offset: 0xD1H) (R - 16 bits) - ATM90E32 Phase A Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAF_Pos                             _UINT16_(0)                                 /* (PMEANAF) Phase A Active Power Fundamental Position */
#define PMEANAF_Msk                             (_UINT16_(0xFFFF) << PMEANAF_Pos)           /* (PMEANAF) Phase A Active Power Fundamental Mask */
#define PMEANAF_Val(value)                      (PMEANAF_Msk & (_UINT16_(value) << PMEANAF_Pos))

/* -------- Measurement Phase B Active Fundamental Power : (PMEANB Offset: 0xD2H) (R - 16 bits) - ATM90E32 Phase B Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBF_Pos                            _UINT16_(0)                                 /* (PMEANBF) Phase B Active Power Fundamental Position */
#define PMEANBF_Msk                            (_UINT16_(0xFFFF) << PMEANBF_Pos)           /* (PMEANBF) Phase B Active Power Fundamental Mask */
#define PMEANBF_Val(value)                     (PMEANB_Msk & (_UINT16_(value) << PMEANBF_Pos))

/* -------- Measurement Phase C Active Fundamental Power : (PMEAN Offset: 0xD3H) (R - 16 bits) - ATM90E32 Phase C Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCF_Pos                            _UINT16_(0)                                 /* (PMEANCF) Phase C Active Power Fundamental Position */
#define PMEANCF_Msk                            (_UINT16_(0xFFFF) << PMEANC_Pos)            /* (PMEANCF) Phase C Active Power Fundamental Mask */
#define PMEANCF_Val(value)                     (PMEANCF_Msk & (_UINT16_(value) << PMEANCF_Pos))

/* -------- Measurement Total (All phase sum) Active Harmonic Power : (PMEAN Offset: 0x40H) (R - 16 bits) - ATM90E32 Total (All-phase-sum) Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTH_Pos                            _UINT16_(0)                                 /* (PMEANT) Total (All-phase-sum) Active Harmonic Power Position */
#define PMEANTH_Msk                            (_UINT16_(0xFFFF) << PMEANTH_Pos)           /* (PMEANT) Total (All-phase-sum) Active Harmonic Power Mask */
#define PMEANTH_Val(value)                     (PMEANTH_Msk & (_UINT16_(value) << PMEANTH_Pos))

/* -------- Measurement Phase A Active Harmonic Power : (PMEANA Offset: 0xD5H) (R - 16 bits) - ATM90E32 Phase A Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAH_Pos                            _UINT16_(0)                                 /* (PMEANAH) Phase A Active Power Harmonic Position */
#define PMEANAH_Msk                            (_UINT16_(0xFFFF) << PMEANAH_Pos)           /* (PMEANAH) Phase A Active Power Harmonic Mask */
#define PMEANAH_Val(value)                     (PMEANAH_Msk & (_UINT16_(value) << PMEANAH_Pos))

/* -------- Measurement Phase B Active Harmonic Power : (PMEANB Offset: 0xD6H) (R - 16 bits) - ATM90E32 Phase B Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBH_Pos                            _UINT16_(0)                                 /* (PMEANBH) Phase B Active Power Harmonic Position */
#define PMEANBH_Msk                            (_UINT16_(0xFFFF) << PMEANBH_Pos)           /* (PMEANBH) Phase B Active Power Harmonic Mask */
#define PMEANBH_Val(value)                     (PMEANBH_Msk & (_UINT16_(value) << PMEANBH_Pos))

/* -------- Measurement Phase C Active Harmonic Power : (PMEAN Offset: 0xD7H) (R - 16 bits) - ATM90E32 Phase C Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCH_Pos                            _UINT16_(0)                                 /* (PMEANCH) Phase C Active Power Harmonic Position */
#define PMEANCH_Msk                            (_UINT16_(0xFFFF) << PMEANCH_Pos)           /* (PMEANCH) Phase C Active Power Harmonic Mask */
#define PMEANCH_Val(value)                     (PMEANCF_Msk & (_UINT16_(value) << PMEANCFH_Pos))

/* -------- Measurement Phase A Voltage RMS : (URMS Offset: 0xD9H) (R - 16 bits) - ATM90E32 Measurement Phase A Voltage RMS -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSA_Pos                              _UINT16_(0)                              /* (URMSA) Phase A Voltage RMS Value Position */
#define URMSA_Msk                              (_UINT16_(0xFFFF) << URMSA_Pos)          /* (URMSA) Phase A Voltage RMS Value Mask */
#define URMSA_Val(value)                       (URMSA_Msk & (_UINT16_(value) << URMSA_Pos))

/* -------- Measurement Phase B Voltage RMS : (URMS Offset: 0xDAH) (R - 16 bits) - ATM90E32 Measurement Phase B Voltage RMS -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSB_Pos                              _UINT16_(0)                              /* (URMSB) Phase B Voltage RMS Value Position */
#define URMSB_Msk                              (_UINT16_(0xFFFF) << URMSB_Pos)          /* (URMSB) Phase B Voltage RMS Value Mask */
#define URMSB_Val(value)                       (URMSB_Msk & (_UINT16_(value) << URMSB_Pos))

/* -------- Measurement Phase C Voltage RMS : (URMS Offset: 0xDBH) (R - 16 bits) - ATM90E32 Measurement Phase C Voltage RMS -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSC_Pos                              _UINT16_(0)                              /* (URMSC) Phase C Voltage RMS Value Position */
#define URMSC_Msk                              (_UINT16_(0xFFFF) << URMSC_Pos)          /* (URMSC) Phase C Voltage RMS Value Mask */
#define URMSC_Val(value)                       (URMSC_Msk & (_UINT16_(value) << URMSC_Pos))

/* -------- Measurement Phase N Current RMS : (IRMS Offset: 0xDCH) (R - 16 bits) - ATM90E32 Measurement Phase N Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSN_Pos                              _UINT16_(0)                              /* (IRMSN) Phase N Current RMS Value Position */
#define IRMSN_Msk                              (_UINT16_(0xFFFF) << IRMSN_Pos)          /* (IRMSN) Phase N Current RMS Value Mask */
#define IRMSN_Val(value)                       (IRMSN_Msk & (_UINT16_(value) << IRMSN_Pos))

/* -------- Measurement Phase A Current RMS : (IRMS Offset: 0xDDH) (R - 16 bits) - ATM90E32 Measurement Phase A Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSA_Pos                              _UINT16_(0)                              /* (IRMSA) Phase A Current RMS Value Position */
#define IRMSA_Msk                              (_UINT16_(0xFFFF) << IRMSA_Pos)          /* (IRMSA) Phase A Current RMS Value Mask */
#define IRMSA_Val(value)                       (IRMSA_Msk & (_UINT16_(value) << IRMSA_Pos))

/* -------- Measurement Phase B Current RMS : (IRMS Offset: 0xDEH) (R - 16 bits) - ATM90E26 Measurement Phase B Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSB_Pos                              _UINT16_(0)                              /* (IRMSB) Phase B Current RMS Value Position */
#define IRMSB_Msk                              (_UINT16_(0xFFFF) << IRMSB_Pos)          /* (IRMSB) Phase B Current RMS Value Mask */
#define IRMSB_Val(value)                       (IRMSB_Msk & (_UINT16_(value) << IRMSB_Pos))

/* -------- Measurement Phase C Current RMS : (IRMS Offset: 0xDFH) (R - 16 bits) - ATM90E26 Measurement Phase C Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSC_Pos                              _UINT16_(0)                              /* (IRMSC) Phase C Current RMS Value Position */
#define IRMSC_Msk                              (_UINT16_(0xFFFF) << IRMSC_Pos)          /* (IRMSC) Phase C Current RMS Value Mask */
#define IRMSC__Val(value)                      (IRMSC_Msk & (_UINT16_(value) << IRMSC_Pos))

/* -------- Measurement Total (All phase sum) Active Fundamental Power LSB : (PMEAN Offset: 0xE0H) (R - 16 bits) - ATM90E32 Total (All-phase-sum) Active Fundamental Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTFLSB_Pos                         _UINT16_(0)                                   /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Position */
#define PMEANTFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANTFLSB_Pos)          /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Mask */
#define PMEANTFLSB_Val(value)                  (PMEANTFLSB_Msk & (_UINT16_(value) << PMEANTFLSB_Pos))

/* -------- Measurement Phase A Active Fundamental Power : (PMEANA Offset: 0xE1H) (R - 16 bits) - ATM90E32 Phase A Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAFLSB_Pos                         _UINT16_(0)                                   /* (PMEANAF) Phase A Active Power Fundamental Position */
#define PMEANAFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANAFLSB_Pos)          /* (PMEANAF) Phase A Active Power Fundamental Mask */
#define PMEANAFLSB_Val(value)                  (PMEANAFLSB_Msk & (_UINT16_(value) << PMEANAFLSB_Pos))

/* -------- Measurement Phase B Active Fundamental Power : (PMEANB Offset: 0xE2H) (R - 16 bits) - ATM90E32 Phase B Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBFLSB_Pos                         _UINT16_(0)                                   /* (PMEANBF) Phase B Active Power Fundamental Position */
#define PMEANBFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANBFLSB_Pos)          /* (PMEANBF) Phase B Active Power Fundamental Mask */
#define PMEANBFLSB_Val(value)                  (PMEANBFLSB_Msk & (_UINT16_(value) << PMEANBFLSB_Pos))

/* -------- Measurement Phase C Active Fundamental Power : (PMEAN Offset: 0xE3H) (R - 16 bits) - ATM90E32 Phase C Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCFLSB_Pos                         _UINT16_(0)                                   /* (PMEANCF) Phase C Active Power Fundamental Position */
#define PMEANCFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANCFLSB_Pos)          /* (PMEANCF) Phase C Active Power Fundamental Mask */
#define PMEANCFLSB_Val(value)                  (PMEANCFLSB_Msk & (_UINT16_(value) << PMEANCFLSB_Pos))

/* -------- Measurement Total (All phase sum) Active Harmonics Power LSB : (PMEAN Offset: 0xE4H) (R - 16 bits) - ATM90E32 Total (All-phase-sum) Active Harmonics Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTHLSB_Pos                         _UINT16_(0)                                   /* (PMEANTH) Total (All-phase-sum) Active Harmonics Power Position */
#define PMEANTHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANTHLSB_Pos)          /* (PMEANTH) Total (All-phase-sum) Active Harmonics Power Mask */
#define PMEANTHLSB_Val(value)                  (PMEANTHLSB_Msk & (_UINT16_(value) << PMEANTHLSB_Pos))

/* -------- Measurement Phase A Active Harmonics Power : (PMEANA Offset: 0xE5H) (R - 16 bits) - ATM90E32 Phase A Active Harmonics Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAHLSB_Pos                         _UINT16_(0)                                   /* (PMEANAH) Phase A Active Power Harmonics Position */
#define PMEANAHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANAHLSB_Pos)          /* (PMEANAH) Phase A Active Power Harmonics Mask */
#define PMEANAHLSB_Val(value)                  (PMEANAHLSB_Msk & (_UINT16_(value) << PMEANAHLSB_Pos))

/* -------- Measurement Phase B Active Harmonics Power : (PMEANB Offset: 0xE6H) (R - 16 bits) - ATM90E32 Phase B Active Harmonics Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBHLSB_Pos                         _UINT16_(0)                                   /* (PMEANBH) Phase B Active Power Harmonics Position */
#define PMEANBHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANBHLSB_Pos)          /* (PMEANBH) Phase B Active Power Harmonics Mask */
#define PMEANBHLSB_Val(value)                  (PMEANBHLSB_Msk & (_UINT16_(value) << PMEANBHLSB_Pos))

/* -------- Measurement Phase C Active Harmonics Power : (PMEAN Offset: 0xE7H) (R - 16 bits) - ATM90E32 Phase C Active Harmonics Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCHLSB_Pos                         _UINT16_(0)                                   /* (PMEANCH) Phase C Active Power Harmonics Position */
#define PMEANCHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANHCLSB_Pos)          /* (PMEANCH) Phase C Active Power Harmonics Mask */
#define PMEANCHLSB_Val(value)                  (PMEANCHLSB_Msk & (_UINT16_(value) << PMEANCHLSB_Pos))

/* -------- Measurement Phase A Voltage RMS LSB: (URMS Offset: 0xE9H) (R - 16 bits) - ATM90E32 Measurement Phase A Voltage RMS LSB-------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSALSB_Pos                           _UINT16_(0)                                   /* (URMSA) Phase A Voltage RMS Value Position */
#define URMSALSB_Msk                           (_UINT16_(0xFFFF) << URMSALSB_Pos)            /* (URMSA) Phase A Voltage RMS Value Mask */
#define URMSALSB_Val(value)                    (URMSALSB_Msk & (_UINT16_(value) << URMSALSB_Pos))

/* -------- Measurement Phase B Voltage RMS LSB: (URMS Offset: 0xEAH) (R - 16 bits) - ATM90E32 Measurement Phase B Voltage RMS LSB-------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSBLSB_Pos                           _UINT16_(0)                                   /* (URMSB) Phase B Voltage RMS Value Position */
#define URMSBLSB_Msk                           (_UINT16_(0xFFFF) << URMSBLSB_Pos)            /* (URMSB) Phase B Voltage RMS Value Mask */
#define URMSBLSB_Val(value)                    (URMSBLSB_Msk & (_UINT16_(value) << URMSBLSB_Pos))

/* -------- Measurement Phase C Voltage RMS LSB: (URMS Offset: 0xEBH) (R - 16 bits) - ATM90E32 Measurement Phase C Voltage RMS LSB -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSCLSB_Pos                           _UINT16_(0)                                   /* (URMSC) Phase C Voltage RMS Value Position */
#define URMSCLSB_Msk                           (_UINT16_(0xFFFF) << URMSCLSB_Pos)            /* (URMSC) Phase C Voltage RMS Value Mask */
#define URMSCLSB_Val(value)                    (URMSCLSB_Msk & (_UINT16_(value) << URMSCLSB_Pos))

/* -------- Measurement Phase A Current RMS : (IRMS Offset: 0xEDH) (R - 16 bits) - ATM90E32 Measurement Phase A Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSALSB_Pos                           _UINT16_(0)                                   /* (IRMSA) Phase A Current RMS Value Position */
#define IRMSALSB_Msk                           (_UINT16_(0xFFFF) << IRMSALSB_Pos)            /* (IRMSA) Phase A Current RMS Value Mask */
#define IRMSALSB_Val(value)                    (IRMSALSB_Msk & (_UINT16_(value) << IRMSALSB_Pos))

/* -------- Measurement Phase B Current RMS : (IRMS Offset: 0xEEH) (R - 16 bits) - ATM90E32 Measurement Phase B Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSBLSB_Pos                           _UINT16_(0)                                   /* (IRMSB) Phase B Current RMS Value Position */
#define IRMSBLSB_Msk                           (_UINT16_(0xFFFF) << IRMSBLSB_Pos)            /* (IRMSB) Phase B Current RMS Value Mask */
#define IRMSBLSB_Val(value)                    (IRMSBLSB_Msk & (_UINT16_(value) << IRMSBLSB_Pos))

/* -------- Measurement Phase C Current RMS : (IRMS Offset: 0xEFH) (R - 16 bits) - ATM90E32 Measurement Phase C Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSCLSB_Pos                           _UINT16_(0)                                   /* (IRMSC) Phase C Current RMS Value Position */
#define IRMSCLSB_Msk                           (_UINT16_(0xFFFF) << IRMSCLSB_Pos)            /* (IRMSC) Phase C Current RMS Value Mask */
#define IRMSCLSB_Val(value)                    (IRMSCLSB_Msk & (_UINT16_(value) << IRMSCLSB_Pos))

#define PFMEAN_DEFAULT_Val                     _UINT16_(0)
#define URMS_DEFAULT_Val                       _UINT16_(0) 
#define IRMS_DEFAULT_Val                       _UINT16_(0) 
#define PF_DEFAULT_Val                         _UINT16_(0) 

/* ************************************************************************** */
/*   PEAK/FREQUENCY/ANGLE/TEMPERATURE                                         */
/* ************************************************************************** */
/* -------- Measurement Channel A Voltage Peak : (UPEAKA Offset: 0xF1H) (R - 16 bits) - ATM90E32 Channel A Voltage Peak -------- */
/* -------- Note:  Unit is V.  */
#define UPEAKA_Pos                             _UINT16_(0)                                /* (UPEAKA) Voltage peak data detected in the configured period Position */
#define UPEAKA_Msk                             (_UINT16_(0xFFFF) << UPEAKA_Pos)           /* (UPEAKA) Voltage peak data detected in the configured period Mask */
#define UPEAKA_Val(value)                      (UPEAKA_Msk & (_UINT16_(value) << UPEAKA_Pos))

/* -------- Measurement Channel B Voltage Peak : (UPEAKB Offset: 0xF2H) (R - 16 bits) - ATM90E32 Channel B Voltage Peak -------- */
/* -------- Note:  Unit is V.  */
#define UPEAKB_Pos                             _UINT16_(0)                                /* (UPEAKB) Voltage peak data detected in the configured period Position */
#define UPEAKB_Msk                             (_UINT16_(0xFFFF) << UPEAKB_Pos)           /* (UPEAKB) Voltage peak data detected in the configured period Mask */
#define UPEAKB_Val(value)                      (UPEAKB_Msk & (_UINT16_(value) << UPEAKB_Pos))

/* -------- Measurement Channel C Voltage Peak : (UPEAKA Offset: 0xF3H) (R - 16 bits) - ATM90E32 Channel A Voltage Peak -------- */
/* -------- Note:  Unit is V.  */
#define UPEAKC_Pos                             _UINT16_(0)                               /* (UPEAKC) Voltage peak data detected in the configured period Position */
#define UPEAKC_Msk                             (_UINT16_(0xFFFF) << UPEAKC_Pos)          /* (UPEAKC) Voltage peak data detected in the configured period Mask */
#define UPEAKC_Val(value)                      (UPEAKC_Msk & (_UINT16_(value) << UPEAKC_Pos))

/* -------- Measurement Channel A Voltage Peak : (IPEAKA Offset: 0xF5H) (R - 16 bits) - ATM90E32 Channel A Current Peak -------- */
/* -------- Note:  Unit is V.  */
#define IPEAKA_Pos                             _UINT16_(0)                               /* (IPEAKA) Current peak data detected in the configured period Position */
#define IPEAKA_Msk                             (_UINT16_(0xFFFF) << IPEAKA_Pos)          /* (IPEAKA) Current peak data detected in the configured period Mask */
#define IPEAKA_Val(value)                      (IPEAKA_Msk & (_UINT16_(value) << IPEAKA_Pos))

/* -------- Measurement Channel B Voltage Peak : (IPEAKB Offset: 0xF6H) (R - 16 bits) - ATM90E32 Channel B Current Peak -------- */
/* -------- Note:  Unit is V.  */
#define IPEAKB_Pos                             _UINT16_(0)                               /* (IPEAKB) Current peak data detected in the configured period Position */
#define IPEAKB_Msk                             (_UINT16_(0xFFFF) << IPEAKB_Pos)          /* (IPEAKB) Current peak data detected in the configured period Mask */
#define IPEAKB_Val(value)                      (IPEAKB_Msk & (_UINT16_(value) << IPEAKB_Pos))

/* -------- Measurement Channel C Voltage Peak : (IPEAKA Offset: 0xF7H) (R - 16 bits) - ATM90E32 Channel A Current Peak -------- */
/* -------- Note:  Unit is V.  */
#define IPEAKC_Pos                             _UINT16_(0)                               /* (IPEAKC) Current peak data detected in the configured period Position */
#define IPEAKC_Msk                             (_UINT16_(0xFFFF) << IPEAKC_Pos)          /* (IPEAKC) Current peak data detected in the configured period Mask */
#define IPEAKC_Val(value)                      (IPEAKC_Msk & (_UINT16_(value) << IPEAKC_Pos))

/* -------- Measurement Frequency : (FREQ Offset: 0xF8H) (R - 16 bits) - ATM90E26 Measurement Frequency -------- */
/* -------- Note: Data format - Range [45,65] Hz */
#define FREQ_Pos                               _UINT16_(0)                             /* (FREQ) Frequency Position */
#define FREQ_Msk                               (_UINT16_(0xFFFF) << FREQ_Pos)          /* (FREQ) Frequency Mask */
#define FREQ_Val(value)                        (FREQ_Msk & (_UINT16_(value) << FREQ_Pos))
#define FREQ_DEFAULT_Val                       _UINT16_(0)

/* -------- Measurement Phase A Angle between Voltage and L Line Current : (PANGLEA Offset: 0xF9H) (R - 16 bits) - ATM90E32 Measurement Phase A Angle -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define PANGLEA_Pos                            _UINT16_(0)                                /* (PANGLEA) Phase A Angle between Voltage and L Line Current Position */
#define PANGLEA_Msk                            (_UINT16_(0xFFFF) << PANGLEA_Pos)          /* (PANGLEA) Phase A Angle between Voltage and L Line Current Mask */
#define PANGLEA_Val(value)                     (PANGLEA_Msk & (_UINT16_(value) << PANGLEA_Pos))

/* -------- Measurement Phase B Angle between Voltage and L Line Current : (PANGLEB Offset: 0xFAH) (R - 16 bits) - ATM90E32 Measurement Phase B Angle -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define PANGLEB_Pos                            _UINT16_(0)                                /* (PANGLEB) Phase B Angle between Voltage and L Line Current Position */
#define PANGLEB_Msk                            (_UINT16_(0xFFFF) << PANGLEB_Pos)          /* (PANGLEB) Phase B Angle between Voltage and L Line Current Mask */
#define PANGLEB_Val(value)                     (PANGLEB_Msk & (_UINT16_(value) << PANGLEB_Pos))

/* -------- Measurement Phase C Angle between Voltage and L Line Current : (PANGLEC Offset: 0xFBH) (R - 16 bits) - ATM90E32 Measurement Phase C Angle -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define PANGLEC_Pos                            _UINT16_(0)                                /* (PANGLEC) Phase C Angle between Voltage and L Line Current Position */
#define PANGLEC_Msk                            (_UINT16_(0xFFFF) << PANGLEC_Pos)          /* (PANGLEC) Phase c Angle between Voltage and L Line Current Mask */
#define PANGLEC_Val(value)                     (PANGLEC_Msk & (_UINT16_(value) << PANGLEC_Pos))

/* -------- Measurement Temperature  : (TEMP Offset: 0xFCH) (R - 16 bits) - ATM90E32 Measured Temperature  -------- */
/* -------- Note: 1LSB corresponds to 1 °C - Signed, MSB as the sign bit */
#define TEMP_Pos                               _UINT16_(0)                             /* (TEMP) Measured Temperature  Position */
#define TEMP_Msk                               (_UINT16_(0xFFFF) << TEMP_Pos)          /* (TEMP) Measured Temperature  Mask */
#define TEMP_Val(value)                        (TEMP_Msk & (_UINT16_(value) << TEMP_Pos))
#define TEMP_DEFAULT_Val                       _UINT16_(0)

/* -------- Measurement Angle between Phase A and Phase A Voltage : (UANGLEA Offset: 0xFDH) (R - 16 bits) - ATM90E32 Measurement Angle between Phase A and Phase A Voltage -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0°. Always 0 */
#define UANGLEA_Pos                            _UINT16_(0)                                /* (UANGLEA) Angle between Phase A and Phase A Voltage Position */
#define UANGLEA_Msk                            (_UINT16_(0xFFFF) << UANGLEA_Pos)          /* (UANGLEA) Angle between Phase A and Phase A Voltage Mask */
#define UANGLEA_Val(value)                     (UANGLEA_Msk & (_UINT16_(value) << UANGLEA_Pos))
/* -------- Measurement Angle between Phase A and Phase B Voltage : (UANGLEB Offset: 0xFEH) (R - 16 bits) - ATM90E32 Measurement Angle between Phase A and Phase B Voltage -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define UANGLEB_Pos                            _UINT16_(0)                                /* (UANGLEB) Angle between Phase A and Phase B Voltage Position */
#define UANGLEB_Msk                            (_UINT16_(0xFFFF) << UANGLEB_Pos)          /* (UANGLEB) Angle between Phase A and Phase B Voltage Mask */
#define UANGLEB_Val(value)                     (UANGLEB_Msk & (_UINT16_(value) << UANGLEB_Pos))

/* -------- Measurement Angle between Phase A and Phase C Voltage : (UANGLEC Offset: 0xFFH) (R - 16 bits) - ATM90E32 Measurement Angle between Phase A and Phase C Voltage -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define UANGLEC_Pos                            _UINT16_(0)                                /* (UANGLEC) Angle between Phase A and Phase C Voltage Position */
#define UANGLEC_Msk                            (_UINT16_(0xFFFF) << UANGLEC_Pos)          /* (UANGLEC) Angle between Phase A and Phase C Voltage Mask */
#define UANGLEC_Val(value)                     (UANGLEC_Msk & (_UINT16_(value) << UANGLEC_Pos))

#define UPEAK_DEFAULT_Val                      _UINT16_(0) 
#define IPEAK_DEFAULT_Val                      _UINT16_(0) 
#define ANGLE_DEFAULT_Val                      _UINT16_(0) 

/* MISRA C-2012 deviation block end */

/** \brief ATM90EXX Control register API structure */
/** \brief ATM90EXX register API structure */

/** \brief ATM90EXX register Address values */
typedef enum
{
    /* Status and Special Register */
	METEREN_ADDR        = 0x00, /* R/W Metering Enable */
	CHANNELMAPI_ADDR    = 0x01, /* R/W Current Channel Mapping Configuration */
	CHANNELMAPU_ADDR    = 0x02, /* R/W Voltage Channel Mapping Configuration  */
	SAGPEAKDETCFG_ADDR  = 0x05, /* R/W Sag and Peak Detector Period Configuration */
	OVTH_ADDR           = 0x06, /* R/W Over Voltage Threshold */
    ZXCONFIG_ADDR       = 0x07, /* R/W Zero-Crossing Configuration */
	SAGTH_ADDR          = 0x08, /* R/W Voltage Sag Threshold */
	PHASELOSSTH_ADDR    = 0x09, /* R/W Voltage Phase Losing Threshold */
	INWARNTH_ADDR       = 0x0A, /* R/W Neutral Current (Calculated) Warning Threshold */
	OITH_ADDR           = 0x0B, /* R/W Over Current Threshold */
	FREQLOTH_ADDR       = 0x0C, /* R/W Low Threshold for Frequency Detection */
	FREQHITH_ADDR       = 0x0D, /* R/W High Threshold for Frequency Detection */
	PMPWRCTRL_ADDR      = 0x0E, /* R/W Partial Measurement Mode Power Control */
	IRQ0MERGECFG_ADDR   = 0x0F, /* R/W IRQ0 Merge Configuration */
    /* Low Power Mode Registers */
	DETECTCTRL_ADDR     = 0x10, /* R/W Current Detect Control */
	DETECTTH1_ADDR      = 0x11, /* R/W Channel 1 Current Threshold in Detection Mode */
	DETECTTH2_ADDR      = 0x12, /* R/W Channel 2 Current Threshold in Detection Mode */
	DETECTTH3_ADDR      = 0x13, /* R/W Channel 3 Current Threshold in Detection Mode */
	IDCOFFSETA_ADDR     = 0x14, /* R/W Phase A Current DC offset */
	IDCOFFSETB_ADDR     = 0x15, /* R/W Phase B Current DC offset */
	IDCOFFSETC_ADDR     = 0x16, /* R/W Phase C Current DC offset */
	UDCOFFSETA_ADDR     = 0x17, /* R/W Voltage DC offset for Channel A */
	UDCOFFSETB_ADDR     = 0x18, /* R/W Voltage DC offset for Channel B */
	UDCOFFSETC_ADDR     = 0x19, /* R/W Voltage DC offset for Channel C */
    UGAINTAB_ADDR       = 0x1A, /* R/W Voltage Gain Temperature Compensation for Phase A/B */
    UGAINTC_ADDR        = 0x1B, /* R/W Voltage Gain Temperature Compensation for Phase C */
	PHIFREQCOMP_ADDR    = 0x1C, /* R/W Phase Compensation for Frequency */
	LOGIRMS0_ADDR       = 0x20, /* R/W Current (Log Irms0) Configuration for Segment Compensation */
	LOGIRMS1_ADDR       = 0x21, /* R/W Current (Log Irms1) Configuration for Segment Compensation */
	F0_ADDR             = 0x22, /* R/W Nominal Frequency */
	T0_ADDR             = 0x23, /* R/W Nominal Temperature  */
	PHIAIRMS01_ADDR     = 0x34, /* R/W Phase A Phase Compensation for Current Segment 0 and 1 */
	PHIAIRMS2_ADDR      = 0x25, /* R/W Phase A Phase Compensation for Current Segment 2 */
	GAINAIRMS01_ADDR    = 0x26, /* R/W Phase A Gain Compensation for Current Segment 0 and 1 */
	GAINAIRMS2_ADDR     = 0x27, /* R/W Phase A Gain Compensation for Current Segment 2 */
	PHIBIRMS01_ADDR     = 0x28, /* R/W Phase B Phase Compensation for Current Segment 0 and 1 */
	PHIBIRMS2_ADDR      = 0x29, /* R/W Phase B Phase Compensation for Current Segment 2 */
	GAINBIRMS01_ADDR    = 0x2A, /* R/W Phase B Gain Compensation for Current Segment 0 and 1 */
	GAINBIRMS2_ADDR     = 0x2B, /* R/W Phase B Gain Compensation for Current Segment 2 */
	PHICIRMS01_ADDR     = 0x2C,	/* R/W Phase C Phase Compensation for Current Segment 0 and 1 */	 
	PHICIRMS2_ADDR      = 0x2D, /* R/W Phase C Phase Compensation for Current Segment 2 */
	GAINCIRMS01_ADDR    = 0x2E, /* R/W Phase C Gain Compensation for Current Segment 0 and 1 */
	GAINCIRMS2_ADDR     = 0x2F, /* R/W Phase C Gain Compensation for Current Segment 2 */
    /* Configuration Registers */
	PLCONSTH_ADDR       = 0x31, /* R/W High Word of PL_Constant */
	PLCONSTL_ADDR       = 0x32, /* R/W Low Word of PL_Constant */
	MMODE0_ADDR         = 0x33, /* R/W Metering Method Configuration */
	MMODE1_ADDR         = 0x34, /* R/W PGA Gain Configuration */
	PSTARTTH_ADDR       = 0x35,	/* R/W Active Startup Power Threshold */
	QSTARTTH_ADDR       = 0x36, /* R/W Reactive Startup Power Threshold */
	SSTARTTH_ADDR       = 0x37, /* R/W Apparent Startup Power Threshold */
	PPHASETH_ADDR       = 0x38, /* R/W Startup Power Threshold for Any Phase (Active Energy Accumulation) */
	QPHASETH_ADDR       = 0x39, /* R/W Startup Power Threshold for Any Phase (ReActive Energy Accumulation) */
	SPHASETH_ADDR       = 0x3A, /* R/W Startup Power Threshold for Any Phase (Apparent Energy Accumulation) */
    /* Calibration Registers */	
    POFFSETA_ADDR       = 0x41, /* R/W Phase A Active Power offset */
    QOFFSETA_ADDR       = 0x42, /* R/W Phase A Reactive Power offset */
    POFFSETB_ADDR       = 0x43, /* R/W Phase B Active Power offset */
    QOFFSETB_ADDR       = 0x44, /* R/W Phase B Reactive Power offset */
    POFFSETC_ADDR       = 0x45, /* R/W Phase C Active Power offset */
    QOFFSETC_ADDR       = 0x46, /* R/W Phase C Reactive Power offset */
    PQGAINA_ADDR        = 0x47, /* R/W Phase A Calibration Gain */
    PHIA_ADDR           = 0x48, /* R/W Phase A Calibration Phase Angle */
    PQGAINB_ADDR        = 0x49, /* R/W Phase B Calibration Gain */
    PHIB_ADDR           = 0x4A, /* R/W Phase B Calibration Phase Angle */
    PQGAINC_ADDR        = 0x4B, /* R/W Phase C Calibration Gain */
    PHIC_ADDR           = 0x4C, /* R/W Phase C Calibration Phase Angle */
    /* Fundamental/ Harmonic Energy Calibration Registers */
    POFFSETAF_ADDR      = 0x51, /* R/W Phase A Fundamental Active Power offset */
    POFFSETBF_ADDR      = 0x52, /* R/W Phase B Fundamental Active Power offset */
    POFFSETCF_ADDR      = 0x53, /* R/W Phase C Fundamental Active Power offset */ 
    PGAINAF_ADDR        = 0x54, /* R/W Phase A Fundamental Calibration Gain */
    PGAINBF_ADDR        = 0x55, /* R/W Phase B Fundamental Calibration Gain */
    PGAINCF_ADDR        = 0x56, /* R/W Phase C Fundamental Calibration Gain */
    /* Measurement Calibration Registers */
    UGAINA_ADDR         = 0x61, /* R/W Phase A Voltage RMS Gain */
    IGAINA_ADDR         = 0x62, /* R/W Phase A Current RMS Gain */
    UOFFSETA_ADDR       = 0x63, /* R/W Phase A Voltage RMS offset */
    IOFFSETA_ADDR       = 0x64, /* R/W Phase A Current RMS offset */
    UGAINB_ADDR         = 0x65, /* R/W Phase B Voltage RMS Gain */
    IGAINB_ADDR         = 0x66, /* R/W Phase B Current RMS Gain */
    UOFFSETB_ADDR       = 0x67, /* R/W Phase B Voltage RMS offset */
    IOFFSETB_ADDR       = 0x68, /* R/W Phase B Current RMS offset */
    UGAINC_ADDR         = 0x69, /* R/W Phase C Voltage RMS Gain */
    IGAINC_ADDR         = 0x6A, /* R/W Phase C Current RMS Gain */
    UOFFSETC_ADDR       = 0x6B, /* R/W Phase C Voltage RMS offset */
    IOFFSETC_ADDR       = 0x6C, /* R/W Phase C Current RMS offset */
    /* EMM Status Registers */
    SOFTRESET_ADDR      = 0x70, /* R/W Software Reset */
    EMMSTATE0_ADDR      = 0x71, /* R EMM State 0 */
    EMMSTATE1_ADDR      = 0x72, /* R EMM State 1 */
    EMMINTSTATE0_ADDR   = 0x73, /* R/W1C EMM Interrupt Status 0 */
    EMMINTSTATE1_ADDR   = 0x74, /* R/W1C EMM Interrupt Status 1 */
    EMMINTEN0_ADDR      = 0x75, /* R/W EMM Interrupt Enable 0  */ 
    EMMINTEN1_ADDR      = 0x76, /* R/W EMM Interrupt Enable 1 */
    LASTSPIDATA_ADDR    = 0x78, /* R Last Read/Write SPI Value */
    CRCERRSTATUS_ADDR   = 0x79, /* R CRC Error Status */ 
    CRCDIGEST_ADDR      = 0x7A, /* R/W CRC Digest */
    CFGREGACCEN_ADDR    = 0x7F, /* R/W Configure Register Access Enable */
    /* Energy Register */
    APENERGYT_ADDR      = 0x80, /* R/C Total Forward Active Energy */
    APENERGYA_ADDR      = 0x81, /* R/C Phase A Forward Active Energy */
    APENERGYB_ADDR      = 0x82, /* R/C Phase B Forward Active Energy */
    APENERGYC_ADDR      = 0x83, /* R/C Phase C Forward Active Energy */
    ANENERGYT_ADDR      = 0x84, /* R/C Total Reverse Active Energy */
    ANENERGYA_ADDR      = 0x85, /* R/C Phase A Reverse Active Energy */
    ANENERGYB_ADDR      = 0x86, /* R/C Phase B Reverse Active Energy */
    ANENERGYC_ADDR      = 0x87, /* R/C Phase C Reverse Active Energy */
    RPENERGYT_ADDR      = 0x88, /* R/C Total Forward Reactive Energy */
    RPENERGYA_ADDR      = 0x89, /* R/C Phase A Forward Reactive Energy */
    RPENERGYB_ADDR      = 0x8A, /* R/C Phase B Forward Reactive Energy */
    RPENERGYC_ADDR      = 0x8B, /* R/C Phase C Forward Reactive Energy */
    RNENERGYT_ADDR      = 0x8C, /* R/C Total Reverse Reactive Energy */
    RNENERGYA_ADDR      = 0x8D, /* R/C Phase A Reverse Reactive Energy */
    RNENERGYB_ADDR      = 0x8E, /* R/C Phase B Reverse Reactive Energy */
    RNENERGYC_ADDR      = 0x8F, /* R/C Phase C Reverse Reactive Energy */
    SAENERGYT_ADDR      = 0x90, /* R/C Total (Arithmetic Sum) Apparent Energy */
    SENERGYA_ADDR       = 0x91, /* R/C Phase A Apparent Energy */
    SENERGYB_ADDR       = 0x92, /* R/C Phase B Apparent Energy */
    SENERGYC_ADDR       = 0x93, /* R/C Phase C Apparent Energy */
    /* Fundamental / Harmonic Energy Register */
    APENERGYTF_ADDR     = 0xA0, /* R/C Total Forward Fundamental Active Energy */
    APENERGYAF_ADDR     = 0xA1, /* R/C Phase A Forward Fundamental Active Energy */
    APENERGYBF_ADDR     = 0xA2, /* R/C Phase B Forward Fundamental Active Energy */
    APENERGYCF_ADDR     = 0xA3, /* R/C Phase C Forward Fundamental Active Energy */
    ANENERGYTF_ADDR     = 0xA4, /* R/C Total Reverse Fundamental Active Energy */
    ANENERGYAF_ADDR     = 0xA5, /* R/C Phase A Reverse Fundamental Active Energy */
    ANENERGYBF_ADDR     = 0xA6, /* R/C Phase B Reverse Fundamental Active Energy */
    ANENERGYCF_ADDR     = 0xA7, /* R/C Phase C Reverse Fundamental Active Energy */
    APENERGYTH_ADDR     = 0xA8, /* R/C Total Forward Harmonics Active Energy */
    APENERGYAH_ADDR     = 0xA9, /* R/C Phase A Forward Harmonics Active Energy */
    APENERGYBH_ADDR     = 0xAA, /* R/C Phase B Forward Harmonics Active Energy */
    APENERGYCH_ADDR     = 0xAB, /* R/C Phase C Forward Harmonics Active Energy */
    ANENERGYTH_ADDR     = 0xAC, /* R/C Total Reverse Harmonics Active Energy */
    ANENERGYAH_ADDR     = 0xAD, /* R/C Phase A Reverse Harmonics Active Energy */
    ANENERGYBH_ADDR     = 0xAE, /* R/C Phase B Reverse Harmonics Active Energy */
    ANENERGYCH_ADDR     = 0xAF, /* R/C Phase C Reverse Harmonics Active Energy */
    /* Power and Power Factor Registers */
    PMEANT_ADDR         = 0xB0, /* R Total (all-phase-sum) Active Power */
    PMEANA_ADDR         = 0xB1, /* R Phase A Active Power */   
    PMEANB_ADDR         = 0xB2, /* R Phase B Active Power */   
    PMEANC_ADDR         = 0xB3, /* R Phase C Active Power */   
    QMEANT_ADDR         = 0xB4, /* R Total (all-phase-sum) Rective Power */
    QMEANA_ADDR         = 0xB5, /* R Phase A Rective Power */   
    QMEANB_ADDR         = 0xB6, /* R Phase B Rective Power */   
    QMEANC_ADDR         = 0xB7, /* R Phase C Rective Power */  
    SAMEANT_ADDR        = 0xB8, /* R Total (Arithmetic Sum) Aparent Power */
    SMEANA_ADDR         = 0xB9, /* R Phase A Aparent Power */   
    SMEANB_ADDR         = 0xBA, /* R Phase B Aparent Power */   
    SMEANC_ADDR         = 0xBB, /* R Phase C Aparent Power */  
    PFMEANT_ADDR        = 0xBC, /* R Total Power Factor  */
    PFMEANA_ADDR        = 0xBD, /* R Phase A Power Factor */   
    PFMEANB_ADDR        = 0xBE, /* R Phase B Power Factor */   
    PFMEANC_ADDR        = 0xBF, /* R Phase C Power Factor */  
    PMEANTLSB_ADDR      = 0xC0, /* R Lower Word of Total (all-phase-sum) Active Power */
    PMEANALSB_ADDR      = 0xC1, /* R Lower Word of Phase A Active Power */   
    PMEANBLSB_ADDR      = 0xC2, /* R Lower Word of Phase B Active Power */   
    PMEANCLSB_ADDR      = 0xC3, /* R Lower Word of Phase C Active Power */  
    QMEANTLSB_ADDR      = 0xC4, /* R Lower Word of Total (all-phase-sum) Rective Power */
    QMEANALSB_ADDR      = 0xC5, /* R Lower Word of Phase A Rective Power */   
    QMEANBLSB_ADDR      = 0xC6, /* R Lower Word of Phase B Rective Power */   
    QMEANCLSB_ADDR      = 0xC7, /* R Lower Word of Phase C Rective Power */  
    SAMEANTLSB_ADDR     = 0xC8, /* R Lower Word of Total (Arithmetic Sum) Aparent Power */
    SMEANALSB_ADDR      = 0xC9, /* R Lower Word of Phase A Aparent Power */   
    SMEANBLSB_ADDR      = 0xCA, /* R Lower Word of Phase B Aparent Power */   
    SMEANCLSB_ADDR      = 0xCB, /* R Lower Word of Phase C Aparent Power */   
    /* Fundamental / Harmonic Power and Voltage / Current RMS Registers */
    PMEANTF_ADDR        = 0xD0, /* R Total Active Fundamental Power */
    PMEANAF_ADDR        = 0xD1, /* R Phase A Active Fundamental Power */   
    PMEANBF_ADDR        = 0xD2, /* R Phase B Active Fundamental Power */   
    PMEANCF_ADDR        = 0xD3, /* R Phase C Active Fundamental Power */   
    PMEANTH_ADDR        = 0xD4, /* R Total Active Harmonic Power */
    PMEANAH_ADDR        = 0xD5, /* R Phase A Active Harmonic Power */   
    PMEANBH_ADDR        = 0xD6, /* R Phase B Active Harmonic Power */   
    PMEANCH_ADDR        = 0xD7, /* R Phase C Active Harmonic Power */   
    URMSA_ADDR          = 0xD9, /* R Phase A Voltage RMS */
    URMSB_ADDR          = 0xDA, /* R Phase B Voltage RMS */
    URMSC_ADDR          = 0xDB, /* R Phase C Voltage RMS */
    IRMSN_ADDR          = 0xDC, /* R N Line CALCULATED Current RMS */
    IRMSA_ADDR          = 0xDD, /* R Phase A Current RMS */
    IRMSB_ADDR          = 0xDE, /* R Phase B Current RMS */
    IRMSC_ADDR          = 0xDF, /* R Phase C Current RMS */
    PMEANTFLSB_ADDR     = 0xE0, /* R Lower Word of Total Active Fundamental Power */
    PMEANAFLSB_ADDR     = 0xE1, /* R Lower Word of Phase A Active Fundamental Power */   
    PMEANBFLSB_ADDR     = 0xE2, /* R Lower Word of Phase B Active Fundamental Power */   
    PMEANCFLSB_ADDR     = 0xE3, /* R Lower Word of Phase C Active Fundamental Power */   
    PMEANTHLSB_ADDR     = 0xE4, /* R Lower Word of Total Active Harmonic Power */
    PMEANAHLSB_ADDR     = 0xE5, /* R Lower Word of Phase A Active Harmonic Power */   
    PMEANBHLSB_ADDR     = 0xE6, /* R Lower Word of Phase B Active Harmonic Power */   
    PMEANCHLSB_ADDR     = 0xE7, /* R Lower Word of Phase C Active Harmonic Power */
    URMSALSB_ADDR       = 0xE9, /* R Lower Word of Phase A Voltage RMS */
    URMSBLSB_ADDR       = 0xEA, /* R Lower Word of Phase B Voltage RMS */
    URMSCLSB_ADDR       = 0xEB, /* R Lower Word of Phase C Voltage RMS */
    IRMSNLSB_ADDR       = 0xEC, /* R Lower Word of N Line CALCULATED Current RMS */
    IRMSALSB_ADDR       = 0xED, /* R Lower Word of Phase A Current RMS */
    IRMSBLSB_ADDR       = 0xEE, /* R Lower Word of Phase B Current RMS */
    IRMSCLSB_ADDR       = 0xEF, /* R Lower Word of Phase C Current RMS */
    /* Power Quality, Frequency, Angle and Temperature Registers */
    UPEAKA_ADDR         = 0xF1, /* R phase A voltage THD+N */
    UPEAKB_ADDR         = 0xF2, /* R phase B voltage THD+N */
    UPEAKC_ADDR         = 0xF3, /* R phase C voltage THD+N */
    IPEAKA_ADDR         = 0xF5, /* R phase A current THD+N */
    IPEAKB_ADDR         = 0xF6, /* R phase B current THD+N */
    IPEAKC_ADDR         = 0xF7, /* R phase C current THD+N */
    FREQ_ADDR           = 0xF8, /* R Frequency */
    PANGLEA_ADDR        = 0xF9, /* R Phase A Mean Phase Angle */
    PANGLEB_ADDR        = 0xFA, /* R Phase B Mean Phase Angle */
    PANGLEC_ADDR        = 0xFB, /* R Phase C Mean Phase Angle */
    TEMP_ADDR           = 0xFC, /* R Measured Temperature */
    UANGLEA_ADDR        = 0xFD, /* R Phase A Voltage Phase Angle */
    UANGLEB_ADDR        = 0xFE, /* R Phase B Voltage Phase Angle */
    UANGLEC_ADDR        = 0xFF, /* R Phase C Voltage Phase Angle */
    INVALID_ADDR        = 0xFFFF
}ATM90EXX_REGISTERS_ADDR;

typedef struct
{
    /* Control Registers */
    __IO  uint16_t UScale;              /* Voltage Scale */
    __IO  uint16_t IScale;              /* Current Scale */
    __IO  uint16_t PM;                  /* Acts over PM Hardware Pins */
	__IO  uint16_t MeterEn;             /* R/W Metering Enable */
    __IO  uint16_t ChannelMapI;         /* R/W Current Channels Mapping */
    __IO  uint16_t ChannelMapU;         /* R/W Voltage Channels Mapping */
    __IO  uint16_t SagPeakDetCfg;       /* R/W SAG/Peak Detection Configuration */
    __IO  uint16_t ZXConfig;            /* R/W Zero-Crossing Configuration */
    //__IO  uint16_t PMPwrCtrl;           /* R/W Partial Measurement Mode Power Control */
    __IO  uint16_t IRQ0MergeCfg;        /* R/W Interrupt Pins Configuration */
    __IO  uint16_t MMode0;              /* R/W Metering Mode 0 Configuration */
    __IO  uint16_t MMode1;              /* R/W Metering Mode 1 Configuration */
    __IO  uint16_t CfgRegAccEn;         /* R/W Configure Register Access Enable */
    __O   uint16_t EMMIntEn0;           /* R/W EMM Interrupt Enable 0 */
    __O   uint16_t EMMIntEn1;           /* R/W EMM Interrupt Enable 1 */
    __O   uint16_t CRCDigest;           /* R/W CRC Digest */
} ATM90EXX_REGS_CONTROL;

typedef struct {
    /* System Status */
	__O   uint16_t EMMState0;           /* R EMM State 0 */
    __O   uint16_t EMMState1;           /* R EMM State 1 */
    __O   uint16_t EMMIntState0;        /* R/W1C EMM Interrupt Status 0 */
    __O   uint16_t EMMIntState1;        /* R/W1C EMM Interrupt Status 1 */
    __O   uint16_t LastSPIData;
    __O   uint16_t CRCErrStatus;        /* R CRC Error Status */
} ATM90EXX_REGS_STATUS;

typedef struct {
    /* Thresholds */    
    __IO  uint16_t SagTh;               /* R/W SAG Threshold */
    __IO  uint16_t OVth;                /* R/W Swell Threshold */
    __IO  uint16_t PhaseLossTh;         /* R/W Phase Loss Threshold */
    __IO  uint16_t InWarnTh;            /* R/W Neutral Current Threshold */
    __IO  uint16_t OIth;                /* R/W Over Current Threshold */
    __IO  uint16_t FreqLoTh;            /* R/W Frequency Low Threshold */
    __IO  uint16_t FreqHighTh;          /* R/W Frequency High Threshold */
    __IO  uint16_t PStartTh;            /* R/W Creep P Threshold */
    __IO  uint16_t QStartTh;            /* R/W Creep Q Threshold */
    __IO  uint16_t SStartTh;            /* R/W Creep S Threshold */
    __IO  uint16_t PPhaseTh;            /* R/W Active Power Threshold */
    __IO  uint16_t QPhaseTh;            /* R/W Reactive Power Threshold */
    __IO  uint16_t SPhaseTh;            /* R/W Apparent Power Threshold */
} ATM90EXX_REGS_THRESHOLDS;

typedef struct {
    __IO  uint16_t MC;                  /* R/W Meter Constant in pulses/KWh */
    /* Metering Calibration */
    __IO  uint16_t PLconstH;            /* R/W PL Constant */
    __IO  uint16_t PLconstL;            /* R/W PL Constant */
    /* Power Offset Calibration */
    __IO  uint16_t PoffsetA;            /* R/W Phase A Active Power offset */
    __IO  uint16_t QoffsetA;            /* R/W Phase A Reactive Power offset */
    __IO  uint16_t PoffsetB;            /* R/W Phase B Active Power offset */
    __IO  uint16_t QoffsetB;            /* R/W Phase B Reactive Power offset */
    __IO  uint16_t PoffsetC;            /* R/W Phase C Active Power offset */
    __IO  uint16_t QoffsetC;            /* R/W Phase C Reactive Power offset */
    /* Power Gain Calibration */
    __IO  uint16_t PgainA;              /* R/W Phase A Active/Reactive Energy Calibration Gain */
    __IO  uint16_t PgainB;              /* R/W Phase B Active/Reactive Energy Calibration Gain */
    __IO  uint16_t PgainC;              /* R/W Phase C Active/Reactive Energy Calibration Gain */
    /* Power Phase Calibration */
    __IO  uint16_t PhiA;                /* R/W Phase A Calibration Phase Angle */
    __IO  uint16_t PhiB;                /* R/W Phase B Calibration Phase Angle */
    __IO  uint16_t PhiC;                /* R/W Phase C Calibration Phase Angle */
    /* Fundamental Power Offset Calibration */
    __IO  uint16_t PoffsetAF;           /* R/W Phase A Fundamental Active Power offset */
    __IO  uint16_t PoffsetBF;           /* R/W Phase B Fundamental Active Power offset */
    __IO  uint16_t PoffsetCF;           /* R/W Phase C Fundamental Active Power offset */
    /* Fundamental Power Gain Calibration */
    __IO  uint16_t PgainAF;             /* R/W Phase A Fundamental Calibration Gain */
    __IO  uint16_t PgainBF;             /* R/W Phase B Fundamental Calibration Gain */
    __IO  uint16_t PgainCF;             /* R/W Phase C Fundamental Calibration Gain */
} ATM90EXX_REGS_CAL_MET;

typedef struct {  
    /* Measurement Calibration */
	__IO  uint16_t UgainA;              /* R/W Phase A Voltage RMS Gain */
    __IO  uint16_t IgainA;              /* R/W Phase A Current RMS Gain */
    __IO  uint16_t UoffsetA;            /* R/W Phase A Voltage RMS offset */
    __IO  uint16_t IoffsetA;            /* R/W Phase A Current RMS offset */
    __IO  uint16_t UgainB;              /* R/W Phase B Voltage RMS Gain */
    __IO  uint16_t IgainB;              /* R/W Phase B Current RMS Gain */
    __IO  uint16_t UoffsetB;            /* R/W Phase B Voltage RMS offset */
    __IO  uint16_t IoffsetB;            /* R/W Phase B Current RMS offset */
    __IO  uint16_t UgainC;              /* R/W Phase C Voltage RMS Gain */
    __IO  uint16_t IgainC;              /* R/W Phase C Current RMS Gain */
    __IO  uint16_t UoffsetC;            /* R/W Phase C Voltage RMS offset */
    __IO  uint16_t IoffsetC;            /* R/W Phase C Current RMS offset */
} ATM90EXX_REGS_CAL_MEAS;

typedef struct {
    /* Measurements */
    __O   uint16_t PmeanT;              /* R Total (Arithmetic Sum) Active Power */
    __O   uint16_t PmeanA;              /* R Phase A Active Power */
    __O   uint16_t PmeanB;              /* R Phase B Active Power */
    __O   uint16_t PmeanC;              /* R Phase C Active Power */
    __O   uint16_t QmeanT;              /* R Total (Arithmetic Sum) Reactive Power */
    __O   uint16_t QmeanA;              /* R Phase A Reactive Power */
    __O   uint16_t QmeanB;              /* R Phase B Reactive Power */
    __O   uint16_t QmeanC;              /* R Phase C Reactive Power */
    __O   uint16_t SAmeanT;             /* R Total (Arithmetic Sum) Apparent Power */
    __O   uint16_t SmeanA;              /* R Phase A Apparent Power */
    __O   uint16_t SmeanB;              /* R Phase B Apparent Power */
    __O   uint16_t SmeanC;              /* R Phase C Apparent Power */
    __O   uint16_t PFmeanT;             /* R Total Power Factor */
    __O   uint16_t PFmeanA;             /* R Phase A Power Factor */
    __O   uint16_t PFmeanB;             /* R Phase B Power Factor */
    __O   uint16_t PFmeanC;             /* R Phase C Power Factor */
    __O   uint16_t PmeanTLSB;
    __O   uint16_t PmeanALSB;
    __O   uint16_t PmeanBLSB;
    __O   uint16_t PmeanCLSB;
    __O   uint16_t QmeanTLSB;
    __O   uint16_t QmeanALSB;
    __O   uint16_t QmeanBLSB;
    __O   uint16_t QmeanCLSB;
    __O   uint16_t SAmeanTLSB;
    __O   uint16_t SmeanALSB;
    __O   uint16_t SmeanBLSB;
    __O   uint16_t SmeanCLSB;
    __O   uint16_t PmeanTF;             /* R Total Active Fundamental Power */
    __O   uint16_t PmeanAF;             /* R Phase A Active Fundamental Power */
    __O   uint16_t PmeanBF;             /* R Phase B Active Fundamental Power */
    __O   uint16_t PmeanCF;             /* R Phase C Active Fundamental Power */
    __O   uint16_t PmeanTH;             /* R Total Active Harmonic Power */
    __O   uint16_t PmeanAH;             /* R Phase A Active Harmonic Power */
    __O   uint16_t PmeanBH;             /* R Phase B Active Harmonic Power */
    __O   uint16_t PmeanCH;             /* R Phase C Active Harmonic Power */
    __O   uint16_t UrmsA;               /* R Phase A Voltage RMS */
    __O   uint16_t UrmsB;               /* R Phase B Voltage RMS */
    __O   uint16_t UrmsC;               /* R Phase C Voltage RMS */
    __O   uint16_t IrmsNC;              /* R N Line Calculated Current RMS */
	__O   uint16_t IrmsA;               /* R Phase A Current RMS */
    __O   uint16_t IrmsB;               /* R Phase B Current RMS */
    __O   uint16_t IrmsC;               /* R Phase C Current RMS */
    __O   uint16_t PmeanTFLSB;
    __O   uint16_t PmeanAFLSB;
    __O   uint16_t PmeanBFLSB;
    __O   uint16_t PmeanCFLSB;
    __O   uint16_t PmeanTHLSB;
    __O   uint16_t PmeanAHLSB;
    __O   uint16_t PmeanBHLSB;
    __O   uint16_t PmeanCHLSB;
    __O   uint16_t UrmsALSB;
    __O   uint16_t UrmsBLSB;
    __O   uint16_t UrmsCLSB;
    //__O   uint16_t IrmsNLSB;
    __O   uint16_t IrmsALSB;
    __O   uint16_t IrmsBLSB;
    __O   uint16_t IrmsCLSB;
    /* Power Quality Measurements */
    __O   uint16_t UPeakA;              /* R Delay between Voltage A and Voltage C */
    __O   uint16_t UPeakB;              /* R Delay between Voltage A and Voltage C */
    __O   uint16_t UPeakC;              /* R Delay between Voltage A and Voltage C */
    __O   uint16_t IPeakA;              /* R Delay between Voltage A and Voltage C */
    __O   uint16_t IPeakB;              /* R Delay between Voltage A and Voltage C */
    __O   uint16_t IPeakC;              /* R Delay between Voltage A and Voltage C */
    __O   uint16_t Freq;                /* R Frequency */
    __O   uint16_t PAngleA;             /* R Delay between Voltage A and Current A */
    __O   uint16_t PAngleB;             /* R Delay between Voltage B and Current B */
    __O   uint16_t PAngleC;             /* R Delay between Voltage C and Current C */
    __O   uint16_t Temp;                /* R Temperature */
    __O   uint16_t UAngleA;             /* R Delay between Voltage A and Voltage A - Always 0 */
    __O   uint16_t UAngleB;             /* R Delay between Voltage A and Voltage B */
    __O   uint16_t UAngleC;             /* R Delay between Voltage A and Voltage C */
} ATM90EXX_REGS_MEAS;

typedef struct {
    /* Metering */
    __O   uint16_t APEnergyT;           /* R/C Total Forward Active Energy */
    __O   uint16_t APEnergyA;           /* R/C Phase A Forward Active Energy */
    __O   uint16_t APEnergyB;           /* R/C Phase B Forward Active Energy */
    __O   uint16_t APEnergyC;           /* R/C Phase C Forward Active Energy */
    __O   uint16_t ANEnergyT;           /* R/C Total Reverse Active Energy */
    __O   uint16_t ANEnergyA;           /* R/C Phase A Forward Active Energy */
    __O   uint16_t ANEnergyB;           /* R/C Phase B Forward Active Energy */
    __O   uint16_t ANEnergyC;           /* R/C Phase C Forward Active Energy */
    __O   uint16_t RPEnergyT;           /* R/C Total Forward Reactive Energy */
    __O   uint16_t RPEnergyA;           /* R/C Phase A Forward Reactive Energy */
    __O   uint16_t RPEnergyB;           /* R/C Phase B Forward Reactive Energy */
    __O   uint16_t RPEnergyC;           /* R/C Phase C Forward Reactive Energy */
    __O   uint16_t RNEnergyT;           /* R/C Total Reverse Reactive Energy */
    __O   uint16_t RNEnergyA;           /* R/C Phase A Reverse Reactive Energy */
    __O   uint16_t RNEnergyB;           /* R/C Phase B Reverse Reactive Energy */
    __O   uint16_t RNEnergyC;           /* R/C Phase C Reverse Reactive Energy */
    __O   uint16_t SAEnergyT;           /* R/C Total (Arithmetic Sum) Apparent Energy */
    __O   uint16_t SEnergyA;            /* R/C Phase A Apparent Energy */
    __O   uint16_t SEnergyB;            /* R/C Phase B Apparent Energy */
    __O   uint16_t SEnergyC;            /* R/C Phase C Apparent Energy */
    __O   uint16_t APEnergyTF;          /* R/C Total Forward Fundamental Active Energy */
    __O   uint16_t APEnergyAF;          /* R/C Phase A Forward Fundamental Active Energy */
    __O   uint16_t APEnergyCF;          /* R/C Phase C Forward Fundamental Active Energy */
    __O   uint16_t APEnergyBF;          /* R/C Phase B Forward Fundamental Active Energy */
    __O   uint16_t ANEnergyTF;          /* R/C Total Reverse Fundamental Active Energy */
    __O   uint16_t ANEnergyAF;          /* R/C Phase A Reverse Fundamental Active Energy */
    __O   uint16_t ANEnergyBF;          /* R/C Phase B Reverse Fundamental Active Energy */
    __O   uint16_t ANEnergyCF;          /* R/C Phase C Reverse Fundamental Active Energy */
    __O   uint16_t APEnergyTH;          /* R/C Total Forward Harmonics Active Energy */
    __O   uint16_t APEnergyAH;          /* R/C Phase A Forward Harmonics Active Energy */
    __O   uint16_t APEnergyBH;          /* R/C Phase B Forward Harmonics Active Energy */
    __O   uint16_t APEnergyCH;          /* R/C Phase C Forward Harmonics Active Energy */
    __O   uint16_t ANEnergyTH;          /* R/C Total Reverse Harmonics Active Energy */
    __O   uint16_t ANEnergyAH;          /* R/C Phase A Reverse Harmonics Active Energy */
    __O   uint16_t ANEnergyBH;          /* R/C Phase B Reverse Harmonics Active Energy */
    __O   uint16_t ANEnergyCH;          /* R/C Phase C Reverse Harmonics Active Energy */
} ATM90EXX_REGS_MET;

typedef struct
{
    ATM90EXX_REGS_CONTROL       ctrlInfo;
    ATM90EXX_REGS_THRESHOLDS    thresholdInfo;              
    ATM90EXX_REGS_CAL_MEAS      calMeasInfo;
    ATM90EXX_REGS_CAL_MET       calMetInfo;
    ATM90EXX_REGS_STATUS        statusInfo;
    ATM90EXX_REGS_MEAS          measInfo;
    ATM90EXX_REGS_MET           metInfo;
} ATM90EXX_REGS;

typedef struct
{
    ATM90EXX_REGS_CONTROL       ctrlInfo;
    ATM90EXX_REGS_THRESHOLDS    thresholdInfo;     
    ATM90EXX_REGS_CAL_MEAS      calMeasInfo;
    ATM90EXX_REGS_CAL_MET       calMetInfo;
} ATM90EXX_CONF;

typedef struct
{  
    ATM90EXX_REGS_MEAS          measInfo;
    ATM90EXX_REGS_MET           metInfo;
} ATM90EXX_ACC;


#endif /* METROLOGY_REGS_H */
