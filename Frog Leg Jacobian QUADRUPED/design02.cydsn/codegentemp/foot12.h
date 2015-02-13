/*******************************************************************************
* File Name: foot12.h  
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

#if !defined(CY_PINS_foot12_H) /* Pins foot12_H */
#define CY_PINS_foot12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "foot12_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 foot12__PORT == 15 && ((foot12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    foot12_Write(uint8 value) ;
void    foot12_SetDriveMode(uint8 mode) ;
uint8   foot12_ReadDataReg(void) ;
uint8   foot12_Read(void) ;
uint8   foot12_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define foot12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define foot12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define foot12_DM_RES_UP          PIN_DM_RES_UP
#define foot12_DM_RES_DWN         PIN_DM_RES_DWN
#define foot12_DM_OD_LO           PIN_DM_OD_LO
#define foot12_DM_OD_HI           PIN_DM_OD_HI
#define foot12_DM_STRONG          PIN_DM_STRONG
#define foot12_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define foot12_MASK               foot12__MASK
#define foot12_SHIFT              foot12__SHIFT
#define foot12_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define foot12_PS                     (* (reg8 *) foot12__PS)
/* Data Register */
#define foot12_DR                     (* (reg8 *) foot12__DR)
/* Port Number */
#define foot12_PRT_NUM                (* (reg8 *) foot12__PRT) 
/* Connect to Analog Globals */                                                  
#define foot12_AG                     (* (reg8 *) foot12__AG)                       
/* Analog MUX bux enable */
#define foot12_AMUX                   (* (reg8 *) foot12__AMUX) 
/* Bidirectional Enable */                                                        
#define foot12_BIE                    (* (reg8 *) foot12__BIE)
/* Bit-mask for Aliased Register Access */
#define foot12_BIT_MASK               (* (reg8 *) foot12__BIT_MASK)
/* Bypass Enable */
#define foot12_BYP                    (* (reg8 *) foot12__BYP)
/* Port wide control signals */                                                   
#define foot12_CTL                    (* (reg8 *) foot12__CTL)
/* Drive Modes */
#define foot12_DM0                    (* (reg8 *) foot12__DM0) 
#define foot12_DM1                    (* (reg8 *) foot12__DM1)
#define foot12_DM2                    (* (reg8 *) foot12__DM2) 
/* Input Buffer Disable Override */
#define foot12_INP_DIS                (* (reg8 *) foot12__INP_DIS)
/* LCD Common or Segment Drive */
#define foot12_LCD_COM_SEG            (* (reg8 *) foot12__LCD_COM_SEG)
/* Enable Segment LCD */
#define foot12_LCD_EN                 (* (reg8 *) foot12__LCD_EN)
/* Slew Rate Control */
#define foot12_SLW                    (* (reg8 *) foot12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define foot12_PRTDSI__CAPS_SEL       (* (reg8 *) foot12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define foot12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) foot12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define foot12_PRTDSI__OE_SEL0        (* (reg8 *) foot12__PRTDSI__OE_SEL0) 
#define foot12_PRTDSI__OE_SEL1        (* (reg8 *) foot12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define foot12_PRTDSI__OUT_SEL0       (* (reg8 *) foot12__PRTDSI__OUT_SEL0) 
#define foot12_PRTDSI__OUT_SEL1       (* (reg8 *) foot12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define foot12_PRTDSI__SYNC_OUT       (* (reg8 *) foot12__PRTDSI__SYNC_OUT) 


#if defined(foot12__INTSTAT)  /* Interrupt Registers */

    #define foot12_INTSTAT                (* (reg8 *) foot12__INTSTAT)
    #define foot12_SNAP                   (* (reg8 *) foot12__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_foot12_H */


/* [] END OF FILE */
