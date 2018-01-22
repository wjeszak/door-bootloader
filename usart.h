/*
 * uart.h
 *
 *  Created on: 22 sty 2018
 *      Author: wjeszak
 */

#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <inttypes.h>

#define USART_DE_DDR 			DDRC
#define USART_DE_PORT 			PORTC
#define USART_DE_PIN	 		3

#define USART_DE_RECEIVE 		USART_DE_PORT &= ~(1 << USART_DE_PIN)
#define USART_DE_SEND 			USART_DE_PORT |=  (1 << USART_DE_PIN)
#define USART_DE_INIT 			USART_DE_DDR  |=  (1 << USART_DE_PIN)

#define UBRR_VAL 		23 	// 19200 bps @ 7.37 Mhz

extern void Usart_Init();
extern void Usart_Transmit(uint8_t byte);
void Usart_TransmitString(const char* str);
extern uint8_t Usart_Receive();

#endif /* USART_H_ */
