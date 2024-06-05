#ifndef __SIMCOM_CFUNC_H__
#define __SIMCOM_CFUNC_H__


#include "simcom_os.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"


typedef int (*_sAPI_Snprintf)(char *str, int size, const char *format, ...);
typedef int (*_sAPI_Sprintf)(char *str, const char *format, ...);
typedef int (*_sAPI_Vsnprintf)(char *str, UINT32 size, const char *format, va_list ap);
typedef int (*_sAPI_sscanf)(char *str, const char *format, ...);


extern _sAPI_Snprintf   sAPI_Snprintf;
extern _sAPI_Sprintf    sAPI_Sprintf;
extern _sAPI_Vsnprintf  sAPI_Vsnprintf;
extern _sAPI_sscanf     sAPI_sscanf;


void *sAPI_Malloc(UINT32 size);
void sAPI_Free(void* p);



#endif /* __SIMCOM_CFUNC_H__ */
