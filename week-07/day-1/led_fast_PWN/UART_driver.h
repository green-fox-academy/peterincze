/*
 * UART_driver.h
 *
 * Created: 2017. 06. 12. 13:51:40
 *  Author: Peeter
 */ 


#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_


#include <stdint.h>

#define RX_CIRC_BUFF_LEN 25

volatile struct circular_buffer {
	char buffer[RX_CIRC_BUFF_LEN];
	char *head;
	char *tail;
	char *write_ptr;
	char *read_ptr;
} rx_buffer;

void UART_init();
void UART_send_character(char character);
char UART_get_character();
uint8_t UART_is_buffer_empty();


#endif /* UART_DRIVER_H_ */