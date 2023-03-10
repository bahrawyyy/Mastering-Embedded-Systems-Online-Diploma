/*
 * main.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Abdallah
 */

#include "CA.h"
#include "US_Sensor.h"
#include "DC_Motor.h"




void setup()
{
	// Init all drivers
	// Init Interrupts
	// Init HAL  US and DC_Driver
	// Init Block
	US_init();
	DC_init();
	// Set states pointers for each block
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
	CA_state = STATE(CA_waiting);
}

int main()
{
	setup();

	while(1)
	{
		// Call state for each block
		US_state();
		CA_state();
		DC_state();
		// Doesn't this make an overload (Overflow) ?
		// Stack of waiting --> stack of driving --> ..
		// Overflow won't happen, why ?
		// When we put the address of the function inside the pointer, it doesn't mean calling it
		// It will run and after it prints, its stack will be deleted

	}




	return 0;
}
