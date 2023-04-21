#include "LCD_LIB.h"
#include "config.h"
#include <stdint.h>

static uint8_t _lcd_params;

void _write_nibble(uint8_t nibble);
void _send_byte(uint8_t value, uint8_t mode);

void _write_nibble(uint8_t nibble){
    if( (nibble & 0x01) == 0) _LCD_PORT &= ~(1<<_LCD_D4); else _LCD_PORT |= (1<<_LCD_D4);
    if( (nibble & 0x02) == 0) _LCD_PORT &= ~(1<<_LCD_D5); else _LCD_PORT |= (1<<_LCD_D5);
    if( (nibble & 0x04) == 0) _LCD_PORT &= ~(1<<_LCD_D6); else _LCD_PORT |= (1<<_LCD_D6);
    if( (nibble & 0x08) == 0) _LCD_PORT &= ~(1<<_LCD_D7); else _LCD_PORT |= (1<<_LCD_D7);
    
    _LCD_PORT &= ~(1<<_LCD_EN);
    _LCD_PORT |=  (1<<_LCD_EN);
    _LCD_PORT &= ~(1<<_LCD_EN);
    
    __delay_us(300);
}

void  _send_byte(uint8_t value, uint8_t mode){
    
    switch(mode){
        case _COMMAND_: _LCD_PORT &= ~(1<<_LCD_RS); break;
        case _DATA_:    _LCD_PORT |=  (1<<_LCD_RS); break;
    }
    _write_nibble(value>>4);
    _write_nibble(value&0x0F);
}

void lcd_write(uint8_t letra){
    _send_byte(letra,_DATA_);
}
void lcd_command(uint8_t cmd){
    _send_byte(cmd,_COMMAND_);
}

void lcd_init(){
    
    _LCD_DDR &= ~( (1<<_LCD_RS)|
                   (1<<_LCD_EN)|
                   (1<<_LCD_D4)|
                   (1<<_LCD_D5)|
                   (1<<_LCD_D6)|
                   (1<<_LCD_D7));
    
    _LCD_PORT &= ~( (1<<_LCD_RS)|
                   (1<<_LCD_EN)|
                   (1<<_LCD_D4)|
                   (1<<_LCD_D5)|
                   (1<<_LCD_D6)|
                   (1<<_LCD_D7));
    
    
   
    __delay_ms(15);
    _write_nibble(0x03);
    __delay_ms(5);
    _write_nibble(0x03);
    __delay_us(100);
    _write_nibble(0x03);
    _write_nibble(0x02);
    
    lcd_command( _LCD_FUNTIONSET | _LCD_4BITMODE | _LCD_2LINE | _LCD_5x8DOTS );
    __delay_us(37);
    
    _lcd_params = _LCD_DISPLAY_ON | _LCD_CURSOR_ON | _LCD_BLINK_ON;
    lcd_command(_LCD_DISPLAYCONTROL | _lcd_params);
    __delay_us(37);
    
    lcd_command(_LCD_CLEARDISPLAY);
    __delay_ms(2);
}

 

void lcd_puts(char *str){
    while(*str){
        lcd_write(*str);
        str++;
    } 
}

void lcd_set_cursor(uint8_t row, uint8_t col){
	
	switch(row){
        case 1:  lcd_command(0x80+col-1); break;
        case 2:  lcd_command(0xC0+col-1); break;
        case 3:  lcd_command(0x94+col-1); break;
        case 4:  lcd_command(0xD4+col-1); break;
    }
}


void lcd_clear(void){
	lcd_command(_LCD_CLEARDISPLAY);
	_delay_ms(2);
}
void lcd_return_home(void){
	lcd_command(_LCD_RETURNHOME);
	_delay_ms(2);
}

void lcd_on(void){
	_lcd_params |=  _LCD_DISPLAY_ON;
	lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void lcd_off(void){
	_lcd_params &=  ~_LCD_DISPLAY_ON;
	lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void lcd_enable_blink(void){
	_lcd_params |= _LCD_BLINK_ON;
	lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void lcd_disable_blink(void){
	_lcd_params &= ~_LCD_BLINK_ON;
	lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void lcd_enable_cursor(void){
	_lcd_params |= _LCD_CURSOR_ON;
	lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void lcd_disable_cursor(void){
	_lcd_params &= ~_LCD_CURSOR_ON;
	lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void lcd_scroll_left(void){
	 lcd_command(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVELEFT);
	 _delay_us(37);
}
void lcd_scroll_right(void){
	 lcd_command(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVERIGHT);
	 _delay_us(37);
}

void lcd_custom_char(uint8_t mem, uint8_t *charmap){
	lcd_command(_LCD_SET_CGRAM_ADDR |  ((mem&0x07)<<3) );
	for(uint8_t i=0; i<=7; i++){
		lcd_write(charmap[i]);
	}
	lcd_command(_LCD_SET_DDRAM_ADDR);
	_delay_us(37);
}
void lcd_out(char row, char col, char *str){
    lcd_set_cursor(row,col);
    while(*str){
        lcd_write(*str);
        str++;
    } 
    
}
void lcd_char(char row, char col, char letra){
    lcd_set_cursor(row,col);
    lcd_write(letra);
}
