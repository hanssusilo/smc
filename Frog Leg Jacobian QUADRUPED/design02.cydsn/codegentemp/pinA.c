/*******************************************************************************
* File Name: pinA.c  
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
#include "pinA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 pinA__PORT == 15 && ((pinA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: pinA_Write
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
void pinA_Write(uint8 value) 
{
    uint8 staticBits = (pinA_DR & (uint8)(~pinA_MASK));
    pinA_DR = staticBits | ((uint8)(value << pinA_SHIFT) & pinA_MASK);
}


/*******************************************************************************
* Function Name: pinA_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  pinA_DM_STRONG     Strong Drive 
*  pinA_DM_OD_HI      Open Drain, Drives High 
*  pinA_DM_OD_LO      Open Drain, Drives Low 
*  pinA_DM_RES_UP     Resistive Pull Up 
*  pinA_DM_RES_DWN    Resistive Pull Down 
*  pinA_DM_RES_UPDWN  Resistive Pull Up/Down 
*  pinA_DM_DIG_HIZ    High Impedance Digital 
*  pinA_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void pinA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(pinA_0, mode);
}


/*******************************************************************************
* Function Name: pinA_Read
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
*  Macro pinA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 pinA_Read(void) 
{
    return (pinA_PS & pinA_MASK) >> pinA_SHIFT;
}


/*******************************************************************************
* Function Name: pinA_ReadDataReg
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
uint8 pinA_ReadDataReg(void) 
{
    return (pinA_DR & pinA_MASK) >> pinA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(pinA_INTSTAT) 

    /*******************************************************************************
    * Function Name: pinA_ClearInterrupt
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
    uint8 pinA_ClearInterrupt(void) 
    {
        return (pinA_INTSTAT & pinA_MASK) >> pinA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
