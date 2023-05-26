#include "i2c_master.h"
#include <xc.h>

// I2C STATES
typedef enum {
    I2C_IDLE = 0,
    I2C_SEND_ADR_READ,
    I2C_SEND_ADR_WRITE,
    I2C_TX,
    I2C_RX,
    I2C_RCEN,
    I2C_TX_EMPTY,      
    I2C_SEND_RESTART_READ,
    I2C_SEND_RESTART_WRITE,
    I2C_SEND_RESTART,
    I2C_SEND_STOP,
    I2C_RX_ACK,
    I2C_RX_NACK_STOP,
    I2C_RX_NACK_RESTART,
    I2C_RESET,
    I2C_ADDRESS_NACK,

} i2c_fsm_states_t;

// I2C Event callBack List
typedef enum {
    I2C_DATA_COMPLETE = 0,
    I2C_WRITE_COLLISION,
    I2C_ADDR_NACK,
    I2C_DATA_NACK,
    I2C_TIMEOUT,
    I2C_NULL
} i2c_callbackIndex_t;

// I2C Status Structure
typedef struct
{
    i2c_callback_t callbackTable[6];
    void *callbackPayload[6];           //  each callBack can have a payload
    uint16_t time_out;                  // I2C Timeout Counter between I2C Events.
    uint16_t time_out_value;            // Reload value for the timeouts
    i2c_address_t address;             // The I2C Address
    uint8_t *data_ptr;                  // pointer to a data buffer
    size_t data_length;                 // Bytes in the data buffer
    i2c_fsm_states_t state;            // Driver State
    i2c_error_t error;
    unsigned addressNackCheck:1;
    unsigned busy:1;
    unsigned inUse:1;
    unsigned bufferFree:1;

} i2c_status_t;

static void I2C_SetCallback(i2c_callbackIndex_t idx, i2c_callback_t cb, void *ptr);
static void I2C_Poller(void);
static inline void I2C_MasterFsm(void);

/* I2C interfaces */
static inline bool I2C_MasterOpen(void);
static inline void I2C_MasterClose(void);    
static inline uint8_t I2C_MasterGetRxData(void);
static inline void I2C_MasterSendTxData(uint8_t data);
static inline void I2C_MasterEnableRestart(void);
static inline void I2C_MasterDisableRestart(void);
static inline void I2C_MasterStartRx(void);
static inline void I2C_MasterStart(void);
static inline void I2C_MasterStop(void);
static inline bool I2C_MasterIsNack(void);
static inline void I2C_MasterSendAck(void);
static inline void I2C_MasterSendNack(void);
static inline void I2C_MasterClearBusCollision(void);

/* Interrupt interfaces */
static inline void I2C_MasterEnableIrq(void);
static inline bool I2C_MasterIsIrqEnabled(void);
static inline void I2C_MasterDisableIrq(void);
static inline void I2C_MasterClearIrq(void);
static inline void I2C_MasterSetIrq(void);
static inline void I2C_MasterWaitForEvent(void);

static i2c_fsm_states_t I2C_DO_IDLE(void);
static i2c_fsm_states_t I2C_DO_SEND_ADR_READ(void);
static i2c_fsm_states_t I2C_DO_SEND_ADR_WRITE(void);
static i2c_fsm_states_t I2C_DO_TX(void);
static i2c_fsm_states_t I2C_DO_RX(void);
static i2c_fsm_states_t I2C_DO_RCEN(void);
static i2c_fsm_states_t I2C_DO_TX_EMPTY(void);
static i2c_fsm_states_t I2C_DO_SEND_RESTART_READ(void);
static i2c_fsm_states_t I2C_DO_SEND_RESTART_WRITE(void);
static i2c_fsm_states_t I2C_DO_SEND_RESTART(void);
static i2c_fsm_states_t I2C_DO_SEND_STOP(void);
static i2c_fsm_states_t I2C_DO_RX_ACK(void);
static i2c_fsm_states_t I2C_DO_RX_NACK_STOP(void);
static i2c_fsm_states_t I2C_DO_RX_NACK_RESTART(void);
static i2c_fsm_states_t I2C_DO_RESET(void);
static i2c_fsm_states_t I2C_DO_ADDRESS_NACK(void);


