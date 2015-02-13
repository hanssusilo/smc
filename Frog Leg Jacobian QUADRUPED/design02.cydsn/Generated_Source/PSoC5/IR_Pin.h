/*******************************************************************************
* File Name: IR_Pin.h  
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

#if !defined(CY_PINS_IR_Pin_H) /* Pins IR_Pin_H */
#define CY_PINS_IR_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IR_Pin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IR_Pin__PORT == 15 && ((IR_Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    IR_Pin_Write(uint8 value) ;
void    IR_Pin_SetDriveMode(uint8 mode) ;
uint8   IR_Pin_ReadDataReg(void) ;
uint8   IR_Pin_Read(void) ;
uint8   IR_Pin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IR_Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define IR_Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define IR_Pin_DM_RES_UP          PIN_DM_RES_UP
#define IR_Pin_DM_RES_DWN         PIN_DM_RES_DWN
#define IR_Pin_DM_OD_LO           PIN_DM_OD_LO
#define IR_Pin_DM_OD_HI           PIN_DM_OD_HI
#define IR_Pin_DM_STRONG          PIN_DM_STRONG
#define IR_Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define IR_Pin_MASK               IR_Pin__MASK
#define IR_Pin_SHIFT              IR_Pin__SHIFT
#define IR_Pin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IR_Pin_PS                     (* (reg8 *) IR_Pin__PS)
/* Data Register */
#define IR_Pin_DR                     (* (reg8 *) IR_Pin__DR)
/* Port Number */
#define IR_Pin_PRT_NUM                (* (reg8 *) IR_Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define IR_Pin_AG                     (* (reg8 *) IR_Pin__AG)                       
/* Analog MUX bux enable */
#define IR_Pin_AMUX                   (* (reg8 *) IR_Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define IR_Pin_BIE                    (* (reg8 *) IR_Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define IR_Pin_BIT_MASK               (* (reg8 *) IR_Pin__BIT_MASK)
/* Bypass Enable */
#define IR_Pin_BYP                    (* (reg8 *) IR_Pin__BYP)
/* Port wide control signals */                                                   
#define IR_Pin_CTL                    (* (reg8 *) IR_Pin__CTL)
/* Drive Modes */
#define IR_Pin_DM0                    (* (reg8 *) IR_Pin__DM0) 
#define IR_Pin_DM1                    (* (reg8 *) IR_Pin__DM1)
#define IR_Pin_DM2                    (* (reg8 *) IR_Pin__DM2) 
/* Input Buffer Disable Override */
#define IR_Pin_INP_DIS                (* (reg8 *) IR_Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define IR_Pin_LCD_COM_SEG            (* (reg8 *) IR_Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define IR_Pin_LCD_EN                 (* (reg8 *) IR_Pin__LCD_EN)
/* Slew Rate Control */
#define IR_Pin_SLW                    (* (reg8 *) IR_Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IR_Pin_PRTDSI__CAPS_SEL       (* (reg8 *) IR_Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IR_Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IR_Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IR_Pin_PRTDSI__OE_SEL0        (* (reg8 *) IR_Pin__PRTDSI__OE_SEL0) 
#define IR_Pin_PRTDSI__OE_SEL1        (* (reg8 *) IR_Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IR_Pin_PRTDSI__OUT_SEL0       (* (reg8 *) IR_Pin__PRTDSI__OUT_SEL0) 
#define IR_Pin_PRTDSI__OUT_SEL1       (* (reg8 *) IR_Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IR_Pin_PRTDSI__SYNC_OUT       (* (reg8 *) IR_Pin__PRTDSI__SYNC_OUT) 


#if defined(IR_Pin__INTSTAT)  /* Interrupt Registers */

    #define IR_Pin_INTSTAT                (* (reg8 *) IR_Pin__INTSTAT)
    #define IR_Pin_SNAP                   (* (reg8 *) IR_Pin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IR_Pin_H */


/* [] END OF FILE */
