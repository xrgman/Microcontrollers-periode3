/*
 * OpdrachtB2.c
 *
 * Created: 2/16/2016 11:09:46 AM
 * Author : Wesley
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void setLed();

int ledNumber;

ISR( INT0_vect ) {
	ledNumber++;
	setLed(ledNumber);
}

ISR( INT1_vect ) {
	ledNumber++;
	setLed(ledNumber);
}

int main(void)
{
	ledNumber = 0;
	DDRD = 0b11111100;
	EICRA = 0x0A;
	EIMSK = 0x03;
	sei();
    while (1) { }
}

void setLed(int led) {
	PORTD &= ~(1<<(((led-1)%6)+2));	
	PORTD |= (1<<((led%6)+2));
}

