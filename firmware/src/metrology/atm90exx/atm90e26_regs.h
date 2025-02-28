/*
Copyright (C) 2024, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#ifndef ATM90E26_REGS_H
#define ATM90E26_REGS_H

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ATM90E26 REGISTERS                           */
/* ************************************************************************** */
/* MISRA C-2012 deviation block start */
/* MISRA C-2012 Rule 5.4 deviated 64 times.  Deviation record ID - H3_MISRAC_2012_R_5_4_DR_1 */

/* -------- SOFT RESET : (SOFT RESET Offset: 0x00) (W - 16 bits) ATM90E26 Soft Reset Register -------- */
#define SOFTRESET_Pos                         _UINT16_(0)                                   /* (SOFTRESET) Soft Reset Position */
#define SOFTRESET_Msk                         (_UINT16_(0xFFFF) << SOFTRESET_SOFTRESET_Pos) /* (SOFTRESET) Soft Reset Mask */
#define SOFTRESET(value)                      (SOFTRESET_SOFTRESET_Msk & (_UINT16_(value) << SOFTRESET_SOFTRESET_Pos))
#define SOFTRESET_DEFAULT_Val                 _UINT16_(0x789A) 

/* -------- SYS STATUS : (SYSSTATUS Offset: 0x01) (R/C - 16 bits) ATM90E26 SysStatus Register -------- */
#define SYSSTATUS_SAGWARN_Pos                 _UINT16_(1)                                   /* (SYSSTATUS) System Status SagWarn Position */
#define SYSSTATUS_SAGWARN_Msk                 (_UINT16_(0x1) << SYSSTATUS_SAGWARN_Pos)      /* (SYSSTATUS) System Status SagWarn Mask */
#define SYSSTATUS_SAGWARN_(value)             (SYSSTATUS_SAGWARN_Msk & (_UINT16_(value) << SYSSTATUS_SAGWARN_Pos))
#define SYSSTATUS_REVPCHG_Pos                 _UINT16_(5)                                   /* (SYSSTATUS) System Status RevPchg Position */
#define SYSSTATUS_REVPCHG_Msk                 (_UINT16_(0x1) << SYSSTATUS_REVPCHG_Pos)      /* (SYSSTATUS) System Status RevPchg Mask */
#define SYSSTATUS_REVPCHG_(value)             (SYSSTATUS_REVPCHG_Msk & (_UINT16_(value) << SYSSTATUS_REVPCHG_Pos))
#define SYSSTATUS_REVQCHG_Pos                 _UINT16_(6)                                   /* (SYSSTATUS) System Status RevQchg Position */
#define SYSSTATUS_REVQCHG_Msk                 (_UINT16_(0x1) << SYSSTATUS_REVQCHG_Pos)      /* (SYSSTATUS) System Status RevQchg Mask */
#define SYSSTATUS_REVQCHG_(value)             (SYSSTATUS_REVQCHG_Msk & (_UINT16_(value) << SYSSTATUS_REVQCHG_Pos))
#define SYSSTATUS_LNCHANGE_Pos                _UINT16_(7)                                   /* (SYSSTATUS) System Status LNchange Position */
#define SYSSTATUS_LNCHANGE_Msk                (_UINT16_(0x1) << SYSSTATUS_LNCHANGE_Pos)     /* (SYSSTATUS) System Status LNchange Mask */
#define SYSSTATUS_LNCHANGE_(value)            (SYSSTATUS_LNCHANGE_Msk & (_UINT16_(value) << SYSSTATUS_LNCHANGE_Pos))
#define SYSSTATUS_ADJERR_Pos                  _UINT16_(12)                                  /* (SYSSTATUS) System Status AdjErr Position */
#define SYSSTATUS_ADJERR_Msk                  (_UINT16_(0x3) << SYSSTATUS_ADJERR_Pos)       /* (SYSSTATUS) System Status AdjErr Mask */
#define SYSSTATUS_ADJERR_(value)              (SYSSTATUS_ADJERR_Msk & (_UINT16_(value) << SYSSTATUS_ADJERR_Pos))
#define   SYSSTATUS_ADJERR_CS2_OK_Val         _UINT16_(0x0)                                 /* (ADJERR) CS2 checksum correct (default) */
#define   SYSSTATUS_ADJERR_CS2_ERR_Val        _UINT16_(0x3)                                 /* (ADJERR) CS2 checksum error */
#define SYSSTATUS_CALERR_Pos                  _UINT16_(14)                                  /* (SYSSTATUS) System Status CalErr Position */
#define SYSSTATUS_CALERR_Msk                  (_UINT16_(0x3) << SYSSTATUS_ADJERR_Pos)       /* (SYSSTATUS) System Status CalErr Mask */
#define SYSSTATUS_CALERR_(value)              (SYSSTATUS_CALERR_Msk & (_UINT16_(value) << SYSSTATUS_CALERR_Pos))
#define   SYSSTATUS_CALERR_CS1_OK_Val         _UINT16_(0x0)                                 /* (CALERR) CS1 checksum correct (default) */
#define   SYSSTATUS_CALERR_CS1_ERR_Val        _UINT16_(0x3)                                 /* (CALERR) CS1 checksum error */
#define SYSSTATUS_DEFAULT_Val                 _UINT16_(0x0000)

/* -------- Function Enable : (FUNCEN Offset: 0x02H) (R/W - 16 bits) ATM90E26 Function Enable Register -------- */
#define FUNCEN_REVPEN_Pos                     _UINT16_(2)                                   /* (FUNCEN) Function enable RevPEn Position */
#define FUNCEN_REVPEN_Msk                     (_UINT16_(0x1) << FUNCEN_REVPEN_Pos)          /* (FUNCEN) Function enable RevPEn Mask */
#define FUNCEN_REVPEN_(value)                 (FUNCEN_REVPEN_Msk & (_UINT16_(value) << FUNCEN_REVPEN_Pos))
#define   FUNCEN_REVPEN_DIS_Val               _UINT16_(0x0)                                 /* (FUNCEN) RevPEn disable */
#define   FUNCEN_REVPEN_EN_Val                _UINT16_(0x1)                                 /* (FUNCEN) RevPEn enable (default) */
#define FUNCEN_REVQEN_Pos                     _UINT16_(3)                                   /* (FUNCEN) Function enable RevQEn Position */
#define FUNCEN_REVQEN_Msk                     (_UINT16_(0x1) << FUNCEN_REVQEN_Pos)          /* (FUNCEN) Function enable RevQEn Mask */
#define FUNCEN_REVQEN_(value)                 (FUNCEN_REVQEN_Msk & (_UINT16_(value) << FUNCEN_REVQEN_Pos))
#define   FUNCEN_REVQEN_DIS_Val               _UINT16_(0x0)                                 /* (FUNCEN) RevQEn disable */
#define   FUNCEN_REVQEN_EN_Val                _UINT16_(0x1)                                 /* (FUNCEN) RevQEn enable (default) */
#define FUNCEN_SAGWO_Pos                      _UINT16_(4)                                   /* (FUNCEN) Function enable SagWo Position */
#define FUNCEN_SAGWO_Msk                      (_UINT16_(0x1) << FUNCEN_SAGWO_Pos)           /* (FUNCEN) Function enable SagWo Mask */
#define FUNCEN_SAGWO_(value)                  (FUNCEN_SAGWO_Msk & (_UINT16_(value) << FUNCEN_SAGWO_Pos))
#define   FUNCEN_SAGWO_DIS_Val                _UINT16_(0x0)                                 /* (FUNCEN) SagWo disable (default) */
#define   FUNCEN_SAGWO_EN_Val                 _UINT16_(0x1)                                 /* (FUNCEN) SagWo enable */
#define FUNCEN_SAGEN_Pos                      _UINT16_(5)                                   /* (FUNCEN) Function enable SagEn Position */
#define FUNCEN_SAGEN_Msk                      (_UINT16_(0x1) << FUNCEN_SAGEN_Pos)           /* (FUNCEN) Function enable SagEn Mask */
#define FUNCEN_SAGEN_(value)                  (FUNCEN_SAGEN_Msk & (_UINT16_(value) << FUNCEN_SAGEN_Pos))
#define   FUNCEN_SAGEN_DIS_Val                _UINT16_(0x0)                                 /* (FUNCEN) SagEn disable (default) */
#define   FUNCEN_SAGEN_EN_Val                 _UINT16_(0x1)                                 /* (FUNCEN) SagEn enable */
#define FUNCEN_DEFAULT_Val                    _UINT16_(0x000C)
/* -------- Voltage Sag Threshold : (SAGTH Offset: 0x03H) (R/W - 16 bits) Voltage sag threshold configuration - Data Format XXX.XX - Unit is V -------- */
#define SAGTH_Pos                             _UINT16_(0)                                   /* (SAGTH) SAG Threshold Position */
#define SAGTH_Msk                             (_UINT16_(0xFFFF) << SAGTH_SAGTH_Pos)         /* (SAGTH) SAG Threshold Mask */
#define SAGTH_Val(value)                      (SAGTH_SAGTH_Msk & (_UINT16_(value) << SAGTH_SAGTH_Pos))
#define   SAGTH_DEFAULT_Val                   _UINT16_(0x1D6A)                              /* (SAGTH) SAG Threshold Default Value */

