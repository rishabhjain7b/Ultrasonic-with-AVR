/*
 * ultrasonic.c
 *
 * Created: 08-07-2016 13:40:25
 *  Author: RISHABH JAIN
 */ 


#include <avr/io.h>
#include "lcd_4b.h"
#include <util/delay.h>
#define trig PB0
#define echo PB1

int main(void)
{
	double c=0.000000;
	double re;
	char ar[10];
	
	
	lcd_init(LCD_DISP_ON_CURSOR);
	
	DDRB|=(1<<trig);
	DDRB&=~(1<<echo);
	
	PORTB&=~(1<<trig);
	_delay_us(2);
	PORTB|=(1<<trig);
	_delay_us(10);
	PORTB&=~(1<<trig);
	
	PORTB|=(1<<echo);
	
	_delay_us(10);
	while(bit_is_clear(PINB,echo))
	{
		c=c+0.000001;
	}
	
	re=(c*340)/2.0;
	sprintf(ar,"%lf",re);
	lcd_puts(ar);
	while(1);
}