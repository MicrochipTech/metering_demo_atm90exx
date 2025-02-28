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

#ifndef ATM90E36_REGS_H
#define ATM90E36_REGS_H

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR METROLOGY REGISTERS                          */
/* ************************************************************************** */
/* MISRA C-2012 deviation block start */
/* MISRA C-2012 Rule 5.4 deviated 64 times.  Deviation record ID - H3_MISRAC_2012_R_5_4_DR_1 */

/* -------- SOFT RESET : (SOFT RESET Offset: 0x00) (W - 16 bits) ATM90E26 Soft Reset Register -------- */
#define SOFTRESET_SOFTRESET_Pos                         _UINT16_(0)                                   /* (SOFTRESET) Soft Reset Position */
#define SOFTRESET_SOFTRESET_Msk                         (_UINT16_(0xFFFF) << SOFTRESET_SOFTRESET_Pos) /* (SOFTRESET) Soft Reset Mask */
#define SOFTRESET_SOFTRESET(value)                      (SOFTRESET_SOFTRESET_Msk & (_UINT16_(value) << SOFTRESET_SOFTRESET_Pos))
#define SOFTRESET_DEFAULT_Val                           _UINT16_(0x789A) 

/* -------- SYS STATUS0 : (SYSSTATUS Offset: 0x01) (R/C - 16 bits) ATM90E36 SysStatus0 Register -------- */
#define SYSSTATUS0_PHASELOSEWN_Pos                      _UINT16_(2)                                     /* (SYSSTATUS0) System Status Voltage Phase Losing Position */
#define SYSSTATUS0_PHASELOSEWN_Msk                      (_UINT16_(0x1) << SYSSTATUS0_PHASELOSEWN_Pos)   /* (SYSSTATUS0) System Status Voltage Phase Losing Mask */
#define SYSSTATUS0_PHASELOSEWN_(value)                  (SYSSTATUS0_PHASELOSEWN_Msk & (_UINT16_(value) << SYSSTATUS0_PHASELOSEWN_Pos))
#define SYSSTATUS0_SAGWARN_Pos                           _UINT16_(3)                                    /* (SYSSTATUS0) System Status SagWarn Position */
#define SYSSTATUS0_SAGWARN_Msk                           (_UINT16_(0x1) << SYSSTATUS0_SAGWARN_Pos)      /* (SYSSTATUS0) System Status SagWarn Mask */
#define SYSSTATUS0_SAGWARN_(value)                       (SYSSTATUS0_SAGWARN_Msk & (_UINT16_(value) << SYSSTATUS0_SAGWARN_Pos))
#define SYSSTATUS0_IREVWN_Pos                           _UINT16_(6)                                     /* (SYSSTATUS0) System Status Current Phase Sequence Error Position */
#define SYSSTATUS0_IREVWN_Msk                           (_UINT16_(0x1) << SYSSTATUS0_IREVWN_Pos)        /* (SYSSTATUS0) System Status Current Phase Sequence Error Mask */
#define SYSSTATUS0_IREVWN_(value)                       (SYSSTATUS0_IREVWN_Msk & (_UINT16_(value) << SYSSTATUS0_IREVWN_Pos))
#define SYSSTATUS0_UREVWN_Pos                           _UINT16_(7)                                     /* (SYSSTATUS0) System Status Voltage Phase Sequence Error Position */
#define SYSSTATUS0_UREVWN_Msk                           (_UINT16_(0x1) << SYSSTATUS0_UREVWN_Pos)        /* (SYSSTATUS0) System Status Voltage Phase Sequence Error Mask */
#define SYSSTATUS0_UREVWN_(value)                       (SYSSTATUS0_UREVWN_Msk & (_UINT16_(value) << SYSSTATUS0_UREVWN_Pos))
#define SYSSTATUS0_CS3_Pos                              _UINT16_(8)                                     /* (SYSSTATUS) System Status CS3 Position */
#define SYSSTATUS0_CS3_Msk                              (_UINT16_(0x1) << SYSSTATUS0_CS3_Pos)           /* (SYSSTATUS) System Status CS3 Mask */
#define SYSSTATUS0_CS3_(value)                          (SYSSTATUS0_CS3_Msk & (_UINT16_(value) << SYSSTATUS0_CS3_Pos))
#define   SYSSTATUS0_CS3_OK_Val                         _UINT16_(0x0)                                   /* (CS3) CS3 checksum correct (default) */
#define   SYSSTATUS0_CS3_ERR_Val                        _UINT16_(0x1)                                   /* (CS3) CS3 checksum error */
#define SYSSTATUS0_CS2_Pos                               _UINT16_(10)                                   /* (CS2) System Status CS2 Position */
#define SYSSTATUS0_CS2_Msk                              (_UINT16_(0x1) << SYSSTATUS0_CS2_Pos)            /* (CS2) System Status CS2 Mask */
#define SYSSTATUS0_CS2_(value)                          (SYSSTATUS0_CS2_Msk & (_UINT16_(value) << SYSSTATUS0_CS2_Pos))
#define   SYSSTATUS0_CS2_OK_Val                         _UINT16_(0x0)                                 /* (CS2) CS2 checksum correct (default) */
#define   SYSSTATUS0_CS2_ERR_Val                        _UINT16_(0x1)                                 /* (CS2) CS2 checksum error */
#define SYSSTATUS0_CS1_Pos                               _UINT16_(12)                                   /* (CS1) System Status CS1 Position */
#define SYSSTATUS0_CS1_Msk                              (_UINT16_(0x1) << SYSSTATUS0_CS1_Pos)            /* (CS1) System Status CS1 Mask */
#define SYSSTATUS0_CS1_(value)                          (SYSSTATUS0_CS1_Msk & (_UINT16_(value) << SYSSTATUS0_CS1_Pos))
#define   SYSSTATUS0_CS1_OK_Val                         _UINT16_(0x0)                                 /* (CS1) CS1 checksum correct (default) */
#define   SYSSTATUS0_CS1_ERR_Val                        _UINT16_(0x1)                                 /* (CS1) CS1 checksum error */
#define SYSSTATUS0_CS0_Pos                               _UINT16_(14)                                   /* (CS0) System Status CS0 Position */
#define SYSSTATUS0_CS0_Msk                              (_UINT16_(0x1) << SYSSTATUS0_CS0_Pos)            /* (CS0) System Status CS0 Mask */
#define SYSSTATUS0_CS0_(value)                          (SYSSTATUS0_CS0_Msk & (_UINT16_(value) << SYSSTATUS0_CS0_Pos))
#define   SYSSTATUS0_CS0_OK_Val                         _UINT16_(0x0)                                 /* (CS0) CS0 checksum correct (default) */
#define   SYSSTATUS0_CS0_ERR_Val                        _UINT16_(0x1)                                 /* (CS0) CS0 checksum error */
#define SYSTATUS0_DEFAULT_Val                           _UINT16_(0x0)

/* -------- SYS STATUS1 : (SYSSTATUS1 Offset: 0x02) (R/C - 16 bits) ATM90E36 SysStatus1 Register -------- */
#define SYSSTATUS1_REVPCHGC_Pos                           _UINT16_(0)                                   /* (EVPCHGC) System Status RevPchg Position */
#define SYSSTATUS1_REVPCHGC_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVPCHGC_Pos)      /* (EVPCHGC) System Status RevPchg Mask */
#define SYSSTATUS1_REVPCHGC_(value)                       (SYSSTATUS1_REVPCHGC_Msk & (_UINT16_(value) << SYSSTATUS1_REVPCHGC_Pos))
#define SYSSTATUS1_REVPCHGB_Pos                           _UINT16_(1)                                   /* (EVPCHGB) System Status RevPchg Position */
#define SYSSTATUS1_REVPCHGB_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVPCHGB_Pos)      /* (EVPCHGB) System Status RevPchg Mask */
#define SYSSTATUS1_REVPCHGB_(value)                       (SYSSTATUS1_REVPCHGB_Msk & (_UINT16_(value) << SYSSTATUS1_REVPCHGB_Pos))
#define SYSSTATUS1_REVPCHGA_Pos                           _UINT16_(2)                                   /* (EVPCHGA) System Status RevPchg Position */
#define SYSSTATUS1_REVPCHGA_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVPCHGA_Pos)      /* (EVPCHGA) System Status RevPchg Mask */
#define SYSSTATUS1_REVPCHGA_(value)                       (SYSSTATUS1_REVPCHGA_Msk & (_UINT16_(value) << SYSSTATUS1_REVPCHGA_Pos))
#define SYSSTATUS1_REVPCHGT_Pos                           _UINT16_(3)                                   /* (EVPCHGT) System Status RevPchg Position */
#define SYSSTATUS1_REVPCHGT_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVPCHGT_Pos)      /* (EVPCHGT) System Status RevPchg Mask */
#define SYSSTATUS1_REVPCHGT_(value)                       (SYSSTATUS1_REVPCHGT_Msk & (_UINT16_(value) << SYSSTATUS1_REVPCHGT_Pos))
#define SYSSTATUS1_REVQCHGC_Pos                           _UINT16_(4)                                   /* (EVQCHGC) System Status RevQchg Position */
#define SYSSTATUS1_REVQCHGC_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVQCHGC_Pos)      /* (EVQCHGC) System Status RevQchg Mask */
#define SYSSTATUS1_REVQCHGC_(value)                       (SYSSTATUS1_REVQCHGC_Msk & (_UINT16_(value) << SYSSTATUS1_REVQCHGC_Pos))
#define SYSSTATUS1_REVQCHGB_Pos                           _UINT16_(5)                                   /* (EVQCHGB) System Status RevQchg Position */
#define SYSSTATUS1_REVQCHGB_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVQCHGB_Pos)      /* (EVQCHGB) System Status RevQchg Mask */
#define SYSSTATUS1_REVQCHGB_(value)                       (SYSSTATUS1_REVQCHGB_Msk & (_UINT16_(value) << SYSSTATUS1_REVQCHGB_Pos))
#define SYSSTATUS1_REVQCHGA_Pos                           _UINT16_(6)                                   /* (EVQCHGA) System Status RevQchg Position */
#define SYSSTATUS1_REVQCHGA_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVQCHGA_Pos)      /* (EVQCHGA) System Status RevQchg Mask */
#define SYSSTATUS1_REVQCHGA_(value)                       (SYSSTATUS1_REVQCHGA_Msk & (_UINT16_(value) << SYSSTATUS1_REVQCHGA_Pos))
#define SYSSTATUS1_REVQCHGT_Pos                           _UINT16_(7)                                   /* (EVQCHGT) System Status RevQchg Position */
#define SYSSTATUS1_REVQCHGT_Msk                           (_UINT16_(0x1) << SYSSTATUS1_REVQCHGT_Pos)      /* (EVQCHGT) System Status RevQchg Mask */
#define SYSSTATUS1_REVQCHGT_(value)                       (SYSSTATUS1_REVQCHGT_Msk & (_UINT16_(value) << SYSSTATUS1_REVQCHGT_Pos))
#define SYSSTATUS1_DFTDONE_Pos                            _UINT16_(9)                                   /* (DFTDONE) System Status DFTDONE Position */
#define SYSSTATUS1_DFTDONE_Msk                            (_UINT16_(0x1) << SYSSTATUS1_DFTDONE_Pos)      /* (DFTDONE) System Status DFTDONE Mask */
#define SYSSTATUS1_DFTDONE_(value)                        (SYSSTATUS1_DFTDONE_Msk & (_UINT16_(value) << SYSSTATUS1_DFTDONE_Pos))
#define SYSSTATUS1_THDIO_Pos                              _UINT16_(10)                                   /* (THDIO) System Status THDIO Position */
#define SYSSTATUS1_THDIO_Msk                              (_UINT16_(0x1) << SYSSTATUS1_THDIO_Pos)      /* (THDIO) System Status THDIO Mask */
#define SYSSTATUS1_THDIO_(value)                          (SYSSTATUS1_THDIO_Msk & (_UINT16_(value) << SYSSTATUS1_THDIO_Pos))
#define SYSSTATUS1_THDUO_Pos                              _UINT16_(11)                                   /* (THDUO) System Status THDUO Position */
#define SYSSTATUS1_THDUO_Msk                              (_UINT16_(0x1) << SYSSTATUS1_THDUO_Pos)      /* (THDUO) System Status THDUO Mask */
#define SYSSTATUS1_THDUO_(value)                          (SYSSTATUS1_THDUO_Msk & (_UINT16_(value) << SYSSTATUS1_THDUO_Pos))
#define SYSSTATUS1_INOV0_Pos                              _UINT16_(14)                                   /* (INOV0) System Status INOV0 Position */
#define SYSSTATUS1_INOV0_Msk                              (_UINT16_(0x1) << SYSSTATUS1_INOV0_Pos)      /* (INOV0) System Status INOV0 Mask */
#define SYSSTATUS1_INOV0_(value)                          (SYSSTATUS1_INOV0_Msk & (_UINT16_(value) << SYSSTATUS1_INOV0_Pos))
#define SYSSTATUS1_INOV1_Pos                              _UINT16_(15)                                   /* (INOV1) System Status INOV1 Position */
#define SYSSTATUS1_INOV1_Msk                              (_UINT16_(0x1) << SYSSTATUS1_INOV1_Pos)      /* (INOV1) System Status INOV1 Mask */
#define SYSSTATUS1_INOV1_(value)                          (SYSSTATUS1_INOV1_Msk & (_UINT16_(value) << SYSSTATUS1_INOV1_Pos))
#define SYSTATUS1_DEFAULT_Val                           _UINT16_(0x0)

/* -------- Function Enable 0 : (FUNCEN0 Offset: 0x03H) (R/W - 16 bits) ATM90E36 Function Enable 0 Register -------- */
#define FUNCEN0_PHASELOSSWNEN_Pos                         _UINT16_(2)                                   /* (FUNCEN0) Function enable Phase Loss Position */
#define FUNCEN0_PHASELOSSWNEN_Msk                         (_UINT16_(0x1) << FUNCEN0_PHASELOSSWNEN_Pos)  /* (FUNCEN0) Function enable Phase Loss Mask */
#define FUNCEN0_PHASELOSSWNEN_(value)                     (FUNCEN0_PHASELOSSWNEN_Msk & (_UINT16_(value) << FUNCEN0_PHASELOSSWNEN_Pos))
#define   FUNCEN0_PHASELOSSWNEN_DIS_Val                   _UINT16_(0x0)                                 /* (FUNCEN0) Phase Loss disable (default) */
#define   FUNCEN0_PHASELOSSWNEN_EN_Val                    _UINT16_(0x1)                                 /* (FUNCEN0) Phase Loss enable */
#define FUNCEN0_SAGWNEN_Pos                               _UINT16_(3)                                   /* (FUNCEN0) Function enable SagEn Position */
#define FUNCEN0_SAGWNEN_Msk                               (_UINT16_(0x1) << FUNCEN0_SAGWNEN_Pos)        /* (FUNCEN0) Function enable SagEn Mask */
#define FUNCEN0_SAGWNEN_(value)                           (FUNCEN0_SAGWNEN_Msk & (_UINT16_(value) << FUNCEN0_SAGWNEN_Pos))
#define   FUNCEN0_SAGWNEN_DIS_Val                         _UINT16_(0x0)                                 /* (FUNCEN0) SagEn disable (default) */
#define   FUNCEN0_SAGWNEN_EN_Val                          _UINT16_(0x1)                                 /* (FUNCEN0) SagEn enable */
#define FUNCEN0_IREVWNEN_Pos                              _UINT16_(6)                                   /* (FUNCEN0) Function enable Current Phase Sequence Error Position */
#define FUNCEN0_IREVWNEN_Msk                              (_UINT16_(0x1) << FUNCEN0_IREVWNEN_Pos)       /* (FUNCEN0) Function enable Current Phase Sequence Error Mask */
#define FUNCEN0_IREVWNEN_(value)                          (FUNCEN0_IREVWNEN_Msk & (_UINT16_(value) << FUNCEN0_IREVWNEN_Pos))
#define   FUNCEN0_IREVWNEN_DIS_Val                        _UINT16_(0x0)                                 /* (FUNCEN0) Phase Current Phase Sequence Error disable (default) */
#define   FUNCEN0_IREVWNEN_EN_Val                         _UINT16_(0x1)                                 /* (FUNCEN0) Phase Current Phase Sequence Error enable */
#define FUNCEN0_UREVWNEN_Pos                              _UINT16_(7)                                   /* (FUNCEN0) Function enable Voltage Phase Sequence Error Position */
#define FUNCEN0_UREVWNEN_Msk                              (_UINT16_(0x1) << FUNCEN0_UREVWNEN_Pos)       /* (FUNCEN0) Function enable Voltage Phase Sequence Error Mask */
#define FUNCEN0_UREVWNEN_(value)                          (FUNCEN0_UREVWNEN_Msk & (_UINT16_(value) << FUNCEN0_UREVWNEN_Pos))
#define   FUNCEN0_UREVWNEN_DIS_Val                        _UINT16_(0x0)                                 /* (FUNCEN0) Phase Voltage Phase Sequence Error disable (default) */
#define   FUNCEN0_UREVWNEN_EN_Val                         _UINT16_(0x1)                                 /* (FUNCEN0) Phase Voltage Phase Sequence Error enable */
#define FUNCEN0_CS2ERREN_Pos                              _UINT16_(10)                                  /* (FUNCEN0) Function enable CS2 Error Position */
#define FUNCEN0_CS2ERREN_Msk                              (_UINT16_(0x1) << FUNCEN0_CS2ERREN_Pos)       /* (FUNCEN0) Function enable CS2 Error Mask */
#define FUNCEN0_CS2ERREN_(value)                          (FUNCEN0_CS2ERREN_Msk & (_UINT16_(value) << FUNCEN0_CS2ERREN_Pos))
#define   FUNCEN0_CS2ERREN_DIS_Val                        _UINT16_(0x0)                                 /* (FUNCEN0) Phase CS2 Error disable (default) */
#define   FUNCEN0_CS2ERREN_EN_Val                         _UINT16_(0x1)                                 /* (FUNCEN0) Phase CS2 Error enable */
#define FUNCEN0_DEFAULT_Val                               _UINT16_(0x0)

/* -------- Function Enable 1 : (FUNCEN1 Offset: 0x04H) (R/W - 16 bits) ATM90E36 Function Enable 1 Register -------- */
#define FUNCEN1_REVPCHGCEN_Pos                           _UINT16_(0)                                   /* (FUNCEN1) Function enable Direction Change Phase C  Position */
#define FUNCEN1_REVPCHGCEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVPCHGCEN_Pos)     /* (FUNCEN1) Function enable Direction Change Phase C Mask */
#define FUNCEN1_REVPCHGCEN_(value)                       (FUNCEN1_REVPCHGCEN_Msk & (_UINT16_(value) << FUNCEN1_REVPCHGCEN_Pos))
#define   FUNCEN1_REVPCHGCEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevPchgCEn disable (default) */
#define   FUNCEN1_REVPCHGCEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevPchgCEn enable */
#define FUNCEN1_REVPCHGBEN_Pos                           _UINT16_(1)                                   /* (FUNCEN1) Function enable Direction Change Phase B  Position */
#define FUNCEN1_REVPCHGBEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVPCHGBEN_Pos)     /* (FUNCEN1) Function enable Direction Change Phase B Mask */
#define FUNCEN1_REVPCHGBEN_(value)                       (FUNCEN1_REVPCHGBEN_Msk & (_UINT16_(value) << FUNCEN1_REVPCHGCEN_Pos))
#define   FUNCEN1_REVPCHGBEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevPchgbEn disable (default) */
#define   FUNCEN1_REVPCHGBEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevPchgBEn enable */
#define FUNCEN1_REVPCHGAEN_Pos                           _UINT16_(2)                                   /* (FUNCEN1) Function enable Direction Change Phase A  Position */
#define FUNCEN1_REVPCHGAEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVPCHGAEN_Pos)     /* (FUNCEN1) Function enable Direction Change Phase A Mask */
#define FUNCEN1_REVPCHGAEN_(value)                       (FUNCEN1_REVPCHGAEN_Msk & (_UINT16_(value) << FUNCEN1_REVPCHGAEN_Pos))
#define   FUNCEN1_REVPCHGAEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevPchgAEn disable (default) */
#define   FUNCEN1_REVPCHGAEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevPchgAEn enable */
#define FUNCEN1_REVPCHGTEN_Pos                           _UINT16_(3)                                   /* (FUNCEN1) Function enable Direction Change All Phases Position */
#define FUNCEN1_REVPCHGTEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVPCHGTEN_Pos)     /* (FUNCEN1) Function enable Direction Change All Phases Mask */
#define FUNCEN1_REVPCHGTEN_(value)                       (FUNCEN1_REVPCHGTEN_Msk & (_UINT16_(value) << FUNCEN1_REVPCHGTEN_Pos))
#define   FUNCEN1_REVPCHGTEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevPchgTEn disable (default) */
#define   FUNCEN1_REVPCHGTEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevPchgTEn enable */
#define FUNCEN1_REVQCHGCEN_Pos                           _UINT16_(4)                                   /* (FUNCEN1) Function enable Direction Change Phase C  Position */
#define FUNCEN1_REVQCHGCEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVQCHGCEN_Pos)     /* (FUNCEN1) Function enable Direction Change Phase C Mask */
#define FUNCEN1_REVQCHGCEN_(value)                       (FUNCEN1_REVQCHGCEN_Msk & (_UINT16_(value) << FUNCEN1_REVQCHGCEN_Pos))
#define   FUNCEN1_REVQCHGCEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevQchgCEn disable (default) */
#define   FUNCEN1_REVQCHGCEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevQchgCEn enable */
#define FUNCEN1_REVQCHGBEN_Pos                           _UINT16_(5)                                   /* (FUNCEN1) Function enable Direction Change Phase B  Position */
#define FUNCEN1_REVQCHGBEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVQCHGBEN_Pos)     /* (FUNCEN1) Function enable Direction Change Phase B Mask */
#define FUNCEN1_REVQCHGBEN_(value)                       (FUNCEN1_REVQCHGBEN_Msk & (_UINT16_(value) << FUNCEN1_REVQCHGCEN_Pos))
#define   FUNCEN1_REVQCHGBEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevPchgbEn disable (default)*/
#define   FUNCEN1_REVQCHGBEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevPchgBEn enable */
#define FUNCEN1_REVQCHGAEN_Pos                           _UINT16_(6)                                   /* (FUNCEN1) Function enable Direction Change Phase A  Position */
#define FUNCEN1_REVQCHGAEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVPCHGAEN_Pos)     /* (FUNCEN1) Function enable Direction Change Phase A Mask */
#define FUNCEN1_REVQCHGAEN_(value)                       (FUNCEN1_REVQCHGAEN_Msk & (_UINT16_(value) << FUNCEN1_REVQCHGAEN_Pos))
#define   FUNCEN1_REVQCHGAEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevPchgAEn disable (default)*/
#define   FUNCEN1_REVQCHGAEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevPchgAEn enable */
#define FUNCEN1_REVQCHGTEN_Pos                           _UINT16_(7)                                   /* (FUNCEN1) Function enable Direction Change All Phases  Position */
#define FUNCEN1_REVQCHGTEN_Msk                           (_UINT16_(0x1) << FUNCEN1_REVPCHGTEN_Pos)     /* (FUNCEN1) Function enable Direction Change All Phases Mask */
#define FUNCEN1_REVQCHGTEN_(value)                       (FUNCEN1_REVQCHGTEN_Msk & (_UINT16_(value) << FUNCEN1_REVQCHGTEN_Pos))
#define   FUNCEN1_REVQCHGTEN_DIS_Val                     _UINT16_(0x0)                                 /* (FUNCEN1) RevPchgTEn disable (default)*/
#define   FUNCEN1_REVQCHGTEN_EN_Val                      _UINT16_(0x1)                                 /* (FUNCEN1) RevPchgTEn enable */
#define FUNCEN1_DFTDONE_Pos                              _UINT16_(9)                                   /* (FUNCEN1) Function enable DFTDONE  Position */
#define FUNCEN1_DFTDONE_Msk                             (_UINT16_(0x1) << FUNCEN1_DFTDONE_Pos)         /* (FUNCEN1) Function enable DFTDONE Mask */
#define FUNCEN1_DFTDONE_(value)                         (FUNCEN1_DFTDONE_Msk & (_UINT16_(value) << FUNCEN1_DFTDONE_Pos))
#define   FUNCEN1_DFTDONE_DIS_Val                       _UINT16_(0x0)                                  /* (FUNCEN1) DFTDONE disable (default) */
#define   FUNCEN1_DFTDONE_EN_Val                        _UINT16_(0x1)                                  /* (FUNCEN1) DFTDONE enable */
#define FUNCEN1_THDIOVEN_Pos                              _UINT16_(10)                                 /* (FUNCEN1) Function enable THDIOVEN  Position */
#define FUNCEN1_THDIOVEN_Msk                             (_UINT16_(0x1) << FUNCEN1_THDIOVEN_Pos)       /* (FUNCEN1) Function enable THDIOVEN Mask */
#define FUNCEN1_THDIOVEN_(value)                         (FUNCEN1_THDIOVEN_Msk & (_UINT16_(value) << FUNCEN1_THDIOVEN_Pos))
#define   FUNCEN1_THDIOVEN_DIS_Val                       _UINT16_(0x0)                                 /* (FUNCEN1) THDIOVEN disable (default) */
#define   FUNCEN1_THDIOVEN_EN_Val                        _UINT16_(0x1)                                 /* (FUNCEN1) THDIOVEN enable */
#define FUNCEN1_THDUOVEN_Pos                              _UINT16_(11)                                 /* (FUNCEN1) Function enable THDUOVEN  Position */
#define FUNCEN1_THDUOVEN_Msk                             (_UINT16_(0x1) << FUNCEN1_THDUOVEN_Pos)       /* (FUNCEN1) Function enable THDUOVEN Mask */
#define FUNCEN1_THDUOVEN_(value)                         (FUNCEN1_THDUOVEN_Msk & (_UINT16_(value) << FUNCEN1_THDUOVEN_Pos))
#define   FUNCEN1_THDUOVEN_DIS_Val                       _UINT16_(0x0)                                 /* (FUNCEN1) THDUOVEN disable (default) */
#define   FUNCEN1_THDUOVEN_EN_Val                        _UINT16_(0x1)                                 /* (FUNCEN1) THDUOVEN enable */
#define FUNCEN1_INOV0EN_Pos                              _UINT16_(14)                                  /* (FUNCEN1) Function enable INOV0EN  Position */
#define FUNCEN1_INOV0EN_Msk                             (_UINT16_(0x1) << FUNCEN1_INOV0EN_Pos)         /* (FUNCEN1) Function enable INOV0EN Mask */
#define FUNCEN1_INOV0EN_(value)                         (FUNCEN1_INOV0EN_Msk & (_UINT16_(value) << FUNCEN1_INOV0EN_Pos))
#define   FUNCEN1_INOV0EN_DIS_Val                       _UINT16_(0x0)                                  /* (FUNCEN1) INOV0EN disable (default) */
#define   FUNCEN1_INOV0EN_EN_Val                        _UINT16_(0x1)                                  /* (FUNCEN1) INOV0EN enable */
#define FUNCEN1_INOV1EN_Pos                              _UINT16_(15)                                  /* (FUNCEN1) Function enable INOV1EN  Position */
#define FUNCEN1_INOV1EN_Msk                             (_UINT16_(0x1) << FUNCEN1_INOV1EN_Pos)         /* (FUNCEN1) Function enable INOV1EN Mask */
#define FUNCEN1_INOV1EN_(value)                         (FUNCEN1_INOV1EN_Msk & (_UINT16_(value) << FUNCEN1_INOV1EN_Pos))
#define   FUNCEN1_INOV1EN_DIS_Val                       _UINT16_(0x0)                                  /* (FUNCEN1) INOV1EN disable (default) */
#define   FUNCEN1_INOV1EN_EN_Val                        _UINT16_(0x1)                                  /* (FUNCEN1) INOV1EN enable */
#define FUNCEN1_DEFAULT_Val                             _UINT16_(0x0)

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
#define SAGTH_Msk                                      (_UINT16_(0xFFFF) << SAGTH_Pos)               /* (SAGTH) SAG Threshold Mask */
#define SAGTH_Val(value)                               (SAGTH_Msk & (_UINT16_(value) << SAGTH_Pos))
#define   SAGTH_DEFAULT_Val                            _UINT16_(0x0000)                              /* (SAGTH) SAG Threshold Default Value */

