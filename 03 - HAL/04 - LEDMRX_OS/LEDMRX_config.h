/*****************************************************/
/* Author      : yomna                              */
/* Version     : v01                                */
/* date        : 4/6/2022                           */
/*****************************************************/
#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H


/* Choode the number of coloumns and rows */
#define    LEDMRX_ROWS_NUMBER        8 
#define    LEDMRX_COLOUMNS_NUMBER    8

/* Options:
		GPIO_OUTPUT_10MHZ_PP
		GPIO_OUTPUT_50MHZ_PP
		GPIO_OUTPUT_2MHZ_PP

*/
#define    LEDMRX_OUTPUT_MODE      GPIO_OUTPUT_10MHZ_PP

/*
	Options: 0 OR 1 
*/
#define   LEDMRX_ROW_VOLTAGE        1
#define   LEDMRX_COLOUMN_VOLTAGE    0





#endif
