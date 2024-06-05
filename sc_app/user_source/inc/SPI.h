/*
 * SPI.h
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

#ifndef _SPI_H_
#define _SPI_H_


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* Inclusion of system and local header files goes here */
#include "simcom_api.h"
#include <stdint.h>
#include <stdarg.h>
#include "variant.h"

#if(SPI_EN)
/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
typedef struct
{
    unsigned char index;    //spi interface index, default 0 avaliable
    int clock;              //spi clock,refer to SC_SPI_CLOCK
    int mode;               //spi mode,refer to SC_SPI_MODE
    int csMode;             //cs mode,refer to CS_MODE. When set to SSP_MODE,cs will be controled by SPI logic automatically. When set to 1, cs will be GPIO controled by customer.
    uint8_t spi_device;
} SC_SPI_DEV;

typedef enum
{
    SPI_CLOCK_6MHz = 0,
    SPI_CLOCK_13MHz,
    SPI_CLOCK_26MHz,
    SPI_CLOCK_52MHz,
    SPI_CLOCK_3250KHz,
    SPI_CLOCK_1625KHz,
    SPI_CLOCK_812KHz,
} SC_SPI_CLOCK;
/* hardware default config */
/*
  SCK   = D11
  MISO  = D10
  MOSI  = D9
  SS    = D8
*/
/* #define and enum statements go here */
/* Mode          Clock Polarity (CPOL)       Clock Phase (CPHA) */
/* SPI_MODE0             0                         0            */
/* SPI_MODE1             0                         1            */
/* SPI_MODE2             1                         0            */
/* SPI_MODE3             1                         1            */
typedef enum 
{
  SPI_MODE0 = 0,
  SPI_MODE1 = 2,
  SPI_MODE2 = 1,
  SPI_MODE3 = 3
} spi_mode_e;

enum BitOrder 
{
	LSBFIRST = 0,
	MSBFIRST = 1
};

typedef enum
{
  CSmode_HW = 1,
  CSmode_GPIO = 2,
} CsMode_e;

#define SPI_SPEED_CLOCK_DEFAULT SPI_CLOCK_1625KHz

class SPISettings 
{
  private:
    SC_SPI_DEV spiDev; 
    BitOrder bOrder;    /* bit order (MSBFirst or LSBFirst) */
    friend class HardwareSPI;

  public:
    SPISettings(SC_SPI_CLOCK clock, BitOrder bitOrder, spi_mode_e dataMode)
    {
      this->spiDev.clock = clock;    
      this->spiDev.mode = dataMode;
      bOrder = bitOrder;
    }
    SPISettings()
    {
      this->spiDev.clock = SPI_SPEED_CLOCK_DEFAULT;
      this->spiDev.mode = SPI_MODE0;
      bOrder = MSBFIRST;
    }
};

/* HardwareSPI Class ------------------------------------------------------------------------------------------*/
class HardwareSPI
{
  private:
    bool isBegin;
    int bufferIndex;
    SPISettings spiSettings;
    CsMode_e csMode;

  public:
    HardwareSPI(uint32_t arrayIndex);
    void begin(void);
    void end(void);
    /* if user doesn't want to use default config set by begin() function, call beginTransaction */
    void beginTransaction(SPISettings settings);
    void endTransaction(void);
    size_t transfer(uint8_t data);
    size_t transfer(const char *format,...);
    void transfer(void *buf, size_t count);
    void transfer(void *bufin, void *bufout, size_t count);
    /* call this function before calling begin or beginTransaction function */
    void setCsMode(CsMode_e mode); 
};
/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */
#if(SPI_NUM > 0)
extern HardwareSPI SPI;
#endif
#if(SPI_NUM > 1)
extern HardwareSPI SPI1;
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
