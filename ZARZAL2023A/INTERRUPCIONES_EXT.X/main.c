#include <xc.h>
#include "config.h"

int contador=0;

void __interrupt() External(){
    
    if( INTCONbits.INT0IF == 1 ){
        contador++;
        
        INTCONbits.INT0IF = 0;
    }
    
    if( INTCON3bits.INT1IF == 1 ){
        contador--;
        
        INTCON3bits.INT1IF = 0;
    }
    
}

void main(void){
    // CONFIGURAR LAS INTERRUPCIONES
    INTCONbits.GIE     = 1;
    INTCONbits.PEIE    = 1;
    INTCONbits.INT0IE  = 1;
    INTCON3bits.INT1IE = 1;
    
    //Configramos la entrada digital
    TRISBbits.TRISB0= 1;
    
    //Configuramos las salidas digitales
    TRISD = 0xF0;
    
    while(1){
        if(contador>15)
            contador=0;
        if(contador<0)
            contador=15;
        PORTD = contador;
        __delay_ms(100);
    }
    
    return;
}
