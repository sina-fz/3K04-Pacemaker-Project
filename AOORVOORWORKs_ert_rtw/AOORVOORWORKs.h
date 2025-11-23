/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AOORVOORWORKs.h
 *
 * Code generated for Simulink model 'AOORVOORWORKs'.
 *
 * Model version                  : 1.404
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Nov 23 00:12:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AOORVOORWORKs_h_
#define RTW_HEADER_AOORVOORWORKs_h_
#include <string.h>
#include <math.h>
#include <stddef.h>
#ifndef AOORVOORWORKs_COMMON_INCLUDES_
# define AOORVOORWORKs_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_SCI.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                 /* AOORVOORWORKs_COMMON_INCLUDES_ */

#include "AOORVOORWORKs_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T csumrev[19];
  uint8_T RxData[99];
  uint8_T RxDataLocChar[99];
  uint8_T TxDataLocChar[18];
  uint8_T TmpSignalConversionAtSerial[18];
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T RxPinLoc;
  real_T Gain4;                        /* '<S13>/Gain4' */
  real_T Memory;                       /* '<S1>/Memory' */
  real_T Gain1;                        /* '<S13>/Gain1' */
  real_T Product;                      /* '<S22>/Product' */
  real_T Product_k;                    /* '<S23>/Product' */
  real_T PACING_REF_PWM;               /* '<S3>/1.1.3.2 PacemakerControl' */
  real_T count;                        /* '<S3>/1.1.3.2 PacemakerControl' */
  real_T ActivityIndex;                /* '<S2>/Activity Index Determination' */
  real_T MovingAverage;                /* '<S10>/Moving Average' */
  real_T atrial_pulse_width;           /* '<S1>/Chart1' */
  real_T r_s_down;                     /* '<S1>/Chart1' */
  real_T r_s_up;                       /* '<S1>/Chart1' */
  real_T ventricular_pulse_width;      /* '<S1>/Chart1' */
  real_T z;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  uint32_T Cast;                       /* '<S18>/Cast' */
  uint32_T CastToSingle5;              /* '<S2>/Cast To Single5' */
  uint32_T CastToSingle6;              /* '<S2>/Cast To Single6' */
  uint32_T flag;                       /* '<S2>/Chart' */
  uint32_T wait_time;        /* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  uint32_T wait_time_LRL;    /* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  uint32_T wait_time_LRL_hys;/* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  uint32_T wait_time_AAIR;   /* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  uint32_T time_between_pulses;    /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  uint32_T MSR;                        /* '<S1>/Chart1' */
  uint32_T ReactionTime;               /* '<S1>/Chart1' */
  uint32_T Mode;                       /* '<S1>/Chart1' */
  uint32_T RecoveryTime;               /* '<S1>/Chart1' */
  uint32_T ResponseFactor;             /* '<S1>/Chart1' */
  uint32_T a_r_p;                      /* '<S1>/Chart1' */
  uint32_T activity_threshold;         /* '<S1>/Chart1' */
  uint32_T h_r_l;                      /* '<S1>/Chart1' */
  uint32_T lower_rate_limit;           /* '<S1>/Chart1' */
  uint32_T p_v_a_r_p;                  /* '<S1>/Chart1' */
  uint32_T upper_rate_limit;           /* '<S1>/Chart1' */
  uint32_T v_r_p;                      /* '<S1>/Chart1' */
  real32_T MathFunction1;              /* '<S15>/Math Function1' */
  real32_T atrium_output_voltage;      /* '<S3>/1.1.3.2 PacemakerControl' */
  real32_T ventricle_output_voltage;   /* '<S3>/1.1.3.2 PacemakerControl' */
  real32_T ATR_CMP_REF_PWM;            /* '<S3>/1.1.3.2 PacemakerControl' */
  real32_T VENT_CMP_REF_PWM;           /* '<S3>/1.1.3.2 PacemakerControl' */
  real32_T DesiredRate;                /* '<S2>/Chart' */
  real32_T CR;                         /* '<S2>/Chart' */
  real32_T stepup;                     /* '<S2>/Chart' */
  real32_T atrial_amplitude;           /* '<S1>/Chart1' */
  real32_T atrial_sensitivity;         /* '<S1>/Chart1' */
  real32_T ventricular_amplitude;      /* '<S1>/Chart1' */
  real32_T ventricular_sensitivity;    /* '<S1>/Chart1' */
  uint8_T BytePack6;                   /* '<S9>/Byte Pack6' */
  uint8_T BytePack7;                   /* '<S9>/Byte Pack7' */
  uint8_T BytePack8[4];                /* '<S9>/Byte Pack8' */
  uint8_T BytePack9[4];                /* '<S9>/Byte Pack9' */
  uint8_T BytePack10[8];               /* '<S9>/Byte Pack10' */
  uint8_T hysterisis_flag;             /* '<S1>/Chart1' */
  uint8_T Handshake_Request;           /* '<S1>/Chart1' */
  boolean_T ATR_GND_CTRL;              /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T ATR_PACE_CTRL;             /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T PACE_GND_CTRL;             /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T VENT_GND_CTRL;             /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T VENT_PACE_CTRL;            /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T Z_ATR_CTRL;                /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T Z_VENT_CTRL;               /* '<S3>/1.1.3.2 PacemakerControl' */
  boolean_T pulse_finished;        /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  boolean_T HR_Ready;              /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  boolean_T ATR_CMP_DETECT;            /* '<S1>/ATR_CMP_DETECT' */
  boolean_T VENT_CMP_DETECT;           /* '<S1>/VENT_CMP_DETECT' */
} B_AOORVOORWORKs_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  g_dsp_private_SlidingWindowAv_T gobj_1;/* '<S10>/Moving Average' */
  g_dsp_private_SlidingWindowAv_T gobj_2;/* '<S10>/Moving Average' */
  dsp_simulink_MovingAverage_AO_T obj; /* '<S10>/Moving Average' */
  freedomk64f_fxos8700_AOORVOOR_T obj_c;/* '<S10>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_AOORV_T obj_i;/* '<S1>/ATR_CMP_DETECT' */
  freedomk64f_DigitalRead_AOORV_T obj_ci;/* '<S1>/VENT_CMP_DETECT' */
  freedomk64f_AnalogInput_AOORV_T obj_f;/* '<S1>/Analog Input' */
  freedomk64f_AnalogInput_AOORV_T obj_d;/* '<S1>/Analog Input1' */
  freedomk64f_AnalogInput_AOORV_T obj_p;/* '<S1>/Analog Input4' */
  freedomk64f_AnalogInput_AOORV_T obj_h;/* '<S1>/Analog Input5' */
  freedomk64f_SCIRead_AOORVOORW_T obj_m;/* '<S1>/Serial Receive' */
  freedomk64f_DigitalWrite_AOOR_T obj_p5;/* '<S4>/Digital Write' */
  freedomk64f_DigitalWrite_AOOR_T obj_pd;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_AOOR_T obj_is;/* '<S4>/Digital Write2' */
  freedomk64f_DigitalWrite_AOOR_T obj_n;/* '<S4>/Digital Write3' */
  freedomk64f_DigitalWrite_AOOR_T obj_np;/* '<S4>/Digital Write5' */
  freedomk64f_DigitalWrite_AOOR_T obj_e;/* '<S4>/Digital Write6' */
  freedomk64f_DigitalWrite_AOOR_T obj_c4;/* '<S4>/Digital Write7' */
  freedomk64f_DigitalWrite_AOOR_T obj_hw;/* '<S4>/Digital Write8' */
  freedomk64f_DigitalWrite_AOOR_T obj_o;/* '<S2>/Digital Write' */
  freedomk64f_DigitalWrite_AOOR_T obj_hwo;/* '<S1>/Digital Write1' */
  freedomk64f_SCIWrite_AOORVOOR_T obj_ce;/* '<S9>/Serial Transmit' */
  freedomk64f_PWMOutput_AOORVOO_T obj_b;/* '<S4>/PWM Output' */
  freedomk64f_PWMOutput_AOORVOO_T obj_mo;/* '<S4>/PWM Output1' */
  freedomk64f_PWMOutput_AOORVOO_T obj_a;/* '<S4>/PWM Output2' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  real_T AOOR;                         /* '<S3>/1.1.3.2 PacemakerControl' */
  real_T VOOR;                         /* '<S3>/1.1.3.2 PacemakerControl' */
  real_T AAIR;                         /* '<S3>/1.1.3.2 PacemakerControl' */
  real_T a;                            /* '<S2>/Activity Index Determination' */
  real_T smoothing_rate;     /* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  real_T atrial_pulse_width_U;         /* '<S1>/Chart1' */
  real_T r_s_down_U;                   /* '<S1>/Chart1' */
  real_T r_s_up_U;                     /* '<S1>/Chart1' */
  real_T ventricular_pulse_width_U;    /* '<S1>/Chart1' */
  real_T tmp_double_data[8];           /* '<S1>/Chart1' */
  uint32_T Delay7_DSTATE;              /* '<S13>/Delay7' */
  uint32_T Delay_DSTATE;               /* '<S13>/Delay' */
  uint32_T Delay1_DSTATE;              /* '<S13>/Delay1' */
  uint32_T Delay2_DSTATE;              /* '<S13>/Delay2' */
  uint32_T Delay3_DSTATE;              /* '<S13>/Delay3' */
  uint32_T Delay4_DSTATE;              /* '<S13>/Delay4' */
  real32_T stepdown;                   /* '<S2>/Chart' */
  real32_T atrial_amplitude_U;         /* '<S1>/Chart1' */
  real32_T ventricular_amplitude_U;    /* '<S1>/Chart1' */
  real32_T tmp_single_data[4];         /* '<S1>/Chart1' */
  int32_T VOO;                         /* '<S3>/1.1.3.2 PacemakerControl' */
  int32_T tmp_double_sizes;            /* '<S1>/Chart1' */
  int32_T tmp_u32_sizes;               /* '<S1>/Chart1' */
  int32_T tmp_single_sizes;            /* '<S1>/Chart1' */
  uint32_T AAI;                        /* '<S3>/1.1.3.2 PacemakerControl' */
  uint32_T VVI;                        /* '<S3>/1.1.3.2 PacemakerControl' */
  uint32_T AOO;                        /* '<S3>/1.1.3.2 PacemakerControl' */
  uint32_T temporalCounter_i1;         /* '<S3>/1.1.3.2 PacemakerControl' */
  uint32_T time_minute;      /* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  uint32_T temporalCounter_i1_a;   /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  uint32_T MSR_U;                      /* '<S1>/Chart1' */
  uint32_T Mode_U;                     /* '<S1>/Chart1' */
  uint32_T ReactionTime_U;             /* '<S1>/Chart1' */
  uint32_T RecoveryTime_U;             /* '<S1>/Chart1' */
  uint32_T ResponseFactor_U;           /* '<S1>/Chart1' */
  uint32_T a_r_p_U;                    /* '<S1>/Chart1' */
  uint32_T activity_threshold_U;       /* '<S1>/Chart1' */
  uint32_T h_r_l_U;                    /* '<S1>/Chart1' */
  uint32_T lower_rate_limit_U;         /* '<S1>/Chart1' */
  uint32_T p_v_a_r_p_U;                /* '<S1>/Chart1' */
  uint32_T upper_rate_limit_U;         /* '<S1>/Chart1' */
  uint32_T v_r_p_U;                    /* '<S1>/Chart1' */
  uint32_T tmp_u32_data[8];            /* '<S1>/Chart1' */
  uint16_T temporalCounter_i1_l;       /* '<S2>/Chart' */
  uint16_T temporalCounter_i1_o;       /* '<S1>/HeartChamberPulseDetection2' */
  uint8_T is_active_c3_AOORVOORWORKs;  /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_c3_AOORVOORWORKs;         /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_AOOR;                     /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_AAI;                      /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_AAIR;                     /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_AOO;                      /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_VVI;                      /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_VOO;                      /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_VOOR;                     /* '<S3>/1.1.3.2 PacemakerControl' */
  uint8_T is_active_c10_AOORVOORWORKs; /* '<S2>/Chart' */
  uint8_T is_c10_AOORVOORWORKs;        /* '<S2>/Chart' */
  uint8_T is_active_c4_AOORVOORWORKs;  /* '<S2>/Activity Index Determination' */
  uint8_T is_c4_AOORVOORWORKs;         /* '<S2>/Activity Index Determination' */
  uint8_T is_active_c1_AOORVOORWORKs;
                             /* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  uint8_T is_c1_AOORVOORWORKs;
                             /* '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  uint8_T is_active_c5_AOORVOORWORKs;
                                   /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  uint8_T is_c5_AOORVOORWORKs;     /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  uint8_T is_AtrialRateDetection;  /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  uint8_T is_VenticularRateDetection;
                                   /* '<S2>/1.1.2.1 PulsePeriodDetermination' */
  uint8_T is_active_c7_AOORVOORWORKs;  /* '<S1>/HeartChamberPulseDetection3' */
  uint8_T is_c7_AOORVOORWORKs;         /* '<S1>/HeartChamberPulseDetection3' */
  uint8_T temporalCounter_i1_k;        /* '<S1>/HeartChamberPulseDetection3' */
  uint8_T is_active_c8_AOORVOORWORKs;  /* '<S1>/HeartChamberPulseDetection2' */
  uint8_T is_c8_AOORVOORWORKs;         /* '<S1>/HeartChamberPulseDetection2' */
  uint8_T is_active_c6_AOORVOORWORKs;  /* '<S1>/HeartChamberPulseDetection' */
  uint8_T is_c6_AOORVOORWORKs;         /* '<S1>/HeartChamberPulseDetection' */
  uint8_T is_active_c9_AOORVOORWORKs;  /* '<S1>/Chart1' */
  uint8_T is_c9_AOORVOORWORKs;         /* '<S1>/Chart1' */
  uint8_T hysterisis_flag_U;           /* '<S1>/Chart1' */
  uint8_T temporalCounter_i1_m;        /* '<S1>/Chart1' */
  boolean_T objisempty;                /* '<S4>/Digital Write' */
  boolean_T objisempty_h;              /* '<S4>/Digital Write1' */
  boolean_T objisempty_k;              /* '<S4>/Digital Write2' */
  boolean_T objisempty_a;              /* '<S4>/Digital Write3' */
  boolean_T objisempty_f;              /* '<S4>/PWM Output' */
  boolean_T objisempty_i;              /* '<S4>/Digital Write5' */
  boolean_T objisempty_in;             /* '<S4>/Digital Write6' */
  boolean_T objisempty_e;              /* '<S4>/Digital Write7' */
  boolean_T objisempty_e2;             /* '<S4>/Digital Write8' */
  boolean_T objisempty_hv;             /* '<S4>/PWM Output1' */
  boolean_T objisempty_o;              /* '<S4>/PWM Output2' */
  boolean_T objisempty_ez;             /* '<S2>/Digital Write' */
  boolean_T objisempty_l;              /* '<S10>/FXOS8700 6-Axes Sensor' */
  boolean_T objisempty_p;              /* '<S10>/Moving Average' */
  boolean_T objisempty_j;              /* '<S9>/Serial Transmit' */
  boolean_T safety_flag;               /* '<S1>/Chart1' */
  boolean_T objisempty_m;              /* '<S1>/Serial Receive' */
  boolean_T objisempty_mo;             /* '<S1>/ATR_CMP_DETECT' */
  boolean_T objisempty_ml;             /* '<S1>/VENT_CMP_DETECT' */
  boolean_T objisempty_fp;             /* '<S1>/Analog Input' */
  boolean_T objisempty_kb;             /* '<S1>/Analog Input1' */
  boolean_T objisempty_kg;             /* '<S1>/Analog Input4' */
  boolean_T objisempty_ks;             /* '<S1>/Analog Input5' */
  boolean_T objisempty_l1;             /* '<S1>/Digital Write1' */
} DW_AOORVOORWORKs_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
  ZCSigState Subsystem1_Trig_ZCE;      /* '<S1>/Subsystem1' */
} PrevZCX_AOORVOORWORKs_T;

