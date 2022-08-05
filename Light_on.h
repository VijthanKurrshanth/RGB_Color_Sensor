/*
 * Light_on.h
 *
 * Created: 8/5/2022 2:11:11 PM
 *  Author: Gurru
 */ 


#ifndef LIGHT_ON_H_
#define LIGHT_ON_H_
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "config.h"

uint16_t red_light_on = 0;
uint16_t green_light_on = 0;
uint16_t blue_light_on = 0;

void light()
{
	if ((PIND & 1 << PIND7) == 0)
	{
		PORTB |= 1 << PORTB1;
		red_light_on = 1;
		_delay_ms(100);
	}
		
	else if ((PIND & 1 << PIND6) ==0)
	{
		PORTB |= 1 << PORTB2;
		green_light_on = 1;
		_delay_ms(100);
	}
	else if ((PIND & 1 << PIND5) ==0)
	{
		PORTB |= 1 << PORTB3;
		blue_light_on = 1;
		_delay_ms(100);
	}
	else
	{
		PORTB &= 0xF0;
	}
}


#endif /* LIGHT_ON_H_ */