/* -------- Small-Power Mode Command : (SMALLPMOD Offset: 0x04H) (R/W - 16 bits) Small-power mode command -------- */
#define SMALLPMOD_Pos                         _UINT16_(0)                                   /* (SMALLPMOD) Small-Power Mode Position */
#define SMALLPMOD_Msk                         (_UINT16_(0xFFFF) << SMALLPMOD_Pos) /* (SMALLPMOD) Small-Power Mode Mask */
#define SMALLPMOD_Val(value)                  (SMALLPMOD_Msk & (_UINT16_(value) << SMALLPMOD_Pos))
#define   SMALLPMOD_DIS_Val                   _UINT16_(0x0000)                              /* (SMALLPMOD) Small Power Mode */
#define   SMALLPMOD_EN_Val                    _UINT16_(0xA987)                              /* (SMALLPMOD) Normal Power Mode */
#define   SMALLPMOD_DEFAULT_Val               SMALLPMOD_DIS_Val                             /* (SMALLPMOD) Power Mode Default Value */

/* -------- Last Read/Write SPI/UART Value : (LASTDATA Offset: 0x06H) (R - 16 bits) Last Read/Write SPI/UART Value -------- */
#define LASTDATA_LASTDATA_Pos                 _UINT16_(0)                                   /* (LASTDATA) Last Read/Write SPI/UART Value Position */
#define LASTDATA_LASTDATA_Msk                 (_UINT16_(0xFFFF) << LASTDATA_LASTDATA_Pos)   /* (LASTDATA) Last Read/Write SPI/UART Value Mask */
#define LASTDATA_LASTDATA_Val(value)          (LASTDATA_LASTDATA_Msk & (_UINT16_(value) << LASTDATA_LASTDATA_Pos))
#define LASTDATA_DEFAULT_Val                  _UINT16_(0x0000)

/* ************************************************************************** */
/*   METERING CALIBRATION AND CONFIGURATION REGISTER                          */
/* ************************************************************************** */
/* -------- 16-bit LSB RMS/Power : (LSB Offset: 0x08H) (R  16) - 16-bit LSB of the RMS or Power registers. LSB[7:0] bits are always 0 -------- */
#define LSB_Pos                               _UINT16_(8)                                   /* (LSB) 16-bit LSB RMS/Power Value Position */
#define LSB_Msk                               (_UINT16_(0xFF) << LSB__Pos)                  /* (LSB) 16-bit LSB RMS/Power Value Mask */
#define LSB_Val(value)                        (LSB_Msk & (_UINT16_(value) << LSB_Pos))
#define LSB_DEFAULT_Val                       _UINT16_(0)

/* -------- Metering Calibration Start Command : (CALSTART Offset: 0x20H) (R/W 16) - Calibration Start Commands -------- */
#define CALSTART_Pos                          _UINT16_(0)                                   /* (CALSTART) Calibration Start Command Value Position */
#define CALSTART_Msk                          (_UINT16_(0xFFFF) << CALSTART_Pos)            /* (CALSTART) Calibration Start Command Value Mask */
#define CALSTART_Val(value)                   (CALSTART_Msk & (_UINT16_(value) << CALSTART_Pos))
#define   CALSTART_DIS_Val                    _UINT16_(0x6886)                              /* (CALSTART) Metering Function Disabled */
#define   CALSTART_STARTUP_Val                _UINT16_(0x5678)                              /* (CALSTART) Start-up Calibration Configuration */
#define   CALSTART_FINISH_Val                 _UINT16_(0x8765)                              /* (CALSTART) End and Check Calibration Configuration. If OK, normal metering */
#define   CALSTART_DEFAULT_Val                CALSTART_DIS_Val                              /* (CALSTART) Default Value */

/* -------- High Word of PL_Constant : (PLCONSTH Offset: 0x21H) (R/W  - 16 bits) - High Word of PL_Constant -------- */
#define PLCONSTH_Pos                          _UINT16_(0)                                   /* (PLCONSTH) High Word of PL_Constant Value Position */
#define PLCONSTH_Msk                          (_UINT16_(0xFFFF) << PLCONSTH_Pos)            /* (PLCONSTH) High Word of PL_Constant Value Mask */
#define PLCONSTH_Val(value)                   (PLCONSTH_Msk & (_UINT16_(value) << PLCONSTH_Pos))
#define   PLCONSTH_DEFAULT_Val                _UINT16_(0x0015)                              /* (PLCONSTH) Default Value */

/* -------- Low Word of PL_Constant : (PLCONSTL Offset: 0x22H) (R/W  - 16 bits) - Low Word of PL_Constant -------- */
#define PLCONSTL_Pos                          _UINT16_(0)                                   /* (PLCONSTL) Low Word of PL_Constant Value Position */
#define PLCONSTL_Msk                          (_UINT16_(0xFFFF) << PLCONSTL_Pos)            /* (PLCONSTL) Low Word of PL_Constant Value Mask */
#define PLCONSTL_Val(value)                   (PLCONSTL_Msk & (_UINT16_(value) << PLCONSTL_Pos))
#define   PLCONSTL_DEFAULT_Val                _UINT16_(0xD174)                              /* (PLCONSTL) Default Value */

/* -------- L Line Calibration Gain : (LGAIN Offset: 0x23H) (R/W  - 16 bits) - L Line Calibration Gain -------- */
#define LGAIN_Pos                             _UINT16_(0)                                   /* (LGAIN) L Line Calibration Gain Value Position */
#define LGAIN_Msk                             (_UINT16_(0xFFFF) << LGAIN_Pos)               /* (LGAIN) L Line Calibration Gain Value Mask */
#define LGAIN_Val(value)                      (LGAIN_Msk & (_UINT16_(value) << LGAIN_Pos))
#define   LGAIN_DEFAULT_Val                   _UINT16_(0)                                   /* (LGAIN) Default Value */

/* -------- L Line Calibration Angle : (LPHI Offset: 0x24H) (R/W  - 16 bits) - L Line Calibration Angle -------- */
#define LPHI_LPHI_Pos                         _UINT16_(0)                                   /* (LPHI) L Line Calibration Angle Value Position */
#define LPHI_LPHI_Msk                         (_UINT16_(0x03FF) << LPHI_LPHI_Pos)           /* (LPHI) L Line Calibration Angle Value Mask */
#define LPHI_LPHI_Val(value)                  (LPHI_LPHI_Msk & (_UINT16_(value) << LPHI_LPHI_Pos))
#define   LPHI_LPHI_DEFAULT_Val               _UINT16_(0)                                   /* (LPHI) Default L Angle Value */
#define LPHI_SIGN_Pos                         _UINT16_(15)                                  /* (LPHI) L Line Calibration Angle Value Position */
#define LPHI_SIGN_Msk                         (_UINT16_(0x1) << LPHI_SIGN_Pos)              /* (LPHI) L Line Calibration Angle Value Mask */
#define LPHI_SIGN_Val(value)                  (LPHI_SIGN_Msk & (_UINT16_(value) << LPHI_SIGN_Pos))
#define   LPHI_SIGN_DEFAULT_Val               _UINT16_(0)                                   /* (LPHI) Default L Angle Sign Value */
#define LPHI_DEFAULT_Val                      _UINT16_(0)

