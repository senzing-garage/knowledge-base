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
        - Warning: if records in the repository refer to the unregistered datasource
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
      - The template configuration is located PIPELINE.RESOURCEPATH/templates/g2config.json.
        FIXME: Need to say what `PIPELINE.RESOURCEPATH` is.

1. **getConfigRegistry**

    - Gets the configuration registry.

1. **getDefaultConfigId**

    - Gets the default configuration ID for the repository.

1. **registerConfig**

    - Registers a configuration definition in the repository.

1. **replaceDefaultConfigId**

    - Replaces the existing default configuration ID with a new configuration ID.
        - Acts like "Compare and swap"

1. **setDefaultConfig**

    - Registers a configuration in the repository and sets its ID as the default for the repository.
        - Convenience method for `registerConfig` and `setDefaultConfigId`.

1. **setDefaultConfigId**

    - Sets the default configuration ID.

## SzDiagnostic

1. **checkRepositoryPerformance**

    - Conducts a rudimentary repository test to gauge I/O performance.

1. **getFeature**

    - Experimental/internal for Senzing support use only.

1. **getRepositoryInfo**

    - Returns overview information about the repository.

1. **purgeRepository**

    - Purges all data in the repository, except the configuration. (...ALL CAPS!)
        - Very dangerous method

1. **reinitialize**

    - Hidden

## SzEngine

1. **addRecord**

    - Loads a record into the repository and performs entity resolution.
        - Entity resolution occurs during the load.
        - Options for how much information is returns.

1. **closeExportReport**

    - Closes an export report.

1. **countRedoRecords**

    - Gets the number of redo records pending processing.

1. **deleteRecord**

    - Deletes a record from the repository and performs entity resolution.
        - Entity resolution occurs during the load.
        - Is idempotent

1. **exportCsvEntityReport**

    - Initiates an export report of entity data in CSV format.
        - This function does not scale. (reword)
        - Add link to article

1. **exportJsonEntityReport**

    - Initiates an export report of entity data in JSON Lines format.
        - This function does not scale.
        - Add link to article

1. **fetchNext**

    - Fetches the next line of entity data from an open export report.

1. **findInterestingEntitiesByEntityId**

    - Experimental method.
        - Contact Senzing support

1. **findInterestingEntitiesByRecordId**

    - Experimental method.
        - Contact Senzing support

1. **findNetworkByEntityId**

    - Retrieves a network of relationships among entities based on entity IDs.

1. **findNetworkByRecordId**

    - Retrieves a network of relationships among entities based on record IDs.

1. **findPathByEntityId**

    - Searches for the shortest relationship path between two entities based on entity IDs.
        - Based on parameters

1. **findPathByRecordId**

    - Searches for the shortest relationship path between two entities based on record IDs.
        - Based on parameters

1. **getActiveConfigId**

    - Gets the currently active configuration ID.

1. **getEntityByEntityId**

    - Retrieves information about an entity based on entity ID.

1. **getEntityByRecordId**

    - Retrieves information about an entity based on record ID.

1. **getRecord**

    - Retrieves information about a record.

1. **getRecordPreview**

    - Describes the features resulting from the hypothetical load of a record.
        - Don't run preprocessRecord before addRecord or deleteRecord.
        - Does not modify data in the Senzing datastore.
        - Does all processing except the entity relationship work.
        - FIXME:

1. **getRedoRecord**

    - Retrieves and removes a pending redo record.
        - Once retrieved, it must be processed via processRedoRecord.
        - An "empty" may be returned.

1. **getStats**

    - Gets and resets the internal engine workload statistics for the current operating system process.
        - Used when working with Senzing support
        - Best practice to periodically log the results.
        - (not per-thread, not per-function-call)

1. **getVirtualEntityByRecordId**

   - Describes how an entity would look if composed of a given set of records.
        - The entity will be without relationships.

1. **howEntityByEntityId**

    - Explains how an entity was constructed from its records.

1. **primeEngine**

    - Pre-loads engine resources.
        - Otherwise "lazy instantiation" will occur.
        - Giving unpredictable performance.
        - If not used, the load will occur on first access.

1. **processRedoRecord**

    - Processes the provided redo record.

1. **reevaluateEntity**

    - Reevaluates an entity by entity ID.
        - Entity resolution occurs.

1. **reevaluateRecord**

    - Reevaluates an entity by record ID.
        - Entity resolution occurs.
        - Causes the JSON to be reprocessed in the case of a configuration change

1. **searchByAttributes**

    - Searches for entities that match or relate to the provided attributes.

1. **whyEntities**

    - Describes the ways two entities relate to each other.

1. **whyRecordInEntity**

    - Describes the ways a record relates to the rest of its respective entity.

1. **whyRecords**

    - Describes the ways two records relate to each other.

1. **whySearch**

    - Describes the ways a set of search attributes relate to an entity.
        - Can be a positive or negative match

## SzProduct

1. **getLicense**

    - Gets the product license details.

1. **getVersion**

    - Gets the product version details.

[sdk-documentation]: README.md
