/*
 * HardwareSerial.h
 *
 *  Created on: 
 *      Author: chungnt@epi-tech.com.vn
 *
 *      
*/
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef _HARDWARESERIAL_H_
#define _HARDWARESERIAL_H_


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* Inclusion of system and local header files goes here */
#include "simcom_api.h"
#include <stdint.h>
#include <stdarg.h>
#include "variant.h"

#if(SERIAL_EN)
/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
/* #define and enum statements go here */
#define DATA_7        (0x1ul)
#define DATA_8        (0x2ul)
#define DATA_MASK     (0xFul)

#define STOP_BIT_1    (0x10ul)
#define STOP_BIT_2    (0x20ul)
#define STOP_BIT_MASK (0xF0ul)

#define PARITY_NONE   (0x100ul)
#define PARITY_EVEN   (0X200ul)
#define PARITY_ODD    (0x300ul)
#define PARITY_MASK   (0xF00ul)

#define SERIAL_7N1  (DATA_7 | PARITY_NONE| STOP_BIT_1)
#define SERIAL_8N1  (DATA_8 | PARITY_NONE| STOP_BIT_1)
#define SERIAL_7N2  (DATA_7 | PARITY_NONE| STOP_BIT_2)
#define SERIAL_8N2  (DATA_8 | PARITY_NONE| STOP_BIT_2)

#define SERIAL_7E1  (DATA_7 | PARITY_EVEN| STOP_BIT_1)
#define SERIAL_8E1  (DATA_8 | PARITY_EVEN| STOP_BIT_1)
#define SERIAL_7E2  (DATA_7 | PARITY_EVEN| STOP_BIT_2)
#define SERIAL_8E2  (DATA_8 | PARITY_EVEN| STOP_BIT_2)

#define SERIAL_7O1  (DATA_7 | PARITY_ODD| STOP_BIT_1)
#define SERIAL_8O1  (DATA_8 | PARITY_ODD| STOP_BIT_1)
#define SERIAL_7O2  (DATA_7 | PARITY_ODD| STOP_BIT_2)
#define SERIAL_8O2  (DATA_8 | PARITY_ODD| STOP_BIT_2)

#define SERIAL0_ARRAY_INDEX 0
#define SERIAL1_ARRAY_INDEX 1
#define MAX_SERIAL_PORT_NUM UART_SERIAL_NUM

#define SERIAL_BUFFER_SIZE  32
/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */
class HardwareSerial
{ 
  protected:
    bool isBegin;
    int bufferIndex;
    int arrayIndex;  
    uint8_t port;
    uint16_t bufferSize = SERIAL_BUFFER_SIZE;
  public:
    HardwareSerial(uint32_t arrayIndex);
    void begin(const uint32_t dwBaudRate);
    void begin(const uint32_t dwBaudRate, uint16_t config);
    size_t print(const char *format,...);
    void IrqHandler(int dataLen);
    // void end( void ) ;
    int available(void) ;
    char read(void);
    char readBytes(void* buffer, int length);
    void setBufferRxSize(uint16_t bufferSize);
};


#if(UART_SERIAL_NUM > 0)
extern HardwareSerial Serial;
#endif
#if(UART_SERIAL_NUM > 1)
extern HardwareSerial Serial1;
#endif
/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */
/* Function prototypes for public (external) functions go here */



#endif
#ifdef __cplusplus
}
#endif

#endif
