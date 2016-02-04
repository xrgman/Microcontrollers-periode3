/*
 * Opdracht B7.c
 *
 * Created: 2/4/2016 4:58:03 PM
 * Author : Wesley
 * Pin 1 - PORTD1, Pin 2 - PORTD2, Pin 3 - PORTD3
 */ 

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
    /* Replace with your application code */
	
    while (1) 
    {
		for(int x = 1; x <= 6; x++) {
			setCharliePlexingLed(x);
			wait(800);
		}	
    }
	return 1;
}

void setCharliePlexingLed(int lednr) {
	switch(lednr) {
		case 1:
			DDRD = 0b11110111;
			PORTD = 0b00000010;
			break;	
		case 2:
			DDRD = 0b11110111;
			PORTD = 0b00000100;
			break;
		case 3:
			DDRD = 0b11111101;
			PORTD = 0b0001000;
			break;
		case 4:
			DDRD = 0b11111101;
			PORTD = 0b0000100;
			break;
		case 5:
			DDRD = 0b11111011;
			PORTD = 0b0001000;
			break;
		case 6:
			DDRD = 0b11111011;
			PORTD = 0b0000010;
			break;
		
	}
}

