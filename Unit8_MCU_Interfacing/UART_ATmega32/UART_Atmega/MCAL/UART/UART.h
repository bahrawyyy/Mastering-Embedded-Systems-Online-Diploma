/*
 * UART.h
 *
 *  Created on: Jul 18, 2023
 *      Author: Abdallah
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../Registers.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"


void UART_Init(void);

void UART_Send_Char(u8 data);
u8 UART_Receive_Char(void);

void UART_Send_String(char* string);
char* UART_Receive_String(void);


#endif /* MCAL_UART_UART_H_ */
