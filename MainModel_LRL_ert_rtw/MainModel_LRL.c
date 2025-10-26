/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MainModel_LRL.c
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

#include "MainModel_LRL.h"
#include "MainModel_LRL_private.h"

/* Named constants for Chart: '<S2>/Chart' */
#define MainModel_LRL_IN_default       ((uint8_T)1U)
#define MainModel_LRL_IN_led_on        ((uint8_T)2U)
#define MainModel_LR_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Named constants for Chart: '<S3>/Chart' */
#define MainMode_IN_HysterisisSelection ((uint8_T)2U)
#define MainModel_LRL_IN_AAI           ((uint8_T)1U)
#define MainModel_LRL_IN_VVI           ((uint8_T)3U)

/* Named constants for Chart: '<S3>/Chart1' */
#define MainMode_IN_AtrialRateDetection ((uint8_T)1U)
#define MainModel_LRL_IN_UnsensedModes ((uint8_T)2U)
#define MainModel_LRL_IN_awaitNewPulse ((uint8_T)1U)
#define MainModel_LRL_IN_default_j     ((uint8_T)4U)
#define MainModel_LRL_IN_default_jj    ((uint8_T)2U)
#define MainModel_LRL_IN_resetDeltaT   ((uint8_T)4U)
#define MainModel_LRL_IN_setARPasDeltaT ((uint8_T)5U)
#define MainModel_LRL_IN_setVRPasDeltaT ((uint8_T)5U)
#define MainModel_L_IN_newPulseDetected ((uint8_T)3U)
#define Main_IN_VenticularRateDetection ((uint8_T)3U)

/* Named constants for Chart: '<S4>/Pacemaker Control' */
#define IN_ChargeC22CapacitorandDischar ((uint8_T)1U)
#define MainMode_IN_Hysterisis_mode_OFF ((uint8_T)1U)
#define MainModel_IN_Hysterisis_mode_ON ((uint8_T)2U)
#define MainModel_IN_StopPulseDISCHARGE ((uint8_T)2U)
#define MainModel_LRL_IN_AOO           ((uint8_T)2U)
#define MainModel_LRL_IN_Initialize    ((uint8_T)3U)
#define MainModel_LRL_IN_Pulse         ((uint8_T)3U)
#define MainModel_LRL_IN_PulseDISCHARGE ((uint8_T)2U)
#define MainModel_LRL_IN_Standby       ((uint8_T)4U)
#define MainModel_LRL_IN_VOO           ((uint8_T)5U)
#define MainModel_LRL_IN_VVI_h         ((uint8_T)6U)
#define MainModel_LRL_IN_ref1          ((uint8_T)5U)
#define MainModel_LR_IN_initializations ((uint8_T)4U)

/* Block signals (default storage) */
B_MainModel_LRL_T MainModel_LRL_B;

/* Block states (default storage) */
DW_MainModel_LRL_T MainModel_LRL_DW;

/* Real-time model */
RT_MODEL_MainModel_LRL_T MainModel_LRL_M_;
RT_MODEL_MainModel_LRL_T *const MainModel_LRL_M = &MainModel_LRL_M_;

/* Forward declaration for local functions */
static void MainModel_LRL_VVI(const boolean_T *VENT_CMP_DETECT, const real_T
  *Product_j, const real_T *Gain4);
static void MainModel_LRL_AAI(const real_T *Product, const real_T *Gain4);
static void SystemCore_rele_lmiwv4or5bzkwoc(const
  freedomk64f_DigitalRead_MainM_T *obj);
static void SystemCore_dele_lmiwv4or5bzkwoc(const
  freedomk64f_DigitalRead_MainM_T *obj);
static void matlabCodegenHa_lmiwv4or5bzkwoc(freedomk64f_DigitalRead_MainM_T *obj);
static void MainModel_SystemCore_release_lm(const
  freedomk64f_DigitalWrite_Main_T *obj);
static void MainModel__SystemCore_delete_lm(const
  freedomk64f_DigitalWrite_Main_T *obj);
static void matlabCodegenHandle_matlabCo_lm(freedomk64f_DigitalWrite_Main_T *obj);
static void MainModel_LR_SystemCore_release(const
  freedomk64f_PWMOutput_MainMod_T *obj);
static void MainModel_LRL_SystemCore_delete(const
  freedomk64f_PWMOutput_MainMod_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_PWMOutput_MainMod_T *obj);
static void SystemCore_release_lmiwv4or5bzk(const
  freedomk64f_AnalogInput_MainM_T *obj);
static void SystemCore_delete_lmiwv4or5bzk(const freedomk64f_AnalogInput_MainM_T
  *obj);
static void matlabCodegenHandl_lmiwv4or5bzk(freedomk64f_AnalogInput_MainM_T *obj);

