#include "ADC_LIB.h"

void ADC_Init(void){
    ADCON1bits.ADCS   = 0b110;
    ADCON1bits.ADNREF = 0;
    ADCON1bits.ADPREF = 0b00;
    ADCON0bits.ADON   = 1;
    ADCON1bits.ADFM   = 1;
}

int ADC_Read(char ch){
    ADCON0bits.CHS = ch&0b11111;
    ADCON0bits.GO_nDONE = 1;
    while(ADCON0bits.GO_nDONE == 1);
    return (ADRESH<<8 | ADRESL);
}