typedef i2c_fsm_states_t (*i2cFsmHandler)(void);
const i2cFsmHandler i2c_fsmStateTable[] = {
    I2C_DO_IDLE,
    I2C_DO_SEND_ADR_READ,
    I2C_DO_SEND_ADR_WRITE,
    I2C_DO_TX,
    I2C_DO_RX,
    I2C_DO_RCEN,
    I2C_DO_TX_EMPTY,
    I2C_DO_SEND_RESTART_READ,
    I2C_DO_SEND_RESTART_WRITE,
    I2C_DO_SEND_RESTART,
    I2C_DO_SEND_STOP,
    I2C_DO_RX_ACK,
    I2C_DO_RX_NACK_STOP,
    I2C_DO_RX_NACK_RESTART,
    I2C_DO_RESET,
    I2C_DO_ADDRESS_NACK,
};

i2c_status_t I2C_Status = {0};

void I2C_Initialize()
{
    SSPSTAT = 0x00;
    SSPCON1 = 0x08;
    SSPCON2 = 0x00;
    SSPADD  = 0x4F;
    SSPCON1bits.SSPEN = 0;
}

i2c_error_t I2C_Open(i2c_address_t address)
{
    i2c_error_t returnValue = I2C_BUSY;
    
    if(!I2C_Status.inUse)
    {
        I2C_Status.address = address;
        I2C_Status.busy = 0;
        I2C_Status.inUse = 1;
        I2C_Status.addressNackCheck = 0;
        I2C_Status.state = I2C_RESET;
        I2C_Status.time_out_value = 500; // MCC should determine a reasonable starting value here.
        I2C_Status.bufferFree = 1;

        // set all the call backs to a default of sending stop
        I2C_Status.callbackTable[I2C_DATA_COMPLETE]=I2C_CallbackReturnStop;
        I2C_Status.callbackPayload[I2C_DATA_COMPLETE] = NULL;
        I2C_Status.callbackTable[I2C_WRITE_COLLISION]=I2C_CallbackReturnStop;
        I2C_Status.callbackPayload[I2C_WRITE_COLLISION] = NULL;
        I2C_Status.callbackTable[I2C_ADDR_NACK]=I2C_CallbackReturnStop;
        I2C_Status.callbackPayload[I2C_ADDR_NACK] = NULL;
        I2C_Status.callbackTable[I2C_DATA_NACK]=I2C_CallbackReturnStop;
        I2C_Status.callbackPayload[I2C_DATA_NACK] = NULL;
        I2C_Status.callbackTable[I2C_TIMEOUT]=I2C_CallbackReturnReset;
        I2C_Status.callbackPayload[I2C_TIMEOUT] = NULL;
        
        I2C_MasterClearIrq();
        I2C_MasterOpen();
        returnValue = I2C_NOERR;
    }
    return returnValue;
}

i2c_error_t I2C_Close(void)
{
    i2c_error_t returnValue = I2C_BUSY;
    if(!I2C_Status.busy)
    {
        I2C_Status.inUse = 0;
        I2C_Status.address = 0xff;
        I2C_MasterClearIrq();
        I2C_MasterDisableIrq();
        I2C_MasterClose();
        returnValue = I2C_Status.error;
    }
    return returnValue;
}

i2c_error_t I2C_MasterOperation(bool read)
{
    i2c_error_t returnValue = I2C_BUSY;
    if(!I2C_Status.busy)
    {
        I2C_Status.busy = true;
        returnValue = I2C_NOERR;

        if(read)
        {
            I2C_Status.state = I2C_SEND_ADR_READ;
        }
        else
        {
            I2C_Status.state = I2C_SEND_ADR_WRITE;
        }
        I2C_MasterStart();
        I2C_Poller();
    }
    return returnValue;
}

