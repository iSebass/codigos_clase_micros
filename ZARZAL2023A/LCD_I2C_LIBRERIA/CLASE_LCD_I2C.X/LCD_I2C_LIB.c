#include "LCD_I2C_LIB.h"
#include "config.h"
#include "I2C_LIB.h"
#include <stdint.h>

#define LEDON   (1<<_LCD_LED)
#define LEDOFF  0x00

static uint8_t _lcd_params;

static uint8_t LED_STATUS = LEDON;

extern char DIR_PCF = 0x27;

void PCF_Wr(int8_t dato){
    I2C_Start();
    I2C_Wr( DIR_PCF<<1 );
    I2C_Wr(dato | LED_STATUS);
    I2C_Stop();
}
void loadPCF(int8_t dato, uint8_t mode){
    
    switch(mode){
        case _COMMAND_: dato &= ~(1<<_LCD_RS); break;
        case _DATA_:    dato |=  (1<<_LCD_RS); break;
    }
    
    PCF_Wr(dato);
    dato |= (1<<_LCD_EN);
    PCF_Wr(dato);
    dato &= ~(1<<_LCD_EN);
    PCF_Wr(dato);
    __delay_us(30);
    
    
}
void sendDATA(int8_t dato){
    char nibbleH, nibbleL;
    
    nibbleH = (dato & 0xF0)<<0;
    nibbleL = (dato & 0x0F)<<4;
    
    loadPCF(nibbleH,_DATA_);
    loadPCF(nibbleL,_DATA_);
}
void sendCMD(int8_t cmd){
    char nibbleH, nibbleL;
    
    nibbleH = (cmd & 0xF0)<<0;
    nibbleL = (cmd & 0x0F)<<4;
    
    loadPCF(nibbleH,_COMMAND_);
    loadPCF(nibbleL,_COMMAND_);
}

void i2c_lcd_write(uint8_t letra){
    sendDATA(letra);
}
void i2c_lcd_command(uint8_t cmd){
    sendCMD(cmd);
}

void i2c_lcd_init(){
    
    PCF_Wr(0x00);
    __delay_ms(15);
    sendCMD(0x03);
    __delay_ms(5);
    sendCMD(0x03);
    __delay_us(100);
    sendCMD(0x03);
    sendCMD(0x02);
    
    i2c_lcd_command( _LCD_FUNTIONSET | _LCD_4BITMODE | _LCD_2LINE | _LCD_5x8DOTS );
    __delay_us(37);
    
    _lcd_params = _LCD_DISPLAY_ON | _LCD_CURSOR_ON | _LCD_BLINK_ON;
    i2c_lcd_command(_LCD_DISPLAYCONTROL | _lcd_params);
    __delay_us(37);
    
    i2c_lcd_command(_LCD_CLEARDISPLAY);
    __delay_ms(2);
}

 

void i2c_lcd_puts(char *str){
    while(*str){
        i2c_lcd_write(*str);
        str++;
    } 
}

void i2c_lcd_set_cursor(uint8_t row, uint8_t col){
	
	switch(row){
        case 1:  i2c_lcd_command(0x80+col-1); break;
        case 2:  i2c_lcd_command(0xC0+col-1); break;
        case 3:  i2c_lcd_command(0x94+col-1); break;
        case 4:  i2c_lcd_command(0xD4+col-1); break;
    }
}


void i2c_lcd_clear(void){
	i2c_lcd_command(_LCD_CLEARDISPLAY);
	_delay_ms(2);
}
void i2c_lcd_return_home(void){
	i2c_lcd_command(_LCD_RETURNHOME);
	_delay_ms(2);
}

void i2c_lcd_on(void){
	_lcd_params |=  _LCD_DISPLAY_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void i2c_lcd_off(void){
	_lcd_params &=  ~_LCD_DISPLAY_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void i2c_lcd_enable_blink(void){
	_lcd_params |= _LCD_BLINK_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void i2c_lcd_disable_blink(void){
	_lcd_params &= ~_LCD_BLINK_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void i2c_lcd_enable_cursor(void){
	_lcd_params |= _LCD_CURSOR_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void i2c_lcd_disable_cursor(void){
	_lcd_params &= ~_LCD_CURSOR_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void i2c_lcd_scroll_left(void){
	 i2c_lcd_command(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVELEFT);
	 _delay_us(37);
}
void i2c_lcd_scroll_right(void){
	 i2c_lcd_command(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVERIGHT);
	 _delay_us(37);
}

void i2c_lcd_custom_char(uint8_t mem, uint8_t *charmap){
	i2c_lcd_command(_LCD_SET_CGRAM_ADDR |  ((mem&0x07)<<3) );
	for(uint8_t i=0; i<=7; i++){
		lcd_write(charmap[i]);
	}
	i2c_lcd_command(_LCD_SET_DDRAM_ADDR);
	_delay_us(37);
}
void i2c_lcd_out(char row, char col, char *str){
    i2c_lcd_set_cursor(row,col);
    while(*str){
        i2c_lcd_write(*str);
        str++;
    } 
    
}
void i2c_lcd_char(char row, char col, char letra){
    i2c_lcd_set_cursor(row,col);
    i2c_lcd_write(letra);
}

void i2c_lcd_backlight_on(void){
    LED_STATUS  = LEDON;
    PCF_Wr(LED_STATUS);
    
}
void i2c_lcd_backlight_off(void){
    LED_STATUS  = LEDOFF;
    PCF_Wr(LED_STATUS);
     
}
