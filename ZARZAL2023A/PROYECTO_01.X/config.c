

// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include "CONFIG.h"



char strLCD[20]=" ";

extern enum{
    menuPAL=1,
    menuSelMotor,
    menuFuncM1,
    menuFuncM2,
    menuSen
};

extern int currentMenu=menuPAL;
int menuOp=1;


void SystemInit(void){
    ADCON1 = 12;
    ADC_Init();
    lcd_init();
    lcd_disable_blink();
    lcd_disable_cursor();
    BTN_UP_DIR   = IN;
    BTN_DOWN_DIR = IN;
    BTN_SEL_DIR  = IN;
    MOTOR_A1_DIR = OUT;
    MOTOR_A2_DIR = OUT;
    MOTOR_B1_DIR = OUT;
    MOTOR_B2_DIR = OUT;
    
}

void girarMA_Derecha(void){
    MOTOR_A1_PORT = HIGH;
    MOTOR_A2_PORT = LOW;
}
void girarMA_Izquierda(void){
    MOTOR_A1_PORT = LOW;
    MOTOR_A2_PORT = HIGH;
}
void pararMA(void){
    MOTOR_A1_PORT = LOW;
    MOTOR_A2_PORT = LOW;
}

void girarMB_Derecha(void){
    MOTOR_B1_PORT = HIGH;
    MOTOR_B2_PORT = LOW;
}
void girarMB_Izquierda(void){
    MOTOR_B1_PORT = LOW;
    MOTOR_B2_PORT = HIGH;
}
void pararMB(void){
    MOTOR_B1_PORT = LOW;
    MOTOR_B2_PORT = LOW;
}

float getLM35(void){
    int conver;
    conver = ADC_Read(LM35_SENSOR);
    return (0.48875*conver);
}
float getMCP(void){
    int conver;
    conver = ADC_Read(MCP_SENSOR);
    return (0.48875*conver-50.0);
}
float getPOT(void){
    int conver;
    conver = ADC_Read(POT1_SENSOR);
    return (0.0048875*conver);
}


