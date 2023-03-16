#include "alarm.h"
#include "driver.h"

int AlarmVal;

void (*Alarm_Stat)();

void High_Pressure_Detect(int Val)
{
    AlarmVal = Val;  // 1
    if(AlarmVal == 1){
        Alarm_Stat = STATE(AlarmOn);
    }else if(AlarmVal == 0){
        Alarm_Stat = STATE(AlarmOff);
    }
}

STATE_Define(AlarmOff)
{
    Alarm_State_ID = AlarmOff;
    Set_Alarm_actuator(1);
}

STATE_Define(AlarmOn)
{
    Alarm_State_ID = AlarmOn;
    Set_Alarm_actuator(0);;
}
