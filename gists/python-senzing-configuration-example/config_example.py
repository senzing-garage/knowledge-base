#! /usr/bin/env python3

from typing import Any, Dict, Optional, Union


# Mock-up of SzXxxx.initialize() function.
def initialize(
    instance_name: str,
    settings: Union[str, Dict[Any, Any]],
    config_id: Optional[int] = 0,
    verbose_logging: Optional[int] = 0,
    **kwargs: Any,
) -> None:
    print(f"  instance_name: {instance_name}")
    print(f"       settings: {settings}")
    print(f"      config_id: {config_id}")
    print(f"verbose_logging: {verbose_logging}")


# Senzing configuration "object".
SENZING_CONFIG = {
    "instance_name": "example-instance",
    "settings": {
        "PIPELINE": {
            "CONFIGPATH": "/etc/opt/senzing",
            "RESOURCEPATH": "/opt/senzing/g2/resources",
            "SUPPORTPATH": "/opt/senzing/data",
        },
        "SQL": {"CONNECTION": "sqlite3://na:na@/tmp/sqlite/G2C.db"},
    },
    "config_id": 0,
    "verbose_logging": 0,
}

# Example call to SzXxxx.initialize()
initialize(**SENZING_CONFIG)
