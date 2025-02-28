/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    atm90exx_hal.c

  Summary:
    This file contains the source code for the MPLAB Harmony atm90exx HAL.

  Description:
    This file contains the source code for the MPLAB Harmony atm90exx HAL.

 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include "definitions.h"
#include "atm90exx_conf.h"
#include "atm90exx_defs.h"
#include "atm90exx_hal.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
#define ATM90EXX_IRQ0_EIC_PIN     EIC_PIN_8
#define ATM90EXX_IRQ1_EIC_PIN     EIC_PIN_9
#define ATM90EXX_WARNOUT_EIC_PIN  EIC_PIN_15

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
// Section: Driver Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Driver Local Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void lDRV_ATM90Exx_HAL_usDelay ( uint32_t useg )

  Remarks:
    Depends on the implementation
 */
static void lATM90EXX_HAL_usDelay ( uint32_t useg )
{

    //vTaskDelay( pdUS_TO_TICKS( x ) )

    SYS_TIME_HANDLE tmrHandle = SYS_TIME_HANDLE_INVALID;
        
    if (SYS_TIME_DelayUS(useg, &tmrHandle) == SYS_TIME_SUCCESS)
    {
        // Wait till the delay has not expired
        while (SYS_TIME_DelayIsComplete(tmrHandle) == false){}
    }                    
}

/*******************************************************************************
  Function:
    void lDRV_ATM90Exx_HAL_msDelay ( uint32_t mseg )

  Remarks:
    Depends on the implementation
 */
static void lATM90EXX_HAL_msDelay ( uint32_t mseg )
{

    //vTaskDelay( pdMS_TO_TICKS( x ) )

    SYS_TIME_HANDLE tmrHandle = SYS_TIME_HANDLE_INVALID;
        
    if (SYS_TIME_DelayMS(mseg, &tmrHandle) == SYS_TIME_SUCCESS)
    {
        // Wait till the delay has not expired
        while (SYS_TIME_DelayIsComplete(tmrHandle) == false){}
    }                    
}

/*******************************************************************************
  Function:
    void ATM90EXX_HAL_disable_integration_period ( void )

  Remarks:
    Depends on the implementation
 */
void ATM90EXX_HAL_stop_integration_period( SYS_TIME_HANDLE handle)
{   
    /* Stop the timer */
    SYS_TIME_TimerStop(handle);
    SYS_TIME_TimerDestroy(handle);
}

/*******************************************************************************
  Function:
    SYS_TIME_HANDLE ATM90EXX_HAL_set_integration_period_callback ( TC_TIMER_CALLBACK callback, uintptr_t context )

  Remarks:
    Depends on the implementation
 */
SYS_TIME_HANDLE ATM90EXX_HAL_start_integration_period(uint32_t period_ms, SYS_TIME_CALLBACK callback, uintptr_t context )
{
    /* Register callback function for Integration Period */
    return SYS_TIME_CallbackRegisterMS( callback, context, period_ms, SYS_TIME_PERIODIC);
}

/*******************************************************************************
  Function:
    void DRV_ATM90Exx_HAL_Reset ( void )

  Remarks:
    Resets the ATM90EXX
    Attention. On ATM90E26-DB the RST pin is controlled by JP7 Jumper 
 */
void ATM90EXX_HAL_Reset (void)
{
    ATM90EXX_HAL_RESET_CLEAR();
    lATM90EXX_HAL_usDelay(ATM90EXX_RESET_TIMEOUT_MS);
    lATM90EXX_HAL_msDelay(ATM90EXX_RESET_TIMEOUT_MS);
    ATM90EXX_HAL_RESET_SET();
    lATM90EXX_HAL_msDelay(ATM90EXX_RESET_OUT_TIMEOUT_MS);
}

#ifdef ATM90E26_HAL_USEL_PIO_SUPPORT   
/*******************************************************************************
  Function:
    ATM90EXX_HAL_RESULT ATM90EXX_HAL_set_Usel ( ATM90EXX_USEL_MODE usel )

  Remarks:
    Sets the ATM90E32/36 Power Mode configuring PM0-1 HW pins
 */
