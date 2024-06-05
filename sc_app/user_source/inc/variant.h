/*
 * variant.h
 *
 *  Created on: 
 *      Author: chungnt@epi-tech.com.vn
 *
 *      
*/
#ifdef __cplusplus
 extern "C" {
#endif
/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __VARIANT_H
#define __VARIANT_H

/* Includes ------------------------------------------------------------------------------------------------*/
#include "simcom_api.h"
#include <stdint.h>
#include <stdarg.h>

typedef struct
{
  uint8_t uartPort;
  int bufferIndex;
} UARTInfo;

#define UART_SERIAL_NUM                 2

#define SERIAL0_PORT                    1
#define SERIAL0_IRQN                    USART1_IRQn
#define SERIAL0_BUFFER_INDEX            0
#define SERIAL0_ARRAY_INDEX             0

#define SERIAL1_PORT                    2
#define SERIAL1_IRQN                    USART0_IRQn
#define SERIAL1_BUFFER_INDEX            1
#define SERIAL1_ARRAY_INDEX             1

#define INF_GET_UART_PORT(a)            pUARTInfo[a].uartPort
#define INF_GET_UART_BUFFER_INDEX(a)    pUARTInfo[a].bufferIndex

extern const UARTInfo pUARTInfo[UART_SERIAL_NUM];

/* SPI */
typedef struct
{
  unsigned char spiPort;
  int bufferIndex;
} SPIInfo;

#define SPI_NUM                         1

#define SPI0_PORT                       0
#define SPI0_BUFFER_INDEX               0
#define SPI0_ARRAY_INDEX                0

#define SPI1_PORT                       2
#define SPI1_BUFFER_INDEX               1
#define SPI1_ARRAY_INDEX                1

#define INF_GET_SPI_PORT(a)            pSPIInfo[a].spiPort
#define INF_GET_SPI_BUFFER_INDEX(a)    pSPIInfo[a].bufferIndex

extern const SPIInfo pSPIInfo[SPI_NUM];

#define A7672     (1)

#define SPI_EN    (1)
#define WIRE_EN   (1)
#define SERIAL_EN (1)
#define MQTT_EN   (1)
#define SMS_EN    (0)

typedef void (*voidFuncPtr)(void);
typedef void (*voidArgumentFuncPtr)(void *);

#endif
#ifdef __cplusplus
}
#endif
