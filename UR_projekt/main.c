/*
 * opg1_ny_E20.c
 *
 * Created: 01-09-2020 14:34:13
 * Author : osch
 */ 
#include <xc.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "I2C.h"  //include library for i2c driver
#include "ssd1306.h" //include display driver

#define F_CPU 16000000UL //UL = unsigned long
#include <util/delay.h>
#include "UART/UART_MODULE.h"

// For USART
#define BAUD 19200
#define MYUBRRF F_CPU/8/BAUD-1 // full duplex
#define MYUBRRH F_CPU/16/BAUD-1 // half duplex

//init function
void init(){
//	PORTK|=0xFF;
//	DDRG |=0b00100000;  //D4 as output
	
}

int main(void)
{  
	//init();
	
//   _i2c_address = 0X78; // write address for i2c interface
//   
//   I2C_Init();  //initialize i2c interface to display
//   InitializeDisplay(); //initialize  display
//   
//    print_fonts();  //for test and then exclude the  clear_display(); call
//    //char text[]="en tekst string"; //string declared before use it in sendStrXY - 15 chars long incl spaces
//    clear_display();   //use this before writing you own text
   
   uart0_init(MYUBRRF);
   
   //char var[4];
   
  while (1)
  {  
	 //putscUSART0('g');
	 putscUSART0(getchUSART0());
	 //sprintf(var,"%c",getchUSART0());
	 //sendStrXY(var,0,0);
	 
	 //var = getchUSART0();
	 //_delay_ms(1000); 
	 
	 //sendCharXY(var,1,2);  //one char  - X is line number - from 0 -7 and Y number position of the char an the line - 15 chars 
	 
	 //sendStrXY(text,0,0); //line 0  -print the line of text
	  
  }
  

}

