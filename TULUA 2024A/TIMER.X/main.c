#include <xc.h>
#include "config.h"

int contador=0;

void main(void){
    OSCCON  = 0x38;
    OSCTUNE = 0x00;
    BORCON  = 0x00;
    
    ANSELDbits.ANSD0 = 0;
    TRISDbits.TRISD0 = 0;
    
    ANSELAbits.ANSA4 = 0;
    TRISAbits.TRISA4 = 1;
    
    TMR0 = 100;
    OPTION_REG = 0x07;
    
    while(1){
        if(INTCONbits.TMR0IF){
            TMR0 = 100;
            INTCONbits.TMR0IF = 0;
            contador++;
            if(contador==50){
                contador=0;
                LATDbits.LATD0 ^=1;
            }
        }
    
    }
    
}