/*******************************************************************************
* File Name: Enable_1.h  
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

#if !defined(CY_PINS_Enable_1_H) /* Pins Enable_1_H */
#define CY_PINS_Enable_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Enable_1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Enable_1__PORT == 15 && ((Enable_1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Enable_1_Write(uint8 value) ;
void    Enable_1_SetDriveMode(uint8 mode) ;
uint8   Enable_1_ReadDataReg(void) ;
uint8   Enable_1_Read(void) ;
uint8   Enable_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Enable_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Enable_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Enable_1_DM_RES_UP          PIN_DM_RES_UP
#define Enable_1_DM_RES_DWN         PIN_DM_RES_DWN
#define Enable_1_DM_OD_LO           PIN_DM_OD_LO
#define Enable_1_DM_OD_HI           PIN_DM_OD_HI
#define Enable_1_DM_STRONG          PIN_DM_STRONG
#define Enable_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Enable_1_MASK               Enable_1__MASK
#define Enable_1_SHIFT              Enable_1__SHIFT
#define Enable_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Enable_1_PS                     (* (reg8 *) Enable_1__PS)
/* Data Register */
#define Enable_1_DR                     (* (reg8 *) Enable_1__DR)
/* Port Number */
#define Enable_1_PRT_NUM                (* (reg8 *) Enable_1__PRT) 
/* Connect to Analog Globals */                                                  
#define Enable_1_AG                     (* (reg8 *) Enable_1__AG)                       
/* Analog MUX bux enable */
#define Enable_1_AMUX                   (* (reg8 *) Enable_1__AMUX) 
/* Bidirectional Enable */                                                        
#define Enable_1_BIE                    (* (reg8 *) Enable_1__BIE)
/* Bit-mask for Aliased Register Access */
#define Enable_1_BIT_MASK               (* (reg8 *) Enable_1__BIT_MASK)
/* Bypass Enable */
#define Enable_1_BYP                    (* (reg8 *) Enable_1__BYP)
/* Port wide control signals */                                                   
#define Enable_1_CTL                    (* (reg8 *) Enable_1__CTL)
/* Drive Modes */
#define Enable_1_DM0                    (* (reg8 *) Enable_1__DM0) 
#define Enable_1_DM1                    (* (reg8 *) Enable_1__DM1)
#define Enable_1_DM2                    (* (reg8 *) Enable_1__DM2) 
/* Input Buffer Disable Override */
#define Enable_1_INP_DIS                (* (reg8 *) Enable_1__INP_DIS)
/* LCD Common or Segment Drive */
#define Enable_1_LCD_COM_SEG            (* (reg8 *) Enable_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Enable_1_LCD_EN                 (* (reg8 *) Enable_1__LCD_EN)
/* Slew Rate Control */
#define Enable_1_SLW                    (* (reg8 *) Enable_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Enable_1_PRTDSI__CAPS_SEL       (* (reg8 *) Enable_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Enable_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Enable_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Enable_1_PRTDSI__OE_SEL0        (* (reg8 *) Enable_1__PRTDSI__OE_SEL0) 
#define Enable_1_PRTDSI__OE_SEL1        (* (reg8 *) Enable_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Enable_1_PRTDSI__OUT_SEL0       (* (reg8 *) Enable_1__PRTDSI__OUT_SEL0) 
#define Enable_1_PRTDSI__OUT_SEL1       (* (reg8 *) Enable_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Enable_1_PRTDSI__SYNC_OUT       (* (reg8 *) Enable_1__PRTDSI__SYNC_OUT) 


#if defined(Enable_1__INTSTAT)  /* Interrupt Registers */

    #define Enable_1_INTSTAT                (* (reg8 *) Enable_1__INTSTAT)
    #define Enable_1_SNAP                   (* (reg8 *) Enable_1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Enable_1_H */


/* [] END OF FILE */
