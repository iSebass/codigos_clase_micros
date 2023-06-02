#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    I2C_NOERR, // The message was sent.
    I2C_BUSY,  // Message was not sent, bus was busy.
    I2C_FAIL   // Message was not sent, bus failure
               // If you are interested in the failure reason,
               // Sit on the event call-backs.
} i2c_error_t;

typedef enum
{
    I2C_STOP=1,
    I2C_RESTART_READ,
    I2C_RESTART_WRITE,
    I2C_CONTINUE,
    I2C_RESET_LINK
} i2c_operations_t;

typedef uint8_t i2c_address_t;
typedef i2c_operations_t (*i2c_callback_t)(void *funPtr);

// common callback responses
i2c_operations_t I2C_CallbackReturnStop(void *funPtr);
i2c_operations_t I2C_CallbackReturnReset(void *funPtr);
i2c_operations_t I2C_CallbackRestartWrite(void *funPtr);
i2c_operations_t I2C_CallbackRestartRead(void *funPtr);

void I2C_Initialize(void);

i2c_error_t I2C_Open(i2c_address_t address);
i2c_error_t I2C_Close(void);
i2c_error_t I2C_MasterOperation(bool read);
i2c_error_t I2C_MasterWrite(void); // to be depreciated
i2c_error_t I2C_MasterRead(void); // to be depreciated

void I2C_SetTimeout(uint8_t timeOut);
void I2C_SetBuffer(void *buffer, size_t bufferSize);
void I2C_SetDataCompleteCallback(i2c_callback_t cb, void *ptr);
void I2C_SetWriteCollisionCallback(i2c_callback_t cb, void *ptr);
void I2C_SetAddressNackCallback(i2c_callback_t cb, void *ptr);
void I2C_SetDataNackCallback(i2c_callback_t cb, void *ptr);
void I2C_SetTimeoutCallback(i2c_callback_t cb, void *ptr);

/* METODOS DE USUARIO BUS I2C  */
uint8_t  I2C_Read1ByteRegister(i2c_address_t address, uint8_t reg);
uint16_t I2C_Read2ByteRegister(i2c_address_t address, uint8_t reg);
void I2C_Write1ByteRegister(i2c_address_t address, uint8_t reg, uint8_t data);
void I2C_Write2ByteRegister(i2c_address_t address, uint8_t reg, uint16_t data);
void I2C_WriteNBytes(i2c_address_t address, uint8_t *data, size_t len);
void I2C_ReadNBytes(i2c_address_t address, uint8_t *data, size_t len);
void I2C_ReadDataBlock(i2c_address_t address, uint8_t reg, uint8_t *data, size_t len);

#endif