ATM90EXX_HAL_RESULT ATM90E26_HAL_set_Usel (ATM90EXX_HAL_IFACE_TYPE usel)
{
    if (usel == ATM90EXX_HAL_SERIAL)
    {
		ATM90EXX_USEL_SET();
    }
    else
    {
        ATM90EXX_USEL_CLEAR();
	}	
    return ATM90EXX_HAL_SUCCESS;
}
#endif

#ifdef ATM90E3X_HAL_PMX_PIO_SUPPORT   
/*******************************************************************************
  Function:
    ATM90EXX_HAL_RESULT ATM90E3X_HAL_set_PowerMode (ATM90E3X_POWER_MODE_STATES mode)

  Remarks:
    Sets the ATM90E32/36 Power Mode configuring PM0-1 HW pins
 */
ATM90EXX_HAL_RESULT ATM90E3X_HAL_set_PowerMode (ATM90E3X_POWER_MODE_STATES mode)
{
    switch (mode)
	{
		case ATM90E3X_POWER_MODE_IDLE:
		{
			ATM90E3X_PM0_CLEAR();
            ATM90E3X_PM1_CLEAR();
            break;
		}
		case ATM90E3X_POWER_MODE_DETECT:
		{
			ATM90E3X_PM0_CLEAR();
            ATM90E3X_PM1_SET();
            break;
		}
		case ATM90E3X_POWER_MODE_PARTIAL:
		{	
			ATM90E3X_PM0_SET();
            ATM90E3X_PM1_CLEAR();
            break;
		}
		case ATM90E3X_POWER_MODE_NORMAL:
		default:
		{
            ATM90E3X_PM0_SET();
            ATM90E3X_PM1_SET();
            break;           
		}
	}	
    // Wait for a while after Power Mode Change
    return ATM90EXX_HAL_SUCCESS;
}
#endif

#ifdef ATM90E3X_HAL_DMA_CTRL_PIO_SUPPORT   
/*******************************************************************************
  Function:
    ATM90EXX_HAL_RESULT ATM90E3X_HAL_set_DMACtrlMode (ATM90E3X_DMA_MODE mode)

  Remarks:
    Sets the ATM90E36 DMA Mode configuring DMA_CTRL HW pins
 */
ATM90EXX_HAL_RESULT ATM90E3X_HAL_set_DMACtrlMode (ATM90E3X_DMA_MODE mode)
{
    if (mode == ATM90E3X_DMA_MODE_OFF)
		{
			ATM90E3X_DMA_CTRL_CLEAR();
		}
    else
		{
			ATM90E3X_DMA_CTRL_SET();
		}
    // Wait for a while after Power Mode Change
    return ATM90EXX_HAL_SUCCESS;
}
#endif

#ifdef ATM90E26_HAL_MMDX_PIO_SUPPORT   
/*******************************************************************************
  Function:
    void ATM90EXX_HAL_set_MeterMode ( void )

  Remarks:
    Sets the ATM90E26 Meter Mode configuring MMD0-1 HW pins
    On the Evaluation Board, configure connector JP4-5
 */
ATM90EXX_HAL_RESULT ATM90EXX_HAL_set_MeterMode (ATM90EXX_METERING_MODE_STATES mode)
{
  switch (mode)
	{
		case	ATM90EXX_METERING_MODE_ANTI_TAMPER:
		{
			ATM90EXX_MMD0_CLEAR();
      ATM90EXX_MMD1_CLEAR();
      break;
		}
		case	ATM90EXX_METERING_MODE_FIXED_L:
		{
			ATM90EXX_MMD0_CLEAR();
      ATM90EXX_MMD1_SET();
      break;
		}
		case	ATM90EXX_METERING_MODE_L_AND_N:
		{	
			ATM90EXX_MMD0_SET();
      ATM90EXX_MMD1_CLEAR();
      break;
		}
		case	ATM90EXX_METERING_MODE_LNSELBIT:
		default:
		{
      ATM90EXX_MMD0_SET();
      ATM90EXX_MMD1_SET();   
      break;        
		}
	}	
  result ATM90EXX_HAL_SUCCESS;
}
#endif

