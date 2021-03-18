/*
 * UART_MODULE.h
 *
 * Created: 18-03-2021 10:20:17
 *  Author: Jonas
 */ 


#ifndef UART_MODULE_H_
#define UART_MODULE_H_

void uart0_init(unsigned int ubrr);
void putscUSART0(char tx);
char getchUSART0(void);


#endif /* UART_MODULE_H_ */