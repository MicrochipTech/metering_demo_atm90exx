/*******************************************************************************
  ATM90EXX Driver Configuration

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_conf.h

  Summary:
    ATM90EXX Data Configuration

  Description:
    ATM90EXX Data Configuration
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef ATM90EXX_CONF_H
#define ATM90EXX_CONF_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

#ifdef  METROLOGY_ATM90E26_SUPPORT
#define ATM90E26_SUPPORT
#define ATM90E26_LSB_SUPPORT                    /* 24 bits instead of 16 bit for RMS/Power resolution */

#ifdef  METROLOGY_ATM90E26_SPI_SUPPORT        
#define ATM90EXX_HAL_SPI_DRIVER
#else 
#define ATM90EXX_HAL_SERIAL_DRIVER        
#endif
        
#define ATM90E26_HAL_USEL_PIO_SUPPORT           /* Selection of interface SPI/Serial */
#ifdef  ATM90E26_HAL_USEL_PIO_SUPPORT        
#ifdef  METROLOGY_ATM90E26_SERIAL_SUPPORT
#define ATM90E26_HAL_USEL_SERIAL                /* Selection of Serial interface */
#else
#define  ATM90E26_HAL_USEL_SPI                   /* Selection of SPI interface */
#endif
#endif  
        
#undef  ATM90E26_HAL_MMDX_PIO_SUPPORT           /* MDM0-1 pins support to configure ATM90E26 Metering Mode */
#ifdef  ATM90E26_HAL_MMDX_PIO_SUPPORT
#define ATM90E26_HAL_MODE_ANTI_TAMPER
#undef  ATM90E26_HAL_MODE_L_LINE
#undef  ATM90E26_HAL_MODE_L_N
#undef  ATM90E26_HAL_MODE_FLEXIBLE        
#endif        
#endif //METROLOGY_ATM90E26_SUPPORT

#ifdef  METROLOGY_ATM90E32_SUPPORT
#define ATM90E32_SUPPORT
#define ATM90E3X_SUPPORT
#define ATM90EXX_HAL_SPI_DRIVER
#define ATM90E3X_HAL_PMX_PIO_SUPPORT             /* PM0-1 pins support to configure ATM90E3x Power Modes */        
#endif

#ifdef  METROLOGY_ATM90E36_SUPPORT
#define ATM90E36_SUPPORT
#define ATM90E3X_SUPPORT
#define ATM90EXX_HAL_SPI_DRIVER
#define ATM90E3X_HAL_PMX_PIO_SUPPORT
#undef ATM90EXX_I1I3SWAP_SUPPORT
#endif
        
#define ATM90EXX_IRQ_SUPPORT                     /* All the ATM90EXX interrupts managed by the same handler */
#ifdef  ATM90EXX_IRQ_SUPPORT
#define ATM90EXX_IRQ_COMMON_SUPPORT              /* Common Callback independtly of Interrupt Line */
#define ATM90EXX_HAL_IRQ0_SUPPORT                /* IRQ0 interrupt managed */
#ifdef  ATM90E3X_SUPPORT
#undef  ATM90EXX_HAL_IRQ1_SUPPORT                /* IRQ1 interrupt managed */
#endif
#undef  ATM90EXX_HAL_WARNOUT_SUPPORT            /* Warnout interrupt managed - Required on ATM90E26 for SAG */
#ifdef  ATM90E32_SUPPORT
#define  ATM90EXX_IRQ_ALL1ONE_SUPPORT            /* All Interrupts ORed to IRQ0 */
#endif  
#endif        

#ifdef METROLOGY_POLL_INT_SUPPORT        
#define ATM90EXX_DRV_POLL_INT_STATUS             /* Allows to poll ATM90EXX Interrupt status through polling */
#endif
        
