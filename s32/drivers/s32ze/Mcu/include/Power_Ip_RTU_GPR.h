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

#ifndef POWER_IP_RTU_GPR_H
#define POWER_IP_RTU_GPR_H

/**
*   @file       Power_Ip_RTU_GPR.h
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
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Types.h"
#include "StandardTypes.h"
#include "Mcal.h"
#include "Power_Ip_Specific.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_RTU_GPR_VENDOR_ID                       43
#define POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_RTU_GPR_SW_MAJOR_VERSION                1
#define POWER_IP_RTU_GPR_SW_MINOR_VERSION                0
#define POWER_IP_RTU_GPR_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_RTU_GPR.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RTU_GPR.h and StandardTypes.h are different"
#endif

/* Check if Power_Ip_RTU_GPR.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RTU_GPR.h and Mcal.h are different"
#endif
#endif

/* Check if Power_Ip_RTU_GPR.h file and Power_Ip_Types.h file have same versions */
#if (POWER_IP_RTU_GPR_VENDOR_ID  != POWER_IP_TYPES_VENDOR_ID)
    #error "Power_Ip_RTU_GPR.h and Power_Ip_Types.h have different vendor IDs"
#endif

/* Check if Power_Ip_RTU_GPR.h file and Power_Ip_Types.h file are of the same Autosar version */
#if ((POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION != POWER_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RTU_GPR.h and Power_Ip_Types.h are different"
#endif

/* Check if Power_Ip_RTU_GPR.h file and Power_Ip_Types.h file are of the same Software version */
#if ((POWER_IP_RTU_GPR_SW_MAJOR_VERSION != POWER_IP_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_MINOR_VERSION != POWER_IP_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_PATCH_VERSION != POWER_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_RTU_GPR.h and Power_Ip_Types.h are different"
#endif

/* Check if Power_Ip_RTU_GPR.h file and Power_Ip_Specific.h file have same versions */
#if (POWER_IP_RTU_GPR_VENDOR_ID  != POWER_IP_SPECIFIC_VENDOR_ID)
    #error "Power_Ip_RTU_GPR.h and Power_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Power_Ip_RTU_GPR.h file and Power_Ip_Specific.h file are of the same Autosar version */
#if ((POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION != POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RTU_GPR.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_RTU_GPR.h file and Power_Ip_Specific.h file are of the same Software version */
#if ((POWER_IP_RTU_GPR_SW_MAJOR_VERSION != POWER_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_MINOR_VERSION != POWER_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_PATCH_VERSION != POWER_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_RTU_GPR.h and Power_Ip_Specific.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define RTU_GPR_CFG_FD_RWBITS_MASK32 ((uint32)((uint32)RTU_GPR_CFG_FD_MFDEN0_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_MFDEN1_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_MFDEN2_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_MFDEN3_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_FFDEN0_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_FFDEN1_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_FFDEN2_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_FFDEN3_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_LFDEN0_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_LFDEN1_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_LFDEN2_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_LFDEN3_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_SFDEN_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_ISOLEN0_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_ISOLEN1_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_ISOLEN2_MASK | \
                                               (uint32)RTU_GPR_CFG_FD_ISOLEN3_MASK))

#define RTU_GPR_CFG_FD_ISOLENX_RWBITS_MASK32     ((uint32)((uint32)RTU_GPR_CFG_FD_ISOLEN0_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_ISOLEN1_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_ISOLEN2_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_ISOLEN3_MASK))

#define RTU_GPR_CFG_FD_MFD_FFD_LFD_RWBITS_MASK32 ((uint32)((uint32)RTU_GPR_CFG_FD_MFDEN0_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_MFDEN1_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_MFDEN2_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_MFDEN3_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_FFDEN0_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_FFDEN1_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_FFDEN2_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_FFDEN3_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_LFDEN0_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_LFDEN1_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_LFDEN2_MASK | \
                                                           (uint32)RTU_GPR_CFG_FD_LFDEN3_MASK))

