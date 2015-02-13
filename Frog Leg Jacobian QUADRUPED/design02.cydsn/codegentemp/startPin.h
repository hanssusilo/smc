/*******************************************************************************
* File Name: startPin.h  
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

#if !defined(CY_PINS_startPin_H) /* Pins startPin_H */
#define CY_PINS_startPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "startPin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 startPin__PORT == 15 && ((startPin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    startPin_Write(uint8 value) ;
void    startPin_SetDriveMode(uint8 mode) ;
uint8   startPin_ReadDataReg(void) ;
uint8   startPin_Read(void) ;
uint8   startPin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define startPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define startPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define startPin_DM_RES_UP          PIN_DM_RES_UP
#define startPin_DM_RES_DWN         PIN_DM_RES_DWN
#define startPin_DM_OD_LO           PIN_DM_OD_LO
#define startPin_DM_OD_HI           PIN_DM_OD_HI
#define startPin_DM_STRONG          PIN_DM_STRONG
#define startPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define startPin_MASK               startPin__MASK
#define startPin_SHIFT              startPin__SHIFT
#define startPin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define startPin_PS                     (* (reg8 *) startPin__PS)
/* Data Register */
#define startPin_DR                     (* (reg8 *) startPin__DR)
/* Port Number */
#define startPin_PRT_NUM                (* (reg8 *) startPin__PRT) 
/* Connect to Analog Globals */                                                  
#define startPin_AG                     (* (reg8 *) startPin__AG)                       
/* Analog MUX bux enable */
#define startPin_AMUX                   (* (reg8 *) startPin__AMUX) 
/* Bidirectional Enable */                                                        
#define startPin_BIE                    (* (reg8 *) startPin__BIE)
/* Bit-mask for Aliased Register Access */
#define startPin_BIT_MASK               (* (reg8 *) startPin__BIT_MASK)
/* Bypass Enable */
#define startPin_BYP                    (* (reg8 *) startPin__BYP)
/* Port wide control signals */                                                   
#define startPin_CTL                    (* (reg8 *) startPin__CTL)
/* Drive Modes */
#define startPin_DM0                    (* (reg8 *) startPin__DM0) 
#define startPin_DM1                    (* (reg8 *) startPin__DM1)
#define startPin_DM2                    (* (reg8 *) startPin__DM2) 
/* Input Buffer Disable Override */
#define startPin_INP_DIS                (* (reg8 *) startPin__INP_DIS)
/* LCD Common or Segment Drive */
#define startPin_LCD_COM_SEG            (* (reg8 *) startPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define startPin_LCD_EN                 (* (reg8 *) startPin__LCD_EN)
/* Slew Rate Control */
#define startPin_SLW                    (* (reg8 *) startPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define startPin_PRTDSI__CAPS_SEL       (* (reg8 *) startPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define startPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) startPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define startPin_PRTDSI__OE_SEL0        (* (reg8 *) startPin__PRTDSI__OE_SEL0) 
#define startPin_PRTDSI__OE_SEL1        (* (reg8 *) startPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define startPin_PRTDSI__OUT_SEL0       (* (reg8 *) startPin__PRTDSI__OUT_SEL0) 
#define startPin_PRTDSI__OUT_SEL1       (* (reg8 *) startPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define startPin_PRTDSI__SYNC_OUT       (* (reg8 *) startPin__PRTDSI__SYNC_OUT) 


#if defined(startPin__INTSTAT)  /* Interrupt Registers */

    #define startPin_INTSTAT                (* (reg8 *) startPin__INTSTAT)
    #define startPin_SNAP                   (* (reg8 *) startPin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_startPin_H */


/* [] END OF FILE */