#ifdef  METROLOGY_CFX_SUPPORT
#undef  ATM90EXX_CFX_SUPPORT                     /* Support for CFX pulses detection */
#undef  ATM90EXX_CF1_SUPPORT                     /* Support for CF1 pulses detection */
#undef  ATM90EXX_CF2_SUPPORT                     /* Support for CF2 pulses detection */
#undef  ATM90EXX_CF3_SUPPORT                     /* Support for CF3 pulses detection */
#undef  ATM90EXX_CF4_SUPPORT                     /* Support for CF4 pulses detection */
#endif
        
#ifdef  METROLOGY_ZC_SUPPORT
#undef  ATM90EXX_ZCX_SUPPORT                     /* Support for ZC pulses detection */
#undef  ATM90EXX_ZC0_SUPPORT                     /* Support for ZC0 pulses detection */
#undef  ATM90EXX_ZC1_SUPPORT                     /* Support for ZC1 pulses detection */
#undef  ATM90EXX_ZC2_SUPPORT                     /* Support for ZC2 pulses detection */
#endif        

// EVENTS
// NO-LOAD
#ifdef  METROLOGY_API_NOLOAD_SUPPORT
#define ATM90EXX_NOLOAD_SUPPORT                  /* Support for NoLoad Events */
#define ATM90EXX_NOLOAD_ACTIVE_SUPPORT           /* Support for Active Power NoLoad Events */
#define ATM90EXX_NOLOAD_REACTIVE_SUPPORT         /* Support for Reactive Power NoLoad Events */
#ifdef  ATM90E3X_SUPPORT
#define  ATM90EXX_NOLOAD_APPARENT_SUPPORT         /* Support for Apparent Power No Load Events */
#endif
#endif

#ifdef  METROLOGY_API_SAG_SUPPORT
#define  ATM90EXX_SAG_SUPPORT                     /* Support for SAG Events */
#endif
#ifdef  METROLOGY_API_SWELL_SUPPORT
#define  ATM90EXX_SWELL_SUPPORT                   /* Support for OverVoltage Events */        
#endif        

#ifdef  METROLOGY_API_OVER_CURRENT_SUPPORT
#ifdef  ATM90E32_SUPPORT
#define  ATM90EXX_OVER_CURRENT_SUPPORT             /* Only on ATM90E32 */
#undef  ATM90EXX_OVER_CURRENT_INC_SUPPORT          /* Supported in all devices */ 
#endif
#ifdef  ATM90E6_SUPPORT
#undef  ATM90EXX_OVER_CURRENT_INC_SUPPORT          /* Supported in all devices */ 
#undef  ATM90EXX_OVER_CURRENT_INS_SUPPORT
#endif
#endif
        
#ifdef  METROLOGY_API_PHASE_LOSS_SUPPORT
#ifdef  ATM90E3X_SUPPORT
#define  ATM90EXX_PHASE_LOSS_SUPPORT
#endif
#endif 
        
#ifdef  METROLOGY_API_PHASE_SEQUENCE_SUPPORT
#ifdef  ATM90E3X_SUPPORT
#define  ATM90EXX_PHASE_SEQUENCE_SUPPORT
#endif        
#endif

#ifdef  METROLOGY_API_FREQ_RANGE_SUPPORT
#ifdef  ATM90E32_SUPPORT
#define  ATM90EXX_FREQ_RANGE_ERROR_SUPPORT
#endif        
#endif
        
#ifdef  METROLOGY_API_HARD_ERR_SUPPORT
#define  ATM90EXX_HARD_ERR_SUPPORT        
#endif
        
#undef  ATM90EXX_DRV_CHECKSUM_CALC              /* Checksums are calculated instead of read/write */

#ifdef  METROLOGY_API_HARMONICS_SUPPORT
#undef  ATM90E36_HARMONICS_SUPPORT
#endif 

#ifdef  METROLOGY_API_CALIBRATION_SUPPORT
#undef  ATM90EXX_CALIBRATION_SUPPORT
#endif
        
// MEASUREMENTS
        
#ifdef __cplusplus
}
#endif

#endif // #ifndef ATM90EXX_CONF_H
/*******************************************************************************
 End of File
*/
