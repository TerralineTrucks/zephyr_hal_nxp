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
*   @file       Power_Ip_MC_ME.c
*   @version    1.0.0
*
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
#include "Power_Ip_Private.h"
#include "Power_Ip_RTU_GPR.h"
#include "Power_Ip_MC_ME.h"
#if (defined(POWER_IP_SLEEPONEXIT_SUPPORT) && (STD_ON == POWER_IP_SLEEPONEXIT_SUPPORT))
    #include "Power_Ip_CortexM33.h"
#endif 

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_MC_ME_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE)
      #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
      #include "RegLockMacros.h"
    #endif /* (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_MC_ME_VENDOR_ID_C                      43
#define POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_MC_ME_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_MC_ME_SW_MAJOR_VERSION_C               1
#define POWER_IP_MC_ME_SW_MINOR_VERSION_C               0
#define POWER_IP_MC_ME_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_MC_ME.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_MC_ME_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_MC_ME.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_MC_ME.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_MC_ME_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_MC_ME_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_MC_ME.c and Power_Ip_Private.h are different"
#endif

#if (defined(POWER_IP_SLEEPONEXIT_SUPPORT) && (STD_ON == POWER_IP_SLEEPONEXIT_SUPPORT))
/* Check if Power_Ip_MC_ME.c file and Power_Ip_CortexM33.h file are of the same vendor */
#if (POWER_IP_MC_ME_VENDOR_ID_C != POWER_IP_CORTEXM33_VENDOR_ID)
    #error "Power_Ip_MC_ME.c and Power_Ip_CortexM33.h have different vendor ids"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_CortexM33.h file are of the same Autosar version */
