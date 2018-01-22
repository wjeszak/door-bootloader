/*
 * usart.cpp
 *
 *  Created on: 22 sty 2018
 *      Author: wjeszak
 */

#include "usart.h"

void Usart_Init()
{
	USART_DE_INIT;
	USART_DE_RECEIVE;
	UBRR0 = (uint16_t)UBRR_VAL;
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void Usart_TransmitComplete()
{
	while(!(UCSR0A & (1 << TXC0)));
	UCSR0A |= (1 << TXC0);
	USART_DE_RECEIVE;
}

void Usart_Transmit(uint8_t byte)
{
	USART_DE_SEND;
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = byte;
	Usart_TransmitComplete();
}

void Usart_TransmitString(const char* str)
{
	uint8_t c;
	while(*str)
	{
		Usart_Transmit(*str++);
	}
	//Usart_TransmitComplete();
}

uint8_t Usart_Receive(void)
{
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}
