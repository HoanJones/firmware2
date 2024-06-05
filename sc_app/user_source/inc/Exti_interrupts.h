/*
 * Exti_interrupts.h
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

#ifndef _EXTI_INTERRUPTS_H_
#define _EXTI_INTERRUPTS_H_


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


#define EXTI_CHANNEL1  A76xx_D1
#define EXTI_CHANNEL4  A76xx_D4
#define EXTI_CHANNEL5  A76xx_D5
#define EXTI_CHANNEL6  A76xx_D6
#define EXTI_CHANNEL7  A76xx_D7

#define EXTI_RISING  1
#define EXTI_FALLING 2
/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */





/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */
/* Function prototypes for public (external) functions go here */
/*
 * \brief Specifies a named Interrupt Service Routine (ISR) to call when an interrupt occurs.
 *        Replaces any previous function that was attached to the interrupt.
 */
extern void attachInterrupt(uint32_t interruptNum, voidFuncPtr callback, uint32_t mode);

/*
 * \brief Turns off the given interrupt.
 */
extern void detachInterrupt(uint32_t interruptNum);
#endif
#ifdef __cplusplus
}
#endif
