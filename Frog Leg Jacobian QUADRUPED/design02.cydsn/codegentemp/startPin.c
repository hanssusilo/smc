/*******************************************************************************
* File Name: startPin.c  
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
#include "startPin.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 startPin__PORT == 15 && ((startPin__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: startPin_Write
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
void startPin_Write(uint8 value) 
{
    uint8 staticBits = (startPin_DR & (uint8)(~startPin_MASK));
    startPin_DR = staticBits | ((uint8)(value << startPin_SHIFT) & startPin_MASK);
}


/*******************************************************************************
* Function Name: startPin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  startPin_DM_STRONG     Strong Drive 
*  startPin_DM_OD_HI      Open Drain, Drives High 
*  startPin_DM_OD_LO      Open Drain, Drives Low 
*  startPin_DM_RES_UP     Resistive Pull Up 
*  startPin_DM_RES_DWN    Resistive Pull Down 
*  startPin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  startPin_DM_DIG_HIZ    High Impedance Digital 
*  startPin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void startPin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(startPin_0, mode);
}


/*******************************************************************************
* Function Name: startPin_Read
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
*  Macro startPin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 startPin_Read(void) 
{
    return (startPin_PS & startPin_MASK) >> startPin_SHIFT;
}


/*******************************************************************************
* Function Name: startPin_ReadDataReg
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
uint8 startPin_ReadDataReg(void) 
{
    return (startPin_DR & startPin_MASK) >> startPin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(startPin_INTSTAT) 

    /*******************************************************************************
    * Function Name: startPin_ClearInterrupt
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
    uint8 startPin_ClearInterrupt(void) 
    {
        return (startPin_INTSTAT & startPin_MASK) >> startPin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
