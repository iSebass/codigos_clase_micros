#include <pic18f4550.h>

#include "I2C_LIB.h"


void I2C_Init(void){
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    
    SSPSTATbits.SMP   = 1;
    SSPCON1bits.SSPEN = 1;
    SSPCON1bits.SSPM  = 0b1000;
    
    SSPADD =  (unsigned int)((_XTAL_FREQ/(4.0*SCL_CLOCK))-1.0);
    
    SSPCON2 = 0x00;
}
void I2C_Condiciones_Espera(void){
    while( (SSPCON2 & 0x1F) || (SSPSTAT & 0x04) );
}
void I2C_Start(void){
    I2C_Condiciones_Espera();
    SSPCON2bits.SEN = 1;
}
void I2C_Stop(void){
    I2C_Condiciones_Espera();
    SSPCON2bits.PEN = 1;
}
void I2C_Restart(void){
    I2C_Condiciones_Espera();
    SSPCON2bits.RSEN = 1;
}
void I2C_Wr(unsigned char data){
    I2C_Condiciones_Espera();
    SSPBUF = data;
}
char I2C_Rd(void){
    unsigned char datoR;
    I2C_Condiciones_Espera();
    SSPCON2bits.RCEN = 1;
    I2C_Condiciones_Espera();
    datoR = SSPBUF;
    I2C_Condiciones_Espera();
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1;
    return datoR;
}