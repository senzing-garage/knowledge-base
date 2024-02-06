# Principles

1. Faithful representation of the underlying Senzing API in the style of the target SDK language.
   1. All behaviors of the C API should be available at the SDK level.
1. Consistent, Coherent, and Complete functions/methods.
    1. [Canonical names](canonical-names.md)
1. SDK APIs are specified by Interface or Abstract class.
    1. Customers should write to an interface, not an implementation.
1. Consistent JSON-based error messages
    1. JSON helps customers with parsing and logging system
1. Industry-standard techniques:
    1. [Robustness principle](https://en.wikipedia.org/wiki/Robustness_principle)
    1. Function/method parameters are not mutated.
    1. Function/method return values have a constant datatype (in addition to `None`, `null`, `nil`)
1. Testing
    1. All Method/Functions have Unit Tests run by GitHub Actions for every Push
    1. Code coverage analysis is done.
1. Documentation is in the style of the language.
    1. Java
    1. [Go](https://pkg.go.dev/github.com/senzing/g2-sdk-go)
    1. [Python](https://senzing-garage.github.io/g2-sdk-python-next/)
1. Examples
    1. These examples are a "Reference", not a "Guide".
        1. Think "dictionary", not "encyclopedia".
        1. They are not use-cases, but merely shows how function/method is called.
    1. Best case is to have the examples embedded in the documentation.
1. Common `Makefile` targets:
    1. **General:** help, clean
    1. **Development Cycle:** build, setup, test, run
    1. **Docker:** (Optional) docker-build, docker-run

## Under consideration

1. SDK design is guided by Functional programming
1. Dependency injection
    1. Only used in constructor
    1. No setter methods for Dependency Injection
    1. This is mostly for the Senzing engine configuration or gRPC connection
1. Tracing
1. Auditing
