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
 * Update: Edited to be used in ARM CPU MODES lecture.
 *
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "core_cm3.h"

#include "Stm32_F103C6_gpio_driver.h"
#include "Stm32_F103C6_EXTI_driver.h"
#include "stm32f103c6.h"
#include "Lcd.h"
#include "KPD_interface.h"

#include "Schedular.h"

#include "string.h"


// Remember the modifications in the linkersript



Task_Config Task1, Task2, Task3, Task4, Task5, Task6;

uint8_t Task1Indication,Task2Indication,Task3Indication,Task4Indication,Task5Indication,Task6Indication;

Mutex_Config Mutex1,Mutex2;


void task1()
{
	static int counter1 = 0;
	while(1){
		// Task1 Code
		Task1Indication ^= 1;
		counter1++;
		if(counter1 == 100){
			MYRTOS_AcquireMutex(&Mutex1, &Task1);
			MYRTOS_Activate_Task(&Task2);
		}
		if(counter1 == 200)
		{
			counter1 = 0;
			MYRTOS_ReleaseMutex(&Mutex1);
		}
	}
}

void task2()
{
	static int counter1 = 0;
	while(1){
		// Task1 Code
		Task2Indication ^= 1;
		counter1++;
		if(counter1 == 100){
			MYRTOS_Activate_Task(&Task3);
		}
		if(counter1 == 200)
		{
			MYRTOS_Terminate_Task(&Task2);
			counter1 = 0;

		}
	}
}

void task3()
{
	static int counter1 = 0;
	while(1){
		// Task1 Code
		Task3Indication ^= 1;
		counter1++;
		if(counter1 == 100){
			MYRTOS_Activate_Task(&Task4);
		}
		if(counter1 == 200)
		{
			MYRTOS_Terminate_Task(&Task3);
			counter1 = 0;

		}
	}
}

void task4()
{
	static int counter1 = 0;
	while(1){
		// Task1 Code
		Task4Indication ^= 1;
		counter1++;
		if(counter1 == 3)
		{
			MYRTOS_AcquireMutex(&Mutex1, &Task4);
		}
		if(counter1 == 100){
			MYRTOS_ReleaseMutex(&Mutex1);
			MYRTOS_Terminate_Task(&Task4);
			counter1 = 0;
		}
	}
}



void task5()
{
	static int counter1 = 0;
	while(1){
		// Task1 Code
		Task5Indication ^= 1;
		counter1++;
		if(counter1 == 100){
			MYRTOS_AcquireMutex(&Mutex1, &Task5);
			MYRTOS_Activate_Task(&Task6);
			MYRTOS_AcquireMutex(&Mutex2, &Task5);

		}
		if(counter1 == 200)
		{
			MYRTOS_ReleaseMutex(&Mutex1);

		}
		if(counter1 == 300){
			MYRTOS_ReleaseMutex(&Mutex2);
			counter1 = 0;

		}
	}
}


void task6()
{
	static int counter1 = 0;
	MYRTOS_AcquireMutex(&Mutex2, &Task6);
	while(1){
		// Task1 Code
		Task6Indication ^= 1;
		counter1++;
		if(counter1 == 3)
		{
			MYRTOS_AcquireMutex(&Mutex1, &Task6);
		}
		if(counter1 == 100){
			MYRTOS_ReleaseMutex(&Mutex2);
			MYRTOS_Terminate_Task(&Task6);
		}
		if(counter1 == 400)
		{
			MYRTOS_ReleaseMutex(&Mutex2);
			counter1 = 0;

		}
	}
}

uint8_t payload[3] = {1,2,3};

uint8_t payload2[3] = {1,2,3};

int main(void)
{
	MYRTOS_errorID Error = NO_ERROR;
	// HW_Init	(Initialize clockTree, ResetController)
	HW_Init();


	strcpy(Mutex1.MutexName,"Mutex T1,T4");
	Mutex1.Payload_Size = 3;
	Mutex1.P_Payload = payload;





	if(MYRTOS_Init() != NO_ERROR)
		while(1);


	// Create tasks
	Task1.Stack_Size = 1024;   // 1kByte
	Task1.P_TaskEntry = task1;
	Task1.Priority = 4;
	strcpy(Task1.TaskName, "task_1");

	Task2.Stack_Size = 1024;   // 1kByte
	Task2.P_TaskEntry = task2;
	Task2.Priority = 3;
	strcpy(Task2.TaskName, "task_2");

	Task3.Stack_Size = 1024;   // 1kByte
	Task3.P_TaskEntry = task3;
	Task3.Priority = 2;
	strcpy(Task3.TaskName, "task_3");

	Task4.Stack_Size = 1024;   // 0.5kByte
	Task4.P_TaskEntry = task4;
	Task4.Priority = 1;   // The highest priority among all tasks
	strcpy(Task4.TaskName, "task_4");


	// Scenario: Task5 with lower priority will acquire the mutex
	// Task6 with a higher priority will ask for the mutex
	// But it is not released yet
	// Task5 will inherit Task6 Priority to prevent priority inversion condition


	Task5.Stack_Size = 1024;   // 1kByte
	Task5.P_TaskEntry = task5;
	Task5.Priority = 4;
	strcpy(Task5.TaskName, "task_5");


	Task6.Stack_Size = 1024;   // 1kByte
	Task6.P_TaskEntry = task6;
	Task6.Priority = 2;   // The highest priority among all tasks
	strcpy(Task6.TaskName, "task_6");

//	Error += MYRTOS_Create_Task(&Task1);
//	Error += MYRTOS_Create_Task(&Task2);
//	Error += MYRTOS_Create_Task(&Task3);
//	Error += MYRTOS_Create_Task(&Task4);

	Error += MYRTOS_Create_Task(&Task5);
	Error += MYRTOS_Create_Task(&Task6);

//	MYRTOS_Activate_Task(&Task1);
	//	MYRTOS_Activate_Task(&Task2);
	//	MYRTOS_Activate_Task(&Task3);

	MYRTOS_Activate_Task(&Task5);
	//	MYRTOS_Activate_Task(&Task6);


	MYRTOS_START_OS();

	while(1)
	{



	}
}



