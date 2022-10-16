/*
* serial.cpp
*
* Created: 10/15/2022 10:35:47 PM
*  Author: In to Programming
*/
#include "serial.h"

Serial::Serial()
{}

void Serial::begin(unsigned long baudRate)
{
	unsigned int ubrrRegValue = (unsigned int)((F_CPU / (8L * baudRate)) - 1L);
	UBRRH = (unsigned char) ubrrRegValue >> 8;
	UBRRL = (unsigned char) ubrrRegValue;
	UCSRA |= (1 << U2X);
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

unsigned char Serial::available()
{
	return ((UCSRA & (1 << RXC)) > 0) ? 1 : 0;
}

char Serial::read()
{
	while(!available());
	return UDR;
}

void Serial::write(char byte)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = byte;
}

void Serial::print(const char *byte)
{
	while(*byte)
	{
		write(*byte);
		byte++;
	}
}

void Serial::print(int data)
{
	itoa(data, dataHolder, 10);
	print(dataHolder);
}

void Serial::print(long data)
{
	ltoa(data, dataHolder, 10);
	print(dataHolder);
}

void Serial::print(float data)
{
	dtostrf(data, -16, 2, dataHolder);
	print(dataHolder);
}

void Serial::print(double data)
{
	dtostrf(data, -16, 6, dataHolder);
	print(dataHolder);
}

void Serial::println()
{
	nextLine();
}

void Serial::println(const char *byte)
{
	print(byte);
	nextLine();
}

void Serial::println(int data)
{
	print(data);
	nextLine();
}
void Serial::println(long data)
{
	print(data);
	nextLine();
}

void Serial::println(float data)
{
	print(data);
	nextLine();
}

void Serial::println(double data)
{
	print(data);
	nextLine();
}

void Serial::nextLine()
{
	write('\r');
	write('\n');
}