#define RTU_GPR_STAT_FD_MASK32                   ((uint32)((uint32)RTU_GPR_STAT_FD_MFDID0_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_MFDID1_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_MFDID2_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_MFDID3_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID0_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID1_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID2_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID3_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID0_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID1_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID2_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID3_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_SFDID_MASK))

#define RTU_GPR_STAT_FD_MFD_FFD_LFD_MASK32        ((uint32)((uint32)RTU_GPR_STAT_FD_MFDID0_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_MFDID1_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_MFDID2_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_MFDID3_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID0_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID1_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID2_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_FFDID3_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID0_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID1_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID2_MASK | \
                                                           (uint32)RTU_GPR_STAT_FD_LFDID3_MASK))

#define RTU_GPR_CFG_FD_MFDEN(CoreIndex)                    ((uint32)(0x1UL << (CoreIndex)))
#define RTU_GPR_CFG_FD_FFDEN(CoreIndex)                    ((uint32)(0x10UL << (CoreIndex)))
#define RTU_GPR_CFG_FD_LFDEN(CoreIndex)                    ((uint32)(0x100UL << (CoreIndex)))
#define RTU_GPR_CFG_FD_ISOLEN(CoreIndex)                   ((uint32)(0x10000000U << (CoreIndex)))
#define RTU_GPR_CFG_FD_MFDID_FFDID_LFDID_ISOLEN(CoreIndex) ((uint32)((0x1UL << (CoreIndex)) | (0x10UL << (CoreIndex)) | (0x100UL << (CoreIndex)) | (0x10000000U << (CoreIndex))))

#define RTU_GPR_STAT_FD_MFDID(CoreIndex)                   ((uint32)(0x1UL << (CoreIndex)))
#define RTU_GPR_STAT_FD_FFDID(CoreIndex)                   ((uint32)(0x10UL << (CoreIndex)))
#define RTU_GPR_STAT_FD_LFDID(CoreIndex)                   ((uint32)(0x100UL << (CoreIndex)))

#define RTU_GPR_STAT_FD_MFDID_FFDID_LFDID(CoreIndex)       ((uint32)((0x1UL << (CoreIndex)) | (0x10UL << (CoreIndex)) | (0x100UL << (CoreIndex))))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
    #if (defined(MCAL_RTU_GPR_REG_PROT_AVAILABLE))
      #if (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE)
void Power_Ip_RTU_GPR_SetUserAccessAllowed(void);
      #endif /* (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE) */
    #endif
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */



