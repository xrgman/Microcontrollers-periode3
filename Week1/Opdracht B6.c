/*
 * Opdracht B6.c
 *
 * Created: 2/2/2016 6:56:38 PM
 * Author : Wesley
 */ 
#define F_CPU 8000000UL

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
    DDRD = 0b11111111;
	int fastFreq = 0;
    while (1) 
    {
		if(PINC & 0x01) 
			fastFreq++;
		PORTD = 0b10000000;	//Light up led
		if(fastFreq%2 == 0)
			wait(1000);
		else
			wait(250);
		PORTD = 0x00; //Turn off led
		if(fastFreq%2 == 0)
			wait(1000);
		else
			wait(250);
    }
	return 1;
}

