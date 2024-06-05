/*
 * Network.h
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

#ifndef _NETWORK_H_
#define _NETWORK_H_


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* Inclusion of system and local header files goes here */
#include "simcom_api.h"
#include <stdint.h>
#include <stdarg.h>
#include "variant.h"


/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
/* #define and enum statements go here */

/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */
class NetworkClass
{ 
  private:
    uint8_t cfun;
    uint8_t systemMode;
    uint8_t csq;
    int creg;
    int cgreg;
    uint8_t band;
    bool networkOnline;
  public:
    NetworkClass();
    void init(void);
    void setCfunMode(uint8_t cfun); // Set phone functionality
    uint8_t getCSQ(void);
    uint8_t getCgreg(void);
    bool isOnline(void);
    // get local time
};

extern NetworkClass Network;
/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */
/* Function prototypes for public (external) functions go here */



#endif
#ifdef __cplusplus
}
#endif

