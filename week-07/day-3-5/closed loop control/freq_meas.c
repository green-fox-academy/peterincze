/*
 * freq_meas.c
 *
 * Created: 2017. 06. 13. 11:30:56
 *  Author: Peeter
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

uint8_t ovf_counter = 0;
uint8_t ovf_counter2 = 0;
uint16_t first_value = 0;
uint16_t sec_value = 0;

// TODO:
// Write the interrupt handlers

ISR(TIMER1_OVF_vect)
{
	ovf_counter++;
}
	
ISR(TIMER1_CAPT_vect)
{
	first_value = sec_value;
	ovf_counter2 = ovf_counter;
	ovf_counter = 0;
	sec_value = TCNT1;
}

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
	TCCR1B |= (1 << CS12) | (1 << ICES1) | (1 << ICNC1);
	TIMSK1 |= (1 << TOIE0) | (1 << ICIE1);
	sei();
}

// TODO:
// Write this function. It returns the measured frequency in Hz
float get_freq()
{
		// 256/16 000 00 = 0.000016
	float freq = ((1 /( 0.000016 * ((ovf_counter2 * 65535) + sec_value - first_value))) / 7);
	return freq;
}