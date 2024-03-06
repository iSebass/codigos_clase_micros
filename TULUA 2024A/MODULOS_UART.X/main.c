#include <xc.h>
#include "config.h"
#include "UART_LIB.h"

char dataR;

void __interrupt() RxData(){
    if(PIR1bits.RCIF == 1){
        dataR = UART_Read();
        if(dataR == 'a'){
            LATDbits.LATD0 = 0;
        }
        else if(dataR == 'p'){
            LATDbits.LATD0 = 1;
        }
    }
}

void main(void){
    
    OSCCON = 0x38;
    BORCON = 0x00;
    OSCTUNE = 0x00;
    
    ANSELD = 0x00;
    TRISD = 0x00;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIR1bits.RCIF = 0;
    PIE1bits.RCIE = 1;
    
    UART_Init();
    
    
    
    while(1){
        
        
        
        
        
        UART_Write_Text("UNIVALLE \r\n");
        
        __delay_ms(1000);
    }
    
    return;
}
