# Cleanup

The following information will clean the demonstration off the local workstation.

## Stop the Docker container

1. Use `ctrl-c` to stop the running `senzing-serve-grpc` Docker container created by the`docker run ...` command.

## Remove the Docker image

2. Remove the `senzing/serve-grpc` Docker image from Docker's cache.

   ```console
   docker rmi senzing/serve-grpc
   ```

## Remove senzing-grpc python package

3. If installed, uninstall the Senzing `senzing-grpc` python package.

   ```console
   python3 -m pip uninstall senzing-grpc

   ```

## Next steps

4. [Development with Senzing Python SDK]
   1. [Senzing Hello World]
   1. [Load Senzing truth-sets]
   1. [Load user data]
   1. [Show method help]
   1. Clean up

[Development with Senzing Python SDK]: development-with-senzing-python-sdk.md
[Load Senzing truth-sets]: load-senzing-truthsets.md
[Load user data]: load-user-data.md
[Senzing Hello World]: senzing-hello-world.md
[Show method help]: show-method-help.md
