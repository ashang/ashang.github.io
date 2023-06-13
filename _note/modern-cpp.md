---
title: See ya 2022
---

https://www.cnblogs.com/Solstice/p/3195397.html
>
>"本书主要讲述采用现代 C++ 在 x86-64 Linux 上编写多线程 TCP 网络服务程序的主流常规技术”，封面印着“示范在多核时代采用现代 C++ 编写多线程 TCP 网络服务器的正规做法”。
>
>很多教科书上介绍的一些做法是过时的（signal），一些是不推荐使用的（从外部终止线程、TCP OOB数据），一些是大多数情况下没必要使用的（内存池、lock-free 编程）。
>
>多线程程序不要使用signal作为IPC。并且，在muduo-protorpc的示例中给出了Linux专有的signalfd(2)的用法，可以避免传统signal handler的常见陷阱，也更符合UNIX的“everything is a file”哲学。第4.4节说明不要从外部终止线程，因此也就不必去细究Pthreads cancellation point了。多线程程序最好不要fork()
>
>daemon是过时的做法。因为daemon进程的父进程是init(1)，配置文件在本机，不便于多机统一监控与管理（第9.8节）。（注：如果是第三方标准的服务程序，又不需要经常升级或改配置重启，并且一旦崩溃，重启就能继续服务，那么做成 daemon 让init(1)接管是可以的，比如ntpd、sshd等。本书谈的是自己开发维护的服务程序。）另外，Java/Python/Go写的服务程序似乎也没有做成daemon的习惯，C++程序没有理由要特殊对待。补充一点，Linux的进程管理机制很落后（从UNIX继承而来），子进程退出的事件只能被父进程以SIGCHLD信号的方式收到（而且这个signal可能丢失），kill(pid) 也存在很多race condition（你怎么保证pid在kill之前的一瞬间还代表你想kill的那个进程，而不是一个新启动的进程？close(fd)就不会有这种 race condition。）。这些困难在用户态无法克服，只能修改内核，引入新的系统调用才能治本。例如 FreeBSD 9.0 引入了 pdfork()/pdkill() 等，将子进程变成文件描述符，这样就能用IO事件框架统一处理了，也符合UNIX的“everything is a file”哲学。但愿Linux内核也能尽快引入类似的系统调用，减轻程序员的负担。
>这本书没有讲内存池，而是说明不是每个程序都要自己写内存池（§12.2.8）。这本书也没有把“避免内存碎片”挂在嘴边，而是论证为什么一般的程序不必在意它（§A.1.8）；
>这本书只关注Linux，不考虑移植性。它推荐使用Linux专有的gettid()系统调用作为线程标识（第4.3节），而不是用pthread_self()。
>这本书不讲POSIX中五花八门的定时函数，而专讲用Linux特有的timerfd来实现高精度定时（§7.8.2），因为它能方便地融入IO事件处理框架。
>
>
这本书只讲mutex和condition variable作为最基础的线程同步手段（第2章），并且我认为一个C++多线程程序代码里不应该直接出现pthread_mutex_lock之类的基本Pthreads调用。本书进一步建议只使用非递归的mutex（§2.1.1），这与某些网上文章的推荐正好相反。这本书第2.3节甚至建议不要使用读写锁和信号量（semaphore），因为一是容易用错，二是不见得能提高性能。mutex和condition variable是完备的，能实现多种更易用的同步设施，例如CountDownLatch和BlockingQueue。§12.8.3的代码展示了用BlockingQueue和ThreadPool控制并发度的手法，做到了“No locks. No condition variables. No callbacks.”
这本书不讲lock-free编程，因为编写可靠的lock-free代码并分析验证其正确性的难度远大于编写普通的使用mutex和condition variable的多线程代码，后者已经有了相当成熟的理论和工具。我认为lock-free不是每个多线程程序员应该掌握的技术，它投入高而用处少，可以适当了解，但不值得每个人都去深究。只需要少数人用它实现封装好的数据结构，像我这样的普通人就可以受益。
这本书只讲BSD Sockets作为进程间通信的手段，并且只用TCP长连接（§3.4）。这样就砍掉了pipe、FIFO、POSIX message queue、shared memory、STREAMS、UNIX domain socket等等内容，因为它们都只限本机进程间通信，无法扩展到多机。
网络编程方面（第6、7章），这本书不讲Sockets API的基本用法，而且代码中也不会直接使用它们。我认为在程序中直接使用 Sockets API是初学者的做法，当写一个新网络服务程序，如果一开始考虑的是怎么组织accept、read、epoll_wait等调用，这种做法无异于用铅笔刀锯大树，事倍功半，也不利于将来的功能扩展和维护。稍微像样点的公司都会用成熟的网络库（不一定开源），把网络编程的复杂性封装进去，暴露出良好易用的接口，让开发人员使用更高层的building blocks（消息传递或RPC）从功能的角度去设计程序，避免一次次反复掉到TCP网络编程的坑里。多个服务程序共享相同的基础库和事件处理框架的益处是显而易见的，一方面把网络编程的复杂性集中到一起，避免每个团队都去踏一遍坑；另一方面，基础库的bug修复与性能优化能惠及用到它的全部服务程序；最后，程序结构上的相似性让编程经验更加通用，多个服务程序在功能、性能、正确性等方面具有共性，能举一反三触类旁通，降低将来开发维护的成本。应该避免每个程序都另起炉灶，单独设计其IO事件处理结构。
这本书只讲非阻塞IO结合IO复用（IO-Multiplexing）这一种并发风格（归纳为三个半事件），并介绍在多线程下的扩展（one loop per thread）。IO复用方面，本书只讲level-trigger，不讲edge-trigger。一方面目前没有up to date的测试表明ET更快，相反，我认为LT在读取数据时可以节约一次read()调用（§8.7.2）；另一方面，LT模式更容易与其他第三方库结合（§7.15）。多线程程序管理并发socket fd有很多风格可供选择，例如epoll fd是多个线程共享一个（多对一）还是每个线程有自己的epoll fd（一对一），每个socket fd是只属于一个epoll fd（多对一）还是可以同时属于多个 epoll fd（多对多），每个socket fd是只能被固定的一个线程读写还是可以被多个线程读写（如果是后者，那么读写的时候是加锁还是使用ONESHOT）。以上不是每种都可行，本书也没有一一加以分析，而是建议使用one loop per thread这种适用性较强的风格，首先是正确性容易验证，其次是性能也能满足要求。
本书不讲IPv6，因为目前世界上最大的公司的服务机群也用不完一个私有A类地址（10.0.0.0/8）。本书不讲UDP，因为《Unix网络编程》已经讲得很好了。
这本书举的网络编程的例子不再是简单的echo服务，而是有格式（因此引入codec）、多连接之间会交换数据的网络程序，更接近业务场景，也借机讲解如何避免TCP网络编程的常见陷阱。并且在示例代码中给出了分布式单词计数、多机求中位数等稍微复杂一点的程序。
在C++方面，这本书没有介绍动态链接库热更新这种“高级”技术，而是说明，在分布式系统中，为了部署方便，应该从源码编译全部的库，与主程序链接为一个standalone的可执行文件，以减小对运行环境的依赖


https://www.boost.org/doc/libs/1_80_0/more/getting_started/unix-variants.html
https://www.boost.org/doc/libs/


