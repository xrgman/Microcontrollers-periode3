/*
 * Opdracht B5.c
 *
 * Created: 2/2/2016 6:29:12 PM
 * Author : Wesley
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

typedef struct {
	char data;
	int delay;
} PATTERN_STRUCT;

PATTERN_STRUCT pattern[] = {
	{ 0b10000001, 50 }, { 0b01000010, 50 }, { 0b00100100, 50 }, { 0b00011000, 50 }, { 0b00100100, 50 }, { 0b01000010, 0 }	
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
    DDRD = 0b11111111;
    while (1) 
    {
		int index = 0;
		while(pattern[index].delay != 0) {
			PORTD = pattern[index].data;
			wait(pattern[index].delay);
			index++;
		}
    }
	return 1;
}

