/*
 * config.h
 * pin configurations
 * Created: 8/5/2022 2:10:24 PM
 *  Author: Gurru
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_
#define F_CPU 1000000UL
#include <avr/io.h>

void port_config();


void port_config()
{
	DDRD |= (1<<PIND6) | (1<<PIND5) | (1<<PIND3); //configuring output pins of D
	DDRB |= (1<<PINB7) | (1<<PINB6) | (1<<PINB5) | (1<<PINB2); //configuring output pins of B
	PORTD |= (1<<PIND0) | (1<<PIND1) | (1<<PIND2); //configuring input pins of D
}


#endif /* CONFIG_H_ */