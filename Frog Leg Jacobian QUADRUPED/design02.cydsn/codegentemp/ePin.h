/*******************************************************************************
* File Name: ePin.h  
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

#if !defined(CY_PINS_ePin_H) /* Pins ePin_H */
#define CY_PINS_ePin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ePin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ePin__PORT == 15 && ((ePin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ePin_Write(uint8 value) ;
void    ePin_SetDriveMode(uint8 mode) ;
uint8   ePin_ReadDataReg(void) ;
uint8   ePin_Read(void) ;
uint8   ePin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ePin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ePin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ePin_DM_RES_UP          PIN_DM_RES_UP
#define ePin_DM_RES_DWN         PIN_DM_RES_DWN
#define ePin_DM_OD_LO           PIN_DM_OD_LO
#define ePin_DM_OD_HI           PIN_DM_OD_HI
#define ePin_DM_STRONG          PIN_DM_STRONG
#define ePin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ePin_MASK               ePin__MASK
#define ePin_SHIFT              ePin__SHIFT
#define ePin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ePin_PS                     (* (reg8 *) ePin__PS)
/* Data Register */
#define ePin_DR                     (* (reg8 *) ePin__DR)
/* Port Number */
#define ePin_PRT_NUM                (* (reg8 *) ePin__PRT) 
/* Connect to Analog Globals */                                                  
#define ePin_AG                     (* (reg8 *) ePin__AG)                       
/* Analog MUX bux enable */
#define ePin_AMUX                   (* (reg8 *) ePin__AMUX) 
/* Bidirectional Enable */                                                        
#define ePin_BIE                    (* (reg8 *) ePin__BIE)
/* Bit-mask for Aliased Register Access */
#define ePin_BIT_MASK               (* (reg8 *) ePin__BIT_MASK)
/* Bypass Enable */
#define ePin_BYP                    (* (reg8 *) ePin__BYP)
/* Port wide control signals */                                                   
#define ePin_CTL                    (* (reg8 *) ePin__CTL)
/* Drive Modes */
#define ePin_DM0                    (* (reg8 *) ePin__DM0) 
#define ePin_DM1                    (* (reg8 *) ePin__DM1)
#define ePin_DM2                    (* (reg8 *) ePin__DM2) 
/* Input Buffer Disable Override */
#define ePin_INP_DIS                (* (reg8 *) ePin__INP_DIS)
/* LCD Common or Segment Drive */
#define ePin_LCD_COM_SEG            (* (reg8 *) ePin__LCD_COM_SEG)
/* Enable Segment LCD */
#define ePin_LCD_EN                 (* (reg8 *) ePin__LCD_EN)
/* Slew Rate Control */
#define ePin_SLW                    (* (reg8 *) ePin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ePin_PRTDSI__CAPS_SEL       (* (reg8 *) ePin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ePin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ePin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ePin_PRTDSI__OE_SEL0        (* (reg8 *) ePin__PRTDSI__OE_SEL0) 
#define ePin_PRTDSI__OE_SEL1        (* (reg8 *) ePin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ePin_PRTDSI__OUT_SEL0       (* (reg8 *) ePin__PRTDSI__OUT_SEL0) 
#define ePin_PRTDSI__OUT_SEL1       (* (reg8 *) ePin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ePin_PRTDSI__SYNC_OUT       (* (reg8 *) ePin__PRTDSI__SYNC_OUT) 


#if defined(ePin__INTSTAT)  /* Interrupt Registers */

    #define ePin_INTSTAT                (* (reg8 *) ePin__INTSTAT)
    #define ePin_SNAP                   (* (reg8 *) ePin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ePin_H */


/* [] END OF FILE */
