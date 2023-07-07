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

#define BUZZER 4  // Buzzer on D4

int main()
{

	// PORTD 0 As input, internal pull up activated
	CLR_BIT(DDRD,0);
	CLR_BIT(PORTD,0);

	// PORTD 4 As output (buzzer)
	SET_BIT(DDRD,BUZZER);

	// 7 Segments from C2 to C7 As output
	DDRC = 0xfc;

	u8 i,j;


	while(1)
	{
		// Reading pin 0 to turn a buzzer on
		if(GET_BIT(PIND,0) == 1){
			SET_BIT(PORTD,BUZZER);
			_delay_ms(1000);
			CLR_BIT(PORTD,BUZZER);
		}

		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				PORTC = (i<<4) | 0b1000;
				_delay_ms(30);
				PORTC = (j<<4) | 0b0100;
				_delay_ms(30);
			}

		}



	}

	return 0;

}

