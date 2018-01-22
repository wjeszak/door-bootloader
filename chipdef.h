/*
 * chipdef.h
 *
 *  Created on: 22 sty 2018
 *      Author: wjeszak
 */

#ifndef CHIPDEF_H_
#define CHIPDEF_H_

#define _B512				// boot size is 512 words (1024 bytes)

#if defined(__AVR_ATmega88PA__)

//#define sig_byte3 0x1E
//#define sig_byte2 0x93
//#define sig_byte1 0x0F

//#define devtype 0x77 // Mega8 boot device code

// #define PAGESIZE 64 // Size in Bytes

#ifdef _B128
#define APP_PAGES ((24096 / SPM_PAGESIZE)- (2128 / SPM_PAGESIZE ))
#define APP_END APP_PAGES * SPM_PAGESIZE
#endif
#ifdef _B256
#define APP_PAGES ((24096 / SPM_PAGESIZE)- (2256 / SPM_PAGESIZE ))
#define APP_END APP_PAGES * SPM_PAGESIZE
#endif
#ifdef _B512
#define APP_PAGES ((24096 / SPM_PAGESIZE)- (2512 / SPM_PAGESIZE ))
#define APP_END APP_PAGES * SPM_PAGESIZE
#endif
#ifdef _B1024
#define APP_PAGES ((24096 / SPM_PAGESIZE)- (21024 / SPM_PAGESIZE ))
#define APP_END APP_PAGES * SPM_PAGESIZE
#endif
#endif

#endif /* CHIPDEF_H_ */