/* -------- N Line Calibration Gain : (NGAIN Offset: 0x25H) (R/W  - 16 bits) - N Line Calibration Gain -------- */
#define NGAIN_Pos                             _UINT16_(0)                                   /* (NGAIN) N Line Calibration Gain Value Position */
#define NGAIN_Msk                             (_UINT16_(0xFFFF) << NGAIN_Pos)               /* (NGAIN) N Line Calibration Gain Value Mask */
#define NGAIN_Val(value)                      (NGAIN_Msk & (_UINT16_(value) << NGAIN_Pos))
#define   NGAIN_DEFAULT_Val                   _UINT16_(0)                                   /* (NGAIN) Default Value */

/* -------- N Line Calibration Angle : (NPHI Offset: 0x26H) (R/W  - 16 bits) - N Line Calibration Angle -------- */
#define NPHI_NPHI_Pos                         _UINT16_(0)                                   /* (NPHI) N Line Calibration Angle Value Position */
#define NPHI_NPHI_Msk                         (_UINT16_(0x03FF) << NPHI_NPHI_Pos)           /* (NPHI) N Line Calibration Angle Value Mask */
#define NPHI_NPHI_Val(value)                  (NPHI_NPHI_Msk & (_UINT16_(value) << NPHI_NPHI_Pos))
#define   NPHI_NPHI_DEFAULT_Val               _UINT16_(0)                                   /* (NPHI) Default N Angle Value */
#define NPHI_NIGN_Pos                         _UINT16_(15)                                  /* (NPHI) N Line Calibration Angle Value Position */
#define NPHI_SIGN_Msk                         (_UINT16_(0x1) << LPHI_SIGN_Pos)              /* (NPHI) N Line Calibration Angle Value Mask */
#define NPHI_SIGN_Val(value)                  (LPHI_SIGN_Msk & (_UINT16_(value) << LPHI_SIGN_Pos))
#define   NPHI_SIGN_DEFAULT_Val               _UINT16_(0)                                   /* (NPHI) Default N Angle Sign Value */
#define NPHI_DEFAULT_Val                      _UINT16_(0)

/* -------- Active Startup Power Threshold : (PSTARTTH Offset: 0x27H) (R/W  - 16 bits) - Active Startup Power Threshold -------- */
#define PSTARTTH_Pos                          _UINT16_(0)                                   /* (PSTARTTH) Active Startup Power Threshold Value Position */
#define PSTARTTH_Msk                          (_UINT16_(0xFFFF) << PSTARTTH_Pos)            /* (PSTARTTH) Active Startup Power Threshold Value Mask */
#define PSTARTTH_Val(value)                   (PSTARTTH_Msk & (_UINT16_(value) << PSTARTTH_Pos))
#define   PSTARTTH_DEFAULT_Val                _UINT16_(0x08BD)                              /* (PSTARTTH) Active Startup Power Threshold Default Value */

/* -------- Active No-Load Power Threshold : (PSTARTTH Offset: 0x28H) (R/W  - 16 bits) - Active No-Load Power Threshold -------- */
#define PNOLTH_Pos                            _UINT16_(0)                                   /* (PNOLTH) Active No-Load Power Threshold Value Position */
#define PNOLTH_Msk                            (_UINT16_(0xFFFF) << PNOLTH_Pos)              /* (PNOLTH) Active No-Load Power Threshold Value Mask */
#define PNOLTH_Val(value)                     (PNOLTH_Msk & (_UINT16_(value) << PNOLTH_Pos))
#define   PNOLTH_DEFAULT_Val                  _UINT16_(0x0)                                 /* (PNOLTH) Active No-Load Power Threshold Default Value */

/* -------- Rective Startup Power Threshold : (QSTARTTH Offset: 0x29H) (R/W  - 16 bits) - Reactive Startup Power Threshold -------- */
#define QSTARTTH_Pos                          _UINT16_(0)                                   /* (QSTARTTH) Reactive Startup Power Threshold Value Position */
#define QSTARTTH_Msk                          (_UINT16_(0xFFFF) << QSTARTTH_Pos)            /* (QSTARTTH) Reactive Startup Power Threshold Value Mask */
#define QSTARTTH_Val(value)                   (QSTARTTH_Msk & (_UINT16_(value) << QSTARTTH_Pos))
#define   QSTARTTH_DEFAULT_Val                _UINT16_(0x0AEC)                              /* (QSTARTTH) Rective Startup Power Threshold Default Value */

/* -------- Reactive No-Load Power Threshold : (QSTARTTH Offset: 0x2AH) (R/W  - 16 bits) - Reactive No-Load Power Threshold -------- */
#define QNOLTH_Pos                            _UINT16_(0)                                   /* (QNOLTH) Reactive No-Load Power Threshold Value Position */
#define QNOLTH_Msk                            (_UINT16_(0xFFFF) << QNOLTH_Pos)              /* (QNOLTH) Reactive No-Load Power Threshold Value Mask */
#define QNOLTH_Val(value)                     (QNOLTH_Msk & (_UINT16_(value) << QNOLTH_Pos))
#define   QNOLTH_DEFAULT_Val                  _UINT16_(0x0)                                 /* (PNOLTH) Reactive No-Load Power Threshold Default Value */

