/*
 * UART_MODULE.h
 *
 * Created: 18-03-2021 10:20:17
 *  Author: Jonas
 */ 


#ifndef UART_MODULE_H_
#define UART_MODULE_H_

extern void uart0_init(unsigned int ubrr);
extern void putscUSART0(char tx);
extern char getchUSART0(void);


#endif /* UART_MODULE_H_ */