i2c_error_t I2C_MasterRead(void)
{
    return I2C_MasterOperation(true);
}

i2c_error_t I2C_MasterWrite(void)
{
    return I2C_MasterOperation(false);
}

void I2C_SetTimeOut(uint8_t timeOutValue)
{
    I2C_MasterDisableIrq();
    I2C_Status.time_out_value = timeOutValue;
    I2C_MasterEnableIrq();
}

void I2C_SetBuffer(void *buffer, size_t bufferSize)
{
    if(I2C_Status.bufferFree)
    {
        I2C_Status.data_ptr = buffer;
        I2C_Status.data_length = bufferSize;
        I2C_Status.bufferFree = false;
    }
}

void I2C_SetDataCompleteCallback(i2c_callback_t cb, void *ptr)
{
    I2C_SetCallback(I2C_DATA_COMPLETE, cb, ptr);
}

void I2C_SetWriteCollisionCallback(i2c_callback_t cb, void *ptr)
{
    I2C_SetCallback(I2C_WRITE_COLLISION, cb, ptr);
}

void I2C_SetAddressNackCallback(i2c_callback_t cb, void *ptr)
{
    I2C_SetCallback(I2C_ADDR_NACK, cb, ptr);
}

void I2C_SetDataNackCallback(i2c_callback_t cb, void *ptr)
{
    I2C_SetCallback(I2C_DATA_NACK, cb, ptr);
}

void I2C_SetTimeoutCallback(i2c_callback_t cb, void *ptr)
{
    I2C_SetCallback(I2C_TIMEOUT, cb, ptr);
}

static void I2C_SetCallback(i2c_callbackIndex_t idx, i2c_callback_t cb, void *ptr)
{
    if(cb)
    {
        I2C_Status.callbackTable[idx] = cb;
        I2C_Status.callbackPayload[idx] = ptr;
    }
    else
    {
        I2C_Status.callbackTable[idx] = I2C_CallbackReturnStop;
        I2C_Status.callbackPayload[idx] = NULL;
    }
}

static void I2C_Poller(void)
{
    while(I2C_Status.busy)
    {
        I2C_MasterWaitForEvent();
        I2C_MasterFsm();
    }
}

static inline void I2C_MasterFsm(void)
{
    I2C_MasterClearIrq();

    if(I2C_Status.addressNackCheck && I2C_MasterIsNack())
    {
        I2C_Status.state = I2C_ADDRESS_NACK;
    }
    I2C_Status.state = i2c_fsmStateTable[I2C_Status.state]();
}


static i2c_fsm_states_t I2C_DO_IDLE(void)
{
    I2C_Status.busy = false;
    I2C_Status.error = I2C_NOERR;
    return I2C_RESET;
}

static i2c_fsm_states_t I2C_DO_SEND_ADR_READ(void)
{
    I2C_Status.addressNackCheck = 1;
    I2C_MasterSendTxData((uint8_t) (I2C_Status.address << 1 | 1));
    return I2C_RCEN;
}

static i2c_fsm_states_t I2C_DO_SEND_ADR_WRITE(void)
{
    I2C_Status.addressNackCheck = 1;
    I2C_MasterSendTxData((uint8_t) (I2C_Status.address << 1));
    return I2C_TX;
}

static i2c_fsm_states_t I2C_DO_TX(void)
{
    if(I2C_MasterIsNack())
    {
        switch(I2C_Status.callbackTable[I2C_DATA_NACK](I2C_Status.callbackPayload[I2C_DATA_NACK]))
        {
            case I2C_RESTART_READ:
                return I2C_DO_SEND_RESTART_READ();
            case I2C_RESTART_WRITE:
                  return I2C_DO_SEND_RESTART_WRITE();
            default:
            case I2C_CONTINUE:
            case I2C_STOP:
                return I2C_DO_SEND_STOP();
        }
    }
    else
    {
        I2C_Status.addressNackCheck = 0;
        I2C_MasterSendTxData(*I2C_Status.data_ptr++);
        return (--I2C_Status.data_length)?I2C_TX:I2C_TX_EMPTY;
    }
}

