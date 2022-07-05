# Filesystem layout proposal 1

```console
/
├── opt
│   └── senzing
│       └── g2
│           ├── python
│           │   ├── CompressedFile.py
│           │   ├── DumpStack.py
│           │   ├── G2Audit.py
│           │   ├── G2Command.py
│           │   ├── G2ConfigTables.py
│           │   ├── G2ConfigTool.py
│           │   ├── G2ConfigTool.readme
│           │   ├── G2CreateProject.py
│           │   ├── G2Database.py
│           │   ├── G2Explorer.py
│           │   ├── G2Export.py
│           │   ├── G2Loader.py
│           │   ├── G2Paths.py
│           │   ├── G2Project.py
│           │   ├── G2S3.py
│           │   ├── G2SetupConfig.py
│           │   ├── G2Snapshot.py
│           │   ├── G2UpdateProject.py
│           │   ├── SenzingGo.py
│           │   ├── demo
│           │   │   ├── sample
│           │   │   │   ├── project.csv
│           │   │   │   ├── project.json
│           │   │   │   ├── sample_company.csv
│           │   │   │   ├── sample_company.json
│           │   │   │   ├── sample_person.csv
│           │   │   │   └── sample_person.json
│           │   │   └── truth
│           │   │       ├── customers.csv
│           │   │       ├── customers.json
│           │   │       ├── reference.csv
│           │   │       ├── reference.json
│           │   │       ├── truthset-config.g2c
│           │   │       ├── truthset-load1-key.csv
│           │   │       ├── truthset-load1.sh
│           │   │       ├── truthset-load2-key.csv
│           │   │       ├── truthset-load2.sh
│           │   │       ├── truthset-load3-key.csv
│           │   │       ├── truthset-load3.sh
│           │   │       ├── truthset-project1.json
│           │   │       ├── truthset-project2.json
│           │   │       ├── truthset-project3.json
│           │   │       ├── watchlist.csv
│           │   │       └── watchlist.json
│           │   ├── governor_postgres_xid.py
│           │   ├── senzing
│           │   │   ├── G2Config.py
│           │   │   ├── G2ConfigMgr.py
│           │   │   ├── G2Diagnostic.py
│           │   │   ├── G2Engine.py
│           │   │   ├── G2EngineFlags.py
│           │   │   ├── G2Exception.py
│           │   │   ├── G2Hasher.py
│           │   │   ├── G2IniParams.py
│           │   │   ├── G2Product.py
│           │   │   └── __init__.py
│           │   └── senzing_governor.py
```