/* -------- Metering Mode Configuration : (MMODE Offset: 0x2BH) (R/W - 16 bits) - ATM90E26 Metering Mode Configuration -------- */
#define MMODE_PTHRESH_Pos                     _UINT16_(0)                                   /* (MMODE) L&N line power difference threshold (%) in anti-tampering mode Position  */
#define MMODE_PTHRESH_Msk                     (_UINT16_(0xF) << MMODE_PTHRESH_Pos)          /* (MMODE) L&N line power difference threshold (%) in anti-tampering mode Mask */
#define MMODE_PTHRESH_(value)                 (MMODE_PTHRESH_Msk & (_UINT16_(value) << MMODE_PTHRESH_Pos))
#define   MMODE_PTHRESH_12_5_Val              _UINT16_(0x0)                                 /* (MMODE) L&N line power difference threshold 12.5% */
#define   MMODE_PTHRESH_6_25_Val              _UINT16_(0x1)                                 /* (MMODE) L&N line power difference threshold 6.25% */
#define   MMODE_PTHRESH_3_125_Val             _UINT16_(0x2)                                 /* (MMODE) L&N line power difference threshold 3.125% (default) */
#define   MMODE_PTHRESH_1_5625_Val            _UINT16_(0x3)                                 /* (MMODE) L&N line power difference threshold 1.5625% */
#define   MMODE_PTHRESH_1_Val                 _UINT16_(0x4)                                 /* (MMODE) L&N line power difference threshold 1% */
#define   MMODE_PTHRESH_2_Val                 _UINT16_(0x5)                                 /* (MMODE) L&N line power difference threshold 2% */
#define   MMODE_PTHRESH_3_Val                 _UINT16_(0x6)                                 /* (MMODE) L&N line power difference threshold 3% */
#define   MMODE_PTHRESH_4_Val                 _UINT16_(0x7)                                 /* (MMODE) L&N line power difference threshold 4% */
#define   MMODE_PTHRESH_5_Val                 _UINT16_(0x8)                                 /* (MMODE) L&N line power difference threshold 5% */
#define   MMODE_PTHRESH_6_Val                 _UINT16_(0x9)                                 /* (MMODE) L&N line power difference threshold 6% */
#define   MMODE_PTHRESH_7_Val                 _UINT16_(0xA)                                 /* (MMODE) L&N line power difference threshold 7% */
#define   MMODE_PTHRESH_8_Val                 _UINT16_(0xB)                                 /* (MMODE) L&N line power difference threshold 8% */
#define   MMODE_PTHRESH_9_Val                 _UINT16_(0xC)                                 /* (MMODE) L&N line power difference threshold 9% */
#define   MMODE_PTHRESH_10_Val                _UINT16_(0xD)                                 /* (MMODE) L&N line power difference threshold 10% */
#define   MMODE_PTHRESH_11_Val                _UINT16_(0xE)                                 /* (MMODE) L&N line power difference threshold 11% */
#define   MMODE_PTHRESH_12_Val                _UINT16_(0xF)                                 /* (MMODE) L&N line power difference threshold 12% */
#define   MMODE_PTHRESH_DEFAULT_Val           MMODE_PTHRESH_3_125_Val                       /* (MMODE) L&N line power difference threshold default */
#define MMODE_ZXCON_Pos                       _UINT16_(4)                                   /* (MMODE) Zero-crossing Mode Position */
#define MMODE_ZXCON_Msk                       (_UINT16_(0x3) << MMODE_ZXCON_Pos)            /* (MMODE) Zero-crossing Mode Mask */
#define MMODE_ZXCON_(value)                   (MMODE_ZXCON_Msk & (_UINT16_(value) << MMODE_ZXCON_Pos))
#define   MMODE_ZXCON_POS_Val                 _UINT16_(0x0)                                 /* (MMODE) Zero-crossing Mode Positive */
#define   MMODE_ZXCON_NEG_Val                 _UINT16_(0x1)                                 /* (MMODE) Zero-crossing Mode Negative */
#define   MMODE_ZXCON_ALL_Val                 _UINT16_(0x2)                                 /* (MMODE) Zero-crossing Mode All (default) */
#define   MMODE_ZXCON_DIS_Val                 _UINT16_(0x3)                                 /* (MMODE) Zero-crossing Mode Disabled */
#define MMODE_RMOD_Pos                        _UINT16_(6)                                   /* (MMODE) CF2 output for reactive power Position */
#define MMODE_RMOD_Msk                        (_UINT16_(0x1) << MMODE_RMOD_Pos)             /* (MMODE) CF2 output for reactive power Mask */
#define MMODE_RMOD_(value)                    (MMODE_RMOD_Msk & (_UINT16_(value) << MMODE_RMOD_Pos))
#define   MMODE_RMOD_FREE_Val                 _UINT16_(0x0)                                 /* (MMODE) CF2 output forward/reverse reactive power (default) */
#define   MMODE_RMOD_ABS_Val                  _UINT16_(0x1)                                 /* (MMODE) CF2 output absolute reactive power */
#define MMODE_AMOD_Pos                        _UINT16_(7)                                   /* (MMODE) CF1 output for active power Position */
#define MMODE_AMOD_Msk                        (_UINT16_(0x1) << MMODE_AMOD_Pos)             /* (MMODE) CF1 output for active power Mask */
#define MMODE_AMOD_(value)                    (MMODE_AMOD_Msk & (_UINT16_(value) << MMODE_AMOD_Pos))
#define   MMODE_AMOD_FREE_Val                 _UINT16_(0x0)                                 /* (MMODE) CF1 output forward/reverse active power (default) */
#define   MMODE_AMOD_ABS_Val                  _UINT16_(0x1)                                 /* (MMODE) CF1 output absolute active power */
#define MMODE_LNSEL_Pos                       _UINT16_(10)                                  /* (MMODE) Line selection for metering Position */
#define MMODE_LNSEL_Msk                       (_UINT16_(0x1) << MMODE_LNSEL_Pos)            /* (MMODE) Line selection for metering Mask */
#define MMODE_LNSEL_(value)                   (MMODE_LNSEL_Msk & (_UINT16_(value) << MMODE_LNSEL_Pos))
#define   MMODE_LNSEL_LLINE_Val               _UINT16_(0x1)                                 /* (MMODE) L Line selected for metering (default) */
#define   MMODE_LNSEL_NLINE_Val               _UINT16_(0x0)                                 /* (MMODE) N Line selected for metering */
#define MMODE_NGAIN_Pos                       _UINT16_(11)                                  /* (MMODE) N line current gain Position */
#define MMODE_NGAIN_Msk                       (_UINT16_(0x3) << MMODE_NGAIN_Pos)            /* (MMODE) N line current gain Mask */
#define MMODE_NGAIN_(value)                   (MMODE_NGAIN_Msk & (_UINT16_(value) << MMODE_NGAIN_Pos))
#define   MMODE_NGAIN_2_Val                   _UINT16_(0x0)                                 /* (MMODE) N line current gain 2 */
#define   MMODE_NGAIN_4_Val                   _UINT16_(0x1)                                 /* (MMODE) N line current gain 4 */
#define   MMODE_NGAIN_1_Val                   _UINT16_(0x2)                                 /* (MMODE) N line current gain 1 (default) */
#define   MMODE_NGAIN_1BIS_Val                _UINT16_(0x3)                                 /* (MMODE) N line current gain 1 */
#define MMODE_LGAIN_Pos                       _UINT16_(13)                                  /* (MMODE) L line current gain Position */
#define MMODE_LGAIN_Msk                       (_UINT16_(0x7) << MMODE_LGAIN_Pos)            /* (MMODE) L line current gain Mask */
#define MMODE_LGAIN_(value)                   (MMODE_LGAIN_Msk & (_UINT16_(value) << MMODE_LGAIN_Pos))
#define   MMODE_LGAIN_1_Val                   _UINT16_(0x4)                                 /* (MMODE) L line current gain 1 )default) */
#define   MMODE_LGAIN_4_Val                   _UINT16_(0x0)                                 /* (MMODE) L line current gain 4 */
#define   MMODE_LGAIN_8_Val                   _UINT16_(0x1)                                 /* (MMODE) L line current gain 8 */
#define   MMODE_LGAIN_16_Val                  _UINT16_(0x2)                                 /* (MMODE) L line current gain 16 (default) */
#define   MMODE_LGAIN_24_Val                  _UINT16_(0x3)                                 /* (MMODE) L line current gain 24 */
#define MMODE_DEVAULT_Val                     _UINT16_(0x9422)

/* -------- Metering Configuration Checksum: (CS1 Offset: 0x2CH) (R/W - 16 bits) - ATM90E26 Metering Configuration Checksum -------- */
/* -------- Note: The readout value of the CS1 register is the calculation by the M90E26, which is different from what is written.   */
#define MMODE_CS1_Pos                         _UINT16_(0)                                   /* (MMODE) Metering Configuration Checksum Position */
#define MMODE_CS1_Msk                         (_UINT16_(0xFFFF) << MMODE_CS1_Pos)           /* (MMODE) Metering Configuration Checksum Mask */
#define MMODE_CS1_(value)                     (MMODE_CS1_Msk & (_UINT16_(value) << MMODE_CS1_Pos))
#define MMODE_CS1_DEFAULT_Val                 _UINT16_(0)

/* ************************************************************************** */
/*   MEASUREMENT CALIBRATION REGISTER                                         */
/* ************************************************************************** */
/* -------- Measurements Calibration Start Command : (ADJSTART Offset: 0x30H) (R/W 16) - Measurements Calibration Start Commands -------- */
#define ADJSTART_Pos                          _UINT16_(0)                                   /* (ADJSTART) Calibration Start Command Value Position */
#define ADJSTART_Msk                          (_UINT16_(0xFFFF) << ADJSTART_Pos)            /* (ADJSTART) Calibration Start Command Value Mask */
#define ADJSTART_Val(value)                   (ADJSTART_Msk & (_UINT16_(value) << ADJSTART_Pos))
#define   ADJSTART_DIS_Val                    _UINT16_(0x6886)                              /* (ADJSTART) Measurement Function Disabled */
#define   ADJSTART_STARTUP_Val                _UINT16_(0x5678)                              /* (ADJSTART) Start-up Calibration Configuration */
#define   ADJSTART_FINISH_Val                 _UINT16_(0x8765)                              /* (ADJSTART) End and Check Calibration Configuration. If OK, normal metering */
#define   ADJSTART_DEFAULT_Val                ADJSTART_DIS_Val                              /* (ADJSTART) Default Value */

/* -------- Measurements Voltage rms Gain : (UGAIN Offset: 0x31H) (R/W - 16 bits) - ATM90E26 Measurements Voltage rms Gain -------- */
#define UGAIN_Pos                             _UINT16_(0)                                   /* (GAIN) Voltage rms Gain Value Position */
#define UGAIN_Msk                             (_UINT16_(0x7FFF) << UGAIN_Pos)               /* (GAIN) Voltage rms Gain Value Mask */
#define UGAIN_Val(value)                      (UGAIN_Msk & (_UINT16_(value) << UGAIN_Pos))
#define   UGAIN_DEFAULT_Val                   _UINT16_(0x6720)                              /* (GAIN) Voltage rms Gain Default Value */

/* -------- Measurements Current rms Gain Line L : (IGAINL Offset: 0x32H) (R/W - 16 bits) - ATM90E26 Measurements Current rms Gain L Line -------- */
#define IGAINL_Pos                            _UINT16_(0)                                   /* (GAIN) Current rms Gain L Line Value Position */
#define IGAINL_Msk                            (_UINT16_(0x7FFF) << IGAINL_Pos)              /* (GAIN) Current rms Gain L Line Value Mask */
#define IGAINL_Val(value)                     (IGAINL_Msk & (_UINT16_(value) << IGAINL_Pos))
#define   IGAINL_DEFAULT_Val                  _UINT16_(0x7A13)                              /* (GAIN) Current rms Gain L Line Default Value */

