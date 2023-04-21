#include <xc.h>
#include "config.h"

void main(void){
    
    ADCON1 = 0x0F;
    TRISDbits.RD0 = 0;
    
    // Configuramos el Timer 0
    T0CONbits.T08BIT = 0; //modo 16 bits
    T0CONbits.T0PS   = 0b111; // preescaler 256
    T0CONbits.PSA    = 0;
    T0CONbits.T0CS   = 0;
    
    TMR0H = (46005&0xFF00)>>8;
    TMR0L = (46005&0x00FF)>>0;
    
    T0CONbits.TMR0ON = 1;
    
    while(1){
        if(INTCONbits.TMR0IF == 1){
            TMR0H = (46005&0xFF00)>>8;
            TMR0L = (46005&0x00FF)>>0;
            PORTDbits.RD0 ^=1;
            INTCONbits.TMR0IF = 0;
        }
        
    }
    return;
}