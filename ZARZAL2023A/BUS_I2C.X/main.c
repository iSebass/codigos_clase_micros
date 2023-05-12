#include <xc.h>
#include "config.h"
#include "I2C_LIB.h"

#define PCF1_DIR 0b0100111<<1

void main(void){
    
    ADCON1 = 0x0F;
    
    I2C_Init();
    
    while(1){
        I2C_Start();
        I2C_Wr(PCF1_DIR | 0);
        I2C_Wr(0x0F);
        I2C_Stop();
        __delay_ms(500);
        
        I2C_Start();
        I2C_Wr(PCF1_DIR | 0);
        I2C_Wr(0xF0);
        I2C_Stop();
        __delay_ms(500);
        
    }
    
    return;
}
