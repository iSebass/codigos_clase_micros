#include <xc.h>
#include "ADC_LIB.h"

void ADC_Init(void){
    ADCON1bits.VCFG = 0b00; // Referencias 5v GND
    ADCON2bits.ADFM = 1;
    ADCON2bits.ADCS = ADC_AQC;  // FOSC/32
    ADCON2bits.ACQT = ADC_TAD;
    ADCON0bits.ADON = 1;
}
int ADC_Read(uint8_t channel){
    ADCON0bits.CHS = channel & 0x0F;
    ADCON0bits.GODONE = 1;
    while(ADCON0bits.GODONE == 1);
    return ( (ADRESH<<8) | (ADRESL<<0));
}

float ADC_MAP(int conver, float xi,float xf, float yi, float yf){
    float m;
    m = (yf-yi)/(xf-xi);
    return (m*conver-m*xi+yi);
    
}