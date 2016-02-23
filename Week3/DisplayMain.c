/*
 * Week3.c
 *
 * Created: 2/23/2016 9:36:16 AM
 * Author : Wesley
 */ 

#include <avr/io.h>
#include "display.h"


int main(void)
{
    /* Replace with your application code */
	init();
	display_text(1,"feest");
	display_text(2," boef12345678");
	set_cursor(18);
    while (1) {	}
	return(1);
}

