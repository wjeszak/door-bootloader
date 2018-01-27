/*
 * bootloader.cpp
 *
 *  Created on: 22 sty 2018
 *      Author: wjeszak
 */

#include <avr/boot.h>
#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"
#include "memory.h"

static void (*jump_to_app)(void) = 0x0000;

int main()
{
	Usart_Init();
	Usart_Transmit('>');
	while(1)
	{
		switch(Usart_Receive())
		{
		case 'c':
			boot_spm_busy_wait();
			uint16_t address;
			address = 0;
			while(address < APP_END)
			{
				boot_page_erase(address);
				boot_spm_busy_wait();
				address += SPM_PAGESIZE;
			}
			Usart_Transmit('^');
			break;

		case 'r':
			jump_to_app();
			break;
		}
	}
}
