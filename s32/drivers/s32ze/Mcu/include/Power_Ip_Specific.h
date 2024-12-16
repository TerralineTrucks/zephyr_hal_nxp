/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        :
S32ZE_RTD_1_0_0_P02_D2310_ASR_REL_4_7_REV_0000_20231030
*
*   Copyright 2021-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only
be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or
otherwise
*   using the software, you are agreeing that you have read, and that you agree
to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef POWER_IP_SPECIFIC_H
#define POWER_IP_SPECIFIC_H

/**
 *   @file       Power_Ip_Specific.h
 *   @version    1.0.0
 *
 *   @brief   POWER IP driver header file.
 *   @details POWER IP driver header file.
 *
 *   @addtogroup POWER_DRIVER Power Ip Driver
 *   @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Cfg_Defines.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_SPECIFIC_VENDOR_ID 43
#define POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION 4
#define POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION 7
#define POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION 0
#define POWER_IP_SPECIFIC_SW_MAJOR_VERSION 1
#define POWER_IP_SPECIFIC_SW_MINOR_VERSION 0
#define POWER_IP_SPECIFIC_SW_PATCH_VERSION 0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_Specific.h file and Power_Ip_Cfg_Defines.h file have same
 * versions */
#if (POWER_IP_SPECIFIC_VENDOR_ID != POWER_IP_CFG_DEFINES_VENDOR_ID)
#error \
    "Power_Ip_Specific.h and Power_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Power_Ip_Specific.h file and Power_Ip_Cfg_Defines.h file are of the
 * same Autosar version */
#if ((POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION !=     \
      POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION !=     \
      POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION !=  \
      POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error \
    "AutoSar Version Numbers of Power_Ip_Specific.h and Power_Ip_Cfg_Defines.h are different"
#endif

/* Check if Power_Ip_Specific.h file and Power_Ip_Cfg_Defines.h file are of the
 * same Software version */
#if ((POWER_IP_SPECIFIC_SW_MAJOR_VERSION !=     \
      POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (POWER_IP_SPECIFIC_SW_MINOR_VERSION !=     \
      POWER_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (POWER_IP_SPECIFIC_SW_PATCH_VERSION !=     \
      POWER_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error \
    "Software Version Numbers of Power_Ip_Specific.h and Power_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define MC_RGM_FES_RWBITS_MASK32                                \
  ((uint32)(MC_RGM_FES_F_FR_31_MASK | MC_RGM_FES_F_FR_30_MASK | \
            MC_RGM_FES_F_FR_20_MASK | MC_RGM_FES_F_FR_4_MASK |  \
            MC_RGM_FES_F_FR_3_MASK | MC_RGM_FES_F_EXR_MASK))

#define MC_RGM_DES_RWBITS_MASK32                                \
  ((uint32)(MC_RGM_DES_F_DR_31_MASK | MC_RGM_DES_F_DR_30_MASK | \
            MC_RGM_DES_F_DR_18_MASK | MC_RGM_DES_F_DR_17_MASK | \
            MC_RGM_DES_F_DR_16_MASK | MC_RGM_DES_F_DR_15_MASK | \
            MC_RGM_DES_F_DR_14_MASK | MC_RGM_DES_F_DR_13_MASK | \
            MC_RGM_DES_F_DR_12_MASK | MC_RGM_DES_F_DR_11_MASK | \
            MC_RGM_DES_F_DR_10_MASK | MC_RGM_DES_F_DR_9_MASK |  \
            MC_RGM_DES_F_DR_8_MASK | MC_RGM_DES_F_DR_6_MASK |   \
            MC_RGM_DES_F_DR_4_MASK | MC_RGM_DES_F_DR_3_MASK |   \
            MC_RGM_DES_F_DR_1_MASK | MC_RGM_DES_F_POR_MASK))

#define MC_RGM_FES_IRQ_BITS_MASK \
  ((uint32)(MC_RGM_FES_F_FR_31_MASK | MC_RGM_FES_F_EXR_MASK))

#define MC_RGM_DES_IRQ_BITS_MASK ((uint32)0x00000000U)

#define MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ((uint32)0U)
#define MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ((uint32)8U)

#define MC_RGM_FERD_RWBITS_MASK \
  ((uint32)(MC_RGM_FES_F_FR_31_MASK | MC_RGM_FES_F_EXR_MASK))

/***********************************************************/
/*                       MC_RGM_RDSS                       */
/***********************************************************/
#define MC_RGM_FES_RES_OCCURED_DURING_STANDBY_U32 ((uint32)0xFFFFFFFFU)
#define MC_RGM_FES_RES_NOT_OCCURED_DURING_STANDBY_U32 ((uint32)0x00000000U)

#define MC_RGM_DES_RES_OCCURED_DURING_STANDBY_U32 (MC_RGM_RDSS_DES_RES_MASK)
#define MC_RGM_DES_RES_NOT_OCCURED_DURING_STANDBY_U32 ((uint32)0x00000000U)

#define MC_RGM_RDSS_RWBITS_MASK_U32 MC_RGM_RDSS_DES_RES_MASK

#define MC_RGM_RDSS_FES_RES_MASK_U32 ((uint32)0x00000000)
#define MC_RGM_RDSS_DES_RES_MASK_U32 MC_RGM_RDSS_DES_RES_MASK

/***********************************************************/
/*             MC_RGM_GetResetRawValue Defines             */
/***********************************************************/
#define MC_RGM_RAWRESET_FES_F_EXT_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x0U)  \
            << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_FES_FCCU_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x1U) \
            << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_FES_F_ST_DONE_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x2U)  \
            << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_FES_F_HSE_BOOT_ERR_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x3U)           \
            << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_FES_F_SW_FUNC_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x4U)  \
            << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_FES_F_DEBUG_FUNC_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x5U)     \
            << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32))

