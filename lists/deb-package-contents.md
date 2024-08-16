# deb package contents

The following shows the contents of the
`senzingapi-poc`,
`senzingapi-runtime`,
`senzingapi-setup`, and
`senzingapi-tools`
packages.

## Dependency tree

```console
└── senzingapi-runtime
    └── senzingapi-tools
        └── senzingapi-setup
            └── senzingapi-poc
```

## Directory structures

### senzingapi-poc

```console
├── DEBIAN
│   ├── control
│   ├── md5sums
│   └── preinst
├── opt
│   └── senzing
│       └── er
│           ├── bin
│           │   ├── sz_create_project.py
│           │   └── sz_setup_config.py
│           ├── python
│           │   ├── demo
│           │   └── senzing
│           └── resources
│               └── templates
│                   ├── G2C.db
│                   ├── G2C.db.template
│                   ├── G2Module.ini
│                   └── setupEnv
└── usr
    └── share
        └── doc
            └── senzingapi-poc
                └── changelog.gz
```

### senzingapi-runtime

```console
├── DEBIAN
│   ├── control
│   ├── md5sums
│   └── preinst
├── etc
│   └── opt
│       └── senzing
│           ├── cfgVariant.json
│           ├── customGn.txt
│           ├── customOn.txt
│           ├── customSn.txt
│           ├── defaultGNRCP.config
│           └── g2config.json
├── opt
│   └── senzing
│       ├── data
│       │   ├── address_datamodel
│       │   │   ├── address_expansions
│       │   │   │   └── address_dictionary.dat.gz
│       │   │   ├── address_parser
│       │   │   │   ├── address_parser_crf.dat.gz
│       │   │   │   ├── address_parser_phrases.dat.gz
│       │   │   │   ├── address_parser_postal_codes.dat.gz
│       │   │   │   └── address_parser_vocab.trie.gz
│       │   │   ├── language_classifier
│       │   │   │   └── language_classifier.dat.gz
│       │   │   ├── numex
│       │   │   │   └── numex.dat.gz
│       │   │   └── transliteration
│       │   │       └── transliteration.dat.gz
│       │   ├── angloOnRegRule.ibm
│       │   ├── angloRegRule.ibm
│       │   ├── anyTransRule.ibm
│       │   ├── arabicTransRule.ibm
│       │   ├── burmeseClassifier.sz
│       │   ├── burmeseGn.sz
│       │   ├── burmeseOn.sz
│       │   ├── burmeseRegRules.sz
│       │   ├── burmeseSn.sz
│       │   ├── burmeseTransRules.sz
│       │   ├── chineseNativeOnRegRule.ibm
│       │   ├── chineseOnRegRule.ibm
│       │   ├── chineseOnTransRule.ibm
│       │   ├── chineseRegRule.ibm
│       │   ├── chineseTransRule.ibm
│       │   ├── cnv.ibm
│       │   ├── conv.ibm
│       │   ├── ctaq.ibm
│       │   ├── cyrillicOnTransRule.ibm
│       │   ├── cyrillicTransRule.ibm
│       │   ├── eastSlavicOnRegRule.ibm
│       │   ├── eastSlavicRegRule.ibm
│       │   ├── farsiRegRule.ibm
│       │   ├── flemish_germanRegRule.ibm
│       │   ├── frenchRegRule.ibm
│       │   ├── g2SifterRules.ibm
│       │   ├── genericOnRegRule.ibm
│       │   ├── genericRegRule.ibm
│       │   ├── germanRegRule.ibm
│       │   ├── gnv.ibm
│       │   ├── greekTransRule.ibm
│       │   ├── hindiOnTransRule.ibm
│       │   ├── hindiTransRule.ibm
│       │   ├── hispanicOnRegRule.ibm
│       │   ├── hispanicRegRule.ibm
│       │   ├── indianRegRule.ibm
│       │   ├── indoRegRule.ibm
│       │   ├── japaneseNativeOnRegRule.ibm
│       │   ├── japaneseOnTransRule.ibm
│       │   ├── japaneseRegRule.ibm
│       │   ├── japaneseTransRule.ibm
│       │   ├── khmerClassifier.sz
│       │   ├── khmerGn.sz
│       │   ├── khmerRegRules.sz
│       │   ├── khmerSn.sz
│       │   ├── khmerTransRules.sz
│       │   ├── koreanOnRegRule.ibm
│       │   ├── koreanOnTransRule.ibm
│       │   ├── koreanRegRule.ibm
│       │   ├── koreanTransRule.ibm
│       │   ├── latinTransRule.ibm
│       │   ├── mapping-templates
│       │   │   └── default-templates.tpl
│       │   ├── onv.ibm
│       │   ├── polishOnRegRule.ibm
│       │   ├── polishRegRule.ibm
│       │   ├── portugueseOnRegRule.ibm
│       │   ├── portugueseRegRule.ibm
│       │   ├── snv.ibm
│       │   ├── swasianRegRule.ibm
│       │   ├── szBuildVersion.json
│       │   ├── taq.ibm
│       │   ├── terms.ibm
│       │   ├── thaiRegRule.ibm
│       │   └── thaiTransRules.sz
│       └── er
│           ├── lib
│           │   ├── libanalytics.so
│           │   ├── libdb2plugin.so
│           │   ├── libeaexml2.so.2
│           │   ├── libg2AddressComp.so
│           │   ├── libg2AddressHasher.so
│           │   ├── libg2CloseNames.so
│           │   ├── libg2ConfigParseAddr.so
│           │   ├── libg2DateComp.so
│           │   ├── libg2DLComp.so
│           │   ├── libg2EmailComp.so
│           │   ├── libg2ExactDomainMatchComp.so
│           │   ├── libg2ExactMatchComp.so
│           │   ├── libg2FeatBuilder.so
│           │   ├── libg2FormatSSN.so
│           │   ├── libg2GenericHasher.so
│           │   ├── libg2GEOLOCComp.so
│           │   ├── libg2GNRNameComp.so
│           │   ├── libg2GroupAssociationComp.so
│           │   ├── libg2IDHasher.so
│           │   ├── libg2NameHasher.so
│           │   ├── libg2ParseDOB.so
│           │   ├── libg2ParseEmail.so
│           │   ├── libg2ParseGEOLOC.so
│           │   ├── libg2ParseID.so
│           │   ├── libg2ParseName.so
│           │   ├── libg2ParsePhone.so
│           │   ├── libg2PartialAddresses.so
│           │   ├── libg2PartialDates.so
│           │   ├── libg2PartialNames.so
│           │   ├── libg2PhoneComp.so
│           │   ├── libg2PhoneHasher.so
│           │   ├── libg2SSNComp.so
│           │   ├── libg2STBHasher.so
│           │   ├── libg2StdCountry.so
│           │   ├── libg2StdTokenizeName.so
│           │   ├── libg2StrictSubsetFelems.so
│           │   ├── libg2StrictSubsetNormalizedFelems.so
│           │   ├── libg2StrictSubsetTokens.so
│           │   ├── libg2StringComp.so
│           │   ├── libicudataSz.so.70
│           │   ├── libicui18nSz.so.70
│           │   ├── libicuioSz.so.70
│           │   ├── libicutuSz.so.70
│           │   ├── libicuucSz.so.70
│           │   ├── libmssqlplugin.so
│           │   ├── libmysqldbplugin.so
│           │   ├── libNameDataObject.so
│           │   ├── liboracleplugin.so
│           │   ├── libpostgresqlplugin.so
│           │   ├── libscoring.so
│           │   ├── libSpaceTimeBoxStandardizer.so
│           │   ├── libsqliteplugin.so
│           │   ├── libSz.so
│           │   └── sz-sdk.jar
│           ├── LICENSE
│           ├── NOTICES
│           ├── README.1ST
│           ├── resources
│           │   └── templates
│           │       ├── cfgVariant.json
│           │       ├── customGn.txt
│           │       ├── customOn.txt
│           │       ├── customSn.txt
│           │       ├── defaultGNRCP.config
│           │       └── g2config.json
│           ├── sdk
│           │   ├── c
│           │   │   ├── gohelpers
│           │   │   │   └── Szlang_helpers.h
│           │   │   ├── libSzconfig.h
│           │   │   ├── libSzconfigmgr.h
│           │   │   ├── libSzdiagnostic.h
│           │   │   ├── libSz.h
│           │   │   └── libSzproduct.h
│           │   ├── java
│           │   │   └── README.TXT
│           │   └── python
│           │       ├── senzing
│           │       │   ├── _helpers.py
│           │       │   ├── __init__.py
│           │       │   ├── py.typed
│           │       │   ├── szconfigmanager.py
│           │       │   ├── szconfig.py
│           │       │   ├── szdiagnostic.py
│           │       │   ├── szengine.py
│           │       │   ├── szproduct.py
│           │       │   └── _version.py
│           │       └── senzing_abstract
│           │           ├── constants.py
│           │           ├── __init__.py
│           │           ├── observer_abstract.py
│           │           ├── py.typed
│           │           ├── szconfig_abstract.py
│           │           ├── szconfigmanager_abstract.py
│           │           ├── szdiagnostic_abstract.py
│           │           ├── szengine_abstract.py
│           │           ├── szengineflags.py
│           │           ├── szerror.py
│           │           └── szproduct_abstract.py
│           └── szBuildVersion.json
└── usr
    └── share
        └── doc
            └── senzingapi-runtime
                └── changelog.gz
```

