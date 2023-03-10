/*
 * state.h
 *
 *  Created on: Mar 9, 2023
 *      Author: Abdallah
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

// To be used in further blocks and states
#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_


// States Connections
void US_distance_Set(int distance);
void DC_Motor_SetSpeed(int speed);




#endif /* STATE_H_ */
