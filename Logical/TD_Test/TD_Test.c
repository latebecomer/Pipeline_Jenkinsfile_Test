/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
 ********************************************************************
 * Program: TransmissionDownshiftTestSequence
 * File: TD_Test.c
 * Author: The MathWorks, Inc.
 * Created: Wed Jun 03 01:12:01 1998
 ********************************************************************
 * Implementation of program TransmissionDownshiftTestSequence
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink  V6.1.0
 * (ERT based)
 ********************************************************************/

#define _ASMATH_
#define ASMATH_
#define _ASMATH_H
#define ASMATH_H
#define _ASMATH_H_
#define ASMATH_H_
#define _ASSTRING_
#define ASSTRING_
#define _ASSTRING_H
#define ASSTRING_H
#define _ASSTRING_H_
#define ASSTRING_H_
#include <bur/plctypes.h>
#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include "TransmissionDownshiftTestSequence.h"
#include "rtwtypes.h"

/*  Defines */

/*  Data Types */

/**************************** GLOBAL DATA *************************************/
/*  Definitions */

/*  Declarations  */

/***************************** FILE SCOPE DATA ********************************/

/*************************** FUNCTIONS ****************************************/
#ifdef __cplusplus

unsigned long bur_heap_size = 6553500;

#endif


  void _INIT mainINIT(void)
{
  
    UDINT st_ident;
  RTInfo_typ rt_info;
  rt_info.enable = 1;
  RTInfo(&rt_info);
  if (rt_info.cycle_time != 10000) {
    /* cycle time does not match Simulink fixed-step size */
    ST_ident("TD_Test", 0, &st_ident);
    ST_tmp_suspend(st_ident);
    ERR_warning(33310, 0);
  }

  /* initialize model */
  TransmissionDownshiftTestSequence_initialize();
  
} void _CYCLIC mainCYCLIC(void)
{
  /* call model step function */
  TransmissionDownshiftTestSequence_output();

  
  TransmissionDownshiftTestSequence_update();
  
} void _EXIT mainEXIT(void)
{
  /* terminate model */
  TransmissionDownshiftTestSequence_terminate();
  
} /*****************************************************************************
     Task sample time: 0.01s
   *****************************************************************************/
/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.1.0 (06-Nov-2019)
 *****************************************************************************/

/*======================== TOOL VERSION INFORMATION ==========================*
 * MATLAB 9.7 (R2019b)18-Jul-2019                                             *
 * Simulink 10.0 (R2019b)18-Jul-2019                                          *
 * Simulink Coder 9.2 (R2019b)18-Jul-2019                                     *
 * Embedded Coder 7.3 (R2019b)18-Jul-2019                                     *
 * Stateflow 10.1 (R2019b)18-Jul-2019                                         *
 * Fixed-Point Designer 6.4 (R2019b)18-Jul-2019                               *
 *============================================================================*/

/*======================= LICENSE IN USE INFORMATION =========================*
 * matlab                                                                     *
 * matlab_coder                                                               *
 * real-time_workshop                                                         *
 * rtw_embedded_coder                                                         *
 * simulink                                                                   *
 * simulink_test                                                              *
 * stateflow                                                                  *
 *============================================================================*/
