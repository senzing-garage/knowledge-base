#! /usr/bin/env python3

import random
import logging
import sys

# -----------------------------------------------------------------------------
# Base G2Exception
# -----------------------------------------------------------------------------


class G2Exception(Exception):
    '''Base exception for G2 related python code'''

    def __init__(self, *args, **kwargs):
        Exception.__init__(self, *args, **kwargs)

# -----------------------------------------------------------------------------
# Exception categories.
# -----------------------------------------------------------------------------


class G2ExceptionCritical(G2Exception):

    def __init__(self, *args, **kwargs):
        G2Exception.__init__(self, *args, **kwargs)


class G2ExceptionError(G2Exception):

    def __init__(self, *args, **kwargs):
        G2Exception.__init__(self, *args, **kwargs)


class G2ExceptionWarning(G2Exception):

    def __init__(self, *args, **kwargs):
        G2Exception.__init__(self, *args, **kwargs)


class G2ExceptionInfo(G2Exception):

    def __init__(self, *args, **kwargs):
        G2Exception.__init__(self, *args, **kwargs)

# -----------------------------------------------------------------------------
# Example Critical exceptions
# -----------------------------------------------------------------------------


class G2DBExceptionCritical(G2ExceptionCritical):
    '''Base exception for G2 DB related python code'''

    def __init__(self, *args, **kwargs):
        G2ExceptionCritical.__init__(self, *args, **kwargs)


class G2UnsupportedDatabaseType(G2ExceptionCritical):

    def __init__(self, *args, **kwargs):
        G2ExceptionCritical.__init__(self, *args, **kwargs)


class G2TableNoExist(G2ExceptionCritical):

    def __init__(self, *args, **kwargs):
        G2ExceptionCritical.__init__(self, *args, **kwargs)


class G2DBMNotStarted(G2ExceptionCritical):

    def __init__(self, *args, **kwargs):
        G2ExceptionCritical.__init__(self, *args, **kwargs)


class G2DBNotFound(G2ExceptionCritical):

    def __init__(self, *args, **kwargs):
        G2ExceptionCritical.__init__(self, *args, **kwargs)


class G2DBUnknownException(G2ExceptionCritical):

    def __init__(self, *args, **kwargs):
        G2ExceptionCritical.__init__(self, *args, **kwargs)


class G2ModuleMySQLNoSchema(G2ExceptionCritical):

    def __init__(self, *args, **kwargs):
        G2ExceptionCritical.__init__(self, *args, **kwargs)

# -----------------------------------------------------------------------------
# Example Error exceptions
# -----------------------------------------------------------------------------


class G2DBExceptionError(G2ExceptionError):
    '''Base exception for G2 DB related python code'''

    def __init__(self, *args, **kwargs):
        G2ExceptionError.__init__(self, *args, **kwargs)


class G2ModuleInvalidXML(G2ExceptionError):

    def __init__(self, *args, **kwargs):
        G2ExceptionError.__init__(self, *args, **kwargs)

# -----------------------------------------------------------------------------
# Example Warning exceptions
# -----------------------------------------------------------------------------


class G2DBExceptionWarning(G2ExceptionWarning):
    '''Base exception for G2 DB related python code'''

    def __init__(self, *args, **kwargs):
        G2ExceptionWarning.__init__(self, *args, **kwargs)


class G2DBUniqueConstraintViolation(G2ExceptionWarning):

    def __init__(self, *args, **kwargs):
        G2ExceptionWarning.__init__(self, *args, **kwargs)


class G2ModuleEmptyMessage(G2ExceptionWarning):

    def __init__(self, *args, **kwargs):
        G2ExceptionWarning.__init__(self, *args, **kwargs)

# -----------------------------------------------------------------------------
# Example Info exceptions
# -----------------------------------------------------------------------------


class G2DBExceptionWarning(G2ExceptionInfo):
    '''Base exception for G2 DB related python code'''

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)


class G2ModuleResolveMissingResEnt(G2ExceptionInfo):

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)


class G2UnsupportedFileTypeException(G2ExceptionInfo):

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)


class G2InvalidFileTypeContentsException(G2ExceptionInfo):

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)


class UnconfiguredDataSourceException(G2ExceptionInfo):

    def __init__(self, DataSourceName):
        G2ExceptionInfo.__init__(self, ("Datasource %s not configured. See https://senzing.zendesk.com/hc/en-us/articles/360010784333 on how to configure datasources in the config file." % DataSourceName))


class G2ModuleException(G2ExceptionInfo):
    '''Base exception for G2 Module related python code'''

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)


class G2ModuleNotInitialized(G2ExceptionInfo):
    '''G2 Module called but has not been initialized '''

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)


class G2ModuleGenericException(G2ExceptionInfo):
    '''Generic exception for non-subclassed G2 Module exception '''

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)


class G2ModuleLicenseException(G2ExceptionInfo):

    def __init__(self, *args, **kwargs):
        G2ExceptionInfo.__init__(self, *args, **kwargs)

# -----------------------------------------------------------------------------
# Determine database type
# -----------------------------------------------------------------------------


exceptions_map = {
    "7213E": G2ModuleMySQLNoSchema,
    "0002E": G2ModuleInvalidXML,
    "0007E": G2ModuleEmptyMessage,
    "2134E": G2ModuleResolveMissingResEnt,
    "9000E": G2ModuleLicenseException,
    "X001E": G2DBExceptionCritical,
    "X002E": G2DBExceptionError,
    "X003E": G2DBExceptionWarning,
    "X004E": G2DBExceptionWarning,
    "X005E": G2DBMNotStarted,
    "X006E": G2DBNotFound,
    "X007E": G2DBUniqueConstraintViolation,
    "X008E": G2DBUnknownException,
    "X009E": G2InvalidFileTypeContentsException,
    "X010E": G2ModuleException,
    "X011E": G2ModuleGenericException,
    "X012E": G2ModuleNotInitialized,
    "X013E": G2TableNoExist,
    "X014E": G2UnsupportedDatabaseType,
    "X015E": G2UnsupportedFileTypeException,
    "X016E": UnconfiguredDataSourceException,
}


def translate_g2_module_exception(exception_message):
    senzing_error_code = exception_message.split('|', 1)[0].strip()
    senzing_error_class = exceptions_map.get(senzing_error_code, G2ModuleGenericException)
    return senzing_error_class(exception_message)

# -----------------------------------------------------------------------------
# Simulation code
# -----------------------------------------------------------------------------


def get_tls_var_buf_value():
    random_key = random.choice(list(exceptions_map))
    return f"{random_key} | Some senzing explanation"


def example_senzing_call():
    simulated_senzing_message = get_tls_var_buf_value()
    raise translate_g2_module_exception(simulated_senzing_message)

# -----------------------------------------------------------------------------
# Main (Just for testing)
# -----------------------------------------------------------------------------


if __name__ == "__main__":

    logging.basicConfig(format='%(asctime)s %(message)s', level=logging.INFO)

    # Example call to Senzing and exception catching.

    try:
        example_senzing_call()

    except G2ExceptionCritical as err:
        logging.critical("CRITICAL: {0}".format(err))
        sys.exit(1)

    except G2ExceptionError as err:
        if False:
            fix_something()
        else:
            logging.error("ERROR: {0}".format(err))

    except G2ExceptionWarning as err:
        logging.warning("WARNING: {0}".format(err))

    except G2ExceptionInfo as err:
        logging.info("INFO: {0}".format(err))

    except Exception as err:
        logging.exception("Generic exception: {0}".format(err))
        sys.exit(1)

    # Simulate normal execution.

    print("Exit normally.")
