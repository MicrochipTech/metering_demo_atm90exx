/*******************************************************************************
  Interface definitions of Metrology Driver.

  Company:
    Microchip Technology Inc.

  File Name:
    metrology_defs.h

  Summary:
    Metrology Definitions

  Description:
    This file includes definitions for the Metrology driver.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef METROLOGY_DEFS_H
#define METROLOGY_DEFS_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END
        
typedef enum {
    METROLOGY_API_SUCCESS,
    METROLOGY_API_ERROR
} METROLOGY_API_RESULT;

// *****************************************************************************
/* ATM90EXX Driver RMS sign

  Summary:
    Describes the sign of some ATM90EXX measurements.

  Description:
    This quality only affects to some RMS measurements.
*/
typedef enum {
    MEASURE_SIGN_POSITIVE = 0,
    MEASURE_SIGN_NEGATIVE = 1,
} METROLOGY_MEASURE_SIGN;

#ifdef METROLOGY_ATM90E32_SUPPORT
#define METROLOGY_API_VOLTAGE_LINES  3
#define METROLOGY_API_CURRENT_LINES  3
#define METROLOGY_API_POWER_LINES    3
#define METROLOGY_API_PULSE_LINES    4
#endif

#ifdef METROLOGY_ATM90E36_SUPPORT
#define METROLOGY_API_VOLTAGE_LINES  3
#define METROLOGY_API_CURRENT_LINES  4
#define METROLOGY_API_POWER_LINES    4
#define METROLOGY_API_PULSE_LINES    4
#endif

typedef enum {
    METROLOGY_VLINE_UA  = 0x01,
    METROLOGY_VLINE_UB  = 0x02,
    METROLOGY_VLINE_UC  = 0x04,
    METROLOGY_VLINE_ALL = 0x1F
} METROLOGY_API_VOLTAGE_LINE;

typedef enum {
    METROLOGY_CLINE_IN  = 0x00,  /* Calculated Current */
    METROLOGY_CLINE_IA  = 0x01,
    METROLOGY_CLINE_IB  = 0x02,
    METROLOGY_CLINE_IC  = 0x04,
    METROLOGY_CLINE_ALL = 0x1F,
    METROLOGY_CLINE_INS = 0x20   /* Sampled Current */
} METROLOGY_API_CURRENT_LINE;

typedef enum {
    METROLOGY_PMEANA  = 0x01,
    METROLOGY_PMEANB  = 0x02,
    METROLOGY_PMEANC  = 0x04,
    METROLOGY_PMEANT  = 0x1F            
} METROLOGY_API_PMEAN_LINE;

typedef enum {
    METROLOGY_QMEANA  = 0x01,
    METROLOGY_QMEANB  = 0x02,
    METROLOGY_QMEANC  = 0x04,
    METROLOGY_QMEANT  = 0x1F            
} METROLOGY_API_QMEAN_LINE;

typedef enum {
    METROLOGY_SMEANA  = 0x01,
    METROLOGY_SMEANB  = 0x02,
    METROLOGY_SMEANC  = 0x04,
    METROLOGY_SAMEANT = 0x1F,
    METROLOGY_SVMEANT = 0x20
} METROLOGY_API_SMEAN_LINE;

typedef enum {
    METROLOGY_PMEANAF  = 0x01,
    METROLOGY_PMEANBF  = 0x02,
    METROLOGY_PMEANCF  = 0x04,
    METROLOGY_PMEANTF  = 0x1F            
} METROLOGY_API_PMEANF_LINE;

typedef enum {
    METROLOGY_PMEANAH  = 0x01,
    METROLOGY_PMEANBH  = 0x02,
    METROLOGY_PMEANCH  = 0x04,
    METROLOGY_PMEANTH  = 0x1F,
} METROLOGY_API_PMEANH_LINE;

typedef enum {
    METROLOGY_ENERGY_TYPE_ACTIVE,
    METROLOGY_ENERGY_TYPE_REACTIVE,
    METROLOGY_ENERGY_TYPE_APARENT,
    METROLOGY_ENERGY_TYPE_ACTIVE_F,
    METROLOGY_ENERGY_TYPE_ACTIVE_H
} METROLOGY_API_ENERGY_TYPE;
        
