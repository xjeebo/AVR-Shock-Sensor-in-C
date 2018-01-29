#define F_CPU 8000000	// Clock Speed
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void settings();				// Settings and configurations

int main( )
{
	settings();
	_delay_ms(1);
	sei();  // set enable interrupts
	while (1);
	return 0;
}

void settings(){


	DDRD  |= (0 << PORTD2)|(1 << PORTD7);	   // set pd2 and pd3 as input
	PORTD |= (1 << PORTD2)|(0 << PORTD7);   // port2 and 3 pull up enabled pd7 is an LED initialy turned off
	// LED is connected to portd7 to light up when a shock has occured
	EICRA |= (1<<ISC00);
	EIMSK |= (1<<INT0);
	
}


ISR(INT0_vect ){
	_delay_ms(100);
	PORTD ^= (1<< PORTD7);// LED indication whether the key is being sustained
	_delay_ms(100);
	PORTD ^= (1<< PORTD7);// LED indication whether the key is being sustained
	_delay_ms(100);
	PORTD ^= (1<< PORTD7);// LED indication whether the key is being sustained
}