/* -------- Measurements Current rms Gain Line N : (IGAINN Offset: 0x33H) (R/W - 16 bits) - ATM90E26 Measurements Current rms Gain N Line -------- */
#define IGAINN_Pos                            _UINT16_(0)                                   /* (GAINN) Current rms Gain N Line Value Position */
#define IGAINN_Msk                            (_UINT16_(0x7FFF) << IGAINN_Pos)              /* (GAIN) Current rms Gain N Line Value Mask */
#define IGAINN_Val(value)                     (IGAINN_GAIN_Msk & (_UINT16_(value) << IGAINN_Pos))
#define   IGAINN_DEFAULT_Val                  _UINT16_(0x6720)                              /* (GAIN) Current rms Gain N Line Default Value */

/* -------- Measurements Voltage Offset : (UOFFSET Offset: 0x34H) (R/W - 16 bits) - ATM90E26 Measurements Voltage Offset -------- */
/* -------- Note: The voltage offset calibration should be performed at reference current and no offset. It is not applicable for self-powered meter.   */
#define UOFFSET_Pos                           _UINT16_(0)                                   /* (OFFSET) Voltage Offset Value Position */
#define UOFFSET_Msk                           (_UINT16_(0xFFFF) << UOFFSET_Pos)             /* (OFFSET) Current Offset Value Mask */
#define UOFFSET_Val(value)                    (UOFFSET_Msk & (_UINT16_(value) << UOFFSET_Pos))
#define   UOFFSET_DEFAULT_Val                 _UINT16_(0)                                   /* (OFFSET) Current Offset Default Value */

/* -------- Measurements L Line Current Offset : (IOFFSETL Offset: 0x35H) (R/W - 16 bits) - ATM90E26 Measurements L Line Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETL_Pos                          _UINT16_(0)                                   /* (OFFSET) L Line Current Offset Value Position */
#define IOFFSETL_Msk                          (_UINT16_(0xFFFF) << IOFFSETL_Pos)            /* (OFFSET) L Line Current Offset Value Mask */
#define IOFFSETL_Val(value)                   (IOFFSETL_Msk & (_UINT16_(value) << IOFFSETL_Pos))
#define   IOFFSETL_DEFAULT_Val                _UINT16_(0)                                   /* (OFFSET) L Line Current Offset Default Value */

/* -------- Measurements N Line Current Offset : (IOFFSETL Offset: 0x36H) (R/W - 16 bits) - ATM90E26 Measurements N Line Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETN_Pos                          _UINT16_(0)                                   /* (OFFSET) N Line Current Offset Value Position */
#define IOFFSETN_Msk                          (_UINT16_(0xFFFF) << IOFFSETN_Pos)            /* (OFFSET) N Line Current Offset Value Mask */
#define IOFFSETN_Val(value)                   (IOFFSET_Msk & (_UINT16_(value) << IOFFSETN_Pos))
#define   IOFFSETN_DEFAULT_Val                _UINT16_(0)                                   /* (OFFSET) N Line Current Offset Default Value */

/* -------- Measurements L Line Active Power Offset : (POFFSETL Offset: 0x37H) (R/W - 16 bits) - ATM90E26 Measurements L Line Active Power Offset -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETL_Pos                          _UINT16_(0)                                   /* (OFFSET) L Line Active Power Offset Value Position */
#define POFFSETL_Msk                          (_UINT16_(0xFFFF) << POFFSETL_Pos)            /* (OFFSET) L Line Active Power Offset Value Mask */
#define POFFSETL_Val(value)                   (POFFSETL_Msk & (_UINT16_(value) << POFFSETL_Pos))
#define   POFFSETL_DEFAULT_Val                _UINT16_(0)                                   /* (OFFSET) L Line Active Power Offset Default Value */

/* -------- Measurements L Line Reactive Power Offset : (QOFFSETL Offset: 0x38H) (R/W - 16 bits) - ATM90E26 Measurements L Line Rective Power Offset -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define QOFFSETL_Pos                          _UINT16_(0)                                   /* (OFFSET) L Line Rective Power Offset Value Position */
#define QOFFSETL_Msk                          (_UINT16_(0xFFFF) << QOFFSETL_Pos)            /* (OFFSET) L Line Rective Power Offset Value Mask */
#define QOFFSETL_Val(value)                   (QOFFSETL_Msk & (_UINT16_(value) << QOFFSETL_Pos))
#define   QOFFSETL_DEFAULT_Val                _UINT16_(0)                                   /* (OFFSET) L Line Rective Power Offset Default Value */

/* -------- Measurements N Line Active Power Offset : (POFFSETN Offset: 0x39H) (R/W - 16 bits) - ATM90E26 Measurements N Line Active Power Offset -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define POFFSETN_Pos                          _UINT16_(0)                                   /* (OFFSET) N Line Active Power Offset Value Position */
#define POFFSETN_Msk                          (_UINT16_(0xFFFF) << POFFSETN_Pos)            /* (OFFSET) N Line Active Power Offset Value Mask */
#define POFFSETN_Val(value)                   (POFFSETN_Msk & (_UINT16_(value) << POFFSETN_Pos))
#define   POFFSETN_DEFAULT_Val                _UINT16_(0)                                   /* (OFFSET) N Line Active Power Offset Default Value */

/* -------- Measurements N Line Reactive Power Offset : (QOFFSETL Offset: 0x3AH) (R/W - 16 bits) - ATM90E26 Measurements N Line Rective Power Offset -------- */
/* -------- Note: The power offset calibration should be performed at reference voltage and current. */
#define QOFFSETN_Pos                          _UINT16_(0)                                   /* (OFFSET) N Line Rective Power Offset Value Position */
#define QOFFSETNMsk                           (_UINT16_(0xFFFF) << QOFFSETN_Pos)            /* (OFFSET) N Line Rective Power Offset Value Mask */
#define QOFFSETN_Val(value)                   (QOFFSETN_Msk & (_UINT16_(value) << QOFFSETN_Pos))
#define   QOFFSETN_DEFAULT_Val                _UINT16_(0)                                   /* (OFFSET) N Line Rective Power Offset Default Value */

/* -------- Metering Configuration Checksum: (CS1 Offset: 0x3BH) (R/W - 16 bits) - ATM90E26 Metering Configuration Checksum -------- */
/* -------- Note: The readout value of the CS2 register is the calculation by the M90E26, which is different from what is written.   */
#define MMODE_CS2_Pos                         _UINT16_(0)                                   /* (MMODE) Measurement Configuration Checksum Position */
#define MMODE_CS2_Msk                         (_UINT16_(0xFFFF) << MMODE_CS2_Pos)           /* (MMODE) Measurement Configuration Checksum Mask */
#define MMODE_CS2_(value)                     (MMODE_CS2_Msk & (_UINT16_(value) << MMODE_CS2_Pos))
#define MMODE_CS2_DEFAULT_Val                 _UINT16_(0)
/* ************************************************************************** */
/*   ENERGY REGISTER - PULSES                                                 */
/* ************************************************************************** */
/* -------- Metering Forward Active Energy pulses : (APENERGY Offset: 0x40H) (R/C - 16 bits) - ATM90E26 Metering Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.1 pulse. */
#define APENERGY_Pos                          _UINT16_(0)                                   /* (APENERGY) Forward Active Energy Value Position */
#define APENERGY_Msk                          (_UINT16_(0xFFFF) << APENERGY_Pos)            /* (APENERGY) Forward Active Energy Value Mask */
#define APENERGY_Val(value)                   (APENERGY_Msk & (_UINT16_(value) << APENERGY_Pos))
#define APENERGY_DEFAULT_Val                  _UINT16_(0)

/* -------- Metering Reverse Active Energy pulses : (ANENERGY Offset: 0x41H) (R/C - 16 bits) - ATM90E26 Metering Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.1 pulse. */
#define ANENERGY_Pos                          _UINT16_(0)                                   /* (ANENERGY) Reverse Active Energy Value Position */
#define ANENERGY_Msk                          (_UINT16_(0xFFFF) << ANENERGY_Pos)            /* (ANENERGY) Reverse Active Energy Value Mask */
#define ANENERGY_Val(value)                   (ANENERGY_Msk & (_UINT16_(value) << ANENERGY_Pos))
#define ANENERGY_DEFAULT_Val                  _UINT16_(0)

