/*
 * MAX7221.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Abdallah
 */

#ifndef HAL_MAX7221_MAX7221_H_
#define HAL_MAX7221_MAX7221_H_

#include "../../MCAL/SPI/SPI.h"

#define Decode_Mode_Address		0x09
#define Intensity_Address		0x0A
#define SCANLIMIT_Address		0x0B
#define SHUTDOWN_Address		0x0C



void MAX7221_Init(void);
void SPI_MAX7221_Execute(u8 cmd,u8 data);



#endif /* HAL_MAX7221_MAX7221_H_ */