/* Parameters (default storage) */
struct P_AOORVOORWORKs_T_ {
  real_T AnalogInput5_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/Analog Input5'
                                        */
  real_T AnalogInput4_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/Analog Input4'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S1>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S1>/ATR_CMP_DETECT'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S1>/Serial Receive'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S10>/FXOS8700 6-Axes Sensor'
                                         */
  real_T activity_magnitude_Y0;     /* Computed Parameter: activity_magnitude_Y0
                                     * Referenced by: '<S10>/activity_magnitude'
                                     */
  real_T Gain4_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S13>/Gain4'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Gain1_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T MaxVoltage_Value;             /* Expression: 5
                                        * Referenced by: '<S19>/MaxVoltage'
                                        */
  real_T _Value;                       /* Expression: 100
                                        * Referenced by: '<S22>/%'
                                        */
  real_T _Value_b;                     /* Expression: 100
                                        * Referenced by: '<S23>/%'
                                        */
  real_T Constant_Value;               /* Expression: 60000
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S24>/Gain'
                                        */
  real32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S24>/Gain1'
                                        */
  uint32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S13>/Gain'
                                        */
  uint32_T ModelNum_Value;             /* Computed Parameter: ModelNum_Value
                                        * Referenced by: '<S9>/ModelNum'
                                        */
  uint32_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S13>/Delay7'
                                   */
  uint32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S13>/Delay'
                                    */
  uint32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S13>/Delay1'
                                   */
  uint32_T Delay2_InitialCondition;
                                  /* Computed Parameter: Delay2_InitialCondition
                                   * Referenced by: '<S13>/Delay2'
                                   */
  uint32_T Delay3_InitialCondition;
                                  /* Computed Parameter: Delay3_InitialCondition
                                   * Referenced by: '<S13>/Delay3'
                                   */
  uint32_T Delay4_InitialCondition;
                                  /* Computed Parameter: Delay4_InitialCondition
                                   * Referenced by: '<S13>/Delay4'
                                   */
  boolean_T HIGH_Value;                /* Expression: true
                                        * Referenced by: '<S21>/HIGH'
                                        */
  boolean_T LOW_Value;                 /* Expression: false
                                        * Referenced by: '<S21>/LOW'
                                        */
  boolean_T Constant15_Value;          /* Expression: true
                                        * Referenced by: '<S1>/Constant15'
                                        */
  uint8_T Constant23_Value;            /* Computed Parameter: Constant23_Value
                                        * Referenced by: '<S9>/Constant23'
                                        */
  uint8_T Constant22_Value;            /* Computed Parameter: Constant22_Value
                                        * Referenced by: '<S9>/Constant22'
                                        */
  uint8_T HandshakePad_Value[8];       /* Computed Parameter: HandshakePad_Value
                                        * Referenced by: '<S9>/HandshakePad'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AOORVOORWORKs_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_AOORVOORWORKs_T AOORVOORWORKs_P;

/* Block signals (default storage) */
extern B_AOORVOORWORKs_T AOORVOORWORKs_B;

/* Block states (default storage) */
extern DW_AOORVOORWORKs_T AOORVOORWORKs_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_AOORVOORWORKs_T AOORVOORWORKs_PrevZCX;

/* Model entry point functions */
extern void AOORVOORWORKs_initialize(void);
extern void AOORVOORWORKs_step(void);
extern void AOORVOORWORKs_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AOORVOORWORKs_T *const AOORVOORWORKs_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/ActivityThreshold' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S1>/Constant10' : Unused code path elimination
 * Block '<S1>/Constant11' : Unused code path elimination
 * Block '<S1>/Constant12' : Unused code path elimination
 * Block '<S1>/Constant13' : Unused code path elimination
 * Block '<S1>/Constant14' : Unused code path elimination
 * Block '<S1>/Constant16' : Unused code path elimination
 * Block '<S1>/Constant17' : Unused code path elimination
 * Block '<S1>/Constant18' : Unused code path elimination
 * Block '<S1>/Constant19' : Unused code path elimination
 * Block '<S1>/Constant2' : Unused code path elimination
 * Block '<S1>/Constant3' : Unused code path elimination
 * Block '<S1>/Constant4' : Unused code path elimination
 * Block '<S1>/Constant5' : Unused code path elimination
 * Block '<S1>/Constant6' : Unused code path elimination
 * Block '<S1>/Constant7' : Unused code path elimination
 * Block '<S1>/Constant8' : Unused code path elimination
 * Block '<S1>/Constant9' : Unused code path elimination
 * Block '<S1>/HysterisisFlag' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S9>/SerialNum' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S13>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<S18>/Cast To Single' : Eliminate redundant data type conversion
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
 * '<Root>' : 'AOORVOORWORKs'
 * '<S1>'   : 'AOORVOORWORKs/1.1.1 HardwareInputMapping'
 * '<S2>'   : 'AOORVOORWORKs/1.1.2 InputProcessing'
 * '<S3>'   : 'AOORVOORWORKs/1.1.3 Subroutines'
 * '<S4>'   : 'AOORVOORWORKs/1.1.4 Hardware Output Mapping'
 * '<S5>'   : 'AOORVOORWORKs/1.1.1 HardwareInputMapping/Chart1'
 * '<S6>'   : 'AOORVOORWORKs/1.1.1 HardwareInputMapping/HeartChamberPulseDetection'
 * '<S7>'   : 'AOORVOORWORKs/1.1.1 HardwareInputMapping/HeartChamberPulseDetection2'
 * '<S8>'   : 'AOORVOORWORKs/1.1.1 HardwareInputMapping/HeartChamberPulseDetection3'
 * '<S9>'   : 'AOORVOORWORKs/1.1.1 HardwareInputMapping/Subsystem1'
 * '<S10>'  : 'AOORVOORWORKs/1.1.1 HardwareInputMapping/Triggered Subsystem'
 * '<S11>'  : 'AOORVOORWORKs/1.1.1 HardwareInputMapping/Triggered Subsystem/Subsystem'
 * '<S12>'  : 'AOORVOORWORKs/1.1.2 InputProcessing/1.1.2.1 PulsePeriodDetermination'
 * '<S13>'  : 'AOORVOORWORKs/1.1.2 InputProcessing/1.1.2.2 RateCalculation'
 * '<S14>'  : 'AOORVOORWORKs/1.1.2 InputProcessing/1.1.2.3 WatchdogTimerForPulseDetection'
 * '<S15>'  : 'AOORVOORWORKs/1.1.2 InputProcessing/1.1.2.4 CalculateUnsensedPace'
 * '<S16>'  : 'AOORVOORWORKs/1.1.2 InputProcessing/Activity Index Determination'
 * '<S17>'  : 'AOORVOORWORKs/1.1.2 InputProcessing/Chart'
 * '<S18>'  : 'AOORVOORWORKs/1.1.2 InputProcessing/Subsystem1'
 * '<S19>'  : 'AOORVOORWORKs/1.1.3 Subroutines/1.1.3.1 PacingDutyCycleCalculation'
 * '<S20>'  : 'AOORVOORWORKs/1.1.3 Subroutines/1.1.3.2 PacemakerControl'
 * '<S21>'  : 'AOORVOORWORKs/1.1.3 Subroutines/HIGH_or_LOW'
 * '<S22>'  : 'AOORVOORWORKs/1.1.3 Subroutines/1.1.3.1 PacingDutyCycleCalculation/1.1.3.1.1 ATR Duty Cycle Calculation'
 * '<S23>'  : 'AOORVOORWORKs/1.1.3 Subroutines/1.1.3.1 PacingDutyCycleCalculation/1.1.3.1.2 VENT Duty Cycle Calculation'
 * '<S24>'  : 'AOORVOORWORKs/1.1.4 Hardware Output Mapping/1.1.4.1 ReferenceDutyCycleCalculation'
 */
#endif                                 /* RTW_HEADER_AOORVOORWORKs_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
