/*******************************************************************************
* File Name: Button_1_REG_0.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Button_1_REG_0_H) /* Pins Button_1_REG_0_H */
#define CY_PINS_Button_1_REG_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Button_1_REG_0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Button_1_REG_0__PORT == 15 && ((Button_1_REG_0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Button_1_REG_0_Write(uint8 value);
void    Button_1_REG_0_SetDriveMode(uint8 mode);
uint8   Button_1_REG_0_ReadDataReg(void);
uint8   Button_1_REG_0_Read(void);
void    Button_1_REG_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   Button_1_REG_0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Button_1_REG_0_SetDriveMode() function.
     *  @{
     */
        #define Button_1_REG_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Button_1_REG_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Button_1_REG_0_DM_RES_UP          PIN_DM_RES_UP
        #define Button_1_REG_0_DM_RES_DWN         PIN_DM_RES_DWN
        #define Button_1_REG_0_DM_OD_LO           PIN_DM_OD_LO
        #define Button_1_REG_0_DM_OD_HI           PIN_DM_OD_HI
        #define Button_1_REG_0_DM_STRONG          PIN_DM_STRONG
        #define Button_1_REG_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Button_1_REG_0_MASK               Button_1_REG_0__MASK
#define Button_1_REG_0_SHIFT              Button_1_REG_0__SHIFT
#define Button_1_REG_0_WIDTH              1u

/* Interrupt constants */
#if defined(Button_1_REG_0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Button_1_REG_0_SetInterruptMode() function.
     *  @{
     */
        #define Button_1_REG_0_INTR_NONE      (uint16)(0x0000u)
        #define Button_1_REG_0_INTR_RISING    (uint16)(0x0001u)
        #define Button_1_REG_0_INTR_FALLING   (uint16)(0x0002u)
        #define Button_1_REG_0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Button_1_REG_0_INTR_MASK      (0x01u) 
#endif /* (Button_1_REG_0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button_1_REG_0_PS                     (* (reg8 *) Button_1_REG_0__PS)
/* Data Register */
#define Button_1_REG_0_DR                     (* (reg8 *) Button_1_REG_0__DR)
/* Port Number */
#define Button_1_REG_0_PRT_NUM                (* (reg8 *) Button_1_REG_0__PRT) 
/* Connect to Analog Globals */                                                  
#define Button_1_REG_0_AG                     (* (reg8 *) Button_1_REG_0__AG)                       
/* Analog MUX bux enable */
#define Button_1_REG_0_AMUX                   (* (reg8 *) Button_1_REG_0__AMUX) 
/* Bidirectional Enable */                                                        
#define Button_1_REG_0_BIE                    (* (reg8 *) Button_1_REG_0__BIE)
/* Bit-mask for Aliased Register Access */
#define Button_1_REG_0_BIT_MASK               (* (reg8 *) Button_1_REG_0__BIT_MASK)
/* Bypass Enable */
#define Button_1_REG_0_BYP                    (* (reg8 *) Button_1_REG_0__BYP)
/* Port wide control signals */                                                   
#define Button_1_REG_0_CTL                    (* (reg8 *) Button_1_REG_0__CTL)
/* Drive Modes */
#define Button_1_REG_0_DM0                    (* (reg8 *) Button_1_REG_0__DM0) 
#define Button_1_REG_0_DM1                    (* (reg8 *) Button_1_REG_0__DM1)
#define Button_1_REG_0_DM2                    (* (reg8 *) Button_1_REG_0__DM2) 
/* Input Buffer Disable Override */
#define Button_1_REG_0_INP_DIS                (* (reg8 *) Button_1_REG_0__INP_DIS)
/* LCD Common or Segment Drive */
#define Button_1_REG_0_LCD_COM_SEG            (* (reg8 *) Button_1_REG_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Button_1_REG_0_LCD_EN                 (* (reg8 *) Button_1_REG_0__LCD_EN)
/* Slew Rate Control */
#define Button_1_REG_0_SLW                    (* (reg8 *) Button_1_REG_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Button_1_REG_0_PRTDSI__CAPS_SEL       (* (reg8 *) Button_1_REG_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Button_1_REG_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Button_1_REG_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Button_1_REG_0_PRTDSI__OE_SEL0        (* (reg8 *) Button_1_REG_0__PRTDSI__OE_SEL0) 
#define Button_1_REG_0_PRTDSI__OE_SEL1        (* (reg8 *) Button_1_REG_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Button_1_REG_0_PRTDSI__OUT_SEL0       (* (reg8 *) Button_1_REG_0__PRTDSI__OUT_SEL0) 
#define Button_1_REG_0_PRTDSI__OUT_SEL1       (* (reg8 *) Button_1_REG_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Button_1_REG_0_PRTDSI__SYNC_OUT       (* (reg8 *) Button_1_REG_0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Button_1_REG_0__SIO_CFG)
    #define Button_1_REG_0_SIO_HYST_EN        (* (reg8 *) Button_1_REG_0__SIO_HYST_EN)
    #define Button_1_REG_0_SIO_REG_HIFREQ     (* (reg8 *) Button_1_REG_0__SIO_REG_HIFREQ)
    #define Button_1_REG_0_SIO_CFG            (* (reg8 *) Button_1_REG_0__SIO_CFG)
    #define Button_1_REG_0_SIO_DIFF           (* (reg8 *) Button_1_REG_0__SIO_DIFF)
#endif /* (Button_1_REG_0__SIO_CFG) */

/* Interrupt Registers */
#if defined(Button_1_REG_0__INTSTAT)
    #define Button_1_REG_0_INTSTAT            (* (reg8 *) Button_1_REG_0__INTSTAT)
    #define Button_1_REG_0_SNAP               (* (reg8 *) Button_1_REG_0__SNAP)
    
	#define Button_1_REG_0_0_INTTYPE_REG 		(* (reg8 *) Button_1_REG_0__0__INTTYPE)
#endif /* (Button_1_REG_0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Button_1_REG_0_H */


/* [] END OF FILE */