/* -------- Metering Absolute Active Energy pulses : (ATENERGY Offset: 0x42H) (R/C - 16 bits) - ATM90E26 Metering Absolute Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.1 pulse. */
#define ATENERGY_Pos                          _UINT16_(0)                                   /* (ATENERGY) Absolute Active Energy Value Position */
#define ATENERGY_Msk                          (_UINT16_(0xFFFF) << ATENERGY_Pos)            /* (ATENERGY) Absolute Active Energy Value Mask */
#define ATENERGY_Val(value)                   (ATENERGY_Msk & (_UINT16_(value) << ATENERGY_Pos))
#define ATENERGY_DEFAULT_Val                  _UINT16_(0)

/* -------- Metering Forward (Inductive) Reactive Energy pulses : (RPENERGY Offset: 0x43H) (R/C - 16 bits) - ATM90E26 Metering Forward Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.1 pulse. */
#define RPENERGY_Pos                          _UINT16_(0)                                   /* (RPENERGY) Forward Reactive Energy Value Position */
#define RPENERGY_Msk                          (_UINT16_(0xFFFF) << RPENERGY_Pos)            /* (RPENERGY) Forward Reactive Energy Value Mask */
#define RPENERGY_Val(value)                   (RPENERGY_Msk & (_UINT16_(value) << RPENERGY_Pos))
#define RPENERGY_DEFAULT_Val                  _UINT16_(0)

/* -------- Metering Reverse (Capacitive) Reactive Energy pulses : (RNENERGY Offset: 0x44H) (R/C - 16 bits) - ATM90E26 Metering Reverse Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.1 pulse. */
#define RNENERGY_Pos                          _UINT16_(0)                                   /* (RNENERGY) Reverse Reactive Energy Value Position */
#define RNENERGY_Msk                          (_UINT16_(0xFFFF) << RNENERGY_Pos)            /* (RNENERGY) Reverse Reactive Energy Value Mask */
#define RNENERGY_Val(value)                   (RNENERGY_Msk & (_UINT16_(value) << RNENERGY_Pos))
#define RNENERGY_DEFAULT_Val                  _UINT16_(0)

/* -------- Metering Absolute Reactive Energy pulses : (RTENERGY Offset: 0x45H) (R/C - 16 bits) - ATM90E26 Metering Absolute Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.1 pulse. */
#define RTENERGY_Pos                          _UINT16_(0)                                   /* (RTENERGY) Absolute Reactive Energy Value Position */
#define RTENERGY_Msk                          (_UINT16_(0xFFFF) << RTENERGY_Pos)            /* (RTENERGY) Absolute Reactive Energy Value Mask */
#define RTENERGY_Val(value)                   (RTENERGY_Msk & (_UINT16_(value) << RTENERGY_Pos))
#define RTENERGY_DEFAULT_Val                  _UINT16_(0)

/* -------- Metering STATUS : (ENSTATUS Offset: 0x46) (R - 16 bits) ATM90E26 Energy Status Register -------- */
#define ENSTATUS_LNMODE_Pos                   _UINT16_(0)                                   /* (LNMODE) Energy Status LNmode Position */
#define ENSTATUS_LNMODE_Msk                   (_UINT16_(0x3) << ENSTATUS_LNMODE_Pos)        /* (LNMODE) Energy Status LNmode Mask */
#define ENSTATUS_LNMODE_Val(value)            (ENSTATUS_LNMODE_Msk & (_UINT16_(value) << ENSTATUS_LNMODE_Pos))
#define   ENSTATUS_LNMODE_ANTITMP_Val         _UINT16_(0)                                   /* (LNMODE) Metering Mode Anti-Tampering */
#define   ENSTATUS_LNMODE_LLINE_Val           _UINT16_(1)                                   /* (LNMODE) Metering Mode Fixed L Line */
#define   ENSTATUS_LNMODE_LN_Val              _UINT16_(2)                                   /* (LNMODE) Metering Mode L+N */
#define   ENSTATUS_LNMODE_FLEX_Val            _UINT16_(3)                                   /* (LNMODE) Metering Mode Flexible. Selected by MMODE.LNSel */
#define ENSTATUS_LLINE_Pos                    _UINT16_(11)                                  /* (LNMODE) Metering Line Selected Position */
#define ENSTATUS_LLINE_Msk                    (_UINT16_(0x1) << ENSTATUS_LLINE_Pos)         /* (LLINE) Metering Line Selected Mask */
#define ENSTATUS_LLINE_Val(value)             (ENSTATUS_LLINE_Msk & (_UINT16_(value) << ENSTATUS_LLINE_Pos))
#define   ENSTATUS_LLINE_LLINE_Val            _UINT16_(1)                                   /* (LLINE) Metering L Line in Anti-Tampering mode*/
#define   ENSTATUS_LLINE_NLINE_Val            _UINT16_(0)                                   /* (LLINE) Metering N Line in Anti-Tampering mode*/
#define ENSTATUS_REVP_Pos                     _UINT16_(12)                                   /* (REVP) Active Energy (CF1) direction Status Position */
#define ENSTATUS_REVP_Msk                     (_UINT16_(0x1) << ENSTATUS_REVP_Pos)          /* (REVP) Active Energy (CF1) direction Status Mask */
#define ENSTATUS_REVP_Val(value)              (ENSTATUS_REVP_Msk & (_UINT16_(value) << ENSTATUS_REVP_Pos))
#define   ENSTATUS_REVP_AP_Val                _UINT16_(0)                                   /* (REVP) Active Energy (CF1) direction Status Forward or Absolute */
#define   ENSTATUS_REVP_AN_Val                _UINT16_(1)                                   /* (REVP) Active Energy (CF1) direction Status Reverse */
#define ENSTATUS_REVQ_Pos                     _UINT16_(13)                                  /* (REVQ) Reactive Energy (CF2) direction Status Position */
#define ENSTATUS_REVQ_Msk                     (_UINT16_(0x1) << ENSTATUS_REVQ_Pos)          /* (REVQ) Reactive Energy (CF2) direction Status Mask */
#define ENSTATUS_REVQ_Val(value)              (ENSTATUS_REVQ_Msk & (_UINT16_(value) << ENSTATUS_REVQ_Pos))
#define   ENSTATUS_REVQ_RP_Val                _UINT16_(0)                                   /* (REVQ) Reactive Energy (CF2) direction Status Forward or Absolute */
#define   ENSTATUS_REVQ_RN_Val                _UINT16_(1)                                   /* (REVQ) Reactive Energy (CF2) direction Status Reverse */
#define ENSTATUS_PNLOAD_Pos                   _UINT16_(14)                                  /* (PNLOAD) Active No Load State Position */
#define ENSTATUS_PNLOAD_Msk                   (_UINT16_(0x1) << ENSTATUS_PNLOAD_Pos)        /* (PNLOAD) Active No Load State Mask */
#define ENSTATUS_PNLOAD_Val(value)            (ENSTATUS_PNLOAD_Msk & (_UINT16_(value) << ENSTATUS_PNLOAD_Pos))
#define   ENSTATUS_PNLOAD_FALSE_Val           _UINT16_(0)                                   /* (PNLOAD) NOT Active No Load State */
#define   ENSTATUS_PNLOAD_ACTIVE_Val          _UINT16_(1)                                   /* (PNLOAD) Active No Load State */
#define ENSTATUS_QNLOAD_Pos                   _UINT16_(15)                                  /* (QNLOAD) Reactive No Load State Position */
#define ENSTATUS_QNLOAD_Msk                   (_UINT16_(0x1) << ENSTATUS_QNLOAD_Pos)        /* (QNLOAD) Reactive No Load Status Mask */
#define ENSTATUS_QNLOAD_Val(value)            (ENSTATUS_QNLOAD_Msk & (_UINT16_(value) << ENSTATUS_QNLOAD_Pos))
#define   ENSTATUS_QNLOAD_FALSE_Val           _UINT16_(0)                                   /* (QNLOAD) NOT Reactive No Load State */
#define   ENSTATUS_QNLOAD_ACTIVE_Val          _UINT16_(1)                                   /* (QNLOAD) Reactive No Load State */
#define ENSTATUS_DEFAULT_Val                  _UINT16_(0)                                   /* (QNLOAD) Reactive No Load State */

