/*
 * SPI.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Abdallah
 */


#include "SPI.h"



void SPI_Master_Init(void)
{
	DIO_ES_tSetPinDirection(SPI_REG, SCK, OUTPUT);
	DIO_ES_tSetPinDirection(SPI_REG, MOSI, OUTPUT);
	DIO_ES_tSetPinDirection(SPI_REG, SS, OUTPUT);


	// Set MISO pin as INPUT
	DIO_ES_tSetPinDirection(SPI_REG, MISO, INPUT);


//	DIO_ES_tSetPinValue(SPI_REG, SS, LOW);

	// Enable SPI
	SET_BIT(SPCR,SPE);
	// Work as a master
	SET_BIT(SPCR,MSTR);
	// SPI clock rate : fck / 16
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPI2X);
}



void SPI_Slave_Init(void)
{
	DIO_ES_tSetPinDirection(SPI_REG, MISO, OUTPUT);
	// Set SCK, MOSI, and SS pins as INPUT (slave mode doesn't need them as output)
	DIO_ES_tSetPinDirection(SPI_REG, SCK, INPUT);
	DIO_ES_tSetPinDirection(SPI_REG, MOSI, INPUT);
	DIO_ES_tSetPinDirection(SPI_REG, SS, INPUT);


	// Enable SPI
	SET_BIT(SPCR,SPE);

	CLR_BIT(SPCR,MSTR);
}



u8 SPI_Master_Transmit_Receive(u8 data)
{
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
	// Return data received from slave
	return SPDR;

}



u8 SPI_Slave_Transmit_Receive(u8 data)
{
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
	// Return data received from slave
	return SPDR;
}
