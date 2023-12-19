/**********************************************************************************
 © Copyright Senzing, Inc. 2018-2021
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/

#ifndef LIB_G2_PRODUCT_H
#define LIB_G2_PRODUCT_H

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
   * This method will initialize the G2 product object.  It must be called
   * prior to any other calls.
   *
   * @param moduleName A name for the node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string specifying the configuration parameters
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT long long G2Product_init(const char *moduleName, const char *iniParams, const long long verboseLogging);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 product object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT long long G2Product_destroy();
  

  /**
   * @brief
   * This function is used to return the license information
   *
   * @return Returns a pointer to the license information in JSON format
   */
  _DLEXPORT char* G2Product_license();


  /**
   * @brief
   * This function is used to validate an external license file for validity.
   * If it is not valid, information on why will be returned through the 
   * error buffer parameters.
   *
   * @param licenseFilePath The file path and name of the file to validate.
   * @param errorBuf The buffer to write an error message to
   * @param errorBufSize The size of the error buffer
   * @param resizeFunc A function to resize the error buffer, if it needs more space.
   *
   * @return 0 if the file is a valid license.
   */
  _DLEXPORT long long G2Product_validateLicenseFile(const char* licenseFilePath, char **errorBuf, size_t *errorBufSize, void *(*resizeFunc)(void *ptr,size_t newSize));
  _DLEXPORT long long G2Product_validateLicenseStringBase64(const char* licenseString, char **errorBuf, size_t *errorBufSize, void *(*resizeFunc)(void *ptr,size_t newSize));


  /**
   * @brief
   * This function is used to return the version and build information
   *
   * @return Returns a pointer to the version and build information in JSON format
   */
  _DLEXPORT char* G2Product_version();


  /**
   * @brief
   * This function retrieves the last exception thrown in G2Product
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Product_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in G2Product
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2Product_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in G2Product
   */
  _DLEXPORT void G2Product_clearLastException();


#ifdef __cplusplus 
};
#endif

#endif

