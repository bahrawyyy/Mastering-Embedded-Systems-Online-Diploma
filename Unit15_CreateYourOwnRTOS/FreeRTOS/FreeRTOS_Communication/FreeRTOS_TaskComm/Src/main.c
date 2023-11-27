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

#include "Stm32_F103C6_gpio_driver.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "semphr.h"


// Task1(Master) send some commands to task2(Slave) via queue


// Handles

TaskHandle_t vTaskMasterHandle = NULL;
TaskHandle_t vTaskSlaveHandle = NULL;

QueueHandle_t xQueHandle = NULL;


// Tasks Prototypes
void vTaskMasterHandler(void * params);
void vTaskSlaveHandler(void * params);





void HW_INIT(void)
{
	// Led as actuator to the command sent by the master
	// Initialize Output pin (Led) --> Pin13
	GPIO_PinConfig_t PIN13CFG;
	PIN13CFG.GPIO_PinNumber = GPIO_PIN_13;
	PIN13CFG.GPIO_MODE = GPIO_MODE_OUTPUT_PUSHPULL;
	PIN13CFG.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOC, &PIN13CFG);

}



int main(void)
{
	RCC_GPIOC_CLK_EN();
	HW_INIT();

	// Tasks Creation
	xTaskCreate(vTaskMasterHandler, "Master generate commands", 128, NULL, 1, &vTaskMasterHandle);
	xTaskCreate(vTaskSlaveHandler, "Slave execute commands", 128, NULL, 2, &vTaskSlaveHandle);

	// 10 elements of integers
	xQueHandle = xQueueCreate(10 , sizeof(uint8_t));


	vTaskStartScheduler();



	while(1)
	{

	}


	return 0;
}



// Generate commands
void vTaskMasterHandler(void * params)
{
	uint8_t ON_Command = 1;
	uint8_t OFF_Command = 0;

	while(1)
	{
		// This 5 means that if you couldn't send to the queue in 5 ticks then skip this line
		xQueueSend(xQueHandle,&OFF_Command, (TickType_t)5);
		vTaskDelay(10);
		xQueueSend(xQueHandle,&ON_Command, (TickType_t)5);
		vTaskDelay(10);
	}
}

// Take actions corresponding to the commands sent by the master task
void vTaskSlaveHandler(void * params)
{
	uint8_t receivedCommand = 0;

	while(1)
	{
		if(xQueueReceive(xQueHandle, &receivedCommand, (TickType_t)5) == pdTRUE)
		{
			if(receivedCommand == 0)
			{
				MCAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_LOW);
			}else if(receivedCommand == 1){
				MCAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_HIGH);
			}
			vTaskDelay(10);
		}

	}
}