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
*   @file       Power_Ip.c
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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Private.h"
#include "Power_Ip.h"
#include "Power_Ip_MC_ME.h"
#include "Power_Ip_MC_RGM.h"
#include "Power_Ip_PMC.h"
#include "Power_Ip_RTU_GPR.h"
#include "Power_Ip_GPR.h"
#include "OsIf.h"
#include "Power_Ip_RTU_NIC.h"
#if (defined(POWER_IP_WARM_RESET_SUPPORT) && (POWER_IP_WARM_RESET_SUPPORT == STD_ON))
    #include "Power_Ip_MSCM.h" 
#endif
#if ((defined(POWER_IP_SLEEPONEXIT_SUPPORT) && (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)) || \
    (defined(POWER_IP_WARM_RESET_SUPPORT) && (POWER_IP_WARM_RESET_SUPPORT == STD_ON)))    
    #include "Power_Ip_CortexM33.h"           
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_VENDOR_ID_C                      43
#define POWER_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_SW_MAJOR_VERSION_C               1
#define POWER_IP_SW_MINOR_VERSION_C               0
#define POWER_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_MC_ME.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_MC_ME_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_MC_ME.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_MC_ME.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_MC_ME_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_MC_ME.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_MC_ME.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_MC_ME_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_MC_ME_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_MC_ME_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_MC_ME.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_MC_RGM.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_MC_RGM_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_MC_RGM.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_MC_RGM.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_MC_RGM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_MC_RGM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_MC_RGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_MC_RGM.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_RTU_NIC.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_RTU_NIC_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_RTU_NIC.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_RTU_NIC.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C       != POWER_IP_RTU_NIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C       != POWER_IP_RTU_NIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C    != POWER_IP_RTU_NIC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_RTU_NIC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_RTU_NIC.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_RTU_NIC_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_RTU_NIC_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_RTU_NIC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_RTU_NIC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_MC_RGM.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_MC_RGM_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_MC_RGM_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_MC_RGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_MC_RGM.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_PMC.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_PMC_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_PMC.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_PMC.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PMC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_PMC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_PMC.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_PMC_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_PMC_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_PMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_PMC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_RTU_GPR.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_RTU_GPR_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_RTU_GPR.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_RTU_GPR.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_RTU_GPR.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_RTU_GPR.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_RTU_GPR_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_RTU_GPR_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_RTU_GPR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_RTU_GPR.h are different"
#endif

