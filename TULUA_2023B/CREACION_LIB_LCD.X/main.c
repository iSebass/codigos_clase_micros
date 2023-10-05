#include <xc.h>
#include "config.h"
#include "LCD_LIB.h"

char customChar1[] = {
  0b01110,
  0b10001,
  0b10001,
  0b11111,
  0b11011,
  0b11011,
  0b11111,
  0b11111
};

char customChar2[] = {
  0b00010,
  0b00110,
  0b11110,
  0b11110,
  0b11110,
  0b00110,
  0b00010,
  0b00000
};

void main(void){
    
    lcd_init();
    lcd_disable_blink();
    lcd_disable_cursor();
    
    lcd_custom_char(0,customChar1);
    lcd_custom_char(1,customChar2);
    
    lcd_out(2,3,"Univalle");
    lcd_char(3,1,0);
    lcd_write(1);
    
    while(1){
        
    }
    
    return;
}
