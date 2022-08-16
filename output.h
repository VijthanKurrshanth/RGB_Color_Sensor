/*
 * output.h
 * calculates the pwm value according to the sensed ldr light intesity
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

int output()
{
	uint16_t volt = voltage(); //get the current voltage value in digital form
	volt = volt / 1023.0 * 255.0; //calculating the pwm duty cycle according to the voltage
	return volt;	
}

#endif /* OUTPUT_H_ */