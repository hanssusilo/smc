/*******************************************************************************
* File Name: SPI_1_INT.c
* Version 2.40
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
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

#include "SPI_1_PVT.h"

/* User code required at start of ISR */
/* `#START SPI_1_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPI_1_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPI_1_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPI_1_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPI_1_txBuffer[SPI_1_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPI_1_TX_ISR)
{
    #if(SPI_1_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (SPI_1_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START SPI_1_TX_ISR_START` */

    /* `#END` */

    #if(SPI_1_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(SPI_1_txBufferRead != SPI_1_txBufferWrite)
        {
            tmpStatus = SPI_1_GET_STATUS_TX(SPI_1_swStatusTx);
            SPI_1_swStatusTx = tmpStatus;

            if(0u != (SPI_1_swStatusTx & SPI_1_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == SPI_1_txBufferFull)
                {
                   SPI_1_txBufferRead++;

                    if(SPI_1_txBufferRead >= SPI_1_TX_BUFFER_SIZE)
                    {
                        SPI_1_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPI_1_txBufferFull = 0u;
                }

                /* Move data from the Buffer to the FIFO */
                CY_SET_REG8(SPI_1_TXDATA_PTR,
                    SPI_1_txBuffer[SPI_1_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(SPI_1_txBufferRead == SPI_1_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            SPI_1_TX_STATUS_MASK_REG &= ((uint8) ~SPI_1_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (SPI_1_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPI_1_TX_ISR_END` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: SPI_1_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPI_1_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPI_1_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPI_1_rxBuffer[SPI_1_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPI_1_RX_ISR)
{
    #if(SPI_1_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (SPI_1_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START SPI_1_RX_ISR_START` */

    /* `#END` */

    #if(SPI_1_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = SPI_1_GET_STATUS_RX(SPI_1_swStatusRx);
        SPI_1_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (SPI_1_swStatusRx & SPI_1_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG8(SPI_1_RXDATA_PTR);

            /* Set next pointer. */
            SPI_1_rxBufferWrite++;
            if(SPI_1_rxBufferWrite >= SPI_1_RX_BUFFER_SIZE)
            {
                SPI_1_rxBufferWrite = 0u;
            }

            if(SPI_1_rxBufferWrite == SPI_1_rxBufferRead)
            {
                SPI_1_rxBufferRead++;
                if(SPI_1_rxBufferRead >= SPI_1_RX_BUFFER_SIZE)
                {
                    SPI_1_rxBufferRead = 0u;
                }

                SPI_1_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPI_1_rxBuffer[SPI_1_rxBufferWrite] = rxData;

            tmpStatus = SPI_1_GET_STATUS_RX(SPI_1_swStatusRx);
            SPI_1_swStatusRx = tmpStatus;
        }

    #endif /* (SPI_1_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPI_1_RX_ISR_END` */

    /* `#END` */
}

/* [] END OF FILE */
