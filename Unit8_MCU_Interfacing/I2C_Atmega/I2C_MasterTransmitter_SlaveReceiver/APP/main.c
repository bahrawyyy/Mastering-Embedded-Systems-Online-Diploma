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
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/I2C/I2C.h"




int main()
{
#ifdef Act_As_Master
	unsigned char ch= 0;
	I2C_Init(0x48);
	while(1)
	{
		_delay_ms(500);
		I2C_Start();
		I2C_Write(0b11010000+0); // Transmit SLA+W(0)
		while((TWSR&0xF8)!=0x18);		// SLA+W has been transmitted ACK has been received
		I2C_Write(ch++);
		while((TWSR&0xF8)!=0x28);		// Data byte has been transmitted ACK has been received
		I2C_Stop();
	}


	return 0;
#endif

#ifdef Act_As_Slave
	u8 status;
	DDRA = 0xFF;
	I2C_Set_Address(0b1101000);
	while(1){
		PORTA = I2C_Slave_Read(&status);
	}


	return 0;
#endif


}