/*******************************************************************************
  Function:
    bool ATM90EXX_HAL_Write (DRV_HANDLE handle, void* buffer, const size_t numbytes)

  Remarks:
    Disable IRQ0 pin interrupt
        - ATM90E26: corresponds with pin IRQ
        - ATM90E3X: corresponds with pin IRQ0
    Implementation depends on the uC.
 */
bool lATM90EXX_HAL_Write (DRV_HANDLE handle, void* buffer, const size_t numbytes)
{
#ifdef ATM90EXX_HAL_SPI_DRIVER
    return DRV_SPI_WriteTransfer(handle, buffer, numbytes);
#else
    return DRV_USART_WriteBuffer(handle, buffer, numbytes);
#endif
}

#ifdef ATM90EXX_HAL_SPI_DRIVER
/*******************************************************************************
  Function:
    bool ATM90EXX_HAL_WriteRead (DRV_HANDLE handle, void* buffer, const size_t numbytes)

  Remarks:
    Disable IRQ0 pin interrupt
        - ATM90E26: corresponds with pin IRQ
        - ATM90E3X: corresponds with pin IRQ0
    Implementation depends on the uC.
 */
bool lATM90EXX_HAL_WriteRead (DRV_HANDLE handle, void* bufferTx, const size_t numbytesTx, void* bufferRx, const size_t numbytesRx)
{
    return DRV_SPI_WriteReadTransfer(handle, bufferTx, numbytesTx, bufferRx, numbytesRx);
}
#endif

/*******************************************************************************
  Function:
    bool ATM90EXX_HAL_Read (DRV_HANDLE handle, void* buffer, const size_t numbytes)

  Remarks:
    Disable IRQ0 pin interrupt
        - ATM90E26: corresponds with pin IRQ
        - ATM90E3X: corresponds with pin IRQ0
    Implementation depends on the uC.
 */
bool lATM90EXX_HAL_Read (DRV_HANDLE handle, void* buffer, const size_t numbytes)
{
#ifdef ATM90EXX_HAL_SPI_DRIVER
    return DRV_SPI_ReadTransfer(handle, buffer, numbytes);
#else
    return DRV_USART_ReadBuffer(handle, buffer, numbytes);
#endif
}

#if defined(ATM90EXX_HAL_SPI_DRIVER)
/*******************************************************************************
  Function:
    bool ATM90EXX_HAL_write_reg ( uint16_t reg, uint16_t val )

  Remarks:
    Write ATM90EXX Register through SPI access. Synchronous.
 */

ATM90EXX_HAL_RESULT ATM90EXX_HAL_write_reg ( DRV_HANDLE handle, uint16_t reg, uint16_t val )
{
    uint16_t txlen = 0;
    /* TX Buffer */
    uint8_t txBuff[ATM90EXX_TX_BUFF_SIZE];
    /* RX Buffer */
    //uint8_t rxBuff[ATM90EXX_RX_BUFF_SIZE];
    
#ifdef ATM90E26_SUPPORT
    txBuff[txlen++] = (uint8_t) ((reg) & 0x7F);            // MSB=0 --> Write
    txBuff[txlen++] = (uint8_t) ((val >> 8) & 0xFF);
    txBuff[txlen++] = (uint8_t) (val & 0xFF);
#else
    txBuff[txlen++] = (uint8_t) ((reg >> 8) & 0x03);
    txBuff[txlen++] = (uint8_t) (reg & 0xFF);
    txBuff[txlen++] = (uint8_t) ((val >> 8) & 0xFF);
    txBuff[txlen++] = (uint8_t) (val & 0xFF);
#endif        
    
    if (lATM90EXX_HAL_Write(handle, txBuff, txlen))
    {
        //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[AH][WR][0x%04X,0x%04X]\r\n", reg, val);
        return ATM90EXX_HAL_SUCCESS;
    }
    ATM90EXX_DEBUG_PRINT(SYS_ERROR_FATAL, "[AH][WR][0x%04X,0x%04X] Error\r\n", reg, val);
    return ATM90EXX_HAL_ERROR;
}
#else
/*******************************************************************************
  Function:
    ATM90EXX_HAL_RESULT ATM90EXX_HAL_write_reg ( uint16_t reg, uint16_t val )

  Remarks:
    Write ATM90EXX Register. Synchronous.
 */

