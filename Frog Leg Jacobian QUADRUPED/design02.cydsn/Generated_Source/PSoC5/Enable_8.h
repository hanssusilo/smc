/*******************************************************************************
* File Name: Enable_8.h  
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

#if !defined(CY_PINS_Enable_8_H) /* Pins Enable_8_H */
#define CY_PINS_Enable_8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Enable_8_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Enable_8__PORT == 15 && ((Enable_8__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Enable_8_Write(uint8 value) ;
void    Enable_8_SetDriveMode(uint8 mode) ;
uint8   Enable_8_ReadDataReg(void) ;
uint8   Enable_8_Read(void) ;
uint8   Enable_8_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Enable_8_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Enable_8_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Enable_8_DM_RES_UP          PIN_DM_RES_UP
#define Enable_8_DM_RES_DWN         PIN_DM_RES_DWN
#define Enable_8_DM_OD_LO           PIN_DM_OD_LO
#define Enable_8_DM_OD_HI           PIN_DM_OD_HI
#define Enable_8_DM_STRONG          PIN_DM_STRONG
#define Enable_8_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Enable_8_MASK               Enable_8__MASK
#define Enable_8_SHIFT              Enable_8__SHIFT
#define Enable_8_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Enable_8_PS                     (* (reg8 *) Enable_8__PS)
/* Data Register */
#define Enable_8_DR                     (* (reg8 *) Enable_8__DR)
/* Port Number */
#define Enable_8_PRT_NUM                (* (reg8 *) Enable_8__PRT) 
/* Connect to Analog Globals */                                                  
#define Enable_8_AG                     (* (reg8 *) Enable_8__AG)                       
/* Analog MUX bux enable */
#define Enable_8_AMUX                   (* (reg8 *) Enable_8__AMUX) 
/* Bidirectional Enable */                                                        
#define Enable_8_BIE                    (* (reg8 *) Enable_8__BIE)
/* Bit-mask for Aliased Register Access */
#define Enable_8_BIT_MASK               (* (reg8 *) Enable_8__BIT_MASK)
/* Bypass Enable */
#define Enable_8_BYP                    (* (reg8 *) Enable_8__BYP)
/* Port wide control signals */                                                   
#define Enable_8_CTL                    (* (reg8 *) Enable_8__CTL)
/* Drive Modes */
#define Enable_8_DM0                    (* (reg8 *) Enable_8__DM0) 
#define Enable_8_DM1                    (* (reg8 *) Enable_8__DM1)
#define Enable_8_DM2                    (* (reg8 *) Enable_8__DM2) 
/* Input Buffer Disable Override */
#define Enable_8_INP_DIS                (* (reg8 *) Enable_8__INP_DIS)
/* LCD Common or Segment Drive */
#define Enable_8_LCD_COM_SEG            (* (reg8 *) Enable_8__LCD_COM_SEG)
/* Enable Segment LCD */
#define Enable_8_LCD_EN                 (* (reg8 *) Enable_8__LCD_EN)
/* Slew Rate Control */
#define Enable_8_SLW                    (* (reg8 *) Enable_8__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Enable_8_PRTDSI__CAPS_SEL       (* (reg8 *) Enable_8__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Enable_8_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Enable_8__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Enable_8_PRTDSI__OE_SEL0        (* (reg8 *) Enable_8__PRTDSI__OE_SEL0) 
#define Enable_8_PRTDSI__OE_SEL1        (* (reg8 *) Enable_8__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Enable_8_PRTDSI__OUT_SEL0       (* (reg8 *) Enable_8__PRTDSI__OUT_SEL0) 
#define Enable_8_PRTDSI__OUT_SEL1       (* (reg8 *) Enable_8__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Enable_8_PRTDSI__SYNC_OUT       (* (reg8 *) Enable_8__PRTDSI__SYNC_OUT) 


#if defined(Enable_8__INTSTAT)  /* Interrupt Registers */

    #define Enable_8_INTSTAT                (* (reg8 *) Enable_8__INTSTAT)
    #define Enable_8_SNAP                   (* (reg8 *) Enable_8__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Enable_8_H */


/* [] END OF FILE */