#if ((POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_CORTEXM33_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION_C != POWER_IP_CORTEXM33_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_REVISION_VERSION_C != POWER_IP_CORTEXM33_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_MC_ME.c and Power_Ip_CortexM33.h are different"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_CortexM33.h file are of the same Software version */
#if ((POWER_IP_MC_ME_SW_MAJOR_VERSION_C != POWER_IP_CORTEXM33_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_SW_MINOR_VERSION_C != POWER_IP_CORTEXM33_SW_MINOR_VERSION) || \
     (POWER_IP_MC_ME_SW_PATCH_VERSION_C != POWER_IP_CORTEXM33_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_MC_ME.c and Power_Ip_CortexM33.h are different"
#endif
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_MC_ME.h file are of the same vendor */
#if (POWER_IP_MC_ME_VENDOR_ID_C != POWER_IP_MC_ME_VENDOR_ID)
    #error "Power_Ip_MC_ME.c and Power_Ip_MC_ME.h have different vendor ids"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_MC_ME.h file are of the same Autosar version */
#if ((POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION_C != POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_REVISION_VERSION_C != POWER_IP_MC_ME_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_MC_ME.c and Power_Ip_MC_ME.h are different"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_MC_ME.h file are of the same Software version */
#if ((POWER_IP_MC_ME_SW_MAJOR_VERSION_C != POWER_IP_MC_ME_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_SW_MINOR_VERSION_C != POWER_IP_MC_ME_SW_MINOR_VERSION) || \
     (POWER_IP_MC_ME_SW_PATCH_VERSION_C != POWER_IP_MC_ME_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_MC_ME.c and Power_Ip_MC_ME.h are different"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_RTU_GPR.h file are of the same vendor */
#if (POWER_IP_MC_ME_VENDOR_ID_C != POWER_IP_RTU_GPR_VENDOR_ID)
    #error "Power_Ip_MC_ME.c and Power_Ip_RTU_GPR.h have different vendor ids"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_RTU_GPR.h file are of the same Autosar version */
#if ((POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION_C != POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_ME_AR_RELEASE_REVISION_VERSION_C != POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_MC_ME.c and Power_Ip_RTU_GPR.h are different"
#endif

/* Check if Power_Ip_MC_ME.c file and Power_Ip_RTU_GPR.h file are of the same Software version */
#if ((POWER_IP_MC_ME_SW_MAJOR_VERSION_C != POWER_IP_RTU_GPR_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_ME_SW_MINOR_VERSION_C != POWER_IP_RTU_GPR_SW_MINOR_VERSION) || \
     (POWER_IP_MC_ME_SW_PATCH_VERSION_C != POWER_IP_RTU_GPR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_MC_ME.c and Power_Ip_RTU_GPR.h are different"
#endif

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_MC_ME_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE)
        #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
            /* Check if Power_Ip_MC_ME.c file and RegLockMacros.h file are of the same Autosar version */
            #if ((POWER_IP_MC_ME_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                (POWER_IP_MC_ME_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Power_Ip_MC_ME.c and RegLockMacros.h are different"
            #endif
        #endif
    #endif /* (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
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

#include "Mcu_MemMap.h"

static Power_Ip_MC_ME_Type * Power_Ip_pxMC_ME = (Power_Ip_MC_ME_Type *)IP_MC_ME_BASE;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED

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

#include "Mcu_MemMap.h"

static void Power_Ip_MC_ME_EnableCore(const Power_Ip_MC_ME_PartitionConfigType *TempPartitionConfig,
                                       uint8 CoreIndex, 
                                       uint8 PartitionIndex
                                      );
static void Power_Ip_MC_ME_DisableCore(const Power_Ip_MC_ME_PartitionConfigType *TempPartitionConfig,
                                       uint8 CoreIndex, 
                                       uint8 PartitionIndex
                                       );
#if (defined(POWER_IP_CONFIGURE_CADDRN))
  #if (POWER_IP_CONFIGURE_CADDRN == STD_ON)
static boolean Power_Ip_MC_ME_CheckValidCoreForAddr(uint8 CoreIndex, 
                                                    uint8 PartitionIndex
                                                    );
  #endif
#endif
static boolean Power_Ip_MC_ME_CheckValidCoreClock(uint8 CoreIndex, 
                                                  uint8 PartitionIndex
                                                  );
static void Power_Ip_MC_ME_WriteConfigCore(const Power_Ip_MC_ME_CoreConfigType * CoreConfigPtr,
                                           uint8 PartitionIndex
                                           );
static inline void Power_Ip_MC_ME_WriteControlKeys(void);
static inline void Power_Ip_MC_ME_TriggerModeUpdate(void);

static inline void Power_Ip_MC_ME_TriggerPartitionUpdate(uint32 TriggerMask, uint8 PartitionIndex);
static inline void Power_Ip_MC_ME_TriggerCoreUpdate(uint8 PartitionIndex, uint8 CoreIndex);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief            This function configures a given core.
* @details          Configures the core within the given partition and waits until the updates have finished.
*
* @param[in]        CoreConfigPtr    Pointer to a core configuration structure.
* @param[in]        PartitionIndex   Index of the partition in which the core resides.
*
* @return           void
*
*/
static void Power_Ip_MC_ME_WriteConfigCore(const Power_Ip_MC_ME_CoreConfigType * CoreConfigPtr,
                                           uint8 PartitionIndex
                                           )
{
    uint32 CoreConfig = CoreConfigPtr->CorePconfRegValue;
    uint32 CoreStatus;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;
    uint8 CoreIndex = CoreConfigPtr->CoreIndex;
    
    /* Write the new configuration for the core. */
    Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].McMePrtnCoreArray[CoreIndex].PRTN_CORE_PCONF = CoreConfig;

    /* Trigger the update in hardware */
    Power_Ip_MC_ME_TriggerCoreUpdate(PartitionIndex, CoreIndex);

    /* Wait until the update has finished. */
    Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
    do
    {
        TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

        CoreStatus = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].McMePrtnCoreArray[CoreIndex].PRTN_CORE_STAT;
    } while (((CoreStatus & MC_ME_PRTN0_CORE0_STAT_CCS_MASK) != (CoreConfig & MC_ME_PRTN0_CORE0_PCONF_CCE_MASK)) && (!TimeoutOccurred));
    /* timeout notification */
    if(TimeoutOccurred)
    {
        Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
    }
}

