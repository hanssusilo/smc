/*******************************************************************************
* File Name: Direction_1.c  
* Version 2.0
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Direction_1.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Direction_1__PORT == 15 && ((Direction_1__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Direction_1_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Direction_1_Write(uint8 value) 
{
    uint8 staticBits = (Direction_1_DR & (uint8)(~Direction_1_MASK));
    Direction_1_DR = staticBits | ((uint8)(value << Direction_1_SHIFT) & Direction_1_MASK);
}


/*******************************************************************************
* Function Name: Direction_1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Direction_1_DM_STRONG     Strong Drive 
*  Direction_1_DM_OD_HI      Open Drain, Drives High 
*  Direction_1_DM_OD_LO      Open Drain, Drives Low 
*  Direction_1_DM_RES_UP     Resistive Pull Up 
*  Direction_1_DM_RES_DWN    Resistive Pull Down 
*  Direction_1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Direction_1_DM_DIG_HIZ    High Impedance Digital 
*  Direction_1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Direction_1_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Direction_1_0, mode);
}


/*******************************************************************************
* Function Name: Direction_1_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Direction_1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Direction_1_Read(void) 
{
    return (Direction_1_PS & Direction_1_MASK) >> Direction_1_SHIFT;
}


/*******************************************************************************
* Function Name: Direction_1_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Direction_1_ReadDataReg(void) 
{
    return (Direction_1_DR & Direction_1_MASK) >> Direction_1_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Direction_1_INTSTAT) 

    /*******************************************************************************
    * Function Name: Direction_1_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Direction_1_ClearInterrupt(void) 
    {
        return (Direction_1_INTSTAT & Direction_1_MASK) >> Direction_1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