ATM90EXX_HAL_RESULT ATM90EXX_HAL_write_reg ( DRV_HANDLE handle, uint16_t reg, uint16_t val )
{
    uint8_t checksum = 0;
    /* TX Buffer */
    uint8_t txBuff[ATM90EXX_TX_BUFF_SIZE];
    /* RX Buffer */
    uint8_t rxBuff[ATM90EXX_RX_BUFF_SIZE];
    /* Retries */
    uint8_t retries = ATM90EXX_MAX_RETRIES;

    do {
      memset(txBuff,0,sizeof(txBuff));
      memset(rxBuff,0,sizeof(rxBuff));

      txBuff[0] = 0xFE;                      /* TAG */
      txBuff[1] = (uint8_t)(reg) & 0x7F;     /* ADDRESS */
      txBuff[2] = (uint8_t)(val>>8) & 0xFF;  /* VALUE */
      txBuff[3] = (uint8_t)(val & 0xFF);     /* VALUE */
      checksum += txBuff[1];
      checksum += txBuff[2];
      checksum += txBuff[3];   
      txBuff[4] = checksum;                  /* CHECKSUM */

      if (lATM90EXX_HAL_Write(handle, txBuff, 5))
      {
          // Maximum Timeout according with Datasheet
          lATM90EXX_HAL_msDelay(5);
          if (lATM90EXX_HAL_Read(handle, rxBuff, 1))
          {
              /* Compare checksums to verify */
              if (checksum == rxBuff[0])
              {
                  //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[AH][WR][0x%04X,0x%04X]\r\n", reg, val);
                  // According with Datasheet at least 20ms between transitions
                  // Better Program a Timer and check it before any other RD/WR
                  lATM90EXX_HAL_msDelay(5);
                  return ATM90EXX_HAL_SUCCESS;
              }
          }
      }
      // Time to restore serial port communication
      lATM90EXX_HAL_msDelay(25);
      //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[AH][WR][0x%04X][retries:%d]\r\n", reg, retries);
    } while (--retries);
    ATM90EXX_DEBUG_PRINT(SYS_ERROR_FATAL, "[AH][WR][0x%04X,0x%04X] Error\r\n", reg, val);
    return ATM90EXX_HAL_ERROR;
}
#endif

#if defined(ATM90EXX_HAL_SPI_DRIVER)
/*******************************************************************************
  Function:
    ATM90EXX_HAL_RESULT ATM90EXX_HAL_read_reg( DRV_HANDLE handle, uint16_t reg, uint16_t *val )

  Remarks:
    Write ATM90EXX Register through SPI access. Synchronous.
 */

ATM90EXX_HAL_RESULT ATM90EXX_HAL_read_reg( DRV_HANDLE handle, uint16_t reg, uint16_t *val )
{
    uint16_t txlen = 0;
    uint16_t rxlen = 0;
    uint16_t value;
    
    /* TX Buffer */
    uint8_t txBuff[ATM90EXX_TX_BUFF_SIZE];
    /* RX Buffer */
    uint8_t rxBuff[ATM90EXX_RX_BUFF_SIZE];
    
#if defined(ATM90E26_SUPPORT)
    txBuff[txlen++] = (uint8_t)((reg & 0x7F) | 0x80);           // MSB=1 --> Read
    rxlen = 3;
#else
    txBuff[txlen++] = (uint8_t)(((reg >> 8) & 0x03) | 0x80);        // MSB=1 --> Read
    txBuff[txlen++] = (uint8_t) (reg & 0xFF);
    rxlen = 4;
#endif
    if (lATM90EXX_HAL_WriteRead( handle, txBuff, txlen, rxBuff, rxlen)) 
    {
        value = (rxBuff[txlen] << 8) + rxBuff[txlen+1];
        *val = value;
        //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[AH][RD][0x%04X,0x%04X]\r\n", reg, value);
        return ATM90EXX_HAL_SUCCESS;
    }
    ATM90EXX_DEBUG_PRINT(SYS_ERROR_FATAL, "[AH][RD][0x%04X] Error\r\n", reg);
    return ATM90EXX_HAL_ERROR; 
}

