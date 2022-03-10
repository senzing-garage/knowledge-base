# Python simple examples

## Very few lines

```python
#! /usr/bin/env python3

import json

from G2Engine import G2Engine

# REPLACE /home/user/tryme with the path to your Senzing project
# created in the quickstart.
config = {
    "PIPELINE": {
        "CONFIGPATH": "/home/user/tryme/etc",
        "SUPPORTPATH": "/home/user/tryme/data",
        "RESOURCEPATH": "/user/user/tryme/resources"
    },
    "SQL": {
         "CONNECTION": "sqlite3://na:na@/home/user/tryme/var/sqlite/G2C.db"
     }
}

record = {
    "NAME_FULL": "JOHN SMITH",
    "ADDR_FULL": "123 Main St, Las Vegas NV"
}

query = {
    "NAME_FIRST": "JANE",
    "NAME_LAST": "SMITH",
    "ADDR_FULL": "123 Main St, Las Vegas NV"
}

try:

    # Initialize the G2Engine
    g2 = G2Engine()
    g2.initV2("DoIT", json.dumps(config), False)

    # Entity resolve a record
    g2.addRecord("TEST", "1", json.dumps(record))

    # Get the entity it resolved to
    response = bytearray()
    g2.getEntityByRecordID("TEST", "1", response)

    # Display entity JSON
    print(response.decode())

    # Search for entities
    g2.searchByAttributes(json.dumps(query), response)

    # Display result JSON
    print(response.decode())

except Exception as err:
    print(err)
```
