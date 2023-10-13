/* 
 * File:   ADC_LIB.h
 * Author: iProf
 *
 * Created on October 5, 2023, 7:29 PM
 */

#ifndef ADC_LIB_H
#define	ADC_LIB_H

#include <xc.h>
#include "config.h"

void ADC_Init(void);
int ADC_Read(char ch);

#endif	/* ADC_LIB_H */