#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
        #define  Call_Power_Ip_RTU_GPR_FenceDrainDomainController(DomainIndex,Active)            OsIf_Trusted_Call2params(Power_Ip_RTU_GPR_FenceDrainDomainController,(DomainIndex),(Active))
        #define  Call_Power_Ip_RTU_GPR_FenceDrainCoreController(DomainIndex,CoreIndex,Active)    OsIf_Trusted_Call3params(Power_Ip_RTU_GPR_FenceDrainCoreController,(DomainIndex),(CoreIndex),(Active))
        #define  Call_Power_Ip_RTU_GPR_CoreHaltConfig(DomainIndex,CoreIndex,Enable)              OsIf_Trusted_Call3params(Power_Ip_RTU_GPR_CoreHaltConfig,(DomainIndex),(CoreIndex),(Enable))
        #define  Call_Power_Ip_RTU_GPR_CheckTcmBooting(DomainIndex)                              OsIf_Trusted_Call_Return1param(Power_Ip_RTU_GPR_CheckTcmBooting,(DomainIndex))
        #define  Call_Power_Ip_RTU_GPR_SetLockstepMode(DomainIndex, Active)                      OsIf_Trusted_Call2params(Power_Ip_RTU_GPR_SetLockstepMode,(DomainIndex), (Active))
        #define  Call_Power_Ip_RTU_GPR_CheckEnLockStepMode(DomainIndex)                          OsIf_Trusted_Call_Return1param(Power_Ip_RTU_GPR_CheckEnLockStepMode,(DomainIndex))
        #define  Call_Power_Ip_RTU_GPR_CoreReleaseQuiesceState(DomainIndex,CoreIndex)            OsIf_Trusted_Call2params(Power_Ip_RTU_GPR_CoreReleaseQuiesceState,(DomainIndex),(CoreIndex))
    #else
        #define  Call_Power_Ip_RTU_GPR_FenceDrainDomainController(DomainIndex,Active)            Power_Ip_RTU_GPR_FenceDrainDomainController(DomainIndex,Active)
        #define  Call_Power_Ip_RTU_GPR_FenceDrainCoreController(DomainIndex,CoreIndex,Active)    Power_Ip_RTU_GPR_FenceDrainCoreController(DomainIndex,CoreIndex,Active)
        #define  Call_Power_Ip_RTU_GPR_CoreHaltConfig(DomainIndex,CoreIndex,Enable)              Power_Ip_RTU_GPR_CoreHaltConfig(DomainIndex,CoreIndex,Enable)
        #define  Call_Power_Ip_RTU_GPR_CheckTcmBooting(DomainIndex)                              Power_Ip_RTU_GPR_CheckTcmBooting(DomainIndex)
        #define  Call_Power_Ip_RTU_GPR_CheckEnLockStepMode(DomainIndex)                          Power_Ip_RTU_GPR_CheckEnLockStepMode(DomainIndex)        
        #define  Call_Power_Ip_RTU_GPR_SetLockstepMode(DomainIndex, Active)                      Power_Ip_RTU_GPR_SetLockstepMode(DomainIndex, Active)
        #define  Call_Power_Ip_RTU_GPR_CoreReleaseQuiesceState(DomainIndex,CoreIndex)            Power_Ip_RTU_GPR_CoreReleaseQuiesceState(DomainIndex,CoreIndex)
    #endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#else /* POWER_IP_ENABLE_USER_MODE_SUPPORT */
    #define  Call_Power_Ip_RTU_GPR_FenceDrainDomainController(DomainIndex,Active)                Power_Ip_RTU_GPR_FenceDrainDomainController(DomainIndex,Active)
    #define  Call_Power_Ip_RTU_GPR_FenceDrainCoreController(DomainIndex,CoreIndex,Active)        Power_Ip_RTU_GPR_FenceDrainCoreController(DomainIndex,CoreIndex,Active)
    #define  Call_Power_Ip_RTU_GPR_CoreHaltConfig(DomainIndex,CoreIndex,Enable)                  Power_Ip_RTU_GPR_CoreHaltConfig(DomainIndex,CoreIndex,Enable)
    #define  Call_Power_Ip_RTU_GPR_CheckTcmBooting(DomainIndex)                                  Power_Ip_RTU_GPR_CheckTcmBooting(DomainIndex)
    #define  Call_Power_Ip_RTU_GPR_SetLockstepMode(DomainIndex, Active)                          Power_Ip_RTU_GPR_SetLockstepMode(DomainIndex, Active)
    #define  Call_Power_Ip_RTU_GPR_CheckEnLockStepMode(DomainIndex)                              Power_Ip_RTU_GPR_CheckEnLockStepMode(DomainIndex)
    #define  Call_Power_Ip_RTU_GPR_CoreReleaseQuiesceState(DomainIndex,CoreIndex)                Power_Ip_RTU_GPR_CoreReleaseQuiesceState(DomainIndex,CoreIndex)
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */

void Power_Ip_RTU_GPR_FenceDrainDomainController(uint8 DomainIndex, boolean Active);

void Power_Ip_RTU_GPR_FenceDrainCoreController(uint8 DomainIndex, uint8 CoreIndex, boolean Active);

void Power_Ip_RTU_GPR_CoreHaltConfig(uint8 DomainIndex, uint8 CoreIndex, boolean Enable);

uint8 Power_Ip_RTU_GPR_CheckTcmBooting(uint8 DomainIndex);

void Power_Ip_RTU_GPR_SetLockstepMode(uint8 DomainIndex, boolean Active);

uint8 Power_Ip_RTU_GPR_CheckEnLockStepMode(uint8 DomainIndex);

void Power_Ip_RTU_GPR_CoreReleaseQuiesceState(uint8 DomainIndex, uint8 CoreIndex);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_RTU_GPR_H */
