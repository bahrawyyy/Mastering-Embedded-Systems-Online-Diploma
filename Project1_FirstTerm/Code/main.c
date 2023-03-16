#include <stdint.h>
#include "driver.h"
#include "alarm.h"
#include "PS.h"
#include "psensor.h"

int main(void)
{
	GPIO_INITIALIZATION();
	PS_State = STATE(HIGH_Pressure_Detection);
	P_state = STATE(Preading);
	Alarm_Stat = STATE(AlarmOff);

	while (1)
	{
		//Implement your Design 
		P_state();
		PS_State();
		Alarm_Stat();

		Delay(500000);
	}
	return 0;
}