/**
* @brief            This function to check cores support for clock core fields.
* @details          This function to check cores support for fields MC_ME_PRTN_CORE_PCONF,
*                   MC_ME_PRTN_CORE_PUPD, MC_ME_PRTN_CORE_STAT
*
* @param[in]        CoreIndex              Core index.
*                   PartitionIndex         Index of the partition in which the core resides.
*
* @return           TRUE        Core clock field is support for this core.
* @return           FALSE       Core clock field isn't support for this core.
*
*/
static boolean Power_Ip_MC_ME_CheckValidCoreClock(uint8 CoreIndex, 
                                                  uint8 PartitionIndex
                                                  )
{
    boolean ValidCore = TRUE;
    
    if (TRUE == (uint8)Call_Power_Ip_RTU_GPR_CheckEnLockStepMode(PartitionIndex))
    {
        if ((2U == CoreIndex) || (3U == CoreIndex))
        {
            ValidCore = FALSE;
        }
    }
 
    return ValidCore;
}

#if (defined(POWER_IP_CONFIGURE_CADDRN))
  #if (POWER_IP_CONFIGURE_CADDRN == STD_ON)
/**
* @brief            This function to check cores support for address core field.
* @details          This function to check cores support for field MC_ME_PRTN_CORE_ADDR.
*
* @param[in]        CoreIndex              Core index.
*                   PartitionIndex         Index of the partition in which the core resides.
*
* @return           TRUE        Core address field is support for this core.
* @return           FALSE       Core address field isn't support for this core.
*
*/
static boolean Power_Ip_MC_ME_CheckValidCoreForAddr(uint8 CoreIndex, 
                                                    uint8 PartitionIndex
                                                    )
{
    boolean ValidCore = TRUE;
    
    if (TRUE == (uint8)Call_Power_Ip_RTU_GPR_CheckEnLockStepMode(PartitionIndex))
    {
        if ((2U == CoreIndex) || (3U == CoreIndex))
        {
            ValidCore = FALSE;
        }
    }
    
    return ValidCore;
}
  #endif
#endif

/**
* @brief            This function configures a given core is disable.
* @details          Configures the core within the given partition and waits until the updates have finished.
*
* @param[in]        TempPartitionConfig    Pointer to a core configuration structure
*                   CoreIndex              Core index.
* @param[in]        PartitionIndex         Index of the partition in which the core resides.
*
* @return           void
*
*/
static void Power_Ip_MC_ME_DisableCore(const Power_Ip_MC_ME_PartitionConfigType *TempPartitionConfig,
                                       uint8 CoreIndex, 
                                       uint8 PartitionIndex
                                       )
{
    boolean TimeoutOccurred = FALSE;
    boolean ValidCore = TRUE;
    const Power_Ip_MC_ME_CoreConfigType * CoreConfigPtr = NULL_PTR;
    
    CoreConfigPtr = &(*TempPartitionConfig->ArrayPartitionCoreConfigPtr)[CoreIndex];
    
    TimeoutOccurred = Power_Ip_MC_ME_WfiWait(CoreIndex, PartitionIndex);
    
    if (0U != PartitionIndex)
    {
        Call_Power_Ip_RTU_GPR_FenceDrainCoreController(PartitionIndex, CoreIndex, TRUE);
        ValidCore = Power_Ip_MC_ME_CheckValidCoreClock(CoreIndex, PartitionIndex);
    }
    
    /* Core clock is reserve for core 1 and core 3 */
    if ((ValidCore) && (!TimeoutOccurred))
    {
        Power_Ip_MC_ME_WriteConfigCore(CoreConfigPtr, PartitionIndex);
    }
}

