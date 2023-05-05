#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "UART_LIB.h"


void __interrupt() appLedRxData(){
    
   
    
}

void main(void){

    UART_Config uartConfig;
    
    uartConfig.baud_rate    = 9600;       // VELOCIDAD DE BITS/SEG
    uartConfig.data_bits    = 8;          // 8 BITS DATOS
    uartConfig.parity       = 0;          // PARITY NONE
    uartConfig.stop_bits    = 1;          // 1 BIT PARADA
    
    UART_Init(uartConfig); 
   

    while(1){
       
    }
    return;
}

