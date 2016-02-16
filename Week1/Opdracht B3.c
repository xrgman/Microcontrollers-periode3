/*
 * Opdracht B3.c
 *
 * Created: 2/2/2016 5:05:57 PM
 * Author : Wesley
 */ 

#include <avr/io.h>


int main(void)
{
	DDRD = 0b11111111;
    while (1) 
    {
		if(PINC & 0x01)
			PORTD = 0b10000000;
		else
			PORTD = 0x00;	
    }
}

