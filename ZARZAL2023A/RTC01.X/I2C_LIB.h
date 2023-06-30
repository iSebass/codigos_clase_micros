#ifndef I2C_LIB_H
#define	I2C_LIB_H

#include <xc.h>
#include "config.h"

#define SCL_CLOCK 100000UL

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_Wr(unsigned char data);
char I2C_Rd(void);


void I2C_Condiciones_Espera(void);


#endif	/* I2C_LIB_H */

