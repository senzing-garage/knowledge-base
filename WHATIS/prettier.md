# What is Prettier

Prettier is a code formatter that outputs code in a consistent style.      
See more details: [What is Prettier?]

## Install

```console
npm install --save-dev --save-exact prettier
```

Optional: Create an empty config file:
```console
node --eval "fs.writeFileSync('.prettierrc','{}\n')"
```

Optional: Create a .prettierignore file to define what ***not*** to format
```console
node --eval "fs.writeFileSync('.prettierignore','# Ignore artifacts:\nbuild\ncoverage\n')"
```

Find more details in the [Prettier installation documentation].

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

[Prettier installation documentation]: https://prettier.io/docs/en/install
[What is Prettier?]: https://prettier.io/docs/en/