#define MC_RGM_RAWRESET_DES_F_POR_MASK32    \
  ((uint32)(((uint32)0x01U << (uint32)0x0U) \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_NC_SPD_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x1U)     \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_STCU_DEST_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x2U)        \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_STCU_URF_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x3U)   \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_MC_RGM_FRE_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x4U)     \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_FXOSC_FAIL_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x5U)     \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_CORE_LOL_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x6U)   \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_PERIPH_LOL_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x7U)     \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_DDR_LOL_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x8U)  \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_FCCU_DEST_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x9U)        \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_SYS_CLK_FAIL_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0xAU)       \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_RGM_FUNC_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0xBU)       \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_SMU_SWT_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0xCU)      \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_HSE_DEST_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0xDU)       \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_HSE_SNVS_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0xEU)       \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_HSE_SWT_RST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0xFU)      \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_SW_DEST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x10U) \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))
#define MC_RGM_RAWRESET_DES_F_DEBUG_DEST_MASK32 \
  ((uint32)(((uint32)0x01U << (uint32)0x11U)    \
            << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32))

#define MC_RGM_PRST0_COFB0_RSTEN_RWBITS_MASK ((uint32)0xFFFFFFFFU)
#define MC_RGM_PRST1_COFB0_RSTEN_RWBITS_MASK ((uint32)0x0000001FU)
#define MC_RGM_PRST2_COFB0_RSTEN_RWBITS_MASK ((uint32)0x000001FFU)
#define MC_RGM_PRST3_COFB0_RSTEN_RWBITS_MASK ((uint32)0x000001FFU)

#define MC_RGM_PRST0_COFB0_RSTEN_PERIPH_MASK ((uint32)0x03030118U)
#define MC_RGM_PRST1_COFB0_RSTEN_PERIPH_MASK ((uint32)0x0000001FU)
#define MC_RGM_PRST2_COFB0_RSTEN_PERIPH_MASK ((uint32)0x00000007U)
#define MC_RGM_PRST3_COFB0_RSTEN_PERIPH_MASK ((uint32)0x00000007U)

/***********************************************************/
/*               MC_RGM_PRST_MAIN_PRST_INDEX               */
/***********************************************************/
#define MC_RGM_PRST_MAIN_PRST_INDEX ((uint32)0U)

#define MC_RGM_PRST0_COFB0_RSTEN(value) \
  ((uint32)((uint32)(value) & MC_RGM_PRST0_COFB0_RSTEN_RWBITS_MASK))
#define MC_RGM_PRST1_COFB0_RSTEN(value) \
  ((uint32)((uint32)(value) & MC_RGM_PRST1_COFB0_RSTEN_RWBITS_MASK))
#define MC_RGM_PRST2_COFB0_RSTEN(value) \
  ((uint32)((uint32)(value) & MC_RGM_PRST2_COFB0_RSTEN_RWBITS_MASK))
#define MC_RGM_PRST3_COFB0_RSTEN(value) \
  ((uint32)((uint32)(value) & MC_RGM_PRST3_COFB0_RSTEN_RWBITS_MASK))

