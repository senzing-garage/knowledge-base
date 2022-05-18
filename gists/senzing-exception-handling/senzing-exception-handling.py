#! /usr/bin/env python3

from senzing import G2ModuleInvalidXML

# -----------------------------------------------------------------------------
# Example functions.
# -----------------------------------------------------------------------------


def function1(*args, **kwargs):

    raise G2ModuleInvalidXML("An exception happened")

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------


if __name__ == "__main__":

    print("Print 'err' object which is nested.")

    try:
        function1()
    except Exception as err:
        print(err)

    print("\n\nPrint 'err' message from final nesting.")

    try:
        function1()
    except Exception as err:
        print(err.args[-1])
