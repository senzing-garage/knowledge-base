# Developing with Senzing using gRPC

## Overview

1. [A quick look at gRPC]
1. [The Senzing service definition]
1. [Writing to native gRPC code]
1. [Writing to Senzing SDK]
1. [Run Senzing gRPC server Docker container]
1. [Run from command line]
1. [Run in Jupyter Lab]
1. [Jupyter Lab recap]

![image](divider.png)

## A quick look at gRPC

1. [gRPC] - Google Remote Procedure Call
    1. Could have been called "[Stubby]", "[ProtoCall]", or "[ArcWire]".
    1. The [internal code name "gRPC"] stuck.
    1. It is [open source on GitHub], Apache 2 licensed.
    1. So although Google originated the project, the "g" in "gRPC" is less affiliated with Google.
1. What problem does gRPC solve?
    1. Network messaging
        1. Specifically: calling a function or procedure on a remote machine.
        1. Two aspects:
            1. Message format.
            1. Network transportation.
               Usually in Application Layer of the [Open Systems Interconnection (OSI)] and [TCP/IP] models.
    1. Other technologies in this space:
        1. [Simple Object Access Protocol] (SOAP)
        1. [Hypertext Markup Language] (HTML)
        1. [Hypertext Transfer Protocol] (HTTP)
        1. [Short Message Service] (SMS)
1. Advantages of gRPC
    1. Performance
        1. Anecdotal evidence on internet suggests gRPC is 7 times faster than HTML.
        1. Tight packing of data
    1. Language agnostic
    1. Network transportation: HTTP/2
1. 10 years since inception; first release 2015.

![image](divider.png)

## The Senzing service definition

1. For gRPC, the Interface Definition Language (IDL) is [Protocol Buffers] (Protobuf).
   This defines the messages passed across the network.
1. The `.proto` files for Senzing are in [sz-sdk-proto].
    1. Example: [szengine.proto]
       1. `option:` metadata for transpiling into target languages.
       1. `service:` lists all of the procedure calls.
       1. `message:` list all of the request and response messages.
1. Using [protoc], a transpiler, `.proto` specification files are used to generate code.
    1. Example generation: [generate Python gRPC code]
    1. Example output:
        1. [szengine_pb2_grpc.py] - transportation (gRPC)
        1. [szengine_pb2.py] - message (Protobuf)
1. For hints on how to transpile, view the [sz-sdk-proto Makefile].

![image](divider.png)

## Writing to native gRPC code

1. It is possible to write code that uses the transpiled code directly.
   Here is an example in Python:

    ```python
    stub = szengine_pb2_grpc.SzEngineStub(grpc_channel)

    try:
        request = szengine_pb2.AddRecordRequest(
            dataSourceCode=as_str(data_source_code),
            recordId=as_str(record_id),
            recordDefinition=as_str(record_definition),
            flags=flags,
        )
        response = stub.AddRecord(request)
    except Exception as err:
        raise new_exception(err) from err
    info = response.result
    ```

1. **Problem:**  Code to access Senzing via transpiled gRPC interface differs from native Senzing SDK interface.
   So you would have to write it one way to access via gRPC and a different way to access natively.
   Native Senzing SDK access look like this:

    ```console
    try:
        info = sz_engine.add_record(data_source_code, record_id, record_definition, flags)
    except SzError as err:
        print(err)
    ```

![image](divider.png)

## Writing to Senzing SDK

1. Senzing has "core" SDKs to talk directly to the underlying Senzing binary libraries.
    1. Supported languages:  Python, Java, Go
1. Senzing also has "gRPC" SDKs that implement the same interface as the "core" SDKs.
    1. The gRPC SDKs use an [adapter pattern] to translate from the Senzing interface to the gRPC interface.
    1. Supported languages:  Python, Java, Go
1. With Senzing "core" and "gRPC" SDKs, you can access Senzing in the same manner.
   Python example:

    ```python
    try:
        info = sz_engine.add_record(data_source_code, record_id, record_definition, flags)
    except SzError as err:
        print(err)
    ```

