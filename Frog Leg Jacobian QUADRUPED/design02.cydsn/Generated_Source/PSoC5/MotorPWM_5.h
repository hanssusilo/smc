/*******************************************************************************
* File Name: MotorPWM_5.h  
* Version 2.0
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

#if !defined(CY_PINS_MotorPWM_5_H) /* Pins MotorPWM_5_H */
#define CY_PINS_MotorPWM_5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MotorPWM_5_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MotorPWM_5__PORT == 15 && ((MotorPWM_5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MotorPWM_5_Write(uint8 value) ;
void    MotorPWM_5_SetDriveMode(uint8 mode) ;
uint8   MotorPWM_5_ReadDataReg(void) ;
uint8   MotorPWM_5_Read(void) ;
uint8   MotorPWM_5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MotorPWM_5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MotorPWM_5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MotorPWM_5_DM_RES_UP          PIN_DM_RES_UP
#define MotorPWM_5_DM_RES_DWN         PIN_DM_RES_DWN
#define MotorPWM_5_DM_OD_LO           PIN_DM_OD_LO
#define MotorPWM_5_DM_OD_HI           PIN_DM_OD_HI
#define MotorPWM_5_DM_STRONG          PIN_DM_STRONG
#define MotorPWM_5_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MotorPWM_5_MASK               MotorPWM_5__MASK
#define MotorPWM_5_SHIFT              MotorPWM_5__SHIFT
#define MotorPWM_5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MotorPWM_5_PS                     (* (reg8 *) MotorPWM_5__PS)
/* Data Register */
#define MotorPWM_5_DR                     (* (reg8 *) MotorPWM_5__DR)
/* Port Number */
#define MotorPWM_5_PRT_NUM                (* (reg8 *) MotorPWM_5__PRT) 
/* Connect to Analog Globals */                                                  
#define MotorPWM_5_AG                     (* (reg8 *) MotorPWM_5__AG)                       
/* Analog MUX bux enable */
#define MotorPWM_5_AMUX                   (* (reg8 *) MotorPWM_5__AMUX) 
/* Bidirectional Enable */                                                        
#define MotorPWM_5_BIE                    (* (reg8 *) MotorPWM_5__BIE)
/* Bit-mask for Aliased Register Access */
#define MotorPWM_5_BIT_MASK               (* (reg8 *) MotorPWM_5__BIT_MASK)
/* Bypass Enable */
#define MotorPWM_5_BYP                    (* (reg8 *) MotorPWM_5__BYP)
/* Port wide control signals */                                                   
#define MotorPWM_5_CTL                    (* (reg8 *) MotorPWM_5__CTL)
/* Drive Modes */
#define MotorPWM_5_DM0                    (* (reg8 *) MotorPWM_5__DM0) 
#define MotorPWM_5_DM1                    (* (reg8 *) MotorPWM_5__DM1)
#define MotorPWM_5_DM2                    (* (reg8 *) MotorPWM_5__DM2) 
/* Input Buffer Disable Override */
#define MotorPWM_5_INP_DIS                (* (reg8 *) MotorPWM_5__INP_DIS)
/* LCD Common or Segment Drive */
#define MotorPWM_5_LCD_COM_SEG            (* (reg8 *) MotorPWM_5__LCD_COM_SEG)
/* Enable Segment LCD */
#define MotorPWM_5_LCD_EN                 (* (reg8 *) MotorPWM_5__LCD_EN)
/* Slew Rate Control */
#define MotorPWM_5_SLW                    (* (reg8 *) MotorPWM_5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MotorPWM_5_PRTDSI__CAPS_SEL       (* (reg8 *) MotorPWM_5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MotorPWM_5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MotorPWM_5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MotorPWM_5_PRTDSI__OE_SEL0        (* (reg8 *) MotorPWM_5__PRTDSI__OE_SEL0) 
#define MotorPWM_5_PRTDSI__OE_SEL1        (* (reg8 *) MotorPWM_5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MotorPWM_5_PRTDSI__OUT_SEL0       (* (reg8 *) MotorPWM_5__PRTDSI__OUT_SEL0) 
#define MotorPWM_5_PRTDSI__OUT_SEL1       (* (reg8 *) MotorPWM_5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MotorPWM_5_PRTDSI__SYNC_OUT       (* (reg8 *) MotorPWM_5__PRTDSI__SYNC_OUT) 


#if defined(MotorPWM_5__INTSTAT)  /* Interrupt Registers */

    #define MotorPWM_5_INTSTAT                (* (reg8 *) MotorPWM_5__INTSTAT)
    #define MotorPWM_5_SNAP                   (* (reg8 *) MotorPWM_5__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MotorPWM_5_H */


/* [] END OF FILE */
