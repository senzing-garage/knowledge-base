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
the question in the Python programmer's mind is:

> When I catch the Exception, do I log the exception and:
>   1) Exit my program
>   2) Try to correct the situation within the program
>   3) Continue

The proposed approach:

1. Simplifies the decision making process when writing Python code.
1. Encapsulates the severity in the underlying Senzing Python SDK.
1. Reduces the need for "if-elseif-elseif-else" logic in the exception handling.
1. Doesn't introduce new attributes on Exceptions.
1. Doesn't break the existing application code written using Senzing V2.

### Contents

1. [Proposed approach](#proposed-approach)
1. [Usage](#usage)
1. [Implementation](#implementation)

## Proposed approach

The emphasis on the proposed design it to help the Python programmer catch exceptions and know whether to:

1. Log a message and exit
2. Diagnose the cause of the exception and perhaps correct
3. Simply log the message and continue

The approach creates 4 new exception classes:

1. **G2ExceptionCritical**
1. **G2ExceptionError**
1. **G2ExceptionWarning**
1. **G2ExceptionInfo**

Specific Exceptions are mapped into a hierarchy.
Examples:

1. **G2Exception** > **G2ExceptionCritical** > **G2DBExceptionCritical**
1. **G2Exception** > **G2ExceptionWarning** > **G2DBExceptionWarning**
1. **G2Exception** > **G2ExceptionInfo** > **G2ModuleResolveMissingResEnt**

The approach facilitates "future-proofing" applications using the Senzing Python API.

1. New "specific" Exceptions can be added to the Senzing Python API without the applications
   have having to change.  Especially true for new "critical" exceptions.
1. No new Exception attributes are created.  Thus simplifying Exception chaining and logging.

## Usage

1. [Before](https://github.com/Senzing/redoer/blob/c3d3aeaf281d091d2ca370da1c5c56f54d736a66/redoer.py#L2061-L2083)

1. After (simplified)
   Example:

    ```python
    try:
        self.g2_engine.process(redo_record)

    except G2Exception.G2ExceptionCritical as err:
        logging.exception(message_critical(850, threading.current_thread().name, err, redo_record))
        sys.exit(1)

    except G2Exception.G2ExceptionError as err:
        if self.is_g2_default_configuration_changed():
            self.update_active_g2_configuration()
            self.g2_engine.process(redo_record)
        else:
            logging.error(message_error(750, threading.current_thread().name, err))

    except G2Exception.G2ExceptionWarning as err:
        logging.warning(message_warning(350, threading.current_thread().name, err, redo_record))

    except G2Exception.G2ExceptionInfo as err:
        logging.info(message_info(250, threading.current_thread().name, err, redo_record))

    except Exception as err:
        logging.exception(message_critical(950, threading.current_thread().name, err, redo_record))
        sys.exit(1)
    ```

1. The structure follows the [Python logging levels](https://docs.python.org/3/library/logging.html#logging-levels):
    1. critical
    1. error
    1. warning
    1. info
    1. debug
    1. notset
1. The structure uses [logging.exception()](https://docs.python.org/3/library/logging.html#logging.Logger.exception)
   as it provides additional logging information.

1. Semantics for exceptions:
    1. **G2ExceptionCritical** -
       Processing **did not** occur.
       There are no programmatic remedies.
       Therefore, exit the program.
    1. **G2ExceptionError** -
       Processing **did not** occur.
       There may be programmatic remedies before the operation can be tried again.
    1. **G2ExceptionWarning** -
       Processing **did not** occur.
       There is no need to halt operation.
    1. **G2ExceptionInfo** -
       Processing **did** occur.
       There is a message that needs to be conveyed to the user.
       There is no need to halt operation.
    1. **Exception** -
       Processing unknown.
       Catches any unanticipated errors and halts the program.
    1. Synopsis:

        | Log Level            | Completed | Remedies | Halt |
        |----------------------|-----------|----------|------|
        | G2ExceptionCritical  | No        | No       | Yes  |
        | G2ExceptionError     | No        | Yes      | No   |
        | G2ExceptionWarning   | No        | No       | No   |
        | G2ExceptionInfo      | Yes       | No       | No   |
        | Exception            | ??        | ??       | Yes  |

1. Message numbers have
   [ranges](https://github.com/Senzing/stream-loader/blob/30c9fe591137793c063152cee04c0478523d7357/stream-loader.py#L892-L908).

    - 1xx Informational (i.e. logging.info())
    - 3xx Warning (i.e. logging.warning())
    - 5xx User configuration issues (either logging.warning() or logging.err() for Client errors)
    - 7xx Internal error (i.e. logging.error for Server errors)
    - 9xx Debugging (i.e. logging.debug())# 1xx Informational (i.e. logging.info())

   Log message identifiers have the format `senzing-ppppnnnnt`, where:

    - "p" is the 4 digit [product identifier](https://github.com/Senzing/knowledge-base/blob/master/lists/senzing-product-ids.md)
    - "n" is the 4 digit message identifier within product
    - "t" is the 1 character message type: Info, Warn, Error

   This is formatted to aid in internet searches.
   Example, search for [senzing-50010406E](https://www.google.com/search?channel=fs&client=ubuntu&q=senzing-50070896E).

## Implementation

1. See [exceptions.py](python-exceptions/exceptions.py)
1. [Try it](https://code.labstack.com/gFysm75U)
