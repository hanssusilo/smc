/*******************************************************************************
* File Name: ePin.c  
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
#include "ePin.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ePin__PORT == 15 && ((ePin__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ePin_Write
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
void ePin_Write(uint8 value) 
{
    uint8 staticBits = (ePin_DR & (uint8)(~ePin_MASK));
    ePin_DR = staticBits | ((uint8)(value << ePin_SHIFT) & ePin_MASK);
}


/*******************************************************************************
* Function Name: ePin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ePin_DM_STRONG     Strong Drive 
*  ePin_DM_OD_HI      Open Drain, Drives High 
*  ePin_DM_OD_LO      Open Drain, Drives Low 
*  ePin_DM_RES_UP     Resistive Pull Up 
*  ePin_DM_RES_DWN    Resistive Pull Down 
*  ePin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ePin_DM_DIG_HIZ    High Impedance Digital 
*  ePin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ePin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ePin_0, mode);
}


/*******************************************************************************
* Function Name: ePin_Read
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
*  Macro ePin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ePin_Read(void) 
{
    return (ePin_PS & ePin_MASK) >> ePin_SHIFT;
}


/*******************************************************************************
* Function Name: ePin_ReadDataReg
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
uint8 ePin_ReadDataReg(void) 
{
    return (ePin_DR & ePin_MASK) >> ePin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ePin_INTSTAT) 

    /*******************************************************************************
    * Function Name: ePin_ClearInterrupt
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
    uint8 ePin_ClearInterrupt(void) 
    {
        return (ePin_INTSTAT & ePin_MASK) >> ePin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