static i2c_fsm_states_t I2C_DO_RX(void)
{
    *I2C_Status.data_ptr++ = I2C_MasterGetRxData();
    if(--I2C_Status.data_length)
    {
        I2C_MasterSendAck();
        return I2C_RCEN;
    }
    else
    {
        I2C_Status.bufferFree = true;
        switch(I2C_Status.callbackTable[I2C_DATA_COMPLETE](I2C_Status.callbackPayload[I2C_DATA_COMPLETE]))
        {
            case I2C_RESTART_WRITE:
            case I2C_RESTART_READ:
                return I2C_DO_RX_NACK_RESTART();
            default:
            case I2C_CONTINUE:
            case I2C_STOP:
                return I2C_DO_RX_NACK_STOP();
        }
    }
}

static i2c_fsm_states_t I2C_DO_RCEN(void)
{
    I2C_Status.addressNackCheck = 0;
    I2C_MasterStartRx();
    return I2C_RX;
}

static i2c_fsm_states_t I2C_DO_TX_EMPTY(void)
{
    I2C_Status.bufferFree = true;
    switch(I2C_Status.callbackTable[I2C_DATA_COMPLETE](I2C_Status.callbackPayload[I2C_DATA_COMPLETE]))
    {
        case I2C_RESTART_READ:
        case I2C_RESTART_WRITE:
            return I2C_DO_SEND_RESTART();
        case I2C_CONTINUE:
            I2C_MasterSetIrq();
            return I2C_TX;
        default:
        case I2C_STOP:
            return I2C_DO_SEND_STOP();
    }
}

static i2c_fsm_states_t I2C_DO_RX_EMPTY(void)
{
    I2C_Status.bufferFree = true;
    switch(I2C_Status.callbackTable[I2C_DATA_COMPLETE](I2C_Status.callbackPayload[I2C_DATA_COMPLETE]))
    {
        case I2C_RESTART_WRITE:
            I2C_MasterEnableRestart();
            return I2C_SEND_RESTART_WRITE;
        case I2C_RESTART_READ:
            I2C_MasterEnableRestart();
            return I2C_SEND_RESTART_READ;
        case I2C_CONTINUE:
            // Avoid the counter stop condition , Counter is incremented by 1
            return I2C_RX;
        default:
        case I2C_STOP:
            if(I2C_Status.state != I2C_SEND_RESTART_READ)
            {
                I2C_MasterDisableRestart();
            }
            return I2C_RESET;
    }
}

static i2c_fsm_states_t I2C_DO_SEND_RESTART_READ(void)
{
    I2C_MasterEnableRestart();
    return I2C_SEND_ADR_READ;
}

static i2c_fsm_states_t I2C_DO_SEND_RESTART_WRITE(void)
{
    I2C_MasterEnableRestart();
    return I2C_SEND_ADR_WRITE;
}


static i2c_fsm_states_t I2C_DO_SEND_RESTART(void)
{
    I2C_MasterEnableRestart();
    return I2C_SEND_ADR_READ;
}

static i2c_fsm_states_t I2C_DO_SEND_STOP(void)
{
    I2C_MasterStop();
    return I2C_IDLE;
}

static i2c_fsm_states_t I2C_DO_RX_ACK(void)
{
    I2C_MasterSendAck();
    return I2C_RCEN;
}


static i2c_fsm_states_t I2C_DO_RX_NACK_STOP(void)
{
    I2C_MasterSendNack();
    return I2C_SEND_STOP;
}

static i2c_fsm_states_t I2C_DO_RX_NACK_RESTART(void)
{
    I2C_MasterSendNack();
    return I2C_SEND_RESTART;
}

