/*
 * sense_voltage.h
 *
 * Created: 8/5/2022 2:12:44 PM
 *  Author: Gurru
 */ 


#ifndef SENSE_VOLTAGE_H_
#define SENSE_VOLTAGE_H_
#include <avr/io.h>
#include <stdint.h>
#include "config.h"
#include <avr/interrupt.h>

void set_adc();
uint16_t voltage();

uint8_t ADC_O1;
uint16_t ADC_O2;
uint16_t ADC_O;

void set_adc()
{
	ADMUX = 0x40;
	ADCSRA = 0xCF;
	ADCSRB = 0x00;
}


ISR(ADC_vect)
{
	ADC_O1 = ADCL;
	ADC_O2 = ADCH;
	ADC_O = ADCL | ADCH << 8;
	ADCSRA |= 0x40;
}

uint16_t voltage()
{
	return ADC_O;				
}



#endif /* SENSE_VOLTAGE_H_ */