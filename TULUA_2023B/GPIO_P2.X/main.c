#include <xc.h>
#include "config.h"
#include "SEVEN_SEG_LIB.h"

char contador=0;

void main(void){
    OSCCON  = 0b11110010;
    OSCTUNE = 0b00000000;
    BORCON  = 0b00000000;
    decoInit();
    while(1){
        
        decoCC(contador);
        contador++;
        if(contador>9)
            contador=0;
        __delay_ms(500);
        
    }
    return;
}
