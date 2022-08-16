/*
 * Light_on.h
 * turning the 3 leds for ldr sensing
 * Created: 8/5/2022 2:11:11 PM
 *  Author: Gurru
 */ 


#ifndef LIGHT_ON_H_
#define LIGHT_ON_H_
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "config.h"

//variables for indicating led is lit
uint16_t red_light_on = 0;
uint16_t green_light_on = 0;
uint16_t blue_light_on = 0;


void light()
{
	if ((PIND & (1<<PIND2)) == 0) //detect input for red led
	{
		PORTB |= (1<<PORTB5); //lighting red led
		red_light_on = 1; //indicator for red led been lit
		_delay_ms(1000); //led lighting time
		PORTB &= 0x0F; //resetting led (turn off)
	}
		
	if ((PIND & (1<<PIND1)) ==0) //detect input for green led
	{
		PORTB |= (1<<PORTB6); //lighting green led
		green_light_on = 1; //indicator for green led been lit
		_delay_ms(1000); //led lighting time
		PORTB &= 0x0F; //resetting led (turn off)
	}
	
	if ((PIND & (1<<PIND0)) ==0) //detect input for blue led
	{
		PORTB |= (1<<PORTB7);
		blue_light_on = 1; //indicator for blue led been lit
		_delay_ms(1000); //led lighting time
		PORTB &= 0x0F; //resetting led (turn off)
	}
}

#endif /* LIGHT_ON_H_ */