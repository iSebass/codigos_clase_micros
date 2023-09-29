#include <xc.h>
#include "config.h"
#include "LCD_LIB.h"

void main(void){
    
    lcd_init();
    lcd_disable_blink();
    lcd_disable_cursor();
    
    lcd_out(2,3,"Univalle");
    
    while(1){
        
    }
    
    return;
}
