#include "psensor.h"


void (* P_state)();

// Module Variables
int PressureVal = 0;

STATE_Define(Preading)
{
	// State Action
	P_State_ID = Preading;


	// Read from Pressure Sensor
	PressureVal = getPressureVal(); // 23

	// Send the read value to the main algorithm
	SET_Pressure_Val(PressureVal);

	// Go to The waiting state
	P_state = STATE(Pwaiting);
}

STATE_Define(Pwaiting)
{
	// Wait here for 100 msec
	Delay(200000);
	P_state = STATE(Preading);
}