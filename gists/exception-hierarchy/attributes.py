#! /usr/bin/env python3

class APIException(Exception):
    status_code = 500
    detail = ''

    def __init__(self, detail=None):
        if detail is not None:
            self.detail = detail

    def __str__(self):
        return self.detail


class ParseError(APIException):
    status_code = 400
    detail = 'Malformed request.'


class AuthenticationFailed(APIException):
    status_code = 401
    detail = 'Incorrect authentication credentials.'


class NotAuthenticated(APIException):
    status_code = 401
    detail = 'Authentication credentials were not provided.'


class PermissionDenied(APIException):
    status_code = 403
    detail = 'You do not have permission to perform this action.'


class NotFound(APIException):
    status_code = 404
    detail = 'This resource does not exist.'

# class MethodNotAllowed(APIException):
#     status_code = status.HTTP_405_METHOD_NOT_ALLOWED
#     detail = 'Request method "%s" not allowed.'

#     def __init__(self, method, detail=None):
#         self.detail = (detail or self.detail) % method


class NotAcceptable(APIException):
    status_code = 406
    detail = 'Could not satisfy the request Accept header.'


class UnsupportedMediaType(APIException):
    status_code = 415
    detail = 'Unsupported media type in the request Content-Type header.'


class Throttled(APIException):
    status_code = 429
    detail = 'Request was throttled.'

#     def __init__(self, wait=None, detail=None):
#         if wait is None:
#             self.detail = detail or self.detail
#             self.wait = None
#         else:
#             format = (detail or self.detail) + ' ' + self.extra_detail
#             self.detail = format % (wait, wait != 1 and 's' or '')
#             self.wait = math.ceil(wait)

# -----------------------------------------------------------------------------
# Utility functions
# -----------------------------------------------------------------------------


def blow_up():
    raise NotAcceptable("blowing up")

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------


if __name__ == "__main__":

    try:
        print("testing...")
        blow_up()
    except APIException as err:
        print(err)
        print(err.status_code)
