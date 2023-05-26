#ifndef UART_LIB_H
#define	UART_LIB_H

#include "config.h"
#include <xc.h>
#include <stdint.h>

#define PARITY_EVEN   1  //PAR
#define PARITY_ODD    2  //IMPAR
#define PARITY_NONE   3  //SIN PARIDAD
#define HIGH_SPEED    1  //
#define LOW_SPEED     0  //

typedef struct {
    unsigned long baud_rate;  // Velocidad de baudios deseada
    unsigned char data_bits;  // Número de bits de datos (7 u 8)
    unsigned char parity;     // Paridad (0 = ninguno, 1 = par, 2 = impar)
    unsigned char stop_bits;  // Número de bits de parada (1 o 2)
    unsigned char speed_module; // Normal o doble Velocidad
} UART_Config;

void UART_Init(UART_Config config);
void UART_Write_Chr(uint8_t letter);
void UART_Write_Text(char *text);
uint8_t UART_Read(void);





#endif	/* UART_H */
