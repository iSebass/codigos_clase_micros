#include "LCD_I2C.h"
#include <stdint.h>
#include <xc.h>

#define LED_LCD_ON    0b00001000
#define LED_LCD_OFF   0b00000000

static uint8_t statusLED = LED_LCD_ON;
static uint8_t paramsLCD;

void PCF_Wr(uint8_t dato){
    I2C1_Write1ByteRegister(DIR_PCF, 0, dato|statusLED );
}

void loadPCF(uint8_t dato, uint8_t mode){
    
    switch(mode){
        case _DATA_   : dato |=  (1<<LCD_RS); break;
        case _COMMAND_: dato &= ~(1<<LCD_RS); break;
    }
    
    
    PCF_Wr(dato);
    dato |=  (1<<LCD_E);
    PCF_Wr(dato);
    dato &=  ~(1<<LCD_E);
    PCF_Wr(dato);
    
    __delay_us(30);
    
}
void sendDATA(uint8_t dato){
    uint8_t NibbleH, NibbleL;
    NibbleH = (dato & 0xF0);
    NibbleL = (dato & 0x0F)<<4;
    loadPCF(NibbleH,_DATA_);
    loadPCF(NibbleL,_DATA_);
}
void sendCMD(uint8_t cmd){
     uint8_t NibbleH, NibbleL;
     NibbleH =  cmd & 0xF0;
     NibbleL = (cmd & 0x0F)<<4;
     loadPCF(NibbleH,_COMMAND_);
     loadPCF(NibbleL,_COMMAND_);
}

void i2c_lcd_init(void){
    
    PCF_Wr(0x00);
    __delay_ms(15);
    sendCMD(0x03);
    __delay_us(4100);
    sendCMD(0x03);
    __delay_us(100);
    sendCMD(0x03);
    sendCMD(0x02);
    
    sendCMD(_LCD_FUNTIONSET | _LCD_4BITMODE | _LCD_2LINE | _LCD_5x8DOTS);
    __delay_us(37);
    
    paramsLCD = _LCD_DISPLAY_ON | _LCD_CURSOR_ON | _LCD_BLINK_ON;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    __delay_us(37);
    
    sendCMD(_LCD_CLEARDISPLAY);
    __delay_ms(2);
    
    
}
void i2c_lcd_write(uint8_t letra){
    sendDATA(letra);
}
void i2c_lcd_command(uint8_t cmd){
    sendCMD(cmd);
}

void i2c_lcd_puts(char *str){
     
    while(*str){
        sendDATA(*str);
        str++;
    }
     
}
void i2c_lcd_set_cursor(uint8_t row, uint8_t col){
    static uint8_t local_mem[4]={0x00,0x40,0x14,0x54};
    sendCMD(_LCD_SET_DDRAM_ADDR | (local_mem[row-1]+(col-1) ) );
}

/*FUNCIONES DE LA LCD*/


void i2c_lcd_backlight_on(void){
    statusLED=LED_LCD_ON;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    
}
void i2c_lcd_backlight_off(void){
    statusLED=LED_LCD_OFF; 
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
     
}


void i2c_lcd_clear(void){
    sendCMD(_LCD_CLEARDISPLAY);
    __delay_ms(2);
}

void i2c_lcd_return_home(void){
    sendCMD(_LCD_RETURNHOME);
    __delay_ms(2);
}

void i2c_lcd_enable_blink(void){
    paramsLCD |= _LCD_BLINK_ON;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    __delay_us(37);
}
void i2c_lcd_disable_blink(void){
    paramsLCD &= ~_LCD_BLINK_ON;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    __delay_us(37);
}

void i2c_lcd_enable_cursor(void){
    paramsLCD |= _LCD_CURSOR_ON;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    __delay_us(37);
}
void i2c_lcd_disable_cursor(void){
    paramsLCD &= ~_LCD_CURSOR_ON;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    __delay_us(37);
}

void i2c_lcd_on(void){
    paramsLCD |= _LCD_DISPLAY_ON ;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    __delay_us(37);
}
void i2c_lcd_off(void){
    paramsLCD &= ~_LCD_DISPLAY_ON ;
    sendCMD(_LCD_DISPLAYCONTROL | paramsLCD);
    __delay_us(37);
}

void i2c_lcd_scroll_left(void){
    sendCMD(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVELEFT);
    __delay_us(37);
}
void i2c_lcd_scroll_right(void){
    sendCMD(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVERIGHT);
    __delay_us(37);
}

void i2c_lcd_custom_char(uint8_t mem, uint8_t *charmap){
    sendCMD(_LCD_SET_CGRAM_ADDR | ( (mem&0b111)<<3) ) ;
    for(char i=0; i<=7; i++){
        sendDATA(charmap[i]);
    }
    sendCMD(_LCD_SET_DDRAM_ADDR);
    __delay_us(37);
}
