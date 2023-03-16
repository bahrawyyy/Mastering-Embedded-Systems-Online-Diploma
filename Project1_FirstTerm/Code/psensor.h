#ifndef _P_SENSOR_H_
#define _P_SENSOR_H_


#include "driver.h"
#include "state.h"

enum{
	Preading,
	Pwaiting
}P_State_ID;


STATE_Define(Preading);
STATE_Define(Pwaiting);

// Pointer to function
extern void (* P_state)();



#endif
