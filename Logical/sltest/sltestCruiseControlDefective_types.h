/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
 ********************************************************************
 * Program: sltestCruiseControlDefective
 * File: sltestCruiseControlDefective_types.h
 * Author: The MathWorks, Inc.
 * Created: Wed Aug 30 21:41:02 2006
 ********************************************************************
 * Header for program sltestCruiseControlDefective
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink  V6.1.0
 * (ERT based)
 ********************************************************************/

#ifndef RTW_HEADER_sltestCruiseControlDefective_types_h_
#define RTW_HEADER_sltestCruiseControlDefective_types_h_
#include "rtwtypes.h"
#ifndef MIN
#define MIN(a,b)                       ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b)                       ((a) > (b) ? (a) : (b))
#endif

#ifndef DEFINED_TYPEDEF_FOR_setpoint_
#define DEFINED_TYPEDEF_FOR_setpoint_

typedef struct {
  boolean_T inc;
  boolean_T dec;
} setpoint;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Switches_
#define DEFINED_TYPEDEF_FOR_Switches_

typedef struct {
  boolean_T enable;
  boolean_T brake;
  boolean_T set;
  setpoint setIncDec;
} Switches;

#endif

#ifndef DEFINED_TYPEDEF_FOR_InputBus_
#define DEFINED_TYPEDEF_FOR_InputBus_

typedef struct {
  real_T Actual_speed;
  Switches Switches;
} InputBus;

#endif

/* Parameters (default storage) */
typedef struct Parameters_sltestCruiseControlD_ Parameters_sltestCruiseControlD;

/* Forward declaration for rtModel */
typedef struct tag_RTM_sltestCruiseControlDefe RT_MODEL_sltestCruiseControlDef;

#endif                    /* RTW_HEADER_sltestCruiseControlDefective_types_h_ */