/* -------- Voltage Phase Losing Threshold : (PhaseLossTh Offset: 0x09H) (R/W - 16 bits) PhaseLoss threshold level. 0xFFFF map to ADC output full-scale peak. -------- */
#define PHASELOSSTH_Pos                                _UINT16_(0)                                   /* (PHASELOSSTH) Phase Loss Threshold Position */
#define PHASELOSSTH_Msk                                (_UINT16_(0xFFFF) << PHASELOSSTH_Pos)         /* (PHASELOSSTH) Phase Loss Threshold Mask */
#define PHASELOSSTH_Val(value)                         (PHASELOSSTH_Msk & (_UINT16_(value) << PHASELOSSTH_Pos))
#define   PHASELOSSTH_DEFAULT_Val                      _UINT16_(0x0000)                              /* (PHASELOSSTH) Phase Loss Threshold Default Value */

/* -------- Neutral Current (Calculated) Warning Threshold : (InWarnTh0 Offset: 0x0AH) (R/W - 16 bits) . Threshold for calculated (Ia + Ib +Ic) N line rms current. Unsigned 16 bit, unit 1mA. -------- */
#define INWARNTH0_Pos                                   _UINT16_(0)                                   /* (INWARNTH0) Neutral Current (Calculated) Warning Threshold Position */
#define INWARNTH0_Msk                                   (_UINT16_(0xFFFF) << INWARNTH0_Pos)           /* (INWARNTH0) Neutral Current (Calculated) Warning Threshold Mask */
#define INWARNTH0_Val(value)                            (INWARNTH0_Msk & (_UINT16_(value) << INWARNTH0_Pos))
#define   INWARNTH0_DEFAULT_Val                         _UINT16_(0xFFFF)                              /* (INWARNTH0) Neutral Current (Calculated) Warning Threshold Default Value */

/* -------- Neutral Current (Sampled) Warning Threshold : (InWarnTh1 Offset: 0x0BH) (R/W - 16 bits) . Threshold for sampled (In) N line rms current. Unsigned 16 bit, unit 1mA. -------- */
#define INWARNTH1_Pos                                   _UINT16_(0)                                   /* (INWARNTH1) Neutral Current (Measured) Warning Threshold Position */
#define INWARNTH1_Msk                                   (_UINT16_(0xFFFF) << INWARNTH1_Pos)           /* (INWARNTH1) Neutral Current (Measured) Warning Threshold Mask */
#define INWARNTH1_Val(value)                            (INWARNTH1_Msk & (_UINT16_(value) << INWARNTH1_Pos))
#define   INWARNTH1_DEFAULT_Val                         _UINT16_(0xFFFF)                              /* (INWARNTH1) Neutral Current (Measured) Warning Threshold Default Value */

/* -------- Voltage THD Warning Threshold : (THDNUTh Offset: 0x0CH) (R/W - 16 bits) . Voltage THD Warning threshold. -------- */
#define THDNUTH_Pos                                     _UINT16_(0)                                   /* (THDNUTH) Voltage THD Warning Threshold Position */
#define THDNUTH_Msk                                     (_UINT16_(0xFFFF) << THDNUTH_Pos)             /* (THDNUTH) Voltage THD Warning Threshold Mask */
#define THDNUTH_Val(value)                              (THDNUTH_Msk & (_UINT16_(value) << THDNUTH_Pos))
#define   THDNUTH_DEFAULT_Val                           _UINT16_(0xFFFF)                              /* (THDNUTH) Voltage THD Warning Threshold Default Value */

/* -------- Current THD Warning Threshold : (THDNUTh Offset: 0x0DH) (R/W - 16 bits) . Current THD Warning threshold. -------- */
#define THDNITH_Pos                                     _UINT16_(0)                                   /* (THDNITH) Current THD Warning Threshold Position */
#define THDNITH_Msk                                     (_UINT16_(0xFFFF) << THDNITH_Pos)             /* (THDNITH) Current THD Warning Threshold Mask */
#define THDNITH_Val(value)                              (THDNITH_Msk & (_UINT16_(value) << THDNITH_Pos))
#define   THDNITH_DEFAULT_Val                           _UINT16_(0xFFFF)                              /* (THDNITH) Current THD Warning Threshold Default Value */

/* -------- DMA Mode Interface Control : (DMACtrl Offset: 0x0EH) (R/W - 16 bits) DMA Controler -------- */
#define DMACTRL_CLK_DIV_Pos                             _UINT16_(0)                                   /* (DMACTRL_CLK_DIV) Divide ratio to generate SCLK frequency from SYS_CLK Position */
#define DMACTRL_CLK_DIV_Msk                             (_UINT16_(0xF) << DMACTRL_CLK_DIV_Pos)        /* (DMACTRL_CLK_DIV) Divide ratio to generate SCLK frequency from SYS_CLK Mask */
#define DMACTRL_CLK_DIV_Val(value)                      (DMACTRL_CLK_DIV_Msk & (_UINT16_(value) << DMACTRL_CLK_DIV_Pos))
#define DMACTRL_CLK_DRV_Pos                             _UINT16_(4)                                   /* (DMACTRL_CLK_DRV) This bit configures which edge to drive data out. Position */
#define DMACTRL_CLK_DRV_Msk                             (_UINT16_(0x1) << DMACTRL_CLK_DRV_Pos)        /* (DMACTRL_CLK_DRV) This bit configures which edge to drive data out. Mask */
#define DMACTRL_CLK_DRV_Val(value)                      (DMACTRL_CLK_DRV_Msk & (_UINT16_(value) << DMACTRL_CLK_DRV_Pos))
#define   DMACTRL_CLK_DRV_SECOND_Val                    _UINT16_(0x0)                                 /* (DMACTRL_CLK_DRV) Second edge drives data out. (default) */
#define   DMACTRL_CLK_DRV_FIRST_Val                     _UINT16_(0x1)                                 /* (DMACTRL_CLK_DRV) First edge drives data out. */
#define DMACTRL_CLK_IDLE_Pos                            _UINT16_(5)                                   /* (DMACTRL_CLK_IDLE) This bit configures the Idle state clock level. Position */
#define DMACTRL_CLK_IDLE_Msk                            (_UINT16_(0x1) << DMACTRL_CLK_IDLE_Pos)       /* (DMACTRL_CLK_IDLE) This bit configures the Idle state clock level. Mask */
#define DMACTRL_CLK_IDLE_Val(value)                     (DMACTRL_CLK_DRV_Msk & (_UINT16_(value) << DMACTRL_CLK_DRV_Pos))
#define   DMACTRL_CLK_IDLE_LOW_Val                      _UINT16_(0x0)                                 /* (DMACTRL_CLK_IDLE) Idle Low. (default) */
#define   DMACTRL_CLK_IDLE_HIGH_Val                     _UINT16_(0x1)                                 /* (DMACTRL_CLK_IDLE) Idle High. */
#define DMACTRL_CH_BIT_WIDTH_Pos                        _UINT16_(6)                                   /* (DMACTRL_CH_BIT_WIDTH) These bits configure the bit width for each channel. Position */
#define DMACTRL_CH_BIT_WIDTH_Msk                        (_UINT16_(0x3) << DMACTRL_CH_BIT_WIDTH_Pos)   /* (DMACTRL_CH_BIT_WIDTH) These bits configure the bit width for each channel. Mask */
#define DMACTRL_CH_BIT_WIDTH_Val(value)                 (DMACTRL_CH_BIT_WIDTH_Msk & (_UINT16_(value) << DMACTRL_CH_BIT_WIDTH_Pos))
#define   DMACTRL_CH_BIT_WIDTH_32_Val                   _UINT16_(0x0)                                 /* (DMACTRL_CH_BIT_WIDTH) 32 Bits. */
#define   DMACTRL_CH_BIT_WIDTH_24_Val                   _UINT16_(0x1)                                 /* (DMACTRL_CH_BIT_WIDTH) 24 Bits.(default) */
#define   DMACTRL_CH_BIT_WIDTH_16_Val                   _UINT16_(0x2)                                 /* (DMACTRL_CH_BIT_WIDTH) 16 Bits. */
#define DMACTRL_PIN_DIR_SEL_Pos                         _UINT16_(8)                                   /* (DMACTRL_CLK_IDLE) This bit configures the direction of the SDI and SDO pins. Position */
#define DMACTRL_PIN_DIR_SEL_Msk                         (_UINT16_(0x1) << DMACTRL_PIN_DIR_SEL_Pos)    /* (DMACTRL_PIN_DIR_SEL) This bit configures the direction of the SDI and SDO pins. Mask */
#define DMACTRL_PIN_DIR_SEL_Val(value)                  (DMACTRL_PIN_DIR_SEL_Msk & (_UINT16_(value) << DMACTRL_PIN_DIR_SEL_Pos))
#define   DMACTRL_PIN_DIR_SEL_ONE_Val                   _UINT16_(0x0)                                 /* (DMACTRL_PIN_DIR_SEL) SDI→MOSI, SDO←MISO. (default) */
#define   DMACTRL_PIN_DIR_SEL_TWO_Val                   _UINT16_(0x1)                                 /* (DMACTRL_PIN_DIR_SEL) SDI←MISO, SDO→MOSI. */
#define DMACTRL_ADC_CH_SEL_Pos                          _UINT16_(9)                                   /* (DMACTRL_ADC_CH_SEL) This bit configures the direction of the SDI and SDO pins. Position */
#define DMACTRL_ADC_CH_SEL_Msk                          (_UINT16_(0x7F) << DMACTRL_ADC_CH_SEL_Pos)    /* (DMACTRL_ADC_CH_SEL) This bit configures the direction of the SDI and SDO pins. Mask */
#define DMACTRL_ADC_CH_SEL_Val(value)                   (DMACTRL_ADC_CH_SEL_Msk & (_UINT16_(value) << DMACTRL_ADC_CH_SEL_Pos))
#define   DMACTRL_ADC_CH_SEL_V3_Val                     _UINT16_(0x1)                                 /* (DMACTRL_ADC_CH_SEL) ADC Channel Selected V3. (default) */
#define   DMACTRL_ADC_CH_SEL_I3_Val                     _UINT16_(0x2)                                 /* (DMACTRL_ADC_CH_SEL) ADC Channel Selected I3. */
#define   DMACTRL_ADC_CH_SEL_V2_Val                     _UINT16_(0x4)                                 /* (DMACTRL_ADC_CH_SEL) ADC Channel Selected V2. (default) */
#define   DMACTRL_ADC_CH_SEL_I2_Val                     _UINT16_(0x8)                                 /* (DMACTRL_ADC_CH_SEL) ADC Channel Selected I2. */
#define   DMACTRL_ADC_CH_SEL_V1_Val                     _UINT16_(0x10)                                /* (DMACTRL_ADC_CH_SEL) ADC Channel Selected V1. (default) */
#define   DMACTRL_ADC_CH_SEL_I1_Val                     _UINT16_(0x20)                                /* (DMACTRL_ADC_CH_SEL) ADC Channel Selected I1. */
#define   DMACTRL_ADC_CH_SEL_IN_Val                     _UINT16_(0x40)                                /* (DMACTRL_ADC_CH_SEL) ADC Channel Selected IN. */
#define   DMACTRL_DEFAULT_Val                           _UINT16_(0x7E44)                              /* (DMACTRL) DMACTRL Default Value */

/* -------- Last Read/Write SPI/UART Value : (LASTDATA Offset: 0x0FH) (R - 16 bits) Last Read/Write SPI/UART Value -------- */
#define LASTDATA_Pos                                    _UINT16_(0)                                   /* (LASTDATA) Last Read/Write SPI/UART Value Position */
#define LASTDATA_Msk                                    (_UINT16_(0xFFFF) << LASTDATA_Pos)            /* (LASTDATA) Last Read/Write SPI/UART Value Mask */
#define LASTDATA_Val(value)                             (LASTDATA_Msk & (_UINT16_(value) << LASTDATA_Pos))
#define LASTDATA_DEFAULT_Val                            _UINT16_(0) 

/* ************************************************************************** */
/*  CONFIGURATION REGISTERS                                                   */
/* ************************************************************************** */

/* -------- Configuration Start Command : (CALSTART Offset: 0x30H) (R/W 16) - Configuration Start Commands -------- */
#define CONFIGSTART_Pos                           _UINT16_(0)                                         /* (CONFIGSTART) Calibration Start Command Value Position */
#define CONFIGSTART_Msk                           (_UINT16_(0xFFFF) << CONFIGSTART_Pos)                  /* (CONFIGSTART) Calibration Start Command Value Mask */
#define CONFIGSTART_Val(value)                    (CONFIGSTART_Msk & (_UINT16_(value) << CONFIGSTART_Pos))
#define   CONFIGSTART_DIS_Val                     _UINT16_(0x6886)                                    /* (CONFIGSTART) Metering Function Disabled */
#define   CONFIGSTART_STARTUP_Val                 _UINT16_(0x5678)                                    /* (CONFIGSTART) Start-up Calibration Configuration */
#define   CONFIGSTART_FINISH_Val                  _UINT16_(0x8765)                                    /* (CONFIGSTART) End and Check Calibration Configuration. If OK, normal metering */
#define   CONFIGSTART_DEFAULT_Val                 CONFIGSTART_DIS_Val                                 /* (CONFIGSTART) Default Value */

/* -------- High Word of PL_Constant : (PLCONSTH Offset: 0x31H) (R/W  - 16 bits) - High Word of PL_Constant -------- */
#define PLCONSTH_Pos                             _UINT16_(0)                                          /* (PLCONSTH) High Word of PL_Constant Value Position */
#define PLCONSTH_Msk                             (_UINT16_(0xFFFF) << PLCONSTH_Pos)                   /* (PLCONSTH) High Word of PL_Constant Value Mask */
#define PLCONSTH_Val(value)                      (PLCONSTH_Msk & (_UINT16_(value) << PLCONSTH_Pos))
#define   PLCONSTH_DEFAULT_Val                   _UINT16_(0x0861)                                     /* (PLCONSTH) Default Value */

/* -------- Low Word of PL_Constant : (PLCONSTL Offset: 0x32H) (R/W  - 16 bits) - Low Word of PL_Constant -------- */
#define PLCONSTL_Pos                             _UINT16_(0)                                          /* (PLCONSTL) Low Word of PL_Constant Value Position */
#define PLCONSTL_Msk                             (_UINT16_(0xFFFF) << PLCONSTL_Pos)                   /* (PLCONSTL) Low Word of PL_Constant Value Mask */
#define PLCONSTL_Val(value)                      (PLCONSTL_Msk & (_UINT16_(value) << PLCONSTL_Pos))
#define   PLCONSTL_DEFAULT_Val                   _UINT16_(0xC468)                                     /* (PLCONSTL) Default Value */

