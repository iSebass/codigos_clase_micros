#include "mcc_generated_files/mcc.h"

char contador=0, unidades, decenas;

const unsigned char digitos[10] = {
    0x3F, // 0 0b0011 1111
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

#define DIR_DP1  0b0100000<<0
#define DIR_DP2  0b0100001<<0

int statusbtn=0;

void main(void)
{
    SYSTEM_Initialize();
   
    while (1){
        unidades = contador % 10;
        decenas  = contador / 10;
        I2C_Write1ByteRegister(DIR_DP1, 0, digitos[unidades]);
        I2C_Write1ByteRegister(DIR_DP2, 0, digitos[decenas]);
        
        statusbtn=I2C_Rd(DIR_DP1);
        statusbtn = ( statusbtn& 0b10000000 ) >> 7;
        __delay_ms(100);
        if(statusbtn)
            contador++;
        else
            contador--;
        
        if(contador==100)
            contador=0;
        
        if(contador==255)
            contador = 99;
        
        
        
    }
}
