/*
 * Schedular.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Abdallah
 */


#include "Schedular.h"
#include "My_RTOS_FIFO.h"

#include "string.h"


FIFO_Buffer_t ReadyQueue;
Task_Config *ReadyQueueFIFO[100];

Task_Config MYRTOS_IdleTask;


// OS states (in .c not .h to not being seen by the user)

struct{
	Task_Config* OS_Tasks[100];  // Tasks(schedular) table (Can hold up to 100 tasks)
	uint32_t _S_MSP;   // Pointed to the start of the SRAM (From startup)
	uint32_t _E_MSP;   // Then this will act as the size of the stack
	uint32_t PSP_Task_Locator;
	uint32_t ActiveTasksNum;
	Task_Config* CurrentTaskExecuted;
	Task_Config* NextTaskTobeExecuted;
	enum{
		OS_Suspend,
		OS_Running
	}OS_Modes_ID;
}OS_Control;






// To execute specific OS service
void OS_SVC_Services(int* StackFramePointer)
{
	// OS_SVC_Set stack --> r0 = argument 0 = StackFramePointer
	// OS_SVC_Set stack --> r0,r1,r2,r3,r12,lr,pc,xpsr

	unsigned char SVC_Number;

	SVC_Number = *((unsigned char*)(((unsigned char*)StackFramePointer[6]) - 2));


	switch(SVC_Number)
	{
	case 0:  // Activate task
		break;

	case 1:	// Terminate task
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;
	}

}


int OS_SVC_Set(int SVC_ID)
{
	switch(SVC_ID){
	case 0:  // Activate task
		__asm("svc #0x01");
		break;

	case 1:  // Terminate task
		__asm("svc #0x02");
		break;

	case 2:  //
		__asm("svc #0x03");
		break;

	case 3:  //
		__asm("svc #0x04");
		break;

	}
}


// Will be used in context switching
void PendSV_Handler()
{

}


void MYRTOS_Create_MainStack()
{
	OS_Control._S_MSP = &_estack;
	OS_Control._E_MSP = OS_Control._S_MSP - MainStackSize;
	// Align 8 Bytes space between Main stack and Process stack
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP - 8);
}


void MyRTOS_Idle_Task()
{
	while(1)
	{
		__asm("NOP");
	}
}



MYRTOS_errorID MYRTOS_Init()
{
	MYRTOS_errorID ErrorState = NO_ERROR;

	// Update OS Mode (Suspend)
	OS_Control.OS_Modes_ID = OS_Suspend;

	// Specify the Main stack for the OS
	MYRTOS_Create_MainStack();



	// Create OS Ready Queue
	if((FIFO_Init(&ReadyQueue, ReadyQueueFIFO, 100)) != FIFO_No_Error)
		ErrorState += ReadyQueue_Init_Error;


	// Configure idle task
	strcpy(MYRTOS_IdleTask.TaskName,"idleTask");
	MYRTOS_IdleTask.Priority = 255;    // The least priority
	MYRTOS_IdleTask.P_TaskEntry = MyRTOS_Idle_Task;
	MYRTOS_IdleTask.Stack_Size = 300;  // Bytes

	ErrorState += MYRTOS_Create_Task(&MYRTOS_IdleTask);

	return ErrorState;
}


void MYRTOS_Create_Stack(Task_Config* taskReference)
{
	/** Task Frame
	 * 	//// (Automatically pushed by processor)
	 * 	- xpsr
	 * 	- pc (next instrcution to be executed to this task)
	 * 	- lr (Return register which is saved in cpu while task running before switching)
	 * 	- r12
	 * 	- r4
	 * 	- r3
	 * 	- r2
	 * 	- r1
	 * 	- r0
	 *
	 * 	//// (Manually defined to save the value of registers (Manually pushed and restored))
	 * 	r5, r6, r7, r8, r9, r10, r11
	 */
	taskReference->Current_PSP = taskReference->_S_PSP_Task;

	taskReference->Current_PSP--;
	*(taskReference->Current_PSP) = 0x01000000;  // Dummy psr (by default T=1 Thumb2) to avoid bus fault

	taskReference->Current_PSP--;
	*(taskReference->Current_PSP) = (unsigned int)(taskReference->P_TaskEntry);   // PC value

	taskReference->Current_PSP--;
	*(taskReference->Current_PSP) = (unsigned int)(0xFFFFFFFD);   // (Dummy value)As if LR (This function came from interrupt

	// The rest is 13 registers we want to push with 0 for now
	for(int j=0;j<13;j++)
	{
		taskReference->Current_PSP--;
		*(taskReference->Current_PSP) = 0;
	}
}



MYRTOS_errorID MYRTOS_Create_Task(Task_Config* taskReference)
{
	MYRTOS_errorID ErrorState = NO_ERROR;

	// Create its own PS Stack
	taskReference->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	taskReference->_E_PSP_Task = taskReference->_S_PSP_Task -  taskReference->Stack_Size;

	// Check that task size isn't exceeding Process stack size
	if(taskReference->_E_PSP_Task < (uint8_t)(&_eheap))
		return Task_Exceeded_Stack_Size;

	// Align 8 Byte for the next task PS stack
	OS_Control.PSP_Task_Locator = taskReference->_E_PSP_Task - 8;

	// - _S_PSP_Task
	// - Task stack
	// - _E_PSP_Task

	// - _eheap


	// Initialize PS Task Stack
	MYRTOS_Create_Stack(taskReference);

	// Task state update (Suspend mode)
	taskReference->Task_State = Suspend;

	return ErrorState;

}
