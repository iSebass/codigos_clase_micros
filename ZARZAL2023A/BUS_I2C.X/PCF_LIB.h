/* 
 * File:   PCF_LIB.h
 * Author: iProf
 *
 * Created on 12 de mayo de 2023, 10:36 AM
 */

#ifndef PCF_LIB_H
#define	PCF_LIB_H

#include <xc.h>
#include "config.h"
#include "I2C_LIB.h"

void PCF8574_Wr(char dir, char data);
void PCF8574A_Wr(char dir, char data);
char PCF8574_Rd(char dir);
char PCF8574A_Rd(char dir);

#endif	/* PCF_LIB_H */

