/*****************************************************/
/* Author      : yomna                              */
/* Version     : v01                                */
/* date        : 25/5/2022                          */
/*****************************************************/
/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* Module includes */
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"



void UART_voidInit(void)
{
	UART_Ch_t local_u8Counter = 0;
	// To initiaize all the channels 
	for (local_u8Counter = 0 ; local_u8Counter < MAX_TIMERS ; local_u8Counter++){
		// To only configure the enabled uart modules 
		if (UART_configTable [local_u8Counter].moduleEnable == UART_ENABLE){
			
			/* Configure word length */
			switch (UART_configTable [local_u8Counter].wordLenght){
				case DATA_8BIT :
					CLEAR_BIT ((*(UART[local_u8Counter]+CR1)) , M);
					break ;
				case DATA_9BIT :
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , M);
					break ;
				default : /* Should not be here */ break;
			}
			
			/* Configure parity mode */
			switch (UART_configTable [local_u8Counter].parityMode){
				case EVEN_PARITY :
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , PCE);    // enable parity control
					CLEAR_BIT ((*(UART[local_u8Counter]+CR1)) , PS);   // choose even parity
					break ;
				case ODD_PARITY :
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , PCE);    // enable parity control
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , PS);     // choose odd parity
					break ;
				case NO_PARITY :
					CLEAR_BIT ((*(UART[local_u8Counter]+CR1)) , PCE);  // disable parity control
					break ;
				default : /* Should not be here */ break;
			}
			
			/* Configure R / T enable and disable */
			switch (UART_configTable [local_u8Counter].parityMode){
				case ENABLE_RECEIVER :
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , RE);
					break ;
				case ENABLE_TRANSMITTER :
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , TE);   
					break ;
				case ENABLE_BOTH :
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , RE);
					SET_BIT ((*(UART[local_u8Counter]+CR1)) , TE);
					break ;
				default : /* Should not be here */ break;
			}
			
			/* Configure baud rate */
			u32 local_u32BRRValue = UART_configTable [local_u8Counter].u32BusFreq / (16 * UART_configTable [local_u8Counter].u32Baudrate);
			*(UART[local_u8Counter]+BBR)  = (local_u32BRRValue << 4) ;   
			
			/* Enable module */
			SET_BIT((*(UART[local_u8Counter]+CR1)) , UE);
			
			/* Intialize status rigeter */
			*(UART[local_u8Counter]+SR)  = 0 ;
		}
	}
}


void UART_voidSendDataSynch(UART_Ch_t copy_ch , u8 *copy_u8data)
{
	while (*copy_u8data){
		*(UART[copy_ch]+DR)  = *copy_u8data ;
		while (GIT_BIT ((*(UART[copy_ch]+SR)) , 6) == 0);
		copy_u8data++;
	}
}

void UART_voidRecDataSynch (UART_Ch_t copy_ch , u8 *copy_u8data , u8 copy_u8DataLength)
{
	
	while (copy_u8DataLength--){
		while (GIT_BIT ((*(UART[copy_ch]+SR)) , 5) == 0);
		*copy_u8data = *(UART[copy_ch]+DR);
		copy_u8data++;
	}
}



