# What is Prettier

Prettier is a code formatter that outputs code in a consistent style.  
See more details: [What is Prettier?]

## Install

### Via NPM

```console
npm install --save-dev --save-exact prettier
```

Optional: Create an empty config file:

```console
node --eval "fs.writeFileSync('.prettierrc','{}\n')"
```

Optional: Create a .prettierignore file to define what **_not_** to format

```console
node --eval "fs.writeFileSync('.prettierignore','# Ignore artifacts:\nbuild\ncoverage\n')"
```

Find more details in the [Prettier installation documentation].

### Via VSCode

[Install via VSCode Marketplace]

For more details on installation and default config see the [Prettier VSCode documentation].

## Formatting files

## Check all files without writing any changes

```console
npx prettier --check .
```

### Format all files

NOTE: For large files and repos this might take while.

```console
npx prettier --write .
```

### Format specific files

Ex.

```console
 npx prettier --write .github/workflows/lint*
```

[Install via VSCode Marketplace]: https://marketplace.visualstudio.com/items?itemName=esbenp.prettier-vscode
[Prettier installation documentation]: https://prettier.io/docs/en/install
[Prettier VSCode documentation]: https://github.com/prettier/prettier-vscode?tab=readme-ov-file#installation
[What is Prettier?]: https://prettier.io/docs/en/