#else
/*******************************************************************************
  Function:
    void ATM90EXX_HAL_read_reg ( DRV_HANDLE handle, uint16_t reg, uint16_t *val )

  Remarks:
    Read ATM90EXX Register. Synchronous.
 */

ATM90EXX_HAL_RESULT ATM90EXX_HAL_read_reg ( DRV_HANDLE handle, uint16_t reg, uint16_t *val )
{
    uint8_t checksum = 0;
    /* TX Buffer */
    uint8_t txBuff[ATM90EXX_TX_BUFF_SIZE];
    /* RX Buffer */
    uint8_t rxBuff[ATM90EXX_RX_BUFF_SIZE];
    /* Retries */
    uint8_t retries = ATM90EXX_MAX_RETRIES;

    do {    
      memset(txBuff,0,sizeof(txBuff));
      memset(rxBuff,0,sizeof(rxBuff));

      txBuff[0] = 0xFE;                      /* TAG */
      txBuff[1] = (uint8_t)(reg) | 0x80;     /* ADDRESS */
      txBuff[2] = txBuff[1];                 /* CHECKSUM */

      if (lATM90EXX_HAL_Write(handle, txBuff, 3)) 
      {
          // Maximum Timeout according with Datasheet
          lATM90EXX_HAL_msDelay(5);
          if (lATM90EXX_HAL_Read(handle, rxBuff, 3)) 
          {
              checksum = rxBuff[0] + rxBuff[1];
              /* Check Checksum */
              if (checksum == rxBuff[2]) {
                  *val = (rxBuff[0]<<8) + rxBuff[1];
                  //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[AH][RD][0x%04X,0x%04X]\r\n", reg, *val);
                  // According with Datasheet at least 20ms between transitions
                  // Better Program a Timer and check it before any other RD/WR
                  lATM90EXX_HAL_msDelay(5);
                  return ATM90EXX_HAL_SUCCESS;
              }
          }
      }
      // Time to restore serial port communication
        lATM90EXX_HAL_msDelay(25);
        //ATM90EXX_DEBUG_PRINT(SYS_ERROR_DEBUG, "[AH][RD][0x%04X][retries:%d]\r\n", reg, retries);
    } while (--retries);
    ATM90EXX_DEBUG_PRINT(SYS_ERROR_FATAL, "[AH][RD][0x%04X] Error\r\n", reg);
    return ATM90EXX_HAL_ERROR;
}
#endif

#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
/*******************************************************************************
  Function:
    void lATM90Exx_enable_Irq0int ( void )

  Remarks:
    Disable IRQ0 pin interrupt
        - ATM90E26: corresponds with pin IRQ
        - ATM90E3X: corresponds with pin IRQ0
    Implementation depends on the uC.
 */
void lATM90EXX_HAL_enable_Irq0Int (void)
{
    EIC_InterruptEnable(ATM90EXX_IRQ0_EIC_PIN);   
}

/*******************************************************************************
  Function:
    void lATM90Exx_disable_Irq0int( void )

  Remarks:
    Disable IRQ0 pin interrupt
        - ATM90E26: corresponds with pin IRQ
        - ATM90E3X: corresponds with pin IRQ0
    Implementation depends on the uC.
 */
void lATM90EXX_HAL_disable_Irq0Int (void)
{
    EIC_InterruptDisable(ATM90EXX_IRQ0_EIC_PIN);
}

/*******************************************************************************
  Function:
    void lDRV_ATM90Exx_Reset ( void )

  Remarks:
    Resets the ATM90EXX
 */
void ATM90EXX_HAL_Set_Irq0Int_Handler (void *callback, uintptr_t context)
{
    // Assign the callback
    EIC_CallbackRegister(ATM90EXX_IRQ0_EIC_PIN, callback, context);
}
#endif

#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
/*******************************************************************************
  Function:
    void lATM90EXX_HAL_enable_Irq1Int ( void )

  Remarks:
    Disable IRQ1 pin interrupt
        - ATM90E26: doesn't exist
        - ATM90E3X: corresponds with pin IRQ1
    Implementation depends on the uC.
 */
void lATM90EXX_HAL_enable_Irq1Int (void)
{
    EIC_InterruptEnable(ATM90EXX_IRQ1_EIC_PIN);
}

