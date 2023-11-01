/*****************************************************/
/* Author      : yomna                              */
/* Version     : v01                                */
/* date        : 4/6/2022                           */
/*****************************************************/
#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

/*
  * STP_voidInit - > Initialize STP pins
  * i/p : void
*/
void STP_voidInit(void);

/*
  * STP_voidInit - > write data
  * i/p : void
*/
void STP_voidSendSynch(u16 copy_u16DataToSend);


#endif
