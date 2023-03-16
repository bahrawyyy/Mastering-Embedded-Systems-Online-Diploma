#ifndef _ALARM_H_
#define _ALARM_H_

#include "state.h"

enum{
	AlarmOff,
	AlarmOn,
	waiting,
}Alarm_State_ID;


STATE_Define(AlarmOff);
STATE_Define(AlarmOn);
// STATE_Define(waiting);

extern void (*Alarm_Stat)();



#endif