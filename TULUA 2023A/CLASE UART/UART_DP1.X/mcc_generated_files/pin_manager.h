/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1939
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BTNA aliases
#define BTNA_TRIS                 TRISBbits.TRISB0
#define BTNA_LAT                  LATBbits.LATB0
#define BTNA_PORT                 PORTBbits.RB0
#define BTNA_WPU                  WPUBbits.WPUB0
#define BTNA_ANS                  ANSELBbits.ANSB0
#define BTNA_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define BTNA_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define BTNA_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define BTNA_GetValue()           PORTBbits.RB0
#define BTNA_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define BTNA_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define BTNA_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define BTNA_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define BTNA_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define BTNA_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set BTNB aliases
#define BTNB_TRIS                 TRISBbits.TRISB1
#define BTNB_LAT                  LATBbits.LATB1
#define BTNB_PORT                 PORTBbits.RB1
#define BTNB_WPU                  WPUBbits.WPUB1
#define BTNB_ANS                  ANSELBbits.ANSB1
#define BTNB_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BTNB_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BTNB_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BTNB_GetValue()           PORTBbits.RB1
#define BTNB_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BTNB_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BTNB_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BTNB_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BTNB_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define BTNB_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BTNC aliases
#define BTNC_TRIS                 TRISBbits.TRISB2
#define BTNC_LAT                  LATBbits.LATB2
#define BTNC_PORT                 PORTBbits.RB2
#define BTNC_WPU                  WPUBbits.WPUB2
#define BTNC_ANS                  ANSELBbits.ANSB2
#define BTNC_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BTNC_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BTNC_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BTNC_GetValue()           PORTBbits.RB2
#define BTNC_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BTNC_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BTNC_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BTNC_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BTNC_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BTNC_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/