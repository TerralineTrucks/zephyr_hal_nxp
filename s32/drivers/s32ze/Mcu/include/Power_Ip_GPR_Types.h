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

#ifndef POWER_IP_GPR_TYPES_H
#define POWER_IP_GPR_TYPES_H

/**
*   @file       Power_Ip_GPR_Types.h
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
#include "Power_Ip_Specific.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_GPR_TYPES_VENDOR_ID                       43
#define POWER_IP_GPR_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_GPR_TYPES_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_GPR_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_GPR_TYPES_SW_MAJOR_VERSION                1
#define POWER_IP_GPR_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_GPR_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_GPR_Types.h file and Power_Ip_Specific.h file have same versions */
#if (POWER_IP_GPR_TYPES_VENDOR_ID  != POWER_IP_SPECIFIC_VENDOR_ID)
    #error "Power_Ip_GPR_Types.h and Power_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Power_Ip_GPR_Types.h file and Power_Ip_Specific.h file are of the same Autosar version */
#if ((POWER_IP_GPR_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_GPR_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_GPR_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_GPR_Types.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_GPR_Types.h file and Power_Ip_Specific.h file are of the same Software version */
#if ((POWER_IP_GPR_TYPES_SW_MAJOR_VERSION != POWER_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (POWER_IP_GPR_TYPES_SW_MINOR_VERSION != POWER_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (POWER_IP_GPR_TYPES_SW_PATCH_VERSION != POWER_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_GPR_Types.h and Power_Ip_Specific.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define GPR_PCTL_MASK                          GPR3_PCTL_EDMACEPCTL_PCTL_MASK
#define GPR_PCTL_0_MASK                        GPR0_PCTL_EDMA0PCTL_PCTL_0_MASK
#define GPR_PCTL_1_MASK                        GPR0_PCTL_EDMA0PCTL_PCTL_1_MASK
#define GPR_PCTL_2_MASK                        GPR0_PCTL_EDMA0PCTL_PCTL_2_MASK
#define GPR_PCTL_3_MASK                        GPR0_PCTL_EDMA0PCTL_PCTL_3_MASK
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct {
    volatile uint32 PCTL[POWER_IP_PERIPHERALS_NO];
}Power_Ip_GprClockControlEnable_Type;


/**
* @brief            Configuration for GPR.
* @details          The general-purpose registers (GPRs) acts as a bridge for mapping the GPR peripheral
 *                  to the GPR address space.
*/
typedef struct
{
    boolean GprUnderMcuControl;   /**< @brief Specifies whether the the GPR registers is under MCU control. */
    uint32  GprGroupIndex;        /**< @brief Group GPR Index */
    uint32  GprPerIndex;          /**< @brief Peripheral Index */
    boolean Gate;                 /**< @brief Clock Gate Enablement (Peripheral_PCTL[PCTL]) */
} Power_Ip_Peripheral_ConfigType;

/**
* @brief   MC_ME IP Configuration.
* @details This structure contains information for configuring the entire MC_ME IP.
*/
typedef struct
{
    /**< @brief MC_ME Mode Partition Settings. */
    const Power_Ip_Peripheral_ConfigType (*ArrayPeripheralConfigPtr)[POWER_IP_PERIPHERALS_NO];

} Power_Ip_GPR_ConfigType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_GPR_TYPES_H */



