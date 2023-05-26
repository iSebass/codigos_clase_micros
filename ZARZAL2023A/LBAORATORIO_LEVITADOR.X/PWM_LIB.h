

#ifndef PWM_LIB_H
#define	PWM_LIB_H

#include "config.h"
#include <stdint.h>

#define CLK_DIV_1  0
#define CLK_DIV_4  1
#define CLK_DIV_16 2

#define _PRE_    CLK_DIV_16

void PWM1_Init(uint16_t freq);
void PWM2_Init(uint16_t freq);
void PWM1_Set_Duty(uint8_t duty);
void PWM2_Set_Duty(uint8_t duty);
void PWM1_Start(void);
void PWM2_Start(void);
void PWM1_Stop(void);
void PWM2_Stop(void);

#endif	/* PWM_LIB_H */

