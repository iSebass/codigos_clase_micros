#include <xc.h>
#include "config.h"

int contador=0;

int val = 436;

void main(void){
    OSCCON  = 0x38;
    OSCTUNE = 0x00;
    BORCON  = 0x00;
  
    ANSELDbits.ANSD0 = 0;
    TRISDbits.TRISD0 = 0;
    ANSELDbits.ANSD1 = 0;
    TRISDbits.TRISD1 = 0;
    
    //CONFIGURAR TIMER
    PR2 = 155; //5ms de periodo PRE 64
    T2CONbits.T2CKPS = 0b11; // PRE 64 TIMER2
    
    CCPR4L = (val>>2) & 0xFF;
    CCP4CONbits.DC4B = val & 0x3;
    CCP4CONbits.CCP4M = 0b1100;
    
    CCPTMRS0bits.C4TSEL = 0b00; //Seleccionamos TIMER 2
    
    TMR2 = 0;
    T2CONbits.TMR2ON = 1;
    
    
    while(1){
        LATDbits.LATD0 ^=1;
        __delay_ms(500);
    
    }
    
}