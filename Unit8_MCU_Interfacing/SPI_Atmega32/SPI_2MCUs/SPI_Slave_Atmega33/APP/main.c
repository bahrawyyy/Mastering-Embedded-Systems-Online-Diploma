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




int main()
{
	// Seven segment port
	DIO_ES_tSetPortDirection(DIO_U8_PORT_A, OUTPUT);

	u8 data=0;

	SPI_Slave_Init();

	for(data=255;data>=0;data--)
	{
		_delay_ms(1000);
		PORTA = SPI_Slave_Transmit_Receive(data);
	}


	return 0;
}
