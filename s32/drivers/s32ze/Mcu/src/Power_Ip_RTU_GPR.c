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
*   @file       Power_Ip_FLASH.c
*   @version    1.0.0
*
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif




/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Private.h"
#include "Power_Ip_RTU_GPR.h"
#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_RTU_GPR_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE)
      #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
      #include "RegLockMacros.h"
    #endif /* (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_RTU_GPR_VENDOR_ID_C                      43
#define POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_RTU_GPR_SW_MAJOR_VERSION_C               1
#define POWER_IP_RTU_GPR_SW_MINOR_VERSION_C               0
#define POWER_IP_RTU_GPR_SW_PATCH_VERSION_C               0

/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Power_Ip_RTU_GPR.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_RTU_GPR_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_RTU_GPR.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip_RTU_GPR.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_RTU_GPR.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_RTU_GPR.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_RTU_GPR_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_RTU_GPR.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_RTU_GPR.c file and Power_Ip_RTU_GPR.h file are of the same vendor */
#if (POWER_IP_RTU_GPR_VENDOR_ID_C != POWER_IP_RTU_GPR_VENDOR_ID)
    #error "Power_Ip_RTU_GPR.c and Power_Ip_RTU_GPR.h have different vendor ids"
#endif

/* Check if Power_Ip_RTU_GPR.c file and Power_Ip_RTU_GPR.h file are of the same Autosar version */
#if ((POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION_C != POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION_C != POWER_IP_RTU_GPR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_RTU_GPR.c and Power_Ip_RTU_GPR.h are different"
#endif

/* Check if Power_Ip_RTU_GPR.c file and Power_Ip_RTU_GPR.h file are of the same Software version */
#if ((POWER_IP_RTU_GPR_SW_MAJOR_VERSION_C != POWER_IP_RTU_GPR_SW_MAJOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_MINOR_VERSION_C != POWER_IP_RTU_GPR_SW_MINOR_VERSION) || \
     (POWER_IP_RTU_GPR_SW_PATCH_VERSION_C != POWER_IP_RTU_GPR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_RTU_GPR.c and Power_Ip_RTU_GPR.h are different"
#endif

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_RTU_GPR_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE)
        #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
            /* Check if Power_Ip_RTU_GPR.c file and RegLockMacros.h file are of the same Autosar version */
            #if ((POWER_IP_RTU_GPR_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                (POWER_IP_RTU_GPR_AR_RELEASE_MINOR_VERSION_C     != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Power_Ip_RTU_GPR.c and RegLockMacros.h are different"
            #endif
        #endif
    #endif /* (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static RTU_GPR_Type * Power_Ip_pxRtuGpr[3] =
{
    (RTU_GPR_Type *)NULL_PTR,
    (RTU_GPR_Type *)IP_RTU0__GPR_BASE,
    (RTU_GPR_Type *)IP_RTU1__GPR_BASE
};

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

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_RTU_GPR_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
void Power_Ip_RTU_GPR_SetUserAccessAllowed(void)
{
#if (defined(IP_RTU0__GPR_BASE))
    SET_USER_ACCESS_ALLOWED(IP_RTU0__GPR_BASE, RTU_GPR_PROT_MEM_U32);
#endif
#if (defined(IP_RTU1__GPR_BASE))
    SET_USER_ACCESS_ALLOWED(IP_RTU1__GPR_BASE, RTU_GPR_PROT_MEM_U32);
#endif
}
    #endif /* (STD_ON == MCAL_RTU_GPR_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */

