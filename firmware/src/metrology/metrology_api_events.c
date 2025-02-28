/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    metrology_api_events.c

  Summary:
    Interface definition of the Metrology Events Driver.

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
#include "metrology_api_events.h"
#ifdef METROLOGY_ATM90EXX_SUPPORT
#include "atm90exx/atm90exx_api.h"
#include "atm90exx/atm90exx_api_events.h"
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

// *****************************************************************************
// *****************************************************************************
// Section: Metrology API Local Functions
// *****************************************************************************
// *****************************************************************************

#ifdef METROLOGY_API_SAG_SUPPORT
/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_set_sag ( METROLOGY_API_VOLTAGE_LINE line, METROLOGY_API_THRESHOLD threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_set_sag_threshold (METROLOGY_API_VOLTAGE_LINE line, uint32_t threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_set_sag_threshold(threshold) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
  return METROLOGY_API_ERROR;
}

/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_set_sag ( METROLOGY_API_VOLTAGE_LINE line, METROLOGY_API_THRESHOLD *threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_get_sag_threshold (METROLOGY_API_VOLTAGE_LINE line, uint32_t *threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_get_sag_threshold(threshold) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
  return METROLOGY_API_ERROR;
}

/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_set_sag_period ( METROLOGY_API_VOLTAGE_LINE line, uint32_t period_ms )

  Remarks:
    Depends on the implementation but should be fixed and impossible to change
 */
METROLOGY_API_RESULT METROLOGY_API_set_sag_period (METROLOGY_API_VOLTAGE_LINE line, uint32_t period, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_set_sag_period(period) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
    return METROLOGY_API_ERROR;
}

/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_get_sag_period ( METROLOGY_API_VOLTAGE_LINE line, uint32_t *period, METROLOGY_API_VALUE_FORMAT format)

  Remarks:
    Depends on the implementation but should be fixed and impossible to change
 */
METROLOGY_API_RESULT METROLOGY_API_get_sag_period (METROLOGY_API_VOLTAGE_LINE line, uint32_t *period, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_get_sag_period(period) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
    return METROLOGY_API_ERROR;
}
#endif

#ifdef METROLOGY_API_SWELL_SUPPORT
/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_set_swell ( METROLOGY_API_VOLTAGE_LINE line, METROLOGY_API_THRESHOLD threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_set_swell_threshold ( METROLOGY_API_VOLTAGE_LINE line, uint32_t threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_set_swell_threshold( threshold ) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
  return METROLOGY_API_ERROR;
}

/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_set_swell ( METROLOGY_API_VOLTAGE_LINE line, METROLOGY_API_THRESHOLD *threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_get_swell_threshold (METROLOGY_API_VOLTAGE_LINE line, uint32_t *threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_get_swell_threshold( threshold ) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
  return METROLOGY_API_ERROR;
}
#endif

#ifdef METROLOGY_API_OVERCURRENT_SUPPORT
/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_set_overcurrent_threshold ( METROLOGY_API_CURRENT_LINE line, METROLOGY_API_THRESHOLD threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_set_overcurrent_threshold ( METROLOGY_API_CURRENT_LINE line, uint32_t threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_set_overcurrent_threshold( line, threshold ) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
    return METROLOGY_API_ERROR;
}

/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_get_overcurrent_threshold ( METROLOGY_API_CURRENT_LINE line, METROLOGY_API_THRESHOLD *threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_get_overcurrent_threshold (METROLOGY_API_CURRENT_LINE line, uint32_t *threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_get_overcurrent_threshold( line, threshold ) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
    return METROLOGY_API_ERROR;
}
#endif

#ifdef METROLOGY_API_PHASE_LOSS_SUPPORT
/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_set_phase_loss_threshold ( METROLOGY_API_VOLTAGE_LINE line, METROLOGY_API_THRESHOLD threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_set_phase_loss_threshold ( METROLOGY_API_VOLTAGE_LINE line, uint32_t threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_set_phase_loss_threshold( threshold ) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
    return METROLOGY_API_ERROR;
}

/*******************************************************************************
  Function:
    METROLOGY_API_RC METROLOGY_API_get_phase_loss_threshold ( METROLOGY_API_VOLTAGE_LINE line, METROLOGY_API_THRESHOLD *threshold )

  Remarks:
    Depends on the implementation
 */
METROLOGY_API_RESULT METROLOGY_API_get_phase_loss_threshold (METROLOGY_API_VOLTAGE_LINE line, uint32_t *threshold, METROLOGY_API_VALUE_FORMAT format)
{
#ifdef METROLOGY_ATM90EXX_SUPPORT
    if (ATM90EXX_API_get_phase_loss_threshold( threshold ) == ATM90EXX_API_SUCCESS)
    {
        return METROLOGY_API_SUCCESS;
    }
#endif
    return METROLOGY_API_ERROR;
}
#endif

/*******************************************************************************
 End of File
 */
