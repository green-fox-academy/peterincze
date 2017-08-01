/*
 * ADC_driver.h
 *
 * Created: 2017. 06. 12. 12:44:21
 *  Author: Peeter
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdint.h>

#define ADC_CH			0		// Using channel 0
#define ADC_ADPS		0b111	// Clock prescaler is 128
#define ADC_DATA_MAX	1023	// Maximum of ADC result (2^10 - 1)

void ADC_init();
uint16_t ADC_read();



#endif /* ADC_DRIVER_H_ */