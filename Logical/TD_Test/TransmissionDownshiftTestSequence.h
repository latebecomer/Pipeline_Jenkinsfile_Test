/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
 ********************************************************************
 * Program: TransmissionDownshiftTestSequence
 * File: TransmissionDownshiftTestSequence.h
 * Author: The MathWorks, Inc.
 * Created: Wed Jun 03 01:12:01 1998
 ********************************************************************
 * Header for program TransmissionDownshiftTestSequence
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink  V6.1.0
 * (ERT based)
 ********************************************************************/

#ifndef RTW_HEADER_TransmissionDownshiftTestSequence_h_
#define RTW_HEADER_TransmissionDownshiftTestSequence_h_
#include <math.h>
#ifndef TransmissionDownshiftTestSequence_COMMON_INCLUDES_
# define TransmissionDownshiftTestSequence_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                  /* TransmissionDownshiftTestSequence_COMMON_INCLUDES_ */

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

#ifndef AST_ROUND
#define AST_ROUND(x) ((x)>=0?(long long)((x)+0.5):(long long)((x)-0.5))
#endif

#include "TransmissionDownshiftTestSequence_types.h"


/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#define TransmissionDownshiftTestSequence_M (TransmissionDownshiftTestSeq_M)
#ifndef MIN
#define MIN(a,b)                       ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b)                       ((a) > (b) ? (a) : (b))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T engineimpellerinertia;        /* '<S5>/engine + impeller inertia' */
  real_T vehicleinertia;               /* '<S6>/vehicle inertia' */
  real_T out;                          /* '<S9>/Look-Up Table' */
  gearType gear;                       /* '<Root>/shift_controller' */
} BlockIO_TransmissionDownshiftTe;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c4_TransmissionDownsh;/* '<Root>/shift_controller' */
  uint8_T is_active_gear_state;        /* '<Root>/shift_controller' */
  uint8_T is_selection_state;          /* '<Root>/shift_controller' */
  uint8_T is_active_selection_state;   /* '<Root>/shift_controller' */
  uint8_T temporalCounter_i1;          /* '<Root>/shift_controller' */
} D_Work_TransmissionDownshiftTes;

/* Continuous states (default storage) */
typedef struct {
  real_T wheelspeed_CSTATE;            /* '<S6>/wheel speed' */
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
} ContinuousStates_TransmissionDo;

/* State derivatives (default storage) */
typedef struct {
  real_T wheelspeed_CSTATE;            /* '<S6>/wheel speed' */
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
} StateDerivatives_TransmissionDo;

/* State disabled  */
typedef struct {
  boolean_T wheelspeed_CSTATE;         /* '<S6>/wheel speed' */
  boolean_T Integrator_CSTATE;         /* '<S5>/Integrator' */
} StateDisabled_TransmissionDowns;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T brake;                        /* '<Root>/brake' */
  real_T throttle;                     /* '<Root>/throttle' */
} ExternalInputs_TransmissionDown;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
} ExternalOutputs_TransmissionDow;

