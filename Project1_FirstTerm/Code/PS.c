#include "PS.h"

// Pointer to function
void (*PS_State)();


// Variables
int PS_PressureVal = 0;
int Threshold = 20;


void SET_Pressure_Val(int PressureVal)
{
	PS_PressureVal = PressureVal; // 23
	PS_State = STATE(HIGH_Pressure_Detection);
	// printf("PS ------ Pressure = %d ------ \n",PS_PressureVal);
}


STATE_Define(HIGH_Pressure_Detection)
{
	PS_State_ID = HIGH_Pressure_Detection;

	if(PS_PressureVal > Threshold)
	{
		High_Pressure_Detect(1);
	}else{
		High_Pressure_Detect(0);
	}

	PS_State = STATE(HIGH_Pressure_Detection);
}
