/*****************************************************/
/* Author      : yomna                              */
/* Version     : v01                                */
/* date        : 1/6/2022                           */
/*****************************************************/
/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* Module includes */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidInit(void){
	
	/* Choose configurations */	
	#if   NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_16
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_16 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_8
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_8 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_4
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_4 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_2
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_2 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_0
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_0 << GROUPING_BIT) )  ;
	
	#else 
		#error (" Configuration error ")
	#endif
	
}

void NVIC_voidEnableIRQ(NVIC_IRQn_t copyIRQn){
	/* Devided by 32 to write to the right regsiter index         */
	/* Anding (copyIRQn) with 31 so value will always be under 32 */
	u8 reg_index = copyIRQn / 32 ;
	NVIC->ISER[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

void NVIC_voidDisableIRQ(NVIC_IRQn_t copyIRQn){
	u8 reg_index = copyIRQn / 32 ;
	NVIC->ICER[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

u8   NVIC_u8GetPendingIRQ (NVIC_IRQn_t copyIRQn){
	u8 reg_index = copyIRQn / 32 ;
	u8 bit = GIT_BIT(NVIC->ISPR[ reg_index ] , (copyIRQn & 31 ) ) ;
	return bit ;  
}

void NVIC_voidSetPendingIRQ (NVIC_IRQn_t copyIRQn){
	u8 reg_index = copyIRQn / 32 ;
	NVIC->ISPR[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

void NVIC_voidClearPendingIRQ (NVIC_IRQn_t copyIRQn){
	u8 reg_index = copyIRQn / 32 ;
	NVIC->ICPR[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

u8  NVIC_u8GetActive (NVIC_IRQn_t copyIRQn){
	u8 reg_index = copyIRQn / 32 ;
	u8 bit = GIT_BIT(NVIC->IABR[ reg_index ] , (copyIRQn & 31 ) ) ;
	return bit ;
}

void NVIC_voidSetPriority (NVIC_IRQn_t copyIRQn, u8 copy_u8Priority){
	
	/* Writing into the four bit the periority */
	NVIC->IPR[ copyIRQn ] = (copy_u8Priority << 4);
	
}





