/*******************************************************************************
* File Name: QuadDec_4_PM.c
* Version 2.30
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "QuadDec_4.h"

static QuadDec_4_BACKUP_STRUCT QuadDec_4_backup = {0u};


/*******************************************************************************
* Function Name: QuadDec_4_SaveConfig
********************************************************************************
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDec_4_SaveConfig(void) 
{
    #if (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_8_BIT)
        QuadDec_4_Cnt8_SaveConfig();
    #else 
        /* (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_16_BIT) || 
         * (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_32_BIT)
         */
        QuadDec_4_Cnt16_SaveConfig();
    #endif /* (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDec_4_RestoreConfig
********************************************************************************
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDec_4_RestoreConfig(void) 
{
    #if (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_8_BIT)
        QuadDec_4_Cnt8_RestoreConfig();
    #else 
        /* (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_16_BIT) || 
         * (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_32_BIT) 
         */
        QuadDec_4_Cnt16_RestoreConfig();
    #endif /* (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDec_4_Sleep
********************************************************************************
* 
* Summary:
*  Prepare Quadrature Decoder Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QuadDec_4_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDec_4_Sleep(void) 
{
    if (0u != (QuadDec_4_SR_AUX_CONTROL & QuadDec_4_INTERRUPTS_ENABLE))
    {
        QuadDec_4_backup.enableState = 1u;
    }
    else /* The Quadrature Decoder Component is disabled */
    {
        QuadDec_4_backup.enableState = 0u;
    }

    QuadDec_4_Stop();
    QuadDec_4_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_4_Wakeup
********************************************************************************
*
* Summary:
*  Prepare Quadrature Decoder Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QuadDec_4_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void QuadDec_4_Wakeup(void) 
{
    QuadDec_4_RestoreConfig();

    if (QuadDec_4_backup.enableState != 0u)
    {
        #if (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_8_BIT)
            QuadDec_4_Cnt8_Enable();
        #else 
            /* (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_16_BIT) || 
            *  (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_32_BIT) 
            */
            QuadDec_4_Cnt16_Enable();
        #endif /* (QuadDec_4_COUNTER_SIZE == QuadDec_4_COUNTER_SIZE_8_BIT) */

        /* Enable component's operation */
        QuadDec_4_Enable();
    } /* Do nothing if component's block was disabled before */
}


/* [] END OF FILE */
