#include <xc.h>
#include "config.h"
#include "I2C_LIB.h"
#include "LCD_I2C_LIB.h"



void main(void){
   
    ADCON1 = 0x0F;
    
    
    I2C_Init();
    
    i2c_lcd_init();
    
    i2c_lcd_set_cursor(1,1);
    i2c_lcd_puts("EN PCB SI ");
    
    
    i2c_lcd_set_cursor(2,1);
    i2c_lcd_puts(" FUNCIONA :)");
    
    
    TRISDbits.TRISD0 = 0;
    PORTDbits.RD0 = 1;
    
    
  

    while(1){
        
        
        
        PORTDbits.RD0 ^= 1;
        __delay_ms(1000);
       
        
    }
    
    return;
}
