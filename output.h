/*
 * output.h
 *
 * Created: 8/5/2022 2:12:03 PM
 *  Author: Gurru
 */ 


#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <avr/io.h>
#include <stdint.h>
#include "sense_voltage.h"
#include "light_on.h"
#include "config.h"

void output()
{
	set_adc();
	uint16_t volt = voltage();

	if (volt > 683)
	{
		if (red_light_on)
		{
			PORTB |= 1 << PORTB4;
			PORTD |= 1 << PORTD3;
			_delay_ms(100);
			red_light_on = 0;
			
		}
		else if (green_light_on)
		{
			PORTB |= 1 << PORTB5;
			PORTD |= 1 << PORTD2;
			_delay_ms(100);
			green_light_on = 0;
			
		}
		else if (blue_light_on)
		{
			PORTB |= 1 << PORTB6;
			PORTD |= 1 << PORTD1;
			_delay_ms(100);
			blue_light_on = 0;
			
		}
	}
	else if ((volt <= 683) & (volt >= 341))
	{
		if (red_light_on)
		{
			PORTD |= 1 << PORTD3;
			red_light_on = 0;
			_delay_ms(100);
		}
		else if (green_light_on)
		{
			PORTD |= 1 << PORTD2;
			green_light_on = 0;
			_delay_ms(100);
		}
		else if (blue_light_on)
		{
			PORTD |= 1 << PORTD1;
			blue_light_on = 0;
			_delay_ms(100);
		}
	}
	else if (volt < 341)
	{
		PORTB = 0x00;
		PORTD &= 0xF0;
		_delay_ms(100);
	}
	
	PORTB &= 0x0F;
	PORTD &= 0xF0;
}



#endif /* OUTPUT_H_ */