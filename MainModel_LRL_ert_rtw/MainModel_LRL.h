/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MainModel_LRL.h
 *
 * Code generated for Simulink model 'MainModel_LRL'.
 *
 * Model version                  : 1.331
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Oct 25 21:23:08 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MainModel_LRL_h_
#define RTW_HEADER_MainModel_LRL_h_
#include <math.h>
#include <stddef.h>
#ifndef MainModel_LRL_COMMON_INCLUDES_
# define MainModel_LRL_COMMON_INCLUDES_
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "rtwtypes.h"
#include "MW_PWM.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#endif                                 /* MainModel_LRL_COMMON_INCLUDES_ */

#include "MainModel_LRL_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PACING_REF_PWM;               /* '<S4>/Pacemaker Control' */
  real_T ATR_CMP_REF_PWM;              /* '<S4>/Pacemaker Control' */
  real_T VENT_CMP_REF_PWM;             /* '<S4>/Pacemaker Control' */
  real_T count;                        /* '<S4>/Pacemaker Control' */
  real_T time_between_pulses;          /* '<S3>/Chart1' */
  real_T pulse_finished;               /* '<S3>/Chart1' */
  real_T wait_time_LRL;                /* '<S3>/Chart' */
  real_T AnalogInput;                  /* '<S2>/Analog Input' */
  real_T AnalogInput1;                 /* '<S2>/Analog Input1' */
  real32_T wait_time;                  /* '<S3>/Chart' */
  boolean_T ATR_GND_CTRL;              /* '<S4>/Pacemaker Control' */
  boolean_T ATR_PACE_CTRL;             /* '<S4>/Pacemaker Control' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S4>/Pacemaker Control' */
  boolean_T PACE_GND_CTRL;             /* '<S4>/Pacemaker Control' */
  boolean_T VENT_GND_CTRL;             /* '<S4>/Pacemaker Control' */
  boolean_T VENT_PACE_CTRL;            /* '<S4>/Pacemaker Control' */
  boolean_T Z_ATR_CTRL;                /* '<S4>/Pacemaker Control' */
  boolean_T Z_VENT_CTRL;               /* '<S4>/Pacemaker Control' */
  boolean_T HR_Ready;                  /* '<S3>/Chart1' */
  boolean_T ATR_CMP_DETECT;            /* '<S2>/ATR_CMP_DETECT' */
} B_MainModel_LRL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_MainM_T obj; /* '<S2>/ATR_CMP_DETECT' */
  freedomk64f_DigitalRead_MainM_T obj_o;/* '<S2>/VENT_CMP_DETECT' */
  freedomk64f_AnalogInput_MainM_T obj_n;/* '<S2>/Analog Input' */
  freedomk64f_AnalogInput_MainM_T obj_i;/* '<S2>/Analog Input1' */
  freedomk64f_DigitalWrite_Main_T obj_c;/* '<S2>/Digital Write' */
  freedomk64f_DigitalWrite_Main_T obj_e;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_Main_T obj_a;/* '<S1>/Digital Write' */
  freedomk64f_DigitalWrite_Main_T obj_k;/* '<S1>/Digital Write1' */
  freedomk64f_DigitalWrite_Main_T obj_f;/* '<S1>/Digital Write2' */
  freedomk64f_DigitalWrite_Main_T obj_d;/* '<S1>/Digital Write3' */
  freedomk64f_DigitalWrite_Main_T obj_it;/* '<S1>/Digital Write5' */
  freedomk64f_DigitalWrite_Main_T obj_ka;/* '<S1>/Digital Write6' */
  freedomk64f_DigitalWrite_Main_T obj_fn;/* '<S1>/Digital Write7' */
  freedomk64f_DigitalWrite_Main_T obj_j;/* '<S1>/Digital Write8' */
  freedomk64f_PWMOutput_MainMod_T obj_jd;/* '<S1>/PWM Output' */
  freedomk64f_PWMOutput_MainMod_T obj_av;/* '<S1>/PWM Output1' */
  freedomk64f_PWMOutput_MainMod_T obj_km;/* '<S1>/PWM Output2' */
  real_T Delay7_DSTATE;                /* '<S9>/Delay7' */
  real_T Delay_DSTATE;                 /* '<S9>/Delay' */
  real_T Delay1_DSTATE;                /* '<S9>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S9>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S9>/Delay3' */
  real_T Delay4_DSTATE;                /* '<S9>/Delay4' */
  real_T time_minute;                  /* '<S3>/Chart' */
  real_T smoothing_rate;               /* '<S3>/Chart' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_ATR_C;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Pacem;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Input;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_TimeB;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_ATR_g;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Analo;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Ana_o;   /* synthesized block */

  int32_T VOO;                         /* '<S4>/Pacemaker Control' */
  uint32_T AAI;                        /* '<S4>/Pacemaker Control' */
  uint32_T VVI;                        /* '<S4>/Pacemaker Control' */
  uint32_T AOO;                        /* '<S4>/Pacemaker Control' */
  uint32_T temporalCounter_i1;         /* '<S4>/Pacemaker Control' */
  uint32_T temporalCounter_i1_a;       /* '<S3>/Chart1' */
  uint8_T is_active_c3_MainModel_LRL;  /* '<S4>/Pacemaker Control' */
  uint8_T is_c3_MainModel_LRL;         /* '<S4>/Pacemaker Control' */
  uint8_T is_AAI;                      /* '<S4>/Pacemaker Control' */
  uint8_T is_AOO;                      /* '<S4>/Pacemaker Control' */
  uint8_T is_VOO;                      /* '<S4>/Pacemaker Control' */
  uint8_T is_VVI;                      /* '<S4>/Pacemaker Control' */
  uint8_T is_active_c5_MainModel_LRL;  /* '<S3>/Chart1' */
  uint8_T is_c5_MainModel_LRL;         /* '<S3>/Chart1' */
  uint8_T is_AtrialRateDetection;      /* '<S3>/Chart1' */
  uint8_T is_VenticularRateDetection;  /* '<S3>/Chart1' */
  uint8_T is_active_c1_MainModel_LRL;  /* '<S3>/Chart' */
  uint8_T is_c1_MainModel_LRL;         /* '<S3>/Chart' */
  uint8_T is_active_c6_MainModel_LRL;  /* '<S2>/Chart' */
  uint8_T is_c6_MainModel_LRL;         /* '<S2>/Chart' */
} DW_MainModel_LRL_T;

