/*
 * US_Sensor.c
 *
 *  Created on: Mar 10, 2023
 *      Author: Abdallah
 */


#include "US_Sensor.h"
#include <stdlib.h>
#include <stdio.h>

int US_Get_distance_random(int low, int range, int count);


extern void (*US_state)();


// Module Variables
unsigned int distance = 0;



void US_init()
{
	// init US sensor
	// Call the US Driver or Functions
	printf("DC_init\n");
}


STATE_define(US_busy)
{
	// State Action
	US_state_id = US_busy;

	// Read from US
	distance = US_Get_distance_random(45,55,1);
	// -------------------------
	printf("US_busy state : distance = %d\n",distance);



	US_distance_Set(distance);
	US_state = STATE(US_busy);

}


int US_Get_distance_random(int l , int r , int count)
{
	int i,rand_distance=0;
	for(i=0;i<count;i++)
	{
		rand_distance = (rand() % (r - l + 1)) + l;
		return rand_distance;
	}
	return rand_distance;
}







