#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "LCD_LIB.h"
#include "ADC_LIB.h"


int conver;
float pot, temp;
char txtLCD[20]=" ";

void main(void){
    
    ANSELAbits.ANSA0 = 1;
    TRISAbits.TRISA0 = 1;
    
    ANSELAbits.ANSA1 = 1;
    TRISAbits.TRISA1 = 1;

    lcd_init();
    lcd_disable_blink();
    lcd_disable_cursor();
    ADC_Init();
    while(1){
        conver = ADC_Read(0);
        pot = (5.0/1023.0)*conver;
        sprintf(txtLCD,"POT: %3.1f", pot);
        lcd_out(1,1,txtLCD);
        
        conver = ADC_Read(1);
        temp = (150.0/307.0)*conver;
        sprintf(txtLCD,"TEMP: %3.1f", temp);
        lcd_out(2,1,txtLCD);
        
        __delay_ms(10);
    }
    return;
}
