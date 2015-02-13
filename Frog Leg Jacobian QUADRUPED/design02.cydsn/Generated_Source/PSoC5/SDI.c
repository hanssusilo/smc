/*******************************************************************************
* File Name: SDI.c  
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
#include "SDI.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SDI__PORT == 15 && ((SDI__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SDI_Write
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
void SDI_Write(uint8 value) 
{
    uint8 staticBits = (SDI_DR & (uint8)(~SDI_MASK));
    SDI_DR = staticBits | ((uint8)(value << SDI_SHIFT) & SDI_MASK);
}


/*******************************************************************************
* Function Name: SDI_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SDI_DM_STRONG     Strong Drive 
*  SDI_DM_OD_HI      Open Drain, Drives High 
*  SDI_DM_OD_LO      Open Drain, Drives Low 
*  SDI_DM_RES_UP     Resistive Pull Up 
*  SDI_DM_RES_DWN    Resistive Pull Down 
*  SDI_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SDI_DM_DIG_HIZ    High Impedance Digital 
*  SDI_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SDI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SDI_0, mode);
}


/*******************************************************************************
* Function Name: SDI_Read
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
*  Macro SDI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SDI_Read(void) 
{
    return (SDI_PS & SDI_MASK) >> SDI_SHIFT;
}


/*******************************************************************************
* Function Name: SDI_ReadDataReg
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
uint8 SDI_ReadDataReg(void) 
{
    return (SDI_DR & SDI_MASK) >> SDI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SDI_INTSTAT) 

    /*******************************************************************************
    * Function Name: SDI_ClearInterrupt
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
    uint8 SDI_ClearInterrupt(void) 
    {
        return (SDI_INTSTAT & SDI_MASK) >> SDI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
