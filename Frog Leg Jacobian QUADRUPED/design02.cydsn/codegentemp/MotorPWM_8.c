/*******************************************************************************
* File Name: MotorPWM_8.c  
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
#include "MotorPWM_8.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MotorPWM_8__PORT == 15 && ((MotorPWM_8__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MotorPWM_8_Write
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
void MotorPWM_8_Write(uint8 value) 
{
    uint8 staticBits = (MotorPWM_8_DR & (uint8)(~MotorPWM_8_MASK));
    MotorPWM_8_DR = staticBits | ((uint8)(value << MotorPWM_8_SHIFT) & MotorPWM_8_MASK);
}


/*******************************************************************************
* Function Name: MotorPWM_8_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MotorPWM_8_DM_STRONG     Strong Drive 
*  MotorPWM_8_DM_OD_HI      Open Drain, Drives High 
*  MotorPWM_8_DM_OD_LO      Open Drain, Drives Low 
*  MotorPWM_8_DM_RES_UP     Resistive Pull Up 
*  MotorPWM_8_DM_RES_DWN    Resistive Pull Down 
*  MotorPWM_8_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MotorPWM_8_DM_DIG_HIZ    High Impedance Digital 
*  MotorPWM_8_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MotorPWM_8_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MotorPWM_8_0, mode);
}


/*******************************************************************************
* Function Name: MotorPWM_8_Read
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
*  Macro MotorPWM_8_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MotorPWM_8_Read(void) 
{
    return (MotorPWM_8_PS & MotorPWM_8_MASK) >> MotorPWM_8_SHIFT;
}


/*******************************************************************************
* Function Name: MotorPWM_8_ReadDataReg
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
uint8 MotorPWM_8_ReadDataReg(void) 
{
    return (MotorPWM_8_DR & MotorPWM_8_MASK) >> MotorPWM_8_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MotorPWM_8_INTSTAT) 

    /*******************************************************************************
    * Function Name: MotorPWM_8_ClearInterrupt
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
    uint8 MotorPWM_8_ClearInterrupt(void) 
    {
        return (MotorPWM_8_INTSTAT & MotorPWM_8_MASK) >> MotorPWM_8_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