/* -------- Metering Mode 0 Configuration : (MMODE0 Offset: 0x33H) (R/W - 16 bits) - ATM90E36 Metering Mode 0 Configuration -------- */
#define MMODE0_ENPC_Pos                          _UINT16_(0)                                          /* (ENPC) These bits configure whether Phase C are counted into the all-phase sum energy/power (P/Q/S) Position  */
#define MMODE0_ENPC_Msk                          (_UINT16_(0x1) << MMODE0_ENPC_Pos)                   /* (ENPC) These bits configure whether Phase C are counted into the all-phase sum energy/power (P/Q/S) Mask */
#define MMODE0_ENPC_(value)                      (MMODE0_ENPC_Msk & (_UINT16_(value) << MMODE0_ENPC_Pos))
#define   MMODE0_ENPC_EN_Val                     _UINT16_(0x1)                                        /* (ENPC) Corresponding Phase C to be counted into the all-phase sum energy/power (P/Q/S) (default) */
#define   MMODE0_ENPC_DIS_Val                    _UINT16_(0x0)                                        /* (ENPC) Corresponding Phase C not counted into the all-phase sum energy/power (P/Q/S) */
#define MMODE0_ENPB_Pos                          _UINT16_(1)                                          /* (ENPB) These bits configure whether Phase B are counted into the all-phase sum energy/power (P/Q/S) Position  */
#define MMODE0_ENPB_Msk                          (_UINT16_(0x1) << MMODE0_ENPB_Pos)                   /* (ENPB) These bits configure whether Phase B are counted into the all-phase sum energy/power (P/Q/S) Mask */
#define MMODE0_ENPB_(value)                      (MMODE0_ENPB_Msk & (_UINT16_(value) << MMODE0_ENPB_Pos))
#define   MMODE0_ENPB_EN_Val                     _UINT16_(0x1)                                        /* (ENPB) Corresponding Phase B to be counted into the all-phase sum energy/power (P/Q/S) (default) */
#define   MMODE0_ENPB_DIS_Val                    _UINT16_(0x0)                                        /* (ENPB) Corresponding Phase B not counted into the all-phase sum energy/power (P/Q/S) */
#define MMODE0_ENPA_Pos                          _UINT16_(2)                                          /* (ENPA) These bits configure whether Phase A are counted into the all-phase sum energy/power (P/Q/S) Position  */
#define MMODE0_ENPA_Msk                          (_UINT16_(0x1) << MMODE0_ENPA_Pos)                   /* (ENPA) These bits configure whether Phase A are counted into the all-phase sum energy/power (P/Q/S) Mask */
#define MMODE0_ENPA_(value)                      (MMODE0_ENPA_Msk & (_UINT16_(value) << MMODE0_ENPA_Pos))
#define   MMODE0_ENPA_EN_Val                     _UINT16_(0x1)                                        /* (ENPA) Corresponding Phase A to be counted into the all-phase sum energy/power (P/Q/S) (default) */
#define   MMODE0_ENPA_DIS_Val                    _UINT16_(0x0)                                        /* (ENPA) Corresponding Phase a not counted into the all-phase sum energy/power (P/Q/S) */
#define MMODE0_ABSENP_Pos                        _UINT16_(3)                                          /* (ABSENP) These bits configure the calculation method of total (all-phase-sum) active energy and power Position  */
#define MMODE0_ABSENP_Msk                        (_UINT16_(0x1) << MMODE0_ABSENP_Pos)                 /* (ABSENP) These bits configure the calculation method of total (all-phase-sum) active energy and power Mask */
#define MMODE0_ABSENP_(value)                    (MMODE0_ABSENP_Msk & (_UINT16_(value) << MMODE0_ABSENP_Pos))
#define   MMODE0_ABSENP_ABS_Val                  _UINT16_(0x1)                                        /* (ABSENP) Absolute sum */
#define   MMODE0_ABSENP_ARITH_Val                _UINT16_(0x0)                                        /* (ABSENP) Arithmetic sum (default) */
#define MMODE0_ABSENQ_Pos                        _UINT16_(4)                                          /* (ABSENQ) These bits configure the calculation method of total (all-phase-sum) reactive energy and power Position  */
#define MMODE0_ABSENQ_Msk                        (_UINT16_(0x1) << MMODE0_ABSENQ_Pos)                 /* (ABSENQ) These bits configure the calculation method of total (all-phase-sum) reactive energy and power Mask */
#define MMODE0_ABSENQ_(value)                    (MMODE0_ABSENQ_Msk & (_UINT16_(value) << MMODE0_ABSENQ_Pos))
#define   MMODE0_ABSENQ_ABS_Val                  _UINT16_(0x1)                                        /* (ABSENQ) Absolute sum */
#define   MMODE0_ABSENQ_ARITH_Val                _UINT16_(0x0)                                        /* (ABSENQ) Arithmetic sum (default) */
#define MMODE0_CF2ESV_Pos                        _UINT16_(6)                                          /* (CF2ESV) Apparent energy type Position  */
#define MMODE0_CF2ESV_Msk                        (_UINT16_(0x1) << MMODE0_CF2ESV_Pos)                 /* (CF2ESV) Apparent energy type Mask */
#define MMODE0_CF2ESV_(value)                    (MMODE0_CF2ESV_Msk & (_UINT16_(value) << MMODE0_CF2ESV_Pos))
#define   MMODE0_CF2ESV_VECTOR_Val               _UINT16_(0x1)                                        /* (CF2ESV) All-phase apparent energy vector sum Vector sum */
#define   MMODE0_CF2ESV_ARITH_Val                _UINT16_(0x0)                                        /* (CF2ESV) All-phase apparent energy arithmetic sum (default) */
#define MMODE0_CF2VARTH_Pos                      _UINT16_(7)                                          /* (CF2VARTH) CF2 pin source: Position  */
#define MMODE0_CF2VARTH_Msk                      (_UINT16_(0x1) << MMODE0_CF2VARTH_Pos)               /* (CF2VARTH) CF2 pin source: Mask */
#define MMODE0_CF2VARTH_(value)                  (MMODE0_CF2VARTH_Msk & (_UINT16_(value) << MMODE0_CF2VARTH_Pos))
#define   MMODE0_CF2VARTH_REACTIVE_Val           _UINT16_(0x1)                                        /* (CF2VARTH) reactive energy (default) */
#define   MMODE0_CF2VARTH_APPARENT_Val           _UINT16_(0x0)                                        /* (CF2VARTH) apparent energy  */
#define MMODE0_3P3W_Pos                          _UINT16_(8)                                          /* (3P3W) 3P3W Position  */
#define MMODE0_3P3W_Msk                          (_UINT16_(0x1) << MMODE0_3P3W_Pos)                   /* (3P3W) 3P3W Mask */
#define MMODE0_3P3W_(value)                      (MMODE0_3P3W_Msk & (_UINT16_(value) << MMODE0_3P3W_Pos))
#define   MMODE0_3P3W_3P3W_Val                   _UINT16_(0x1)                                        /* (3P3W) 3P3W */
#define   MMODE0_3P3W_3P4W_Val                   _UINT16_(0x0)                                        /* (3P3W) 3P4W (default) */
#define MMODE0_001LSB_Pos                        _UINT16_(9)                                          /* (001LSB) Energy register LSB configuration for all energy registers Position  */
#define MMODE0_001LSB_Msk                        (_UINT16_(0x1) << MMODE0_001LSB_Pos)                   /* (001LSB) Energy register LSB configuration for all energy registers Mask */
#define MMODE0_001LSB_(value)                    (MMODE0_001LSB_Msk & (_UINT16_(value) << MMODE0_001LSB_Pos))
#define   MMODE0_001LSB_EN_Val                   _UINT16_(0x1)                                        /* (001LSB) 0.01 CF */
#define   MMODE0_001LSB_DIS_Val                  _UINT16_(0x0)                                        /* (001LSB) 0.1 CF (default) */
#define MMODE0_DIDTEN_Pos                        _UINT16_(10)                                         /* (DIDTEN) Enable Integrator for didt current sensor. Position  */
#define MMODE0_DIDTEN_Msk                        (_UINT16_(0x1) << MMODE0_DIDTEN_Pos)                 /* (DIDTEN) Enable Integrator for didt current sensor. Mask */
#define MMODE0_DIDTEN_(value)                    (MMODE0_DIDTEN_Msk & (_UINT16_(value) << MMODE0_DIDTEN_Pos))
#define   MMODE0_DIDTEN_ENABLE_Val               _UINT16_(0x1)                                        /* (DIDTEN) Enable (Rogowski CT) */
#define   MMODE0_DIDTEN_DISABLE_Val              _UINT16_(0x0)                                        /* (DIDTEN) Disable */
#define MMODE0_FREQ60HZ_Pos                      _UINT16_(12)                                         /* (FREQ60HZ) Current Grid operating line frequency. Position  */
#define MMODE0_FREQ60HZ_Msk                      (_UINT16_(0x1) << MMODE0_FREQ60HZ_Pos)               /* (FREQ60HZ) Current Grid operating line frequency. Mask */
#define MMODE0_FREQ60HZ_(value)                  (MMODE0_FREQ60HZ_Msk & (_UINT16_(value) << MMODE0_FREQ60HZ_Pos))
#define   MMODE0_FREQ60HZ_60HZ_Val               _UINT16_(0x1)                                        /* (FREQ60HZ) 60Hz  */
#define   MMODE0_FREQ60HZ_50HZ_Val               _UINT16_(0x0)                                        /* (FREQ60HZ) 50Hz */
#define MMODE0_I1I3SWAP_Pos                      _UINT16_(13)                                         /* (I1I3SWAP) This bit defines phase mapping for I1 and I3. Position  */
#define MMODE0_I1I3SWAP_Msk                      (_UINT16_(0x1) << MMODE0_I1I3SWAP_Pos)               /* (I1I3SWAP) This bit defines phase mapping for I1 and I3. Mask */
#define MMODE0_I1I3SWAP_(value)                  (MMODE0_I1I3SWAP_Msk & (_UINT16_(value) << MMODE0_I1I3SWAP_Pos))
#define   MMODE0_I1I3SWAP_EN_Val                 _UINT16_(0x1)                                        /* (I1I3SWAP) swap enabled  */
#define   MMODE0_I1I3SWAP_DIS_Val                _UINT16_(0x0)                                        /* (I1I3SWAP) Swap disabled (default) */
#define MMODE0_DEFAULT_Val                       _UINT16_(0x0087)                                        /* Default Value */

/* -------- Metering Mode 1 Configuration : (MMODE0 Offset: 0x34H) (R/W - 16 bits) - ATM90E36 Metering Mode 1 Configuration -------- */
#define MMODE1_PGA_GAIN_I1_Pos                   _UINT16_(0)                                          /* (MMODE1) Line 1 current gain Position */
#define MMODE1_PGA_GAIN_I1_Msk                   (_UINT16_(0x3) << MMODE1_PGA_GAIN_I1_Pos)            /* (MMODE1) Line 1 current gain Mask */
#define MMODE1_PGA_GAIN_I1(value)                (MMODE1_PGA_GAIN_I1_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_I1_Pos))
#define MMODE1_PGA_GAIN_I2_Pos                   _UINT16_(2)                                          /* (MMODE1) Line 2 current gain Position */
#define MMODE1_PGA_GAIN_I2_Msk                   (_UINT16_(0x3) << MMODE1_PGA_GAIN_I2_Pos)            /* (MMODE1) Line 2 current gain Mask */
#define MMODE1_PGA_GAIN_I2(value)                (MMODE1_PGA_GAIN_I2_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_I2_Pos))
#define MMODE1_PGA_GAIN_I3_Pos                   _UINT16_(4)                                          /* (MMODE1) Line 3 current gain Position */
#define MMODE1_PGA_GAIN_I3_Msk                   (_UINT16_(0x3) << MMODE1_PGA_GAIN_I3_Pos)            /* (MMODE1) Line 3 current gain Mask */
#define MMODE1_PGA_GAIN_I3(value)                (MMODE1_PGA_GAIN_I3_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_I3_Pos))
#define MMODE1_PGA_GAIN_I4_Pos                   _UINT16_(6)                                          /* (MMODE1) Line 4 current gain Position */
#define MMODE1_PGA_GAIN_I4_Msk                   (_UINT16_(0x3) << MMODE1_PGA_GAIN_I4_Pos)            /* (MMODE1) Line 4 current gain Mask */
#define MMODE1_PGA_GAIN_I4(value)                (MMODE1_PGA_GAIN_I4_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_I4_Pos))
#define MMODE1_PGA_GAIN_V1_Pos                   _UINT16_(8)                                          /* (MMODE1) Line 1 voltage gain Position */
#define MMODE1_PGA_GAIN_V1_Msk                   (_UINT16_(0x3) << MMODE1_PGA_GAIN_V1_Pos)            /* (MMODE1) Line 1 voltage gain Mask */
#define MMODE1_PGA_GAIN_V1(value)                (MMODE1_PGA_GAIN_V1_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_V1_Pos))
#define MMODE1_PGA_GAIN_V2_Pos                   _UINT16_(10)                                         /* (MMODE1) Line 2 voltage gain Position */
#define MMODE1_PGA_GAIN_V2_Msk                   (_UINT16_(0x3) << MMODE1_PGA_GAIN_V2_Pos)            /* (MMODE1) Line 2 voltage gain Mask */
#define MMODE1_PGA_GAIN_V2(value)                (MMODE1_PGA_GAIN_V2_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_V2_Pos))
#define MMODE1_PGA_GAIN_V3_Pos                   _UINT16_(12)                                         /* (MMODE1) Line 3 voltage gain Position */
#define MMODE1_PGA_GAIN_V3_Msk                   (_UINT16_(0x3) << MMODE1_PGA_GAIN_V3_Pos)            /* (MMODE1) Line 3 voltage gain Mask */
#define MMODE1_PGA_GAIN_V3(value)                (MMODE1_PGA_GAIN_V3_Msk & (_UINT16_(value) << MMODE1_PGA_GAIN_V3_Pos))
#define   MMODE1_PGA_GAIN_1_Val                  _UINT16_(0x0)                                        /* (MMODE1) PGA Gain 1 (default) */
#define   MMODE1_PGA_GAIN_2_Val                  _UINT16_(0x1)                                        /* (MMODE1) PGA Gain 2 */
#define   MMODE1_PGA_GAIN_4_Val                  _UINT16_(0x2)                                        /* (MMODE1) PGA Gain 4 */
#define MMODE1_DPGA_GAIN_Pos                     _UINT16_(14)                                         /* (MMODE1) Digital PGA Gain for the 4 current channels Position */
#define MMODE1_DPGA_GAIN_Msk                     (_UINT16_(0x3) << MMODE1_DPGA_GAIN_Pos)              /* (MMODE1) Digital PGA Gain for the 4 current channels Mask */
#define MMODE1_DPGA_GAIN_(value)                 (MMODE_LGAIN_Msk & (_UINT16_(value) << MMODE_LGAIN_Pos))
#define   MMODE1_DPGA_GAIN_1_Val                 _UINT16_(0x0)                                        /* (MMODE1) Digital PGA Gain for the 4 current channels 1 (default) */
#define   MMODE1_DPGA_GAIN_2_Val                 _UINT16_(0x1)                                        /* (MMODE1) Digital PGA Gain for the 4 current channels 2  */
#define   MMODE1_DPGA_GAIN_4_Val                 _UINT16_(0x2)                                        /* (MMODE1) Digital PGA Gain for the 4 current channels 4 */
#define   MMODE1_DPGA_GAIN_8_Val                 _UINT16_(0x3)                                        /* (MMODE1) Digital PGA Gain for the 4 current channels 8 */
#define MMODE1_DEFAULT_Val                       _UINT16_(0x0)

/* -------- Active Startup Power Threshold : (PSTARTTH Offset: 0x35H) (R/W  - 16 bits) - Active Startup Power Threshold -------- */
#define PSTARTTH_Pos                             _UINT16_(0)                                          /* (PSTARTTH) Active Startup Power Threshold Value Position */
#define PSTARTTH_Msk                             (_UINT16_(0xFFFF) << PSTARTTH_Pos)                   /* (PSTARTTH) Active Startup Power Threshold Value Mask */
#define PSTARTTH_Val(value)                      (PSTARTTH_Msk & (_UINT16_(value) << PSTARTTH_Pos))
#define   PSTARTTH_DEFAULT_Val                   _UINT16_(0x0000)                                     /* (PSTARTTH) Active Startup Power Threshold Default Value */

/* -------- Rective Startup Power Threshold : (QSTARTTH Offset: 0x36H) (R/W  - 16 bits) - Reactive Startup Power Threshold -------- */
#define QSTARTTH_Pos                             _UINT16_(0)                                          /* (QSTARTTH) Reactive Startup Power Threshold Value Position */
#define QSTARTTH_Msk                             (_UINT16_(0xFFFF) << QSTARTTH_Pos)                   /* (QSTARTTH) Reactive Startup Power Threshold Value Mask */
#define QSTARTTH_Val(value)                      (QSTARTTH_Msk & (_UINT16_(value) << QSTARTTH_Pos))
#define   QSTARTTH_DEFAULT_Val                   _UINT16_(0x0000)                                     /* (QSTARTTH) Rective Startup Power Threshold Default Value */

/* -------- Apparent Startup Power Threshold : (SSTARTTH Offset: 0x37H) (R/W  - 16 bits) - Apparent Startup Power Threshold -------- */
#define SSTARTTH_Pos                             _UINT16_(0)                                          /* (SSTARTTH) Apparent Startup Power Threshold Value Position */
#define SSTARTTH_Msk                             (_UINT16_(0xFFFF) << SSTARTTH_Pos)                   /* (SSTARTTH) Apparent Startup Power Threshold Value Mask */
#define SSTARTTH_Val(value)                      (SSTARTTH_Msk & (_UINT16_(value) << SSTARTTH_Pos))
#define   SSTARTTH_DEFAULT_Val                   _UINT16_(0x0000)                                     /* (SSTARTTH) Apparent Startup Power Threshold Default Value */

/* -------- Active No-Load Power Threshold : (PSTARTTH Offset: 0x38H) (R/W  - 16 bits) - Active No-Load Power Threshold -------- */
#define PPHASETH_Pos                             _UINT16_(0)                                          /* (PPHASETH) Active No-Load Power Threshold Value Position */
#define PPHASETH_Msk                             (_UINT16_(0xFFFF) << PPHASETH_Pos)                   /* (PPHASETH) Active No-Load Power Threshold Value Mask */
#define PPHASETH_Val(value)                      PPHASETH_Msk & (_UINT16_(value) << PPHASETH_Pos))
#define   PPHASETH_DEFAULT_Val                   _UINT16_(0x0)                                        /* (PPHASETH) Active No-Load Power Threshold Default Value */

/* -------- Reactive No-Load Power Threshold : (QSTARTTH Offset: 0x39H) (R/W  - 16 bits) - Reactive No-Load Power Threshold -------- */
#define QPHASETH_Pos                             _UINT16_(0)                                          /* (QPHASETH) Active No-Load Power Threshold Value Position */
#define QPHASETH_Msk                             (_UINT16_(0xFFFF) << QPHASETH_Pos)                   /* (QPHASETH) Active No-Load Power Threshold Value Mask */
#define QPHASETH_Val(value)                      QPHASETH_Msk & (_UINT16_(value) << QPHASETH_Pos))
#define   QPHASETH_DEFAULT_Val                   _UINT16_(0x0)                                        /* (PPHASETH) Active No-Load Power Threshold Default Value */

/* -------- Reactive No-Load Power Threshold : (QSTARTTH Offset: 0x3AH) (R/W  - 16 bits) - Apparent No-Load Power Threshold -------- */
#define SPHASETH_Pos                             _UINT16_(0)                                          /* (SPHASETH) Apparent No-Load Power Threshold Value Position */
#define SPHASETH_Msk                             (_UINT16_(0xFFFF) << SPHASETH_Pos)                   /* (SPHASETH) Apparent No-Load Power Threshold Value Mask */
#define SPHASETH_Val(value)                      (SPHASETH_Msk & (_UINT16_(value) << SPHASETH_Pos))
#define   SPHASETH_DEFAULT_Val                   _UINT16_(0x0)                                        /* (SPHASETH) Apparent No-Load Power Threshold Default Value */

/* -------- Metering Configuration Checksum: (CS0 Offset: 0x3BH) (R/W - 16 bits) - ATM90E36 Metering Configuration Checksum -------- */
/* -------- Note: The readout value of the CS0 register is the calculation by the M90E36, which is different from what is written.   */
#define CS0_Pos                                  _UINT16_(0)                                          /* (CS0) Metering Configuration Checksum Position */
#define CS0_Msk                                  (_UINT16_(0xFFFF) << CS0_Pos)                        /* (CS0) Metering Configuration Checksum Mask */
#define CS0_(value)                              (MMODE_CS0_Msk & (_UINT16_(value) << CS0_Pos))

/* ************************************************************************** */
/*  ENERGY CALIBRATION REGISTERS                                              */
/* ************************************************************************** */

/* -------- Metering Calibration Start Command : (CALSTART Offset: 0x40H) (R/W 16) - Calibration Start Commands -------- */
#define CALSTART_Pos                            _UINT16_(0)                                           /* (CALSTART) Calibration Start Command Value Position */
#define CALSTART_Msk                            (_UINT16_(0xFFFF) << CALSTART_Pos)                    /* (CALSTART) Calibration Start Command Value Mask */
#define CALSTART_Val(value)                     (CALSTART_Msk & (_UINT16_(value) << CALSTART_Pos))
#define   CALSTART_DIS_Val                      _UINT16_(0x6886)                                      /* (CALSTART) Metering Function Disabled */
#define   CALSTART_STARTUP_Val                  _UINT16_(0x5678)                                      /* (CALSTART) Start-up Calibration Configuration */
#define   CALSTART_FINISH_Val                   _UINT16_(0x8765)                                      /* (CALSTART) End and Check Calibration Configuration. If OK, normal metering */
#define   CALSTART_DEFAULT_Val                  CALSTART_DIS_Val                                      /* (CALSTART) Default Value */

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
#define PHIA_DELAYCYCLES_Msk                            (_UINT16_(0x3FF) << PHIA_DELAYCYCLES_Pos)     /* (PHIA) Number of delay cycles calculated in phase compensation. Mask */
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
#define PHIB_DELAYCYCLES_Msk                            (_UINT16_(0x3FF) << PHIB_DELAYCYCLES_Pos)     /* (PHIB) Number of delay cycles calculated in phase compensation. Mask */
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
#define PHIC_DELAYCYCLES_Msk                            (_UINT16_(0x3FF) << PHIC_DELAYCYCLES_Pos)     /* (PHIC) Number of delay cycles calculated in phase compensation. Mask */
#define PHIC_DELAYCYCLES_Val(value)                     (PHIC_DELAYCYCLES_Msk & (_UINT16_(value) << PHIC_DELAYCYCLES_Pos))
#define   PHIC_DELAYCYCLES_DEFAULT_Val                  _UINT16_(0)                                   /* (PHIC) Default Value. uint8_t */
#define PHIC_DELAYV_Pos                                 _UINT16_(15)                                  /* (PHIC) Phase C Active/Reactive Energy Calibration Phase Angle Value Position */
#define PHIC_DELAYV_Msk                                 (_UINT16_(0x1) << PHIC_DELAYV_Pos)            /* (PHIC) Phase C Active/Reactive Energy Calibration Phase Angle Value Mask */
#define PHIC_DELAYV_Val(value)                          (PHIC_DELAYV_Msk & (_UINT16_(value) << PHIC_DELAYV_Pos))
#define   PHIC_DELAYV_VOLTAGE_Val                       _UINT16_(1)                                   /* (PHIC) Delay Cycles are applied to voltage channel */
#define   PHIC_DELAYV_CURRENT_Val                       _UINT16_(0)                                   /* (PHIC) Delay Cycles are applied to current channel */
#define   PHIC_DELAYV_DEFAULT_Val                       _UINT16_(0)                                   /* (PHIC) Default Value */
#define   PHIC_DEFAULT_Val                              _UINT16_(0x0)                                 /* (PHIC) Default Register Value */

/* -------- Metering Configuration Checksum: (CS1 Offset: 0x2CH) (R/W - 16 bits) - ATM90E36 Metering Configuration Checksum -------- */
/* -------- Note: The readout value of the CS1 register is the calculation by the M90E36, which is different from what is written.   */
#define CS1_Pos                                         _UINT16_(0)                                   /* (CS1) Metering Configuration Checksum Position */
#define CS1_Msk                                         (_UINT16_(0xFFFF) << CS1_Pos)                 /* (CS1) Metering Configuration Checksum Mask */
#define CS1_(value)                                     (CS1_Msk & (_UINT16_(value) << CS1_Pos))

/* ************************************************************************** */
/*   FUNDAMENTAL/HARMONIC ENERGY CALIBRATION REGISTER                         */
/* ************************************************************************** */
/* -------- Harmonic Calibration Startup Command : (HARMSTART Offset: 0x50H) (R/W 16) - Harmonic Calibration Startup Commands -------- */
#define HARMSTART_Pos                                   _UINT16_(0)                                   /* (HARMSTART) Harmonic Calibration Startup Command Value Position */
#define HARMSTART_Msk                                   (_UINT16_(0xFFFF) << HARMSTART_Pos)           /* (HARMSTART) Harmonic Calibration Startup Command Value Mask */
#define HARMSTART_Val(value)                            (HARMSTART_Msk & (_UINT16_(value) << HARMSTART_Pos))
#define   HARMSTART_DIS_Val                             _UINT16_(0x6886)                              /* (HARMSTART) Harmonic Calibration Startup Function Disabled */
#define   HARMSTART_STARTUP_Val                         _UINT16_(0x5678)                              /* (HARMSTART) Harmonic Calibration Startup Configuration */
#define   HARMSTART_FINISH_Val                          HARMSTART_DIS_Val                             /* (HARMSTART) Default Value */

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

/* -------- Metering Configuration Checksum: (CS2 Offset: 0x57H) (R/W - 16 bits) - ATM90E36 Metering Configuration Checksum -------- */
/* -------- Note: The readout value of the CS2 register is the calculation by the M90E36, which is different from what is written.   */
#define CS2_Pos                                         _UINT16_(0)                                   /* (CS2) Harmonic Calibration Configuration Checksum Position */
#define CS2_Msk                                         (_UINT16_(0xFFFF) << CS2_Pos)                 /* (CS2) Harmonic Calibration Configuration Checksum Mask */
#define CS2_(value)                                     (CS2_Msk & (_UINT16_(value) << CS2_Pos))

/* ************************************************************************** */
/*   MEASUREMENT CALIBRATION REGISTER                                         */
/* ************************************************************************** */
/* -------- Measurements Calibration Start Command : (ADJSTART Offset: 0x60H) (R/W 16) - Measurements Calibration Start Commands -------- */
#define ADJSTART_Pos                                    _UINT16_(0)                                   /* (ADJSTART) Calibration Start Command Value Position */
#define ADJSTART_Msk                                    (_UINT16_(0xFFFF) << ADJSTART_Pos)            /* (ADJSTART) Calibration Start Command Value Mask */
#define ADJSTART_Val(value)                             (ADJSTART_Msk & (_UINT16_(value) << ADJSTART_Pos))
#define   ADJSTART_DIS_Val                              _UINT16_(0x6886)                              /* (ADJSTART) Measurement Function Disabled */
#define   ADJSTART_STARTUP_Val                          _UINT16_(0x5678)                              /* (ADJSTART) Start-up Calibration Configuration */
#define   ADJSTART_FINISH_Val                           _UINT16_(0x8765)                              /* (ADJSTART) End and Check Calibration Configuration. If OK, normal metering */
#define   ADJSTART_DEFAULT_Val                          ADJSTART_DIS_Val                              /* (ADJSTART) Default Value */

/* -------- Measurements Phase A Voltage rms Gain : (UGAINA Offset: 0x61H) (R/W - 16 bits) - ATM90E36 Measurements Phase A Voltage rms Gain -------- */
#define UGAINA_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase A Voltage rms Gain Value Position */
#define UGAINA_GAIN_Msk                                 (_UINT16_(0xFFFF) << UGAINA_GAIN_Pos)         /* (GAIN) Phase A Voltage rms Gain Value Mask */
#define UGAINA_GAIN_Val(value)                          (UGAINA_GAIN_Msk & (_UINT16_(value) << UGAINA_GAIN_Pos))
#define   UGAINA_GAIN_DEFAULT_Val                       _UINT16_(0xCE40)                              /* (GAIN) Phase A Voltage rms Gain Default Value */

