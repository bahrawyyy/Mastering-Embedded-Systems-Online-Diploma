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

#define DefaultStop '\r'


void UART_Init(void);

void UART_Send_Char(u8 data);
u8 UART_Receive_Char(void);

// Sending and receiving using busy wait
void UART_Send_String(char* string);
void UART_Receive_String(char *Buffer);

// Sending and receiving without blocking
u8 UART_Receive_PeriodicCheck(u8* pdata);

// Using Interrupts
void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);

// Enabling interrupts
void UART_TX_InterruptEnable(void);
void UART_RX_InterruptEnable(void);

void UART_TX_InterruptDisable(void);
void UART_RX_InterruptDisable(void);


void UART_SendString_ASYNCH(u8* str);
void UART_ReceiveString_ASYNCH(u8* str);

#endif /* MCAL_UART_UART_H_ */
