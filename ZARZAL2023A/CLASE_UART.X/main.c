#include <xc.h>
#include "config.h"
#include "UART_LIB.h"


void main(void){
    UART_Config uartConfig;
    
    uartConfig.baud_rate    = 9600;       // VELOCIDAD DE BITS/SEG
    uartConfig.data_bits    = 8;          // 8 BITS DATOS
    uartConfig.parity       = 0;          // PARITY NONE
    uartConfig.stop_bits    = 1;          // 1 BIT PARADA
    uartConfig.speed_module = HIGH_SPEED; // SPEED MODE
    
    UART_Init(uartConfig); 
    while(1){
        UART_Write_Text("Univalle \r\n");
        __delay_ms(1000);
    }
    return;
}
