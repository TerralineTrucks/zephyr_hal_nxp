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

#ifndef POWER_IP_CORTEXM33_H
#define POWER_IP_CORTEXM33_H

/**
*   @file       Power_Ip_CortexM33.h
*   @version    1.0.0
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Types.h"
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CORTEXM33_VENDOR_ID                    43
#define POWER_IP_CORTEXM33_AR_RELEASE_MAJOR_VERSION     4
#define POWER_IP_CORTEXM33_AR_RELEASE_MINOR_VERSION     7
#define POWER_IP_CORTEXM33_AR_RELEASE_REVISION_VERSION  0
#define POWER_IP_CORTEXM33_SW_MAJOR_VERSION             1
#define POWER_IP_CORTEXM33_SW_MINOR_VERSION             0
#define POWER_IP_CORTEXM33_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_CortexM33.h file and Power_Ip_Types.h file have same versions */
#if (POWER_IP_CORTEXM33_VENDOR_ID  != POWER_IP_TYPES_VENDOR_ID)
    #error "Power_Ip_CortexM33.h and Power_Ip_Types.h have different vendor IDs"
#endif

/* Check if Power_Ip_CortexM33.h file and Power_Ip_Types.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXM33_AR_RELEASE_MAJOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM33_AR_RELEASE_MINOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CORTEXM33_AR_RELEASE_REVISION_VERSION != POWER_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_CortexM33.h and Power_Ip_Types.h are different"
#endif

/* Check if Power_Ip_CortexM33.h file and Power_Ip_Types.h file are of the same Software version */
#if ((POWER_IP_CORTEXM33_SW_MAJOR_VERSION != POWER_IP_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM33_SW_MINOR_VERSION != POWER_IP_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_CORTEXM33_SW_PATCH_VERSION != POWER_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_CortexM33.h and Power_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_CortexM33.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXM33_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM33_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_CortexM33.h and Mcal.h are different"
#endif
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/***********************************************************/
/*          CortexM33 System Control Register               */
/***********************************************************/
#define CM33_SCR_BASEADDR                   ((uint32)0xE000E000U)

#define CM33_SCR_SLEEPONEXIT_MASK32         ((uint32)0x00000002U)
#define CM33_SCR_SLEEPDEEP_MASK32           ((uint32)0x00000004U)

/* Memory mapping of Cortex-M Hardware */
/* Application Interrupt and Reset Control Register */

#define CM_AIRCR_ADDR32                     ((uint32)0xE000ED0CU)               /* System Control Block Base Address  */

/** CM33 AIRCR base pointer */
#define IP_CM_AIRCR                         (*(volatile uint32*)(CM_AIRCR_ADDR32))

#define CM_AIRCR_SYSRESETREQ_MASK32         ((uint32)0x4U)
#define CM_AIRCR_VECTKEY_MASK32             ((uint32)0xFFFF0000U)
#define CM_AIRCR_VECTKEY_SHIFT32            ((uint32)16U)

/**
* @violates @ref Reg_eSys_CortexM_H_REF_1 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define CM_AIRCR_VECTKEY(x)                 ((uint32)( (uint32)( (x) << CM_AIRCR_VECTKEY_SHIFT32 ) & CM_AIRCR_VECTKEY_MASK32 ))

#define CM_AIRCR_VECTKEY_KEY_U32            ((uint32)0x000005FAU)
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
        #define  Call_Power_Ip_CM33_EnableSleepOnExit()     OsIf_Trusted_Call(Power_Ip_CM33_EnableSleepOnExit)
        #define  Call_Power_Ip_CM33_DisableSleepOnExit()    OsIf_Trusted_Call(Power_Ip_CM33_DisableSleepOnExit)
    #else   
        #define  Call_Power_Ip_CM33_EnableSleepOnExit()     Power_Ip_CM33_EnableSleepOnExit()
        #define  Call_Power_Ip_CM33_DisableSleepOnExit()    Power_Ip_CM33_DisableSleepOnExit()
    #endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#else /* POWER_IP_ENABLE_USER_MODE_SUPPORT */
    #define  Call_Power_Ip_CM33_EnableSleepOnExit()         Power_Ip_CM33_EnableSleepOnExit()
    #define  Call_Power_Ip_CM33_DisableSleepOnExit()        Power_Ip_CM33_DisableSleepOnExit()
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */

#endif /* POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON */
#endif /* POWER_IP_SLEEPONEXIT_SUPPORT */

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
        #define  Call_Power_Ip_CM33_EnableDeepSleep()    OsIf_Trusted_Call(Power_Ip_CM33_EnableDeepSleep)
        #define  Call_Power_Ip_CM33_DisableDeepSleep()   OsIf_Trusted_Call(Power_Ip_CM33_DisableDeepSleep)
    #else   
        #define  Call_Power_Ip_CM33_EnableDeepSleep()    Power_Ip_CM33_EnableDeepSleep()
        #define  Call_Power_Ip_CM33_DisableDeepSleep()   Power_Ip_CM33_DisableDeepSleep()
    #endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#else /* POWER_IP_ENABLE_USER_MODE_SUPPORT */
    #define  Call_Power_Ip_CM33_EnableDeepSleep()        Power_Ip_CM33_EnableDeepSleep()
    #define  Call_Power_Ip_CM33_DisableDeepSleep()       Power_Ip_CM33_DisableDeepSleep()
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */

#ifdef POWER_IP_WARM_RESET_SUPPORT
#if (POWER_IP_WARM_RESET_SUPPORT == STD_ON)

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
        #define Call_Power_Ip_CortexM_WarmReset()   OsIf_Trusted_Call(Power_Ip_CortexM_WarmReset)
    #else
        #define Call_Power_Ip_CortexM_WarmReset()   Power_Ip_CortexM_WarmReset()
    #endif
#else
    #define Call_Power_Ip_CortexM_WarmReset()       Power_Ip_CortexM_WarmReset()
#endif

#endif
#endif

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
  #if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
void Power_Ip_CM33_EnableSleepOnExit(void);
void Power_Ip_CM33_DisableSleepOnExit(void);
  #endif
#endif

void Power_Ip_CM33_DisableDeepSleep(void);
void Power_Ip_CM33_EnableDeepSleep(void);

#ifdef POWER_IP_WARM_RESET_SUPPORT
#if (POWER_IP_WARM_RESET_SUPPORT == STD_ON)
void Power_Ip_CortexM_WarmReset(void);
#endif
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_CORTEXM33_H */

