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

uint16_t voltR = 0;
uint16_t voltG = 0;
uint16_t voltB = 0;

int main(void)
{
	port_config(); //configure ports
	sei(); //enable global interrupts
	
	//variables to check whether the color is already sensed
	uint16_t sensed_r = 0; 
	uint16_t sensed_g = 0;
	uint16_t sensed_b = 0;
	
	while (1)
	{
		light(); //enabling to turn on led lights
		set_adc(); //initialize adc
		
		if (red_light_on & ~sensed_r)
		{
			voltR = output(); //store ldr intensity of red led reflections
			sensed_r = 1;
		}
		
		if (green_light_on & ~sensed_g)
		{
			voltG = output(); //store ldr intensity of green led reflections
			sensed_g = 1;
		}

		if (blue_light_on & ~sensed_b)
		{
			voltB = output(); //store ldr intensity of blue led reflections
			sensed_b = 1;
		}
				
		if (sensed_r & sensed_g & sensed_b) //check whether all three intensities are sensed
		{
			break; //break out of while loop
		}
	}
	
	//pwm signal output to the red input of rgb led
	OCR0A = voltR;
	TCCR0A |= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00);	//Non-Inverting Fast PWM mode 7
	TCCR0B |= (1<<CS00);	//No-Prescaler
	
	//pwm signal output to the green input of rgb led
	OCR0B = voltG;
	TCCR0A |= (1<<COM0B1) | (1<<WGM01) | (1<<WGM00);	//Non-Inverting Fast PWM mode 7
	TCCR0B |= (1<<CS00);	//No-Prescaler
	
	//pwm signal output to the blue input of rgb led
	OCR2B = voltB;
	TCCR2A |= (1<<COM2B1) | (1<<WGM21) | (1<<WGM20);	//Non-Inverting Fast PWM mode 7
	TCCR2B |= (1<<CS20);	//No-Prescaler
}

