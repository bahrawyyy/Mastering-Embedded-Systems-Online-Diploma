/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include <util/delay.h>
#include "../HAL/KPD/KPD_interface.h"
#include "../MCAL/UART/UART.h"
#include "string.h"




int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();
	UART_Init();


	Lcd_ES_tsendString("UART");
	LCD_ES_tGoTo(1, 0);
	Lcd_ES_tsendString("Testing !");
	_delay_ms(500);
	lcd_ES_tclear();

	UART_Send_String("Abdalla");

	char received_string[100];

	while (1)
	{

		strcpy(received_string,UART_Receive_String());

		Lcd_ES_tsendString(received_string);
		_delay_ms(500);


	}

	return 0;
}
