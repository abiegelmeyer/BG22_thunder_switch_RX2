// This is an autogenerated config file, any changes to this file will be overwritten

#ifndef MBEDTLS_CONFIG_AUTOGEN_H
#define MBEDTLS_CONFIG_AUTOGEN_H



#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_USE_PSA_CRYPTO
#define MBEDTLS_CIPHER_C
#define MBEDTLS_PSA_CRYPTO_CONFIG
#define MBEDTLS_PSA_CRYPTO_DRIVERS
#define MBEDTLS_PSA_CRYPTO_STORAGE_C


#include "config-device-acceleration.h"

#if !defined(TEST_SUITE_MEMORY_BUFFER_ALLOC)
#if !defined(MBEDTLS_PLATFORM_FREE_MACRO) && !defined(MBEDTLS_PLATFORM_CALLOC_MACRO)
#if defined(CONFIG_MBEDTLS_USE_FREERTOS_PVCALLOC)
    /* In FreeRTOS, use pvCalloc (and vPortFree) for dynamic memory allocation.
       E.g. Amazon FreeRTOS implements pvCalloc for dynamic memory allocation. */
    #include <stddef.h>

    extern void * pvCalloc( size_t xNumElements,
                            size_t xSize ) ;
    extern void vPortFree( void *pv );
    #define MBEDTLS_PLATFORM_CALLOC_MACRO pvCalloc
    #define MBEDTLS_PLATFORM_FREE_MACRO   vPortFree
#else
    /* No memory allocator override, supply the default for SL platforms */
    #include "sl_malloc.h"

    #define MBEDTLS_PLATFORM_FREE_MACRO    sl_free
    #define MBEDTLS_PLATFORM_CALLOC_MACRO  sl_calloc
#endif
#endif /* No specific memory allocator override */
#endif /* Not under test */

#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_PLATFORM_C



#endif