/**
* @brief            This function to check status of wfi for core.
*
* @param[in]        PartitionIdx Partition Index.
*                   CoreIndex    Core Index.
*
* @return           TRUE timeout occurred.
*                   FALSE timout not occurred.
*
*/
boolean Power_Ip_MC_ME_WfiWait(uint8 CoreIndex,
                               uint8 PartitionIndex
                               )
{
    uint32 CoreStatus;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;
    boolean ValidCore = TRUE;
    
    /* For lockstep operation, core 2 and core 3 is reserve for wfi */
    if (0U != PartitionIndex)
    {
        if (TRUE == (uint8)Call_Power_Ip_RTU_GPR_CheckEnLockStepMode(PartitionIndex))
        {
            if ((2U == CoreIndex) || (3U == CoreIndex))
            {
                ValidCore = FALSE;
            }
        }
    }
    
    if (ValidCore)
    {
        /* Wait until WFI is set */
        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        
            CoreStatus = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].McMePrtnCoreArray[CoreIndex].PRTN_CORE_STAT;
        } while ((MC_ME_PRTNX_COREX_STAT_WFI_EXECUTED_U32 != (CoreStatus & MC_ME_PRTN0_CORE0_STAT_WFI_MASK)) && (!TimeoutOccurred));
        /* timeout notification */
        if (TimeoutOccurred)
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }
    }
    
    return TimeoutOccurred;
}

/**
* @brief            This function configures a given core is enable.
* @details          Configures the core within the given partition and waits until the updates have finished.
*
* @param[in]        TempPartitionConfig    Pointer to a core configuration structure
*                   CoreIndex              Core index.
* @param[in]        PartitionIndex         Index of the partition in which the core resides.
*
* @return           void
*
*/
static void Power_Ip_MC_ME_EnableCore(const Power_Ip_MC_ME_PartitionConfigType *TempPartitionConfig,
                                       uint8 CoreIndex, 
                                       uint8 PartitionIndex
                                      )
{
    const Power_Ip_MC_ME_CoreConfigType * CoreConfigPtr = NULL_PTR;
    boolean ValidCore = TRUE;
    
    CoreConfigPtr = &(*TempPartitionConfig->ArrayPartitionCoreConfigPtr)[CoreIndex];
#if (defined(POWER_IP_CONFIGURE_CADDRN))
  #if (POWER_IP_CONFIGURE_CADDRN == STD_ON)
    uint8 BootingStatus;

    /* Check if configure for R52 core then write CFG_HALT for the correspond core index */
    if (0U != PartitionIndex)
    {
        BootingStatus = (uint8)Call_Power_Ip_RTU_GPR_CheckTcmBooting(PartitionIndex);
        if (1U == BootingStatus)
        {
            Call_Power_Ip_RTU_GPR_CoreHaltConfig(PartitionIndex, CoreIndex, TRUE);
        }
        /* Check valid core to write to address core field */
        ValidCore = Power_Ip_MC_ME_CheckValidCoreForAddr(CoreIndex, PartitionIndex);
    }
    if (ValidCore)
    {
        /* Set the boot address for the core */
        Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].McMePrtnCoreArray[CoreIndex].PRTN_CORE_ADDR = (uint32) CoreConfigPtr->CoreBootAddress;
    }
  #endif
#endif

    if (0U != PartitionIndex)
    {
        ValidCore = Power_Ip_MC_ME_CheckValidCoreClock(CoreIndex, PartitionIndex);
    }
    if (ValidCore)
    {
        Power_Ip_MC_ME_WriteConfigCore(CoreConfigPtr, PartitionIndex);
    }

    /* Deactivate Cortex-R52 core fencing logic */
    if (0U != PartitionIndex)
    {
        Call_Power_Ip_RTU_GPR_FenceDrainCoreController(PartitionIndex, CoreIndex, FALSE);
    }
}
/**
* @brief            This function triggers the hardware processes of MC_ME.
* @details          This function writes the key 0x5AF0 and the inverted key
*                   0xA50F to the Control Key Register (MC_ME_CTL_KEY).
*
* @param[in]        void
*
* @return           void
*
*/
static inline void Power_Ip_MC_ME_WriteControlKeys(void)
{
    /* Starting the hardware processes */

    /* Write key to MC_ME_CTL_KEY */
    Power_Ip_pxMC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(MC_ME_CTL_KEY_DIRECT_KEY_U32);

    /* Write inverted key to MC_ME_CTL_KEY */
    Power_Ip_pxMC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(MC_ME_CTL_KEY_INVERTED_KEY_U32);
}

