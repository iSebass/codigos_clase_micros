#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include "i2c_master.h"

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void WDT_Initialize(void);

#endif	/* MCC_H */
/**
 End of File
*/