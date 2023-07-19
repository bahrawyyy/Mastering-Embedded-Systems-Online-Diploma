/*
 * UART.c
 *
 *  Created on: Jul 18, 2023
 *      Author: Abdallah
 */


#include "UART.h"
#include "../../HAL/Lcd/Lcd.h"

#define NULL ((void *)0)


#define MAX_STRING_LENGTH 100

void UART_Init(void)
{
	// Baud rate
	UBRRL = 103;     // 16 MHz crystal
	// Normal mode
	CLR_BIT(UCSRA,U2X);


	// Frame
	// In order to access UCSRC
	SET_BIT(UCSRC,URSEL);   // To write data on UCSRC
	CLR_BIT(UCSRC,UMSEL);   // Asynchronous
	// 8-bit data
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);


	// Enable
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);


}

void UART_Send_Char(u8 data)
{
	// Busy wait
	while(!GET_BIT(UCSRA,UDRE));
	UDR = data;
}
u8 UART_Receive_Char(void)
{
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}


void UART_Send_String(char* string)
{
	u8 i=0;
	while(string[i] != '\0'){
		UART_Send_Char(string[i]);
		i++;
	}
}


char* UART_Receive_String(void)
{
    static char string[MAX_STRING_LENGTH];
    int i = 0;
    char received_char;

    while ((received_char = UART_Receive_Char()) != '#') {
        string[i] = received_char;
        i++;

        // Add a check for string length to prevent buffer overflow
        if (i >= MAX_STRING_LENGTH - 1) {
            break; // Exit loop to prevent exceeding the buffer size (leave space for null-termination)
        }
    }

    string[i] = '\0'; // Null-terminate the string

    return string;
}