static i2c_fsm_states_t I2C_DO_RESET(void)
{
    I2C_Status.busy = false;
    I2C_Status.error = I2C_NOERR;
    return I2C_RESET;
}
static i2c_fsm_states_t I2C_DO_ADDRESS_NACK(void)
{
    I2C_Status.addressNackCheck = 0;
    I2C_Status.error = I2C_FAIL;
    switch(I2C_Status.callbackTable[I2C_ADDR_NACK](I2C_Status.callbackPayload[I2C_ADDR_NACK]))
    {
        case I2C_RESTART_READ:
        case I2C_RESTART_WRITE:
            return I2C_DO_SEND_RESTART();
        default:
            return I2C_DO_SEND_STOP();
    }
}

void I2C_BusCollisionIsr(void)
{
    I2C_MasterClearBusCollision();
    I2C_Status.state = I2C_RESET;
}

i2c_operations_t I2C_CallbackReturnStop(void *funPtr)
{
    return I2C_STOP;
}

i2c_operations_t I2C_CallbackReturnReset(void *funPtr)
{
    return I2C_RESET_LINK;
}

i2c_operations_t I2C_CallbackRestartWrite(void *funPtr)
{
    return I2C_RESTART_WRITE;
}

i2c_operations_t I2C_CallbackRestartRead(void *funPtr)
{
    return I2C_RESTART_READ;
}



