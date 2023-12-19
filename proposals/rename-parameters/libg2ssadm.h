/**********************************************************************************
 © Copyright Senzing, Inc. 2018-2021
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/

#ifndef LIBG2SSADM_H
#define LIBG2SSADM_H

/* Platform specific function export header */
#if defined(_WIN32)
  #define _DLEXPORT __declspec(dllexport)
#else
  #include <stddef.h>
  #define _DLEXPORT __attribute__ ((visibility ("default")))
#endif


#ifdef __cplusplus 
extern "C"
{
#endif


  _DLEXPORT long long G2SecureStoreAdmin_init(const char *moduleName, const char *iniParams, const long long verboseLogging);
  _DLEXPORT long long G2SecureStoreAdmin_destroy();

  _DLEXPORT long long G2SecureStoreAdmin_initializeNewToken(const char* defaultSOPin, const char* newSOPin, const char* label);
  _DLEXPORT long long G2SecureStoreAdmin_reinitializeToken(const char* soPin, const char* label);

  _DLEXPORT long long G2SecureStoreAdmin_setupStore(const char* soPin);

  _DLEXPORT long long G2SecureStoreAdmin_list(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );
  _DLEXPORT long long G2SecureStoreAdmin_put(const char* soPin, const char* label, const char* value);

  _DLEXPORT long long G2SecureStoreAdmin_createSaltInStore(const char* soPin, const char* name, const char* method,char *buffer, const size_t bufSize);

  _DLEXPORT long long G2SecureStoreAdmin_getLastException(char *buffer, const size_t bufSize);
  _DLEXPORT long long G2SecureStoreAdmin_getLastExceptionCode();
  _DLEXPORT void G2SecureStoreAdmin_clearLastException();


#ifdef __cplusplus 
};
#endif

#endif /* header file */

