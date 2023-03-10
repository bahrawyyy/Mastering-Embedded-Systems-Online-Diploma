/*
 * US_Sensor.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Abdallah
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"

enum{
	US_busy
}US_state_id;

// Prototypes
void US_init();
STATE_define(US_busy);

// global pointer to function
void (*US_state)();

#endif /* US_SENSOR_H_ */