/***********************************************************/
/*                 MC_RGM_PRSTX_COFBX_RSTEN                */
/***********************************************************/
#define MC_RGM_MAIN_PRST_CORES_SHIFT ((uint32)0U)
#define MC_RGM_SECONDARY_PRST_CORES_SHIFT ((uint32)1U)

#define MC_RGM_PRST0_COFB0_RSTEN_CORES_MASK(CoreIndex) \
  ((uint32)(((uint32)0x01U << (uint32)(CoreIndex))     \
            << MC_RGM_MAIN_PRST_CORES_SHIFT))
#define MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(CoreIndex) \
  ((uint32)(((uint32)0x01U << (uint32)(CoreIndex))     \
            << MC_RGM_SECONDARY_PRST_CORES_SHIFT))
#define MC_RGM_PRST2_COFB0_RSTEN_CORES_MASK(CoreIndex) \
  ((uint32)(((uint32)0x01U << (uint32)(CoreIndex))     \
            << MC_RGM_SECONDARY_PRST_CORES_SHIFT))

#define MC_RGM_PRTN_RST_MASK MC_RGM_PRST_0_PERIPH_64_RST_MASK
/***********************************************************/
/*                    RDC_RDx_CTRL_REG                     */
/***********************************************************/
#define RDC_RDX_CTRL_REG_CTRL_LOCK ((uint32)0x00000000U)
#define RDC_RDX_CTRL_REG_CTRL_UNLOCK (RDC_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK)

#define RDC_RDX_CTRL_REG_ICON_INTF_ENABLE ((uint32)0x00000000U)
#define RDC_RDX_CTRL_REG_ICON_INTF_DISABLE \
  (RDC_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK)

/***********************************************************/
/*                    GPR3.RTUnFDC                     */
/***********************************************************/
#define GPR3_RTUX_FDC_FDREQ_LLC_DISABLE ((uint32)0x00000000U)
#define GPR3_RTUX_FDC_SRAM_KILL_ACCESS_DISABLE ((uint32)0x00000000U)
#define GPR3_RTUX_FDC_FDREQ_LLC_ENABLE (GPR3_RTU0FDC_FDREQ_LLC_MASK)
#define GPR3_RTUX_FDC_SRAM_KILL_ACCESS_ENABLE \
  (GPR3_RTU0FDC_SRAM_KILL_ACCESS_MASK)

/***********************************************************/
/*                     RDC_RDx_STAT_REG                    */
/***********************************************************/
#define RESET_RDX_CTRL_REG_RDX_INTERCONNECT_INTERFACE_DISABLE_VALUE_U32(value)    \
  ((uint32)((uint32)((value) &                                                    \
                     RDC_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK) >> \
            RDC_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_SHIFT))
#define RDC_RDX_STAT_REG_RDX_INTERCONNECT_INTERFACE_DISABLE_STAT_VALUE_U32(            \
    value)                                                                             \
  ((uint32)((uint32)((value) &                                                         \
                     RDC_RD1_STAT_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_STAT_MASK) >> \
            RDC_RD1_STAT_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_STAT_SHIFT))
#define RDC_RDX_STAT_REG_ICON_INTF_ENABLE ((uint32)0x00000000U)
#define RDC_RDX_STAT_REG_ICON_INTF_DISABLE \
  (RDC_RDX_STAT_REG_XBAR_INTF_DIS_STAT_MASK32)

#define RDC_RDX_STAT_REG_ICON_INTF_REQ_NACK ((uint32)0x00000000U)
#define RDC_RDX_STAT_REG_ICON_INTF_REQ_ACK \
  (RDC_RDX_STAT_REG_XBAR_INTF_DIS_REQ_ACK_STAT_MASK32)

#define MC_ME_PRTN0_PUPD_RWBITS_MASK ((uint32)(MC_ME_PRTN0_PUPD_PCUD_MASK))
#define MC_ME_PRTN1_PUPD_RWBITS_MASK \
  ((uint32)(MC_ME_PRTN1_PUPD_PCUD_MASK | MC_ME_PRTN1_PUPD_OSSUD_MASK))
#define MC_ME_PRTN2_PUPD_RWBITS_MASK \
  ((uint32)(MC_ME_PRTN2_PUPD_PCUD_MASK | MC_ME_PRTN2_PUPD_OSSUD_MASK))
