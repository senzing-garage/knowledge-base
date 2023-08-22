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
