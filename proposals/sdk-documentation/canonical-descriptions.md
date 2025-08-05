# SDK Documentation - canonical description

 Proposal for [sdk-documentation].

 1. Guiding principles
    1. Approach from the customer point of view.
    1. First sentence is a "topic" sentence as it may show up in synopsis and code hints.
        1. Think of this as a newspaper headline:  short, concise, and differentiates it from other methods.
        1. Although the topic sentence starts with a verb in this list, each SDK may choose the appropriate introduction
            1. e.g.  *Go:* Method AddDataSource adds a new data source to this instance
    1. Less is better.
    1. Avoid redundancy.
        1. Overview shouldn't talk about parameter specifics.
        1. Specifics about parameters should be described in the parameters
    1. Tailoring to SDK language specific style is OK.

## SzConfig

An in-memory representation of the Senzing configuration.

1. **export**

    - Retrieves the definition for this configuration.

1. **getDataSourceRegistry**

    - Gets the data source registry for this configuration.

1. **registerDataSource**

    - Adds a data source to this configuration.
        - Because SzConfig is an in-memory representation,
          the repository is not changed unless the configuration
          is exported and then registered via ConfigManager.

1. **unregisterDataSource**

    - Removes a data source from this configuration.
        - Because SzConfig is an in-memory representation,
          the repository is not changed unless the configuration
          is exported and then registered via ConfigManager.
        - Is idempotent.
        - Warning: if records in the repository refer to the unregistered datasource,
          the configuration cannot be used as the active configuration.

## SzConfigManager

1. **createConfigFromConfigId**

    - Creates a new SzConfig instance for a configuration ID.
        - Returns:
            - Non-null;  exception if ID not recognized

1. **createConfigFromString**

    - Creates a new SzConfig instance from a configuration definition.

1. **createConfigFromTemplate**

    - Creates a new SzConfig instance from the template configuration definition.

1. **getConfigRegistry**

    - Gets the configuration registry.
        - The registry contains the original timestamp, original comment, and configuration ID of all
          configurations ever registered with the repository.
        - Registered configurations cannot be unregistered.

1. **getDefaultConfigId**

    - Gets the default configuration ID for the repository.
        - Unless an explicit configuration ID is specified at initialization,
          the default configuration ID is used.
        - This may not be the same as the active configuration ID.
        - Returns:
            - The current default configuration ID or zero if the default configuration has not been set.

1. **registerConfig**

    - Registers a configuration definition in the repository.
        - Registered configurations do not become immediately active nor do they become the default.
        - Registered configurations cannot be unregistered.

1. **replaceDefaultConfigId**

    - Replaces the existing default configuration ID with a new configuration ID.
        - The change is prevented if the current default configuration ID value is not as expected.
        - Use this in place of setDefaultConfigID to handle race conditions.

1. **setDefaultConfig**

    - Registers a configuration in the repository and then sets its ID as the default for the repository.
        - Convenience method for `registerConfig` followed by `setDefaultConfigId`.

1. **setDefaultConfigId**

    - Sets the default configuration ID.
        - Usually this method is sufficient for setting the default configuration ID.
          However in concurrent environments that could encounter race conditions,
          consider using replaceDefaultConfigId instead.

## SzDiagnostic

1. **checkRepositoryPerformance**

    - Conducts a rudimentary repository test to gauge I/O and network performance.
        - Typically, this is only run when troubleshooting performance.
        - This is a non-destructive test.

1. **getFeature**

    - Experimental/internal for Senzing support use.

1. **getRepositoryInfo**

    - Returns overview information about the repository.

1. **purgeRepository**

    - Permanently deletes all data in the repository, except the configuration.
        - WARNING: This method is destructive, it will delete all loaded records and entity resolution decisions.
        - Senzing does not provide a means to restore the data.
        - The only means of recovery would be restoring from a database backup.

1. **reinitialize**

    - Hidden

## SzEngine

1. **addRecord**

    - Loads a record into the repository and performs entity resolution.
        - If a record already exists with the same data source code and record ID, it will be replaced.
        - If the record definition contains DATA_SOURCE and RECORD_ID JSON keys,
          the values must match the dataSourceCode and recordID parameters.
        - The data source code must be registered in the active configuration.

1. **closeExportReport**

    - Closes an export report.
        - Used in conjunction with ExportJsonEntityReport, ExportCsvEntityReport, and FetchNext.

1. **countRedoRecords**

    - Gets the number of redo records pending processing.

1. **deleteRecord**

    - Deletes a record from the repository and performs entity resolution.
        - The data source code must be registered in the active configuration.
        - Is idempotent.

1. **exportCsvEntityReport**

    - Initiates an export report of entity data in CSV format.
        - Used in conjunction with fetchNext and closeEntityReport.
        - The first fetchNext call, after calling this method, returns the CSV header.
        - Subsequent fetchNext calls return exported entity data in CSV format.
        - Use with large repositories is not advised.