/*******************************************************************************
  Function:
    void lATM90EXX_HAL_disable_Irq1Int ( void )

  Remarks:
    Disable IRQ1 pin interrupt
        - ATM90E26: doesn't exist
        - ATM90E3X: corresponds with pin IRQ1
    Implementation depends on the uC.
 */
void lATM90EXX_HAL_disable_Irq1Int (void)
{
    EIC_InterruptDisable(ATM90EXX_IRQ1_EIC_PIN);
}

/*******************************************************************************
  Function:
    void lDRV_ATM90Exx_Reset ( void )

  Remarks:
    Resets the ATM90EXX
 */
void ATM90EXX_HAL_Set_Irq1Int_Handler (void *callback, uintptr_t context)
{
    // Assign the callback
    EIC_CallbackRegister(ATM90EXX_IRQ1_EIC_PIN, callback, context);
}
#endif

#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
/*******************************************************************************
  Function:
    void lATM90EXX_HAL_enable_WarnoutInt ( void )

  Remarks:
    Disable WARNOUT pin interrupt
    Implementation depends on the uC.
 */
void lATM90EXX_HAL_WarnoutInt_enable (void)
{
    EIC_InterruptEnable(ATM90EXX_WARNOUT_INT_MSK);
}

/*******************************************************************************
  Function:
    void lATM90EXX_HAL_disable_WarnoutInt ( void )

  Remarks:
    Disable WARNOUT pin interrupt
    Implementation depends on the uC.
 */
void lATM90EXX_HAL_WarnoutInt_disable (void)
{
    EIC_InterruptDisable(ATM90EXX_WARNOUT_INT_MSK);
}

/*******************************************************************************
  Function:
    void lDRV_ATM90Exx_Reset ( void )

  Remarks:
    Resets the ATM90EXX
 */
void ATM90EXX_HAL_Set_WarnoutInt_Handler (void *callback, uintptr_t context)
{
    // Assign the callback
    EIC_CallbackRegister(ATM90EXX_WARNOUT_EIC_PIN, callback, context);
}
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
#if defined(ATM90EXX_IRQ_SUPPORT) 

void ATM90EXX_HAL_enable_interrupts (void)
{
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
    /* Not needed - Done on initialization.c */
    lATM90EXX_HAL_enable_Irq0Int();
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
    lATM90EXX_HAL_enable_Irq1Int();
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
    lATM90EXX_HAL_enable_WarnoutInt();
#endif
}

void ATM90EXX_HAL_disable_interrupts(void)
{
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
    /* Not needed - Done on initialization.c */
    lATM90EXX_HAL_disable_Irq0Int();
#endif
#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
    lATM90EXX_HAL_disable_Irq1int();
#endif
#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
    lATM90EXX_HAL_disables_WarnoutInt();
#endif
}
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Application 
// *****************************************************************************
// *****************************************************************************
ATM90EXX_HAL_RESULT ATM90EXX_HAL_Init (/* id, iface_type, ATM90EXX_METERING_MODE_STATES meter_mode */)
{
    /* Keeps ATM90EXX in reset first */
    ATM90EXX_HAL_RESET_CLEAR();

#ifdef ATM90E3X_HAL_PMX_PIO_SUPPORT
    ATM90E3X_HAL_set_PowerMode(ATM90E3X_POWER_MODE_IDLE);
    lATM90EXX_HAL_msDelay(ATM90EXX_IDLE_TIMEOUT_MS);
#endif

#ifdef ATM90E26_HAL_USEL_PIO_SUPPORT    
#if defined(ATM90E26_HAL_USEL_SERIAL)
    ATM90E26_HAL_set_Usel(ATM90EXX_HAL_SERIAL);
#else
    ATM90E26_HAL_set_Usel(ATM90EXX_HAL_SPI);
#endif    
#endif    

    /* Keeps ATM90EXX in reset after POR */
    lATM90EXX_HAL_msDelay(ATM90EXX_RESET_AFTER_POR_MS);

#ifdef ATM90E26_HAL_MMD0_PIO_SUPPORT
    /* Configure ATM90 Meter/Power Mode if connected to uC */
#if defined(ATM90E26_HAL_MODE_ANTI_TAMPER)    
    ATM90EXX_HAL_set_MeterMode(meter_mode);
#elif defined(ATM90E26_HAL_MODE_L_LINE)
    ATM90EXX_HAL_set_MeterMode(meter_mode);
#elif defined(ATM90E26_HAL_MODE_L_N)
    ATM90EXX_HAL_set_MeterMode(meter_mode);
#else
    ATM90EXX_HAL_set_MeterMode(meter_mode);
#endif    
#endif
    
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
    /* Disable/Clear INT0 interrupt */
    lATM90EXX_HAL_disable_Irq0Int();
#endif

#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
    /* Disable/Clear INT1 interrupt */
    lATM90EXX_HAL_disable_Irq1Int();
#endif

#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
    /* Disable/Clear WARNOUT interrupt */
    lATM90Exx_HAL_disable_Warnout();
#endif

#if defined(ATM90EXX_HAL_IRQ0_SUPPORT) || defined(ATM90EXX_HAL_IRQ1_SUPPORT) || defined(ATM90EXX_HAL_WARNOUT_SUPPORT)
    /* Interrupts come from external PINs - Only enabled after configuring process */
    //lATM90EXX_HAL_enable_Interrupts();
#endif

    /* SPI/SERIAL Initialization done automatically */
    /* Free RESET PIN */
    ATM90EXX_HAL_Reset();

    return ATM90EXX_HAL_SUCCESS;
}

