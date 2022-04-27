/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
 ********************************************************************
 * Program: TransmissionDownshiftTestSequence
 * File: TransmissionDownshiftTestSequence.c
 * Author: The MathWorks, Inc.
 * Created: Wed Jun 03 01:12:01 1998
 ********************************************************************
 * Implementation of program TransmissionDownshiftTestSequence
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink  V6.1.0
 * (ERT based)
 ********************************************************************/

#include "TransmissionDownshiftTestSequence.h"
#include "TransmissionDownshiftTestSequence_private.h"

/*  Defines */

/* Named constants for Chart: '<Root>/shift_controller' */
#define TransmissionDow_IN_downshifting ((uint8_T)1U)
#define TransmissionDow_IN_steady_state ((uint8_T)2U)
#define TransmissionDowns_IN_upshifting ((uint8_T)3U)
#define TransmissionDownshif_event_DOWN (0)
#define TransmissionDownshiftT_event_UP (1)
#define Transmission_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/*  Data Types */

/**************************** GLOBAL DATA *************************************/
/*  Definitions */

/* Block signals (default storage) */
BlockIO_TransmissionDownshiftTe TransmissionDownshiftTestSequ_B;

/* Continuous states */
ContinuousStates_TransmissionDo TransmissionDownshiftTestSequ_X;

/* Block states (default storage) */
D_Work_TransmissionDownshiftTes TransmissionDownshiftTest_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_TransmissionDown TransmissionDownshiftTestSequ_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_TransmissionDow TransmissionDownshiftTestSequ_Y;

/* Real-time model */
RT_MODEL_TransmissionDownshiftT TransmissionDownshiftTestSeq_M_;
RT_MODEL_TransmissionDownshiftT *const TransmissionDownshiftTestSeq_M =
  &TransmissionDownshiftTestSeq_M_;

/*  Declarations  */

/* Forward declaration for local functions */
static void TransmissionDownshif_gear_state(const int32_T *sfEvent);
static void rate_scheduler(void);

/***************************** FILE SCOPE DATA ********************************/

