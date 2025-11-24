/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAIRVVIRWORK.c
 *
 * Code generated for Simulink model 'AAIRVVIRWORK'.
 *
 * Model version                  : 1.423
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Nov 24 01:15:23 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AAIRVVIRWORK.h"
#include "AAIRVVIRWORK_private.h"

/* Named constants for Chart: '<S1>/Chart1' */
#define AAIRVVIRWORK_IN_Echo           ((uint8_T)1U)
#define AAIRVVIRWORK_IN_Egram_Update   ((uint8_T)2U)
#define AAIRVVIRWORK_IN_Initial_State  ((uint8_T)4U)
#define AAIRVVIRWORK_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define AAIRVVIRWORK_IN_Read_Data      ((uint8_T)5U)
#define AAIRVVIRWORK_IN_Safety_Check   ((uint8_T)6U)
#define AAIRVVIRWORK_IN_Standby        ((uint8_T)7U)
#define AAIRVVIRWORK_IN_Write_Data     ((uint8_T)8U)
#define AAIRVVIRWORK_IN_par_load       ((uint8_T)9U)
#define AAIRVVIR_IN_setToZeroForTesting ((uint8_T)10U)
#define AAIRV_IN_HandshakeRequestEnable ((uint8_T)3U)

/* Named constants for Chart: '<S1>/HeartChamberPulseDetection' */
#define AAIRVVIRWORK_IN_default        ((uint8_T)1U)
#define AAIRVVIRWORK_IN_led_on         ((uint8_T)2U)

/* Named constants for Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */
#define AAIRVVIRWORK_IN_UnsensedModes  ((uint8_T)3U)
#define AAIRVVIRWORK_IN_awaitNewPulse  ((uint8_T)1U)
#define AAIRVVIRWORK_IN_default_m      ((uint8_T)6U)
#define AAIRVVIRWORK_IN_default_mk     ((uint8_T)2U)
#define AAIRVVIRWORK_IN_resetDeltaT    ((uint8_T)4U)
#define AAIRVVIRWORK_IN_setARPasDeltaT ((uint8_T)5U)
#define AAIRVVIRWORK_IN_setVRPasDeltaT ((uint8_T)5U)
#define AAIRVVIRWOR_IN_newPulseDetected ((uint8_T)3U)
#define AAIRVVIR_IN_AtrialRateDetection ((uint8_T)1U)
#define AAIRVVI_IN_AtrialRateDetection1 ((uint8_T)2U)
#define AAIR_IN_VenticularRateDetection ((uint8_T)4U)
#define AAI_IN_VenticularRateDetection1 ((uint8_T)5U)

/* Named constants for Chart: '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
#define AAIRVVIRWORK_IN_AAI            ((uint8_T)1U)
#define AAIRVVIRWORK_IN_AAIR           ((uint8_T)2U)
#define AAIRVVIRWORK_IN_VVI            ((uint8_T)4U)
#define AAIRVVIRWORK_IN_VVIR           ((uint8_T)5U)
#define AAIRVVIR_IN_HysterisisSelection ((uint8_T)3U)

/* Named constants for Chart: '<S2>/Activity Index Determination' */
#define AAIRVVIRWORK_IN_High           ((uint8_T)1U)
#define AAIRVVIRWORK_IN_Low            ((uint8_T)2U)
#define AAIRVVIRWORK_IN_Med            ((uint8_T)3U)
#define AAIRVVIRWORK_IN_Med_High       ((uint8_T)4U)
#define AAIRVVIRWORK_IN_Med_Low        ((uint8_T)5U)
#define AAIRVVIRWORK_IN_V_High         ((uint8_T)6U)
#define AAIRVVIRWORK_IN_V_Low          ((uint8_T)7U)
#define AAIRVVIRWORK_IN_init           ((uint8_T)8U)

/* Named constants for Chart: '<S2>/Chart' */
#define AAIRVVIRWORK_IN_STEPUP         ((uint8_T)1U)
#define AAIRVVIRWORK_IN_overThreshold  ((uint8_T)3U)
#define AAIRVVIRWORK_IN_start          ((uint8_T)4U)
#define AAIRVVIRWORK_IN_stepdown       ((uint8_T)5U)

/* Named constants for Chart: '<S3>/1.1.3.2 PacemakerControl' */
#define AAIRVVIRWORK_IN_AOO            ((uint8_T)3U)
#define AAIRVVIRWORK_IN_AOOR           ((uint8_T)4U)
#define AAIRVVIRWORK_IN_CHARGE         ((uint8_T)1U)
#define AAIRVVIRWORK_IN_DISCHARGE      ((uint8_T)2U)
#define AAIRVVIRWORK_IN_Initialize     ((uint8_T)5U)
#define AAIRVVIRWORK_IN_Pulse          ((uint8_T)4U)
#define AAIRVVIRWORK_IN_Standby_a      ((uint8_T)6U)
#define AAIRVVIRWORK_IN_VOO            ((uint8_T)7U)
#define AAIRVVIRWORK_IN_VOOR           ((uint8_T)8U)
#define AAIRVVIRWORK_IN_VVIR_c         ((uint8_T)10U)
#define AAIRVVIRWORK_IN_VVI_n          ((uint8_T)9U)
#define AAIRVVIRWORK_IN_initializations ((uint8_T)5U)
#define AAIRVVIRW_IN_Hysterisis_mode_ON ((uint8_T)3U)
#define AAIRVVIR_IN_Hysterisis_mode_OFF ((uint8_T)2U)

/* Block signals (default storage) */
B_AAIRVVIRWORK_T AAIRVVIRWORK_B;

/* Block states (default storage) */
DW_AAIRVVIRWORK_T AAIRVVIRWORK_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_AAIRVVIRWORK_T AAIRVVIRWORK_PrevZCX;

/* Real-time model */
RT_MODEL_AAIRVVIRWORK_T AAIRVVIRWORK_M_;
RT_MODEL_AAIRVVIRWORK_T *const AAIRVVIRWORK_M = &AAIRVVIRWORK_M_;

/* Forward declaration for local functions */
static void AAIRVVIRWOR_AtrialRateDetection(void);
static void AAIRVVIRWO_AtrialRateDetection1(void);
static void AAIRVVIRWORK_AAI(void);
static void AAIRVVIRWORK_AAIR(void);
static void AAIRVVIRWORK_AOO(void);
static void AAIRVVIRWORK_AOOR(void);
static void AAIRVVIRWORK_Standby(void);
static void AAIRVVIRWORK_VVI(void);
static void AAIR_SystemCore_release_pfn2eia(const
  freedomk64f_SCIRead_AAIRVVIRW_T *obj);
static void AAIRV_SystemCore_delete_pfn2eia(const
  freedomk64f_SCIRead_AAIRVVIRW_T *obj);
static void matlabCodegenHandle_mat_pfn2eia(freedomk64f_SCIRead_AAIRVVIRW_T *obj);
static void AAIRVV_SystemCore_release_pfn2e(const
  freedomk64f_DigitalRead_AAIRV_T *obj);
static void AAIRVVI_SystemCore_delete_pfn2e(const
  freedomk64f_DigitalRead_AAIRV_T *obj);
static void matlabCodegenHandle_matla_pfn2e(freedomk64f_DigitalRead_AAIRV_T *obj);
static void AAIRVVIRWORK_SystemCore_release(const
  freedomk64f_DigitalWrite_AAIR_T *obj);
static void AAIRVVIRWORK_SystemCore_delete(const freedomk64f_DigitalWrite_AAIR_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_AAIR_T *obj);
static void SystemCore_releas_pfn2eia2mtltj(const
  freedomk64f_PWMOutput_AAIRVVI_T *obj);
static void SystemCore_delete_pfn2eia2mtltj(const
  freedomk64f_PWMOutput_AAIRVVI_T *obj);
static void matlabCodegenHand_pfn2eia2mtltj(freedomk64f_PWMOutput_AAIRVVI_T *obj);
static void AAIRVVIRWO_SystemCore_release_p(const
  freedomk64f_AnalogInput_AAIRV_T *obj);
static void AAIRVVIRWOR_SystemCore_delete_p(const
  freedomk64f_AnalogInput_AAIRV_T *obj);
static void matlabCodegenHandle_matlabCod_p(freedomk64f_AnalogInput_AAIRV_T *obj);
static void AAI_SystemCore_release_pfn2eia2(const
  freedomk64f_SCIWrite_AAIRVVIR_T *obj);
static void AAIR_SystemCore_delete_pfn2eia2(const
  freedomk64f_SCIWrite_AAIRVVIR_T *obj);
static void matlabCodegenHandle_ma_pfn2eia2(freedomk64f_SCIWrite_AAIRVVIR_T *obj);
static void A_SystemCore_release_pfn2eia2mt(const
  freedomk64f_fxos8700_AAIRVVIR_T *obj);
static void AA_SystemCore_delete_pfn2eia2mt(const
  freedomk64f_fxos8700_AAIRVVIR_T *obj);
static void matlabCodegenHandle__pfn2eia2mt(freedomk64f_fxos8700_AAIRVVIR_T *obj);
static void SystemCore_release_pfn2eia2mtl(b_freedomk64f_I2CMasterWrite__T *obj);
static void A_SystemCore_delete_pfn2eia2mtl(b_freedomk64f_I2CMasterWrite__T *obj);
static void matlabCodegenHandle_pfn2eia2mtl(b_freedomk64f_I2CMasterWrite__T *obj);
static void AA_SystemCore_release_pfn2eia2m(dsp_simulink_MovingAverage_AA_T *obj);
static void AAI_SystemCore_delete_pfn2eia2m(dsp_simulink_MovingAverage_AA_T *obj);
static void matlabCodegenHandle_m_pfn2eia2m(dsp_simulink_MovingAverage_AA_T *obj);
static void AAIRVVIRWORK_SystemCore_setup_p(freedomk64f_SCIWrite_AAIRVVIR_T *obj);
static void AAIRVVIRWOR_SystemCore_setup_pf(freedomk64f_fxos8700_AAIRVVIR_T *obj);
static void AAIRVVIRWORK_SystemCore_setup(freedomk64f_SCIRead_AAIRVVIRW_T *obj);
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

/* Function for Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */
static void AAIRVVIRWOR_AtrialRateDetection(void)
{
  uint32_T qY;
  if (AAIRVVIRWORK_B.Mode != 112U) {
    AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
    AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_m;
  } else {
    switch (AAIRVVIRWORK_DW.is_AtrialRateDetection) {
     case AAIRVVIRWORK_IN_awaitNewPulse:
      if (!AAIRVVIRWORK_B.ATR_CMP_DETECT) {
        AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWORK_IN_awaitNewPulse;
        qY = AAIRVVIRWORK_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
        if (qY < AAIRVVIRWORK_B.time_between_pulses) {
          qY = MAX_uint32_T;
        }

        AAIRVVIRWORK_B.time_between_pulses = qY;
      } else {
        AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWOR_IN_newPulseDetected;
        AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
        AAIRVVIRWORK_B.pulse_finished = true;
        AAIRVVIRWORK_B.HR_Ready = true;
      }
      break;

     case AAIRVVIRWORK_IN_default_mk:
      AAIRVVIRWORK_B.pulse_finished = false;
      if (AAIRVVIRWORK_B.ATR_CMP_DETECT) {
        AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWORK_IN_setARPasDeltaT;
        AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
        AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.a_r_p;
      }
      break;

     case AAIRVVIRWOR_IN_newPulseDetected:
      AAIRVVIRWORK_B.pulse_finished = true;
      if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= 1U) {
        AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWORK_IN_resetDeltaT;
        AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
        AAIRVVIRWORK_B.pulse_finished = false;
        AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.a_r_p;
      }
      break;

     case AAIRVVIRWORK_IN_resetDeltaT:
      AAIRVVIRWORK_B.pulse_finished = false;
      qY = AAIRVVIRWORK_B.a_r_p - /*MW:OvSatOk*/ 1U;
      if (qY > AAIRVVIRWORK_B.a_r_p) {
        qY = 0U;
      }

      if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= qY) {
        if (!AAIRVVIRWORK_B.ATR_CMP_DETECT) {
          AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWORK_IN_awaitNewPulse;
          qY = AAIRVVIRWORK_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
          if (qY < AAIRVVIRWORK_B.time_between_pulses) {
            qY = MAX_uint32_T;
          }

          AAIRVVIRWORK_B.time_between_pulses = qY;
        } else {
          AAIRVVIRWORK_DW.is_AtrialRateDetection =
            AAIRVVIRWOR_IN_newPulseDetected;
          AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
          AAIRVVIRWORK_B.pulse_finished = true;
          AAIRVVIRWORK_B.HR_Ready = true;
        }
      }
      break;

     default:
      /* case IN_setARPasDeltaT: */
      if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= AAIRVVIRWORK_B.a_r_p) {
        if (!AAIRVVIRWORK_B.ATR_CMP_DETECT) {
          AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWORK_IN_awaitNewPulse;
          qY = AAIRVVIRWORK_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
          if (qY < AAIRVVIRWORK_B.time_between_pulses) {
            qY = MAX_uint32_T;
          }

          AAIRVVIRWORK_B.time_between_pulses = qY;
        } else {
          AAIRVVIRWORK_DW.is_AtrialRateDetection =
            AAIRVVIRWOR_IN_newPulseDetected;
          AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
          AAIRVVIRWORK_B.pulse_finished = true;
          AAIRVVIRWORK_B.HR_Ready = true;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */
static void AAIRVVIRWO_AtrialRateDetection1(void)
{
  uint32_T qY;
  if (AAIRVVIRWORK_B.Mode != 1120U) {
    AAIRVVIRWORK_DW.is_AtrialRateDetection1 = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
    AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_m;
  } else {
    switch (AAIRVVIRWORK_DW.is_AtrialRateDetection1) {
     case AAIRVVIRWORK_IN_awaitNewPulse:
      if (!AAIRVVIRWORK_B.ATR_CMP_DETECT) {
        AAIRVVIRWORK_DW.is_AtrialRateDetection1 = AAIRVVIRWORK_IN_awaitNewPulse;
        qY = AAIRVVIRWORK_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
        if (qY < AAIRVVIRWORK_B.time_between_pulses) {
          qY = MAX_uint32_T;
        }

        AAIRVVIRWORK_B.time_between_pulses = qY;
      } else {
        AAIRVVIRWORK_DW.is_AtrialRateDetection1 =
          AAIRVVIRWOR_IN_newPulseDetected;
        AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
        AAIRVVIRWORK_B.pulse_finished = true;
        AAIRVVIRWORK_B.HR_Ready = true;
      }
      break;

     case AAIRVVIRWORK_IN_default_mk:
      AAIRVVIRWORK_B.pulse_finished = false;
      if (AAIRVVIRWORK_B.ATR_CMP_DETECT) {
        AAIRVVIRWORK_DW.is_AtrialRateDetection1 = AAIRVVIRWORK_IN_setARPasDeltaT;
        AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
        AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.a_r_p;
      }
      break;

     case AAIRVVIRWOR_IN_newPulseDetected:
      AAIRVVIRWORK_B.pulse_finished = true;
      if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= 1U) {
        AAIRVVIRWORK_DW.is_AtrialRateDetection1 = AAIRVVIRWORK_IN_resetDeltaT;
        AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
        AAIRVVIRWORK_B.pulse_finished = false;
        AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.a_r_p;
      }
      break;

     case AAIRVVIRWORK_IN_resetDeltaT:
      AAIRVVIRWORK_B.pulse_finished = false;
      qY = AAIRVVIRWORK_B.a_r_p - /*MW:OvSatOk*/ 1U;
      if (qY > AAIRVVIRWORK_B.a_r_p) {
        qY = 0U;
      }

      if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= qY) {
        if (!AAIRVVIRWORK_B.ATR_CMP_DETECT) {
          AAIRVVIRWORK_DW.is_AtrialRateDetection1 =
            AAIRVVIRWORK_IN_awaitNewPulse;
          qY = AAIRVVIRWORK_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
          if (qY < AAIRVVIRWORK_B.time_between_pulses) {
            qY = MAX_uint32_T;
          }

          AAIRVVIRWORK_B.time_between_pulses = qY;
        } else {
          AAIRVVIRWORK_DW.is_AtrialRateDetection1 =
            AAIRVVIRWOR_IN_newPulseDetected;
          AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
          AAIRVVIRWORK_B.pulse_finished = true;
          AAIRVVIRWORK_B.HR_Ready = true;
        }
      }
      break;

     default:
      /* case IN_setARPasDeltaT: */
      if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= AAIRVVIRWORK_B.a_r_p) {
        if (!AAIRVVIRWORK_B.ATR_CMP_DETECT) {
          AAIRVVIRWORK_DW.is_AtrialRateDetection1 =
            AAIRVVIRWORK_IN_awaitNewPulse;
          qY = AAIRVVIRWORK_B.time_between_pulses + /*MW:OvSatOk*/ 1U;
          if (qY < AAIRVVIRWORK_B.time_between_pulses) {
            qY = MAX_uint32_T;
          }

          AAIRVVIRWORK_B.time_between_pulses = qY;
        } else {
          AAIRVVIRWORK_DW.is_AtrialRateDetection1 =
            AAIRVVIRWOR_IN_newPulseDetected;
          AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
          AAIRVVIRWORK_B.pulse_finished = true;
          AAIRVVIRWORK_B.HR_Ready = true;
        }
      }
      break;
    }
  }
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
static void AAIRVVIRWORK_AAI(void)
{
  if (AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.AAI) {
    AAIRVVIRWORK_DW.is_AAI = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
    AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
    AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
  } else {
    switch (AAIRVVIRWORK_DW.is_AAI) {
     case AAIRVVIRWORK_IN_CHARGE:
      if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AAIRVVIRWORK_B.atrial_pulse_width)) {
        AAIRVVIRWORK_DW.is_AAI = AAIRVVIRWORK_IN_Pulse;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
      }
      break;

     case AAIRVVIR_IN_Hysterisis_mode_OFF:
      /* Constant: '<S22>/LOW' */
      if ((AAIRVVIRWORK_B.count <= AAIRVVIRWORK_B.wait_time) &&
          ((AAIRVVIRWORK_B.ATR_CMP_DETECT != AAIRVVIRWORK_P.LOW_Value) ||
           (!(AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.lower_rate_limit)))) {
        AAIRVVIRWORK_DW.is_AAI = AAIRVVIR_IN_Hysterisis_mode_OFF;
        AAIRVVIRWORK_B.count++;
      } else {
        if ((AAIRVVIRWORK_B.ATR_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
            (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.lower_rate_limit)) {
          AAIRVVIRWORK_DW.is_AAI = AAIRVVIRWORK_IN_CHARGE;
          AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
          AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

          /* Constant: '<S22>/HIGH' */
          AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;
        }
      }
      break;

     case AAIRVVIRW_IN_Hysterisis_mode_ON:
      /* Constant: '<S22>/LOW' */
      if ((AAIRVVIRWORK_B.ATR_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
          (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.h_r_l)) {
        AAIRVVIRWORK_DW.is_AAI = AAIRVVIRWORK_IN_CHARGE;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
        AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;
      } else {
        if ((AAIRVVIRWORK_B.count <= AAIRVVIRWORK_B.wait_time) &&
            ((AAIRVVIRWORK_B.ATR_CMP_DETECT != AAIRVVIRWORK_P.LOW_Value) ||
             (!(AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.lower_rate_limit)))) {
          AAIRVVIRWORK_DW.is_AAI = AAIRVVIRW_IN_Hysterisis_mode_ON;
          AAIRVVIRWORK_B.count++;
        }
      }
      break;

     case AAIRVVIRWORK_IN_Pulse:
      if (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.a_r_p) {
        AAIRVVIRWORK_DW.is_AAI = AAIRVVIRWORK_IN_initializations;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
        AAIRVVIRWORK_B.ATR_CMP_REF_PWM = AAIRVVIRWORK_B.atrial_sensitivity;
        AAIRVVIRWORK_B.count = 0.0;
      }
      break;

     default:
      /* case IN_initializations: */
      if ((AAIRVVIRWORK_B.hysterisis_flag == 0) &&
          (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.wait_time_LRL))
      {
        AAIRVVIRWORK_DW.is_AAI = AAIRVVIR_IN_Hysterisis_mode_OFF;
        AAIRVVIRWORK_B.count++;
      } else {
        if ((AAIRVVIRWORK_B.hysterisis_flag == 1) &&
            (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.wait_time_LRL))
        {
          AAIRVVIRWORK_DW.is_AAI = AAIRVVIRW_IN_Hysterisis_mode_ON;
          AAIRVVIRWORK_B.count++;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AAIRVVIRWORK_AAIR(void)
{
  if (AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.AAIR) {
    AAIRVVIRWORK_DW.is_AAIR = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
    AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
    AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
  } else {
    switch (AAIRVVIRWORK_DW.is_AAIR) {
     case AAIRVVIRWORK_IN_CHARGE:
      if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AAIRVVIRWORK_B.atrial_pulse_width)) {
        AAIRVVIRWORK_DW.is_AAIR = AAIRVVIRWORK_IN_Pulse;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
      }
      break;

     case AAIRVVIR_IN_Hysterisis_mode_OFF:
      /* Constant: '<S22>/LOW' */
      if ((AAIRVVIRWORK_B.ATR_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
          (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.CR)) {
        AAIRVVIRWORK_DW.is_AAIR = AAIRVVIRWORK_IN_CHARGE;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
        AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;
      }
      break;

     case AAIRVVIRW_IN_Hysterisis_mode_ON:
      /* Constant: '<S22>/LOW' */
      if ((AAIRVVIRWORK_B.ATR_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
          (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.CR - 5.0F)) {
        AAIRVVIRWORK_DW.is_AAIR = AAIRVVIRWORK_IN_CHARGE;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
        AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;
      }
      break;

     case AAIRVVIRWORK_IN_Pulse:
      if (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.a_r_p) {
        AAIRVVIRWORK_DW.is_AAIR = AAIRVVIRWORK_IN_initializations;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
        AAIRVVIRWORK_B.ATR_CMP_REF_PWM = AAIRVVIRWORK_B.atrial_sensitivity;
      }
      break;

     default:
      /* case IN_initializations: */
      if ((AAIRVVIRWORK_B.hysterisis_flag == 0) &&
          (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.wait_time_AAIR))
      {
        AAIRVVIRWORK_DW.is_AAIR = AAIRVVIR_IN_Hysterisis_mode_OFF;
      } else {
        if ((AAIRVVIRWORK_B.hysterisis_flag == 1) &&
            (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.wait_time_AAIR))
        {
          AAIRVVIRWORK_DW.is_AAIR = AAIRVVIRW_IN_Hysterisis_mode_ON;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AAIRVVIRWORK_AOO(void)
{
  if (AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.AOO) {
    AAIRVVIRWORK_DW.is_AOO = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
    AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
    AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
  } else if (AAIRVVIRWORK_DW.is_AOO == AAIRVVIRWORK_IN_CHARGE) {
    if (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.MathFunction1 -
        (real32_T)AAIRVVIRWORK_B.atrial_pulse_width) {
      AAIRVVIRWORK_DW.is_AOO = AAIRVVIRWORK_IN_DISCHARGE;
      AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

      /* Constant: '<S22>/HIGH' */
      AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
      AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;
    }
  } else {
    /* case IN_DISCHARGE: */
    if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
        (AAIRVVIRWORK_B.atrial_pulse_width)) {
      AAIRVVIRWORK_DW.is_AOO = AAIRVVIRWORK_IN_CHARGE;
      AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;

      /* Constant: '<S22>/HIGH' */
      AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
      AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;

      /* Constant: '<S22>/HIGH' */
      AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AAIRVVIRWORK_AOOR(void)
{
  real_T tmp;
  uint32_T tmp_0;
  if (AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.AOOR) {
    AAIRVVIRWORK_DW.is_AOOR = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
    AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
    AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
  } else if (AAIRVVIRWORK_DW.is_AOOR == AAIRVVIRWORK_IN_CHARGE) {
    tmp = rt_roundd_snf((real_T)AAIRVVIRWORK_B.Cast -
                        AAIRVVIRWORK_B.atrial_pulse_width);
    if (tmp < 4.294967296E+9) {
      if (tmp >= 0.0) {
        tmp_0 = (uint32_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint32_T;
    }

    if (AAIRVVIRWORK_DW.temporalCounter_i1 >= tmp_0) {
      AAIRVVIRWORK_DW.is_AOOR = AAIRVVIRWORK_IN_DISCHARGE;
      AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

      /* Constant: '<S22>/HIGH' */
      AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
      AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;
    }
  } else {
    /* case IN_DISCHARGE: */
    if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
        (AAIRVVIRWORK_B.atrial_pulse_width)) {
      AAIRVVIRWORK_DW.is_AOOR = AAIRVVIRWORK_IN_CHARGE;
      AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;

      /* Constant: '<S22>/HIGH' */
      AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
      AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
      AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;

      /* Constant: '<S22>/HIGH' */
      AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

      /* Constant: '<S22>/LOW' */
      AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AAIRVVIRWORK_Standby(void)
{
  AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
  AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
  if (AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.AOO) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_AOO;
    AAIRVVIRWORK_DW.is_AOO = AAIRVVIRWORK_IN_CHARGE;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
    AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
  } else if (AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.AOOR) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_AOOR;
    AAIRVVIRWORK_DW.is_AOOR = AAIRVVIRWORK_IN_CHARGE;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
    AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
  } else if (AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.VVIR) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_VVIR_c;
    AAIRVVIRWORK_DW.is_VVIR = AAIRVVIRWORK_IN_initializations;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
    AAIRVVIRWORK_B.VENT_CMP_REF_PWM = AAIRVVIRWORK_B.ventricular_sensitivity;
  } else if (AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.VOOR) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_VOOR;
    AAIRVVIRWORK_DW.is_VOOR = AAIRVVIRWORK_IN_CHARGE;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
    AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
  } else if (AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.AAIR) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_AAIR;
    AAIRVVIRWORK_DW.is_AAIR = AAIRVVIRWORK_IN_initializations;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
    AAIRVVIRWORK_B.ATR_CMP_REF_PWM = AAIRVVIRWORK_B.atrial_sensitivity;
  } else if (AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.VVI) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_VVI_n;
    AAIRVVIRWORK_DW.is_VVI = AAIRVVIRWORK_IN_initializations;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
    AAIRVVIRWORK_B.VENT_CMP_REF_PWM = AAIRVVIRWORK_B.ventricular_sensitivity;
    AAIRVVIRWORK_B.count = 0.0;
  } else if ((real_T)AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.VOO) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_VOO;
    AAIRVVIRWORK_DW.is_VOO = AAIRVVIRWORK_IN_CHARGE;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
    AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

    /* Constant: '<S22>/LOW' */
    AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
    AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;

    /* Constant: '<S22>/HIGH' */
    AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
  } else if (AAIRVVIRWORK_B.Mode == AAIRVVIRWORK_DW.AAI) {
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_AAI;
    AAIRVVIRWORK_DW.is_AAI = AAIRVVIRWORK_IN_initializations;
    AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
    AAIRVVIRWORK_B.ATR_CMP_REF_PWM = AAIRVVIRWORK_B.atrial_sensitivity;
    AAIRVVIRWORK_B.count = 0.0;
  } else {
    if (!AAIRVVIRWORK_B.HR_Ready) {
      AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Initialize;
      AAIRVVIRWORK_DW.AOO = 100U;
      AAIRVVIRWORK_DW.VOO = 200;
      AAIRVVIRWORK_DW.AAI = 112U;
      AAIRVVIRWORK_DW.VVI = 222U;
      AAIRVVIRWORK_DW.AOOR = 1000.0;
      AAIRVVIRWORK_DW.AAIR = 1120.0;
      AAIRVVIRWORK_DW.VOOR = 2000.0;
      AAIRVVIRWORK_DW.VVIR = 2220.0;
    }
  }
}

/* Function for Chart: '<S3>/1.1.3.2 PacemakerControl' */
static void AAIRVVIRWORK_VVI(void)
{
  if (AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.VVI) {
    AAIRVVIRWORK_DW.is_VVI = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
    AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
    AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
  } else {
    switch (AAIRVVIRWORK_DW.is_VVI) {
     case AAIRVVIRWORK_IN_CHARGE:
      if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AAIRVVIRWORK_B.ventricular_pulse_width)) {
        AAIRVVIRWORK_DW.is_VVI = AAIRVVIRWORK_IN_Pulse;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;

        /* Constant: '<S22>/LOW' */
        AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
      }
      break;

     case AAIRVVIR_IN_Hysterisis_mode_OFF:
      /* Constant: '<S22>/LOW' */
      if ((AAIRVVIRWORK_B.count <= AAIRVVIRWORK_B.wait_time) &&
          ((AAIRVVIRWORK_B.VENT_CMP_DETECT != AAIRVVIRWORK_P.LOW_Value) ||
           (!(AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.lower_rate_limit)))) {
        AAIRVVIRWORK_DW.is_VVI = AAIRVVIR_IN_Hysterisis_mode_OFF;
        AAIRVVIRWORK_B.count++;
      } else {
        if ((AAIRVVIRWORK_B.VENT_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
            (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.lower_rate_limit)) {
          AAIRVVIRWORK_DW.is_VVI = AAIRVVIRWORK_IN_CHARGE;
          AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
          AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

          /* Constant: '<S22>/HIGH' */
          AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;

          /* Constant: '<S22>/HIGH' */
          AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
        }
      }
      break;

     case AAIRVVIRW_IN_Hysterisis_mode_ON:
      /* Constant: '<S22>/LOW' */
      if ((AAIRVVIRWORK_B.VENT_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
          (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.h_r_l)) {
        AAIRVVIRWORK_DW.is_VVI = AAIRVVIRWORK_IN_CHARGE;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
        AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
        AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;

        /* Constant: '<S22>/HIGH' */
        AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
      } else {
        if ((AAIRVVIRWORK_B.count <= AAIRVVIRWORK_B.wait_time) &&
            ((AAIRVVIRWORK_B.VENT_CMP_DETECT != AAIRVVIRWORK_P.LOW_Value) ||
             (!(AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.lower_rate_limit)))) {
          AAIRVVIRWORK_DW.is_VVI = AAIRVVIRW_IN_Hysterisis_mode_ON;
          AAIRVVIRWORK_B.count++;
        }
      }
      break;

     case AAIRVVIRWORK_IN_Pulse:
      if (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.v_r_p) {
        AAIRVVIRWORK_DW.is_VVI = AAIRVVIRWORK_IN_initializations;
        AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
        AAIRVVIRWORK_B.VENT_CMP_REF_PWM = AAIRVVIRWORK_B.ventricular_sensitivity;
        AAIRVVIRWORK_B.count = 0.0;
      }
      break;

     default:
      /* case IN_initializations: */
      if ((AAIRVVIRWORK_B.hysterisis_flag == 0) &&
          (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.wait_time_LRL))
      {
        AAIRVVIRWORK_DW.is_VVI = AAIRVVIR_IN_Hysterisis_mode_OFF;
        AAIRVVIRWORK_B.count++;
      } else {
        if ((AAIRVVIRWORK_B.hysterisis_flag == 1) &&
            (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.wait_time_LRL))
        {
          AAIRVVIRWORK_DW.is_VVI = AAIRVVIRW_IN_Hysterisis_mode_ON;
          AAIRVVIRWORK_B.count++;
        }
      }
      break;
    }
  }
}

static void AAIR_SystemCore_release_pfn2eia(const
  freedomk64f_SCIRead_AAIRVVIRW_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void AAIRV_SystemCore_delete_pfn2eia(const
  freedomk64f_SCIRead_AAIRVVIRW_T *obj)
{
  AAIR_SystemCore_release_pfn2eia(obj);
}

static void matlabCodegenHandle_mat_pfn2eia(freedomk64f_SCIRead_AAIRVVIRW_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AAIRV_SystemCore_delete_pfn2eia(obj);
  }
}

static void AAIRVV_SystemCore_release_pfn2e(const
  freedomk64f_DigitalRead_AAIRV_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void AAIRVVI_SystemCore_delete_pfn2e(const
  freedomk64f_DigitalRead_AAIRV_T *obj)
{
  AAIRVV_SystemCore_release_pfn2e(obj);
}

static void matlabCodegenHandle_matla_pfn2e(freedomk64f_DigitalRead_AAIRV_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AAIRVVI_SystemCore_delete_pfn2e(obj);
  }
}

static void AAIRVVIRWORK_SystemCore_release(const
  freedomk64f_DigitalWrite_AAIR_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void AAIRVVIRWORK_SystemCore_delete(const freedomk64f_DigitalWrite_AAIR_T
  *obj)
{
  AAIRVVIRWORK_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_AAIR_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_SystemCore_delete(obj);
  }
}

static void SystemCore_releas_pfn2eia2mtltj(const
  freedomk64f_PWMOutput_AAIRVVI_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void SystemCore_delete_pfn2eia2mtltj(const
  freedomk64f_PWMOutput_AAIRVVI_T *obj)
{
  SystemCore_releas_pfn2eia2mtltj(obj);
}

static void matlabCodegenHand_pfn2eia2mtltj(freedomk64f_PWMOutput_AAIRVVI_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete_pfn2eia2mtltj(obj);
  }
}

static void AAIRVVIRWO_SystemCore_release_p(const
  freedomk64f_AnalogInput_AAIRV_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_AnalogIn_Stop(obj->MW_ANALOGIN_HANDLE);
    MW_AnalogIn_Close(obj->MW_ANALOGIN_HANDLE);
  }
}

static void AAIRVVIRWOR_SystemCore_delete_p(const
  freedomk64f_AnalogInput_AAIRV_T *obj)
{
  AAIRVVIRWO_SystemCore_release_p(obj);
}

static void matlabCodegenHandle_matlabCod_p(freedomk64f_AnalogInput_AAIRV_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AAIRVVIRWOR_SystemCore_delete_p(obj);
  }
}

static void AAI_SystemCore_release_pfn2eia2(const
  freedomk64f_SCIWrite_AAIRVVIR_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void AAIR_SystemCore_delete_pfn2eia2(const
  freedomk64f_SCIWrite_AAIRVVIR_T *obj)
{
  AAI_SystemCore_release_pfn2eia2(obj);
}

static void matlabCodegenHandle_ma_pfn2eia2(freedomk64f_SCIWrite_AAIRVVIR_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AAIR_SystemCore_delete_pfn2eia2(obj);
  }
}

static void A_SystemCore_release_pfn2eia2mt(const
  freedomk64f_fxos8700_AAIRVVIR_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void AA_SystemCore_delete_pfn2eia2mt(const
  freedomk64f_fxos8700_AAIRVVIR_T *obj)
{
  A_SystemCore_release_pfn2eia2mt(obj);
}

static void matlabCodegenHandle__pfn2eia2mt(freedomk64f_fxos8700_AAIRVVIR_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AA_SystemCore_delete_pfn2eia2mt(obj);
  }
}

static void SystemCore_release_pfn2eia2mtl(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void A_SystemCore_delete_pfn2eia2mtl(b_freedomk64f_I2CMasterWrite__T *obj)
{
  SystemCore_release_pfn2eia2mtl(obj);
}

static void matlabCodegenHandle_pfn2eia2mtl(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    A_SystemCore_delete_pfn2eia2mtl(obj);
  }
}

static void AA_SystemCore_release_pfn2eia2m(dsp_simulink_MovingAverage_AA_T *obj)
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

static void AAI_SystemCore_delete_pfn2eia2m(dsp_simulink_MovingAverage_AA_T *obj)
{
  AA_SystemCore_release_pfn2eia2m(obj);
}

static void matlabCodegenHandle_m_pfn2eia2m(dsp_simulink_MovingAverage_AA_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    AAI_SystemCore_delete_pfn2eia2m(obj);
  }
}

static void AAIRVVIRWORK_SystemCore_setup_p(freedomk64f_SCIWrite_AAIRVVIR_T *obj)
{
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  AAIRVVIRWORK_B.RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, AAIRVVIRWORK_B.RxPinLoc,
    10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void AAIRVVIRWOR_SystemCore_setup_pf(freedomk64f_fxos8700_AAIRVVIR_T *obj)
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

static void AAIRVVIRWORK_SystemCore_setup(freedomk64f_SCIRead_AAIRVVIRW_T *obj)
{
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  AAIRVVIRWORK_B.TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U,
    AAIRVVIRWORK_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void AAIRVVIRWORK_step(void)
{
  uint32_T b_x;
  uint8_T status;
  int16_T b_output[3];
  uint8_T output_raw[6];
  uint8_T y[2];
  uint8_T b_x_0[2];
  boolean_T rtb_LED_STATE_f;
  uint32_T rtb_CastToSingle9;
  int32_T i;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  uint64m_T tmp;
  real32_T stepup_tmp;

  /* MATLABSystem: '<S1>/Serial Receive' */
  if (AAIRVVIRWORK_DW.obj_m.SampleTime !=
      AAIRVVIRWORK_P.SerialReceive_SampleTime) {
    AAIRVVIRWORK_DW.obj_m.SampleTime = AAIRVVIRWORK_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(AAIRVVIRWORK_DW.obj_m.MW_SCIHANDLE,
    AAIRVVIRWORK_B.RxDataLocChar, 99U);
  memcpy((void *)&AAIRVVIRWORK_B.TxDataLocChar[0], (void *)
         &AAIRVVIRWORK_B.RxDataLocChar[0], (uint32_T)((size_t)99 * sizeof
          (uint8_T)));

  /* Chart: '<S1>/Chart1' incorporates:
   *  MATLABSystem: '<S1>/Serial Receive'
   */
  if (AAIRVVIRWORK_DW.temporalCounter_i1_m < 1U) {
    AAIRVVIRWORK_DW.temporalCounter_i1_m++;
  }

  if (AAIRVVIRWORK_DW.is_active_c9_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c9_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Initial_State;
    AAIRVVIRWORK_B.Mode = 100U;
    AAIRVVIRWORK_B.upper_rate_limit = 175U;
    AAIRVVIRWORK_B.lower_rate_limit = 60U;
    AAIRVVIRWORK_B.atrial_amplitude = 3.75F;
    AAIRVVIRWORK_B.atrial_pulse_width = 0.4;
    AAIRVVIRWORK_B.ventricular_amplitude = 3.75F;
    AAIRVVIRWORK_B.ventricular_pulse_width = 1.0;
    AAIRVVIRWORK_B.a_r_p = 250U;
    AAIRVVIRWORK_B.p_v_a_r_p = 250U;
    AAIRVVIRWORK_B.h_r_l = 45U;
    AAIRVVIRWORK_B.r_s_up = 0.09;
    AAIRVVIRWORK_B.r_s_down = 0.09;
    AAIRVVIRWORK_B.ventricular_sensitivity = 2.5F;
    AAIRVVIRWORK_B.atrial_sensitivity = 2.75F;
    AAIRVVIRWORK_B.v_r_p = 320U;
    AAIRVVIRWORK_B.hysterisis_flag = 0U;
    AAIRVVIRWORK_B.activity_threshold = 2U;
    AAIRVVIRWORK_B.ReactionTime = 10U;
    AAIRVVIRWORK_B.ResponseFactor = 6U;
    AAIRVVIRWORK_B.RecoveryTime = 2U;
    AAIRVVIRWORK_B.MSR = 120U;
  } else {
    switch (AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK) {
     case AAIRVVIRWORK_IN_Echo:
      AAIRVVIRWORK_B.MSG_ident = 2U;
      AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby;
      AAIRVVIRWORK_B.MSG_trigger = 0U;
      break;

     case AAIRVVIRWORK_IN_Egram_Update:
      AAIRVVIRWORK_B.MSG_ident = 0U;
      AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby;
      AAIRVVIRWORK_B.MSG_trigger = 0U;
      break;

     case AAIRV_IN_HandshakeRequestEnable:
      AAIRVVIRWORK_B.MSG_trigger = 1U;
      AAIRVVIRWORK_B.MSG_ident = 1U;
      if (AAIRVVIRWORK_DW.temporalCounter_i1_m >= 1U) {
        AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby;
        AAIRVVIRWORK_B.MSG_trigger = 0U;
      }
      break;

     case AAIRVVIRWORK_IN_Initial_State:
      AAIRVVIRWORK_B.ventricular_sensitivity = 2.5F;
      AAIRVVIRWORK_B.atrial_sensitivity = 2.75F;
      AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby;
      AAIRVVIRWORK_B.MSG_trigger = 0U;
      break;

     case AAIRVVIRWORK_IN_Read_Data:
      if (AAIRVVIRWORK_DW.temporalCounter_i1_m >= 1U) {
        AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Safety_Check;
        AAIRVVIRWORK_DW.safety_flag = true;
        if (AAIRVVIRWORK_DW.safety_flag) {
          AAIRVVIRWORK_DW.safety_flag = (((uint32_T)(50U <=
            AAIRVVIRWORK_DW.lower_rate_limit_U) <=
            AAIRVVIRWORK_B.upper_rate_limit) && AAIRVVIRWORK_DW.safety_flag);
          AAIRVVIRWORK_DW.safety_flag = (((AAIRVVIRWORK_DW.Mode_U == 100U) ||
            (AAIRVVIRWORK_DW.Mode_U == 200U) || (AAIRVVIRWORK_DW.Mode_U == 112U)
            || (AAIRVVIRWORK_DW.Mode_U == 222U) || (AAIRVVIRWORK_DW.Mode_U ==
            1000U) || (AAIRVVIRWORK_DW.Mode_U == 1120U) ||
            (AAIRVVIRWORK_DW.Mode_U == 2000U) || (AAIRVVIRWORK_DW.Mode_U ==
            2220U) || (AAIRVVIRWORK_DW.Mode_U == 3330U)) &&
            AAIRVVIRWORK_DW.safety_flag);
          AAIRVVIRWORK_DW.safety_flag = (((AAIRVVIRWORK_DW.Mode_U != 100U) ||
            (AAIRVVIRWORK_DW.lower_rate_limit_U != 60U) ||
            (!(AAIRVVIRWORK_DW.atrial_pulse_width_U == 0.4)) ||
            (AAIRVVIRWORK_DW.a_r_p_U != 250U)) && AAIRVVIRWORK_DW.safety_flag);
        }
      }
      break;

     case AAIRVVIRWORK_IN_Safety_Check:
      if (!AAIRVVIRWORK_DW.safety_flag) {
        AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIR_IN_setToZeroForTesting;
      } else {
        AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Write_Data;
        AAIRVVIRWORK_B.Mode = AAIRVVIRWORK_DW.Mode_U;
        AAIRVVIRWORK_B.upper_rate_limit = AAIRVVIRWORK_DW.upper_rate_limit_U;
        AAIRVVIRWORK_B.lower_rate_limit = AAIRVVIRWORK_DW.lower_rate_limit_U;
        AAIRVVIRWORK_B.atrial_amplitude = AAIRVVIRWORK_DW.atrial_amplitude_U;
        AAIRVVIRWORK_B.atrial_pulse_width = AAIRVVIRWORK_DW.atrial_pulse_width_U;
        AAIRVVIRWORK_B.ventricular_amplitude =
          AAIRVVIRWORK_DW.ventricular_amplitude_U;
        AAIRVVIRWORK_B.ventricular_pulse_width =
          AAIRVVIRWORK_DW.ventricular_pulse_width_U;
        AAIRVVIRWORK_B.a_r_p = AAIRVVIRWORK_DW.a_r_p_U;
        AAIRVVIRWORK_B.p_v_a_r_p = AAIRVVIRWORK_DW.p_v_a_r_p_U;
        AAIRVVIRWORK_B.h_r_l = AAIRVVIRWORK_DW.h_r_l_U;
        AAIRVVIRWORK_B.r_s_up = AAIRVVIRWORK_DW.r_s_up_U;
        AAIRVVIRWORK_B.r_s_down = AAIRVVIRWORK_DW.r_s_down_U;
        AAIRVVIRWORK_B.ventricular_sensitivity = 2.5F;
        AAIRVVIRWORK_B.atrial_sensitivity = 2.75F;
        AAIRVVIRWORK_B.v_r_p = AAIRVVIRWORK_DW.v_r_p_U;
        AAIRVVIRWORK_B.hysterisis_flag = AAIRVVIRWORK_DW.hysterisis_flag_U;
        AAIRVVIRWORK_B.activity_threshold = AAIRVVIRWORK_DW.activity_threshold_U;
        AAIRVVIRWORK_B.ReactionTime = AAIRVVIRWORK_DW.ReactionTime_U;
        AAIRVVIRWORK_B.ResponseFactor = AAIRVVIRWORK_DW.ResponseFactor_U;
        AAIRVVIRWORK_B.RecoveryTime = AAIRVVIRWORK_DW.RecoveryTime_U;
        AAIRVVIRWORK_B.MSR = AAIRVVIRWORK_DW.MSR_U;
      }
      break;

     case AAIRVVIRWORK_IN_Standby:
      AAIRVVIRWORK_B.MSG_trigger = 0U;
      if ((status == 0) && (AAIRVVIRWORK_B.TxDataLocChar[0] == 22)) {
        switch (AAIRVVIRWORK_B.TxDataLocChar[1]) {
         case 85:
          AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Read_Data;
          AAIRVVIRWORK_DW.temporalCounter_i1_m = 0U;
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[2], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.Mode_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[6], (uint32_T)((size_t)1 * sizeof
                  (uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.upper_rate_limit_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[10], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.lower_rate_limit_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[38], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.a_r_p_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[42], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.p_v_a_r_p_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[46], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.h_r_l_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[74], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.v_r_p_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[78], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.activity_threshold_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[82], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.ReactionTime_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[86], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.ResponseFactor_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[90], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.RecoveryTime_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_u32_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[94], (uint32_T)((size_t)1 *
                  sizeof(uint32_T)));
          AAIRVVIRWORK_DW.tmp_u32_sizes = 1;
          AAIRVVIRWORK_DW.MSR_U = AAIRVVIRWORK_DW.tmp_u32_data[0];
          AAIRVVIRWORK_DW.hysterisis_flag_U = AAIRVVIRWORK_B.TxDataLocChar[98];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_single_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[14], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          AAIRVVIRWORK_DW.tmp_single_sizes = 1;
          AAIRVVIRWORK_DW.atrial_amplitude_U = AAIRVVIRWORK_DW.tmp_single_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_single_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[26], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          AAIRVVIRWORK_DW.tmp_single_sizes = 1;
          AAIRVVIRWORK_DW.ventricular_amplitude_U =
            AAIRVVIRWORK_DW.tmp_single_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_single_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[66], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          AAIRVVIRWORK_DW.tmp_single_sizes = 1;
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_single_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[70], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          AAIRVVIRWORK_DW.tmp_single_sizes = 1;
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_double_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[18], (uint32_T)((size_t)1 *
                  sizeof(real_T)));
          AAIRVVIRWORK_DW.tmp_double_sizes = 1;
          AAIRVVIRWORK_DW.atrial_pulse_width_U =
            AAIRVVIRWORK_DW.tmp_double_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_double_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[30], (uint32_T)((size_t)1 *
                  sizeof(real_T)));
          AAIRVVIRWORK_DW.tmp_double_sizes = 1;
          AAIRVVIRWORK_DW.ventricular_pulse_width_U =
            AAIRVVIRWORK_DW.tmp_double_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_double_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[50], (uint32_T)((size_t)1 *
                  sizeof(real_T)));
          AAIRVVIRWORK_DW.tmp_double_sizes = 1;
          AAIRVVIRWORK_DW.r_s_up_U = AAIRVVIRWORK_DW.tmp_double_data[0];
          memcpy((void *)&AAIRVVIRWORK_DW.tmp_double_data[0], (void *)
                 &AAIRVVIRWORK_B.TxDataLocChar[58], (uint32_T)((size_t)1 *
                  sizeof(real_T)));
          AAIRVVIRWORK_DW.tmp_double_sizes = 1;
          AAIRVVIRWORK_DW.r_s_down_U = AAIRVVIRWORK_DW.tmp_double_data[0];
          break;

         case 69:
          AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRV_IN_HandshakeRequestEnable;
          AAIRVVIRWORK_DW.temporalCounter_i1_m = 0U;
          AAIRVVIRWORK_B.MSG_trigger = 1U;
          AAIRVVIRWORK_B.MSG_ident = 1U;
          break;

         case 54:
          AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Egram_Update;
          AAIRVVIRWORK_B.MSG_trigger = 1U;
          AAIRVVIRWORK_B.MSG_ident = 0U;
          break;

         case 96:
          AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_par_load;
          AAIRVVIRWORK_B.MSG_trigger = 1U;
          AAIRVVIRWORK_B.MSG_ident = 3U;
          break;
        }
      }
      break;

     case AAIRVVIRWORK_IN_Write_Data:
      AAIRVVIRWORK_B.ventricular_sensitivity = 2.5F;
      AAIRVVIRWORK_B.atrial_sensitivity = 2.75F;
      AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Echo;
      AAIRVVIRWORK_B.MSG_trigger = 1U;
      AAIRVVIRWORK_B.MSG_ident = 2U;
      break;

     case AAIRVVIRWORK_IN_par_load:
      AAIRVVIRWORK_B.MSG_ident = 3U;
      AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby;
      AAIRVVIRWORK_B.MSG_trigger = 0U;
      break;

     default:
      /* case IN_setToZeroForTesting: */
      AAIRVVIRWORK_DW.is_c9_AAIRVVIRWORK = AAIRVVIRWORK_IN_Echo;
      AAIRVVIRWORK_B.MSG_trigger = 1U;
      AAIRVVIRWORK_B.MSG_ident = 2U;
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
  AAIRVVIRWORK_B.MathFunction1 = 1.0F / ((real32_T)
    AAIRVVIRWORK_B.lower_rate_limit / 60000.0F);

  /* MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  if (AAIRVVIRWORK_DW.obj_i.SampleTime !=
      AAIRVVIRWORK_P.ATR_CMP_DETECT_SampleTime) {
    AAIRVVIRWORK_DW.obj_i.SampleTime = AAIRVVIRWORK_P.ATR_CMP_DETECT_SampleTime;
  }

  AAIRVVIRWORK_B.ATR_CMP_DETECT = MW_digitalIO_read
    (AAIRVVIRWORK_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  if (AAIRVVIRWORK_DW.obj_ci.SampleTime !=
      AAIRVVIRWORK_P.VENT_CMP_DETECT_SampleTime) {
    AAIRVVIRWORK_DW.obj_ci.SampleTime =
      AAIRVVIRWORK_P.VENT_CMP_DETECT_SampleTime;
  }

  AAIRVVIRWORK_B.VENT_CMP_DETECT = MW_digitalIO_read
    (AAIRVVIRWORK_DW.obj_ci.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/VENT_CMP_DETECT' */

  /* Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */
  if (AAIRVVIRWORK_DW.temporalCounter_i1_l < MAX_uint32_T) {
    AAIRVVIRWORK_DW.temporalCounter_i1_l++;
  }

  if (AAIRVVIRWORK_DW.is_active_c5_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c5_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_m;
  } else {
    switch (AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK) {
     case AAIRVVIR_IN_AtrialRateDetection:
      AAIRVVIRWOR_AtrialRateDetection();
      break;

     case AAIRVVI_IN_AtrialRateDetection1:
      AAIRVVIRWO_AtrialRateDetection1();
      break;

     case AAIRVVIRWORK_IN_UnsensedModes:
      if ((AAIRVVIRWORK_B.Mode != 100U) && (AAIRVVIRWORK_B.Mode != 200U)) {
        AAIRVVIRWORK_B.HR_Ready = false;
        AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_m;
      }
      break;

     case AAIR_IN_VenticularRateDetection:
      if (AAIRVVIRWORK_B.Mode != 222U) {
        AAIRVVIRWORK_DW.is_VenticularRateDetection =
          AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
        AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_m;
      } else {
        switch (AAIRVVIRWORK_DW.is_VenticularRateDetection) {
         case AAIRVVIRWORK_IN_awaitNewPulse:
          if (!AAIRVVIRWORK_B.VENT_CMP_DETECT) {
            AAIRVVIRWORK_DW.is_VenticularRateDetection =
              AAIRVVIRWORK_IN_awaitNewPulse;
            rtb_CastToSingle9 = AAIRVVIRWORK_B.time_between_pulses +
              /*MW:OvSatOk*/ 1U;
            if (rtb_CastToSingle9 < AAIRVVIRWORK_B.time_between_pulses) {
              rtb_CastToSingle9 = MAX_uint32_T;
            }

            AAIRVVIRWORK_B.time_between_pulses = rtb_CastToSingle9;
          } else {
            AAIRVVIRWORK_DW.is_VenticularRateDetection =
              AAIRVVIRWOR_IN_newPulseDetected;
            AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
            AAIRVVIRWORK_B.pulse_finished = true;
            AAIRVVIRWORK_B.HR_Ready = true;
          }
          break;

         case AAIRVVIRWORK_IN_default_mk:
          AAIRVVIRWORK_B.pulse_finished = false;
          if (AAIRVVIRWORK_B.VENT_CMP_DETECT) {
            AAIRVVIRWORK_DW.is_VenticularRateDetection =
              AAIRVVIRWORK_IN_setVRPasDeltaT;
            AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
            AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.v_r_p;
          }
          break;

         case AAIRVVIRWOR_IN_newPulseDetected:
          AAIRVVIRWORK_B.pulse_finished = true;
          if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= 1U) {
            AAIRVVIRWORK_DW.is_VenticularRateDetection =
              AAIRVVIRWORK_IN_resetDeltaT;
            AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
            AAIRVVIRWORK_B.pulse_finished = false;
            AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.v_r_p;
          }
          break;

         case AAIRVVIRWORK_IN_resetDeltaT:
          AAIRVVIRWORK_B.pulse_finished = false;
          rtb_CastToSingle9 = AAIRVVIRWORK_B.v_r_p - /*MW:OvSatOk*/ 1U;
          if (rtb_CastToSingle9 > AAIRVVIRWORK_B.v_r_p) {
            rtb_CastToSingle9 = 0U;
          }

          if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= rtb_CastToSingle9) {
            if (!AAIRVVIRWORK_B.VENT_CMP_DETECT) {
              AAIRVVIRWORK_DW.is_VenticularRateDetection =
                AAIRVVIRWORK_IN_awaitNewPulse;
              rtb_CastToSingle9 = AAIRVVIRWORK_B.time_between_pulses +
                /*MW:OvSatOk*/ 1U;
              if (rtb_CastToSingle9 < AAIRVVIRWORK_B.time_between_pulses) {
                rtb_CastToSingle9 = MAX_uint32_T;
              }

              AAIRVVIRWORK_B.time_between_pulses = rtb_CastToSingle9;
            } else {
              AAIRVVIRWORK_DW.is_VenticularRateDetection =
                AAIRVVIRWOR_IN_newPulseDetected;
              AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
              AAIRVVIRWORK_B.pulse_finished = true;
              AAIRVVIRWORK_B.HR_Ready = true;
            }
          }
          break;

         default:
          /* case IN_setVRPasDeltaT: */
          if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= AAIRVVIRWORK_B.v_r_p) {
            if (!AAIRVVIRWORK_B.VENT_CMP_DETECT) {
              AAIRVVIRWORK_DW.is_VenticularRateDetection =
                AAIRVVIRWORK_IN_awaitNewPulse;
              rtb_CastToSingle9 = AAIRVVIRWORK_B.time_between_pulses +
                /*MW:OvSatOk*/ 1U;
              if (rtb_CastToSingle9 < AAIRVVIRWORK_B.time_between_pulses) {
                rtb_CastToSingle9 = MAX_uint32_T;
              }

              AAIRVVIRWORK_B.time_between_pulses = rtb_CastToSingle9;
            } else {
              AAIRVVIRWORK_DW.is_VenticularRateDetection =
                AAIRVVIRWOR_IN_newPulseDetected;
              AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
              AAIRVVIRWORK_B.pulse_finished = true;
              AAIRVVIRWORK_B.HR_Ready = true;
            }
          }
          break;
        }
      }
      break;

     case AAI_IN_VenticularRateDetection1:
      if (AAIRVVIRWORK_B.Mode != 2220U) {
        AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
          AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
        AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_m;
      } else {
        switch (AAIRVVIRWORK_DW.is_VenticularRateDetection1) {
         case AAIRVVIRWORK_IN_awaitNewPulse:
          if (!AAIRVVIRWORK_B.VENT_CMP_DETECT) {
            AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
              AAIRVVIRWORK_IN_awaitNewPulse;
            rtb_CastToSingle9 = AAIRVVIRWORK_B.time_between_pulses +
              /*MW:OvSatOk*/ 1U;
            if (rtb_CastToSingle9 < AAIRVVIRWORK_B.time_between_pulses) {
              rtb_CastToSingle9 = MAX_uint32_T;
            }

            AAIRVVIRWORK_B.time_between_pulses = rtb_CastToSingle9;
          } else {
            AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
              AAIRVVIRWOR_IN_newPulseDetected;
            AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
            AAIRVVIRWORK_B.pulse_finished = true;
            AAIRVVIRWORK_B.HR_Ready = true;
          }
          break;

         case AAIRVVIRWORK_IN_default_mk:
          AAIRVVIRWORK_B.pulse_finished = false;
          if (AAIRVVIRWORK_B.VENT_CMP_DETECT) {
            AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
              AAIRVVIRWORK_IN_setVRPasDeltaT;
            AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
            AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.v_r_p;
          }
          break;

         case AAIRVVIRWOR_IN_newPulseDetected:
          AAIRVVIRWORK_B.pulse_finished = true;
          if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= 1U) {
            AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
              AAIRVVIRWORK_IN_resetDeltaT;
            AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
            AAIRVVIRWORK_B.pulse_finished = false;
            AAIRVVIRWORK_B.time_between_pulses = AAIRVVIRWORK_B.v_r_p;
          }
          break;

         case AAIRVVIRWORK_IN_resetDeltaT:
          AAIRVVIRWORK_B.pulse_finished = false;
          rtb_CastToSingle9 = AAIRVVIRWORK_B.v_r_p - /*MW:OvSatOk*/ 1U;
          if (rtb_CastToSingle9 > AAIRVVIRWORK_B.v_r_p) {
            rtb_CastToSingle9 = 0U;
          }

          if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= rtb_CastToSingle9) {
            if (!AAIRVVIRWORK_B.VENT_CMP_DETECT) {
              AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
                AAIRVVIRWORK_IN_awaitNewPulse;
              rtb_CastToSingle9 = AAIRVVIRWORK_B.time_between_pulses +
                /*MW:OvSatOk*/ 1U;
              if (rtb_CastToSingle9 < AAIRVVIRWORK_B.time_between_pulses) {
                rtb_CastToSingle9 = MAX_uint32_T;
              }

              AAIRVVIRWORK_B.time_between_pulses = rtb_CastToSingle9;
            } else {
              AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
                AAIRVVIRWOR_IN_newPulseDetected;
              AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
              AAIRVVIRWORK_B.pulse_finished = true;
              AAIRVVIRWORK_B.HR_Ready = true;
            }
          }
          break;

         default:
          /* case IN_setVRPasDeltaT: */
          if (AAIRVVIRWORK_DW.temporalCounter_i1_l >= AAIRVVIRWORK_B.v_r_p) {
            if (!AAIRVVIRWORK_B.VENT_CMP_DETECT) {
              AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
                AAIRVVIRWORK_IN_awaitNewPulse;
              rtb_CastToSingle9 = AAIRVVIRWORK_B.time_between_pulses +
                /*MW:OvSatOk*/ 1U;
              if (rtb_CastToSingle9 < AAIRVVIRWORK_B.time_between_pulses) {
                rtb_CastToSingle9 = MAX_uint32_T;
              }

              AAIRVVIRWORK_B.time_between_pulses = rtb_CastToSingle9;
            } else {
              AAIRVVIRWORK_DW.is_VenticularRateDetection1 =
                AAIRVVIRWOR_IN_newPulseDetected;
              AAIRVVIRWORK_DW.temporalCounter_i1_l = 0U;
              AAIRVVIRWORK_B.pulse_finished = true;
              AAIRVVIRWORK_B.HR_Ready = true;
            }
          }
          break;
        }
      }
      break;

     default:
      /* case IN_default: */
      switch (AAIRVVIRWORK_B.Mode) {
       case 112U:
        AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIR_IN_AtrialRateDetection;
        AAIRVVIRWORK_DW.is_AtrialRateDetection = AAIRVVIRWORK_IN_default_mk;
        AAIRVVIRWORK_B.pulse_finished = false;
        AAIRVVIRWORK_B.time_between_pulses = 0U;
        break;

       case 2220U:
        AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAI_IN_VenticularRateDetection1;
        AAIRVVIRWORK_DW.is_VenticularRateDetection1 = AAIRVVIRWORK_IN_default_mk;
        AAIRVVIRWORK_B.pulse_finished = false;
        AAIRVVIRWORK_B.time_between_pulses = 0U;
        break;

       case 1120U:
        AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVI_IN_AtrialRateDetection1;
        AAIRVVIRWORK_DW.is_AtrialRateDetection1 = AAIRVVIRWORK_IN_default_mk;
        AAIRVVIRWORK_B.pulse_finished = false;
        AAIRVVIRWORK_B.time_between_pulses = 0U;
        break;

       default:
        if ((AAIRVVIRWORK_B.Mode == 100U) || (AAIRVVIRWORK_B.Mode == 200U)) {
          AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIRVVIRWORK_IN_UnsensedModes;
          AAIRVVIRWORK_B.HR_Ready = true;
        } else {
          if (AAIRVVIRWORK_B.Mode == 222U) {
            AAIRVVIRWORK_DW.is_c5_AAIRVVIRWORK = AAIR_IN_VenticularRateDetection;
            AAIRVVIRWORK_DW.is_VenticularRateDetection =
              AAIRVVIRWORK_IN_default_mk;
            AAIRVVIRWORK_B.pulse_finished = false;
            AAIRVVIRWORK_B.time_between_pulses = 0U;
          }
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/1.1.2.1 PulsePeriodDetermination' */

  /* Switch: '<S13>/Switch9' incorporates:
   *  Delay: '<S13>/Delay7'
   */
  if (AAIRVVIRWORK_B.pulse_finished) {
    AAIRVVIRWORK_DW.Delay7_DSTATE = AAIRVVIRWORK_B.time_between_pulses;
  }

  /* End of Switch: '<S13>/Switch9' */

  /* Gain: '<S13>/Gain4' incorporates:
   *  DataTypeConversion: '<S13>/Cast To Double'
   *  Delay: '<S13>/Delay7'
   *  Fcn: '<S13>/Fcn3'
   */
  AAIRVVIRWORK_B.Gain4 = 1.0 / (real_T)AAIRVVIRWORK_DW.Delay7_DSTATE *
    AAIRVVIRWORK_P.Gain4_Gain;

  /* Memory: '<S1>/Memory' */
  AAIRVVIRWORK_B.Memory = AAIRVVIRWORK_DW.Memory_PreviousInput;

  /* Sum: '<S18>/Sum' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   *  DataTypeConversion: '<S18>/Cast'
   *  Product: '<S18>/Product'
   */
  AAIRVVIRWORK_B.Add = (real32_T)AAIRVVIRWORK_B.activity_threshold *
    AAIRVVIRWORK_P.Constant_Value + AAIRVVIRWORK_P.Constant1_Value;

  /* Chart: '<S2>/Chart' incorporates:
   *  DataTypeConversion: '<S2>/Cast To Single'
   *  DataTypeConversion: '<S2>/Cast To Single1'
   *  DataTypeConversion: '<S2>/Cast To Single2'
   *  DataTypeConversion: '<S2>/Cast To Single3'
   *  DataTypeConversion: '<S2>/Cast To Single4'
   *  DataTypeConversion: '<S2>/Cast To Single7'
   *  DataTypeConversion: '<S2>/Cast To Single8'
   */
  if (AAIRVVIRWORK_DW.temporalCounter_i1_lr < 1023U) {
    AAIRVVIRWORK_DW.temporalCounter_i1_lr++;
  }

  if (AAIRVVIRWORK_DW.is_active_c10_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c10_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_start;
    AAIRVVIRWORK_B.DesiredRate = (real32_T)AAIRVVIRWORK_B.lower_rate_limit;
    AAIRVVIRWORK_B.CR = (real32_T)AAIRVVIRWORK_B.lower_rate_limit;
  } else {
    switch (AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK) {
     case AAIRVVIRWORK_IN_STEPUP:
      if (AAIRVVIRWORK_DW.temporalCounter_i1_lr >= 1000U) {
        AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_STEPUP;
        AAIRVVIRWORK_DW.temporalCounter_i1_lr = 0U;
        AAIRVVIRWORK_B.CR += AAIRVVIRWORK_B.stepup;
      } else {
        if (AAIRVVIRWORK_B.CR >= AAIRVVIRWORK_B.DesiredRate) {
          AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_overThreshold;
          AAIRVVIRWORK_B.flag = 1U;
          AAIRVVIRWORK_B.CR = AAIRVVIRWORK_B.DesiredRate;
        }
      }
      break;

     case AAIRVVIRWORK_IN_default_mk:
      AAIRVVIRWORK_B.flag = 0U;
      if ((real32_T)AAIRVVIRWORK_B.Memory >= (real32_T)AAIRVVIRWORK_B.Add) {
        AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_overThreshold;
        AAIRVVIRWORK_B.flag = 1U;
        AAIRVVIRWORK_B.CR = AAIRVVIRWORK_B.DesiredRate;
      } else {
        AAIRVVIRWORK_B.DesiredRate = (real32_T)AAIRVVIRWORK_B.lower_rate_limit;
        AAIRVVIRWORK_B.CR = (real32_T)AAIRVVIRWORK_B.lower_rate_limit;
        stepup_tmp = (real32_T)AAIRVVIRWORK_B.MSR - (real32_T)
          AAIRVVIRWORK_B.lower_rate_limit;
        AAIRVVIRWORK_B.stepup = stepup_tmp / (real32_T)
          AAIRVVIRWORK_B.ReactionTime;
        AAIRVVIRWORK_DW.stepdown = stepup_tmp / ((real32_T)
          AAIRVVIRWORK_B.RecoveryTime * 60.0F);
      }
      break;

     case AAIRVVIRWORK_IN_overThreshold:
      AAIRVVIRWORK_B.flag = 1U;
      if ((real32_T)AAIRVVIRWORK_B.Memory < (real32_T)AAIRVVIRWORK_B.Add) {
        AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_stepdown;
        AAIRVVIRWORK_DW.temporalCounter_i1_lr = 0U;
        AAIRVVIRWORK_B.CR -= AAIRVVIRWORK_DW.stepdown;
        AAIRVVIRWORK_B.flag = 0U;
      } else if (AAIRVVIRWORK_B.CR < AAIRVVIRWORK_B.DesiredRate) {
        AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_STEPUP;
        AAIRVVIRWORK_DW.temporalCounter_i1_lr = 0U;
        AAIRVVIRWORK_B.CR += AAIRVVIRWORK_B.stepup;
      } else {
        AAIRVVIRWORK_B.DesiredRate = (1.0F - rt_powf_snf(2.718F, (4.0F *
          (real32_T)AAIRVVIRWORK_B.Memory - (real32_T)AAIRVVIRWORK_B.Add) *
          -(real32_T)AAIRVVIRWORK_B.ResponseFactor)) * ((real32_T)
          AAIRVVIRWORK_B.MSR - (real32_T)AAIRVVIRWORK_B.lower_rate_limit) +
          (real32_T)AAIRVVIRWORK_B.lower_rate_limit;
      }
      break;

     case AAIRVVIRWORK_IN_start:
      AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_mk;
      AAIRVVIRWORK_B.flag = 0U;
      break;

     default:
      /* case IN_stepdown: */
      AAIRVVIRWORK_B.flag = 0U;
      if (AAIRVVIRWORK_DW.temporalCounter_i1_lr >= 1000U) {
        AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_stepdown;
        AAIRVVIRWORK_DW.temporalCounter_i1_lr = 0U;
        AAIRVVIRWORK_B.CR -= AAIRVVIRWORK_DW.stepdown;
        AAIRVVIRWORK_B.flag = 0U;
      } else {
        if (AAIRVVIRWORK_B.CR <= AAIRVVIRWORK_B.lower_rate_limit) {
          AAIRVVIRWORK_DW.is_c10_AAIRVVIRWORK = AAIRVVIRWORK_IN_default_mk;
          AAIRVVIRWORK_B.flag = 0U;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* DataTypeConversion: '<S2>/Cast To Single9' */
  stepup_tmp = (real32_T)floor(AAIRVVIRWORK_B.CR);
  if (rtIsNaNF(stepup_tmp) || rtIsInfF(stepup_tmp)) {
    stepup_tmp = 0.0F;
  } else {
    stepup_tmp = (real32_T)fmod(stepup_tmp, 4.294967296E+9);
  }

  rtb_CastToSingle9 = stepup_tmp < 0.0F ? (uint32_T)-(int32_T)(uint32_T)
    -stepup_tmp : (uint32_T)stepup_tmp;

  /* End of DataTypeConversion: '<S2>/Cast To Single9' */

  /* Chart: '<S2>/1.1.2.3 WatchdogTimerForPulseDetection' */
  if (AAIRVVIRWORK_DW.is_active_c1_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c1_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIR_IN_HysterisisSelection;
    AAIRVVIRWORK_DW.time_minute = 60000U;
    AAIRVVIRWORK_DW.smoothing_rate = (1.0 - AAIRVVIRWORK_B.r_s_down) *
      AAIRVVIRWORK_B.Gain4;
  } else {
    switch (AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK) {
     case AAIRVVIRWORK_IN_AAI:
      if (AAIRVVIRWORK_B.Mode != 112U) {
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIR_IN_HysterisisSelection;
        AAIRVVIRWORK_DW.time_minute = 60000U;
        AAIRVVIRWORK_DW.smoothing_rate = (1.0 - AAIRVVIRWORK_B.r_s_down) *
          AAIRVVIRWORK_B.Gain4;
      }
      break;

     case AAIRVVIRWORK_IN_AAIR:
      if (AAIRVVIRWORK_B.Mode != 1120U) {
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIR_IN_HysterisisSelection;
        AAIRVVIRWORK_DW.time_minute = 60000U;
        AAIRVVIRWORK_DW.smoothing_rate = (1.0 - AAIRVVIRWORK_B.r_s_down) *
          AAIRVVIRWORK_B.Gain4;
      } else {
        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)AAIRVVIRWORK_B.a_r_p +
          AAIRVVIRWORK_B.atrial_pulse_width);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        AAIRVVIRWORK_B.total_AAIR_rate_time = AAIRVVIRWORK_DW.time_minute -
          /*MW:OvSatOk*/ mul_u32_sat(b_x, rtb_CastToSingle9);
        if (AAIRVVIRWORK_B.total_AAIR_rate_time > AAIRVVIRWORK_DW.time_minute) {
          AAIRVVIRWORK_B.total_AAIR_rate_time = 0U;
        }

        if (rtb_CastToSingle9 == 0U) {
          if (AAIRVVIRWORK_B.total_AAIR_rate_time == 0U) {
            AAIRVVIRWORK_B.wait_time_AAIR = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_AAIR = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_AAIR = AAIRVVIRWORK_B.total_AAIR_rate_time /
            rtb_CastToSingle9;
          b_x = AAIRVVIRWORK_B.total_AAIR_rate_time -
            AAIRVVIRWORK_B.wait_time_AAIR * rtb_CastToSingle9;
          if ((b_x > 0U) && (b_x >= (rtb_CastToSingle9 >> 1U) +
                             (rtb_CastToSingle9 & 1U))) {
            AAIRVVIRWORK_B.wait_time_AAIR++;
          }
        }

        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/
          mul_u32_sat(b_x, AAIRVVIRWORK_B.lower_rate_limit);
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        if (AAIRVVIRWORK_B.lower_rate_limit == 0U) {
          if (rtb_CastToSingle9 == 0U) {
            AAIRVVIRWORK_B.wait_time_LRL = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_LRL = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_LRL = AAIRVVIRWORK_B.lower_rate_limit == 0U ?
            MAX_uint32_T : rtb_CastToSingle9 / AAIRVVIRWORK_B.lower_rate_limit;
          rtb_CastToSingle9 -= AAIRVVIRWORK_B.wait_time_LRL *
            AAIRVVIRWORK_B.lower_rate_limit;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AAIRVVIRWORK_B.lower_rate_limit >> 1U) +
               (AAIRVVIRWORK_B.lower_rate_limit & 1U))) {
            AAIRVVIRWORK_B.wait_time_LRL++;
          }
        }

        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/
          mul_u32_sat(b_x, AAIRVVIRWORK_B.h_r_l);
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        if (AAIRVVIRWORK_B.h_r_l == 0U) {
          if (rtb_CastToSingle9 == 0U) {
            AAIRVVIRWORK_B.wait_time_LRL_hys = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_LRL_hys = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_LRL_hys = AAIRVVIRWORK_B.h_r_l == 0U ?
            MAX_uint32_T : rtb_CastToSingle9 / AAIRVVIRWORK_B.h_r_l;
          rtb_CastToSingle9 -= AAIRVVIRWORK_B.wait_time_LRL_hys *
            AAIRVVIRWORK_B.h_r_l;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AAIRVVIRWORK_B.h_r_l >> 1U) + (AAIRVVIRWORK_B.h_r_l & 1U))) {
            AAIRVVIRWORK_B.wait_time_LRL_hys++;
          }
        }
      }
      break;

     case AAIRVVIR_IN_HysterisisSelection:
      switch (AAIRVVIRWORK_B.Mode) {
       case 112U:
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIRWORK_IN_AAI;
        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)AAIRVVIRWORK_B.a_r_p +
          AAIRVVIRWORK_B.atrial_pulse_width);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)b_x *
          AAIRVVIRWORK_DW.smoothing_rate);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/ b_x;
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)rtb_CastToSingle9 /
          AAIRVVIRWORK_DW.smoothing_rate);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            AAIRVVIRWORK_B.wait_time = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            AAIRVVIRWORK_B.wait_time = 0U;
          }
        } else {
          AAIRVVIRWORK_B.wait_time = MAX_uint32_T;
        }

        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)AAIRVVIRWORK_B.a_r_p +
          AAIRVVIRWORK_B.atrial_pulse_width);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/
          mul_u32_sat(b_x, AAIRVVIRWORK_B.lower_rate_limit);
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        if (AAIRVVIRWORK_B.lower_rate_limit == 0U) {
          if (rtb_CastToSingle9 == 0U) {
            AAIRVVIRWORK_B.wait_time_LRL = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_LRL = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_LRL = AAIRVVIRWORK_B.lower_rate_limit == 0U ?
            MAX_uint32_T : rtb_CastToSingle9 / AAIRVVIRWORK_B.lower_rate_limit;
          rtb_CastToSingle9 -= AAIRVVIRWORK_B.wait_time_LRL *
            AAIRVVIRWORK_B.lower_rate_limit;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AAIRVVIRWORK_B.lower_rate_limit >> 1U) +
               (AAIRVVIRWORK_B.lower_rate_limit & 1U))) {
            AAIRVVIRWORK_B.wait_time_LRL++;
          }
        }

        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)AAIRVVIRWORK_B.a_r_p +
          AAIRVVIRWORK_B.atrial_pulse_width);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/
          mul_u32_sat(b_x, AAIRVVIRWORK_B.h_r_l);
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        if (AAIRVVIRWORK_B.h_r_l == 0U) {
          if (rtb_CastToSingle9 == 0U) {
            AAIRVVIRWORK_B.wait_time_LRL_hys = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_LRL_hys = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_LRL_hys = AAIRVVIRWORK_B.h_r_l == 0U ?
            MAX_uint32_T : rtb_CastToSingle9 / AAIRVVIRWORK_B.h_r_l;
          rtb_CastToSingle9 -= AAIRVVIRWORK_B.wait_time_LRL_hys *
            AAIRVVIRWORK_B.h_r_l;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AAIRVVIRWORK_B.h_r_l >> 1U) + (AAIRVVIRWORK_B.h_r_l & 1U))) {
            AAIRVVIRWORK_B.wait_time_LRL_hys++;
          }
        }
        break;

       case 222U:
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIRWORK_IN_VVI;
        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)AAIRVVIRWORK_B.v_r_p +
          AAIRVVIRWORK_B.ventricular_pulse_width);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)b_x
          * AAIRVVIRWORK_DW.smoothing_rate);
        if (AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/ b_x;
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 = rt_roundd_snf((real_T)
          rtb_CastToSingle9 / AAIRVVIRWORK_DW.smoothing_rate);
        if (AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 >= 0.0) {
            AAIRVVIRWORK_B.wait_time = (uint32_T)
              AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1;
          } else {
            AAIRVVIRWORK_B.wait_time = 0U;
          }
        } else {
          AAIRVVIRWORK_B.wait_time = MAX_uint32_T;
        }

        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/
          mul_u32_sat(b_x, AAIRVVIRWORK_B.lower_rate_limit);
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        if (AAIRVVIRWORK_B.lower_rate_limit == 0U) {
          if (rtb_CastToSingle9 == 0U) {
            AAIRVVIRWORK_B.wait_time_LRL = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_LRL = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_LRL = AAIRVVIRWORK_B.lower_rate_limit == 0U ?
            MAX_uint32_T : rtb_CastToSingle9 / AAIRVVIRWORK_B.lower_rate_limit;
          rtb_CastToSingle9 -= AAIRVVIRWORK_B.wait_time_LRL *
            AAIRVVIRWORK_B.lower_rate_limit;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AAIRVVIRWORK_B.lower_rate_limit >> 1U) +
               (AAIRVVIRWORK_B.lower_rate_limit & 1U))) {
            AAIRVVIRWORK_B.wait_time_LRL++;
          }
        }
        break;

       case 1120U:
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIRWORK_IN_AAIR;
        break;

       case 2220U:
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIRWORK_IN_VVIR;
        break;
      }
      break;

     case AAIRVVIRWORK_IN_VVI:
      if (AAIRVVIRWORK_B.Mode != 222U) {
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIR_IN_HysterisisSelection;
        AAIRVVIRWORK_DW.time_minute = 60000U;
        AAIRVVIRWORK_DW.smoothing_rate = (1.0 - AAIRVVIRWORK_B.r_s_down) *
          AAIRVVIRWORK_B.Gain4;
      }
      break;

     default:
      /* case IN_VVIR: */
      if (AAIRVVIRWORK_B.Mode != 2220U) {
        AAIRVVIRWORK_DW.is_c1_AAIRVVIRWORK = AAIRVVIR_IN_HysterisisSelection;
        AAIRVVIRWORK_DW.time_minute = 60000U;
        AAIRVVIRWORK_DW.smoothing_rate = (1.0 - AAIRVVIRWORK_B.r_s_down) *
          AAIRVVIRWORK_B.Gain4;
      } else {
        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)AAIRVVIRWORK_B.v_r_p +
          AAIRVVIRWORK_B.ventricular_pulse_width);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        AAIRVVIRWORK_B.total_AAIR_rate_time = AAIRVVIRWORK_DW.time_minute -
          /*MW:OvSatOk*/ mul_u32_sat(b_x, rtb_CastToSingle9);
        if (AAIRVVIRWORK_B.total_AAIR_rate_time > AAIRVVIRWORK_DW.time_minute) {
          AAIRVVIRWORK_B.total_AAIR_rate_time = 0U;
        }

        if (rtb_CastToSingle9 == 0U) {
          if (AAIRVVIRWORK_B.total_AAIR_rate_time == 0U) {
            AAIRVVIRWORK_B.wait_time_AAIR = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_AAIR = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_AAIR = AAIRVVIRWORK_B.total_AAIR_rate_time /
            rtb_CastToSingle9;
          b_x = AAIRVVIRWORK_B.total_AAIR_rate_time -
            AAIRVVIRWORK_B.wait_time_AAIR * rtb_CastToSingle9;
          if ((b_x > 0U) && (b_x >= (rtb_CastToSingle9 >> 1U) +
                             (rtb_CastToSingle9 & 1U))) {
            AAIRVVIRWORK_B.wait_time_AAIR++;
          }
        }

        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/
          mul_u32_sat(b_x, AAIRVVIRWORK_B.lower_rate_limit);
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        if (AAIRVVIRWORK_B.lower_rate_limit == 0U) {
          if (rtb_CastToSingle9 == 0U) {
            AAIRVVIRWORK_B.wait_time_LRL = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_LRL = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_LRL = AAIRVVIRWORK_B.lower_rate_limit == 0U ?
            MAX_uint32_T : rtb_CastToSingle9 / AAIRVVIRWORK_B.lower_rate_limit;
          rtb_CastToSingle9 -= AAIRVVIRWORK_B.wait_time_LRL *
            AAIRVVIRWORK_B.lower_rate_limit;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AAIRVVIRWORK_B.lower_rate_limit >> 1U) +
               (AAIRVVIRWORK_B.lower_rate_limit & 1U))) {
            AAIRVVIRWORK_B.wait_time_LRL++;
          }
        }

        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        rtb_CastToSingle9 = AAIRVVIRWORK_DW.time_minute - /*MW:OvSatOk*/
          mul_u32_sat(b_x, AAIRVVIRWORK_B.h_r_l);
        if (rtb_CastToSingle9 > AAIRVVIRWORK_DW.time_minute) {
          rtb_CastToSingle9 = 0U;
        }

        if (AAIRVVIRWORK_B.h_r_l == 0U) {
          if (rtb_CastToSingle9 == 0U) {
            AAIRVVIRWORK_B.wait_time_LRL_hys = 0U;
          } else {
            AAIRVVIRWORK_B.wait_time_LRL_hys = MAX_uint32_T;
          }
        } else {
          AAIRVVIRWORK_B.wait_time_LRL_hys = AAIRVVIRWORK_B.h_r_l == 0U ?
            MAX_uint32_T : rtb_CastToSingle9 / AAIRVVIRWORK_B.h_r_l;
          rtb_CastToSingle9 -= AAIRVVIRWORK_B.wait_time_LRL_hys *
            AAIRVVIRWORK_B.h_r_l;
          if ((rtb_CastToSingle9 > 0U) && (rtb_CastToSingle9 >=
               (AAIRVVIRWORK_B.h_r_l >> 1U) + (AAIRVVIRWORK_B.h_r_l & 1U))) {
            AAIRVVIRWORK_B.wait_time_LRL_hys++;
          }
        }
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
  b_x = (((AAIRVVIRWORK_DW.Delay_DSTATE + AAIRVVIRWORK_DW.Delay1_DSTATE) +
          AAIRVVIRWORK_DW.Delay2_DSTATE) + AAIRVVIRWORK_DW.Delay3_DSTATE) +
    AAIRVVIRWORK_DW.Delay4_DSTATE;
  uMultiWordMul(&AAIRVVIRWORK_P.Gain_Gain_j, 1, &b_x, 1, &tmp.chunks[0U], 2);

  /* Gain: '<S13>/Gain1' incorporates:
   *  DataTypeConversion: '<S13>/Cast To Double1'
   *  Fcn: '<S13>/Fcn'
   */
  AAIRVVIRWORK_B.Gain1 = 1.0 / (uMultiWord2Double(&tmp.chunks[0U], 2, 0) *
    5.8207660913467407E-11) * AAIRVVIRWORK_P.Gain1_Gain;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S20>/MaxVoltage'
   *  Constant: '<S23>/%'
   *  Product: '<S23>/Divide'
   */
  AAIRVVIRWORK_B.Product = AAIRVVIRWORK_B.atrial_amplitude /
    AAIRVVIRWORK_P.MaxVoltage_Value * AAIRVVIRWORK_P._Value;

  /* Product: '<S24>/Product' incorporates:
   *  Constant: '<S20>/MaxVoltage'
   *  Constant: '<S24>/%'
   *  Product: '<S24>/Divide'
   */
  AAIRVVIRWORK_B.Product_k = AAIRVVIRWORK_B.ventricular_amplitude /
    AAIRVVIRWORK_P.MaxVoltage_Value * AAIRVVIRWORK_P._Value_b;

  /* DataTypeConversion: '<S19>/Cast' incorporates:
   *  Constant: '<S19>/Constant'
   *  Math: '<S19>/Math Function1'
   *  Product: '<S19>/Product'
   *
   * About '<S19>/Math Function1':
   *  Operator: reciprocal
   */
  AAIRVVIRWORK_B.Add = floor(1.0F / AAIRVVIRWORK_B.CR *
    AAIRVVIRWORK_P.Constant_Value_g);
  if (rtIsNaN(AAIRVVIRWORK_B.Add) || rtIsInf(AAIRVVIRWORK_B.Add)) {
    AAIRVVIRWORK_B.Add = 0.0;
  } else {
    AAIRVVIRWORK_B.Add = fmod(AAIRVVIRWORK_B.Add, 4.294967296E+9);
  }

  AAIRVVIRWORK_B.Cast = AAIRVVIRWORK_B.Add < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -AAIRVVIRWORK_B.Add : (uint32_T)AAIRVVIRWORK_B.Add;

  /* End of DataTypeConversion: '<S19>/Cast' */

  /* DataTypeConversion: '<S2>/Cast To Single5' */
  stepup_tmp = (real32_T)floor(AAIRVVIRWORK_B.DesiredRate);
  if (rtIsNaNF(stepup_tmp) || rtIsInfF(stepup_tmp)) {
    stepup_tmp = 0.0F;
  } else {
    stepup_tmp = (real32_T)fmod(stepup_tmp, 4.294967296E+9);
  }

  AAIRVVIRWORK_B.CastToSingle5 = stepup_tmp < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-stepup_tmp : (uint32_T)stepup_tmp;

  /* End of DataTypeConversion: '<S2>/Cast To Single5' */

  /* Chart: '<S3>/1.1.3.2 PacemakerControl' incorporates:
   *  Constant: '<S22>/HIGH'
   *  Constant: '<S22>/LOW'
   */
  if (AAIRVVIRWORK_DW.temporalCounter_i1 < MAX_uint32_T) {
    AAIRVVIRWORK_DW.temporalCounter_i1++;
  }

  if (AAIRVVIRWORK_DW.is_active_c3_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c3_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Initialize;
    AAIRVVIRWORK_DW.AOO = 100U;
    AAIRVVIRWORK_DW.VOO = 200;
    AAIRVVIRWORK_DW.AAI = 112U;
    AAIRVVIRWORK_DW.VVI = 222U;
    AAIRVVIRWORK_DW.AOOR = 1000.0;
    AAIRVVIRWORK_DW.AAIR = 1120.0;
    AAIRVVIRWORK_DW.VOOR = 2000.0;
    AAIRVVIRWORK_DW.VVIR = 2220.0;
  } else {
    switch (AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK) {
     case AAIRVVIRWORK_IN_AAI:
      AAIRVVIRWORK_AAI();
      break;

     case AAIRVVIRWORK_IN_AAIR:
      AAIRVVIRWORK_AAIR();
      break;

     case AAIRVVIRWORK_IN_AOO:
      AAIRVVIRWORK_AOO();
      break;

     case AAIRVVIRWORK_IN_AOOR:
      AAIRVVIRWORK_AOOR();
      break;

     case AAIRVVIRWORK_IN_Initialize:
      if (AAIRVVIRWORK_B.HR_Ready) {
        AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
        AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
        AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
      }
      break;

     case AAIRVVIRWORK_IN_Standby_a:
      AAIRVVIRWORK_Standby();
      break;

     case AAIRVVIRWORK_IN_VOO:
      if ((real_T)AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.VOO) {
        AAIRVVIRWORK_DW.is_VOO = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
        AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
        AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
        AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
      } else if (AAIRVVIRWORK_DW.is_VOO == AAIRVVIRWORK_IN_CHARGE) {
        if (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.MathFunction1 -
            (real32_T)AAIRVVIRWORK_B.ventricular_pulse_width) {
          AAIRVVIRWORK_DW.is_VOO = AAIRVVIRWORK_IN_DISCHARGE;
          AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
          AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
        }
      } else {
        /* case IN_DISCHARGE: */
        if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
            (AAIRVVIRWORK_B.ventricular_pulse_width)) {
          AAIRVVIRWORK_DW.is_VOO = AAIRVVIRWORK_IN_CHARGE;
          AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
          AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
          AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        }
      }
      break;

     case AAIRVVIRWORK_IN_VOOR:
      if (AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.VOOR) {
        AAIRVVIRWORK_DW.is_VOOR = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
        AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
        AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
        AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
      } else if (AAIRVVIRWORK_DW.is_VOOR == AAIRVVIRWORK_IN_CHARGE) {
        AAIRVVIRWORK_B.Add = rt_roundd_snf((real_T)AAIRVVIRWORK_B.Cast -
          AAIRVVIRWORK_B.ventricular_pulse_width);
        if (AAIRVVIRWORK_B.Add < 4.294967296E+9) {
          if (AAIRVVIRWORK_B.Add >= 0.0) {
            b_x = (uint32_T)AAIRVVIRWORK_B.Add;
          } else {
            b_x = 0U;
          }
        } else {
          b_x = MAX_uint32_T;
        }

        if (AAIRVVIRWORK_DW.temporalCounter_i1 >= b_x) {
          AAIRVVIRWORK_DW.is_VOOR = AAIRVVIRWORK_IN_DISCHARGE;
          AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
          AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
        }
      } else {
        /* case IN_DISCHARGE: */
        if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
            (AAIRVVIRWORK_B.ventricular_pulse_width)) {
          AAIRVVIRWORK_DW.is_VOOR = AAIRVVIRWORK_IN_CHARGE;
          AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
          AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
          AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
          AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
        }
      }
      break;

     case AAIRVVIRWORK_IN_VVI_n:
      AAIRVVIRWORK_VVI();
      break;

     default:
      /* case IN_VVIR: */
      if (AAIRVVIRWORK_B.Mode != AAIRVVIRWORK_DW.VVIR) {
        AAIRVVIRWORK_DW.is_VVIR = AAIRVVIRWORK_IN_NO_ACTIVE_CHILD;
        AAIRVVIRWORK_DW.is_c3_AAIRVVIRWORK = AAIRVVIRWORK_IN_Standby_a;
        AAIRVVIRWORK_B.atrium_output_voltage = 0.0F;
        AAIRVVIRWORK_B.ventricle_output_voltage = 0.0F;
      } else {
        switch (AAIRVVIRWORK_DW.is_VVIR) {
         case AAIRVVIRWORK_IN_CHARGE:
          if (AAIRVVIRWORK_DW.temporalCounter_i1 >= (uint32_T)ceil
              (AAIRVVIRWORK_B.ventricular_pulse_width)) {
            AAIRVVIRWORK_DW.is_VVIR = AAIRVVIRWORK_IN_Pulse;
            AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
            AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
            AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
            AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
            AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
          }
          break;

         case AAIRVVIR_IN_Hysterisis_mode_OFF:
          if ((AAIRVVIRWORK_B.VENT_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
              (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.CR)) {
            AAIRVVIRWORK_DW.is_VVIR = AAIRVVIRWORK_IN_CHARGE;
            AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
            AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
            AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
            AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
          }
          break;

         case AAIRVVIRW_IN_Hysterisis_mode_ON:
          if ((AAIRVVIRWORK_B.VENT_CMP_DETECT == AAIRVVIRWORK_P.LOW_Value) &&
              (AAIRVVIRWORK_B.Gain4 < AAIRVVIRWORK_B.CR - 5.0F)) {
            AAIRVVIRWORK_DW.is_VVIR = AAIRVVIRWORK_IN_CHARGE;
            AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
            AAIRVVIRWORK_B.PACE_CHARGE_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.PACE_GND_CTRL = AAIRVVIRWORK_P.HIGH_Value;
            AAIRVVIRWORK_B.ATR_PACE_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.ATR_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.Z_ATR_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.Z_VENT_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.VENT_GND_CTRL = AAIRVVIRWORK_P.LOW_Value;
            AAIRVVIRWORK_B.VENT_PACE_CTRL = AAIRVVIRWORK_P.HIGH_Value;
            AAIRVVIRWORK_B.PACING_REF_PWM = AAIRVVIRWORK_B.Product_k;
          }
          break;

         case AAIRVVIRWORK_IN_Pulse:
          if (AAIRVVIRWORK_DW.temporalCounter_i1 >= AAIRVVIRWORK_B.v_r_p) {
            AAIRVVIRWORK_DW.is_VVIR = AAIRVVIRWORK_IN_initializations;
            AAIRVVIRWORK_DW.temporalCounter_i1 = 0U;
            AAIRVVIRWORK_B.VENT_CMP_REF_PWM =
              AAIRVVIRWORK_B.ventricular_sensitivity;
          }
          break;

         default:
          /* case IN_initializations: */
          if ((AAIRVVIRWORK_B.hysterisis_flag == 0) &&
              (AAIRVVIRWORK_DW.temporalCounter_i1 >=
               AAIRVVIRWORK_B.wait_time_AAIR)) {
            AAIRVVIRWORK_DW.is_VVIR = AAIRVVIR_IN_Hysterisis_mode_OFF;
          } else {
            if ((AAIRVVIRWORK_B.hysterisis_flag == 1) &&
                (AAIRVVIRWORK_DW.temporalCounter_i1 >=
                 AAIRVVIRWORK_B.wait_time_AAIR)) {
              AAIRVVIRWORK_DW.is_VVIR = AAIRVVIRW_IN_Hysterisis_mode_ON;
            }
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S3>/1.1.3.2 PacemakerControl' */

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_p5.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_pd.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write2' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_is.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write3' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_n.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(AAIRVVIRWORK_DW.obj_b.MW_PWM_HANDLE,
                      AAIRVVIRWORK_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_np.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_e.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_c4.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S4>/Digital Write8' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_h.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S4>/PWM Output1' incorporates:
   *  Fcn: '<S25>/Fcn'
   *  Gain: '<S25>/Gain'
   */
  MW_PWM_SetDutyCycle(AAIRVVIRWORK_DW.obj_mo.MW_PWM_HANDLE, (real_T)
                      (AAIRVVIRWORK_P.Gain_Gain *
                       (AAIRVVIRWORK_B.ATR_CMP_REF_PWM / 3.3F)));

  /* MATLABSystem: '<S4>/PWM Output2' incorporates:
   *  Fcn: '<S25>/Fcn1'
   *  Gain: '<S25>/Gain1'
   */
  MW_PWM_SetDutyCycle(AAIRVVIRWORK_DW.obj_a.MW_PWM_HANDLE, (real_T)
                      (AAIRVVIRWORK_P.Gain1_Gain_p *
                       (AAIRVVIRWORK_B.VENT_CMP_REF_PWM / 3.3F)));

  /* MATLABSystem: '<S1>/Analog Input' */
  if (AAIRVVIRWORK_DW.obj_f.SampleTime != AAIRVVIRWORK_P.AnalogInput_SampleTime)
  {
    AAIRVVIRWORK_DW.obj_f.SampleTime = AAIRVVIRWORK_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(AAIRVVIRWORK_DW.obj_f.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AAIRVVIRWORK_DW.obj_f.MW_ANALOGIN_HANDLE,
    &AAIRVVIRWORK_B.Add, 7);

  /* MATLABSystem: '<S1>/Analog Input4' */
  if (AAIRVVIRWORK_DW.obj_p.SampleTime != AAIRVVIRWORK_P.AnalogInput4_SampleTime)
  {
    AAIRVVIRWORK_DW.obj_p.SampleTime = AAIRVVIRWORK_P.AnalogInput4_SampleTime;
  }

  MW_AnalogIn_Start(AAIRVVIRWORK_DW.obj_p.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AAIRVVIRWORK_DW.obj_p.MW_ANALOGIN_HANDLE,
    &AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1, 7);

  /* Outputs for Triggered SubSystem: '<S1>/Subsystem1' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  if ((AAIRVVIRWORK_B.MSG_trigger > 0) &&
      (AAIRVVIRWORK_PrevZCX.Subsystem1_Trig_ZCE != POS_ZCSIG)) {
    /* S-Function (any2byte): '<S9>/Byte Pack4' incorporates:
     *  Constant: '<S9>/Constant4'
     */

    /* Pack: <S9>/Byte Pack4 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack4, &AAIRVVIRWORK_P.Constant4_Value,
                  1);

    /* S-Function (any2byte): '<S9>/Byte Pack5' incorporates:
     *  Constant: '<S9>/Constant3'
     */

    /* Pack: <S9>/Byte Pack5 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack5, &AAIRVVIRWORK_P.Constant3_Value,
                  1);

    /* DataTypeConversion: '<S9>/Cast To Single' incorporates:
     *  MATLABSystem: '<S1>/Analog Input'
     */
    AAIRVVIRWORK_B.CastToSingle = (real32_T)AAIRVVIRWORK_B.Add;

    /* S-Function (any2byte): '<S9>/Byte Pack' */

    /* Pack: <S9>/Byte Pack */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack[0], &AAIRVVIRWORK_B.CastToSingle,
                  4);

    /* DataTypeConversion: '<S9>/Cast To Single1' incorporates:
     *  MATLABSystem: '<S1>/Analog Input4'
     */
    AAIRVVIRWORK_B.CastToSingle1 = (real32_T)
      AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1;

    /* S-Function (any2byte): '<S9>/Byte Pack1' */

    /* Pack: <S9>/Byte Pack1 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack1[0], &AAIRVVIRWORK_B.CastToSingle1,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack34' incorporates:
     *  Constant: '<S9>/HandshakePad1'
     */

    /* Pack: <S9>/Byte Pack34 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack34[0],
                  &AAIRVVIRWORK_P.HandshakePad1_Value[0],
                  89);

    /* S-Function (any2byte): '<S9>/Byte Pack6' incorporates:
     *  Constant: '<S9>/Constant23'
     */

    /* Pack: <S9>/Byte Pack6 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack6, &AAIRVVIRWORK_P.Constant23_Value,
                  1);

    /* S-Function (any2byte): '<S9>/Byte Pack7' incorporates:
     *  Constant: '<S9>/Constant22'
     */

    /* Pack: <S9>/Byte Pack7 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack7, &AAIRVVIRWORK_P.Constant22_Value,
                  1);

    /* S-Function (any2byte): '<S9>/Byte Pack8' incorporates:
     *  Constant: '<S9>/SerialNum'
     */

    /* Pack: <S9>/Byte Pack8 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack8[0], &AAIRVVIRWORK_P.SerialNum_Value,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack9' incorporates:
     *  Constant: '<S9>/ModelNum'
     */

    /* Pack: <S9>/Byte Pack9 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack9[0], &AAIRVVIRWORK_P.ModelNum_Value,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack10' incorporates:
     *  Constant: '<S9>/HandshakePad'
     */

    /* Pack: <S9>/Byte Pack10 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack10[0],
                  &AAIRVVIRWORK_P.HandshakePad_Value[0],
                  89);

    /* S-Function (any2byte): '<S9>/Byte Pack11' incorporates:
     *  Constant: '<S9>/Constant1'
     */

    /* Pack: <S9>/Byte Pack11 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack11, &AAIRVVIRWORK_P.Constant1_Value_k,
                  1);

    /* MultiPortSwitch: '<S9>/Multiport Switch1' incorporates:
     *  Constant: '<S9>/Constant2'
     *  Constant: '<S9>/Constant5'
     */
    if (AAIRVVIRWORK_B.MSG_ident == 2) {
      AAIRVVIRWORK_B.MultiportSwitch1 = AAIRVVIRWORK_P.Constant2_Value;
    } else {
      AAIRVVIRWORK_B.MultiportSwitch1 = AAIRVVIRWORK_P.Constant5_Value;
    }

    /* End of MultiPortSwitch: '<S9>/Multiport Switch1' */

    /* S-Function (any2byte): '<S9>/Byte Pack12' */

    /* Pack: <S9>/Byte Pack12 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack12, &AAIRVVIRWORK_B.MultiportSwitch1,
                  1);

    /* S-Function (any2byte): '<S9>/Byte Pack15' */

    /* Pack: <S9>/Byte Pack15 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack15[0], &AAIRVVIRWORK_B.Mode,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack13' */

    /* Pack: <S9>/Byte Pack13 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack13[0],
                  &AAIRVVIRWORK_B.upper_rate_limit,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack14' */

    /* Pack: <S9>/Byte Pack14 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack14[0],
                  &AAIRVVIRWORK_B.lower_rate_limit,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack16' */

    /* Pack: <S9>/Byte Pack16 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack16[0],
                  &AAIRVVIRWORK_B.atrial_amplitude,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack17' */

    /* Pack: <S9>/Byte Pack17 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack17[0],
                  &AAIRVVIRWORK_B.atrial_pulse_width,
                  8);

    /* S-Function (any2byte): '<S9>/Byte Pack18' */

    /* Pack: <S9>/Byte Pack18 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack18[0],
                  &AAIRVVIRWORK_B.ventricular_amplitude,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack19' */

    /* Pack: <S9>/Byte Pack19 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack19[0],
                  &AAIRVVIRWORK_B.ventricular_pulse_width,
                  8);

    /* S-Function (any2byte): '<S9>/Byte Pack20' */

    /* Pack: <S9>/Byte Pack20 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack20[0], &AAIRVVIRWORK_B.a_r_p,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack21' */

    /* Pack: <S9>/Byte Pack21 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack21[0], &AAIRVVIRWORK_B.p_v_a_r_p,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack22' */

    /* Pack: <S9>/Byte Pack22 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack22[0], &AAIRVVIRWORK_B.h_r_l,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack23' */

    /* Pack: <S9>/Byte Pack23 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack23[0], &AAIRVVIRWORK_B.r_s_up,
                  8);

    /* S-Function (any2byte): '<S9>/Byte Pack24' */

    /* Pack: <S9>/Byte Pack24 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack24[0], &AAIRVVIRWORK_B.r_s_down,
                  8);

    /* S-Function (any2byte): '<S9>/Byte Pack25' */

    /* Pack: <S9>/Byte Pack25 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack25[0],
                  &AAIRVVIRWORK_B.atrial_sensitivity,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack26' */

    /* Pack: <S9>/Byte Pack26 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack26[0],
                  &AAIRVVIRWORK_B.ventricular_sensitivity,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack27' */

    /* Pack: <S9>/Byte Pack27 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack27[0], &AAIRVVIRWORK_B.v_r_p,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack28' */

    /* Pack: <S9>/Byte Pack28 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack28[0],
                  &AAIRVVIRWORK_B.activity_threshold,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack29' */

    /* Pack: <S9>/Byte Pack29 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack29[0], &AAIRVVIRWORK_B.ReactionTime,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack30' */

    /* Pack: <S9>/Byte Pack30 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack30[0], &AAIRVVIRWORK_B.ResponseFactor,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack31' */

    /* Pack: <S9>/Byte Pack31 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack31[0], &AAIRVVIRWORK_B.RecoveryTime,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack32' */

    /* Pack: <S9>/Byte Pack32 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack32[0], &AAIRVVIRWORK_B.MSR,
                  4);

    /* S-Function (any2byte): '<S9>/Byte Pack33' */

    /* Pack: <S9>/Byte Pack33 */
    (void) memcpy(&AAIRVVIRWORK_B.BytePack33, &AAIRVVIRWORK_B.hysterisis_flag,
                  1);

    /* MultiPortSwitch: '<S9>/Multiport Switch' */
    switch (AAIRVVIRWORK_B.MSG_ident) {
     case 0:
      AAIRVVIRWORK_B.RxDataLocChar[0] = AAIRVVIRWORK_B.BytePack4;
      AAIRVVIRWORK_B.RxDataLocChar[1] = AAIRVVIRWORK_B.BytePack5;
      AAIRVVIRWORK_B.RxDataLocChar[2] = AAIRVVIRWORK_B.BytePack[0];
      AAIRVVIRWORK_B.RxDataLocChar[6] = AAIRVVIRWORK_B.BytePack1[0];
      AAIRVVIRWORK_B.RxDataLocChar[3] = AAIRVVIRWORK_B.BytePack[1];
      AAIRVVIRWORK_B.RxDataLocChar[7] = AAIRVVIRWORK_B.BytePack1[1];
      AAIRVVIRWORK_B.RxDataLocChar[4] = AAIRVVIRWORK_B.BytePack[2];
      AAIRVVIRWORK_B.RxDataLocChar[8] = AAIRVVIRWORK_B.BytePack1[2];
      AAIRVVIRWORK_B.RxDataLocChar[5] = AAIRVVIRWORK_B.BytePack[3];
      AAIRVVIRWORK_B.RxDataLocChar[9] = AAIRVVIRWORK_B.BytePack1[3];
      memcpy(&AAIRVVIRWORK_B.RxDataLocChar[10], &AAIRVVIRWORK_B.BytePack34[0],
             89U * sizeof(uint8_T));
      break;

     case 1:
      AAIRVVIRWORK_B.RxDataLocChar[0] = AAIRVVIRWORK_B.BytePack6;
      AAIRVVIRWORK_B.RxDataLocChar[1] = AAIRVVIRWORK_B.BytePack7;
      AAIRVVIRWORK_B.RxDataLocChar[2] = AAIRVVIRWORK_B.BytePack8[0];
      AAIRVVIRWORK_B.RxDataLocChar[6] = AAIRVVIRWORK_B.BytePack9[0];
      AAIRVVIRWORK_B.RxDataLocChar[3] = AAIRVVIRWORK_B.BytePack8[1];
      AAIRVVIRWORK_B.RxDataLocChar[7] = AAIRVVIRWORK_B.BytePack9[1];
      AAIRVVIRWORK_B.RxDataLocChar[4] = AAIRVVIRWORK_B.BytePack8[2];
      AAIRVVIRWORK_B.RxDataLocChar[8] = AAIRVVIRWORK_B.BytePack9[2];
      AAIRVVIRWORK_B.RxDataLocChar[5] = AAIRVVIRWORK_B.BytePack8[3];
      AAIRVVIRWORK_B.RxDataLocChar[9] = AAIRVVIRWORK_B.BytePack9[3];
      memcpy(&AAIRVVIRWORK_B.RxDataLocChar[10], &AAIRVVIRWORK_B.BytePack10[0],
             89U * sizeof(uint8_T));
      break;

     case 2:
      AAIRVVIRWORK_B.RxDataLocChar[0] = AAIRVVIRWORK_B.BytePack11;
      AAIRVVIRWORK_B.RxDataLocChar[1] = AAIRVVIRWORK_B.BytePack12;
      AAIRVVIRWORK_B.RxDataLocChar[2] = AAIRVVIRWORK_B.BytePack15[0];
      AAIRVVIRWORK_B.RxDataLocChar[6] = AAIRVVIRWORK_B.BytePack13[0];
      AAIRVVIRWORK_B.RxDataLocChar[10] = AAIRVVIRWORK_B.BytePack14[0];
      AAIRVVIRWORK_B.RxDataLocChar[14] = AAIRVVIRWORK_B.BytePack16[0];
      AAIRVVIRWORK_B.RxDataLocChar[3] = AAIRVVIRWORK_B.BytePack15[1];
      AAIRVVIRWORK_B.RxDataLocChar[7] = AAIRVVIRWORK_B.BytePack13[1];
      AAIRVVIRWORK_B.RxDataLocChar[11] = AAIRVVIRWORK_B.BytePack14[1];
      AAIRVVIRWORK_B.RxDataLocChar[15] = AAIRVVIRWORK_B.BytePack16[1];
      AAIRVVIRWORK_B.RxDataLocChar[4] = AAIRVVIRWORK_B.BytePack15[2];
      AAIRVVIRWORK_B.RxDataLocChar[8] = AAIRVVIRWORK_B.BytePack13[2];
      AAIRVVIRWORK_B.RxDataLocChar[12] = AAIRVVIRWORK_B.BytePack14[2];
      AAIRVVIRWORK_B.RxDataLocChar[16] = AAIRVVIRWORK_B.BytePack16[2];
      AAIRVVIRWORK_B.RxDataLocChar[5] = AAIRVVIRWORK_B.BytePack15[3];
      AAIRVVIRWORK_B.RxDataLocChar[9] = AAIRVVIRWORK_B.BytePack13[3];
      AAIRVVIRWORK_B.RxDataLocChar[13] = AAIRVVIRWORK_B.BytePack14[3];
      AAIRVVIRWORK_B.RxDataLocChar[17] = AAIRVVIRWORK_B.BytePack16[3];
      AAIRVVIRWORK_B.RxDataLocChar[26] = AAIRVVIRWORK_B.BytePack18[0];
      AAIRVVIRWORK_B.RxDataLocChar[27] = AAIRVVIRWORK_B.BytePack18[1];
      AAIRVVIRWORK_B.RxDataLocChar[28] = AAIRVVIRWORK_B.BytePack18[2];
      AAIRVVIRWORK_B.RxDataLocChar[29] = AAIRVVIRWORK_B.BytePack18[3];
      AAIRVVIRWORK_B.RxDataLocChar[38] = AAIRVVIRWORK_B.BytePack20[0];
      AAIRVVIRWORK_B.RxDataLocChar[42] = AAIRVVIRWORK_B.BytePack21[0];
      AAIRVVIRWORK_B.RxDataLocChar[46] = AAIRVVIRWORK_B.BytePack22[0];
      AAIRVVIRWORK_B.RxDataLocChar[39] = AAIRVVIRWORK_B.BytePack20[1];
      AAIRVVIRWORK_B.RxDataLocChar[43] = AAIRVVIRWORK_B.BytePack21[1];
      AAIRVVIRWORK_B.RxDataLocChar[47] = AAIRVVIRWORK_B.BytePack22[1];
      AAIRVVIRWORK_B.RxDataLocChar[40] = AAIRVVIRWORK_B.BytePack20[2];
      AAIRVVIRWORK_B.RxDataLocChar[44] = AAIRVVIRWORK_B.BytePack21[2];
      AAIRVVIRWORK_B.RxDataLocChar[48] = AAIRVVIRWORK_B.BytePack22[2];
      AAIRVVIRWORK_B.RxDataLocChar[41] = AAIRVVIRWORK_B.BytePack20[3];
      AAIRVVIRWORK_B.RxDataLocChar[45] = AAIRVVIRWORK_B.BytePack21[3];
      AAIRVVIRWORK_B.RxDataLocChar[49] = AAIRVVIRWORK_B.BytePack22[3];
      for (i = 0; i < 8; i++) {
        AAIRVVIRWORK_B.RxDataLocChar[i + 18] = AAIRVVIRWORK_B.BytePack17[i];
        AAIRVVIRWORK_B.RxDataLocChar[i + 30] = AAIRVVIRWORK_B.BytePack19[i];
        AAIRVVIRWORK_B.RxDataLocChar[i + 50] = AAIRVVIRWORK_B.BytePack23[i];
        AAIRVVIRWORK_B.RxDataLocChar[i + 58] = AAIRVVIRWORK_B.BytePack24[i];
      }

      AAIRVVIRWORK_B.RxDataLocChar[66] = AAIRVVIRWORK_B.BytePack25[0];
      AAIRVVIRWORK_B.RxDataLocChar[70] = AAIRVVIRWORK_B.BytePack26[0];
      AAIRVVIRWORK_B.RxDataLocChar[74] = AAIRVVIRWORK_B.BytePack27[0];
      AAIRVVIRWORK_B.RxDataLocChar[78] = AAIRVVIRWORK_B.BytePack28[0];
      AAIRVVIRWORK_B.RxDataLocChar[82] = AAIRVVIRWORK_B.BytePack29[0];
      AAIRVVIRWORK_B.RxDataLocChar[86] = AAIRVVIRWORK_B.BytePack30[0];
      AAIRVVIRWORK_B.RxDataLocChar[90] = AAIRVVIRWORK_B.BytePack31[0];
      AAIRVVIRWORK_B.RxDataLocChar[94] = AAIRVVIRWORK_B.BytePack32[0];
      AAIRVVIRWORK_B.RxDataLocChar[67] = AAIRVVIRWORK_B.BytePack25[1];
      AAIRVVIRWORK_B.RxDataLocChar[71] = AAIRVVIRWORK_B.BytePack26[1];
      AAIRVVIRWORK_B.RxDataLocChar[75] = AAIRVVIRWORK_B.BytePack27[1];
      AAIRVVIRWORK_B.RxDataLocChar[79] = AAIRVVIRWORK_B.BytePack28[1];
      AAIRVVIRWORK_B.RxDataLocChar[83] = AAIRVVIRWORK_B.BytePack29[1];
      AAIRVVIRWORK_B.RxDataLocChar[87] = AAIRVVIRWORK_B.BytePack30[1];
      AAIRVVIRWORK_B.RxDataLocChar[91] = AAIRVVIRWORK_B.BytePack31[1];
      AAIRVVIRWORK_B.RxDataLocChar[95] = AAIRVVIRWORK_B.BytePack32[1];
      AAIRVVIRWORK_B.RxDataLocChar[68] = AAIRVVIRWORK_B.BytePack25[2];
      AAIRVVIRWORK_B.RxDataLocChar[72] = AAIRVVIRWORK_B.BytePack26[2];
      AAIRVVIRWORK_B.RxDataLocChar[76] = AAIRVVIRWORK_B.BytePack27[2];
      AAIRVVIRWORK_B.RxDataLocChar[80] = AAIRVVIRWORK_B.BytePack28[2];
      AAIRVVIRWORK_B.RxDataLocChar[84] = AAIRVVIRWORK_B.BytePack29[2];
      AAIRVVIRWORK_B.RxDataLocChar[88] = AAIRVVIRWORK_B.BytePack30[2];
      AAIRVVIRWORK_B.RxDataLocChar[92] = AAIRVVIRWORK_B.BytePack31[2];
      AAIRVVIRWORK_B.RxDataLocChar[96] = AAIRVVIRWORK_B.BytePack32[2];
      AAIRVVIRWORK_B.RxDataLocChar[69] = AAIRVVIRWORK_B.BytePack25[3];
      AAIRVVIRWORK_B.RxDataLocChar[73] = AAIRVVIRWORK_B.BytePack26[3];
      AAIRVVIRWORK_B.RxDataLocChar[77] = AAIRVVIRWORK_B.BytePack27[3];
      AAIRVVIRWORK_B.RxDataLocChar[81] = AAIRVVIRWORK_B.BytePack28[3];
      AAIRVVIRWORK_B.RxDataLocChar[85] = AAIRVVIRWORK_B.BytePack29[3];
      AAIRVVIRWORK_B.RxDataLocChar[89] = AAIRVVIRWORK_B.BytePack30[3];
      AAIRVVIRWORK_B.RxDataLocChar[93] = AAIRVVIRWORK_B.BytePack31[3];
      AAIRVVIRWORK_B.RxDataLocChar[97] = AAIRVVIRWORK_B.BytePack32[3];
      AAIRVVIRWORK_B.RxDataLocChar[98] = AAIRVVIRWORK_B.BytePack33;
      break;

     default:
      AAIRVVIRWORK_B.RxDataLocChar[0] = AAIRVVIRWORK_B.BytePack11;
      AAIRVVIRWORK_B.RxDataLocChar[1] = AAIRVVIRWORK_B.BytePack12;
      AAIRVVIRWORK_B.RxDataLocChar[2] = AAIRVVIRWORK_B.BytePack15[0];
      AAIRVVIRWORK_B.RxDataLocChar[6] = AAIRVVIRWORK_B.BytePack13[0];
      AAIRVVIRWORK_B.RxDataLocChar[10] = AAIRVVIRWORK_B.BytePack14[0];
      AAIRVVIRWORK_B.RxDataLocChar[14] = AAIRVVIRWORK_B.BytePack16[0];
      AAIRVVIRWORK_B.RxDataLocChar[3] = AAIRVVIRWORK_B.BytePack15[1];
      AAIRVVIRWORK_B.RxDataLocChar[7] = AAIRVVIRWORK_B.BytePack13[1];
      AAIRVVIRWORK_B.RxDataLocChar[11] = AAIRVVIRWORK_B.BytePack14[1];
      AAIRVVIRWORK_B.RxDataLocChar[15] = AAIRVVIRWORK_B.BytePack16[1];
      AAIRVVIRWORK_B.RxDataLocChar[4] = AAIRVVIRWORK_B.BytePack15[2];
      AAIRVVIRWORK_B.RxDataLocChar[8] = AAIRVVIRWORK_B.BytePack13[2];
      AAIRVVIRWORK_B.RxDataLocChar[12] = AAIRVVIRWORK_B.BytePack14[2];
      AAIRVVIRWORK_B.RxDataLocChar[16] = AAIRVVIRWORK_B.BytePack16[2];
      AAIRVVIRWORK_B.RxDataLocChar[5] = AAIRVVIRWORK_B.BytePack15[3];
      AAIRVVIRWORK_B.RxDataLocChar[9] = AAIRVVIRWORK_B.BytePack13[3];
      AAIRVVIRWORK_B.RxDataLocChar[13] = AAIRVVIRWORK_B.BytePack14[3];
      AAIRVVIRWORK_B.RxDataLocChar[17] = AAIRVVIRWORK_B.BytePack16[3];
      AAIRVVIRWORK_B.RxDataLocChar[26] = AAIRVVIRWORK_B.BytePack18[0];
      AAIRVVIRWORK_B.RxDataLocChar[27] = AAIRVVIRWORK_B.BytePack18[1];
      AAIRVVIRWORK_B.RxDataLocChar[28] = AAIRVVIRWORK_B.BytePack18[2];
      AAIRVVIRWORK_B.RxDataLocChar[29] = AAIRVVIRWORK_B.BytePack18[3];
      AAIRVVIRWORK_B.RxDataLocChar[38] = AAIRVVIRWORK_B.BytePack20[0];
      AAIRVVIRWORK_B.RxDataLocChar[42] = AAIRVVIRWORK_B.BytePack21[0];
      AAIRVVIRWORK_B.RxDataLocChar[46] = AAIRVVIRWORK_B.BytePack22[0];
      AAIRVVIRWORK_B.RxDataLocChar[39] = AAIRVVIRWORK_B.BytePack20[1];
      AAIRVVIRWORK_B.RxDataLocChar[43] = AAIRVVIRWORK_B.BytePack21[1];
      AAIRVVIRWORK_B.RxDataLocChar[47] = AAIRVVIRWORK_B.BytePack22[1];
      AAIRVVIRWORK_B.RxDataLocChar[40] = AAIRVVIRWORK_B.BytePack20[2];
      AAIRVVIRWORK_B.RxDataLocChar[44] = AAIRVVIRWORK_B.BytePack21[2];
      AAIRVVIRWORK_B.RxDataLocChar[48] = AAIRVVIRWORK_B.BytePack22[2];
      AAIRVVIRWORK_B.RxDataLocChar[41] = AAIRVVIRWORK_B.BytePack20[3];
      AAIRVVIRWORK_B.RxDataLocChar[45] = AAIRVVIRWORK_B.BytePack21[3];
      AAIRVVIRWORK_B.RxDataLocChar[49] = AAIRVVIRWORK_B.BytePack22[3];
      for (i = 0; i < 8; i++) {
        AAIRVVIRWORK_B.RxDataLocChar[i + 18] = AAIRVVIRWORK_B.BytePack17[i];
        AAIRVVIRWORK_B.RxDataLocChar[i + 30] = AAIRVVIRWORK_B.BytePack19[i];
        AAIRVVIRWORK_B.RxDataLocChar[i + 50] = AAIRVVIRWORK_B.BytePack23[i];
        AAIRVVIRWORK_B.RxDataLocChar[i + 58] = AAIRVVIRWORK_B.BytePack24[i];
      }

      AAIRVVIRWORK_B.RxDataLocChar[66] = AAIRVVIRWORK_B.BytePack25[0];
      AAIRVVIRWORK_B.RxDataLocChar[70] = AAIRVVIRWORK_B.BytePack26[0];
      AAIRVVIRWORK_B.RxDataLocChar[74] = AAIRVVIRWORK_B.BytePack27[0];
      AAIRVVIRWORK_B.RxDataLocChar[78] = AAIRVVIRWORK_B.BytePack28[0];
      AAIRVVIRWORK_B.RxDataLocChar[82] = AAIRVVIRWORK_B.BytePack29[0];
      AAIRVVIRWORK_B.RxDataLocChar[86] = AAIRVVIRWORK_B.BytePack30[0];
      AAIRVVIRWORK_B.RxDataLocChar[90] = AAIRVVIRWORK_B.BytePack31[0];
      AAIRVVIRWORK_B.RxDataLocChar[94] = AAIRVVIRWORK_B.BytePack32[0];
      AAIRVVIRWORK_B.RxDataLocChar[67] = AAIRVVIRWORK_B.BytePack25[1];
      AAIRVVIRWORK_B.RxDataLocChar[71] = AAIRVVIRWORK_B.BytePack26[1];
      AAIRVVIRWORK_B.RxDataLocChar[75] = AAIRVVIRWORK_B.BytePack27[1];
      AAIRVVIRWORK_B.RxDataLocChar[79] = AAIRVVIRWORK_B.BytePack28[1];
      AAIRVVIRWORK_B.RxDataLocChar[83] = AAIRVVIRWORK_B.BytePack29[1];
      AAIRVVIRWORK_B.RxDataLocChar[87] = AAIRVVIRWORK_B.BytePack30[1];
      AAIRVVIRWORK_B.RxDataLocChar[91] = AAIRVVIRWORK_B.BytePack31[1];
      AAIRVVIRWORK_B.RxDataLocChar[95] = AAIRVVIRWORK_B.BytePack32[1];
      AAIRVVIRWORK_B.RxDataLocChar[68] = AAIRVVIRWORK_B.BytePack25[2];
      AAIRVVIRWORK_B.RxDataLocChar[72] = AAIRVVIRWORK_B.BytePack26[2];
      AAIRVVIRWORK_B.RxDataLocChar[76] = AAIRVVIRWORK_B.BytePack27[2];
      AAIRVVIRWORK_B.RxDataLocChar[80] = AAIRVVIRWORK_B.BytePack28[2];
      AAIRVVIRWORK_B.RxDataLocChar[84] = AAIRVVIRWORK_B.BytePack29[2];
      AAIRVVIRWORK_B.RxDataLocChar[88] = AAIRVVIRWORK_B.BytePack30[2];
      AAIRVVIRWORK_B.RxDataLocChar[92] = AAIRVVIRWORK_B.BytePack31[2];
      AAIRVVIRWORK_B.RxDataLocChar[96] = AAIRVVIRWORK_B.BytePack32[2];
      AAIRVVIRWORK_B.RxDataLocChar[69] = AAIRVVIRWORK_B.BytePack25[3];
      AAIRVVIRWORK_B.RxDataLocChar[73] = AAIRVVIRWORK_B.BytePack26[3];
      AAIRVVIRWORK_B.RxDataLocChar[77] = AAIRVVIRWORK_B.BytePack27[3];
      AAIRVVIRWORK_B.RxDataLocChar[81] = AAIRVVIRWORK_B.BytePack28[3];
      AAIRVVIRWORK_B.RxDataLocChar[85] = AAIRVVIRWORK_B.BytePack29[3];
      AAIRVVIRWORK_B.RxDataLocChar[89] = AAIRVVIRWORK_B.BytePack30[3];
      AAIRVVIRWORK_B.RxDataLocChar[93] = AAIRVVIRWORK_B.BytePack31[3];
      AAIRVVIRWORK_B.RxDataLocChar[97] = AAIRVVIRWORK_B.BytePack32[3];
      AAIRVVIRWORK_B.RxDataLocChar[98] = AAIRVVIRWORK_B.BytePack33;
      break;
    }

    /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

    /* MATLABSystem: '<S9>/Serial Transmit' */
    status = 1U;
    while (status != 0) {
      memcpy((void *)&AAIRVVIRWORK_B.TxDataLocChar[0], (void *)
             &AAIRVVIRWORK_B.RxDataLocChar[0], (uint32_T)((size_t)99 * sizeof
              (uint8_T)));
      status = MW_SCI_Transmit(AAIRVVIRWORK_DW.obj_ce.MW_SCIHANDLE,
        AAIRVVIRWORK_B.TxDataLocChar, 99U);
    }

    /* End of MATLABSystem: '<S9>/Serial Transmit' */
  }

  AAIRVVIRWORK_PrevZCX.Subsystem1_Trig_ZCE = (ZCSigState)
    (AAIRVVIRWORK_B.MSG_trigger > 0);

  /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

  /* Chart: '<S1>/HeartChamberPulseDetection' */
  if (AAIRVVIRWORK_DW.is_active_c6_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c6_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c6_AAIRVVIRWORK = AAIRVVIRWORK_IN_default;
  } else if (AAIRVVIRWORK_DW.is_c6_AAIRVVIRWORK == AAIRVVIRWORK_IN_default) {
    if (AAIRVVIRWORK_B.VENT_CMP_DETECT) {
      AAIRVVIRWORK_DW.is_c6_AAIRVVIRWORK = AAIRVVIRWORK_IN_led_on;
    }
  } else {
    /* case IN_led_on: */
    if (!AAIRVVIRWORK_B.VENT_CMP_DETECT) {
      AAIRVVIRWORK_DW.is_c6_AAIRVVIRWORK = AAIRVVIRWORK_IN_default;
    }
  }

  /* End of Chart: '<S1>/HeartChamberPulseDetection' */

  /* Chart: '<S1>/HeartChamberPulseDetection3' */
  if (AAIRVVIRWORK_DW.temporalCounter_i1_k < 63U) {
    AAIRVVIRWORK_DW.temporalCounter_i1_k++;
  }

  if (AAIRVVIRWORK_DW.is_active_c7_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c7_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c7_AAIRVVIRWORK = AAIRVVIRWORK_IN_default;
    AAIRVVIRWORK_DW.temporalCounter_i1_k = 0U;
    rtb_LED_STATE_f = false;
  } else if (AAIRVVIRWORK_DW.is_c7_AAIRVVIRWORK == AAIRVVIRWORK_IN_default) {
    rtb_LED_STATE_f = false;
    if (AAIRVVIRWORK_DW.temporalCounter_i1_k >= 50U) {
      AAIRVVIRWORK_DW.is_c7_AAIRVVIRWORK = AAIRVVIRWORK_IN_led_on;
      AAIRVVIRWORK_DW.temporalCounter_i1_k = 0U;
      rtb_LED_STATE_f = true;
    }
  } else {
    /* case IN_led_on: */
    rtb_LED_STATE_f = true;
    if (AAIRVVIRWORK_DW.temporalCounter_i1_k >= 50U) {
      AAIRVVIRWORK_DW.is_c7_AAIRVVIRWORK = AAIRVVIRWORK_IN_default;
      AAIRVVIRWORK_DW.temporalCounter_i1_k = 0U;
      rtb_LED_STATE_f = false;
    }
  }

  /* End of Chart: '<S1>/HeartChamberPulseDetection3' */

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  if (rtb_LED_STATE_f && (AAIRVVIRWORK_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
                          POS_ZCSIG)) {
    /* MATLABSystem: '<S10>/FXOS8700 6-Axes Sensor' */
    if (AAIRVVIRWORK_DW.obj_c.SampleTime !=
        AAIRVVIRWORK_P.FXOS87006AxesSensor_SampleTime) {
      AAIRVVIRWORK_DW.obj_c.SampleTime =
        AAIRVVIRWORK_P.FXOS87006AxesSensor_SampleTime;
    }

    status = 1U;
    status = MW_I2C_MasterWrite(AAIRVVIRWORK_DW.obj_c.i2cobj.MW_I2C_HANDLE, 29U,
      &status, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(AAIRVVIRWORK_DW.obj_c.i2cobj.MW_I2C_HANDLE, 29U,
                        output_raw, 6U, false, true);
      memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
              sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_output[0], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      b_x_0[0] = y[1];
      b_x_0[1] = y[0];
      memcpy((void *)&b_output[0], (void *)&b_x_0[0], (uint32_T)((size_t)1 *
              sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_output[1], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      b_x_0[0] = y[1];
      b_x_0[1] = y[0];
      memcpy((void *)&b_output[1], (void *)&b_x_0[0], (uint32_T)((size_t)1 *
              sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_output[2], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      b_x_0[0] = y[1];
      b_x_0[1] = y[0];
      memcpy((void *)&b_output[2], (void *)&b_x_0[0], (uint32_T)((size_t)1 *
              sizeof(int16_T)));
    } else {
      b_output[0] = 0;
      b_output[1] = 0;
      b_output[2] = 0;
    }

    AAIRVVIRWORK_B.Add = (real_T)(int16_T)(b_output[0] >> 2) * 2.0 * 0.244 /
      1000.0;
    AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_output[1]
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
    AAIRVVIRWORK_B.Add = sqrt((AAIRVVIRWORK_B.Add * AAIRVVIRWORK_B.Add +
      AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 *
      AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1) +
      rtb_FXOS87006AxesSensor_idx_2 * rtb_FXOS87006AxesSensor_idx_2);

    /* MATLABSystem: '<S10>/Moving Average' */
    if (AAIRVVIRWORK_DW.obj.TunablePropsChanged) {
      AAIRVVIRWORK_DW.obj.TunablePropsChanged = false;
    }

    if (AAIRVVIRWORK_DW.obj.pStatistic->isInitialized != 1) {
      AAIRVVIRWORK_DW.obj.pStatistic->isSetupComplete = false;
      AAIRVVIRWORK_DW.obj.pStatistic->isInitialized = 1;
      AAIRVVIRWORK_DW.obj.pStatistic->pCumSum = 0.0;
      AAIRVVIRWORK_DW.obj.pStatistic->pCumRevIndex = 1.0;
      AAIRVVIRWORK_DW.obj.pStatistic->isSetupComplete = true;
      AAIRVVIRWORK_DW.obj.pStatistic->pCumSum = 0.0;
      memset(&AAIRVVIRWORK_DW.obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof
             (real_T));
      AAIRVVIRWORK_DW.obj.pStatistic->pCumRevIndex = 1.0;
    }

    AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 =
      AAIRVVIRWORK_DW.obj.pStatistic->pCumRevIndex;
    rtb_FXOS87006AxesSensor_idx_2 = AAIRVVIRWORK_DW.obj.pStatistic->pCumSum;
    for (i = 0; i < 19; i++) {
      AAIRVVIRWORK_B.csumrev[i] = AAIRVVIRWORK_DW.obj.pStatistic->pCumSumRev[i];
    }

    rtb_FXOS87006AxesSensor_idx_2 += AAIRVVIRWORK_B.Add;
    i = (int32_T)AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 - 1;
    AAIRVVIRWORK_B.z = AAIRVVIRWORK_B.csumrev[i] + rtb_FXOS87006AxesSensor_idx_2;
    AAIRVVIRWORK_B.csumrev[i] = AAIRVVIRWORK_B.Add;
    if (AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 != 19.0) {
      AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1++;
    } else {
      AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1 = 1.0;
      rtb_FXOS87006AxesSensor_idx_2 = 0.0;
      for (i = 17; i >= 0; i--) {
        AAIRVVIRWORK_B.csumrev[i] += AAIRVVIRWORK_B.csumrev[i + 1];
      }
    }

    AAIRVVIRWORK_DW.obj.pStatistic->pCumSum = rtb_FXOS87006AxesSensor_idx_2;
    memcpy(&AAIRVVIRWORK_DW.obj.pStatistic->pCumSumRev[0],
           &AAIRVVIRWORK_B.csumrev[0], 19U * sizeof(real_T));
    AAIRVVIRWORK_DW.obj.pStatistic->pCumRevIndex =
      AAIRVVIRWORK_B.rtb_FXOS87006AxesSensor_idx_1;
    AAIRVVIRWORK_B.MovingAverage = AAIRVVIRWORK_B.z / 20.0;

    /* End of MATLABSystem: '<S10>/Moving Average' */
  }

  AAIRVVIRWORK_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_LED_STATE_f;

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */

  /* Chart: '<S1>/HeartChamberPulseDetection2' */
  if (AAIRVVIRWORK_DW.temporalCounter_i1_o < 16383U) {
    AAIRVVIRWORK_DW.temporalCounter_i1_o++;
  }

  if (AAIRVVIRWORK_DW.is_active_c8_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c8_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c8_AAIRVVIRWORK = AAIRVVIRWORK_IN_default;
    AAIRVVIRWORK_DW.temporalCounter_i1_o = 0U;
  } else if (AAIRVVIRWORK_DW.is_c8_AAIRVVIRWORK == AAIRVVIRWORK_IN_default) {
    if (AAIRVVIRWORK_DW.temporalCounter_i1_o >= 10000U) {
      AAIRVVIRWORK_DW.is_c8_AAIRVVIRWORK = AAIRVVIRWORK_IN_led_on;
      AAIRVVIRWORK_DW.temporalCounter_i1_o = 0U;
    }
  } else {
    /* case IN_led_on: */
    if (AAIRVVIRWORK_DW.temporalCounter_i1_o >= 10000U) {
      AAIRVVIRWORK_DW.is_c8_AAIRVVIRWORK = AAIRVVIRWORK_IN_default;
      AAIRVVIRWORK_DW.temporalCounter_i1_o = 0U;
    }
  }

  /* End of Chart: '<S1>/HeartChamberPulseDetection2' */

  /* Chart: '<S2>/Activity Index Determination' */
  if (AAIRVVIRWORK_DW.is_active_c4_AAIRVVIRWORK == 0U) {
    AAIRVVIRWORK_DW.is_active_c4_AAIRVVIRWORK = 1U;
    AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_init;
    AAIRVVIRWORK_DW.a = 0.0;
  } else {
    switch (AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK) {
     case AAIRVVIRWORK_IN_High:
      AAIRVVIRWORK_B.ActivityIndex = 6.0;
      break;

     case AAIRVVIRWORK_IN_Low:
      AAIRVVIRWORK_B.ActivityIndex = 2.0;
      break;

     case AAIRVVIRWORK_IN_Med:
      AAIRVVIRWORK_B.ActivityIndex = 4.0;
      break;

     case AAIRVVIRWORK_IN_Med_High:
      AAIRVVIRWORK_B.ActivityIndex = 5.0;
      break;

     case AAIRVVIRWORK_IN_Med_Low:
      AAIRVVIRWORK_B.ActivityIndex = 3.0;
      break;

     case AAIRVVIRWORK_IN_V_High:
      AAIRVVIRWORK_B.ActivityIndex = 7.0;
      break;

     case AAIRVVIRWORK_IN_V_Low:
      AAIRVVIRWORK_B.ActivityIndex = 1.0;
      break;

     default:
      /* case IN_init: */
      if ((AAIRVVIRWORK_DW.a >= 0.0) && (AAIRVVIRWORK_DW.a < 1.0)) {
        AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_V_Low;
        AAIRVVIRWORK_B.ActivityIndex = 1.0;
      } else if ((AAIRVVIRWORK_DW.a >= 1.0) && (AAIRVVIRWORK_DW.a < 2.0)) {
        AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_Low;
        AAIRVVIRWORK_B.ActivityIndex = 2.0;
      } else if ((AAIRVVIRWORK_DW.a >= 2.0) && (AAIRVVIRWORK_DW.a < 3.0)) {
        AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_Med_Low;
        AAIRVVIRWORK_B.ActivityIndex = 3.0;
      } else if ((AAIRVVIRWORK_DW.a >= 3.0) && (AAIRVVIRWORK_DW.a < 4.0)) {
        AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_Med;
        AAIRVVIRWORK_B.ActivityIndex = 4.0;
      } else if ((AAIRVVIRWORK_DW.a >= 4.0) && (AAIRVVIRWORK_DW.a < 5.0)) {
        AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_Med_High;
        AAIRVVIRWORK_B.ActivityIndex = 5.0;
      } else if ((AAIRVVIRWORK_DW.a >= 5.0) && (AAIRVVIRWORK_DW.a < 6.0)) {
        AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_High;
        AAIRVVIRWORK_B.ActivityIndex = 6.0;
      } else {
        if ((AAIRVVIRWORK_DW.a >= 6.0) && (AAIRVVIRWORK_DW.a < 7.0)) {
          AAIRVVIRWORK_DW.is_c4_AAIRVVIRWORK = AAIRVVIRWORK_IN_V_High;
          AAIRVVIRWORK_B.ActivityIndex = 7.0;
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
  if (AAIRVVIRWORK_B.pulse_finished) {
    AAIRVVIRWORK_DW.Delay4_DSTATE = AAIRVVIRWORK_DW.Delay3_DSTATE;
    AAIRVVIRWORK_DW.Delay3_DSTATE = AAIRVVIRWORK_DW.Delay2_DSTATE;
    AAIRVVIRWORK_DW.Delay2_DSTATE = AAIRVVIRWORK_DW.Delay1_DSTATE;
    AAIRVVIRWORK_DW.Delay1_DSTATE = AAIRVVIRWORK_DW.Delay_DSTATE;
    AAIRVVIRWORK_DW.Delay_DSTATE = AAIRVVIRWORK_B.time_between_pulses;
  }

  /* End of Switch: '<S13>/Switch4' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_o.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_B.flag != 0U);

  /* MATLABSystem: '<S1>/Analog Input1' */
  if (AAIRVVIRWORK_DW.obj_d.SampleTime != AAIRVVIRWORK_P.AnalogInput1_SampleTime)
  {
    AAIRVVIRWORK_DW.obj_d.SampleTime = AAIRVVIRWORK_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(AAIRVVIRWORK_DW.obj_d.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AAIRVVIRWORK_DW.obj_d.MW_ANALOGIN_HANDLE,
    &AAIRVVIRWORK_B.Add, 7);

  /* End of MATLABSystem: '<S1>/Analog Input1' */

  /* MATLABSystem: '<S1>/Analog Input2' */
  if (AAIRVVIRWORK_DW.obj_g.SampleTime != AAIRVVIRWORK_P.AnalogInput2_SampleTime)
  {
    AAIRVVIRWORK_DW.obj_g.SampleTime = AAIRVVIRWORK_P.AnalogInput2_SampleTime;
  }

  MW_AnalogIn_Start(AAIRVVIRWORK_DW.obj_g.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(AAIRVVIRWORK_DW.obj_g.MW_ANALOGIN_HANDLE,
    &AAIRVVIRWORK_B.Add, 7);

  /* End of MATLABSystem: '<S1>/Analog Input2' */

  /* MATLABSystem: '<S1>/Digital Write1' incorporates:
   *  Constant: '<S1>/Constant15'
   */
  MW_digitalIO_write(AAIRVVIRWORK_DW.obj_hw.MW_DIGITALIO_HANDLE,
                     AAIRVVIRWORK_P.Constant15_Value);

  /* Switch: '<S1>/Switch' */
  if (rtb_LED_STATE_f) {
    /* Update for Memory: '<S1>/Memory' */
    AAIRVVIRWORK_DW.Memory_PreviousInput = AAIRVVIRWORK_B.MovingAverage;
  } else {
    /* Update for Memory: '<S1>/Memory' */
    AAIRVVIRWORK_DW.Memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<S1>/Switch' */
}

/* Model initialize function */
void AAIRVVIRWORK_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_DigitalRead_AAIRV_T *obj;
    freedomk64f_DigitalWrite_AAIR_T *obj_0;
    freedomk64f_PWMOutput_AAIRVVI_T *obj_1;
    freedomk64f_AnalogInput_AAIRV_T *obj_2;
    freedomk64f_fxos8700_AAIRVVIR_T *obj_3;
    AAIRVVIRWORK_PrevZCX.Subsystem1_Trig_ZCE = POS_ZCSIG;
    AAIRVVIRWORK_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for Delay: '<S13>/Delay7' */
    AAIRVVIRWORK_DW.Delay7_DSTATE = AAIRVVIRWORK_P.Delay7_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    AAIRVVIRWORK_DW.Memory_PreviousInput =
      AAIRVVIRWORK_P.Memory_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay' */
    AAIRVVIRWORK_DW.Delay_DSTATE = AAIRVVIRWORK_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay1' */
    AAIRVVIRWORK_DW.Delay1_DSTATE = AAIRVVIRWORK_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay2' */
    AAIRVVIRWORK_DW.Delay2_DSTATE = AAIRVVIRWORK_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay3' */
    AAIRVVIRWORK_DW.Delay3_DSTATE = AAIRVVIRWORK_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S13>/Delay4' */
    AAIRVVIRWORK_DW.Delay4_DSTATE = AAIRVVIRWORK_P.Delay4_InitialCondition;

    /* SystemInitialize for Triggered SubSystem: '<S1>/Subsystem1' */
    /* Start for MATLABSystem: '<S9>/Serial Transmit' */
    AAIRVVIRWORK_DW.obj_ce.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_ce.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_ce.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_j = true;
    AAIRVVIRWORK_SystemCore_setup_p(&AAIRVVIRWORK_DW.obj_ce);

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem1' */

    /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem' */
    /* Start for MATLABSystem: '<S10>/FXOS8700 6-Axes Sensor' */
    AAIRVVIRWORK_DW.obj_c.i2cobj.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_c.matlabCodegenIsDeleted = true;
    obj_3 = &AAIRVVIRWORK_DW.obj_c;
    AAIRVVIRWORK_DW.obj_c.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_c.SampleTime = -1.0;
    obj_3->i2cobj.isInitialized = 0;
    obj_3->i2cobj.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.obj_c.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_l = true;
    AAIRVVIRWORK_DW.obj_c.SampleTime =
      AAIRVVIRWORK_P.FXOS87006AxesSensor_SampleTime;
    AAIRVVIRWOR_SystemCore_setup_pf(&AAIRVVIRWORK_DW.obj_c);

    /* Start for MATLABSystem: '<S10>/Moving Average' */
    AAIRVVIRWORK_DW.obj.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj.isInitialized = 0;
    AAIRVVIRWORK_DW.obj.NumChannels = -1;
    AAIRVVIRWORK_DW.obj.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_p = true;
    AAIRVVIRWORK_DW.obj.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj.isInitialized = 1;
    AAIRVVIRWORK_DW.obj.NumChannels = 1;
    AAIRVVIRWORK_DW.gobj_2.isInitialized = 0;
    AAIRVVIRWORK_DW.obj.pStatistic = &AAIRVVIRWORK_DW.gobj_2;
    AAIRVVIRWORK_DW.obj.isSetupComplete = true;
    AAIRVVIRWORK_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S10>/Moving Average' */
    if (AAIRVVIRWORK_DW.obj.pStatistic->isInitialized == 1) {
      AAIRVVIRWORK_DW.obj.pStatistic->pCumSum = 0.0;
      memset(&AAIRVVIRWORK_DW.obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof
             (real_T));
      AAIRVVIRWORK_DW.obj.pStatistic->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S10>/Moving Average' */

    /* SystemInitialize for Outport: '<S10>/activity_magnitude' */
    AAIRVVIRWORK_B.MovingAverage = AAIRVVIRWORK_P.activity_magnitude_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */

    /* Start for MATLABSystem: '<S1>/Serial Receive' */
    AAIRVVIRWORK_DW.obj_m.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_m.SampleTime = -1.0;
    AAIRVVIRWORK_DW.obj_m.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_m.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_m = true;
    AAIRVVIRWORK_DW.obj_m.SampleTime = AAIRVVIRWORK_P.SerialReceive_SampleTime;
    AAIRVVIRWORK_SystemCore_setup(&AAIRVVIRWORK_DW.obj_m);

    /* Start for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
    AAIRVVIRWORK_DW.obj_i.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_i.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_i.SampleTime = -1.0;
    AAIRVVIRWORK_DW.obj_i.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_mo = true;
    AAIRVVIRWORK_DW.obj_i.SampleTime = AAIRVVIRWORK_P.ATR_CMP_DETECT_SampleTime;
    obj = &AAIRVVIRWORK_DW.obj_i;
    AAIRVVIRWORK_DW.obj_i.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    AAIRVVIRWORK_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
    AAIRVVIRWORK_DW.obj_ci.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_ci.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_ci.SampleTime = -1.0;
    AAIRVVIRWORK_DW.obj_ci.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_ml = true;
    AAIRVVIRWORK_DW.obj_ci.SampleTime =
      AAIRVVIRWORK_P.VENT_CMP_DETECT_SampleTime;
    obj = &AAIRVVIRWORK_DW.obj_ci;
    AAIRVVIRWORK_DW.obj_ci.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_ci.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    AAIRVVIRWORK_DW.obj_ci.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    AAIRVVIRWORK_DW.obj_p5.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_p5.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_p5.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_p5;
    AAIRVVIRWORK_DW.obj_p5.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_p5.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    AAIRVVIRWORK_DW.obj_p5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    AAIRVVIRWORK_DW.obj_pd.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_pd.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_pd.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_h = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_pd;
    AAIRVVIRWORK_DW.obj_pd.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_pd.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    AAIRVVIRWORK_DW.obj_pd.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write2' */
    AAIRVVIRWORK_DW.obj_is.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_is.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_is.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_k = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_is;
    AAIRVVIRWORK_DW.obj_is.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_is.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    AAIRVVIRWORK_DW.obj_is.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    AAIRVVIRWORK_DW.obj_n.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_n.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_n.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_a = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_n;
    AAIRVVIRWORK_DW.obj_n.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    AAIRVVIRWORK_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    AAIRVVIRWORK_DW.obj_b.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_b.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_b.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_f = true;
    obj_1 = &AAIRVVIRWORK_DW.obj_b;
    AAIRVVIRWORK_DW.obj_b.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_b.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 100.0);
    MW_PWM_Start(AAIRVVIRWORK_DW.obj_b.MW_PWM_HANDLE);
    AAIRVVIRWORK_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    AAIRVVIRWORK_DW.obj_np.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_np.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_np.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_i = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_np;
    AAIRVVIRWORK_DW.obj_np.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_np.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    AAIRVVIRWORK_DW.obj_np.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write6' */
    AAIRVVIRWORK_DW.obj_e.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_e.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_e.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_in = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_e;
    AAIRVVIRWORK_DW.obj_e.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    AAIRVVIRWORK_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write7' */
    AAIRVVIRWORK_DW.obj_c4.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_c4.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_c4.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_e = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_c4;
    AAIRVVIRWORK_DW.obj_c4.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_c4.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    AAIRVVIRWORK_DW.obj_c4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    AAIRVVIRWORK_DW.obj_h.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_h.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_h.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_e2 = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_h;
    AAIRVVIRWORK_DW.obj_h.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    AAIRVVIRWORK_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output1' */
    AAIRVVIRWORK_DW.obj_mo.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_mo.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_mo.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_hv = true;
    obj_1 = &AAIRVVIRWORK_DW.obj_mo;
    AAIRVVIRWORK_DW.obj_mo.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_mo.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 20.0);
    MW_PWM_Start(AAIRVVIRWORK_DW.obj_mo.MW_PWM_HANDLE);
    AAIRVVIRWORK_DW.obj_mo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output2' */
    AAIRVVIRWORK_DW.obj_a.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_a.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_a.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_o = true;
    obj_1 = &AAIRVVIRWORK_DW.obj_a;
    AAIRVVIRWORK_DW.obj_a.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 20.0);
    MW_PWM_Start(AAIRVVIRWORK_DW.obj_a.MW_PWM_HANDLE);
    AAIRVVIRWORK_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input' */
    AAIRVVIRWORK_DW.obj_f.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_f.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_f.SampleTime = -1.0;
    AAIRVVIRWORK_DW.obj_f.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_fp = true;
    AAIRVVIRWORK_DW.obj_f.SampleTime = AAIRVVIRWORK_P.AnalogInput_SampleTime;
    obj_2 = &AAIRVVIRWORK_DW.obj_f;
    AAIRVVIRWORK_DW.obj_f.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_f.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    AAIRVVIRWORK_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AAIRVVIRWORK_DW.obj_f.MW_ANALOGIN_HANDLE,
      AAIRVVIRWORK_B.trigger_val, 0U);
    AAIRVVIRWORK_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input4' */
    AAIRVVIRWORK_DW.obj_p.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_p.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_p.SampleTime = -1.0;
    AAIRVVIRWORK_DW.obj_p.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_kg = true;
    AAIRVVIRWORK_DW.obj_p.SampleTime = AAIRVVIRWORK_P.AnalogInput4_SampleTime;
    obj_2 = &AAIRVVIRWORK_DW.obj_p;
    AAIRVVIRWORK_DW.obj_p.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_p.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    AAIRVVIRWORK_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AAIRVVIRWORK_DW.obj_p.MW_ANALOGIN_HANDLE,
      AAIRVVIRWORK_B.trigger_val, 0U);
    AAIRVVIRWORK_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    AAIRVVIRWORK_DW.obj_o.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_o.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_o.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_ez = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_o;
    AAIRVVIRWORK_DW.obj_o.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    AAIRVVIRWORK_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input1' */
    AAIRVVIRWORK_DW.obj_d.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_d.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_d.SampleTime = -1.0;
    AAIRVVIRWORK_DW.obj_d.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_kb = true;
    AAIRVVIRWORK_DW.obj_d.SampleTime = AAIRVVIRWORK_P.AnalogInput1_SampleTime;
    obj_2 = &AAIRVVIRWORK_DW.obj_d;
    AAIRVVIRWORK_DW.obj_d.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_d.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19U);
    AAIRVVIRWORK_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AAIRVVIRWORK_DW.obj_d.MW_ANALOGIN_HANDLE,
      AAIRVVIRWORK_B.trigger_val, 0U);
    AAIRVVIRWORK_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Analog Input2' */
    AAIRVVIRWORK_DW.obj_g.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_g.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_g.SampleTime = -1.0;
    AAIRVVIRWORK_DW.obj_g.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_lf = true;
    AAIRVVIRWORK_DW.obj_g.SampleTime = AAIRVVIRWORK_P.AnalogInput2_SampleTime;
    obj_2 = &AAIRVVIRWORK_DW.obj_g;
    AAIRVVIRWORK_DW.obj_g.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_g.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(20U);
    AAIRVVIRWORK_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(AAIRVVIRWORK_DW.obj_g.MW_ANALOGIN_HANDLE,
      AAIRVVIRWORK_B.trigger_val, 0U);
    AAIRVVIRWORK_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    AAIRVVIRWORK_DW.obj_hw.matlabCodegenIsDeleted = true;
    AAIRVVIRWORK_DW.obj_hw.isInitialized = 0;
    AAIRVVIRWORK_DW.obj_hw.matlabCodegenIsDeleted = false;
    AAIRVVIRWORK_DW.objisempty_l1 = true;
    obj_0 = &AAIRVVIRWORK_DW.obj_hw;
    AAIRVVIRWORK_DW.obj_hw.isSetupComplete = false;
    AAIRVVIRWORK_DW.obj_hw.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    AAIRVVIRWORK_DW.obj_hw.isSetupComplete = true;
  }
}

/* Model terminate function */
void AAIRVVIRWORK_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Serial Receive' */
  matlabCodegenHandle_mat_pfn2eia(&AAIRVVIRWORK_DW.obj_m);

  /* Terminate for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  matlabCodegenHandle_matla_pfn2e(&AAIRVVIRWORK_DW.obj_i);

  /* Terminate for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  matlabCodegenHandle_matla_pfn2e(&AAIRVVIRWORK_DW.obj_ci);

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_p5);

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_pd);

  /* Terminate for MATLABSystem: '<S4>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_is);

  /* Terminate for MATLABSystem: '<S4>/Digital Write3' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_n);

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  matlabCodegenHand_pfn2eia2mtltj(&AAIRVVIRWORK_DW.obj_b);

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_np);

  /* Terminate for MATLABSystem: '<S4>/Digital Write6' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_e);

  /* Terminate for MATLABSystem: '<S4>/Digital Write7' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_c4);

  /* Terminate for MATLABSystem: '<S4>/Digital Write8' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_h);

  /* Terminate for MATLABSystem: '<S4>/PWM Output1' */
  matlabCodegenHand_pfn2eia2mtltj(&AAIRVVIRWORK_DW.obj_mo);

  /* Terminate for MATLABSystem: '<S4>/PWM Output2' */
  matlabCodegenHand_pfn2eia2mtltj(&AAIRVVIRWORK_DW.obj_a);

  /* Terminate for MATLABSystem: '<S1>/Analog Input' */
  matlabCodegenHandle_matlabCod_p(&AAIRVVIRWORK_DW.obj_f);

  /* Terminate for MATLABSystem: '<S1>/Analog Input4' */
  matlabCodegenHandle_matlabCod_p(&AAIRVVIRWORK_DW.obj_p);

  /* Terminate for Triggered SubSystem: '<S1>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S9>/Serial Transmit' */
  matlabCodegenHandle_ma_pfn2eia2(&AAIRVVIRWORK_DW.obj_ce);

  /* End of Terminate for SubSystem: '<S1>/Subsystem1' */

  /* Terminate for Triggered SubSystem: '<S1>/Triggered Subsystem' */
  /* Terminate for MATLABSystem: '<S10>/FXOS8700 6-Axes Sensor' */
  matlabCodegenHandle__pfn2eia2mt(&AAIRVVIRWORK_DW.obj_c);
  matlabCodegenHandle_pfn2eia2mtl(&AAIRVVIRWORK_DW.obj_c.i2cobj);

  /* Terminate for MATLABSystem: '<S10>/Moving Average' */
  matlabCodegenHandle_m_pfn2eia2m(&AAIRVVIRWORK_DW.obj);

  /* End of Terminate for SubSystem: '<S1>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_o);

  /* Terminate for MATLABSystem: '<S1>/Analog Input1' */
  matlabCodegenHandle_matlabCod_p(&AAIRVVIRWORK_DW.obj_d);

  /* Terminate for MATLABSystem: '<S1>/Analog Input2' */
  matlabCodegenHandle_matlabCod_p(&AAIRVVIRWORK_DW.obj_g);

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&AAIRVVIRWORK_DW.obj_hw);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
