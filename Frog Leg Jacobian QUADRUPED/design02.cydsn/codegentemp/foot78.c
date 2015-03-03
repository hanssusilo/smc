/*******************************************************************************
* File Name: foot78.c  
* Version 2.5
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
#include "foot78.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 foot78__PORT == 15 && ((foot78__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: foot78_Write
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
void foot78_Write(uint8 value) 
{
    uint8 staticBits = (foot78_DR & (uint8)(~foot78_MASK));
    foot78_DR = staticBits | ((uint8)(value << foot78_SHIFT) & foot78_MASK);
}


/*******************************************************************************
* Function Name: foot78_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  foot78_DM_STRONG     Strong Drive 
*  foot78_DM_OD_HI      Open Drain, Drives High 
*  foot78_DM_OD_LO      Open Drain, Drives Low 
*  foot78_DM_RES_UP     Resistive Pull Up 
*  foot78_DM_RES_DWN    Resistive Pull Down 
*  foot78_DM_RES_UPDWN  Resistive Pull Up/Down 
*  foot78_DM_DIG_HIZ    High Impedance Digital 
*  foot78_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void foot78_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(foot78_0, mode);
}


/*******************************************************************************
* Function Name: foot78_Read
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
*  Macro foot78_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 foot78_Read(void) 
{
    return (foot78_PS & foot78_MASK) >> foot78_SHIFT;
}


/*******************************************************************************
* Function Name: foot78_ReadDataReg
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
uint8 foot78_ReadDataReg(void) 
{
    return (foot78_DR & foot78_MASK) >> foot78_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(foot78_INTSTAT) 

    /*******************************************************************************
    * Function Name: foot78_ClearInterrupt
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
    uint8 foot78_ClearInterrupt(void) 
    {
        return (foot78_INTSTAT & foot78_MASK) >> foot78_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
