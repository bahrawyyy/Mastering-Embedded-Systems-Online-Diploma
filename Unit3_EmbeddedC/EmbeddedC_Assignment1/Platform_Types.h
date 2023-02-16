
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


#include <stdbool.h>

#define CPU_TYPE_8         8
#define CPU_TYPE_16        16
#define CPU_TYPE_32        32
#define CPU_TYPE_64        64

#define MSB_FIRST          0
#define LSB_FIRST          1

#define HIGH_BYTE_FIRST    0
#define LOW_BYTE_FIRST     1

#define CPY_TYPE          CPU_TYPE_32
#define CPU_BIT_ORDER     MSB_FIRST
#define CPU_BYTE_ORDER    HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE        (boolean)false
#endif
#ifndef TRUE
#define TRUE         (boolean)true
#endif

typedef _Bool                         boolean;
typedef signed char                   sint8;
typedef unsigned char                 uint8;
typedef signed short                  sint16;
typedef unsigned short                uint16;
typedef signed long                   sint32;
typedef unsigned long                 uint32;
typedef signed long long              sint64;
typedef unsigned long long            uint64;


typedef volatile signed char          vint8_t;
typedef volatile unsigned char        vuint8_t;

typedef volatile signed short         vint16_t;
typedef volatile unsigned short       vuint16_t;

typedef volatile signed long          vint32_t;
typedef volatile unsigned long        vuint32_t;

typedef volatile signed long long     vint64_t;
typedef volatile unsigned long long   vuint64_t;

#endif   /* PLATFORM_TYPES_H_ */
