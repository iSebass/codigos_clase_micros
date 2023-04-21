#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "ADC_LIB.h"
#include "LCD_LIB.h"

int conver;
float volt;
char strLCD[20]=" ";

void main(void){
    ADCON1bits.PCFG = 13;
    ADC_Init();
    lcd_init();
    lcd_disable_blink();
    lcd_disable_cursor();
    
    while(1){
        conver = ADC_Read(0);
        volt   = (5.0/1023.0)*conver;
        sprintf(strLCD,"volt: %3.1f",volt );
        lcd_out(1,1,strLCD);
    }
    return;
}
