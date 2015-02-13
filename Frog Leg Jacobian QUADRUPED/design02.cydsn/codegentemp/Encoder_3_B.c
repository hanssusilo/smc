/*******************************************************************************
* File Name: Encoder_3_B.c  
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
#include "Encoder_3_B.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Encoder_3_B__PORT == 15 && ((Encoder_3_B__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Encoder_3_B_Write
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
void Encoder_3_B_Write(uint8 value) 
{
    uint8 staticBits = (Encoder_3_B_DR & (uint8)(~Encoder_3_B_MASK));
    Encoder_3_B_DR = staticBits | ((uint8)(value << Encoder_3_B_SHIFT) & Encoder_3_B_MASK);
}


/*******************************************************************************
* Function Name: Encoder_3_B_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Encoder_3_B_DM_STRONG     Strong Drive 
*  Encoder_3_B_DM_OD_HI      Open Drain, Drives High 
*  Encoder_3_B_DM_OD_LO      Open Drain, Drives Low 
*  Encoder_3_B_DM_RES_UP     Resistive Pull Up 
*  Encoder_3_B_DM_RES_DWN    Resistive Pull Down 
*  Encoder_3_B_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Encoder_3_B_DM_DIG_HIZ    High Impedance Digital 
*  Encoder_3_B_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Encoder_3_B_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Encoder_3_B_0, mode);
}


/*******************************************************************************
* Function Name: Encoder_3_B_Read
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
*  Macro Encoder_3_B_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Encoder_3_B_Read(void) 
{
    return (Encoder_3_B_PS & Encoder_3_B_MASK) >> Encoder_3_B_SHIFT;
}


/*******************************************************************************
* Function Name: Encoder_3_B_ReadDataReg
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
uint8 Encoder_3_B_ReadDataReg(void) 
{
    return (Encoder_3_B_DR & Encoder_3_B_MASK) >> Encoder_3_B_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Encoder_3_B_INTSTAT) 

    /*******************************************************************************
    * Function Name: Encoder_3_B_ClearInterrupt
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
    uint8 Encoder_3_B_ClearInterrupt(void) 
    {
        return (Encoder_3_B_INTSTAT & Encoder_3_B_MASK) >> Encoder_3_B_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */