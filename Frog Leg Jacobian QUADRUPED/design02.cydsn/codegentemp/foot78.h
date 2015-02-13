/*******************************************************************************
* File Name: foot78.h  
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

#if !defined(CY_PINS_foot78_H) /* Pins foot78_H */
#define CY_PINS_foot78_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "foot78_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 foot78__PORT == 15 && ((foot78__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    foot78_Write(uint8 value) ;
void    foot78_SetDriveMode(uint8 mode) ;
uint8   foot78_ReadDataReg(void) ;
uint8   foot78_Read(void) ;
uint8   foot78_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define foot78_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define foot78_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define foot78_DM_RES_UP          PIN_DM_RES_UP
#define foot78_DM_RES_DWN         PIN_DM_RES_DWN
#define foot78_DM_OD_LO           PIN_DM_OD_LO
#define foot78_DM_OD_HI           PIN_DM_OD_HI
#define foot78_DM_STRONG          PIN_DM_STRONG
#define foot78_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define foot78_MASK               foot78__MASK
#define foot78_SHIFT              foot78__SHIFT
#define foot78_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define foot78_PS                     (* (reg8 *) foot78__PS)
/* Data Register */
#define foot78_DR                     (* (reg8 *) foot78__DR)
/* Port Number */
#define foot78_PRT_NUM                (* (reg8 *) foot78__PRT) 
/* Connect to Analog Globals */                                                  
#define foot78_AG                     (* (reg8 *) foot78__AG)                       
/* Analog MUX bux enable */
#define foot78_AMUX                   (* (reg8 *) foot78__AMUX) 
/* Bidirectional Enable */                                                        
#define foot78_BIE                    (* (reg8 *) foot78__BIE)
/* Bit-mask for Aliased Register Access */
#define foot78_BIT_MASK               (* (reg8 *) foot78__BIT_MASK)
/* Bypass Enable */
#define foot78_BYP                    (* (reg8 *) foot78__BYP)
/* Port wide control signals */                                                   
#define foot78_CTL                    (* (reg8 *) foot78__CTL)
/* Drive Modes */
#define foot78_DM0                    (* (reg8 *) foot78__DM0) 
#define foot78_DM1                    (* (reg8 *) foot78__DM1)
#define foot78_DM2                    (* (reg8 *) foot78__DM2) 
/* Input Buffer Disable Override */
#define foot78_INP_DIS                (* (reg8 *) foot78__INP_DIS)
/* LCD Common or Segment Drive */
#define foot78_LCD_COM_SEG            (* (reg8 *) foot78__LCD_COM_SEG)
/* Enable Segment LCD */
#define foot78_LCD_EN                 (* (reg8 *) foot78__LCD_EN)
/* Slew Rate Control */
#define foot78_SLW                    (* (reg8 *) foot78__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define foot78_PRTDSI__CAPS_SEL       (* (reg8 *) foot78__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define foot78_PRTDSI__DBL_SYNC_IN    (* (reg8 *) foot78__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define foot78_PRTDSI__OE_SEL0        (* (reg8 *) foot78__PRTDSI__OE_SEL0) 
#define foot78_PRTDSI__OE_SEL1        (* (reg8 *) foot78__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define foot78_PRTDSI__OUT_SEL0       (* (reg8 *) foot78__PRTDSI__OUT_SEL0) 
#define foot78_PRTDSI__OUT_SEL1       (* (reg8 *) foot78__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define foot78_PRTDSI__SYNC_OUT       (* (reg8 *) foot78__PRTDSI__SYNC_OUT) 


#if defined(foot78__INTSTAT)  /* Interrupt Registers */

    #define foot78_INTSTAT                (* (reg8 *) foot78__INTSTAT)
    #define foot78_SNAP                   (* (reg8 *) foot78__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_foot78_H */


/* [] END OF FILE */
