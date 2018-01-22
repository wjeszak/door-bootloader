/*
 * bootloader.cpp
 *
 *  Created on: 22 sty 2018
 *      Author: wjeszak
 */

#include <avr/boot.h>
#include <avr/io.h>
#include <util/delay.h>

int main()
{

	DDRD |= (1 << 4); // green 1
	PORTD &= ~(1 << 4);
	while(1)
	{
		_delay_ms(5000);
		PORTD ^= (1 << 4);
	}


}



