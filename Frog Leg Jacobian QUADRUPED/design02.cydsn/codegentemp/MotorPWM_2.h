/*******************************************************************************
* File Name: MotorPWM_2.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MotorPWM_2_H) /* Pins MotorPWM_2_H */
#define CY_PINS_MotorPWM_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MotorPWM_2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MotorPWM_2__PORT == 15 && ((MotorPWM_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MotorPWM_2_Write(uint8 value) ;
void    MotorPWM_2_SetDriveMode(uint8 mode) ;
uint8   MotorPWM_2_ReadDataReg(void) ;
uint8   MotorPWM_2_Read(void) ;
uint8   MotorPWM_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MotorPWM_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MotorPWM_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MotorPWM_2_DM_RES_UP          PIN_DM_RES_UP
#define MotorPWM_2_DM_RES_DWN         PIN_DM_RES_DWN
#define MotorPWM_2_DM_OD_LO           PIN_DM_OD_LO
#define MotorPWM_2_DM_OD_HI           PIN_DM_OD_HI
#define MotorPWM_2_DM_STRONG          PIN_DM_STRONG
#define MotorPWM_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MotorPWM_2_MASK               MotorPWM_2__MASK
#define MotorPWM_2_SHIFT              MotorPWM_2__SHIFT
#define MotorPWM_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MotorPWM_2_PS                     (* (reg8 *) MotorPWM_2__PS)
/* Data Register */
#define MotorPWM_2_DR                     (* (reg8 *) MotorPWM_2__DR)
/* Port Number */
#define MotorPWM_2_PRT_NUM                (* (reg8 *) MotorPWM_2__PRT) 
/* Connect to Analog Globals */                                                  
#define MotorPWM_2_AG                     (* (reg8 *) MotorPWM_2__AG)                       
/* Analog MUX bux enable */
#define MotorPWM_2_AMUX                   (* (reg8 *) MotorPWM_2__AMUX) 
/* Bidirectional Enable */                                                        
#define MotorPWM_2_BIE                    (* (reg8 *) MotorPWM_2__BIE)
/* Bit-mask for Aliased Register Access */
#define MotorPWM_2_BIT_MASK               (* (reg8 *) MotorPWM_2__BIT_MASK)
/* Bypass Enable */
#define MotorPWM_2_BYP                    (* (reg8 *) MotorPWM_2__BYP)
/* Port wide control signals */                                                   
#define MotorPWM_2_CTL                    (* (reg8 *) MotorPWM_2__CTL)
/* Drive Modes */
#define MotorPWM_2_DM0                    (* (reg8 *) MotorPWM_2__DM0) 
#define MotorPWM_2_DM1                    (* (reg8 *) MotorPWM_2__DM1)
#define MotorPWM_2_DM2                    (* (reg8 *) MotorPWM_2__DM2) 
/* Input Buffer Disable Override */
#define MotorPWM_2_INP_DIS                (* (reg8 *) MotorPWM_2__INP_DIS)
/* LCD Common or Segment Drive */
#define MotorPWM_2_LCD_COM_SEG            (* (reg8 *) MotorPWM_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MotorPWM_2_LCD_EN                 (* (reg8 *) MotorPWM_2__LCD_EN)
/* Slew Rate Control */
#define MotorPWM_2_SLW                    (* (reg8 *) MotorPWM_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MotorPWM_2_PRTDSI__CAPS_SEL       (* (reg8 *) MotorPWM_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MotorPWM_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MotorPWM_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MotorPWM_2_PRTDSI__OE_SEL0        (* (reg8 *) MotorPWM_2__PRTDSI__OE_SEL0) 
#define MotorPWM_2_PRTDSI__OE_SEL1        (* (reg8 *) MotorPWM_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MotorPWM_2_PRTDSI__OUT_SEL0       (* (reg8 *) MotorPWM_2__PRTDSI__OUT_SEL0) 
#define MotorPWM_2_PRTDSI__OUT_SEL1       (* (reg8 *) MotorPWM_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MotorPWM_2_PRTDSI__SYNC_OUT       (* (reg8 *) MotorPWM_2__PRTDSI__SYNC_OUT) 


#if defined(MotorPWM_2__INTSTAT)  /* Interrupt Registers */

    #define MotorPWM_2_INTSTAT                (* (reg8 *) MotorPWM_2__INTSTAT)
    #define MotorPWM_2_SNAP                   (* (reg8 *) MotorPWM_2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MotorPWM_2_H */


/* [] END OF FILE */