#define MC_ME_PRTN3_PUPD_RWBITS_MASK \
  ((uint32)(MC_ME_PRTN3_PUPD_PCUD_MASK | MC_ME_PRTN3_PUPD_OSSUD_MASK))

#define MC_ME_PRTN0_COFB0_CLKEN_RWBITS_MASK     \
  ((uint32)(MC_ME_PRTN0_COFB0_CLKEN_REQ0_MASK | \
            MC_ME_PRTN0_COFB0_CLKEN_REQ1_MASK))

#define MC_ME_PRTN0_COFB0_CLKEN(value) \
  (((uint32)(((uint32)(value)) & MC_ME_PRTN0_COFB0_CLKEN_RWBITS_MASK)))

#define MC_ME_PRTN2_COFB0_CLKEN_RWBITS_MASK     \
  ((uint32)(MC_ME_PRTN2_COFB0_CLKEN_REQ0_MASK | \
            MC_ME_PRTN2_COFB0_CLKEN_REQ1_MASK | \
            MC_ME_PRTN2_COFB0_CLKEN_REQ2_MASK | \
            MC_ME_PRTN2_COFB0_CLKEN_REQ3_MASK))

#define MC_ME_PRTN2_COFB0_CLKEN(value) \
  (((uint32)(((uint32)(value)) & MC_ME_PRTN2_COFB0_CLKEN_RWBITS_MASK)))

#define MC_ME_PRTN3_COFB0_CLKEN_RWBITS_MASK ((uint32)0x00000000U)

#define MC_ME_PRTN3_COFB0_CLKEN(value) \
  (((uint32)(((uint32)(value)) & MC_ME_PRTN3_COFB0_CLKEN_RWBITS_MASK)))

/***********************************************************/
/*                    MC_ME_MAIN_COREID                    */
/***********************************************************/
#define MC_ME_MAIN_COREID_NOT_USED_U32 ((uint32)0xFFFFFFFFU)

#define MC_ME_MODE_CONF_MASK                 \
  ((uint32)(MC_ME_MODE_CONF_DEST_RST_MASK) | \
   (uint32)(MC_ME_MODE_CONF_FUNC_RST_MASK))

#define MC_ME_MODE_CONF(value) \
  ((uint32)(((uint32)(value)) & ((uint32)(MC_ME_MODE_CONF_MASK))))

/** Number of domains of the RESET module. */
#define POWER_IP_RESET_DOMAIN_COUNT (2u)
/** Number of instances of the RESET module. */
#define POWER_IP_RESET_INSTANCE_COUNT (1u)

#define POWER_IP_MC_ME_PRTN_COUNT (3U)
#define POWER_IP_MC_ME_CORE_COUNT (8U)

/** MC_RGM - Size of Registers Arrays */
#define POWER_IP_MC_RGM_PRST_COUNT (3U)
#define POWER_IP_MC_RGM_PSTAT_COUNT (3U)
#define POWER_IP_MC_RGM_PRST_COFB_MAX_COUNT (2U)

/**
 * @brief            This macro is used to define the position of the first
 * reset reason.
 *
 */
#define POWER_IP_FIRST_RESET_REASON_POS ((uint32)MCU_POWER_ON_RESET)

#define RESET_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK \
  RDC_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK
#define RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK \
  RDC_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK
#define RESET_RD1_STAT_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_STAT \
  RDC_RD1_STAT_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_STAT
#define RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE \
  RDC_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
