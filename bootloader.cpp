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

int main()
{
	Usart_Init();
	while(1)
	{
		Usart_TransmitString("Bootloader");
		//Usart_Transmit('b');
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

			while(address < APP_END)
			{
				boot_page_erase(address);
				boot_spm_busy_wait();
				address += SPM_PAGESIZE;
			}
			///address = 0;
			Usart_TransmitString("OK");
			//Usart_Transmit('U');
		}
	}
}



