/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
 ********************************************************************
 * Program: TransmissionDownshiftTestSequence
 * File: TransmissionDownshiftTestSequence_types.h
 * Author: The MathWorks, Inc.
 * Created: Wed Jun 03 01:12:01 1998
 ********************************************************************
 * Header for program TransmissionDownshiftTestSequence
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink  V6.1.0
 * (ERT based)
 ********************************************************************/

#ifndef RTW_HEADER_TransmissionDownshiftTestSequence_types_h_
#define RTW_HEADER_TransmissionDownshiftTestSequence_types_h_
#include "rtwtypes.h"
#ifndef MIN
#define MIN(a,b)                       ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b)                       ((a) > (b) ? (a) : (b))
#endif

#ifndef DEFINED_TYPEDEF_FOR_gearType_
#define DEFINED_TYPEDEF_FOR_gearType_

typedef enum {
  gearType_None = 0,                   /* Default value */
  gearType_first,
  gearType_second,
  gearType_third,
  gearType_fourth
} gearType;

#endif

/* Parameters (default storage) */
typedef struct Parameters_TransmissionDownshif_ Parameters_TransmissionDownshif;

/* Forward declaration for rtModel */
typedef struct tag_RTM_TransmissionDownshiftTe RT_MODEL_TransmissionDownshiftT;

#endif               /* RTW_HEADER_TransmissionDownshiftTestSequence_types_h_ */
