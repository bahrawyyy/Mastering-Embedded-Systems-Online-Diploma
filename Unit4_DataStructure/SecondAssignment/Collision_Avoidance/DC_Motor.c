/*
 * DC_Motor.c
 *
 *  Created on: Mar 10, 2023
 *      Author: Abdallah
 */

#include "DC_Motor.h"

unsigned int Sspeed = 0;

void (*DC_state)();


void DC_init()
{

	// init DC
	printf("DC_init\n");
}

void DC_Motor_SetSpeed(int speed)
{
	Sspeed = speed;
	DC_state_ID = DC_idle;
	DC_state = STATE(DC_busy);

	printf("DC_idle state : speed = %d \n \n",Sspeed);
}

STATE_define(DC_idle)
{
	DC_state_ID = DC_idle;

	printf("DC_idle state : speed = %d \n \n \n",Sspeed);
}

STATE_define(DC_busy)
{
	DC_state_ID = DC_busy;
	DC_state = STATE(DC_idle);

	printf("DC_busy state : speed = %d \n \n \n",Sspeed);
}








