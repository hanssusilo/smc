/*******************************************************************************
* File Name: onPin.h  
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

#if !defined(CY_PINS_onPin_H) /* Pins onPin_H */
#define CY_PINS_onPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "onPin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 onPin__PORT == 15 && ((onPin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    onPin_Write(uint8 value) ;
void    onPin_SetDriveMode(uint8 mode) ;
uint8   onPin_ReadDataReg(void) ;
uint8   onPin_Read(void) ;
uint8   onPin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define onPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define onPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define onPin_DM_RES_UP          PIN_DM_RES_UP
#define onPin_DM_RES_DWN         PIN_DM_RES_DWN
#define onPin_DM_OD_LO           PIN_DM_OD_LO
#define onPin_DM_OD_HI           PIN_DM_OD_HI
#define onPin_DM_STRONG          PIN_DM_STRONG
#define onPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define onPin_MASK               onPin__MASK
#define onPin_SHIFT              onPin__SHIFT
#define onPin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define onPin_PS                     (* (reg8 *) onPin__PS)
/* Data Register */
#define onPin_DR                     (* (reg8 *) onPin__DR)
/* Port Number */
#define onPin_PRT_NUM                (* (reg8 *) onPin__PRT) 
/* Connect to Analog Globals */                                                  
#define onPin_AG                     (* (reg8 *) onPin__AG)                       
/* Analog MUX bux enable */
#define onPin_AMUX                   (* (reg8 *) onPin__AMUX) 
/* Bidirectional Enable */                                                        
#define onPin_BIE                    (* (reg8 *) onPin__BIE)
/* Bit-mask for Aliased Register Access */
#define onPin_BIT_MASK               (* (reg8 *) onPin__BIT_MASK)
/* Bypass Enable */
#define onPin_BYP                    (* (reg8 *) onPin__BYP)
/* Port wide control signals */                                                   
#define onPin_CTL                    (* (reg8 *) onPin__CTL)
/* Drive Modes */
#define onPin_DM0                    (* (reg8 *) onPin__DM0) 
#define onPin_DM1                    (* (reg8 *) onPin__DM1)
#define onPin_DM2                    (* (reg8 *) onPin__DM2) 
/* Input Buffer Disable Override */
#define onPin_INP_DIS                (* (reg8 *) onPin__INP_DIS)
/* LCD Common or Segment Drive */
#define onPin_LCD_COM_SEG            (* (reg8 *) onPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define onPin_LCD_EN                 (* (reg8 *) onPin__LCD_EN)
/* Slew Rate Control */
#define onPin_SLW                    (* (reg8 *) onPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define onPin_PRTDSI__CAPS_SEL       (* (reg8 *) onPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define onPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) onPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define onPin_PRTDSI__OE_SEL0        (* (reg8 *) onPin__PRTDSI__OE_SEL0) 
#define onPin_PRTDSI__OE_SEL1        (* (reg8 *) onPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define onPin_PRTDSI__OUT_SEL0       (* (reg8 *) onPin__PRTDSI__OUT_SEL0) 
#define onPin_PRTDSI__OUT_SEL1       (* (reg8 *) onPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define onPin_PRTDSI__SYNC_OUT       (* (reg8 *) onPin__PRTDSI__SYNC_OUT) 


#if defined(onPin__INTSTAT)  /* Interrupt Registers */

    #define onPin_INTSTAT                (* (reg8 *) onPin__INTSTAT)
    #define onPin_SNAP                   (* (reg8 *) onPin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_onPin_H */


/* [] END OF FILE */
