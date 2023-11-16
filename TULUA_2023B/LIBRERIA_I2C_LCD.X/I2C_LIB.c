#include "I2C_LIB.h"

void I2C_Init(void){
    SCL_DIR = 1;
    SDA_DIR = 1;
    
    SSPCON1bits.SSPM = 0b1000; // MODO I2C CON FORMULA
    SSPSTATbits.SMP = 1; // SLEW RATE NONE
    SSPCON1bits.SSPEN = 1;
    
    SSPADD = SSP_ADD_VAL;
    
    SSPCON2 = 0x00;
    
}
void I2C_Start(void){
    I2C_BusStatus();
    SSPCON2bits.SEN = 1;
}
void I2C_Stop(void){
   I2C_BusStatus();
   SSPCON2bits.PEN = 1;
}
void I2C_Restart(void){
   I2C_BusStatus();
   SSPCON2bits.RSEN = 1;
}
void I2C_Wr(unsigned char data){
    I2C_BusStatus();
    SSPBUF = data; // Escribir datos en el búfer de transmisión
}
char I2C_Rd(void){
    unsigned char datoR;
    I2C_BusStatus();
    SSPCON2bits.RCEN = 1;
    I2C_BusStatus();
    datoR = SSPBUF;
    I2C_BusStatus();
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1;
    return datoR;
    
}
void I2C_BusStatus(void){
    while( (SSPCON2 & 0x1F) || (SSPSTAT & 0x04) );
}
