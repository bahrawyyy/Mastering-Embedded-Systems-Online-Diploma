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
	sei();

	u8 received_string[100]={0};



	Lcd_ES_tsendString("UART");
	LCD_ES_tGoTo(1, 0);
	Lcd_ES_tsendString("Testing !");
	_delay_ms(500);
	lcd_ES_tclear();



	UART_SendString_ASYNCH("Abdalla");


	UART_ReceiveString_ASYNCH(received_string);



	while (1)
	{

		Lcd_ES_tsendString(received_string);
		_delay_ms(1000);




	}

	return 0;
}
