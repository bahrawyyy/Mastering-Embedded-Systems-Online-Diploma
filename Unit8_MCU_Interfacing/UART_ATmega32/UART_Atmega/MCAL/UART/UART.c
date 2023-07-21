/*
 * UART.c
 *
 *  Created on: Jul 18, 2023
 *      Author: Abdallah
 */


#include "UART.h"
#include "../../HAL/Lcd/Lcd.h"

#define NULL ((void *)0)

static u8 *TX_Str;
static u8 flag_send = 1;



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
	// The CPU is stucking here
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
	// Send (Enter) as a terminating char
	UART_Send_Char(DefaultStop);
}


void UART_Receive_String(char *Buffer)
{
    int i = 0;

    Buffer[i] = UART_Receive_Char();
    while (Buffer[i] != DefaultStop) {
        i++;
        Buffer[i] = UART_Receive_Char();

    }

    Buffer[i] = '\0'; // Null-terminate the string
}

// Some characters may not be read, if you entered them fast
u8 UART_Receive_PeriodicCheck(u8* pdata)
{
	if(GET_BIT(UCSRA,RXC))
	{
		*pdata = UDR;
		return 1;
	}
	return 0;
}


void UART_SendNoBlock(u8 data)
{
	UDR = data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

// Receive complete
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

// Transmission complete
void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}


// Receive complete
void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}

// Transmission complete
void UART_TX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,TXCIE);
}



// Function Asynchronous to send string
void UART_SendString_ASYNCH(u8* str)
{
	// To prevent data over run
	// When I'm sending this string, I'll continue till I finish it
	if(flag_send == 1){
		UART_TX_InterruptEnable();
		UART_SendNoBlock(str[0]);
		TX_Str = str;   // To know where I'm stopping out of this function
		flag_send = 0;
	}
}




ISR(USART_TXC_vect)
{
	static u8 i = 1;
	if(TX_Str[i]!= 0)
	{
		UART_SendNoBlock(TX_Str[i]);
		i++;
	}else{
		i=1;
		flag_send=1;
	}
}


