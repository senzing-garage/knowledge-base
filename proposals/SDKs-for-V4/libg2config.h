/**********************************************************************************
 © Copyright Senzing, Inc. 2017-2021
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/

#ifndef LIBG2CONFIG_H
#define LIBG2CONFIG_H

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
   * This method will initialize the G2 Config object.  It must be called
   * prior to any other calls.
   *
   * @param moduleName A name for the auditing node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string containing configuration paramters.
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT long long G2Config_init(const char *moduleName, const char *iniParams, const long long verboseLogging);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 Config object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT long long G2Config_destroy();


  /* type definitions for Config Handle data  */
  typedef void* ConfigHandle;


  /**
   * @brief
   * This method creates a stock G2 JSON config from the template config
   */
  _DLEXPORT long long G2Config_create(ConfigHandle* configHandle);


  /**
   * @brief
   * This method initializes the G2 Config object from a JSON string.  Any time you need to edit an existing
   * config from an existing repository you will want to use this method to be able to modify it.
   */
  _DLEXPORT long long G2Config_load(const char *jsonConfig,ConfigHandle* configHandle);


  /**
   * @brief
   * This method saves the G2 Config object into a JSON string.
   */
  _DLEXPORT long long G2Config_save(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief
   * This method cleans up the G2 Config object pointed to by the handle.
   */
  _DLEXPORT long long G2Config_close(ConfigHandle configHandle);


  /* Functions for data source configuration */
  _DLEXPORT long long G2Config_listDataSources(ConfigHandle configHandle, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2Config_addDataSource(ConfigHandle configHandle, const char *inputJson, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2Config_deleteDataSource(ConfigHandle configHandle, const char *inputJson);


  /**
   * @brief
   * This function retrieves the last exception thrown in G2Config
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Config_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in G2Config
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Config_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in G2Config
   */
  _DLEXPORT void G2Config_clearLastException();


#ifdef __cplusplus 
};
#endif

#endif /* LIBG2CONFIG_H */

