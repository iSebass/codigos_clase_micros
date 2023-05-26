?
#ifndef UART_LIB_H_
#define UART_LIB_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void UART1_Init(unsigned long baudrate);
void UART1_Transmit_char(unsigned char data);
void UART1_Transmit_Text(char *texto);
void UART1_Transmit_Printf(char *str, ...);

bool UART1_DataAvailable(void);
unsigned char UART1_Receive(void);


#endif /* UART_LIB_H_ */