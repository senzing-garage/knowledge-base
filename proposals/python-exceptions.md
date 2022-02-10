# Python exceptions

## Synopsis

Improve the customer experience in Exception handling in the Senzing Python SDK.

## Overview

Currently a Python programmer using the
[Senzing Python SDK](https://github.com/Senzing/g2-sdk-python/tree/main/src/senzing)
has a plethora of
[Exceptions](https://github.com/Senzing/g2-sdk-python/blob/main/src/senzing/G2Exception.py)
that could be thrown by the underlying SDK.

When an Exception is thrown by the Senzing Python SDK,
the question is the Python programmer's mind is:

> When I catch the Exception, do I log the exception and:
>   1) Exit my program
>   2) Try to correct the situation within the program
>   3) Continue

The proposed approach:

1. Simplifies the decision making process when writing Python code.
1. Encapsulates the severity in the underlying Senzing Python SDK.
1. Reduces the need for "if-elseif-elseif-else" logic in the exception handling.

Because this is a "breaking change", the recommendation is to introduce the functionality into Senzing API 3.0.0.

### Contents

1. [Installation](#installation)
1. [Modification to client code](#modification-to-client-code)
    1. [Imports](#imports)
    1. [Object creation](#object-creation)
    1. [Import alternative](#import-alternative)
1. [Modification to Senzing SDK for Python](#modification-to-senzing-sdk-for-python)
    1. [Use relative path](#use-relative-path)
1. [Modification to RPM/DEB directory structure](#modification-to-rpm-deb-directory-structure)

### Proposed approach

The emphasis on the proposed design it to help the python programmer catch exceptions and know whether to:

1. Log a message and exit
2. Diagnose the cause of the exception and perhaps correct
3. Simply log the message and continue

### Implementation

1. [Before](https://github.com/Senzing/redoer/blob/c3d3aeaf281d091d2ca370da1c5c56f54d736a66/redoer.py#L2061-L2083)

1. After (simplified)
   Example:

    ```python
    try:
        self.g2_engine.process(redo_record)

    except G2Exception.G2ExceptionCritical as err:
        logging.exception(message_critical(901, threading.current_thread().name, err, redo_record))
        sys.exit(1)

    except G2Exception.G2ExceptionError as err:
        if self.is_g2_default_configuration_changed():
            self.update_active_g2_configuration()
            self.g2_engine.process(redo_record)
        else:
            logging.error(message_error(701, threading.current_thread().name, err))

    except G2Exception.G2ExceptionWarning as err:
        logging.warning(message_warning(501, threading.current_thread().name, err, redo_record))

    except Exception as err:
        logging.exception(message_critical(902, threading.current_thread().name, err, redo_record))
        sys.exit(1)
    ```

1. Python logging levels [list](https://docs.python.org/3/library/logging.html#logging.info).