/**
* @brief            This function triggers a mode update.
* @details          This function triggers a mode update by writing to the
*                   corresponding MC_ME_MODE_UPD register.
*
* @param[in]        void
*
* @return           void
*
*/
static inline void Power_Ip_MC_ME_TriggerModeUpdate(void)
{
    Power_Ip_pxMC_ME->MODE_UPD = MC_ME_MODE_UPD_MODE_UPD(MC_ME_MODE_UPD_MODE_UPD_MASK);

    Power_Ip_MC_ME_WriteControlKeys();
}

/**
* @brief            This function triggers a partition update.
* @details          This function triggers a partition update based on the value of TriggerMask
*                   by writing to the corresponding MC_ME_PRTNx_PUPD register.
*
* @param[in]        TriggerMask      Mask containing the process updates to be triggered.
* @param[in]        PartitionIndex    Index of the partition to be updated.
*
* @return           void
*
*/
static inline void Power_Ip_MC_ME_TriggerPartitionUpdate(uint32 TriggerMask, uint8 PartitionIndex)
{
    uint32 TempValue = 0U;
    TempValue = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_PUPD;
    TempValue &= ~TriggerMask;
    TempValue |= TriggerMask;
    Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_PUPD = TempValue;

    Power_Ip_MC_ME_WriteControlKeys();
}

/**
* @brief            This function triggers a core update.
* @details          This function triggers a core update by writing to the corresponding MC_ME_PRTNx_COREx_PUPD register.
*
* @param[in]        PartitionIndex    Index of the partition to be updated.
* @param[in]        CoreIndex         Index of the core (within the partition) to be updated.
*
* @return           void
*
*/
static inline void Power_Ip_MC_ME_TriggerCoreUpdate(uint8 PartitionIndex, uint8 CoreIndex)
{
    uint32 TempValue = 0U;
    TempValue = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].McMePrtnCoreArray[CoreIndex].PRTN_CORE_PUPD;
    TempValue &= ~MC_ME_PRTN0_CORE0_PUPD_CCUPD_MASK;
    TempValue |= (MC_ME_PRTNX_COREX_PUPD_CCUPD_TRIG_U32 & MC_ME_PRTN0_CORE0_PUPD_CCUPD_MASK);
    Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].McMePrtnCoreArray[CoreIndex].PRTN_CORE_PUPD = TempValue;

    Power_Ip_MC_ME_WriteControlKeys();
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_MC_ME_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
void Power_Ip_MC_ME_SetUserAccessAllowed(void)
{
#if (defined(IP_MC_ME_BASE))
    SET_USER_ACCESS_ALLOWED(IP_MC_ME_BASE, MC_ME_PROT_MEM_U32);
#endif
}
    #endif /* (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */

/**
* @brief            This function configures a given core.
* @details          Configures the core within the given partition and waits until the updates have finished.
*
* @param[in]        TempPartitionConfig   Pointer to a partition configuration structure
*                   (member of 'Power_Ip_MC_ME_PartitionConfigType' struct).
*                   CoreIndex             Index of core.
* @param[in]        PartitionIndex        Index of the partition in which the core resides.
*
* @return           void
*
*/
void Power_Ip_MC_ME_ConfigureCore(const Power_Ip_MC_ME_PartitionConfigType *TempPartitionConfig,
                                  uint8 CoreIndex,
                                  uint8 PartitionIndex
                                  )
{
    const Power_Ip_MC_ME_CoreConfigType * CoreConfigPtr = NULL_PTR;
    
    CoreConfigPtr = &(*TempPartitionConfig->ArrayPartitionCoreConfigPtr)[CoreIndex];

    if (MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32 == (CoreConfigPtr->CorePconfRegValue & MC_ME_PRTN0_CORE0_PCONF_CCE_MASK))
    {
        Power_Ip_MC_ME_DisableCore(TempPartitionConfig, CoreIndex, PartitionIndex);
    }
    else
    {
        Power_Ip_MC_ME_EnableCore(TempPartitionConfig, CoreIndex, PartitionIndex);

    }
}

