#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "UART_LIB.h"

char opletra = 'a';
char strRx[50]=" ", interpretarFlag = 0;
int indexRx = 0;


void __interrupt() appLedRxData(){
    
    if(PIR1bits.RC1IF == 1){
        strRx[indexRx] = UART_Read();
        if( strRx[indexRx]== '#' ){
            interpretarFlag = 1;
        }
        indexRx++;
    }
    
}

void main(void){
    
    TRISDbits.RD0 = 0;
    
    INTCONbits.GIE  = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE   = 1;
    
    UART_Config uartConfig;
    
    uartConfig.baud_rate    = 9600;       // VELOCIDAD DE BITS/SEG
    uartConfig.data_bits    = 8;          // 8 BITS DATOS
    uartConfig.parity       = 0;          // PARITY NONE
    uartConfig.stop_bits    = 1;          // 1 BIT PARADA
    
    UART_Init(uartConfig); 
   

    while(1){
        if( interpretarFlag == 1){
            
            if( strstr(strRx,"LedOn") ){
                PORTDbits.RD0 = 1;
            }
            else if( strstr(strRx,"LedOff") ){
                PORTDbits.RD0 = 0;
            }
            indexRx = 0;
            memset(strRx," ",50);
            interpretarFlag=0;
            
        }
        
        
        UART_Write_Text("Univalle \r\n");
        __delay_ms(300);
    }
    return;
}
