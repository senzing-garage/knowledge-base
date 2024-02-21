/**********************************************************************************
 © Copyright Senzing, Inc. 2019-2021
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/

#ifndef LIBG2CONFIGMGR_H
#define LIBG2CONFIGMGR_H

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


  /**
   * @brief
   * This method will initialize the G2 Config Manager object.  It must be called
   * prior to any other calls.
   *
   * @param moduleName A name for the node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string specifying the configuration parameters
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT long long G2ConfigMgr_init(const char *moduleName, const char *iniParams, const long long verboseLogging);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 Config object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT long long G2ConfigMgr_destroy();


  /**
   * @brief Registers a configuration handle with the backend data store
   */
  _DLEXPORT long long G2ConfigMgr_addConfig(const char* configStr, const char* configComments, long long* configID);


  /**
   * @brief Retrieve configuration information from the backend data store
   */
  _DLEXPORT long long G2ConfigMgr_getConfig(const long long configID, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief Retrieve a list of configurations from the backend data store
   */
  _DLEXPORT long long G2ConfigMgr_getConfigList(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief Set the default configuration identifier in the backend data store
   */
  _DLEXPORT long long G2ConfigMgr_setDefaultConfigID(const long long configID);


  /**
   * @brief Get the default configuration identifier from the backend data store
   */
  _DLEXPORT long long G2ConfigMgr_getDefaultConfigID(long long* configID);


  /**
   * @brief Replace the default configuration identifier in the backend data store
   */
  _DLEXPORT long long G2ConfigMgr_replaceDefaultConfigID(const long long oldConfigID, const long long newConfigID);


  /**
   * @brief
   * This function retrieves the last exception thrown in G2ConfigMgr
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2ConfigMgr_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in G2ConfigMgr
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2ConfigMgr_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in G2ConfigMgr
   */
  _DLEXPORT void G2ConfigMgr_clearLastException();


#ifdef __cplusplus 
};
#endif

#endif /* LIBG2CONFIGMGR_H */

