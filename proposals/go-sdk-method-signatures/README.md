# Go SDK method signatures

## Proposal 1

In this proposal, the use of Go "structs" is used to pass information
in and out of the method signataures.

### Current

The current design (and implementation) passes JSON strings to and from the Senzing G2 API
as is seen in
[senzing/g2-sdk-go-base](https://github.com/Senzing/g2-sdk-go-base).

When implementing applications base on the current design,
it was discovered that the Go code needed to create and parse JSON
that is passed into and out of the Senzing.
This task of marshaling and unmarshaling to JSON will be needed
for all Senzing APIs.

Since every program will need to parse and construct JSON,
it seems to make sense to have the Senzing SDK for Go do that work.
Then the calling program can simply set and retrieve variables from the
"structs" that are used for input and output.

### XXX

In [senzing/g2-sdk-go/senzing/main.go](https://github.com/Senzing/g2-sdk-go/tree/main/senzing/main.go),
Define "type - interface" for `config`, `configmgr`, `diagnostic`, `engine`, and `product`.
using

In packages like
[senzing/g2-sdk-go/g2engine](https://github.com/Senzing/g2-sdk-go/tree/main/g2engine),
add a `g2engine.go` file that has
the code for:

1. In `main.go`, define input and output "type -structs".
1. In `main.go`, define the "type - interface" of the `senzing` package
1. Receiving "structs" as input
1. Using [senzing/go-sdk-abstract-factory](https://github.com/Senzing/go-sdk-abstract-factory) to
   get an implementation of the
