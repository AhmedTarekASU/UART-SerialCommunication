#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcdConfig.c"	//include LCD code

void usart_init()
{
	UCSRB = (1<<TXEN)|(1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL = (0x07);
}

void usart_send(unsigned char ch)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR = ch;
}

unsigned char usart_receive()
{
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}

int main(void)
{
	lcd_init();			//Initialize LCD
	lcd_gotoxy(1,1);	//Select LCD line to print on
	lcd_print("YES");	//Print "YES" on LCD

	lcd_gotoxy(1,2);
	lcd_print("Driver Working Successfully");

	DDRA = 0xFF;		//Set Port A as output for LEDs
	DDRB = 0x00;		//Set Port B as input for Switches
	PORTB = 0xFF;		//Pull-up Port B
	
	usart_init();		//Initialize USART
	while (1)
	{
		usart_send(PINB);			//Send data on PIN C (Switches)
		PORTA = usart_receive();	//Receive Data and display it on PORT A (LEDs)
	}
}

