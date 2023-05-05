#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "UART_LIB.h"
#include "ADC_LIB.h"


int   conver;
float temp, hum, pressure;

char strUART[50]=" ";


void __interrupt() appLedRxData(){
    
   
    
}

void main(void){
    
    ADCON1 = 12; 
    
    ADC_Init();
    
    UART_Config uartConfig;
    
    uartConfig.baud_rate    = 9600;       // VELOCIDAD DE BITS/SEG
    uartConfig.data_bits    = 8;          // 8 BITS DATOS
    uartConfig.parity       = 0;          // PARITY NONE
    uartConfig.stop_bits    = 1;          // 1 BIT PARADA
    
    UART_Init(uartConfig); 
   

    while(1){
        conver = ADC_Read(0);
        temp = ADC_MAP(conver, 0.0, 1023.0, 0.0, 150.0);
        
        conver = ADC_Read(1);
        hum    = ADC_MAP(conver, 0.0, 1023.0, 100.0, 0.0);
        
        conver   = ADC_Read(2);
        pressure = ADC_MAP(conver, 0.0, 1023.0, 700.0, 1100.0);
        
        sprintf(strUART,"* %f / %f / %f #\r\n",temp, hum, pressure);
        UART_Write_Text(strUART);
        
        __delay_ms(500);
    }
    return;
}