typedef enum {
  /* 'Destructive' Event Status Register (MC_RGM_DES) */
  MCU_POWER_ON_RESET = McuConf_McuResetReasonConf_MCU_POWER_ON_RESET,
  MCU_NCSPD_RESET = McuConf_McuResetReasonConf_MCU_NCSPD_RESET,
  MCU_CSTCU_DEST_RESET = McuConf_McuResetReasonConf_MCU_CSTCU_DEST_RESET,
  MCU_CSTCU_URF_RESET = McuConf_McuResetReasonConf_MCU_CSTCU_URF_RESET,
  MCU_MC_RGM_FRE_RESET = McuConf_McuResetReasonConf_MCU_MC_RGM_FRE_RESET,
  MCU_FXOSC_FAIL_RESET = McuConf_McuResetReasonConf_MCU_FXOSC_FAIL_RESET,
  MCU_CORE_LOL_RESET = McuConf_McuResetReasonConf_MCU_CORE_LOL_RESET,
  MCU_PERIPH_LOL_RESET = McuConf_McuResetReasonConf_MCU_PERIPH_LOL_RESET,
  MCU_DDR_LOL_RESET = McuConf_McuResetReasonConf_MCU_DDR_LOL_RESET,
  MCU_FCCU_DEST_RST_RESET = McuConf_McuResetReasonConf_MCU_FCCU_DEST_RST_RESET,
  MCU_SYS_CLK_FAIL_RESET = McuConf_McuResetReasonConf_MCU_SYS_CLK_FAIL_RESET,
  MCU_RGM_FUNC_FST_TIMEOUT_RESET =
      McuConf_McuResetReasonConf_MCU_RGM_FUNC_FST_TIMEOUT_RESET,
  MCU_SMU_SWT_RST_RESET = McuConf_McuResetReasonConf_MCU_SMU_SWT_RST_RESET,
  MCU_HSE_DEST_RST_TMPR_RESET =
      McuConf_McuResetReasonConf_MCU_HSE_DEST_RST_TMPR_RESET,
  MCU_HSE_SNVS_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_SNVS_RST_RESET,
  MCU_HSE_SWT_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_SWT_RST_RESET,
  MCU_SW_DEST_RESET = McuConf_McuResetReasonConf_MCU_SW_DEST_RESET,
  MCU_DEBUG_DEST_RESET = McuConf_McuResetReasonConf_MCU_DEBUG_DEST_RESET,
  MCU_WAKEUP_REASON = McuConf_McuResetReasonConf_MCU_WAKEUP_REASON,
  MCU_NO_RESET_REASON = McuConf_McuResetReasonConf_MCU_NO_RESET_REASON,
  MCU_MULTIPLE_RESET_REASON =
      McuConf_McuResetReasonConf_MCU_MULTIPLE_RESET_REASON,
  MCU_RESET_UNDEFINED = McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED
} Power_Ip_ResetType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct {
  uint8 RESERVED_1[4];
  volatile uint32 RDC_CTRL_REG;
  uint8 RESERVED_2[124];
  volatile const uint32 RDC_STAT_REG;
} Power_Ip_RDC_Type;

typedef struct {
  volatile uint32 LVFCCUGD3;   /**< VFCCU Global DID register 3, offset: 0x0 */
  volatile uint32 LVFCCULD9;   /**< VFCCU Local DID register 9, offset: 0x4 */
  volatile uint32 LVFCCULD10;  /**< VFCCU Local DID register 10, offset: 0x8 */
  volatile uint32 LVFCCULD11;  /**< VFCCU Local DID register 11, offset: 0xC */
  volatile const uint32 DDRCS; /**< DDRC Status, offset: 0x10 */
  volatile uint32 DDRCC;       /**< DDRC Control, offset: 0x14 */
  volatile uint32 GENC0;       /**< Generic control register 0, offset: 0x18 */
  uint8 RESERVED_0[52];
  volatile const uint32
      INITM3; /**< NoC Initiator NIU Timeout Status, offset: 0x50 */
  volatile const uint32
      TARGTMS3;             /**< NoC Target NIU Timeout Status, offset: 0x54 */
  volatile uint32 TARGTMC3; /**< NoC Target NIU Timeout Control, offset: 0x58 */
  struct {                  /* offset: 0x5C, array step: 0x4 */
    volatile uint32 RTUFDC;
    volatile const uint32 RTUFDS;
  } RTUFD[2];
  uint8 RESERVED_1[4];
  volatile uint32
      CE0RSTCNT; /**< FlexLLCE Cortex-M33 Core 0 Reset Counter, offset: 0x70 */
  volatile uint32
      CE1RSTCNT; /**< FlexLLCE Cortex-M33 Core 1 Reset Counter, offset: 0x74 */
  volatile uint32 CLKOUT4SEL; /**< CLKOUT_4 MUX select, offset: 0x78 */
  uint8 RESERVED_2[4];
  volatile const uint32 XRDC_INT_S; /**< XRDC Interrupt Source, offset: 0x80 */
  uint8 RESERVED_3[32];
  volatile const uint32
      FLEXLLCECM33S; /**< FLEXLLCE CM33 Status, offset: 0xA4 */
  volatile const uint32
      FLEXLLCECM33CES; /**< FLEXLLCE CM33 CE Status, offset: 0xA8 */
  uint8 RESERVED_4[4];
  volatile uint32 LVFCCU3S;   /**< VFCCU Fault Status 3, offset: 0xB0 */
  volatile uint32 LVFCCU3S_2; /**< VFCCU Fault Status 3 for RTU and FlexLLCE,
                                 offset: 0xB4 */
  volatile uint32
      XPAR3; /**< Interface parity control and status register, offset: 0xB8 */
  volatile uint32
      XPAR4; /**< Interface parity control and status register, offset: 0xBC */
  volatile uint32
      RTU0XPAR; /**< RTU0 global parity control register, offset: 0xC0 */
  volatile uint32
      RTU1XPAR; /**< RTU1 global parity control register, offset: 0xC4 */
} Power_Ip_GPR3_type;