#if (defined(POWER_IP_WARM_RESET_SUPPORT) && (POWER_IP_WARM_RESET_SUPPORT == STD_ON))
/* Check if Power_Ip.c file and Power_Ip_MSCM.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_MSCM_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_MSCM.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_MSCM.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_MSCM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_MSCM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_MSCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_MSCM.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_MSCM.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_MSCM_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_MSCM_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_MSCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_MSCM.h are different"
#endif
#endif

#if ((defined(POWER_IP_SLEEPONEXIT_SUPPORT) && (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)) || \
    (defined(POWER_IP_WARM_RESET_SUPPORT) && (POWER_IP_WARM_RESET_SUPPORT == STD_ON)))
/* Check if Power_Ip.c file and Power_Ip_CortexM33.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_CORTEXM33_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_CortexM33.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_CortexM33.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXM33_AR_RELEASE_MAJOR_VERSION    != POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM33_AR_RELEASE_MINOR_VERSION    != POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CORTEXM33_AR_RELEASE_REVISION_VERSION != POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_CortexM33.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_CortexM33.h file are of the same Software version */
#if ((POWER_IP_CORTEXM33_SW_MAJOR_VERSION != POWER_IP_RTU_GPR_SW_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM33_SW_MINOR_VERSION != POWER_IP_RTU_GPR_SW_MINOR_VERSION) || \
     (POWER_IP_CORTEXM33_SW_PATCH_VERSION != POWER_IP_RTU_GPR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_CortexM33.h are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip.c and OsIf.h are different"
#endif
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
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Power_Ip_c_REF_1 #include directives should only be preceded by preprocessor
* directives or comments.
*
* @violates @ref Power_Ip_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
*/
#include "Mcu_MemMap.h"

/* Power Report Error Callback */
Power_Ip_ReportErrorsCallbackType Power_Ip_pfReportErrorsCallback = Power_Ip_ReportPowerErrorsEmptyCallback;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Power_Ip_c_REF_1 #include directives should only be preceded by preprocessor
* directives or comments.
*
* @violates @ref Power_Ip_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Power_Ip_c_REF_1 #include directives should only be preceded by preprocessor
* directives or comments.
*
* @violates @ref Power_Ip_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
*/
#include "Mcu_MemMap.h"

static void Power_Ip_HandleSelectedMode(const Power_Ip_ModeConfigType *ModeConfigPtr);
static void Power_Ip_TurnOffPartition(const Power_Ip_MC_ME_PartitionConfigType *PartitionConfig,const Power_Ip_MC_RGM_DomainConfigType *DomainConfigPtr , uint8 PartitionIndex);
static void Power_Ip_TurnOnPartition(const Power_Ip_MC_ME_PartitionConfigType *PartitionConfig,const Power_Ip_MC_RGM_DomainConfigType *DomainConfigPtr , uint8 PartitionIndex);
/*==================================================================================================
                                      LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief            This function set up Mode follow to configuration.
*
* @param[in]        ModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
*/
static void Power_Ip_HandleSelectedMode(const Power_Ip_ModeConfigType *ModeConfigPtr)
{
    Power_Ip_PowerModeType PowerMode;

    POWER_IP_DEV_ASSERT(NULL_PTR != ModeConfigPtr);

    PowerMode = ModeConfigPtr->PowerMode;

#if (defined(POWER_IP_WARM_RESET_SUPPORT) && (POWER_IP_WARM_RESET_SUPPORT == STD_ON))
    Power_Ip_MSCM_CpxType McuCpxType;
#endif /* (POWER_IP_WARM_RESET_SUPPORT == STD_ON) */

    if ( (POWER_IP_DEST_RESET_MODE == PowerMode) || (POWER_IP_FUNC_RESET_MODE == PowerMode) )
    {
        Power_Ip_MC_ME_SocTriggerResetEvent(PowerMode);
    }
#if (defined(POWER_IP_ENTER_LOW_POWER_MODE) && (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON))
    else if (POWER_IP_CORE_STANDBY_MODE == PowerMode)
    {
        /* External assumption: The application will make sure that the core is prepared for standby entry. */
        Power_Ip_MC_ME_CoreStandbyEntry(ModeConfigPtr);
    }
#endif
#if (defined(POWER_IP_WARM_RESET_SUPPORT) && (POWER_IP_WARM_RESET_SUPPORT == STD_ON))
    else if (POWER_IP_CORE_WARM_RESET_MODE == PowerMode)
    {
        McuCpxType = Power_Ip_MSCM_GetPersonality();

        switch (McuCpxType)
        {
            case POWER_IP_CORE_R52:
            {
                /* This just supported in Hyp Mode for Core R52 */
                break;
            }
            case POWER_IP_CORE_M33:
            {
                Call_Power_Ip_CortexM_WarmReset();
                break;
            }

            default:
            {
                /* Should never reach this branch. */
                break;
            }
        }
    }
#endif /* (POWER_IP_WARM_RESET_SUPPORT == STD_ON) */
    else
    {
        /* Nothing else to be done. Ignore the power mode. */
    }
}

/**
* @brief            This function to turn off the partition.
*
* @param[in]        PartitionConfig   Pointer to partition configuration structure.
* @param[in]        DomainConfigPtr   Pointer to Domain configuration structure.
*
* @return           void
*
*/

static void Power_Ip_TurnOffPartition(const Power_Ip_MC_ME_PartitionConfigType *PartitionConfig,const Power_Ip_MC_RGM_DomainConfigType *DomainConfigPtr , uint8 PartitionIndex)
{
    uint8 CoreIndex;

    if (0U != PartitionIndex)
    {
        /* Check partition need to turn on before */
        if (TRUE == Power_Ip_MC_ME_CheckEnPartitionClock(PartitionIndex))
        {
            /* Step 1: Check wfi status for all cores in this partition */
            for (CoreIndex = 0U; CoreIndex < DomainConfigPtr->NumberOfCores; ++CoreIndex)
            {
                (void)Power_Ip_MC_ME_WfiWait(CoreIndex, PartitionIndex);
            }

            /* Step 2: Active core R52 fencing */
            Power_Ip_MC_RGM_ConfigureResetDomainController(PartitionIndex, DomainConfigPtr->DomainRdcRegValue);
        
            /* Step 3: Disable Partitions clock base on configuration of McuPartitionClockEnable.  */
            Power_Ip_MC_ME_ConfigurePartitionClock(PartitionIndex, PartitionConfig->PartitionPconfRegValue,         PartitionConfig->PartitionTriggerMask);
            
            /* Step 4: Enable Output safe stating base on configuration of McuPartitionClockEnable. */
            Power_Ip_MC_ME_ConfigurePartitionOutputSafe(PartitionIndex, PartitionConfig->PartitionPconfRegValue,        PartitionConfig->PartitionTriggerMask);
            
            /* Step 5: Assert partition reset */
            Call_Power_Ip_MC_RGM_AssertDomainReset(PartitionIndex);
        }
    }
}

static void Power_Ip_TurnOnPartition(const Power_Ip_MC_ME_PartitionConfigType *PartitionConfig,const Power_Ip_MC_RGM_DomainConfigType *DomainConfigPtr , uint8 PartitionIndex)
{
    volatile uint32 Count;
    /* Step 1: Enable Partitions clock base on configuration of McuPartitionClockEnable. */
    Power_Ip_MC_ME_ConfigurePartitionClock(PartitionIndex, PartitionConfig->PartitionPconfRegValue,PartitionConfig->PartitionTriggerMask);
    if (0U != PartitionIndex)
    {
        /* Step 2: Release partition from reset */
        Call_Power_Ip_MC_RGM_ReleaseDomainReset(DomainConfigPtr->DomainIndex);
        
        /* Step 3: Disable Output safe stating base on configuration of McuPartitionClockEnable. */
        Power_Ip_MC_ME_ConfigurePartitionOutputSafe(PartitionIndex, PartitionConfig->PartitionPconfRegValue, PartitionConfig->PartitionTriggerMask);
        
        /* Step 4: Enable interconnect, connect SRAM, disable LLC fencing*/
        Power_Ip_MC_RGM_ConfigureResetDomainController(PartitionIndex, DomainConfigPtr->DomainRdcRegValue);

        if (2U == PartitionIndex)
        {
            /* Step 5: Configure NIC */
            Power_Ip_RTU_NIC_EnableRemap();
        }
        /* Wait for remap, have no idea about this. */
        Count = 5000U;
        while (Count > 0U)
        {
            Count--;
        }
    
    #ifdef POWER_IP_LOCKSTEP_SUPPORT
        #if (STD_ON == POWER_IP_LOCKSTEP_SUPPORT)
        if (TRUE == PartitionConfig->CoreOperationUnderMcuControl)
        {
            /* Step 6: Lockstep or split cores just configurable for Cortex R52 */
            Call_Power_Ip_RTU_GPR_SetLockstepMode(PartitionIndex, PartitionConfig->LockStepEn);
        }
        #endif
    #endif
    }
}
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


/**
* @brief            This function initializes the mode structure.
* @details          This function initializes the mode structure by configuring the MC_ME module.
*
* @param[in]        ModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
* @implements Power_Ip_SetMode_Activity
*
*/
void Power_Ip_SetMode(const Power_Ip_ModeConfigType * ModeConfigPtr)
{
    const Power_Ip_MC_ME_ModeConfigType *pMcMeConfig = NULL_PTR;
    const Power_Ip_MC_RGM_ModeConfigType *pRGMConfig = NULL_PTR;
    const Power_Ip_MC_ME_PartitionConfigType *TempPartitionConfig = NULL_PTR;
    const Power_Ip_MC_RGM_DomainConfigType *TempDomainConfigPtr = NULL_PTR;
    const Power_Ip_MC_RGM_CoreConfigType * CoreResetConfigPtr = NULL_PTR;
    uint8 PartitionIndex;
    uint8 CoreIndex;
    uint8 CofbIndex;
    
    POWER_IP_DEV_ASSERT(NULL_PTR != ModeConfigPtr);
    
    pMcMeConfig = ModeConfigPtr->McMeModeConfigPtr;
    pRGMConfig = ModeConfigPtr->McRgmModeConfigPtr;
    
    /* Set clock gate for peripherals  */
    Power_Ip_GPR_Config(ModeConfigPtr->GprConfigPtr);
    
    for (PartitionIndex = 0U; PartitionIndex < POWER_IP_MAX_NUMBER_OF_PARTITIONS; ++PartitionIndex)
    {
        TempPartitionConfig = &(*pMcMeConfig->ArrayPartitionConfigPtr)[PartitionIndex];
        
        TempDomainConfigPtr = &(*pRGMConfig->ArrayDomainConfigPtr)[PartitionIndex];
        
        /* We have same nodes under control Mcu and Power Under control Mcu for RGM and MC_ME */
        if (TRUE == TempPartitionConfig->PartitionUnderMcuControl)
        {
            if (TRUE == TempPartitionConfig->PartitionPowerUnderMcuControl)
            {
                /* Start the processing partition turn on, cores in this partition can turn on or turn off */
                if (MC_ME_PRTNX_PCONF_PCE_EN_U32 == (TempPartitionConfig->PartitionPconfRegValue & MC_ME_PRTN0_PCONF_PCE_MASK))
                {
                    /* Step 1: Enable Partitions */
                    Power_Ip_TurnOnPartition(TempPartitionConfig, TempDomainConfigPtr, PartitionIndex);

                    /* The processing peripheral in RGM */
                    for (CofbIndex = 0U; CofbIndex < TempDomainConfigPtr->NumberOfCofbs; ++CofbIndex)
                    {
                        if ( TRUE == (*TempDomainConfigPtr->ArrayDomainCofbConfigPtr)[CofbIndex].CofbUnderMcuControl )
                        {
                            Call_Power_Ip_MC_RGM_ConfigureCOFB(&(*TempDomainConfigPtr->ArrayDomainCofbConfigPtr)[CofbIndex], TempDomainConfigPtr->DomainIndex);
                        }
                    }
                    /* Start the processing core turn on or turn off */
                    for (CoreIndex = 0U; CoreIndex < TempDomainConfigPtr->NumberOfCores; ++CoreIndex)
                    {
                        if (TRUE == (*TempDomainConfigPtr->ArrayDomainCoreConfigPtr)[CoreIndex].CoreUnderMcuControl)
                        {
                            CoreResetConfigPtr = &(*TempDomainConfigPtr->ArrayDomainCoreConfigPtr)[CoreIndex];
                            
                            /* Step 2: Configure core is turn on or turn off depends on configuration */
                            Power_Ip_MC_ME_ConfigureCore(TempPartitionConfig, CoreIndex, PartitionIndex);
                            
                            /* Step 3: Release or assert core from reset */ 
                            Call_Power_Ip_MC_RGM_ConfigureCore(CoreResetConfigPtr, PartitionIndex);
                        }
                    }
                }
                else /* Start the processing turn off partition, force reset partition */
                {
                    /* Turn Off Partition */
                    Power_Ip_TurnOffPartition(TempPartitionConfig, TempDomainConfigPtr, PartitionIndex);
                }
            }
        }
    }

    Power_Ip_HandleSelectedMode(ModeConfigPtr);
}

#if (POWER_IP_PERFORM_RESET_API == STD_ON)
/**
* @brief            This function performs a microcontroller reset.
* @details          This function performs a microcontroller reset by using the hardware feature of
*                   the microcontroller.
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
* @implements Power_Ip_PerformReset_Activity
*
*/
void Power_Ip_PerformReset(const Power_Ip_HwIPsConfigType * HwIPsConfigPtr)
{

    POWER_IP_DEV_ASSERT(NULL_PTR != HwIPsConfigPtr);
    /*
     *  Performs a microcontroller reset.
     *  A RESET mode requested via the ME_MCTL register is passed to the MC_RGM, which generates a
     *  global system reset and initiates the reset sequence.
     */

    Call_Power_Ip_MC_RGM_PerformReset(HwIPsConfigPtr->McRgmConfigPtr);
}
#endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */

/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*
* @param[in]        None
*
* @return           void
*
* @implements Power_Ip_GetResetReason_Activity
*
*/
Power_Ip_ResetType Power_Ip_GetResetReason(void)
{
    Power_Ip_ResetType ResetReason = MCU_RESET_UNDEFINED;

    ResetReason = (Power_Ip_ResetType)Call_Power_Ip_MC_RGM_GetResetReason();
    
    return ResetReason;
}

/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_GetResetReason() from HLD.
*
* @param[in]        None
*
* @return           void
*
* @implements Power_Ip_GetResetRawValue_Activity
*
*/
Power_Ip_RawResetType Power_Ip_GetResetRawValue(void)
{
    Power_Ip_RawResetType ResetReason;

    ResetReason = Call_Power_Ip_MC_RGM_GetResetRawValue();
    return ResetReason;
}

/**
* @brief            This function initializes the power module.
* @details
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure.
*
* @return           void
*
* @implements Power_Ip_Init_Activity
*
*/
void Power_Ip_Init(const Power_Ip_HwIPsConfigType * HwIPsConfigPtr)
{
    POWER_IP_DEV_ASSERT(NULL_PTR != HwIPsConfigPtr);

#if (defined(POWER_IP_DISABLE_RGM_INIT) && (STD_OFF == POWER_IP_DISABLE_RGM_INIT))
    /* Init MCU MC_RGM part of the registers: MC_RGM_FERD, MC_RGM_FEAR, MC_RGM_FESS, MC_RGM_FBRE, clear FES & DES status registers. */
    Call_Power_Ip_MC_RGM_ResetInit(HwIPsConfigPtr->McRgmConfigPtr);
#endif

#if (defined(POWER_IP_DISABLE_PMC_INIT) && (STD_OFF == POWER_IP_DISABLE_PMC_INIT))
    /* Init Power Management Controller digital interface */
    Power_Ip_PMC_PowerInit(HwIPsConfigPtr->PMCConfigPtr);
#endif
    /* Avoid compiler warning */
    (void)HwIPsConfigPtr;
}

/**
* @brief            This function installs a callback for reporting errors from power driver.
* @details
*
* @param[in]        ReportErrorsCallback    Callback to be installed.
*
* @return           void
*
* @implements Power_Ip_InstallNotificationsCallback_Activity
*/
void Power_Ip_InstallNotificationsCallback(Power_Ip_ReportErrorsCallbackType ReportErrorsCallback)
{
    POWER_IP_DEV_ASSERT(NULL_PTR != ReportErrorsCallback);

    Power_Ip_pfReportErrorsCallback = ReportErrorsCallback;
}

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
  #if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
/**
* @brief        The function enable SLEEPONEXIT bit.
* @details      The function enable SLEEPONEXIT bit.
*
* @return void
*
* @implements Power_Ip_EnableSleepOnExit_Activity
*/
void Power_Ip_EnableSleepOnExit(void)
{
    Call_Power_Ip_CM33_EnableSleepOnExit();
}

/**
* @brief        The function disable SLEEPONEXIT bit.
* @details      The function disable SLEEPONEXIT bit.
*
* @return void
*
* @implements Power_Ip_DisableSleepOnExit_Activity
*/
void Power_Ip_DisableSleepOnExit(void)
{
    Call_Power_Ip_CM33_DisableSleepOnExit();
}
  #endif
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Power_Ip_c_REF_1 #include directives should only be preceded by preprocessor
* directives or comments.
*
* @violates @ref Power_Ip_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
