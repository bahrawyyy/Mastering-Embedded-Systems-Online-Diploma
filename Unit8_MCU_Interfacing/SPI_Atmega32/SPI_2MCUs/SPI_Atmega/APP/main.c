/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdallah
 */

#define Act_As_Master
//#define Act_As_Slave

#define F_CPU 16000000UL

#include "../HAL/Lcd/Lcd.h"
#include <util/delay.h>
#include "../HAL/KPD/KPD_interface.h"
#include "../MCAL/UART/UART.h"
#include "string.h"
#include "../MCAL/SPI/SPI.h"




int main()
{
	u8 data=0;
	// Seven segment port
	DIO_ES_tSetPortDirection(DIO_U8_PORT_A, OUTPUT);

	SPI_Config_t SPI_Cfg;

	SPI_Cfg.CLK_PHASE = SPI_CLK_PHASE_LEADING_SAMPLE;
	SPI_Cfg.CLK_Polarity = SPI_CLK_Polarity_IDLE_LOW;
	SPI_Cfg.Data_Order = SPI_DATA_ORDER_MSB;

#ifdef Act_As_Master
	SPI_Cfg.Device_Mode = SPI_DEVICE_MODE_MASTER;
	SPI_Cfg.Prescalar = SPI_Prescalar_16;
#endif

#ifdef Act_As_Slave
	SPI_Cfg.Device_Mode = SPI_DEVICE_MODE_SLAVE;
#endif


	SPI_Init(&SPI_Cfg);

#ifdef Act_As_Master
	for(data=0;data<= 255;data++)
	{
		DIO_ES_tSetPinValue(SPI_REG, SS, LOW);
#endif

#ifdef Act_As_Slave
	for(data=255;data>=0;data--)
	{
#endif
		_delay_ms(1000);
		PORTA = SPI_Transmit_Receive(data);
	}


		return 0;
	}
