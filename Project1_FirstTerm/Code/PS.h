#ifndef _PS_H
#define _PS_H

#include "state.h"

enum{
	HIGH_Pressure_Detection
}PS_State_ID;


// Prototypes
STATE_Define(HIGH_Pressure_Detection);


extern void (*PS_State)();



#endif