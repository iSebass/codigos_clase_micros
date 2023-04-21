

#include "mcc_generated_files/mcc.h"

void avanzar();
void girarD();
void girarI();
void giroIzqCentro();
void giroDerCentro();

int conver;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while(1){
        if(S1_GetValue() == 1){
            girarI();
            
        }
        else if(S3_GetValue() == 1){
            girarD();
            
        }
        conver = ADC_GetConversion(2);
        PWM4_LoadDutyValue(50);
        
    }
}

void avanzar(){
    A2_SetHigh();
    A1_SetLow();
    B1_SetHigh();
    B2_SetLow();
}


void giroIzqCentro(){
    A2_SetHigh();
    A1_SetLow();
    B2_SetHigh();
    B1_SetLow();
}
void giroDerCentro(){
    A1_SetHigh();
    A2_SetLow();
    B1_SetHigh();
    B2_SetLow();
    
}
void girarD(){
    A2_SetHigh();
    A1_SetLow();
    B1_SetLow();
    B2_SetLow();
}
void girarI(){
    A1_SetLow();
    A2_SetLow();
    B1_SetHigh();
    B2_SetLow();
}