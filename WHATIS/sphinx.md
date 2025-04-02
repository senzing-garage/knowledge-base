# Sphinx

> Sphinx makes it easy to create intelligent and beautiful documentation.

Refer to the [Documentation] for more details.

## Install

See the official [Installing Sphinx] page.

### macOS

1. A tip from [StackOverflow]:

   ```console
   brew install sphinx-doc
   brew link sphinx-doc --force
   ```

### Install via pip

1. ```console
   pip install sphinx
   ```

- See additional details in the [Installation Documentation].

1. Additional tools

   ```console
   python3 -m pip install \
       sphinx \
       sphinx-autodoc-typehints \
       sphinx-gallery \
       sphinx-jinja2-compat \
       sphinx-prompt \
       sphinx-rtd-theme \
       sphinx-tabs \
       sphinx-toolbox \
       sphinxcontrib-applehelp \
       sphinxcontrib-devhelp \
       sphinxcontrib-htmlhelp \
       sphinxcontrib-jquery \
       sphinxcontrib-jsmath \
       sphinxcontrib-qthelp \
       sphinxcontrib-serializinghtml
   ```

[Documentation]: https://www.sphinx-doc.org
[Installation Documentation]: https://www.sphinx-doc.org/en/master/usage/installation.html
[Installing Sphinx]: https://www.sphinx-doc.org/en/master/usage/installation.html
[StackOverflow]: https://stackoverflow.com/questions/36137496/os-x-install-of-sphinx-the-sphinx-build-and-sphinx-quickstart-not-found
