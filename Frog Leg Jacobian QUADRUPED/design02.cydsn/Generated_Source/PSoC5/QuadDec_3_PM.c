/*******************************************************************************
* File Name: QuadDec_3_PM.c
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

#include "QuadDec_3.h"

static QuadDec_3_BACKUP_STRUCT QuadDec_3_backup = {0u};


/*******************************************************************************
* Function Name: QuadDec_3_SaveConfig
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
void QuadDec_3_SaveConfig(void) 
{
    #if (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_8_BIT)
        QuadDec_3_Cnt8_SaveConfig();
    #else 
        /* (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_16_BIT) || 
         * (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_32_BIT)
         */
        QuadDec_3_Cnt16_SaveConfig();
    #endif /* (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDec_3_RestoreConfig
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
void QuadDec_3_RestoreConfig(void) 
{
    #if (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_8_BIT)
        QuadDec_3_Cnt8_RestoreConfig();
    #else 
        /* (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_16_BIT) || 
         * (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_32_BIT) 
         */
        QuadDec_3_Cnt16_RestoreConfig();
    #endif /* (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDec_3_Sleep
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
*  QuadDec_3_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDec_3_Sleep(void) 
{
    if (0u != (QuadDec_3_SR_AUX_CONTROL & QuadDec_3_INTERRUPTS_ENABLE))
    {
        QuadDec_3_backup.enableState = 1u;
    }
    else /* The Quadrature Decoder Component is disabled */
    {
        QuadDec_3_backup.enableState = 0u;
    }

    QuadDec_3_Stop();
    QuadDec_3_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_3_Wakeup
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
*  QuadDec_3_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void QuadDec_3_Wakeup(void) 
{
    QuadDec_3_RestoreConfig();

    if (QuadDec_3_backup.enableState != 0u)
    {
        #if (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_8_BIT)
            QuadDec_3_Cnt8_Enable();
        #else 
            /* (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_16_BIT) || 
            *  (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_32_BIT) 
            */
            QuadDec_3_Cnt16_Enable();
        #endif /* (QuadDec_3_COUNTER_SIZE == QuadDec_3_COUNTER_SIZE_8_BIT) */

        /* Enable component's operation */
        QuadDec_3_Enable();
    } /* Do nothing if component's block was disabled before */
}


/* [] END OF FILE */