/**
* @brief            This function to check status of partition clock is enable or disable.
*
* @param[in]        PartitionIdx Partition Index.
*                   
*
* @return           TRUE Partition clock is enable.
*                   FALSE Partition clock is disable.
*
*/
boolean Power_Ip_MC_ME_CheckEnPartitionClock(uint8 PartitionIdx)
{
    boolean RetVal = FALSE;
    
    if (MC_ME_PRTN0_STAT_PCS_MASK == (Power_Ip_pxMC_ME->McMePrtnArray[PartitionIdx].PRTN_STAT & MC_ME_PRTN0_STAT_PCS_MASK))
    {
        RetVal = TRUE;
    }
    
    return RetVal;
}

#if (defined(POWER_IP_HAS_OUTPUT_SAFE_STATE))
  #if (POWER_IP_HAS_OUTPUT_SAFE_STATE == STD_ON)
/**
* @brief            This function configures Output safe stating enable/disable.
* @details          Configures the processes and waits until the updates have finished.
*
* @param[in]        PartitionIndex        Partition Index.
*                   PartitionConfig       Configuration of Output Safe.
*                   PartitionTriggerMask  Trigger Mask of Output Safe.  
*
* @return           void
*
*/
void Power_Ip_MC_ME_ConfigurePartitionOutputSafe(uint8 PartitionIndex,
                                                 uint32 PartitionConfig,
                                                 uint32 PartitionTriggerMask
                                                 )
{
    uint32 TempValue = 0U;
    uint32 PartitionStatus;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;

    if (MC_ME_PRTNX_PUPD_OSSUD_TRIG_U32 == (PartitionTriggerMask & MC_ME_PRTN1_PUPD_OSSUD_MASK))
    {
        /*  Write the new configuration for PRTNx_PCONF[OSSE]. */
        TempValue = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_PCONF;
        TempValue &= ~MC_ME_PRTN1_PCONF_OSSE_MASK;
        TempValue |= (PartitionConfig & MC_ME_PRTN1_PCONF_OSSE_MASK);
        Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_PCONF = TempValue;

        /* Trigger the update in hardware. */
        Power_Ip_MC_ME_TriggerPartitionUpdate(MC_ME_PRTN1_PUPD_OSSUD_MASK, PartitionIndex);

        /* Wait until the update has finished. */
        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

            PartitionStatus = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_STAT;
        } while (((PartitionStatus & MC_ME_PRTN1_STAT_OSSS_MASK) != (PartitionConfig & MC_ME_PRTN1_PCONF_OSSE_MASK)) && (!TimeoutOccurred));
        /* timeout notification */
        if (TimeoutOccurred)
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }
    }
}
  #endif /* (POWER_IP_HAS_OUTPUT_SAFE_STATE == STD_ON) */
#endif


