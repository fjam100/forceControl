/*
 * exertConstForce2_data.c
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

#include "exertConstForce2.h"
#include "exertConstForce2_private.h"

/* Block parameters (auto storage) */
Parameters_exertConstForce2 exertConstForce2_P = {
  /*  Expression: inpVector
   * Referenced by: '<Root>/Constant1'
   */
  { 0.05, 0.1 },
  7.1250445315283219E-004,             /* Expression: 4/5614
                                        * Referenced by: '<S10>/encGainY'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S12>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S12>/UD'
                                        */
  0.01,                                /* Expression: const
                                        * Referenced by: '<S14>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Reset'
                                        */

  /*  Expression: calMatrix
   * Referenced by: '<Root>/Constant'
   */
  { -2.2138964144975253E+000, -8.9569226215273119E+000, 1.3706169091822559E+002,
    -5.3084979645774452E-002, 2.4951711957641156E+000, 1.0425552263289020E-001,
    9.4537126788346937E-001, 1.0511701499289349E+002, 7.3516045865678494E+000,
    7.1581712479122217E-001, 1.2806805137764724E-001, -1.2978695038341532E+000,
    2.0121782313233179E+000, 2.4334926306286442E-001, 1.4160763344342215E+002,
    -2.2624238741870064E+000, -1.2632615022244273E+000, -8.1631695447016463E-003,
    -9.2872586345668452E+001, -5.4064239846059060E+001, 4.5051909928599558E+000,
    -4.4440305312903960E-001, 5.8771166442143341E-001, -1.3515846485137581E+000,
    -5.6439207217857064E+000, 5.9040798334464215E+000, 1.2945044487606236E+002,
    2.2428011387550080E+000, -1.2741060474136585E+000, 1.4548267324056874E-001,
    1.0259326078392422E+002, -5.9494495585917910E+001, 6.4531705446391303E+000,
    -2.7812628140244228E-001, -7.6211008071391073E-001, -1.5045640215991956E+000
  },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/channel5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/channel9'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/channel17'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/channel18'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/channel19'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/channel20'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/GainFx'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/GainFy'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/GainFz'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/GainMx'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/GainMy'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/GainMz'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/ID'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S1>/Constant'
                                        */
  32768U,                              /* Computed Parameter: motionInd2_Gain
                                        * Referenced by: '<Root>/motionInd2'
                                        */
  128U                                 /* Computed Parameter: motionInd1_Gain
                                        * Referenced by: '<Root>/motionInd1'
                                        */
};
