#include <xc.h>
#include "config.h"

void secuencia_A();
void secuencia_B();
void secuencia_C();

void main(void){
    //CONFIGURACION DEL RELOJ PRIMARIO
    OSCCON  = 0x38;
    OSCTUNE = 0x00;
    BORCON  = 0x00;
    
    //CONFIGURAR LA APP
    ANSELD = 0x00;
    TRISD  = 0b00000000;
    //LOOP 
    while(1){
        for(int i=0; i<=6; i++){
            secuencia_A();
        }
        
        __delay_ms(200);
        for(int i=0; i<=6; i++){
            secuencia_B();
        }
        __delay_ms(200);
        for(int i=0; i<=6; i++){
            secuencia_C();
        }
        __delay_ms(200);
    }
}


void secuencia_A(){
    LATD = 0b10101010;
    __delay_ms(200);
    LATD = 0b01010101;
    __delay_ms(200);
}
void secuencia_B(){
    LATD = 0xF0;
    __delay_ms(200);
    LATD = 0x0F;
    __delay_ms(200);
}
void secuencia_C(){
    LATD =  0b10000001;
    __delay_ms(200);
    LATD =  0b11000011;
    __delay_ms(200);
    LATD =  0b11101111;
    __delay_ms(200);
    LATD =  0b11111111;
    __delay_ms(200);
    LATD =  0b11101111;
    __delay_ms(200);
    LATD =  0b11000111;
    __delay_ms(200);
    LATD =  0b10000001;
    __delay_ms(200);
    
}