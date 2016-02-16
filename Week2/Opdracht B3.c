/*
 * OpdrachtB3.c
 *
 * Created: 2/16/2016 11:26:40 AM
 * Author : Wesley
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void display();

int currentNumber;
int number[16] = {
	0b11010111, // 0
	0b10000100, // 1
	0b11001011, // 2
	0b11001110, // 3
	0b10011100, // 4
	0b01011110, // 5
	0b01011111, // 6
	0b11000100, // 7
	0b11111111, // 8
	0b11011110, // 9
	0b11111101, // A
	0b00011111, // B
	0b01010011, // C
	0b10001111, // D
	0b01011011, // E
	0b01111001  // F
};

ISR( INT0_vect ) {
	currentNumber++;
	display(currentNumber);
}

ISR( INT1_vect ) {
	currentNumber--;
	display(currentNumber);
}

int main(void)
{
	currentNumber = 0;
	DDRF = 0b11111111;
	DDRD = 0b11111100;
	EICRA = 0x0A;
	EIMSK = 0x03;
	sei();
    while (1) {	 }
}

void display(int digit) {
	if(digit < 0 || digit > 15)
		PORTF = number[14];
	else
		PORTF = number[digit];	
}

