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

char received_string[100];
u8 y,x;


int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();
	UART_Init();
	sei();


	Lcd_ES_tsendString("UART");
	LCD_ES_tGoTo(1, 0);
	Lcd_ES_tsendString("Testing !");
	_delay_ms(500);
	lcd_ES_tclear();



	UART_SendString_ASYNCH("Abdalla");
	_delay_ms(10);
	UART_SendString_ASYNCH("Bahrawy");


	while (1)
	{





//		UART_Receive_String(received_string);
//
//		Lcd_ES_tsendString(received_string);
//		_delay_ms(500);


		// Using No blocking functions
//		if(UART_Receive_PeriodicCheck(&y))
//		{
//			LCD_ES_tGoTo(0, 0);
//			Lcd_ES_tsendChar(y);
//		}
//
//		LCD_ES_tGoTo(1, 0);
//		Lcd_ES_tdisplayNum(x);
//		x++;
//		if(x==10)
//		{
//			x=0;
//		}
//		_delay_ms(200);




	}

	return 0;
}
