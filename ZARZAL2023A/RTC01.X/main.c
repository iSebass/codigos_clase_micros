#include <xc.h>
#include "config.h"
#include "I2C_LIB.h"
#include "DS1307LIB.h"



void main(void) {
    
    ADCON1 = 0x0F;
    
    I2C_Init();
    
    setHH(0x23);
    setMM(0x59);
    setSS(0x56);
    
    setDAY(LUNES);
    
    setYEAR(0x23);
    setMONTH(0x02);
    setDATE(0x28);
    
    
    while(1){
        
        
        
    }
    
    return;
}
