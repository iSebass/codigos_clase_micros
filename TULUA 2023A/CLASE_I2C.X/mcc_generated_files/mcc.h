
#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include "I2C_MCC.h"

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void PMD_Initialize(void);


#endif	