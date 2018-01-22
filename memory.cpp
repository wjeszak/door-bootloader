/*
 * functions.cpp
 *
 *  Created on: 22 sty 2018
 *      Author: wjeszak
 */

#include <avr/boot.h>
#include <avr/interrupt.h>
#include "memory.h"

void EraseProgramPage(uint32_t page, uint8_t* buf)
{
	uint16_t i;
	uint8_t sreg;
	sreg = SREG;
	cli();
	eeprom_busy_wait();
	boot_page_erase(page);
	boot_spm_busy_wait();      // Wait until the memory is erased.
// ....
}