typedef enum {
    METROLOGY_AENERGYA  = 0x0001, /* Total Active Energy Phase A. Only Exists in ATM90E26 and Metrology Classical */
    METROLOGY_AENERGYB  = 0x0002, /* Total Active Energy Phase C */
    METROLOGY_AENERGYC  = 0x0004, /* Total Active Energy Phase B */
    METROLOGY_AENERGY   = 0x001F, /* Total Active Energy */
    METROLOGY_APENERGYA = 0x0020, /* Active Forward Energy Phase A */
    METROLOGY_APENERGYB = 0x0040, /* Active Forward Energy Phase B */
    METROLOGY_APENERGYC = 0x0080, /* Active Forward Energy Phase C */
    METROLOGY_APENERGY  = 0x00E0, /* Total Active Forward Energy */
    METROLOGY_ANENERGYA = 0x0100, /* Active Reverse Energy Phase A */
    METROLOGY_ANENERGYB = 0x0200, /* Active Reverse Energy Phase B */
    METROLOGY_ANENERGYC = 0x0400, /* Active Reverse Energy Phase C */
    METROLOGY_ANENERGY  = 0x0700  /* Total Active Reverse Energy */
} METROLOGY_API_AENERGY_TYPE;

typedef enum {
    METROLOGY_AFENERGYA  = 0x0001, /* Total Active Fundamental Energy Phase A. Like on Classical Metrology */
    METROLOGY_AFENERGYB  = 0x0002, /* Total Active Fundamental Energy Phase C. Like on Classical Metrology */
    METROLOGY_AFENERGYC  = 0x0004, /* Total Active Fundamental Energy Phase B. Like on Classical Metrology */
    METROLOGY_AFENERGY   = 0x001F, /* Total Active Fundamental Energy */
    METROLOGY_APFENERGYA = 0x0020, /* Active Forward Fundamental Energy Phase A */
    METROLOGY_APFENERGYB = 0x0040, /* Active Forward Fundamental Energy Phase B */
    METROLOGY_APFENERGYC = 0x0080, /* Active Forward Fundamental Energy Phase C */
    METROLOGY_APFENERGY  = 0x00E0, /* Total Active Forward Fundamental Energy */
    METROLOGY_ANFENERGYA = 0x0100, /* Active Reverse Fundamental Energy Phase A */
    METROLOGY_ANFENERGYB = 0x0200, /* Active Reverse Fundamental Energy Phase B */
    METROLOGY_ANFENERGYC = 0x0400, /* Active Reverse Fundamental Energy Phase C */
    METROLOGY_ANFENERGY  = 0x0700  /* Total Active Reverse Fundamental Energy */
} METROLOGY_API_AFENERGY_TYPE;

typedef enum {
    METROLOGY_AHENERGYA  = 0x0001, /* Total Active Harmonics Energy Phase A */
    METROLOGY_AHENERGYB  = 0x0002, /* Total Active Harmonics Energy Phase C */
    METROLOGY_AHENERGYC  = 0x0004, /* Total Active Harmonics Energy Phase B */
    METROLOGY_AHENERGY   = 0x001F, /* Total Active Harmonics Energy */
    METROLOGY_APHENERGYA = 0x0020, /* Active Forward Harmonics Energy Phase A */
    METROLOGY_APHENERGYB = 0x0040, /* Active Forward Harmonics Energy Phase B */
    METROLOGY_APHENERGYC = 0x0080, /* Active Forward Harmonics Energy Phase C */
    METROLOGY_APHENERGY  = 0x00E0, /* Total Active Forward Harmonics Energy */
    METROLOGY_ANHENERGYA = 0x0100, /* Active Reverse Harmonics Energy Phase A */
    METROLOGY_ANHENERGYB = 0x0200, /* Active Reverse Harmonics Energy Phase B */
    METROLOGY_ANHENERGYC = 0x0400, /* Active Reverse Harmonics Energy Phase C */
    METROLOGY_ANHENERGY  = 0x0700  /* Total Active Reverse Harmonics Energy */
} METROLOGY_API_AHENERGY_TYPE;