/* Parameters (default storage) */
struct P_MainModel_LRL_T_ {
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_CMP_DETECT'
                                        */
  real_T Constant14_Value;             /* Expression: 320
                                        * Referenced by: '<S2>/Constant14'
                                        */
  real_T Constant8_Value;              /* Expression: 250
                                        * Referenced by: '<S2>/Constant8'
                                        */
  real_T Delay7_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S9>/Delay7'
                                        */
  real_T Switch9_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S9>/Switch9'
                                        */
  real_T Gain4_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S9>/Gain4'
                                        */
  real_T Constant10_Value;             /* Expression: 45
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay4'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.2
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T MaxVoltage_Value;             /* Expression: 5
                                        * Referenced by: '<S4>/MaxVoltage'
                                        */
  real_T _Value;                       /* Expression: 100
                                        * Referenced by: '<S10>/%'
                                        */
  real_T _Value_g;                     /* Expression: 100
                                        * Referenced by: '<S13>/%'
                                        */
  real_T Constant13_Value;             /* Expression: 2.5
                                        * Referenced by: '<S2>/Constant13'
                                        */
  real_T Constant7_Value;              /* Expression: 2.75
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T Constant9_Value;              /* Expression: 250
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 100
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S9>/Switch4'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S9>/Switch3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S9>/Switch2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S9>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S9>/Switch'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real32_T Constant6_Value;            /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S2>/Constant5'
                                        */
  uint32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S2>/Constant2'
                                        */
  uint32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S2>/Constant1'
                                        */
  boolean_T HysterisisFlag_Value;    /* Computed Parameter: HysterisisFlag_Value
                                      * Referenced by: '<S2>/HysterisisFlag'
                                      */
  boolean_T HIGH_Value;                /* Expression: true
                                        * Referenced by: '<S11>/HIGH'
                                        */
  boolean_T LOW_Value;                 /* Expression: false
                                        * Referenced by: '<S11>/LOW'
                                        */
  boolean_T Constant15_Value;          /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S2>/Constant15'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MainModel_LRL_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (default storage) */
extern P_MainModel_LRL_T MainModel_LRL_P;

/* Block signals (default storage) */
extern B_MainModel_LRL_T MainModel_LRL_B;

/* Block states (default storage) */
extern DW_MainModel_LRL_T MainModel_LRL_DW;

/* Model entry point functions */
extern void MainModel_LRL_initialize(void);
extern void MainModel_LRL_step(void);
extern void MainModel_LRL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MainModel_LRL_T *const MainModel_LRL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant11' : Unused code path elimination
 * Block '<S2>/Constant12' : Unused code path elimination
 * Block '<S2>/Constant16' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope2' : Unused code path elimination
 * Block '<S6>/Data Type Conversion' : Unused code path elimination
 * Block '<S6>/Fcn1' : Unused code path elimination
 * Block '<S6>/Gain' : Unused code path elimination
 * Block '<S6>/Sum' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'MainModel_LRL'
 * '<S1>'   : 'MainModel_LRL/Hardware Output Pin Mapping'
 * '<S2>'   : 'MainModel_LRL/HardwareInputMapping'
 * '<S3>'   : 'MainModel_LRL/InputProcessing'
 * '<S4>'   : 'MainModel_LRL/Subroutines'
 * '<S5>'   : 'MainModel_LRL/HardwareInputMapping/Chart'
 * '<S6>'   : 'MainModel_LRL/InputProcessing/CalculateUnsensedPace'
 * '<S7>'   : 'MainModel_LRL/InputProcessing/Chart'
 * '<S8>'   : 'MainModel_LRL/InputProcessing/Chart1'
 * '<S9>'   : 'MainModel_LRL/InputProcessing/Subsystem'
 * '<S10>'  : 'MainModel_LRL/Subroutines/ATR Duty Cycle Calculation1'
 * '<S11>'  : 'MainModel_LRL/Subroutines/HIGH_or_LOW'
 * '<S12>'  : 'MainModel_LRL/Subroutines/Pacemaker Control'
 * '<S13>'  : 'MainModel_LRL/Subroutines/VENT Duty Cycle Calculation2'
 */
#endif                                 /* RTW_HEADER_MainModel_LRL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
