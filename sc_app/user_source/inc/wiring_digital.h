/*
 * wiring_digital.h
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

#ifndef _WIRING_DIGITAL_
#define _WIRING_DIGITAL_


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* Inclusion of system and local header files goes here */
#include "simcom_api.h"
#include <stdint.h>
#include "variant.h"
/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
/* #define and enum statements go here */
#define NETLIGHT_PIN       9 
#define FLASH_CS_PIN       12 // IO1
#define RF_CS_PIN          10 // IO2
#define A76xx_D1           0 
#define A76xx_D4           14 
#define A76xx_D5           13 
#define A76xx_D6           12 
#define A76xx_D7           10 


#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define INPUT_PULLDOWN 0x03
/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */





/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */
/* Function prototypes for public (external) functions go here */
/**
 * \brief Configures the specified pin to behave either as an input or an output. See the description of digital pins for details.
 *
 * \param ulPin The number of the pin whose mode you wish to set
 * \param ulMode Either INPUT ,OUTPUT, INPUT_PULLUP, INPUT_PULLDOWN.
 */
extern void pinMode( unsigned int ulPin, unsigned int ulMode ) ;

/**
 * \brief Write a HIGH or a LOW value to a digital pin.
 *
 * \param ulPin the pin number
 * \param ulVal HIGH or LOW or CHANGE
 */
extern void digitalWrite( unsigned int ulPin, unsigned int ulVal ) ;

/**
 * \brief Reads the value from a specified digital pin, either HIGH or LOW.
 *
 * \param ulPin The number of the digital pin you want to read (int)
 *
 * \return HIGH or LOW
 */
extern unsigned int digitalRead( unsigned int ulPin ) ;

/**
 * \brief Toggle the value from a specified digital pin.
 *
 * \param ulPin The number of the digital pin you want to toggle(uint32_t).
 *
 * \return void
 */
extern void digitalToggle(unsigned int ulPin);

extern int _setInterrupt(uint32_t interruptNum, voidFuncPtr callback, uint32_t mode);
#endif
#ifdef __cplusplus
}
#endif
