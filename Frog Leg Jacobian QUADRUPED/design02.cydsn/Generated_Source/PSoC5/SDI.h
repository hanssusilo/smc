/*******************************************************************************
* File Name: SDI.h  
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

#if !defined(CY_PINS_SDI_H) /* Pins SDI_H */
#define CY_PINS_SDI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SDI_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SDI__PORT == 15 && ((SDI__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SDI_Write(uint8 value) ;
void    SDI_SetDriveMode(uint8 mode) ;
uint8   SDI_ReadDataReg(void) ;
uint8   SDI_Read(void) ;
uint8   SDI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SDI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SDI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SDI_DM_RES_UP          PIN_DM_RES_UP
#define SDI_DM_RES_DWN         PIN_DM_RES_DWN
#define SDI_DM_OD_LO           PIN_DM_OD_LO
#define SDI_DM_OD_HI           PIN_DM_OD_HI
#define SDI_DM_STRONG          PIN_DM_STRONG
#define SDI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SDI_MASK               SDI__MASK
#define SDI_SHIFT              SDI__SHIFT
#define SDI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SDI_PS                     (* (reg8 *) SDI__PS)
/* Data Register */
#define SDI_DR                     (* (reg8 *) SDI__DR)
/* Port Number */
#define SDI_PRT_NUM                (* (reg8 *) SDI__PRT) 
/* Connect to Analog Globals */                                                  
#define SDI_AG                     (* (reg8 *) SDI__AG)                       
/* Analog MUX bux enable */
#define SDI_AMUX                   (* (reg8 *) SDI__AMUX) 
/* Bidirectional Enable */                                                        
#define SDI_BIE                    (* (reg8 *) SDI__BIE)
/* Bit-mask for Aliased Register Access */
#define SDI_BIT_MASK               (* (reg8 *) SDI__BIT_MASK)
/* Bypass Enable */
#define SDI_BYP                    (* (reg8 *) SDI__BYP)
/* Port wide control signals */                                                   
#define SDI_CTL                    (* (reg8 *) SDI__CTL)
/* Drive Modes */
#define SDI_DM0                    (* (reg8 *) SDI__DM0) 
#define SDI_DM1                    (* (reg8 *) SDI__DM1)
#define SDI_DM2                    (* (reg8 *) SDI__DM2) 
/* Input Buffer Disable Override */
#define SDI_INP_DIS                (* (reg8 *) SDI__INP_DIS)
/* LCD Common or Segment Drive */
#define SDI_LCD_COM_SEG            (* (reg8 *) SDI__LCD_COM_SEG)
/* Enable Segment LCD */
#define SDI_LCD_EN                 (* (reg8 *) SDI__LCD_EN)
/* Slew Rate Control */
#define SDI_SLW                    (* (reg8 *) SDI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SDI_PRTDSI__CAPS_SEL       (* (reg8 *) SDI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SDI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SDI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SDI_PRTDSI__OE_SEL0        (* (reg8 *) SDI__PRTDSI__OE_SEL0) 
#define SDI_PRTDSI__OE_SEL1        (* (reg8 *) SDI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SDI_PRTDSI__OUT_SEL0       (* (reg8 *) SDI__PRTDSI__OUT_SEL0) 
#define SDI_PRTDSI__OUT_SEL1       (* (reg8 *) SDI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SDI_PRTDSI__SYNC_OUT       (* (reg8 *) SDI__PRTDSI__SYNC_OUT) 


#if defined(SDI__INTSTAT)  /* Interrupt Registers */

    #define SDI_INTSTAT                (* (reg8 *) SDI__INTSTAT)
    #define SDI_SNAP                   (* (reg8 *) SDI__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SDI_H */


/* [] END OF FILE */
