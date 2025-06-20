# What is grpcurl

> `grpcurl` is a command-line tool that lets you interact with gRPC servers.
> It's basically curl for gRPC servers.
> -- _[grpcurl on Github]_

## Install

1. Linux.

   For latest version, visit [releases].

   ```console
   wget https://github.com/fullstorydev/grpcurl/releases/download/v1.9.3/grpcurl_1.9.3_linux_amd64.deb
   sudo apt-get install -y ./grpcurl_1.9.3_linux_amd64.deb
   ```

   Installation tests:

   ```console
   grpcurl -version
   which grpcurl
   ```

## Usage

1. See [Usage]
1. Example using [senzing/serve-grpc]:

    ```console
    grpcurl -plaintext -format text localhost:8261 szproduct.SzProduct.GetVersion
    ```

## Sites

1. [grpcurl on Github]

[grpcurl on Github]: https://github.com/fullstorydev/grpcurl
[releases]: https://github.com/fullstorydev/grpcurl/releases
[senzing/serve-grpc]: https://github.com/senzing-garage/serve-grpc
[Usage]: <https://github.com/fullstorydev/grpcurl?tab=readme-ov-file#usage>
