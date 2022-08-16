/*
 * sense_voltage.h
 * converts the analog voltage input to a digital value
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

uint8_t ADC_O1; //variable to store value of higher 2 bits of converted digital output
uint16_t ADC_O2; //variable to store value of lower 8 bits of converted digital output
uint16_t ADC_O; //variable to store value of complete 10 bits of converted digital output

void set_adc()
{
	ADMUX = 0x40; //configuring ADC multiplexer selection register //voltage reference - AVcc //analog channel - ADC0
	ADCSRA = 0xCF; //configuring ADC control and status register A //ADC enable & start conversion //interrupt enable //prescaler division factor - 128
	ADCSRB = 0x00; //configuring ADC control and status register B //free running mode
	
}

ISR(ADC_vect) //interrupt service routine
{
	ADC_O1 = ADCL; //storing lower 8 bits of converted digital output
	ADC_O2 = ADCH; //storing higher 2 bits of converted digital output
	ADC_O = ADCL | ADCH << 8; //storing complete 10 bits of converted digital output
	ADCSRA |= 0x40; //resetting ADC to next conversion
}

uint16_t voltage()
{
	return ADC_O; //return value of complete 10 bits of converted digital output			
}

#endif /* SENSE_VOLTAGE_H_ */