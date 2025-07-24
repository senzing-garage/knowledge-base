# What is R

> R is a free software environment for statistical computing and graphics.
> -- _[The R Project for Statistical Computing]_

## Install

1. Ubuntu
    - [Ubuntu Packages For R - Full Instructions]
    - Example:

        ```console
        sudo apt update
        sudo apt upgrade
        ```

        ```console
        sudo apt install software-properties-common dirmngr -y
        ```

        ```console
        wget -qO- https://cloud.r-project.org/bin/linux/ubuntu/marutter_pubkey.asc | sudo tee -a /etc/apt/trusted.gpg.d/cran_ubuntu_key.asc
        ```

        ```console
        sudo add-apt-repository "deb https://cloud.r-project.org/bin/linux/ubuntu $(lsb_release -cs)-cran40/"
        ```

        ```console
        sudo apt update
        sudo apt install r-base r-base-dev -y
        ```

## References

- [CRAN]

[CRAN]: https://cran.r-project.org/
[The R Project for Statistical Computing]: https://www.r-project.org/
[Ubuntu Packages For R - Full Instructions]: https://cran.r-project.org/bin/linux/ubuntu/fullREADME.html
