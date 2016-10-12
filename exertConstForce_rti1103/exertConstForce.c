/*
 * exertConstForce.c
 *
 * Real-Time Workshop code generation for Simulink model "exertConstForce.mdl".
 *
 * Model version              : 1.20
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Tue Sep 20 16:57:36 2016
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "exertConstForce_trc_ptr.h"
#include "exertConstForce.h"
#include "exertConstForce_private.h"

/* Block signals (auto storage) */
BlockIO_exertConstForce exertConstForce_B;

/* Block states (auto storage) */
D_Work_exertConstForce exertConstForce_DWork;

/* Real-time model */
RT_MODEL_exertConstForce exertConstForce_M_;
RT_MODEL_exertConstForce *exertConstForce_M = &exertConstForce_M_;

/* Model output function */
static void exertConstForce_output(int_T tid)
{
  int32_T tmp;
  int32_T tmp_0;

  /* S-Function (rti_commonblock): '<S7>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/channel5' */
  exertConstForce_B.channel5 = exertConstForce_P.channel5_Gain *
    exertConstForce_B.SFunction;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/uForce'
   *  Constant: '<Root>/uNoForce'
   */
  if (exertConstForce_B.channel5 > exertConstForce_P.Switch_Threshold) {
    exertConstForce_B.Switch = exertConstForce_P.uNoForce_Value;
  } else {
    exertConstForce_B.Switch = exertConstForce_P.uForce_Value;
  }

  /* Product: '<Root>/u1' incorporates:
   *  Constant: '<Root>/Reset'
   */
  exertConstForce_B.u1 = exertConstForce_B.Switch *
    exertConstForce_P.Reset_Value;

  /* S-Function (rti_commonblock): '<S5>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(2, exertConstForce_B.u1);

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' */
  exertConstForce_B.VectorConcatenate[0] = exertConstForce_B.channel5;

  /* S-Function (rti_commonblock): '<S1>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S3>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S4>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S8>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/channel9' */
  exertConstForce_B.VectorConcatenate[1] = exertConstForce_P.channel9_Gain *
    exertConstForce_B.SFunction_j;

  /* Gain: '<Root>/channel17' */
  exertConstForce_B.VectorConcatenate[2] = exertConstForce_P.channel17_Gain *
    exertConstForce_B.SFunction_i;

  /* Gain: '<Root>/channel18' */
  exertConstForce_B.VectorConcatenate[3] = exertConstForce_P.channel18_Gain *
    exertConstForce_B.SFunction_f;

  /* Gain: '<Root>/channel19' */
  exertConstForce_B.VectorConcatenate[4] = exertConstForce_P.channel19_Gain *
    exertConstForce_B.SFunction_e;

  /* Gain: '<Root>/channel20' */
  exertConstForce_B.VectorConcatenate[5] = exertConstForce_P.channel20_Gain *
    exertConstForce_B.SFunction_k;

  /* Product: '<Root>/Matrix Multiply' incorporates:
   *  Constant: '<Root>/Constant'
   */
  for (tmp = 0; tmp < 6; tmp++) {
    exertConstForce_B.MatrixMultiply[tmp] = 0.0;
    for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
      exertConstForce_B.MatrixMultiply[tmp] = exertConstForce_P.Constant_Value[6
        * tmp_0 + tmp] * exertConstForce_B.VectorConcatenate[tmp_0] +
        exertConstForce_B.MatrixMultiply[tmp];
    }
  }

  /* Gain: '<Root>/GainFx' */
  exertConstForce_B.GainFx = exertConstForce_P.GainFx_Gain *
    exertConstForce_B.MatrixMultiply[0];

  /* Gain: '<Root>/GainFy' */
  exertConstForce_B.GainFy = exertConstForce_P.GainFy_Gain *
    exertConstForce_B.MatrixMultiply[1];

  /* Gain: '<Root>/GainFz' */
  exertConstForce_B.GainFz = exertConstForce_P.GainFz_Gain *
    exertConstForce_B.MatrixMultiply[2];

  /* Gain: '<Root>/GainMx' */
  exertConstForce_B.GainMx = exertConstForce_P.GainMx_Gain *
    exertConstForce_B.MatrixMultiply[3];

  /* Gain: '<Root>/GainMy' */
  exertConstForce_B.GainMy = exertConstForce_P.GainMy_Gain *
    exertConstForce_B.MatrixMultiply[4];

  /* Gain: '<Root>/GainMz' */
  exertConstForce_B.GainMz = exertConstForce_P.GainMz_Gain *
    exertConstForce_B.MatrixMultiply[5];

  /* Signal Processing Blockset Variable Selector (sdspperm2) - '<Root>/Variable Selector' */
  /* Permute rows port 0 input rows = 6, output rows = 1 */
  {
    int32_T i_idx = (int32_T)(exertConstForce_P.ID_Value - 1);

    /* Clip bad index */
    if (i_idx < 0) {
      i_idx = 0;
    } else if (i_idx > 5) {
      i_idx = 5;
    }

    exertConstForce_B.VariableSelector = exertConstForce_B.MatrixMultiply[i_idx];
  }

  /* S-Function (rti_commonblock): '<S12>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S12>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<S9>/encGainY' */
  exertConstForce_B.encGainY = exertConstForce_P.encGainY_Gain *
    exertConstForce_B.SFunction1;

  /* SampleTimeMath: '<S11>/TSamp'
   *
   * About '<S11>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  exertConstForce_B.TSamp = exertConstForce_B.encGainY *
    exertConstForce_P.TSamp_WtEt;

  /* UnitDelay: '<S11>/UD' */
  exertConstForce_B.Uk1 = exertConstForce_DWork.UD_DSTATE;

  /* Sum: '<S11>/Diff' */
  exertConstForce_B.Diff = exertConstForce_B.TSamp - exertConstForce_B.Uk1;

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function3' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function4' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function5' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function6' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function7' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* user code (Output function Trailer) */

  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  {
    host_service(1, rtk_current_task_absolute_time_ptr_get());
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void exertConstForce_update(int_T tid)
{
  /* Update for UnitDelay: '<S11>/UD' */
  exertConstForce_DWork.UD_DSTATE = exertConstForce_B.TSamp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++exertConstForce_M->Timing.clockTick0)) {
    ++exertConstForce_M->Timing.clockTickH0;
  }

  exertConstForce_M->Timing.t[0] = exertConstForce_M->Timing.clockTick0 *
    exertConstForce_M->Timing.stepSize0 + exertConstForce_M->Timing.clockTickH0 *
    exertConstForce_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void exertConstForce_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)exertConstForce_M, 0,
                sizeof(RT_MODEL_exertConstForce));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = exertConstForce_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    exertConstForce_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    exertConstForce_M->Timing.sampleTimes =
      (&exertConstForce_M->Timing.sampleTimesArray[0]);
    exertConstForce_M->Timing.offsetTimes =
      (&exertConstForce_M->Timing.offsetTimesArray[0]);

    /* task periods */
    exertConstForce_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    exertConstForce_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(exertConstForce_M, &exertConstForce_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = exertConstForce_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    exertConstForce_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(exertConstForce_M, -1);
  exertConstForce_M->Timing.stepSize0 = 0.001;
  exertConstForce_M->solverInfoPtr = (&exertConstForce_M->solverInfo);
  exertConstForce_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&exertConstForce_M->solverInfo, 0.001);
  rtsiSetSolverMode(&exertConstForce_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  exertConstForce_M->ModelData.blockIO = ((void *) &exertConstForce_B);
  (void) memset(((void *) &exertConstForce_B), 0,
                sizeof(BlockIO_exertConstForce));

  /* parameters */
  exertConstForce_M->ModelData.defaultParam = ((real_T *)&exertConstForce_P);

  /* states (dwork) */
  exertConstForce_M->Work.dwork = ((void *) &exertConstForce_DWork);
  (void) memset((void *)&exertConstForce_DWork, 0,
                sizeof(D_Work_exertConstForce));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void exertConstForce_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  exertConstForce_output(tid);
}

void MdlUpdate(int_T tid)
{
  exertConstForce_update(tid);
}

void MdlInitializeSizes(void)
{
  exertConstForce_M->Sizes.numContStates = (0);/* Number of continuous states */
  exertConstForce_M->Sizes.numY = (0); /* Number of model outputs */
  exertConstForce_M->Sizes.numU = (0); /* Number of model inputs */
  exertConstForce_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  exertConstForce_M->Sizes.numSampTimes = (1);/* Number of sample times */
  exertConstForce_M->Sizes.numBlocks = (46);/* Number of blocks */
  exertConstForce_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  exertConstForce_M->Sizes.numBlockPrms = (56);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for UnitDelay: '<S11>/UD' */
  exertConstForce_DWork.UD_DSTATE = exertConstForce_P.UD_X0;
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  exertConstForce_terminate();
}

RT_MODEL_exertConstForce *exertConstForce(void)
{
  exertConstForce_initialize(1);
  return exertConstForce_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