typedef struct {
  volatile uint32 PRTN_CORE_PCONF; /**< Partition Core Process Configuration
                                      Register, offset: 0x140 */
  volatile uint32 PRTN_CORE_PUPD;  /**< Partition Core Process Update Register,
                                      offset: 0x144 */
  volatile const uint32
      PRTN_CORE_STAT; /**< Partition Core Status Register, offset: 0x148 */
  volatile uint32
      PRTN_CORE_ADDR; /**< Partition Core Address Register, offset: 0x14C */
  uint8 RESERVED[16U];
} Power_Ip_MC_ME_Prtn_Core_Type;

typedef struct {
  volatile uint32 PRTN_PCONF; /**< Partition Process Configuration Register,
                                 offset: 0x100 */
  volatile uint32
      PRTN_PUPD; /**< Partition Process Update Register, offset: 0x104 */
  volatile const uint32
      PRTN_STAT; /**< Partition Status Register, offset: 0x108 */
  uint8 RESERVED_0[52U];
  Power_Ip_MC_ME_Prtn_Core_Type
      McMePrtnCoreArray[POWER_IP_MC_ME_CORE_COUNT]; /**< Partition Core Array */
  uint8 RESERVED_2[192U];
} Power_Ip_MC_ME_Prtn_Type;

typedef struct {
  volatile uint32 CTL_KEY;   /**< Control Key Register, offset: 0x0 */
  volatile uint32 MODE_CONF; /**< Mode Configuration Register, offset: 0x4 */
  volatile uint32 MODE_UPD;  /**< Mode Update Register, offset: 0x8 */
  uint8 RESERVED[244U];      /**< Reserved Register. */
  Power_Ip_MC_ME_Prtn_Type
      McMePrtnArray[POWER_IP_MC_ME_PRTN_COUNT]; /**< Partition Array */
} Power_Ip_MC_ME_Type;

/** MC_RGM - Register Layout Typedef */
typedef struct {
  volatile uint32 DES; /**< Destructive Event Status Register, offset: 0x0 */
  uint8 RESERVED_0[4]; /**< Reserved Register. */
  volatile uint32
      FES; /**< Functional /External Reset Status Register, offset: 0x8 */
  volatile uint32
      FERD; /**< Functional Event Reset Disable Register, offset: 0xC */
  volatile uint32
      FBRE; /**< Functional Bidirectional Reset Enable Register, offset: 0x10 */
  volatile uint32
      FREC; /**< Functional Reset Escalation Counter Register, offset: 0x14 */
  volatile uint32
      FRET; /**< Functional Reset Escalation Threshold Register, offset: 0x18 */
  volatile uint32 DRET;   /**< Destructive Reset Escalation Threshold Register,
                             offset: 0x1C */
  volatile uint32 ERCTRL; /**< External Reset Control Register, offset: 0x20 */
  uint8 RESERVED_1[4];    /**< Reserved Register. */
  volatile uint32 FRENTC; /**< Functional Reset Entry Timeout Control Register,
                             offset: 0x28 */
  uint8 RESERVED_2[20];   /**< Reserved Register. */
  struct {                /* offset: 0x40, array step: 0x8 */
    volatile uint32 PRST_COFB[POWER_IP_MC_RGM_PRST_COFB_MAX_COUNT];
  } PRST[POWER_IP_MC_RGM_PRST_COUNT]; /**< Peripheral Reset, array offset: 0x40,
                                         array step: 0x8 */
  uint8 RESERVED_3[232];              /**< Reserved Register. */
  struct {                            /* offset: 0x140, array step: 0x8 */
    volatile const uint32 PSTAT_COFB[POWER_IP_MC_RGM_PRST_COFB_MAX_COUNT];
  } PSTAT[POWER_IP_MC_RGM_PSTAT_COUNT]; /**< Peripheral Reset Status Register,
                                           array offset: 0x140, array step: 0x8
                                         */
} Power_Ip_MC_RGM_Type;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_SPECIFIC_H */
