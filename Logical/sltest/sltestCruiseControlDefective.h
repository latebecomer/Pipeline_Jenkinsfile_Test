/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
 ********************************************************************
 * Program: sltestCruiseControlDefective
 * File: sltestCruiseControlDefective.h
 * Author: The MathWorks, Inc.
 * Created: Wed Aug 30 21:41:02 2006
 ********************************************************************
 * Header for program sltestCruiseControlDefective
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink  V6.1.0
 * (ERT based)
 ********************************************************************/

#ifndef RTW_HEADER_sltestCruiseControlDefective_h_
#define RTW_HEADER_sltestCruiseControlDefective_h_
#include <math.h>
#ifndef sltestCruiseControlDefective_COMMON_INCLUDES_
# define sltestCruiseControlDefective_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                       /* sltestCruiseControlDefective_COMMON_INCLUDES_ */

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

#ifndef AST_ROUND
#define AST_ROUND(x) ((x)>=0?(long long)((x)+0.5):(long long)((x)-0.5))
#endif

#include "sltestCruiseControlDefective_types.h"


/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef MIN
#define MIN(a,b)                       ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b)                       ((a) > (b) ? (a) : (b))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum1;                         /* '<S1>/Sum1' */
  boolean_T ActiveControl;             /* '<S1>/Logical Operator' */
} BlockIO_sltestCruiseControlDefe;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S2>/FromWs' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S2>/FromWs' */

  boolean_T UnitDelay1_DSTATE;         /* '<S1>/Unit Delay1' */
} D_Work_sltestCruiseControlDefec;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T throt;                        /* '<Root>/throt' */
  real_T target;                       /* '<Root>/target' */
} ExternalOutputs_sltestCruiseCon;

/* Parameters (default storage) */
struct Parameters_sltestCruiseControlD_ {
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T throt_Y0;                     /* Expression: 0
                                        * Referenced by: '<S5>/throt'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S5>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 5
                                          * Referenced by: '<S5>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: -5
                                          * Referenced by: '<S5>/Discrete-Time Integrator'
                                          */
  real_T Kp1_Gain;                     /* Expression: 0.01
                                        * Referenced by: '<S5>/Kp1'
                                        */
  real_T Kp_Gain;                      /* Expression: 0.02
                                        * Referenced by: '<S5>/Kp'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  boolean_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S1>/Unit Delay1'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_sltestCruiseControlDefe {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_sltestCruiseControlD sltestCruiseControlDefective_P;

/* Block signals (default storage) */
extern BlockIO_sltestCruiseControlDefe sltestCruiseControlDefective_B;

/* Block states (default storage) */
extern D_Work_sltestCruiseControlDefec sltestCruiseControlDefect_DWork;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_sltestCruiseCon sltestCruiseControlDefective_Y;

/* Model entry point functions */
extern void sltestCruiseControlDefective_initialize(void);
extern void sltestCruiseControlDefective_output(void);
extern void sltestCruiseControlDefective_update(void);
extern void sltestCruiseControlDefective_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sltestCruiseControlDef *const sltestCruiseControlDefective_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sltestCruiseControlDefective'
 * '<S1>'   : 'sltestCruiseControlDefective/Controller'
 * '<S2>'   : 'sltestCruiseControlDefective/Inputs'
 * '<S3>'   : 'sltestCruiseControlDefective/Safety Properties'
 * '<S4>'   : 'sltestCruiseControlDefective/Size-Type'
 * '<S5>'   : 'sltestCruiseControlDefective/Controller/PI Controller'
 * '<S6>'   : 'sltestCruiseControlDefective/Safety Properties/Implies'
 * '<S7>'   : 'sltestCruiseControlDefective/Safety Properties/constraint'
 * '<S8>'   : 'sltestCruiseControlDefective/Safety Properties/constraint/viewdvc'
 * '<S9>'   : 'sltestCruiseControlDefective/Size-Type/Bus1'
 */
#endif                          /* RTW_HEADER_sltestCruiseControlDefective_h_ */
