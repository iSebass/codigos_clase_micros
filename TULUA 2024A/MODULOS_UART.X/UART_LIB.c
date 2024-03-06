#include "UART_LIB.h"


void UART_Init(void){
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;
    
    //CALCULAR EL BAUDRATE
    SPBRG = 12;
    // BRGH = 0 -> LOW SPEED,  BRGH=1 -> HIGH SPEED
    TXSTAbits.BRGH = 0;
    
    //MODO ASINCRONICO
    TXSTAbits.SYNC = 0; 
        
    TXSTAbits.TXEN = 1;
    RCSTAbits.SPEN = 1;
    RCSTAbits.CREN = 1;
}
void UART_Write(char letra){
    TXREG = letra;
    while(!TXIF);
}
void UART_Write_Text(char *txt){
    while(*txt){
        UART_Write(*txt);
        txt++;
    }
}

char UART_Read(void){
    while(!RCIF);
    return RCREG;
}