/**
* @brief            This function configures Fence and Drain Controller for Domain.
* @details          This function configures Fence and Drain Controller by fencing off
*                   any new bus transactions and draining all  outstanding transactions.
*                   To be used when turn on/off partitions.
*
* @param[in]        DomainIndex The Domain Index
* @param[in]        Active Active the Fence and Drain Sequence or not
*
* @return           void
*
*/
void Power_Ip_RTU_GPR_FenceDrainDomainController(uint8 DomainIndex, boolean Active)
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;
    uint32 CoreFenceDrainStatus;
    uint32 TempValue;

    if (Active)
    {
        /* Stage 1: Quiesce Cortex-R52 master ports */
        TempValue = Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD;
        TempValue |= RTU_GPR_CFG_FD_MFD_FFD_LFD_RWBITS_MASK32;
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD = TempValue;

        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

            CoreFenceDrainStatus = Power_Ip_pxRtuGpr[DomainIndex]->STAT_FD;
        } while (((CoreFenceDrainStatus & RTU_GPR_STAT_FD_MFD_FFD_LFD_MASK32) != RTU_GPR_STAT_FD_MFD_FFD_LFD_MASK32) && (!TimeoutOccurred));
        /* timeout notification */
        if(TimeoutOccurred)
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }

        /* Stage 2: Quiesce Cortex-R52 slave port */
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD |= RTU_GPR_CFG_FD_SFDEN_MASK;
        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

            CoreFenceDrainStatus = Power_Ip_pxRtuGpr[DomainIndex]->STAT_FD;
        } while (((CoreFenceDrainStatus & RTU_GPR_STAT_FD_SFDID_MASK) != RTU_GPR_STAT_FD_SFDID_MASK) && (!TimeoutOccurred));
        /* timeout notification */
        if(TimeoutOccurred)
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }

        /* Stage 3: Isolate Cortex-R52 core I/O */
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD |= RTU_GPR_CFG_FD_ISOLENX_RWBITS_MASK32;
    }
    else
    {
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD = ~(RTU_GPR_CFG_FD_RWBITS_MASK32);
    }
}

/**
* @brief            This function configures Fence and Drain Controller for Core.
* @details          This function configures Fence and Drain Controller by fencing off
*                   any new bus transactions and draining all  outstanding transactions.
*                   To be used when turn on/off cores.
*
* @param[in]        DomainIndex The Domain Index
* @param[in]        CoreIndex The Core Index
* @param[in]        Active Active the Fence and Drain Sequence or not
*
* @return           void
*
*/
void Power_Ip_RTU_GPR_FenceDrainCoreController(uint8 DomainIndex, uint8 CoreIndex, boolean Active)
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;
    uint32 CoreFenceDrainStatus;
    uint32 TempValue;

    if (Active)
    {
        /* Stage 1: Quiesce Cortex-R52 master ports */
        TempValue = Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD;
        TempValue |= (RTU_GPR_CFG_FD_MFDEN(CoreIndex) | RTU_GPR_CFG_FD_FFDEN(CoreIndex) | RTU_GPR_CFG_FD_LFDEN(CoreIndex));
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD |= TempValue;

        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

            CoreFenceDrainStatus = Power_Ip_pxRtuGpr[DomainIndex]->STAT_FD;
        } while ((((CoreFenceDrainStatus & RTU_GPR_STAT_FD_MFDID_FFDID_LFDID(CoreIndex))) != RTU_GPR_STAT_FD_MFDID_FFDID_LFDID(CoreIndex)) && (!TimeoutOccurred));
        /* timeout notification */
        if(TimeoutOccurred)
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }

        /* Stage 2: Quiesce Cortex-R52 slave port */
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD |= RTU_GPR_CFG_FD_SFDEN_MASK;
        Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

            CoreFenceDrainStatus = Power_Ip_pxRtuGpr[DomainIndex]->STAT_FD;
        } while (((CoreFenceDrainStatus & RTU_GPR_STAT_FD_SFDID_MASK) != RTU_GPR_STAT_FD_SFDID_MASK) && (!TimeoutOccurred));
        /* timeout notification */
        if(TimeoutOccurred)
        {
            Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
        }

        /* Stage 3: Isolate Cortex-R52 core I/O */
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD |= RTU_GPR_CFG_FD_ISOLEN(CoreIndex);
    }
    else
    {
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD &= ~(RTU_GPR_STAT_FD_MFDID_FFDID_LFDID(CoreIndex) | RTU_GPR_CFG_FD_ISOLEN(CoreIndex));
    }
}