/* -------- Measurements Phase A Current rms Gain : (IGAINA Offset: 0x62H) (R/W - 16 bits) - ATM90E36 Measurements Phase A Current rms Gain -------- */
#define IGAINA_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase A Current rms Gain Value Position */
#define IGAINA_GAIN_Msk                                 (_UINT16_(0xFFFF) << IGAINA_GAIN_Pos)         /* (GAIN) Phase A Current rms Gain Value Mask */
#define IGAINA_GAIN_Val(value)                          (IGAINA_GAIN_Msk & (_UINT16_(value) << IGAINA_GAIN_Pos))
#define   IGAINA_GAIN_DEFAULT_Val                       _UINT16_(0x7530)                              /* (GAIN) Phase A Current rms Gain Default Value */

/* -------- Measurements Phase A Voltage Offset : (UOFFSETA Offset: 0x63H) (R/W - 16 bits) - ATM90E36 Measurements Phase A Voltage Offset -------- */
/* -------- Note: The voltage offset calibration should be performed at reference current and no offset. It is not applicable for self-powered meter.   */
#define UOFFSETA_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase A Voltage Offset Value Position */
#define UOFFSETA_OFFSET_Msk                             (_UINT16_(0xFFFF) << UOFFSETA_OFFSET_Pos)     /* (OFFSET) Phase A Voltage Offset Value Mask */
#define UOFFSETA_OFFSET_Val(value)                      (UOFFSETA_OFFSET_Msk & (_UINT16_(value) << UOFFSETA_OFFSET_Pos))
#define   UOFFSETA_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase A Voltage Offset Default Value */

/* -------- Measurements Phase A Current Offset : (IOFFSETA Offset: 0x64H) (R/W - 16 bits) - ATM90E36 Measurements Phase A Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETA_OFFSET_Pos                           _UINT16_(0)                                    /* (OFFSET) Phase A Current Offset Value Position */
#define IOFFSETA_OFFSET_Msk                           (_UINT16_(0xFFFF) << IOFFSETA_OFFSET_Pos)      /* (OFFSET) Phase A Current Offset Value Mask */
#define IOFFSETA_OFFSET_Val(value)                    (IOFFSETA_OFFSET_Msk & (_UINT16_(value) << IOFFSETA_OFFSET_Pos))
#define   IOFFSETA_OFFSET_DEFAULT_Val                 _UINT16_(0)                                    /* (OFFSET) Phase A Current Offset Default Value */

/* -------- Measurements Phase B Voltage rms Gain : (UGAINB Offset: 0x65H) (R/W - 16 bits) - ATM90E36 Measurements Phase B Voltage rms Gain -------- */
#define UGAINB_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase B Voltage rms Gain Value Position */
#define UGAINB_GAIN_Msk                                 (_UINT16_(0xFFFF) << UGAINB_GAIN_Pos)         /* (GAIN) Phase B Voltage rms Gain Value Mask */
#define UGAINB_GAIN_Val(value)                          (UGAINB_GAIN_Msk & (_UINT16_(value) << UGAINB_GAIN_Pos))
#define   UGAINB_GAIN_DEFAULT_Val                       _UINT16_(0xCE40)                              /* (GAIN) Phase B Voltage rms Gain Default Value */

/* -------- Measurements Phase B Current rms Gain : (IGAINB Offset: 0x66H) (R/W - 16 bits) - ATM90E36 Measurements Phase B Current rms Gain -------- */
#define IGAINB_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase B Current rms Gain Value Position */
#define IGAINB_GAIN_Msk                                 (_UINT16_(0xFFFF) << IGAINB_GAIN_Pos)         /* (GAIN) Phase B Current rms Gain Value Mask */
#define IGAINB_GAIN_Val(value)                          (IGAINB_GAIN_Msk & (_UINT16_(value) << IGAINB_GAIN_Pos))
#define   IGAINB_GAIN_DEFAULT_Val                       _UINT16_(0x7530)                              /* (GAIN) Phase B Current rms Gain Default Value */

/* -------- Measurements Phase B Voltage Offset : (UOFFSETB Offset: 0x67H) (R/W - 16 bits) - ATM90E36 Measurements Phase B Voltage Offset -------- */
/* -------- Note: The voltage offset calibration should be performed at reference current and no offset. It is not applicable for self-powered meter.   */
#define UOFFSETB_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase B Voltage Offset Value Position */
#define UOFFSETB_OFFSET_Msk                             (_UINT16_(0xFFFF) << UOFFSETB_OFFSET_Pos)     /* (OFFSET) Phase B Voltage Offset Value Mask */
#define UOFFSETB_OFFSET_Val(value)                      (UOFFSETB_OFFSET_Msk & (_UINT16_(value) << UOFFSETB_OFFSET_Pos))
#define   UOFFSETB_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase B Voltage Offset Default Value */

/* -------- Measurements Phase B Current Offset : (IOFFSETB Offset: 0x64H) (R/W - 16 bits) - ATM90E36 Measurements Phase B Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETB_OFFSET_Pos                           _UINT16_(0)                                    /* (OFFSET) Phase B Current Offset Value Position */
#define IOFFSETB_OFFSET_Msk                           (_UINT16_(0xFFFF) << IOFFSETB_OFFSET_Pos)      /* (OFFSET) Phase B Current Offset Value Mask */
#define IOFFSETB_OFFSET_Val(value)                    (IOFFSETB_OFFSET_Msk & (_UINT16_(value) << IOFFSETB_OFFSET_Pos))
#define   IOFFSETB_OFFSET_DEFAULT_Val                 _UINT16_(0)                                    /* (OFFSET) Phase A Current Offset Default Value */

/* -------- Measurements Phase C Voltage rms Gain : (UGAIN Offset: 0x69H) (R/W - 16 bits) - ATM90E36 Measurements Phase C Voltage rms Gain -------- */
#define UGAINC_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase C Voltage rms Gain Value Position */
#define UGAINC_GAIN_Msk                                 (_UINT16_(0xFFFF) << UGAINC_GAIN_Pos)         /* (GAIN) Phase C Voltage rms Gain Value Mask */
#define UGAINC_GAIN_Val(value)                          (UGAINC_GAIN_Msk & (_UINT16_(value) << UGAINC_GAIN_Pos))
#define   UGAINC_GAIN_DEFAULT_Val                       _UINT16_(0xCE40)                              /* (GAIN) Phase C Voltage rms Gain Default Value */

/* -------- Measurements Phase C Current rms Gain : (IGAINC Offset: 0x6AH) (R/W - 16 bits) - ATM90E36 Measurements Phase C Current rms Gain -------- */
#define IGAINC_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase C Current rms Gain Value Position */
#define IGAINC_GAIN_Msk                                 (_UINT16_(0xFFFF) << IGAINC_GAIN_Pos)         /* (GAIN) Phase C Current rms Gain Value Mask */
#define IGAINC_GAIN_Val(value)                          (IGAINC_GAIN_Msk & (_UINT16_(value) << IGAINC_GAIN_Pos))
#define   IGAINC_GAIN_DEFAULT_Val                       _UINT16_(0x7530)                              /* (GAIN) Phase C Current rms Gain Default Value */

/* -------- Measurements Phase C Voltage Offset : (UOFFSETA Offset: 0x6BH) (R/W - 16 bits) - ATM90E36 Measurements Phase C Voltage Offset -------- */
/* -------- Note: The voltage offset calibration should be performed at reference current and no offset. It is not applicable for self-powered meter.   */
#define UOFFSETC_OFFSET_Pos                             _UINT16_(0)                                   /* (OFFSET) Phase C Voltage Offset Value Position */
#define UOFFSETC_OFFSET_Msk                             (_UINT16_(0xFFFF) << UOFFSETC_OFFSET_Pos)     /* (OFFSET) Phase C Voltage Offset Value Mask */
#define UOFFSETC_OFFSET_Val(value)                      (UOFFSETC_OFFSET_Msk & (_UINT16_(value) << UOFFSETC_OFFSET_Pos))
#define   UOFFSETC_OFFSET_DEFAULT_Val                   _UINT16_(0)                                   /* (OFFSET) Phase C Voltage Offset Default Value */

/* -------- Measurements Phase C Current Offset : (IOFFSETC Offset: 0x6CH) (R/W - 16 bits) - ATM90E36 Measurements Phase C Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETC_OFFSET_Pos                             _UINT16_(0)                                    /* (OFFSET) Phase C Current Offset Value Position */
#define IOFFSETC_OFFSET_Msk                             (_UINT16_(0xFFFF) << IOFFSETC_OFFSET_Pos)      /* (OFFSET) Phase C Current Offset Value Mask */
#define IOFFSETC_OFFSET_Val(value)                      (IOFFSETC_OFFSET_Msk & (_UINT16_(value) << IOFFSETC_OFFSET_Pos))
#define   IOFFSETC_OFFSET_DEFAULT_Val                   _UINT16_(0)                                    /* (OFFSET) Phase C Current Offset Default Value */

/* -------- Measurements Phase C Current rms Gain : (IGAINC Offset: 0x6AH) (R/W - 16 bits) - ATM90E36 Measurements Phase C Current rms Gain -------- */
#define IGAINN_GAIN_Pos                                 _UINT16_(0)                                   /* (GAIN) Phase N Current rms Gain Value Position */
#define IGAINN_GAIN_Msk                                 (_UINT16_(0xFFFF) << IGAINN_GAIN_Pos)         /* (GAIN) Phase N Current rms Gain Value Mask */
#define IGAINN_GAIN_Val(value)                          (IGAINN_GAIN_Msk & (_UINT16_(value) << IGAINN_GAIN_Pos))
#define   IGAINN_GAIN_DEFAULT_Val                       _UINT16_(0x7530)                              /* (GAIN) Phase N Current rms Gain Default Value */

/* -------- Measurements Phase C Current Offset : (IOFFSETC Offset: 0x6CH) (R/W - 16 bits) - ATM90E36 Measurements Phase N Current Offset -------- */
/* -------- Note: The current offset calibration should be performed at reference voltage and no offset. */
#define IOFFSETN_OFFSET_Pos                             _UINT16_(0)                                    /* (OFFSET) Phase N Current Offset Value Position */
#define IOFFSETN_OFFSET_Msk                             (_UINT16_(0xFFFF) << IOFFSETN_OFFSET_Pos)      /* (OFFSET) Phase N Current Offset Value Mask */
#define IOFFSETN_OFFSET_Val(value)                      (IOFFSETN_OFFSET_Msk & (_UINT16_(value) << IOFFSETN_OFFSET_Pos))
#define   IOFFSETN_OFFSET_DEFAULT_Val                   _UINT16_(0)                                    /* (OFFSET) Phase N Current Offset Default Value */

/* -------- Metering Configuration Checksum: (CS3 Offset: 0x6FH) (R/W - 16 bits) - ATM90E36 Metering Configuration Checksum -------- */
/* -------- Note: The readout value of the CS3 register is the calculation by the M90E26, which is different from what is written.   */
#define CS3_Pos                                        _UINT16_(0)                                     /* (CS3) Measurement Configuration Checksum Position */
#define CS3_Msk                                        (_UINT16_(0xFFFF) << CS3_Pos)                   /* (CS3) Measurement Configuration Checksum Mask */
#define CS3_(value)                                    (CS3_Msk & (_UINT16_(value) << CS3_Pos))

/* ************************************************************************** */
/*   ENERGY REGISTER - PULSES                                                 */
/* ************************************************************************** */
/* -------- Total Metering Forward Active Energy pulses : (APENERGYT Offset: 0x80H) (R/C - 16 bits) - ATM90E36 Metering Total Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYT_Pos                           _UINT16_(0)                                   /* (APENERGYT) Total Forward Active Energy Value Position */
#define APENERGYT_Msk                           (_UINT16_(0xFFFF) << APENERGYT_Pos) /* (APENERGYT) Total Forward Active Energy Value Mask */
#define APENERGYT_Val(value)                    APENERGYT_Msk & (_UINT16_(value) << APENERGYT_Pos))

/* -------- Phase A Metering Forward Active Energy pulses : (APENERGYA Offset: 0x81H) (R/C - 16 bits) - ATM90E36 Metering Phase A Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYA_Pos                           _UINT16_(0)                                   /* (APENERGYA) Phase A Forward Active Energy Value Position */
#define APENERGYA_Msk                           (_UINT16_(0xFFFF) << APENERGYA_Pos) /* (APENERGYA) Phase A Forward Active Energy Value Mask */
#define APENERGYA_Val(value)                    (APENERGYA_Msk & (_UINT16_(value) << APENERGYA_Pos)) /* -------- Phase A Metering Forward Active Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Active Energy pulses : (APENERGYB Offset: 0x82H) (R/C - 16 bits) - ATM90E36 Metering Phase B Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYB_Pos                           _UINT16_(0)                                   /* (APENERGYB) Phase B  Forward Active Energy Value Position */
#define APENERGYB_Msk                           (_UINT16_(0xFFFF) << APENERGYB_Pos) /* (APENERGYB) Phase B  Forward Active Energy Value Mask */
#define APENERGYB_Val(value)                    (APENERGYB_Msk & (_UINT16_(value) << APENERGYB_Pos)) /* -------- Phase B  Metering Forward Active Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Active Energy pulses : (APENERGYC Offset: 0x83H) (R/C - 16 bits) - ATM90E36 Metering Phase C Forward Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYC_Pos                           _UINT16_(0)                                   /* (APENERGYC) Phase C Forward Active Energy Value Position */
#define APENERGYC_Msk                           (_UINT16_(0xFFFF) << APENERGYC_Pos) /* (APENERGYC) Phase C Forward Active Energy Value Mask */
#define APENERGYC_Val(value)                    (APENERGYC_Msk & (_UINT16_(value) << APENERGYC_Pos))

/* -------- Metering Total Reverse Active Energy pulses : (ANENERGYT Offset: 0x84H) (R/C - 16 bits) - ATM90E36 Metering Total Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYT_Pos                           _UINT16_(0)                                   /* (ANENERGYT) Total Reverse Active Energy Value Position */
#define ANENERGYT_Msk                           (_UINT16_(0xFFFF) << ANENERGYT_Pos) /* (ANENERGYT) Total Reverse Active Energy Value Mask */
#define ANENERGYT_Val(value)                    (ANENERGYT_Msk & (_UINT16_(value) << ANENERGYT_Pos))

/* -------- Metering Phase A Reverse Active Energy pulses : (ANENERGYA Offset: 0x85H) (R/C - 16 bits) - ATM90E36 Metering Phase A Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYA_Pos                           _UINT16_(0)                                   /* (ANENERGYA) Phase A Reverse Active Energy Value Position */
#define ANENERGYA_Msk                           (_UINT16_(0xFFFF) << ANENERGYA_Pos) /* (ANENERGYA) Phase A Reverse Active Energy Value Mask */
#define ANENERGYA_Val(value)                    (ANENERGYA_Msk & (_UINT16_(value) << ANENERGYA_Pos))

/* -------- Metering Phase B Reverse Active Energy pulses : (ANENERGYB Offset: 0x86H) (R/C - 16 bits) - ATM90E36 Metering Phase B Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYB_Pos                           _UINT16_(0)                                   /* (ANENERGYB) Phase B Reverse Active Energy Value Position */
#define ANENERGYB_Msk                           (_UINT16_(0xFFFF) << ANENERGYB_Pos) /* (ANENERGYB) Phase B Reverse Active Energy Value Mask */
#define ANENERGYB_Val(value)                    (ANENERGYB_ANENERGYB_Msk & (_UINT16_(value) << ANENERGYB_ANENERGYB_Pos))

/* -------- Metering Phase C Reverse Active Energy pulses : (ANENERGYC Offset: 0x87H) (R/C - 16 bits) - ATM90E36 Metering Phase C Reverse Active Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYC_Pos                           _UINT16_(0)                                   /* (ANENERGYA) Phase C Reverse Active Energy Value Position */
#define ANENERGYC_Msk                           (_UINT16_(0xFFFF) << ANENERGYC_Pos) /* (ANENERGYA) Phase C Reverse Active Energy Value Mask */
#define ANENERGYC_Val(value)                    (ANENERGYC_Msk & (_UINT16_(value) << ANENERGYC_Pos))

/* -------- Total Metering Forward Reactive Energy pulses : (RPENERGYT Offset: 0x88H) (R/C - 16 bits) - ATM90E36 Metering Total Forward Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYT_Pos                           _UINT16_(0)                                   /* (APENERGYT) Total Forward Rective Energy Value Position */
#define RPENERGYT_Msk                           (_UINT16_(0xFFFF) << APENERGYT_Pos) /* (APENERGYT) Total Forward Rective Energy Value Mask */
#define RPENERGYT_Val(value)                    (APENERGYT_Msk & (_UINT16_(value) << APENERGYT_Pos))

/* -------- Phase A Metering Forward Reactive Energy pulses : (RPENERGYA Offset: 0x89H) (R/C - 16 bits) - ATM90E36 Metering Phase A Forward Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYA_Pos                           _UINT16_(0)                                   /* (APENERGYA) Phase A Forward Rective Energy Value Position */
#define RPENERGYA_Msk                           (_UINT16_(0xFFFF) << APENERGYA_Pos) /* (APENERGYA) Phase A Forward Rective Energy Value Mask */
#define RPENERGYA_Val(value)                    (APENERGYA_Msk & (_UINT16_(value) << APENERGYA_Pos)) /* -------- Phase A Metering Forward Reactive Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Reactive Energy pulses : (RPENERGYB Offset: 0x8AH) (R/C - 16 bits) - ATM90E36 Metering Phase B Forward Rective Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYB_Pos                           _UINT16_(0)                                   /* (APENERGYB) Phase B  Forward Reactive Energy Value Position */
#define RPENERGYB_Msk                           (_UINT16_(0xFFFF) << APENERGYB_Pos) /* (APENERGYB) Phase B  Forward Reactive Energy Value Mask */
#define RPENERGYB_Val(value)                    (APENERGYB_Msk & (_UINT16_(value) << APENERGYB_Pos)) /* -------- Phase B  Metering Forward Reactive Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Reactive Energy pulses : (RPENERGYC Offset: 0x8BH) (R/C - 16 bits) - ATM90E36 Metering Phase C Forward Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RPENERGYC_Pos                           _UINT16_(0)                                   /* (RPENERGYC) Phase C Forward Reactive Energy Value Position */
#define RPENERGYC_Msk                           (_UINT16_(0xFFFF) << RPENERGYC_Pos) /* (RPENERGYC) Phase C Forward Reactive Energy Value Mask */
#define RPENERGYC_Val(value)                    (RPENERGYC_Msk & (_UINT16_(value) << APENERGYC_Pos))

/* -------- Metering Total Reverse Active Energy pulses : (RNENERGYT Offset: 0x8CH) (R/C - 16 bits) - ATM90E36 Metering Total Reverse Rective Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYT_Pos                           _UINT16_(0)                                   /* (RNENERGYT) Total Reverse Rective Energy Value Position */
#define RNENERGYT_Msk                           (_UINT16_(0xFFFF) << RNENERGYT_Pos) /* (RNENERGYT) Total Reverse Rective Energy Value Mask */
#define RNENERGYT_Val(value)                    (RNENERGYT_Msk & (_UINT16_(value) << RNENERGYT_Pos))

/* -------- Metering Phase A Reverse Active Energy pulses : (RNENERGYA Offset: 0x8DH) (R/C - 16 bits) - ATM90E36 Metering Phase A Reverse Rective Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYA_Pos                           _UINT16_(0)                                   /* (RNENERGYA) Phase A Reverse Reactive Energy Value Position */
#define RNENERGYA_Msk                           (_UINT16_(0xFFFF) << RNENERGYA_RNENERGYA_Pos) /* (RNENERGYA) Phase A Reverse Reactive Energy Value Mask */
#define RNENERGYA_Val(value)                    (RNENERGYA_RNENERGYA_Msk & (_UINT16_(value) << RNENERGYA_RNENERGYA_Pos))

/* -------- Metering Phase B Reverse Active Energy pulses : (RNENERGYB Offset: 0x8EH) (R/C - 16 bits) - ATM90E36 Metering Phase B Reverse Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYB_Pos                           _UINT16_(0)                                   /* (RNENERGYB) Phase B Reverse Reactive Energy Value Position */
#define RNENERGYB_Msk                           (_UINT16_(0xFFFF) << RNENERGYB_Pos) /* (RNENERGYB) Phase B Reverse Reactive Energy Value Mask */
#define RNENERGYB_Val(value)                    (RNENERGYB_Msk & (_UINT16_(value) << ANENERGYB_Pos))

/* -------- Metering Phase C Reverse Active Energy pulses : (RNENERGYC Offset: 0x8FH) (R/C - 16 bits) - ATM90E36 Metering Phase C Reverse Reactive Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define RNENERGYC_Pos                           _UINT16_(0)                                   /* (RNENERGYC) Phase C Reverse Reactive Energy Value Position */
#define NENERGYC_Msk                           (_UINT16_(0xFFFF) << RNENERGYC_Pos) /* (RNENERGYC) Phase C Reverse Reactive Energy Value Mask */
#define RNENERGYC_Val(value)                    (RNENERGYC_Msk & (_UINT16_(value) << RNENERGYC_Pos))

/* -------- Metering Total (Arithmetic Sum) Apparent Energy pulses : (SAENERGYT Offset: 0x90H) (R/C - 16 bits) - ATM90E36 Metering Total (Arithmetic Sum) Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SAENERGYT_Pos                           _UINT16_(0)                                   /* (SAENERGYT) Total (Arithmetic Sum) Apparent Energy Value Position */
#define SAENERGYT_Msk                           (_UINT16_(0xFFFF) << SAENERGYT_Pos) /* (SAENERGYT) Total (Arithmetic Sum) Apparent Energy Value Mask */
#define SAENERGYT_Val(value)                    (SAENERGYT_Msk & (_UINT16_(value) << SAENERGYT_Pos))

/* -------- Metering Phase A Apparent Energy pulses : (SAENERGYA Offset: 0x91H) (R/C - 16 bits) - ATM90E36 Metering Phase A Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SENERGYA_Pos                           _UINT16_(0)                                   /* (SAENERGYA) Phase A Apparent Energy Value Position */
#define SENERGYA_Msk                           (_UINT16_(0xFFFF) << SAENERGYA_Pos) /* (SAENERGYA) Phase A Apparent Apparent Energy Value Mask */
#define SENERGYA_Val(value)                    (SAENERGYA_Msk & (_UINT16_(value) << SAENERGYA_Pos))

/* -------- Metering Phase B Apparent Energy pulses : (SAENERGYB Offset: 0x92H) (R/C - 16 bits) - ATM90E36 Metering Phase B Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SENERGYB_Pos                           _UINT16_(0)                                   /* (SAENERGYB) Phase B Apparent Energy Value Position */
#define SENERGYB_Msk                           (_UINT16_(0xFFFF) << SAENERGYB_Pos) /* (SAENERGYB) Phase B Apparent Apparent Energy Value Mask */
#define SENERGYB_Val(value)                    (SAENERGYB_Msk & (_UINT16_(value) << SAENERGYB_Pos))

/* -------- Metering Phase C Apparent Energy pulses : (SAENERGYC Offset: 0x93H) (R/C - 16 bits) - ATM90E36 Metering Phase C Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SENERGYC_Pos                           _UINT16_(0)                                   /* (SAENERGYC) Phase C Apparent Energy Value Position */
#define SENERGYC_Msk                           (_UINT16_(0xFFFF) << SAENERGYC_Pos) /* (SAENERGYC) Phase C Apparent Apparent Energy Value Mask */
#define SENERGYC_Val(value)                    (SAENERGYC_Msk & (_UINT16_(value) << SAENERGYC_Pos))

