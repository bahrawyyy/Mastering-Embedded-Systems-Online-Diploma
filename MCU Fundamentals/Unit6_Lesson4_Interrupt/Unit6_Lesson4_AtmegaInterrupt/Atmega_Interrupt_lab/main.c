/*
 * main.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Abdallah
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	// Enabling interrupts
	GICR |= (1<<7 | 1<<6 | 1<<5);

	// Configuring interrupts as falling, rising ,and falling
	MCUCR |= (1<<0 | 1<<2 | 1<<3);
	MCUCR &= ~(1<<1);
	MCUCSR &= ~(1<<6);


	// Enabling global interrupt
	sei();


	// Setting LED pins as output
	DDRD |= (1<<5) | (1<<6) | (1<<7) ;

	while(1)
	{
		PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ;
		_delay_ms(1000);
	}



	return 0;
}



ISR(INT0_vect)
{
	PORTD |= (1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
}
