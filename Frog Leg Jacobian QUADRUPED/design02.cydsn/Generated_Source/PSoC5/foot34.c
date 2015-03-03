/*******************************************************************************
* File Name: foot34.c  
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
#include "foot34.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 foot34__PORT == 15 && ((foot34__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: foot34_Write
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
void foot34_Write(uint8 value) 
{
    uint8 staticBits = (foot34_DR & (uint8)(~foot34_MASK));
    foot34_DR = staticBits | ((uint8)(value << foot34_SHIFT) & foot34_MASK);
}


/*******************************************************************************
* Function Name: foot34_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  foot34_DM_STRONG     Strong Drive 
*  foot34_DM_OD_HI      Open Drain, Drives High 
*  foot34_DM_OD_LO      Open Drain, Drives Low 
*  foot34_DM_RES_UP     Resistive Pull Up 
*  foot34_DM_RES_DWN    Resistive Pull Down 
*  foot34_DM_RES_UPDWN  Resistive Pull Up/Down 
*  foot34_DM_DIG_HIZ    High Impedance Digital 
*  foot34_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void foot34_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(foot34_0, mode);
}


/*******************************************************************************
* Function Name: foot34_Read
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
*  Macro foot34_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 foot34_Read(void) 
{
    return (foot34_PS & foot34_MASK) >> foot34_SHIFT;
}


/*******************************************************************************
* Function Name: foot34_ReadDataReg
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
uint8 foot34_ReadDataReg(void) 
{
    return (foot34_DR & foot34_MASK) >> foot34_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(foot34_INTSTAT) 

    /*******************************************************************************
    * Function Name: foot34_ClearInterrupt
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
    uint8 foot34_ClearInterrupt(void) 
    {
        return (foot34_INTSTAT & foot34_MASK) >> foot34_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
