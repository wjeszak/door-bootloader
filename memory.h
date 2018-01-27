/*
 * memory.h
 *
 *  Created on: 22 sty 2018
 *      Author: wjeszak
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include <inttypes.h>

#define APP_END				0x0E00		// 512 words (fusebit BOOTSZ)

extern void EraseProgramPage(uint32_t page, uint8_t* buf);

#endif /* MEMORY_H_ */
