/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
 ********************************************************************
 * Program: sltestCruiseControlDefective
 * File: sltestCruiseControlDefective.c
 * Author: The MathWorks, Inc.
 * Created: Wed Aug 30 21:41:02 2006
 ********************************************************************
 * Implementation of program sltestCruiseControlDefective
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink  V6.1.0
 * (ERT based)
 ********************************************************************/

#include "sltestCruiseControlDefective.h"
#include "sltestCruiseControlDefective_private.h"

/*  Defines */

/*  Data Types */

/**************************** GLOBAL DATA *************************************/
/*  Definitions */

/* Block signals (default storage) */
BlockIO_sltestCruiseControlDefe sltestCruiseControlDefective_B;

/* Block states (default storage) */
D_Work_sltestCruiseControlDefec sltestCruiseControlDefect_DWork;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_sltestCruiseCon sltestCruiseControlDefective_Y;

/* Real-time model */
RT_MODEL_sltestCruiseControlDef sltestCruiseControlDefective_M_;
RT_MODEL_sltestCruiseControlDef *const sltestCruiseControlDefective_M =
  &sltestCruiseControlDefective_M_;

/*  Declarations  */

/***************************** FILE SCOPE DATA ********************************/

/*************************** FUNCTIONS ****************************************/

/* Model output function */
void sltestCruiseControlDefective_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs[6];

  /* FromWorkspace: '<S2>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      sltestCruiseControlDefect_DWork.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      sltestCruiseControlDefect_DWork.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = sltestCruiseControlDefect_DWork.FromWs_IWORK.PrevIndex;
    real_T t = sltestCruiseControlDefective_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[105]) {
      currTimeIndex = 104;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    sltestCruiseControlDefect_DWork.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex];
              pDataValues += 106;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex + 1];
              pDataValues += 106;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 6; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&rtb_FromWs[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 106;
          }
        }
      }
    }
  }

  /* Switch: '<S1>/Switch1' incorporates:
   *  DataTypeConversion: '<S4>/Cast4'
   *  DataTypeConversion: '<S4>/Cast5'
   *  DataTypeConversion: '<S4>/Cast6'
   *  Switch: '<S1>/Switch2'
   *  Switch: '<S1>/Switch3'
   */
  if (rtb_FromWs[3] != 0.0) {
    /* Outport: '<Root>/target' incorporates:
     *  DataTypeConversion: '<S4>/Cast1'
     */
    sltestCruiseControlDefective_Y.target = rtb_FromWs[0];
  } else if (rtb_FromWs[4] != 0.0) {
    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Outport: '<Root>/target'
     *  Sum: '<S1>/Sum'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    sltestCruiseControlDefective_Y.target =
      sltestCruiseControlDefective_P.Constant1_Value +
      sltestCruiseControlDefect_DWork.UnitDelay_DSTATE;
  } else if (rtb_FromWs[5] != 0.0) {
    /* Switch: '<S1>/Switch3' incorporates:
     *  Constant: '<S1>/Constant3'
     *  Outport: '<Root>/target'
     *  Sum: '<S1>/Sum2'
     *  Switch: '<S1>/Switch2'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    sltestCruiseControlDefective_Y.target =
      sltestCruiseControlDefect_DWork.UnitDelay_DSTATE -
      sltestCruiseControlDefective_P.Constant3_Value;
  } else {
    /* Outport: '<Root>/target' incorporates:
     *  Switch: '<S1>/Switch2'
     *  Switch: '<S1>/Switch3'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    sltestCruiseControlDefective_Y.target =
      sltestCruiseControlDefect_DWork.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  DataTypeConversion: '<S4>/Cast1'
   *  Outport: '<Root>/target'
   */
  sltestCruiseControlDefective_B.Sum1 = sltestCruiseControlDefective_Y.target -
    rtb_FromWs[0];

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S4>/Cast2'
   *  DataTypeConversion: '<S4>/Cast3'
   *  DataTypeConversion: '<S4>/Cast4'
   *  Logic: '<S1>/Logical Operator1'
   *  Logic: '<S1>/Logical Operator2'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  sltestCruiseControlDefective_B.ActiveControl = ((rtb_FromWs[1] != 0.0) &&
    (rtb_FromWs[2] == 0.0) && ((rtb_FromWs[3] != 0.0) ||
    sltestCruiseControlDefect_DWork.UnitDelay1_DSTATE));

  /* Outputs for Enabled SubSystem: '<S1>/PI Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (sltestCruiseControlDefective_B.ActiveControl) {
    /* Outport: '<Root>/throt' incorporates:
     *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
     *  Gain: '<S5>/Kp'
     *  Gain: '<S5>/Kp1'
     *  Sum: '<S5>/Sum'
     */
    sltestCruiseControlDefective_Y.throt =
      sltestCruiseControlDefective_P.Kp_Gain *
      sltestCruiseControlDefective_B.Sum1 +
      sltestCruiseControlDefective_P.Kp1_Gain *
      sltestCruiseControlDefect_DWork.DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Outputs for SubSystem: '<S1>/PI Controller' */

  /* S-Function (bur_out): '<S1>/Output' */
  Active_Control = sltestCruiseControlDefective_B.ActiveControl;
}

