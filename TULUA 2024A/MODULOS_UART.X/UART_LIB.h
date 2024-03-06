/* 
 * File:   UART_LIB.h
 * Author: iProf
 *
 * Created on 5 de marzo de 2024, 08:41 PM
 */

#ifndef UART_LIB_H
#define	UART_LIB_H

#include <xc.h>
#include "config.h"

void UART_Init(void);
void UART_Write(char letra);
void UART_Write_Text(char *txt);

char UART_Read(void);


#endif	/* UART_LIB_H */

