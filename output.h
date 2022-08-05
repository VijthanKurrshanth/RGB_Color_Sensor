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
// 	if (ADC_O != 0)
// 	{
// 		PORTB |= 1 << PORTB4;
// 		_delay_ms(100);
// 	}

	if (volt > 0x2AA)
	{
		if (red_light_on)
		{
			PORTB |= 1 << PORTB4;
			_delay_ms(100);
			red_light_on = 0;
			
		}
		else if (green_light_on)
		{
			PORTB |= 1 << PORTB5;
			_delay_ms(100);
			green_light_on = 0;
			
		}
		else if (blue_light_on)
		{
			PORTB |= 1 << PORTB6;
			_delay_ms(100);
			blue_light_on = 0;
			
		}
	}
	else if ((volt <= 0x2AA) & (volt >= 0x155))
	{
		if (red_light_on)
		{
			PORTB |= 1 << PORTB4;
			red_light_on = 0;
			_delay_ms(100);
		}
		else if (green_light_on)
		{
			PORTB |= 1 << PORTB5;
			green_light_on = 0;
			_delay_ms(100);
		}
		else if (blue_light_on)
		{
			PORTB |= 1 << PORTB6;
			blue_light_on = 0;
			_delay_ms(100);
		}
	}
	else if (volt < 0x155)
	{
		PORTB = 0x00;
		_delay_ms(100);
	}
	PORTB &= 0xF0;
}



#endif /* OUTPUT_H_ */