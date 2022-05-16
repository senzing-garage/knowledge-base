# What is pylint

## install

1. See [pylint on pypi](https://pypi.org/project/pylint/)

## .pylintrc

1. :pencil2: Identify the file to be inspected.
   Example:

    ```console
    export SENZING_PYTHON=redoer.py
    ```

1. List all type of errors seen in the file.
   Example:

    ```console
    pylint --msg-template="{symbol}" ${SENZING_PYTHON} | sort | uniq
    ```

## Uses

### Github workflow

1. See [.github/workflows/pylint.yaml](https://github.com/Senzing/stream-loader/blob/main/.github/workflows/pylint.yaml)
