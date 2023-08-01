/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


// #define MCU_Act_As_Master
#define MCU_Act_As_Master

#include "Stm32_F103C6_gpio_driver.h"
#include "Stm32_F103C6_EXTI_driver.h"
#include "Stm32_F103C6_USART_driver.h"
#include "Stm32_F103C6_SPI_driver.h"
#include "stm32f103c6.h"
#include "Lcd.h"
#include "KPD_interface.h"
#include "Stm32_F103C6_I2C_driver.h"
#include "I2C_Slave_EEPROM.h"





int main(void)
{
	// Enable clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	// Test case (1)

	unsigned char ch1[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7};
	unsigned char ch2[7] = {0};


	EEPROM_Init();
	EEPROM_Write_MBytes(0xAF, ch1, 7);
	EEPROM_Read_Bytes(0xAF, ch2, 7);

	// Test case (2)
	ch1[0] = 0xA;
	ch1[1] = 0xB;
	ch1[2] = 0xC;
	ch1[3] = 0xD;


	EEPROM_Write_MBytes(0xFFF, ch1, 4);
	EEPROM_Read_Bytes(0xFFF, ch2, 4);


	while(1)
	{
	}
}