/* -------- Metering Total (Vector Sum) Apparent Energy pulses : (SVENERGYT Offset: 0x94H) (R/C - 16 bits) - ATM90E36 Metering Total (Vector Sum) Apparent Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define SVENERGYT_Pos                           _UINT16_(0)                                   /* (SVENERGYT) Total (Vector Sum) Apparent Energy Value Position */
#define SVENERGYT_Msk                           (_UINT16_(0xFFFF) << SVENERGYT_Pos)           /* (SVENERGYT) Total (Vector Sum) Apparent Energy Value Mask */
#define SVENERGYT_Val(value)                    (SVENERGYT_Msk & (_UINT16_(value) << SVENERGYT_Pos))

/* -------- Metering STATUS 0 : (ENSTATUS0 Offset: 0x95) (R - 16 bits) ATM90E36 Energy Status 0 Register -------- */
#define ENSTATUS0_CF1REVFLAG_Pos                _UINT16_(0)                                   /* (CF1REVFLAG) Active Energy (CF1) direction Status Position */
#define ENSTATUS0_CF1REVFLAG_Msk                (_UINT16_(0x1) << ENSTATUS0_CF1REVFLAG_Pos)    /* (CF1REVFLAG) Active Energy (CF1) direction Status Mask */
#define ENSTATUS0_CF1REVFLAG_Val(value)         (ENSTATUS0_CF1REVFLAG_Msk & (_UINT16_(value) << ENSTATUS0_CF1REVFLAG_Pos))
#define   ENSTATUS0_CF1REVFLAG_FWD_Val          _UINT16_(0)                                   /* (CF1REVFLAG) Active Energy (CF1) direction Status Forward or Absolute */
#define   ENSTATUS0_CF1REVFLAG_REV_Val          _UINT16_(1)                                   /* (CF1REVFLAG) Active Energy (CF1) direction Status Reverse */
#define ENSTATUS0_CF2REVFLAG_Pos                _UINT16_(1)                                   /* (CF2REVFLAG) Active Energy (CF2) direction Status Position */
#define ENSTATUS0_CF2REVFLAG_Msk                (_UINT16_(0x1) << ENSTATUS0_CF2REVFLAG_Pos)   /* (CF2REVFLAG) Active Energy (CF2) direction Status Mask */
#define ENSTATUS0_CF2REVFLAG_Val(value)         (ENSTATUS0_CF2REVFLAG_Msk & (_UINT16_(value) << ENSTATUS0_CF2REVFLAG_Pos))
#define   ENSTATUS0_CF2REVFLAG_FWD_Val          _UINT16_(0)                                   /* (CF2REVFLAG) Active Energy (CF2) direction Status Forward or Absolute */
#define   ENSTATUS0_CF2REVFLAG_REV_Val          _UINT16_(1)                                   /* (CF2REVFLAG) Active Energy (CF2) direction Status Reverse */
#define ENSTATUS0_CF3REVFLAG_Pos                _UINT16_(2)                                   /* (CF3REVFLAG) Active Energy (CF3) direction Status Position */
#define ENSTATUS0_CF3REVFLAG_Msk                (_UINT16_(0x1) << ENSTATUS0_CF3REVFLAG_Pos)   /* (CF3REVFLAG) Active Energy (CF3) direction Status Mask */
#define ENSTATUS0_CF3REVFLAG_Val(value)         (ENSTATUS0_CF3REVFLAG_Msk & (_UINT16_(value) << ENSTATUS0_CF3REVFLAG_Pos))
#define   ENSTATUS0_CF3REVFLAG_FWD_Val          _UINT16_(0)                                   /* (CF3REVFLAG) Active Energy (CF3) direction Status Forward or Absolute */
#define   ENSTATUS0_CF3REVFLAG_REV_Val          _UINT16_(1)                                   /* (CF3REVFLAG) Active Energy (CF3) direction Status Reverse */
#define ENSTATUS0_CF4REVFLAG_Pos                _UINT16_(3)                                   /* (CF4REVFLAG) Active Energy (CF4) direction Status Position */
#define ENSTATUS0_CF4REVFLAG_Msk                (_UINT16_(0x1) << ENSTATUS0_CF4REVFLAG_Pos)   /* (CF4REVFLAG) Active Energy (CF4) direction Status Mask */
#define ENSTATUS0_CF4REVFLAG_Val(value)         (ENSTATUS0_CF4REVFLAG_Msk & (_UINT16_(value) << ENSTATUS0_CF4REVFLAG_Pos))
#define   ENSTATUS0_CF4REVFLAG_FWD_Val          _UINT16_(0)                                   /* (CF4REVFLAG) Active Energy (CF4) direction Status Forward or Absolute */
#define   ENSTATUS0_CF4REVFLAG_REV_Val          _UINT16_(1)                                   /* (CF4REVFLAG) Active Energy (CF4) direction Status Reverse */
#define ENSTATUS0_TVSNOLOAD_Pos                 _UINT16_(12)                                  /* (TVSNOLOAD) Vector Sum Apparent No Load State Position */
#define ENSTATUS0_TVSNOLOAD_Msk                 (_UINT16_(0x1) << ENSTATUS0_TPNOLOAD_Pos)     /* (TVSNOLOAD) Vector Sum Apparent No Load State Mask */
#define ENSTATUS0_TVSNOLOAD_Val(value)          (ENSTATUS0_TPNOLOAD_Msk & (_UINT16_(value) << ENSTATUS0_TPNOLOAD_Pos))
#define   ENSTATUS0_TVSNOLOAD_FALSE_Val         _UINT16_(0)                                   /* (TVSNOLOAD) NOT Apparent No Load State */
#define   ENSTATUS0_TVSNOLOAD_ACTIVE_Val        _UINT16_(1)                                   /* (TVSNOLOAD) Apparent No Load State */
#define ENSTATUS0_TASNOLOAD_Pos                 _UINT16_(13)                                  /* (TASNOLOAD) Apparent No Load State Position */
#define ENSTATUS0_TASNOLOAD_Msk                 (_UINT16_(0x1) << ENSTATUS0_TASNOLOAD_Pos)    /* (TASNOLOAD) Apparent No Load State Mask */
#define ENSTATUS0_TASNOLOAD_Val(value)          (ENSTATUS0_TASNOLOAD_Msk & (_UINT16_(value) << ENSTATUS0_TASNOLOAD_Pos))
#define   ENSTATUS0_TASNOLOAD_FALSE_Val         _UINT16_(0)                                   /* (TASNOLOAD) NOT Apparent No Load State */
#define   ENSTATUS0_TASNOLOAD_ACTIVE_Val        _UINT16_(1)                                   /* (TASNOLOAD) Apparent No Load State */
#define ENSTATUS0_TPNOLOAD_Pos                  _UINT16_(14)                                  /* (TPNOLOAD) Active No Load State Position */
#define ENSTATUS0_TPNOLOAD_Msk                  (_UINT16_(0x1) << ENSTATUS0_TPNOLOAD_Pos)     /* (TPNOLOAD) Active No Load State Mask */
#define ENSTATUS0_TPNOLOAD_Val(value)           (ENSTATUS0_TPNOLOAD_Msk & (_UINT16_(value) << ENSTATUS0_TPNOLOAD_Pos))
#define   ENSTATUS0_TPNOLOAD_FALSE_Val          _UINT16_(0)                                   /* (TPNOLOAD) NOT Active No Load State */
#define   ENSTATUS0_TPNOLOAD_ACTIVE_Val         _UINT16_(1)                                   /* (TPNOLOAD) Active No Load State */
#define ENSTATUS0_TQNOLOAD_Pos                  _UINT16_(15)                                  /* (TQNOLOAD) Reactive No Load State Position */
#define ENSTATUS0_TQNOLOAD_Msk                  (_UINT16_(0x1) << ENSTATUS0_TQNOLOAD_Pos)     /* (TQNOLOAD) Reactive No Load Status Mask */
#define ENSTATUS0_TQNOLOAD_Val(value)           (ENSTATUS0_TQNOLOAD_Msk & (_UINT16_(value) << ENSTATUS0_TQNOLOAD_Pos))
#define   ENSTATUS0_TQNOLOAD_FALSE_Val          _UINT16_(0)                                   /* (TQNOLOAD) NOT Reactive No Load State */
#define   ENSTATUS0_TQNOLOAD_ACTIVE_Val         _UINT16_(1)                                   /* (TQNOLOAD) Reactive No Load State */
#define ENSTATUS0_DEFAULT_Val                   _UINT16_(0xF000)

/* -------- Metering STATUS 1 : (ENSTATUS1 Offset: 0x96) (R - 16 bits) ATM90E36 Energy Status 1 Register -------- */
#define ENSTATUS1_PHASELOSSC_Pos                _UINT16_(0)                                   /* (PHASELOSSC) Phase C Phase Loss Status Position */
#define ENSTATUS1_PHASELOSSC_Msk                (_UINT16_(0x1) << ENSTATUS1_PHASELOSSC_Pos)   /* (PHASELOSSC) Phase C Phase Loss Status Mask */
#define ENSTATUS1_PHASELOSSC_Val(value)         (ENSTATUS1_PHASELOSSC_Msk & (_UINT16_(value) << ENSTATUS1_PHASELOSSC_Pos))
#define   ENSTATUS1_PHASELOSSC_ACT_Val          _UINT16_(1)                                   /* (PHASELOSSC) Phase C Phase Loss Status active */
#define ENSTATUS1_PHASELOSSB_Pos                _UINT16_(1)                                   /* (PHASELOSSC) Phase B Phase Loss Status Position */
#define ENSTATUS1_PHASELOSSB_Msk                (_UINT16_(0x1) << ENSTATUS1_PHASELOSSB_Pos)   /* (PHASELOSSC) Phase B Phase Loss Status Mask */
#define ENSTATUS1_PHASELOSSB_Val(value)         (ENSTATUS1_PHASELOSSB_Msk & (_UINT16_(value) << ENSTATUS1_PHASELOSSB_Pos))
#define   ENSTATUS1_PHASELOSSB_ACT_Val          _UINT16_(1)                                   /* (PHASELOSSC) Phase B Phase Loss Status active */
#define ENSTATUS1_PHASELOSSA_Pos                _UINT16_(2)                                   /* (PHASELOSSC) Phase A Phase Loss Status Position */
#define ENSTATUS1_PHASELOSSA_Msk                (_UINT16_(0x1) << ENSTATUS1_PHASELOSSA_Pos)   /* (PHASELOSSC) Phase A Phase Loss Status Mask */
#define ENSTATUS1_PHASELOSSA_Val(value)         (ENSTATUS1_PHASELOSSA_Msk & (_UINT16_(value) << ENSTATUS1_PHASELOSSA_Pos))
#define   ENSTATUS1_PHASELOSSA_ACT_Val          _UINT16_(1)                                   /* (PHASELOSSC) Phase A Phase Loss Status active */
#define ENSTATUS1_SAGPHASEC_Pos                 _UINT16_(4)                                   /* (SAGPHASEC) Phase C Phase Loss Status Position */
#define ENSTATUS1_SAGPHASEC_Msk                 (_UINT16_(0x1) << ENSTATUS1_SAGPHASEC_Pos)    /* (SAGPHASEC) Phase C Phase Loss Status Mask */
#define ENSTATUS1_SAGPHASEC_Val(value)          (ENSTATUS1_SAGPHASEC_Msk & (_UINT16_(value) << ENSTATUS1_SAGPHASEC_Pos))
#define   ENSTATUS1_SAGPHASEC_ACT_Val           _UINT16_(1)                                   /* (SAGPHASEC) Phase C Phase Loss Status active */
#define ENSTATUS1_SAGPHASEB_Pos                 _UINT16_(5)                                   /* (SAGPHASEB) Phase B Phase Loss Status Position */
#define ENSTATUS1_SAGPHASEB_Msk                 (_UINT16_(0x1) << ENSTATUS1_SAGPHASEB_Pos)    /* (SAGPHASEB) Phase B Phase Loss Status Mask */
#define ENSTATUS1_SAGPHASEB_Val(value)          (ENSTATUS1_SAGPHASEB_Msk & (_UINT16_(value) << ENSTATUS1_SAGPHASEB_Pos))
#define   ENSTATUS1_SAGPHASEB_ACT_Val           _UINT16_(1)                                   /* (SAGPHASEB) Phase B Phase Loss Status active */
#define ENSTATUS1_SAGPHASEA_Pos                 _UINT16_(6)                                   /* (SAGPHASEA) Phase A Phase Loss Status Position */
#define ENSTATUS1_SAGPHASEA_Msk                 (_UINT16_(0x1) << ENSTATUS1_SAGPHASEA_Pos)    /* (SAGPHASEA) Phase A Phase Loss Status Mask */
#define ENSTATUS1_SAGPHASEA_Val(value)          (ENSTATUS1_SAGPHASEA_Msk & (_UINT16_(value) << ENSTATUS1_SAGPHASEA_Pos))
#define   ENSTATUS1_SAGPHASEA_ACT_Val           _UINT16_(1)                                   /* (SAGPHASEA) Phase A Phase Loss Status active */
#define ENSTATUS1_DEFAULT_Val                   _UINT16_(0)

/* -------- Measurement Total (All-phase-sum) Apparent Power : (SVMEANT Offset: 0x98H) (R - 16 bits) - ATM90E36 Measurement Total (All-phase-sum) Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SVMEANT_Pos                                     _UINT16_(0)                                   /* (SVMEANT) Total (All-phase-sum) Apparent Power Position */
#define SVMEANT_Msk                                     (_UINT16_(0xFFFF) << SVMEANT_Pos)             /* (SVMEANT) Total (All-phase-sum) Apparent Power Mask */
#define SVMEANT_Val(value)                              (SVMEANT_Msk & (_UINT16_(value) << SVMEANT_Pos))

/* -------- Measurement Total (All-phase-sum) Apparent Power LSB: (SVMEANT Offset: 0x99H) (R - 16 bits) - ATM90E36 Measurement Total (All-phase-sum) Apparent Power LSB -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SVMEANTLSB_Pos                                 _UINT16_(0)                                    /* (SVMEANT) Total (All-phase-sum) Apparent Power Position */
#define SVMEANTLSB_Msk                                 (_UINT16_(0xFFFF) << SVMEANTLSB_Pos)           /* (SVMEANT) Total (All-phase-sum) Apparent Power Mask */
#define SVMEANTLSB_Val(value)                          (SVMEANTLSB_Msk & (_UINT16_(value) << SVMEANTLSB_Pos))

/* ************************************************************************** */
/*   FUNDAMENTAL / HARMONIC ENERGY REGISTER                                   */
/* ************************************************************************** */
/* -------- Total Metering Forward Active Fundamental Energy pulses : (APENERGYT Offset: 0xA0H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYTF_Pos                           _UINT16_(0)                                            /* (APENERGYTF) Total Forward Active Fundamental Energy Value Position */
#define APENERGYTF_Msk                           (_UINT16_(0xFFFF) << APENERGYTF_Pos)                   /* (APENERGYTF) Total Forward Active Fundamental Energy Value Mask */
#define APENERGYTF_Val(value)                    (APENERGYTF_Msk & (_UINT16_(value) << APENERGYTF_Pos))

/* -------- Phase A Metering Forward Active Fundamental Energy pulses : (APENERGYA Offset: 0xA1H) (R/C - 16 bits) - ATM90E32 Metering Phase A Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYAF_Pos                           _UINT16_(0)                                            /* (APENERGYA) Phase A Forward Active Energy Fundamental Value Position */
#define APENERGYAF_Msk                           (_UINT16_(0xFFFF) << APENERGYAF_Pos)                   /* (APENERGYA) Phase A Forward Active Energy Fundamental Value Mask */
#define APENERGYAF_Val(value)                    (APENERGYAF_Msk & (_UINT16_(value) << APENERGYAF_Pos)) /* -------- Phase A Metering Forward Active Fundamental Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Active Fundamental Energy pulses : (APENERGYB Offset: 0xA2H) (R/C - 16 bits) - ATM90E32 Metering Phase B Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYBF_Pos                           _UINT16_(0)                                            /* (APENERGYB) Phase B  Forward Active Fundamental Energy Value Position */
#define APENERGYBF_Msk                           (_UINT16_(0xFFFF) << APENERGYBF_Pos)                   /* (APENERGYB) Phase B  Forward Active FundamentalEnergy Value Mask */
#define APENERGYBF_Val(value)                    (APENERGYBF_Msk & (_UINT16_(value) << APENERGYBF_Pos)) /* -------- Phase B  Metering Forward Active Fundamental Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Active Fundamental Energy pulses : (APENERGYC Offset: 0xA3H) (R/C - 16 bits) - ATM90E32 Metering Phase C Forward Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYCF_Pos                           _UINT16_(0)                                            /* (APENERGYCF) Phase C Forward Active Fundamental Energy Value Position */
#define APENERGYCF_Msk                           (_UINT16_(0xFFFF) << APENERGYCF_Pos)                   /* (APENERGYCF) Phase C Forward Active Fundamental Energy Value Mask */
#define APENERGYCF_Val(value)                    (APENERGYCF_Msk & (_UINT16_(value) << APENERGYCF_Pos))

/* -------- Metering Total Reverse Active Fundamental Energy pulses : (ANENERGYTH Offset: 0xA4H) (R/C - 16 bits) - ATM90E32 Metering Total Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYTF_Pos                           _UINT16_(0)                                            /* (ANENERGYTF) Total Reverse Active Fundamental Energy Value Position */
#define ANENERGYTF_Msk                           (_UINT16_(0xFFFF) << ANENERGYTF_Pos)                   /* (ANENERGYTF) Total Reverse Active Fundamental Energy Value Mask */
#define ANENERGYTF_Val(value)                    (ANENERGYTF_Msk & (_UINT16_(value) << ANENERGYTF_Pos))

/* -------- Metering Phase A Reverse Active Fundamental  Energy pulses : (ANENERGYAH Offset: 0xA5H) (R/C - 16 bits) - ATM90E32 Metering Phase A Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYAF_Pos                           _UINT16_(0)                                            /* (ANENERGYAF) Phase A Reverse Active Fundamental Energy Value Position */
#define ANENERGYAF_Msk                           (_UINT16_(0xFFFF) << ANENERGYAF_Pos)                   /* (ANENERGYAF) Phase A Reverse Active Fundamental Energy Value Mask */
#define ANENERGYAF_Val(value)                    (ANENERGYAF_Msk & (_UINT16_(value) << ANENERGYAF_Pos))

/* -------- Metering Phase B Reverse Active Fundamental Energy pulses : (ANENERGYBH Offset: 0xA6H) (R/C - 16 bits) - ATM90E32 Metering Phase B Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYBF_Pos                           _UINT16_(0)                                            /* (ANENERGYBF) Phase B Reverse Active Fundamental Energy Value Position */
#define ANENERGYBF_Msk                           (_UINT16_(0xFFFF) << ANENERGYBF_Pos)                   /* (ANENERGYBF) Phase B Reverse Active Fundamental Energy Value Mask */
#define ANENERGYBF_Val(value)                    (ANENERGYBF_Msk & (_UINT16_(value) << ANENERGYBF_Pos))

/* -------- Metering Phase C Reverse Active Fundamental Energy pulses : (ANENERGYCH Offset: 0xA7H) (R/C - 16 bits) - ATM90E32 Metering Phase C Reverse Active Fundamental Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYCF_Pos                           _UINT16_(0)                                            /* (ANENERGYCF) Phase C Reverse Active Fundamental Energy Value Position */
#define ANENERGYCF_Msk                           (_UINT16_(0xFFFF) << ANENERGYCF_Pos)                   /* (ANENERGYCF) Phase C Reverse Active Fundamental Energy Value Mask */
#define ANENERGYCF_Val(value)                    (ANENERGYCF_Msk & (_UINT16_(value) << ANENERGYCF_Pos))

/* -------- Total Metering Forward Active Harmonic Energy pulses : (APENERGYT Offset: 0xA8H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYTH_Pos                           _UINT16_(0)                                            /* (APENERGYTH) Total Forward Active Harmonic Energy Value Position */
#define APENERGYTH_Msk                           (_UINT16_(0xFFFF) << APENERGYTH_Pos)                   /* (APENERGYTH) Total Forward Active Harmonic Energy Value Mask */
#define APENERGYTH_Val(value)                    (APENERGYTH_Msk & (_UINT16_(value) << APENERGYTH_Pos))

/* -------- Phase A Metering Forward Active Harmonic Energy pulses : (APENERGYA Offset: 0xA9H) (R/C - 16 bits) - ATM90E32 Metering Phase A Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYAH_Pos                           _UINT16_(0)                                            /* (APENERGYAH) Phase A Forward Active Energy Harmonic Value Position */
#define APENERGYAH_Msk                           (_UINT16_(0xFFFF) << APENERGYAH_Pos)                   /* (APENERGYAH) Phase A Forward Active Energy Harmonic Value Mask */
#define APENERGYAH_Val(value)                    (APENERGYAH_Msk & (_UINT16_(value) << APENERGYAH_Pos)) /* -------- Phase A Metering Forward Active Harmonic Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase B Metering Forward Active Harmonic Energy pulses : (APENERGYBH Offset: 0xAAH) (R/C - 16 bits) - ATM90E32 Metering Phase B Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYBH_Pos                           _UINT16_(0)                                            /* (APENERGYBH) Phase B  Forward Active Harmonic Energy Value Position */
#define APENERGYBH_Msk                           (_UINT16_(0xFFFF) << APENERGYBH_Pos)                   /* (APENERGYBH) Phase B  Forward Active Harmonic Energy Value Mask */
#define APENERGYBH_Val(value)                    (APENERGYB_Msk & (_UINT16_(value) << APENERGYBH_Pos))  /* -------- Phase B  Metering Forward Active Harmonic Energy pulses : (APENERGY Offset: 0x80H) (R/C - 16 bits) - ATM90E32 Metering Total Forward Active Energy -------- */

/* -------- Phase C Metering Forward Active Harmonic Energy pulses : (APENERGYCH Offset: 0xABH) (R/C - 16 bits) - ATM90E32 Metering Phase C Forward Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define APENERGYCH_Pos                           _UINT16_(0)                                            /* (APENERGYCH) Phase C Forward Active Harmonic Energy Value Position */
#define APENERGYCH_Msk                           (_UINT16_(0xFFFF) << APENERGYCH_Pos)                   /* (APENERGYCH) Phase C Forward Active Harmonic Energy Value Mask */
#define APENERGYCH_Val(value)                    (APENERGYCH_Msk & (_UINT16_(value) << APENERGYCH_Pos))

/* -------- Metering Total Reverse Active Harmonic Energy pulses : (ANENERGYTH Offset: 0xACH) (R/C - 16 bits) - ATM90E32 Metering Total Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYTH_Pos                           _UINT16_(0)                                            /* (ANENERGYTH) Total Reverse Active Harmonic Energy Value Position */
#define ANENERGYTH_Msk                           (_UINT16_(0xFFFF) << ANENERGYTH_Pos)                   /* (ANENERGYTH) Total Reverse Active Harmonic Energy Value Mask */
#define ANENERGYTH_Val(value)                    (ANENERGYTH_Msk & (_UINT16_(value) << ANENERGYTH_Pos))

/* -------- Metering Phase A Reverse Active Harmonic  Energy pulses : (ANENERGYAH Offset: 0xADH) (R/C - 16 bits) - ATM90E32 Metering Phase A Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYAH_Pos                           _UINT16_(0)                                            /* (ANENERGYAH) Phase A Reverse Active Harmonic Energy Value Position */
#define ANENERGYAH_Msk                           (_UINT16_(0xFFFF) << ANENERGYAH_Pos)                   /* (ANENERGYAH) Phase A Reverse Active Harmonic Energy Value Mask */
#define ANENERGYAH_Val(value)                    (ANENERGYAH_Msk & (_UINT16_(value) << ANENERGYAH_Pos))

