#include <pic18f4550.h>

#include "PWM_LIB.h"

float reg10bits;

void PWM1_Init(uint16_t freq){
    
    uint8_t prees;
    
    switch(_PRE_){
        case CLK_DIV_1:  prees=1; break;
        case CLK_DIV_4:  prees=4; break;
        case CLK_DIV_16: prees=16; break;
    }
    
    //CONFIGURAMOS CCP1 COMO SALIDA
    TRISCbits.TRISC2 = 0;
    
    //Configurar el modulo CCP
    CCP1CONbits.CCP1M = 0b1100; //MODO PWM
    
    //CONFIGURAMOS EL PRE DEL TIMER2
    T2CONbits.T2CKPS = _PRE_; //PRE 16
    
    //CALCULAMOS EL VALOR DE PR2
    PR2 = (uint8_t)((_XTAL_FREQ / (4.0*freq*prees) ) - 1.0);
    
    reg10bits = (_XTAL_FREQ/(1.0*freq*prees));
    
    CCPR1L           = (int)(reg10bits)>>2;
    CCP1CONbits.DC1B = (int)(reg10bits)& 0x003;
}
void PWM2_Init(uint16_t freq){
    uint8_t prees;
    
    switch(_PRE_){
        case CLK_DIV_1:  prees=1; break;
        case CLK_DIV_4:  prees=4; break;
        case CLK_DIV_16: prees=16; break;
    }
    
    //CONFIGURAMOS CCP1 COMO SALIDA
    TRISCbits.TRISC1 = 0;
    
    //Configurar el modulo CCP
    CCP1CONbits.CCP1M = 0b1100; //MODO PWM
    
    //CONFIGURAMOS EL PRE DEL TIMER2
    T2CONbits.T2CKPS = _PRE_; //PRE 16
    
    //CALCULAMOS EL VALOR DE PR2
    PR2 = (uint8_t)((_XTAL_FREQ / (4.0*freq*prees) ) - 1.0);
    
    reg10bits = (_XTAL_FREQ/(1.0*freq*prees));
    
    CCPR2L           = (int)(reg10bits)>>2;
    CCP2CONbits.DC2B = (int)(reg10bits)& 0x003;
}
void PWM1_Set_Duty(uint8_t duty){
    float val = duty*reg10bits/100.0;
    CCPR1L           = (int)(val)>>2;
    CCP1CONbits.DC1B = (int)(val)& 0x003;
}
void PWM2_Set_Duty(uint8_t duty){
    
}
void PWM1_Start(void){
    T2CONbits.TMR2ON = 1;
}
void PWM2_Start(void);
void PWM1_Stop(void){
    T2CONbits.TMR2ON = 0;
}
void PWM2_Stop(void);
