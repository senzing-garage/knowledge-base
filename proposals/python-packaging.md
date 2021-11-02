# Python packaging

## Synopsis

This proposal is to modify the Senzing Software Development Kit (SDK) for Python
to become more in-line with industry standards.

## Overview

The current Senzing SDK for Python is shipped in the RPM/DEB file as a
directory (`g2/sdk/python`) and is intermingled with client programs in
another directory (`g2/python`).
To accommodate this setup, a user has to modify `PYTHONPATH` to locate these files.

This approach has shortcomings:

1. Isn't conducive to the industry standard method of installing Python libraries, `pip`.
1. User modification of `PYTHONPATH` isn't the usual method of adding Python libraries.
1. Cannot be independenly installed; requires yum/apt installer.
1. Does not work well with Python's virtual environments.
1. `__pycache__` is created dynamically which may mutate containers.
1. Not conducive to toolchains (Integrated Development Environments, Docker build, )

The proposed approach:

1. Creates industry-standard Python packaging.
1. Hosts packages in industry standard location, [Python Package Index](https://pypi.org/).
1. Updates Senzing Python programs (i.e. `g2/python/*`) to use packages correctly.

**Note:**
This will not preclude the use of the directories shipped with the SenzingAPI RPM/DEB packages.
However, the directory structure of the Senzing SDK for Python will need to be modified
to the industry-standard packaging format.

Because this is a "breaking change", the recommendation is to introduce the functionality into Senzing API 3.0.0.

### Contents

1. [Installation](#installation)
1. [Modification to client code](#modification-to-client-code)
    1. [Imports](#imports)
    1. [Object creation](#object-creation)
    1. [Import alternative](#import-alternative)
1. [Modification to Senzing SDK for Python](#modification-to-senzing-sdk-for-python)
    1. [Use relative path](#use-relative-path)
1. [Modification to RPM/DEB directory structure](#modification-to-rpm-deb-directory-structure)

## Installation

Installation is done with `pip`.

1. Using the `pip` test server.
   Example:

    ```console
    python3 -m pip install \
      --index-url https://test.pypi.org/simple/ \
      --no-deps \
      senzing
    ```

## Modification to client code

### Imports

1. Before.
   Example:

    ```python
    import G2Exception
    from G2Config import G2Config
    from G2ConfigMgr import G2ConfigMgr
    from G2Diagnostic import G2Diagnostic
    from G2Engine import G2Diagnostic
    from G2Product import G2Product
    ```

1. After.
   Example:

    ```python
    from senzing import G2Exception, G2Config, G2ConfigMgr, G2Diagnostic, G2Diagnostic, G2Product
    ```

1. After alternative.
   Example:

    ```python
    from senzing import *
    ```

### Object creation

1. Before.
   Example:

    ```python
    an_object = G2Product()
    ```

1. After.
   Example:

    ```python
    an_object = G2Product.G2Product()
    ```

### Import alternative

This alternative `from`/`import` syntax allows object creation to remain unchanged.

1. Use `from` containing path.
   Example:

    ```python
    from senzing.G2Exception import G2Exception
    from senzing.G2Config import G2Config
    from senzing.G2ConfigMgr import G2ConfigMgr
    from senzing.G2Diagnostic import G2Diagnostic
    from senzing.G2Engine import G2Engine
    from senzing.G2Product import G2Product
    ```

1. Then object creation can remain:

    ```python
    an_object = G2Product()
    ```

## Modification to Senzing SDK for Python

### Use relative path

1. Before.
   Example:

    ```python
    from G2Exception import TranslateG2ModuleException, G2ModuleNotInitialized, G2ModuleGenericException
    ```

1. After.
   Example:

    ```python
    from .G2Exception import TranslateG2ModuleException, G2ModuleNotInitialized, G2ModuleGenericException
    ```

1. Notice the preceeding dot in `.G2Exception`.  It means "look for G2Exception in the same directory as the calling python module".  It is a "relative path" indicator.

## Modification to RPM/DEB directory structure

1. `g2/python` before.
   Example:

    ```console
    $ tree
    .
    ├── CompressedFile.py
    ├── demo
    │   ├── sample
    │   │   ├── project.csv
    │   │   ├── project.json
    │   │   ├── sample_company.csv
    │   │   ├── sample_company.json
    │   │   ├── sample_person.csv
    │   │   └── sample_person.json
    │   └── truth
    │       ├── project.csv
    │       ├── project.json
    │       ├── truthset-person-v1-set1-data.csv
    │       ├── truthset-person-v1-set1-key.csv
    │       ├── truthset-person-v1-set1.sh
    │       ├── truthset-person-v1-set2-data.csv
    │       ├── truthset-person-v1-set2-key.csv
    │       └── truthset-person-v1-set2.sh
    ├── DumpStack.py
    ├── G2Audit.py
    ├── G2Command.py
    ├── G2ConfigMgr.py
    ├── G2Config.py
    ├── G2ConfigTables.py
    ├── G2ConfigTool.py
    ├── G2ConfigTool.readme
    ├── G2CreateProject.py
    ├── G2Database.py
    ├── G2Diagnostic.py
    ├── G2Engine.py
    ├── G2Exception.py
    ├── G2Explorer.py
    ├── G2Export.py
    ├── G2Hasher.py
    ├── G2Health.py
    ├── G2IniParams.py
    ├── G2Loader.py
    ├── G2Paths.py
    ├── G2Product.py
    ├── G2Project.py
    ├── g2purge.umf
    ├── G2S3.py
    ├── G2SetupConfig.py
    ├── G2Snapshot.py
    ├── G2UpdateProject.py
    └── governor_postgres_xid.py
    ```

1. `g2/python` after.
   Example:

    ```console
    $ tree
    .
    ├── CompressedFile.py
    ├── demo
    │   ├── sample
    │   │   ├── project.csv
    │   │   ├── project.json
    │   │   ├── sample_company.csv
    │   │   ├── sample_company.json
    │   │   ├── sample_person.csv
    │   │   └── sample_person.json
    │   └── truth
    │       ├── project.csv
    │       ├── project.json
    │       ├── truthset-person-v1-set1-data.csv
    │       ├── truthset-person-v1-set1-key.csv
    │       ├── truthset-person-v1-set1.sh
    │       ├── truthset-person-v1-set2-data.csv
    │       ├── truthset-person-v1-set2-key.csv
    │       └── truthset-person-v1-set2.sh
    ├── DumpStack.py
    ├── G2Audit.py
    ├── G2Command.py
    ├── G2ConfigTables.py
    ├── G2ConfigTool.py
    ├── G2ConfigTool.readme
    ├── G2CreateProject.py
    ├── G2Database.py
    ├── G2Explorer.py
    ├── G2Export.py
    ├── G2Health.py
    ├── G2Loader.py
    ├── G2Paths.py
    ├── G2Project.py
    ├── g2purge.umf
    ├── G2S3.py
    ├── G2SetupConfig.py
    ├── G2Snapshot.py
    ├── G2UpdateProject.py
    ├── governor_postgres_xid.py
    ├── senzing
    │   ├── G2ConfigMgr.py
    │   ├── G2Config.py
    │   ├── G2Diagnostic.py
    │   ├── G2Engine.py
    │   ├── G2Exception.py
    │   ├── G2Hasher.py
    │   ├── G2IniParams.py
    │   ├── G2Product.py
    │   └── __init__.py
    └── senzing_governor.py
    ```

1. In terms of code it would look like this.
   Move Senzing SDK for Python modules to a `senzing` subdirectory.
   Example:

    ```console
    export SENZING_PYTHON_DIR=~/my-senzing/g2/python

    mkdir ${SENZING_PYTHON_DIR}/senzing
    mv ${SENZING_PYTHON_DIR}/G2Config.py     ${SENZING_PYTHON_DIR}/senzing/
    mv ${SENZING_PYTHON_DIR}/G2ConfigMgr.py  ${SENZING_PYTHON_DIR}/senzing/
    mv ${SENZING_PYTHON_DIR}/G2Diagnostic.py ${SENZING_PYTHON_DIR}/senzing/
    mv ${SENZING_PYTHON_DIR}/G2Engine.py     ${SENZING_PYTHON_DIR}/senzing/
    mv ${SENZING_PYTHON_DIR}/G2Exception.py  ${SENZING_PYTHON_DIR}/senzing/
    mv ${SENZING_PYTHON_DIR}/G2Hasher.py     ${SENZING_PYTHON_DIR}/senzing/
    mv ${SENZING_PYTHON_DIR}/G2IniParams.py  ${SENZING_PYTHON_DIR}/senzing/
    mv ${SENZING_PYTHON_DIR}/G2Product.py    ${SENZING_PYTHON_DIR}/senzing/
    ```

1. Then add `__init__.py`.
   Example:

    ```console
    cat <<EOT > ${SENZING_PYTHON_DIR}/senzing/__init__.py
    __all__ = ["G2Config", "G2ConfigMgr", "G2Diagnostic", "G2Engine", "G2Exception", "G2Hasher", "G2IniParams", "G2Product"]
    EOT
    ```

## Prototypes

1. init-container
    1. [Import](https://github.com/Senzing/docker-init-container/compare/master...issue-128.dockter.1)
    1. [Import alternative](https://github.com/Senzing/docker-init-container/compare/master...issue-128.dockter.2)
1. stream-loader
    1. [Import](https://github.com/Senzing/stream-loader/compare/master...issue-246.dockter.1)
    1. [Import alternative](https://github.com/Senzing/stream-loader/compare/master...issue-246.dockter.2)
