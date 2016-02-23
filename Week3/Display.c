/*
 * Display.c
 *
 * Created: 2/23/2016 9:37:09 AM
 *  Author: Wesley
 */ 
#include <avr/io.h>
#include <util/delay.h>

void lcd_command(unsigned char command);
void display_char(unsigned char carachter);

void init() {
	DDRC = 0xFF;
	_delay_ms(100);
	lcd_command(0x01); //Clear screen
	_delay_ms(2);
	lcd_command(0x02);
	lcd_command(0x28);
	lcd_command(0x0F);
	lcd_command(0x06);
	lcd_command(0x80);
}

void display_text(int line, char *text) {
	if(line == 2) 
		lcd_command(0xC0);
	else 
		lcd_command(0x80);
	for(int x = 0; x < strlen(text); x++)
		display_char(text[x]);
}

void display_char( unsigned char character )
{
	PORTC = character & 0xF0;
	PORTC |= 0x0C; 
	_delay_ms(1); 
	PORTC = 0x04; 
	PORTC = (character & 0x0F) << 4; 
	PORTC |= 0x0C; 
	_delay_ms(1); 
	PORTC = 0x00; 
}

void set_cursor(int position) {
	lcd_command(0x02); //Return cursor to start;
	_delay_ms(1);
	if(position <= 16)
		lcd_command(0x80); //Return to first line;
	else {
		lcd_command(0xC0);
		position -= 16;
	}
	_delay_ms(1);
	for(int x = 0; x <= position-2; x++)
		lcd_command(0x14);
}

void lcd_command ( unsigned char command )
{
	PORTC = command & 0xF0; 
	PORTC |= 0x08; 
	_delay_ms(1); 
	PORTC = 0x04; 
	PORTC = (command & 0x0F) << 4;
	PORTC |= 0x08; 
	_delay_ms(1);
	PORTC = 0x00;
}