typedef enum {
    METROLOGY_QENERGYA   = 0x0001, /* Total Reactive Energy Phase A */
    METROLOGY_QENERGYB   = 0x0002, /* Total Reactive Energy Phase C */
    METROLOGY_QENERGYC   = 0x0004, /* Total Reactive Energy Phase B */
    METROLOGY_QENERGY    = 0x001F, /* Total Reactive Energy */
    METROLOGY_QPENERGYA  = 0x0020, /* Reactive Forward Energy Phase A */
    METROLOGY_QPENERGYB  = 0x0040, /* Reactive Forward Energy Phase B */
    METROLOGY_QPENERGYC  = 0x0080, /* Reactive Forward Energy Phase C */
    METROLOGY_QPENERGY   = 0x00E0, /* Total Reactive Forward Energy */
    METROLOGY_QNENERGYA  = 0x0100, /* Reactive Reverse Energy Phase A */
    METROLOGY_QNENERGYB  = 0x0200, /* Reactive Reverse Energy Phase B */
    METROLOGY_QNENERGYC  = 0x0400, /* Reactive Reverse Energy Phase C */
    METROLOGY_QNENERGY   = 0x0700  /* Total Reactive Reverse Energy */
} METROLOGY_API_QENERGY_TYPE;

typedef enum {
    METROLOGY_SENERGYA  = 0x01,    /* Total Apparent Energy Phase A */
    METROLOGY_SENERGYB  = 0x02,    /* Total Apparent Energy Phase C */
    METROLOGY_SENERGYC  = 0x04,    /* Total Apparent Energy Phase B */
    METROLOGY_SAENERGY  = 0x1F,    /* Total Arithmetic Sum Apparent Energy */
    METROLOGY_SVENERGY  = 0x20     /* Total Vector Sum Apparent Energy */
} METROLOGY_API_SENERGY_TYPE;

typedef enum {
    METROLOGY_LINE_TYPE_VOLTAGE = 0,
    METROLOGY_LINE_TYPE_CURRENT = 1,
    METROLOGY_LINE_TYPE_ALL = 2
} METROLOGY_API_LINE_TYPE;

typedef enum {
    SCALE_FACTOR_DIV16 = 0x0C,
    SCALE_FACTOR_DIV8  = 0x0B,
    SCALE_FACTOR_DIV4  = 0x0A,
    SCALE_FACTOR_DIV2  = 0x09,
    SCALE_FACTOR_1     = 0x00,
    SCALE_FACTOR_MUL2  = 0x01,
    SCALE_FACTOR_MUL4  = 0x02,
    SCALE_FACTOR_MUL8  = 0x03,
    SCALE_FACTOR_MUL16 = 0x04
} METROLOGY_SCALE_FACTOR;

typedef enum {
    SENSOR_CT        = 0,
    SENSOR_SHUNT     = 1,
    SENSOR_ROGOWSKI  = 2,
    SENSOR_NUM_TYPE
} METROLOGY_API_SENSOR_TYPE;

typedef enum {
    METER_1P2W = 0,      // 1P2W
    METER_TYPE_3P4W = 1, // 3P4W
    METER_TYPE_3P3W = 2  // 3P3W
} METROLOGY_METER_TYPE;

typedef enum {
    GAIN_1        = 1,  // 26 (L-N), 32, 36
    GAIN_2        = 2,  // 26 (N), 32, 36
    GAIN_4        = 4,  // 26 (L-N), 32, 36
    GAIN_8        = 8,  // 26 (Line L)
    GAIN_16       = 16, // 26 (Line L)
    GAIN_24       = 24, // 26 (Line L)
    GAIN_NUM_TYPE
} METROLOGY_IGAIN;

/* Metrology Basic Configuration

  Summary:
    Identifies values needed to set basic metrology configurations.

  Description:
    - mc. Meter Constant (amount of energy signified by one output pulse). Units: pulses/kWh (active energy), pulses/kVARh (reactive energy), or pulses/kAmp2-h (amp square)
    - freq. Mains frequency. Units: Hz.
    - tr.
      - In the case of a current transformer, this is the current transformer ratio
      - In the case of a Rogowski Coil, this is the current sensitivity (units: uV/A) at the main frequency specified in ?Frequency? parameter.
    - rl.
      - In the case of current transformer, this is the resistor load or burden resistor (units in scale 0.001).
      - In the case of shunt resistor, this is the shunt resistor value (units in scale 0.001)
    - ku. Voltage divider ratio.
    - st. Sensor Type. Refer to METROLOGY_API_SENSOR_TYPE.
    - PGA_Igain. Programmable Gain Amplifier (Analog) of the AFE (Depends on the AFE).
    - UScale: Voltage Scale Factor to apply to get real results
    - IScale: Current Scale Factor to apply to get real results
*/
typedef struct 
{
    uint32_t mc;
    uint32_t freq;
    uint32_t tr;
    uint32_t rl;
    uint32_t ku;
    METROLOGY_API_SENSOR_TYPE st;
    METROLOGY_IGAIN PGA_Igain;
    METROLOGY_SCALE_FACTOR UScale;
    METROLOGY_SCALE_FACTOR IScale;
} METROLOGY_BASIC_CONF;

