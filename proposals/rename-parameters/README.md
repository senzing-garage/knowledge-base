# Renaming parameters

  _DLEXPORT long long G2_init(const char *moduleName, const char*iniParams, const long long verboseLogging);
  _DLEXPORT long long G2_initWithConfigID(const char *moduleName, const char*iniParams, const long long initConfigID, const long long verboseLogging);
  _DLEXPORT long long G2_reinit(const long long initConfigID);
  _DLEXPORT long long G2_destroy();
  _DLEXPORT long long G2_primeEngine();
  _DLEXPORT long long G2_process(const char *record);
  _DLEXPORT long long G2_processWithInfo(const char*record, const long long flags, char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void*ptr, size_t newSize));
  _DLEXPORT long long G2_processWithResponse(const char *record, char*responseBuf, const size_t bufSize);
  _DLEXPORT long long G2_processWithResponseResize(const char *record, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );
  _DLEXPORT long long G2_checkRecord(const char *record, const char* recordQueryList, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );
  _DLEXPORT long long G2_processRedoRecord(char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize) );
  _DLEXPORT long long G2_processRedoRecordWithInfo(const long long flags, char **responseBuf, size_t*bufSize, char**infoBuf, size_t *infoBufSize, void*(*resizeFunc)(void*ptr, size_t newSize));
  _DLEXPORT long long G2_getRedoRecord(char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void*ptr, size_t newSize) );
  _DLEXPORT long long G2_countRedoRecords();
  _DLEXPORT long long G2_stats(char**responseBuf, size_t *bufSize, void*(*resizeFunc)(void*ptr, size_t newSize) );
  _DLEXPORT long long G2_exportConfig(char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void *ptr, size_t newSize) );
  _DLEXPORT long long G2_exportConfigAndConfigID(char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize), long long* configID );
  _DLEXPORT long long G2_getActiveConfigID(long long* configID);
  _DLEXPORT long long G2_getRepositoryLastModifiedTime(long long* lastModifiedTime);
  _DLEXPORT long long G2_addRecord(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID);
  _DLEXPORT long long G2_addRecordWithReturnedRecordID(const char* dataSourceCode, const char* jsonData, const char *loadID, char *recordIDBuf, const size_t bufSize);
  _DLEXPORT long long G2_addRecordWithInfo(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_addRecordWithInfoWithReturnedRecordID(const char* dataSourceCode, const char* jsonData, const char*loadID, const long long flags, char *recordIDBuf, const size_t recordIDBufSize, char**responseBuf, size_t *responseBufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_replaceRecord(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID);
  _DLEXPORT long long G2_replaceRecordWithInfo(const char* dataSourceCode, const char* recordID, const char* jsonData, const char *loadID, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_reevaluateRecord(const char* dataSourceCode, const char* recordID, const long long flags);
  _DLEXPORT long long G2_reevaluateEntity(const long long entityID, const long long flags);
  _DLEXPORT long long G2_reevaluateRecordWithInfo(const char* dataSourceCode, const char* recordID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_reevaluateEntityWithInfo(const long long entityID, const long long flags, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

* @brief
* This method is used to delete observation data from the system.  This
* removes a single entity observation record, by removing all of its
* feature data and the observation itself.
   *
   * @param dataSourceCode The data source for the observation.
   * @param recordID The ID for the record
   * @param loadID The observation load ID for the record, can be NULL and will default to dataSourceCode
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
  _DLEXPORT long long G2_deleteRecord(const char* dataSourceCode, const char*recordID, const char* loadID);
  _DLEXPORT long long G2_deleteRecordWithInfo(const char*dataSourceCode, const char* recordID, const char*loadID, const long long flags, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

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
  _DLEXPORT long long G2_searchByAttributes(const char* jsonData, char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_searchByAttributes_V2(const char* jsonData, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_searchByAttributes_V3(const char* jsonData, const char* searchProfile, const long long flags, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

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
  _DLEXPORT long long G2_getEntityByEntityID(const long long entityID, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getEntityByEntityID_V2(const long long entityID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getEntityByRecordID(const char* dataSourceCode, const char* recordID, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getEntityByRecordID_V2(const char* dataSourceCode, const char* recordID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

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
  _DLEXPORT long long G2_getRecord(const char* dataSourceCode, const char*recordID, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getRecord_V2(const char* dataSourceCode, const char* recordID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

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
  _DLEXPORT long long G2_findPathByEntityID(const long long entityID1, const long long entityID2, const long long maxDegree, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathByEntityID_V2(const long long entityID1, const long long entityID2, const long long maxDegree, const long long flags, char**responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathByRecordID(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long maxDegree, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathByRecordID_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long maxDegree, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

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
  _DLEXPORT long long G2_findPathExcludingByEntityID(const long long entityID1, const long long entityID2, const long long maxDegree, const char* excludedEntities, char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathExcludingByEntityID_V2(const long long entityID1, const long long entityID2, const long long maxDegree, const char* excludedEntities, const long long flags, char**responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathExcludingByRecordID(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long maxDegree, const char* excludedRecords, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathExcludingByRecordID_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long maxDegree, const char* excludedRecords, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

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
  _DLEXPORT long long G2_findPathIncludingSourceByEntityID(const long long entityID1, const long long entityID2, const long long maxDegree, const char* excludedEntities, const char*requiredDsrcs, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathIncludingSourceByEntityID_V2(const long long entityID1, const long long entityID2, const long long maxDegree, const char* excludedEntities, const char* requiredDsrcs, const long long flags, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathIncludingSourceByRecordID(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long maxDegree, const char* excludedRecords, const char* requiredDsrcs, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findPathIncludingSourceByRecordID_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long maxDegree, const char* excludedRecords, const char* requiredDsrcs, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

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
  _DLEXPORT long long G2_findNetworkByEntityID(const char* entityList, const long long maxDegree, const long long buildOutDegree, const long long maxEntities, char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findNetworkByEntityID_V2(const char* entityList, const long long maxDegree, const long long buildOutDegree, const long long maxEntities, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findNetworkByRecordID(const char* recordList, const long long maxDegree, const long long buildOutDegree, const long long maxEntities, char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findNetworkByRecordID_V2(const char* recordList, const long long maxDegree, const long long buildOutDegree, const long long maxEntities, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This method determines what interesting entities exist around a particular resolved entity
   */
  _DLEXPORT long long G2_findInterestingEntitiesByEntityID(const long long entityID, const long long flags, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_findInterestingEntitiesByRecordID(const char* dataSourceCode, const char* recordID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This method determines why records are included in the resolved entity they belong to.
   */
  _DLEXPORT long long G2_whyEntityByRecordID(const char* dataSourceCode, const char*recordID, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyEntityByRecordID_V2(const char* dataSourceCode, const char* recordID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyEntityByEntityID(const long long entityID, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyEntityByEntityID_V2(const long long entityID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This method determines why a particular record is included in its resolved entity.
   */
  _DLEXPORT long long G2_whyRecordInEntity(const char* dataSourceCode, const char*recordID, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyRecordInEntity_V2(const char* dataSourceCode, const char* recordID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This method determines how records are related to each other.
   */
  _DLEXPORT long long G2_whyRecords(const char* dataSourceCode1, const char*recordID1, const char* dataSourceCode2, const char*recordID2, char **responseBuf, size_t *bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyRecords_V2(const char* dataSourceCode1, const char* recordID1, const char* dataSourceCode2, const char* recordID2, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This method determines how entities are related to each other.
   */
  _DLEXPORT long long G2_whyEntities(const long long entityID1, const long long entityID2, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_whyEntities_V2(const long long entityID1, const long long entityID2, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This method gives information on how entities were constructed from their base records.
   */
  _DLEXPORT long long G2_howEntityByEntityID(const long long entityID, char **responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_howEntityByEntityID_V2(const long long entityID, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This method gives information on how an entity composed of a given set of records would look
   */
  _DLEXPORT long long G2_getVirtualEntityByRecordID(const char* recordList, char **responseBuf, size_t *bufSize, void*(*resizeFunc)(void *ptr, size_t newSize));
  _DLEXPORT long long G2_getVirtualEntityByRecordID_V2(const char* recordList, const long long flags, char**responseBuf, size_t*bufSize, void *(*resizeFunc)(void *ptr, size_t newSize));

  /**

   * @brief
   * This is used to purge all data from an existing repository
   * @return Returns 0 for success, or an appropriate error code.
   */
  _DLEXPORT long long G2_purgeRepository();

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
   *        "G2_EXPORT_INCLUDE_SINGLETONS".  The default and recommended
   *        value is "G2_EXPORT_DEFAULT_FLAGS".
   *
   * @return Returns an export handle that the entity data can be read from.
   */
  _DLEXPORT long long G2_exportJSONEntityReport(const long long flags, ExportHandle* responseHandle);

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
   *        "G2_EXPORT_INCLUDE_SINGLETONS".  The default and recommended
   *        value is "G2_EXPORT_DEFAULT_FLAGS".
   *
   * @return Returns an export handle that the entity data can be read from.
   */
  _DLEXPORT long long G2_exportCSVEntityReport(const char* csvColumnList, const long long flags, ExportHandle* responseHandle);

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
  _DLEXPORT long long G2_fetchNext(ExportHandle responseHandle, char*responseBuf, const size_t bufSize);

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
  _DLEXPORT long long G2_getLastException(char*buffer, const size_t bufSize);

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

# ifdef __cplusplus
};
# endif

# endif /*LIBG2_H*/
