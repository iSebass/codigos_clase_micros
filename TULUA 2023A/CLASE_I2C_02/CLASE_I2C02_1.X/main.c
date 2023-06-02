#include "mcc_generated_files/mcc.h"
#include "LCD_I2C.h"

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    i2c_lcd_init();

    while (1){
       
    }
}
/**
 End of File
*/