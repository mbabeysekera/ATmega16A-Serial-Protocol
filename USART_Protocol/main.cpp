
/*
* USART_Protocol.cpp
*
* Created: 10/15/2022 11:20:24 AM
* Author : In to Programming
*/
#define F_CPU 16000000L

#include <avr/io.h>

void begin(unsigned int baudRate);
void wait() ;
void write(char byte);
char read();

int main(void)
{
	begin(9600);
	while (1)
	{
		char data = read();
		write(data);
	}
}

void begin(unsigned int baudRate)
{
	unsigned int ubrrRegValue = (unsigned int)((F_CPU / (8L * baudRate)) - 1L);
	UBRRH = (unsigned char) ubrrRegValue >> 8;
	UBRRL = (unsigned char) ubrrRegValue;
	UCSRA |= (1 << U2X);
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void wait() 
{
	while(!(UCSRA & (1 << RXC)));
}

void write(char byte) {
	while(!(UCSRA & (1 << UDRE)));
	UDR = byte;
}

char read() {
	wait();
	return UDR;
}