typedef enum {
    METROLOGY_STATUS_UNINITIALIZED = SYS_STATUS_UNINITIALIZED,
    METROLOGY_STATUS_BUSY = SYS_STATUS_BUSY,
    METROLOGY_STATUS_READY = SYS_STATUS_READY,
    METROLOGY_STATUS_RUNNING = SYS_STATUS_READY_EXTENDED + 1U,
    METROLOGY_STATUS_STOP = SYS_STATUS_READY_EXTENDED + 2U,            
    METROLOGY_STATUS_CONFIGURING = SYS_STATUS_READY_EXTENDED + 3U,
    METROLOGY_STATUS_CALIBRATING = SYS_STATUS_READY_EXTENDED + 4U, 
    METROLOGY_STATUS_ERROR = SYS_STATUS_ERROR
} METROLOGY_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* METROLOGY Results

  Summary:
    Result of a METROLOGY operation.

  Description:
    Identifies the result of certain ATM90EXX driver operations.
*/

typedef enum 
{
    SAGTH,
    SWELLTH,
    PHASELOSSTH,
    OVERCURRENTTH,
    FREQHITH,
    FREQLOTH,
    INVALIDTH
} METROLOGY_API_THRESHOLDS;

typedef union 
{
    uint32_t events;
    struct {
        // Energy Direction
        uint32_t paDir     : 1;
        uint32_t pbDir     : 1;
        uint32_t pcDir     : 1;
        uint32_t ptDir     : 1;
        uint32_t qaDir     : 1;
        uint32_t qbDir     : 1;
        uint32_t qcDir     : 1;
        uint32_t qtDir     : 1;
        // SAG
        uint32_t sagA      : 1;
        uint32_t sagB      : 1;
        uint32_t sagC      : 1;
        // SWELL
        uint32_t swellA    : 1;
        uint32_t swellB    : 1;
        uint32_t swellC    : 1;
        // OVER CURRENT
        uint32_t overCA    : 1;
        uint32_t overCB    : 1;
        uint32_t overCC    : 1;
        uint32_t overCN    : 1;
        // PHASE LOSS
        uint32_t pLossVA   : 1;
        uint32_t pLossVB   : 1;
        uint32_t pLossVC   : 1;
        // PHASE SEQUENCE ERROR
        uint32_t phaseSeqV : 1;
        uint32_t phaseSeqC : 1;
        // FREQUENCY RANGE ERROR
        uint32_t freqRange : 1;
        // NOLOAD 
        uint32_t noloadAP  : 1;
        uint32_t noloadAQ  : 1;
        uint32_t noloadAS  : 1;
        // THD
        uint32_t thdu      : 1;
        uint32_t thdi      : 1;
        // HARD ERR
        uint32_t hardErr   : 1;
        // RESERVED
        uint32_t reserved2 : 2;
    } BIT; 
} METROLOGY_API_EVENTS;

// *****************************************************************************
/* ATM90EXX Driver Start mode

  Summary:
    Describes how the startup process is.

  Description:
    HARD mode implies a full reload of Core 1 application. SOFT mode does not
    any effects on Core 1 application.
*/
typedef enum {
    METROLOGY_API_START_SOFT,
    METROLOGY_API_START_HARD
} METROLOGY_API_START_MODE;

// *****************************************************************************
/* 
 * METROLOGY RESOLUTION FORMAT
 * 
 */
// *****************************************************************************


#ifdef __cplusplus
 }
#endif

#endif // #ifndef METROLOGY_API_H
/*******************************************************************************
 End of File
*/
