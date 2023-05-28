#include <xc.h>
#include "config.h"
#include "I2C_LIB.h"
#include "PCF_LIB.h"

char data;

void main(void){
    
    ADCON1 = 0x0F;
    
    I2C_Init();
    
    while(1){
        
        data = PCF8574A_Rd(0);
        PCF8574_Wr(0,data);
        __delay_ms(500);
        
    }
    
    return;
}
