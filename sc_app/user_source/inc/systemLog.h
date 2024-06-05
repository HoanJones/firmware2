/*
 * systemLog.h
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

#ifndef _SYSTEMLOG_H_
#define _SYSTEMLOG_H_


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* Inclusion of system and local header files goes here */
#include "simcom_api.h"
#include <string.h>
#include <stdarg.h>
// #include "defineType.h"
/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
/* #define and enum statements go here */
      
#define STRCAT2(a, b)        a##b  
#define STRCAT3(a, b, c)     a##b##c

#define __FILENAME__    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define COLOR_GREEN     "\033[32;40m"    // green text, black backgound
#define COLOR_YELLOW    "\033[33;40m"    // yellow text, black backgound
#define COLOR_RED       "\033[31;40m"    // red text, black backgound

// #define LOG_I(TAG, CMDLINE, format, ...) systemLog_Print(COLOR_GREEN, TAG, CMDLINE, format, ##__VA_ARGS__)
// #define LOG_W(TAG, CMDLINE, format, ...) systemLog_Print(COLOR_YELLOW, TAG, CMDLINE, format, ##__VA_ARGS__)
// #define LOG_E(TAG, CMDLINE, format, ...) systemLog_Print(COLOR_RED, TAG, CMDLINE, format, ##__VA_ARGS__)

#define LOG_I(format, ...) systemLog_Print(COLOR_GREEN,     __FILENAME__, __LINE__, format, ##__VA_ARGS__)
#define LOG_W(format, ...) systemLog_Print(COLOR_YELLOW,    __FILENAME__, __LINE__, format, ##__VA_ARGS__)
#define LOG_E(format, ...) systemLog_Print(COLOR_RED,       __FILENAME__, __LINE__, format, ##__VA_ARGS__)


/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */





/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */
/* Function prototypes for public (external) functions go here */
extern void systemLog_Init(void);
extern void systemLog_Print(const char *colorType, const char *tag, int codeLine, const char *format,...);
#endif
#ifdef __cplusplus
}
#endif
