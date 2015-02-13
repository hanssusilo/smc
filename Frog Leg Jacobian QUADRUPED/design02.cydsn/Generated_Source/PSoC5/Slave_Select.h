/*******************************************************************************
* File Name: Slave_Select.h  
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

#if !defined(CY_PINS_Slave_Select_H) /* Pins Slave_Select_H */
#define CY_PINS_Slave_Select_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Slave_Select_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Slave_Select__PORT == 15 && ((Slave_Select__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Slave_Select_Write(uint8 value) ;
void    Slave_Select_SetDriveMode(uint8 mode) ;
uint8   Slave_Select_ReadDataReg(void) ;
uint8   Slave_Select_Read(void) ;
uint8   Slave_Select_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Slave_Select_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Slave_Select_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Slave_Select_DM_RES_UP          PIN_DM_RES_UP
#define Slave_Select_DM_RES_DWN         PIN_DM_RES_DWN
#define Slave_Select_DM_OD_LO           PIN_DM_OD_LO
#define Slave_Select_DM_OD_HI           PIN_DM_OD_HI
#define Slave_Select_DM_STRONG          PIN_DM_STRONG
#define Slave_Select_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Slave_Select_MASK               Slave_Select__MASK
#define Slave_Select_SHIFT              Slave_Select__SHIFT
#define Slave_Select_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Slave_Select_PS                     (* (reg8 *) Slave_Select__PS)
/* Data Register */
#define Slave_Select_DR                     (* (reg8 *) Slave_Select__DR)
/* Port Number */
#define Slave_Select_PRT_NUM                (* (reg8 *) Slave_Select__PRT) 
/* Connect to Analog Globals */                                                  
#define Slave_Select_AG                     (* (reg8 *) Slave_Select__AG)                       
/* Analog MUX bux enable */
#define Slave_Select_AMUX                   (* (reg8 *) Slave_Select__AMUX) 
/* Bidirectional Enable */                                                        
#define Slave_Select_BIE                    (* (reg8 *) Slave_Select__BIE)
/* Bit-mask for Aliased Register Access */
#define Slave_Select_BIT_MASK               (* (reg8 *) Slave_Select__BIT_MASK)
/* Bypass Enable */
#define Slave_Select_BYP                    (* (reg8 *) Slave_Select__BYP)
/* Port wide control signals */                                                   
#define Slave_Select_CTL                    (* (reg8 *) Slave_Select__CTL)
/* Drive Modes */
#define Slave_Select_DM0                    (* (reg8 *) Slave_Select__DM0) 
#define Slave_Select_DM1                    (* (reg8 *) Slave_Select__DM1)
#define Slave_Select_DM2                    (* (reg8 *) Slave_Select__DM2) 
/* Input Buffer Disable Override */
#define Slave_Select_INP_DIS                (* (reg8 *) Slave_Select__INP_DIS)
/* LCD Common or Segment Drive */
#define Slave_Select_LCD_COM_SEG            (* (reg8 *) Slave_Select__LCD_COM_SEG)
/* Enable Segment LCD */
#define Slave_Select_LCD_EN                 (* (reg8 *) Slave_Select__LCD_EN)
/* Slew Rate Control */
#define Slave_Select_SLW                    (* (reg8 *) Slave_Select__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Slave_Select_PRTDSI__CAPS_SEL       (* (reg8 *) Slave_Select__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Slave_Select_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Slave_Select__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Slave_Select_PRTDSI__OE_SEL0        (* (reg8 *) Slave_Select__PRTDSI__OE_SEL0) 
#define Slave_Select_PRTDSI__OE_SEL1        (* (reg8 *) Slave_Select__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Slave_Select_PRTDSI__OUT_SEL0       (* (reg8 *) Slave_Select__PRTDSI__OUT_SEL0) 
#define Slave_Select_PRTDSI__OUT_SEL1       (* (reg8 *) Slave_Select__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Slave_Select_PRTDSI__SYNC_OUT       (* (reg8 *) Slave_Select__PRTDSI__SYNC_OUT) 


#if defined(Slave_Select__INTSTAT)  /* Interrupt Registers */

    #define Slave_Select_INTSTAT                (* (reg8 *) Slave_Select__INTSTAT)
    #define Slave_Select_SNAP                   (* (reg8 *) Slave_Select__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Slave_Select_H */


/* [] END OF FILE */