/* -------- Metering Phase B Reverse Active Harmonic Energy pulses : (ANENERGYBH Offset: 0xAEH) (R/C - 16 bits) - ATM90E32 Metering Phase B Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYBH_Pos                           _UINT16_(0)                                            /* (ANENERGYBH) Phase B Reverse Active Harmonic Energy Value Position */
#define ANENERGYBH_Msk                           (_UINT16_(0xFFFF) << ANENERGYBH_Pos)                   /* (ANENERGYBH) Phase B Reverse Active Harmonic Energy Value Mask */
#define ANENERGYBH_Val(value)                    (ANENERGYBF_Msk & (_UINT16_(value) << ANENERGYBF_Pos))

/* -------- Metering Phase C Reverse Active Harmonic Energy pulses : (ANENERGYCH Offset: 0xAFH) (R/C - 16 bits) - ATM90E32 Metering Phase C Reverse Active Harmonic Energy -------- */
/* -------- Note: Data format is XXXX.X pulses. Resolution is 0.01 pulse. */
#define ANENERGYCH_Pos                           _UINT16_(0)                                            /* (ANENERGYCH) Phase C Reverse Active Harmonic Energy Value Position */
#define ANENERGYCH_Msk                           (_UINT16_(0xFFFF) << ANENERGYCH_Pos)                   /* (ANENERGYCH) Phase C Reverse Active Harmonic Energy Value Mask */
#define ANENERGYCH_Val(value)                    (ANENERGYCH_Msk & (_UINT16_(value) << ANENERGYCH_Pos))

#define ENERGY_DEFAULT_Val                       _UINT16_(0)

/* ************************************************************************** */
/*   MEASUREMENT REGISTER - POWER AND POWER FACTOR REGISTERS                  */
/* ************************************************************************** */
/* -------- Measurement Total (All phase sum) Active Power : (PMEAN Offset: 0xB0H) (R - 16 bits) - ATM90E36 Total (All-phase-sum) Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANT_Pos                                 _UINT16_(0)                                 /* (PMEANT) Total (All-phase-sum) Active Power Position */
#define PMEANT_Msk                                 (_UINT16_(0xFFFF) << PMEANT_Pos)            /* (PMEANT) Total (All-phase-sum) Active Power Mask */
#define PMEANT_Val(value)                          (PMEANT_Msk & (_UINT16_(value) << PMEANT_Pos))

/* -------- Measurement Phase A Active Power : (PMEANA Offset: 0xB1H) (R - 16 bits) - ATM90E36 Phase A Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANA_Pos                                 _UINT16_(0)                                 /* (PMEANA) Phase A Active Power Position */
#define PMEANA_Msk                                 (_UINT16_(0xFFFF) << PMEANA_Pos)            /* (PMEANA) Phase A Active Power Mask */
#define PMEANA_Val(value)                          (PMEANA_Msk & (_UINT16_(value) << PMEANA_Pos))

/* -------- Measurement Phase B Active Power : (PMEANB Offset: 0xB2H) (R - 16 bits) - ATM90E36 Phase B Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANB_Pos                                 _UINT16_(0)                                 /* (PMEANB) Phase B Active Power Position */
#define PMEANB_Msk                                 (_UINT16_(0xFFFF) << PMEANB_Pos)            /* (PMEANB) Phase B Active Power Mask */
#define PMEANB_Val(value)                          (PMEANB_Msk & (_UINT16_(value) << PMEANB_Pos))

/* -------- Measurement Phase C Active Power : (PMEAN Offset: 0xB3H) (R - 16 bits) - ATM90E36 Phase C Active Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANC_Pos                                 _UINT16_(0)                                 /* (PMEANC) Phase C Active Power Position */
#define PMEANC_Msk                                 (_UINT16_(0xFFFF) << PMEANC_Pos)            /* (PMEANC) Phase C Active Power Mask */
#define PMEANC_Val(value)                          (PMEANC_Msk & (_UINT16_(value) << PMEANC_Pos))

/* -------- Measurement Total (All-phase-sum) Reactive Power : (QMEAN Offset: 0xB4H) (R - 16 bits) - ATM90E36 Measurement Total (All-phase-sum) Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANT_Pos                                 _UINT16_(0)                                 /* (QMEANT) Total (All-phase-sum) Reactive Power Position */
#define QMEANT_Msk                                 (_UINT16_(0xFFFF) << QMEANT_Pos)            /* (QMEANT) Total (All-phase-sum) Reactive Power Mask */
#define QMEANT_Val(value)                          (QMEANT_Msk & (_UINT16_(value) << QMEANT_Pos))

/* -------- Measurement Phase A Reactive Power : (QMEAN Offset: 0xB5H) (R - 16 bits) - ATM90E36 Measurement Phase A Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANA_Pos                                 _UINT16_(0)                                 /* (QMEANT) Phase A Reactive Power Position */
#define QMEANA_Msk                                 (_UINT16_(0xFFFF) << QMEANA_Pos)            /* (QMEANT) Phase A Reactive Power Mask */
#define QMEANA_Val(value)                          (QMEANA_Msk & (_UINT16_(value) << QMEANA_Pos))

/* -------- Measurement Phase B Reactive Power : (QMEANB Offset: 0xB6H) (R - 16 bits) - ATM90E36 Measurement Phase B Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANB_Pos                                 _UINT16_(0)                                 /* (QMEANB) Phase B Reactive Power Position */
#define QMEANB_Msk                                 (_UINT16_(0xFFFF) << QMEANB_Pos)            /* (QMEANB) Phase B Reactive Power Mask */
#define QMEANB_Val(value)                          (QMEANB_Msk & (_UINT16_(value) << QMEANB_Pos))

/* -------- Measurement Phase C Reactive Power : (QMEANC Offset: 0xB7H) (R - 16 bits) - ATM90E36 Measurement Phase C Reactive Power -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANC_Pos                                 _UINT16_(0)                                 /* (QMEANC) Phase C Reactive Power Position */
#define QMEANC_Msk                                 (_UINT16_(0xFFFF) << QMEANC_Pos)     /* (QMEANC) Phase C Reactive Power Mask */
#define QMEANC_Val(value)                          (QMEANC_Msk & (_UINT16_(value) << QMEANC_Pos))

/* -------- Measurement Total (All-phase-sum) Apparent Power : (SAMEANT Offset: 0xB8H) (R - 16 bits) - ATM90E36 Measurement Total (All-phase-sum) Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SAMEANT_Pos                                 _UINT16_(0)                                /* (SAMEANT) Total (All-phase-sum) Apparent Power Position */
#define SAMEANT_Msk                                 (_UINT16_(0xFFFF) << SAMEANT_Pos)          /* (SAMEANT) Total (All-phase-sum) Apparent Power Mask */
#define SAMEANT_Val(value)                          (SAMEANT_Msk & (_UINT16_(value) << SAMEANT_Pos))

/* -------- Measurement Phase A Apparent Power : (SMEANA Offset: 0xB9H) (R - 16 bits) - ATM90E36 Measurement Phase A Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANA_Pos                                 _UINT16_(0)                                 /* (SMEANA) Phase A Apparent Power Position */
#define SMEANA_Msk                                 (_UINT16_(0xFFFF) << SMEANA_Pos)            /* (SMEANA) Phase A Apparent Power Mask */
#define SMEANA_Val(value)                          (SMEANA_Msk & (_UINT16_(value) << SMEANA_Pos))

/* -------- Measurement Phase B Apparent Power : (SMEANB Offset: 0xBAH) (R - 16 bits) - ATM90E36 Measurement Phase B Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANB_Pos                                 _UINT16_(0)                                 /* (SMEANB) Phase B Apparent Power Position */
#define SMEANB_Msk                                 (_UINT16_(0xFFFF) << SMEANB_Pos)            /* (SMEANB) Phase B Apparent Power Mask */
#define SMEANB_Val(value)                          (SMEANB_Msk & (_UINT16_(value) << SMEANB_Pos))

/* -------- Measurement Phase C Apparent Power : (SMEANC Offset: 0xBBH) (R - 16 bits) - ATM90E36 Measurement Phase C Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANC_Pos                                 _UINT16_(0)                                 /* (SMEANC) Phase C Apparent Power Position */
#define SMEANC_Msk                                 (_UINT16_(0xFFFF) << SMEANC_Pos)            /* (SMEANC) Phase C Apparent Power Mask */
#define SMEANC_Val(value)                          (SMEANC_Msk & (_UINT16_(value) << SMEANC_Pos))

/* -------- Measurement Total Power Factor : (POWERF Offset: 0xBCH) (R - 16 bits) - ATM90E36 Measurement Total Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANT_Pos                               _UINT16_(0)                                  /* (PFMEANT) Total Power Factor Position */
#define PFMEANT_Msk                               (_UINT16_(0xFFFF) << PFMEANT_Pos)            /* (PFMEANT) Total Power Factor Factor Mask */
#define PFMEANT_Val(value)                        (PFMEANT_Msk & (_UINT16_(value) << PFMEANT_Pos))

/* -------- Measurement Phase A Power Factor : (POWERF Offset: 0xBDH) (R - 16 bits) - ATM90E36 Measurement Phase A Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANA_Pos                               _UINT16_(0)                                 /* (PFMEANA) Phase A Power Factor Position */
#define PFMEANA_Msk                               (_UINT16_(0xFFFF) << PFMEANA_Pos)           /* (PFMEANA) Phase A Power Factor Factor Mask */
#define PFMEANA_Val(value)                        (PFMEANA_Msk & (_UINT16_(value) << PFMEANA_Pos))

/* -------- Measurement Phase B Power Factor : (POWERF Offset: 0xBEH) (R - 16 bits) - ATM90E36 Measurement Phase B Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANB_Pos                               _UINT16_(0)                                 /* (PFMEANB) Phase B Power Factor Position */
#define PFMEANB_Msk                               (_UINT16_(0xFFFF) << PFMEANB_Pos)           /* (PFMEANB) Phase B Power Factor Factor Mask */
#define PFMEANB_Val(value)                        (PFMEANB_Msk & (_UINT16_(value) << PFMEANB_Pos))

/* -------- Measurement Phase A Power Factor : (POWERF Offset: 0xBFH) (R - 16 bits) - ATM90E36 Measurement Phase C Power Factor -------- */
/* -------- Note: Signed with complement format, X.XXX LSB is 0.001. Range from -1000 to +1000 */
#define PFMEANC_Pos                               _UINT16_(0)                                 /* (PFMEANC) Phase C Power Factor Position */
#define PFMEANC_Msk                               (_UINT16_(0xFFFF) << PFMEANC_Pos)           /* (PFMEANC) Phase C Power Factor Factor Mask */
#define PFMEANC_Val(value)                        (PFMEANC_Msk & (_UINT16_(value) << PFMEANC_Pos))

/* -------- Measurement Total (All phase sum) Active Power LSB : (PMEAN Offset: 0xC0H) (R - 16 bits) - ATM90E36 Total (All-phase-sum) Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTLSB_Pos                           _UINT16_(0)                                   /* (PMEANTLSB) Total (All-phase-sum) Active Power Position */
#define PMEANTLSB_Msk                           (_UINT16_(0xFFFF) << PMEANTLSB_Pos)           /* (PMEANTLSB) Total (All-phase-sum) Active Power Mask */
#define PMEANTLSB_Val(value)                    (PMEANTLSB_Msk & (_UINT16_(value) << PMEANTLSB_Pos))

/* -------- Measurement Phase A Active Power LSB: (PMEANA Offset: 0xC1H) (R - 16 bits) - ATM90E36 Phase A Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANALSB_Pos                           _UINT16_(0)                                   /* (PMEANALSB) Phase A Active Power Position */
#define PMEANALSB_Msk                           (_UINT16_(0xFFFF) << PMEANALSB_Pos)           /* (PMEANALSB) Phase A Active Power Mask */
#define PMEANALSB_Val(value)                    (PMEANALSB_Msk & (_UINT16_(value) << PMEANALSB_Pos))

/* -------- Measurement Phase B Active Power LSB: (PMEANB Offset: 0xC2H) (R - 16 bits) - ATM90E36 Phase B Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBLSB_Pos                           _UINT16_(0)                                   /* (PMEANB) Phase B Active Power Position */
#define PMEANBLSB_Msk                           (_UINT16_(0xFFFF) << PMEANBLSB_Pos)           /* (PMEANB) Phase B Active Power Mask */
#define PMEANBLSB_Val(value)                    (PMEANBLSB_Msk & (_UINT16_(value) << PMEANBLSB_Pos))

/* -------- Measurement Phase C Active Power LSB : (PMEAN Offset: 0xC3H) (R - 16 bits) - ATM90E36 Phase C Active Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCLSB_Pos                           _UINT16_(0)                                   /* (PMEANC) Phase C Active Power Position */
#define PMEANCLSB_Msk                           (_UINT16_(0xFFFF) << PMEANCLSB_Pos)           /* (PMEANC) Phase C Active Power Mask */
#define PMEANCLSB_Val(value)                    (PMEANCLSB_Msk & (_UINT16_(value) << PMEANCLSB_Pos))

/* -------- Measurement Total (All-phase-sum) Reactive Power LSB: (QMEAN Offset: 0xC4H) (R - 16 bits) - ATM90E36 Measurement Total (All-phase-sum) Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANTLSB_Pos                           _UINT16_(0)                                   /* (QMEANT) Total (All-phase-sum) Reactive Power Position */
#define QMEANTLSB_Msk                           (_UINT16_(0xFFFF) << QMEANTLSB_Pos)           /* (QMEANT) Total (All-phase-sum) Reactive Power Mask */
#define QMEANTLSB_Val(value)                    (QMEANTLSB_Msk & (_UINT16_(value) << QMEANTLSB_Pos))

/* -------- Measurement Phase A Reactive Power LSB: (QMEAN Offset: 0xC5H) (R - 16 bits) - ATM90E36 Measurement Phase A Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANALSB_Pos                           _UINT16_(0)                                   /* (QMEANT) Phase A Reactive Power Position */
#define QMEANALSB_Msk                           (_UINT16_(0xFFFF) << QMEANALSB_Pos)           /* (QMEANT) Phase A Reactive Power Mask */
#define QMEANALSB_Val(value)                    (QMEANALSB_Msk & (_UINT16_(value) << QMEANALSB_Pos))

/* -------- Measurement Phase B Reactive Power LSB: (QMEANB Offset: 0xC6H) (R - 16 bits) - ATM90E36 Measurement Phase B Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANBLSB_Pos                           _UINT16_(0)                                   /* (QMEANB) Phase B Reactive Power Position */
#define QMEANBLSB_Msk                           (_UINT16_(0xFFFF) << QMEANBLSB_Pos)           /* (QMEANB) Phase B Reactive Power Mask */
#define QMEANBLSB_Val(value)                    (QMEANBLSB_Msk & (_UINT16_(value) << QMEANBLSB_Pos))

/* -------- Measurement Phase C Reactive Power LSB: (QMEANC Offset: 0xC7H) (R - 16 bits) - ATM90E36 Measurement Phase C Reactive Power LSB -------- */
/* -------- Note: Data format is Complement - Range [-32768,32768) kvar */
#define QMEANCLSB_Pos                           _UINT16_(0)                                   /* (QMEANC) Phase C Reactive Power Position */
#define QMEANCLSB_Msk                           (_UINT16_(0xFFFF) << QMEANCLSB_Pos)           /* (QMEANC) Phase C Reactive Power Mask */
#define QMEANCLSB_Val(value)                    (QMEANCLSB_Msk & (_UINT16_(value) << QMEANCLSB_Pos))

/* -------- Measurement Total (All-phase-sum) Apparent Power LSB: (SMEANT Offset: 0xC8H) (R - 16 bits) - ATM90E36 Measurement Total (All-phase-sum) Apparent Power LSB -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SAMEANTLSB_Pos                          _UINT16_(0)                                   /* (SAMEANT) Total (All-phase-sum) Apparent Power Position */
#define SAMEANTLSB_Msk                          (_UINT16_(0xFFFF) << SAMEANTLSB_Pos)          /* (SAMEANT) Total (All-phase-sum) Apparent Power Mask */
#define SAMEANTLSB_Val(value)                   (SAMEANTLSB_Msk & (_UINT16_(value) << SAMEANTLSB_Pos))

/* -------- Measurement Phase A Apparent Power : (SMEANA Offset: 0xC9H) (R - 16 bits) - ATM90E36 Measurement Phase A Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANALSB_Pos                           _UINT16_(0)                                   /* (SMEANT) Phase A Apparent Power Position */
#define SMEANALSB_Msk                           (_UINT16_(0xFFFF) << SMEANALSB_Pos)           /* (SMEANT) Phase A Apparent Power Mask */
#define SMEANALSB_Val(value)                    (SMEANALSB_Msk & (_UINT16_(value) << SMEANALSB_Pos))

/* -------- Measurement Phase B Apparent Power : (SMEANB Offset: 0xCAH) (R - 16 bits) - ATM90E36 Measurement Phase B Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANBLSB_Pos                           _UINT16_(0)                                   /* (SMEANB) Phase B Apparent Power Position */
#define SMEANBLSB_Msk                           (_UINT16_(0xFFFF) << SMEANB_Pos)              /* (SMEANB) Phase B Apparent Power Mask */
#define SMEANBLSB_Val(value)                    (SMEANB_Msk & (_UINT16_(value) << SMEANB_Pos))

/* -------- Measurement Phase C Apparent Power : (SMEANC Offset: 0xCBH) (R - 16 bits) - ATM90E36 Measurement Phase C Apparent Power -------- */
/* -------- Note: Data format is Complement - Range [0,32767) kVA */
#define SMEANCLSB_Pos                           _UINT16_(0)                                   /* (SMEANC) Phase C Apparent Power Position */
#define SMEANCLSB_Msk                           (_UINT16_(0xFFFF) << SMEANCLSB_Pos)           /* (SMEANC) Phase C Apparent Power Mask */
#define SMEANCLSB_Val(value)                    (SMEANCLSB_Msk & (_UINT16_(value) << SMEANCLSB_Pos))

#define PMEAN_DEFAULT_Val                       _UINT16_(0)
#define QMEAN_DEFAULT_Val                       _UINT16_(0)
#define SMEAN_DEFAULT_Val                       _UINT16_(0)

/* ************************************************************************** */
/*   FUNDAMENTAL/ HARMONIC POWER AND VOLTAGE/ CURRENT RMS REGISTERS           */
/* ************************************************************************** */
/* -------- Measurement Total (All phase sum) Active Fundamental Power : (PMEAN Offset: 0xD0H) (R - 16 bits) - ATM90E36 Total (All-phase-sum) Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTF_Pos                            _UINT16_(0)                                 /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Position */
#define PMEANTF_Msk                            (_UINT16_(0xFFFF) << PMEANTF_Pos)           /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Mask */
#define PMEANTF_Val(value)                     (PMEANTF_Msk & (_UINT16_(value) << PMEANTF_Pos))

/* -------- Measurement Phase A Active Fundamental Power : (PMEANA Offset: 0xD1H) (R - 16 bits) - ATM90E36 Phase A Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAF_Pos                            _UINT16_(0)                                 /* (PMEANAF) Phase A Active Power Fundamental Position */
#define PMEANAF_Msk                            (_UINT16_(0xFFFF) << PMEANAF_Pos)           /* (PMEANAF) Phase A Active Power Fundamental Mask */
#define PMEANAF_Val(value)                     (PMEANAF_Msk & (_UINT16_(value) << PMEANAF_Pos))

/* -------- Measurement Phase B Active Fundamental Power : (PMEANB Offset: 0xD2H) (R - 16 bits) - ATM90E36 Phase B Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBF_Pos                            _UINT16_(0)                                 /* (PMEANBF) Phase B Active Power Fundamental Position */
#define PMEANBF_Msk                            (_UINT16_(0xFFFF) << PMEANBF_Pos)           /* (PMEANBF) Phase B Active Power Fundamental Mask */
#define PMEANBF_Val(value)                     (PMEANB_Msk & (_UINT16_(value) << PMEANBF_Pos))

/* -------- Measurement Phase C Active Fundamental Power : (PMEAN Offset: 0xD3H) (R - 16 bits) - ATM90E36 Phase C Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCF_Pos                            _UINT16_(0)                                 /* (PMEANCF) Phase C Active Power Fundamental Position */
#define PMEANCF_Msk                            (_UINT16_(0xFFFF) << PMEANC_Pos)            /* (PMEANCF) Phase C Active Power Fundamental Mask */
#define PMEANCF_Val(value)                     (PMEANCF_Msk & (_UINT16_(value) << PMEANCF_Pos))

/* -------- Measurement Total (All phase sum) Active Harmonic Power : (PMEAN Offset: 0xD4H) (R - 16 bits) - ATM90E36 Total (All-phase-sum) Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTH_Pos                            _UINT16_(0)                                 /* (PMEANT) Total (All-phase-sum) Active Harmonic Power Position */
#define PMEANTH_Msk                            (_UINT16_(0xFFFF) << PMEANTH_Pos)           /* (PMEANT) Total (All-phase-sum) Active Harmonic Power Mask */
#define PMEANTH_Val(value)                     (PMEANTH_Msk & (_UINT16_(value) << PMEANTH_Pos))

/* -------- Measurement Phase A Active Harmonic Power : (PMEANA Offset: 0xD5H) (R - 16 bits) - ATM90E36 Phase A Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAH_Pos                            _UINT16_(0)                                 /* (PMEANAH) Phase A Active Power Harmonic Position */
#define PMEANAH_Msk                            (_UINT16_(0xFFFF) << PMEANAH_Pos)           /* (PMEANAH) Phase A Active Power Harmonic Mask */
#define PMEANAH_Val(value)                     (PMEANAH_Msk & (_UINT16_(value) << PMEANAH_Pos))

/* -------- Measurement Phase B Active Harmonic Power : (PMEANB Offset: 0xD6H) (R - 16 bits) - ATM90E36 Phase B Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBH_Pos                            _UINT16_(0)                                 /* (PMEANBH) Phase B Active Power Harmonic Position */
#define PMEANBH_Msk                            (_UINT16_(0xFFFF) << PMEANBH_Pos)           /* (PMEANBH) Phase B Active Power Harmonic Mask */
#define PMEANBH_Val(value)                     (PMEANBH_Msk & (_UINT16_(value) << PMEANBH_Pos))

/* -------- Measurement Phase C Active Harmonic Power : (PMEAN Offset: 0xD7H) (R - 16 bits) - ATM90E36 Phase C Active Harmonic Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCH_Pos                            _UINT16_(0)                                 /* (PMEANCH) Phase C Active Power Harmonic Position */
#define PMEANCH_Msk                            (_UINT16_(0xFFFF) << PMEANCH_Pos)           /* (PMEANCH) Phase C Active Power Harmonic Mask */
#define PMEANCH_Val(value)                     (PMEANCF_Msk & (_UINT16_(value) << PMEANCFH_Pos))

/* -------- Measurement Phase N Measured Current RMS : (IRMS Offset: 0xD8H) (R - 16 bits) - ATM90E36 Measurement Phase N Measured Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSNM_Pos                             _UINT16_(0)                              /* (IRMSNM) Phase N Measured Current RMS Value Position */
#define IRMSNM_Msk                             (_UINT16_(0xFFFF) << IRMSNM_Pos)         /* (IRMSNM) Phase N Measured Current RMS Value Mask */
#define IRMSNM_Val(value)                      (IRMSNM_Msk & (_UINT16_(value) << IRMSNM_Pos))

/* -------- Measurement Phase A Voltage RMS : (URMS Offset: 0xD9H) (R - 16 bits) - ATM90E36 Measurement Phase A Voltage RMS -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSA_Pos                              _UINT16_(0)                              /* (URMSA) Phase A Voltage RMS Value Position */
#define URMSA_Msk                              (_UINT16_(0xFFFF) << URMSA_Pos)          /* (URMSA) Phase A Voltage RMS Value Mask */
#define URMSA_Val(value)                       (URMSA_Msk & (_UINT16_(value) << URMSA_Pos))

