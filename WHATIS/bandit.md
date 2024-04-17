# Bandit

> Bandit is a tool designed to find common security issues in Python code. To do this, Bandit processes each file, builds an AST from it, and runs appropriate plugins against the AST nodes. Once Bandit has finished scanning all the files, it generates a report.

Refer to the [Bandit Documentation] for more details.

## Install

### Install via pip

1. ```console
    pip install bandit
    ```
  - See additional details in the [Bandit Installation Documentation].

### Install via brew

1. ```console
    brew install bandit
    ```
  - See additional details in the [Brew Documentation].

### Install via snap

1. ```console
    sudo apt update
    sudo apt install snapd
    sudo snap install bandit
    ```
  - See additional details in the [Snap Documentation].

## Running Bandit against a source folder

1. ```console
    bandit -r ~/your_repos/project
    ```
  - See [Bandit Usage Documentation] for more details.

[Bandit Documentation]: https://bandit.readthedocs.io/en/latest/
[Bandit Installation Documentation]: https://bandit.readthedocs.io/en/latest/start.html
[Bandit Usage Documentation]: https://bandit.readthedocs.io/en/latest/start.html#usage
[Brew Documentation]: https://formulae.brew.sh/formula/bandit
[Snap Documentation]: https://snapcraft.io/install/bandit/ubuntu