/* 
 * File:   LCD_LIB.h
 * Author: iProf
 *
 * Created on 1 de septiembre de 2023, 08:06 AM
 */

#ifndef LCD_LIB_H
#define	LCD_LIB_H

#include <xc.h>
#include <stdint.h>
#include "config.h"
#include "I2C_LIB.h"

#define _delay_ms(x)   __delay_ms(x)
#define _delay_us(x)   __delay_us(x)



/************************************************************************/
/* Comportamiento de RS                                                 */
/************************************************************************/
#define _COMMAND_      0
#define _DATA_         1

/************************************************************************/
/* DEFINIR EL PUERTO DONDE SE VA CONECTAR LA LCD                        */
/************************************************************************/
#define _LCD_RS    0
#define _LCD_RW    1
#define _LCD_EN    2
#define _LCD_LED   3
#define _LCD_D4    4
#define _LCD_D5    5
#define _LCD_D6    6
#define _LCD_D7    7

/*
 */

#define __LCD_CLEAR             1
#define __LCD_RETURN_HOME       2
#define __LCD_BLINK_CURSOR_ON   15
#define __LCD_CURSOR_OFF        12
#define __LCD_UNDERLINE_ON      14
#define __LCD_FIRST_ROW         128
#define __LCD_SECOND_ROW        192
#define __LCD_THIRD_ROW         148
#define __LCD_FOURTH_ROW        212
#define __LCD_MOVE_CURSOR_LEFT  16
#define __LCD_MOVE_CURSOR_RIGHT 20
#define __LCD_TURN_OFF          8
#define __LCD_TURN_ON           15
#define __LCD_SHIFT_LEFT        24
#define __LCD_SHIFT_RIGHT       28

/************************************************************************/
/*  MODO CELAR DISPLAY:  D7 D6 D5 D4 D3 D2 D1 D0                        */
/*                       0  0  0  0  0  0  0  1                         */
/************************************************************************/
#define _LCD_CLEARDISPLAY 0x01

/************************************************************************/
/*  MODO CELAR RETURN HOME:  D7 D6 D5 D4 D3 D2 D1 D0                    */
/*                           0  0  0  0  0  0  1  0                     */
/************************************************************************/
#define _LCD_RETURNHOME     0x02

/************************************************************************/
/*      ENTRAMOS EN MODE SET:  D7 D6 D5 D4 D3 D2 D1  D0                 */
/*      					   0  0  0  0  0  1  I/D  S                 */
/*----------------------------------------------------------------------*/
/*      I/D = 1: Inc                                                    */
/*		      0: Dec                                                    */
/*		S   = 1: SHIFT ON                                               */
/*            0: SHIFT OFF                                              */
/************************************************************************/
#define _LCD_ENTRYMODESET   0x04
#define _LCD_INCREMENT      0x02
#define _LCD_DECREMENT      0x00
#define _LCD_SHIFT_ON       0x01
#define _LCD_SHIFT_OFF      0x00

/************************************************************************/
/*      ENTRAMOS EN DISPLAY CONTROL:  D7 D6 D5 D4  D3 D2 D1 D0          */
/*      						      0  0  0  0   1  D  U  B           */
/*----------------------------------------------------------------------*/
/*      D   = 1: DISPLAY ON                                             */
/*		      0: DISPLAY OFF                                            */
/*		U   = 1: CURSOR ON                                              */
/*		      0: CURSOR OFF                                             */
/*		B   = 1: BLINK                                                  */
/*		      0: NO BLINK                                               */
/************************************************************************/
#define _LCD_DISPLAYCONTROL 0x08
#define _LCD_DISPLAY_ON     0x04
#define _LCD_DISPLAY_OFF    0x00
#define _LCD_CURSOR_ON      0x02
#define _LCD_CURSOR_OFF     0x00
#define _LCD_BLINK_ON       0x01
#define _LCD_BLINK_OFF      0x00

/************************************************************************/
/* ENTRAMOS EN CURSOR OR DISPLAY SHIFT:  D7 D6 D5 D4  D3 D2  D1 D0      */
/*      						         0  0  0  1  S/C R/L  *  *      */
/*----------------------------------------------------------------------*/
/*      S/C = 1: display shift                                          */
/*		      0: cursor move                                            */
/*		R/L = 1: shift to the right                                     */
/*		      0: shift to the left                                      */
/************************************************************************/
#define _LCD_CURSORDISPLAYSHIFT 0x10
#define _LCD_DISPLAY_SHIFT      0x08
#define _LCD_CURSOR_SHIFT       0x00
#define _LCD_MOVERIGHT          0x04
#define _LCD_MOVELEFT           0x00

/************************************************************************/
/*      ENTRAMOS EN FUNTIONS SET:  D7 D6 D5 D4  D3 D2 D1 D0             */
/*      						   0  0  1  D/L  N  F  *  *             */
/*----------------------------------------------------------------------*/
/*      D/L = 1: modo 8 bits                                            */
/*		      0: modo 4 btis                                            */
/*		N   = 1: MODO 2 Lineas                                          */
/*		      0: MODO 1 Linea                                           */
/*		F   = 1: MATRIZ 5x10                                            */
/*		      0: MATRIZ 5x7/5x8                                         */
/************************************************************************/
#define _LCD_FUNTIONSET 0x20
#define _LCD_8BITMODE   0x10
#define _LCD_4BITMODE   0x00
#define _LCD_2LINE      0x08
#define _LCD_1LINE      0x00
#define _LCD_5x10DOTS   0x04
#define _LCD_5x8DOTS    0x00


/************************************************************************/
/*      SET CGRAM:  D7 D6  D5  D4   D3   D2   D1   D0                   */
/*      			0  1   ACG ACG  ACG  ACG  ACG  ACG                  */
/*----------------------------------------------------------------------*/
/*      ACG -> CGRAM ADDRESS                                            */
/************************************************************************/
#define _LCD_SET_CGRAM_ADDR  0x40

/************************************************************************/
/*      SET DDRAM:  D7 D6  D5  D4   D3   D2   D1   D0                   */
/*      			1  0   ADD ADD  ADD  ADD  ADD  ADD                  */
/*----------------------------------------------------------------------*/
/*      ADD -> DDRAM ADDRESS                                            */
/************************************************************************/
#define _LCD_SET_DDRAM_ADDR  0x80

/*
 * METODOS DE I2C
 */
void PCF_Wr(char dato);
void loadPCF(char dato, char mode);
void sendDATA(char dato);
void sendCMD(char cmd);

// Cremos el prototipo de funcion
void I2C_LCD_Init(void);
void I2C_LCD_Cmd(char cmd);
void I2C_LCD_Write_Cp(char letra);
void I2C_LCD_Write_Text_Cp(char *text);
void I2C_LCD_Set_Cursor(char fila, char col);
void I2C_LCD_Write(char fila, char col, char letra);
void I2C_LCD_Write_Text(char fil, char col, char *text);



#endif	/* LCD_LIB_H */