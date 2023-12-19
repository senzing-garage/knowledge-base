
/**********************************************************************************
© Copyright Senzing, Inc. 2018-2021
The source code for this program is not published or otherwise divested
of its trade secrets, irrespective of what has been deposited with the U.S.
Copyright Office.
**********************************************************************************/

#ifndef G2_PLUGIN_INTERFACE_HEADER_INCLUDED
#define G2_PLUGIN_INTERFACE_HEADER_INCLUDED

/* standard C++ headers */
#include <string.h>


#if defined(_WIN32)
  #define _DLEXPORT __declspec(dllexport)
#else
  #define _DLEXPORT __attribute__ ((visibility ("default")))
#endif


/* the interface must be C-callable */
#ifdef __cplusplus
extern "C" 
{
#endif

  /* definition of a minimal function pointer */
  typedef void ( * G2CALLBACK)();

  /* fetch a pointer to a function which implements a specific callback. */
  typedef G2CALLBACK ( * G2GETCALLBACK)(const char * name);

  /* the function pointer equivalent of NULL */
  #define NULL_CALLBACK ((G2CALLBACK) NULL)
  #define NULL_GETCALLBACK ((G2GETCALLBACK) NULL)

  /* constants for defining data structures */
  #define MAX_SCORING_TUPLES 1024
  #define MAX_RESULT_TUPLES 100
  #define MAX_STRING_RESULT_LENGTH 10

  /* constants for special error conditions */
  #define PLUGIN_SUCCESS 0
  #define PLUGIN_SUCCESS_WITH_INFO 1
  #define PLUGIN_SIMPLE_ERROR -1
  #define PLUGIN_CRITICAL_ERROR -20
  #define PLUGIN_OUTPUT_BUFFER_SIZE_ERROR -5

  /* basic data field structures */
  struct CTuple
  {
    const char* type;
    const char* value;
    int listFormat; /* a boolean */
  };
  struct CNumTuple
  {
    const char* type;
    long* value;
  };
  struct CStringResultTuple
  {
    const char* type;
    char value[MAX_STRING_RESULT_LENGTH];
  };

  /* typedefs for data field structures */
  typedef struct CTuple CFelemTuples[MAX_SCORING_TUPLES];
  typedef struct CTuple CScoringTuples[MAX_SCORING_TUPLES];
  typedef struct CNumTuple CResultNumTuples[MAX_RESULT_TUPLES];
  typedef struct CStringResultTuple CResultStringTuples[MAX_RESULT_TUPLES];

  /* the function prototype used to initialize/close a plugin */
  typedef int InitPluginFunc(const char *configInfo, char *errorStr, const size_t maxErrorStrSize, G2GETCALLBACK getCallback, G2CALLBACK callback1, G2CALLBACK callback2, G2CALLBACK callback3);
  typedef InitPluginFunc* InitPluginFuncPtr;
  typedef int ClosePluginFunc();
  typedef ClosePluginFunc* ClosePluginFuncPtr;

  /* the function prototype used to get a plugin version */
  typedef const char* GetVersionFunc();
  typedef GetVersionFunc* GetVersionFuncPtr;

  /* function pointer types for scoring */
  typedef const char* GetScoreNamesFunc();
  typedef GetScoreNamesFunc* GetScoreNamesFuncPtr;
  typedef int ScoreSimpleFunc(const char *ftypeCode, const char *felemCode, const char *inboundStr, const int inboundIsHashed, const char *matchedStr, const int matchedIsHashed, char *behavior, const size_t maxBehaviorBufferSize, int* resultScore, char *errorStr, const size_t maxErrorStrSize);
  typedef ScoreSimpleFunc* ScoreSimpleFuncPtr;
  typedef int ScorePairFunc(const char* ftypeCode, const char *felemCode1, const char *felemCode2, const char *inboundStr1, const char *inboundStr2, const int inboundIsHashed, const char *matchedStr1, const char *matchedStr2, const int matchedIsHashed, char *behavior, const size_t maxBehaviorBufferSize, int* resultScore, char *errorStr, const size_t maxErrorStrSize);
  typedef ScorePairFunc* ScorePairFuncPtr;
  typedef int ScoreSetFunc(const char* ftypeCode, const CScoringTuples *inT, const int inboundIsHashed, const CScoringTuples *matT, const int matchedIsHashed, CResultNumTuples *retT, CResultStringTuples *retT2, char *errorStr, const size_t maxErrorStrSize);
  typedef ScoreSetFunc* ScoreSetFuncPtr;

  /* function pointer types for DQM */
  typedef int RunDQMFunc(const char *ftypeCode, const char *inputStr, char *result, const size_t resultBufferSize, const int isHashed, char *errorStr, const size_t maxErrorStrSize);
  typedef RunDQMFunc* RunDQMFuncPtr;

  /* function pointer types for expressed feature creation */
  typedef int CreateEFeatFunc(const char *bomStr, char *result, const size_t resultBufferSize, char *errorStr, const size_t maxErrorStrSize);
  typedef CreateEFeatFunc* CreateEFeatFuncPtr;

  /* function pointer types for distinct features */
  typedef int CheckForGeneralizationFunc(const char* ftypeCode, const CFelemTuples *primaryT, const int primaryIsHashed, const CFelemTuples *possiblyGeneralizationT, const int possiblyGeneralizationIsHashed, int* result, char *errorStr, const size_t maxErrorStrSize);
  typedef CheckForGeneralizationFunc* CheckForGeneralizationFuncPtr;


#ifdef __cplusplus
}
#endif

#endif /* G2PLUGIN_H_INCLUDED */

