# Filesystem layout proposal 1

```console
/
├── etc
│   └── opt
│       └── senzing
│           ├── cfgVariant.json
│           ├── customGn.txt
│           ├── customOn.txt
│           ├── customSn.txt
│           ├── defaultGNRCP.config
│           └── stb.config
├── opt
│   └── senzing
│       ├── data
│       │   ├── LICENSE
│       │   ├── angloOnRegRule.ibm
│       │   ├── angloRegRule.ibm
│       │   ├── anyTransRule.ibm
│       │   ├── arabicTransRule.ibm
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
│       │   ├── libpostal
│       │   │   ├── address_expansions
│       │   │   │   └── address_dictionary.dat
│       │   │   ├── address_parser
│       │   │   │   ├── address_parser_crf.dat
│       │   │   │   ├── address_parser_phrases.dat
│       │   │   │   ├── address_parser_postal_codes.dat
│       │   │   │   └── address_parser_vocab.trie
│       │   │   ├── base_data_file_version
│       │   │   ├── data_version
│       │   │   ├── language_classifier
│       │   │   │   └── language_classifier.dat
│       │   │   ├── language_classifier_model_file_version
│       │   │   ├── numex
│       │   │   │   └── numex.dat
│       │   │   ├── parser_model_file_version
│       │   │   └── transliteration
│       │   │       └── transliteration.dat
│       │   ├── onv.ibm
│       │   ├── polishOnRegRule.ibm
│       │   ├── polishRegRule.ibm
│       │   ├── portugueseOnRegRule.ibm
│       │   ├── portugueseRegRule.ibm
│       │   ├── russianOnRegRule.ibm
│       │   ├── russianRegRule.ibm
│       │   ├── snv.ibm
│       │   ├── swasianRegRule.ibm
│       │   ├── taq.ibm
│       │   ├── terms.ibm
│       │   └── thaiRegRule.ibm
│       └── g2
│           ├── LICENSE
│           ├── NOTICES
│           ├── README.1ST
│           ├── g2BuildVersion.json
│           ├── lib
│           │   ├── g2.jar
│           │   ├── libG2.so
│           │   ├── libG2Hasher.so
│           │   ├── libNameDataObject.so
│           │   ├── libSpaceTimeBoxStandardizer.so
│           │   ├── libanalytics.so
│           │   ├── libboost_atomic.so
│           │   ├── libboost_atomic.so.1.78.0
│           │   ├── libboost_chrono.so
│           │   ├── libboost_chrono.so.1.78.0
│           │   ├── libboost_container.so
│           │   ├── libboost_container.so.1.78.0
│           │   ├── libboost_context.so
│           │   ├── libboost_context.so.1.78.0
│           │   ├── libboost_contract.so
│           │   ├── libboost_contract.so.1.78.0
│           │   ├── libboost_coroutine.so
│           │   ├── libboost_coroutine.so.1.78.0
│           │   ├── libboost_date_time.so
│           │   ├── libboost_date_time.so.1.78.0
│           │   ├── libboost_filesystem.so
│           │   ├── libboost_filesystem.so.1.78.0
│           │   ├── libboost_graph.so
│           │   ├── libboost_graph.so.1.78.0
│           │   ├── libboost_iostreams.so
│           │   ├── libboost_iostreams.so.1.78.0
│           │   ├── libboost_json.so
│           │   ├── libboost_json.so.1.78.0
│           │   ├── libboost_locale.so
│           │   ├── libboost_locale.so.1.78.0
│           │   ├── libboost_log.so
│           │   ├── libboost_log.so.1.78.0
│           │   ├── libboost_log_setup.so
│           │   ├── libboost_log_setup.so.1.78.0
│           │   ├── libboost_math_c99.so
│           │   ├── libboost_math_c99.so.1.78.0
│           │   ├── libboost_math_c99f.so
│           │   ├── libboost_math_c99f.so.1.78.0
│           │   ├── libboost_math_c99l.so
│           │   ├── libboost_math_c99l.so.1.78.0
│           │   ├── libboost_math_tr1.so
│           │   ├── libboost_math_tr1.so.1.78.0
│           │   ├── libboost_math_tr1f.so
│           │   ├── libboost_math_tr1f.so.1.78.0
│           │   ├── libboost_math_tr1l.so
│           │   ├── libboost_math_tr1l.so.1.78.0
│           │   ├── libboost_nowide.so
│           │   ├── libboost_nowide.so.1.78.0
│           │   ├── libboost_prg_exec_monitor.so
│           │   ├── libboost_prg_exec_monitor.so.1.78.0
│           │   ├── libboost_program_options.so
│           │   ├── libboost_program_options.so.1.78.0
│           │   ├── libboost_python39.so
│           │   ├── libboost_python39.so.1.78.0
│           │   ├── libboost_random.so
│           │   ├── libboost_random.so.1.78.0
│           │   ├── libboost_regex.so
│           │   ├── libboost_regex.so.1.78.0
│           │   ├── libboost_serialization.so
│           │   ├── libboost_serialization.so.1.78.0
│           │   ├── libboost_system.so
│           │   ├── libboost_system.so.1.78.0
│           │   ├── libboost_thread.so
│           │   ├── libboost_thread.so.1.78.0
│           │   ├── libboost_timer.so
│           │   ├── libboost_timer.so.1.78.0
│           │   ├── libboost_type_erasure.so
│           │   ├── libboost_type_erasure.so.1.78.0
│           │   ├── libboost_wave.so
│           │   ├── libboost_wave.so.1.78.0
│           │   ├── libboost_wserialization.so
│           │   ├── libboost_wserialization.so.1.78.0
│           │   ├── libdb2plugin.so
│           │   ├── libeaexml2.so
│           │   ├── libeaexml2.so.2
│           │   ├── libeaexml2.so.2.9.12
│           │   ├── libg2AddressComp.so
│           │   ├── libg2AddressHasher.so
│           │   ├── libg2CloseNames.so
│           │   ├── libg2CompJavaScoreSet.so
│           │   ├── libg2ConfigParseAddr.so
│           │   ├── libg2DLComp.so
│           │   ├── libg2DateComp.so
│           │   ├── libg2DistinctFeatJava.so
│           │   ├── libg2EFeatJava.so
│           │   ├── libg2EmailComp.so
│           │   ├── libg2ExactDomainMatchComp.so
│           │   ├── libg2ExactMatchComp.so
│           │   ├── libg2FeatBuilder.so
│           │   ├── libg2FormatSSN.so
│           │   ├── libg2GEOLOCComp.so
│           │   ├── libg2GNRNameComp.so
│           │   ├── libg2GenericHasher.so
│           │   ├── libg2GroupAssociationComp.so
│           │   ├── libg2IDHasher.so
│           │   ├── libg2JVMPlugin.so
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
│           │   ├── libg2StdJava.so
│           │   ├── libg2StdTokenizeName.so
│           │   ├── libg2StrictSubsetFelems.so
│           │   ├── libg2StrictSubsetNormalizedFelems.so
│           │   ├── libg2StrictSubsetTokens.so
│           │   ├── libg2StringComp.so
│           │   ├── libicudata.so
│           │   ├── libicudata.so.70
│           │   ├── libicudata.so.70.1
│           │   ├── libicui18n.so
│           │   ├── libicui18n.so.70
│           │   ├── libicui18n.so.70.1
│           │   ├── libicuio.so
│           │   ├── libicuio.so.70
│           │   ├── libicuio.so.70.1
│           │   ├── libicutest.so
│           │   ├── libicutest.so.70
│           │   ├── libicutest.so.70.1
│           │   ├── libicutu.so
│           │   ├── libicutu.so.70
│           │   ├── libicutu.so.70.1
│           │   ├── libicuuc.so
│           │   ├── libicuuc.so.70
│           │   ├── libicuuc.so.70.1
│           │   ├── libmariadbplugin.so
│           │   ├── libmssqlplugin.so
│           │   ├── liboracleplugin.so
│           │   ├── libpostal.so
│           │   ├── libpostal.so.1
│           │   ├── libpostal.so.1.0.1
│           │   ├── libpostgresqlplugin.so
│           │   ├── libscoring.so
│           │   └── libsqliteplugin.so
│           ├── resources
│           │   └── templates
│           │       ├── g2config.json
│           └── sdk
│               ├── java
│               │   └── README.txt
│               └── python
│                   └── senzing
│                       ├── G2Config.py
│                       ├── G2ConfigMgr.py
│                       ├── G2Diagnostic.py
│                       ├── G2Engine.py
│                       ├── G2EngineFlags.py
│                       ├── G2Exception.py
│                       ├── G2Hasher.py
│                       ├── G2Product.py
│                       └── __init__.py
```
