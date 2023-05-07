#include "pin_manager.h"
void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATF = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISF = 0xFF;
    TRISA = 0xFF;
    TRISB = 0xF9;
    TRISC = 0xFF;
    TRISD = 0xFF;

    /**
    ANSELx registers
    */
    ANSELD = 0xFF;
    ANSELC = 0xFF;
    ANSELB = 0xF9;
    ANSELE = 0x07;
    ANSELF = 0xFF;
    ANSELA = 0xFF;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUF = 0x00;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    RxyI2C registers
    */
    RB1I2C = 0x00;
    RB2I2C = 0x00;
    RC3I2C = 0x00;
    RC4I2C = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONF = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x06;
    ODCONC = 0x18;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;
    SLRCONF = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0x0F;
    INLVLF = 0xFF;
    
    I2C1SDAPPS = 0x0A;   //RB2->I2C1:SDA1;    
    RB1PPS = 0x37;   //RB1->I2C1:SCL1;    
    RB2PPS = 0x38;   //RB2->I2C1:SDA1;    
    I2C1SCLPPS = 0x09;   //RB1->I2C1:SCL1;    
}
  
void PIN_MANAGER_IOC(void)
{   
}
