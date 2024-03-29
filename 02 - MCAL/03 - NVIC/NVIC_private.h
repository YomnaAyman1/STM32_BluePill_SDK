/*****************************************************/
/* Author      : yomna                              */
/* Version     : v01                                */
/* date        : 1/6/2022                           */
/*****************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* Struct for the NVIC regsiter mapping */
typedef struct {
	volatile u32 ISER[3]           ;   /* Interrupt set enable registers    */
	volatile u32 RESERVED0[29]     ;   
	volatile u32 ICER[3]           ;   /* Interrupt clear enable registers  */
	volatile u32 RESERVED1[29]     ;  
	volatile u32 ISPR[3]           ;   /* Interrupt set pinding registers   */
	volatile u32 RESERVED2[29]     ;
	volatile u32 ICPR[3]           ;   /* Interrupt clear pinding registers */
	volatile u32 RESERVED3[29]     ;
	volatile u32 IABR[3]           ;   /* Interrupt active bit registers    */
	volatile u32 RESERVED4[61]     ;	
	volatile u8 IPR[80]            ;   /* Interrupt priority registers      */
}NVIC_t;

/* Register defintions  */
#define   NVIC_BASE_ADDRESS     0xE000E100
#define   NVIC                   ((volatile NVIC_t *) NVIC_BASE_ADDRESS      )
#define   NVIC_STIR             *((volatile u32 *) NVIC_BASE_ADDRESS + 0xE00 )
#define   SCB_AIRCR             *((volatile u32 *) 0xE000ED0C )

/* constants */
#define   VECTKEY               0x05FA0000
#define   GROUPING_BIT          8

/* Group priority options */
#define NVIC_GROUPING_16     0b011
#define NVIC_GROUPING_8      0b100
#define NVIC_GROUPING_4      0b101
#define NVIC_GROUPING_2      0b110
#define NVIC_GROUPING_0      0b111



#endif
