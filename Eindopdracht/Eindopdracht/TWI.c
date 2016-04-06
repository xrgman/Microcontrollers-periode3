/*
 * TWI.c
 *
 * Created: 3/23/2016 5:19:02 PM
 *  Author: Wesley
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

//First element is size:
int letters[][9] = {
	{5, 0,0,0,0,0},
  {5, 0,56,125,56,0},//!
  {5, 80,96,0,80,96},//"
  {5, 20,127,20,127,20},//#
  {5, 18,42,127,42,36},//$
  {5, 98,100,8,19,35},//%
  {5, 54,73,85,34,5},//&
  {5, 0,80,96,0,0},//'(7)
  {5, 0,28,34,65,0},//(
  {5, 0,65,34,28,0},//)
  {5, 20,8,62,8,20},//*
  {5, 8,8,62,8,8},//+
  {5, 0,5,6,0,0},//,(12)
  {5, 8,8,8,8,8},//-
  {5, 0,3,3,0,0},//.(14)
  {5, 2,4,8,16,32},///
  {5, 62,69,73,81,62},//0
  {5, 17,33,127,1,1},//1
  {5, 33,67,69,73,49},//2
  {5, 34,65,73,73,54},//3
  {5, 12,20,36,127,4},//4
  {5, 114,81,81,81,78},//5
  {5, 62,73,73,73,38},//6
  {5, 64,71,72,80,96},//7
  {5, 54,73,73,73,54},//8
  {5, 50,73,73,73,62},//9
  {5, 0,54,54,0,0},//:(26)
  {5, 0,53,54,0,0},//;(27)
  {5, 8,20,34,65,0},//<
  {5, 20,20,20,20,20},//=
  {5, 0,65,34,20,8},//>
  {5, 32,64,69,72,48},//?
  {5, 62,73,87,85,62},//@
  {5, 31, 36, 68, 36, 31},//A
  {5, 127, 73, 73, 73, 54},//B
  {5, 62, 65, 65, 65, 34},//C
  {5, 127, 65, 65, 34, 28},//D
  {5, 127, 73, 73, 65, 65},//E
  {5, 127, 72, 72, 72, 64},//F
  {5, 62, 65, 65, 69, 38},//G
  {5, 127, 8, 8, 8, 127},//H
  {5, 65, 65, 127, 65, 65},//I
  {5, 2, 1, 1, 1, 126},//J
  {5, 127, 8, 20, 34, 65},//K
  {5, 127, 1, 1, 1, 1},//L
  {5, 127, 32, 16, 32, 127},//M
  {5, 127, 16, 8, 4, 127},//N
  {5, 62, 65, 65, 65, 62},//O
  {5, 127, 72, 72, 72, 48},//P
  {5, 62, 65, 69, 66, 61},//Q
  {5, 127, 72, 76, 74, 49},//R
  {5, 50, 73, 73, 73, 38},//S
  {5, 64, 64, 127, 64, 64},//T
  {5, 126, 1, 1, 1, 126},//U
  {5, 124, 2, 1, 2, 124},//V
  {5, 126, 1, 6, 1, 126},//W
  {5, 99, 20, 8, 20, 99},//X
  {5, 96, 16, 15, 16, 96},//Y
  {5, 67, 69, 73, 81, 97},//Z
  {5, 0,127,65,65,0},//[
  {5, 32,16,8,4,2},//
  {5, 0,65,65,127,0},
  {5, 16,32,64,32,16},//^
  {5, 1,1,1,1,1},//_
  {5, 0,64,32,16,0},//`
  {5, 2,21,21,14,1},//a
  {5, 64,126,9,17,14},//b
  {5, 14,17,17,17,10},//c
  {5, 14,17,74,127,1},//d
  {5, 14,21,21,21,9},//e
  {5, 1,9,63,72,32},//f
  {5, 9,21,21,21,30},//g
  {5, 127,8,8,8,7},//h
  {5, 0,0,46,1,1},//i
  {5, 2,1,1,1,94},//j
  {5, 1,127,4,10,17},//k
  {5, 0,65,127,1,0},//l
  {5, 31,16,14,16,31},//m
  {5, 31,8,16,16,15},//n
  {5, 14,17,17,17,14},//o
  {5, 127,20,20,20,8},//p
  {5, 8,20,20,31,1},//q
  {5, 31,8,16,16,8},//r
  {5, 9,21,21,21,18},//s
  {5, 16,16,126,17,18},//t
  {5, 30,1,1,30,1},//u
  {5, 28,2,1,2,28},//v
  {5, 30,1,6,1,30},//w
  {5, 17,10,4,10,17},//x
  {5, 16,9,6,8,16},//y
  {5, 17,19,21,25,17},//z
  {5, 8,54,65,65,0},//{
  {5, 0,0,127,0,0},//|(92)
  {5, 0,65,65,54,8},//}
  {5, 32,64,32,16,32},//~
};


void twi_init() {
	TWSR = 0;
	TWBR = 32;
}

void twi_start() {
	TWCR = (0x80 | 0x20 | 0x04);
	while(0x00 == (TWCR & 0x80));
}

void twi_stop() {
	TWCR = (0x80 | 0x10 | 0x04);
}

void twi_tx(unsigned char data) {
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while(0 == (TWCR & 0x80));
}

void initializeTWI() {
	twi_init();
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x21);	// Internal osc on (page 10 HT16K33)
	twi_stop();

	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0xA0);	// HT16K33 pins all output
	twi_stop();

	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0xE3);	// Display Dimming 4/16 duty cycle
	twi_stop();

	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0x81);	// Display OFF - Blink On
	twi_stop();
}

/************************************************************************/
/* Clears the whole 8*8 display.                                        */
/************************************************************************/
void clearDisplay() {
	for(int x = 0; x < 15; x+=2) {
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(x);	// Address
		twi_tx(0x00);	// data
		twi_stop();
		_delay_ms(10);
	}
}

/*********************************************************************************/
/* Draw a given word on the 8*8 display, it will automaticcly scroll to the left */
/*********************************************************************************/
void displayWord(int word[]) {
	int wordSize = word[0];
	int currentrow = 0;
	int scrollCounter = 0;
	
	for(int startPosition = 0; startPosition < (wordSize*5)+wordSize; startPosition++) { //Scroll-loop
		for(int letter = 1; letter <= wordSize; letter++ ) { //Letter writing loop
			int carachterSize = letters[word[letter]][0];
			for(int carachter = 1; carachter <= carachterSize; carachter++) { //Carachter writing loop
				if(scrollCounter >= startPosition && scrollCounter <= startPosition + 8) { //Only draw when inside the view area
					twi_start();
					twi_tx(0xE0);
					twi_tx(currentrow);	
					twi_tx(letters[word[letter]][carachter]);
					twi_stop();
					currentrow += 2;
				}
				scrollCounter++;
			}
			if(scrollCounter >= startPosition && scrollCounter <= startPosition + 8) { //draw empty line between two carachters
				twi_start();
				twi_tx(0xE0);
				twi_tx(currentrow);
				twi_tx(0);	
				twi_stop();
				currentrow += 2;
			}
			scrollCounter++;
		}
		currentrow = 0;
		scrollCounter = 0;
		_delay_ms(100);
	}
}

/************************************************************************/
/* Draw a given string on the 8*8 Display                               */		
/* Size = amount og carachters in the string +1							*/
/************************************************************************/
void displayString(char string[], int size) {
	int word[size];
	word[0] = size-1;
	for(int x = 1; x <= size; x++) {
		char letter = string[x-1];
		word[x] = letter-32;
	}
	displayWord(word);
}