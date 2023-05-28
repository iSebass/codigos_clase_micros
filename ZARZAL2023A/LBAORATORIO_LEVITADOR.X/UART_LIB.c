#include "UART_LIB.h"



void UART_Init(UART_Config config){
      // Cálculo del valor del registro SPBRG para la velocidad de baudios deseada
    unsigned long spbrg_val = (_XTAL_FREQ / (16 * config.baud_rate)) - 1;
    SPBRG = (unsigned char)(spbrg_val);

    // Configuración de los bits de control del UART
    TXSTA = 0x24;  // Transmisor en modo asíncrono de 8 bits, habilitado
    RCSTA = 0x90;  // Recepción en modo asíncrono de 8 bits, habilitada

    // Configuración de los bits de datos, paridad y bits de parada
    TX9  = config.data_bits == 9 ? 1 : 0;  // 9 bits de datos si se configura
    RX9  = config.data_bits == 9 ? 1 : 0;  // así en la estructura UART_Config
    TXEN = 1;  // Habilitación del transmisor
    SYNC = 0;  // Modo asíncrono
    SPEN = 1;  // Habilitación del UART

    // Configuración de la paridad
    switch (config.parity) {
        case 1:  // Paridad par
            BRGH = 1;   // Alto nivel de velocidad de baudios
            TX9D = 0;   // Bit de datos más significativo en 0
            RCSTA |= 0x02;  // Habilitación de la paridad
            break;
        case 2:  // Paridad impar
            BRGH = 1;   // Alto nivel de velocidad de baudios
            TX9D = 1;   // Bit de datos más significativo en 1
            RCSTA |= 0x02;  // Habilitación de la paridad
            break;
        default:  // Paridad ninguno
            BRGH = 1;   // Alto nivel de velocidad de baudios
            TX9D = 0;   // Bit de datos más significativo en 0
            RCSTA &= ~0x02;  // Deshabilitación de la paridad
            break;
        }
}
void UART_Write_Chr(uint8_t letter){
    while (!TXSTAbits.TRMT);   // Esperar a que el registro de transmisión esté vacío;
    TXREG = letter;            // Escribir el byte en el registro de transmisión;
}
void UART_Write_Text(char *text){
    while(*text){
        UART_Write_Chr(*text);
        text++;
    }
}
uint8_t UART_Read(void){
    while (!PIR1bits.RCIF); // Esperar a que se reciba un byte;
    return RCREG; // Leer el byte del registro de recepción;
}


