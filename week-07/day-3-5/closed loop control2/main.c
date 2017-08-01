/*
 * projekt.c
 *
 * Created: 2017. 06. 14. 13:04:16
 * Author : Peeter
 */ 

 #define F_CPU	16000000

#include "freq_meas.h"
#include "UART_driver.h"
#include "ADC_driver.h"
#include "PWM_driver.h"
#include "AC_driver.h"

#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>


void system_init()
{
	ADC_init();
	UART_init();
	freq_meas_init();
	pwm_init();
	AC_driver_init();
	sei();

	// Enable interrupts globally, UART uses interrupts
}


int main(void)
{

	
	system_init();

	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;


	printf("start....\n\r");
	/* Replace with your application code */
	char speed[256];
	int speedvalue;
	//speed_percent(50);
	OCR2A = 255;
	_delay_ms(200);
	uint8_t ctrler_out_min = 0;
	uint8_t ctrler_out_max = 5000;
	float integral = 1;
	float err = 0;
	float ctrler_out = 0;
	float p = 0.05;
	float i = 0.01;

	while (1)
	{
		//OCR2A = ADC_read() / 4;
		float ref = ADC_read() * 4.88;
		float process_variable = get_rpm(); // 19.6 ;
		err = ref - process_variable;
		integral = integral + err;
		ctrler_out = p * err + i * integral;

		if (ctrler_out < ctrler_out_min) {
			OCR2A = ctrler_out_min;
			integral = integral - err;
			}
		else if (ctrler_out > ctrler_out_max) {
			OCR2A = ctrler_out_max;
			integral = integral - err;
			}



// 		printf("The value is in %%: ");
// 		gets(speed);
// 		if (UDR0 != 0)
// 		{
// 			speedvalue = atoi(speed);
// 			printf("%d  %%\n", speedvalue);
// 			speed_percent(speedvalue);
// 		}
// 		_delay_ms(5000);
		
		printf("%.f integral   ", integral);
		printf("%.f Hz   ", get_freq());
		printf("%.f RPM   ", get_rpm());
		printf("%.f error   ", err);
		printf("%.f ref\n", ref);
		_delay_ms(10);
		
	}
}