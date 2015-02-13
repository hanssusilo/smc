/*******************************************************************************
* File Name: onPin.c  
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
#include "onPin.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 onPin__PORT == 15 && ((onPin__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: onPin_Write
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
void onPin_Write(uint8 value) 
{
    uint8 staticBits = (onPin_DR & (uint8)(~onPin_MASK));
    onPin_DR = staticBits | ((uint8)(value << onPin_SHIFT) & onPin_MASK);
}


/*******************************************************************************
* Function Name: onPin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  onPin_DM_STRONG     Strong Drive 
*  onPin_DM_OD_HI      Open Drain, Drives High 
*  onPin_DM_OD_LO      Open Drain, Drives Low 
*  onPin_DM_RES_UP     Resistive Pull Up 
*  onPin_DM_RES_DWN    Resistive Pull Down 
*  onPin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  onPin_DM_DIG_HIZ    High Impedance Digital 
*  onPin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void onPin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(onPin_0, mode);
}


/*******************************************************************************
* Function Name: onPin_Read
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
*  Macro onPin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 onPin_Read(void) 
{
    return (onPin_PS & onPin_MASK) >> onPin_SHIFT;
}


/*******************************************************************************
* Function Name: onPin_ReadDataReg
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
uint8 onPin_ReadDataReg(void) 
{
    return (onPin_DR & onPin_MASK) >> onPin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(onPin_INTSTAT) 

    /*******************************************************************************
    * Function Name: onPin_ClearInterrupt
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
    uint8 onPin_ClearInterrupt(void) 
    {
        return (onPin_INTSTAT & onPin_MASK) >> onPin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
