/*
* serial.h
*
* Created: 10/15/2022 10:33:38 PM
*  Author: In to Programming
*/

#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>
#include <stdlib.h>
#define F_CPU 16000000L
class Serial
{
	private:
	char dataHolder[10];
	void nextLine();
	
	public:
	Serial();
	void begin(unsigned long baudRate);
	unsigned char available();
	char read();
	void write(char byte);
	void print(const char *byte);
	void print(int data);
	void print(long data);
	void print(float data);
	void print(double data);
	void println();
	void println(const char *byte);
	void println(int data);
	void println(long data);
	void println(float data);
	void println(double data);
};
#endif