/*
 * exertConstForce2.c
 *
 * Real-Time Workshop code generation for Simulink model "exertConstForce2.mdl".
 *
 * Model version              : 1.33
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Sun Oct 09 18:43:40 2016
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "exertConstForce2_trc_ptr.h"
#include "exertConstForce2.h"
#include "exertConstForce2_private.h"

/* Block signals (auto storage) */
BlockIO_exertConstForce2 exertConstForce2_B;

/* Block states (auto storage) */
D_Work_exertConstForce2 exertConstForce2_DWork;

/* Real-time model */
RT_MODEL_exertConstForce2 exertConstForce2_M_;
RT_MODEL_exertConstForce2 *exertConstForce2_M = &exertConstForce2_M_;

/* Model output function */
static void exertConstForce2_output(int_T tid)
{
  int32_T tmp;
  int32_T tmp_0;

  /* S-Function (rti_commonblock): '<S15>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<S10>/encGainY' */
  exertConstForce2_B.encGainY = exertConstForce2_P.encGainY_Gain *
    exertConstForce2_B.SFunction1;

  /* SampleTimeMath: '<S12>/TSamp'
   *
   * About '<S12>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  exertConstForce2_B.TSamp = exertConstForce2_B.encGainY *
    exertConstForce2_P.TSamp_WtEt;

  /* UnitDelay: '<S12>/UD' */
  exertConstForce2_B.Uk1 = exertConstForce2_DWork.UD_DSTATE;

  /* Sum: '<S12>/Diff' */
  exertConstForce2_B.Diff = exertConstForce2_B.TSamp - exertConstForce2_B.Uk1;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  exertConstForce2_B.Compare = (exertConstForce2_B.Diff <
    exertConstForce2_P.Constant_Value);

  /* Memory: '<Root>/Memory' */
  exertConstForce2_B.Memory = exertConstForce2_DWork.Memory_PreviousInput;

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   */
  exertConstForce2_B.Compare_g = (exertConstForce2_B.Memory >
    exertConstForce2_P.Constant_Value_a);

  /* Product: '<Root>/Product1' */
  exertConstForce2_B.Product1 = (uint16_T)(exertConstForce2_B.Compare *
    exertConstForce2_B.Compare_g);

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  exertConstForce2_B.Compare_o = (exertConstForce2_B.Product1 ==
    exertConstForce2_P.Constant_Value_k);

  /* Gain: '<Root>/motionInd1' */
  exertConstForce2_B.motionInd1 = (uint16_T)(exertConstForce2_P.motionInd1_Gain *
    exertConstForce2_B.Compare_o);

  /* Gain: '<Root>/motionInd2' */
  exertConstForce2_B.motionInd2 = (uint32_T)exertConstForce2_P.motionInd2_Gain *
    (uint32_T)exertConstForce2_B.Product1;

  /* Sum: '<Root>/Add' */
  exertConstForce2_B.Add = (uint32_T)(exertConstForce2_B.motionInd1 << 7) +
    exertConstForce2_B.motionInd2;

  /* DataTypeConversion: '<Root>/index' */
  exertConstForce2_B.index = ldexp((real_T)exertConstForce2_B.Add, -14);

  /* Signal Processing Blockset Variable Selector (sdspperm2) - '<Root>/inpU' */
  /* Permute rows port 0 input rows = 2, output rows = 1 */
  {
    int32_T i_idx = (int32_T)(exertConstForce2_B.index - 1);

    /* Clip bad index */
    if (i_idx < 0) {
      i_idx = 0;
    } else if (i_idx > 1) {
      i_idx = 1;
    }

    exertConstForce2_B.inpU = exertConstForce2_P.Constant1_Value[i_idx];
  }

  /* Product: '<Root>/u1' incorporates:
   *  Constant: '<Root>/Reset'
   */
  exertConstForce2_B.u1 = exertConstForce2_B.inpU *
    exertConstForce2_P.Reset_Value;

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(2, exertConstForce2_B.u1);

  /* S-Function (rti_commonblock): '<S15>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S3>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S4>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S5>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S8>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S9>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/channel5' */
  exertConstForce2_B.VectorConcatenate[0] = exertConstForce2_P.channel5_Gain *
    exertConstForce2_B.SFunction_eb;

  /* Gain: '<Root>/channel9' */
  exertConstForce2_B.VectorConcatenate[1] = exertConstForce2_P.channel9_Gain *
    exertConstForce2_B.SFunction_d;

  /* Gain: '<Root>/channel17' */
  exertConstForce2_B.VectorConcatenate[2] = exertConstForce2_P.channel17_Gain *
    exertConstForce2_B.SFunction;

  /* Gain: '<Root>/channel18' */
  exertConstForce2_B.VectorConcatenate[3] = exertConstForce2_P.channel18_Gain *
    exertConstForce2_B.SFunction_e;

  /* Gain: '<Root>/channel19' */
  exertConstForce2_B.VectorConcatenate[4] = exertConstForce2_P.channel19_Gain *
    exertConstForce2_B.SFunction_j;

  /* Gain: '<Root>/channel20' */
  exertConstForce2_B.VectorConcatenate[5] = exertConstForce2_P.channel20_Gain *
    exertConstForce2_B.SFunction_jn;

  /* Product: '<Root>/Matrix Multiply' incorporates:
   *  Constant: '<Root>/Constant'
   */
  for (tmp = 0; tmp < 6; tmp++) {
    exertConstForce2_B.MatrixMultiply[tmp] = 0.0;
    for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
      exertConstForce2_B.MatrixMultiply[tmp] =
        exertConstForce2_P.Constant_Value_b[6 * tmp_0 + tmp] *
        exertConstForce2_B.VectorConcatenate[tmp_0] +
        exertConstForce2_B.MatrixMultiply[tmp];
    }
  }

  /* Gain: '<Root>/GainFx' */
  exertConstForce2_B.GainFx = exertConstForce2_P.GainFx_Gain *
    exertConstForce2_B.MatrixMultiply[0];

  /* Gain: '<Root>/GainFy' */
  exertConstForce2_B.GainFy = exertConstForce2_P.GainFy_Gain *
    exertConstForce2_B.MatrixMultiply[1];

  /* Gain: '<Root>/GainFz' */
  exertConstForce2_B.GainFz = exertConstForce2_P.GainFz_Gain *
    exertConstForce2_B.MatrixMultiply[2];

  /* Gain: '<Root>/GainMx' */
  exertConstForce2_B.GainMx = exertConstForce2_P.GainMx_Gain *
    exertConstForce2_B.MatrixMultiply[3];

  /* Gain: '<Root>/GainMy' */
  exertConstForce2_B.GainMy = exertConstForce2_P.GainMy_Gain *
    exertConstForce2_B.MatrixMultiply[4];

  /* Gain: '<Root>/GainMz' */
  exertConstForce2_B.GainMz = exertConstForce2_P.GainMz_Gain *
    exertConstForce2_B.MatrixMultiply[5];

  /* Signal Processing Blockset Variable Selector (sdspperm2) - '<Root>/Variable Selector' */
  /* Permute rows port 0 input rows = 6, output rows = 1 */
  {
    int32_T i_idx = (int32_T)(exertConstForce2_P.ID_Value - 1);

    /* Clip bad index */
    if (i_idx < 0) {
      i_idx = 0;
    } else if (i_idx > 5) {
      i_idx = 5;
    }

    exertConstForce2_B.VariableSelector =
      exertConstForce2_B.MatrixMultiply[i_idx];
  }

  /* S-Function (rti_commonblock): '<S7>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function3' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function4' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function5' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function6' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function7' */
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
static void exertConstForce2_update(int_T tid)
{
  /* Update for UnitDelay: '<S12>/UD' */
  exertConstForce2_DWork.UD_DSTATE = exertConstForce2_B.TSamp;

  /* Update for Memory: '<Root>/Memory' */
  exertConstForce2_DWork.Memory_PreviousInput = exertConstForce2_B.u1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++exertConstForce2_M->Timing.clockTick0)) {
    ++exertConstForce2_M->Timing.clockTickH0;
  }

  exertConstForce2_M->Timing.t[0] = exertConstForce2_M->Timing.clockTick0 *
    exertConstForce2_M->Timing.stepSize0 +
    exertConstForce2_M->Timing.clockTickH0 *
    exertConstForce2_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void exertConstForce2_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)exertConstForce2_M, 0,
                sizeof(RT_MODEL_exertConstForce2));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = exertConstForce2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    exertConstForce2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    exertConstForce2_M->Timing.sampleTimes =
      (&exertConstForce2_M->Timing.sampleTimesArray[0]);
    exertConstForce2_M->Timing.offsetTimes =
      (&exertConstForce2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    exertConstForce2_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    exertConstForce2_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(exertConstForce2_M, &exertConstForce2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = exertConstForce2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    exertConstForce2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(exertConstForce2_M, -1);
  exertConstForce2_M->Timing.stepSize0 = 0.001;
  exertConstForce2_M->solverInfoPtr = (&exertConstForce2_M->solverInfo);
  exertConstForce2_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&exertConstForce2_M->solverInfo, 0.001);
  rtsiSetSolverMode(&exertConstForce2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  exertConstForce2_M->ModelData.blockIO = ((void *) &exertConstForce2_B);
  (void) memset(((void *) &exertConstForce2_B), 0,
                sizeof(BlockIO_exertConstForce2));

  /* parameters */
  exertConstForce2_M->ModelData.defaultParam = ((real_T *)&exertConstForce2_P);

  /* states (dwork) */
  exertConstForce2_M->Work.dwork = ((void *) &exertConstForce2_DWork);
  (void) memset((void *)&exertConstForce2_DWork, 0,
                sizeof(D_Work_exertConstForce2));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void exertConstForce2_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  exertConstForce2_output(tid);
}

void MdlUpdate(int_T tid)
{
  exertConstForce2_update(tid);
}

void MdlInitializeSizes(void)
{
  exertConstForce2_M->Sizes.numContStates = (0);/* Number of continuous states */
  exertConstForce2_M->Sizes.numY = (0);/* Number of model outputs */
  exertConstForce2_M->Sizes.numU = (0);/* Number of model inputs */
  exertConstForce2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  exertConstForce2_M->Sizes.numSampTimes = (1);/* Number of sample times */
  exertConstForce2_M->Sizes.numBlocks = (54);/* Number of blocks */
  exertConstForce2_M->Sizes.numBlockIO = (32);/* Number of block outputs */
  exertConstForce2_M->Sizes.numBlockPrms = (61);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for UnitDelay: '<S12>/UD' */
  exertConstForce2_DWork.UD_DSTATE = exertConstForce2_P.UD_X0;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  exertConstForce2_DWork.Memory_PreviousInput = exertConstForce2_P.Memory_X0;
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  exertConstForce2_terminate();
}

RT_MODEL_exertConstForce2 *exertConstForce2(void)
{
  exertConstForce2_initialize(1);
  return exertConstForce2_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
