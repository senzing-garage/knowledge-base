# Filesystem layout in Senzing 3.0.0

```console
/
├── etc
│   └── opt
│       └── senzing
│           ├── G2Config.gtc
│           ├── G2Module.ini
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
│       │   ├── current -> /etc/alternatives/senzingdata
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
│           ├── bin
│           │   ├── g2configupgrade
│           │   ├── g2dbencrypt
│           │   ├── g2dbupgrade
│           │   ├── g2saltadm
│           │   └── g2ssadm
│           ├── g2BuildVersion.json
│           ├── lib
│           │   ├── g2.jar
│           │   ├── g2rst.jar
│           │   ├── jdk-11.0.10+9-jre
│           │   │   ├── bin
│           │   │   │   ├── jaotc
│           │   │   │   ├── java
│           │   │   │   ├── jfr
│           │   │   │   ├── jjs
│           │   │   │   ├── jrunscript
│           │   │   │   ├── keytool
│           │   │   │   ├── pack200
│           │   │   │   ├── rmid
│           │   │   │   ├── rmiregistry
│           │   │   │   └── unpack200
│           │   │   ├── conf
│           │   │   │   ├── logging.properties
│           │   │   │   ├── management
│           │   │   │   │   ├── jmxremote.access
│           │   │   │   │   ├── jmxremote.password.template
│           │   │   │   │   └── management.properties
│           │   │   │   ├── net.properties
│           │   │   │   ├── security
│           │   │   │   │   ├── java.policy
│           │   │   │   │   ├── java.security
│           │   │   │   │   └── policy
│           │   │   │   │       ├── README.txt
│           │   │   │   │       ├── limited
│           │   │   │   │       │   ├── default_US_export.policy
│           │   │   │   │       │   ├── default_local.policy
│           │   │   │   │       │   └── exempt_local.policy
│           │   │   │   │       └── unlimited
│           │   │   │   │           ├── default_US_export.policy
│           │   │   │   │           └── default_local.policy
│           │   │   │   └── sound.properties
│           │   │   ├── legal
│           │   │   │   ├── java.base
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE
│           │   │   │   │   ├── aes.md
│           │   │   │   │   ├── asm.md
│           │   │   │   │   ├── c-libutl.md
│           │   │   │   │   ├── cldr.md
│           │   │   │   │   ├── icu.md
│           │   │   │   │   ├── public_suffix.md
│           │   │   │   │   └── unicode.md
│           │   │   │   ├── java.compiler
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.datatransfer
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.desktop
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   ├── colorimaging.md
│           │   │   │   │   ├── giflib.md
│           │   │   │   │   ├── harfbuzz.md
│           │   │   │   │   ├── jpeg.md
│           │   │   │   │   ├── lcms.md
│           │   │   │   │   ├── libpng.md
│           │   │   │   │   ├── mesa3d.md
│           │   │   │   │   └── xwd.md
│           │   │   │   ├── java.instrument
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.logging
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.management
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.management.rmi
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.naming
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.net.http
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.prefs
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.rmi
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.scripting
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.se
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.security.jgss
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.security.sasl
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.smartcardio
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   └── pcsclite.md
│           │   │   │   ├── java.sql
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.sql.rowset
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.transaction.xa
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── java.xml
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   ├── bcel.md
│           │   │   │   │   ├── dom.md
│           │   │   │   │   ├── jcup.md
│           │   │   │   │   ├── xalan.md
│           │   │   │   │   └── xerces.md
│           │   │   │   ├── java.xml.crypto
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   └── santuario.md
│           │   │   │   ├── jdk.accessibility
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.aot
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.charsets
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.crypto.cryptoki
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   ├── pkcs11cryptotoken.md
│           │   │   │   │   └── pkcs11wrapper.md
│           │   │   │   ├── jdk.crypto.ec
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   └── ecc.md
│           │   │   │   ├── jdk.dynalink
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   └── dynalink.md
│           │   │   │   ├── jdk.httpserver
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.internal.ed
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.internal.le
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   └── jline.md
│           │   │   │   ├── jdk.internal.vm.ci
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.internal.vm.compiler
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.internal.vm.compiler.management
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.jdwp.agent
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.jfr
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.jsobject
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.localedata
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   ├── cldr.md -> ../java.base/cldr.md
│           │   │   │   │   └── thaidict.md
│           │   │   │   ├── jdk.management
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.management.agent
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.management.jfr
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.naming.dns
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.naming.ldap
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.naming.rmi
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.net
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.pack
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.scripting.nashorn
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   ├── LICENSE -> ../java.base/LICENSE
│           │   │   │   │   ├── double-conversion.md
│           │   │   │   │   └── joni.md
│           │   │   │   ├── jdk.scripting.nashorn.shell
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.sctp
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.security.auth
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.security.jgss
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.unsupported
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   ├── jdk.xml.dom
│           │   │   │   │   ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │   │   ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │   │   └── LICENSE -> ../java.base/LICENSE
│           │   │   │   └── jdk.zipfs
│           │   │   │       ├── ADDITIONAL_LICENSE_INFO -> ../java.base/ADDITIONAL_LICENSE_INFO
│           │   │   │       ├── ASSEMBLY_EXCEPTION -> ../java.base/ASSEMBLY_EXCEPTION
│           │   │   │       └── LICENSE -> ../java.base/LICENSE
│           │   │   ├── lib
│           │   │   │   ├── classlist
│           │   │   │   ├── jexec
│           │   │   │   ├── jfr
│           │   │   │   │   ├── default.jfc
│           │   │   │   │   └── profile.jfc
│           │   │   │   ├── jli
│           │   │   │   │   └── libjli.so
│           │   │   │   ├── jrt-fs.jar
│           │   │   │   ├── jspawnhelper
│           │   │   │   ├── jvm.cfg
│           │   │   │   ├── libawt.so
│           │   │   │   ├── libawt_headless.so
│           │   │   │   ├── libawt_xawt.so
│           │   │   │   ├── libdt_socket.so
│           │   │   │   ├── libextnet.so
│           │   │   │   ├── libfontmanager.so
│           │   │   │   ├── libharfbuzz.so
│           │   │   │   ├── libinstrument.so
│           │   │   │   ├── libj2gss.so
│           │   │   │   ├── libj2pcsc.so
│           │   │   │   ├── libj2pkcs11.so
│           │   │   │   ├── libjaas.so
│           │   │   │   ├── libjava.so
│           │   │   │   ├── libjavajpeg.so
│           │   │   │   ├── libjawt.so
│           │   │   │   ├── libjdwp.so
│           │   │   │   ├── libjimage.so
│           │   │   │   ├── libjsig.so
│           │   │   │   ├── libjsound.so
│           │   │   │   ├── liblcms.so
│           │   │   │   ├── libmanagement.so
│           │   │   │   ├── libmanagement_agent.so
│           │   │   │   ├── libmanagement_ext.so
│           │   │   │   ├── libmlib_image.so
│           │   │   │   ├── libnet.so
│           │   │   │   ├── libnio.so
│           │   │   │   ├── libprefs.so
│           │   │   │   ├── librmi.so
│           │   │   │   ├── libsctp.so
│           │   │   │   ├── libsplashscreen.so
│           │   │   │   ├── libsunec.so
│           │   │   │   ├── libunpack.so
│           │   │   │   ├── libverify.so
│           │   │   │   ├── libzip.so
│           │   │   │   ├── modules
│           │   │   │   ├── psfont.properties.ja
│           │   │   │   ├── psfontj2d.properties
│           │   │   │   ├── security
│           │   │   │   │   ├── blacklisted.certs
│           │   │   │   │   ├── cacerts
│           │   │   │   │   ├── default.policy
│           │   │   │   │   └── public_suffix_list.dat
│           │   │   │   ├── server
│           │   │   │   │   ├── Xusage.txt
│           │   │   │   │   ├── libjsig.so
│           │   │   │   │   └── libjvm.so
│           │   │   │   └── tzdb.dat
│           │   │   ├── man
│           │   │   │   ├── ja -> ja_JP.UTF-8
│           │   │   │   ├── ja_JP.UTF-8
│           │   │   │   │   └── man1
│           │   │   │   │       ├── java.1
│           │   │   │   │       ├── jjs.1
│           │   │   │   │       ├── keytool.1
│           │   │   │   │       ├── pack200.1
│           │   │   │   │       ├── rmid.1
│           │   │   │   │       ├── rmiregistry.1
│           │   │   │   │       └── unpack200.1
│           │   │   │   └── man1
│           │   │   │       ├── java.1
│           │   │   │       ├── jjs.1
│           │   │   │       ├── keytool.1
│           │   │   │       ├── pack200.1
│           │   │   │       ├── rmid.1
│           │   │   │       ├── rmiregistry.1
│           │   │   │       └── unpack200.1
│           │   │   └── release
│           │   ├── jre -> jdk-11.0.10+9-jre
│           │   ├── libG2.so
│           │   ├── libG2Hasher.so
│           │   ├── libG2SSAdm.so
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
│           ├── resources
│           │   ├── config
│           │   │   ├── g2core-configuration-upgrade-3-to-3.1.gtc
│           │   │   ├── g2core-configuration-upgrade-3-to-4.gtc
│           │   │   ├── g2core-configuration-upgrade-3.1-to-4.1.gtc
│           │   │   ├── g2core-configuration-upgrade-4-to-4.1.gtc
│           │   │   ├── g2core-configuration-upgrade-4.1-to-5.gtc
│           │   │   ├── g2core-configuration-upgrade-5-to-6.gtc
│           │   │   ├── g2core-configuration-upgrade-6-to-7.gtc
│           │   │   ├── g2core-configuration-upgrade-7-to-8.gtc
│           │   │   ├── g2core-configuration-upgrade-8-to-9.gtc
│           │   │   ├── g2core-configuration-upgrade-9-to-9.1.gtc
│           │   │   └── g2core-configuration-upgrade-9.1-to-10.gtc
│           │   ├── schema
│           │   │   ├── g2core-schema-db2-create.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.1-to-1.2.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.10-to-1.11.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.11-to-1.12.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.12-to-1.13.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.13-to-1.14.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.14-to-1.14.2.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.14-to-1.15.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.14.2-to-1.15.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.15-to-2.0.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.2-to-1.3.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.3-to-1.4.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.8-to-1.9.sql
│           │   │   ├── g2core-schema-db2-upgrade-1.9-to-1.10.sql
│           │   │   ├── g2core-schema-db2-upgrade-2.0-to-3.0.sql
│           │   │   ├── g2core-schema-mssql-create.sql
│           │   │   ├── g2core-schema-mssql-upgrade-1.13-to-1.14.sql
│           │   │   ├── g2core-schema-mssql-upgrade-1.14-to-1.14.2.sql
│           │   │   ├── g2core-schema-mssql-upgrade-1.14-to-1.15.sql
│           │   │   ├── g2core-schema-mssql-upgrade-1.14.2-to-1.15.sql
│           │   │   ├── g2core-schema-mssql-upgrade-1.15-to-2.0.sql
│           │   │   ├── g2core-schema-mssql-upgrade-2.0-to-3.0.sql
│           │   │   ├── g2core-schema-mysql-create.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.1-to-1.2.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.10-to-1.11.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.11-to-1.12.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.12-to-1.13.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.13-to-1.14.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.14-to-1.14.2.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.14-to-1.15.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.14.2-to-1.15.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.15-to-2.0.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.2-to-1.3.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.3-to-1.4.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.8-to-1.9.sql
│           │   │   ├── g2core-schema-mysql-upgrade-1.9-to-1.10.sql
│           │   │   ├── g2core-schema-mysql-upgrade-2.0-to-3.0.sql
│           │   │   ├── g2core-schema-oracle-create.sql
│           │   │   ├── g2core-schema-postgresql-create.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.10-to-1.11.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.11-to-1.12.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.12-to-1.13.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.13-to-1.14.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.14-to-1.14.2.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.14-to-1.15.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.14.2-to-1.15.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.15-to-2.0.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.8-to-1.9.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-1.9-to-1.10.sql
│           │   │   ├── g2core-schema-postgresql-upgrade-2.0-to-3.0.sql
│           │   │   ├── g2core-schema-sqlite-create.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.1-to-1.2.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.10-to-1.11.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.11-to-1.12.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.12-to-1.13.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.13-to-1.14.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.14-to-1.14.2.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.14-to-1.15.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.14.2-to-1.15.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.15-to-2.0.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.2-to-1.3.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.3-to-1.4.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.8-to-1.9.sql
│           │   │   ├── g2core-schema-sqlite-upgrade-1.9-to-1.10.sql
│           │   │   └── g2core-schema-sqlite-upgrade-2.0-to-3.0.sql
│           │   └── templates
│           │       ├── G2C.db
│           │       ├── G2C.db.template
│           │       ├── G2Module.ini
│           │       ├── G2Module.ini.template
│           │       ├── cfgVariant.json
│           │       ├── cfgVariant.json.template
│           │       ├── customGn.txt
│           │       ├── customGn.txt.template
│           │       ├── customOn.txt
│           │       ├── customOn.txt.template
│           │       ├── customSn.txt
│           │       ├── customSn.txt.template
│           │       ├── defaultGNRCP.config
│           │       ├── defaultGNRCP.config.template
│           │       ├── g2config.json
│           │       ├── g2config.json.template
│           │       ├── senzing_governor.py
│           │       ├── setupEnv
│           │       ├── stb.config
│           │       └── stb.config.template
│           └── sdk
│               ├── c
│               │   ├── g2PluginInterface.h
│               │   ├── libg2.h
│               │   ├── libg2config.h
│               │   ├── libg2configmgr.h
│               │   ├── libg2diagnostic.h
│               │   ├── libg2hasher.h
│               │   ├── libg2product.h
│               │   └── libg2ssadm.h
│               ├── java
│               │   └── com
│               │       └── senzing
│               │           └── g2
│               │               └── engine
│               │                   ├── G2Config.java
│               │                   ├── G2ConfigJNI.java
│               │                   ├── G2ConfigMgr.java
│               │                   ├── G2ConfigMgrJNI.java
│               │                   ├── G2Diagnostic.java
│               │                   ├── G2DiagnosticJNI.java
│               │                   ├── G2Engine.java
│               │                   ├── G2Fallible.java
│               │                   ├── G2JNI.java
│               │                   ├── G2Product.java
│               │                   ├── G2ProductJNI.java
│               │                   └── Result.java
│               └── python
│                   └── senzing
│                       ├── G2Config.py
│                       ├── G2ConfigMgr.py
│                       ├── G2Diagnostic.py
│                       ├── G2Engine.py
│                       ├── G2EngineFlags.py
│                       ├── G2Exception.py
│                       ├── G2Hasher.py
│                       ├── G2IniParams.py
│                       ├── G2Product.py
│                       └── __init__.py
└── var
    └── opt
        └── senzing
            ├── pgadmin
            │   └── ...
            ├── postgres
            │   └── ...
            ├── rabbitmq
            │   └── ...
            └── sqlite
                ├── G2C.db
                ├── G2C.db.template
                ├── G2C_LIBFEAT.db
                └── G2C_RES.db

```
