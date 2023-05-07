#include "mcc_generated_files/mcc.h"
#include "LCD_I2C.h"

void main(void){
    
    SYSTEM_Initialize();
    i2c_lcd_init();
    i2c_lcd_puts("iSebas");
    TRISFbits.TRISF3 = 0;
    
    while(1){
        LATFbits.LATF3 ^= 1;
        
        __delay_ms(1000);
    }
}