1. **exportJsonEntityReport**

    - Initiates an export report of entity data in JSON Lines format.
        - Used in conjunction with fetchNext and closeEntityReport.
        - Each fetchNext call returns exported entity data as a JSON object.
        - Use with large repositories is not advised.

1. **fetchNext**

    - Fetches the next line of entity data from an open export report.
        - Used in conjunction with ExportJsonEntityReport, ExportCsvEntityReport, and closeEntityReport.
        - If the export handle was obtained from ExportCsvEntityReport,
          this returns the CSV header on the first call
          and exported entity data in CSV format on subsequent calls.
        - If the export handle was obtained from ExportJsonEntityReport,
          this returns exported entity data as a JSON object.
        - When "null" is returned, the export report is complete and the caller should
          invoke closeExportReport to free resources.

1. **findInterestingEntitiesByEntityId**

    - Experimental method.
        - Contact Senzing support.

1. **findInterestingEntitiesByRecordId**

    - Experimental method.
        - Contact Senzing support.

1. **findNetworkByEntityId**

    - Retrieves a network of relationships among entities, specified by entity IDs.
        - Warning: Entity networks may be very large due to
          the volume of inter-related data in the repository.
          The parameters of this method can be used to limit the information returned.

1. **findNetworkByRecordId**

    - Retrieves a network of relationships among entities, specified by record IDs.
        - Warning: Entity networks may be very large due to
          the volume of inter-related data in the repository.
          The parameters of this method can be used to limit the information returned.

1. **findPathByEntityId**

    - Searches for the shortest relationship path between two entities, specified by entity IDs.
        - The returned path is the shortest path among the paths that satisfy the parameters.

1. **findPathByRecordId**

    - Searches for the shortest relationship path between two entities, specified by record IDs.
        - The returned path is the shortest path among the paths that satisfy the parameters.

1. **getActiveConfigId**

    - Gets the currently active configuration ID.
        - May not be the default configuration ID.

1. **getEntityByEntityId**

    - Retrieves information about an entity, specified by entity ID.

1. **getEntityByRecordId**

    - Retrieves information about an entity, specified by record ID.

1. **getRecord**

    - Retrieves information about a record.
        - The information contains the original record data that was loaded
          and may contain other information depending on the flags parameter.

1. **getRecordPreview**

    - Describes the features resulting from the hypothetical load of a record.
        - Used to preview the features for a record that has not been loaded.

1. **getRedoRecord**

    - Retrieves and removes a pending redo record.
        - An empty value will be returned if there are no pending redo records.
        - Use processRedoRecord() to process the result of this function.
        - Once a redo record is retrieved, it is no longer tracked by Senzing.
        - The redo record may be stored externally for later processing.
        - See also countRedoRecords(), processRedoRecord().

1. **getStats**

    - Gets and resets the internal engine workload statistics for the current operating system process.
        - The output is helpful when interacting with Senzing support.
        - Best practice to periodically log the results.

1. **getVirtualEntityByRecordId**

    - Describes how an entity would look if composed of a given set of records.
        - Virtual entities do not have relationships.

1. **howEntityByEntityId**

    - Explains how an entity was constructed from its records.

1. **primeEngine**

    - Pre-loads engine resources.
        - Explicitly calling this method ensures the performance cost is incurred at a predictable time
          rather than unexpectedly with the first call requiring the resources.

1. **processRedoRecord**

    - Processes the provided redo record.
        - This operation performs entity resolution.
        - Calling processRedoRecord() has the potential to create more redo records in certain situations.
        - See also getRedoRecord(), countRedoRecords().

1. **reevaluateEntity**

    - Reevaluates an entity by entity ID.
        - This operation performs entity resolution.
        - If the entity is not found, then no changes are made.

1. **reevaluateRecord**

    - Reevaluates an entity by record ID.
        - This operation performs entity resolution.
        - If the record is not found, then no changes are made.

1. **searchByAttributes**

    - Searches for entities that match or relate to the provided attributes.
        - The default search profile is SEARCH.  Alternatively, INGEST may be used.

1. **whyEntities**

    - Describes the ways two entities relate to each other.

1. **whyRecordInEntity**

    - Describes the ways a record relates to the rest of its respective entity.

1. **whyRecords**

    - Describes the ways two records relate to each other.

1. **whySearch**

    - Describes the ways a set of search attributes relate to an entity.
        - The default search profile is SEARCH.  Alternatively, INGEST may be used.

## SzProduct

1. **getLicense**

    - Gets the details and entitlements of the applied product license.
        - The details do not include the licence key.

1. **getVersion**

    - Gets the product version details.

[sdk-documentation]: README.md
