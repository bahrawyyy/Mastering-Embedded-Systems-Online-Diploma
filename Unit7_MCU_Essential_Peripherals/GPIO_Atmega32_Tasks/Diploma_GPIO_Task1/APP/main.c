/*
 * main.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Abdallah
 */



#include "../MCAL/Registers.h"
#include "../LIB/Bit_Math.h"
#include "util/delay.h"

#define F_CPU 16000000UL

int main()
{
	DDRA = 0xff;   // All port A as output

	while(1)
	{
		SET_BIT(PORTA,0);
		_delay_ms(300);
		SET_BIT(PORTA,1);
		_delay_ms(300);
		SET_BIT(PORTA,2);
		_delay_ms(300);
		SET_BIT(PORTA,3);
		_delay_ms(300);
		SET_BIT(PORTA,4);
		_delay_ms(300);
		SET_BIT(PORTA,5);
		_delay_ms(300);
		SET_BIT(PORTA,6);
		_delay_ms(300);
		SET_BIT(PORTA,7);
		_delay_ms(300);
		CLR_BIT(PORTA,7);
		_delay_ms(300);
		CLR_BIT(PORTA,6);
		_delay_ms(300);
		CLR_BIT(PORTA,5);
		_delay_ms(300);
		CLR_BIT(PORTA,4);
		_delay_ms(300);
		CLR_BIT(PORTA,3);
		_delay_ms(300);
		CLR_BIT(PORTA,2);
		_delay_ms(300);
		CLR_BIT(PORTA,1);
		_delay_ms(300);
		CLR_BIT(PORTA,0);
		_delay_ms(300);

	}

	return 0;

}

