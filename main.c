/*
 * LDR_Sensing_Part.c
 *
 * Created: 8/5/2022 2:09:17 PM
 * Author : Gurru
 */ 

#include "config.h"
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "sense_voltage.h"
#include "output.h"
#include "Light_on.h"
#include <avr/interrupt.h>

int main(void)
{
	port_config();
	sei();
	
	while (1)
	{
		light();
		if (red_light_on | green_light_on | blue_light_on)
		{
			output();
		}
		
	}
}

