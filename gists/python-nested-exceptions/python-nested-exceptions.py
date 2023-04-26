#! /usr/bin/env python3

import json


# -----------------------------------------------------------------------------
# Example Exceptions.
# -----------------------------------------------------------------------------

class ExampleException(Exception):
    '''Base exception for examples'''

    def __init__(self, *args, **kwargs):
        super().__init__(self, *args, **kwargs)

class SpecificException1(ExampleException):
    '''Base exception for examples'''

    def __init__(self, *args, **kwargs):
        super().__init__(self, *args, **kwargs)

class SpecificException2(ExampleException):
    '''Base exception for examples'''

    def __init__(self, *args, **kwargs):
        super().__init__(self, *args, **kwargs)

# -----------------------------------------------------------------------------
# Example functions.
# -----------------------------------------------------------------------------


def function1(*args, **kwargs):

    raise SpecificException1("Specific exception 1")

def function2(*args, **kwargs):

    raise SpecificException2("Specific exception 2")


def function3(*args, **kwargs):

    try:
        function1(args, kwargs)
    except SpecificException1 as err:
        print("function 3 error: {0}".format(err))
        try:
            function2(args, kwargs)
        except Exception as err:
            raise SpecificException2("secondary exception")
    except Exception as err:
        print("function 3 error 2: {0}".format(err))


def function4(*args, **kwargs):

    try:
        function3(args, kwargs)
    except Exception as err:
        print("function4 error: {0}".format(err))

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------


if __name__ == "__main__":

    function4()
