
/*
* USART_Protocol.cpp
*
* Created: 10/15/2022 11:20:24 AM
* Author : In to Programming
*/
#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

Serial serial;

int main(void)
{
	serial.begin(9600);
	
	serial.println("AVR C Compiler Data Sizes Are:");
	serial.print("int   : "); serial.println((int)sizeof(int));
	serial.print("long  : "); serial.println((int)sizeof(long));
	serial.print("float : "); serial.println((int)sizeof(float));
	serial.print("double: "); serial.println((int)sizeof(double));
	
	while (1)
	{
		if (serial.available())
		{
			char data = '\0';
			while(data != '\n')
			{
				data = serial.read();
				serial.write(data);
			}
		}
		
	}
}