/* -------- Measurement Phase B Voltage RMS : (URMS Offset: 0xDAH) (R - 16 bits) - ATM90E36 Measurement Phase B Voltage RMS -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSB_Pos                              _UINT16_(0)                              /* (URMSB) Phase B Voltage RMS Value Position */
#define URMSB_Msk                              (_UINT16_(0xFFFF) << URMSB_Pos)          /* (URMSB) Phase B Voltage RMS Value Mask */
#define URMSB_Val(value)                       (URMSB_Msk & (_UINT16_(value) << URMSB_Pos))

/* -------- Measurement Phase C Voltage RMS : (URMS Offset: 0xDBH) (R - 16 bits) - ATM90E36 Measurement Phase C Voltage RMS -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSC_Pos                              _UINT16_(0)                              /* (URMSC) Phase C Voltage RMS Value Position */
#define URMSC_Msk                              (_UINT16_(0xFFFF) << URMSC_Pos)          /* (URMSC) Phase C Voltage RMS Value Mask */
#define URMSC_Val(value)                       (URMSC_Msk & (_UINT16_(value) << URMSC_Pos))

/* -------- Measurement Phase N Calculated Current RMS : (IRMS Offset: 0xDCH) (R - 16 bits) - ATM90E36 Measurement Phase N Calculated Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSN_Pos                              _UINT16_(0)                              /* (IRMSN) Phase N Calculated Current RMS Value Position */
#define IRMSN_Msk                              (_UINT16_(0xFFFF) << IRMSN_Pos)          /* (IRMSN) Phase N Calculated Current RMS Value Mask */
#define IRMSN_Val(value)                       (IRMSN_Msk & (_UINT16_(value) << IRMSN_Pos))

/* -------- Measurement Phase A Current RMS : (IRMS Offset: 0xDDH) (R - 16 bits) - ATM90E36 Measurement Phase A Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSA_Pos                              _UINT16_(0)                              /* (IRMSA) Phase A Current RMS Value Position */
#define IRMSA_Msk                              (_UINT16_(0xFFFF) << IRMSA_Pos)          /* (IRMSA) Phase A Current RMS Value Mask */
#define IRMSA_Val(value)                       (IRMSA_Msk & (_UINT16_(value) << IRMSA_Pos))

/* -------- Measurement Phase B Current RMS : (IRMS Offset: 0xDEH) (R - 16 bits) - ATM90E36 Measurement Phase B Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSB_Pos                              _UINT16_(0)                              /* (IRMSB) Phase B Current RMS Value Position */
#define IRMSB_Msk                              (_UINT16_(0xFFFF) << IRMSB_Pos)          /* (IRMSB) Phase B Current RMS Value Mask */
#define IRMSB_Val(value)                       (IRMSB_Msk & (_UINT16_(value) << IRMSB_Pos))

/* -------- Measurement Phase C Current RMS : (IRMS Offset: 0xDFH) (R - 16 bits) - ATM90E36 Measurement Phase C Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSC_Pos                              _UINT16_(0)                              /* (IRMSC) Phase C Current RMS Value Position */
#define IRMSC_Msk                              (_UINT16_(0xFFFF) << IRMSC_Pos)          /* (IRMSC) Phase C Current RMS Value Mask */
#define IRMSC__Val(value)                      (IRMSC_Msk & (_UINT16_(value) << IRMSC_Pos))

/* -------- Measurement Total (All phase sum) Active Fundamental Power LSB : (PMEAN Offset: 0xE0H) (R - 16 bits) - ATM90E36 Total (All-phase-sum) Active Fundamental Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTFLSB_Pos                         _UINT16_(0)                                   /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Position */
#define PMEANTFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANTFLSB_Pos)          /* (PMEANT) Total (All-phase-sum) Active Fundamental Power Mask */
#define PMEANTFLSB_Val(value)                  (PMEANTFLSB_Msk & (_UINT16_(value) << PMEANTFLSB_Pos))

/* -------- Measurement Phase A Active Fundamental Power : (PMEANA Offset: 0xE1H) (R - 16 bits) - ATM90E36 Phase A Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAFLSB_Pos                         _UINT16_(0)                                   /* (PMEANAF) Phase A Active Power Fundamental Position */
#define PMEANAFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANAFLSB_Pos)          /* (PMEANAF) Phase A Active Power Fundamental Mask */
#define PMEANAFLSB_Val(value)                  (PMEANAFLSB_Msk & (_UINT16_(value) << PMEANAFLSB_Pos))

/* -------- Measurement Phase B Active Fundamental Power : (PMEANB Offset: 0xE2H) (R - 16 bits) - ATM90E36 Phase B Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBFLSB_Pos                         _UINT16_(0)                                   /* (PMEANBF) Phase B Active Power Fundamental Position */
#define PMEANBFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANBFLSB_Pos)          /* (PMEANBF) Phase B Active Power Fundamental Mask */
#define PMEANBFLSB_Val(value)                  (PMEANBFLSB_Msk & (_UINT16_(value) << PMEANBFLSB_Pos))

/* -------- Measurement Phase C Active Fundamental Power : (PMEAN Offset: 0xE3H) (R - 16 bits) - ATM90E36 Phase C Active Fundamental Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCFLSB_Pos                         _UINT16_(0)                                   /* (PMEANCF) Phase C Active Power Fundamental Position */
#define PMEANCFLSB_Msk                         (_UINT16_(0xFFFF) << PMEANCFLSB_Pos)          /* (PMEANCF) Phase C Active Power Fundamental Mask */
#define PMEANCFLSB_Val(value)                  (PMEANCFLSB_Msk & (_UINT16_(value) << PMEANCFLSB_Pos))

/* -------- Measurement Total (All phase sum) Active Harmonics Power LSB : (PMEAN Offset: 0xE4H) (R - 16 bits) - ATM90E36 Total (All-phase-sum) Active Harmonics Power LSB -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANTHLSB_Pos                         _UINT16_(0)                                   /* (PMEANTH) Total (All-phase-sum) Active Harmonics Power Position */
#define PMEANTHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANTHLSB_Pos)          /* (PMEANTH) Total (All-phase-sum) Active Harmonics Power Mask */
#define PMEANTHLSB_Val(value)                  (PMEANTHLSB_Msk & (_UINT16_(value) << PMEANTHLSB_Pos))

/* -------- Measurement Phase A Active Harmonics Power : (PMEANA Offset: 0xE5H) (R - 16 bits) - ATM90E36 Phase A Active Harmonics Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANAHLSB_Pos                         _UINT16_(0)                                   /* (PMEANAH) Phase A Active Power Harmonics Position */
#define PMEANAHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANAHLSB_Pos)          /* (PMEANAH) Phase A Active Power Harmonics Mask */
#define PMEANAHLSB_Val(value)                  (PMEANAHLSB_Msk & (_UINT16_(value) << PMEANAHLSB_Pos))

/* -------- Measurement Phase B Active Harmonics Power : (PMEANB Offset: 0xE6H) (R - 16 bits) - ATM90E36 Phase B Active Harmonics Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANBHLSB_Pos                         _UINT16_(0)                                   /* (PMEANBH) Phase B Active Power Harmonics Position */
#define PMEANBHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANBHLSB_Pos)          /* (PMEANBH) Phase B Active Power Harmonics Mask */
#define PMEANBHLSB_Val(value)                  (PMEANBHLSB_Msk & (_UINT16_(value) << PMEANBHLSB_Pos))

/* -------- Measurement Phase C Active Harmonics Power : (PMEAN Offset: 0xE7H) (R - 16 bits) - ATM90E36 Phase C Active Harmonics Power -------- */
/* -------- Note: Complement, Power=32-bit register value* 0.00032 W */
#define PMEANCHLSB_Pos                         _UINT16_(0)                                   /* (PMEANCH) Phase C Active Power Harmonics Position */
#define PMEANCHLSB_Msk                         (_UINT16_(0xFFFF) << PMEANHCLSB_Pos)          /* (PMEANCH) Phase C Active Power Harmonics Mask */
#define PMEANCHLSB_Val(value)                  (PMEANCHLSB_Msk & (_UINT16_(value) << PMEANCHLSB_Pos))

/* -------- Measurement Phase A Voltage RMS LSB: (URMS Offset: 0xE9H) (R - 16 bits) - ATM90E36 Measurement Phase A Voltage RMS LSB-------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSALSB_Pos                           _UINT16_(0)                                   /* (URMSA) Phase A Voltage RMS Value Position */
#define URMSALSB_Msk                           (_UINT16_(0xFFFF) << URMSALSB_Pos)            /* (URMSA) Phase A Voltage RMS Value Mask */
#define URMSALSB_Val(value)                    (URMSALSB_Msk & (_UINT16_(value) << URMSALSB_Pos))

/* -------- Measurement Phase B Voltage RMS LSB: (URMS Offset: 0xEAH) (R - 16 bits) - ATM90E36 Measurement Phase B Voltage RMS LSB-------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSBLSB_Pos                           _UINT16_(0)                                   /* (URMSB) Phase B Voltage RMS Value Position */
#define URMSBLSB_Msk                           (_UINT16_(0xFFFF) << URMSBLSB_Pos)            /* (URMSB) Phase B Voltage RMS Value Mask */
#define URMSBLSB_Val(value)                    (URMSBLSB_Msk & (_UINT16_(value) << URMSBLSB_Pos))

/* -------- Measurement Phase C Voltage RMS LSB: (URMS Offset: 0xEBH) (R - 16 bits) - ATM90E36 Measurement Phase C Voltage RMS LSB -------- */
/* -------- Note: Unsigned 16-bit integer with unit of 0.01V. 1LSB corresponds to 0.01 V */
#define URMSCLSB_Pos                           _UINT16_(0)                                   /* (URMSC) Phase C Voltage RMS Value Position */
#define URMSCLSB_Msk                           (_UINT16_(0xFFFF) << URMSCLSB_Pos)            /* (URMSC) Phase C Voltage RMS Value Mask */
#define URMSCLSB_Val(value)                    (URMSCLSB_Msk & (_UINT16_(value) << URMSCLSB_Pos))

/* -------- Measurement Phase A Current RMS : (IRMS Offset: 0xEDH) (R - 16 bits) - ATM90E36 Measurement Phase A Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSALSB_Pos                           _UINT16_(0)                                   /* (IRMSA) Phase A Current RMS Value Position */
#define IRMSALSB_Msk                           (_UINT16_(0xFFFF) << IRMSALSB_Pos)            /* (IRMSA) Phase A Current RMS Value Mask */
#define IRMSALSB_Val(value)                    (IRMSALSB_Msk & (_UINT16_(value) << IRMSALSB_Pos))

/* -------- Measurement Phase B Current RMS : (IRMS Offset: 0xEEH) (R - 16 bits) - ATM90E36 Measurement Phase B Current RMS -------- */
/* -------- Note: Data format is XX.XXX - Range (0-65.535) */
#define IRMSBLSB_Pos                           _UINT16_(0)                                   /* (IRMSB) Phase B Current RMS Value Position */
#define IRMSBLSB_Msk                           (_UINT16_(0xFFFF) << IRMSBLSB_Pos)            /* (IRMSB) Phase B Current RMS Value Mask */
#define IRMSBLSB_Val(value)                    (IRMSBLSB_Msk & (_UINT16_(value) << IRMSBLSB_Pos))

/* -------- Measurement Phase C Current RMS : (IRMS Offset: 0xEFH) (R - 16 bits) - ATM90E36 Measurement Phase C Current RMS -------- */
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
/* -------- phase A voltage THD+N : (THDNUA Offset: 0xF1H) (R - 16 bits) - ATM90E36 phase A voltage THD+N -------- */
/* -------- Note: Data format - 1LSB corresponds to 0.01% */
#define THDNUA_Pos                                _UINT16_(0)                              /* (THDNUA) phase A voltage THD+N Position */
#define THDNUA_Msk                                (_UINT16_(0xFFFF) << THDNUA_Pos)         /* (THDNUA) phase A voltage THD+N Mask */
#define THDNUA_Val(value)                         (THDNUA_Msk & (_UINT16_(value) << THDNUA_Pos))
#define THDNUA_DEFAULT_Val                        _UINT16_(0)

/* -------- phase B voltage THD+N : (THDNUB Offset: 0xF1H) (R - 16 bits) - ATM90E36 phase A voltage THD+N -------- */
/* -------- Note: Data format - 1LSB corresponds to 0.01% */
#define THDNUB_Pos                                _UINT16_(0)                              /* (THDNUB) phase B voltage THD+N Position */
#define THDNUB_Msk                                (_UINT16_(0xFFFF) << THDNUB_Pos)         /* (THDNUB) phase B voltage THD+N Mask */
#define THDNUB_Val(value)                         (THDNUB_Msk & (_UINT16_(value) << THDNUB_Pos))
#define THDNUB_DEFAULT_Val                        _UINT16_(0)

/* -------- phase C voltage THD+N : (THDNUC Offset: 0xF1H) (R - 16 bits) - ATM90E36 phase C voltage THD+N -------- */
/* -------- Note: Data format - 1LSB corresponds to 0.01% */
#define THDNUC_Pos                                _UINT16_(0)                              /* (THDNUC) phase C voltage THD+N Position */
#define THDNUC_Msk                                (_UINT16_(0xFFFF) << THDNUC_Pos)         /* (THDNUC) phase C voltage THD+N Mask */
#define THDNUC_Val(value)                         (THDNUC_Msk & (_UINT16_(value) << THDNUC_Pos))
#define THDNUC_DEFAULT_Val                        _UINT16_(0)

/* -------- phase A current THD+N : (THDNIA Offset: 0xF1H) (R - 16 bits) - ATM90E36 phase A current THD+N -------- */
/* -------- Note: Data format - 1LSB corresponds to 0.01% */
#define THDNIA_Pos                                _UINT16_(0)                              /* (THDNIA) phase A current THD+N Position */
#define THDNIA_Msk                                (_UINT16_(0xFFFF) << THDNIA_Pos)         /* (THDNIA) phase A current THD+N Mask */
#define THDNIA_Val(value)                         (THDNIA_Msk & (_UINT16_(value) << THDNIA_Pos))
#define THDNIA_DEFAULT_Val                        _UINT16_(0)

/* -------- phase B current THD+N : (THDNIB Offset: 0xF1H) (R - 16 bits) - ATM90E36 phase A current THD+N -------- */
/* -------- Note: Data format - 1LSB corresponds to 0.01% */
#define THDNIB_Pos                                _UINT16_(0)                              /* (THDNIB) phase B current THD+N Position */
#define THDNIB_Msk                                (_UINT16_(0xFFFF) << THDNIB_Pos)         /* (THDNIB) phase B current THD+N Mask */
#define THDNIB_Val(value)                         (THDNIB_Msk & (_UINT16_(value) << THDNIB_Pos))
#define THDNIB_DEFAULT_Val                        _UINT16_(0)

/* -------- phase C current THD+N : (THDNIC Offset: 0xF1H) (R - 16 bits) - ATM90E36 phase C current THD+N -------- */
/* -------- Note: Data format - 1LSB corresponds to 0.01% */
#define THDNIC_Pos                                _UINT16_(0)                              /* (THDNIC) phase C current THD+N Position */
#define THDNIC_Msk                                (_UINT16_(0xFFFF) << THDNIC_Pos)         /* (THDNIC) phase C current THD+N Mask */
#define THDNIC_Val(value)                         (THDNIC_Msk & (_UINT16_(value) << THDNIC_Pos))
#define THDNIC_DEFAULT_Val                        _UINT16_(0)

/* -------- Measurement Frequency : (FREQ Offset: 0xF8H) (R - 16 bits) - ATM90E36 Measurement Frequency -------- */
/* -------- Note: Data format - Range [45,65] Hz */
#define FREQ_Pos                                _UINT16_(0)                                /* (FREQ) Frequency Position */
#define FREQ_Msk                                (_UINT16_(0xFFFF) << FREQ_Pos)             /* (FREQ) Frequency Mask */
#define FREQ_Val(value)                         (FREQ_Msk & (_UINT16_(value) << FREQ_Pos))
#define FREQ_DEFAULT_Val                        _UINT16_(0)

/* -------- Measurement Phase A Angle between Voltage and L Line Current : (PANGLEA Offset: 0xF9H) (R - 16 bits) - ATM90E36 Measurement Phase A Angle -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define PANGLEA_Pos                             _UINT16_(0)                                /* (PANGLEA) Phase A Angle between Voltage and L Line Current Position */
#define PANGLEA_Msk                             (_UINT16_(0xFFFF) << PANGLEA_Pos)          /* (PANGLEA) Phase A Angle between Voltage and L Line Current Mask */
#define PANGLEA_Val(value)                      (PANGLEA_Msk & (_UINT16_(value) << PANGLEA_Pos))

/* -------- Measurement Phase B Angle between Voltage and L Line Current : (PANGLEB Offset: 0xFAH) (R - 16 bits) - ATM90E36 Measurement Phase B Angle -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define PANGLEB_Pos                             _UINT16_(0)                                /* (PANGLEB) Phase B Angle between Voltage and L Line Current Position */
#define PANGLEB_Msk                             (_UINT16_(0xFFFF) << PANGLEB_Pos)          /* (PANGLEB) Phase B Angle between Voltage and L Line Current Mask */
#define PANGLEB_Val(value)                      (PANGLEB_Msk & (_UINT16_(value) << PANGLEB_Pos))

/* -------- Measurement Phase C Angle between Voltage and L Line Current : (PANGLEC Offset: 0xFBH) (R - 16 bits) - ATM90E36 Measurement Phase C Angle -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define PANGLEC_Pos                             _UINT16_(0)                                /* (PANGLEC) Phase C Angle between Voltage and L Line Current Position */
#define PANGLEC_Msk                             (_UINT16_(0xFFFF) << PANGLEC_Pos)          /* (PANGLEC) Phase c Angle between Voltage and L Line Current Mask */
#define PANGLEC_Val(value)                      (PANGLEC_Msk & (_UINT16_(value) << PANGLEC_Pos))

/* -------- Measurement Temperature  : (TEMP Offset: 0xFCH) (R - 16 bits) - ATM90E36 Measured Temperature  -------- */
/* -------- Note: 1LSB corresponds to 1 °C - Signed, MSB as the sign bit */
#define TEMP_Pos                                _UINT16_(0)                             /* (TEMP) Measured Temperature  Position */
#define TEMP_Msk                                (_UINT16_(0xFFFF) << TEMP_Pos)          /* (TEMP) Measured Temperature  Mask */
#define TEMP_Val(value)                         (TEMP_Msk & (_UINT16_(value) << TEMP_Pos))
#define TEMP_DEFAULT_Val                        _UINT16_(0)

/* -------- Measurement Angle between Phase A and Phase A Voltage : (UANGLEA Offset: 0xFDH) (R - 16 bits) - ATM90E36 Measurement Angle between Phase A and Phase A Voltage -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0°. Always 0 */
#define UANGLEA_Pos                             _UINT16_(0)                                /* (UANGLEA) Angle between Phase A and Phase A Voltage Position */
#define UANGLEA_Msk                             (_UINT16_(0xFFFF) << UANGLEA_Pos)          /* (UANGLEA) Angle between Phase A and Phase A Voltage Mask */
#define UANGLEA_Val(value)                      (UANGLEA_Msk & (_UINT16_(value) << UANGLEA_Pos))
/* -------- Measurement Angle between Phase A and Phase B Voltage : (UANGLEB Offset: 0xFEH) (R - 16 bits) - ATM90E36 Measurement Angle between Phase A and Phase B Voltage -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define UANGLEB_Pos                             _UINT16_(0)                                /* (UANGLEB) Angle between Phase A and Phase B Voltage Position */
#define UANGLEB_Msk                             (_UINT16_(0xFFFF) << UANGLEB_Pos)          /* (UANGLEB) Angle between Phase A and Phase B Voltage Mask */
#define UANGLEB_Val(value)                      (UANGLEB_Msk & (_UINT16_(value) << UANGLEB_Pos))

/* -------- Measurement Angle between Phase A and Phase C Voltage : (UANGLEC Offset: 0xFFH) (R - 16 bits) - ATM90E36 Measurement Angle between Phase A and Phase C Voltage -------- */
/* -------- Note: Unsigned, 1LSB corresponds to 0.1 degree, 0°~+360.0° */
#define UANGLEC_Pos                             _UINT16_(0)                                /* (UANGLEC) Angle between Phase A and Phase C Voltage Position */
#define UANGLEC_Msk                             (_UINT16_(0xFFFF) << UANGLEC_Pos)          /* (UANGLEC) Angle between Phase A and Phase C Voltage Mask */
#define UANGLEC_Val(value)                      (UANGLEC_Msk & (_UINT16_(value) << UANGLEC_Pos))

#define THDNU_DEFAULT_Val                       _UINT16_(0) 
#define THDNI_DEFAULT_Val                       _UINT16_(0) 
#define ANGLE_DEFAULT_Val                       _UINT16_(0) 

/* ************************************************************************** */
/*   HARMONIC FOURIER ANALYSIS REGISTERS                                      */
/* ************************************************************************** */
/* -------- DFT Scale : (DFT_CTRL Offset: 0x1D1H) (R - 16 bits) - ATM90E36 DFT Controller -------- */
#define DFT_SCALE_AI_Pos                        _UINT16_(0)                                  /* (DFT_SCALE_AI) DFT Scale AI */
#define DFT_SCALE_AI_Msk                        (_UINT16_(0x7) << DFT_SCALE_AI_Pos)          /* (DFT_SCALE_AI) DFT Scale AI */
#define DFT_SCALE_AI_Val(value)                 (DFT_SCALE_AI_Msk & (_UINT16_(value) << DFT_SCALE_AI_Pos))
#define DFT_SCALE_BI_Pos                        _UINT16_(3)                                  /* (DFT_SCALE_BI) DFT Scale BI */
#define DFT_SCALE_BI_Msk                        (_UINT16_(0x7) << DFT_SCALE_BI_Pos)          /* (DFT_SCALE_BI) DFT Scale BI */
#define DFT_SCALE_BI_Val(value)                 (DFT_SCALE_BI_Msk & (_UINT16_(value) << DFT_SCALE_BI_Pos))
#define DFT_SCALE_CI_Pos                        _UINT16_(6)                                  /* (DFT_SCALE_CI) DFT Scale CI */
#define DFT_SCALE_CI_Msk                        (_UINT16_(0x7) << DFT_SCALE_CI_Pos)          /* (DFT_SCALE_CI) DFT Scale CI */
#define DFT_SCALE_CI_Val(value)                 (DFT_SCALE_CI_Msk & (_UINT16_(value) << DFT_SCALE_CI_Pos))
#define DFT_SCALE_AV_Pos                        _UINT16_(9)                                  /* (DFT_SCALE_AV) DFT Scale AV */
#define DFT_SCALE_AV_Msk                        (_UINT16_(0x7) << DFT_SCALE_AV_Pos)          /* (DFT_SCALE_AV) DFT Scale AV */
#define DFT_SCALE_AV_Val(value)                 (DFT_SCALE_AV_Msk & (_UINT16_(value) << DFT_SCALE_AV_Pos))
#define DFT_SCALE_BV_Pos                        _UINT16_(11)                                 /* (DFT_SCALE_BV) DFT Scale BV */
#define DFT_SCALE_BV_Msk                        (_UINT16_(0x7) << DFT_SCALE_BV_Pos)          /* (DFT_SCALE_BV) DFT Scale BV */
#define DFT_SCALE_BV_Val(value)                 (DFT_SCALE_BV_Msk & (_UINT16_(value) << DFT_SCALE_BV_Pos))
#define DFT_SCALE_CV_Pos                        _UINT16_(13)                                 /* (DFT_SCALE_CV) DFT Scale CV */
#define DFT_SCALE_CV_Msk                        (_UINT16_(0x7) << DFT_SCALE_CV_Pos)          /* (DFT_SCALE_CV) DFT Scale CV */
#define DFT_SCALE_CV_Val(value)                 (DFT_SCALE_CV_Msk & (_UINT16_(value) << DFT_SCALE_CV_Pos))
#define DFT_SCALE_HW_Pos                        _UINT16_(15)                                 /* (DFT_SCALE_HW) DFT Hanning Window */
#define DFT_SCALE_HW_Msk                        (_UINT16_(0x1) << DFT_SCALE_HW_Pos)          /* (DFT_SCALE_HW) DFT Hanning Window */
#define DFT_SCALE_HW_Val(value)                 (DFT_SCALE_HW_Msk & (_UINT16_(value) << DFT_SCALE_HW_Pos))
#define DFT_SCALE_HW_DIS_Val                    _UINT16_(0x1) 
#define DFT_SCALE_HW_EN_Val                     _UINT16_(0x0) 

