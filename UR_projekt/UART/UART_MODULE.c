/*
 * UART_MODULE.c
 *
 * Created: 18-03-2021 10:20:27
 *  Author: Jonas
 */ 

#include <avr/io.h>
#include "UART_MODULE.h"
#define F_CPU 16000000UL //UL = unsigned long

// For USART
#define BAUD 19200
#define MYUBRRF F_CPU/8/BAUD-1 // full duplex
#define MYUBRRH F_CPU/16/BAUD-1 // half duplex

// init UART1
void uart0_init(unsigned int ubrr){
	UCSR0A=(1<<U2X0); // Full duplex // enable full duplex (A register)
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);// enable receive and transmit (B-register)
	UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01); // set frame format (C-register)
	UBRR0H =(unsigned char)(ubrr>>8); //s.211  // set baud rate (UBRR register)
	UBRR0L =(unsigned char)ubrr;
}

// transmit one byte
void putscUSART0(char tx){
	while(!(UCSR0A & (1<<UDRE0))); // UDREn er 0 ved transmission indtil transmit buffer er tom (venter på at uart kan sende ny byte)
	UDR0 = tx;
}

// receive one byte
char getchUSART0(void){
	while(!(UCSR0A & (1<<RXC0))); // RXCn er 0 ved transmission indtil der er modtaget en byte (vente på at uart har modtaget en byte)
	return UDR0;
}
