# Tools used in Community

This exercise introduces some of the major tooling used by the Senzing Community.

## Contents

1. [Introductory tools](#introductory-tools)
    1. [GitHub](#github)
    1. [Docker](#docker)
    1. [Integrated Development Environments](#integrated-development-environments-ide)
    1. [Markdown](#markdown)
    1. [Tools for Thinking](#tools-for-thinking)
1. [Language tools]()
    1. [Python](#python)
    1. [Go](#go)
    1. [Java](#java)
    1. [Node](#node)
1. [Intermediate tools](#intermediate-tools)
    1. [docker-compose](#docker-compose)
    1. [Portainer](#portainer)
1. [Advanced tools](#advanced-tools)
    1. [AWS Cloudformation](#aws-cloudformation)
    1. [Jupyter notebooks](#jupyter-notebooks)
    1. [Kubernetes](#kubernetes)
1. [Potential future tools](#potential-future-tools)
    1. [Packer](#packer)
    1. [Terraform](#terraform)

## Introductory tools

### GitHub

[GitHub](../../WHATIS/github.md)
holds the corpus of the Senzing Community code.
You'll want to create a "GitHub username" for yourself.

### Docker

[Docker](../../WHATIS/docker.md)
is useful for quick environments that can be used to test ideas
as well as deploy Senzing.

1. If you want to try something on Debian, run:

    ```console
    docker run \
      --interactive \
      --rm \
      --tty \
      debian /bin/bash
    ```

1. If you want to try something on Ubuntu, run:

    ```console
    docker run \
      --interactive \
      --rm \
      --tty \
      ubuntu /bin/bash
    ```

1. If you want to somethin on Centos, run:

    ```console
    docker run \
      --interactive \
      --rm \
      --tty \
      centos /bin/bash
    ```

### Integrated Development Environments (IDE)

#### Visual Studio Code

1. [Visual Studio Code](../../WHATIS/visual-studio-code.md) is the preferred IDE.
   But it is not a mandatory IDE.
1. Others seen in Senzing:  Eclipse, Pycharm

### Markdown

[Markdown](../../WHATIS/markdown.md)
is the style of documentation used in GitHub.

### Tools for Thinking

1. [The Twelve-Factor App](https://12factor.net/) is a compendium of know-how for building software in the cloud.
   As such, Senzing wants to build software that is conducive to the Twelve-Factor approach.

1. [The Pragmatic Programmer](https://pragprog.com/titles/tpp20/the-pragmatic-programmer-20th-anniversary-edition/)
   is a book that serves as a pretty good guide to modern software development.

## Language tools

### Python

> "When in Rome, do as the Romans"

If you are a Java programmer and see variables written in
[snake case](https://en.wikipedia.org/wiki/Snake_case),
you'd probably think that the person who wrote the Java program
didn't know much about Java.
Well, the same is true in
[Python](../../WHATIS/python.md).
If lower camelCase is used in for local Python variables,
one wonders if the person knows Python
or is still a Java programmer trying out a new language.
To learn how to speak "Python", knowledge of
[PEP-8](https://www.python.org/dev/peps/pep-0008/)
is essential.

#### Python standards

1. [Python Enhancement Proposals (PEP)](https://www.python.org/dev/peps/)
    1. [PEP-8 checker](http://pep8online.com/)

### Go

1. Standard tool set
    1. [go](https://go.dev/)
    1. [gofmt](https://pkg.go.dev/cmd/gofmt) - Formatting
    1. [godoc](https://pkg.go.dev/golang.org/x/tools/cmd/godoc) - Documentation generator
1. Additional tools
    1. [gosec](https://github.com/securego/gosec) - Inspects code for security issues

### Java

### Node

## Intermediate tools

### docker-compose

[docker-compose](../../WHATIS/docker-compose.md)

### Portainer

[Portainer](../../WHATIS/portainer.md) is a web interface for `docker` commands.

## Advanced tools

[knowledge-base/WHATIS](../../WHATIS) has tools that have been on the "radar".

### AWS Cloudformation

### Jupyter notebooks

[Jupyter Notebooks](../../WHATIS/jupyter-notebook.md)

### Kubernetes

1. [minikube](https://minikube.sigs.k8s.io/docs/start/)

## Potential future tools

### Packer

[Packer](../../WHATIS/packer.md)

### Terraform
