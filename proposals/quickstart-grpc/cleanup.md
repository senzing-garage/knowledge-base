# Cleanup

The following information will clean the demonstration off the local workstation.

## Stop the Docker container

1. Use `ctrl-c` to stop the Docker container created by `docker run ...`,

## Remove senzing-grpc python package

```console
python3 -m pip uninstall senzing-grpc

```

## Remove the Docker image

```console
docker rmi senzing/demo-quickstart
```

## Next steps

8. [Senzing Python Software Development Kit]
    1. [Senzing Hello World]
    1. [Load Senzing truth-sets]
    1. [Load user data]
    1. [Show method help]
    1. Clean up

[Load Senzing truth-sets]: load-senzing-truthsets.md
[Load user data]: load-user-data.md
[Senzing Hello World]: senzing-hello-world.md
[Senzing Python Software Development Kit]: python-sdk.md
[Show method help]: show-method-help.md
