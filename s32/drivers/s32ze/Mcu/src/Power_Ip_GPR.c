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
*   @file       Power_Ip_GPR.c
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
#include "Power_Ip_Private.h"
#include "Power_Ip_GPR.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_GPR_VENDOR_ID_C                      43
#define POWER_IP_GPR_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_GPR_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_GPR_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_GPR_SW_MAJOR_VERSION_C               1
#define POWER_IP_GPR_SW_MINOR_VERSION_C               0
#define POWER_IP_GPR_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_GPR.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_GPR_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_GPR.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip_GPR.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_GPR_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_GPR_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_GPR_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_GPR.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_GPR.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_GPR_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_GPR_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_GPR_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_GPR.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_GPR.c file and Power_Ip_GPR.h file are of the same vendor */
#if (POWER_IP_GPR_VENDOR_ID_C != POWER_IP_GPR_VENDOR_ID)
    #error "Power_Ip_GPR.c and Power_Ip_GPR.h have different vendor ids"
#endif

/* Check if Power_Ip_GPR.c file and Power_Ip_GPR.h file are of the same Autosar version */
#if ((POWER_IP_GPR_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_GPR_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_GPR_AR_RELEASE_MINOR_VERSION_C != POWER_IP_GPR_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_GPR_AR_RELEASE_REVISION_VERSION_C != POWER_IP_GPR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_GPR.c and Power_Ip_GPR.h are different"
#endif

/* Check if Power_Ip_GPR.c file and Power_Ip_GPR.h file are of the same Software version */
#if ((POWER_IP_GPR_SW_MAJOR_VERSION_C != POWER_IP_GPR_SW_MAJOR_VERSION) || \
     (POWER_IP_GPR_SW_MINOR_VERSION_C != POWER_IP_GPR_SW_MINOR_VERSION) || \
     (POWER_IP_GPR_SW_PATCH_VERSION_C != POWER_IP_GPR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_GPR.c and Power_Ip_GPR.h are different"
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
static Power_Ip_GprClockControlEnable_Type* const Power_Ip_apxGprClockControlEnable[POWER_IP_PERIPHERAL_GROUPS_COUNT] =
{
    (Power_Ip_GprClockControlEnable_Type*)(IP_GPR0_PCTL_BASE),
    (Power_Ip_GprClockControlEnable_Type*)(IP_GPR1_PCTL_BASE),
    NULL_PTR,
    (Power_Ip_GprClockControlEnable_Type*)(IP_GPR3_PCTL_BASE),
    (Power_Ip_GprClockControlEnable_Type*)(IP_GPR4_PCTL_BASE),
    (Power_Ip_GprClockControlEnable_Type*)(IP_GPR5_PCTL_BASE),
    (Power_Ip_GprClockControlEnable_Type*)(IP_GPR6_PCTL_BASE),
};


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function configure the General-Purpose Registers
* @details          Control to clock gate for peripherals.
*
* @param[in]        ConfigPtr   Pointer to GPR configuration structure.
*
* @return           void
*
*/
void Power_Ip_GPR_Config(const Power_Ip_GPR_ConfigType * ConfigPtr)
{
    (void)ConfigPtr;
    const Power_Ip_Peripheral_ConfigType *TempPerConfig = NULL_PTR;
    uint8 PerIndex;
    uint32 GprPctlMask;

    for (PerIndex = 0U; PerIndex < POWER_IP_PERIPHERALS_NO; PerIndex++)
    {
        TempPerConfig = &(*ConfigPtr->ArrayPeripheralConfigPtr)[PerIndex];
        
        switch(PerIndex)
        {
            case POWER_IP_DMACRC0_PCLT_INDEX:
            case POWER_IP_DMACRC1_PCLT_INDEX:
            case POWER_IP_DMACRC4_PCLT_INDEX:
            case POWER_IP_DMACRC5_PCLT_INDEX:
            case POWER_IP_NANO_PCLT_INDEX:
                GprPctlMask = GPR_PCTL_1_MASK;
                break;
            case POWER_IP_DMAMUX0_PCLT_INDEX:
            case POWER_IP_DMAMUX1_PCLT_INDEX:
            case POWER_IP_DMAMUX4_PCLT_INDEX:
            case POWER_IP_DMAMUX5_PCLT_INDEX:
                GprPctlMask = GPR_PCTL_2_MASK;
                break;
            case POWER_IP_PIT_0_PCLT_INDEX:
            case POWER_IP_PIT_1_PCLT_INDEX:
            case POWER_IP_PIT_4_PCLT_INDEX:
            case POWER_IP_PIT_5_PCLT_INDEX:
                GprPctlMask = GPR_PCTL_3_MASK;
                break;
            default:
                GprPctlMask = GPR_PCTL_MASK;
                break;
        }
        
        if(TRUE == TempPerConfig->GprUnderMcuControl)
        {
            if (TRUE == TempPerConfig->Gate)
            {
                Power_Ip_apxGprClockControlEnable[TempPerConfig->GprGroupIndex]->PCTL[TempPerConfig->GprPerIndex] |= GprPctlMask;
            }
            else
            {
                Power_Ip_apxGprClockControlEnable[TempPerConfig->GprGroupIndex]->PCTL[TempPerConfig->GprPerIndex] &= ~GprPctlMask;
            }
        }
    }
}

#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
