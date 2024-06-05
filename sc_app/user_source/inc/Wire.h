/*
 * Wire.h
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

#ifndef _WIRE_H_
#define _WIRE_H_


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* Inclusion of system and local header files goes here */
#include "simcom_api.h"
#include <stdint.h>
#include <stdarg.h>
#include "variant.h"

#if(WIRE_EN)
/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
/* #define and enum statements go here */

/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */
class TwoWire
{ 
  protected:
    bool isBegin = false;
    uint8_t slaveAddr;
    uint8_t lcdAddr;
  public:
    void begin(void);
    void begin(uint8_t address);
    void write(uint8_t slaveAddr, void* data, uint16_t len);
    void write(uint8_t slaveAddr, uint8_t regAddr, void* data, uint16_t len);
    void read(uint8_t slaveAddr, void* data, uint16_t len);
    void read(uint8_t slaveAddr, uint8_t regAddr, void* data, uint16_t len);
    void lcdInit(uint8_t address);
    size_t lcdPrint(const char *format,...);
    void lcdClear(void);
    void lcdGotoXY(int row, int col);
};

extern TwoWire Wire;

/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */
/* Function prototypes for public (external) functions go here */



#endif
#ifdef __cplusplus
}
#endif

#endif
