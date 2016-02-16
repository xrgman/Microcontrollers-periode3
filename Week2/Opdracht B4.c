/*
 * OpdrachtB4.c
 *
 * Created: 2/16/2016 4:50:52 PM
 * Author : Wesley
 */ 

#include <avr/io.h>
#include <util/delay.h>


int lookupTable[] = {
	0b00000010, 0b00000001, 0b00010000, 
	0b01000000,0b10000000, 0b00000100	
};

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	DDRF = 0b11111111;
    while (1) 
    {
		for(int x = 0; x < 6; x++) {
			PORTF = lookupTable[x];
			wait(300);
		}
    }
}