/* Function for Chart: '<S4>/Pacemaker Control' */
static void MainModel_LRL_VVI(const boolean_T *VENT_CMP_DETECT, const real_T
  *Product_j, const real_T *Gain4)
{
  uint32_T tmp;

  /* Constant: '<S2>/Constant' */
  if (MainModel_LRL_P.Constant_Value != MainModel_LRL_DW.VVI) {
    MainModel_LRL_DW.is_VVI = MainModel_LR_IN_NO_ACTIVE_CHILD;
    MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_Standby;
  } else {
    switch (MainModel_LRL_DW.is_VVI) {
     case MainMode_IN_Hysterisis_mode_OFF:
      /* Constant: '<S11>/LOW' incorporates:
       *  Constant: '<S2>/Constant2'
       */
      if ((MainModel_LRL_B.count <= MainModel_LRL_B.wait_time) &&
          ((*VENT_CMP_DETECT != MainModel_LRL_P.LOW_Value) || (!(*Gain4 <
             MainModel_LRL_P.Constant2_Value)))) {
        MainModel_LRL_DW.is_VVI = MainMode_IN_Hysterisis_mode_OFF;
        MainModel_LRL_B.count++;
      } else {
        if (((*VENT_CMP_DETECT == MainModel_LRL_P.LOW_Value) && (*Gain4 <
              MainModel_LRL_P.Constant2_Value)) || ((MainModel_LRL_B.count >
              MainModel_LRL_B.wait_time) && (*VENT_CMP_DETECT ==
              MainModel_LRL_P.LOW_Value))) {
          MainModel_LRL_DW.is_VVI = MainModel_LRL_IN_ref1;
          MainModel_LRL_DW.temporalCounter_i1 = 0U;
          MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.LOW_Value;

          /* Constant: '<S11>/HIGH' */
          MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;

          /* Constant: '<S11>/HIGH' */
          MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.PACING_REF_PWM = *Product_j;
        }
      }
      break;

     case MainModel_IN_Hysterisis_mode_ON:
      /* Constant: '<S11>/LOW' incorporates:
       *  Constant: '<S2>/Constant10'
       *  Constant: '<S2>/Constant2'
       */
      if (((*VENT_CMP_DETECT == MainModel_LRL_P.LOW_Value) && (*Gain4 <
            MainModel_LRL_P.Constant10_Value)) || ((MainModel_LRL_B.count >
            MainModel_LRL_B.wait_time) && (*VENT_CMP_DETECT ==
            MainModel_LRL_P.LOW_Value))) {
        MainModel_LRL_DW.is_VVI = MainModel_LRL_IN_ref1;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;
        MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.LOW_Value;

        /* Constant: '<S11>/HIGH' */
        MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;

        /* Constant: '<S11>/HIGH' */
        MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.PACING_REF_PWM = *Product_j;
      } else {
        if ((MainModel_LRL_B.count <= MainModel_LRL_B.wait_time) &&
            ((*VENT_CMP_DETECT != MainModel_LRL_P.LOW_Value) || (!(*Gain4 <
               MainModel_LRL_P.Constant2_Value)))) {
          MainModel_LRL_DW.is_VVI = MainModel_IN_Hysterisis_mode_ON;
          MainModel_LRL_B.count++;
        }
      }
      break;

     case MainModel_LRL_IN_Pulse:
      /* Constant: '<S2>/Constant14' */
      if (MainModel_LRL_DW.temporalCounter_i1 >= (uint32_T)ceil
          (MainModel_LRL_P.Constant14_Value)) {
        MainModel_LRL_DW.is_VVI = MainModel_LR_IN_initializations;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S2>/Constant13' */
        MainModel_LRL_B.VENT_CMP_REF_PWM = MainModel_LRL_P.Constant13_Value;
        MainModel_LRL_B.count = 0.0;
      }

      /* End of Constant: '<S2>/Constant14' */
      break;

     case MainModel_LR_IN_initializations:
      tmp = (uint32_T)ceil(MainModel_LRL_B.wait_time_LRL);

      /* Constant: '<S2>/HysterisisFlag' */
      if ((!MainModel_LRL_P.HysterisisFlag_Value) &&
          (MainModel_LRL_DW.temporalCounter_i1 >= tmp)) {
        MainModel_LRL_DW.is_VVI = MainMode_IN_Hysterisis_mode_OFF;
        MainModel_LRL_B.count++;
      } else {
        if (MainModel_LRL_P.HysterisisFlag_Value &&
            (MainModel_LRL_DW.temporalCounter_i1 >= tmp)) {
          MainModel_LRL_DW.is_VVI = MainModel_IN_Hysterisis_mode_ON;
          MainModel_LRL_B.count++;
        }
      }

      /* End of Constant: '<S2>/HysterisisFlag' */
      break;

     default:
      /* Constant: '<S2>/Constant6' */
      /* case IN_ref1: */
      if (MainModel_LRL_DW.temporalCounter_i1 >= MainModel_LRL_P.Constant6_Value)
      {
        MainModel_LRL_DW.is_VVI = MainModel_LRL_IN_Pulse;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S11>/LOW' */
        MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.PACING_REF_PWM = *Product_j;

        /* Constant: '<S11>/HIGH' */
        MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;

        /* Constant: '<S11>/LOW' */
        MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;

        /* Constant: '<S11>/HIGH' */
        MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.HIGH_Value;
      }

      /* End of Constant: '<S2>/Constant6' */
      break;
    }
  }

  /* End of Constant: '<S2>/Constant' */
}

/* Function for Chart: '<S4>/Pacemaker Control' */
static void MainModel_LRL_AAI(const real_T *Product, const real_T *Gain4)
{
  uint32_T tmp;

  /* Constant: '<S2>/Constant' */
  if (MainModel_LRL_P.Constant_Value != MainModel_LRL_DW.AAI) {
    MainModel_LRL_DW.is_AAI = MainModel_LR_IN_NO_ACTIVE_CHILD;
    MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_Standby;
  } else {
    switch (MainModel_LRL_DW.is_AAI) {
     case MainMode_IN_Hysterisis_mode_OFF:
      /* Constant: '<S11>/LOW' incorporates:
       *  Constant: '<S2>/Constant2'
       */
      if ((MainModel_LRL_B.count <= MainModel_LRL_B.wait_time) &&
          ((MainModel_LRL_B.ATR_CMP_DETECT != MainModel_LRL_P.LOW_Value) ||
           (!(*Gain4 < MainModel_LRL_P.Constant2_Value)))) {
        MainModel_LRL_DW.is_AAI = MainMode_IN_Hysterisis_mode_OFF;
        MainModel_LRL_B.count++;
      } else {
        if (((MainModel_LRL_B.ATR_CMP_DETECT == MainModel_LRL_P.LOW_Value) &&
             (*Gain4 < MainModel_LRL_P.Constant2_Value)) ||
            ((MainModel_LRL_B.count > MainModel_LRL_B.wait_time) &&
             (MainModel_LRL_B.ATR_CMP_DETECT == MainModel_LRL_P.LOW_Value))) {
          MainModel_LRL_DW.is_AAI = MainModel_LRL_IN_ref1;
          MainModel_LRL_DW.temporalCounter_i1 = 0U;
          MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.LOW_Value;

          /* Constant: '<S11>/HIGH' */
          MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.PACING_REF_PWM = *Product;
        }
      }
      break;

     case MainModel_IN_Hysterisis_mode_ON:
      /* Constant: '<S11>/LOW' incorporates:
       *  Constant: '<S2>/Constant10'
       *  Constant: '<S2>/Constant2'
       */
      if (((MainModel_LRL_B.ATR_CMP_DETECT == MainModel_LRL_P.LOW_Value) &&
           (*Gain4 < MainModel_LRL_P.Constant10_Value)) ||
          ((MainModel_LRL_B.count > MainModel_LRL_B.wait_time) &&
           (MainModel_LRL_B.ATR_CMP_DETECT == MainModel_LRL_P.LOW_Value))) {
        MainModel_LRL_DW.is_AAI = MainModel_LRL_IN_ref1;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;
        MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.LOW_Value;

        /* Constant: '<S11>/HIGH' */
        MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.PACING_REF_PWM = *Product;
      } else {
        if ((MainModel_LRL_B.count <= MainModel_LRL_B.wait_time) &&
            ((MainModel_LRL_B.ATR_CMP_DETECT != MainModel_LRL_P.LOW_Value) ||
             (!(*Gain4 < MainModel_LRL_P.Constant2_Value)))) {
          MainModel_LRL_DW.is_AAI = MainModel_IN_Hysterisis_mode_ON;
          MainModel_LRL_B.count++;
        }
      }
      break;

     case MainModel_LRL_IN_Pulse:
      /* Constant: '<S2>/Constant8' */
      if (MainModel_LRL_DW.temporalCounter_i1 >= (uint32_T)ceil
          (MainModel_LRL_P.Constant8_Value)) {
        MainModel_LRL_DW.is_AAI = MainModel_LR_IN_initializations;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S2>/Constant7' */
        MainModel_LRL_B.ATR_CMP_REF_PWM = MainModel_LRL_P.Constant7_Value;
        MainModel_LRL_B.count = 0.0;
      }

      /* End of Constant: '<S2>/Constant8' */
      break;

     case MainModel_LR_IN_initializations:
      tmp = (uint32_T)ceil(MainModel_LRL_B.wait_time_LRL);

      /* Constant: '<S2>/HysterisisFlag' */
      if ((!MainModel_LRL_P.HysterisisFlag_Value) &&
          (MainModel_LRL_DW.temporalCounter_i1 >= tmp)) {
        MainModel_LRL_DW.is_AAI = MainMode_IN_Hysterisis_mode_OFF;
        MainModel_LRL_B.count++;
      } else {
        if (MainModel_LRL_P.HysterisisFlag_Value &&
            (MainModel_LRL_DW.temporalCounter_i1 >= tmp)) {
          MainModel_LRL_DW.is_AAI = MainModel_IN_Hysterisis_mode_ON;
          MainModel_LRL_B.count++;
        }
      }

      /* End of Constant: '<S2>/HysterisisFlag' */
      break;

     default:
      /* Constant: '<S2>/Constant4' */
      /* case IN_ref1: */
      if (MainModel_LRL_DW.temporalCounter_i1 >= MainModel_LRL_P.Constant4_Value)
      {
        MainModel_LRL_DW.is_AAI = MainModel_LRL_IN_Pulse;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S11>/LOW' */
        MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.PACING_REF_PWM = *Product;

        /* Constant: '<S11>/HIGH' */
        MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;

        /* Constant: '<S11>/LOW' */
        MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;

        /* Constant: '<S11>/HIGH' */
        MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.HIGH_Value;

        /* Constant: '<S11>/LOW' */
        MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;
      }

      /* End of Constant: '<S2>/Constant4' */
      break;
    }
  }

  /* End of Constant: '<S2>/Constant' */
}