/**
* @brief            This function performs release Quiesce State for Core.
* @details          This function performs release Quiesce State for Core
*
* @param[in]        DomainIndex The Domain Index
* @param[in]        CoreIndex The Core Index
*
* @return           void
*
*/
void Power_Ip_RTU_GPR_CoreReleaseQuiesceState(uint8 DomainIndex, uint8 CoreIndex)
{
    uint32 TempValue;

    TempValue = ~(RTU_GPR_CFG_FD_MFDID_FFDID_LFDID_ISOLEN(CoreIndex) | RTU_GPR_STAT_FD_SFDID_MASK);
    Power_Ip_pxRtuGpr[DomainIndex]->CFG_FD &= TempValue;
}

/**
* @brief            This function configures Core Halt Control.
* @details          This function configures Core Halt behavior for each core Cortex-R52
*
* @param[in]        DomainIndex The Domain Index
* @param[in]        CoreIndex The Core Index
* @param[in]        Enable Enable core halt control for corresponds core
*
* @return           void
*
*/
void Power_Ip_RTU_GPR_CoreHaltConfig(uint8 DomainIndex, uint8 CoreIndex, boolean Enable)
{
    if (Enable)
    {
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_HALT |= (1UL << CoreIndex);
    }
    else
    {
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_HALT &= ~(1UL << CoreIndex);
    }
}

/**
* @brief            This function checks the status of TCM Booting.
* @details          This function checks the status of TCM Booting.
*
* @param[in]        DomainIndex The Domain Index
*
* @return           Status of Tcm booting
*
*/
uint8 Power_Ip_RTU_GPR_CheckTcmBooting(uint8 DomainIndex)
{
    uint8 TcmBootingStatus;

    TcmBootingStatus = (uint8)((Power_Ip_pxRtuGpr[DomainIndex]->CFG_CORE & RTU_GPR_CFG_CORE_TCM_BT_MASK) >> RTU_GPR_CFG_CORE_TCM_BT_SHIFT);

    return TcmBootingStatus;
}

/**
* @brief            This functions to set mode for Cortex-R52 processor.
* @details          This functions to set mode for Cortex-R52 processor operates in Lockstep mode or Split-Lock mode.
*
* @param[in]        DomainIndex The Domain Index
* @param[in]        Active is TRUE, LockStep mode selected; ACTIVE is FALSE, Split-Lock mode selected.
*
*
*/
void Power_Ip_RTU_GPR_SetLockstepMode(uint8 DomainIndex, boolean Active)
{    
    if (Active)
    {
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_CORE &= ~RTU_GPR_CFG_CORE_SPLT_LCK(1U);
    }
    else
    {
        Power_Ip_pxRtuGpr[DomainIndex]->CFG_CORE |= RTU_GPR_CFG_CORE_SPLT_LCK(1U);
    }
}

/**
* @brief            This functions to check mode operation for Cortex-R52 processor.
* @details          This functions to check mode operation for Cortex-R52 processor operates in Lockstep mode or Split-Lock mode.
*
* @param[in]        DomainIndex The Domain Index
* 
* @return           TRUE Mode is lockstep.
* @return           FALSE Mode is split.
*
*/
uint8 Power_Ip_RTU_GPR_CheckEnLockStepMode(uint8 DomainIndex)
{
    uint8 RetVal;
    
    if (RTU_GPR_CFG_CORE_SPLT_LCK_MASK == (Power_Ip_pxRtuGpr[DomainIndex]->CFG_CORE & RTU_GPR_CFG_CORE_SPLT_LCK_MASK))
    {
        RetVal = FALSE;
    }
    else
    {
        RetVal = TRUE;
    }
    
    return RetVal;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
