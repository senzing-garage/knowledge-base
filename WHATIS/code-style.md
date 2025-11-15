# Senzing Code Style Guide

Code style refers to a set of conventions and guidelines for writing and formatting source code in a consistent and readable manner.

Quick reference for code style standards across Senzing projects.

---

## Python

**Standard**: [PEP-0008](https://peps.python.org/pep-0008/) (with some line length exceptions)  
**Reference**: [template-python](https://github.com/senzing-garage/template-python)

### Key Requirements

- 4 spaces for indentation (no tabs)
- `snake_case` for variables and functions
- `PascalCase` for classes
- `UPPER_SNAKE_CASE` for constants
- Type hints for function signatures
- Docstrings for all public APIs

### Special Rules for Test Code

Test files in `Senzing.Sdk.Tests/` have relaxed rules:

- Can catch generic `Exception` (CA1031 disabled)
- Can use literal strings without localization (CA1303 disabled)
- Can have nested classes (CA1034 disabled)
- No "never instantiated" warnings (CA1812 disabled)
- No forced `sealed` class warnings (CA1852 disabled)

```bash
black --check .           # Formatting
pylint your_module/       # Linting
mypy your_module/         # Type checking
pytest                    # Tests
```

---

## Java

**Standard**: Checkstyle enforced via Maven (with suppressions)  
**Reference**: [sz-sdk-java](https://github.com/senzing-garage/sz-sdk-java)  
**Minimum Version**: OpenJDK 17+

### Checkstyle Suppressions (from suppressions.xml)

The following checks are **globally suppressed**:

- `LeftCurly` - Opening brace placement not enforced
- `LineLength` - No line length limit
- `FileLength` - No file length limit
- `FinalParameters` - Parameters don't need `final`
- `RegexpSingleline` - No regex patterns enforced
- `AvoidStarImport` - Star imports allowed
- `HiddenField` - Field shadowing allowed
- `ParameterNumber` - No limit on parameter count
- `MagicNumber` - Magic numbers allowed

**Specific suppressions**:

- `MethodLength` suppressed for `SzExceptionMapper.java` and `InstallUtilities.java`
- `AvoidNestedBlocks` suppressed for `InstallUtilities.java`

### Key Requirements

- `camelCase` for variables and methods
- `PascalCase` for classes
- `UPPER_SNAKE_CASE` for constants
- Javadoc for all public APIs
- Use `final` for immutable variables (but not required for parameters)

### Build & Check

```bash
mvn checkstyle:check      # Style checking
mvn test                  # Run tests
mvn package               # Build JAR
mvn -DskipTests=true package  # Build without tests
```

---

## Go

**Standard**: [Effective Go](https://go.dev/doc/effective_go)  
**Reference**: [template-go](https://github.com/senzing-garage/template-go)

### Key Requirements

- **Always use `gofmt`** - Non-negotiable
- Tabs for indentation (handled by `gofmt`)
- `camelCase` for unexported names
- `PascalCase` for exported names
- Interfaces often end in `-er` (e.g., `Reader`, `Writer`)
- Short variable names in small scopes (e.g., `i`, `err`)
- Package names: lowercase, single word when possible

### Build & Check

```bash
gofmt -l .                # Check formatting
goimports -l .            # Check imports
go vet ./...              # Static analysis
golangci-lint run         # Comprehensive linting
go test ./...             # Run tests
make build                # Use Makefile commands
```

---

## C#

**Standard**: `dotnet format` with `.editorconfig` (mandatory)  
**Reference**: [sz-sdk-csharp](https://github.com/senzing-garage/sz-sdk-csharp)  
**Target**: .NET Standard 2.0

### Key Requirements (from .editorconfig)

- **4 spaces** for indentation (tab_width = 4)
- **UTF-8** encoding with final newline
- **Allman style** braces (opening brace on new line: `csharp_new_line_before_open_brace = all`)
- Style violations are **build errors** (`dotnet_analyzer_diagnostic.category-Style.severity = error`)

### Naming Conventions

- `PascalCase`: Types, namespaces, methods, properties, public fields, constants
- `camelCase`: Local variables, parameters, local constants
- `_camelCase`: Private instance fields (leading underscore)
- `s_camelCase`: Private static fields (s\_ prefix)
- `IPascalCase`: Interfaces (I prefix)
- `TPascalCase`: Type parameters (T prefix)

### Code Style Preferences

- **No `var`** - Explicit types preferred (`csharp_style_var_* = false`)
- **No `this.`** qualifier unless necessary
- **Expression-bodied** accessors, indexers, properties, lambdas
- **NOT expression-bodied** constructors, methods, operators
- **Pattern matching** preferred over `as`/`is` with null checks
- **Braces required** even for single-line blocks
- **`using` directives** outside namespace
- System directives sorted first, grouped separately

### Build & Check

```bash
# MUST pass before committing:
dotnet format --verify-no-changes --verbosity diagnostic Senzing.Sdk
dotnet format --verify-no-changes --verbosity diagnostic Senzing.Sdk.Tests

dotnet build Senzing.Sdk                        # Debug build
dotnet build -c Release Senzing.Sdk             # Release build
dotnet test Senzing.Sdk.Tests                   # Run tests
```

---

## Node.js / JavaScript

**Standard**: Airbnb Style Guide  
**Tools**: ESLint + Prettier

### Key Requirements

- 2 spaces for indentation
- `camelCase` for variables and functions
- `PascalCase` for classes
- `UPPER_SNAKE_CASE` for constants
- Single quotes for strings
- Always use semicolons
- Use `const` by default, `let` when reassignment needed
- Use arrow functions for anonymous functions
- Use template literals over string concatenation

### Build & Check

```bash
npm run lint              # ESLint
npm run format            # Prettier
npm test                  # Run tests
```

---

## General PR Review Checklist

### Code Quality

- [ ] Follows language-specific style guide (run formatters/linters)
- [ ] No commented-out code
- [ ] Meaningful variable and function names
- [ ] DRY principle followed (no duplicated logic)
- [ ] Functions are small and focused (single responsibility)
- [ ] No magic numbers (use named constants)

### Testing

- [ ] Unit tests for new functions/methods
- [ ] Integration tests for new endpoints/interfaces
- [ ] Edge cases covered
- [ ] Test coverage > 80%
- [ ] Tests are passing

### Documentation

- [ ] README updated if needed
- [ ] API documentation updated
- [ ] Inline comments for complex logic
- [ ] CHANGELOG.md updated
- [ ] Public APIs have proper doc comments

### Security

- [ ] No hardcoded credentials or API keys
- [ ] Input validation implemented
- [ ] Proper error handling (no silent failures)
- [ ] No sensitive data in logs

### Senzing-Specific

- [ ] Native library dependencies properly configured
- [ ] Environment variables documented
- [ ] Follows template repository structure
- [ ] Build succeeds with standard commands
- [ ] Compatible with Senzing v4.0+

---

## Pre-Commit Commands by Language

Run these before creating a PR:

**Python:**

```bash
black .
pylint your_module/
mypy your_module/
pytest
```

**Java:**

```bash
mvn checkstyle:check
mvn test
```

**Go:**

```bash
gofmt -w .
goimports -w .
go vet ./...
go test ./...
```

**C#:**

```bash
dotnet format Senzing.Sdk
dotnet format Senzing.Sdk.Tests
dotnet test Senzing.Sdk.Tests
```

**Node.js:**

```bash
npm run lint -- --fix
npm run format
npm test
```

---

## Environment Setup

All SDK projects require Senzing native libraries. Set these before building:

**Linux:**

```bash
export SENZING_PATH=/opt/senzing
export LD_LIBRARY_PATH=/opt/senzing/er/lib:$LD_LIBRARY_PATH
```

**macOS:**

```bash
export SENZING_PATH=$HOME/senzing
export DYLD_LIBRARY_PATH=$HOME/senzing/er/lib:$HOME/senzing/er/lib/macos:$DYLD_LIBRARY_PATH
```

**Windows:**

```cmd
set SENZING_PATH=%USERPROFILE%\senzing
set Path=%USERPROFILE%\senzing\er\lib;%Path%
```

---

## Reference Links

- **Python Template**: https://github.com/senzing-garage/template-python
- **Go Template**: https://github.com/senzing-garage/template-go
- **Java SDK**: https://github.com/senzing-garage/sz-sdk-java
- **C# SDK**: https://github.com/senzing-garage/sz-sdk-csharp
- **Quick Start Guides**: https://docs.senzing.com/quickstart/
- **PEP-0008**: https://peps.python.org/pep-0008/
- **Effective Go**: https://go.dev/doc/effective_go

---

## Common Issues

### Java

- ❌ Most Checkstyle rules are suppressed → Focus on naming conventions and Javadoc
- ❌ Star imports allowed → `import java.util.*` is acceptable
- ❌ No line length enforcement → But keep reasonable (suggest < 120 chars)
- ❌ Magic numbers allowed → But named constants still preferred for readability

### C#

- ❌ `dotnet format` fails → Run `dotnet format` to auto-fix
- ❌ Missing XML docs → Add `///` comments for public APIs
- ❌ Wrong brace style → Use Allman style (brace on new line)
- ❌ Using `var` → Use explicit types (`string`, `int`, etc.)
- ❌ Missing `_` on private fields → Prefix with underscore (`_myField`)
- ❌ Using `this.` unnecessarily → Remove `this.` qualifier
- ❌ Style warnings are errors → Must fix all style issues to build

### Go

- ❌ Not using `gofmt` → **ALWAYS run `gofmt` before committing**
- ❌ Spaces instead of tabs → Let `gofmt` handle it
- ❌ Verbose error handling → Use standard Go patterns

### Python

- ❌ Not PEP-8 compliant → Run `black` formatter
- ❌ Missing type hints → Add type annotations
- ❌ Lines too long → Refactor or use line continuations

### All Languages

- ❌ Hardcoded paths → Use environment variables
- ❌ Commented code → Remove it (it's in git history)
- ❌ Missing tests → Add unit and integration tests
