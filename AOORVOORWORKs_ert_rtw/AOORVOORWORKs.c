/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AOORVOORWORKs.c
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

#include "AOORVOORWORKs.h"
#include "AOORVOORWORKs_private.h"

/* Named constants for Chart: '<S1>/Chart1' */
#define AOORVOORWORK_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define AOORVOORWORKs_IN_Initial_State ((uint8_T)2U)
#define AOORVOORWORKs_IN_Read_Data     ((uint8_T)3U)
#define AOORVOORWORKs_IN_Safety_Check  ((uint8_T)4U)
#define AOORVOORWORKs_IN_Standby       ((uint8_T)5U)
#define AOORVOORWORKs_IN_Write_Data    ((uint8_T)6U)
#define AOORVOOR_IN_setToZeroForTesting ((uint8_T)7U)
#define AOORV_IN_HandshakeRequestEnable ((uint8_T)1U)

/* Named constants for Chart: '<S1>/HeartChamberPulseDetection' */
#define AOORVOORWORKs_IN_default       ((uint8_T)1U)
#define AOORVOORWORKs_IN_led_on        ((uint8_T)2U)

/* Named constants for Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */
#define AOORVOORWORKs_IN_UnsensedModes ((uint8_T)2U)
#define AOORVOORWORKs_IN_awaitNewPulse ((uint8_T)1U)
#define AOORVOORWORKs_IN_default_m     ((uint8_T)4U)
#define AOORVOORWORKs_IN_default_mk    ((uint8_T)2U)
#define AOORVOORWORKs_IN_resetDeltaT   ((uint8_T)4U)
#define AOORVOORWORKs_IN_setARPasDeltaT ((uint8_T)5U)
#define AOORVOORWORKs_IN_setVRPasDeltaT ((uint8_T)5U)
#define AOORVOORWOR_IN_newPulseDetected ((uint8_T)3U)
#define AOORVOOR_IN_AtrialRateDetection ((uint8_T)1U)
#define AOOR_IN_VenticularRateDetection ((uint8_T)3U)

/* Named constants for Chart: '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
#define AOORVOORWORKs_IN_AAI           ((uint8_T)1U)
#define AOORVOORWORKs_IN_AAIR          ((uint8_T)2U)
#define AOORVOORWORKs_IN_VVI           ((uint8_T)4U)
#define AOORVOOR_IN_HysterisisSelection ((uint8_T)3U)

/* Named constants for Chart: '<S2>/Activity Index Determination' */
#define AOORVOORWORKs_IN_High          ((uint8_T)1U)
#define AOORVOORWORKs_IN_Low           ((uint8_T)2U)
#define AOORVOORWORKs_IN_Med           ((uint8_T)3U)
#define AOORVOORWORKs_IN_Med_High      ((uint8_T)4U)
#define AOORVOORWORKs_IN_Med_Low       ((uint8_T)5U)
#define AOORVOORWORKs_IN_V_High        ((uint8_T)6U)
#define AOORVOORWORKs_IN_V_Low         ((uint8_T)7U)
#define AOORVOORWORKs_IN_init          ((uint8_T)8U)

/* Named constants for Chart: '<S2>/Chart' */
#define AOORVOORWORKs_IN_STEPUP        ((uint8_T)1U)
#define AOORVOORWORKs_IN_overThreshold ((uint8_T)3U)
#define AOORVOORWORKs_IN_start         ((uint8_T)4U)
#define AOORVOORWORKs_IN_stepdown      ((uint8_T)5U)

/* Named constants for Chart: '<S3>/1.1.3.2 PacemakerControl' */
#define AOORVOORWORK_IN_initializations ((uint8_T)5U)
#define AOORVOORWORKs_IN_AOO           ((uint8_T)3U)
#define AOORVOORWORKs_IN_AOOR          ((uint8_T)4U)
#define AOORVOORWORKs_IN_CHARGE        ((uint8_T)1U)
#define AOORVOORWORKs_IN_DISCHARGE     ((uint8_T)2U)
#define AOORVOORWORKs_IN_Initialize    ((uint8_T)5U)
#define AOORVOORWORKs_IN_Pulse         ((uint8_T)4U)
#define AOORVOORWORKs_IN_Standby_a     ((uint8_T)6U)
#define AOORVOORWORKs_IN_VOO           ((uint8_T)7U)
#define AOORVOORWORKs_IN_VOOR          ((uint8_T)8U)
#define AOORVOORWORKs_IN_VVI_n         ((uint8_T)9U)
#define AOORVOORW_IN_Hysterisis_mode_ON ((uint8_T)3U)
#define AOORVOOR_IN_Hysterisis_mode_OFF ((uint8_T)2U)

/* Block signals (default storage) */
B_AOORVOORWORKs_T AOORVOORWORKs_B;

/* Block states (default storage) */
DW_AOORVOORWORKs_T AOORVOORWORKs_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_AOORVOORWORKs_T AOORVOORWORKs_PrevZCX;

/* Real-time model */
RT_MODEL_AOORVOORWORKs_T AOORVOORWORKs_M_;
RT_MODEL_AOORVOORWORKs_T *const AOORVOORWORKs_M = &AOORVOORWORKs_M_;

/* Forward declaration for local functions */
static void AOORVOORWORKs_VVI(void);
static void AOORVOORWORKs_AAI(void);
static void AOORVOORWORKs_AAIR(void);
static void AOORVOORWORKs_AOO(void);
static void AOORVOORWORKs_AOOR(void);
static void AOOR_SystemCore_release_jfpx5x5(const
  freedomk64f_SCIRead_AOORVOORW_T *obj);
static void AOORV_SystemCore_delete_jfpx5x5(const
  freedomk64f_SCIRead_AOORVOORW_T *obj);
static void matlabCodegenHandle_mat_jfpx5x5(freedomk64f_SCIRead_AOORVOORW_T *obj);
static void AOORVO_SystemCore_release_jfpx5(const
  freedomk64f_DigitalRead_AOORV_T *obj);
static void AOORVOO_SystemCore_delete_jfpx5(const
  freedomk64f_DigitalRead_AOORV_T *obj);
static void matlabCodegenHandle_matla_jfpx5(freedomk64f_DigitalRead_AOORV_T *obj);
static void AOORVOORWORK_SystemCore_release(const
  freedomk64f_DigitalWrite_AOOR_T *obj);
static void AOORVOORWORKs_SystemCore_delete(const
  freedomk64f_DigitalWrite_AOOR_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_AOOR_T *obj);
static void SystemCore_releas_jfpx5x5vtseop(const
  freedomk64f_PWMOutput_AOORVOO_T *obj);
static void SystemCore_delete_jfpx5x5vtseop(const
  freedomk64f_PWMOutput_AOORVOO_T *obj);
static void matlabCodegenHand_jfpx5x5vtseop(freedomk64f_PWMOutput_AOORVOO_T *obj);
static void AOORVOORWO_SystemCore_release_j(const
  freedomk64f_AnalogInput_AOORV_T *obj);
static void AOORVOORWOR_SystemCore_delete_j(const
  freedomk64f_AnalogInput_AOORV_T *obj);
static void matlabCodegenHandle_matlabCod_j(freedomk64f_AnalogInput_AOORV_T *obj);
static void AOO_SystemCore_release_jfpx5x5v(const
  freedomk64f_SCIWrite_AOORVOOR_T *obj);
static void AOOR_SystemCore_delete_jfpx5x5v(const
  freedomk64f_SCIWrite_AOORVOOR_T *obj);
static void matlabCodegenHandle_ma_jfpx5x5v(freedomk64f_SCIWrite_AOORVOOR_T *obj);
static void A_SystemCore_release_jfpx5x5vts(const
  freedomk64f_fxos8700_AOORVOOR_T *obj);
static void AO_SystemCore_delete_jfpx5x5vts(const
  freedomk64f_fxos8700_AOORVOOR_T *obj);
