#include "mcc_generated_files/mcc.h"

void girarM1Derecha();
void girarM1Izquierda();
void pararM1();

void girarM2Derecha();
void girarM2Izquierda();
void pararM2();


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    PORTB = 0x0F;

    while (1)
    {
        if( BTNA_GetValue() == 0 && BTNB_GetValue() == 0 ){
            pararM1();
            pararM2();
        }
        if( BTNB_GetValue() == 0 && BTNA_GetValue() == 1 ){
            girarM1Derecha();
            girarM2Izquierda();
        }
        if( BTNB_GetValue() == 1 && BTNA_GetValue() == 0 ){
            girarM2Derecha();
            girarM1Izquierda();
        }
        if( BTNB_GetValue() == 1 && BTNA_GetValue() == 1 ){
            girarM2Izquierda();
            girarM1Izquierda();
        }
        PORTB = ~PORTB;
        __delay_ms(500);
    }
}

void girarM1Derecha(){
    ENA1_SetHigh();
    ENA2_SetLow();
}
void girarM1Izquierda(){
    ENA2_SetHigh();
    ENA1_SetLow();
}

void girarM2Derecha(){
    ENB1_SetHigh();
    ENB2_SetLow();
}
void girarM2Izquierda(){
     ENB2_SetHigh();
     ENB1_SetLow();
}
void pararM1(){
    ENA1_SetLow();
    ENA2_SetLow();
}

void pararM2(){
    ENB1_SetLow();
    ENB2_SetLow();
}
