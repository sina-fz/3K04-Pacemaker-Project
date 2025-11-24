/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAIRVVIRWORK_data.c
 *
 * Code generated for Simulink model 'AAIRVVIRWORK'.
 *
 * Model version                  : 1.422
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Nov 23 23:14:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AAIRVVIRWORK.h"
#include "AAIRVVIRWORK_private.h"

/* Block parameters (default storage) */
P_AAIRVVIRWORK_T AAIRVVIRWORK_P = {
  /* Expression: SampleTime
   * Referenced by: '<S1>/Analog Input1'
   */
  0.001,

  /* Expression: SampleTime
   * Referenced by: '<S1>/Analog Input4'
   */
  0.001,

  /* Expression: SampleTime
   * Referenced by: '<S1>/Analog Input'
   */
  0.001,

  /* Expression: SampleTime
   * Referenced by: '<S1>/VENT_CMP_DETECT'
   */
  0.001,

  /* Expression: SampleTime
   * Referenced by: '<S1>/ATR_CMP_DETECT'
   */
  0.001,

  /* Expression: -1
   * Referenced by: '<S1>/Serial Receive'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S10>/FXOS8700 6-Axes Sensor'
   */
  -1.0,

  /* Computed Parameter: activity_magnitude_Y0
   * Referenced by: '<S10>/activity_magnitude'
   */
  0.0,

  /* Expression: 60000
   * Referenced by: '<S13>/Gain4'
   */
  60000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Memory'
   */
  0.0,

  /* Expression: 7/24
   * Referenced by: '<S18>/Constant'
   */
  0.29166666666666669,

  /* Expression: 23/24
   * Referenced by: '<S18>/Constant1'
   */
  0.95833333333333337,

  /* Expression: 60000
   * Referenced by: '<S13>/Gain1'
   */
  60000.0,

  /* Expression: 5
   * Referenced by: '<S20>/MaxVoltage'
   */
  5.0,

  /* Expression: 100
   * Referenced by: '<S23>/%'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S24>/%'
   */
  100.0,

  /* Expression: 60000
   * Referenced by: '<S19>/Constant'
   */
  60000.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S25>/Gain'
   */
  100.0F,

  /* Computed Parameter: Gain1_Gain_p
   * Referenced by: '<S25>/Gain1'
   */
  100.0F,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S13>/Gain'
   */
  3435973837U,

  /* Computed Parameter: SerialNum_Value
   * Referenced by: '<S9>/SerialNum'
   */
  1010101U,

  /* Computed Parameter: ModelNum_Value
   * Referenced by: '<S9>/ModelNum'
   */
  1000001U,

  /* Computed Parameter: Delay7_InitialCondition
   * Referenced by: '<S13>/Delay7'
   */
  0U,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S13>/Delay'
   */
  0U,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<S13>/Delay1'
   */
  0U,

  /* Computed Parameter: Delay2_InitialCondition
   * Referenced by: '<S13>/Delay2'
   */
  0U,

  /* Computed Parameter: Delay3_InitialCondition
   * Referenced by: '<S13>/Delay3'
   */
  0U,

  /* Computed Parameter: Delay4_InitialCondition
   * Referenced by: '<S13>/Delay4'
   */
  0U,

  /* Expression: true
   * Referenced by: '<S22>/HIGH'
   */
  1,

  /* Expression: false
   * Referenced by: '<S22>/LOW'
   */
  0,

  /* Expression: true
   * Referenced by: '<S1>/Constant15'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S9>/Constant4'
   */
  22U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S9>/Constant3'
   */
  32U,

  /* Computed Parameter: HandshakePad1_Value
   * Referenced by: '<S9>/HandshakePad1'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Constant23_Value
   * Referenced by: '<S9>/Constant23'
   */
  22U,

  /* Computed Parameter: Constant22_Value
   * Referenced by: '<S9>/Constant22'
   */
  41U,

  /* Computed Parameter: HandshakePad_Value
   * Referenced by: '<S9>/HandshakePad'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Constant1_Value_k
   * Referenced by: '<S9>/Constant1'
   */
  22U,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S9>/Constant2'
   */
  57U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
