/*****************************************************/
 /* Author      : mosad                              */
 /* Version     : v01                                */
 /* date        : 24/8/2020                          */
/*****************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* enum to hold the trigger options */
typedef enum {
	EXTI_RISING_EDGE ,
	EXTI_FALLING_EDGE,
	EXTI_ON_CHANGE
}EXTI_triggerSelect_t;

/* 
  * EXTI_voidInitLineInterrupt - > Only set the trigger sensing 
  * i/p : (u8) line number / (EXTI_triggerSelect_t) the trigger mode 
*/
void EXTI_voidInitLineInterrupt(u8 copy_u8Line , EXTI_triggerSelect_t copy_triggerType);

/* 
  * EXTI_voidEnableLineInterrupt - > Enable a specific external interrupt line
  * i/p : (u8) line number
*/
void EXTI_voidEnableLineInterrupt(u8 copy_u8Line);

/* 
  * EXTI_voidDisableLineInterrupt - > Disable a specific external interrupt line
  * i/p : (u8) line number
*/
void EXTI_voidDisableLineInterrupt(u8 copy_u8Line);

/* 
  * EXTI_voidSoftwareInterrupt - > Trigger SWI for a given external interrupt line
  * i/p : (u8) line number
*/
void EXTI_voidSoftwareInterrupt(u8 copy_u8Line);

/* 
  * EXTI_voidClearPendingFlag - > clear the pending flag for a specific external interrupt line 
  * i/p : (u8) line number
*/
void EXTI_voidClearPendingFlag(u8 copy_u8Line);


#endif