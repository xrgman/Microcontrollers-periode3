/*
 * Temperatuur.c
 *
 * Created: 3/2/2016 5:12:38 PM
 * Author : Wesley
 */ 

#define BIT(x)	(1 << (x))

#include <avr/io.h>
#include <util/delay.h>


void initializeADC() {
	ADMUX = 0b11100001;
	ADCSRA = 0b10000110;
}


int main(void)
{
	initializeADC();
    DDRA = 0xFF;
	init();
	display_text("Temperature: 0");
    while (1) 
    {
		ADCSRA |= BIT(6);
		while(ADCSRA & BIT(6));
		PORTA = ADCH;
		char str[20];
		sprintf(str,"Temperature: %d",ADCH);
		display_text(1,str);
		_delay_ms(500);
    }
}

