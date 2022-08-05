/*
 * config.h
 *
 * Created: 8/5/2022 2:10:24 PM
 *  Author: Gurru
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_
#define F_CPU 16000000UL
#include <avr/io.h>

void port_config();


void port_config()
{
	DDRD = 0x0F;
	DDRB = 0xFF;
	PORTD = 0xF0;
	PORTB = 0x00;
}


#endif /* CONFIG_H_ */