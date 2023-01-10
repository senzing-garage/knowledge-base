# Log Levels

## Current integer assignments

| Integer value | C          | Go    | Python |
|---------------|------------|-------|--------|
| 0             | no logging | TRACE |        |
| 1             | logging    | DEBUG |        |
| 2             |            | INFO  |        |
| 3             |            | WARN  |        |
| 4             |            | ERROR |        |
| 5             |            | FATAL |        |
| 6             |            | PANIC |        |

## Go level explanations

| Level | Use                                                   |
|-------|-------------------------------------------------------|
| TRACE | Entry/Exit tracing                                    |
| DEBUG | Values see during processing                          |
| INFO  | Process steps achieved                                |
| WARN  | Unexpected situations, but processing was successful  |
| ERROR | Unexpected situations, processing was not successful  |
| FATAL | The process needs to shutdown                         |
| PANIC | The underlying system is at issue                     |
