#! /usr/bin/env python3


class G2Exception(Exception):
    '''Base exception for G2 related python code'''

    def __init__(self, *args, **kwargs):
        super().__init__(self, *args, **kwargs)
        print("here - 0 ")

    def __str__(self):
        result = []
        for arg in self.args:
            message = arg
            if isinstance(arg, Exception):
                message = "{0}:".format(arg.__class__.__name__)
            if message not in result:
                result.append(message)
        return " ".join(result)


class G2L1Exception(G2Exception):
    '''DocString'''
    print("here - 1")


class G2L2Exception(G2L1Exception):
    '''DocString'''
    print("here - 2a")

    def __init__(self, *args, **kwargs):
        super().__init__(self, *args, **kwargs)
        print("here - 2b")


class G2L1xException(G2Exception):
    '''DocString'''
    print("here - this shouldn't print")


class G2L3Exception(G2L2Exception):
    '''DocString'''
    print("here - 3")

# -----------------------------------------------------------------------------
# Utility functions
# -----------------------------------------------------------------------------


def blow_up():
    raise G2L3Exception("blowing up")

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------


if __name__ == "__main__":

    try:
        print("testing...")
        blow_up()
    except G2Exception as err:
        print(err)
