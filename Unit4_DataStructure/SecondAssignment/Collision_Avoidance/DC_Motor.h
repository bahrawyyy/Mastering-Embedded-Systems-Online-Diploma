/*
 * DC_Motor.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Abdallah
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

enum{
	DC_idle,
	DC_busy
}DC_state_ID;

void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);


extern void (*DC_state)();


#endif /* DC_MOTOR_H_ */
