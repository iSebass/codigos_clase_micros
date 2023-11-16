#include "I2C_LCD_LIB.h"
#include "I2C_LIB.h"
#include <stdint.h>

#define LEDON   (1<<_LCD_LED)
#define LEDOFF  0x00

static uint8_t _lcd_params;

static uint8_t LED_STATUS = LEDON;

char DIR_PCF=0x27;


void PCF_Wr(char dato){
    I2C_Start();
    I2C_Wr( DIR_PCF<<1 );
    I2C_Wr(dato | LED_STATUS);
    I2C_Stop();
}
void loadPCF(char dato, char mode){
    
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
void sendDATA(char dato){
    char nibbleH, nibbleL;
    
    nibbleH = (dato & 0xF0)<<0;
    nibbleL = (dato & 0x0F)<<4;
    
    loadPCF(nibbleH,_DATA_);
    loadPCF(nibbleL,_DATA_);
}
void sendCMD(char cmd){
    char nibbleH, nibbleL;
    
    nibbleH = (cmd & 0xF0)<<0;
    nibbleL = (cmd & 0x0F)<<4;
    
    loadPCF(nibbleH,_COMMAND_);
    loadPCF(nibbleL,_COMMAND_);
}


// Cremos el prototipo de funcion
void I2C_LCD_Init(void){
    I2C_Init();
    PCF_Wr(0x00);
    __delay_ms(15);
    sendCMD(0x03);
    __delay_ms(5);
    sendCMD(0x03);
    __delay_us(100);
    sendCMD(0x03);
    sendCMD(0x02);
    
    I2C_LCD_Cmd( _LCD_FUNTIONSET | _LCD_4BITMODE | _LCD_2LINE | _LCD_5x8DOTS );
    __delay_us(37);
    
    _lcd_params = _LCD_DISPLAY_ON | _LCD_CURSOR_ON | _LCD_BLINK_ON;
    I2C_LCD_Cmd(_LCD_DISPLAYCONTROL | _lcd_params);
    __delay_us(37);
    
    I2C_LCD_Cmd(_LCD_CLEARDISPLAY);
    __delay_ms(2);
}
void I2C_LCD_Cmd(char cmd){
    sendCMD(cmd);
}
void I2C_LCD_Write_Cp(char letra){
    sendDATA(letra);
}
void I2C_LCD_Write_Text_Cp(char *text){
    while(*text){
        I2C_LCD_Write_Cp(*text);
        text++;
    }
}
void I2C_LCD_Set_Cursor(char fila, char col){
    char pos;
    switch(fila){
        case 1: pos = 0x80+(col-1); break;
        case 2: pos = 0xC0+(col-1); break;
        case 3: pos = 0x94+(col-1); break;
        case 4: pos = 0xD4+(col-1); break;
    }
    I2C_LCD_Cmd(pos);
}
void I2C_LCD_Write(char fila, char col, char letra){
    I2C_LCD_Set_Cursor(fila, col);
    I2C_LCD_Write_Cp(letra);
}
void I2C_LCD_Write_Text(char fil, char col, char *text){
    I2C_LCD_Set_Cursor(fil, col);
    while(*text){
        I2C_LCD_Write_Cp(*text);
        text++;
    }
}
