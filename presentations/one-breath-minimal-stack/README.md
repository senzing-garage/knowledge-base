# One Breath: Minimal docker-compose stack

## One-breath

1. Download `docker-compose.yaml` file and bring up docker compose stack.
   Example:

    ```console
    wget "https://raw.githubusercontent.com/Senzing/knowledge-base/main/presentations/one-breath-minimal-stack/docker-compose.yaml"
    docker-compose up

    ```

### Use

1. What's being created?
   View [image](https://github.com/senzing-garage/docker-compose-demo/blob/main/docs/img-architecture/architecture.png).

1. Open web browser to AWS's assigned IP address.
   Use the `http://` protocol, not the `https://` protocol.
   Example:

   - [http://localhost:8251](http://localhost:8251)
   - [http://1.2.3.4:8251](http://1.2.3.4:8251)

1. Search for "Robert Smith"

## Caveats

1. This demonstration does not address security concerns.
   Do not put private information into demonstration without
   modifying the demonstration to meet your security requirements.
1. This is an ephemeral demonstration.
   As soon as as the docker-compose stack is brought down,
   the data is deleted.
