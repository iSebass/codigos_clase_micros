#ifndef I2C1_MASTER_H
#define I2C1_MASTER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    I2C1_NOERR, // The message was sent.
    I2C1_BUSY,  // Message was not sent, bus was busy.
    I2C1_FAIL   // Message was not sent, bus failure
               // If you are interested in the failure reason,
               // Sit on the event call-backs.
} i2c1_error_t;

typedef enum
{
    I2C1_STOP=1,
    I2C1_RESTART_READ,
    I2C1_RESTART_WRITE,
    I2C1_CONTINUE,
    I2C1_RESET_LINK
} i2c1_operations_t;

typedef uint8_t i2c1_address_t;
typedef i2c1_operations_t (*i2c1_callback_t)(void *funPtr);

// common callback responses
i2c1_operations_t I2C1_CallbackReturnStop(void *funPtr);
i2c1_operations_t I2C1_CallbackReturnReset(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartWrite(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartRead(void *funPtr);

void I2C1_Initialize(void);

i2c1_error_t I2C1_Open(i2c1_address_t address);
i2c1_error_t I2C1_Close(void);
i2c1_error_t I2C1_MasterOperation(bool read);
i2c1_error_t I2C1_MasterWrite(void); // to be depreciated
i2c1_error_t I2C1_MasterRead(void); // to be depreciated
void I2C1_SetTimeout(uint8_t timeOut);
void I2C1_SetBuffer(void *buffer, size_t bufferSize);
void I2C1_SetDataCompleteCallback(i2c1_callback_t cb, void *ptr);
void I2C1_SetWriteCollisionCallback(i2c1_callback_t cb, void *ptr);
void I2C1_SetAddressNackCallback(i2c1_callback_t cb, void *ptr);
void I2C1_SetDataNackCallback(i2c1_callback_t cb, void *ptr);
void I2C1_SetTimeoutCallback(i2c1_callback_t cb, void *ptr);

/*METODOS DE EJEMPLO Y DE USUARIO*/
uint8_t  I2C1_Read1ByteRegister(i2c1_address_t address, uint8_t reg);
uint16_t I2C1_Read2ByteRegister(i2c1_address_t address, uint8_t reg);
void I2C1_Write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data);
void I2C1_Write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data);
void I2C1_WriteNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadDataBlock(i2c1_address_t address, uint8_t reg, uint8_t *data, size_t len);


#endif //I2C1_MASTER_H