/**
* @brief            This function configures Partition clock enable.
* @details          Configures the processes and waits until the updates have finished.
*
* @param[in]        PartitionIndex          Partition Index.
*                   PartitionConfig         Configuration of partition clock..
*                   PartitionTriggerMask    Trigger Mask of parition.
*
* @return           void
*
*/
void Power_Ip_MC_ME_ConfigurePartitionClock(uint8 PartitionIndex,
                                            uint32 PartitionConfig,
                                            uint32 PartitionTriggerMask
                                            )
{
    uint32 TempValue = 0U;
    uint32 PartitionStatus;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;
    
    if (MC_ME_PRTNX_PUPD_PCUD_TRIG_U32 == (PartitionTriggerMask & MC_ME_PRTN0_PUPD_PCUD_MASK))
    {
        /* Write the new configuration for PRTNx_PCONF[PCE]. */
        TempValue = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_PCONF;
        TempValue &= ~MC_ME_PRTN0_PCONF_PCE_MASK;
        TempValue |= (PartitionConfig & MC_ME_PRTN0_PCONF_PCE_MASK);
        Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_PCONF = TempValue;

        /* Trigger the update in hardware. */
        Power_Ip_MC_ME_TriggerPartitionUpdate(MC_ME_PRTN0_PUPD_PCUD_MASK, PartitionIndex);

        /* Wait until the update has finished. */
        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

            PartitionStatus = Power_Ip_pxMC_ME->McMePrtnArray[PartitionIndex].PRTN_STAT;
        } 
        while (((PartitionStatus & MC_ME_PRTN0_STAT_PCS_MASK) != (PartitionConfig & MC_ME_PRTN0_PCONF_PCE_MASK)) && (!TimeoutOccurred));
        /* timeout notification */
        if (TimeoutOccurred)
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }
    }
}

/**
* @brief            This function triggers a reset event (destructive or functional) for the SoC.
* @details          This function triggers a reset event (destructive or functional) for the SoC.
*
* @return           Status of the previous mode.
*
*/
void Power_Ip_MC_ME_SocTriggerResetEvent(Power_Ip_PowerModeType PowerMode)
{

    /* Software must not enable mode entry if the value of multiple fields is 1 in the MODE_CONF register. */
    if (MC_ME_MODE_CONF_MASK != Power_Ip_pxMC_ME->MODE_CONF)
    {
        if (POWER_IP_DEST_RESET_MODE == PowerMode)
        {
            /* Makes a request to trigger a Destructive Reset Event */
            Power_Ip_pxMC_ME->MODE_CONF=MC_ME_MODE_CONF(MC_ME_MODE_CONF_DEST_RST_MASK);
        }
        else if (POWER_IP_FUNC_RESET_MODE == PowerMode)
        {
            /* Makes a request to trigger a Functional Reset Event */
            Power_Ip_pxMC_ME->MODE_CONF=MC_ME_MODE_CONF(MC_ME_MODE_CONF_FUNC_RST_MASK);
        }
        else
        {
            /* Should never happen. Throw an error. */
        }
    }

    /* Trigger the update in hardware */
    Power_Ip_MC_ME_TriggerModeUpdate();
}

#if (defined(POWER_IP_ENTER_LOW_POWER_MODE))
  #if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
/**
* @brief            This function will transition a core to Standby mode.
* @details          This function will transition a core to Standby mode.
*
* @param[in]        ModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
*/
void Power_Ip_MC_ME_CoreStandbyEntry(const Power_Ip_ModeConfigType * ModeConfigPtr)
{
    (void)ModeConfigPtr;
#ifdef MCAL_PLATFORM_ARM
    /* Finish/Retire outstanding instructions */
    MCAL_DATA_SYNC_BARRIER();
#endif
#ifdef POWER_IP_DEEPSLEEP_SUPPORT
#if (POWER_IP_DEEPSLEEP_SUPPORT == STD_ON)
    if (TRUE == ModeConfigPtr->DeepSleep)
    {
        /* Enable Deep Sleep */
        Call_Power_Ip_CM33_EnableDeepSleep();
    }
    else
    {
        Call_Power_Ip_CM33_DisableDeepSleep();
    } 
#endif
#endif
#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
    if (FALSE != ModeConfigPtr->SleepOnExit)
    {
        /* Enable Sleep On Exit */
        Call_Power_Ip_CM33_EnableSleepOnExit();
    }
#endif
#endif
    /* Execute WFI */
    EXECUTE_WAIT();

#ifdef MCAL_PLATFORM_ARM
    /* Finish/Retire outstanding instructions */
    MCAL_DATA_SYNC_BARRIER();
#endif

}
  #endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
#endif


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
