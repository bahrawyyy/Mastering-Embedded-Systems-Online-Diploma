/*
 * main.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Abdallah
 */



#include "../MCAL/Registers.h"
#include "../LIB/Bit_Math.h"
#include "../LIB/STD_Types.h"
#include "util/delay.h"

#define F_CPU 16000000UL

int main()
{
	// All port A as output
	DDRA = 0xff;
	// PORTB 0 As input, internal pull up activated
	DDRB = 0x00;
	PORTB = 0x01;
	// Flag to be used when switching between LEDs
	u8 flag = 0;

	while(1)
	{
		// Reading pin 0
		if(GET_BIT(PINB,0) == 0){
			flag++;
			// Stay here until the user stop pressing
			while(GET_BIT(PINB,0) == 0);
		}

		switch(flag){
		case 1:
			SET_BIT(PORTA,0);
			break;
		case 2:
			SET_BIT(PORTA,1);
			break;
		case 3:
			SET_BIT(PORTA,2);
			break;
		case 4:
			SET_BIT(PORTA,3);
			break;
		case 5:
			SET_BIT(PORTA,4);
			break;
		case 6:
			SET_BIT(PORTA,5);
			break;
		case 7:
			SET_BIT(PORTA,6);
			break;
		case 8:
			SET_BIT(PORTA,7);
			break;
		default:;
		}

	}

	return 0;

}

