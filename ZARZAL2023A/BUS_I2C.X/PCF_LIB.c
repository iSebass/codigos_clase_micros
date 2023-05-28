#include "PCF_LIB.h"

void PCF8574_Wr(char dir, char data){
    dir = ((0b0100<<3)|dir)<<1;
    I2C_Start();
    I2C_Wr( dir | 0 );
    I2C_Wr(data);
    I2C_Stop();
}
void PCF8574A_Wr(char dir, char data){
    dir = ((0b0111<<3)|dir)<<1;
    I2C_Start();
    I2C_Wr( dir | 0 );
    I2C_Wr(data);
    I2C_Stop();
}
char PCF8574_Rd(char dir){
    char  dato;
    dir = ((0b0100<<3)|dir)<<1;
    I2C_Start();
    I2C_Wr( dir | 1 );
    dato = I2C_Rd();
    I2C_Stop();
    
    return dato;
}
char PCF8574A_Rd(char dir){
    char  dato;
    dir = ((0b0111<<3)|dir)<<1;
    I2C_Start();
    I2C_Wr( dir | 1 );
    dato = I2C_Rd();
    I2C_Stop();
    
    return dato;
    
}
