/**********************************************************************************
 © Copyright Senzing, Inc. 2017-2021
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/

#ifndef LIBG2HASHER_H
#define LIBG2HASHER_H

// Platform specific function export header
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
   * This method will initialize the G2 hasher object.  It must be called
   * once per thread, prior to any other calls.
   *
   * @param moduleName A name for the hashing node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string specifying the configuration parameters
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT long long G2Hasher_init(const char *moduleName, const char *iniParams, const long long verboseLogging);
  _DLEXPORT long long G2Hasher_initWithConfig(const char *moduleName, const char *iniParams, const char *configJson, const long long verboseLogging);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 hasher object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT long long G2Hasher_destroy();


  /**
   * @brief
   * This method will run a hashing process on a record.  It will return
   * a new record with the data properly hashed.
   *
   * @param record An input record to be processed.
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer MUST be able to hold at least this many bytes.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 object is not intitialized. Returns -2 if an 
   *         exception was thrown and caught. 
   */
  _DLEXPORT long long G2Hasher_process(const char *record, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method returns a JSON document containing the G2 token library.
   * 
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer MUST be able to hold at least this many bytes.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.
   */
  _DLEXPORT long long G2Hasher_exportTokenLibrary(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  
  /**
   * @brief
   * This function retrieves the last exception thrown in G2Hasher
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Hasher_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in G2Hasher
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Hasher_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in G2Hasher
   */
  _DLEXPORT void G2Hasher_clearLastException();


#ifdef __cplusplus 
};
#endif

#endif // LIBG2HASHER_H