static void matlabCodegenHandle__jfpx5x5vts(freedomk64f_fxos8700_AOORVOOR_T *obj);
static void SystemCore_release_jfpx5x5vtse(b_freedomk64f_I2CMasterWrite__T *obj);
static void A_SystemCore_delete_jfpx5x5vtse(b_freedomk64f_I2CMasterWrite__T *obj);
static void matlabCodegenHandle_jfpx5x5vtse(b_freedomk64f_I2CMasterWrite__T *obj);
static void AO_SystemCore_release_jfpx5x5vt(dsp_simulink_MovingAverage_AO_T *obj);
static void AOO_SystemCore_delete_jfpx5x5vt(dsp_simulink_MovingAverage_AO_T *obj);
static void matlabCodegenHandle_m_jfpx5x5vt(dsp_simulink_MovingAverage_AO_T *obj);
static void AOORVOORWORK_SystemCore_setup_j(freedomk64f_SCIWrite_AOORVOOR_T *obj);
static void AOORVOORWOR_SystemCore_setup_jf(freedomk64f_fxos8700_AOORVOOR_T *obj);
static void AOORVOORWORKs_SystemCore_setup(freedomk64f_SCIRead_AOORVOORW_T *obj);
real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_sat(uint32_T a, uint32_T b)
{
  uint32_T result;
  uint32_T u32_chi;
  mul_wide_u32(a, b, &u32_chi, &result);
  if (u32_chi) {
    result = MAX_uint32_T;
  }

  return result;
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  real32_T tmp_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AOORVOORWORKs_VVI(void)
{
  if (AOORVOORWORKs_B.Mode != AOORVOORWORKs_DW.VVI) {
    AOORVOORWORKs_DW.is_VVI = AOORVOORWORK_IN_NO_ACTIVE_CHILD;
    AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
    AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
    AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
  } else {
    switch (AOORVOORWORKs_DW.is_VVI) {
     case AOORVOORWORKs_IN_CHARGE:
      if (AOORVOORWORKs_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AOORVOORWORKs_B.ventricular_pulse_width)) {
        AOORVOORWORKs_DW.is_VVI = AOORVOORWORKs_IN_Pulse;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
      }
      break;

     case AOORVOOR_IN_Hysterisis_mode_OFF:
      /* Constant: '<S21>/LOW' */
      if ((AOORVOORWORKs_B.count <= AOORVOORWORKs_B.wait_time) &&
          ((AOORVOORWORKs_B.VENT_CMP_DETECT != AOORVOORWORKs_P.LOW_Value) ||
           (!(AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.lower_rate_limit)))) {
        AOORVOORWORKs_DW.is_VVI = AOORVOOR_IN_Hysterisis_mode_OFF;
        AOORVOORWORKs_B.count++;
      } else {
        if ((AOORVOORWORKs_B.VENT_CMP_DETECT == AOORVOORWORKs_P.LOW_Value) &&
            (AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.lower_rate_limit)) {
          AOORVOORWORKs_DW.is_VVI = AOORVOORWORKs_IN_CHARGE;
          AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
          AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

          /* Constant: '<S21>/HIGH' */
          AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;

          /* Constant: '<S21>/HIGH' */
          AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
        }
      }
      break;

     case AOORVOORW_IN_Hysterisis_mode_ON:
      /* Constant: '<S21>/LOW' */
      if ((AOORVOORWORKs_B.VENT_CMP_DETECT == AOORVOORWORKs_P.LOW_Value) &&
          (AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.h_r_l)) {
        AOORVOORWORKs_DW.is_VVI = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
      } else {
        if ((AOORVOORWORKs_B.count <= AOORVOORWORKs_B.wait_time) &&
            ((AOORVOORWORKs_B.VENT_CMP_DETECT != AOORVOORWORKs_P.LOW_Value) || (
              !(AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.lower_rate_limit)))) {
          AOORVOORWORKs_DW.is_VVI = AOORVOORW_IN_Hysterisis_mode_ON;
          AOORVOORWORKs_B.count++;
        }
      }
      break;

     case AOORVOORWORKs_IN_Pulse:
      if (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.v_r_p) {
        AOORVOORWORKs_DW.is_VVI = AOORVOORWORK_IN_initializations;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.VENT_CMP_REF_PWM =
          AOORVOORWORKs_B.ventricular_sensitivity;
        AOORVOORWORKs_B.count = 0.0;
      }
      break;

     default:
      /* case IN_initializations: */
      if ((AOORVOORWORKs_B.hysterisis_flag == 0) &&
          (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.wait_time_LRL))
      {
        AOORVOORWORKs_DW.is_VVI = AOORVOOR_IN_Hysterisis_mode_OFF;
        AOORVOORWORKs_B.count++;
      } else {
        if ((AOORVOORWORKs_B.hysterisis_flag == 1) &&
            (AOORVOORWORKs_DW.temporalCounter_i1 >=
             AOORVOORWORKs_B.wait_time_LRL)) {
          AOORVOORWORKs_DW.is_VVI = AOORVOORW_IN_Hysterisis_mode_ON;
          AOORVOORWORKs_B.count++;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AOORVOORWORKs_AAI(void)
{
  if (AOORVOORWORKs_B.Mode != AOORVOORWORKs_DW.AAI) {
    AOORVOORWORKs_DW.is_AAI = AOORVOORWORK_IN_NO_ACTIVE_CHILD;
    AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
    AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
    AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
  } else {
    switch (AOORVOORWORKs_DW.is_AAI) {
     case AOORVOORWORKs_IN_CHARGE:
      if (AOORVOORWORKs_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AOORVOORWORKs_B.atrial_pulse_width)) {
        AOORVOORWORKs_DW.is_AAI = AOORVOORWORKs_IN_Pulse;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      }
      break;

     case AOORVOOR_IN_Hysterisis_mode_OFF:
      /* Constant: '<S21>/LOW' */
      if ((AOORVOORWORKs_B.count <= AOORVOORWORKs_B.wait_time) &&
          ((AOORVOORWORKs_B.ATR_CMP_DETECT != AOORVOORWORKs_P.LOW_Value) ||
           (!(AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.lower_rate_limit)))) {
        AOORVOORWORKs_DW.is_AAI = AOORVOOR_IN_Hysterisis_mode_OFF;
        AOORVOORWORKs_B.count++;
      } else {
        if ((AOORVOORWORKs_B.ATR_CMP_DETECT == AOORVOORWORKs_P.LOW_Value) &&
            (AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.lower_rate_limit)) {
          AOORVOORWORKs_DW.is_AAI = AOORVOORWORKs_IN_CHARGE;
          AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
          AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

          /* Constant: '<S21>/HIGH' */
          AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
        }
      }
      break;

     case AOORVOORW_IN_Hysterisis_mode_ON:
      /* Constant: '<S21>/LOW' */
      if ((AOORVOORWORKs_B.ATR_CMP_DETECT == AOORVOORWORKs_P.LOW_Value) &&
          (AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.h_r_l)) {
        AOORVOORWORKs_DW.is_AAI = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
      } else {
        if ((AOORVOORWORKs_B.count <= AOORVOORWORKs_B.wait_time) &&
            ((AOORVOORWORKs_B.ATR_CMP_DETECT != AOORVOORWORKs_P.LOW_Value) ||
             (!(AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.lower_rate_limit)))) {
          AOORVOORWORKs_DW.is_AAI = AOORVOORW_IN_Hysterisis_mode_ON;
          AOORVOORWORKs_B.count++;
        }
      }
      break;

     case AOORVOORWORKs_IN_Pulse:
      if (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.a_r_p) {
        AOORVOORWORKs_DW.is_AAI = AOORVOORWORK_IN_initializations;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_CMP_REF_PWM = AOORVOORWORKs_B.atrial_sensitivity;
        AOORVOORWORKs_B.count = 0.0;
      }
      break;

     default:
      /* case IN_initializations: */
      if ((AOORVOORWORKs_B.hysterisis_flag == 0) &&
          (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.wait_time_LRL))
      {
        AOORVOORWORKs_DW.is_AAI = AOORVOOR_IN_Hysterisis_mode_OFF;
        AOORVOORWORKs_B.count++;
      } else {
        if ((AOORVOORWORKs_B.hysterisis_flag == 1) &&
            (AOORVOORWORKs_DW.temporalCounter_i1 >=
             AOORVOORWORKs_B.wait_time_LRL)) {
          AOORVOORWORKs_DW.is_AAI = AOORVOORW_IN_Hysterisis_mode_ON;
          AOORVOORWORKs_B.count++;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AOORVOORWORKs_AAIR(void)
{
  if (AOORVOORWORKs_B.Mode != AOORVOORWORKs_DW.AAIR) {
    AOORVOORWORKs_DW.is_AAIR = AOORVOORWORK_IN_NO_ACTIVE_CHILD;
    AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
    AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
    AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
  } else {
    switch (AOORVOORWORKs_DW.is_AAIR) {
     case AOORVOORWORKs_IN_CHARGE:
      if (AOORVOORWORKs_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AOORVOORWORKs_B.atrial_pulse_width)) {
        AOORVOORWORKs_DW.is_AAIR = AOORVOORWORKs_IN_Pulse;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

        /* Constant: '<S21>/LOW' */
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      }
      break;

     case AOORVOOR_IN_Hysterisis_mode_OFF:
      /* Constant: '<S21>/LOW' */
      if ((AOORVOORWORKs_B.ATR_CMP_DETECT == AOORVOORWORKs_P.LOW_Value) &&
          (AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.CR)) {
        AOORVOORWORKs_DW.is_AAIR = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
      }
      break;

     case AOORVOORW_IN_Hysterisis_mode_ON:
      /* Constant: '<S21>/LOW' */
      if ((AOORVOORWORKs_B.ATR_CMP_DETECT == AOORVOORWORKs_P.LOW_Value) &&
          (AOORVOORWORKs_B.Gain4 < AOORVOORWORKs_B.CR - 5.0F)) {
        AOORVOORWORKs_DW.is_AAIR = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

        /* Constant: '<S21>/HIGH' */
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
      }
      break;

     case AOORVOORWORKs_IN_Pulse:
      if (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.a_r_p) {
        AOORVOORWORKs_DW.is_AAIR = AOORVOORWORK_IN_initializations;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_CMP_REF_PWM = AOORVOORWORKs_B.atrial_sensitivity;
      }
      break;

     default:
      /* case IN_initializations: */
      if ((AOORVOORWORKs_B.hysterisis_flag == 0) &&
          (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.wait_time_AAIR))
      {
        AOORVOORWORKs_DW.is_AAIR = AOORVOOR_IN_Hysterisis_mode_OFF;
      } else {
        if ((AOORVOORWORKs_B.hysterisis_flag == 1) &&
            (AOORVOORWORKs_DW.temporalCounter_i1 >=
             AOORVOORWORKs_B.wait_time_AAIR)) {
          AOORVOORWORKs_DW.is_AAIR = AOORVOORW_IN_Hysterisis_mode_ON;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AOORVOORWORKs_AOO(void)
{
  if (AOORVOORWORKs_B.Mode != AOORVOORWORKs_DW.AOO) {
    AOORVOORWORKs_DW.is_AOO = AOORVOORWORK_IN_NO_ACTIVE_CHILD;
    AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
    AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
    AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
  } else if (AOORVOORWORKs_DW.is_AOO == AOORVOORWORKs_IN_CHARGE) {
    if (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.MathFunction1 -
        (real32_T)AOORVOORWORKs_B.atrial_pulse_width) {
      AOORVOORWORKs_DW.is_AOO = AOORVOORWORKs_IN_DISCHARGE;
      AOORVOORWORKs_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

      /* Constant: '<S21>/HIGH' */
      AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
      AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
    }
  } else {
    /* case IN_DISCHARGE: */
    if (AOORVOORWORKs_DW.temporalCounter_i1 >= (uint32_T)ceil
        (AOORVOORWORKs_B.atrial_pulse_width)) {
      AOORVOORWORKs_DW.is_AOO = AOORVOORWORKs_IN_CHARGE;
      AOORVOORWORKs_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;

      /* Constant: '<S21>/HIGH' */
      AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
      AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;

      /* Constant: '<S21>/HIGH' */
      AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AOORVOORWORKs_AOOR(void)
{
  real_T tmp;
  uint32_T tmp_0;
  if (AOORVOORWORKs_B.Mode != AOORVOORWORKs_DW.AOOR) {
    AOORVOORWORKs_DW.is_AOOR = AOORVOORWORK_IN_NO_ACTIVE_CHILD;
    AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
    AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
    AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
  } else if (AOORVOORWORKs_DW.is_AOOR == AOORVOORWORKs_IN_CHARGE) {
    tmp = rt_roundd_snf((real_T)AOORVOORWORKs_B.Cast -
                        AOORVOORWORKs_B.atrial_pulse_width);
    if (tmp < 4.294967296E+9) {
      if (tmp >= 0.0) {
        tmp_0 = (uint32_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint32_T;
    }

    if (AOORVOORWORKs_DW.temporalCounter_i1 >= tmp_0) {
      AOORVOORWORKs_DW.is_AOOR = AOORVOORWORKs_IN_DISCHARGE;
      AOORVOORWORKs_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;

      /* Constant: '<S21>/HIGH' */
      AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
      AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
    }
  } else {
    /* case IN_DISCHARGE: */
    if (AOORVOORWORKs_DW.temporalCounter_i1 >= (uint32_T)ceil
        (AOORVOORWORKs_B.atrial_pulse_width)) {
      AOORVOORWORKs_DW.is_AOOR = AOORVOORWORKs_IN_CHARGE;
      AOORVOORWORKs_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;

      /* Constant: '<S21>/HIGH' */
      AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
      AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
      AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;

      /* Constant: '<S21>/HIGH' */
      AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;

      /* Constant: '<S21>/LOW' */
      AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
    }
  }
}

static void AOOR_SystemCore_release_jfpx5x5(const
  freedomk64f_SCIRead_AOORVOORW_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void AOORV_SystemCore_delete_jfpx5x5(const
  freedomk64f_SCIRead_AOORVOORW_T *obj)
{
  AOOR_SystemCore_release_jfpx5x5(obj);
}

static void matlabCodegenHandle_mat_jfpx5x5(freedomk64f_SCIRead_AOORVOORW_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AOORV_SystemCore_delete_jfpx5x5(obj);
  }
}

static void AOORVO_SystemCore_release_jfpx5(const
  freedomk64f_DigitalRead_AOORV_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void AOORVOO_SystemCore_delete_jfpx5(const
  freedomk64f_DigitalRead_AOORV_T *obj)
{
  AOORVO_SystemCore_release_jfpx5(obj);
}

static void matlabCodegenHandle_matla_jfpx5(freedomk64f_DigitalRead_AOORV_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AOORVOO_SystemCore_delete_jfpx5(obj);
  }
}

static void AOORVOORWORK_SystemCore_release(const
  freedomk64f_DigitalWrite_AOOR_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void AOORVOORWORKs_SystemCore_delete(const
  freedomk64f_DigitalWrite_AOOR_T *obj)
{
  AOORVOORWORK_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_AOOR_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AOORVOORWORKs_SystemCore_delete(obj);
  }
}

static void SystemCore_releas_jfpx5x5vtseop(const
  freedomk64f_PWMOutput_AOORVOO_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void SystemCore_delete_jfpx5x5vtseop(const
  freedomk64f_PWMOutput_AOORVOO_T *obj)
{
  SystemCore_releas_jfpx5x5vtseop(obj);
}

static void matlabCodegenHand_jfpx5x5vtseop(freedomk64f_PWMOutput_AOORVOO_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete_jfpx5x5vtseop(obj);
  }
}

static void AOORVOORWO_SystemCore_release_j(const
  freedomk64f_AnalogInput_AOORV_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_AnalogIn_Stop(obj->MW_ANALOGIN_HANDLE);
    MW_AnalogIn_Close(obj->MW_ANALOGIN_HANDLE);
  }
}

static void AOORVOORWOR_SystemCore_delete_j(const
  freedomk64f_AnalogInput_AOORV_T *obj)
{
  AOORVOORWO_SystemCore_release_j(obj);
}

static void matlabCodegenHandle_matlabCod_j(freedomk64f_AnalogInput_AOORV_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AOORVOORWOR_SystemCore_delete_j(obj);
  }
}

static void AOO_SystemCore_release_jfpx5x5v(const
  freedomk64f_SCIWrite_AOORVOOR_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void AOOR_SystemCore_delete_jfpx5x5v(const
  freedomk64f_SCIWrite_AOORVOOR_T *obj)
{
  AOO_SystemCore_release_jfpx5x5v(obj);
}

static void matlabCodegenHandle_ma_jfpx5x5v(freedomk64f_SCIWrite_AOORVOOR_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AOOR_SystemCore_delete_jfpx5x5v(obj);
  }
}

static void A_SystemCore_release_jfpx5x5vts(const
  freedomk64f_fxos8700_AOORVOOR_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void AO_SystemCore_delete_jfpx5x5vts(const
  freedomk64f_fxos8700_AOORVOOR_T *obj)
{
  A_SystemCore_release_jfpx5x5vts(obj);
}

static void matlabCodegenHandle__jfpx5x5vts(freedomk64f_fxos8700_AOORVOOR_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AO_SystemCore_delete_jfpx5x5vts(obj);
  }
}

static void SystemCore_release_jfpx5x5vtse(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void A_SystemCore_delete_jfpx5x5vtse(b_freedomk64f_I2CMasterWrite__T *obj)
{
  SystemCore_release_jfpx5x5vtse(obj);
}

static void matlabCodegenHandle_jfpx5x5vtse(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    A_SystemCore_delete_jfpx5x5vtse(obj);
  }
}

static void AO_SystemCore_release_jfpx5x5vt(dsp_simulink_MovingAverage_AO_T *obj)
{
  g_dsp_private_SlidingWindowAv_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void AOO_SystemCore_delete_jfpx5x5vt(dsp_simulink_MovingAverage_AO_T *obj)
{
  AO_SystemCore_release_jfpx5x5vt(obj);
}

static void matlabCodegenHandle_m_jfpx5x5vt(dsp_simulink_MovingAverage_AO_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AOO_SystemCore_delete_jfpx5x5vt(obj);
  }
}

static void AOORVOORWORK_SystemCore_setup_j(freedomk64f_SCIWrite_AOORVOOR_T *obj)
{
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  AOORVOORWORKs_B.RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, AOORVOORWORKs_B.RxPinLoc,
    10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void AOORVOORWOR_SystemCore_setup_jf(freedomk64f_fxos8700_AOORVOOR_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_RegisterValue;
  uint8_T b_SwappedDataBytes[2];
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  obj->isSetupComplete = true;
}

static void AOORVOORWORKs_SystemCore_setup(freedomk64f_SCIRead_AOORVOORW_T *obj)
{
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  AOORVOORWORKs_B.TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U,
    AOORVOORWORKs_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void AOORVOORWORKs_step(void)
{
  uint8_T status;
  int16_T b_output[3];
  uint8_T output_raw[6];
  uint8_T y[2];
  uint8_T b_x[2];
  boolean_T rtb_LED_STATE_f;
  uint32_T rtb_CastToSingle9;
  int32_T i;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  uint32_T qY;
  uint64m_T tmp;
  real32_T stepup_tmp;

  /* MATLABSystem: '<S1>/Serial Receive' */
  if (AOORVOORWORKs_DW.obj_m.SampleTime !=
      AOORVOORWORKs_P.SerialReceive_SampleTime) {
    AOORVOORWORKs_DW.obj_m.SampleTime = AOORVOORWORKs_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(AOORVOORWORKs_DW.obj_m.MW_SCIHANDLE,
    AOORVOORWORKs_B.RxDataLocChar, 99U);
  memcpy((void *)&AOORVOORWORKs_B.RxData[0], (void *)
         &AOORVOORWORKs_B.RxDataLocChar[0], (uint32_T)((size_t)99 * sizeof
          (uint8_T)));

  /* Chart: '<S1>/Chart1' incorporates:
   *  MATLABSystem: '<S1>/Serial Receive'
   */
  if (AOORVOORWORKs_DW.temporalCounter_i1_m < 1U) {
    AOORVOORWORKs_DW.temporalCounter_i1_m++;
  }

  if (AOORVOORWORKs_DW.is_active_c9_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c9_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Initial_State;
    AOORVOORWORKs_B.Mode = 100U;
    AOORVOORWORKs_B.upper_rate_limit = 175U;
    AOORVOORWORKs_B.lower_rate_limit = 60U;
    AOORVOORWORKs_B.atrial_amplitude = 3.75F;
    AOORVOORWORKs_B.atrial_pulse_width = 0.4;
    AOORVOORWORKs_B.ventricular_amplitude = 3.75F;
    AOORVOORWORKs_B.ventricular_pulse_width = 1.0;
    AOORVOORWORKs_B.a_r_p = 250U;
    AOORVOORWORKs_B.p_v_a_r_p = 250U;
    AOORVOORWORKs_B.h_r_l = 45U;
    AOORVOORWORKs_B.r_s_up = 0.09;
    AOORVOORWORKs_B.r_s_down = 0.09;
    AOORVOORWORKs_B.ventricular_sensitivity = 2.5F;
    AOORVOORWORKs_B.atrial_sensitivity = 2.75F;
    AOORVOORWORKs_B.v_r_p = 320U;
    AOORVOORWORKs_B.hysterisis_flag = 0U;
    AOORVOORWORKs_B.activity_threshold = 2U;
    AOORVOORWORKs_B.ReactionTime = 10U;
    AOORVOORWORKs_B.ResponseFactor = 6U;
    AOORVOORWORKs_B.RecoveryTime = 2U;
    AOORVOORWORKs_B.MSR = 120U;
  } else {
    switch (AOORVOORWORKs_DW.is_c9_AOORVOORWORKs) {
     case AOORV_IN_HandshakeRequestEnable:
      AOORVOORWORKs_B.Handshake_Request = 1U;
      if (AOORVOORWORKs_DW.temporalCounter_i1_m >= 1U) {
        AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Standby;
        AOORVOORWORKs_B.Handshake_Request = 0U;
      }
      break;

     case AOORVOORWORKs_IN_Initial_State:
      AOORVOORWORKs_B.ventricular_sensitivity = 2.5F;
      AOORVOORWORKs_B.atrial_sensitivity = 2.75F;
      AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Standby;
      AOORVOORWORKs_B.Handshake_Request = 0U;
      break;

     case AOORVOORWORKs_IN_Read_Data:
      if (AOORVOORWORKs_DW.temporalCounter_i1_m >= 1U) {
        AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Safety_Check;
        AOORVOORWORKs_DW.safety_flag = true;
        if (AOORVOORWORKs_DW.safety_flag) {
          AOORVOORWORKs_DW.safety_flag = (((uint32_T)(50U <=
            AOORVOORWORKs_DW.lower_rate_limit_U) <=
            AOORVOORWORKs_B.upper_rate_limit) && AOORVOORWORKs_DW.safety_flag);
          AOORVOORWORKs_DW.safety_flag = (((AOORVOORWORKs_DW.Mode_U == 100U) ||
            (AOORVOORWORKs_DW.Mode_U == 200U) || (AOORVOORWORKs_DW.Mode_U ==
            112U) || (AOORVOORWORKs_DW.Mode_U == 222U) ||
            (AOORVOORWORKs_DW.Mode_U == 1000U) || (AOORVOORWORKs_DW.Mode_U ==
            1120U) || (AOORVOORWORKs_DW.Mode_U == 2000U) ||
            (AOORVOORWORKs_DW.Mode_U == 2220U) || (AOORVOORWORKs_DW.Mode_U ==
            3330U)) && AOORVOORWORKs_DW.safety_flag);
          AOORVOORWORKs_DW.safety_flag = (((AOORVOORWORKs_DW.Mode_U != 100U) ||
            (AOORVOORWORKs_DW.lower_rate_limit_U != 60U) ||
            (!(AOORVOORWORKs_DW.atrial_pulse_width_U == 0.4)) ||
            (AOORVOORWORKs_DW.a_r_p_U != 250U)) && AOORVOORWORKs_DW.safety_flag);
        }
      }
      break;

     case AOORVOORWORKs_IN_Safety_Check:
      if (!AOORVOORWORKs_DW.safety_flag) {
        AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOOR_IN_setToZeroForTesting;
      } else {
        AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Write_Data;
        AOORVOORWORKs_B.Mode = AOORVOORWORKs_DW.Mode_U;
        AOORVOORWORKs_B.upper_rate_limit = AOORVOORWORKs_DW.upper_rate_limit_U;
        AOORVOORWORKs_B.lower_rate_limit = AOORVOORWORKs_DW.lower_rate_limit_U;
        AOORVOORWORKs_B.atrial_amplitude = AOORVOORWORKs_DW.atrial_amplitude_U;
        AOORVOORWORKs_B.atrial_pulse_width =
          AOORVOORWORKs_DW.atrial_pulse_width_U;
        AOORVOORWORKs_B.ventricular_amplitude =
          AOORVOORWORKs_DW.ventricular_amplitude_U;
        AOORVOORWORKs_B.ventricular_pulse_width =
          AOORVOORWORKs_DW.ventricular_pulse_width_U;
        AOORVOORWORKs_B.a_r_p = AOORVOORWORKs_DW.a_r_p_U;
        AOORVOORWORKs_B.p_v_a_r_p = AOORVOORWORKs_DW.p_v_a_r_p_U;
        AOORVOORWORKs_B.h_r_l = AOORVOORWORKs_DW.h_r_l_U;
        AOORVOORWORKs_B.r_s_up = AOORVOORWORKs_DW.r_s_up_U;
        AOORVOORWORKs_B.r_s_down = AOORVOORWORKs_DW.r_s_down_U;
        AOORVOORWORKs_B.ventricular_sensitivity = 2.5F;
        AOORVOORWORKs_B.atrial_sensitivity = 2.75F;
        AOORVOORWORKs_B.v_r_p = AOORVOORWORKs_DW.v_r_p_U;
        AOORVOORWORKs_B.hysterisis_flag = AOORVOORWORKs_DW.hysterisis_flag_U;
        AOORVOORWORKs_B.activity_threshold =
          AOORVOORWORKs_DW.activity_threshold_U;
        AOORVOORWORKs_B.ReactionTime = AOORVOORWORKs_DW.ReactionTime_U;
        AOORVOORWORKs_B.ResponseFactor = AOORVOORWORKs_DW.ResponseFactor_U;
        AOORVOORWORKs_B.RecoveryTime = AOORVOORWORKs_DW.RecoveryTime_U;
        AOORVOORWORKs_B.MSR = AOORVOORWORKs_DW.MSR_U;
      }
      break;

     case AOORVOORWORKs_IN_Standby:
      AOORVOORWORKs_B.Handshake_Request = 0U;
      if ((status == 0) && (AOORVOORWORKs_B.RxData[0] == 22)) {
        switch (AOORVOORWORKs_B.RxData[1]) {
         case 85:
          AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Read_Data;
          AOORVOORWORKs_DW.temporalCounter_i1_m = 0U;
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[2], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.Mode_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[6], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.upper_rate_limit_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[10], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.lower_rate_limit_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[38], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.a_r_p_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[42], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.p_v_a_r_p_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[46], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.h_r_l_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[74], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.v_r_p_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[78], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.activity_threshold_U = AOORVOORWORKs_DW.tmp_u32_data
            [0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[82], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.ReactionTime_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[86], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.ResponseFactor_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[90], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.RecoveryTime_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_u32_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[94], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AOORVOORWORKs_DW.tmp_u32_sizes = 1;
          AOORVOORWORKs_DW.MSR_U = AOORVOORWORKs_DW.tmp_u32_data[0];
          AOORVOORWORKs_DW.hysterisis_flag_U = AOORVOORWORKs_B.RxData[98];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_single_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[14], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          AOORVOORWORKs_DW.tmp_single_sizes = 1;
          AOORVOORWORKs_DW.atrial_amplitude_U =
            AOORVOORWORKs_DW.tmp_single_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_single_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[26], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          AOORVOORWORKs_DW.tmp_single_sizes = 1;
          AOORVOORWORKs_DW.ventricular_amplitude_U =
            AOORVOORWORKs_DW.tmp_single_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_single_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[66], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          AOORVOORWORKs_DW.tmp_single_sizes = 1;
          memcpy((void *)&AOORVOORWORKs_DW.tmp_single_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[70], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          AOORVOORWORKs_DW.tmp_single_sizes = 1;
          memcpy((void *)&AOORVOORWORKs_DW.tmp_double_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[18], (uint32_T)((size_t)1 * sizeof
                  (real_T)));
          AOORVOORWORKs_DW.tmp_double_sizes = 1;
          AOORVOORWORKs_DW.atrial_pulse_width_U =
            AOORVOORWORKs_DW.tmp_double_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_double_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[30], (uint32_T)((size_t)1 * sizeof
                  (real_T)));
          AOORVOORWORKs_DW.tmp_double_sizes = 1;
          AOORVOORWORKs_DW.ventricular_pulse_width_U =
            AOORVOORWORKs_DW.tmp_double_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_double_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[50], (uint32_T)((size_t)1 * sizeof
                  (real_T)));
          AOORVOORWORKs_DW.tmp_double_sizes = 1;
          AOORVOORWORKs_DW.r_s_up_U = AOORVOORWORKs_DW.tmp_double_data[0];
          memcpy((void *)&AOORVOORWORKs_DW.tmp_double_data[0], (void *)
                 &AOORVOORWORKs_B.RxData[58], (uint32_T)((size_t)1 * sizeof
                  (real_T)));
          AOORVOORWORKs_DW.tmp_double_sizes = 1;
          AOORVOORWORKs_DW.r_s_down_U = AOORVOORWORKs_DW.tmp_double_data[0];
          break;

         case 69:
          AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORV_IN_HandshakeRequestEnable;
          AOORVOORWORKs_DW.temporalCounter_i1_m = 0U;
          AOORVOORWORKs_B.Handshake_Request = 1U;
          break;
        }
      }
      break;

     case AOORVOORWORKs_IN_Write_Data:
      AOORVOORWORKs_B.ventricular_sensitivity = 2.5F;
      AOORVOORWORKs_B.atrial_sensitivity = 2.75F;
      AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Standby;
      AOORVOORWORKs_B.Handshake_Request = 0U;
      break;

     default:
      /* case IN_setToZeroForTesting: */
      AOORVOORWORKs_DW.is_c9_AOORVOORWORKs = AOORVOORWORKs_IN_Standby;
      AOORVOORWORKs_B.Handshake_Request = 0U;
      break;
    }
  }

  /* End of Chart: '<S1>/Chart1' */

  /* Math: '<S15>/Math Function1' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion1'
   *  Fcn: '<S15>/Fcn2'
   *
   * About '<S15>/Math Function1':
   *  Operator: reciprocal
   */
  AOORVOORWORKs_B.MathFunction1 = 1.0F / ((real32_T)
    AOORVOORWORKs_B.lower_rate_limit / 60000.0F);

  /* MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  if (AOORVOORWORKs_DW.obj_i.SampleTime !=
      AOORVOORWORKs_P.ATR_CMP_DETECT_SampleTime) {
    AOORVOORWORKs_DW.obj_i.SampleTime =
      AOORVOORWORKs_P.ATR_CMP_DETECT_SampleTime;
  }

  AOORVOORWORKs_B.ATR_CMP_DETECT = MW_digitalIO_read
    (AOORVOORWORKs_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  if (AOORVOORWORKs_DW.obj_ci.SampleTime !=
      AOORVOORWORKs_P.VENT_CMP_DETECT_SampleTime) {
    AOORVOORWORKs_DW.obj_ci.SampleTime =
      AOORVOORWORKs_P.VENT_CMP_DETECT_SampleTime;
  }

  AOORVOORWORKs_B.VENT_CMP_DETECT = MW_digitalIO_read
    (AOORVOORWORKs_DW.obj_ci.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/VENT_CMP_DETECT' */

  /* Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */
  if (AOORVOORWORKs_DW.temporalCounter_i1_a < MAX_uint32_T) {
    AOORVOORWORKs_DW.temporalCounter_i1_a++;
  }

  if (AOORVOORWORKs_DW.is_active_c5_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c5_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c5_AOORVOORWORKs = AOORVOORWORKs_IN_default_m;
  } else {
    switch (AOORVOORWORKs_DW.is_c5_AOORVOORWORKs) {
     case AOORVOOR_IN_AtrialRateDetection:
      if (AOORVOORWORKs_B.Mode != 112U) {
        AOORVOORWORKs_DW.is_AtrialRateDetection =
          AOORVOORWORK_IN_NO_ACTIVE_CHILD;
        AOORVOORWORKs_DW.is_c5_AOORVOORWORKs = AOORVOORWORKs_IN_default_m;
      } else {
        switch (AOORVOORWORKs_DW.is_AtrialRateDetection) {
         case AOORVOORWORKs_IN_awaitNewPulse:
          if (!AOORVOORWORKs_B.ATR_CMP_DETECT) {
            AOORVOORWORKs_DW.is_AtrialRateDetection =
              AOORVOORWORKs_IN_awaitNewPulse;
            qY = AOORVOORWORKs_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
            if (qY < AOORVOORWORKs_B.time_between_pulses) {
              qY = MAX_uint32_T;
            }

            AOORVOORWORKs_B.time_between_pulses = qY;
          } else {
            AOORVOORWORKs_DW.is_AtrialRateDetection =
              AOORVOORWOR_IN_newPulseDetected;
            AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
            AOORVOORWORKs_B.pulse_finished = true;
            AOORVOORWORKs_B.HR_Ready = true;
          }
          break;

         case AOORVOORWORKs_IN_default_mk:
          AOORVOORWORKs_B.pulse_finished = false;
          if (AOORVOORWORKs_B.ATR_CMP_DETECT) {
            AOORVOORWORKs_DW.is_AtrialRateDetection =
              AOORVOORWORKs_IN_setARPasDeltaT;
            AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
            AOORVOORWORKs_B.time_between_pulses = AOORVOORWORKs_B.a_r_p;
          }
          break;

         case AOORVOORWOR_IN_newPulseDetected:
          AOORVOORWORKs_B.pulse_finished = true;
          if (AOORVOORWORKs_DW.temporalCounter_i1_a >= 1U) {
            AOORVOORWORKs_DW.is_AtrialRateDetection =
              AOORVOORWORKs_IN_resetDeltaT;
            AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
            AOORVOORWORKs_B.pulse_finished = false;
            AOORVOORWORKs_B.time_between_pulses = AOORVOORWORKs_B.a_r_p;
          }
          break;

         case AOORVOORWORKs_IN_resetDeltaT:
          AOORVOORWORKs_B.pulse_finished = false;
          qY = AOORVOORWORKs_B.a_r_p - /*MW:OvSatOk*/ 1U;
          if (qY > AOORVOORWORKs_B.a_r_p) {
            qY = 0U;
          }

          if (AOORVOORWORKs_DW.temporalCounter_i1_a >= qY) {
            if (!AOORVOORWORKs_B.ATR_CMP_DETECT) {
              AOORVOORWORKs_DW.is_AtrialRateDetection =
                AOORVOORWORKs_IN_awaitNewPulse;
              qY = AOORVOORWORKs_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
              if (qY < AOORVOORWORKs_B.time_between_pulses) {
                qY = MAX_uint32_T;
              }

              AOORVOORWORKs_B.time_between_pulses = qY;
            } else {
              AOORVOORWORKs_DW.is_AtrialRateDetection =
                AOORVOORWOR_IN_newPulseDetected;
              AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
              AOORVOORWORKs_B.pulse_finished = true;
              AOORVOORWORKs_B.HR_Ready = true;
            }
          }
          break;

         default:
          /* case IN_setARPasDeltaT: */
          if (AOORVOORWORKs_DW.temporalCounter_i1_a >= AOORVOORWORKs_B.a_r_p) {
            if (!AOORVOORWORKs_B.ATR_CMP_DETECT) {
              AOORVOORWORKs_DW.is_AtrialRateDetection =
                AOORVOORWORKs_IN_awaitNewPulse;
              qY = AOORVOORWORKs_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
              if (qY < AOORVOORWORKs_B.time_between_pulses) {
                qY = MAX_uint32_T;
              }

              AOORVOORWORKs_B.time_between_pulses = qY;
            } else {
              AOORVOORWORKs_DW.is_AtrialRateDetection =
                AOORVOORWOR_IN_newPulseDetected;
              AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
              AOORVOORWORKs_B.pulse_finished = true;
              AOORVOORWORKs_B.HR_Ready = true;
            }
          }
          break;
        }
      }
      break;

     case AOORVOORWORKs_IN_UnsensedModes:
      if ((AOORVOORWORKs_B.Mode != 100U) && (AOORVOORWORKs_B.Mode != 200U)) {
        AOORVOORWORKs_B.HR_Ready = false;
        AOORVOORWORKs_DW.is_c5_AOORVOORWORKs = AOORVOORWORKs_IN_default_m;
      }
      break;

     case AOOR_IN_VenticularRateDetection:
      if (AOORVOORWORKs_B.Mode != 222U) {
        AOORVOORWORKs_DW.is_VenticularRateDetection =
          AOORVOORWORK_IN_NO_ACTIVE_CHILD;
        AOORVOORWORKs_DW.is_c5_AOORVOORWORKs = AOORVOORWORKs_IN_default_m;
      } else {
        switch (AOORVOORWORKs_DW.is_VenticularRateDetection) {
         case AOORVOORWORKs_IN_awaitNewPulse:
          if (!AOORVOORWORKs_B.VENT_CMP_DETECT) {
            AOORVOORWORKs_DW.is_VenticularRateDetection =
              AOORVOORWORKs_IN_awaitNewPulse;
            qY = AOORVOORWORKs_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
            if (qY < AOORVOORWORKs_B.time_between_pulses) {
              qY = MAX_uint32_T;
            }

            AOORVOORWORKs_B.time_between_pulses = qY;
          } else {
            AOORVOORWORKs_DW.is_VenticularRateDetection =
              AOORVOORWOR_IN_newPulseDetected;
            AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
            AOORVOORWORKs_B.pulse_finished = true;
            AOORVOORWORKs_B.HR_Ready = true;
          }
          break;

         case AOORVOORWORKs_IN_default_mk:
          AOORVOORWORKs_B.pulse_finished = false;
          if (AOORVOORWORKs_B.VENT_CMP_DETECT) {
            AOORVOORWORKs_DW.is_VenticularRateDetection =
              AOORVOORWORKs_IN_setVRPasDeltaT;
            AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
            AOORVOORWORKs_B.time_between_pulses = AOORVOORWORKs_B.v_r_p;
          }
          break;

         case AOORVOORWOR_IN_newPulseDetected:
          AOORVOORWORKs_B.pulse_finished = true;
          if (AOORVOORWORKs_DW.temporalCounter_i1_a >= 1U) {
            AOORVOORWORKs_DW.is_VenticularRateDetection =
              AOORVOORWORKs_IN_resetDeltaT;
            AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
            AOORVOORWORKs_B.pulse_finished = false;
            AOORVOORWORKs_B.time_between_pulses = AOORVOORWORKs_B.v_r_p;
          }
          break;

         case AOORVOORWORKs_IN_resetDeltaT:
          AOORVOORWORKs_B.pulse_finished = false;
          qY = AOORVOORWORKs_B.v_r_p - /*MW:OvSatOk*/ 1U;
          if (qY > AOORVOORWORKs_B.v_r_p) {
            qY = 0U;
          }

          if (AOORVOORWORKs_DW.temporalCounter_i1_a >= qY) {
            if (!AOORVOORWORKs_B.VENT_CMP_DETECT) {
              AOORVOORWORKs_DW.is_VenticularRateDetection =
                AOORVOORWORKs_IN_awaitNewPulse;
              qY = AOORVOORWORKs_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
              if (qY < AOORVOORWORKs_B.time_between_pulses) {
                qY = MAX_uint32_T;
              }

              AOORVOORWORKs_B.time_between_pulses = qY;
            } else {
              AOORVOORWORKs_DW.is_VenticularRateDetection =
                AOORVOORWOR_IN_newPulseDetected;
              AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
              AOORVOORWORKs_B.pulse_finished = true;
              AOORVOORWORKs_B.HR_Ready = true;
            }
          }
          break;

         default:
          /* case IN_setVRPasDeltaT: */
          if (AOORVOORWORKs_DW.temporalCounter_i1_a >= AOORVOORWORKs_B.v_r_p) {
            if (!AOORVOORWORKs_B.VENT_CMP_DETECT) {
              AOORVOORWORKs_DW.is_VenticularRateDetection =
                AOORVOORWORKs_IN_awaitNewPulse;
              qY = AOORVOORWORKs_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
              if (qY < AOORVOORWORKs_B.time_between_pulses) {
                qY = MAX_uint32_T;
              }

              AOORVOORWORKs_B.time_between_pulses = qY;
            } else {
              AOORVOORWORKs_DW.is_VenticularRateDetection =
                AOORVOORWOR_IN_newPulseDetected;
              AOORVOORWORKs_DW.temporalCounter_i1_a = 0U;
              AOORVOORWORKs_B.pulse_finished = true;
              AOORVOORWORKs_B.HR_Ready = true;
            }
          }
          break;
        }
      }
      break;

     default:
      /* case IN_default: */
      if (AOORVOORWORKs_B.Mode == 112U) {
        AOORVOORWORKs_DW.is_c5_AOORVOORWORKs = AOORVOOR_IN_AtrialRateDetection;
        AOORVOORWORKs_DW.is_AtrialRateDetection = AOORVOORWORKs_IN_default_mk;
        AOORVOORWORKs_B.pulse_finished = false;
        AOORVOORWORKs_B.time_between_pulses = 0U;
      } else if ((AOORVOORWORKs_B.Mode == 100U) || (AOORVOORWORKs_B.Mode == 200U))
      {
        AOORVOORWORKs_DW.is_c5_AOORVOORWORKs = AOORVOORWORKs_IN_UnsensedModes;
        AOORVOORWORKs_B.HR_Ready = true;
      } else {
        if (AOORVOORWORKs_B.Mode == 222U) {
          AOORVOORWORKs_DW.is_c5_AOORVOORWORKs = AOOR_IN_VenticularRateDetection;
          AOORVOORWORKs_DW.is_VenticularRateDetection =
            AOORVOORWORKs_IN_default_mk;
          AOORVOORWORKs_B.pulse_finished = false;
          AOORVOORWORKs_B.time_between_pulses = 0U;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */

  /* Switch: '<S13>/Switch9' incorporates:
   *  Delay: '<S13>/Delay7'
   */
  if (AOORVOORWORKs_B.pulse_finished) {
    AOORVOORWORKs_DW.Delay7_DSTATE = AOORVOORWORKs_B.time_between_pulses;
  }

  /* End of Switch: '<S13>/Switch9' */

  /* Gain: '<S13>/Gain4' incorporates:
   *  DataTypeConversion: '<S13>/Cast To Double'
   *  Delay: '<S13>/Delay7'
   *  Fcn: '<S13>/Fcn3'
   */
  AOORVOORWORKs_B.Gain4 = 1.0 / (real_T)AOORVOORWORKs_DW.Delay7_DSTATE *
    AOORVOORWORKs_P.Gain4_Gain;

  /* Memory: '<S1>/Memory' */
  AOORVOORWORKs_B.Memory = AOORVOORWORKs_DW.Memory_PreviousInput;

  /* Chart: '<S2>/Chart' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Single'
   *  DataTypeConversion: '<S2>/Cast To Single1'
   *  DataTypeConversion: '<S2>/Cast To Single2'
   *  DataTypeConversion: '<S2>/Cast To Single3'
   *  DataTypeConversion: '<S2>/Cast To Single4'
   *  DataTypeConversion: '<S2>/Cast To Single7'
   *  DataTypeConversion: '<S2>/Cast To Single8'
   */
  if (AOORVOORWORKs_DW.temporalCounter_i1_l < 1023U) {
    AOORVOORWORKs_DW.temporalCounter_i1_l++;
  }

  if (AOORVOORWORKs_DW.is_active_c10_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c10_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_start;
    AOORVOORWORKs_B.DesiredRate = (real32_T)AOORVOORWORKs_B.lower_rate_limit;
    AOORVOORWORKs_B.CR = (real32_T)AOORVOORWORKs_B.lower_rate_limit;
  } else {
    switch (AOORVOORWORKs_DW.is_c10_AOORVOORWORKs) {
     case AOORVOORWORKs_IN_STEPUP:
      if (AOORVOORWORKs_DW.temporalCounter_i1_l >= 1000U) {
        AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_STEPUP;
        AOORVOORWORKs_DW.temporalCounter_i1_l = 0U;
        AOORVOORWORKs_B.CR += AOORVOORWORKs_B.stepup;
      } else {
        if (AOORVOORWORKs_B.CR >= AOORVOORWORKs_B.DesiredRate) {
          AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_overThreshold;
          AOORVOORWORKs_B.flag = 1U;
          AOORVOORWORKs_B.CR = AOORVOORWORKs_B.DesiredRate;
        }
      }
      break;

     case AOORVOORWORKs_IN_default_mk:
      AOORVOORWORKs_B.flag = 0U;
      if ((real32_T)AOORVOORWORKs_B.Memory >= AOORVOORWORKs_B.activity_threshold)
      {
        AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_overThreshold;
        AOORVOORWORKs_B.flag = 1U;
        AOORVOORWORKs_B.CR = AOORVOORWORKs_B.DesiredRate;
      } else {
        AOORVOORWORKs_B.DesiredRate = (real32_T)AOORVOORWORKs_B.lower_rate_limit;
        AOORVOORWORKs_B.CR = (real32_T)AOORVOORWORKs_B.lower_rate_limit;
        stepup_tmp = (real32_T)AOORVOORWORKs_B.MSR - (real32_T)
          AOORVOORWORKs_B.lower_rate_limit;
        AOORVOORWORKs_B.stepup = stepup_tmp / (real32_T)
          AOORVOORWORKs_B.ReactionTime;
        AOORVOORWORKs_DW.stepdown = stepup_tmp / ((real32_T)
          AOORVOORWORKs_B.RecoveryTime * 60.0F);
      }
      break;

     case AOORVOORWORKs_IN_overThreshold:
      AOORVOORWORKs_B.flag = 1U;
      if ((real32_T)AOORVOORWORKs_B.Memory < AOORVOORWORKs_B.activity_threshold)
      {
        AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_stepdown;
        AOORVOORWORKs_DW.temporalCounter_i1_l = 0U;
        AOORVOORWORKs_B.CR -= AOORVOORWORKs_DW.stepdown;
        AOORVOORWORKs_B.flag = 0U;
      } else if (AOORVOORWORKs_B.CR < AOORVOORWORKs_B.DesiredRate) {
        AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_STEPUP;
        AOORVOORWORKs_DW.temporalCounter_i1_l = 0U;
        AOORVOORWORKs_B.CR += AOORVOORWORKs_B.stepup;
      } else {
        AOORVOORWORKs_B.DesiredRate = (1.0F - rt_powf_snf(2.718F, (4.0F *
          (real32_T)AOORVOORWORKs_B.Memory - (real32_T)
          AOORVOORWORKs_B.activity_threshold) * -(real32_T)
          AOORVOORWORKs_B.ResponseFactor)) * ((real32_T)AOORVOORWORKs_B.MSR -
          (real32_T)AOORVOORWORKs_B.lower_rate_limit) + (real32_T)
          AOORVOORWORKs_B.lower_rate_limit;
      }
      break;

     case AOORVOORWORKs_IN_start:
      AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_default_mk;
      AOORVOORWORKs_B.flag = 0U;
      break;

     default:
      /* case IN_stepdown: */
      AOORVOORWORKs_B.flag = 0U;
      if (AOORVOORWORKs_DW.temporalCounter_i1_l >= 1000U) {
        AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_stepdown;
        AOORVOORWORKs_DW.temporalCounter_i1_l = 0U;
        AOORVOORWORKs_B.CR -= AOORVOORWORKs_DW.stepdown;
        AOORVOORWORKs_B.flag = 0U;
      } else {
        if (AOORVOORWORKs_B.CR <= AOORVOORWORKs_B.lower_rate_limit) {
          AOORVOORWORKs_DW.is_c10_AOORVOORWORKs = AOORVOORWORKs_IN_default_mk;
          AOORVOORWORKs_B.flag = 0U;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* DataTypeConversion: '<S2>/Cast To Single9' */
  stepup_tmp = (real32_T)floor(AOORVOORWORKs_B.CR);
  if (rtIsNaNF(stepup_tmp) || rtIsInfF(stepup_tmp)) {
    stepup_tmp = 0.0F;
  } else {
    stepup_tmp = (real32_T)fmod(stepup_tmp, 4.294967296E+9);
  }

  rtb_CastToSingle9 = stepup_tmp < 0.0F ? (uint32_T)-(int32_T)(uint32_T)
    -stepup_tmp : (uint32_T)stepup_tmp;

  /* End of DataTypeConversion: '<S2>/Cast To Single9' */

  /* Chart: '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  if (AOORVOORWORKs_DW.is_active_c1_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c1_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c1_AOORVOORWORKs = AOORVOOR_IN_HysterisisSelection;
    AOORVOORWORKs_DW.time_minute = 60000U;
    AOORVOORWORKs_DW.smoothing_rate = (1.0 - AOORVOORWORKs_B.r_s_down) *
      AOORVOORWORKs_B.Gain4;
  } else {
    switch (AOORVOORWORKs_DW.is_c1_AOORVOORWORKs) {
     case AOORVOORWORKs_IN_AAI:
      if (AOORVOORWORKs_B.Mode != 112U) {
        AOORVOORWORKs_DW.is_c1_AOORVOORWORKs = AOORVOOR_IN_HysterisisSelection;
        AOORVOORWORKs_DW.time_minute = 60000U;
        AOORVOORWORKs_DW.smoothing_rate = (1.0 - AOORVOORWORKs_B.r_s_down) *
          AOORVOORWORKs_B.Gain4;
      }
      break;

     case AOORVOORWORKs_IN_AAIR:
      if (AOORVOORWORKs_B.Mode != 1121U) {
        AOORVOORWORKs_DW.is_c1_AOORVOORWORKs = AOORVOOR_IN_HysterisisSelection;
        AOORVOORWORKs_DW.time_minute = 60000U;
        AOORVOORWORKs_DW.smoothing_rate = (1.0 - AOORVOORWORKs_B.r_s_down) *
          AOORVOORWORKs_B.Gain4;
      }
      break;

     case AOORVOOR_IN_HysterisisSelection:
      switch (AOORVOORWORKs_B.Mode) {
       case 112U:
        AOORVOORWORKs_DW.is_c1_AOORVOORWORKs = AOORVOORWORKs_IN_AAI;
        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = rt_roundd_snf((real_T)
          AOORVOORWORKs_B.a_r_p + AOORVOORWORKs_B.atrial_pulse_width);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)qY
          * AOORVOORWORKs_DW.smoothing_rate);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ qY;
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)qY
          / AOORVOORWORKs_DW.smoothing_rate);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            AOORVOORWORKs_B.wait_time = (uint32_T)
              AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            AOORVOORWORKs_B.wait_time = 0U;
          }
        } else {
          AOORVOORWORKs_B.wait_time = MAX_uint32_T;
        }

        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ mul_u32_sat(qY,
          AOORVOORWORKs_B.lower_rate_limit);
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        if (AOORVOORWORKs_B.lower_rate_limit == 0U) {
          if (qY == 0U) {
            AOORVOORWORKs_B.wait_time_LRL = 0U;
          } else {
            AOORVOORWORKs_B.wait_time_LRL = MAX_uint32_T;
          }
        } else {
          AOORVOORWORKs_B.wait_time_LRL = AOORVOORWORKs_B.lower_rate_limit == 0U
            ? MAX_uint32_T : qY / AOORVOORWORKs_B.lower_rate_limit;
          rtb_CastToSingle9 = qY - AOORVOORWORKs_B.wait_time_LRL *
            AOORVOORWORKs_B.lower_rate_limit;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AOORVOORWORKs_B.lower_rate_limit >> 1U) +
               (AOORVOORWORKs_B.lower_rate_limit & 1U))) {
            AOORVOORWORKs_B.wait_time_LRL++;
          }
        }

        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ mul_u32_sat(qY,
          AOORVOORWORKs_B.h_r_l);
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        if (AOORVOORWORKs_B.h_r_l == 0U) {
          if (qY == 0U) {
            AOORVOORWORKs_B.wait_time_LRL_hys = 0U;
          } else {
            AOORVOORWORKs_B.wait_time_LRL_hys = MAX_uint32_T;
          }
        } else {
          AOORVOORWORKs_B.wait_time_LRL_hys = AOORVOORWORKs_B.h_r_l == 0U ?
            MAX_uint32_T : qY / AOORVOORWORKs_B.h_r_l;
          rtb_CastToSingle9 = qY - AOORVOORWORKs_B.wait_time_LRL_hys *
            AOORVOORWORKs_B.h_r_l;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AOORVOORWORKs_B.h_r_l >> 1U) + (AOORVOORWORKs_B.h_r_l & 1U))) {
            AOORVOORWORKs_B.wait_time_LRL_hys++;
          }
        }
        break;

       case 222U:
        AOORVOORWORKs_DW.is_c1_AOORVOORWORKs = AOORVOORWORKs_IN_VVI;
        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = rt_roundd_snf((real_T)
          AOORVOORWORKs_B.v_r_p + AOORVOORWORKs_B.ventricular_pulse_width);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)qY
          * AOORVOORWORKs_DW.smoothing_rate);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ qY;
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)qY
          / AOORVOORWORKs_DW.smoothing_rate);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            AOORVOORWORKs_B.wait_time = (uint32_T)
              AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            AOORVOORWORKs_B.wait_time = 0U;
          }
        } else {
          AOORVOORWORKs_B.wait_time = MAX_uint32_T;
        }

        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ mul_u32_sat(qY,
          AOORVOORWORKs_B.lower_rate_limit);
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        if (AOORVOORWORKs_B.lower_rate_limit == 0U) {
          if (qY == 0U) {
            AOORVOORWORKs_B.wait_time_LRL = 0U;
          } else {
            AOORVOORWORKs_B.wait_time_LRL = MAX_uint32_T;
          }
        } else {
          AOORVOORWORKs_B.wait_time_LRL = AOORVOORWORKs_B.lower_rate_limit == 0U
            ? MAX_uint32_T : qY / AOORVOORWORKs_B.lower_rate_limit;
          rtb_CastToSingle9 = qY - AOORVOORWORKs_B.wait_time_LRL *
            AOORVOORWORKs_B.lower_rate_limit;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AOORVOORWORKs_B.lower_rate_limit >> 1U) +
               (AOORVOORWORKs_B.lower_rate_limit & 1U))) {
            AOORVOORWORKs_B.wait_time_LRL++;
          }
        }
        break;

       case 1121U:
        AOORVOORWORKs_DW.is_c1_AOORVOORWORKs = AOORVOORWORKs_IN_AAIR;
        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = rt_roundd_snf((real_T)
          AOORVOORWORKs_B.a_r_p + AOORVOORWORKs_B.atrial_pulse_width);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)qY
          * AOORVOORWORKs_DW.smoothing_rate);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ qY;
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)qY
          / AOORVOORWORKs_DW.smoothing_rate);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            AOORVOORWORKs_B.wait_time = (uint32_T)
              AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            AOORVOORWORKs_B.wait_time = 0U;
          }
        } else {
          AOORVOORWORKs_B.wait_time = MAX_uint32_T;
        }

        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ mul_u32_sat(qY,
          rtb_CastToSingle9);
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        if (rtb_CastToSingle9 == 0U) {
          if (qY == 0U) {
            AOORVOORWORKs_B.wait_time_AAIR = 0U;
          } else {
            AOORVOORWORKs_B.wait_time_AAIR = MAX_uint32_T;
          }
        } else {
          AOORVOORWORKs_B.wait_time_AAIR = qY / rtb_CastToSingle9;
          qY -= AOORVOORWORKs_B.wait_time_AAIR * rtb_CastToSingle9;
          if ((qY > 0U) && (qY >= (rtb_CastToSingle9 >> 1U) + (rtb_CastToSingle9
                & 1U))) {
            AOORVOORWORKs_B.wait_time_AAIR++;
          }
        }

        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ mul_u32_sat(qY,
          AOORVOORWORKs_B.lower_rate_limit);
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        if (AOORVOORWORKs_B.lower_rate_limit == 0U) {
          if (qY == 0U) {
            AOORVOORWORKs_B.wait_time_LRL = 0U;
          } else {
            AOORVOORWORKs_B.wait_time_LRL = MAX_uint32_T;
          }
        } else {
          AOORVOORWORKs_B.wait_time_LRL = AOORVOORWORKs_B.lower_rate_limit == 0U
            ? MAX_uint32_T : qY / AOORVOORWORKs_B.lower_rate_limit;
          rtb_CastToSingle9 = qY - AOORVOORWORKs_B.wait_time_LRL *
            AOORVOORWORKs_B.lower_rate_limit;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AOORVOORWORKs_B.lower_rate_limit >> 1U) +
               (AOORVOORWORKs_B.lower_rate_limit & 1U))) {
            AOORVOORWORKs_B.wait_time_LRL++;
          }
        }

        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        qY = AOORVOORWORKs_DW.time_minute - /*MW:OvSatOk*/ mul_u32_sat(qY,
          AOORVOORWORKs_B.h_r_l);
        if (qY > AOORVOORWORKs_DW.time_minute) {
          qY = 0U;
        }

        if (AOORVOORWORKs_B.h_r_l == 0U) {
          if (qY == 0U) {
            AOORVOORWORKs_B.wait_time_LRL_hys = 0U;
          } else {
            AOORVOORWORKs_B.wait_time_LRL_hys = MAX_uint32_T;
          }
        } else {
          AOORVOORWORKs_B.wait_time_LRL_hys = AOORVOORWORKs_B.h_r_l == 0U ?
            MAX_uint32_T : qY / AOORVOORWORKs_B.h_r_l;
          rtb_CastToSingle9 = qY - AOORVOORWORKs_B.wait_time_LRL_hys *
            AOORVOORWORKs_B.h_r_l;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AOORVOORWORKs_B.h_r_l >> 1U) + (AOORVOORWORKs_B.h_r_l & 1U))) {
            AOORVOORWORKs_B.wait_time_LRL_hys++;
          }
        }
        break;
      }
      break;

     default:
      /* case IN_VVI: */
      if (AOORVOORWORKs_B.Mode != 222U) {
        AOORVOORWORKs_DW.is_c1_AOORVOORWORKs = AOORVOOR_IN_HysterisisSelection;
        AOORVOORWORKs_DW.time_minute = 60000U;
        AOORVOORWORKs_DW.smoothing_rate = (1.0 - AOORVOORWORKs_B.r_s_down) *
          AOORVOORWORKs_B.Gain4;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */

  /* Gain: '<S13>/Gain' incorporates:
   *  Delay: '<S13>/Delay'
   *  Delay: '<S13>/Delay1'
   *  Delay: '<S13>/Delay2'
   *  Delay: '<S13>/Delay3'
   *  Delay: '<S13>/Delay4'
   *  Sum: '<S13>/Sum'
   */
  qY = (((AOORVOORWORKs_DW.Delay_DSTATE + AOORVOORWORKs_DW.Delay1_DSTATE) +
         AOORVOORWORKs_DW.Delay2_DSTATE) + AOORVOORWORKs_DW.Delay3_DSTATE) +
    AOORVOORWORKs_DW.Delay4_DSTATE;
  uMultiWordMul(&AOORVOORWORKs_P.Gain_Gain_j, 1, &qY, 1, &tmp.chunks[0U], 2);

  /* Gain: '<S13>/Gain1' incorporates:
   *  DataTypeConversion: '<S13>/Cast To Double1'
   *  Fcn: '<S13>/Fcn'
   */
  AOORVOORWORKs_B.Gain1 = 1.0 / (uMultiWord2Double(&tmp.chunks[0U], 2, 0) *
    5.8207660913467407E-11) * AOORVOORWORKs_P.Gain1_Gain;

  /* Product: '<S22>/Product' incorporates:
   *  Constant: '<S19>/MaxVoltage'
   *  Constant: '<S22>/%'
   *  Product: '<S22>/Divide'
   */
  AOORVOORWORKs_B.Product = AOORVOORWORKs_B.atrial_amplitude /
    AOORVOORWORKs_P.MaxVoltage_Value * AOORVOORWORKs_P._Value;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S19>/MaxVoltage'
   *  Constant: '<S23>/%'
   *  Product: '<S23>/Divide'
   */
  AOORVOORWORKs_B.Product_k = AOORVOORWORKs_B.ventricular_amplitude /
    AOORVOORWORKs_P.MaxVoltage_Value * AOORVOORWORKs_P._Value_b;

  /* DataTypeConversion: '<S18>/Cast' incorporates:
   *  Constant: '<S18>/Constant'
   *  Math: '<S18>/Math Function1'
   *  Product: '<S18>/Product'
   *
   * About '<S18>/Math Function1':
   *  Operator: reciprocal
   */
  AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = floor(1.0F /
    AOORVOORWORKs_B.CR * AOORVOORWORKs_P.Constant_Value);
  if (rtIsNaN(AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0) || rtIsInf
      (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0)) {
    AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = 0.0;
  } else {
    AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = fmod
      (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0, 4.294967296E+9);
  }

  AOORVOORWORKs_B.Cast = AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 0.0 ?
    (uint32_T)-(int32_T)(uint32_T)-AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0
    : (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;

  /* End of DataTypeConversion: '<S18>/Cast' */

  /* DataTypeConversion: '<S2>/Cast To Single5' */
  stepup_tmp = (real32_T)floor(AOORVOORWORKs_B.DesiredRate);
  if (rtIsNaNF(stepup_tmp) || rtIsInfF(stepup_tmp)) {
    stepup_tmp = 0.0F;
  } else {
    stepup_tmp = (real32_T)fmod(stepup_tmp, 4.294967296E+9);
  }

  AOORVOORWORKs_B.CastToSingle5 = stepup_tmp < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-stepup_tmp : (uint32_T)stepup_tmp;

  /* End of DataTypeConversion: '<S2>/Cast To Single5' */

  /* Chart: '<S3>/1.1.3.2 PacemakerControl' incorporates:
   *  Constant: '<S21>/HIGH'
   *  Constant: '<S21>/LOW'
   */
  if (AOORVOORWORKs_DW.temporalCounter_i1 < MAX_uint32_T) {
    AOORVOORWORKs_DW.temporalCounter_i1++;
  }

  if (AOORVOORWORKs_DW.is_active_c3_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c3_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Initialize;
    AOORVOORWORKs_DW.AOO = 100U;
    AOORVOORWORKs_DW.VOO = 200;
    AOORVOORWORKs_DW.AAI = 112U;
    AOORVOORWORKs_DW.VVI = 222U;
    AOORVOORWORKs_DW.AOOR = 1000.0;
    AOORVOORWORKs_DW.AAIR = 1120.0;
    AOORVOORWORKs_DW.VOOR = 2000.0;
  } else {
    switch (AOORVOORWORKs_DW.is_c3_AOORVOORWORKs) {
     case AOORVOORWORKs_IN_AAI:
      AOORVOORWORKs_AAI();
      break;

     case AOORVOORWORKs_IN_AAIR:
      AOORVOORWORKs_AAIR();
      break;

     case AOORVOORWORKs_IN_AOO:
      AOORVOORWORKs_AOO();
      break;

     case AOORVOORWORKs_IN_AOOR:
      AOORVOORWORKs_AOOR();
      break;

     case AOORVOORWORKs_IN_Initialize:
      if (AOORVOORWORKs_B.HR_Ready) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
        AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
        AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
      }
      break;

     case AOORVOORWORKs_IN_Standby_a:
      AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
      AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
      if (AOORVOORWORKs_B.Mode == AOORVOORWORKs_DW.AOO) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_AOO;
        AOORVOORWORKs_DW.is_AOO = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      } else if (AOORVOORWORKs_B.Mode == AOORVOORWORKs_DW.AOOR) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_AOOR;
        AOORVOORWORKs_DW.is_AOOR = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
      } else if (AOORVOORWORKs_B.Mode == AOORVOORWORKs_DW.VOOR) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_VOOR;
        AOORVOORWORKs_DW.is_VOOR = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
      } else if (AOORVOORWORKs_B.Mode == AOORVOORWORKs_DW.AAIR) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_AAIR;
        AOORVOORWORKs_DW.is_AAIR = AOORVOORWORK_IN_initializations;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_CMP_REF_PWM = AOORVOORWORKs_B.atrial_sensitivity;
      } else if (AOORVOORWORKs_B.Mode == AOORVOORWORKs_DW.VVI) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_VVI_n;
        AOORVOORWORKs_DW.is_VVI = AOORVOORWORK_IN_initializations;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.VENT_CMP_REF_PWM =
          AOORVOORWORKs_B.ventricular_sensitivity;
        AOORVOORWORKs_B.count = 0.0;
      } else if ((real_T)AOORVOORWORKs_B.Mode == AOORVOORWORKs_DW.VOO) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_VOO;
        AOORVOORWORKs_DW.is_VOO = AOORVOORWORKs_IN_CHARGE;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
        AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
        AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
      } else if (AOORVOORWORKs_B.Mode == AOORVOORWORKs_DW.AAI) {
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_AAI;
        AOORVOORWORKs_DW.is_AAI = AOORVOORWORK_IN_initializations;
        AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
        AOORVOORWORKs_B.ATR_CMP_REF_PWM = AOORVOORWORKs_B.atrial_sensitivity;
        AOORVOORWORKs_B.count = 0.0;
      } else {
        if (!AOORVOORWORKs_B.HR_Ready) {
          AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Initialize;
          AOORVOORWORKs_DW.AOO = 100U;
          AOORVOORWORKs_DW.VOO = 200;
          AOORVOORWORKs_DW.AAI = 112U;
          AOORVOORWORKs_DW.VVI = 222U;
          AOORVOORWORKs_DW.AOOR = 1000.0;
          AOORVOORWORKs_DW.AAIR = 1120.0;
          AOORVOORWORKs_DW.VOOR = 2000.0;
        }
      }
      break;

     case AOORVOORWORKs_IN_VOO:
      if ((real_T)AOORVOORWORKs_B.Mode != AOORVOORWORKs_DW.VOO) {
        AOORVOORWORKs_DW.is_VOO = AOORVOORWORK_IN_NO_ACTIVE_CHILD;
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
        AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
        AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
      } else if (AOORVOORWORKs_DW.is_VOO == AOORVOORWORKs_IN_CHARGE) {
        if (AOORVOORWORKs_DW.temporalCounter_i1 >= AOORVOORWORKs_B.MathFunction1
            - (real32_T)AOORVOORWORKs_B.ventricular_pulse_width) {
          AOORVOORWORKs_DW.is_VOO = AOORVOORWORKs_IN_DISCHARGE;
          AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
          AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
        }
      } else {
        /* case IN_DISCHARGE: */
        if (AOORVOORWORKs_DW.temporalCounter_i1 >= (uint32_T)ceil
            (AOORVOORWORKs_B.ventricular_pulse_width)) {
          AOORVOORWORKs_DW.is_VOO = AOORVOORWORKs_IN_CHARGE;
          AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
          AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
          AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        }
      }
      break;

     case AOORVOORWORKs_IN_VOOR:
      if (AOORVOORWORKs_B.Mode != AOORVOORWORKs_DW.VOOR) {
        AOORVOORWORKs_DW.is_VOOR = AOORVOORWORK_IN_NO_ACTIVE_CHILD;
        AOORVOORWORKs_DW.is_c3_AOORVOORWORKs = AOORVOORWORKs_IN_Standby_a;
        AOORVOORWORKs_B.atrium_output_voltage = 0.0F;
        AOORVOORWORKs_B.ventricle_output_voltage = 0.0F;
      } else if (AOORVOORWORKs_DW.is_VOOR == AOORVOORWORKs_IN_CHARGE) {
        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = rt_roundd_snf((real_T)
          AOORVOORWORKs_B.Cast - AOORVOORWORKs_B.ventricular_pulse_width);
        if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 < 4.294967296E+9) {
          if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 >= 0.0) {
            qY = (uint32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
          } else {
            qY = 0U;
          }
        } else {
          qY = MAX_uint32_T;
        }

        if (AOORVOORWORKs_DW.temporalCounter_i1 >= qY) {
          AOORVOORWORKs_DW.is_VOOR = AOORVOORWORKs_IN_DISCHARGE;
          AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
          AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
        }
      } else {
        /* case IN_DISCHARGE: */
        if (AOORVOORWORKs_DW.temporalCounter_i1 >= (uint32_T)ceil
            (AOORVOORWORKs_B.ventricular_pulse_width)) {
          AOORVOORWORKs_DW.is_VOOR = AOORVOORWORKs_IN_CHARGE;
          AOORVOORWORKs_DW.temporalCounter_i1 = 0U;
          AOORVOORWORKs_B.ATR_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_PACE_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.PACING_REF_PWM = AOORVOORWORKs_B.Product_k;
          AOORVOORWORKs_B.PACE_CHARGE_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.PACE_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
          AOORVOORWORKs_B.Z_ATR_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.Z_VENT_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.ATR_GND_CTRL = AOORVOORWORKs_P.LOW_Value;
          AOORVOORWORKs_B.VENT_GND_CTRL = AOORVOORWORKs_P.HIGH_Value;
        }
      }
      break;

     default:
      /* case IN_VVI: */
      AOORVOORWORKs_VVI();
      break;
    }
  }

  /* End of Chart: '<S3>/1.1.3.2 PacemakerControl' */

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_p5.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_pd.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write2' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_is.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write3' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_n.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(AOORVOORWORKs_DW.obj_b.MW_PWM_HANDLE,
                      AOORVOORWORKs_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_np.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_e.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_c4.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S4>/Digital Write8' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_hw.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S4>/PWM Output1' incorporates:
   *  Fcn: '<S24>/Fcn'
   *  Gain: '<S24>/Gain'
   */
  MW_PWM_SetDutyCycle(AOORVOORWORKs_DW.obj_mo.MW_PWM_HANDLE, (real_T)
                      (AOORVOORWORKs_P.Gain_Gain *
                       (AOORVOORWORKs_B.ATR_CMP_REF_PWM / 3.3F)));

  /* MATLABSystem: '<S4>/PWM Output2' incorporates:
   *  Fcn: '<S24>/Fcn1'
   *  Gain: '<S24>/Gain1'
   */
  MW_PWM_SetDutyCycle(AOORVOORWORKs_DW.obj_a.MW_PWM_HANDLE, (real_T)
                      (AOORVOORWORKs_P.Gain1_Gain_p *
                       (AOORVOORWORKs_B.VENT_CMP_REF_PWM / 3.3F)));

  /* MATLABSystem: '<S1>/Analog Input' */
  if (AOORVOORWORKs_DW.obj_f.SampleTime !=
      AOORVOORWORKs_P.AnalogInput_SampleTime) {
    AOORVOORWORKs_DW.obj_f.SampleTime = AOORVOORWORKs_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(AOORVOORWORKs_DW.obj_f.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AOORVOORWORKs_DW.obj_f.MW_ANALOGIN_HANDLE,
    &AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S1>/Analog Input' */

  /* MATLABSystem: '<S1>/Analog Input1' */
  if (AOORVOORWORKs_DW.obj_d.SampleTime !=
      AOORVOORWORKs_P.AnalogInput1_SampleTime) {
    AOORVOORWORKs_DW.obj_d.SampleTime = AOORVOORWORKs_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(AOORVOORWORKs_DW.obj_d.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AOORVOORWORKs_DW.obj_d.MW_ANALOGIN_HANDLE,
    &AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S1>/Analog Input1' */

  /* MATLABSystem: '<S1>/Analog Input4' */
  if (AOORVOORWORKs_DW.obj_p.SampleTime !=
      AOORVOORWORKs_P.AnalogInput4_SampleTime) {
    AOORVOORWORKs_DW.obj_p.SampleTime = AOORVOORWORKs_P.AnalogInput4_SampleTime;
  }

  MW_AnalogIn_Start(AOORVOORWORKs_DW.obj_p.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AOORVOORWORKs_DW.obj_p.MW_ANALOGIN_HANDLE,
    &AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S1>/Analog Input4' */

  /* MATLABSystem: '<S1>/Analog Input5' */
  if (AOORVOORWORKs_DW.obj_h.SampleTime !=
      AOORVOORWORKs_P.AnalogInput5_SampleTime) {
    AOORVOORWORKs_DW.obj_h.SampleTime = AOORVOORWORKs_P.AnalogInput5_SampleTime;
  }

  MW_AnalogIn_Start(AOORVOORWORKs_DW.obj_h.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AOORVOORWORKs_DW.obj_h.MW_ANALOGIN_HANDLE,
    &AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0, 7);

  /* End of MATLABSystem: '<S1>/Analog Input5' */

  /* DataTypeConversion: '<S2>/Cast To Single6' */
  stepup_tmp = (real32_T)floor(AOORVOORWORKs_B.CR);
  if (rtIsNaNF(stepup_tmp) || rtIsInfF(stepup_tmp)) {
    stepup_tmp = 0.0F;
  } else {
    stepup_tmp = (real32_T)fmod(stepup_tmp, 4.294967296E+9);
  }

  AOORVOORWORKs_B.CastToSingle6 = stepup_tmp < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-stepup_tmp : (uint32_T)stepup_tmp;

  /* End of DataTypeConversion: '<S2>/Cast To Single6' */

  /* Outputs for Triggered SubSystem: '<S1>/Subsystem1' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  if ((AOORVOORWORKs_B.Handshake_Request > 0) &&
      (AOORVOORWORKs_PrevZCX.Subsystem1_Trig_ZCE != POS_ZCSIG)) {
    /* S-Function (any2byte): '<S9>/Byte Pack6' incorporates:
     *  Constant: '<S9>/Constant23'
     */

    /* Pack: <S9>/Byte Pack6 */
    (void) memcpy(&AOORVOORWORKs_B.BytePack6, &AOORVOORWORKs_P.Constant23_Value,
                  1);

    /* S-Function (any2byte): '<S9>/Byte Pack7' incorporates:
     *  Constant: '<S9>/Constant22'
     */

    /* Pack: <S9>/Byte Pack7 */
    (void) memcpy(&AOORVOORWORKs_B.BytePack7, &AOORVOORWORKs_P.Constant22_Value,
                  1);

    /* S-Function (any2byte): '<S9>/Byte Pack8' */

    /* Pack: <S9>/Byte Pack8 */
    (void) memcpy(&AOORVOORWORKs_B.BytePack8[0], &AOORVOORWORKs_B.CastToSingle6,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack9' incorporates:
     *  Constant: '<S9>/ModelNum'
     */

    /* Pack: <S9>/Byte Pack9 */
    (void) memcpy(&AOORVOORWORKs_B.BytePack9[0], &AOORVOORWORKs_P.ModelNum_Value,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack10' incorporates:
     *  Constant: '<S9>/HandshakePad'
     */

    /* Pack: <S9>/Byte Pack10 */
    (void) memcpy(&AOORVOORWORKs_B.BytePack10[0],
                  &AOORVOORWORKs_P.HandshakePad_Value[0],
                  8);

    /* SignalConversion generated from: '<S9>/Serial Transmit' */
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[0] = AOORVOORWORKs_B.BytePack6;
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[1] = AOORVOORWORKs_B.BytePack7;
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[2] = AOORVOORWORKs_B.BytePack8[0];
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[6] = AOORVOORWORKs_B.BytePack9[0];
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[3] = AOORVOORWORKs_B.BytePack8[1];
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[7] = AOORVOORWORKs_B.BytePack9[1];
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[4] = AOORVOORWORKs_B.BytePack8[2];
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[8] = AOORVOORWORKs_B.BytePack9[2];
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[5] = AOORVOORWORKs_B.BytePack8[3];
    AOORVOORWORKs_B.TmpSignalConversionAtSerial[9] = AOORVOORWORKs_B.BytePack9[3];
    for (i = 0; i < 8; i++) {
      AOORVOORWORKs_B.TmpSignalConversionAtSerial[i + 10] =
        AOORVOORWORKs_B.BytePack10[i];
    }

    /* End of SignalConversion generated from: '<S9>/Serial Transmit' */

    /* MATLABSystem: '<S9>/Serial Transmit' */
    status = 1U;
    while (status != 0) {
      memcpy((void *)&AOORVOORWORKs_B.TxDataLocChar[0], (void *)
             &AOORVOORWORKs_B.TmpSignalConversionAtSerial[0], (uint32_T)((size_t)
              18 * sizeof(uint8_T)));
      status = MW_SCI_Transmit(AOORVOORWORKs_DW.obj_ce.MW_SCIHANDLE,
        AOORVOORWORKs_B.TxDataLocChar, 18U);
    }

    /* End of MATLABSystem: '<S9>/Serial Transmit' */
  }

  AOORVOORWORKs_PrevZCX.Subsystem1_Trig_ZCE = (ZCSigState)
    (AOORVOORWORKs_B.Handshake_Request > 0);

  /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

  /* Chart: '<S1>/HeartChamberPulseDetection' */
  if (AOORVOORWORKs_DW.is_active_c6_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c6_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c6_AOORVOORWORKs = AOORVOORWORKs_IN_default;
  } else if (AOORVOORWORKs_DW.is_c6_AOORVOORWORKs == AOORVOORWORKs_IN_default) {
    if (AOORVOORWORKs_B.VENT_CMP_DETECT) {
      AOORVOORWORKs_DW.is_c6_AOORVOORWORKs = AOORVOORWORKs_IN_led_on;
    }
  } else {
    /* case IN_led_on: */
    if (!AOORVOORWORKs_B.VENT_CMP_DETECT) {
      AOORVOORWORKs_DW.is_c6_AOORVOORWORKs = AOORVOORWORKs_IN_default;
    }
  }

  /* End of Chart: '<S1>/HeartChamberPulseDetection' */

  /* Chart: '<S1>/HeartChamberPulseDetection3' */
  if (AOORVOORWORKs_DW.temporalCounter_i1_k < 63U) {
    AOORVOORWORKs_DW.temporalCounter_i1_k++;
  }

  if (AOORVOORWORKs_DW.is_active_c7_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c7_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c7_AOORVOORWORKs = AOORVOORWORKs_IN_default;
    AOORVOORWORKs_DW.temporalCounter_i1_k = 0U;
    rtb_LED_STATE_f = false;
  } else if (AOORVOORWORKs_DW.is_c7_AOORVOORWORKs == AOORVOORWORKs_IN_default) {
    rtb_LED_STATE_f = false;
    if (AOORVOORWORKs_DW.temporalCounter_i1_k >= 50U) {
      AOORVOORWORKs_DW.is_c7_AOORVOORWORKs = AOORVOORWORKs_IN_led_on;
      AOORVOORWORKs_DW.temporalCounter_i1_k = 0U;
      rtb_LED_STATE_f = true;
    }
  } else {
    /* case IN_led_on: */
    rtb_LED_STATE_f = true;
    if (AOORVOORWORKs_DW.temporalCounter_i1_k >= 50U) {
      AOORVOORWORKs_DW.is_c7_AOORVOORWORKs = AOORVOORWORKs_IN_default;
      AOORVOORWORKs_DW.temporalCounter_i1_k = 0U;
      rtb_LED_STATE_f = false;
    }
  }

  /* End of Chart: '<S1>/HeartChamberPulseDetection3' */

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  if (rtb_LED_STATE_f && (AOORVOORWORKs_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
                          POS_ZCSIG)) {
    /* MATLABSystem: '<S10>/FXOS8700 6-Axes Sensor' */
    if (AOORVOORWORKs_DW.obj_c.SampleTime !=
        AOORVOORWORKs_P.FXOS87006AxesSensor_SampleTime) {
      AOORVOORWORKs_DW.obj_c.SampleTime =
        AOORVOORWORKs_P.FXOS87006AxesSensor_SampleTime;
    }

    status = 1U;
    status = MW_I2C_MasterWrite(AOORVOORWORKs_DW.obj_c.i2cobj.MW_I2C_HANDLE, 29U,
      &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(AOORVOORWORKs_DW.obj_c.i2cobj.MW_I2C_HANDLE, 29U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
              sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_output[0], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      b_x[0] = y[1];
      b_x[1] = y[0];
      memcpy((void *)&b_output[0], (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_output[1], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      b_x[0] = y[1];
      b_x[1] = y[0];
      memcpy((void *)&b_output[1], (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_output[2], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      b_x[0] = y[1];
      b_x[1] = y[0];
      memcpy((void *)&b_output[2], (void *)&b_x[0], (uint32_T)((size_t)1 *
              sizeof(int16_T)));
    } else {
      b_output[0] = 0;
      b_output[1] = 0;
      b_output[2] = 0;
    }

    AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)(b_output[0]
      >> 2) * 2.0 * 0.244 / 1000.0;
    AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_output[1]
      >> 2) * 2.0 * 0.244 / 1000.0;
    rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)(b_output[2] >> 2) * 2.0 *
      0.244 / 1000.0;

    /* End of MATLABSystem: '<S10>/FXOS8700 6-Axes Sensor' */

    /* Sqrt: '<S11>/Square Root' incorporates:
     *  Math: '<S11>/Square'
     *  Math: '<S11>/Square1'
     *  Math: '<S11>/Square2'
     *  Sum: '<S11>/Add'
     */
    AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 = sqrt
      ((AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 *
        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0 +
        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 *
        AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1) +
       rtb_FXOS87006AxesSensor_idx_2 * rtb_FXOS87006AxesSensor_idx_2);

    /* MATLABSystem: '<S10>/Moving Average' */
    if (AOORVOORWORKs_DW.obj.TunablePropsChanged) {
      AOORVOORWORKs_DW.obj.TunablePropsChanged = false;
    }

    if (AOORVOORWORKs_DW.obj.pStatistic->isInitialized != 1) {
      AOORVOORWORKs_DW.obj.pStatistic->isSetupComplete = false;
      AOORVOORWORKs_DW.obj.pStatistic->isInitialized = 1;
      AOORVOORWORKs_DW.obj.pStatistic->pCumSum = 0.0;
      AOORVOORWORKs_DW.obj.pStatistic->pCumRevIndex = 1.0;
      AOORVOORWORKs_DW.obj.pStatistic->isSetupComplete = true;
      AOORVOORWORKs_DW.obj.pStatistic->pCumSum = 0.0;
      memset(&AOORVOORWORKs_DW.obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof
             (real_T));
      AOORVOORWORKs_DW.obj.pStatistic->pCumRevIndex = 1.0;
    }

    AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 =
      AOORVOORWORKs_DW.obj.pStatistic->pCumRevIndex;
    rtb_FXOS87006AxesSensor_idx_2 = AOORVOORWORKs_DW.obj.pStatistic->pCumSum;
    for (i = 0; i < 19; i++) {
      AOORVOORWORKs_B.csumrev[i] = AOORVOORWORKs_DW.obj.pStatistic->pCumSumRev[i];
    }

    rtb_FXOS87006AxesSensor_idx_2 +=
      AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
    i = (int32_T)AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 - 1;
    AOORVOORWORKs_B.z = AOORVOORWORKs_B.csumrev[i] +
      rtb_FXOS87006AxesSensor_idx_2;
    AOORVOORWORKs_B.csumrev[i] = AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_0;
    if (AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 != 19.0) {
      AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1++;
    } else {
      AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1 = 1.0;
      rtb_FXOS87006AxesSensor_idx_2 = 0.0;
      for (i = 17; i >= 0; i--) {
        AOORVOORWORKs_B.csumrev[i] += AOORVOORWORKs_B.csumrev[i + 1];
      }
    }

    AOORVOORWORKs_DW.obj.pStatistic->pCumSum = rtb_FXOS87006AxesSensor_idx_2;
    memcpy(&AOORVOORWORKs_DW.obj.pStatistic->pCumSumRev[0],
           &AOORVOORWORKs_B.csumrev[0], 19U * sizeof(real_T));
    AOORVOORWORKs_DW.obj.pStatistic->pCumRevIndex =
      AOORVOORWORKs_B.rtb_FXOS87006AxesSensor_idx_1;
    AOORVOORWORKs_B.MovingAverage = AOORVOORWORKs_B.z / 20.0;

    /* End of MATLABSystem: '<S10>/Moving Average' */
  }

  AOORVOORWORKs_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_LED_STATE_f;

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */

  /* Chart: '<S1>/HeartChamberPulseDetection2' */
  if (AOORVOORWORKs_DW.temporalCounter_i1_o < 16383U) {
    AOORVOORWORKs_DW.temporalCounter_i1_o++;
  }

  if (AOORVOORWORKs_DW.is_active_c8_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c8_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c8_AOORVOORWORKs = AOORVOORWORKs_IN_default;
    AOORVOORWORKs_DW.temporalCounter_i1_o = 0U;
  } else if (AOORVOORWORKs_DW.is_c8_AOORVOORWORKs == AOORVOORWORKs_IN_default) {
    if (AOORVOORWORKs_DW.temporalCounter_i1_o >= 10000U) {
      AOORVOORWORKs_DW.is_c8_AOORVOORWORKs = AOORVOORWORKs_IN_led_on;
      AOORVOORWORKs_DW.temporalCounter_i1_o = 0U;
    }
  } else {
    /* case IN_led_on: */
    if (AOORVOORWORKs_DW.temporalCounter_i1_o >= 10000U) {
      AOORVOORWORKs_DW.is_c8_AOORVOORWORKs = AOORVOORWORKs_IN_default;
      AOORVOORWORKs_DW.temporalCounter_i1_o = 0U;
    }
  }

  /* End of Chart: '<S1>/HeartChamberPulseDetection2' */

  /* Chart: '<S2>/Activity Index Determination' */
  if (AOORVOORWORKs_DW.is_active_c4_AOORVOORWORKs == 0U) {
    AOORVOORWORKs_DW.is_active_c4_AOORVOORWORKs = 1U;
    AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_init;
    AOORVOORWORKs_DW.a = 0.0;
  } else {
    switch (AOORVOORWORKs_DW.is_c4_AOORVOORWORKs) {
     case AOORVOORWORKs_IN_High:
      AOORVOORWORKs_B.ActivityIndex = 6.0;
      break;

     case AOORVOORWORKs_IN_Low:
      AOORVOORWORKs_B.ActivityIndex = 2.0;
      break;

     case AOORVOORWORKs_IN_Med:
      AOORVOORWORKs_B.ActivityIndex = 4.0;
      break;

     case AOORVOORWORKs_IN_Med_High:
      AOORVOORWORKs_B.ActivityIndex = 5.0;
      break;

     case AOORVOORWORKs_IN_Med_Low:
      AOORVOORWORKs_B.ActivityIndex = 3.0;
      break;

     case AOORVOORWORKs_IN_V_High:
      AOORVOORWORKs_B.ActivityIndex = 7.0;
      break;

     case AOORVOORWORKs_IN_V_Low:
      AOORVOORWORKs_B.ActivityIndex = 1.0;
      break;

     default:
      /* case IN_init: */
      if ((AOORVOORWORKs_DW.a >= 0.0) && (AOORVOORWORKs_DW.a < 1.0)) {
        AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_V_Low;
        AOORVOORWORKs_B.ActivityIndex = 1.0;
      } else if ((AOORVOORWORKs_DW.a >= 1.0) && (AOORVOORWORKs_DW.a < 2.0)) {
        AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_Low;
        AOORVOORWORKs_B.ActivityIndex = 2.0;
      } else if ((AOORVOORWORKs_DW.a >= 2.0) && (AOORVOORWORKs_DW.a < 3.0)) {
        AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_Med_Low;
        AOORVOORWORKs_B.ActivityIndex = 3.0;
      } else if ((AOORVOORWORKs_DW.a >= 3.0) && (AOORVOORWORKs_DW.a < 4.0)) {
        AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_Med;
        AOORVOORWORKs_B.ActivityIndex = 4.0;
      } else if ((AOORVOORWORKs_DW.a >= 4.0) && (AOORVOORWORKs_DW.a < 5.0)) {
        AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_Med_High;
        AOORVOORWORKs_B.ActivityIndex = 5.0;
      } else if ((AOORVOORWORKs_DW.a >= 5.0) && (AOORVOORWORKs_DW.a < 6.0)) {
        AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_High;
        AOORVOORWORKs_B.ActivityIndex = 6.0;
      } else {
        if ((AOORVOORWORKs_DW.a >= 6.0) && (AOORVOORWORKs_DW.a < 7.0)) {
          AOORVOORWORKs_DW.is_c4_AOORVOORWORKs = AOORVOORWORKs_IN_V_High;
          AOORVOORWORKs_B.ActivityIndex = 7.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Activity Index Determination' */

  /* Switch: '<S13>/Switch4' incorporates:
   *  Delay: '<S13>/Delay'
   *  Delay: '<S13>/Delay1'
   *  Delay: '<S13>/Delay2'
   *  Delay: '<S13>/Delay3'
   *  Delay: '<S13>/Delay4'
   *  Switch: '<S13>/Switch'
   *  Switch: '<S13>/Switch1'
   *  Switch: '<S13>/Switch2'
   *  Switch: '<S13>/Switch3'
   */
  if (AOORVOORWORKs_B.pulse_finished) {
    AOORVOORWORKs_DW.Delay4_DSTATE = AOORVOORWORKs_DW.Delay3_DSTATE;
    AOORVOORWORKs_DW.Delay3_DSTATE = AOORVOORWORKs_DW.Delay2_DSTATE;
    AOORVOORWORKs_DW.Delay2_DSTATE = AOORVOORWORKs_DW.Delay1_DSTATE;
    AOORVOORWORKs_DW.Delay1_DSTATE = AOORVOORWORKs_DW.Delay_DSTATE;
    AOORVOORWORKs_DW.Delay_DSTATE = AOORVOORWORKs_B.time_between_pulses;
  }

  /* End of Switch: '<S13>/Switch4' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_o.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_B.flag != 0U);

  /* MATLABSystem: '<S1>/Digital Write1' incorporates:
   *  Constant: '<S1>/Constant15'
   */
  MW_digitalIO_write(AOORVOORWORKs_DW.obj_hwo.MW_DIGITALIO_HANDLE,
                     AOORVOORWORKs_P.Constant15_Value);

  /* Switch: '<S1>/Switch' */
  if (rtb_LED_STATE_f) {
    /* Update for Memory: '<S1>/Memory' */
    AOORVOORWORKs_DW.Memory_PreviousInput = AOORVOORWORKs_B.MovingAverage;
  } else {
    /* Update for Memory: '<S1>/Memory' */
    AOORVOORWORKs_DW.Memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<S1>/Switch' */
}

/* Model initialize function */
void AOORVOORWORKs_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_DigitalRead_AOORV_T *obj;
    freedomk64f_DigitalWrite_AOOR_T *obj_0;
    freedomk64f_PWMOutput_AOORVOO_T *obj_1;
    freedomk64f_AnalogInput_AOORV_T *obj_2;
    freedomk64f_fxos8700_AOORVOOR_T *obj_3;
    AOORVOORWORKs_PrevZCX.Subsystem1_Trig_ZCE = POS_ZCSIG;
    AOORVOORWORKs_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for Delay: '<S13>/Delay7' */
    AOORVOORWORKs_DW.Delay7_DSTATE = AOORVOORWORKs_P.Delay7_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    AOORVOORWORKs_DW.Memory_PreviousInput =
      AOORVOORWORKs_P.Memory_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay' */
    AOORVOORWORKs_DW.Delay_DSTATE = AOORVOORWORKs_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay1' */
    AOORVOORWORKs_DW.Delay1_DSTATE = AOORVOORWORKs_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay2' */
    AOORVOORWORKs_DW.Delay2_DSTATE = AOORVOORWORKs_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay3' */
    AOORVOORWORKs_DW.Delay3_DSTATE = AOORVOORWORKs_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay4' */
    AOORVOORWORKs_DW.Delay4_DSTATE = AOORVOORWORKs_P.Delay4_InitialCondition;

    /* SystemInitialize for Triggered SubSystem: '<S1>/Subsystem1' */
    /* Start for MATLABSystem: '<S9>/Serial Transmit' */
    AOORVOORWORKs_DW.obj_ce.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_ce.isInitialized = 0;
    AOORVOORWORKs_DW.obj_ce.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_j = true;
    AOORVOORWORK_SystemCore_setup_j(&AOORVOORWORKs_DW.obj_ce);

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem1' */

    /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem' */
    /* Start for MATLABSystem: '<S10>/FXOS8700 6-Axes Sensor' */
    AOORVOORWORKs_DW.obj_c.i2cobj.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_c.matlabCodegenIsDeleted = true;
    obj_3 = &AOORVOORWORKs_DW.obj_c;
    AOORVOORWORKs_DW.obj_c.isInitialized = 0;
    AOORVOORWORKs_DW.obj_c.SampleTime = -1.0;
    obj_3->i2cobj.isInitialized = 0;
    obj_3->i2cobj.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.obj_c.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_l = true;
    AOORVOORWORKs_DW.obj_c.SampleTime =
      AOORVOORWORKs_P.FXOS87006AxesSensor_SampleTime;
    AOORVOORWOR_SystemCore_setup_jf(&AOORVOORWORKs_DW.obj_c);

    /* Start for MATLABSystem: '<S10>/Moving Average' */
    AOORVOORWORKs_DW.obj.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj.isInitialized = 0;
    AOORVOORWORKs_DW.obj.NumChannels = -1;
    AOORVOORWORKs_DW.obj.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_p = true;
    AOORVOORWORKs_DW.obj.isSetupComplete = false;
    AOORVOORWORKs_DW.obj.isInitialized = 1;
    AOORVOORWORKs_DW.obj.NumChannels = 1;
    AOORVOORWORKs_DW.gobj_2.isInitialized = 0;
    AOORVOORWORKs_DW.obj.pStatistic = &AOORVOORWORKs_DW.gobj_2;
    AOORVOORWORKs_DW.obj.isSetupComplete = true;
    AOORVOORWORKs_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S10>/Moving Average' */
    if (AOORVOORWORKs_DW.obj.pStatistic->isInitialized == 1) {
      AOORVOORWORKs_DW.obj.pStatistic->pCumSum = 0.0;
      memset(&AOORVOORWORKs_DW.obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof
             (real_T));
      AOORVOORWORKs_DW.obj.pStatistic->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S10>/Moving Average' */

    /* SystemInitialize for Outport: '<S10>/activity_magnitude' */
    AOORVOORWORKs_B.MovingAverage = AOORVOORWORKs_P.activity_magnitude_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */

    /* Start for MATLABSystem: '<S1>/Serial Receive' */
    AOORVOORWORKs_DW.obj_m.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_m.SampleTime = -1.0;
    AOORVOORWORKs_DW.obj_m.isInitialized = 0;
    AOORVOORWORKs_DW.obj_m.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_m = true;
    AOORVOORWORKs_DW.obj_m.SampleTime = AOORVOORWORKs_P.SerialReceive_SampleTime;
    AOORVOORWORKs_SystemCore_setup(&AOORVOORWORKs_DW.obj_m);

    /* Start for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
    AOORVOORWORKs_DW.obj_i.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_i.isInitialized = 0;
    AOORVOORWORKs_DW.obj_i.SampleTime = -1.0;
    AOORVOORWORKs_DW.obj_i.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_mo = true;
    AOORVOORWORKs_DW.obj_i.SampleTime =
      AOORVOORWORKs_P.ATR_CMP_DETECT_SampleTime;
    obj = &AOORVOORWORKs_DW.obj_i;
    AOORVOORWORKs_DW.obj_i.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    AOORVOORWORKs_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
    AOORVOORWORKs_DW.obj_ci.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_ci.isInitialized = 0;
    AOORVOORWORKs_DW.obj_ci.SampleTime = -1.0;
    AOORVOORWORKs_DW.obj_ci.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_ml = true;
    AOORVOORWORKs_DW.obj_ci.SampleTime =
      AOORVOORWORKs_P.VENT_CMP_DETECT_SampleTime;
    obj = &AOORVOORWORKs_DW.obj_ci;
    AOORVOORWORKs_DW.obj_ci.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_ci.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    AOORVOORWORKs_DW.obj_ci.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    AOORVOORWORKs_DW.obj_p5.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_p5.isInitialized = 0;
    AOORVOORWORKs_DW.obj_p5.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty = true;
    obj_0 = &AOORVOORWORKs_DW.obj_p5;
    AOORVOORWORKs_DW.obj_p5.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_p5.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    AOORVOORWORKs_DW.obj_p5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    AOORVOORWORKs_DW.obj_pd.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_pd.isInitialized = 0;
    AOORVOORWORKs_DW.obj_pd.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_h = true;
    obj_0 = &AOORVOORWORKs_DW.obj_pd;
    AOORVOORWORKs_DW.obj_pd.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_pd.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    AOORVOORWORKs_DW.obj_pd.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write2' */
    AOORVOORWORKs_DW.obj_is.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_is.isInitialized = 0;
    AOORVOORWORKs_DW.obj_is.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_k = true;
    obj_0 = &AOORVOORWORKs_DW.obj_is;
    AOORVOORWORKs_DW.obj_is.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_is.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    AOORVOORWORKs_DW.obj_is.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    AOORVOORWORKs_DW.obj_n.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_n.isInitialized = 0;
    AOORVOORWORKs_DW.obj_n.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_a = true;
    obj_0 = &AOORVOORWORKs_DW.obj_n;
    AOORVOORWORKs_DW.obj_n.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    AOORVOORWORKs_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    AOORVOORWORKs_DW.obj_b.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_b.isInitialized = 0;
    AOORVOORWORKs_DW.obj_b.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_f = true;
    obj_1 = &AOORVOORWORKs_DW.obj_b;
    AOORVOORWORKs_DW.obj_b.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_b.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 100.0);
    MW_PWM_Start(AOORVOORWORKs_DW.obj_b.MW_PWM_HANDLE);
    AOORVOORWORKs_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    AOORVOORWORKs_DW.obj_np.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_np.isInitialized = 0;
    AOORVOORWORKs_DW.obj_np.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_i = true;
    obj_0 = &AOORVOORWORKs_DW.obj_np;
    AOORVOORWORKs_DW.obj_np.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_np.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    AOORVOORWORKs_DW.obj_np.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write6' */
    AOORVOORWORKs_DW.obj_e.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_e.isInitialized = 0;
    AOORVOORWORKs_DW.obj_e.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_in = true;
    obj_0 = &AOORVOORWORKs_DW.obj_e;
    AOORVOORWORKs_DW.obj_e.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    AOORVOORWORKs_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write7' */
    AOORVOORWORKs_DW.obj_c4.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_c4.isInitialized = 0;
    AOORVOORWORKs_DW.obj_c4.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_e = true;
    obj_0 = &AOORVOORWORKs_DW.obj_c4;
    AOORVOORWORKs_DW.obj_c4.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_c4.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    AOORVOORWORKs_DW.obj_c4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    AOORVOORWORKs_DW.obj_hw.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_hw.isInitialized = 0;
    AOORVOORWORKs_DW.obj_hw.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_e2 = true;
    obj_0 = &AOORVOORWORKs_DW.obj_hw;
    AOORVOORWORKs_DW.obj_hw.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_hw.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    AOORVOORWORKs_DW.obj_hw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output1' */
    AOORVOORWORKs_DW.obj_mo.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_mo.isInitialized = 0;
    AOORVOORWORKs_DW.obj_mo.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_hv = true;
    obj_1 = &AOORVOORWORKs_DW.obj_mo;
    AOORVOORWORKs_DW.obj_mo.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_mo.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 20.0);
    MW_PWM_Start(AOORVOORWORKs_DW.obj_mo.MW_PWM_HANDLE);
    AOORVOORWORKs_DW.obj_mo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output2' */
    AOORVOORWORKs_DW.obj_a.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_a.isInitialized = 0;
    AOORVOORWORKs_DW.obj_a.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_o = true;
    obj_1 = &AOORVOORWORKs_DW.obj_a;
    AOORVOORWORKs_DW.obj_a.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 20.0);
    MW_PWM_Start(AOORVOORWORKs_DW.obj_a.MW_PWM_HANDLE);
    AOORVOORWORKs_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input' */
    AOORVOORWORKs_DW.obj_f.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_f.isInitialized = 0;
    AOORVOORWORKs_DW.obj_f.SampleTime = -1.0;
    AOORVOORWORKs_DW.obj_f.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_fp = true;
    AOORVOORWORKs_DW.obj_f.SampleTime = AOORVOORWORKs_P.AnalogInput_SampleTime;
    obj_2 = &AOORVOORWORKs_DW.obj_f;
    AOORVOORWORKs_DW.obj_f.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_f.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    AOORVOORWORKs_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AOORVOORWORKs_DW.obj_f.MW_ANALOGIN_HANDLE,
      AOORVOORWORKs_B.trigger_val, 0U);
    AOORVOORWORKs_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input1' */
    AOORVOORWORKs_DW.obj_d.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_d.isInitialized = 0;
    AOORVOORWORKs_DW.obj_d.SampleTime = -1.0;
    AOORVOORWORKs_DW.obj_d.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_kb = true;
    AOORVOORWORKs_DW.obj_d.SampleTime = AOORVOORWORKs_P.AnalogInput1_SampleTime;
    obj_2 = &AOORVOORWORKs_DW.obj_d;
    AOORVOORWORKs_DW.obj_d.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_d.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19U);
    AOORVOORWORKs_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AOORVOORWORKs_DW.obj_d.MW_ANALOGIN_HANDLE,
      AOORVOORWORKs_B.trigger_val, 0U);
    AOORVOORWORKs_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input4' */
    AOORVOORWORKs_DW.obj_p.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_p.isInitialized = 0;
    AOORVOORWORKs_DW.obj_p.SampleTime = -1.0;
    AOORVOORWORKs_DW.obj_p.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_kg = true;
    AOORVOORWORKs_DW.obj_p.SampleTime = AOORVOORWORKs_P.AnalogInput4_SampleTime;
    obj_2 = &AOORVOORWORKs_DW.obj_p;
    AOORVOORWORKs_DW.obj_p.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_p.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    AOORVOORWORKs_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AOORVOORWORKs_DW.obj_p.MW_ANALOGIN_HANDLE,
      AOORVOORWORKs_B.trigger_val, 0U);
    AOORVOORWORKs_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input5' */
    AOORVOORWORKs_DW.obj_h.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_h.isInitialized = 0;
    AOORVOORWORKs_DW.obj_h.SampleTime = -1.0;
    AOORVOORWORKs_DW.obj_h.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_ks = true;
    AOORVOORWORKs_DW.obj_h.SampleTime = AOORVOORWORKs_P.AnalogInput5_SampleTime;
    obj_2 = &AOORVOORWORKs_DW.obj_h;
    AOORVOORWORKs_DW.obj_h.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_h.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18U);
    AOORVOORWORKs_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AOORVOORWORKs_DW.obj_h.MW_ANALOGIN_HANDLE,
      AOORVOORWORKs_B.trigger_val, 0U);
    AOORVOORWORKs_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    AOORVOORWORKs_DW.obj_o.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_o.isInitialized = 0;
    AOORVOORWORKs_DW.obj_o.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_ez = true;
    obj_0 = &AOORVOORWORKs_DW.obj_o;
    AOORVOORWORKs_DW.obj_o.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    AOORVOORWORKs_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    AOORVOORWORKs_DW.obj_hwo.matlabCodegenIsDeleted = true;
    AOORVOORWORKs_DW.obj_hwo.isInitialized = 0;
    AOORVOORWORKs_DW.obj_hwo.matlabCodegenIsDeleted = false;
    AOORVOORWORKs_DW.objisempty_l1 = true;
    obj_0 = &AOORVOORWORKs_DW.obj_hwo;
    AOORVOORWORKs_DW.obj_hwo.isSetupComplete = false;
    AOORVOORWORKs_DW.obj_hwo.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    AOORVOORWORKs_DW.obj_hwo.isSetupComplete = true;
  }
}

/* Model terminate function */
void AOORVOORWORKs_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Serial Receive' */
  matlabCodegenHandle_mat_jfpx5x5(&AOORVOORWORKs_DW.obj_m);

  /* Terminate for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  matlabCodegenHandle_matla_jfpx5(&AOORVOORWORKs_DW.obj_i);

  /* Terminate for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  matlabCodegenHandle_matla_jfpx5(&AOORVOORWORKs_DW.obj_ci);

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_p5);

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_pd);

  /* Terminate for MATLABSystem: '<S4>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_is);

  /* Terminate for MATLABSystem: '<S4>/Digital Write3' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_n);

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  matlabCodegenHand_jfpx5x5vtseop(&AOORVOORWORKs_DW.obj_b);

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_np);

  /* Terminate for MATLABSystem: '<S4>/Digital Write6' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_e);

  /* Terminate for MATLABSystem: '<S4>/Digital Write7' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_c4);

  /* Terminate for MATLABSystem: '<S4>/Digital Write8' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_hw);

  /* Terminate for MATLABSystem: '<S4>/PWM Output1' */
  matlabCodegenHand_jfpx5x5vtseop(&AOORVOORWORKs_DW.obj_mo);

  /* Terminate for MATLABSystem: '<S4>/PWM Output2' */
  matlabCodegenHand_jfpx5x5vtseop(&AOORVOORWORKs_DW.obj_a);

  /* Terminate for MATLABSystem: '<S1>/Analog Input' */
  matlabCodegenHandle_matlabCod_j(&AOORVOORWORKs_DW.obj_f);

  /* Terminate for MATLABSystem: '<S1>/Analog Input1' */
  matlabCodegenHandle_matlabCod_j(&AOORVOORWORKs_DW.obj_d);

  /* Terminate for MATLABSystem: '<S1>/Analog Input4' */
  matlabCodegenHandle_matlabCod_j(&AOORVOORWORKs_DW.obj_p);

  /* Terminate for MATLABSystem: '<S1>/Analog Input5' */
  matlabCodegenHandle_matlabCod_j(&AOORVOORWORKs_DW.obj_h);

  /* Terminate for Triggered SubSystem: '<S1>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S9>/Serial Transmit' */
  matlabCodegenHandle_ma_jfpx5x5v(&AOORVOORWORKs_DW.obj_ce);

  /* End of Terminate for SubSystem: '<S1>/Subsystem1' */

  /* Terminate for Triggered SubSystem: '<S1>/Triggered Subsystem' */
  /* Terminate for MATLABSystem: '<S10>/FXOS8700 6-Axes Sensor' */
  matlabCodegenHandle__jfpx5x5vts(&AOORVOORWORKs_DW.obj_c);
  matlabCodegenHandle_jfpx5x5vtse(&AOORVOORWORKs_DW.obj_c.i2cobj);

  /* Terminate for MATLABSystem: '<S10>/Moving Average' */
  matlabCodegenHandle_m_jfpx5x5vt(&AOORVOORWORKs_DW.obj);

  /* End of Terminate for SubSystem: '<S1>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_o);

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&AOORVOORWORKs_DW.obj_hwo);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