1. Compare file differences between using a Senzing "gRPC" SDK and a "core" SDK:
    1. Visit [DiffNow] and enter the following URLs:

        ```console
        https://raw.githubusercontent.com/senzing-garage/playground/refs/heads/main/rootfs/examples/python/senzing_hello_world.py
        ```

        ```console
        https://raw.githubusercontent.com/senzing-garage/knowledge-base/refs/heads/main/presentations/developing-with-senzing-using-grpc/senzing_hello_world.py
        ```

    1. Another example. Visit [DiffNow] again and enter the following URLs:

        ```console
        https://raw.githubusercontent.com/senzing-garage/playground/refs/heads/main/rootfs/examples/python/senzing_load_truthsets.py
        ```

        ```console
        https://raw.githubusercontent.com/senzing-garage/knowledge-base/refs/heads/main/presentations/developing-with-senzing-using-grpc/senzing_load_truthsets.py
        ```

    1. **Net:** In Python, only the imported package and the `FACTORY_PARAMETERS` change.
       Similar for other languages.

1. Under the covers the [gRPC add_record method] is adapting from the Senzing SDK interfact to the gRPC interface.

1. **NOTE:** If you are writing in a [gRPC supported language] other than Python, Java, or Go,
   you can still use gRPC natively to access a Senzing gRPC server.
   However, there will be no "core" Senzing SDK for accessing Senzing natively.

![image](divider.png)

## Create gRPC server Docker image

1. **Note:** These instructions will only be required during the Senzing V4 beta.
   After Senzing V4 is public, the Docker image will be available on [DockerHub].
1. To get values for `<get-from-Senzing>`, visit [Become a Senzing Beta Tester].
1. Set environment variables:
    1. Linux/macOS

        ```console
        export SENZING_APT_REPOSITORY_NAME=<get-from-Senzing>
        export SENZING_APT_REPOSITORY_URL=<get-from-Senzing>
        ```

    1. Windows cmd

        ```console
        set SENZING_APT_REPOSITORY_NAME=<get-from-Senzing>
        set SENZING_APT_REPOSITORY_URL=<get-from-Senzing>
        ```

    1. Windows PowerShell

        ```console
        $env:SENZING_APT_REPOSITORY_NAME="<get-from-Senzing>"
        $env:SENZING_APT_REPOSITORY_URL="<get-from-Senzing>"
        ```

1. Build `senzing/senzingsdk-runtime-beta:latest`.

    ```console
    docker build --no-cache --pull --build-arg SENZING_APT_REPOSITORY_NAME --build-arg SENZING_APT_REPOSITORY_URL --tag senzing/senzingsdk-runtime-beta:latest https://github.com/senzing/senzingsdk-runtime.git#main
    ```

1. Build `senzing/serve-grpc:latest`.

    ```console
    docker build --no-cache --pull --tag senzing/serve-grpc:latest https://github.com/senzing-garage/serve-grpc.git#main
    ```

![image](divider.png)

## Run Senzing gRPC server Docker container

1. Run `senzing/serve-grpc:latest`

    ```console
    docker run -it --name senzing-serve-grpc -p 8261:8261 --read-only --rm senzing/serve-grpc:latest
    ```

1. In the Docker container, Senzing uses an internal, in-memory SQLite database.
   Naturally this means when the container is stopped, the database contents are gone.
