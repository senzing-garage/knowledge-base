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

1. **addDataSource**

    - Adds a new data source to this instance.

1. **deleteDataSource**

    - Deletes a data source from this instance.
        - Is idempotent

1. **export**

    - Retrieves the configuration definition for this instance.

1. **getDataSources**

    - Gets the data sources for this instance.

## SzConfigManager

1. **createConfigFromConfigID**

    - Creates a new SzConfig instance for a configuration ID.

1. **createConfigFromString**

    - Creates a new SzConfig instance from a configuration definition.

1. **createConfigFromTemplate**

    - Creates a new SzConfig instance from the template configuration definition.

1. **getConfigRegistry**

    - Gets the configuration registry.

1. **getDefaultConfigId**

    - Gets the default configuration for the repository.

1. **registerConfig**

    - Registers a configuration definition with the repository.

1. **replaceDefaultConfigId**

    - Replaces the existing default configuration ID with a new configuration ID.
        - Acts like "Compare and swap"

1. **setDefaultConfig**

    - Registers a configuration with the repository and sets its ID as the default for the repository.
        - Convenience method for `registerConfig` and `setDefaultConfigId`.

1. **setDefaultConfigId**

    - Sets the default configuration ID.

## SzDiagnostic

1. **checkDatastorePerformance**

    - Conducts a rudimentary datastore test to gauge I/O performance.

1. **getDatastoreInfo**

    - Returns overview information about the datastore.

1. **getFeature**

    - Experimental/internal for Senzing support use only.

1. **purgeRepository**

    - Purges all entity data in the entire repository.
        - Very dangerous method

1. **reinitialize**

    - Hidden

## SzEngine

1. **addRecord**

    - Loads a record into the repository.
        - Entity resolution occurs during the load.
        - Options for how much information is returns.

1. **closeExport**

    - Closes an export handle of a previous export operation.
        - From any previous export operation

1. **countRedoRecords**

    - Gets the number of redo records pending processing.

1. **deleteRecord**

    - Deletes a record from the repository.
        - Entity resolution occurs during the load.
        - Is idempotent

1. **exportCsvEntityReport**

    - Initiates an export of entity data in CSV format.

1. **exportJsonEntityReport**

    - Initiates an export of entity data in JSON format.

1. **fetchNext**

    - Fetches the next line of entity data from an open export operation.

1. **findInterestingEntitiesByEntityId**

    - Experimental method.
        - Contact Senzing support

1. **findInterestingEntitiesByRecordId**

    - Experimental method.
        - Contact Senzing support

1. **findNetworkByEntityId**

    - Discovers a network of entity relationships among entities based on entity IDs.

1. **findNetworkByRecordId**

    - Discovers a network of entity relationships among entities based on record IDs.

1. **findPathByEntityId**

    - Searches for an entity relationship path between two entities based on entity IDs.

1. **findPathByRecordId**

    - Searches for an entity relationship path between two entities based on record IDs.

1. **getActiveConfigId**

    - Gets the currently active configuration ID.

1. **getEntityByEntityId**

    - Retrieves information about an entity based on entity ID.

1. **getEntityByRecordId**

    - Retrieves information about an entity based on record ID.

1. **getRecord**

    - Gets the record definition for a record.
        - This is the same information submitted in `addRecord`

1. **getRedoRecord**

    - Retrieves a pending redo record from the reevaluation queue.
        - Once retrieved, it must be processed via processRedoRecord.
        - If reevauation queue is empty, empty is returne.

1. **getStats**

    - Gets the internal engine workload statistics for the current process.
        - Statistics are affected by record insert, update, delete, and re-evaluate. (to be fleshed out)
        - Used when working with Senzing support

1. **getVirtualEntityByRecordId**

    - Describes what an entity would look like for a given set of records.

1. **howEntityByEntityId**

    - Describes how an entity was constructed from its constituent records.

1. **preprocessRecord**

    - Describes the features resulting from the hypothetical load of a record.
        - Does not modify data in the Senzing datastore.

1. **primeEngine**

    - Pre-loads engine resources to reduce latency of initial entity resolution processing.
        - If not used, the load will occur on first access.

1. **processRedoRecord**

    - Loads a record into the  repository.
        - Entity resolution occurs during the load.

1. **reevaluateEntity**

    - Loads a record into the  repository.
        - Entity resolution occurs during the load.

1. **reevaluateRecord**

    - Loads a record into the  repository.
        - Entity resolution occurs during the load.

1. **searchByAttributes**

    - Searches for entities that match or relate to the provided attributes.

1. **whyEntities**

    - Describes the ways two entities relate to each other.

1. **whyRecordInEntity**

    - Describes why a record is in its respective entity.

1. **whyRecords**

    - Describes the ways two records relate to each other.

1. **whySearch**

    - Describes why an entity did not match or relate to a set of search attributes.

## SzProduct

1. **getLicense**

    - Gets the product license details.

1. **getVersion**

    - Gets the product version details.

[sdk-documentation]: README.md
