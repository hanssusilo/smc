/*******************************************************************************
* File Name: foot34.h  
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

#if !defined(CY_PINS_foot34_H) /* Pins foot34_H */
#define CY_PINS_foot34_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "foot34_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 foot34__PORT == 15 && ((foot34__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    foot34_Write(uint8 value) ;
void    foot34_SetDriveMode(uint8 mode) ;
uint8   foot34_ReadDataReg(void) ;
uint8   foot34_Read(void) ;
uint8   foot34_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define foot34_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define foot34_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define foot34_DM_RES_UP          PIN_DM_RES_UP
#define foot34_DM_RES_DWN         PIN_DM_RES_DWN
#define foot34_DM_OD_LO           PIN_DM_OD_LO
#define foot34_DM_OD_HI           PIN_DM_OD_HI
#define foot34_DM_STRONG          PIN_DM_STRONG
#define foot34_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define foot34_MASK               foot34__MASK
#define foot34_SHIFT              foot34__SHIFT
#define foot34_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define foot34_PS                     (* (reg8 *) foot34__PS)
/* Data Register */
#define foot34_DR                     (* (reg8 *) foot34__DR)
/* Port Number */
#define foot34_PRT_NUM                (* (reg8 *) foot34__PRT) 
/* Connect to Analog Globals */                                                  
#define foot34_AG                     (* (reg8 *) foot34__AG)                       
/* Analog MUX bux enable */
#define foot34_AMUX                   (* (reg8 *) foot34__AMUX) 
/* Bidirectional Enable */                                                        
#define foot34_BIE                    (* (reg8 *) foot34__BIE)
/* Bit-mask for Aliased Register Access */
#define foot34_BIT_MASK               (* (reg8 *) foot34__BIT_MASK)
/* Bypass Enable */
#define foot34_BYP                    (* (reg8 *) foot34__BYP)
/* Port wide control signals */                                                   
#define foot34_CTL                    (* (reg8 *) foot34__CTL)
/* Drive Modes */
#define foot34_DM0                    (* (reg8 *) foot34__DM0) 
#define foot34_DM1                    (* (reg8 *) foot34__DM1)
#define foot34_DM2                    (* (reg8 *) foot34__DM2) 
/* Input Buffer Disable Override */
#define foot34_INP_DIS                (* (reg8 *) foot34__INP_DIS)
/* LCD Common or Segment Drive */
#define foot34_LCD_COM_SEG            (* (reg8 *) foot34__LCD_COM_SEG)
/* Enable Segment LCD */
#define foot34_LCD_EN                 (* (reg8 *) foot34__LCD_EN)
/* Slew Rate Control */
#define foot34_SLW                    (* (reg8 *) foot34__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define foot34_PRTDSI__CAPS_SEL       (* (reg8 *) foot34__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define foot34_PRTDSI__DBL_SYNC_IN    (* (reg8 *) foot34__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define foot34_PRTDSI__OE_SEL0        (* (reg8 *) foot34__PRTDSI__OE_SEL0) 
#define foot34_PRTDSI__OE_SEL1        (* (reg8 *) foot34__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define foot34_PRTDSI__OUT_SEL0       (* (reg8 *) foot34__PRTDSI__OUT_SEL0) 
#define foot34_PRTDSI__OUT_SEL1       (* (reg8 *) foot34__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define foot34_PRTDSI__SYNC_OUT       (* (reg8 *) foot34__PRTDSI__SYNC_OUT) 


#if defined(foot34__INTSTAT)  /* Interrupt Registers */

    #define foot34_INTSTAT                (* (reg8 *) foot34__INTSTAT)
    #define foot34_SNAP                   (* (reg8 *) foot34__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_foot34_H */


/* [] END OF FILE */
