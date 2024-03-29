/*****************************************************/
/* Author      : yomna                              */
/* Version     : v01                                */
/* date        : 1/6/2022                           */
/*****************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/******************************************************/
/* (STK_voidSetBusyWait) function is to use the STK in 
    synchronous mode the processor will be hold.
   (STK_voidSetIntervalPeriodic) function is to use the
    STK in asynchronous mode and a function will be
    passed to the ISR.
	you should use the STK in only one of the modes to 
	guarantee to work correctly 
	you can also use it to caclulate some elabsed time from
	specific point using (STK_voidStart)
*/
/*******************************************************/

            /****    global types   ****/
typedef enum {
	TIME_MS,
	TIME_US
}STK_time_t;

/*******************************************************/

           /****  Function prototypes  *****/
/* 
  * STK_voidInit - > initialize the SysTick 
*/
void STK_voidInit(void);

/* 
  * STK_voidSetBusyWait - > hold the processor for amount of time in ms or us 
  * i/p : (u32) Time / (STK_time_t) unit : TIME_MS - TIME_US
*/
void STK_voidSetBusyWait( u32 Copy_u32Time , STK_time_t copy_unit );

/* 
  * STK_voidSetIntervalPeriodic - > pass a periodic function to the SysTick ISR
  * i/p : (u32) Time / (STK_time_t) unit : TIME_MS - TIME_US / void function 
*/
void STK_voidSetIntervalPeriodic( u32 Copy_u32Time , STK_time_t copy_unit, void (*Copy_func)(void));

/* 
  * STK_voidSetIntervalSingle - > pass a one shot function to the SysTick ISR
  * i/p : (u32) Time / (STK_time_t) unit : TIME_MS - TIME_US / void function 
*/
void STK_voidSetIntervalSingle( u32 Copy_u32Time , STK_time_t copy_unit, void (*Copy_func)(void));

/* 
  * STK_voidStop - > stop timer and disable interrupt  
*/
void STK_voidStop(void);

/* 
  * STK_voidResume - > start timer and enable interrupt  
*/
void STK_voidResume(void);

/* 
  * STK_voidStart - > start timer to count from max value can be used to culcated time elapsed
					  from calling this function 
*/
void STK_voidStart(void);

/* 
  * STK_u32GetElapsedTime - > return elapsed time in ms or us
  * i/p : (STK_time_t) unit : TIME_MS - TIME_US
*/
u32 STK_u32GetElapsedTime(STK_time_t copy_unit);

/* 
  * STK_u32GetRemainingTime - > return remaining time in ms or us
  * i/p : (STK_time_t) unit : TIME_MS - TIME_US
*/
u32 STK_u32GetRemainingTime(STK_time_t copy_unit);


#endif
