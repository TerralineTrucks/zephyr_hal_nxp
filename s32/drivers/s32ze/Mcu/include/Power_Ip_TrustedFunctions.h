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
*   Build Version        : S32ZE_RTD_1_0_0_P02_D2310_ASR_REL_4_7_REV_0000_20231030
*
*   Copyright 2021-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef POWER_IP_TRUSTEDFUNCTIONS_H
#define POWER_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Power_Ip_TrustedFunctions.h
*   @version    1.0.0
*
*   @brief   POWER IP type header file.
*   @details POWER IP type header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "StandardTypes.h"
#include "Power_Ip_Cfg.h"
#include "Power_Ip_Specific.h"
#include "Power_Ip_Types.h"
#include "Mcal.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                1
#define POWER_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define POWER_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_TrustedFunctions.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_TrustedFunctions.h and StandardTypes.h are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_TrustedFunctions.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_TrustedFunctions.h and Mcal.h are different"
#endif
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Cfg.h file have same versions */
#if (POWER_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != POWER_IP_CFG_VENDOR_ID)
    #error "Power_Ip_TrustedFunctions.h and Power_Ip_Cfg.h have different vendor IDs"
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Cfg.h file are of the same Autosar version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != POWER_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_TrustedFunctions.h and Power_Ip_Cfg.h are different"
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Cfg.h file are of the same Software version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != POWER_IP_CFG_SW_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != POWER_IP_CFG_SW_MINOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != POWER_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_TrustedFunctions.h and Power_Ip_Cfg.h are different"
#endif


/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Specific.h file have same versions */
#if (POWER_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != POWER_IP_SPECIFIC_VENDOR_ID)
    #error "Power_Ip_TrustedFunctions.h and Power_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Specific.h file are of the same Autosar version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_TrustedFunctions.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Specific.h file are of the same Software version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != POWER_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != POWER_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != POWER_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_TrustedFunctions.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Types.h file have same versions */
#if (POWER_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != POWER_IP_TYPES_VENDOR_ID)
    #error "Power_Ip_TrustedFunctions.h and Power_Ip_Types.h have different vendor IDs"
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Types.h file are of the same Autosar version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != POWER_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_TrustedFunctions.h and Power_Ip_Types.h are different"
#endif

/* Check if Power_Ip_TrustedFunctions.h file and Power_Ip_Types.h file are of the same Software version */
#if ((POWER_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != POWER_IP_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != POWER_IP_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != POWER_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_TrustedFunctions.h and Power_Ip_Types.h are different"
#endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
/**
 * @brief        The function enables SLEEPONEXIT bit.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CM33_EnableSleepOnExit(void);

/**
 * @brief        The function disables SLEEPONEXIT bit.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CM33_DisableSleepOnExit(void);
  #endif
#endif

#ifdef POWER_IP_WARM_RESET_SUPPORT
#if (POWER_IP_WARM_RESET_SUPPORT == STD_ON)
/**
 * @brief        The function request a Warm reset.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CortexM_WarmReset(void);
#endif
#endif

/**
* @brief        The function disable SLEEPDEEP bit.
*
* @param[in]    none
* @return void
*/
extern void Power_Ip_CM33_DisableDeepSleep(void);

/**
* @brief        The function enable SLEEPDEEP bit.
*
* @param[in]    none
* @return void
*/
extern void Power_Ip_CM33_EnableDeepSleep(void);


/**
 * @brief        This function initializes the Reset parameters.
 *
 * @param        ConfigPtr   Pointer to the MC_RGM configuration structure.
 * @return       None
 *
 */
extern void Power_Ip_MC_RGM_ResetInit(const Power_Ip_MC_RGM_ConfigType * ConfigPtr);


#if (defined(POWER_IP_PERFORM_RESET_API))
  #if (POWER_IP_PERFORM_RESET_API == STD_ON)
/**
 * @brief        This function performs a microcontroller reset.
 *
 * @param        ConfigPtr   Pointer to the MC_RGM configuration structure.
 * @return       None
 *
 */
extern void Power_Ip_MC_RGM_PerformReset(const Power_Ip_MC_RGM_ConfigType * ConfigPtr);
  #endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */
#endif

/**
 * @brief        This function returns the Reset reason.
 *
 * @param        None
 * @return       Reason of the Reset event.
 *
 */