static void SystemCore_rele_lmiwv4or5bzkwoc(const
  freedomk64f_DigitalRead_MainM_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void SystemCore_dele_lmiwv4or5bzkwoc(const
  freedomk64f_DigitalRead_MainM_T *obj)
{
  SystemCore_rele_lmiwv4or5bzkwoc(obj);
}

static void matlabCodegenHa_lmiwv4or5bzkwoc(freedomk64f_DigitalRead_MainM_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_dele_lmiwv4or5bzkwoc(obj);
  }
}

static void MainModel_SystemCore_release_lm(const
  freedomk64f_DigitalWrite_Main_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void MainModel__SystemCore_delete_lm(const
  freedomk64f_DigitalWrite_Main_T *obj)
{
  MainModel_SystemCore_release_lm(obj);
}

static void matlabCodegenHandle_matlabCo_lm(freedomk64f_DigitalWrite_Main_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    MainModel__SystemCore_delete_lm(obj);
  }
}

static void MainModel_LR_SystemCore_release(const
  freedomk64f_PWMOutput_MainMod_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void MainModel_LRL_SystemCore_delete(const
  freedomk64f_PWMOutput_MainMod_T *obj)
{
  MainModel_LR_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_PWMOutput_MainMod_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    MainModel_LRL_SystemCore_delete(obj);
  }
}

static void SystemCore_release_lmiwv4or5bzk(const
  freedomk64f_AnalogInput_MainM_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_AnalogIn_Stop(obj->MW_ANALOGIN_HANDLE);
    MW_AnalogIn_Close(obj->MW_ANALOGIN_HANDLE);
  }
}

static void SystemCore_delete_lmiwv4or5bzk(const freedomk64f_AnalogInput_MainM_T
  *obj)
{
  SystemCore_release_lmiwv4or5bzk(obj);
}

static void matlabCodegenHandl_lmiwv4or5bzk(freedomk64f_AnalogInput_MainM_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete_lmiwv4or5bzk(obj);
  }
}