void menuPPAL(void){
    lcd_out(1,1,"   MENU PRINCIPAL   ");
    lcd_out(2,1,"1.MOTOR             ");
    lcd_out(3,1,"2.SENSORES          ");
    lcd_out(4,1,"OP:");
    
    switch(menuOp){
        case 1: lcd_char(2,8,'<');
                lcd_char(3,11,' ');
                break;
        case 2: lcd_char(2,8,' ');
                lcd_char(3,11,'<');
                break;
    }
    
    if(BTN_UP_PORT== 0){
        while(BTN_UP_PORT==0);
        menuOp += 1;
        if(menuOp>2){
            menuOp=2;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_DOWN_PORT== 0){
        while(BTN_DOWN_PORT==0);
        menuOp -= 1;
        if(menuOp<1){
            menuOp=1;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_SEL_PORT == 0){
        while(BTN_SEL_PORT == 0);
        switch(menuOp){
            case 1: currentMenu = menuSelMotor; break;
            case 2: currentMenu = menuSen; break;
            
        }
        lcd_clear();
        menuOp=1;
    }
    
}
void menuSelM(void){
    lcd_out(1,1,"  MENU SEL MOTOR    ");
    lcd_out(2,1,"1. M1     2. M2     ");
    lcd_out(3,1,"3. BACK         ");
    lcd_out(4,1,"OP:");
    
    switch(menuOp){
        case 1: lcd_char(2,6,'<');
                lcd_char(2,16,' ');
                lcd_char(3,8,' ');
                break;
        case 2: lcd_char(2,6,' ');
                lcd_char(2,16,'<');
                lcd_char(3,8,' ');
                break;
        case 3: lcd_char(2,6,' ');
                lcd_char(2,16,' ');
                lcd_char(3,8,'<');
                break;
    }
    
    if(BTN_UP_PORT== 0){
        while(BTN_UP_PORT==0);
        menuOp += 1;
        if(menuOp>3){
            menuOp=1;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_DOWN_PORT== 0){
        while(BTN_DOWN_PORT==0);
        menuOp -= 1;
        if(menuOp<1){
            menuOp=3;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_SEL_PORT == 0){
        while(BTN_SEL_PORT == 0);
        switch(menuOp){
            case 1: currentMenu = menuFuncM1; break;
            case 2: currentMenu = menuFuncM2; break;
            case 3: currentMenu = menuPAL; break;
            
        }
        lcd_clear();
        menuOp=1;
    }
    
    
}
void menuM1(void){
    lcd_out(1,1,"  MENU MOTOR 1      ");
    lcd_out(2,1,"1.GirarD   2.GirarI ");
    lcd_out(3,1,"3.Parar    4. BACK  ");
    lcd_out(4,1,"OP:");
    
    switch(menuOp){
        case 1: lcd_char(2,9,'<');
                lcd_char(2,20,' ');
                lcd_char(3,8,' ');
                lcd_char(3,20,' ');
                break;
        case 2: lcd_char(2,9,' ');
                lcd_char(2,20,'<');
                lcd_char(3,8,' ');
                lcd_char(3,20,' ');
                break;
        case 3: lcd_char(2,9,' ');
                lcd_char(2,20,' ');
                lcd_char(3,8,'<');
                lcd_char(3,20,' ');
                break;
        case 4: lcd_char(2,9,' ');
                lcd_char(2,20,' ');
                lcd_char(3,8,' ');
                lcd_char(3,20,'<');
                break;
    }
    
    if(BTN_UP_PORT== 0){
        while(BTN_UP_PORT==0);
        menuOp += 1;
        if(menuOp>4){
            menuOp=1;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_DOWN_PORT== 0){
        while(BTN_DOWN_PORT==0);
        menuOp -= 1;
        if(menuOp<1){
            menuOp=4;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_SEL_PORT == 0){
        while(BTN_SEL_PORT == 0);
        switch(menuOp){
            case 1: girarMA_Derecha(); break;
            case 2: girarMA_Izquierda(); break;
            case 3: pararMA(); break;
            case 4: currentMenu = menuSelMotor; break;
            
        }
        lcd_clear();
        menuOp=1;
    }
    
    
    
}
void menuM2(void){
    lcd_out(1,1,"  MENU MOTOR 2      ");
    lcd_out(2,1,"1.GirarD   2.GirarI ");
    lcd_out(3,1,"3.Parar    4. BACK  ");
    
     lcd_out(4,1,"OP:");
    
    switch(menuOp){
        case 1: lcd_char(2,9,'<');
                lcd_char(2,20,' ');
                lcd_char(3,8,' ');
                lcd_char(3,20,' ');
                break;
        case 2: lcd_char(2,9,' ');
                lcd_char(2,20,'<');
                lcd_char(3,8,' ');
                lcd_char(3,20,' ');
                break;
        case 3: lcd_char(2,9,' ');
                lcd_char(2,20,' ');
                lcd_char(3,8,'<');
                lcd_char(3,20,' ');
                break;
        case 4: lcd_char(2,9,' ');
                lcd_char(2,20,' ');
                lcd_char(3,8,' ');
                lcd_char(3,20,'<');
                break;
    }
    
    if(BTN_UP_PORT== 0){
        while(BTN_UP_PORT==0);
        menuOp += 1;
        if(menuOp>4){
            menuOp=1;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_DOWN_PORT== 0){
        while(BTN_DOWN_PORT==0);
        menuOp -= 1;
        if(menuOp<1){
            menuOp=4;
        }
        lcd_char(4,5,menuOp+48);
    }
    if(BTN_SEL_PORT == 0){
        while(BTN_SEL_PORT == 0);
        switch(menuOp){
            case 1: girarMB_Derecha(); break;
            case 2: girarMB_Izquierda(); break;
            case 3: pararMB(); break;
            case 4: currentMenu = menuSelMotor; break;
            
        }
        lcd_clear();
        menuOp=1;
    }
    
}
void menuSensores(void){
    
}