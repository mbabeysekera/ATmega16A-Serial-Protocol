
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
	begin(9600); // baud rate has been set to 9600
	while (1)
	{
		char data = read(); // read data(byte) from the PC
		write(data); // write received byte to serial monitor (data visualizer)
	}
}

void begin(unsigned int baudRate)
{
	unsigned int ubrrRegValue = (unsigned int)((F_CPU / (8L * baudRate)) - 1L); // calculate baud rate register value
	UBRRH = (unsigned char) ubrrRegValue >> 8;
	UBRRL = (unsigned char) ubrrRegValue;
	UCSRA |= (1 << U2X); // for 2x speed
	UCSRB |= (1 << RXEN) | (1 << TXEN); // enable RX and TX
	UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0); // No parity, One Stop Bit
}

void wait() 
{
	while(!(UCSRA & (1 << RXC))); // wait until data received from other device
}

void write(char byte) {
	while(!(UCSRA & (1 << UDRE))); // wait until data sent to other device 
	UDR = byte; // then write new data to other device
}

char read() {
	wait();
	return UDR; // read data from other devices
}