// *****************************************************************************
DRV_HANDLE ATM90EXX_HAL_Open ( /* const SYS_MODULE_INDEX index */ )
{
#ifdef ATM90EXX_HAL_SPI_DRIVER
    DRV_HANDLE handle;
    DRV_SPI_TRANSFER_SETUP setup;
    
#if defined(ATM90E26_SUPPORT)   
    setup.baudRateInHz = 150000;
#else
    setup.baudRateInHz = 800000;
#endif
    setup.clockPhase = DRV_SPI_CLOCK_PHASE_VALID_TRAILING_EDGE;
    setup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_HIGH;
    setup.dataBits = DRV_SPI_DATA_BITS_8;
    setup.chipSelect = (SYS_PORT_PIN)ATM90EXX_CS_PIN;
    setup.csPolarity = DRV_SPI_CS_POLARITY_ACTIVE_LOW;
    
    handle = DRV_SPI_Open( DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE );
    if (handle != DRV_HANDLE_INVALID)
    {
       if(DRV_SPI_TransferSetup(handle, &setup) == true) 
       {
           //DRV_SPI_TransferEventHandlerSet(handle, ATM90EXX_HAL_SPIEventHandler, (uintptr_t)NULL);
           return handle;
       }   
    }
    
    /* Error opening the SPI Driver for ATM90Exx */
    return DRV_HANDLE_INVALID;
#else  
    /* Open the USART for ATM90Exx */
    return DRV_USART_Open( DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);
#endif
}

// *****************************************************************************
ATM90EXX_HAL_RESULT ATM90EXX_HAL_Close (DRV_HANDLE handle)
{

#ifdef ATM90EXX_HAL_SPI_DRIVER
    /* Open the SPI Driver for ATM90Exx */
    DRV_SPI_Close( handle );
#else  
    /* Open the USART for ATM90Exx */
    DRV_USART_Close( handle );
#endif
    
#ifdef ATM90EXX_HAL_IRQ0_SUPPORT
    /* Disable/Clear INT0 interrupt */
    lATM90EXX_HAL_disable_Irq0Int();
#endif

#ifdef ATM90EXX_HAL_IRQ1_SUPPORT
    /* Disable/Clear INT1 interrupt */
    lATM90EXX_HAL_disable_Irq1Int();
#endif

#ifdef ATM90EXX_HAL_WARNOUT_SUPPORT
    /* Disable/Clear WARNOUT interrupt */
    lATM90EXX_HAL_disable_Warnout();
#endif

    /* Keep ATM90Exx in reset */
    ATM90EXX_HAL_RESET_CLEAR();

  return ATM90EXX_HAL_SUCCESS;
}

/*******************************************************************************
 End of File
 */
