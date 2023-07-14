/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include "../HAL/KPD/KPD_interface.h"



int main()
{
	DIO_ES_tInit();
	Lcd_ES_tInit();



	lcd_ES_tclear();
	Lcd_ES_tsendString("Learn In Depth");


	while (1)
	{

	}

	return 0;
}
