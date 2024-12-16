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

/**
*   @file       Power_Ip_MSCM.c
*   @version    1.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
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
#include "Power_Ip_MSCM.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_MSCM_VENDOR_ID_C                        43
#define POWER_IP_MSCM_AR_RELEASE_MAJOR_VERSION_C         4
#define POWER_IP_MSCM_AR_RELEASE_MINOR_VERSION_C         7
#define POWER_IP_MSCM_AR_RELEASE_REVISION_VERSION_C      0
#define POWER_IP_MSCM_SW_MAJOR_VERSION_C                 1
#define POWER_IP_MSCM_SW_MINOR_VERSION_C                 0
#define POWER_IP_MSCM_SW_PATCH_VERSION_C                 0


/*==================================================================================================
                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_MSCM.c file and Power_Ip_MSCM.h file are of the same vendor */
#if (POWER_IP_MSCM_VENDOR_ID_C != POWER_IP_MSCM_VENDOR_ID)
    #error "Power_Ip_MSCM.c and Power_Ip_MSCM.h have different vendor ids"
#endif

/* Check if Power_Ip_MSCM.c file and Power_Ip_MSCM.h file are of the same Autosar version */
#if ((POWER_IP_MSCM_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_MSCM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MSCM_AR_RELEASE_MINOR_VERSION_C != POWER_IP_MSCM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MSCM_AR_RELEASE_REVISION_VERSION_C != POWER_IP_MSCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_MSCM.c and Power_Ip_MSCM.h are different"
#endif

/* Check if Power_Ip_MSCM.c file and Power_Ip_MSCM.h file are of the same Software version */
#if ((POWER_IP_MSCM_SW_MAJOR_VERSION_C != POWER_IP_MSCM_SW_MAJOR_VERSION) || \
     (POWER_IP_MSCM_SW_MINOR_VERSION_C != POWER_IP_MSCM_SW_MINOR_VERSION) || \
     (POWER_IP_MSCM_SW_PATCH_VERSION_C != POWER_IP_MSCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_MSCM.c and Power_Ip_MSCM.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


/**
* @brief            Get MSCM processor personality.
* @details          This routine returns the accessor core personality.
*
* @param[in]        void.
*
* @return           Power_Ip_MSCM_CpxType.
*
*/
Power_Ip_MSCM_CpxType Power_Ip_MSCM_GetPersonality(void)
{
    uint32 MSCMCpxType;
    Power_Ip_MSCM_CpxType MSCMPersonality = POWER_IP_CORE_UNDEFINED;

    MSCMCpxType = (IP_MSCM->CPXTYPE & MSCM_CPXTYPE_PERSONALITY_MASK);

    if (MSCM_CPXTYPE_R52_MASK32 == (MSCMCpxType & MSCM_CORE_PERSONALITY_MASK32))
    {
        MSCMPersonality = POWER_IP_CORE_R52;
    }
    else if (MSCM_CPXTYPE_M33_MASK32 == (MSCMCpxType & MSCM_CORE_PERSONALITY_MASK32))
    {
        MSCMPersonality = POWER_IP_CORE_M33;
    }
    else
    {
        /* Nothing else to be done. Ignore the CPU type. */
    }

    return MSCMPersonality;
}


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
