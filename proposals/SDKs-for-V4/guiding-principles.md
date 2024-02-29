# Guiding Principles

1. Faithful representation of the underlying Senzing API in the style of the target SDK language.
    1. All behaviors of the C API should be available at the SDK level.
        1. Any exceptions should be documented for review.
    1. However, the function/method signatures may not match exactly.
1. Consistent, Coherent, and Complete functions/methods.
    1. All SDKs (Java, Python, Go) implement the [core methods](canonical-names-condensed.md)
    1. Use the "to principle" for function/method names.
1. SDK APIs are specified by Interface (or Abstract) class.
    1. This allows customers to write to an interface, not an implementation.
    1. This allows us to create specific implementations, if/when needed.
1. "Convenience Methods" may be unique per SDK language.
    1. Convenience methods are written at the "abstract level" so they can be inherited by all concrete classes.
    1. In general, convenience methods call [core methods](canonical-names-condensed.md)
       (i.e. it must not independently call the Senzing C API).
1. Consistent JSON-based error messages
    1. JSON helps customers with parsing and logging system.
    1. See [Error Messages](error-messages.md)
1. Industry-standard techniques:
    1. [Robustness principle](https://en.wikipedia.org/wiki/Robustness_principle)
    1. Function/method parameters are not mutated.
    1. Function/method return values have a constant data-type
    1. For simplicity,
       [core method](canonical-names-condensed.md)
       parameters must support the following data-types:
        1. `string`, `int`, `int64`, or `<handle>`
        1. `<handle>` will differ in each language
        1. `flags` are `int64` in [core methods](canonical-names-condensed.md), but can be different in "convenience methods".
    1. For simplicity,
       [core methods](canonical-names-condensed.md)
       return the following data-types:
        1. `string`, `int`, `int64`, or `handle`
        1. Also `None`, `null`, `nil`, depending on SDK language
1. Testing
    1. All function/methods have Unit Tests run by GitHub Actions for every Push
    1. Code coverage analysis is done.
    1. Static analysis for complexity and type-checking (in some languages)
1. Documentation is in the style of the language.
    1. [Java](https://www.oracle.com/technical-resources/articles/java/javadoc-tool.html)
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

## Convenience methods

"Convenience Methods" are method signatures that make it "convenient" for the customer to call the Senzing functionality.
Often they allow different variations of input parameters or return different data types than the
[core methods](canonical-names-condensed.md).
The implementation of each "convenience method" will normalize input parameters and call a
[core method](canonical-names-condensed.md).
The return from the
[core method](canonical-names-condensed.md) may be altered before returning to the caller.

Each language may have different convenience methods for their specific customer.

1. Use the following forms:
    1. `addXxxReturnYyy()`
    1. `checkDatabasePerformanceReturnYyy()`
    1. `deleteXxxReturnYyy()`
    1. `findXxxReturnYyy()`
    1. `getXxxAsYyy()`
    1. `howXxxAsYyy()`
    1. `reevaluateEntityReturnYyy()`
    1. `reevaluateRecordReturnYyy()`
    1. `replaceRecordReturnYyy()`
    1. `saveReturnYyy()`
    1. `searchByAttributesReturnYyy()`
    1. `whyXxxAsYyy()`

1. **Net:** Use `...ReturnYyy()` for everthing except `getXxx()`, `howXxx()` and `whyXxx()`

## Under consideration

1. SDK design is guided by Functional programming
1. Dependency injection
    1. Only used in constructor
    1. No setter methods for Dependency Injection
    1. This is mostly for the Senzing engine configuration or gRPC connection
1. Tracing
1. Auditing
