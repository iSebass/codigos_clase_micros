#include "UART_LIB.h"



void UART_Init(UART_Config config){
      // C�lculo del valor del registro SPBRG para la velocidad de baudios deseada
    unsigned long spbrg_val = (_XTAL_FREQ / (16 * config.baud_rate)) - 1;
    SPBRG = (unsigned char)(spbrg_val);

    // Configuraci�n de los bits de control del UART
    TXSTA = 0x24;  // Transmisor en modo as�ncrono de 8 bits, habilitado
    RCSTA = 0x90;  // Recepci�n en modo as�ncrono de 8 bits, habilitada

    // Configuraci�n de los bits de datos, paridad y bits de parada
    TX9  = config.data_bits == 9 ? 1 : 0;  // 9 bits de datos si se configura
    RX9  = config.data_bits == 9 ? 1 : 0;  // as� en la estructura UART_Config
    TXEN = 1;  // Habilitaci�n del transmisor
    SYNC = 0;  // Modo as�ncrono
    SPEN = 1;  // Habilitaci�n del UART

    // Configuraci�n de la paridad
    switch (config.parity) {
        case 1:  // Paridad par
            BRGH = 1;   // Alto nivel de velocidad de baudios
            TX9D = 0;   // Bit de datos m�s significativo en 0
            RCSTA |= 0x02;  // Habilitaci�n de la paridad
            break;
        case 2:  // Paridad impar
            BRGH = 1;   // Alto nivel de velocidad de baudios
            TX9D = 1;   // Bit de datos m�s significativo en 1
            RCSTA |= 0x02;  // Habilitaci�n de la paridad
            break;
        default:  // Paridad ninguno
            BRGH = 1;   // Alto nivel de velocidad de baudios
            TX9D = 0;   // Bit de datos m�s significativo en 0
            RCSTA &= ~0x02;  // Deshabilitaci�n de la paridad
            break;
        }
}
void UART_Write_Chr(uint8_t letter){
    while (!TXSTAbits.TRMT);   // Esperar a que el registro de transmisi�n est� vac�o;
    TXREG = letter;            // Escribir el byte en el registro de transmisi�n;
}
void UART_Write_Text(char *text){
    while(*text){
        UART_Write_Chr(*text);
        text++;
    }
}
uint8_t UART_Read(void){
    while (!PIR1bits.RCIF); // Esperar a que se reciba un byte;
    return RCREG; // Leer el byte del registro de recepci�n;
}