## senzingapi-setup

```console
├── DEBIAN
│   ├── control
│   ├── md5sums
│   └── preinst
├── opt
│   └── senzing
│       └── er
│           ├── bin
│           │   ├── szconfigupgrade
│           │   └── szdbupgrade
│           └── resources
│               ├── config
│               └── schema
│                   ├── szcore-schema-mssql-create.sql
│                   ├── szcore-schema-mysql-create.sql
│                   ├── szcore-schema-oracle-create.sql
│                   ├── szcore-schema-postgresql-create.sql
│                   └── szcore-schema-sqlite-create.sql
└── usr
    └── share
        └── doc
            └── senzingapi-setup
                └── changelog.gz
```

### senzingapi-tools

```console
├── DEBIAN
│   ├── control
│   ├── md5sums
│   └── preinst
├── opt
│   └── senzing
│       └── er
│           └── bin
│               ├── reset
│               ├── sz_command.py
│               ├── sz_configtool.py
│               ├── sz_database.py
│               ├── sz_explorer.py
│               ├── szsaltadm
│               ├── sz_snapshot.py
│               ├── szssadm
│               └── _tool_helpers.py
└── usr
    └── share
        └── doc
            └── senzingapi-tools
                └── changelog.gz
```

## How to create directory lists

1. Download packages.

    ```console
    export SENZING_DEB_FILES=~/senzing-deb-files
    mkdir ${SENZING_DEB_FILES}
    sudo docker run \
    --rm \
    --volume ${SENZING_DEB_FILES}:/download \
    senzing/aptdownloader-staging senzingapi-poc senzingapi-runtime senzingapi-setup senzingapi-tools

    ```

1. Extract packages.

    ```console
    export SENZING_DEB_FILES_EXTRACTED=${SENZING_DEB_FILES}/extracted
    mkdir ${SENZING_DEB_FILES_EXTRACTED}
    dpkg-deb -R ${SENZING_DEB_FILES}/senzingapi-poc_*.deb ${SENZING_DEB_FILES_EXTRACTED}/poc
    dpkg-deb -R ${SENZING_DEB_FILES}/senzingapi-runtime_*.deb ${SENZING_DEB_FILES_EXTRACTED}/runtime
    dpkg-deb -R ${SENZING_DEB_FILES}/senzingapi-setup_*.deb ${SENZING_DEB_FILES_EXTRACTED}/setup
    dpkg-deb -R ${SENZING_DEB_FILES}/senzingapi-tools_*.deb ${SENZING_DEB_FILES_EXTRACTED}/tools

    ```

1. Print contents of packages.

    ```console
    tree ${SENZING_DEB_FILES_EXTRACTED}/poc
    tree ${SENZING_DEB_FILES_EXTRACTED}/runtime
    tree ${SENZING_DEB_FILES_EXTRACTED}/setup
    tree ${SENZING_DEB_FILES_EXTRACTED}/tools

    ```
