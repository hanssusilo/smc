/*******************************************************************************
* File Name: SPI_1_PM.c
* Version 2.40
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_1_PVT.h"

static SPI_1_BACKUP_STRUCT SPI_1_backup =
{
    SPI_1_DISABLED,
    SPI_1_BITCTR_INIT,
    #if(CY_UDB_V0)
        SPI_1_TX_INIT_INTERRUPTS_MASK,
        SPI_1_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


/*******************************************************************************
* Function Name: SPI_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_1_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_1_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if(CY_UDB_V0)
       SPI_1_backup.cntrPeriod      = SPI_1_COUNTER_PERIOD_REG;
       SPI_1_backup.saveSrTxIntMask = SPI_1_TX_STATUS_MASK_REG;
       SPI_1_backup.saveSrRxIntMask = SPI_1_RX_STATUS_MASK_REG;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPI_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_1_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  SPI_1_STATUS_MASK_REG and SPI_1_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPI_1_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if(CY_UDB_V0)
        SPI_1_COUNTER_PERIOD_REG = SPI_1_backup.cntrPeriod;
        SPI_1_TX_STATUS_MASK_REG = ((uint8) SPI_1_backup.saveSrTxIntMask);
        SPI_1_RX_STATUS_MASK_REG = ((uint8) SPI_1_backup.saveSrRxIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPI_1_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_1_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_1_Sleep(void) 
{
    /* Save components enable state */
    SPI_1_backup.enableState = ((uint8) SPI_1_IS_ENABLED);

    SPI_1_Stop();
    SPI_1_SaveConfig();
}


/*******************************************************************************
* Function Name: SPI_1_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_1_backup - used when non-retention registers are restored.
*  SPI_1_txBufferWrite - modified every function call - resets to
*  zero.
*  SPI_1_txBufferRead - modified every function call - resets to
*  zero.
*  SPI_1_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPI_1_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_1_Wakeup(void) 
{
    SPI_1_RestoreConfig();

    #if(SPI_1_RX_SOFTWARE_BUF_ENABLED)
        SPI_1_rxBufferFull  = 0u;
        SPI_1_rxBufferRead  = 0u;
        SPI_1_rxBufferWrite = 0u;
    #endif /* (SPI_1_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPI_1_TX_SOFTWARE_BUF_ENABLED)
        SPI_1_txBufferFull  = 0u;
        SPI_1_txBufferRead  = 0u;
        SPI_1_txBufferWrite = 0u;
    #endif /* (SPI_1_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPI_1_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPI_1_backup.enableState)
    {
        SPI_1_Enable();
    }
}


/* [] END OF FILE */
