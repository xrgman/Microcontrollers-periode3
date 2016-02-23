/*
 * Week3.c
 *
 * Created: 2/23/2016 9:36:16 AM
 * Author : Wesley
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "display.h"

void opdracht1(void);

int count;

ISR(TIMER2_OVF_vect) {
	count++;
	char str[10];
	sprintf(str,"Count: %d",count);
	display_text(1,str);
	TCNT2 = -1;
}

int main(void)
{
	DDRD = 0x00;
	TCNT2 = -1;
	TIMSK |= 0x40;
	TCCR2= 0x07; //Turning on counter on button PD7;
	sei();
	init();
	display_text(1,"Count: 0");
    while (1) {}
	return(1);
}

void opdracht1() {
	init();
	display_text(1,"feest");
	display_text(2," boef12345678");
	set_cursor(18);
}