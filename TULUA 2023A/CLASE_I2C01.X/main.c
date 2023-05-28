#include "mcc_generated_files/mcc.h"
#include "LCD_I2C.h"



int statusbtn=0;

void main(void)
{
    SYSTEM_Initialize();
    
    i2c_lcd_init();
      
    
    while (1){
        
    }
}
