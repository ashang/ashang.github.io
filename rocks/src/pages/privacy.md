There are many fronts in the fight against the enclosure of the internet and the relentless efforts to surveil and monetize our lives. We are a small and growing effort to expand the use of circumvention technology to protect us from incursions into our online lives.

Riseup is a longtime provider of online communication tools for people and groups working on liberatory social change.

RiseupVPN is a free to use donation supported VPN built on LEAP VPN. The Calyx Institute has a long track record of educating users about the threat of online surveillance and providing tools to protect their privacy, and is headed by Nicholas Merrill, one of the first people to successfully fight a National Security Letter.

---

AutoMySQLBackup with a basic configuration will create Daily, Weekly and Monthly backups of one or more of your MySQL databases from one or more of your MySQL servers.  
  
Other Features include:  
- Email notification of backups  
- Backup Compression and Encryption  
- Configurable backup rotation  
- Incremental database backups  
  
Time for a new maintainer.. I first created AutoMySQLBackup in 2002 and since then it's helped many thousands of admins keep their databases backed up.. I always had one basic requirement and that was that it should always be super simple to initially get working.. I would like to hand it over now to someone with the time and skill to keep it updated and take it further.. If you would like to take over the project please get in touch..


---

在数据库系统中，一个事务是指：由一系列数据库操作组成的一个完整的逻辑过程。例如银行转帐，从原账户扣除金额，以及向目标账户添加金额，这两个数据库操作的总和，构成一个完整的逻辑过程，不可拆分。这个过程被称为一个事务，具有ACID特性。ACID的概念在[ISO](https://zh.wikipedia.org/wiki/ISO "ISO")/IEC 10026-1:1992文件的第四段内有所说明。


## 四大特性

- 原子性（Atomicity）：一个事务（transaction）中的所有操作，或者全部完成，或者全部不完成，不会结束在中间某个环节。事务在执行过程中发生错误，会被[回滚](https://zh.wikipedia.org/wiki/%E5%9B%9E%E6%BB%9A_\(%E6%95%B0%E6%8D%AE%E7%AE%A1%E7%90%86\) "回滚 (数据管理)")（Rollback）到事务开始前的状态，就像这个事务从来没有执行过一样。即，事务不可分割、不可约简。[[1]](https://zh.wikipedia.org/wiki/ACID#cite_note-acid-1)
- [一致性](https://zh.wikipedia.org/wiki/%E4%B8%80%E8%87%B4%E6%80%A7_\(%E6%95%B0%E6%8D%AE%E5%BA%93\) "一致性 (数据库)")（Consistency）：在事务开始之前和事务结束以后，数据库的完整性没有被破坏。这表示写入的资料必须完全符合所有的预设[约束](https://zh.wikipedia.org/wiki/%E6%95%B0%E6%8D%AE%E5%AE%8C%E6%95%B4%E6%80%A7 "数据完整性")、[触发器](https://zh.wikipedia.org/wiki/%E8%A7%A6%E5%8F%91%E5%99%A8_\(%E6%95%B0%E6%8D%AE%E5%BA%93\) "触发器 (数据库)")、[级联回滚](https://zh.wikipedia.org/wiki/%E7%BA%A7%E8%81%94%E5%9B%9E%E6%BB%9A "级联回滚")等。[[1]](https://zh.wikipedia.org/wiki/ACID#cite_note-acid-1)
- [事务隔离](https://zh.wikipedia.org/wiki/%E4%BA%8B%E5%8B%99%E9%9A%94%E9%9B%A2 "事务隔离")（Isolation）：数据库允许多个并发事务同时对其数据进行读写和修改的能力，隔离性可以防止多个事务并发执行时由于交叉执行而导致数据的不一致。事务隔离分为不同级别，包括未提交读（Read uncommitted）、提交读（read committed）、可重复读（repeatable read）和串行化（Serializable）。[[1]](https://zh.wikipedia.org/wiki/ACID#cite_note-acid-1)
- [持久性](https://zh.wikipedia.org/wiki/%E6%8C%81%E4%B9%85%E6%80%A7 "持久性")（Durability）：事务处理结束后，对数据的修改就是永久的，即便系统故障也不会丢失。[[1]](https://zh.wikipedia.org/wiki/ACID#cite_note-acid-1)


----

We've chosen Eclipse Temurin as our default JDK because it's widely recognized as the de facto standard for OpenJDK distributions. Trusted for its reliability, stability, and performance, Temurin is ideal for production-grade development. We ensure our default version aligns with the latest stable release, so you're equipped with the best tools for your JVM projects.

Looking ahead, we plan to give you the flexibility to track the latest JDK releases from individual vendors, such as Oracle or Amazon Corretto. While this isn't available yet, we're working to make it easier for you to stay on top of the specific distributions you rely on.

https://sdkman.io/jdks/

