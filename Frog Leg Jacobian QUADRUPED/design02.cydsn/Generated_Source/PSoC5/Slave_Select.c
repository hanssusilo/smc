/*******************************************************************************
* File Name: Slave_Select.c  
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
#include "Slave_Select.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Slave_Select__PORT == 15 && ((Slave_Select__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Slave_Select_Write
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
void Slave_Select_Write(uint8 value) 
{
    uint8 staticBits = (Slave_Select_DR & (uint8)(~Slave_Select_MASK));
    Slave_Select_DR = staticBits | ((uint8)(value << Slave_Select_SHIFT) & Slave_Select_MASK);
}


/*******************************************************************************
* Function Name: Slave_Select_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Slave_Select_DM_STRONG     Strong Drive 
*  Slave_Select_DM_OD_HI      Open Drain, Drives High 
*  Slave_Select_DM_OD_LO      Open Drain, Drives Low 
*  Slave_Select_DM_RES_UP     Resistive Pull Up 
*  Slave_Select_DM_RES_DWN    Resistive Pull Down 
*  Slave_Select_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Slave_Select_DM_DIG_HIZ    High Impedance Digital 
*  Slave_Select_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Slave_Select_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Slave_Select_0, mode);
}


/*******************************************************************************
* Function Name: Slave_Select_Read
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
*  Macro Slave_Select_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Slave_Select_Read(void) 
{
    return (Slave_Select_PS & Slave_Select_MASK) >> Slave_Select_SHIFT;
}


/*******************************************************************************
* Function Name: Slave_Select_ReadDataReg
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
uint8 Slave_Select_ReadDataReg(void) 
{
    return (Slave_Select_DR & Slave_Select_MASK) >> Slave_Select_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Slave_Select_INTSTAT) 

    /*******************************************************************************
    * Function Name: Slave_Select_ClearInterrupt
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
    uint8 Slave_Select_ClearInterrupt(void) 
    {
        return (Slave_Select_INTSTAT & Slave_Select_MASK) >> Slave_Select_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