/* Parameters (default storage) */
struct Parameters_TransmissionDownshif_ {
  real_T Iei;                          /* Variable: Iei
                                        * Referenced by: '<S5>/engine + impeller inertia'
                                        */
  real_T downtab[24];                  /* Variable: downtab
                                        * Referenced by: '<S3>/interp_down'
                                        */
  real_T downth[6];                    /* Variable: downth
                                        * Referenced by: '<S3>/interp_down'
                                        */
  real_T emap[110];                    /* Variable: emap
                                        * Referenced by: '<S5>/engine torque'
                                        */
  real_T nevec[11];                    /* Variable: nevec
                                        * Referenced by: '<S5>/engine torque'
                                        */
  real_T thvec[10];                    /* Variable: thvec
                                        * Referenced by: '<S5>/engine torque'
                                        */
  real_T uptab[24];                    /* Variable: uptab
                                        * Referenced by: '<S3>/interp_up'
                                        */
  real_T upth[6];                      /* Variable: upth
                                        * Referenced by: '<S3>/interp_up'
                                        */
  real_T vehicledata[6];               /* Variable: vehicledata
                                        * Referenced by:
                                        *   '<S6>/final drive ratio1'
                                        *   '<S6>/final drive ratio2'
                                        *   '<S6>/linear speed'
                                        *   '<S6>/vehicle inertia'
                                        *   '<S6>/wheel speed'
                                        */
  real_T TorqueConverter_Kfactor[21]; /* Mask Parameter: TorqueConverter_Kfactor
                                       * Referenced by: '<S8>/K factor'
                                       */
  real_T TorqueConverter_Torkratio[21];
                                    /* Mask Parameter: TorqueConverter_Torkratio
                                     * Referenced by: '<S8>/Torque ratio'
                                     */
  real_T TorqueConverter_speedratio[21];
                                   /* Mask Parameter: TorqueConverter_speedratio
                                    * Referenced by:
                                    *   '<S8>/K factor'
                                    *   '<S8>/Torque ratio'
                                    */
  uint8_T shift_controller_TWAIT;      /* Mask Parameter: shift_controller_TWAIT
                                        * Referenced by: '<Root>/shift_controller'
                                        */
  real_T interp_down_bp02Data[4];      /* Expression: [1:4]
                                        * Referenced by: '<S3>/interp_down'
                                        */
  real_T interp_up_bp02Data[4];        /* Expression: [1:4]
                                        * Referenced by: '<S3>/interp_up'
                                        */
  real_T mph_Gain;                     /* Expression: 60/5280
                                        * Referenced by: '<S6>/mph'
                                        */
  real_T Integrator_IC;                /* Expression: 1000
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 6000
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: 600
                                        * Referenced by: '<S5>/Integrator'
                                        */
  uint32_T interp_down_maxIndex[2];  /* Computed Parameter: interp_down_maxIndex
                                      * Referenced by: '<S3>/interp_down'
                                      */
  uint32_T interp_up_maxIndex[2];      /* Computed Parameter: interp_up_maxIndex
                                        * Referenced by: '<S3>/interp_up'
                                        */
  uint32_T enginetorque_maxIndex[2];/* Computed Parameter: enginetorque_maxIndex
                                     * Referenced by: '<S5>/engine torque'
                                     */
};

/* Real-time Model Data Structure */
struct tag_RTM_TransmissionDownshiftTe {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  ContinuousStates_TransmissionDo *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][2];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

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
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_TransmissionDownshif TransmissionDownshiftTestSequ_P;

/* Block signals (default storage) */
extern BlockIO_TransmissionDownshiftTe TransmissionDownshiftTestSequ_B;

/* Continuous states (default storage) */
extern ContinuousStates_TransmissionDo TransmissionDownshiftTestSequ_X;

/* Block states (default storage) */
extern D_Work_TransmissionDownshiftTes TransmissionDownshiftTest_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_TransmissionDown TransmissionDownshiftTestSequ_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_TransmissionDow TransmissionDownshiftTestSequ_Y;

/* Model entry point functions */
extern void TransmissionDownshiftTestSequence_initialize(void);
extern void TransmissionDownshiftTestSequence_output(void);
extern void TransmissionDownshiftTestSequence_update(void);
extern void TransmissionDownshiftTestSequence_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TransmissionDownshiftT *const TransmissionDownshiftTestSeq_M;

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
 * '<Root>' : 'TransmissionDownshiftTestSequence'
 * '<S1>'   : 'TransmissionDownshiftTestSequence/shift_controller'
 * '<S2>'   : 'TransmissionDownshiftTestSequence/vehicle'
 * '<S3>'   : 'TransmissionDownshiftTestSequence/shift_controller/selection_state.calc_th'
 * '<S4>'   : 'TransmissionDownshiftTestSequence/shift_controller/selection_state.calc_th/Look-Up'
 * '<S5>'   : 'TransmissionDownshiftTestSequence/vehicle/Engine'
 * '<S6>'   : 'TransmissionDownshiftTestSequence/vehicle/Vehicle'
 * '<S7>'   : 'TransmissionDownshiftTestSequence/vehicle/transmission'
 * '<S8>'   : 'TransmissionDownshiftTestSequence/vehicle/transmission/Torque Converter'
 * '<S9>'   : 'TransmissionDownshiftTestSequence/vehicle/transmission/transmission ratio'
 * '<S10>'  : 'TransmissionDownshiftTestSequence/vehicle/transmission/transmission ratio/Look-Up Table'
 */
#endif                     /* RTW_HEADER_TransmissionDownshiftTestSequence_h_ */
