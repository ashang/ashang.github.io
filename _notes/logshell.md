---
title: log4shell
categories: security
date: 2017-10-17
---


Apache Log4j2 <=2.14.1 JNDI features used in configuration, log messages, and parameters do not protect against attacker controlled LDAP and other JNDI related endpoints. An attacker who can control log messages or log message parameters can execute arbitrary code loaded from LDAP servers when message lookup substitution is enabled. From log4j 2.15.0, this behavior has been disabled by default.


In previous releases (>2.10) this behavior can be mitigated by setting system property "log4j2.formatMsgNoLookups" to true; or it can be mitigated in prior releases (<2.10) by removing the JndiLookup class from the classpath

    example: zip -q -d log4j-core-*.jar org/apache/logging/log4j/core/lookup/JndiLookup.class



https://nvd.nist.gov/vuln/detail/CVE-2021-44228
