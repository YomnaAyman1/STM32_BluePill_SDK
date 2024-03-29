/*****************************************************/
/* Author      : yomna                              */
/* Version     : v01                                */
/* date        : 25/5/2022                          */
/*****************************************************/

#include "STD_TYPES.h"

#include "UART_config.h"

UART_config_t UART_configTable [UART_MAX_CH] = {
   // Module 	Date          parity         Rec / trans          Bus       baudrate
   // enable	bits          mode           enable               clk
	{UART_ENABLE   , DATA_8BIT   , NO_PARITY    , ENABLE_BOTH   , APB2_CLK , 9600},
	{UART_DISABLE  , DATA_8BIT   , NO_PARITY    , ENABLE_BOTH   , APB1_CLK , 9600},
	{UART_DISABLE  , DATA_8BIT   , NO_PARITY    , ENABLE_BOTH   , APB1_CLK , 9600}
};