/* Model step function */
void MainModel_LRL_step(void)
{
  boolean_T tmp;
  boolean_T rtb_LED_STATE;
  real32_T MathFunction1;
  real_T Product_j;
  real_T Product;
  real_T Gain4;

  /* MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  if (MainModel_LRL_DW.obj.SampleTime !=
      MainModel_LRL_P.ATR_CMP_DETECT_SampleTime) {
    MainModel_LRL_DW.obj.SampleTime = MainModel_LRL_P.ATR_CMP_DETECT_SampleTime;
  }

  MainModel_LRL_B.ATR_CMP_DETECT = MW_digitalIO_read
    (MainModel_LRL_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  if (MainModel_LRL_DW.obj_o.SampleTime !=
      MainModel_LRL_P.VENT_CMP_DETECT_SampleTime) {
    MainModel_LRL_DW.obj_o.SampleTime =
      MainModel_LRL_P.VENT_CMP_DETECT_SampleTime;
  }

  tmp = MW_digitalIO_read(MainModel_LRL_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* Chart: '<S3>/Chart1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant14'
   *  Constant: '<S2>/Constant8'
   *  MATLABSystem: '<S2>/VENT_CMP_DETECT'
   */
  if (MainModel_LRL_DW.temporalCounter_i1_a < MAX_uint32_T) {
    MainModel_LRL_DW.temporalCounter_i1_a++;
  }

  if (MainModel_LRL_DW.is_active_c5_MainModel_LRL == 0U) {
    MainModel_LRL_DW.is_active_c5_MainModel_LRL = 1U;
    MainModel_LRL_DW.is_c5_MainModel_LRL = MainModel_LRL_IN_default_j;
  } else {
    switch (MainModel_LRL_DW.is_c5_MainModel_LRL) {
     case MainMode_IN_AtrialRateDetection:
      if (MainModel_LRL_P.Constant_Value != 112U) {
        MainModel_LRL_DW.is_AtrialRateDetection =
          MainModel_LR_IN_NO_ACTIVE_CHILD;
        MainModel_LRL_DW.is_c5_MainModel_LRL = MainModel_LRL_IN_default_j;
      } else {
        switch (MainModel_LRL_DW.is_AtrialRateDetection) {
         case MainModel_LRL_IN_awaitNewPulse:
          if (!MainModel_LRL_B.ATR_CMP_DETECT) {
            MainModel_LRL_DW.is_AtrialRateDetection =
              MainModel_LRL_IN_awaitNewPulse;
            MainModel_LRL_B.time_between_pulses++;
          } else {
            MainModel_LRL_DW.is_AtrialRateDetection =
              MainModel_L_IN_newPulseDetected;
            MainModel_LRL_DW.temporalCounter_i1_a = 0U;
            MainModel_LRL_B.pulse_finished = 1.0;
            MainModel_LRL_B.HR_Ready = true;
          }
          break;

         case MainModel_LRL_IN_default_jj:
          MainModel_LRL_B.pulse_finished = 0.0;
          if (MainModel_LRL_B.ATR_CMP_DETECT) {
            MainModel_LRL_DW.is_AtrialRateDetection =
              MainModel_LRL_IN_setARPasDeltaT;
            MainModel_LRL_DW.temporalCounter_i1_a = 0U;
            MainModel_LRL_B.time_between_pulses =
              MainModel_LRL_P.Constant8_Value;
          }
          break;

         case MainModel_L_IN_newPulseDetected:
          MainModel_LRL_B.pulse_finished = 1.0;
          if (MainModel_LRL_DW.temporalCounter_i1_a >= 1U) {
            MainModel_LRL_DW.is_AtrialRateDetection =
              MainModel_LRL_IN_resetDeltaT;
            MainModel_LRL_DW.temporalCounter_i1_a = 0U;
            MainModel_LRL_B.pulse_finished = 0.0;
            MainModel_LRL_B.time_between_pulses =
              MainModel_LRL_P.Constant8_Value;
          }
          break;

         case MainModel_LRL_IN_resetDeltaT:
          MainModel_LRL_B.pulse_finished = 0.0;
          if (MainModel_LRL_DW.temporalCounter_i1_a >= (uint32_T)ceil
              (MainModel_LRL_P.Constant8_Value - 1.0)) {
            if (!MainModel_LRL_B.ATR_CMP_DETECT) {
              MainModel_LRL_DW.is_AtrialRateDetection =
                MainModel_LRL_IN_awaitNewPulse;
              MainModel_LRL_B.time_between_pulses++;
            } else {
              MainModel_LRL_DW.is_AtrialRateDetection =
                MainModel_L_IN_newPulseDetected;
              MainModel_LRL_DW.temporalCounter_i1_a = 0U;
              MainModel_LRL_B.pulse_finished = 1.0;
              MainModel_LRL_B.HR_Ready = true;
            }
          }
          break;

         default:
          /* case IN_setARPasDeltaT: */
          if (MainModel_LRL_DW.temporalCounter_i1_a >= (uint32_T)ceil
              (MainModel_LRL_P.Constant8_Value)) {
            if (!MainModel_LRL_B.ATR_CMP_DETECT) {
              MainModel_LRL_DW.is_AtrialRateDetection =
                MainModel_LRL_IN_awaitNewPulse;
              MainModel_LRL_B.time_between_pulses++;
            } else {
              MainModel_LRL_DW.is_AtrialRateDetection =
                MainModel_L_IN_newPulseDetected;
              MainModel_LRL_DW.temporalCounter_i1_a = 0U;
              MainModel_LRL_B.pulse_finished = 1.0;
              MainModel_LRL_B.HR_Ready = true;
            }
          }
          break;
        }
      }
      break;

     case MainModel_LRL_IN_UnsensedModes:
      if ((MainModel_LRL_P.Constant_Value != 100U) &&
          (MainModel_LRL_P.Constant_Value != 200U)) {
        MainModel_LRL_B.HR_Ready = false;
        MainModel_LRL_DW.is_c5_MainModel_LRL = MainModel_LRL_IN_default_j;
      }
      break;

     case Main_IN_VenticularRateDetection:
      if (MainModel_LRL_P.Constant_Value != 222U) {
        MainModel_LRL_DW.is_VenticularRateDetection =
          MainModel_LR_IN_NO_ACTIVE_CHILD;
        MainModel_LRL_DW.is_c5_MainModel_LRL = MainModel_LRL_IN_default_j;
      } else {
        switch (MainModel_LRL_DW.is_VenticularRateDetection) {
         case MainModel_LRL_IN_awaitNewPulse:
          if (!tmp) {
            MainModel_LRL_DW.is_VenticularRateDetection =
              MainModel_LRL_IN_awaitNewPulse;
            MainModel_LRL_B.time_between_pulses++;
          } else {
            MainModel_LRL_DW.is_VenticularRateDetection =
              MainModel_L_IN_newPulseDetected;
            MainModel_LRL_DW.temporalCounter_i1_a = 0U;
            MainModel_LRL_B.pulse_finished = 1.0;
            MainModel_LRL_B.HR_Ready = true;
          }
          break;

         case MainModel_LRL_IN_default_jj:
          MainModel_LRL_B.pulse_finished = 0.0;
          if (tmp) {
            MainModel_LRL_DW.is_VenticularRateDetection =
              MainModel_LRL_IN_setVRPasDeltaT;
            MainModel_LRL_DW.temporalCounter_i1_a = 0U;
            MainModel_LRL_B.time_between_pulses =
              MainModel_LRL_P.Constant14_Value;
          }
          break;

         case MainModel_L_IN_newPulseDetected:
          MainModel_LRL_B.pulse_finished = 1.0;
          if (MainModel_LRL_DW.temporalCounter_i1_a >= 1U) {
            MainModel_LRL_DW.is_VenticularRateDetection =
              MainModel_LRL_IN_resetDeltaT;
            MainModel_LRL_DW.temporalCounter_i1_a = 0U;
            MainModel_LRL_B.pulse_finished = 0.0;
            MainModel_LRL_B.time_between_pulses =
              MainModel_LRL_P.Constant14_Value;
          }
          break;

         case MainModel_LRL_IN_resetDeltaT:
          MainModel_LRL_B.pulse_finished = 0.0;
          if (MainModel_LRL_DW.temporalCounter_i1_a >= (uint32_T)ceil
              (MainModel_LRL_P.Constant14_Value - 1.0)) {
            if (!tmp) {
              MainModel_LRL_DW.is_VenticularRateDetection =
                MainModel_LRL_IN_awaitNewPulse;
              MainModel_LRL_B.time_between_pulses++;
            } else {
              MainModel_LRL_DW.is_VenticularRateDetection =
                MainModel_L_IN_newPulseDetected;
              MainModel_LRL_DW.temporalCounter_i1_a = 0U;
              MainModel_LRL_B.pulse_finished = 1.0;
              MainModel_LRL_B.HR_Ready = true;
            }
          }
          break;

         default:
          /* case IN_setVRPasDeltaT: */
          if (MainModel_LRL_DW.temporalCounter_i1_a >= (uint32_T)ceil
              (MainModel_LRL_P.Constant14_Value)) {
            if (!tmp) {
              MainModel_LRL_DW.is_VenticularRateDetection =
                MainModel_LRL_IN_awaitNewPulse;
              MainModel_LRL_B.time_between_pulses++;
            } else {
              MainModel_LRL_DW.is_VenticularRateDetection =
                MainModel_L_IN_newPulseDetected;
              MainModel_LRL_DW.temporalCounter_i1_a = 0U;
              MainModel_LRL_B.pulse_finished = 1.0;
              MainModel_LRL_B.HR_Ready = true;
            }
          }
          break;
        }
      }
      break;

     default:
      /* case IN_default: */
      if (MainModel_LRL_P.Constant_Value == 112U) {
        MainModel_LRL_DW.is_c5_MainModel_LRL = MainMode_IN_AtrialRateDetection;
        MainModel_LRL_DW.is_AtrialRateDetection = MainModel_LRL_IN_default_jj;
        MainModel_LRL_B.pulse_finished = 0.0;
        MainModel_LRL_B.time_between_pulses = 0.0;
      } else if ((MainModel_LRL_P.Constant_Value == 100U) ||
                 (MainModel_LRL_P.Constant_Value == 200U)) {
        MainModel_LRL_DW.is_c5_MainModel_LRL = MainModel_LRL_IN_UnsensedModes;
        MainModel_LRL_B.HR_Ready = true;
      } else {
        if (MainModel_LRL_P.Constant_Value == 222U) {
          MainModel_LRL_DW.is_c5_MainModel_LRL = Main_IN_VenticularRateDetection;
          MainModel_LRL_DW.is_VenticularRateDetection =
            MainModel_LRL_IN_default_jj;
          MainModel_LRL_B.pulse_finished = 0.0;
          MainModel_LRL_B.time_between_pulses = 0.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Switch: '<S9>/Switch9' incorporates:
   *  Delay: '<S9>/Delay7'
   */
  if (MainModel_LRL_B.pulse_finished > MainModel_LRL_P.Switch9_Threshold) {
    MainModel_LRL_DW.Delay7_DSTATE = MainModel_LRL_B.time_between_pulses;
  }

  /* End of Switch: '<S9>/Switch9' */

  /* Gain: '<S9>/Gain4' incorporates:
   *  Delay: '<S9>/Delay7'
   *  Fcn: '<S9>/Fcn3'
   */
  Gain4 = 1.0 / MainModel_LRL_DW.Delay7_DSTATE * MainModel_LRL_P.Gain4_Gain;

  /* Chart: '<S3>/Chart' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant14'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant8'
   */
  if (MainModel_LRL_DW.is_active_c1_MainModel_LRL == 0U) {
    MainModel_LRL_DW.is_active_c1_MainModel_LRL = 1U;
    MainModel_LRL_DW.is_c1_MainModel_LRL = MainMode_IN_HysterisisSelection;
    MainModel_LRL_DW.time_minute = 60000.0;
    MainModel_LRL_DW.smoothing_rate = Gain4 - 5.0;
  } else {
    switch (MainModel_LRL_DW.is_c1_MainModel_LRL) {
     case MainModel_LRL_IN_AAI:
      break;

     case MainMode_IN_HysterisisSelection:
      switch (MainModel_LRL_P.Constant_Value) {
       case 112U:
        MainModel_LRL_DW.is_c1_MainModel_LRL = MainModel_LRL_IN_AAI;
        MainModel_LRL_B.wait_time = ((real32_T)MainModel_LRL_DW.time_minute -
          ((real32_T)MainModel_LRL_P.Constant8_Value +
           MainModel_LRL_P.Constant4_Value) * (real32_T)
          MainModel_LRL_DW.smoothing_rate) / (real32_T)
          MainModel_LRL_DW.smoothing_rate;
        MainModel_LRL_B.wait_time_LRL = (MainModel_LRL_DW.time_minute - 12520.0)
          / 50.0;
        break;

       case 222U:
        MainModel_LRL_DW.is_c1_MainModel_LRL = MainModel_LRL_IN_VVI;
        MainModel_LRL_B.wait_time = ((real32_T)MainModel_LRL_DW.time_minute -
          ((real32_T)MainModel_LRL_P.Constant14_Value +
           MainModel_LRL_P.Constant6_Value) * (real32_T)
          MainModel_LRL_DW.smoothing_rate) / (real32_T)
          MainModel_LRL_DW.smoothing_rate;
        MainModel_LRL_B.wait_time_LRL = (MainModel_LRL_DW.time_minute - 16050.0)
          / 50.0;
        break;
      }
      break;

     default:
      /* case IN_VVI: */
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* Math: '<S6>/Math Function1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   *  Fcn: '<S6>/Fcn2'
   *
   * About '<S6>/Math Function1':
   *  Operator: reciprocal
   */
  MathFunction1 = 1.0F / ((real32_T)MainModel_LRL_P.Constant2_Value / 60000.0F);

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/%'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S4>/MaxVoltage'
   *  Product: '<S10>/Divide'
   */
  Product = MainModel_LRL_P.Constant3_Value / MainModel_LRL_P.MaxVoltage_Value *
    MainModel_LRL_P._Value;

  /* Product: '<S13>/Product' incorporates:
   *  Constant: '<S13>/%'
   *  Constant: '<S2>/Constant5'
   *  Constant: '<S4>/MaxVoltage'
   *  Product: '<S13>/Divide'
   */
  Product_j = MainModel_LRL_P.Constant5_Value / MainModel_LRL_P.MaxVoltage_Value
    * MainModel_LRL_P._Value_g;

  /* Chart: '<S4>/Pacemaker Control' incorporates:
   *  Constant: '<S11>/HIGH'
   *  Constant: '<S11>/LOW'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant13'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  MATLABSystem: '<S2>/VENT_CMP_DETECT'
   */
  if (MainModel_LRL_DW.temporalCounter_i1 < MAX_uint32_T) {
    MainModel_LRL_DW.temporalCounter_i1++;
  }

  if (MainModel_LRL_DW.is_active_c3_MainModel_LRL == 0U) {
    MainModel_LRL_DW.is_active_c3_MainModel_LRL = 1U;
    MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_Initialize;
    MainModel_LRL_DW.AOO = 100U;
    MainModel_LRL_DW.VOO = 200;
    MainModel_LRL_DW.AAI = 112U;
    MainModel_LRL_DW.VVI = 222U;
  } else {
    switch (MainModel_LRL_DW.is_c3_MainModel_LRL) {
     case MainModel_LRL_IN_AAI:
      MainModel_LRL_AAI(&Product, &Gain4);
      break;

     case MainModel_LRL_IN_AOO:
      if (MainModel_LRL_P.Constant_Value != MainModel_LRL_DW.AOO) {
        MainModel_LRL_DW.is_AOO = MainModel_LR_IN_NO_ACTIVE_CHILD;
        MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_Standby;
      } else if (MainModel_LRL_DW.is_AOO == IN_ChargeC22CapacitorandDischar) {
        if (MainModel_LRL_DW.temporalCounter_i1 >= MathFunction1 -
            MainModel_LRL_P.Constant4_Value) {
          MainModel_LRL_DW.is_AOO = MainModel_LRL_IN_PulseDISCHARGE;
          MainModel_LRL_DW.temporalCounter_i1 = 0U;
          MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.PACING_REF_PWM = Product;
        }
      } else {
        /* case IN_PulseDISCHARGE: */
        if (MainModel_LRL_DW.temporalCounter_i1 >=
            MainModel_LRL_P.Constant4_Value) {
          MainModel_LRL_DW.is_AOO = IN_ChargeC22CapacitorandDischar;
          MainModel_LRL_DW.temporalCounter_i1 = 0U;
          MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.PACING_REF_PWM = Product;
          MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;
        }
      }
      break;

     case MainModel_LRL_IN_Initialize:
      if (MainModel_LRL_B.HR_Ready) {
        MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_Standby;
      }
      break;

     case MainModel_LRL_IN_Standby:
      if (MainModel_LRL_P.Constant_Value == MainModel_LRL_DW.AOO) {
        MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_AOO;
        MainModel_LRL_DW.is_AOO = IN_ChargeC22CapacitorandDischar;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;
        MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.PACING_REF_PWM = Product;
        MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;
      } else if (MainModel_LRL_P.Constant_Value == MainModel_LRL_DW.VVI) {
        MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_VVI_h;
        MainModel_LRL_DW.is_VVI = MainModel_LR_IN_initializations;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;
        MainModel_LRL_B.VENT_CMP_REF_PWM = MainModel_LRL_P.Constant13_Value;
        MainModel_LRL_B.count = 0.0;
      } else if ((real_T)MainModel_LRL_P.Constant_Value == MainModel_LRL_DW.VOO)
      {
        MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_VOO;
        MainModel_LRL_DW.is_VOO = IN_ChargeC22CapacitorandDischar;
        MainModel_LRL_DW.temporalCounter_i1 = 0U;
        MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.PACING_REF_PWM = Product_j;
        MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
        MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
        MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.HIGH_Value;
      } else {
        if (MainModel_LRL_P.Constant_Value == MainModel_LRL_DW.AAI) {
          MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_AAI;
          MainModel_LRL_DW.is_AAI = MainModel_LR_IN_initializations;
          MainModel_LRL_DW.temporalCounter_i1 = 0U;
          MainModel_LRL_B.ATR_CMP_REF_PWM = MainModel_LRL_P.Constant7_Value;
          MainModel_LRL_B.count = 0.0;
        }
      }
      break;

     case MainModel_LRL_IN_VOO:
      if ((real_T)MainModel_LRL_P.Constant_Value != MainModel_LRL_DW.VOO) {
        MainModel_LRL_DW.is_VOO = MainModel_LR_IN_NO_ACTIVE_CHILD;
        MainModel_LRL_DW.is_c3_MainModel_LRL = MainModel_LRL_IN_Standby;
      } else if (MainModel_LRL_DW.is_VOO == IN_ChargeC22CapacitorandDischar) {
        if (MainModel_LRL_DW.temporalCounter_i1 >= MathFunction1 -
            MainModel_LRL_P.Constant6_Value) {
          MainModel_LRL_DW.is_VOO = MainModel_IN_StopPulseDISCHARGE;
          MainModel_LRL_DW.temporalCounter_i1 = 0U;
          MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.PACING_REF_PWM = Product_j;
        }
      } else {
        /* case IN_StopPulseDISCHARGE: */
        if (MainModel_LRL_DW.temporalCounter_i1 >=
            MainModel_LRL_P.Constant6_Value) {
          MainModel_LRL_DW.is_VOO = IN_ChargeC22CapacitorandDischar;
          MainModel_LRL_DW.temporalCounter_i1 = 0U;
          MainModel_LRL_B.ATR_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_PACE_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.PACING_REF_PWM = Product_j;
          MainModel_LRL_B.PACE_CHARGE_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.PACE_GND_CTRL = MainModel_LRL_P.HIGH_Value;
          MainModel_LRL_B.Z_ATR_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.Z_VENT_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.ATR_GND_CTRL = MainModel_LRL_P.LOW_Value;
          MainModel_LRL_B.VENT_GND_CTRL = MainModel_LRL_P.HIGH_Value;
        }
      }
      break;

     default:
      /* case IN_VVI: */
      MainModel_LRL_VVI(&tmp, &Product_j, &Gain4);
      break;
    }
  }

  /* End of Chart: '<S4>/Pacemaker Control' */

  /* MATLABSystem: '<S1>/Digital Write' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_a.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S1>/Digital Write1' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_k.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write2' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_f.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write3' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_d.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S1>/PWM Output' */
  MW_PWM_SetDutyCycle(MainModel_LRL_DW.obj_jd.MW_PWM_HANDLE,
                      MainModel_LRL_B.PACING_REF_PWM);

  /* MATLABSystem: '<S1>/Digital Write5' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_it.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S1>/Digital Write6' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_ka.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write7' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_fn.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S1>/Digital Write8' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_j.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S1>/PWM Output1' incorporates:
   *  Fcn: '<S1>/Fcn'
   *  Gain: '<S1>/Gain'
   */
  MW_PWM_SetDutyCycle(MainModel_LRL_DW.obj_av.MW_PWM_HANDLE,
                      MainModel_LRL_P.Gain_Gain_a *
                      (MainModel_LRL_B.ATR_CMP_REF_PWM / 3.3));

  /* ToAsyncQueueBlock generated from: '<S1>/ATR_CMP_REF_PWM' */
  {
    {
      double time = ((MainModel_LRL_M->Timing.clockTick0) * 0.001);
      void *pData = (void *)&MainModel_LRL_B.ATR_CMP_REF_PWM;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(3459616259U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S1>/PWM Output2' incorporates:
   *  Fcn: '<S1>/Fcn1'
   *  Gain: '<S1>/Gain1'
   */
  MW_PWM_SetDutyCycle(MainModel_LRL_DW.obj_km.MW_PWM_HANDLE,
                      MainModel_LRL_P.Gain1_Gain_m *
                      (MainModel_LRL_B.VENT_CMP_REF_PWM / 3.3));

  /* Chart: '<S2>/Chart' incorporates:
   *  MATLABSystem: '<S2>/VENT_CMP_DETECT'
   */
  if (MainModel_LRL_DW.is_active_c6_MainModel_LRL == 0U) {
    MainModel_LRL_DW.is_active_c6_MainModel_LRL = 1U;
    MainModel_LRL_DW.is_c6_MainModel_LRL = MainModel_LRL_IN_default;
    rtb_LED_STATE = false;
  } else if (MainModel_LRL_DW.is_c6_MainModel_LRL == MainModel_LRL_IN_default) {
    rtb_LED_STATE = false;
    if (tmp) {
      MainModel_LRL_DW.is_c6_MainModel_LRL = MainModel_LRL_IN_led_on;
      rtb_LED_STATE = true;
    }
  } else {
    /* case IN_led_on: */
    rtb_LED_STATE = true;
    if (!tmp) {
      MainModel_LRL_DW.is_c6_MainModel_LRL = MainModel_LRL_IN_default;
      rtb_LED_STATE = false;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(MainModel_LRL_DW.obj_c.MW_DIGITALIO_HANDLE, rtb_LED_STATE);

  /* ToAsyncQueueBlock generated from: '<S4>/Pacemaker Control' */
  {
    {
      double time = ((MainModel_LRL_M->Timing.clockTick0) * 0.001);
      void *pData = (void *)&MainModel_LRL_B.count;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(3681928785U, time, pData, size);
    }
  }

  /* Switch: '<S9>/Switch4' incorporates:
   *  Delay: '<S9>/Delay3'
   *  Delay: '<S9>/Delay4'
   */
  if (MainModel_LRL_B.pulse_finished > MainModel_LRL_P.Switch4_Threshold) {
    MainModel_LRL_DW.Delay4_DSTATE = MainModel_LRL_DW.Delay3_DSTATE;
  }

  /* End of Switch: '<S9>/Switch4' */

  /* Switch: '<S9>/Switch3' incorporates:
   *  Delay: '<S9>/Delay2'
   *  Delay: '<S9>/Delay3'
   */
  if (MainModel_LRL_B.pulse_finished > MainModel_LRL_P.Switch3_Threshold) {
    MainModel_LRL_DW.Delay3_DSTATE = MainModel_LRL_DW.Delay2_DSTATE;
  }

  /* End of Switch: '<S9>/Switch3' */

  /* Switch: '<S9>/Switch2' incorporates:
   *  Delay: '<S9>/Delay1'
   *  Delay: '<S9>/Delay2'
   */
  if (MainModel_LRL_B.pulse_finished > MainModel_LRL_P.Switch2_Threshold) {
    MainModel_LRL_DW.Delay2_DSTATE = MainModel_LRL_DW.Delay1_DSTATE;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Delay: '<S9>/Delay'
   *  Delay: '<S9>/Delay1'
   */
  if (MainModel_LRL_B.pulse_finished > MainModel_LRL_P.Switch1_Threshold) {
    MainModel_LRL_DW.Delay1_DSTATE = MainModel_LRL_DW.Delay_DSTATE;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Delay: '<S9>/Delay'
   */
  if (MainModel_LRL_B.pulse_finished > MainModel_LRL_P.Switch_Threshold) {
    MainModel_LRL_DW.Delay_DSTATE = MainModel_LRL_B.time_between_pulses;
  }

  /* End of Switch: '<S9>/Switch' */

  /* ToAsyncQueueBlock generated from: '<Root>/InputProcessing' */
  {
    {
      double time = ((MainModel_LRL_M->Timing.clockTick0) * 0.001);
      void *pData = (void *)&MainModel_LRL_B.wait_time;
      int32_T size = 1*sizeof(real32_T);
      sendToAsyncQueueTgtAppSvc(3973252287U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S9>/TimeBetweenPulses' */
  {
    {
      double time = ((MainModel_LRL_M->Timing.clockTick0) * 0.001);
      void *pData = (void *)&MainModel_LRL_B.time_between_pulses;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(3187686688U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<S2>/ATR_CMP_DETECT' */
  {
    {
      double time = ((MainModel_LRL_M->Timing.clockTick0) * 0.001);
      void *pData = (void *)&MainModel_LRL_B.ATR_CMP_DETECT;
      int32_T size = 1*sizeof(boolean_T);
      sendToAsyncQueueTgtAppSvc(978043829U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S2>/Analog Input' */
  if (MainModel_LRL_DW.obj_n.SampleTime !=
      MainModel_LRL_P.AnalogInput_SampleTime) {
    MainModel_LRL_DW.obj_n.SampleTime = MainModel_LRL_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(MainModel_LRL_DW.obj_n.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(MainModel_LRL_DW.obj_n.MW_ANALOGIN_HANDLE,
    &MainModel_LRL_B.AnalogInput, 7);

  /* End of MATLABSystem: '<S2>/Analog Input' */

  /* ToAsyncQueueBlock generated from: '<S2>/Analog Input' */
  {
    {
      double time = ((MainModel_LRL_M->Timing.clockTick0) * 0.001);
      void *pData = (void *)&MainModel_LRL_B.AnalogInput;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(2523819041U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S2>/Analog Input1' */
  if (MainModel_LRL_DW.obj_i.SampleTime !=
      MainModel_LRL_P.AnalogInput1_SampleTime) {
    MainModel_LRL_DW.obj_i.SampleTime = MainModel_LRL_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(MainModel_LRL_DW.obj_i.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(MainModel_LRL_DW.obj_i.MW_ANALOGIN_HANDLE,
    &MainModel_LRL_B.AnalogInput1, 7);

  /* End of MATLABSystem: '<S2>/Analog Input1' */

  /* ToAsyncQueueBlock generated from: '<S2>/Analog Input1' */
  {
    {
      double time = ((MainModel_LRL_M->Timing.clockTick0) * 0.001);
      void *pData = (void *)&MainModel_LRL_B.AnalogInput1;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(2322880855U, time, pData, size);
    }
  }

  /* MATLABSystem: '<S2>/Digital Write1' incorporates:
   *  Constant: '<S2>/Constant15'
   */
  MW_digitalIO_write(MainModel_LRL_DW.obj_e.MW_DIGITALIO_HANDLE,
                     MainModel_LRL_P.Constant15_Value);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  MainModel_LRL_M->Timing.clockTick0++;
}

/* Model initialize function */
void MainModel_LRL_initialize(void)
{
  {
    freedomk64f_DigitalRead_MainM_T *obj;
    freedomk64f_DigitalWrite_Main_T *obj_0;
    freedomk64f_PWMOutput_MainMod_T *obj_1;
    freedomk64f_AnalogInput_MainM_T *obj_2;
    MW_AnalogIn_TriggerSource_Type trigger_val;

    /* InitializeConditions for Delay: '<S9>/Delay7' */
    MainModel_LRL_DW.Delay7_DSTATE = MainModel_LRL_P.Delay7_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay' */
    MainModel_LRL_DW.Delay_DSTATE = MainModel_LRL_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay1' */
    MainModel_LRL_DW.Delay1_DSTATE = MainModel_LRL_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay2' */
    MainModel_LRL_DW.Delay2_DSTATE = MainModel_LRL_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay3' */
    MainModel_LRL_DW.Delay3_DSTATE = MainModel_LRL_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay4' */
    MainModel_LRL_DW.Delay4_DSTATE = MainModel_LRL_P.Delay4_InitialCondition;

    /* Start for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
    MainModel_LRL_DW.obj.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj.isInitialized = 0;
    MainModel_LRL_DW.obj.SampleTime = -1.0;
    MainModel_LRL_DW.obj.matlabCodegenIsDeleted = false;
    MainModel_LRL_DW.obj.SampleTime = MainModel_LRL_P.ATR_CMP_DETECT_SampleTime;
    obj = &MainModel_LRL_DW.obj;
    MainModel_LRL_DW.obj.isSetupComplete = false;
    MainModel_LRL_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    MainModel_LRL_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
    MainModel_LRL_DW.obj_o.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_o.isInitialized = 0;
    MainModel_LRL_DW.obj_o.SampleTime = -1.0;
    MainModel_LRL_DW.obj_o.matlabCodegenIsDeleted = false;
    MainModel_LRL_DW.obj_o.SampleTime =
      MainModel_LRL_P.VENT_CMP_DETECT_SampleTime;
    obj = &MainModel_LRL_DW.obj_o;
    MainModel_LRL_DW.obj_o.isSetupComplete = false;
    MainModel_LRL_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    MainModel_LRL_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    MainModel_LRL_DW.obj_a.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_a.isInitialized = 0;
    MainModel_LRL_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_a;
    MainModel_LRL_DW.obj_a.isSetupComplete = false;
    MainModel_LRL_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    MainModel_LRL_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    MainModel_LRL_DW.obj_k.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_k.isInitialized = 0;
    MainModel_LRL_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_k;
    MainModel_LRL_DW.obj_k.isSetupComplete = false;
    MainModel_LRL_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    MainModel_LRL_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write2' */
    MainModel_LRL_DW.obj_f.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_f.isInitialized = 0;
    MainModel_LRL_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_f;
    MainModel_LRL_DW.obj_f.isSetupComplete = false;
    MainModel_LRL_DW.obj_f.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    MainModel_LRL_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write3' */
    MainModel_LRL_DW.obj_d.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_d.isInitialized = 0;
    MainModel_LRL_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_d;
    MainModel_LRL_DW.obj_d.isSetupComplete = false;
    MainModel_LRL_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    MainModel_LRL_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output' */
    MainModel_LRL_DW.obj_jd.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_jd.isInitialized = 0;
    MainModel_LRL_DW.obj_jd.matlabCodegenIsDeleted = false;
    obj_1 = &MainModel_LRL_DW.obj_jd;
    MainModel_LRL_DW.obj_jd.isSetupComplete = false;
    MainModel_LRL_DW.obj_jd.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 100.0);
    MW_PWM_Start(MainModel_LRL_DW.obj_jd.MW_PWM_HANDLE);
    MainModel_LRL_DW.obj_jd.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write5' */
    MainModel_LRL_DW.obj_it.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_it.isInitialized = 0;
    MainModel_LRL_DW.obj_it.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_it;
    MainModel_LRL_DW.obj_it.isSetupComplete = false;
    MainModel_LRL_DW.obj_it.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    MainModel_LRL_DW.obj_it.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write6' */
    MainModel_LRL_DW.obj_ka.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_ka.isInitialized = 0;
    MainModel_LRL_DW.obj_ka.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_ka;
    MainModel_LRL_DW.obj_ka.isSetupComplete = false;
    MainModel_LRL_DW.obj_ka.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    MainModel_LRL_DW.obj_ka.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write7' */
    MainModel_LRL_DW.obj_fn.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_fn.isInitialized = 0;
    MainModel_LRL_DW.obj_fn.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_fn;
    MainModel_LRL_DW.obj_fn.isSetupComplete = false;
    MainModel_LRL_DW.obj_fn.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    MainModel_LRL_DW.obj_fn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write8' */
    MainModel_LRL_DW.obj_j.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_j.isInitialized = 0;
    MainModel_LRL_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_j;
    MainModel_LRL_DW.obj_j.isSetupComplete = false;
    MainModel_LRL_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    MainModel_LRL_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output1' */
    MainModel_LRL_DW.obj_av.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_av.isInitialized = 0;
    MainModel_LRL_DW.obj_av.matlabCodegenIsDeleted = false;
    obj_1 = &MainModel_LRL_DW.obj_av;
    MainModel_LRL_DW.obj_av.isSetupComplete = false;
    MainModel_LRL_DW.obj_av.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 20.0);
    MW_PWM_Start(MainModel_LRL_DW.obj_av.MW_PWM_HANDLE);
    MainModel_LRL_DW.obj_av.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output2' */
    MainModel_LRL_DW.obj_km.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_km.isInitialized = 0;
    MainModel_LRL_DW.obj_km.matlabCodegenIsDeleted = false;
    obj_1 = &MainModel_LRL_DW.obj_km;
    MainModel_LRL_DW.obj_km.isSetupComplete = false;
    MainModel_LRL_DW.obj_km.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 20.0);
    MW_PWM_Start(MainModel_LRL_DW.obj_km.MW_PWM_HANDLE);
    MainModel_LRL_DW.obj_km.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    MainModel_LRL_DW.obj_c.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_c.isInitialized = 0;
    MainModel_LRL_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_c;
    MainModel_LRL_DW.obj_c.isSetupComplete = false;
    MainModel_LRL_DW.obj_c.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    MainModel_LRL_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input' */
    MainModel_LRL_DW.obj_n.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_n.isInitialized = 0;
    MainModel_LRL_DW.obj_n.SampleTime = -1.0;
    MainModel_LRL_DW.obj_n.matlabCodegenIsDeleted = false;
    MainModel_LRL_DW.obj_n.SampleTime = MainModel_LRL_P.AnalogInput_SampleTime;
    obj_2 = &MainModel_LRL_DW.obj_n;
    MainModel_LRL_DW.obj_n.isSetupComplete = false;
    MainModel_LRL_DW.obj_n.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(MainModel_LRL_DW.obj_n.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    MainModel_LRL_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input1' */
    MainModel_LRL_DW.obj_i.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_i.isInitialized = 0;
    MainModel_LRL_DW.obj_i.SampleTime = -1.0;
    MainModel_LRL_DW.obj_i.matlabCodegenIsDeleted = false;
    MainModel_LRL_DW.obj_i.SampleTime = MainModel_LRL_P.AnalogInput1_SampleTime;
    obj_2 = &MainModel_LRL_DW.obj_i;
    MainModel_LRL_DW.obj_i.isSetupComplete = false;
    MainModel_LRL_DW.obj_i.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(MainModel_LRL_DW.obj_i.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    MainModel_LRL_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    MainModel_LRL_DW.obj_e.matlabCodegenIsDeleted = true;
    MainModel_LRL_DW.obj_e.isInitialized = 0;
    MainModel_LRL_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &MainModel_LRL_DW.obj_e;
    MainModel_LRL_DW.obj_e.isSetupComplete = false;
    MainModel_LRL_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    MainModel_LRL_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void MainModel_LRL_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  matlabCodegenHa_lmiwv4or5bzkwoc(&MainModel_LRL_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  matlabCodegenHa_lmiwv4or5bzkwoc(&MainModel_LRL_DW.obj_o);

  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_a);

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_k);

  /* Terminate for MATLABSystem: '<S1>/Digital Write2' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_f);

  /* Terminate for MATLABSystem: '<S1>/Digital Write3' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_d);

  /* Terminate for MATLABSystem: '<S1>/PWM Output' */
  matlabCodegenHandle_matlabCodeg(&MainModel_LRL_DW.obj_jd);

  /* Terminate for MATLABSystem: '<S1>/Digital Write5' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_it);

  /* Terminate for MATLABSystem: '<S1>/Digital Write6' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_ka);

  /* Terminate for MATLABSystem: '<S1>/Digital Write7' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_fn);

  /* Terminate for MATLABSystem: '<S1>/Digital Write8' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_j);

  /* Terminate for MATLABSystem: '<S1>/PWM Output1' */
  matlabCodegenHandle_matlabCodeg(&MainModel_LRL_DW.obj_av);

  /* Terminate for MATLABSystem: '<S1>/PWM Output2' */
  matlabCodegenHandle_matlabCodeg(&MainModel_LRL_DW.obj_km);

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_c);

  /* Terminate for MATLABSystem: '<S2>/Analog Input' */
  matlabCodegenHandl_lmiwv4or5bzk(&MainModel_LRL_DW.obj_n);

  /* Terminate for MATLABSystem: '<S2>/Analog Input1' */
  matlabCodegenHandl_lmiwv4or5bzk(&MainModel_LRL_DW.obj_i);

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  matlabCodegenHandle_matlabCo_lm(&MainModel_LRL_DW.obj_e);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
