/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef POWER_IP_CFG_DEFINES_H
#define POWER_IP_CFG_DEFINES_H

/**
 *   @file       Power_Ip_Cfg_Defines.h
 *   @version    3.0.0
 *
 *   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
 *   @details Code template for Post-Build(PB) configuration file generation.
 *
 *   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
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
#include "S32Z2_GPR0.h"
#include "S32Z2_GPR1.h"
#include "S32Z2_GPR2.h"
#include "S32Z2_GPR3.h"
#include "S32Z2_GPR4.h"
#include "S32Z2_GPR5.h"
#include "S32Z2_GPR6.h"
#include "S32Z2_MC_ME.h"
#include "S32Z2_MC_RGM.h"
#include "S32Z2_MSCM.h"
#include "S32Z2_PMC.h"
#include "S32Z2_RTUE_NIC_D.h"
#include "S32Z2_RTUF_NIC_D.h"
#include "S32Z2_RTUM_NIC_D.h"
#include "S32Z2_RTUP_NIC_B.h"
#include "S32Z2_RTU_GPR.h"
#include "S32Z2_SCB.h"
#include "StandardTypes.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_DEFINES_VENDOR_ID 43
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION 4
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION 7
#define POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION 0
#define POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION 1
#define POWER_IP_CFG_DEFINES_SW_MINOR_VERSION 0
#define POWER_IP_CFG_DEFINES_SW_PATCH_VERSION 0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_Cfg_Defines.h file and StandardTypes.h file are of the same
 * Autosar version */
#if ((POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != \
      STD_AR_RELEASE_MAJOR_VERSION) ||                 \
     (POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != \
      STD_AR_RELEASE_MINOR_VERSION))
#error \
    "AutoSar Version Numbers of Power_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/

/**
 * @brief            Derivative used.
 */
#define POWER_IP_DERIVATIVE_005

#define PMC_CONFIG_RWBITS_MASK                                             \
  (((uint32)PMC_CONFIG_LMEN_MASK) | ((uint32)PMC_CONFIG_LMBCTLEN_MASK) |   \
   ((uint32)PMC_CONFIG_FASTREC_MASK) | ((uint32)PMC_CONFIG_LPM25EN_MASK) | \
   ((uint32)PMC_CONFIG_LVRBLPEN_MASK) | ((uint32)PMC_CONFIG_HVDIE_MASK) |  \
   ((uint32)PMC_CONFIG_LVDIE_MASK) | ((uint32)PMC_CONFIG_LMAUTOEN_MASK))

/**
 * @brief            If this parameter is set to TRUE, the Reset Generation
 * Module (RGM) initialization has to be disabled from the MCU driver.
 */

#define POWER_IP_DISABLE_RGM_INIT (STD_OFF)

/**
 * @brief            If this parameter is set to TRUE, the Power Management
 * Controller (PMC) initialization has to be disabled from the MCU driver.
 */
#define POWER_IP_DISABLE_PMC_INIT (STD_OFF)

/**
 * @brief            If this parameter is set to TRUE, the Switched Mode Power
 * Supply (SMPS) initialization has to be disabled from the MCU driver.
 */
#define POWER_IP_ENABLE_SMPS_INIT (STD_OFF)

/**
 * @brief            Support for Low Power mode.
 */
#define POWER_IP_ENTER_LOW_POWER_MODE (STD_OFF)

/**
 * @brief
 */
#define POWER_IP_PERFORM_RESET_API (STD_ON)

/**
 * @brief            Configure PRTNm_COREn_ADDR registers
 */
#define POWER_IP_CONFIGURE_CADDRN (STD_OFF)

/**
 * @brief            Support for Functional Reset Disable (FERD regiter
 * present).
 */
#define POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT (STD_ON)

/**
 * @brief            Max number of MC_ME partitions.
 */
#define POWER_IP_MAX_NUMBER_OF_PARTITIONS ((uint8)3U)

/**
 * @brief            Support for lockstep configuration (PTRNx_CORE_LOCKSTEP)
 * registers.
 */
#define POWER_IP_LOCKSTEP_CTRL_SUPPORT (STD_OFF)

/**
 * @brief            ISR Mcu_ResetAlternate_ISR is/is not available
 * (STD_ON/STD_OFF)
 */
#define POWER_IP_RESET_ALTERNATE_ISR_USED (STD_OFF)

/**
 * @brief
 */
#define POWER_IP_HAS_OUTPUT_SAFE_STATE (STD_OFF)

/**
 * @brief
 */
#define POWER_IP_RESET_DURING_STANDBY_SUPPORTED (STD_ON)

#define POWER_IP_RESET_DOMAINS_SUPPORTED (STD_OFF)

