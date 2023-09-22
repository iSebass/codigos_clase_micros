#include <xc.h>
#include "config.h"
#include "SEVEN_SEG_LIB.h"

char counter=0;
char unidades, decenas;

const int te=50;

void main(void){
    OSCCON  = 0x38;
    OSCTUNE = 0x00;
    BORCON  = 0x00;
    
    decoInit();
    
    ANSELD = 0x00;
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    
    LATDbits.LATD0 = 0;
    LATDbits.LATD0 = 0;
    
    
    while(1){
        
        decenas = counter  / 10;
        unidades = counter % 10;
        
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 0;
        decoCC(decenas);
        
        __delay_ms(te);
        
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        decoCC(unidades);
        
        __delay_ms(te);
        
        
        counter++;
        if(counter==99){
            counter=0;
        }
        
    
    }
    return;
}
