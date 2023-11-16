#include <xc.h>
#include "config.h"
#include "I2C_LIB.h"
#include "I2C_LCD_LIB.h"



void main(void){
    
    OSCCON  = 0x38;
    OSCTUNE = 0x00;
    BORCON  = 0x00;
    

    
    I2C_LCD_Init();
    
    I2C_LCD_Write_Text(1,1,"Grupo UV");
            
    
    ANSELD = 0x00;
    TRISD = 0x00;
    
    while(1){
      
        
    }
    return;
}