/* ************************************************************************** */
/*   MEASUREMENT REGISTER                                                     */
/* ************************************************************************** */
/* -------- Measurement L Line Current RMS : (IRMS Offset: 0x48H) (R - 16 bits) - ATM90E26 Measurement L Line Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMS_Pos                              _UINT16_(0)                                   /* (IRMS) L Line Current RMS Value Position */
#define IRMS_Msk                              (_UINT16_(0xFFFF) << IRMS_Pos)                /* (IRMS) L Line Current RMS Value Mask */
#define IRMS_Val(value)                       (IRMS_Msk & (_UINT16_(value) << IRMS_Pos))
#define IRMS_DEFAULT_Val                      _UINT16_(0)

/* -------- Measurement Voltage RMS : (URMS Offset: 0x49H) (R - 16 bits) - ATM90E26 Measurement Voltage RMS -------- */
/* -------- Note: Data format is XXX.XX - Range (0-655.35) */
#define URMS_Uos                              _UINT16_(0)                                   /* (URMS) Voltage RMS Value Position */
#define URMS_Msk                              (_UINT16_(0xFFFF) << URMS_Pos)                /* (URMS) Voltage RMS Value Mask */
#define URMS_Val(value)                       (URMS_Msk & (_UINT16_(value) << URMS_Pos))
#define URMS_DEFAULT_Val                      _UINT16_(0)

/* -------- Measurement L Line Mean Active Power : (PMEAN Offset: 0x4AH) (R - 16 bits) - ATM90E26 Measurement L Line Mean Active Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kW */
#define PMEAN_Pos                             _UINT16_(0)                                   /* (PMEAN) L Line Mean Active Power Position */
#define PMEAN_Msk                             (_UINT16_(0xFFFF) << PMEAN_Pos)               /* (PMEAN) L Line Mean Active Power Mask */
#define PMEAN_Val(value)                      (PMEAN_Msk & (_UINT16_(value) << PMEAN_Pos))
#define PMEAN_DEFAULT_Val                     _UINT16_(0)

/* -------- Measurement L Line Mean Reactive Power : (QMEAN Offset: 0x4BH) (R - 16 bits) - ATM90E26 Measurement L Line Mean Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEAN_Pos                             _UINT16_(0)                                   /* (QMEAN) L Line Mean Reactive Power Position */
#define QMEAN_Msk                             (_UINT16_(0xFFFF) << QMEAN_Pos)               /* (QMEAN) L Line Mean Reactive Power Mask */
#define QMEAN_Val(value)                      (QMEAN_Msk & (_UINT16_(value) << QMEAN_Pos))
#define QMEAN_DEFAULT_Val                     _UINT16_(0)

/* -------- Measurement Frequency : (FREQ Offset: 0x4CH) (R - 16 bits) - ATM90E26 Measurement Frequency -------- */
/* -------- Note: Data format - Range [45,65] Hz */
#define FREQ_Pos                              _UINT16_(0)                                   /* (FREQ) Frequency Position */
#define FREQ_Msk                              (_UINT16_(0xFFFF) << FREQ_Pos)                /* (FREQ) Frequency Mask */
#define FREQ_Val(value)                       (FREQ_Msk & (_UINT16_(value) << FREQ_Pos))
#define FREQ_DEFAULT_Val                      _UINT16_(0)

/* -------- Measurement L Line Power Factor : (POWERF Offset: 0x4DH) (R - 16 bits) - ATM90E26 Measurement L Line Power Factor -------- */
/* -------- Note: Data format Signed - Range [-1,1) */
#define POWERF_Pos                            _UINT16_(0)                                   /* (POWERF) L Line Power Factor Position */
#define POWERF_Msk                            (_UINT16_(0xFFFF) << POWERF_Pos)              /* (POWERF) L Line Power Factor Mask */
#define POWERF_Val(value)                     (POWERF_Msk & (_UINT16_(value) << POWERF_Pos))
#define POWERF_DEFAULT_Val                    _UINT16_(0)

/* -------- Measurement Phase Angle between Voltage and L Line Current : (PANGLE Offset: 0x4EH) (R - 16 bits) - ATM90E26 Measurement Phase Angle -------- */
/* -------- Note: Data format Signed - Range [-180,180) */
#define PANGLE_Pos                            _UINT16_(0)                                   /* (PANGLE) Phase Angle between Voltage and L Line Current Position */
#define PANGLE_Msk                            (_UINT16_(0xFFFF) << PANGLE_Pos)              /* (PANGLE) Phase Angle between Voltage and L Line Current Mask */
#define PANGLE_Val(value)                     (PANGLE_Msk & (_UINT16_(value) << PANGLE_Pos))
#define PANGLE_DEFAULT_Val                    _UINT16_(0)

/* -------- Measurement L Line Mean Apparent Power : (SMEAN Offset: 0x4FH) (R - 16 bits) - ATM90E26 Measurement L Line Mean Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEAN_Pos                             _UINT16_(0)                                   /* (SMEAN) L Line Mean Apparent Power Position */
#define SMEAN_Msk                             (_UINT16_(0xFFFF) << SMEAN_Pos)               /* (SMEAN) L Line Mean Apparent Power Mask */
#define SMEAN_Val(value)                      (SMEAN_Msk & (_UINT16_(value) << SMEAN_Pos))
#define SMEAN_DEFAULT_Val                     _UINT16_(0)

/* -------- Measurement N Line Current RMS : (IRMS2 Offset: 0x68H) (R - 16 bits) - ATM90E26 Measurement N Line Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMS2_Pos                             _UINT16_(0)                                   /* (IRMS2) N Line Current RMS Value Position */
#define IRMS2_Msk                             (_UINT16_(0xFFFF) << IRMS2_Pos)               /* (IRMS2) N Line Current RMS Value Mask */
#define IRMS2_Val(value)                      (IRMS2_Msk & (_UINT16_(value) << IRMS2_Pos))
#define IRMS2_DEFAULT_Val                     _UINT16_(0)

/* -------- Measurement N Line Mean Active Power : (PMEAN2 Offset: 0x6AH) (R - 16 bits) - ATM90E26 Measurement L Line Mean Active Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kW */
#define PMEAN2_Pos                            _UINT16_(0)                                   /* (PMEAN) N Line Mean Active Power Position */
#define PMEAN2_Msk                            (_UINT16_(0xFFFF) << PMEAN2_Pos)              /* (PMEAN) N Line Mean Active Power Mask */
#define PMEAN2_Val(value)                     (PMEAN2_Msk & (_UINT16_(value) << PMEAN2_Pos))
#define PMEAN2_DEFAULT_Val                    _UINT16_(0)

/* -------- Measurement N Line Mean Reactive Power : (QMEAN2 Offset: 0x6BH) (R - 16 bits) - ATM90E26 Measurement N Line Mean Reative Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEAN2_Pos                            _UINT16_(0)                                   /* (QMEAN2) N Line Mean Reactive Power Position */
#define QMEAN2_Msk                            (_UINT16_(0xFFFF) << QMEAN2_Pos)              /* (QMEAN2) N Line Mean Reactive Power Mask */
#define QMEAN2_Val(value)                     (QMEAN2_Msk & (_UINT16_(value) << QMEAN2_Pos))
#define QMEAN2_DEFAULT_Val                    _UINT16_(0)

/* -------- Measurement N Line Power Factor : (POWERF Offset: 0x6DH) (R - 16 bits) - ATM90E26 Measurement N Line Power Factor -------- */
/* -------- Note: Data format Signed - Range [-1,1) */
#define POWERF2_Pos                           _UINT16_(0)                                   /* (POWERF2) N Line Power Factor Position */
#define POWERF2_Msk                           (_UINT16_(0xFFFF) << POWERF2_Pos)             /* (POWERF2) N Line Power Factor Mask */
#define POWERF2_Val(value)                    (POWERF2_Msk & (_UINT16_(value) << POWERF2_Pos))
#define POWERF2_DEFAULT_Val                   _UINT16_(0)

/* -------- Measurement Phase Angle between Voltage and N Line Current : (PANGLE2 Offset: 0x6EH) (R - 16 bits) - ATM90E26 Measurement N Line Phase Angle -------- */
/* -------- Note: Data format Signed - Range [-180,180) */
#define PANGLE2_Pos                           _UINT16_(0)                                   /* (PANGLE) Phase Angle between Voltage and N Line Current Position */
#define PANGLE2_Msk                           (_UINT16_(0xFFFF) << PANGLE2_Pos)             /* (PANGLE) Phase Angle between Voltage and N Line Current Mask */
#define PANGLE2_Val(value)                    (PANGLE2_Msk & (_UINT16_(value) << PANGLE2_Pos))
#define PANGLE2_DEFAULT_Val                   _UINT16_(0)

