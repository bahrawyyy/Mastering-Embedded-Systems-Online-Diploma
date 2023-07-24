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
#include "../MCAL/SPI/SPI.h"
#include "../HAL/MAX7221/MAX7221.h"




int main()
{
	DIO_ES_tSetPinValue(SPI_REG, SS, HIGH);

	u8 sevenSegmentIndex=0,counter=0;

	SPI_Master_Init();
	MAX7221_Init();

	while(1)
	{
		for(sevenSegmentIndex=1;sevenSegmentIndex<9;sevenSegmentIndex++)
		{
			SPI_MAX7221_Execute(sevenSegmentIndex, counter++);
			_delay_ms(200);
		}
	}


	return 0;
}
