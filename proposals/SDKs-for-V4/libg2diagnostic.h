/**********************************************************************************
 © Copyright Senzing, Inc. 2019-2023
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/


#ifndef LIBG2DIAGNOSTIC_H
#define LIBG2DIAGNOSTIC_H


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
   * This method will initialize the G2 diagnostic object.  It must be called
   * prior to any other calls.
   *
   * @param moduleName A name for the diagnostic node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string specifying the configuration parameters
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT long long G2Diagnostic_init(
                            const char *moduleName,
                            const char *iniParams,
                            const long long verboseLogging);
  _DLEXPORT long long G2Diagnostic_initWithConfigID(
                            const char *moduleName,
                            const char *iniParams,
                            const long long initConfigID,
                            const long long verboseLogging);


  /**
   * @brief
   * This method will re-initialize the G2 diagnostic object.
   */
  _DLEXPORT long long G2Diagnostic_reinit(const long long initConfigID);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 diagnostic object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT long long G2Diagnostic_destroy();


  /**
   * @brief
   * This is used to purge all data from an existing repository
   * @return Returns 0 for success, or an appropriate error code.
   */
  _DLEXPORT long long G2Diagnostic_purgeRepository();


  /**
   * @brief Check the performance metrics of the datastore
   */
  _DLEXPORT long long G2Diagnostic_checkDBPerf(
                            const long long secondsToRun,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize) );

  /**
   * @brief
   * This function retrieves the last exception thrown in G2Diagnostic
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Diagnostic_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in G2Diagnostic
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Diagnostic_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in G2Diagnostic
   */
  _DLEXPORT void G2Diagnostic_clearLastException();


#ifdef __cplusplus
};
#endif


#endif /* LIBG2DIAGNOSTIC_H */
