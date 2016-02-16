/*
 * Opdracht B4.c
 *
 * Created: 2/2/2016 5:38:45 PM
 * Author : Wesley
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
    DDRD = 0b11111111;
	PORTD = 0x01;
    while (1) 
    {
		for(int x = 0x01; x < 0b11111111; x <<= 1) {
			PORTD = x;
			wait(50);	
		}
		for(int x = 0b10000000; x > 0x00; x >>= 1) {
			PORTD = x;
			wait(50);
		}	
    }
	return 1;
}