extern Power_Ip_ResetType Power_Ip_MC_RGM_GetResetReason(void);

/**
 * @brief        This function returns the Raw Reset value.
 *
 * @param        None
 * @return       Implementation-specific value with the Reset status.
 *
 */
extern Power_Ip_RawResetType Power_Ip_MC_RGM_GetResetRawValue(void);

#if (defined(POWER_IP_RESET_DOMAINS_SUPPORTED))
  #if (POWER_IP_RESET_DOMAINS_SUPPORTED == STD_ON)
/**
 * @brief        Request mode configuration from MC_RGM.
 *
 * @param        MC_RGM Mode Domain Settings.
 * @return       None
 *
 */
extern void Power_Ip_MC_RGM_ModeConfig(const Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr);

/**
 * @brief         Check mode configuration from MC_RGM.
 *
 * @param        MC_RGM Mode Domain Settings.
 * @return       None
 *
 */
extern void Power_Ip_MC_RGM_CheckModeConfig(const Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr);

/**
 * @brief        Enable interconnect interface of Software Reset Domain base on configuration of McuPartitionResetEnable.
 *
 * @param        MC_RGM Mode Domain Settings.
 * @return       None
 *
 */
extern void Power_Ip_MC_RGM_EnableResetDomain(const Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr);

/**
 * @brief        Disable interconnect interface of Software Reset Domain base on configuration of McuPartitionResetEnable.
 *
 * @param        MC_RGM Mode Domain Settings.
 * @return       None
 *
 */
extern void Power_Ip_MC_RGM_DisableResetDomain(const Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr);
  #endif /* (POWER_IP_RESET_DOMAINS_SUPPORTED == STD_ON) */
#endif

/**
 * @brief        This function configure the Power Management Controller
 *
 * @param        ConfigPtr   Pointer to PMC configuration structure.
 * @return       None
 *
 */
extern void Power_Ip_PMC_PowerInit(const Power_Ip_PMC_ConfigType * ConfigPtr);

#if (defined(POWER_IP_ENTER_LOW_POWER_MODE))
  #if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
/**
 * @brief        This function prepares the PMC module for Standby/Low Power entry.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_PMC_PrepareLowPowerEntry(void);
  #endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
#endif

#if (defined(MCAL_MC_ME_REG_PROT_AVAILABLE))
 #if (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE)
/**
 * @brief        This function will enable writing in User mode by configuring REG_PROT
 *
 * @param        None
 * @return       None
 *
 */
void Power_Ip_MC_ME_SetUserAccessAllowed(void);
 #endif /* (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE) */
#endif

#if (defined(MCAL_PMC_REG_PROT_AVAILABLE))
 #if (STD_ON == MCAL_PMC_REG_PROT_AVAILABLE)
/**
 * @brief        This function will enable writing in User mode by configuring REG_PROT
 *
 * @param        None
 * @return       None
 *
 */
void Power_Ip_PMC_SetUserAccessAllowed(void);
 #endif /* (STD_ON == MCAL_PMC_REG_PROT_AVAILABLE) */
#endif

#if (defined(MCAL_MC_RGM_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_MC_RGM_REG_PROT_AVAILABLE)
/**
 * @brief        This function will enable writing in User mode by configuring REG_PROT
 *
 * @param        None
 * @return       None
 *
 */
void Power_Ip_MC_RGM_SetUserAccessAllowed(void);
  #endif /* (STD_ON == MCAL_MC_RGM_REG_PROT_AVAILABLE) */
#endif

#if (defined(MCAL_RDC_REG_PROT_AVAILABLE))
 #if (STD_ON == MCAL_RDC_REG_PROT_AVAILABLE)

/**
 * @brief        This function will enable writing in User mode by configuring REG_PROT
 *
 * @param        None
 * @return       None
 *
 */
void Power_Ip_RDC_SetUserAccessAllowed(void);
 #endif /* (STD_ON == MCAL_RDC_REG_PROT_AVAILABLE) */
#endif

#if (defined(MCAL_RTU_GPR_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE)
      
/**
 * @brief        This function will enable writing in User mode by configuring REG_PROT for RTU.GPR
 *
 * @param        None
 * @return       None
 *
 */
void Power_Ip_RTU_GPR_SetUserAccessAllowed(void);
  #endif
#endif

  #endif
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */


/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_TRUSTEDFUNCTIONS_H */