/* I2C Register Level interfaces */
static inline bool I2C_MasterOpen(void)
{
    if(!SSPCON1bits.SSPEN)
    {
        SSPSTAT = 0x00;
        SSPCON1 = 0x08;
        SSPCON2 = 0x00;
        SSPADD = 0x4F;
        SSPCON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

static inline void I2C_MasterClose(void)
{
    //Disable I2C
    SSPCON1bits.SSPEN = 0;
}

static inline uint8_t I2C_MasterGetRxData(void)
{
    return SSPBUF;
}

static inline void I2C_MasterSendTxData(uint8_t data)
{
    SSPBUF  = data;
}

static inline void I2C_MasterEnableRestart(void)
{
    SSPCON2bits.RSEN = 1;
}

static inline void I2C_MasterDisableRestart(void)
{
    SSPCON2bits.RSEN = 0;
}

static inline void I2C_MasterStartRx(void)
{
    SSPCON2bits.RCEN = 1;
}

static inline void I2C_MasterStart(void)
{
    SSPCON2bits.SEN = 1;
}

static inline void I2C_MasterStop(void)
{
    SSPCON2bits.PEN = 1;
}

static inline bool I2C_MasterIsNack(void)
{
    return SSPCON2bits.ACKSTAT;
}

static inline void I2C_MasterSendAck(void)
{
    SSPCON2bits.ACKDT = 0;
    SSPCON2bits.ACKEN = 1;
}

static inline void I2C_MasterSendNack(void)
{
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1;
}

static inline void I2C_MasterClearBusCollision(void)
{
    PIR2bits.BCLIF = 0;
}

static inline bool I2C_MasterIsRxBufFull(void)
{
    return SSPSTATbits.BF;
}

static inline void I2C_MasterEnableIrq(void)
{
    PIE1bits.SSPIE = 1;
}

static inline bool I2C_MasterIsIrqEnabled(void)
{
    return PIE1bits.SSPIE;
}

static inline void I2C_MasterDisableIrq(void)
{
    PIE1bits.SSPIE = 0;
}

static inline void I2C_MasterClearIrq(void)
{
    PIR1bits.SSPIF = 0;
}

static inline void I2C_MasterSetIrq(void)
{
    PIR1bits.SSPIF = 1;
}

static inline void I2C_MasterWaitForEvent(void)
{
    while(1)
    {
        if(PIR1bits.SSPIF)
        {    
            break;
        }
    }
}

/*********************************  
 *   METODOS DE USUARIO          *
 *********************************
 */


typedef struct
{
    size_t len;
    uint8_t *data;
}i2c_buffer_t;

static i2c_operations_t rd1RegCompleteHandler(void *ptr);
static i2c_operations_t rd2RegCompleteHandler(void *ptr);
static i2c_operations_t wr1RegCompleteHandler(void *ptr);
static i2c_operations_t wr2RegCompleteHandler(void *ptr);
static i2c_operations_t rdBlkRegCompleteHandler(void *ptr);




uint8_t I2C_Read1ByteRegister(i2c_address_t address, uint8_t reg)
{
    uint8_t returnValue = 0x00;
    
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetDataCompleteCallback(rd1RegCompleteHandler,&returnValue);
    I2C_SetBuffer(&reg,1);
    I2C_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C_MasterWrite();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
    
    return returnValue;
}

uint16_t I2C_Read2ByteRegister(i2c_address_t address, uint8_t reg)
{
    uint8_t returnValue = 0x00;
    
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetDataCompleteCallback(rd1RegCompleteHandler,&returnValue);
    I2C_SetBuffer(&reg,1);
    I2C_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C_MasterWrite();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
    
    return returnValue;
}

void I2C_Write1ByteRegister(i2c_address_t address, uint8_t reg, uint8_t data)
{
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetDataCompleteCallback(wr1RegCompleteHandler,&data);
    I2C_SetBuffer(&reg,1);
    I2C_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C_MasterWrite();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
}

void I2C_Write2ByteRegister(i2c_address_t address, uint8_t reg, uint16_t data)
{
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetDataCompleteCallback(wr2RegCompleteHandler,&data);
    I2C_SetBuffer(&reg,1);
    I2C_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C_MasterWrite();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
}

void I2C_WriteNBytes(i2c_address_t address, uint8_t* data, size_t len)
{
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetBuffer(data,len);
    I2C_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C_MasterWrite();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
}

void I2C_ReadNBytes(i2c_address_t address, uint8_t *data, size_t len)
{
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetBuffer(data,len);
    I2C_MasterRead();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
}

void I2C_ReadDataBlock(i2c_address_t address, uint8_t reg, uint8_t *data, size_t len)
{
    i2c_buffer_t bufferBlock; // result is little endian
    bufferBlock.data = data;
    bufferBlock.len = len;

    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetDataCompleteCallback(rdBlkRegCompleteHandler,&bufferBlock);
    I2C_SetBuffer(&reg,1);
    I2C_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C_MasterWrite();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
}

static i2c_operations_t rd1RegCompleteHandler(void *ptr)
{
    I2C_SetBuffer(ptr,1);
    I2C_SetDataCompleteCallback(NULL,NULL);
    return I2C_RESTART_READ;
}

static i2c_operations_t rd2RegCompleteHandler(void *ptr)
{
    I2C_SetBuffer(ptr,2);
    I2C_SetDataCompleteCallback(NULL,NULL);
    return I2C_RESTART_READ;
}

static i2c_operations_t wr1RegCompleteHandler(void *ptr)
{
    I2C_SetBuffer(ptr,1);
    I2C_SetDataCompleteCallback(NULL,NULL);
    return I2C_CONTINUE;
}

static i2c_operations_t wr2RegCompleteHandler(void *ptr)
{
    I2C_SetBuffer(ptr,2);
    I2C_SetDataCompleteCallback(NULL,NULL);
    return I2C_CONTINUE;
}

static i2c_operations_t rdBlkRegCompleteHandler(void *ptr)
{
    I2C_SetBuffer(((i2c_buffer_t *)ptr)->data,((i2c_buffer_t*)ptr)->len);
    I2C_SetDataCompleteCallback(NULL,NULL);
    return I2C_RESTART_READ;
}


/*******************************************
 *   METODOS PERSONALIZADOS POR iSEBAS     *
 *******************************************/

uint8_t I2C_Wr(i2c_address_t address, uint8_t data){
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetBuffer(&data,1);
    I2C_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C_MasterWrite();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
}

uint8_t I2C_Rd(i2c_address_t address) {
    uint8_t returnValue = 0x00;
    
    while(!I2C_Open(address)); // sit here until we get the bus..
    I2C_SetBuffer(&returnValue,1);
    I2C_MasterRead();
    while(I2C_BUSY == I2C_Close()); // sit here until finished.
    
    return returnValue;
}