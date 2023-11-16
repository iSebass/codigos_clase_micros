/* 
 * File:   I2C_LIB.h
 * Author: iProf
 *
 * Created on 26 de octubre de 2023, 07:09 PM
 */

#ifndef I2C_LIB_H
#define	I2C_LIB_H

#include <xc.h>
#include "config.h"

#define SSP_ADD_VAL 19

#define SCL_DIR   TRISCbits.TRISC3
#define SDA_DIR   TRISCbits.TRISC4

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_Wr(unsigned char data);
char I2C_Rd(void);


void I2C_BusStatus(void);

#endif	/* I2C_LIB_H */