/* -------- DFT Controller : (DFT_CTRL Offset: 0x1D1H) (R - 16 bits) - ATM90E36 DFT Controller -------- */
#define DFT_CTRL_Pos                           _UINT16_(0)                                   /* (DFT_CTRL) DFT Controller */
#define DFT_CTRL_Msk                           (_UINT16_(0x1) << DFT_CTRL_Pos)               /* (DFT_CTRL) DFT Controller */
#define DFT_CTRL_Val(value)                    (DFT_CTRL_Msk & (_UINT16_(value) << DFT_CTRL_Pos))
#define   DFT_CTRL_START_Val                   _UINT16_(1)                                   /* (DFT_CTRL) Starts DFT Computation */
#define   DFT_CTRL_STOP_Val                    _UINT16_(0)                                   /* (DFT_CTRL) Stops DFT Computation */

/* ************************************************************************** */
/*   TEMPERATURE COMPENSATION                                                 */
/* ************************************************************************** */
#define TEMPSTART_Pos                          _UINT16_(0)                                   /* (TEMPSTART) Temperature Compensation Start Position */
#define TEMPSTART_Msk                          (_UINT16_(0xFFFF) << ADJSTART_Pos)            /* (TEMPSTART) Temperature Compensation Start Mask */
#define TEMPSTART_Val(value)                   (ADJSTART_Msk & (_UINT16_(value) << ADJSTART_Pos))
#define   TEMPSTART_STARTUP_Val                _UINT16_(0xAA55)                              /* (TEMPSTART) Start-up Temperature Compensation */
#define   TEMPSTART_FINISH_Val                 _UINT16_(0x0000)                              /* (TEMPSTART) End Temperature Compensation */

/* MISRA C-2012 deviation block end */

/** \brief ATM90EXX Control register API structure */
/** \brief ATM90EXX register API structure */

/** \brief ATM90EXX register Address values */
typedef enum
{
    /* Status and Special Register */
    SOFTRESET_ADDR      = 0x00, /* W Software Reset */
	SYSSTATUS0_ADDR     = 0x01, /* W Software Reset */
    SYSSTATUS1_ADDR     = 0x02, /* W Software Reset */
	FUNCEN0_ADDR        = 0x03, /* W Software Reset */
	FUNCEN1_ADDR        = 0x04, /* W Software Reset */
    ZXCONFIG_ADDR       = 0x07, /* W Software Reset */
	SAGTH_ADDR          = 0x08, /* W Software Reset */
    PHASELOSSTH_ADDR    = 0x09, /* W Software Reset */
	INWARNTH_ADDR       = 0x0A, /* R/W Neutral Current (Calculated) Warning Threshold */
	INWARNTH1_ADDR      = 0x0B, /* R/W Neutral Current (Sampled from ADC) Warning Threshold */
    THDNUTH_ADDR        = 0x0C, /* R/W Voltage THD Warning Threshold */
    THDNITH_ADDR        = 0x0D, /* R/W Current THD Warning Threshold */
    DMACTRL_ADDR        = 0x0E, /* R/W DMA Mode Interface Control */
    LASTDATA_ADDR       = 0x0F, /* R Last Read/ Write SPI Value */
    /* Low Power Mode Register */
	DETECTCTRL_ADDR     = 0x10, /* R/W Current Detect Control */
	DETECTTH1_ADDR      = 0x11, /* R/W Channel 1 Current Threshold in Detection Mode */
	DETECTTH2_ADDR      = 0x12, /* R/W Channel 2 Current Threshold in Detection Mode */
	DETECTTH3_ADDR      = 0x13, /* R/W Channel 3 Current Threshold in Detection Mode */
    PMOFFSETA_ADDR      = 0x14, /* R/W Ioffset for phase A in Partial Measurement mode */
    PMOFFSETB_ADDR      = 0x15, /* R/W Ioffset for phase B in Partial Measurement mode */
    PMOFFSETC_ADDR      = 0x16, /* R/W Ioffset for phase C in Partial Measurement mode */
    PMPGA_ADDR          = 0x17, /* R/W PGAgain Configuration in Partial Measurement mode */
    PMIRMSA_ADDR        = 0x18, /* R Irms for phase A in Partial Measurement mode */
    PMIRMSB_ADDR        = 0x19, /* R Irms for phase B in Partial Measurement mode */
    PMIRMSC_ADDR        = 0x1A, /* R Irms for phase C in Partial Measurement mode */
    PMCONFIG_ADDR       = 0x1B, /* R/W Measure configuration in Partial Measurement mode */       
    PMAVGSAMPLES_ADDR   = 0x1C, /* R/W Number of 8K samples to be averaged in RMS/mean computation */       
    PMIRMSLSB           = 0x1D, /* R LSB bits of PMRrms[A/B/C] */       
    /* Configuration Registers */
	CONFIGSTART_ADDR    = 0x30, /* R/W Configuration Start Command */
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
    CS0_ADDR            = 0x3B, /* R/W Checksum 0 */
    /* Calibration Registers */	
    CALSTART_ADDR       = 0x40, /* R/W Calibration Start Command */
    POFFSETA_ADDR       = 0x41, /* R/W Phase A Active Power offset */
    QOFFSETA_ADDR       = 0x42, /* R/W Phase A Reactive Power offset */
    POFFSETB_ADDR       = 0x43, /* R/W Phase B Active Power offset */
    QOFFSETB_ADDR       = 0x44, /* R/W Phase B Reactive Power offset */
    POFFSETC_ADDR       = 0x45, /* R/W Phase C Active Power offset */
    QOFFSETC_ADDR       = 0x46, /* R/W Phase C Reactive Power offset */
    PGAINA_ADDR         = 0x47, /* R/W Phase A Calibration Gain */
    PHIA_ADDR           = 0x48, /* R/W Phase A Calibration Phase Angle */
    PGAINB_ADDR         = 0x49, /* R/W Phase B Calibration Gain */
    PHIB_ADDR           = 0x4A, /* R/W Phase B Calibration Phase Angle */
    PGAINC_ADDR         = 0x4B, /* R/W Phase C Calibration Gain */
    PHIC_ADDR           = 0x4C, /* R/W Phase C Calibration Phase Angle */
    CS1_ADDR            = 0x4D, /* R/W Checksum 1 */
    /* Fundamental/ Harmonic Energy Calibration registers */
    HARMSTART_ADDR      = 0x50, /* R/W Harmonic Calibration Start Command */
    POFFSETAF_ADDR      = 0x51, /* R/W Phase A Fundamental Active Power offset */
    POFFSETBF_ADDR      = 0x52, /* R/W Phase B Fundamental Active Power offset */
    POFFSETCF_ADDR      = 0x53, /* R/W Phase C Fundamental Active Power offset */ 
    PGAINAF_ADDR        = 0x54, /* R/W Phase A Fundamental Active Power Calibration Gain */
    PGAINBF_ADDR        = 0x55, /* R/W Phase B Fundamental Active Power Calibration Gain */
    PGAINCF_ADDR        = 0x56, /* R/W Phase C Fundamental Active Power Calibration Gain */
    CS2_ADDR            = 0x57, /* R/W Checksum 2 */
    /* Measurement Calibration */
	ADJSTART_ADDR       = 0x60, /*  R/W Measurement Calibration Startup Command */
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
	IGAINN_ADDR         = 0x6D, /* R/W Sampled N line Current RMS Gain */
	IOFFSETN_ADDR       = 0x6E, /* R/W Sampled N line Current RMS Offset */
    CS3_ADDR            = 0x6F, /* R/W Checksum 3 */    
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
    SVENERGYT_ADDR      = 0x94, /* R/C Total (Vector Sum) Apparent Energy */
    ENSTATUS0_ADDR      = 0x95, /* R Metering Status 0 */
    ENSTATUS1_ADDR      = 0x96, /* R Metering Status 1 */
    SVMEANT_ADDR        = 0x98, /* R/C (Vector Sum) Total Apparent Power */	
    SVMEANTLSB_ADDR     = 0x99, /* R/C LSB of (Vector Sum) Total Apparent Power */
    /* Fundamental / Harmonic Energy Register */
    APENERGYTF_ADDR     = 0xA0, /* R/C Total Forward Active Energy */
    APENERGYAF_ADDR     = 0xA1, /* R/C Phase A Forward Active Energy */
    APENERGYBF_ADDR     = 0xA2, /* R/C Phase B Forward Active Energy */
    APENERGYCF_ADDR     = 0xA3, /* R/C Phase C Forward Active Energy */
    ANENERGYTF_ADDR     = 0xA4, /* R/C Total Reverse Active Energy */
    ANENERGYAF_ADDR     = 0xA5, /* R/C Phase A Reverse Active Energy */
    ANENERGYBF_ADDR     = 0xA6, /* R/C Phase B Reverse Active Energy */
    ANENERGYCF_ADDR     = 0xA7, /* R/C Phase C Reverse Active Energy */
    APENERGYTH_ADDR     = 0xA8, /* R/C Total Forward Active Energy */
    APENERGYAH_ADDR     = 0xA9, /* R/C Phase A Forward Active Energy */
    APENERGYBH_ADDR     = 0xAA, /* R/C Phase B Forward Active Energy */
    APENERGYCH_ADDR     = 0xAB, /* R/C Phase C Forward Active Energy */
    ANENERGYTH_ADDR     = 0xAC, /* R/C Total Reverse Active Energy */
    ANENERGYAH_ADDR     = 0xAD, /* R/C Phase A Reverse Active Energy */
    ANENERGYBH_ADDR     = 0xAE, /* R/C Phase B Reverse Active Energy */
    ANENERGYCH_ADDR     = 0xAF, /* R/C Phase C Reverse Active Energy */	
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
    IRMSNS_ADDR         = 0xD8, /* Neutral Current Sampled RMS */   
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
    IRMSNCLSB_ADDR      = 0xEC, /* R Lower Word of N Line CALCULATED Current RMS */
    IRMSALSB_ADDR       = 0xED, /* R Lower Word of Phase A Current RMS */
    IRMSBLSB_ADDR       = 0xEE, /* R Lower Word of Phase B Current RMS */
    IRMSCLSB_ADDR       = 0xEF, /* R Lower Word of Phase C Current RMS */
    /* THD+N, Frequency, Angle and Temperature Registers */
    THDNUA_ADDR         = 0xF1, /* R phase A voltage THD+N */
    THDNUB_ADDR         = 0xF2, /* R phase B voltage THD+N */
    THDNUC_ADDR         = 0xF3, /* R phase C voltage THD+N */
    THDNIA_ADDR         = 0xF5, /* R phase A current THD+N */
    THDNIB_ADDR         = 0xF6, /* R phase B current THD+N */
    THDNIC_ADDR         = 0xF7, /* R phase C current THD+N */
    FREQ_ADDR           = 0xF8, /* R Frequency */
    PANGLEA_ADDR        = 0xF9, /* R Phase A Mean Phase Angle */
    PANGLEB_ADDR        = 0xFA, /* R Phase B Mean Phase Angle */
    PANGLEC_ADDR        = 0xFB, /* R Phase C Mean Phase Angle */
    TEMP_ADDR           = 0xFC, /* R Measured Temperature */
    UANGLEA_ADDR        = 0xFD, /* R Phase A Voltage Phase Angle */
    UANGLEB_ADDR        = 0xFE, /* R Phase B Voltage Phase Angle */
    UANGLEC_ADDR        = 0xFF, /* R Phase C Voltage Phase Angle */
    AI_HR2_ADDR         = 0x100, /* phase A, Current, Harmonic Ratio for 2-th order component */
    AI_THD_ADDR         = 0x11F, /* phase A, Current, Total Harmonic Distortion Ratio */
    BI_HR2_ADDR         = 0x120, /* phase A, Current, Harmonic Ratio for 2-th order component */
    BI_THD_ADDR         = 0x13F, /* phase A, Current, Total Harmonic Distortion Ratio */
    CI_HR2_ADDR         = 0x140, /* phase A, Current, Harmonic Ratio for 2-th order component */
    CI_THD_ADDR         = 0x15F, /* phase A, Current, Total Harmonic Distortion Ratio */
    AV_HR2_ADDR         = 0x160, /* phase A, Current, Harmonic Ratio for 2-th order component */
    AV_THD_ADDR         = 0x17F, /* phase A, Current, Total Harmonic Distortion Ratio */
    BV_HR2_ADDR         = 0x180, /* phase A, Current, Harmonic Ratio for 2-th order component */
    BV_THD_ADDR         = 0x19F, /* phase A, Current, Total Harmonic Distortion Ratio */
    CV_HR2_ADDR         = 0x1A0, /* phase A, Current, Harmonic Ratio for 2-th order component */
    CV_THD_ADDR         = 0x1BF, /* phase A, Current, Total Harmonic Distortion Ratio */
    AI_FUND_ADDR        = 0x1C0, /* phase A, Current, Fundamental component value */
    AV_FUND_ADDR        = 0x1C1, /* phase A, Voltage, Fundamental component value */
    BI_FUND_ADDR        = 0x1C2, /* phase B, Current, Fundamental component value */
    BV_FUND_ADDR        = 0x1C3, /* phase B, Voltage, Fundamental component value */
    CI_FUND_ADDR        = 0x1C4, /* phase C, Current, Fundamental component value */
    CV_FUND_ADDR        = 0x1C5, /* phase C, Voltage, Fundamental component value */
    DFT_SCALE_ADDR      = 0x1D0, /* DFT Scale */
    DFT_CONTROL_ADDR    = 0x110, /* DFT Control */
    BGCURVEK_ADDR       = 0x201, /* Temperature Sensor Configuration Register 0 */
    BG_TEMP_P12_ADDR    = 0x202, /* Compensation coefficient on the 25/17 ℃ temperature point */
    BG_TEMP_P34_ADDR    = 0x203, /* Compensation coefficient on the 41/33 ℃ temperature point */
    BG_TEMP_P56_ADDR    = 0x204, /* Compensation coefficient on the 57/49 ℃ temperature point */
    BG_TEMP_P78_ADDR    = 0x205, /* Compensation coefficient on the 73/65 ℃ temperature point */
    BG_TEMP_N12_ADDR    = 0x206, /* Compensation coefficient on the 1/9 ℃ temperature point */
    BG_TEMP_N34_ADDR    = 0x207, /* Compensation coefficient on the -15/-7 ℃ temperature point */
    BG_TEMP_N56_ADDR    = 0x208, /* Compensation coefficient on the -31/-23 ℃ temperature point */
    BG_TEMP_N78_ADDR    = 0x209, /* Compensation coefficient on the -47/-39 ℃ temperature point */
    TEMPCFG0_ADDR       = 0x216, /* Temperature Sensor Configuration Register 0 */
    TEMPCFG1_ADDR       = 0x219, /* Temperature Sensor Configuration Register 1 */
    TEMPCOMPGAIN_ADDR   = 0x270, /* Temperature compensation coefficient, bit 7 is the sign bit, unit is ppm/ ℃ */
    TEMPCOMPREF_ADDR    = 0x27B, /* Fiducial point temperature of the temperature coefficient */
    TEMPSTART_ADDR      = 0x2FD, 
    INVALID_ADDR        = 0xFFFF
}ATM90EXX_REGISTERS_ADDR;

typedef struct
{
    /* Control Registers */
    __IO  uint16_t UScale;              /* Voltage Scale */
    __IO  uint16_t IScale;              /* Current Scale */
    __IO  uint16_t PM;                  /* Acts over PM Hardware Pins */
    //__IO  uint16_t SoftReset;
	__IO  uint16_t FuncEn0;             /* Function Enable 0 */
    __IO  uint16_t FuncEn1;             /* Function Enable 1 */
    __IO  uint16_t ZXconfig;            /* Zero-Crossing Configuration */
    __IO  uint16_t MMode0;              /* Metering method configuration */
    __IO  uint16_t MMode1;              /* PGA gain configuration */
    __IO  uint16_t DMACtrl;             /* DMA Mode Interface Control */
    __IO  uint16_t CS0;
    __IO  uint16_t CS1;
    __IO  uint16_t CS2;
    __IO  uint16_t CS3;
} ATM90EXX_REGS_CONTROL;

typedef struct {
    /* Thresholds */
    __IO  uint16_t SagTh;               /* Voltage Sag Threshold */
    __IO  uint16_t PhaseLossTh;         /* Voltage Phase Losing Threshold */
    __IO  uint16_t InWarnTh;            /* Neutral Current (Calculated) Warning Threshold */
    __IO  uint16_t InWarnTh1;           /* Neutral Current (Sampled from ADC) Warning Threshold */
    __IO  uint16_t ThdNuTh;             /* Voltage THD Warning Threshold */
    __IO  uint16_t ThdNiTh;             /* Current THD Warning Threshold */
    __IO  uint16_t PStartTh;            /* Active Startup Power Threshold */
    __IO  uint16_t QStartTh;            /* Reactive Startup Power Threshold */
    __IO  uint16_t SStartTh;            /* Apparent Startup Power Threshold */
    __IO  uint16_t PPhaseTh;            /* Startup Power Threshold (Active Energy Accumulation) */
    __IO  uint16_t QPhaseTh;            /* Startup Power Threshold (ReActive Energy Accumulation) */
    __IO  uint16_t SPhaseTh;            /* Startup Power Threshold (Apparent Energy Accumulation) */
} ATM90EXX_REGS_THRESHOLDS;

typedef struct {
    /* System Status */
	__O   uint16_t SysStatus0;          /* System Status 0 */
    __O   uint16_t SysStatus1;          /* System Status 1 */
    __O   uint16_t EnStatus0;           /* Metering Status 0 */
    __O   uint16_t EnStatus1;           /* Metering Status 1 */
    __O   uint16_t LastSPIData;
} ATM90EXX_REGS_STATUS;

typedef struct {
    /* Metering Calibration */
    __IO  uint16_t MC;                  /* R/W Meter Constant in pulses/KWh */
    __IO  uint16_t PLconstH;            /* PLConstant High Word */
    __IO  uint16_t PLconstL;            /* PLConstant Low Word */
    __IO  uint16_t PoffsetA;            /* Phase A Active Power Offset */
    __IO  uint16_t QoffsetA;            /* Phase A Reactive Power Offset */
    __IO  uint16_t PoffsetB;            /* Phase B Active Power Offset */
    __IO  uint16_t QoffsetB;            /* Phase B Reactive Power Offset */
    __IO  uint16_t PoffsetC;            /* Phase C Active Power Offset */
    __IO  uint16_t QoffsetC;            /* Phase C Reactive Power Offset */
    __IO  uint16_t PgainA;              /* Phase A Active Power Gain */
    __IO  uint16_t PgainB;              /* Phase B Active Power Gain */
    __IO  uint16_t PgainC;              /* Phase C Active Power Gain */
    __IO  uint16_t PhiA;                /* Phase A calibration phase angle */
    __IO  uint16_t PhiB;                /* Phase B calibration phase angle */
    __IO  uint16_t PhiC;                /* Phase C calibration phase angle */
    /* Fundamental/ Harmonic Metering Calibration */
    __IO  uint16_t PoffsetAF;           /* Phase A Fundamental Active Power Offset */
    __IO  uint16_t PoffsetBF;           /* Phase B Fundamental Active Power Offset */
    __IO  uint16_t PoffsetCF;           /* Phase C Fundamental Active Power Offset */
    __IO  uint16_t PgainAF;             /* Phase A Fundamental Active Power Gain */
    __IO  uint16_t PgainBF;             /* Phase B Fundamental Active Power Gain */
    __IO  uint16_t PgainCF;             /* Phase C Fundamental Active Power Gain */
} ATM90EXX_REGS_CAL_MET;

typedef struct {
    /* Measurement Calibration Group */
	__IO  uint16_t UgainA;              /* Phase A Voltage RMS Gain   */
    __IO  uint16_t IgainA;              /* Phase A Current RMS Gain   */
    __IO  uint16_t UoffsetA;            /* Phase A Voltage RMS Offset */
    __IO  uint16_t IoffsetA;            /* Phase A Current RMS Offset */
	__IO  uint16_t UgainB;              /* Phase B Voltage RMS Gain   */
    __IO  uint16_t IgainB;              /* Phase B Current RMS Gain   */
    __IO  uint16_t UoffsetB;            /* Phase B Voltage RMS Offset */
    __IO  uint16_t IoffsetB;            /* Phase B Current RMS Offset */
	__IO  uint16_t UgainC;              /* Phase C Voltage RMS Gain   */
    __IO  uint16_t IgainC;              /* Phase C Current RMS Gain   */
    __IO  uint16_t UoffsetC;            /* Phase C Voltage RMS Offset */
    __IO  uint16_t IoffsetC;            /* Phase C Current RMS Offset */
    __IO  uint16_t IgainNS;             /* Sampled N Line Current RMS Gain   */
    __IO  uint16_t IoffsetNS;           /* Sampled N Line Current RMS Offset */
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
    __O   uint16_t SVmeanT;             /* R Total (Vectorial Sum) Apparent Power */
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
    __O   uint16_t SVmeanTLSB;
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
	__O   uint16_t IrmsA;               /* R Phase A Current RMS */
    __O   uint16_t IrmsB;               /* R Phase B Current RMS */
    __O   uint16_t IrmsC;               /* R Phase C Current RMS */
    __O   uint16_t IrmsNS;              /* R N Line Sampled Current RMS */
    __O   uint16_t IrmsNC;              /* R N Line Calculated Current RMS */
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
    __O   uint16_t IrmsALSB;
    __O   uint16_t IrmsBLSB;
    __O   uint16_t IrmsCLSB;
    /* Other Measurements */
    __O   uint16_t THDNUA;              /* R Phase A voltage THD+N */
    __O   uint16_t THDNUB;              /* R Phase B voltage THD+N */
    __O   uint16_t THDNUC;              /* R Phase C voltage THD+N */
    __O   uint16_t THDNIA;              /* R Phase A current THD+N */
    __O   uint16_t THDNIB;              /* R Phase B current THD+N */
    __O   uint16_t THDNIC;              /* R Phase C current THD+N */
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
    __O   uint16_t SVEnergyT;           /* R/C Total (Vectorial Sum) Apparent Energy */
    __O   uint16_t SEnergyA;            /* R/C Phase A Apparent Energy */
    __O   uint16_t SEnergyB;            /* R/C Phase B Apparent Energy */
    __O   uint16_t SEnergyC;            /* R/C Phase C Apparent Energy */
    __O   uint16_t APEnergyTF;          /* R/C Total Forward Fundamental Active Energy */
    __O   uint16_t APEnergyAF;          /* R/C Phase A Forward Fundamental Active Energy */
    __O   uint16_t APEnergyBF;          /* R/C Phase B Forward Fundamental Active Energy */
    __O   uint16_t APEnergyCF;          /* R/C Phase C Forward Fundamental Active Energy */
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