/**
 * @brief            PMC_AE Configuration Register (CONFIG) and PMC_AE Monitor
 * Register (MONITOR).
 */
#define POWER_IP_PMC_AE_SUPPORT (STD_OFF)

/**
 * @brief            AEC Configuration Register (RSTGEN_CFG).
 */
#define POWER_IP_AEC_SUPPORT (STD_OFF)

/**
 * @brief            Enable the usage of Non-Autosar API Power_Ip_PmcAeConfig().
 */
#define POWER_IP_PMCAECONFIG_API (STD_OFF)

/**
 * @brief            Enable the usage of Non-Autosar API
 * Power_Ip_AecResetConfig().
 */
#define POWER_IP_AECRESETCONFIG_API (STD_OFF)

/**
 * @brief            ISR Mcu_PMC_UnderOverVoltage_ISR is/is not available
 * (STD_ON/STD_OFF)
 */
#define POWER_IP_VOLTAGE_ERROR_ISR_USED (STD_OFF)

/**
 * @brief            Create defines with the values assigned to Mcu Reset Reason
 * configurations. These values can be  retrieved from Mcu_GetResetReason Api.
 */

#define McuConf_McuResetReasonConf_MCU_POWER_ON_RESET ((uint8)0U)

#define McuConf_McuResetReasonConf_MCU_NCSPD_RESET ((uint8)1U)

#define McuConf_McuResetReasonConf_MCU_CSTCU_DEST_RESET ((uint8)3U)

#define McuConf_McuResetReasonConf_MCU_CSTCU_URF_RESET ((uint8)4U)

#define McuConf_McuResetReasonConf_MCU_MC_RGM_FRE_RESET ((uint8)6U)

#define McuConf_McuResetReasonConf_MCU_FXOSC_FAIL_RESET ((uint8)8U)

#define McuConf_McuResetReasonConf_MCU_CORE_LOL_RESET ((uint8)9U)

#define McuConf_McuResetReasonConf_MCU_PERIPH_LOL_RESET ((uint8)10U)

#define McuConf_McuResetReasonConf_MCU_DDR_LOL_RESET ((uint8)11U)

#define McuConf_McuResetReasonConf_MCU_FCCU_DEST_RST_RESET ((uint8)12U)

#define McuConf_McuResetReasonConf_MCU_SYS_CLK_FAIL_RESET ((uint8)13U)

#define McuConf_McuResetReasonConf_MCU_RGM_FUNC_FST_TIMEOUT_RESET ((uint8)14U)

#define McuConf_McuResetReasonConf_MCU_SMU_SWT_RST_RESET ((uint8)15U)

#define McuConf_McuResetReasonConf_MCU_HSE_DEST_RST_TMPR_RESET ((uint8)16U)

#define McuConf_McuResetReasonConf_MCU_HSE_SNVS_RST_RESET ((uint8)17U)

#define McuConf_McuResetReasonConf_MCU_HSE_SWT_RST_RESET ((uint8)18U)

#define McuConf_McuResetReasonConf_MCU_SW_DEST_RESET ((uint8)30U)

#define McuConf_McuResetReasonConf_MCU_DEBUG_DEST_RESET ((uint8)31U)

#define McuConf_McuResetReasonConf_MCU_WAKEUP_REASON ((uint8)32U)

#define McuConf_McuResetReasonConf_MCU_NO_RESET_REASON ((uint8)33U)

#define McuConf_McuResetReasonConf_MCU_MULTIPLE_RESET_REASON ((uint8)34U)

#define McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED ((uint8)35U)
/**
 * @brief           This define controls the availability of function
 * Mcu_SleepOnExit
 */
#define POWER_IP_SLEEPONEXIT_SUPPORT (STD_ON)

#define POWER_IP_WARM_RESET_SUPPORT (STD_ON)

#define POWER_IP_PERIPHERAL_GROUPS_COUNT 6U

#define POWER_IP_PERIPHERALS_NO 6U
#define POWER_IP_DMACRC0_PCLT_INDEX 1U
#define POWER_IP_DMACRC1_PCLT_INDEX
#define POWER_IP_DMACRC4_PCLT_INDEX
#define POWER_IP_DMACRC5_PCLT_INDEX
#define POWER_IP_NANO_PCLT_INDEX
#define POWER_IP_DMAMUX0_PCLT_INDEX
#define POWER_IP_DMAMUX1_PCLT_INDEX
#define POWER_IP_DMAMUX4_PCLT_INDEX
#define POWER_IP_DMAMUX5_PCLT_INDEX
#define POWER_IP_PIT_0_PCLT_INDEX
#define POWER_IP_PIT_1_PCLT_INDEX
#define POWER_IP_PIT_4_PCLT_INDEX
#define POWER_IP_PIT_5_PCLT_INDEX

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_DEFINES_H */
