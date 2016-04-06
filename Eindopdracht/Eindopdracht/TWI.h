/*
 * TWI.h
 *
 * Created: 4/2/2016 6:39:20 PM
 *  Author: Wesley
 */ 

void twi_init();
void twi_start();
void twi_stop();
void twi_tx(unsigned char data);
void initializeTWI();
void clearDisplay();
void displayWord(int word[]);
void displayString(char string[], int size);