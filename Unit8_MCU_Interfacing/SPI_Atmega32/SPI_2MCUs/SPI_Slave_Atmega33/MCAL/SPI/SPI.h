/*
 * SPI.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Abdallah
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../Dio/Dio_interface.h"
#include "../Registers.h"

#define SPI_REG		DIO_U8_PORT_B
#define SS			DIO_U8_PIN_4
#define MOSI		DIO_U8_PIN_5
#define MISO		DIO_U8_PIN_6
#define SCK			DIO_U8_PIN_7


void SPI_Master_Init(void);
void SPI_Slave_Init(void);

u8 SPI_Master_Transmit_Receive(u8 data);
u8 SPI_Slave_Transmit_Receive(u8 data);



#endif /* MCAL_SPI_SPI_H_ */