1. Port 8261 was chosen because it doesn't conflict with anything on
   [IANA's Service Name and Transport Protocol Port Number Registry].
![image](divider.png)

## Run from command line

1. Get examples from GitHub.

    ```console
    git clone git@github.com:senzing-garage/playground.git ~/my-senzing-playground
    ```

1. Activate python virtual environment and install python `senzing-grpc` package.
   Example:

    ```console
    source ~/.venv/bin/activate
    ```

    ```console
    python3 -m pip install --upgrade senzing-grpc
    ```

1. Run example programs.

    ```console
    cd ~/my-senzing-playground/rootfs/examples/python/
    ```

    ```console
    ./senzing_hello_world.py
    ```

    ```console
    ./senzing_load_truthsets.py
    ```

1. This means that you can work with Senzing locally with your custom toolset.
   Examples:
    1. Integrated Developement environments (IDEs) like VSCode, Eclipse, PyCharm.
    1. Linting/Formatting like pylint, gofmt, flake8, black
    1. Testers like pytest, go test, unittest
    1. Type checking like mypy.
    1. Security testing like Bandit, gosec

![image](divider.png)

## Run in Jupyter Lab

1. **Caveat:** This exercise requires that you already have [Jupyter Lab] installed on your computer.
1. Activate python virtual environment and install python `senzing-grpc` package.
   Example:

    ```console
    source ~/.venv/bin/activate
    ```

    ```console
    python3 -m pip install --upgrade senzing-grpc
    ```

1. Run `jupyter lab` from examples directory.

    ```console
    cd ~/my-senzing-playground/rootfs/examples/notebooks/
    ```

    ```console
    jupyter lab
    ```

1. In Jupyter Lab, navigate to the `python` directory and run the following:
    1. `senzing_hello_world.ipynb`
    1. `senzing_load_truthsets.ipynb`

1. In Jupyter Lab, if a Go Kernel (e.g. [gonb]) is installed, navigate to the `go` directory and run the following:
    1. `senzing_hello_world.ipynb`
    1. `senzing_load_truthsets.ipynb`

![image](divider.png)

## Jupyter Lab recap

A recap of the steps to start working with Senzing on Jupyter Lab:

1. Start Docker container running Senzing gRPC service.

    ```console
    docker run -it --name senzing-serve-grpc -p 8261:8261 --read-only --rm senzing/serve-grpc:latest
    ```

1. Activate python virtual environment and install python `senzing-grpc` package.
   Example:

    ```console
    source ~/.venv/bin/activate
    python3 -m pip install --upgrade senzing-grpc
    ```

1. Run `jupyter lab`.

    ```console
    jupyter lab
    ```

1. Start coding!

![image](divider.png)

## References

1. [gRPC on GitHub]
1. [gRPC on Wikipedia]
1. [gRPC on Google]
1. [gRPC FAQs]

[A quick look at gRPC]: #a-quick-look-at-grpc
[adapter pattern]: https://en.wikipedia.org/wiki/Adapter_pattern
[ArcWire]: https://youtu.be/5dMK5OW6WSw?t=333
[Become a Senzing Beta Tester]: https://senzing.com/beta-test-interest/
[DiffNow]: https://www.diffnow.com/compare-urls
[DockerHub]: https://hub.docker.com/
[generate Python gRPC code]: https://grpc.io/docs/languages/python/quickstart/#generate-grpc-code
[gonb]: https://github.com/janpfeifer/gonb
[gRPC add_record method]: https://github.com/senzing-garage/sz-sdk-python-grpc/blob/4731a2ec428f3c3265e10aacb8b3e813067292c6/src/senzing_grpc/szengine.py#L77-L94
[gRPC FAQs]: https://grpc.io/docs/what-is-grpc/faq/
[gRPC on GitHub]: https://github.com/grpc/
[gRPC on Google]: https://opensource.google/projects/grpc
[gRPC on Wikipedia]: https://en.wikipedia.org/wiki/GRPC
[gRPC supported language]: https://grpc.io/docs/languages/
[gRPC]: https://grpc.io
[Hypertext Markup Language]: https://en.wikipedia.org/wiki/HTML
[Hypertext Transfer Protocol]: https://en.wikipedia.org/wiki/HTTP
[internal code name "gRPC"]: https://youtu.be/5dMK5OW6WSw?t=276
[Jupyter Lab recap]: #jupyter-lab-recap
[Jupyter Lab]: https://jupyter.org/
[open source on GitHub]: https://github.com/grpc/grpc
[Open Systems Interconnection (OSI)]: https://en.wikipedia.org/wiki/OSI_model
[protoc]: https://grpc.io/docs/protoc-installation/
[ProtoCall]: https://youtu.be/5dMK5OW6WSw?t=318
[Protocol Buffers]: https://protobuf.dev/
[Run from command line]:#run-from-command-line
[Run in Jupyter Lab]: #run-in-jupyter-lab
[Run Senzing gRPC server Docker container]: #run-senzing-grpc-server-docker-container
[Short Message Service]: https://en.wikipedia.org/wiki/SMS
[Simple Object Access Protocol]: https://en.wikipedia.org/wiki/SOAP
[Stubby]: https://youtu.be/5dMK5OW6WSw?t=98
[sz-sdk-proto Makefile]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/Makefile
[sz-sdk-proto]: https://github.com/senzing-garage/sz-sdk-proto
[szengine_pb2_grpc.py]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/example_generated_source_code/python/szengine/szengine_pb2_grpc.py
[szengine_pb2.py]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/example_generated_source_code/python/szengine/szengine_pb2.py
[szengine.proto]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/szengine.proto
[TCP/IP]: https://en.wikipedia.org/wiki/Internet_protocol_suite
[The Senzing service definition]: #the-senzing-service-definition
[Writing to native gRPC code]: #writing-to-native-grpc-code
[Writing to Senzing SDK]: #writing-to-senzing-sdk
[IANA's Service Name and Transport Protocol Port Number Registry]: http://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.txt
