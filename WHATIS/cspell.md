# CSpell

> The CSpell mono-repo, a spell checker for code.

Refer to the [Documentation] for more details.

## Install

### Install via npm

```console
npm install -g cspell@latest
```

## Run locally

### Run recursively against visible files in the current directory

```console
cspell .
```

### Run recursively against all files (including hidden)

```console
cspell . --dot
```

### Run with the vscode configuration file

```console
cspell . -c .vscode/cspell.json --dot
```

[Documentation]: https://cspell.org/
