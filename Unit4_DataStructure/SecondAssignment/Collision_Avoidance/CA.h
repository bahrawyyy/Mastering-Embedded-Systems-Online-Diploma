/*
 * CA.h
 *
 *  Created on: Mar 9, 2023
 *      Author: Abdallah
 */

#ifndef CA_H_
#define CA_H_


#include "state.h"

enum{
	CA_waiting,
	CA_driving
}State_id;

// Prototypes
STATE_define(CA_waiting);
STATE_define(CA_driving);

// To be seen in main.c which will include this file
extern void (*CA_state)();



#endif /* CA_H_ */
