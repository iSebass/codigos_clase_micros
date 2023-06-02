#include <xc.h>
#include "config.h"

void main(void){
    //CONFIGURAMOS EL OSCILADOR DE 8MHZ PLL x4 = 32MHZ
    OSCCON = 0xF2;
    
    while(1){
        
        
    }
    return;
}
