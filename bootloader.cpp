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
#include "chipdef.h"
#include "memory.h"

int main()
{
	Usart_Init();
	Usart_TransmitString("Dynabox/Lockerbox Bootloader\n");
	while(1)
	{
		uint8_t ch = Usart_Receive();

		if(ch == 'u')
		{
			uint8_t memory_tmp[SPM_PAGESIZE];
			uint16_t address, tmp_address;
			uint8_t cnt, type, i, j;
			uint8_t new_page = 0;
			uint16_t memory_data;

			type = 0;
			address = 0;
			for(uint8_t page = 0; page < 128; page++)
			{
				EraseProgramPage(page, 0);
			}
			Usart_TransmitString("Flash Erase OK\n");
		}
	}
}



