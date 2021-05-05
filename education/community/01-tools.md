# Tools used in Community

This exercise introduces some of the major tooling used by the Senzing Community.

## Introductory tools

### GitHub

[GitHub](../../WHATIS/github.md)
holds the corpus of the Senzing Community code.
You'll want to create a "GitHub username" for yourself.

### Docker

[Docker](../../WHATIS/docker.md)
is useful for quick environments that can be used to test ideas
as well as deploy Senzing.

For instance if you want to try something on Ubuntu, run

```console
docker run \
  --interactive \
  --rm \
  --tty \
  ubuntu /bin/bash
```

If you want to try the same thing on Centos:

```console
docker run \
  --interactive \
  --rm \
  --tty \
  centos /bin/bash
```

Here's [how to install Docker](../../HOWTO/install-docker.md).

### Python

> "When in Rome, do as the Romans"

If you are a Java programmer and see variables written in
[snake case](https://en.wikipedia.org/wiki/Snake_case),
you'd probably think that the person who wrote the Java program
didn't know much about Java.

Well, the same is true in
[Python](../../WHATIS/python.md).

To learn how to speak "Python", knowledge of
[PEP-8](https://www.python.org/dev/peps/pep-0008/)
is essential.

#### Python standards

1. [Python Enhancement Proposals (PEP)](https://www.python.org/dev/peps/)
    1. [PEP-8 checker](http://pep8online.com/)

### Markdown

[Markdown](../../WHATIS/markdown.md)
is the style of documentation used in GitHub.

### Tools for thinking

1. [The Twelve-Factor App](https://12factor.net/) is a compendium of know-how for building software in the cloud.
   As such, Senzing wants to build software that is conducive to the Twelve-Factor approach.

1. [The Pragmatic Programmer](https://pragprog.com/titles/tpp20/the-pragmatic-programmer-20th-anniversary-edition/)
   is a book that serves as a pretty good guide to modern software development.

## Intermediate tools

### docker-compose

[docker-compose](../../WHATIS/docker-compose.md)

### Integrated Development Environments (IDE)

#### Eclipse

### Portainer

[Portainer](../../WHATIS/portainer.md) is a web interface for `docker` commands.

## Advanced tools

### AWS Cloudformation

### Jupyter notebooks

[Jupyter Notebooks](../../WHATIS/jupyter-notebook.md)

### Kubernetes

### minikube

### OpenShift

### Packer

[Packer](../../WHATIS/packer.md)

### Terraform

