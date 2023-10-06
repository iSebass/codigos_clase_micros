#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "LCD_LIB.h"
#include "ADC_LIB.h"


int conver;
char txtLCD[20]=" ";

void main(void){
    
    ANSELAbits.ANSA0 = 1;
    TRISAbits.TRISA0 = 1;

    lcd_init();
    lcd_disable_blink();
    lcd_disable_cursor();
    ADC_Init();
    while(1){
        conver = ADC_Read(0);
        sprintf(txtLCD,"Conver: %04d", conver);
        lcd_out(1,1,txtLCD);
        __delay_ms(10);
    }
    return;
}
