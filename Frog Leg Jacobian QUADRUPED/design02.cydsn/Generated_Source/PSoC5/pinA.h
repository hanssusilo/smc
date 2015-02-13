/*******************************************************************************
* File Name: pinA.h  
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

#if !defined(CY_PINS_pinA_H) /* Pins pinA_H */
#define CY_PINS_pinA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pinA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pinA__PORT == 15 && ((pinA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    pinA_Write(uint8 value) ;
void    pinA_SetDriveMode(uint8 mode) ;
uint8   pinA_ReadDataReg(void) ;
uint8   pinA_Read(void) ;
uint8   pinA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define pinA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define pinA_DM_RES_UP          PIN_DM_RES_UP
#define pinA_DM_RES_DWN         PIN_DM_RES_DWN
#define pinA_DM_OD_LO           PIN_DM_OD_LO
#define pinA_DM_OD_HI           PIN_DM_OD_HI
#define pinA_DM_STRONG          PIN_DM_STRONG
#define pinA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define pinA_MASK               pinA__MASK
#define pinA_SHIFT              pinA__SHIFT
#define pinA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinA_PS                     (* (reg8 *) pinA__PS)
/* Data Register */
#define pinA_DR                     (* (reg8 *) pinA__DR)
/* Port Number */
#define pinA_PRT_NUM                (* (reg8 *) pinA__PRT) 
/* Connect to Analog Globals */                                                  
#define pinA_AG                     (* (reg8 *) pinA__AG)                       
/* Analog MUX bux enable */
#define pinA_AMUX                   (* (reg8 *) pinA__AMUX) 
/* Bidirectional Enable */                                                        
#define pinA_BIE                    (* (reg8 *) pinA__BIE)
/* Bit-mask for Aliased Register Access */
#define pinA_BIT_MASK               (* (reg8 *) pinA__BIT_MASK)
/* Bypass Enable */
#define pinA_BYP                    (* (reg8 *) pinA__BYP)
/* Port wide control signals */                                                   
#define pinA_CTL                    (* (reg8 *) pinA__CTL)
/* Drive Modes */
#define pinA_DM0                    (* (reg8 *) pinA__DM0) 
#define pinA_DM1                    (* (reg8 *) pinA__DM1)
#define pinA_DM2                    (* (reg8 *) pinA__DM2) 
/* Input Buffer Disable Override */
#define pinA_INP_DIS                (* (reg8 *) pinA__INP_DIS)
/* LCD Common or Segment Drive */
#define pinA_LCD_COM_SEG            (* (reg8 *) pinA__LCD_COM_SEG)
/* Enable Segment LCD */
#define pinA_LCD_EN                 (* (reg8 *) pinA__LCD_EN)
/* Slew Rate Control */
#define pinA_SLW                    (* (reg8 *) pinA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pinA_PRTDSI__CAPS_SEL       (* (reg8 *) pinA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pinA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pinA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pinA_PRTDSI__OE_SEL0        (* (reg8 *) pinA__PRTDSI__OE_SEL0) 
#define pinA_PRTDSI__OE_SEL1        (* (reg8 *) pinA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pinA_PRTDSI__OUT_SEL0       (* (reg8 *) pinA__PRTDSI__OUT_SEL0) 
#define pinA_PRTDSI__OUT_SEL1       (* (reg8 *) pinA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pinA_PRTDSI__SYNC_OUT       (* (reg8 *) pinA__PRTDSI__SYNC_OUT) 


#if defined(pinA__INTSTAT)  /* Interrupt Registers */

    #define pinA_INTSTAT                (* (reg8 *) pinA__INTSTAT)
    #define pinA_SNAP                   (* (reg8 *) pinA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pinA_H */


/* [] END OF FILE */
