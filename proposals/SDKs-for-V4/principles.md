# Principles

1. Faithful representation of the underlying Senzing API in the style of the target SDK language
1. Consistent, Coherent, and Complete functions/methods
1. SDK APIs are specified by Interface or Abstract class
1. Industry-standard techniques:
    1. [Robustness principle](https://en.wikipedia.org/wiki/Robustness_principle)
    1. Function/method parameters are not mutated.
    1. Function/method return values have a constant datatype
1. Testing
    1. All Method/Functions have Unit Tests run by GitHub Actions for every Push
1. Documentation is in the style of the language.
    1. Java
    1. [Go](https://pkg.go.dev/github.com/senzing/g2-sdk-go)
    1. [Python](https://senzing-garage.github.io/g2-sdk-python-next/)
1. Examples

## Under consideration

1. Guided by Functional programming
1. Dependency injection
    1. Only used in constructor
    1. No setter methods for Dependency Injection
    1. This is mostly for the Senzing engine configuration or gRPC connection
