#!/usr/bin/env python3

import json

from senzing_core import SzAbstractFactory, SzAbstractFactoryParameters

FACTORY_PARAMETERS: SzAbstractFactoryParameters = {
    "instance_name": "Example",
    "settings": {
        "PIPELINE": {
            "CONFIGPATH": "/etc/opt/senzing",
            "RESOURCEPATH": "/opt/senzing/er/resources",
            "SUPPORTPATH": "/opt/senzing/data",
        },
        "SQL": {"CONNECTION": "sqlite3://na:na@/tmp/sqlite/G2C.db"},
    },
}

sz_abstract_factory = SzAbstractFactory(**FACTORY_PARAMETERS)
sz_product = sz_abstract_factory.create_product()
print(json.dumps(json.loads(sz_product.get_version()), indent=2))
