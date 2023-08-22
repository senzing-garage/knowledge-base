# What is Senzing system installation


## Linux

"Senzing System Installation" as seen in the `senzing/senzingapi-runtime` Docker image.
**Note:** This is an abbreviated representation.

```console
/
├── etc
│   └── opt
│       └── senzing
│           ├── cfgVariant.json
│           ├── ...
│           └── stb.config
└── opt
    └── senzing
        ├── data
        │   ├── angloOnRegRule.ibm
        │   ├── ...
        │   ├── thaiRegRule.ibm
        │   └── libpostal
        └── g2
            ├── g2BuildVersion.json
            ├── lib
            │   ├── libG2.so
            │   ├── ...
            │   └── libsqliteplugin.so
            ├── resources
            │   └── templates
            │       └── config.json
            └── sdk
                ├── c
                ├── java
                └── python
```

## macOS

**Note:** This is an abbreviated representation.

```console
/
└── opt
    └── senzing
        └── g2
            ├── g2BuildVersion.json
            ├── bin
            ├── data
            │   ├── angloOnRegRule.ibm
            │   ├── ...
            │   ├── thaiRegRule.ibm
            │   └── libpostal
            ├── etc
            │   ├── cfgVariant.json
            │   ├── ...
            │   └── stb.config
            ├── lib
            │   ├── libG2.so
            │   ├── ...
            │   ├── libsqliteplugin.so
            │   └── macos
            │       ├── libcrypto-univ.1.1.dylib
            │       ├── ...
            │       └── libssl.dylib
            ├── resources
            │   ├── config
            │   │   └── g2core-configuration-upgrade-X-to-Y.gtc
            │   ├── schema
            │   │   ├── g2core-schema-postgresql-create.sql
            │   │   ├── ...
            │   │   └── g2core-schema-sqlite-create.sql
            │   └── templates
            │       ├── G2C.db
            │       ├── ...
            │       └── stb.config
            ├── sdk
            │   ├── c
            │   ├── java
            │   └── python
            └── var
                └── sqldb
                    └── G2C.db

```
