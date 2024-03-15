/**********************************************************************************
 © Copyright Senzing, Inc. 2017-2024
 The source code for this program is not published or otherwise divested
 of its trade secrets, irrespective of what has been deposited with the U.S.
 Copyright Office.
**********************************************************************************/


#ifndef LIBG2_H
#define LIBG2_H


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

  /******************************************************
  ****  Flags for exporting entity data
  ******************************************************/

  /* we should include entities with "resolved" relationships */
  #define G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES static_cast<long long>( 1LL << 0 )
  /* we should include entities with "possibly same" relationships */
  #define G2_EXPORT_INCLUDE_POSSIBLY_SAME static_cast<long long>( 1LL << 1 )
  /* we should include entities with "possibly related" relationships */
  #define G2_EXPORT_INCLUDE_POSSIBLY_RELATED static_cast<long long>( 1LL << 2 )
  /* we should include entities with "name only" relationships */
  #define G2_EXPORT_INCLUDE_NAME_ONLY static_cast<long long>( 1LL << 3 )
  /* we should include entities with "disclosed" relationships */
  #define G2_EXPORT_INCLUDE_DISCLOSED static_cast<long long>( 1LL << 4 )
  /* we should include singleton entities */
  #define G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES static_cast<long long>( 1LL << 5 )
  /* we should include all entities */
  #define G2_EXPORT_INCLUDE_ALL_ENTITIES        \
            (G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES         \
            | G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES)
  /* we should include all entities with relationships */
  #define G2_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS      \
            (G2_EXPORT_INCLUDE_POSSIBLY_SAME       \
            | G2_EXPORT_INCLUDE_POSSIBLY_RELATED   \
            | G2_EXPORT_INCLUDE_NAME_ONLY          \
            | G2_EXPORT_INCLUDE_DISCLOSED)

  /******************************************************
  ****  Flags for outputting entity relation data
  ******************************************************/

  /* include "possibly same" relationships on entities */
  #define G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS static_cast<long long>( 1LL << 6 )
  /* include "possibly related" relationships on entities */
  #define G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS static_cast<long long>( 1LL << 7 )
  /* include "name only" relationships on entities */
  #define G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS static_cast<long long>( 1LL << 8 )
  /* include "disclosed" relationships on entities */
  #define G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS static_cast<long long>( 1LL << 9 )
  /* include all relationships on entities */
  #define G2_ENTITY_INCLUDE_ALL_RELATIONS                   \
            (G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS      \
            | G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS  \
            | G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS         \
            | G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS)

  /******************************************************
  ****  Flags for outputting entity feature data
  ******************************************************/

  /* include all features for entities */
  #define G2_ENTITY_INCLUDE_ALL_FEATURES static_cast<long long>( 1LL << 10 )
  /* include only representative features on entities */
  #define G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES static_cast<long long>( 1LL << 11 )

  /******************************************************
  ****  Flags for getting extra information about an entity
  ******************************************************/

  /* include the name of the entity */
  #define G2_ENTITY_INCLUDE_ENTITY_NAME static_cast<long long>( 1LL << 12 )
  /* include the record summary of the entity */
  #define G2_ENTITY_INCLUDE_RECORD_SUMMARY static_cast<long long>( 1LL << 13 )
  /* include the record types of the entity */
  #define G2_ENTITY_INCLUDE_RECORD_TYPES static_cast<long long>( 1LL << 28 )
  /* include the basic record data for the entity  */
  #define G2_ENTITY_INCLUDE_RECORD_DATA static_cast<long long>( 1LL << 14 )
  /* include the record matching info for the entity */
  #define G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO static_cast<long long>( 1LL << 15 )
  /* include the record json data for the entity */
  #define G2_ENTITY_INCLUDE_RECORD_JSON_DATA static_cast<long long>( 1LL << 16 )
  /* include the record unmapped data for the entity */
  #define G2_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA static_cast<long long>( 1LL << 31 )
  /* include the features identifiers for the records */
  #define G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS static_cast<long long>( 1LL << 18 )
  /* include the name of the related entities */
  #define G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME static_cast<long long>( 1LL << 19 )
  /* include the record matching info of the related entities */
  #define G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO static_cast<long long>( 1LL << 20 )
  /* include the record summary of the related entities */
  #define G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY static_cast<long long>( 1LL << 21 )
  /* include the record types of the related entities */
  #define G2_ENTITY_INCLUDE_RELATED_RECORD_TYPES static_cast<long long>( 1LL << 29 )
  /* include the basic record of the related entities */
  #define G2_ENTITY_INCLUDE_RELATED_RECORD_DATA static_cast<long long>( 1LL << 22 )

  /******************************************************
  ****  Flags for extra feature data
  ******************************************************/

  /* include internal features  */
  #define G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES static_cast<long long>( 1LL << 23 )
  /* include statistics on features */
  #define G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS static_cast<long long>( 1LL << 24 )
  /* include feature elements */
  #define G2_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS static_cast<long long>( 1LL << 32 )

  /******************************************************
  ****  Flags for extra matching data
  ******************************************************/

  /* include internal features  */
  #define G2_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS static_cast<long long>( 1LL << 34 )

  /******************************************************
  ****  Flags for finding entity path data
  ******************************************************/

  /* excluded entities are still allowed, but not preferred */
  #define G2_FIND_PATH_PREFER_EXCLUDE static_cast<long long>( 1LL << 25 )
  /* include matching info on entity paths */
  #define G2_FIND_PATH_MATCHING_INFO static_cast<long long>( 1LL << 30 )
  /* include matching info on entity networks */
  #define G2_FIND_NETWORK_MATCHING_INFO static_cast<long long>( 1LL << 33 )

  /******************************************************
  ****  Flags for including search result feature scores
  ******************************************************/

  /* include feature scores */
  #define G2_INCLUDE_FEATURE_SCORES static_cast<long long>( 1LL << 26 )
  /* include statistics from search results */
  #define G2_SEARCH_INCLUDE_STATS static_cast<long long>( 1LL << 27 )
  /* include feature scores from search results */
  #define G2_SEARCH_INCLUDE_FEATURE_SCORES (G2_INCLUDE_FEATURE_SCORES)
  /* include detailed match key in search results */
  #define G2_SEARCH_INCLUDE_MATCH_KEY_DETAILS (G2_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS)

  /******************************************************
  ****  Flags for searching for entities
  ******************************************************/

  #define G2_SEARCH_INCLUDE_RESOLVED (G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES)
  #define G2_SEARCH_INCLUDE_POSSIBLY_SAME (G2_EXPORT_INCLUDE_POSSIBLY_SAME)
  #define G2_SEARCH_INCLUDE_POSSIBLY_RELATED (G2_EXPORT_INCLUDE_POSSIBLY_RELATED)
  #define G2_SEARCH_INCLUDE_NAME_ONLY (G2_EXPORT_INCLUDE_NAME_ONLY)
  #define G2_SEARCH_INCLUDE_ALL_ENTITIES          \
            (G2_SEARCH_INCLUDE_RESOLVED           \
            | G2_SEARCH_INCLUDE_POSSIBLY_SAME     \
            | G2_SEARCH_INCLUDE_POSSIBLY_RELATED  \
            | G2_SEARCH_INCLUDE_NAME_ONLY)

  
  /******************************************************
  ****  Recommended settings for various API functions
  ******************************************************/

  /* the recommended default flag values for getting records */
  #define G2_RECORD_DEFAULT_FLAGS                 \
            (G2_ENTITY_INCLUDE_RECORD_JSON_DATA)

  /* the recommended default flag values for getting entities */
  #define G2_ENTITY_DEFAULT_FLAGS                          \
            (G2_ENTITY_INCLUDE_ALL_RELATIONS               \
              | G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES  \
              | G2_ENTITY_INCLUDE_ENTITY_NAME              \
              | G2_ENTITY_INCLUDE_RECORD_SUMMARY           \
              | G2_ENTITY_INCLUDE_RECORD_DATA              \
              | G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO     \
              | G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME      \
              | G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY   \
              | G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO)

  /* the recommended default flag values for a brief entity result */
  #define G2_ENTITY_BRIEF_DEFAULT_FLAGS                   \
            (G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO       \
              | G2_ENTITY_INCLUDE_ALL_RELATIONS           \
              | G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO)

  /* the recommended default flag values for exporting entities */
  #define G2_EXPORT_DEFAULT_FLAGS                          \
            (G2_EXPORT_INCLUDE_ALL_ENTITIES                \
              | G2_ENTITY_DEFAULT_FLAGS)

  /* the recommended default flag values for finding entity paths */
  #define G2_FIND_PATH_DEFAULT_FLAGS                      \
            (G2_FIND_PATH_MATCHING_INFO                   \
              | G2_ENTITY_INCLUDE_ENTITY_NAME             \
              | G2_ENTITY_INCLUDE_RECORD_SUMMARY)
  #define G2_FIND_NETWORK_DEFAULT_FLAGS                   \
            (G2_FIND_NETWORK_MATCHING_INFO                \
              | G2_ENTITY_INCLUDE_ENTITY_NAME             \
              | G2_ENTITY_INCLUDE_RECORD_SUMMARY)

  /* the recommended default flag values for why-analysis on entities */
  #define G2_WHY_ENTITIES_DEFAULT_FLAGS                      \
            (G2_ENTITY_DEFAULT_FLAGS                         \
              | G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES   \
              | G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS       \
              | G2_INCLUDE_FEATURE_SCORES) 
  #define G2_WHY_RECORDS_DEFAULT_FLAGS                       \
            (G2_ENTITY_DEFAULT_FLAGS                         \
              | G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES   \
              | G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS       \
              | G2_INCLUDE_FEATURE_SCORES) 
  #define G2_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS              \
            (G2_ENTITY_DEFAULT_FLAGS                         \
              | G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES   \
              | G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS       \
              | G2_INCLUDE_FEATURE_SCORES) 

  /* the recommended default flag values for how-analysis on entities */
  #define G2_HOW_ENTITY_DEFAULT_FLAGS                        \
            (G2_INCLUDE_FEATURE_SCORES)

  /* the recommended default flag values for virtual-entity-analysis on entities */
  #define G2_VIRTUAL_ENTITY_DEFAULT_FLAGS                   \
            (G2_ENTITY_DEFAULT_FLAGS)


  /******************************************************
  ****  Recommended settings for searching by attributes
  ******************************************************/

  /* the recommended flag values for searching by attributes, returning all matching entities */
  #define G2_SEARCH_BY_ATTRIBUTES_ALL                       \
            (G2_SEARCH_INCLUDE_ALL_ENTITIES                 \
              | G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES   \
              | G2_ENTITY_INCLUDE_ENTITY_NAME               \
              | G2_ENTITY_INCLUDE_RECORD_SUMMARY            \
              | G2_SEARCH_INCLUDE_FEATURE_SCORES)
  /* the recommended flag values for searching by attributes, returning only strongly matching entities */
  #define G2_SEARCH_BY_ATTRIBUTES_STRONG                    \
            (G2_SEARCH_INCLUDE_RESOLVED                     \
              | G2_SEARCH_INCLUDE_POSSIBLY_SAME             \
              | G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES   \
              | G2_ENTITY_INCLUDE_ENTITY_NAME               \
              | G2_ENTITY_INCLUDE_RECORD_SUMMARY            \
              | G2_SEARCH_INCLUDE_FEATURE_SCORES)
  /* return minimal data with all matches */
  #define G2_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL       \
            (G2_SEARCH_INCLUDE_ALL_ENTITIES)
  /* return minimal data with only the strongest matches */
  #define G2_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG    \
            (G2_SEARCH_INCLUDE_RESOLVED             \
              | G2_SEARCH_INCLUDE_POSSIBLY_SAME )
  /* the recommended default flag values for search-by-attributes */
  #define G2_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS     \
            (G2_SEARCH_BY_ATTRIBUTES_ALL)


  /**
   * @brief
   * This method will initialize the G2 processing object.  It must be called
   * once per process, prior to any other calls.
   *
   * @param moduleName A name for the processing node, to help identify it within
   *        system logs.
   * @param iniParams A JSON string containing configuration paramters.
   * @param initConfigID Identifier for the configuration to use in initialization.
   * @param verboseLogging A flag to enable deeper logging of the G2 processing
   */
  _DLEXPORT long long G2_init(
                            const char *moduleName,
                            const char *iniParams,
                            const long long verboseLogging);
  _DLEXPORT long long G2_initWithConfigID(
                            const char *moduleName,
                            const char *iniParams,
                            const long long initConfigID,
                            const long long verboseLogging);


  /**
   * @brief
   * This method will re-initialize the G2 processing object.
   */
  _DLEXPORT long long G2_reinit(const long long initConfigID);


  /**
   * @brief
   * This method will destroy and perform cleanup for the G2 processing object.  It
   * should be called after all other calls are complete.
   */
  _DLEXPORT long long G2_destroy();


  /**
   * @brief
   * This method may optionally be called to pre-initialize some of the heavier weight
   * internal resources of the G2 engine.
   */
  _DLEXPORT long long G2_primeEngine();


  /**
   * @brief Process a record contained in the internal redo-queue
   * 
   * @param redoRecord Null terminated UT8-JSON record from G2_getRedoRecord
   * @param infoBuf Same as responseBuf. In a success, returns info about the 
            affected entities
   * @param infoBufSize Same as bufSize but for infoBuf
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   */
  _DLEXPORT long long G2_processRedoRecord(const char *redoRecord);
  _DLEXPORT long long G2_processRedoRecordWithInfo(const char *redoRecord,
                            char **infoBuf,
                            size_t *infoBufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief Retrieve a record contained in the internal redo-queue
   * 
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   */
  _DLEXPORT long long G2_getRedoRecord(
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief Get the number of records contained in the internal redo-queue
   */
  _DLEXPORT long long G2_countRedoRecords();


  /**
   * @brief
   * This method returns a JSON document that provides basic statistics on
   * the requests made through the G2 object.  It returns things such as the
   * number of records loaded, the duration of processing time, the number of
   * retries made, etc.
   * 
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   */
  _DLEXPORT long long G2_stats(
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize) );


  /**
   * @brief
   * This method returns an identifier for the loaded G2 engine configuration
   * 
   * @param configID The identifier value for the config.
   */
  _DLEXPORT long long G2_getActiveConfigID(long long* configID);


  /**
   * @brief
   * This method returns the timestamp of when the entity datastore was last modified.
   * This is a long integer representing number of seconds since 
   * January 1, 1970 12:00am GMT (epoch time)
   * 
   * @param lastModifiedTime The last modified time.
   */
  _DLEXPORT long long G2_getRepositoryLastModifiedTime(long long* lastModifiedTime);


  /**
   * @brief
   * This method is used to add entity data into the system.  This adds or
   * updates a single entity observation record, by adding features for the 
   * observation.
   * 
   * @param dataSourceCode The data source for the observation.
   * @param recordID The ID for the record
   * @param jsonData A JSON document containing the attribute information
   *        for the observation.
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the module transport is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_addRecord(
                            const char* dataSourceCode,
                            const char* recordID,
                            const char* jsonData);
  _DLEXPORT long long G2_addRecordWithInfo(
                            const char* dataSourceCode,
                            const char* recordID,
                            const char* jsonData,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_replaceRecord(
                            const char* dataSourceCode,
                            const char* recordID,
                            const char* jsonData);
  _DLEXPORT long long G2_replaceRecordWithInfo(
                            const char* dataSourceCode,
                            const char* recordID,
                            const char* jsonData,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief Reevaluate an entity in the database.
   */
  _DLEXPORT long long G2_reevaluateRecord(
                            const char* dataSourceCode,
                            const char* recordID,
                            const long long flags);
  _DLEXPORT long long G2_reevaluateEntity(
                            const long long entityID,
                            const long long flags);
  _DLEXPORT long long G2_reevaluateRecordWithInfo(
                            const char* dataSourceCode,
                            const char* recordID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_reevaluateEntityWithInfo(
                            const long long entityID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to delete observation data from the system.  This
   * removes a single entity observation record, by removing all of its
   * feature data and the observation itself.
   * 
   * @param dataSourceCode The data source for the observation.
   * @param recordID The ID for the record
   * @param responseBuf A buffer that returns a JSON object that summaries the changes cased by adding the
   *        record. Also contains the recordID.
   * @param bufSize The size of the responseBuf buffer
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_deleteRecord(
                            const char* dataSourceCode,
                            const char* recordID);
  _DLEXPORT long long G2_deleteRecordWithInfo(
                            const char* dataSourceCode,
                            const char* recordID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method searches for entities that contain attribute information
   * that are relevant to a set of input search attributes.
   * 
   * @param jsonData A JSON document containing the attribute information
   *        to search for
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_searchByAttributes(
                            const char* jsonData,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_searchByAttributes_V2(
                            const char* jsonData,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_searchByAttributes_V3(
                            const char* jsonData,
                            const char* searchProfile,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to retrieve information about a specific resolved 
   * entity.  The information is returned as a JSON document.
   *
   * @param entityID The resolved entity to retrieve information for
   * @param dataSourceCode The data source of the observation to search for
   * @param recordID The record ID of the observation to search for
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_getEntityByEntityID(
                            const long long entityID,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getEntityByEntityID_V2(
                            const long long entityID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getEntityByRecordID(
                            const char* dataSourceCode,
                            const char* recordID,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getEntityByRecordID_V2(
                            const char* dataSourceCode,
                            const char* recordID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to retrieve a stored record.
   * 
   * @param dataSourceCode The data source of the observation to search for
   * @param recordID The record ID of the observation to search for
   * @param responseBuf A memory buffer for returning the response document.
   *        If an error occurred, an error response is stored here.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold at least this many bytes,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_getRecord(
                            const char* dataSourceCode,
                            const char* recordID,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getRecord_V2(
                            const char* dataSourceCode,
                            const char* recordID,
                            const long long flags, 
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to find a relationship path between entities.
   * 
   * @param entityID1 The starting entity of the relationship path
   * @param entityID2 The ending entity of the relationship path
   * @param dataSourceCode1 The data source for the starting record of the relationship path
   * @param recordID1 The record ID for the starting record of the relationship path
   * @param dataSourceCode2 The data source for the ending record of the relationship path
   * @param recordID2 The record ID for the ending record of the relationship path
   * @param maxDegree The maximum degree of relationships to search
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_findPathByEntityID(
                            const long long entityID1,
                            const long long entityID2,
                            const long long maxDegree,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathByEntityID_V2(
                            const long long entityID1,
                            const long long entityID2,
                            const long long maxDegree,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathByRecordID(
                            const char* dataSourceCode1,
                            const char* recordID1,
                            const char* dataSourceCode2,
                            const char* recordID2,
                            const long long maxDegree,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathByRecordID_V2(
                            const char* dataSourceCode1,
                            const char* recordID1,
                            const char* dataSourceCode2,
                            const char* recordID2, 
                            const long long maxDegree,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to find a relationship path between entities, that excludes
   * a particular set of entities.
   * 
   * @param entityID1 The starting entity of the relationship path
   * @param entityID2 The ending entity of the relationship path
   * @param dataSourceCode1 The data source for the starting record of the relationship path
   * @param recordID1 The record ID for the starting record of the relationship path
   * @param dataSourceCode2 The data source for the ending record of the relationship path
   * @param recordID2 The record ID for the ending record of the relationship path
   * @param maxDegree The maximum degree of relationships to search
   * @param excludedEntities A JSON document identifying the list of entities to
   *        exclude from the path.  
   *        (example:  {"ENTITIES":[{"ENTITY_ID":"6"},{"ENTITY_ID":"11"},{"ENTITY_ID":"9"}]} )
   * @param excludedRecords A JSON document identifying the list of records for
   *        entities to exclude from the path.  
   *        (example:  {"RECORDS":[{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1504"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1507"}]} )
   * @param flags A bit mask specifying control flags, such as 
   *        "G2_FIND_PATH_PREFER_EXCLUDE".  The default and recommended
   *        value is "G2_FIND_PATH_DEFAULT_FLAGS".
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_findPathExcludingByEntityID(
                            const long long entityID1,
                            const long long entityID2,
                            const long long maxDegree,
                            const char* excludedEntities,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathExcludingByEntityID_V2(
                            const long long entityID1,
                            const long long entityID2,
                            const long long maxDegree,
                            const char* excludedEntities,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathExcludingByRecordID(
                            const char* dataSourceCode1,
                            const char* recordID1,
                            const char* dataSourceCode2,
                            const char* recordID2,
                            const long long maxDegree, 
                            const char* excludedRecords,
                            char **responseBuf,
                            size_t *bufSize, 
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathExcludingByRecordID_V2(
                            const char* dataSourceCode1,
                            const char* recordID1, 
                            const char* dataSourceCode2, 
                            const char* recordID2, 
                            const long long maxDegree,
                            const char* excludedRecords, 
                            const long long flags,
                            char **responseBuf, 
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method is used to find a relationship path between entities, that excludes
   * a particular set of entities, and also requires at least one data source from a
   * set to be part of the path.
   * 
   * @param entityID1 The starting entity of the relationship path
   * @param entityID2 The ending entity of the relationship path
   * @param dataSourceCode1 The data source for the starting record of the relationship path
   * @param recordID1 The record ID for the starting record of the relationship path
   * @param dataSourceCode2 The data source for the ending record of the relationship path
   * @param recordID2 The record ID for the ending record of the relationship path
   * @param maxDegree The maximum degree of relationships to search
   * @param excludedEntities A JSON document identifying the list of entities to
   *        exclude from the path.  
   *        (example:  {"ENTITIES":[{"ENTITY_ID":"6"},{"ENTITY_ID":"11"},{"ENTITY_ID":"9"}]} )
   * @param excludedRecords A JSON document identifying the list of records for
   *        entities to exclude from the path.  
   *        (example:  {"RECORDS":[{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1504"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1507"}]} )
   * @param requiredDsrcs A JSON document identifying the list of data sources to watch for
   *        (example:  {"DATA_SOURCES":["PEOPLE","COMPANIES"]} )
   * @param flags A bit mask specifying control flags, such as 
   *        "G2_FIND_PATH_PREFER_EXCLUDE".  The default and recommended
   *        value is "G2_FIND_PATH_DEFAULT_FLAGS".
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_findPathIncludingSourceByEntityID(
                            const long long entityID1,
                            const long long entityID2,
                            const long long maxDegree,
                            const char* excludedEntities,
                            const char* requiredDsrcs,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathIncludingSourceByEntityID_V2(
                            const long long entityID1,
                            const long long entityID2,
                            const long long maxDegree,
                            const char* excludedEntities,
                            const char* requiredDsrcs,
                            const long long flags,
                            char **responseBuf, 
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathIncludingSourceByRecordID(
                            const char* dataSourceCode1,
                            const char* recordID1,
                            const char* dataSourceCode2,
                            const char* recordID2,
                            const long long maxDegree, 
                            const char* excludedRecords,
                            const char* requiredDsrcs,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathIncludingSourceByRecordID_V2(
                            const char* dataSourceCode1,
                            const char* recordID1,
                            const char* dataSourceCode2, 
                            const char* recordID2, 
                            const long long maxDegree,
                            const char* excludedRecords,
                            const char* requiredDsrcs, 
                            const long long flags, 
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));

 
  /**
   * @brief
   * This method is used to find a network of entity relationships, surrounding the paths between
   * a set of entities.
   * 
   * @param entityList A JSON document identifying the list of entities to
   *        find paths between and a network around. 
   *        (example:  {"ENTITIES":[{"ENTITY_ID":"6"},{"ENTITY_ID":"11"},{"ENTITY_ID":"9"}]} )
   * @param recordList A JSON document identifying the list of record entities to
   *        find paths between and a network around. 
   *        (example:  {"RECORDS":[{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1504"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1507"},{"DATA_SOURCE":"PEOPLE","RECORD_ID":"1510"}]} )
   * @param maxDegree The maximum degree of relationships to search for a path
   * @param buildOutDegree The maximum degree of relationships to include in the network
   *        around each entity
   * @param maxEntities The maximum number of entities to return
   * @param responseBuf A memory buffer for returning the response document.
   * @param bufSize The max number of bytes that can be stored in responseBuf.
   *        The response buffer must be able to hold the whole response message,
   *        or a resize method must be provided that may be used to resize
   *        the buffer.  This will return the new size.
   * @param resizeFunc A function pointer that can be used to resize the memory
   *        buffer specified in the responseBuf argument.  This function will
   *        be called to allocate more memory if the response buffer is not large
   *        enough.  This argument may be NULL.  If it is NULL, the function
   *        will return an error if the result is larger than the buffer.
   * @return Returns 0 for success. Returns -1 if the response status indicates
   *         failure or the G2 module is not initialized. Returns -2 if 
   *         an exception was thrown and caught.
   */
  _DLEXPORT long long G2_findNetworkByEntityID(
                            const char* entityList,
                            const long long maxDegree,
                            const long long buildOutDegree,
                            const long long maxEntities,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findNetworkByEntityID_V2(
                            const char* entityList,
                            const long long maxDegree,
                            const long long buildOutDegree,
                            const long long maxEntities,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findNetworkByRecordID(
                            const char* recordList,
                            const long long maxDegree,
                            const long long buildOutDegree,
                            const long long maxEntities,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findNetworkByRecordID_V2(
                            const char* recordList,
                            const long long maxDegree,
                            const long long buildOutDegree,
                            const long long maxEntities,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method determines what interesting entities exist around a particular resolved entity
   */
  _DLEXPORT long long G2_findInterestingEntitiesByEntityID(
                            const long long entityID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize, 
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findInterestingEntitiesByRecordID(
                            const char* dataSourceCode,
                            const char* recordID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method determines why a particular record is included in its resolved entity.
   */
  _DLEXPORT long long G2_whyRecordInEntity(
                            const char* dataSourceCode,
                            const char* recordID,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyRecordInEntity_V2(
                            const char* dataSourceCode, 
                            const char* recordID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method determines how records are related to each other.
   */
  _DLEXPORT long long G2_whyRecords(
                            const char* dataSourceCode1,
                            const char* recordID1,
                            const char* dataSourceCode2,
                            const char* recordID2,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyRecords_V2(
                            const char* dataSourceCode1,
                            const char* recordID1,
                            const char* dataSourceCode2,
                            const char* recordID2,
                            const long long flags, 
                            char **responseBuf,
                            size_t *bufSize, 
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  

  /**
   * @brief
   * This method determines how entities are related to each other.
   */
  _DLEXPORT long long G2_whyEntities(
                            const long long entityID1,
                            const long long entityID2,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyEntities_V2(
                            const long long entityID1,
                            const long long entityID2, 
                            const long long flags,
                            char **responseBuf, 
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method gives information on how entities were constructed from their base records.
   */
  _DLEXPORT long long G2_howEntityByEntityID(
                            const long long entityID,
                            char **responseBuf,
                            size_t *bufSize, 
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_howEntityByEntityID_V2(
                            const long long entityID,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /**
   * @brief
   * This method gives information on how an entity composed of a given set of records would look
   */
  _DLEXPORT long long G2_getVirtualEntityByRecordID(
                            const char* recordList,
                            char **responseBuf,
                            size_t *bufSize,
                            void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getVirtualEntityByRecordID_V2(
                            const char* recordList,
                            const long long flags,
                            char **responseBuf,
                            size_t *bufSize, 
                            void *(*resizeFunc)(void *ptr, size_t newSize));


  /* type definitions for exporting data  */
  typedef void* ExportHandle;


  /**
   * @brief
   * This is used to export entity data from known entities.  This function
   * returns an export-handle that can be read from to get the export data 
   * in JSON format.  The export-handle should be read using the "G2_fetchNext"
   * function, and closed when work is complete. Each output row contains the 
   * exported entity data for a single resolved entity.
   *
   * @param flags A bit mask specifying control flags, such as 
   *        "G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES".  The default and recommended
   *        value is "G2_EXPORT_DEFAULT_FLAGS".
   *
   * @return Returns an export handle that the entity data can be read from.
   */
  _DLEXPORT long long G2_exportJSONEntityReport(
                            const long long flags,
                            ExportHandle* responseHandle);


  /**
   * @brief
   * This is used to export entity data from known entities.  This function
   * returns an export-handle that can be read from to get the export data 
   * in CSV format.  The export-handle should be read using the "G2_fetchNext"
   * function, and closed when work is complete. The first output row returned 
   * by the export-handle contains the JSON column headers as a string.  Each 
   * following row contains the exported entity data.
   *
   * @param flags A bit mask specifying other control flags, such as 
   *        "G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES".  The default and recommended
   *        value is "G2_EXPORT_DEFAULT_FLAGS".
   *
   * @return Returns an export handle that the entity data can be read from.
   */
  _DLEXPORT long long G2_exportCSVEntityReport(
                            const char* csvColumnList,
                            const long long flags,
                            ExportHandle* responseHandle);


  /**
   * @brief
   * This function is used to read entity data from an export handle,
   * one data row at a time.
   *
   * @param responseHandle The export handle to retrieve data from
   * @param responseBuf The buffer to write the string data to
   * @param bufSize The size of the response buffer
   *
   * @return Returns a pointer to the buffer if successful, or -1 otherwise
   */
  _DLEXPORT long long G2_fetchNext(
                            ExportHandle responseHandle,
                            char *responseBuf,
                            const size_t bufSize);


  /**
   * @brief
   * This function closes an export handle, to clean up system resources.
   */
  _DLEXPORT long long G2_closeExport(ExportHandle responseHandle);

  
  /**
   * @brief
   * This function retrieves the last exception thrown in the engine
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2_getLastException(char *buffer, const size_t bufSize);


  /**
   * @brief
   * This function retrieves the code of the last exception thrown in the engine
   * @return number of bytes copied into buffer
   */
  _DLEXPORT long long G2_getLastExceptionCode();


  /**
   * @brief
   * This function clears the last exception thrown in libG2
   */
  _DLEXPORT void G2_clearLastException();


#ifdef __cplusplus 
};
#endif


#endif /* LIBG2_H */