/* Model update function */
void sltestCruiseControlDefective_update(void)
{
  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Outport: '<Root>/target'
   */
  sltestCruiseControlDefect_DWork.UnitDelay_DSTATE =
    sltestCruiseControlDefective_Y.target;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  sltestCruiseControlDefect_DWork.UnitDelay1_DSTATE =
    sltestCruiseControlDefective_B.ActiveControl;

  /* Update for Enabled SubSystem: '<S1>/PI Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (sltestCruiseControlDefective_B.ActiveControl) {
    /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    sltestCruiseControlDefect_DWork.DiscreteTimeIntegrator_DSTATE +=
      sltestCruiseControlDefective_P.DiscreteTimeIntegrator_gainval *
      sltestCruiseControlDefective_B.Sum1;
    if (sltestCruiseControlDefect_DWork.DiscreteTimeIntegrator_DSTATE >=
        sltestCruiseControlDefective_P.DiscreteTimeIntegrator_UpperSat) {
      sltestCruiseControlDefect_DWork.DiscreteTimeIntegrator_DSTATE =
        sltestCruiseControlDefective_P.DiscreteTimeIntegrator_UpperSat;
    } else {
      if (sltestCruiseControlDefect_DWork.DiscreteTimeIntegrator_DSTATE <=
          sltestCruiseControlDefective_P.DiscreteTimeIntegrator_LowerSat) {
        sltestCruiseControlDefect_DWork.DiscreteTimeIntegrator_DSTATE =
          sltestCruiseControlDefective_P.DiscreteTimeIntegrator_LowerSat;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  }

  /* End of Update for SubSystem: '<S1>/PI Controller' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sltestCruiseControlDefective_M->Timing.clockTick0)) {
    ++sltestCruiseControlDefective_M->Timing.clockTickH0;
  }

  sltestCruiseControlDefective_M->Timing.t[0] =
    sltestCruiseControlDefective_M->Timing.clockTick0 *
    sltestCruiseControlDefective_M->Timing.stepSize0 +
    sltestCruiseControlDefective_M->Timing.clockTickH0 *
    sltestCruiseControlDefective_M->Timing.stepSize0 * 4294967296.0;

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
    sltestCruiseControlDefective_M->Timing.clockTick1++;
    if (!sltestCruiseControlDefective_M->Timing.clockTick1) {
      sltestCruiseControlDefective_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void sltestCruiseControlDefective_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sltestCruiseControlDefective_M->solverInfo,
                          &sltestCruiseControlDefective_M->Timing.simTimeStep);
    rtsiSetTPtr(&sltestCruiseControlDefective_M->solverInfo, &rtmGetTPtr
                (sltestCruiseControlDefective_M));
    rtsiSetStepSizePtr(&sltestCruiseControlDefective_M->solverInfo,
                       &sltestCruiseControlDefective_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&sltestCruiseControlDefective_M->solverInfo,
                          (&rtmGetErrorStatus(sltestCruiseControlDefective_M)));
    rtsiSetRTModelPtr(&sltestCruiseControlDefective_M->solverInfo,
                      sltestCruiseControlDefective_M);
  }

  rtsiSetSimTimeStep(&sltestCruiseControlDefective_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&sltestCruiseControlDefective_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(sltestCruiseControlDefective_M,
             &sltestCruiseControlDefective_M->Timing.tArray[0]);
  sltestCruiseControlDefective_M->Timing.stepSize0 = 0.01;

  /* Start for FromWorkspace: '<S2>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.01, 0.02, 0.02, 0.03, 0.03,
      0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15,
      0.16, 0.17, 0.18, 0.19, 0.2, 0.2, 0.21, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26,
      0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.38,
      0.39, 0.4, 0.41, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.5, 0.51,
      0.52, 0.53, 0.54, 0.55, 0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63,
      0.64, 0.65, 0.66, 0.67, 0.68, 0.69, 0.7, 0.71, 0.72, 0.73, 0.74, 0.75,
      0.76, 0.77, 0.78, 0.79, 0.8, 0.81, 0.82, 0.83, 0.84, 0.85, 0.86, 0.87,
      0.88, 0.89, 0.9, 0.91, 0.92, 0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.0
    } ;

    static real_T pDataValues0[] = { 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
      40.0, 40.0, 40.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.95000000000000007, -0.05, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    sltestCruiseControlDefect_DWork.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    sltestCruiseControlDefect_DWork.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    sltestCruiseControlDefect_DWork.FromWs_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  sltestCruiseControlDefect_DWork.UnitDelay_DSTATE =
    sltestCruiseControlDefective_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
  sltestCruiseControlDefect_DWork.UnitDelay1_DSTATE =
    sltestCruiseControlDefective_P.UnitDelay1_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S1>/PI Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  sltestCruiseControlDefect_DWork.DiscreteTimeIntegrator_DSTATE =
    sltestCruiseControlDefective_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for Outport: '<Root>/throt' incorporates:
   *  Outport: '<S5>/throt'
   */
  sltestCruiseControlDefective_Y.throt = sltestCruiseControlDefective_P.throt_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/PI Controller' */
}

/* Model terminate function */
void sltestCruiseControlDefective_terminate(void)
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