/* -------- Measurement N Line Mean Apparent Power : (SMEAN2 Offset: 0x6FH) (R - 16 bits) - ATM90E26 Measurement N Line Mean Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEAN2_Pos                            _UINT16_(0)                                   /* (SMEAN2) N Line Mean Apparent Power Position */
#define SMEAN2_Msk                            (_UINT16_(0xFFFF) << SMEAN2_Pos)              /* (SMEAN2) N Line Mean Apparent Power Mask */
#define SMEAN2_Val(value)                     (SMEAN2_Msk & (_UINT16_(value) << SMEAN2_Pos))
#define SMEAN2_DEFAULT_Val                    _UINT16_(0)

/* MISRA C-2012 deviation block end */

/** \brief ATM90EXX Control register API structure */
/** \brief ATM90EXX register API structure */

/** \brief ATM90EXX register Address values */
typedef enum
{
	SOFTRESET_ADDR   = 0x00,
	SYSSTATUS_ADDR   = 0x01,
	FUNCEN_ADDR      = 0x02,
	SAGTH_ADDR       = 0x03,
	SMALLPMOD_ADDR   = 0x04,
    LASTSPIDATA_ADDR = 0x06,
	LSB_ADDR		 = 0x08,
	CALSTART_ADDR    = 0x20,
	PLCONSTH_ADDR    = 0x21,
	PLCONSTL_ADDR    = 0x22,
	LGAIN_ADDR       = 0x23,
	LPHI_ADDR        = 0x24,
	NGAIN_ADDR       = 0x25,
	NPHI_ADDR        = 0x26,
	PSTARTTH_ADDR    = 0x27,
	PNOLTH_ADDR      = 0x28,
	QSTARTTH_ADDR    = 0x29,
	QNOLTH_ADDR      = 0x2A,
	MMODE_ADDR       = 0x2B,
	CS1_ADDR         = 0x2C,
	ADJSTART_ADDR    = 0x30,
	UGAIN_ADDR       = 0x31,
	IGAINL_ADDR      = 0x32,
	IGAINN_ADDR      = 0x33,
	UOFFSET_ADDR     = 0x34,
	IOFFSETL_ADDR    = 0x35,
	IOFFSETN_ADDR    = 0x36,
	POFFSETL_ADDR    = 0x37,
	POFFSETN_ADDR    = 0x38,
	QOFFSETL_ADDR    = 0x39,
	QOFFSETN_ADDR    = 0x3A,
	CS2_ADDR         = 0x3B,
	APENERGY_ADDR    = 0x40,
	ANENERGY_ADDR    = 0x41,
	ATENERGY_ADDR    = 0x42,
	RPENERGY_ADDR    = 0x43,
	RNENERGY_ADDR    = 0x44,
	RTENERGY_ADDR    = 0x45,
	ENSTATUS_ADDR    = 0x46,		
	IRMS_ADDR        = 0x48,
	URMS_ADDR        = 0x49,
	PMEAN_ADDR       = 0x4A,
	QMEAN_ADDR       = 0x4B,
	FREQ_ADDR        = 0x4C,
	POWERF_ADDR      = 0x4D,
	PANGLE_ADDR      = 0x4E,
	SMEAN_ADDR       = 0x4F,	
	IRMS2_ADDR       = 0x68,
	PMEAN2_ADDR      = 0x6A,
	QMEAN2_ADDR      = 0x6B,
	POWERF2_ADDR     = 0x6D,
	PANGLE2_ADDR     = 0x6E,
	SMEAN2_ADDR      = 0x6F,
    INVALID_ADDR     = 0xFF		
}ATM90EXX_REGISTERS_ADDR;

/* ATM90E2X Metering Mode Definitions */
typedef enum
{
    ATM90EXX_METERING_MODE_ANTI_TAMPER = 0, /* Anti Tampering Mode. CFx represents the larger energy line */
	ATM90EXX_METERING_MODE_FIXED_L,         /* L Line Mode (fixed L line). CFx represents L line energy all the time. */
	ATM90EXX_METERING_MODE_L_AND_N,         /* L+N Mode (1P3W system). CFx represents the arithmetic sum of L line and N line energy */
	ATM90EXX_METERING_MODE_LNSELBIT         /* Flexible Mode. CFx represents energy of the specified line. */
} ATM90EXX_METERING_MODE_STATES;

typedef struct
{
    /* Control Registers */
    __IO  uint16_t UScale;
    __IO  uint16_t IScale;
    __IO  uint16_t MMDx;
    __IO  uint16_t SoftReset;
	__IO  uint16_t FuncEn;
    __IO  uint16_t SmallPMod;
    __IO  uint16_t MMode;
    __IO  uint16_t CS1;
    __IO  uint16_t CS2;
    __IO  uint16_t LastSpiData;
} ATM90EXX_REGS_CONTROL;

typedef struct {
    /* Thresholds */
    __IO  uint16_t SagTh;
    __IO  uint16_t PStartTh;
    __IO  uint16_t PNolTh;
    __IO  uint16_t QStartTh;
    __IO  uint16_t QNolTh;
} ATM90EXX_REGS_THRESHOLDS;

typedef struct {
    /* Metering Calibration - Checksum on CS1 */
    __IO  uint16_t MC;                  /* R/W Meter Constant in pulses/KWh */
    __IO  uint16_t PLconstH;
    __IO  uint16_t PLconstL;
    __IO  uint16_t Lgain;
    __IO  uint16_t Lphi;
    __IO  uint16_t Ngain;
    __IO  uint16_t Nphi;
} ATM90EXX_REGS_CAL_MET;

typedef struct {  
    /* Measurement Calibration - Checksum on CS2 */
	__IO  uint16_t Ugain;
    __IO  uint16_t IgainL;
    __IO  uint16_t IgainN;
    __IO  uint16_t Uoffset;
    __IO  uint16_t IoffsetL;
    __IO  uint16_t IoffsetN;
    __IO  uint16_t PoffsetL;
    __IO  uint16_t QoffsetL;
    __IO  uint16_t PoffsetN;
    __IO  uint16_t QoffsetN;
} ATM90EXX_REGS_CAL_MEAS;

typedef struct {
    /* System Status */
	__O   uint16_t SysStatus;
    __O   uint16_t EnStatus;
} ATM90EXX_REGS_STATUS;

typedef struct {
    /* Measurements */
	__O   uint16_t Irms;
    __O   uint16_t Urms;
    __O   uint16_t Pmean;
    __O   uint16_t Qmean;
    __O   uint16_t Smean;
    __O   uint16_t PowerF;
    __O   uint16_t Pangle;
    __O   uint16_t Irms2;
    __O   uint16_t Pmean2;
    __O   uint16_t Qmean2;
    __O   uint16_t PowerF2;
    __O   uint16_t Pangle2;
    __O   uint16_t Smean2;
    __O   uint16_t Freq;
#ifdef ATM90E26_LSB_SUPPORT
	__O   uint16_t IrmsLSB;
    __O   uint16_t UrmsLSB;
    __O   uint16_t PmeanLSB;
    __O   uint16_t QmeanLSB;
    __O   uint16_t SmeanLSB;
    __O   uint16_t Irms2LSB;
    __O   uint16_t Pmean2LSB;
    __O   uint16_t Qmean2LSB;
    __O   uint16_t Smean2LSB;
#endif
} ATM90EXX_REGS_MEAS;

typedef struct {
    /* Metering */
    __O   uint16_t APEnergy;    // Forward Active Energy APenergy
    __O   uint16_t ANEnergy;    // Reverse Active Energy
    __O   uint16_t ATEnergy;    // Absolute Active Energy
    __O   uint16_t RPEnergy;    // Forward (Inductive) Reactive Energy
    __O   uint16_t RNEnergy;    // Reverse (Capacitive) Reactive Energy
    __O   uint16_t RTEnergy;    // Absolute Reactive Energy
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
    ATM90EXX_REGS_CAL_MET       calMetInfo;
    ATM90EXX_REGS_CAL_MEAS      calMeasInfo;
} ATM90EXX_CONF;

typedef struct
{  
    ATM90EXX_REGS_MEAS          measInfo;
    ATM90EXX_REGS_MET           metInfo;
} ATM90EXX_ACC;

#endif /* ATM90E26_REGS_H */
