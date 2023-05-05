/* 
 * File:   ADC_LIB.h
 * Author: iProf
 *
 * Created on March 17, 2023, 8:53 AM
 */

#ifndef ADC_LIB_H
#define	ADC_LIB_H

#include <stdint.h>

#define TAD_20  7
#define TAD_16  6
#define TAD_12  5
#define TAD_8   4
#define TAD_6   3
#define TAD_4   2
#define TAD_2   1
#define TAD_0   0

#define FOSC_64  6
#define FOSC_16  5
#define FOSC_4   4
#define FOSC_32  2
#define FOSC_8   1
#define FOSC_2   0

#define ADC_TAD TAD_20
#define ADC_AQC FOSC_64   

void ADC_Init(void);
int ADC_Read(uint8_t channel);
float ADC_MAP(int conver, float xi, 
                          float xf,
                          float yi,
                          float yf);



#endif	/* ADC_LIB_H */

