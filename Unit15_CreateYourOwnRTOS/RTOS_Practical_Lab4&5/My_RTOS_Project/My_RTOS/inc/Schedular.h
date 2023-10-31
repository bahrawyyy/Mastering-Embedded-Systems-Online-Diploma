/*
 * Schedular.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Abdallah
 */

#ifndef INC_SCHEDULAR_H_
#define INC_SCHEDULAR_H_

#include "CortexMxOS_Porting.h"
//#include "My_RTOS_FIFO.h"


typedef enum
{
	NO_ERROR,
	ReadyQueue_Init_Error,
	Task_Exceeded_Stack_Size,
	MutexReachedMaximumNumber,
	Mutex_Prevent_Deadlock

}MYRTOS_errorID;


typedef struct{
	uint32_t Stack_Size;		// Entered by the user
	uint8_t Priority;
	void (*P_TaskEntry)(void);   // A pointer to the C function that this task is linked to
	uint32_t _S_PSP_Task;    // Start of this task stack (Not entered by the user, calculate by OS)
	uint32_t _E_PSP_Task;	  // (Not entered by the user)
	uint32_t *Current_PSP;    // Current_PSP points to the location that currently pointed by PSP of this task (Not entered by the user)
	char TaskName[30];    // Useful in debugging
	enum{
		Suspend,
		Waiting,
		Ready,
		Running
	}Task_State;   				// (Not entered by the user)


	struct{
		enum{
			Blocking_Disable,
			Blocking_Enable
		}Block_Timing;
		uint32_t Ticks_Count;   // Blocked in suspend state
	}Time_Waiting;
}Task_Config;


typedef struct{
	char MutexName[30];
	Task_Config * currentTask;
	Task_Config * nextTask;
	uint8_t *P_Payload;   // For data exchange
	uint8_t Payload_Size;
	uint8_t Main_TaskPriority;
}Mutex_Config;


// APIs
MYRTOS_errorID MYRTOS_Init(void);
MYRTOS_errorID MYRTOS_Create_Task(Task_Config* taskReference);
MYRTOS_errorID MYRTOS_Activate_Task(Task_Config* taskReference);
MYRTOS_errorID MYRTOS_Terminate_Task(Task_Config* taskReference);
MYRTOS_errorID MYRTOS_Task_Wait(uint32_t TicksNum, Task_Config* taskReference);

MYRTOS_errorID MYRTOS_AcquireMutex(Mutex_Config *Mutex, Task_Config* taskReference);
MYRTOS_errorID MYRTOS_ReleaseMutex(Mutex_Config *Mutex);


void MYRTOS_START_OS(void);




#endif /* INC_SCHEDULAR_H_ */
