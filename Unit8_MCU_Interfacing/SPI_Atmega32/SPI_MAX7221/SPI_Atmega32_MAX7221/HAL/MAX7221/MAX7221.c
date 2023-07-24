/*
 * MAX7221.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Abdallah
 */


#include "MAX7221.h"
#include "../../MCAL/SPI/SPI.h"

// For Max7221
void SPI_MAX7221_Execute(u8 cmd,u8 data)
{
	DIO_ES_tSetPinValue(SPI_REG, SS, LOW);
	SPDR = cmd;
	while(!GET_BIT(SPSR,SPIF));
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
	DIO_ES_tSetPinValue(SPI_REG, SS, HIGH);
}



void MAX7221_Init(void)
{
	// Normal operation
	SPI_MAX7221_Execute(SHUTDOWN_Address,0x01);

	// Decode for digits from 0 to 7
	SPI_MAX7221_Execute(Decode_Mode_Address,0xFF);

	// Intensity max
	SPI_MAX7221_Execute(Intensity_Address,0x0F);

	// Display digits from 0 to 7
	SPI_MAX7221_Execute(SCANLIMIT_Address, 0x07);
}



