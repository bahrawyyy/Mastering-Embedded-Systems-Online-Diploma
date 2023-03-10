/*
 * CA.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Abdallah
 */

#include "CA.h"


// Variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


// Pointer to function
void (*CA_state)();

void US_distance_Set(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US ------ Distance = %d ----->\n",CA_distance);
}



STATE_define(CA_waiting)
{
	// State Name
	State_id = CA_waiting;

	// State Action
	// DC_MOTOR(SPEED)
	CA_speed = 0;
	printf("CA_waiting : distance = %d Speed = %d",CA_distance,CA_speed);
	DC_Motor_SetSpeed(CA_speed);

}

STATE_define(CA_driving)
{
	// State Name
	State_id = CA_driving;

	// State Action
	// DC_MOTOR(SPEED)
	CA_speed = 30;
	printf("CA_driviing : distance = %d Speed = %d",CA_distance,CA_speed);
	DC_Motor_SetSpeed(CA_speed);


	// Event Check
	// US_Get_Distance(CA_distance)
}
