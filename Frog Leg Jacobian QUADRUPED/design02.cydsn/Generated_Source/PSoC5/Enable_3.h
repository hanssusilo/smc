/*******************************************************************************
* File Name: Enable_3.h  
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

#if !defined(CY_PINS_Enable_3_H) /* Pins Enable_3_H */
#define CY_PINS_Enable_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Enable_3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Enable_3__PORT == 15 && ((Enable_3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Enable_3_Write(uint8 value) ;
void    Enable_3_SetDriveMode(uint8 mode) ;
uint8   Enable_3_ReadDataReg(void) ;
uint8   Enable_3_Read(void) ;
uint8   Enable_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Enable_3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Enable_3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Enable_3_DM_RES_UP          PIN_DM_RES_UP
#define Enable_3_DM_RES_DWN         PIN_DM_RES_DWN
#define Enable_3_DM_OD_LO           PIN_DM_OD_LO
#define Enable_3_DM_OD_HI           PIN_DM_OD_HI
#define Enable_3_DM_STRONG          PIN_DM_STRONG
#define Enable_3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Enable_3_MASK               Enable_3__MASK
#define Enable_3_SHIFT              Enable_3__SHIFT
#define Enable_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Enable_3_PS                     (* (reg8 *) Enable_3__PS)
/* Data Register */
#define Enable_3_DR                     (* (reg8 *) Enable_3__DR)
/* Port Number */
#define Enable_3_PRT_NUM                (* (reg8 *) Enable_3__PRT) 
/* Connect to Analog Globals */                                                  
#define Enable_3_AG                     (* (reg8 *) Enable_3__AG)                       
/* Analog MUX bux enable */
#define Enable_3_AMUX                   (* (reg8 *) Enable_3__AMUX) 
/* Bidirectional Enable */                                                        
#define Enable_3_BIE                    (* (reg8 *) Enable_3__BIE)
/* Bit-mask for Aliased Register Access */
#define Enable_3_BIT_MASK               (* (reg8 *) Enable_3__BIT_MASK)
/* Bypass Enable */
#define Enable_3_BYP                    (* (reg8 *) Enable_3__BYP)
/* Port wide control signals */                                                   
#define Enable_3_CTL                    (* (reg8 *) Enable_3__CTL)
/* Drive Modes */
#define Enable_3_DM0                    (* (reg8 *) Enable_3__DM0) 
#define Enable_3_DM1                    (* (reg8 *) Enable_3__DM1)
#define Enable_3_DM2                    (* (reg8 *) Enable_3__DM2) 
/* Input Buffer Disable Override */
#define Enable_3_INP_DIS                (* (reg8 *) Enable_3__INP_DIS)
/* LCD Common or Segment Drive */
#define Enable_3_LCD_COM_SEG            (* (reg8 *) Enable_3__LCD_COM_SEG)
/* Enable Segment LCD */
#define Enable_3_LCD_EN                 (* (reg8 *) Enable_3__LCD_EN)
/* Slew Rate Control */
#define Enable_3_SLW                    (* (reg8 *) Enable_3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Enable_3_PRTDSI__CAPS_SEL       (* (reg8 *) Enable_3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Enable_3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Enable_3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Enable_3_PRTDSI__OE_SEL0        (* (reg8 *) Enable_3__PRTDSI__OE_SEL0) 
#define Enable_3_PRTDSI__OE_SEL1        (* (reg8 *) Enable_3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Enable_3_PRTDSI__OUT_SEL0       (* (reg8 *) Enable_3__PRTDSI__OUT_SEL0) 
#define Enable_3_PRTDSI__OUT_SEL1       (* (reg8 *) Enable_3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Enable_3_PRTDSI__SYNC_OUT       (* (reg8 *) Enable_3__PRTDSI__SYNC_OUT) 


#if defined(Enable_3__INTSTAT)  /* Interrupt Registers */

    #define Enable_3_INTSTAT                (* (reg8 *) Enable_3__INTSTAT)
    #define Enable_3_SNAP                   (* (reg8 *) Enable_3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Enable_3_H */


/* [] END OF FILE */
