# Python packaging

## Synopsis

This proposal is to modify the Senzing Software Development Kit (SDK) for Python
to become more in-line with industry standards.

## Overview

The current Senzing SDK for Python is shipped in the RPM/DEB file as a
dirctory (`g2/sdk/python`) and is intermingled with client programs in
another directory (`g2/python`).
To accommdate this setup, a user has to modify `PYTHONPATH` to locate these files.

This approach has shortcomings:

1. Isn't conducive to the industry standard method of installing Python libraries, `pip`.
1. User modification of `PYTHONPATH` isn't the usual method of adding Python libraries.
1. Cannot be independenly installed; requires yum/apt installer.
1. Does not work well with Python's virtual environments.
1. `__pycache__` is created dynamically which may mutate containers.
1. Not conducive to toolchains (Integrated Development Environments, Docker build, )

The proposed approach:

1. Create industry-standard Python packaging.
1. Host packages in industry standard location, [Python Package Index](https://pypi.org/).
1. Update Senzing Python programs (i.e. `g2/python/*`) to use packages correctly.

**Note:**
This will not preclude the use of the directories shipped with the SenzingAPI RPM/DEB packages.
However, the directory structure of the Senzing SDK for Python will need to be modified
to the industry-standard packaging format.


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

## Modification to Senzing SDK Python

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
