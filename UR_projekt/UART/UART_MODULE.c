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
#define BAUD 19200 // baud rates skal være ens på begge enheder
#define MYUBRRF F_CPU/8/BAUD-1 // full duplex
#define MYUBRRH F_CPU/16/BAUD-1 // half duplex

/**
	UART INITIALIZATION
**/
// init UART1
extern void uart0_init(unsigned int ubrr){
	// setting UCRSRn (USART Control and Status Register) (for A, B and C)
	UCSR0A=(1<<U2X0); // Full duplex // enable full duplex aka. double speed (A register)
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);// enable receive and transmit (B-register)
	UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01); // set frame format (C-register) (8 bits, no parity...vidst også med 1 start bit og 1 stop bit)
	// setting UBRRn (USART Baud Rate Register) s.211 (16 bits where H is 8 bit high and L is 8 bit low) (skal beregnes: se tabel i datablad)
	UBRR0H =(unsigned char)(ubrr>>8); // skriver de 8 høje bit. (skiftes da der er 16 bit i alt i UBRRn)
	UBRR0L =(unsigned char)ubrr; // skriver de 8 lave bit.
}

/**
	UART CHARACTERS
**/
// transmit one byte/character
extern void putchUSART0(char tx){
	while(!(UCSR0A & (1<<UDRE0))); // UDREn er 0 ved transmission indtil transmit buffer er tom (venter på at uart kan sende ny byte) (sker i UCSRnA registret)
	UDR0 = tx; // skriver til UDR registret
}

// receive one byte/character
 extern char getchUSART0(void){
	while(!(UCSR0A & (1<<RXC0))); // RXCn er 0 ved transmission indtil der er modtaget en byte/character (vente på at uart har modtaget en byte/character) (sker i UCSRnA registret)
	return UDR0; // modtager data fra UDR registret
}

/**
	UART STRINGS
**/

// transmit one string (by calling putscUSART0 continuously until whole string is sent)
extern void putsUSART0(char *ptr){
	
	while(*ptr){
		putscUSART0(*ptr);
		ptr++;
	} 
	
}

// receive one string
extern char getsUSART0(void){
	
}