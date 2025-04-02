# What is pylint

> Pylint is a static code analyser for Python 2 or 3.
> Pylint analyses your code without actually running it.
> It checks for errors, enforces a coding standard, looks for code smells, and can make suggestions about how the code could be refactored.
> -- _[pylint on pypi.org]_

## Install

1. See [pylint on pypi.org]

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

1. See [.github/workflows/pylint.yaml]

## References

1. [ReadTheDocs]
1. [Linting Python in Visual Studio Code]

[.github/workflows/pylint.yaml]: https://github.com/senzing-garage/stream-loader/blob/main/.github/workflows/pylint.yaml
[Linting Python in Visual Studio Code]: https://code.visualstudio.com/docs/python/linting
[pylint on pypi.org]: https://pypi.org/project/pylint/
[ReadTheDocs]: https://pylint.readthedocs.io/en/latest/