/*************************** FUNCTIONS ****************************************/
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          yL_1d) * frac + yL_1d;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (TransmissionDownshiftTestSeq_M->Timing.TaskCounters.TID[2])++;
  if ((TransmissionDownshiftTestSeq_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.04s, 0.0s] */
    TransmissionDownshiftTestSeq_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  TransmissionDownshiftTestSequence_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for Chart: '<Root>/shift_controller' */
static void TransmissionDownshif_gear_state(const int32_T *sfEvent)
{
  switch (TransmissionDownshiftTestSequ_B.gear) {
   case gearType_first:
    if (*sfEvent == TransmissionDownshiftT_event_UP) {
      TransmissionDownshiftTestSequ_B.gear = gearType_second;
    }
    break;

   case gearType_second:
    if (*sfEvent == TransmissionDownshiftT_event_UP) {
      TransmissionDownshiftTestSequ_B.gear = gearType_third;
    } else {
      if (*sfEvent == TransmissionDownshif_event_DOWN) {
        TransmissionDownshiftTestSequ_B.gear = gearType_first;
      }
    }
    break;

   case gearType_third:
    if (*sfEvent == TransmissionDownshiftT_event_UP) {
      TransmissionDownshiftTestSequ_B.gear = gearType_fourth;
    } else {
      if (*sfEvent == TransmissionDownshif_event_DOWN) {
        TransmissionDownshiftTestSequ_B.gear = gearType_second;
      }
    }
    break;

   case gearType_fourth:
    if (*sfEvent == TransmissionDownshif_event_DOWN) {
      TransmissionDownshiftTestSequ_B.gear = gearType_third;
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    TransmissionDownshiftTestSequ_B.gear = gearType_None;
    break;
  }
}

/* Model output function */
void TransmissionDownshiftTestSequence_output(void)
{
  real_T rtb_out;
  real_T mph;
  int32_T sfEvent;
  real_T interp_down;
  real_T mph_0;
  if (rtmIsMajorTimeStep(TransmissionDownshiftTestSeq_M)) {
    /* set solver stop time */
    if (!(TransmissionDownshiftTestSeq_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TransmissionDownshiftTestSeq_M->solverInfo,
                            ((TransmissionDownshiftTestSeq_M->Timing.clockTickH0
        + 1) * TransmissionDownshiftTestSeq_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TransmissionDownshiftTestSeq_M->solverInfo,
                            ((TransmissionDownshiftTestSeq_M->Timing.clockTick0
        + 1) * TransmissionDownshiftTestSeq_M->Timing.stepSize0 +
        TransmissionDownshiftTestSeq_M->Timing.clockTickH0 *
        TransmissionDownshiftTestSeq_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TransmissionDownshiftTestSeq_M)) {
    TransmissionDownshiftTestSeq_M->Timing.t[0] = rtsiGetT
      (&TransmissionDownshiftTestSeq_M->solverInfo);
  }

  /* Gain: '<S6>/mph' incorporates:
   *  Gain: '<S6>/linear speed'
   *  Integrator: '<S6>/wheel speed'
   */
  mph = 6.2831853071795862 * TransmissionDownshiftTestSequ_P.vehicledata[3] *
    TransmissionDownshiftTestSequ_X.wheelspeed_CSTATE *
    TransmissionDownshiftTestSequ_P.mph_Gain;

  /* Outport: '<Root>/Out1' */
  TransmissionDownshiftTestSequ_Y.Out1 = mph;
  if (rtmIsMajorTimeStep(TransmissionDownshiftTestSeq_M) &&
      TransmissionDownshiftTestSeq_M->Timing.TaskCounters.TID[2] == 0) {
    /* Chart: '<Root>/shift_controller' */
    sfEvent = -1;
    if (TransmissionDownshiftTest_DWork.temporalCounter_i1 < 255U) {
      TransmissionDownshiftTest_DWork.temporalCounter_i1++;
    }

    if (TransmissionDownshiftTest_DWork.is_active_c4_TransmissionDownsh == 0U) {
      TransmissionDownshiftTest_DWork.is_active_c4_TransmissionDownsh = 1U;
      TransmissionDownshiftTest_DWork.is_active_gear_state = 1U;
      TransmissionDownshiftTestSequ_B.gear = gearType_first;
      TransmissionDownshiftTest_DWork.is_active_selection_state = 1U;
      TransmissionDownshiftTest_DWork.is_selection_state =
        TransmissionDow_IN_steady_state;
    } else {
      if (TransmissionDownshiftTest_DWork.is_active_gear_state != 0U) {
        TransmissionDownshif_gear_state(&sfEvent);
      }

      if (TransmissionDownshiftTest_DWork.is_active_selection_state != 0U) {
        /* Outputs for Function Call SubSystem: '<S1>/selection_state.calc_th' */
        /* MATLAB Function: '<S3>/Look-Up' */
        switch (TransmissionDownshiftTestSequ_B.gear) {
         case gearType_fourth:
          rtb_out = 4.0;
          break;

         case gearType_third:
          rtb_out = 3.0;
          break;

         case gearType_second:
          rtb_out = 2.0;
          break;

         default:
          rtb_out = 1.0;
          break;
        }

        /* End of MATLAB Function: '<S3>/Look-Up' */

        /* Lookup_n-D: '<S3>/interp_down' incorporates:
         *  Inport: '<Root>/throttle'
         */
        interp_down = look2_binlxpw(TransmissionDownshiftTestSequ_U.throttle,
          rtb_out, TransmissionDownshiftTestSequ_P.downth,
          TransmissionDownshiftTestSequ_P.interp_down_bp02Data,
          TransmissionDownshiftTestSequ_P.downtab,
          TransmissionDownshiftTestSequ_P.interp_down_maxIndex, 6U);

        /* Lookup_n-D: '<S3>/interp_up' incorporates:
         *  Inport: '<Root>/throttle'
         */
        rtb_out = look2_binlxpw(TransmissionDownshiftTestSequ_U.throttle,
          rtb_out, TransmissionDownshiftTestSequ_P.upth,
          TransmissionDownshiftTestSequ_P.interp_up_bp02Data,
          TransmissionDownshiftTestSequ_P.uptab,
          TransmissionDownshiftTestSequ_P.interp_up_maxIndex, 6U);

        /* End of Outputs for SubSystem: '<S1>/selection_state.calc_th' */
        switch (TransmissionDownshiftTest_DWork.is_selection_state) {
         case TransmissionDow_IN_downshifting:
          if ((TransmissionDownshiftTest_DWork.temporalCounter_i1 >=
               TransmissionDownshiftTestSequ_P.shift_controller_TWAIT) && (mph <=
               interp_down)) {
            sfEvent = TransmissionDownshif_event_DOWN;
            if (TransmissionDownshiftTest_DWork.is_active_gear_state != 0U) {
              TransmissionDownshif_gear_state(&sfEvent);
            }

            TransmissionDownshiftTest_DWork.is_selection_state =
              TransmissionDow_IN_steady_state;
          } else {
            if (mph > interp_down) {
              TransmissionDownshiftTest_DWork.is_selection_state =
                TransmissionDow_IN_steady_state;
            }
          }
          break;

         case TransmissionDow_IN_steady_state:
          if (mph > rtb_out) {
            TransmissionDownshiftTest_DWork.is_selection_state =
              TransmissionDowns_IN_upshifting;
            TransmissionDownshiftTest_DWork.temporalCounter_i1 = 0U;
          } else {
            if (mph < interp_down) {
              TransmissionDownshiftTest_DWork.is_selection_state =
                TransmissionDow_IN_downshifting;
              TransmissionDownshiftTest_DWork.temporalCounter_i1 = 0U;
            }
          }
          break;

         case TransmissionDowns_IN_upshifting:
          if ((TransmissionDownshiftTest_DWork.temporalCounter_i1 >=
               TransmissionDownshiftTestSequ_P.shift_controller_TWAIT) && (mph >=
               rtb_out)) {
            sfEvent = TransmissionDownshiftT_event_UP;
            if (TransmissionDownshiftTest_DWork.is_active_gear_state != 0U) {
              TransmissionDownshif_gear_state(&sfEvent);
            }

            TransmissionDownshiftTest_DWork.is_selection_state =
              TransmissionDow_IN_steady_state;
          } else {
            if (mph < rtb_out) {
              TransmissionDownshiftTest_DWork.is_selection_state =
                TransmissionDow_IN_steady_state;
            }
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          TransmissionDownshiftTest_DWork.is_selection_state =
            Transmission_IN_NO_ACTIVE_CHILD;
          break;
        }
      }
    }

    /* End of Chart: '<Root>/shift_controller' */

    /* MATLAB Function: '<S9>/Look-Up Table' */
    switch (TransmissionDownshiftTestSequ_B.gear) {
     case gearType_fourth:
      TransmissionDownshiftTestSequ_B.out = 0.677;
      break;

     case gearType_third:
      TransmissionDownshiftTestSequ_B.out = 1.0;
      break;

     case gearType_second:
      TransmissionDownshiftTestSequ_B.out = 1.45;
      break;

     default:
      TransmissionDownshiftTestSequ_B.out = 2.393;
      break;
    }

    /* End of MATLAB Function: '<S9>/Look-Up Table' */
  }

  /* Integrator: '<S5>/Integrator' */
  /* Limited  Integrator  */
  if (TransmissionDownshiftTestSequ_X.Integrator_CSTATE >=
      TransmissionDownshiftTestSequ_P.Integrator_UpperSat) {
    TransmissionDownshiftTestSequ_X.Integrator_CSTATE =
      TransmissionDownshiftTestSequ_P.Integrator_UpperSat;
  } else {
    if (TransmissionDownshiftTestSequ_X.Integrator_CSTATE <=
        TransmissionDownshiftTestSequ_P.Integrator_LowerSat) {
      TransmissionDownshiftTestSequ_X.Integrator_CSTATE =
        TransmissionDownshiftTestSequ_P.Integrator_LowerSat;
    }
  }

  /* Product: '<S8>/speed ratio' incorporates:
   *  Gain: '<S6>/final drive ratio2'
   *  Integrator: '<S5>/Integrator'
   *  Integrator: '<S6>/wheel speed'
   *  Product: '<S9>/Product1'
   */
  interp_down = TransmissionDownshiftTestSequ_P.vehicledata[0] *
    TransmissionDownshiftTestSequ_X.wheelspeed_CSTATE *
    TransmissionDownshiftTestSequ_B.out /
    TransmissionDownshiftTestSequ_X.Integrator_CSTATE;

  /* Fcn: '<S8>/impeller' incorporates:
   *  Integrator: '<S5>/Integrator'
   *  Lookup_n-D: '<S8>/K factor'
   *  Product: '<S8>/quotient'
   */
  rtb_out = pow(TransmissionDownshiftTestSequ_X.Integrator_CSTATE /
                look1_binlxpw(interp_down,
    TransmissionDownshiftTestSequ_P.TorqueConverter_speedratio,
    TransmissionDownshiftTestSequ_P.TorqueConverter_Kfactor, 20U), 2.0);

  /* Gain: '<S5>/engine + impeller inertia' incorporates:
   *  Fcn: '<S8>/impeller'
   *  Inport: '<Root>/throttle'
   *  Integrator: '<S5>/Integrator'
   *  Lookup_n-D: '<S5>/engine torque'
   *  Sum: '<S5>/Sum'
   */
  TransmissionDownshiftTestSequ_B.engineimpellerinertia = 1.0 /
    TransmissionDownshiftTestSequ_P.Iei * (look2_binlxpw
    (TransmissionDownshiftTestSequ_U.throttle,
     TransmissionDownshiftTestSequ_X.Integrator_CSTATE,
     TransmissionDownshiftTestSequ_P.thvec,
     TransmissionDownshiftTestSequ_P.nevec, TransmissionDownshiftTestSequ_P.emap,
     TransmissionDownshiftTestSequ_P.enginetorque_maxIndex, 10U) - rtb_out);

  /* Lookup_n-D: '<S8>/Torque ratio' */
  interp_down = look1_binlxpw(interp_down,
    TransmissionDownshiftTestSequ_P.TorqueConverter_speedratio,
    TransmissionDownshiftTestSequ_P.TorqueConverter_Torkratio, 20U);

  /* Signum: '<S6>/Sign' */
  if (mph < 0.0) {
    mph_0 = -1.0;
  } else if (mph > 0.0) {
    mph_0 = 1.0;
  } else {
    mph_0 = mph;
  }

  /* End of Signum: '<S6>/Sign' */

  /* Gain: '<S6>/vehicle inertia' incorporates:
   *  Fcn: '<S6>/road load'
   *  Fcn: '<S8>/impeller'
   *  Gain: '<S6>/final drive ratio1'
   *  Inport: '<Root>/brake'
   *  Product: '<S6>/signed load'
   *  Product: '<S8>/turbine'
   *  Product: '<S9>/Product'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S6>/Sum1'
   */
  TransmissionDownshiftTestSequ_B.vehicleinertia = (rtb_out * interp_down *
    TransmissionDownshiftTestSequ_B.out *
    TransmissionDownshiftTestSequ_P.vehicledata[0] - ((0.3 * pow(mph, 2.0) +
    40.0) + TransmissionDownshiftTestSequ_U.brake) * mph_0) * (1.0 /
    TransmissionDownshiftTestSequ_P.vehicledata[4]);
  if (rtmIsMajorTimeStep(TransmissionDownshiftTestSeq_M) &&
      TransmissionDownshiftTestSeq_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Outport: '<Root>/Out2' incorporates:
   *  Inport: '<Root>/throttle'
   */
  TransmissionDownshiftTestSequ_Y.Out2 =
    TransmissionDownshiftTestSequ_U.throttle;
}

/* Model update function */
void TransmissionDownshiftTestSequence_update(void)
{
  if (rtmIsMajorTimeStep(TransmissionDownshiftTestSeq_M)) {
    rt_ertODEUpdateContinuousStates(&TransmissionDownshiftTestSeq_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TransmissionDownshiftTestSeq_M->Timing.clockTick0)) {
    ++TransmissionDownshiftTestSeq_M->Timing.clockTickH0;
  }

  TransmissionDownshiftTestSeq_M->Timing.t[0] = rtsiGetSolverStopTime
    (&TransmissionDownshiftTestSeq_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    TransmissionDownshiftTestSeq_M->Timing.clockTick1++;
    if (!TransmissionDownshiftTestSeq_M->Timing.clockTick1) {
      TransmissionDownshiftTestSeq_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void TransmissionDownshiftTestSequence_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  StateDerivatives_TransmissionDo *_rtXdot;
  _rtXdot = ((StateDerivatives_TransmissionDo *)
             TransmissionDownshiftTestSeq_M->derivs);

  /* Derivatives for Integrator: '<S6>/wheel speed' */
  _rtXdot->wheelspeed_CSTATE = TransmissionDownshiftTestSequ_B.vehicleinertia;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  lsat = (TransmissionDownshiftTestSequ_X.Integrator_CSTATE <=
          TransmissionDownshiftTestSequ_P.Integrator_LowerSat);
  usat = (TransmissionDownshiftTestSequ_X.Integrator_CSTATE >=
          TransmissionDownshiftTestSequ_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat &&
       (TransmissionDownshiftTestSequ_B.engineimpellerinertia > 0.0)) || (usat &&
       (TransmissionDownshiftTestSequ_B.engineimpellerinertia < 0.0))) {
    _rtXdot->Integrator_CSTATE =
      TransmissionDownshiftTestSequ_B.engineimpellerinertia;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S5>/Integrator' */
}

/* Model initialize function */
void TransmissionDownshiftTestSequence_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TransmissionDownshiftTestSeq_M->solverInfo,
                          &TransmissionDownshiftTestSeq_M->Timing.simTimeStep);
    rtsiSetTPtr(&TransmissionDownshiftTestSeq_M->solverInfo, &rtmGetTPtr
                (TransmissionDownshiftTestSeq_M));
    rtsiSetStepSizePtr(&TransmissionDownshiftTestSeq_M->solverInfo,
                       &TransmissionDownshiftTestSeq_M->Timing.stepSize0);
    rtsiSetdXPtr(&TransmissionDownshiftTestSeq_M->solverInfo,
                 &TransmissionDownshiftTestSeq_M->derivs);
    rtsiSetContStatesPtr(&TransmissionDownshiftTestSeq_M->solverInfo, (real_T **)
                         &TransmissionDownshiftTestSeq_M->contStates);
    rtsiSetNumContStatesPtr(&TransmissionDownshiftTestSeq_M->solverInfo,
      &TransmissionDownshiftTestSeq_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TransmissionDownshiftTestSeq_M->solverInfo,
      &TransmissionDownshiftTestSeq_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&TransmissionDownshiftTestSeq_M->solverInfo,
       &TransmissionDownshiftTestSeq_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&TransmissionDownshiftTestSeq_M->solverInfo,
       &TransmissionDownshiftTestSeq_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&TransmissionDownshiftTestSeq_M->solverInfo,
                          (&rtmGetErrorStatus(TransmissionDownshiftTestSeq_M)));
    rtsiSetRTModelPtr(&TransmissionDownshiftTestSeq_M->solverInfo,
                      TransmissionDownshiftTestSeq_M);
  }

  rtsiSetSimTimeStep(&TransmissionDownshiftTestSeq_M->solverInfo,
                     MAJOR_TIME_STEP);
  TransmissionDownshiftTestSeq_M->intgData.f[0] =
    TransmissionDownshiftTestSeq_M->odeF[0];
  TransmissionDownshiftTestSeq_M->contStates = ((ContinuousStates_TransmissionDo
    *) &TransmissionDownshiftTestSequ_X);
  rtsiSetSolverData(&TransmissionDownshiftTestSeq_M->solverInfo, (void *)
                    &TransmissionDownshiftTestSeq_M->intgData);
  rtsiSetSolverName(&TransmissionDownshiftTestSeq_M->solverInfo,"ode1");
  rtmSetTPtr(TransmissionDownshiftTestSeq_M,
             &TransmissionDownshiftTestSeq_M->Timing.tArray[0]);
  TransmissionDownshiftTestSeq_M->Timing.stepSize0 = 0.01;

  /* InitializeConditions for Integrator: '<S6>/wheel speed' */
  TransmissionDownshiftTestSequ_X.wheelspeed_CSTATE =
    TransmissionDownshiftTestSequ_P.vehicledata[5] /
    TransmissionDownshiftTestSequ_P.vehicledata[3] *
    TransmissionDownshiftTestSequ_P.vehicledata[0] /
    TransmissionDownshiftTestSequ_P.vehicledata[0];

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  TransmissionDownshiftTestSequ_X.Integrator_CSTATE =
    TransmissionDownshiftTestSequ_P.Integrator_IC;

  /* SystemInitialize for Chart: '<Root>/shift_controller' */
  TransmissionDownshiftTestSequ_B.gear = gearType_None;
}

/* Model terminate function */
void TransmissionDownshiftTestSequence_terminate(void)
{
  /* (no terminate code required) */
}

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
