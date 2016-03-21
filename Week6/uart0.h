/*
 * uart0.h
 *
 * Created: 3/15/2016 12:03:59 PM
 *  Author: Wesley
 */ 
#ifndef _UART
#define _UART

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BIT(x) (1 << (x))
#define UART0_BAUD 9600 // Baud rate USART0
#define MYUBRR F_CPU/16/UART0_BAUD - 1 // My USART Baud Rate Register

void usart0_init( void ) ; // initialize USART0 - receive/transmit
void usart0_start( void ) ; // UART0 receiver & transmitter enable
char uart0_receiveChar() ; // UART0: receive ch
int uart0_sendChar( char ch ) ; // UART0: send ch

#endif