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
   View [image](https://github.com/Senzing/docker-compose-demo#overview).

1. Open web browser to AWS's assigned IP address.
   Use the `http://` protocol, not the `https://` protocol.
   Example:

   - [http://localhost](http://localhost)
   - [http://1.2.3.4](http://1.2.3.4)

1. Search for "Robert Smith"

## Caveats

1. This demonstration does not address security concerns.
   Do not put private information into demonstration without
   modifying the demonstration to meet your security requirements.
