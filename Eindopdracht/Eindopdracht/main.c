/*
 * Eindopdracht.c
 *
 * Created: 3/22/2016 1:47:42 PM
 * Author : Wesley
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "TWI.h"

int main(void)
{
    initializeTWI();
	clearDisplay();
	_delay_ms(500);
    while (1) 
    {
		displayString("HOI1 je2 bent- {een,} boef!!!!",31);
		_delay_ms(300);				
    }
}

