https://www.wmocloudatlas.org/search-image-gallery.html

https://www.cumulusmedia.com/2021/06/25/cumulus-media-announces-successful-completion-of-175-million-debt-paydown/


https://www.globenewswire.com/news-release/2022/05/05/2436584/9032/en/Cumulus-Media-Announces-Modified-Dutch-Auction-Tender-Offer-to-Purchase-up-to-25-Million-of-its-Outstanding-Class-A-Common-Stock.html



https://www.nextplatform.com/2021/04/07/is-aws-making-the-switch-to-homegrown-network-asics/





find all reference 这只是个接口而已，在装上 clangd 插件之后，就会提示与默认的 c++ intellsense 冲突，禁用掉默认的 c++ intellsense 之后这个接口就被clangd接管了，clangd 在第一次整理 index 结束之后的速度还是非常快的，基本上就是秒出结果



vscode 有 call hierarchy 和 find all references，大概能代替这个功能





使用vsc的gtags插件，加上配置compile_comands.json作为intellisense，速度快的一比
而且嵌套宏解析，条件编译代码显示等都解决得比si好
2022-07-14
​回复
​7
我看你看大家看
我看你看大家看
你这个有点老了，直接clang插件加compile json文件，精准无比加静态检测加代码格式化





Visual Studio code里cpptools + c/c++ gnu global 配合 compile_commands.json跳转定义，以及ctrl T 符号搜索已经够用了。clangd更好，能静态解析出调用层次，就是不能debug，还得要codelldb，不如cpptools all in one方便。

作者：匿名用户
链接：https://www.zhihu.com/question/30008168/answer/2738045239
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。





可以安装cpp插件，把intellisence，错误提示全关了，只保留debug功能，我觉得这玩意debug比codelldb好用一点点[思考]
05-25 · IP 属地山东
​回复
​1
Shaka
Shaka
一开始我的配置跟您一样，cpptools+gtags+fuzzyTags+compile_commands.json。后面发现用了compile_commands.json后，gtags没装也没啥影响，装了反而在hover时提示过多（gtags只负责解析tags，可能会把非本项目相关的tag一同解析）




看Linux内核代码，随便一个支持LSP的编辑器在查找符号上都吊打SI




cumulus 主要功能（我认为的主要功能）

1.management port ,eth0

2.Network Command Line Utility,support commit <<<<这个很关键，要有独立的命令行操作方式。

3.license

4.bridge，support vlan aware,support BVI and trunk,vlan tagging

<<<<这个也很关键，基本的vlan功能。无论交换机还是接入网关，这个功能还是要支持的。从cumulus的操作过程看，不像是直接用ovs改的，应该是用标准的linux的bridge改的

5. support append interface loopback，and support second ip address

<<<<这个功能，对于交换机还是需要的

6.support bgp

7.support ladp\tacas+\radius

8.support netfilter based on iptable+ebtable

<<<<<依靠iptable +ethtable实现l2 l3 acl

9.support https rest api，support nginx proxy

<<<<这个北向接口，rest api，我们可以参考

10.support breakout ports

<<<<这个功能也就是目前5G承载网里面要求的flexisble ethernet ,即1个100G physical 可以分为4x25G logical interface。这个有难度，需要硬件支持，绝不是开源可以搞定

11.support dhcp relay/dhcp server

12.support spanning tree per vlan

<<<<这个功能虽然很土，但是在datacenter和企业内网还是需要的，很基本的功能。如果要做datacenter接入交换机还是要支持的


13.support vxlan aware bridge

14.support mlag

15.support vrrp

16.support evpn

<<<<<这个功能现在很Hot，5G承载网必选

17.support vxlan routing

18.support QinQ over vxlan

19.support FRRouting

20.support bfd

21.support VRF

<<<< <vrf支持，对于datacenter和承载网交换机，都是必须的。标准linux一张路由表是不够的。它也是支持l3vpn 、l2vpn 的基础。












https://www.trinea.cn/android/didi-internationalization-android-evolution/


披荆斩棘间，不至使内心慌乱芜杂；消沉寂寥时，也不会就此瘫软不起。

线车宣言（The Cluetrain Manifesto）是一本绝对的经典，「市场就是谈话」是它较为准确的意译。

这一次出版社很大胆，用上了《互联网的本质》这样强烈的中文书名。这四位作者中，其他人的著作在很少有接触，第四作者戴维·温伯格之后有很精彩的书。

对于互联网的本质，有很多种解读。但是，说互联网带来的就是个体之间的谈话，这个的确正是我们现在感受到的现实。

互联网，让我们每个人都成了个体，又让我们所有人都联系到一起，在持续地交谈。

市场就是谈话。






在繼續操作之前
無論您是首次使用Airbnb，還是我們一直以來的成員，都希望您能尊重和接納Airbnb社區的每一位成員，和我們一起努力把世界變得更美好。 了解更多
我承諾尊重這個社區的所有成員，不論對方的種族、宗教、國籍、民族、身心障礙狀況、性別、性別認同、性取向或年齡，皆不會對他們妄加評斷，也不會懷有偏見。

搜尋
關於社區承諾
Airbnb為什麼會下此承諾？
這項承諾是我們向打造全球化社區、讓每個人都真正擁有歸屬感的目標所邁出的重要一步。歧視會讓房東、房客及他們的家人感到不被接納、不受歡迎，對此我們絕不能容忍。如果要打造出一個讓每個人都擁有歸屬感的Airbnb，就需要我們社區中的每個人都能理解這個使命，並願意幫助我們實現此目標。
如果我拒絕接受此承諾，會發生什麼事？
如果您拒絕承諾，您就不能夠再透過Airbnb預訂或出租，您可以選擇取消您的帳號。一旦您的帳號取消了，未來已預訂的旅程也會被取消。您仍然可以瀏覽Airbnb網站，但您無法進行任何預訂或接待任何房客。
我可以如何分享對此承諾的回饋意見或獲得更多資訊？
我們歡迎您提供回饋意見，回饋意見請發送至allbelong@airbnb.com。 您也可以查看我們的房東資源，這裡回答了房東針對Airbnb的反歧視政策所提的常見問題。

没有飞翔过的鸟儿，总觉得飞翔是一种病。

玫瑰少年

不一样又怎样。

同志议题，并不仅仅是关心这个群体本身，而是关注我们所有人共同的命运。

因为我们的社会还充斥着各种各样的歧视，歧视就像是潜伏在我们生活中无处不在的幽灵，一不留神，我们都可能成为被主流群体排斥的少数群体和弱势群体。

你不是同性恋者，但你可能是在公司里遭受职场歧视的女性，你可能是在大城市里被歧视的外地人，你可能是被强权欺凌房子面临强拆的底层百姓，你可能因为不标准的口音而在公交车上被人翻了白眼，你可能仅仅因为是个左撇子而遭受嘲笑。

因为我们同气连枝，都是期望在这块土地上不遭受任何不公正对待、平等而有尊严地生活的普通人。”

为别人争取平等和权益，其实就是在为自己争取平等和权益。

2014年10月，

主流和弱势，原本就只是一个相对的概念。每一个人，都可能在某个时候，成为不被主流社会认可和接纳的“他者”。而且，选择权甚至都不在你自己手上。






我的願望，就是這塊土地上的每一個普通人，都能平等而有尊嚴地生活，臉上有笑，心裡有愛。

从白发苍苍的祁家威，到农妇母亲陈君汝，从最高法的败诉，到释宪裁决，

不难想象，可能不好理解这里为何出现蒋先生经国，龙女士应台。





----



https://www.sohu.com/a/322186732_240947



https://zhuanlan.zhihu.com/p/41443936



https://so.gushiwen.cn/mingju/juv_c3bb30455854.aspx


ris 史蒂文森

斯蒂文森

苔丝

葛地斯堡

雪莱的一生

拜伦 心路历程

新约福音

门罗

生命太短暂

失乐园


対德宣战

阿拉伯的劳伦斯







免责申明：

以下内容，有可能引起内心冲突或愤怒等不适症状。若有此症状自觉被误导者，请绕行。若按捺不住看后症状特别明显，可自行前往CCAV等欢乐 频道进行综合调理。其余，概不负责 。

本文转摘的各类事件，均来自于公开发表的国内媒体报道。引用的个人或媒体评论旨在传播各种声音，并不代表我们认同或反对其观点。

欢迎转载，转载请保证原文的完整性（不得随意增删内容，或篡改图卦名称等），请注明来源和链接。

【1】广东暂停从江苏、浙江、

support@vultr.com wrote:

>Ticket URQ-72THT has been updated by www.vultr.com  [staff].
>
>Dear Vultr Customer,
>
>Including pending charges, your account is carrying a $1.03 balance.
>
>In order to cover your current balance and your estimated monthly costs, our billing system will automatically deposit $5.00 from your payment method on file in 24 hours.
>
>You can review your current balance or make a deposit for a different amount directly from your customer portal:
>
>https://my.vultr.com/billing/
>
>To update or check the progress of your ticket, please reply directly to this e-mail or visit:
>
>https://my.vultr.com/support/view_ticket/?TICKETID=URQ-72THT
>
>Thank you for using Vultr.com
>
>Follow us on Twitter!
>
>https://twitter.com/vultr






Ticket URQ-72THT has been updated by www.vultr.com  [staff].

Dear Vultr Customer,

Including pending charges, your account is carrying a $1.03 balance.

In order to cover your current balance and your estimated monthly costs, our billing system will automatically deposit $5.00 from your payment method on file in 24 hours.

You can review your current balance or make a deposit for a different amount directly from your customer portal:

https://my.vultr.com/billing/

To update or check the progress of your ticket, please reply directly to this e-mail or visit:

https://my.vultr.com/support/view_ticket/?TICKETID=URQ-72THT

Thank you for using Vultr.com

Follow us on Twitter!

https://twitter.com/vultr




----

Hi, James,

On Thu, Nov 18, 2021 at 07:13:56AM +0800, James Liao wrote:
>Aaron,
>I would like to initialize a conversation with you on the possibility of using
>Docker/Kubernetics on PicOS.
>
>The reason behind this potential project is there are many applications, such
>as NPB, Firewall, or Identify control, that can be run on the switch CPU.
>Ideally, we want to use Docker or Kubernetics to provide application protection
>and remove the system dependency.

That's what I had long thought to propose, esp. with more edge and powerful
computing nodes working as switches.

>In this case, I have the following questions.
>
> 1. Do you have time to work on this research in parallel to your daily work?

I can manage that.

> 2. Assuming you have time, what would the architecture looks like?
>     a. Do we prefer Docker or Kubernetics?

Docker is one of and also the first popular containers, while K8s is one
of the orchestrating systems coming out late but now becoming
dominating due to its excellence and active community.

Docker can be used as one of the supported containers for k8s.
For single or few node cases, Docker can be used.
For scaling or consistent managing of instances, k8s would assist a
lot just as what Ansible playbooks help automation tasks.

>     b. Do we run Docker in parallel to PicOS? Or do we want PicOS as one of
>        the Docker service?

It would help us a lot if running PicOS as one docker service, referring
to what we are doing on VM. But PicOS has L2 dependencies.

L3 only solutions, such as FRR, can easily run as a container.
So in the beginning, I would like that to run in parallel to PicOS.
Later we can leverage it to make PicOS container-wise as much as we can.

> 3. What is the risk and consideration factors for different choices?

Basically, there is no risk. Running docker services in parallel to
PicOS is just easy to start with.

> 4. Evaluation of the required time and resource.

I think I can make some tests by trial and error to have a better
practice. That can be expected to be done in December.

I would consult with and involve solution team, Leon/Yachal/Tim when
needed.

>Copying Lin as well in case you have concern about your assignment.
>
>Thanks,
>
>James
>

--
Aaron




The dad_transmits setting determines how many neighbor solicitations are to be sent out per address including global and link-local, when you bring up an interface to ensure that the desired address is unique on the network.


    If the values are not set to 0, configure the host system to deny IPv6 neighbor solicitations.

$ cat /proc/sys/net/ipv6/conf/all/dad_transmits
1



https://tldp.org/HOWTO/Linux+IPv6-HOWTO/ch11s02.html

dad_transmits

    Type: INTEGER

    Default: 1

The amount of Duplicate Address Detection probes to send.





$ cat /proc/sys/net/ipv6/conf/all/accept_dad
0



https://www.kernel.org/doc/Documentation/networking/ip-sysctl.txt


accept_dad - INTEGER
        Whether to accept DAD (Duplicate Address Detection).
        0: Disable DAD
        1: Enable DAD (default)
        2: Enable DAD, and disable IPv6 operation if MAC-based duplicate
           link-local address has been found.

        DAD operation and mode on a given interface will be selected according
        to the maximum value of conf/{all,interface}/accept_dad.


--
Aaron



## 几个链接，cache相关，


https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/5/html/tuning_and_optimizing_red_hat_enterprise_linux_for_oracle_9i_and_10g_databases/sect-oracle_9i_and_10g_tuning_guide-memory_usage_and_page_cache-tuning_the_page_cache


Page cache is a disk cache which holds data of files and executable programs, for example pages with actual contents of files or block devices. Page cache (disk cache) is used to reduce the number of disk reads. To control the percentage of total memory used for page cache in Red Hat Enterprise Linux 5, change the pagecache kernel parameter. The lower the percentage, the more the system favors reclaiming unmapped pagecache memory over mapped memory. High values (like the default value of 100) are not recommended for databases.
The pagecache parameters can be changed in the proc file system without reboot:

# echo "40" > /proc/sys/vm/pagecache

Alternatively, you can use sysctl(8) to change it:

# sysctl -w vm.pagecache="40"

To make the change permanent, add the following line to the file /etc/sysctl.conf. This file is used during the boot process.

# echo "vm.pagecache=40" >> /etc/sysctl.conf

You can also adjust the minimum free pages using the following command:

# echo 1024 > /proc/sys/vm/min_free_kbytes

To make this change permanent, add the following line to the file /etc/sysctl.conf:

# echo vm.min_free_kbytes=1024 >> /etc/sysctl.conf


LSAG文章：
https://tldp.org/LDP/sag/html/buffer-cache.html



一个很有用的product 设置参考：

https://discuss.aerospike.com/t/how-to-tune-the-linux-kernel-for-memory-performance/4195

摘录：
- drop_cache 只用 echo 1, 足够，否则slab会导致系统性能波动/
- min_free_kbytes 需要仔细考虑，大了小了都会有问题，

Tuning is performed by performing an echo NUMBER > /proc/sys/vm/min_free_kbytes where, NUMBER is the number of kilobytes required to be free in the system. To leave 3% of memory on a 100GB RAM machine unoccupied, the command would be:

echo 3145728 > /proc/sys/vm/min_free_kbytes

Caution should be exercised when setting this parameter, both too low and too high values can have an adverse effect upon system performance. Setting min_free_kbytes too low prevents the system from reclaiming memory. This can result in system hangs and OOM kills of processes.

Setting this parameter to a value that is too high (5-10% of total system memory) will cause the system to run out of memory immediately. Linux is designed to use all available RAM to cache file system data. Setting a high min_free_kbytes value results in the system spending too much time reclaiming memory.

It is advised to either reduce swappiness to 0 or not use swap. For low-latency operations, using swap to any extent will drastically slow down performance.

To set the swappiness to 0 to reduce potential latency:

echo 0 > /proc/sys/vm/swappiness




下面这2个链接需要帐号，抄内容如下，免得你们访问不了：

https://access.redhat.com/solutions/146673



    It is not possible to reclaim the dirty pages automatically when the total physical memory usage reaches a specific percentage value since the system considers dirty pages cached separately of total memory available. Thus you need to set parameter for the dirty pages cached to be written to the disk and free memory space.

    Writing the appropriate value to the file /proc/sys/vm/drop_caches causes the kernel to drop clean caches, dentries and inodes from memory, causing that memory to become free.
        To free pagecache:
    Raw

    $ echo 1 > /proc/sys/vm/drop_caches

        To free dentries and inodes:
    Raw

    $ echo 2 > /proc/sys/vm/drop_caches

        To free pagecache, dentries and inodes:
    Raw

    $ echo 3 > /proc/sys/vm/drop_caches

NOTE: Please run sync first to flush pending data out to disk.

Using the parameter dirty_ratio and dirty_background_ratio simultaneously, the pdflush daemon can be invoked to write dirty pages on the disk and free memory space.

Refer following link which will give you brief detail about 'dirty_ratio' & 'dirty_background_ratio': How to control the size of page cache in RHEL?

The values for dirty_ratio (default = 10) & dirty_background_ratio (default = 40) which are set for ideal system, thus for your scenario try gradually decreasing these values simultaneously to get final optimal values (usually recommended to see how the relevant settings works in a production-like test environment first) that can be set which can write the cached pages from memory to disk when total memory usage reaches a certain percentage value on your system.

Decreasing these values will result in a high I/O rate (negatively impacting your I/O speeds) from the process running on your system which will eventually increase load of your system.

NOTE: Modifications to these values could affect a significant change in behavior and performance of the system (both positive or negative). It is highly recommended that you modify them slightly at first and test each change thoroughly to ensure they do not have any negative effects in your environment.


https://access.redhat.com/solutions/32769


The primary sysctl tunables (along with their default values) for controlling the behaviour of the page cache are as follows:

    vm.vfs_cache_pressure (default = 100)
        At the default value of vfs_cache_pressure=100 the kernel will attempt to reclaim dentries and inodes at a "fair" rate with respect to pagecache and swapcache reclaim.
        Controls the tendency of the kernel to reclaim the memory which is used for caching of directory and inode objects.
        Decreasing vfs_cache_pressure causes the kernel to prefer to retain dentry and inode caches. Increasing vfs_cache_pressure beyond 100 causes the kernel to prefer to reclaim dentries and inodes
        To limit the size of page cache, you would want to increase this value so the kernel will be more likely to reclaim these objects.

    vm.dirty_background_ratio (default = 10)
        Contains, as a percentage of total system memory, the number of pages at which the pdflush background writeback daemon will start writing out dirty data.
        To limit the size of page cache, decrease this number so the pdflush daemon will start writing out dirty data sooner.

    vm.dirty_ratio (default = 20)
        Contains (as a percentage of total system memory) the number of pages at which a process which is generating disk writes will itself start writing out dirty data.
        To limit the size of page cache, decrease this number so processes will start writing out dirty data sooner.

    vm.dirty_writeback_centisecs (Red Hat Enterprise Linux 4 and 5: default = 499, Red Hat Enterprise Linux 6, 7 and 8: default = 500)
        The pdflush writeback daemons will periodically wake up and write "old" data out to disk. This tunable expresses the interval between those wakeups, in 100'ths of a second. Setting this to zero disables periodic writeback altogether.
        To limit the size of page cache, decrease this value so the pdflush daemon will wake up more often and write dirty data out to disk.

    vm.dirty_expire_centisecs (Red Hat Enterprise Linux 4 and 5: default = 2999, Red Hat Enterprise Linux 6, 7 and 8: default = 3000)
        This tunable is used to define when dirty data is old enough to be eligible for writeout by the pdflush daemons. It is expressed in 100ths of a second. Data which has been dirty in-memory for longer than this interval will be written out next time a pdflush daemon wakes up.
        To limit the size of page cache, decrease this value so data will be considered dirty sooner and will be written out by pdflush.

    vm.swappiness (RHEL 5 and 6: default = 60, RHEL 7 and 8: default = 30)
        This controls how likely the vm is to swap out inactive memory pages (the higher the value, the more likely it is to swap).
        To limit the size of page cache, decrease this value so the kernel is less likely to swap and thus more likely to drop pages from the page cache.
        A value of zero here does not prevent the system from swapping.

You do not need to reboot for sysctl changes to take effect.

Modifications to these values could effect a significant change in behavior and performance of the system (positive or negative). It is highly recommended that you modify them slightly at first and test each change thoroughly to ensure they do not have any negative effects in your environment.

For further details please check the following documents that are contained in the kernel-doc package: /usr/share/doc/kernel-doc-$VERSION/Documentation/{filesystems/proc.txt, sysctl/vm.txt}.




关于dirty ratio:
https://lonesysadmin.net/2013/12/22/better-linux-disk-caching-performance-vm-dirty_ratio/




有意义的实验：

https://www.linuxatemyram.com/play.html





________________________________________
From: Lin Du
Sent: Friday, August 19, 2016 4:40 PM
To: Harsha Vardhan; support@pica8.com; Aaron Shang
Subject: Re: Docker error

Harsha,
Aaron will check it and get back you soon.
Thanks,
Lin
PICA8， Inc.


-------- 原始邮件 --------
主题：Docker error
发件人：Harsha Vardhan
收件人：support@pica8.com
抄送：


Hi Support,

So I  want to run a container on the as7712 running picos 2.7.1.
The package docker is available for as7712 but with that you are not able to run containers.
The package required is docker-io, which is not available.
Error message :

admin@XorPlus$sudo docker load container-lxc.tar.gz
Segmentation Fault or Critical Error encountered. Dumping core and aborting.
admin@XorPlus$^C
admin@XorPlus$sudo apt-get install lxc-docker
Reading package lists... Done
Building dependency tree
Reading state information... Done
E: Unable to locate package lxc-docker
admin@XorPlus$sudo apt-get install docker.io
Reading package lists... Done
Building dependency tree
Reading state information... Done
E: Unable to locate package docker.io
E: Couldn't find any package by regex 'docker.io'
admin@XorPlus$

Best Regards
Harsha Vardhan

STORDIS GmbH
Rosenwiesstr. 17, 70567 Stuttgart, Germany, www.stordis.com<http://www.stordis.com/>, T: +49 (0)711 34 21 58 – 0
Amtsgericht Stuttgart, HRB 724261, Geschäftsführer: Alexander Jeffries, Waldemar Scheck
[Signatur-IBC2016]

[160818Email_Signatur-breiter]







-----


On Fri, 23 Jul 2021 08:29:30 +0800
James Liao <james.liao@pica8.com> wrote:

> Aaron,
>
> I am keeping only PLM on this mail list for now. Any of the major
> changes should be agreed by PLM before we give it out to sales or SE
> team.

Got, sorry for lack of that considerations.

> I understand the reason for the change (thank you for the detailed
> explanation), but have a couple of questions.
>
> 1. Is there any visible change (such as Bash or CLI) to the users?


There are only CLI commands to enable/disable, to set servers, and to
check status/results.

The input keeps the same.

The output should be changed. Because the previous output calls kernel
ntptime syscall, which confused users.

I will note this and have documents to reflect the differences.

> 2. Is there any operation environment change users (such as external
> NTP server change) need to prepare?

No. Users should be unaware of any changes. NTP servers are the same
ones, settings are also the same.

We will take care what is needed internally.

> 3. is there any impact to users
> who upgrade PICOS from 3.x to 4.x?

Should be no. All previous settings would be kept and continue to be
used.

We will keep NTP config upgrade cases in regression test.


>
> James
>
>
> On 7/22/21, 10:25 AM, "Aaron Shang" <aaron.shang@pica8.com> wrote:
>
>     Hi, team
>
>     Here is a proposal to change to use modern, graceful way to sync
> time.
>
>     This plan is related to current NTP issue, but it had been
> discussed for a long time.
>
>     It is just for future plan, perhaps in future minor releases,
> such as 4.2.0, or 4.3.0.
>
>     ## Why the change
>
>     NTP had been responsible for most of the largest ever scale of
> DDoS.
>
>     Also in our Bugzilla db, there had been a dozen of issues related
> to NTP.
>
>     At first, we use `ntpdate` as a client to sync time with NTP
> servers. That needs a cron task to help run it regularly.
>
>     At some point, with no clear reason, we added `ntpd` server into
> rootfs, using its service mode to sync time, without using its server
> function.
>
>     We had been using systemd as PID 1 from Debian 8.
>     Systemd has a built-in time syncing service `timesyncd`, which
> can sync time as a daemon. It is very light at runtime, as very tiny,
> built-in.
>
>     ## What it is like
>
>     Although it is built-in, the service won't start if it detect the
> existence of often used time daemons.
>
>         admin@Xorplus:~$ cat
> /lib/systemd/system/systemd-timesyncd.service.d/disable-with-time-daemon.conf
> [Unit] # don't run timesyncd if we have another NTP daemon installed
>         ConditionFileIsExecutable=!/usr/sbin/ntpd
>         ConditionFileIsExecutable=!/usr/sbin/openntpd
>         ConditionFileIsExecutable=!/usr/sbin/chronyd
>         ConditionFileIsExecutable=!/usr/sbin/VBoxService
>
>     After we removed ntp, it will run and keep time sync.
>
>         admin@Xorplus:~$ sudo apt autoremove --purge ntp
>         admin@Xorplus:~$ sudo systemctl daemon-reload
>         admin@Xorplus:~$ sudo systemctl restart systemd-timesyncd
>         admin@Xorplus:~$ sudo systemctl status systemd-timesyncd
>         * systemd-timesyncd.service - Network Time Synchronization
>            Loaded: loaded
> (/lib/systemd/system/systemd-timesyncd.service; enabled; vendor
> preset: enabled) Drop-In:
> /lib/systemd/system/systemd-timesyncd.service.d
> `-disable-with-time-daemon.conf Active: active (running) since Tue
> 2021-07-20 09:39:31 UTC; 42s ago Docs:
> man:systemd-timesyncd.service(8) Main PID: 2295 (systemd-timesyn)
> Status: "Synchronized to time server for the first time
> 134.76.249.102:123 (0.debian.pool.ntp.org)." Tasks: 2 (limit: 4915)
> Memory: 1.6M CGroup: /system.slice/systemd-timesyncd.service
>                    `-2295 /lib/systemd/systemd-timesyncd
>
>         Jul 20 09:39:36 Xorplus systemd-timesyncd[2295]: Synchronized
> to time server for the first time 134.76.24
>
>     The output is nice.
>
>     To check system time status.
>
>         admin@Xorplus:~$ timedatectl status
>                        Local time: Tue 2021-07-20 10:10:10 UTC
>                    Universal time: Tue 2021-07-20 10:10:10 UTC
>                          RTC time: Tue 2021-07-20 10:10:10
>                         Time zone: UTC (UTC, +0000)
>         System clock synchronized: yes
>                       NTP service: active
>                   RTC in local TZ: no
>
>     Or if you want to have output message as what the `ntpq -p` had
> been showing as below.
>
>         admin@Xorplus:~$ timedatectl timesync-status
>                Server: 80.249.145.122 (0.debian.pool.ntp.org)
>         Poll interval: 8min 32s (min: 32s; max 34min 8s)
>                  Leap: normal
>               Version: 4
>               Stratum: 2
>             Reference: 596DFB18
>             Precision: 1us (-23)
>         Root distance: 38.803ms (max: 5s)
>                Offset: -5.086ms
>                 Delay: 273.384ms
>                Jitter: 10month 2w 1d 13h 28min 23.169258s
>          Packet count: 17
>             Frequency: -0.870ppm
>
>     It will NOT take more than 1 sec as what current talked issue had
> shown, because it is showing ntp status.
>
>
>     To toggle ntp service on/off, start/stop.
>
>         admin@Xorplus:~$ timedatectl set-ntp true
>         admin@Xorplus:~$ timedatectl set-ntp false
>
>     Thus we can remove scripts we had maintained to operate ntp
> services.
>
>     Actually we had used that for current timezone processing from
> release 3.x.
>
>     ## What next
>
>     Do very little change to keep almost same input/output as before.
>
>     The CLI can keep unchanged.
>
>     Remove ntp/ntpdate, to save 3MB rootfs.
>
>         sudo apt autoremove --purge ntp
>         sudo apt autoremove --purge ntpdate
>
>     ## Others
>
>     If we want to provide NTP service outside, just forget the above.
>     It's better to keep using existing setup, although there had been
>     other NTP implementations besides this old official one.
>
>     ## Reference
>
>     - Time daemons
>       - https://chrony.tuxfamily.org/comparison.html
>     - timedatectl
>         - https://man7.org/linux/man-pages/man1/timedatectl.1.html
>     - timesyncd.service
>         -
> https://man7.org/linux/man-pages/man8/systemd-timesyncd.service.8.html
>     - A command called hwclock can set them accordingly by
> --hctosys/--systohc
>       - https://man7.org/linux/man-pages/man8/hwclock.8.html
>
>
>
>
>
>
>     --
>     Aaron
>
>
>     ________________________________________
>     From: Aaron Shang <aaron.shang@pica8.com>
>     Sent: Thursday, July 22, 2021 20:32
>     To: Sasikumar Puthiyaveedu; Tom Jia; Vic Lan; Lisa Pi; Daisy
> Zhao; Iris Rong Cc: Zoneson Chen; Hai Vo-Dinh; Mani Subramanian; Don
> DeRisi; Lin Du Subject: Re: NTP issue - UNSYNC - returns code 5
> (ERROR)
>
>     Hi, Sasi,
>
>     We had investigated this issue carefully for several days.
>
>     Here are some summaries on this issue.
>
>     ## Conclusion
>
>     - The NTP feature works, till now as expected, but the
>     trailing output to show result might confuse most end users.
>
>     I am not meant to say that is not an issue. It is not a
> work-as-designed, a wont-fix, or works-for-me. But we should not call
> `ntptime` at the end.
>
>     ## What we had done wrong, or at least not graceful?
>
>     - We should not call `ntptime` to show the status, which is not
> intended for end users.
>     - `ntptime` to show kernel time variables using the ntp_gettime()
> system call.
>       - Refer to NTP "Kernel Application Program API", KAPI
>       - https://linux.die.net/man/8/ntptime
>       - The error 5 shows status of UNSYNC, meaning HW Clock not
> finished synchronized.
>
>     ## What next?
>
>     - Change from using `ntptime` to service status for output
>       - Use systemd built-in timedatectl timesync-status to show the
> status
>         - https://man7.org/linux/man-pages/man1/timedatectl.1.html
>     - Change to use modern, graceful way to sync time
>       - Use systemd built-in timesyncd.service to set and sync time
>         -
> https://man7.org/linux/man-pages/man8/systemd-timesyncd.service.8.html
>         - `timedatectl set-ntp` command may be used to enable and
> start, or disable and stop NTP
>     - Make fixes in next minor releases, such as 4.2.0, or 4.3.0.
>     - A separate proposal should follow.
>
>     ## Details and references
>
>     In Linux, there are two times
>     - One is called system time (or wall clock, what we can see from
> `date` command output)
>       - It can also be changed from timezone or locale settings.
>     - Another is HW clock (i.e. RTC, with battery assistance, CMOS
> CLOCK)
>     - A command called hwclock can set them accordingly by
> --hctosys/--systohc
>       - https://man7.org/linux/man-pages/man8/hwclock.8.html
>
>     The above hwclock command manpage is a great source with detailed
> info on system time and HW clock. It also talks about Automatic
> Hardware Clock Synchronization by the Kernel.
>
>     If you dual-boot your computer with Linux and macOS or Windows,
> if not having the HW clock sync correctly configured, you will run
> into issues with time delta of local timezone with UTC.
>
>     The Linux kernel must be careful to keep it's pulse of time, i.e.
> ticks/jiffies to run stable task schedul ing, process, i/o, etc.
>
>     With NTP running, kernel also keeps careful time syncing, such as
> drift compensation, to avoid jitters etc . Also the Linux kernel now
> works in a `eleven minute mode`. If NTP is used, the Linux kernel
> starts to sync the hardware clock with the system clock every eleven
> minu tes.
>
>     As Tom mentioned, the general synchronizing process as the
> NTP.org NTPD: https://linux.die.net/man/8/ntpd
>
>     NTP syncs with the local time and NTP servers in intervals and
> varied time spans.
>
>     Calculating the summed up time, the `ntptime` return NOT OK even
> in tens of minutes can be expected. In critical cases, couples of
> days might be needed to keep a stable sync.
>
>     Here is also an old link to how Linux keeps time:
>     - https://tldp.org/HOWTO/Clock-2.html
>



----

原来outlook 无法区分inline，请注意

--
Aaron

From: Aaron Shang <aaron.shang@pica8.com>
Sent: Monday, May 20, 2019 17:18
To: Iris Rong
Cc: Aaron Shang; Tracy Yang; Tom Jia; Daisy Zhao; Mikel Tang; Yachal Chen; George Guo; Richard Zhang; Frank Zhang; Vic Lan; Tong Zhang; Lin Du; Mandy Ding; Tim Yi; 'sqa'
Subject: Re: 答复: PICOS Debian package user guide

On Mon, May 20, 2019 at 04:56:17PM +0800, Iris Rong wrote:
>   > 1， Debian安装之前的版本必须是master(3.2) 版本(是通过onie install或upgrade更换的版本)；如果debian 安装前是2.11 的版本是否会有报错？

不支持在2.x版本执行deb相关操作。

>   > 2， 测试时安装顺序为：‘picos-linux’-> ‘picos-vasic’-> ‘picos-utils’-> ‘picos-xorplus’or ‘picos-ovs’；如果没有按顺序安装，是否需要测试？

必须按这个依赖顺序操作。不需要测试其他安装顺序。

>   > 3， 安装完成后查看是否image是否被更换：dpkg -l | grep picos-；l2l3和ovs是否能够正常工作；

应该列出的为新安装的版本。应该正常工作。

>   > 4， 带配置安装，检查配置是否丢失；

应该不会丢失配置。

>   > 5， 安装过程中在CLI 和/tmp/log/message不应出现err和fail信息；

应该不出现错误信息。空间不足会报错之类除外。

>   > 6， 安装platform不匹配的image, 安装时应提示错误；

应该提示。

>   > 7， 若卸载安装包，重新安装后l2l3和ovs是否能够正常工作： sudo apt remove * ， eg. sudo apt remove picos-utils

可以进行这步操作。但要保证对比之前和之后的包状态相同，不能卸载了3个包，再安装2个包，然后对比。

不要执行卸载通配符。那样会卸载很多。

因为包安装的post操作从来没有维护过，目前只有pre检查部分有测试。这部分需要进一步更新上。



----




The `service` command is just a helper for redhat-style init compatibility,
In Debian 8 and before, it is in `sysvinit-utils` package. Also `sysvinit` package is a must for Debian 7, `sysvinit-utils` package is optional.

In Debian 9 and most Debian-style distros, `service` is only from package `init-system-helpers`, another additional optional package. Usually most Debian-style deployments do not include this by default.

In Debian 8 and later, the recommended way to restart service is:
$ sudo systemctl restart picos

But the previous one can also be available:
$ sudo /etc/init.d/picos restart





----




From: James Liao <james.liao@pica8.com>
Sent: Thursday, July 30, 2020 09:18
To: Aaron Shang <aaron.shang@pica8.com>; Lin Du <lin.du@pica8.com>
Subject: Re: Debian-10 migration

Aaron,

I managed to get an hour today to try this before I got pulled out by an investor (doing project is more fun). Anyway, I was able to get a couple of small milestones.

1.	I was able to run through the whole Debian 8 build. It took only 7 minutes so I guess it only pass through the existing binary.
2.	I was able to change run.sh and enable the Debian 10 build. It stopped in the middle because of some errors in pam_radius_auth.c.

The next step for me is to change the code (I can do this), re-run the compilation (easy), and then check in the change (I don’t know how to do this). So, I guess my question is how I can create a private git copy so I can merge the code back in the future?

James

From: James Liao <james.liao@pica8.com>
Date: Wednesday, July 29, 2020 at 2:04 PM
To: Aaron Shang <aaron.shang@pica8.com>, Lin Du <lin.du@pica8.com>
Subject: Re: Debian-10 migration

Aaron,

Thanks a lot. It is hard for me to put time into this project until we pass the current crisis mode.

In my plan, I will consider only #1 as the solution. Our code needs to keep up with the tool chain.

James

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 29, 2020 at 9:15 AM
To: James Liao <james.liao@pica8.com>, Lin Du <lin.du@pica8.com>
Subject: Re: Debian-10 migration


Approach:
1.	Try Debian 10 default toolchain, fix issues one by one when met;
2.	If that is not possible, then consider to change toolchain, downgrade or upgrade. generally the later one will be more strict, for secure/effecient/optimised build result, but there might be false-negative and then recensions again.
3.	if these toolchians won't work, then we need to fine-tune default set of gcc options or autotools flags etc. to let build pass. it is possible to do that for pica/xorp/sdk each.
4.	all these are test-and-trial processes, so hard to estimate how many fixes would be needed.
5.	if possible, Cmake like layer can be added for better makefile generating. Or more modern toolchain set such as meson/ninja building can help building easier.





----



首先是邮件系统下午出现能发不能收状况, Richard在6点左右重启后恢复正常,
原因不明, 猜测是排队组件出现过问题.
另一个问题是DNS解析故障. 经dig排查,目前DNS系统内网解析正常, 但出外网解析
53端口被拒绝,原因不明,导致DNS请求超时, 指定外网dns则dig正常.
因此请大家在问题解决前先自行设置DNS,这样内部解析会有问题,
主要是code,请在自己的hosts文件将其解析到10.10.50.50
下面是推荐使用的DNS, 不在这个列表中的慎用,如某些isp的还有某114的.
nameserver  8.8.8.8 # Google Open DNS
nameserver  208.67.222.222  # OpenDNS, also 208.67.220.220
nameserver  77.88.8.8   # Yandex
nameserver  216.146.36.36 # Dyn
nameserver  89.36.220.220 # OpenNic
nameserver  64.6.64.6   # Verisign
nameserver  119.29.29.29    # Public DNS+ by DNSPod, Tencent
nameserver  223.5.5.5 # AliDNS, also 223.6.6.6

最复杂的一个问题是上周Tracy遇到Chrome访问bugzilla问题,在我和Leon机器上复现.
故障是强制跳转https.但是Firefox没问题.各种排除,如reset
cookie,都未解决.服务器并没有启用任何https.

Leon提到HSTS的提示,但服务器没有启用STS字段.

后经Mikel/Tim/Leon追踪问题,终于真相大白.简述如下.
IANA于2012年后开放了很多gTLD,现在有1528个,其中Google申请了110多个,包括我们的dev,这也相安无事.
之后RFC6797的HSTS发布并得到了主流浏览器的支持,以及陆续有进入preload.
https://en.wikipedia.org/wiki/HTTP_Strict_Transport_Security

但是上周的Chrome升级到v63,将其拥有的gTLD加入preload的HSTS列表,
于是,这个版本及以后的Chrome访问我们的dev就强行跳转https了.

还好我们的code不在现在gTLD里面,但是codes在哦.
https://en.wikipedia.org/wiki/List_of_Internet_top-level_domains

https://en.wikipedia.org/wiki/.local

其实,我们并未使用dev作为domain name,只是hostname,
最初dev的fqdn是dev.pica8.org,后来James要走了要去做开源社区,我们就启用了pica8.local域名,.local是RFC6762保留的域名.

所以我们的dev只是个昵称,同时指向这个机器的还有www/web/git/trac/mail/dns/ns1/ftp等等,他们都是.pica8.local前面的部分.

但是历史上,很多配置都是不带pica8.local这个domain的,
全部fqdn后需要改很多地方,全输入也麻烦些.

怎么解决dev的访问问题?
1. 不用63及以上的Chrome,
   或使用firefox/opera.但是相信他们也会陆续加入gtld到preload,只是时间问题.
2. 换域名, 如mikel/tim建议 - 待测试. 我建议用code:9000来取代.
3. 加HTTPS支持.
   我试过certbot用Letsencrypt,但是这个要求域名能公开解析,显然我们内部域名不能解析,pica8.org倒是很好的选择,那样我们发出的邮件也可以配置SPF/DKIM后不被reject了.




----

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, June 3, 2020 at 8:38 PM
To: Tom Jia <tom.jia@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Lisa Pi <lisa.pi@pica8.com>, Niraj Jain <niraj.jain@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
Cc: Tim Yi <tim.yi@pica8.com>, Don DeRisi <don.derisi@pica8.com>, Lin Du <lin.du@pica8.com>, "plm@pica8.com" <plm@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Re: 回复: Re: VZ AmpCon OVA testing - Issues for Upgrade - detail - troubleshoot


There is only one time/date, i.e. RTC, set by `hwclock` or `date -s`, or ntpdate, or ntpd, or any means of capable time setting facilities.
That is the system time.

There can be different time-zones for each user, i.e. set from each $TZ in case users work from different time zones.
There is one default timezone, i.e./etc/localtime, linked to zoneinfo db.

The time zone is for user experience. Users may get knowledge of the local time by simple calculating UTC/GMT plus the zone offset.


To set time zone, accurate string must be provided, such as `America/Los_Angeles`.
To our consensus, it has to be result of selection, rather than manual input, to reduce issues.
So we use system function for the selection.
The loop there is provided by that in-built system function, which we must not modify or intercept.

The time output is from RTC/hwclock, which is not related to time zone.
I think it OK because the setup is not done till now.

After the setup, you noticed the time is expected, because ntpdate/ntp set the synced time. They takes a while during syncing with external ntp servers.

Currently we collect all input first then do the setup, to not break user input sequence.
If the waiting time can be endured, we can rearrange the time syncing before the time zone setting.




----





The default will be 4 types, all SSH keys are asymmetric, ours are all default length, with no extra arguments at generating.

root@new:/etc/ssh# ssh-keygen -l -f ssh_host_dsa_key
1024 SHA256:FNjD9TawgdIqDtDUZN4Za44DBrI5hiaErSigYQ9Mf0Q root@localhost (DSA)

root@new:/etc/ssh# ssh-keygen -l -f ssh_host_rsa_key
2048 SHA256:xfpYjN07T5VYdUmzcI7ppmvwFWfzQs3P/GSEISHIYKY root@dev14 (RSA)

root@new:/etc/ssh# ssh-keygen -l -f ssh_host_ecdsa_key
256 SHA256:yP06uqTcOY9T2Jo2F4EDyZpfV7CaLSC36UWqJTXfdfY root@dev14 (ECDSA)

root@new:/etc/ssh# ssh-keygen -l -f ssh_host_ed25519_key
256 SHA256:iB4P8VYiXKIonly9Ent01KSza4KOryjZS4z4BSOa8LQ root@dev14 (ED25519)



$ man ssh-keygen | grep -A5 '\s\-b bits'
     -b bits
             Specifies the number of bits in the key to create.  For RSA keys, the minimum size is 1024 bits and the default is 2048 bits.  Generally, 2048 bits is considered
             sufficient.  DSA keys must be exactly 1024 bits as specified by FIPS 186-2.  For ECDSA keys, the -b flag determines the key length by selecting from one of three
             elliptic curve sizes: 256, 384 or 521 bits.  Attempting to use bit lengths other than these three values for ECDSA keys will fail.  Ed25519 keys have a fixed length
             and the -b flag will be ignored.






----




Debian is famous in slow cadence in upgrading main component versions.

But latest upgrades would apply latest patches. For example, latest Debian 8 Jessie would upgrade kernel to 3.16.43-2, whenever the original installed Jessie is 8.0, 8.2, or 8.5.



The problem was in our side.

The rootfs in our boxes was not `built` out, instead it was a `live` system at some very old point.

It's `live`, but living not able to upgrade.

I had tried to upgrade, only to fail the picos to start, which depends exactly on a very old GLIBC version to work. Any upgrade of kernel or basic utils would also upgrade glibc and make the GLIBC range higher than ours.


The whole rootfs in this living system was not able to upgrade components such as kernel, like usual in normal Linux distros.
We had to `chroot` into the rootfs, make maintenance, then package the rootfs as a whole.

Anyway, that was terrible.


The root cause was that the build had to rely on an exact old Debian system, where nobody dare to upgrade after my upgrade failed.

There were no stable toolchain to ensure the build can be OK anywher with that toolchain.


Richard, Jacob and I had been working to solve this long-term tricky issue.


But our efforts via Yocto would give up the ability to upgrade as standard Debian system, which was highlighted in our published whitepaper.


Ideas to make use of Debian build system to build our delivery in form of upgrade-capable picos-kernel, picos-ovs, picos-utils, picos-config, picos-base, etc. were not finally decided.


We had been discussing actively over this during the past weeks.



====




通用文本识别（OCR）功能

亚马逊云科技 OCR 解决方案提供了通用文字提取功能，可分析和识别文本资料的图像文件，获取文字及版面信息，将图像中的文字进行识别，并以文本形式返回。该方案可用于印刷体文字识别，手写材料识别，图像内容审核，出版物图像文本电子化等领域。在此部分，您将和讲师动手体验基于OCR 通用文字提取以及车牌号提取功能。





人脸检测、人脸相似度对比

亚马逊云科技 AI solution Kit 提供了人脸检测、人脸相似度对的 API 接口，并可以与亚马逊云科技提供的其它服务无缝集成。本方案根据面部特征，将检测到的五官与轮廓关键点信息映射到 64 个矢量坐标上进行人脸识别，人脸相似度比较是通过两张人脸图片中的特征向量计算余弦相似度作为置信度，根据置信度比较，从而判断是否为同一个人




亚马逊云科技的 Transcribe 是一种语音识别服务，可以轻松地将语音转文本功能添加到任何应用程序。Polly 使用深度学习技术来合成听起来自然的人类语音，让您可以将文本内容转换为语音，借助 Polly 提供的 API 将语音合成功能快速集成到应用程序中。




开始学习简单的“Hello, World!”教程以实际操作 AWS 服务控制台。





----

Dec 21
13:35	Dec 21 13:35
James Liao commented on this task
@aarons Do we have any new findings on this?

Dec 16
15:13	Dec 16 15:13
James Liao commented
@vivieny @aarons I had a call with Lin on this subject and learned more details, which helped me to understand where our disconnection is.

1.	Basically, the CPU threshold (10%, 20%, 50%) we describe here is the threshold of the Docker's usage, which is the user mode CPU utilization. Even when we put CPU threshold at 1%, as long as we don't run application, the 2Gbps traffic can still get to CPU, because it is only burning the kernel CPU cycle, but not Docker.
2.	In this case, the 2Gbps of traffic consumes certain CPU. Since the traffic is processed in batches, we are seeing spikes of CPU utilization from Linux kernel, sometimes as high as 70%. This is where we have concerns.
3.	It is not clear whether the spikes of CPU utilization impacts the PICOS operation. My guess is it does not, but there is no way to validate this until we collect enough data from the field in the future.
4.	To control the CPU spikes, we have a couple of choices,
o	Since the CPU utilization is dominated by the inbound traffic, we can provide a configuration to do speed limit on the ASIC port. This forces ASIC to drop packets when the egress buffer (to CPU) is full.
o	Another way to limit the CPU cycle is to reduce the buffer size of the CPU NICs in the kernel space. This is a plan-B workaround because the buffer size cannot be dynamically set.
Dec 14
23:08	Dec 14 23:08
James Liao commented
Vivien,
Thanks for the data. I don’t understand (2) and (4), which seem to be counter intuitive. I don’t understand how we can control the CPU at 10% but still achieve the same throughput as the CPU at 70%. There must be some discrepancy that I have overlooked.
James

Dec 14
22:30	Dec 14 22:30
Vivien Yin commented
Hi James, sorry for late reply. Because Aaron is s till looking to see if it needs to be perfected.
And according my test:
1. If we don’t set the CPU threshold, we can drive 2Gbps traffic to CPU but the CPU consumption will be 73%-76%. Correct?
<Vivien>Yes, because speed of me-1/1/1 and me-1/1/2 have 2Gbps in total. According to my test, if the CPU threshold is not set,
the max cpu cansumption is about 75%,maybe less cpu cansumptionis needed. The "Actual cpu consume value1" and "Actual cpu consume value2" in the table are the random value which is choosen when I check the cpu consume.

2. If we set the CPU threshold (between 10% and 50%), the CPU consumption will be controlled. However, in these cases, there must be packet drop. Correct?
<Vivien>No, it's right that the Cpu threshold work well. But about 2Gbps traffic to cpu in these cases, there will have no drop packets. Only greater than 2Gbps packets is driven to cpu, there will have packet drop.

3. If (2) is true, each Gbps of traffic should consume about 35% of CPU. Correct?
<Vivien>If the CPU threshold is not set, 1Gbps will consume max cpu about 35%.

4. If (3) is true, when we drive 940Mbps of traffic to CPU at 10% threshold, we must have seen packet loss. Correct?
<Vivien>No, if we drive traffic 940Mbps of traffic to CPU at 10% threshold, will have no drop packets.

Dec 10
10:01	Dec 10 10:01
James Liao commented
Vivien,
Just want to make sure I interpret your numbers correctly.
1.	If we don’t set the CPU threshold, we can drive 2Gbps traffic to CPU but the CPU consumption will be 73%-76%. Correct?
2.	If we set the CPU threshold (between 10% and 50%), the CPU consumption will be controlled. However, in these cases, there must be packet drop. Correct?
3.	If (2) is true, each Gbps of traffic should consume about 35% of CPU. Correct?
4.	If (3) is true, when we drive 940Mbps of traffic to CPU at 10% threshold, we must have seen packet loss. Correct?
I am not questioning. Just try to get my math work out.

Dec 10
00:42	Dec 10 00:42
Vivien Yin commented
Hi James, sorry for driving 3Gbps of packets but 2Gbps is ok, because the max speed of eth1(me-1/1/1) is 1G. And I have tested it. The new result is following table2.
Table2:
About 2Gbps packets to cpu port, and the cpu consume is following.
Theoretical cpu threshold value	Actual cpu consume value1	Actual cpu consume value2
Without cpu threshold value	75.97%	73.77%
10%	9.11%	9.59%
20%	20.23%	17.50%
30%	30.28%	29.81%
40%	36.02%	35.08%
50%	50.62%	48.88%

Dec 09
23:06	Dec 09 23:06
James Liao commented
Vivien, Is it possible to run another tests? Can you drive 3Gbps of packets and see how much CPU it costs? I would like to get a sense of the CPU utilization per Gbps.


This email has been limited to the 6 most recent comments. View all comments






----




About efforts to "repackage the code", or "Run code in VM or Container":
- Same efforts for packaging to standard formats, `deb`, `rpm`, `ipkg`
- Easier to debug and deploy with container
- VM needs efforts to install and run the generated packages.
- Yocto provides native container output, if no distro is preferred.








----



About efforts to "repackage the code", or "Run code in VM or Container":
- Same efforts for packaging to standard formats, `deb`, `rpm`, `ipkg`
- Easier to debug and deploy with container
- VM needs efforts to install and run the generated packages.
- Yocto provides native container output, if no distro is preferred.


--
Aaron


From: Aaron Shang
Sent: Wednesday, May 10, 2017 11:00
To: Lin Du; Clark Lee; Jeff Wang; Tim Yi; Tom Jia
Cc: George Guo; Mikel Tang; Iris Rong; Tong Zhang; Lisa Pi; Allerson Yao; Bert Yang; Alan Yu; plm@pica8.com
Subject: Re: Hardware Roadmap


Comments:
- KVM VMs are high perf VM compared to others
  - But still heavier than container
  - Need overhead for "Loading, monitoring, management of VMs"


- Container(lxc, rkt, or docker) advantage over KVM
  - High perf than KVM, isolate env but sharing host capability, not exclusive
  - Native kernel long time support. KVM needs kernel config enabled (although easy)
  - Easier to maintain, update, deploy; More lightweight.
  - Native management and control interface. KVM needs libvirt/oVirt/Qemu, etc.

As an education, we can:
  - summarize all customer needs into typical use cases,
  - set up live interactive online demo,
    - based on current solutions.

On CPU architecture:
- dpdk support includes ATOM, ARM.
  - Crypto: http://dpdk.org/doc/guides/cryptodevs/

- ARMv8 has good native aes/cipher/crypto support
  - AES encrypt/decrypt and SHA-1/SHA-2 hashing instructions, etc.
  - https://en.wikipedia.org/wiki/Comparison_of_ARMv8-A_cores



Several links:
- App layer, SW/HW
  - https://en.wikipedia.org/wiki/6WIND
  - https://en.wikipedia.org/wiki/Tilera
  - http://www.mellanox.com/page/npu_multicore_overview






----




Hi, Hai,

The following are algorithms used for SSH on our boxes.

# cipher-auth
aes128-gcm@openssh.com
aes256-gcm@openssh.com
chacha20-poly1305@openssh.com
# cipher
3des-cbc
blowfish-cbc
cast128-cbc
arcfour
arcfour128
arcfour256
aes128-cbc
aes192-cbc
aes256-cbc
rijndael-cbc@lysator.liu.se
aes128-ctr
aes192-ctr
aes256-ctr
aes128-gcm@openssh.com
aes256-gcm@openssh.com
chacha20-poly1305@openssh.com

# kex
curve25519-sha256@libssh.org
ecdh-sha2-nistp256
ecdh-sha2-nistp384
ecdh-sha2-nistp521
diffie-hellman-group-exchange-sha256
diffie-hellman-group-exchange-sha1
diffie-hellman-group14-sha1

# key
ssh-ed25519
ssh-ed25519-cert-v01@openssh.com
ssh-rsa
ssh-dss
ecdsa-sha2-nistp256
ecdsa-sha2-nistp384
ecdsa-sha2-nistp521
ssh-rsa-cert-v01@openssh.com
ssh-dss-cert-v01@openssh.com
ecdsa-sha2-nistp256-cert-v01@openssh.com
ecdsa-sha2-nistp384-cert-v01@openssh.com
ecdsa-sha2-nistp521-cert-v01@openssh.com

# key-plain
ssh-ed25519
ssh-rsa
ssh-dss
ecdsa-sha2-nistp256
ecdsa-sha2-nistp384
ecdsa-sha2-nistp521

# key-cert
ssh-ed25519-cert-v01@openssh.com
ssh-rsa-cert-v01@openssh.com
ssh-dss-cert-v01@openssh.com
ecdsa-sha2-nistp256-cert-v01@openssh.com
ecdsa-sha2-nistp384-cert-v01@openssh.com
ecdsa-sha2-nistp521-cert-v01@openssh.com

# mac
hmac-sha1
hmac-sha1-96
hmac-sha2-256
hmac-sha2-512
hmac-md5
hmac-md5-96
hmac-ripemd160
hmac-ripemd160@openssh.com
umac-64@openssh.com
umac-128@openssh.com
hmac-sha1-etm@openssh.com
hmac-sha1-96-etm@openssh.com
hmac-sha2-256-etm@openssh.com
hmac-sha2-512-etm@openssh.com
hmac-md5-etm@openssh.com
hmac-md5-96-etm@openssh.com
hmac-ripemd160-etm@openssh.com
umac-64-etm@openssh.com
umac-128-etm@openssh.com

--
Aaron

From: Hai Vo-Dinh
Sent: Monday, January 22, 2018 1:53:14 PM
To: Aaron Shang
Subject: Ssh encryption algorithm

Hi Aaron,
Lenovo is asking for the specific algorithm(s) we are using for ssh, and secure file transfer protocol. Would you please let me know?
Thanks,
Hai



----






DEFAULT_GOAL
Sets the default goal to be used if no targets were specified on the command line (see Arguments to Specify the Goals). The .DEFAULT_GOALvariable allows you to discover the current default goal, restart the default goal selection algorithm by clearing its value, or to explicitly set the default goal. The following example illustrates these cases:
# Query the default goal.
ifeq ($(.DEFAULT_GOAL),)
  $(warning no default goal is set)
endif

.PHONY: foo
foo: ; @echo $@

$(warning default goal is $(.DEFAULT_GOAL))

# Reset the default goal.
.DEFAULT_GOAL :=

.PHONY: bar
bar: ; @echo $@

$(warning default goal is $(.DEFAULT_GOAL))

# Set our own.
.DEFAULT_GOAL := foo
This makefile prints:
no default goal is set
default goal is foo
default goal is bar
foo
Note that assigning more than one target name to .DEFAULT_GOAL is invalid and will result in an error.


这个可以试试，不加option的make走这个goal，加check的则去check的


来自


https://www.gnu.org/software/make/manual/html_node/Special-Variables.html#Special-Variables





--
Aaron








-----  10.10.51.56


Starting: dropbear ssh daemon... done.
Starting: telnetd... done.
discover: Rescue mode detected.  Installer disabled.

Please press Enter to activate this console.
To check the install status inspect /var/log/onie.log.
Try this:  tail -f /var/log/onie.log

** Rescue Mode Enabled **
ONIE:/ #
ONIE:/ #
ONIE:/ #
ONIE:/ # onie-nos-install http://10.10.50.22/sonic-broadcom.bin
discover: Rescue mode detected. No discover stopped.
Info: Attempting http://10.10.50.22/sonic-broadcom.bin ...
Connecting to 10.10.50.22 (10.10.50.22:80)
installer            100% |*******************************|  1004M  0:00:00 ETA
ONIE: Executing installer: http://10.10.50.22/sonic-broadcom.bin
Verifying image checksum ... OK.
Preparing image archive ... OK.
Installing SONiC in ONIE
ONIE Installer: platform: x86_64-broadcom-r0
onie_platform: x86_64-accton_as7726_32x-r0
Partition #1 is in use.
Partition #2 is in use.
Partition #3 is in use.
Partition #4 is in use.
Partition #5 is in use.
Partition #6 is in use.
Partition #7 is in use.
Partition #8 is available
Creating new SONiC-OS partition /dev/sda8 ...
Could not create partition 8 from 34 to 67108897
Unable to set partition 8's name to 'SONiC-OS'!
Error encountered; not saving changes.
Warning: The first trial of creating partition failed, trying the largest aligned available block of sectors on the disk
Warning: The kernel is still using the old partition table.
The new table will be used at the next reboot.
The operation has completed successfully.
mke2fs 1.42.13 (17-May-2015)

Filesystem too small for a journal
Creating filesystem with 1004 1k blocks and 128 inodes

Allocating group tables: done
Writing inode tables: done
Writing superblocks and filesystem accounting information: done

Installing SONiC to /tmp/tmp.OyGZkn/image-master.314321-dc5258eed
Archive:  fs.zip
   creating: boot/
  inflating: boot/initrd.img-5.10.0-18-2-amd64
unzip: write: No space left on device
unzip: inflate error
Failure: Unable to install image: http://10.10.50.22/sonic-broadcom.bin
ONIE:/ # df
Filesystem           1K-blocks      Used Available Use% Mounted on
devtmpfs               8150084         0   8150084   0% /dev
tmpfs                    10240        24     10216   0% /run
tmpfs                    10240         0     10240   0% /run/lock
tmpfs                  8155704         0   8155704   0% /tmp
tmpfs                  8155704         0   8155704   0% /var/tmp
tmpfs                  8155704         0   8155704   0% /run/shm
/dev/sda2               122835     15698     97963  14% /mnt/onie-boot
ONIE:/ # gdisk /dev/sda
GPT fdisk (gdisk) version 0.8.8

Partition table scan:
  MBR: protective
  BSD: not present
  APM: not present
  GPT: present

Found valid GPT with protective MBR; using GPT.

Command (? for help): p
Disk /dev/sda: 125045424 sectors, 59.6 GiB
Logical sector size: 512 bytes
Disk identifier (GUID): A9AC284A-8189-47B0-AE7B-C87FC8BE5544
Partition table holds up to 128 entries
First usable sector is 34, last usable sector is 125045390
Partitions will be aligned on 2-sector boundaries
Total free space is 0 sectors (0 bytes)

Number  Start (sector)    End (sector)  Size       Code  Name
   1            2048            6143   2.0 MiB     EF02  GRUB-BOOT
   2            6144          268287   128.0 MiB   3000  ONIE-BOOT
   3          268288         4462591   2.0 GiB     8300  ACCTON-DIAG
   4         4462592         4495359   16.0 MiB    8300  PICOS
   5         4495360         8689663   2.0 GiB     8300  PICOS
   6         8689664        12883967   2.0 GiB     8300  PICOS
   7        12883968       125045390   53.5 GiB    8300  Linux filesystem
   8              34            2047   1007.0 KiB  8300  SONiC-OS

Command (? for help): d
Partition number (1-8): 8

Command (? for help): d
Partition number (1-7): 7

Command (? for help): d
Partition number (1-6): 6

Command (? for help): d
Partition number (1-5): 5

Command (? for help): d
Partition number (1-4): 4

Command (? for help): p
Disk /dev/sda: 125045424 sectors, 59.6 GiB
Logical sector size: 512 bytes
Disk identifier (GUID): A9AC284A-8189-47B0-AE7B-C87FC8BE5544
Partition table holds up to 128 entries
First usable sector is 34, last usable sector is 125045390
Partitions will be aligned on 2-sector boundaries
Total free space is 120584813 sectors (57.5 GiB)

Number  Start (sector)    End (sector)  Size       Code  Name
   1            2048            6143   2.0 MiB     EF02  GRUB-BOOT
   2            6144          268287   128.0 MiB   3000  ONIE-BOOT
   3          268288         4462591   2.0 GiB     8300  ACCTON-DIAG

Command (? for help): w

Final checks complete. About to write GPT data. THIS WILL OVERWRITE EXISTING
PARTITIONS!!

Do you want to proceed? (Y/N):
(Y/N): y
OK; writing new GUID partition table (GPT) to /dev/sda.
Warning: The kernel is still using the old partition table.
The new table will be used at the next reboot.
The operation has completed successfully.
ONIE:/ # partprobe
ONIE:/ #
ONIE:/ #
ONIE:/ # onie-nos-install http://10.10.50.22/sonic-broadcom.bin
discover: Rescue mode detected. No discover stopped.
Info: Attempting http://10.10.50.22/sonic-broadcom.bin ...
Connecting to 10.10.50.22 (10.10.50.22:80)
installer            100% |*******************************|  1004M  0:00:00 ETA
ONIE: Executing installer: http://10.10.50.22/sonic-broadcom.bin
Verifying image checksum ... OK.
Preparing image archive ... OK.
Installing SONiC in ONIE
ONIE Installer: platform: x86_64-broadcom-r0
onie_platform: x86_64-accton_as7726_32x-r0
Partition #1 is in use.
Partition #2 is in use.
Partition #3 is in use.
Partition #4 is available
Creating new SONiC-OS partition /dev/sda4 ...
Warning: The kernel is still using the old partition table.
The new table will be used at the next reboot.
The operation has completed successfully.
mke2fs 1.42.13 (17-May-2015)
Discarding device blocks: done
Creating filesystem with 8388608 4k blocks and 2097152 inodes
Filesystem UUID: 1d547123-9209-4e9d-bb5b-2ad5552bec8e
Superblock backups stored on blocks:
        32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208,
        4096000, 7962624

Allocating group tables: done
Writing inode tables: done
Creating journal (32768 blocks): done
Writing superblocks and filesystem accounting information: done

Installing SONiC to /tmp/tmp.7i4zQN/image-master.314321-dc5258eed
Archive:  fs.zip
   creating: boot/
  inflating: boot/initrd.img-5.10.0-18-2-amd64
  inflating: boot/config-5.10.0-18-2-amd64
  inflating: boot/System.map-5.10.0-18-2-amd64
  inflating: boot/vmlinuz-5.10.0-18-2-amd64
  inflating: fs.squashfs
ONIE_IMAGE_PART_SIZE=32768
EXTRA_CMDLINE_LINUX=
Success: Support tarball created: /tmp/onie-support-accton_as7726_32x.tar.bz2
firmware=bios
Installing for i386-pc platform.
Installation finished. No error reported.
Switch CPU vendor is: GenuineIntel
Switch CPU cstates are: disabled
cp /tmp/tmp.vvGPVP /boot/efi/EFI/debian/grub.cfg
EXTRA_CMDLINE_LINUX=
Installed SONiC base image SONiC-OS successfully
ONIE: NOS install successful: http://10.10.50.22/sonic-broadcom.bin
ONIE: Rebooting...
ONIE:/ # discover: Rescue mode detected. No discover stopped.
Stopping: dropbear ssh daemon... done.
Stopping: telnetd... done.
Stopping: klogd... done.
Stopping: syslogd... done.
Info: Unmounting kernel filesystems
umount: devtmpfs busy - remounted read-only
umount: can't unmount /: Invalid argument
The system is going down NOW!
Sent SIGTERM to all processes
Sent SIGKILL toreboot: Restarting system
























                                                                             A2
Version 2.19.1269. Copyright (C) 2018 American Megatrends, Inc.
BIOS Date: 08/06/2018 10:06:37 Ver: AS7726 V36 20180806
Press <DEL> or <ESC> to enter setup.
























Welcome to GRUB!
                          GNU GRUB  version 2.02~beta3

 ******************************************************************************
 **SONiC-OS-master.314321-dc5258eed                                           *
 * ONIE                                                                       *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************

      Use the * and * keys to select which entry is highlighted.
      Press enter to boot the selected OS, `e' to edit the commands
      before booting or `c' for a command-line.
   The highlighted entry will be executed automatically in 0s.



Loading SONiC-OS OS kernel ...                                                  Loading SONiC-OS OS initial ramdisk ...
Loading SONiC-OS OS initial ramdisk ...



                                                                                tune2fs 1.46.2 (28-Feb-2021)
Setting reserved blocks percentage to 0% (0 blocks)
Setting reserved blocks count to 0
[    5.245253] rc.local[581]: + cat /etc/sonic/sonic_version.yml
[    5.261583] rc.local[583]: +
[    5.277494] rc.local[582]: +
[    5.292816] rc.local[583]: sed -e s/build_version: //g;s/'//g
[    5.300312] rc.local[582]: grep build_version
[    5.317676] rc.local[576]: + SONIC_VERSION=master.314321-dc5258eed
[    5.334383] rc.local[576]: + FIRST_BOOT_FILE=/host/image-master.314321-dc5258eed/platform/firsttime
[    5.352769] rc.local[576]: + SONIC_CONFIG_DIR=/host/image-master.314321-dc5258eed/sonic-config
[    5.368756] rc.local[576]: + SONIC_ENV_FILE=/host/image-master.314321-dc5258eed/sonic-config/sonic-environment
[    5.380742] rc.local[576]: + [ -d /host/image-master.314321-dc5258eed/sonic-config -a -f /host/image-master.314321-dc5258eed/sonic-config/sonic-environment ]
[    5.406554] rc.local[576]: + logger SONiC version master.314321-dc5258eed starting up...
[    5.437746] rc.local[576]: + grub_installation_needed=
[    5.456754] rc.local[576]: + [ ! -e /host/machine.conf ]
[    5.472718] rc.local[576]: + . /host/machine.conf
[    5.478494] rc.local[576]: + onie_arch=x86_64
[    5.496750] rc.local[576]: + onie_bin=
[    5.508756] rc.local[576]: + onie_boot_reason=rescue
[    5.524754] rc.local[576]: + onie_build_date=2018-02-08T21:53+0800
[    5.540766] rc.local[576]: + onie_build_machine=accton_as7726_32x
[    5.556750] rc.local[576]: + onie_build_platform=x86_64-accton_as7726_32x-r0
[    5.572849] rc.local[576]: + onie_cli_static_parms=
[    5.588788] rc.local[576]: + onie_cli_static_url=http://10.10.50.22/sonic-broadcom.bin
[    5.604793] rc.local[576]: + onie_config_version=1
[    5.620758] rc.local[576]: + onie_dev=/dev/sda2
[    5.636763] rc.local[576]: + onie_exec_url=http://10.10.50.22/sonic-broadcom.bin
[    5.652745] rc.local[576]: + onie_firmware=auto
[    5.668757] rc.local[576]: + onie_grub_image_name=grubx64.efi
[    5.684738] rc.local[576]: + onie_initrd_tmp=/
[    5.700724] rc.local[576]: + onie_installer=/var/tmp/installer
[    5.716758] rc.local[576]: + onie_kernel_version=4.9.57
[    5.732859] rc.local[576]: + onie_machine=accton_as7726_32x
[    5.748740] rc.local[576]: + onie_machine_rev=0
[    5.764759] rc.local[576]: + onie_partition_type=gpt
[    5.780724] rc.local[576]: + onie_platform=x86_64-accton_as7726_32x-r0
[    5.796714] rc.local[576]: + onie_root_dir=/mnt/onie-boot/onie
[    5.812742] rc.local[576]: + onie_skip_ethmgmt_macs=no
[    5.828721] rc.local[576]: + onie_switch_asic=bcm
[    5.844725] rc.local[576]: + onie_vendor_id=259
[    5.860760] rc.local[576]: + onie_version=2017.11.00.05
[    5.876724] rc.local[576]: + program_console_speed
[    5.896052] kdump-tools[567]: Starting kdump-tools:
[    5.912922] rc.local[592]: + cat /proc/cmdline
[    5.930224] kdump-tools[623]: no crashkernel= parameter in the kernel cmdline ...
[    5.948863] kdump-tools[734]:  failed!
[    5.960945] rc.local[593]: + grep -Eo console=tty(S|AMA)[0-9]+,[0-9]+
[    5.977404] rc.local[597]: + cut -d , -f2
[    5.990229] rc.local[576]: + speed=115200
[    6.004793] rc.local[576]: + [ -z 115200 ]
[    6.016728] rc.local[576]: + CONSOLE_SPEED=115200
[    6.035381] rc.local[605]: +
[    6.049741] rc.local[604]: +
[    6.064709] rc.local[605]: grep keep-baud
[    6.076931] rc.local[604]: grep agetty /lib/systemd/system/serial-getty@.service
[    6.097201] rc.local[605]: ExecStart=-/sbin/agetty -o '-p -- \\u' --keep-baud 115200,57600,38400,9600 %I $TERM
[    6.117044] rc.local[576]: + [ 0 = 0 ]
[    6.128767] rc.local[576]: + sed -i s|\-\-keep\-baud .* %I| 115200 %I|g /lib/systemd/system/serial-getty@.service
[    6.148717] rc.local[576]: + systemctl daemon-reload
[    6.164765] rc.local[576]: + [ -f /host/image-master.314321-dc5258eed/platform/firsttime ]
[    6.180752] rc.local[576]: + echo First boot detected. Performing first boot tasks...
[    6.196746] rc.local[576]: First boot detected. Performing first boot tasks...
[    6.212724] rc.local[576]: + [ -n  ]
[    6.224726] rc.local[576]: + [ -n x86_64-accton_as7726_32x-r0 ]
[    6.240805] rc.local[576]: + platform=x86_64-accton_as7726_32x-r0
[    6.260739] rc.local[576]: + [ -d /host/old_config ]
[    6.276751] rc.local[576]: + [ -f /host/minigraph.xml ]
[    6.292745] rc.local[576]: + [ -n  ]
[    6.304755] rc.local[576]: + touch /tmp/pending_config_initialization
[    6.321030] rc.local[576]: + touch /tmp/notify_firstboot_to_platform
[    6.336749] rc.local[576]: + [ ! -d /host/reboot-cause/platform ]
[    6.352748] rc.local[576]: + mkdir -p /host/reboot-cause/platform
[    6.368717] rc.local[576]: + [ -d /host/image-master.314321-dc5258eed/platform/x86_64-accton_as7726_32x-r0 ]
[    6.388761] rc.local[576]: + [ -f /host/image-master.314321-dc5258eed/platform/common/Packages.gz ]
[    6.408741] rc.local[576]: + mv /etc/apt/sources.list /etc/apt/sources.list.rc-local
[    6.424747] rc.local[576]: + echo deb [trusted=yes] file:///host/image-master.314321-dc5258eed/platform/common /
[    6.444764] rc.local[576]: + LANG=C DEBIAN_FRONTEND=noninteractive apt-get update
[    6.461340] rc.local[735]: Get:1 file:/host/image-master.314321-dc5258eed/platform/common  InRelease
[    6.480745] rc.local[735]: Ign:1 file:/host/image-master.314321-dc5258eed/platform/common  InRelease
[    6.500779] rc.local[735]: Get:2 file:/host/image-master.314321-dc5258eed/platform/common  Release
[    6.520749] rc.local[735]: Ign:2 file:/host/image-master.314321-dc5258eed/platform/common  Release
[    6.544752] rc.local[735]: Get:3 file:/host/image-master.314321-dc5258eed/platform/common  Packages [7190 B]
[    6.564740] rc.local[735]: Reading package lists...
[    6.582495] rc.local[576]: + LANG=C DEBIAN_FRONTEND=noninteractive apt-get -o DPkg::Path=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/bin -y install /host/image-master.314321-dc5258eed/platform/x86_64-accton_as7726_32x-r0/sonic-platform-accton-as7726-32x_1.1_amd64.deb
[    6.621505] rc.local[753]: Reading package lists...
[    6.636735] rc.local[753]: Building dependency tree...
[    6.652762] rc.local[753]: Reading state information...
[    6.668755] rc.local[753]: The following NEW packages will be installed:
[    6.688743] rc.local[753]:   sonic-platform-accton-as7726-32x
[    6.708735] rc.local[753]: 0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.
[    6.728747] rc.local[753]: Need to get 0 B/279 kB of archives.
[    6.748709] rc.local[753]: After this operation, 2176 kB of additional disk space will be used.
[    6.768714] rc.local[753]: Get:1 file:/host/image-master.314321-dc5258eed/platform/common  sonic-platform-accton-as7726-32x 1.1 [279 kB]
[    6.793106] rc.local[764]: debconf: delaying package configuration, since apt-utils is not installed
[    6.813015] rc.local[753]: Selecting previously unselected package sonic-platform-accton-as7726-32x.
(Reading database ... 39393 files and directories currently installed.)
[    6.904865] rc.local[753]: Preparing to unpack .../sonic-platform-accton-as7726-32x_1.1_amd64.deb ...
[    6.924829] rc.local[753]: Unpacking sonic-platform-accton-as7726-32x (1.1) ...
[    7.393935] rc.local[753]: Setting up sonic-platform-accton-as7726-32x (1.1) ...
[   13.897722] PDDF_ERROR: dev_operation: Invalid value for dev_ops STATUS_LED_COLOR_BLUE
[   13.913976] PDDF_ERROR: dev_operation: Invalid value for dev_ops STATUS_LED_COLOR_OFF
[   13.929918] PDDF_ERROR: dev_operation: Invalid value for dev_ops STATUS_LED_COLOR_GREEN
[   13.945535] PDDF_ERROR: dev_operation: Invalid value for dev_ops STATUS_LED_COLOR_RED
[   13.960902] PDDF_ERROR: dev_operation: Invalid value for dev_ops STATUS_LED_COLOR_OFF
[   15.428224] rc.local[576]: + rm -f /etc/apt/sources.list.d/sonic_debian_extension.list
[   15.444813] rc.local[576]: + rm -f /var/lib/apt/lists/_host_image-master.314321-dc5258eed_platform_common_Packages.lz4
[   15.464759] rc.local[576]: + mv /etc/apt/sources.list.rc-local /etc/apt/sources.list
[   15.480712] rc.local[576]: + sync
[   15.511436] rc.local[576]: + [ -n x86_64-accton_as7726_32x-r0 ]
[   15.528791] rc.local[576]: + [ -n  ]
[   15.540776] rc.local[576]: + mkdir -p /var/platform
[   15.556847] rc.local[576]: + [ -f /etc/default/kdump-tools ]
[   15.572780] rc.local[576]: + sed -i -e s/__PLATFORM__/x86_64-accton_as7726_32x-r0/g /etc/default/kdump-tools
[   15.592773] rc.local[576]: + firsttime_exit
[   15.604777] rc.local[576]: + rm -rf /host/image-master.314321-dc5258eed/platform/firsttime
[   15.624786] rc.local[576]: + exit 0

Debian GNU/Linux 11 sonic ttyS0

sonic login: admin
Password:

Login incorrect
sonic login: admin
Password:
Linux sonic 5.10.0-18-2-amd64 #1 SMP Debian 5.10.140-1 (2022-09-02) x86_64
You are on
  ____   ___  _   _ _  ____
 / ___| / _ \| \ | (_)/ ___|
 \___ \| | | |  \| | | |
  ___) | |_| | |\  | | |___
 |____/ \___/|_| \_|_|\____|

-- Software for Open Networking in the Cloud --

Unauthorized access and/or use are prohibited.
All access and/or use are subject to monitoring.

Help:    https://sonic-net.github.io/SONiC/

admin@sonic:~$ sudo passwd admin
New password:
BAD PASSWORD: it is too short
BAD PASSWORD: is too simple
Retype new password:
passwd: password updated successfully
admin@sonic:~$ ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/16 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host
       valid_lft forever preferred_lft forever
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.10.51.56/24 brd 10.10.51.255 scope global dynamic eth0
       valid_lft 3501sec preferred_lft 3501sec
    inet6 fe80::3e2c:99ff:fef8:dc40/64 scope link
       valid_lft forever preferred_lft forever
3: eth1: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:41 brd ff:ff:ff:ff:ff:ff
4: eth2: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:42 brd ff:ff:ff:ff:ff:ff
5: bcm0: <BROADCAST,MULTICAST> mtu 9100 qdisc noop state DOWN group default qlen 1000
    link/ether 02:10:18:ea:78:02 brd ff:ff:ff:ff:ff:ff
6: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:d4:f9:a3:7d brd ff:ff:ff:ff:ff:ff
    inet 240.127.1.1/24 brd 240.127.1.255 scope global docker0
       valid_lft forever preferred_lft forever
    inet6 fd00::1/80 scope global
       valid_lft forever preferred_lft forever
    inet6 fe80::1/64 scope link
       valid_lft forever preferred_lft forever
7: Ethernet0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.0/31 scope global Ethernet0
       valid_lft forever preferred_lft forever
8: Ethernet4: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.2/31 scope global Ethernet4
       valid_lft forever preferred_lft forever
9: Ethernet8: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.4/31 scope global Ethernet8
       valid_lft forever preferred_lft forever
10: Ethernet12: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.6/31 scope global Ethernet12
       valid_lft forever preferred_lft forever
11: Ethernet16: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.8/31 scope global Ethernet16
       valid_lft forever preferred_lft forever
12: Ethernet20: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.10/31 scope global Ethernet20
       valid_lft forever preferred_lft forever
13: Ethernet24: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.12/31 scope global Ethernet24
       valid_lft forever preferred_lft forever
14: Ethernet28: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.14/31 scope global Ethernet28
       valid_lft forever preferred_lft forever
15: Ethernet32: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.16/31 scope global Ethernet32
       valid_lft forever preferred_lft forever
16: Ethernet36: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.18/31 scope global Ethernet36
       valid_lft forever preferred_lft forever
17: Ethernet40: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.20/31 scope global Ethernet40
       valid_lft forever preferred_lft forever
18: Ethernet44: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.22/31 scope global Ethernet44
       valid_lft forever preferred_lft forever
19: Ethernet48: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.24/31 scope global Ethernet48
       valid_lft forever preferred_lft forever
20: Ethernet52: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.26/31 scope global Ethernet52
       valid_lft forever preferred_lft forever
21: Ethernet56: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.28/31 scope global Ethernet56
       valid_lft forever preferred_lft forever
22: Ethernet60: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.30/31 scope global Ethernet60
       valid_lft forever preferred_lft forever
23: Ethernet64: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.32/31 scope global Ethernet64
       valid_lft forever preferred_lft forever
24: Ethernet68: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.34/31 scope global Ethernet68
       valid_lft forever preferred_lft forever
25: Ethernet72: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.36/31 scope global Ethernet72
       valid_lft forever preferred_lft forever
26: Ethernet76: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.38/31 scope global Ethernet76
       valid_lft forever preferred_lft forever
27: Ethernet80: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.40/31 scope global Ethernet80
       valid_lft forever preferred_lft forever
28: Ethernet84: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.42/31 scope global Ethernet84
       valid_lft forever preferred_lft forever
29: Ethernet88: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.44/31 scope global Ethernet88
       valid_lft forever preferred_lft forever
30: Ethernet92: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.46/31 scope global Ethernet92
       valid_lft forever preferred_lft forever
31: Ethernet96: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.48/31 scope global Ethernet96
       valid_lft forever preferred_lft forever
32: Ethernet100: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.50/31 scope global Ethernet100
       valid_lft forever preferred_lft forever
33: Ethernet104: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.52/31 scope global Ethernet104
       valid_lft forever preferred_lft forever
34: Ethernet108: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.54/31 scope global Ethernet108
       valid_lft forever preferred_lft forever
35: Ethernet112: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.56/31 scope global Ethernet112
       valid_lft forever preferred_lft forever
36: Ethernet116: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.58/31 scope global Ethernet116
       valid_lft forever preferred_lft forever
37: Ethernet120: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.60/31 scope global Ethernet120
       valid_lft forever preferred_lft forever
38: Ethernet124: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.62/31 scope global Ethernet124
       valid_lft forever preferred_lft forever
39: Bridge: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 9100 qdisc noqueue state DOWN group default qlen 1000
    link/ether 3c:2c:99:f8:dc:40 brd ff:ff:ff:ff:ff:ff
    inet6 fe80::dcfd:e5ff:fec3:9710/64 scope link
       valid_lft forever preferred_lft forever
40: dummy: <BROADCAST,NOARP> mtu 1500 qdisc noop master Bridge state DOWN group default qlen 1000
    link/ether 0e:ed:4d:b8:33:e9 brd ff:ff:ff:ff:ff:ff
41: Loopback0: <BROADCAST,NOARP,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/ether 9a:df:9e:b7:a9:76 brd ff:ff:ff:ff:ff:ff
    inet 10.1.0.1/32 scope global Loopback0
       valid_lft forever preferred_lft forever
    inet6 fe80::98df:9eff:feb7:a976/64 scope link
       valid_lft forever preferred_lft forever
admin@sonic:~$
admin@sonic:~$ sho
shopt  show
admin@sonic:~$ sho
shopt  show
admin@sonic:~$ sho
shopt  show
admin@sonic:~$ show
aaa                       ipv6                      reboot-cause
acl                       kdump                     route-map
arp                       kubernetes                runningconfiguration
auto-techsupport          line                      services
auto-techsupport-feature  lldp                      sflow
bfd                       logging                   snmpagentaddress
boot                      mac                       snmptrap
buffer                    macsec                    startupconfiguration
buffer_pool               management_interface      storm-control
chassis                   mgmt-vrf                  subinterfaces
clock                     mirror_session            suppress-fib-pending
dhcp6relay_counters       mmu                       switch-hash
dhcp_relay                muxcable                  syslog
dhcprelay_helper          nat                       system-health
dns                       ndp                       system-memory
dropcounters              ntp                       tacacs
ecn                       nvgre-tunnel              techsupport
environment               nvgre-tunnel-map          uptime
event-counters            passw-hardening           users
fabric                    pbh                       version
feature                   pfc                       vlan
fgnhg                     pfcwd                     vnet
flowcnt-route             platform                  vrf
admin@sonic:~$ show version

SONiC Software Version: SONiC.master.314321-dc5258eed
SONiC OS Version: 11
Distribution: Debian 11.7
Kernel: 5.10.0-18-2-amd64
Build commit: dc5258eed
Build date: Thu Jul 13 13:31:39 UTC 2023
Built by: AzDevOps@vmss-soni001J11

Platform: x86_64-accton_as7726_32x-r0
HwSKU: Accton-AS7726-32X
ASIC: broadcom
ASIC Count: 1
Serial Number: 772632X1830021
Model Number: FP3ZZ7632074A
Hardware Revision: N/A
Uptime: 11:58:07 up 2 min,  1 user,  load average: 1.24, 0.71, 0.29
Date: Thu 22 Dec 2022 11:58:07

Docker images:
REPOSITORY                    TAG                       IMAGE ID       SIZE
docker-gbsyncd-broncos        latest                    a3dfd3034426   348MB
docker-gbsyncd-broncos        master.314321-dc5258eed   a3dfd3034426   348MB
docker-gbsyncd-credo          latest                    197a00c2861d   319MB
docker-gbsyncd-credo          master.314321-dc5258eed   197a00c2861d   319MB
docker-syncd-brcm             latest                    5aeb510883c7   673MB
docker-syncd-brcm             master.314321-dc5258eed   5aeb510883c7   673MB
docker-orchagent              latest                    ea2aeda69400   335MB
docker-orchagent              master.314321-dc5258eed   ea2aeda69400   335MB
docker-fpm-frr                latest                    e77922525a75   352MB
docker-fpm-frr                master.314321-dc5258eed   e77922525a75   352MB
docker-nat                    latest                    f0824a9e8907   326MB
docker-nat                    master.314321-dc5258eed   f0824a9e8907   326MB
docker-sflow                  latest                    b0f6e90c5730   324MB
docker-sflow                  master.314321-dc5258eed   b0f6e90c5730   324MB
docker-teamd                  latest                    025c28d5f4e3   323MB
docker-teamd                  master.314321-dc5258eed   025c28d5f4e3   323MB
docker-macsec                 latest                    b5e5a93c84f2   325MB
docker-dhcp-relay             latest                    1926d2429a64   306MB
docker-eventd                 latest                    e78c62c1a924   299MB
docker-eventd                 master.314321-dc5258eed   e78c62c1a924   299MB
docker-sonic-p4rt             latest                    e168d14a5511   870MB
docker-sonic-p4rt             master.314321-dc5258eed   e168d14a5511   870MB
docker-snmp                   latest                    16445b62b393   338MB
docker-snmp                   master.314321-dc5258eed   16445b62b393   338MB
docker-sonic-telemetry        latest                    ec273faddde6   599MB
docker-sonic-telemetry        master.314321-dc5258eed   ec273faddde6   599MB
docker-router-advertiser      latest                    9a4355ee4f41   299MB
docker-router-advertiser      master.314321-dc5258eed   9a4355ee4f41   299MB
docker-platform-monitor       latest                    c3f4d71ea35f   420MB
docker-platform-monitor       master.314321-dc5258eed   c3f4d71ea35f   420MB
docker-lldp                   latest                    1ba5294a0c98   341MB
docker-lldp                   master.314321-dc5258eed   1ba5294a0c98   341MB
docker-mux                    latest                    640b92b6bb24   347MB
docker-mux                    master.314321-dc5258eed   640b92b6bb24   347MB
docker-database               latest                    89aeeae0a3cb   299MB
docker-database               master.314321-dc5258eed   89aeeae0a3cb   299MB
docker-sonic-mgmt-framework   latest                    4958ac96fddb   415MB
docker-sonic-mgmt-framework   master.314321-dc5258eed   4958ac96fddb   415MB




----




The original vlan-interface configurations have been replaced by the following configurations as below. Please refer the details in the attachments.

l3-interface {
    vlan-interface "vlan2_l3" {
        dhcp: false
        mtu: 1500
        address 192.168.2.1 {
            prefix-length: 22
        }
    }
    vlan-interface "vlan10_l3" {
        dhcp: false
        mtu: 1500
        address 10.65.204.173 {
            prefix-length: 24
        }
    }
    vlan-interface "vlan20_l3" {
        dhcp: false
        mtu: 1500
        address 192.168.48.1 {
            prefix-length: 22
        }
    }
    vlan-interface "vlan40_l3" {
…

Please let us know if I do not answer your question.

Thanks,

Zoneson
From: Rafael Bezerra <rafael@openglobe.com.br>





----

Hi Vic,

I can create the symptom. Here is the console outputs:

admin@PICOS-OVS$./a.sh &
[1] 2794
admin@PICOS-OVS$./b.sh &
[2] 6913
admin@PICOS-OVS$BUG: unable to handle kernel NULL pointer dereference at           (null)
IP: [<ffffffff8145b80f>] __mutex_lock_slowpath+0x11a/0x1c0
PGD 272438067 PUD 275db9067 PMD 0
Oops: 0002 [#1] SMP
Modules linked in: linux_user_bde(PO) linux_kernel_bde(PO) ctrl(O) led(O) psu(O) qsfp(O) sfp(O) i2c_mux_cpld(O) hwinfo sffcore swmon lm75 iTCO_wdt iTCO_vendor_support ip6t_MASQUERADE ip6t_NPT ip6t_frag ip6t_REJECT ip6table_nat ip6table_mangle ip6table_filter ip6_tables nf_nat_ipv6 ipt_REJECT ipt_MASQUERADE iptable_nat iptable_mangle iptable_filter ip_tables nf_nat_ipv4 xt_REDIRECT xt_NETMAP xt_nat nf_nat xt_mac xt_dscp xt_NFLOG xt_LOG xt_mark
CPU: 0 PID: 6927 Comm: cat Tainted: P           O  3.16.7-ckt11 #1
Hardware name: Accton AS5712-54X/To be filled by O.E.M., BIOS 5.6.5 11/20/2014
task: ffff880275633b80 ti: ffff88007a6d8000 task.ti: ffff88007a6d8000
RIP: 0010:[<ffffffff8145b80f>]  [<ffffffff8145b80f>] __mutex_lock_slowpath+0x11a/0x1c0
RSP: 0018:ffff88007a6dbd28  EFLAGS: 00010286
RAX: 0000000000000000 RBX: ffff88007a107428 RCX: 00000000c0000100
RDX: ffff88007a6dbd30 RSI: ffff880275633b80 RDI: ffff88007a10742c
RBP: ffff88007a6dbd78 R08: ffff88007a6d8000 R09: 000000000000ba9a
R10: 00007f24900f87d0 R11: 0000000000000001 R12: ffff88007a10742c
R13: ffff880275633b80 R14: ffff88007a107430 R15: 00000000ffffffff
FS:  00007f9288759700(0000) GS:ffff88027fc00000(0000) knlGS:0000000000000000
CS:  0010 DS: 0000 ES: 0000 CR0: 000000008005003b
CR2: 0000000000000000 CR3: 000000027249b000 CR4: 00000000001007b0
Stack:
ffff88007a6dbf24 ffff88007a107430 0000000000000000 ffff8802740276c0
ffff88007a6dbd68 ffff88007a107428 ffffffffa00ac97c ffff88007a6dbf50
ffff880272ba8780 ffff880275f23200 ffff88007a6dbd98 ffffffff8145b8c9
Call Trace:
[<ffffffff8145b8c9>] mutex_lock+0x14/0x25
[<ffffffffa00ac2b6>] sync_ctrldata+0x1d/0x15a [ctrl]
[<ffffffffa00ac4fb>] show_fan+0x16/0x33 [ctrl]
[<ffffffff811e0f95>] kobj_attr_show+0xf/0x1b
[<ffffffff8113eaaf>] sysfs_kf_seq_show+0x80/0xca
[<ffffffff8113da1d>] kernfs_seq_show+0x1b/0x1d
[<ffffffff81109f32>] seq_read+0x14e/0x318
[<ffffffff8113dfad>] kernfs_fop_read+0x31/0x114
[<ffffffff81104c20>] ? __fget_light+0x27/0x48
[<ffffffff810efd64>] vfs_read+0x8c/0xfc
[<ffffffff810ef1c3>] ? fdget_pos+0xd/0x19
[<ffffffff81104c20>] ? __fget_light+0x27/0x48
[<ffffffff810efee6>] SyS_read+0x4d/0x7f
[<ffffffff8145d0c9>] system_call_fastpath+0x16/0x1b
Code: 04 4c 89 e7 e8 3f 7f c3 ff 8b 03 85 c0 79 25 48 8b 43 10 48 8d 55 b8 4c 8d 73 08 41 83 cf ff 48 89 53 10 4c 89 75 b8 48 89 45 c0 <48> 89 10 4c 89 6d c8 eb 0a 31 c0 87 03 ff c8 75 d3 eb 5e 8b 03
RIP  [<ffffffff8145b80f>] __mutex_lock_slowpath+0x11a/0x1c0
RSP <ffff88007a6dbd28>
CR2: 0000000000000000
---[ end trace 4b0729e6d3381b63 ]---
Kernel panic - not syncing: Fatal exception
Kernel Offset: 0x0 from 0xffffffff81000000 (relocation range: 0xffffffff80000000-0xffffffff9fffffff)
Rebooting in 180 seconds..

Thanks,

Zoneson

From: Vic Lan <vic.lan@pica8.com>
Date: Tuesday, December 15, 2020 at 6:42 PM
To: Tom Jia <tom.jia@pica8.com>, James Liao <james.liao@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171
Hi James,

FAN code in 2.11.3.verizon is *exactly* a function like the example we gave in last email:
    mutex_lock(p);
    memset(p, 0, sizeof (struct mutex)); <<----- ROOT CAUSE
    /* here will collect fan data for users */
    mutex_unlock(p);

So it must be a lock bug.
If many calls enters this function, it is a concurrent case. It will crash.

I have reproduced this problem, and you can also do it easily.
Create a script, and run it at the same time:
a.sh:
while [ 1 ]; do
        cat /sys/class/swmon/ctrl/fan*_input > /dev/null
done
b.sh:
while [ 1 ]; do
        cat /sys/class/swmon/ctrl/*temp* > /dev/null
done

Run it at the same time:
./a.sh &
./b.sh &

It will crash within 5 seconds for highest pressure scripts.
The attachments are crash texts by the two scripts.
For it is a concurrent bug, so the crash style will be more.


Confirmed with tim, many (2 or more) process will call this interface( /sys/class/swmon/ctrl/*) in ovs code.
So it is the cause in OVS:
one process want to get temperature, another process want to get fan*_input.
At that time, it crash by that lock problem. And it is a probability problem.

Regards,
Vic


On 12/16/20 9:07 AM, Tom Jia wrote:
James,

Please see my answers in line.

Thanks.

Best regards,
Tom Jia (贾彦民)



From: James Liao <james.liao@pica8.com>
Sent: Wednesday, December 16, 2020 8:45 AM
To: Tom Jia <tom.jia@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom,

Can you confirm,
1.	Do we have a procedure to reproduce the problem? (I suppose yes, but it takes time to script)
[Tom] I have given a snippet of code to reproduce this issue yesterday afternoon. But that cannot 100% match the scenario of PICOS driver code. We are planning to reproduce this issue as following:
•	reduce the interval of calling the problematic function
•	write a test script to capture the panic output message on console terminal
1.	When the problem happens, is any alert messages sent to Syslog? (please confirm)
[Tom] Not sure. From my understanding, the kernel panic handler will not send alarm messages to rsyslog because it doesn't know if rsyslog is OK when a panic happens. Will double check with Vic.
1.	When the problem happens, is any alert sent to console? (please confirm)
 [Tom] Yes, it is.
The enhancement to capture the core dump of driver module is for the future. Let’s NOT debate that for now.

James

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, December 15, 2020 at 4:22 PM
To: James Liao <james.liao@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Let's explore the way to get core dump restored when kernel panic happens by passing the specific parameters to driver modules.
And let's see if we could trigger it easier by minimizing the interval to call the problematic function.
Currently, output messages of kernel panic can be printed on the console terminal.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: James Liao <james.liao@pica8.com>
Sent: Tuesday, December 15, 2020 10:07 PM
To: Tom Jia <tom.jia@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom, Vic,

Is there any “clue” (like some log or some trace) that we can show Verizon this is indeed the root cause?

For this crash to happen, do we have a theory what might have triggered it so frequently in the past two weeks (like weather is becoming cold or the temperature is changing fast in the machine room)?

James

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, December 15, 2020 at 2:20 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Hi Zoneson,

We can generate the same kernel panic with the attached code given by Vic.

int __init swctrl_init(void)
{
    struct mutex *p = &lock;
        mutex_init(p);

    //key point - clean up the content pointed by p.
    memset(p, 0, sizeof (struct mutex));

    mutex_lock(p);
    mutex_unlock(p);
    return 0;

}

The situation in the driver code is much complicated than the attached code. In fact, the problematic function is called periodically by the up-layer code for temperature control. But it's not necessary the specific pointer in the corrupted struct mutex (update) is NULL at each call.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Tom Jia <tom.jia@pica8.com>
Sent: Tuesday, December 15, 2020 5:34 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Hi Zoneson,

We are exploring to simulate this issue by writing a simple kernel module.
I think we need to release a new version to fix this issue. Will add #12977 in the incoming new version.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Tuesday, December 15, 2020 5:30 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom,

Thank you for the explanation! I will inform Verizon about this problem! I just wonder whether there exists a command to trigger the driver. In this case, it may reproduce the problem by issuing the command in a loop.

If there is a plan to release a newer version to Verizon, I would like to request for the OVS enhancement on supporting the rsyslog and setting its server IP address (bug#12977).

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, December 15, 2020 at 1:10 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171
Hi Zoneson,

First of all, 2.7 version doesn't has this issue because fan driver code in 2.11.3.x is completely different from 2.7 by a code structure refactor.

We think bug#9171 is the root cause of the switch reboot because #9171 fix in 2.11.3.vzsdn.6 did not cover as5712.

This issue can raise kernel panic randomly because a mutex pointer is corrupted in function  os-dev/as5712_54x/driver/ctrl/ctrl.c:sync_ctrldata(...).

In beginning of this function, a lock (kernel mutex)  is used to protect critical section.

    mutex_lock(&update->lock);

And then update (struct dynamic_data) is overwritten by,

    memcpy(update, &ctrldata->update, sizeof(struct dynamic_data));

The update->lock is corrupted by ctrldata->update.lock. When this function (sync_ctrldata) releases the corrupted lock which is not the lock in mutex_lock() in the beginning of this function,

mutex_unlock(&update->lock);

it would raise kernel panic if __mutex_lock_slowpath tries to dereference a NULL pointer specifically by reference of the terminal output in #9171.

***********
compacting database online (1524639494.560 seconds old, 218 transactions, 10547401 bytes)
BUG: unable to handle kernel NULL pointer dereference at           (null)
IP: [<ffffffff8145b5ef>] __mutex_lock_slowpath+0x11a/0x1c0
PGD 46c164067 PUD 46c9da067 PMD 0
***********

Please refer this code as attached. Please ping me if any question.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Tuesday, December 15, 2020 1:29 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom,

May I ask why this bug 9171 did not show in 2.7 version to Verizon?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Monday, December 14, 2020 at 9:24 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: <Tom help> bug 9171
Tom,

Thank you for letting me know that this Verizon silent reboot problem could be caused by bug 9171! Are there any way we can trigger it to cause Linux crash? Or are there any other ways to prove it to Verizon?

As we discussed in the phone, there are two reboots on the following switches:

1.	BBTPNJ33OS1-FB02
2.	NRTNOHIAOS1-FB01

I also list the startup temperatures in the attached file.

Thanks,

Zoneson


.




----



The reversible keys are as following:


#snmp
set protocols snmp v3 usm-user patsch authentication-key “cherry”
set protocols snmp v3 usm-user patsch privacy-key “cherry”

 #bgp
set protocols bgp neighbor 1.1.1.1 password “cherry”
set protocols bgp interface vlan1111 password “cherry”
set protocols bgp vrf blue peer-group test_group password “cherry”
set protocols bgp vrf blue neighbor 1.1.1.1 password “cherry”
set protocols bgp vrf blue interface vlan1111 password “cherry”

#ospf
set protocols ospf interface vlan1111 message-digest-key 1 md5 “cherry”

  #vrrp
set protocols vrrp interface vlan1111 vrid 1 authentication md5-key “cherry”

 #nac
set protocols dot1x aaa radius authentication server-ip vlan1111 shared-key “cherry”
set protocols dot1x aaa radius dynamic-author client 1.1.1.1 shared-key “cherry”

#tacacs+
set system aaa tacacs-plus key “cherry”


The login password is unreversible.

set system login user test authentication plain-text-password pica8

Thanks.







10.10.50.22:/tftp/build/release/experiment-codes/config2set

There are 2 files under this folder as following:
•	python script - config2set.py
•	startup config - pica_startup.boot
•	converted set commands - pica_startup_set_commands
This script can be execute as,

python3 config2set.py pica_startup.boot

or as,

python3 config2set.py pica_startup.boot > pica_startup_commands

if you want to save the output to a file.

Additionally, it is a little bit complicated with 3 categories of keys as I highlighted as following:
•	base64 transformation
•	encrypted with encryption alogrithm based on base64
•	plaintext

root@Xorplus# show |display set |match c3BhY2V0aW1l
    set protocols bgp interface vlan3333 password "VzFsc3BhY2V0aW1lYzNC"
    set protocols bgp vrf blue interface vlan1111 password "VzFsc3BhY2V0aW1lYzNC"
    set protocols ospf interface vlan1111 message-digest-key 1 md5 "VzFsc3BhY2V0aW1lYzNC"
    set protocols snmp v3 usm-user patsch authentication-key "VzFsc3BhY2V0aW1lYzNC"
    set protocols snmp v3 usm-user patsch privacy-key "VzFsc3BhY2V0aW1lYzNC"
    set system aaa tacacs-plus key "VzFsc3BhY2V0aW1lYzNC"
    set protocols vrrp interface vlan1111 vrid 1 authentication md5-key "c3BhY2V0aW1l"
    set protocols dot1x aaa radius authentication server-ip 111.111.111.111 shared-key "c3BhY2V0aW1l"
    set protocols dot1x aaa radius dynamic-author client 1.1.1.1 shared-key "c3BhY2V0aW1l"

root@Xorplus# show |display set |match spacetime
    set system aaa radius authorization server-ip 111.111.111.111 shared-key "spacetime"
    set protocols vrrp interface vlan1111 vrid 1 authentication simple-key "spacetime"


Anyway, these keys are converted back to plaintext by config2set.py.


tjia@dev16:~/codes$ python3 config2set.py pica_startup.boot |grep key
set protocols dot1x aaa radius authentication server-ip 111.111.111.111 shared-key "spacetime"
set protocols dot1x aaa radius dynamic-author client 1.1.1.1 shared-key "spacetime"
set protocols ospf interface vlan1111 message-digest-key 1 md5 "spacetime"
set protocols snmp v3 usm-user patsch authentication-key "spacetime"
set protocols snmp v3 usm-user patsch privacy-key "spacetime"
set protocols vrrp interface vlan1111 vrid 1 authentication md5-key "spacetime"
set system aaa tacacs-plus key "spacetime"
set system aaa radius authorization server-ip 111.111.111.111 shared-key "spacetime"
tjia@dev16:~/codes$ python3 config2set.py pica_startup.boot |grep password
set protocols bgp interface vlan3333 password "spacetime"
set protocols bgp vrf blue interface vlan1111 password "spacetime"


The decryption algorithm is covered in function decode_key in the python script. Please feel free to tailor it if needed.

Please let me know if any question or problem.

Thanks.

Best regards,
Tom Jia (贾彦民)






----

From: Lin Du <lin.du@pica8.com>
Sent: Wednesday, June 24, 2020 07:44
To: James Liao <james.liao@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Yachal Chen <yachal.chen@pica8.com>; Vic Lan <vic.lan@pica8.com>
Subject: RE: (PDLC) A new file has been added

Aaron,
The netadmin local user with xorp group will allow it to run with configuration privilege under L2/L3, no other requirement on L2/L3 side.
The user mapping is done in pam_tacas module. Those with level 15 privilege is mapped to admin and 0 mapped to operator.

Here we should answer a question for the level 15 users in TACACS+. Do we allow them to run Ansible Scripts? Or the Ansible users must be level 10 users.
If level 15 users are allowed to run Ansible, how to control their behavior under Linux command line?




----




if you want,  I can show you tomorrow

Yachal Chen


发件人: Aaron Shang <aaron.shang@pica8.com>
发送时间: 2020年6月23日星期二 23:21
收件人: Lin Du; James Liao
抄送: Yachal Chen; Vic Lan; Tim Yi
主题: Re: (PDLC) A new file has been added




There is no ansible app on NOS boxes. ansible is merely batches of tasks and results run on targets via ssh.
Actually, PICOS has no idea or will be not aware of the concept of ansible.

The IT users who init ansible ad-hoc commands or playbook recipes from their workstation can be very different from the users on target NOS hosts.

The users who init ansible tasks can be root or normal non-root users from their workstation.
The remote user who executes the exact task items is the account on the PICOS box.


To refine example:

    $ ansible <host-lists> -m <module-name> -u <user-name--on-tacacs+--that-would-map-to--netadmin-onto-box> -a "commands-and-needed-parameters"

    $ ansible <host-lists> -m shell -u root -a "hostname A-NEW-COOL-HOSTNAME"

    $ ansible all -m shell -a "ip a | grep -A5 lo:"

    $ ansible 10.10.50.188 -m shell -u admin -a "sudo dmidecode -t chassis"

    $ ansible production-host-1 -m apt -u root -a "name=git state=absent"    # Ensure to remove this package
    $ ansible dev2s -m user -u sudo-able-user  -a "name=foo password=foo" --sudo -K
    $ ansible master-inst-room-bots -m user -u sudo-able-user -a "name=foo state=absent" --sudo -K
    $ ansible db-1 -m service -u admin -a "name=mysql state=started"         # Start this service








If the TACACS+ authed level 15 users to the box, the mapped users on the box should be able to run anything.

For this case, as I proposed, we should totally disable or remove shell access from default CLI releases.



Hi, Tim/Yachal,
Can you share a copy or repo location of the playbook for PICOS so we can refer to it?






--
Aaron





----






--------8<--------8<--------8<--------8<--------8<--------

- name: Commit config and wait 30 seconds for confirmation and re-commit
  command: "/pica/bin/pica_sh -c 'configure ; load override candidate.conf ; commit confirmed 30 ; run \"bash sleep 10\" ; commit'"
  register: result
  failed_when: "'Commit OK.' not in result.stdout_lines"
  when: candidate_upload.changed
  timeout: 20
  tags:
    - apply_conf

--------8<--------8<--------8<--------8<--------8<--------







i guess you want to do following in ansible.
you want to load a config to switch, but when the loaded config will broken the connectivity, you want the system rollback the config.  if that is the requirement, we can do it with several ways.

Let me explain my approach a little more to work around the problem you meet.

1. The sleep time should be longer than "commit confirm 30",  you also need remove the commit as following
"/pica/bin/pica_sh -c 'configure ; load override candidate.conf ; commit confirmed 30 ; run \"bash sleep 40\""
you need run this in daemon mode. i am typing in mobile phone so please forgive i can not give correct Ansible command in here, but similar as following

command : nohub "/pica/bin/pica_sh -c 'configure ; load override candidate.conf ; commit confirmed 30 ; run \"bash sleep 40\""&

what does this mean, it mean you will run a background task , which will load a config, but you need commit again in 40 sec. during 40 sec, the pica_sh will wait in background without existed

2. then  add another task to commit as following
"/pica/bin/pica_sh -c 'configure ;commit;"
if step 1's config will broken ssh connectivity, this task will never be executed, and switch will rollback

i am sorry i have not tested it by Ansible playbook.




----




Hi James,

FAN code in 2.11.3.verizon is *exactly* a function like the example we gave in last email:
    mutex_lock(p);
    memset(p, 0, sizeof (struct mutex)); <<----- ROOT CAUSE
    /* here will collect fan data for users */
    mutex_unlock(p);

So it must be a lock bug.
If many calls enters this function, it is a concurrent case. It will crash.

I have reproduced this problem, and you can also do it easily.
Create a script, and run it at the same time:
a.sh:
while [ 1 ]; do
        cat /sys/class/swmon/ctrl/fan*_input > /dev/null
done
b.sh:
while [ 1 ]; do
        cat /sys/class/swmon/ctrl/*temp* > /dev/null
done

Run it at the same time:
./a.sh &
./b.sh &

It will crash within 5 seconds for highest pressure scripts.
The attachments are crash texts by the two scripts.
For it is a concurrent bug, so the crash style will be more.


Confirmed with tim, many (2 or more) process will call this interface( /sys/class/swmon/ctrl/*) in ovs code.
So it is the cause in OVS:
one process want to get temperature, another process want to get fan*_input.
At that time, it crash by that lock problem. And it is a probability problem.

Regards,
Vic


On 12/16/20 9:07 AM, Tom Jia wrote:
James,

Please see my answers in line.

Thanks.

Best regards,
Tom Jia (贾彦民)



From: James Liao <james.liao@pica8.com>
Sent: Wednesday, December 16, 2020 8:45 AM
To: Tom Jia <tom.jia@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom,

Can you confirm,
1.	Do we have a procedure to reproduce the problem? (I suppose yes, but it takes time to script)
[Tom] I have given a snippet of code to reproduce this issue yesterday afternoon. But that cannot 100% match the scenario of PICOS driver code. We are planning to reproduce this issue as following:
•	reduce the interval of calling the problematic function
•	write a test script to capture the panic output message on console terminal
1.	When the problem happens, is any alert messages sent to Syslog? (please confirm)
[Tom] Not sure. From my understanding, the kernel panic handler will not send alarm messages to rsyslog because it doesn't know if rsyslog is OK when a panic happens. Will double check with Vic.
1.	When the problem happens, is any alert sent to console? (please confirm)
 [Tom] Yes, it is.
The enhancement to capture the core dump of driver module is for the future. Let’s NOT debate that for now.

James

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, December 15, 2020 at 4:22 PM
To: James Liao <james.liao@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Let's explore the way to get core dump restored when kernel panic happens by passing the specific parameters to driver modules.
And let's see if we could trigger it easier by minimizing the interval to call the problematic function.
Currently, output messages of kernel panic can be printed on the console terminal.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: James Liao <james.liao@pica8.com>
Sent: Tuesday, December 15, 2020 10:07 PM
To: Tom Jia <tom.jia@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom, Vic,

Is there any “clue” (like some log or some trace) that we can show Verizon this is indeed the root cause?

For this crash to happen, do we have a theory what might have triggered it so frequently in the past two weeks (like weather is becoming cold or the temperature is changing fast in the machine room)?

James

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, December 15, 2020 at 2:20 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, Vic Lan <vic.lan@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Hi Zoneson,

We can generate the same kernel panic with the attached code given by Vic.

int __init swctrl_init(void)
{
    struct mutex *p = &lock;
        mutex_init(p);

    //key point - clean up the content pointed by p.
    memset(p, 0, sizeof (struct mutex));

    mutex_lock(p);
    mutex_unlock(p);
    return 0;

}

The situation in the driver code is much complicated than the attached code. In fact, the problematic function is called periodically by the up-layer code for temperature control. But it's not necessary the specific pointer in the corrupted struct mutex (update) is NULL at each call.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Tom Jia <tom.jia@pica8.com>
Sent: Tuesday, December 15, 2020 5:34 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Hi Zoneson,

We are exploring to simulate this issue by writing a simple kernel module.
I think we need to release a new version to fix this issue. Will add #12977 in the incoming new version.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Tuesday, December 15, 2020 5:30 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom,

Thank you for the explanation! I will inform Verizon about this problem! I just wonder whether there exists a command to trigger the driver. In this case, it may reproduce the problem by issuing the command in a loop.

If there is a plan to release a newer version to Verizon, I would like to request for the OVS enhancement on supporting the rsyslog and setting its server IP address (bug#12977).

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, December 15, 2020 at 1:10 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171
Hi Zoneson,

First of all, 2.7 version doesn't has this issue because fan driver code in 2.11.3.x is completely different from 2.7 by a code structure refactor.

We think bug#9171 is the root cause of the switch reboot because #9171 fix in 2.11.3.vzsdn.6 did not cover as5712.

This issue can raise kernel panic randomly because a mutex pointer is corrupted in function  os-dev/as5712_54x/driver/ctrl/ctrl.c:sync_ctrldata(...).

In beginning of this function, a lock (kernel mutex)  is used to protect critical section.

    mutex_lock(&update->lock);

And then update (struct dynamic_data) is overwritten by,

    memcpy(update, &ctrldata->update, sizeof(struct dynamic_data));

The update->lock is corrupted by ctrldata->update.lock. When this function (sync_ctrldata) releases the corrupted lock which is not the lock in mutex_lock() in the beginning of this function,

mutex_unlock(&update->lock);

it would raise kernel panic if __mutex_lock_slowpath tries to dereference a NULL pointer specifically by reference of the terminal output in #9171.

***********
compacting database online (1524639494.560 seconds old, 218 transactions, 10547401 bytes)
BUG: unable to handle kernel NULL pointer dereference at           (null)
IP: [<ffffffff8145b5ef>] __mutex_lock_slowpath+0x11a/0x1c0
PGD 46c164067 PUD 46c9da067 PMD 0
***********

Please refer this code as attached. Please ping me if any question.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Tuesday, December 15, 2020 1:29 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Tom help> bug 9171

Tom,

May I ask why this bug 9171 did not show in 2.7 version to Verizon?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Monday, December 14, 2020 at 9:24 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: <Tom help> bug 9171
Tom,

Thank you for letting me know that this Verizon silent reboot problem could be caused by bug 9171! Are there any way we can trigger it to cause Linux crash? Or are there any other ways to prove it to Verizon?

As we discussed in the phone, there are two reboots on the following switches:

1.	BBTPNJ33OS1-FB02
2.	NRTNOHIAOS1-FB01

I also list the startup temperatures in the attached file.

Thanks,

Zoneson


.





PICOS-OVS login: BUG: unable to handle kernel NULL pointer dereference at 0000000000000010
IP: [<ffffffff8145b18e>] __mutex_unlock_slowpath+0x29/0x3f
PGD 273650067 PUD 2735d7067 PMD 0
Oops: 0000 [#1] SMP
Modules linked in: linux_user_bde(PO) linux_kernel_bde(PO) ctrl(O) led(O) psu(O) qsfp(O) sfp(O) i2c_mux_cpld(O) hwinfo sffcore swmon lm75 iTCO_wdt iTCO_vendor_support ip6t_MASQUERADE ip6t_NPT ip6t_frag ip6t_REJECT ip6table_nat ip6table_mangle ip6table_filter ip6_tables nf_nat_ipv6 ipt_REJECT ipt_MASQUERADE iptable_nat iptable_mangle iptable_filter ip_tables nf_nat_ipv4 xt_REDIRECT xt_NETMAP xt_nat nf_nat xt_mac xt_dscp xt_NFLOG xt_LOG xt_mark
CPU: 2 PID: 6460 Comm: cat Tainted: P           O  3.16.7-ckt11 #1
Hardware name: Accton AS5712-54X/AS5712-54X, BIOS 5.6.5 11/20/2014
task: ffff880273226f90 ti: ffff880273610000 task.ti: ffff880273610000
RIP: 0010:[<ffffffff8145b18e>]  [<ffffffff8145b18e>] __mutex_unlock_slowpath+0x29/0x3f
RSP: 0018:ffff880273613d68  EFLAGS: 00010207
RAX: 0000000000000000 RBX: ffff8802757d9970 RCX: 0000000000000000
RDX: 0000000000000000 RSI: ffffffffa00ac97c RDI: ffff8802757d996c
RBP: ffff880273613d78 R08: ffff880275b99b80 R09: ffff8802736aa980
R10: ffff880273613e48 R11: ffff88027595f900 R12: ffff8802757d996c
R13: ffff880273613f50 R14: ffff8802736aab00 R15: ffff88027595f900
FS:  00007f94358e4700(0000) GS:ffff88027fd00000(0000) knlGS:0000000000000000
CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
CR2: 0000000000000010 CR3: 000000027366f000 CR4: 00000000001007a0
Stack:
 000000000000003f ffffffffa00ac97c ffff880273613d88 ffffffff81093836
 ffff880273613d98 ffffffff8145b1e5 ffff880273613db8 ffffffffa00ac3ec
 ffff8802731db000 ffffffff816491b0 ffff880273613dd8 ffffffffa00ac4fb
Call Trace:
 [<ffffffff81093836>] __mutex_fastpath_unlock.constprop.11+0xe/0x10
 [<ffffffff8145b1e5>] mutex_unlock+0x11/0x13
 [<ffffffffa00ac3ec>] sync_ctrldata+0x153/0x15a [ctrl]
 [<ffffffffa00ac4fb>] show_fan+0x16/0x33 [ctrl]
 [<ffffffff811e0f95>] kobj_attr_show+0xf/0x1b
 [<ffffffff8113eaaf>] sysfs_kf_seq_show+0x80/0xca
 [<ffffffff8113da1d>] kernfs_seq_show+0x1b/0x1d
 [<ffffffff81109f32>] seq_read+0x14e/0x318
 [<ffffffff8113dfad>] kernfs_fop_read+0x31/0x114
 [<ffffffff81104c20>] ? __fget_light+0x27/0x48
 [<ffffffff810efd64>] vfs_read+0x8c/0xfc
 [<ffffffff810ef1c3>] ? fdget_pos+0xd/0x19
 [<ffffffff81104c20>] ? __fget_light+0x27/0x48
 [<ffffffff810efee6>] SyS_read+0x4d/0x7f
 [<ffffffff8145d0c9>] system_call_fastpath+0x16/0x1b
Code: 5d c3 55 48 89 e5 41 54 4c 8d 67 04 53 48 89 fb c7 07 01 00 00 00 4c 89 e7 e8 ab 85 c3 ff 48 8b 43 08 48 83 c3 08 48 39 d8 74 09 <48> 8b 78 10 e8 d8 cc c2 ff 4c 89 e7 e8 55 85 c3 ff 5b 41 5c 5d
RIP  [<ffffffff8145b18e>] __mutex_unlock_slowpath+0x29/0x3f
 RSP <ffff880273613d68>
CR2: 0000000000000010
---[ end trace a8a5bd4b89f65abb ]---
Kernel panic - not syncing: Fatal exception
Kernel Offset: 0x0 from 0xffffffff81000000 (relocation range: 0xffffffff80000000-0xffffffff9fffffff)
Rebooting in 180 seconds..





root@PICOS-OVS$BUG: unable to handle kernel NULL pointer dereference at           (null)
IP: [<ffffffff8145b80f>] __mutex_lock_slowpath+0x11a/0x1c0
PGD 2735db067 PUD 273585067 PMD 0
Oops: 0002 [#1] SMP
Modules linked in: linux_user_bde(PO) linux_kernel_bde(PO) ctrl(O) led(O) psu(O) qsfp(O) sfp(O) i2c_mux_cpld(O) hwinfo sffcore swmon lm75 iTCO_wdt iTCO_vendor_support ip6t_MASQUERADE ip6t_NPT ip6t_frag ip
6t_REJECT ip6table_nat ip6table_mangle ip6table_filter ip6_tables nf_nat_ipv6 ipt_REJECT ipt_MASQUERADE iptable_nat iptable_mangle iptable_filter ip_tables nf_nat_ipv4 xt_REDIRECT xt_NETMAP xt_nat nf_nat
xt_mac xt_dscp xt_NFLOG xt_LOG xt_mark
CPU: 0 PID: 6580 Comm: cat Tainted: P           O  3.16.7-ckt11 #1
Hardware name: Accton AS5712-54X/AS5712-54X, BIOS 5.6.5 11/20/2014
task: ffff88007a884a60 ti: ffff88007a904000 task.ti: ffff88007a904000
RIP: 0010:[<ffffffff8145b80f>]  [<ffffffff8145b80f>] __mutex_lock_slowpath+0x11a/0x1c0
RSP: 0018:ffff88007a907d28  EFLAGS: 00010286
RAX: 0000000000000000 RBX: ffff880275218c68 RCX: 00000000c0000100
RDX: ffff88007a907d30 RSI: ffff88007a884a60 RDI: ffff880275218c6c
RBP: ffff88007a907d78 R08: ffff88007a904000 R09: 000000000000b92a
R10: 0000000000000004 R11: 0000000000000001 R12: ffff880275218c6c
R13: ffff88007a884a60 R14: ffff880275218c70 R15: 00000000ffffffff
FS:  00007fd44e3c1700(0000) GS:ffff88027fc00000(0000) knlGS:0000000000000000
CS:  0010 DS: 0000 ES: 0000 CR0: 000000008005003b
CR2: 0000000000000000 CR3: 000000007a828000 CR4: 00000000001007b0
Stack:
 ffff88007a907f24 ffff880275218c70 0000000000000000 ffff8802740560c0
 ffff88007a907d68 ffff880275218c68 ffffffffa00ac97c ffff88007a907f50
 ffff880273b49280 ffff88027585b800 ffff88007a907d98 ffffffff8145b8c9
Call Trace:
 [<ffffffff8145b8c9>] mutex_lock+0x14/0x25
 [<ffffffffa00ac2b6>] sync_ctrldata+0x1d/0x15a [ctrl]
 [<ffffffffa00ac4fb>] show_fan+0x16/0x33 [ctrl]
 [<ffffffff811e0f95>] kobj_attr_show+0xf/0x1b
 [<ffffffff8113eaaf>] sysfs_kf_seq_show+0x80/0xca
 [<ffffffff8113da1d>] kernfs_seq_show+0x1b/0x1d
 [<ffffffff81109f32>] seq_read+0x14e/0x318
 [<ffffffff8113dfad>] kernfs_fop_read+0x31/0x114
 [<ffffffff81104c20>] ? __fget_light+0x27/0x48
 [<ffffffff810efd64>] vfs_read+0x8c/0xfc
 [<ffffffff810ef1c3>] ? fdget_pos+0xd/0x19
 [<ffffffff81104c20>] ? __fget_light+0x27/0x48
 [<ffffffff810efee6>] SyS_read+0x4d/0x7f
 [<ffffffff8145d0c9>] system_call_fastpath+0x16/0x1b
Code: 04 4c 89 e7 e8 3f 7f c3 ff 8b 03 85 c0 79 25 48 8b 43 10 48 8d 55 b8 4c 8d 73 08 41 83 cf ff 48 89 53 10 4c 89 75 b8 48 89 45 c0 <48> 89 10 4c 89 6d c8 eb 0a 31 c0 87 03 ff c8 75 d3 eb 5e 8b 03
RIP  [<ffffffff8145b80f>] __mutex_lock_slowpath+0x11a/0x1c0
 RSP <ffff88007a907d28>
CR2: 0000000000000000
---[ end trace 218c0678f02e2509 ]---
Kernel panic - not syncing: Fatal exception
Kernel Offset: 0x0 from 0xffffffff81000000 (relocation range: 0xffffffff80000000-0xffffffff9fffffff)
Rebooting in 180 seconds..








$ ssh admin@172.16.0.234
OpenSSH_8.2p1 Debian-4, OpenSSL 1.1.1g  21 Apr 2020
debug1: Reading configuration data /home/aaron/.ssh/config
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: /etc/ssh/ssh_config line 19: include /etc/ssh/ssh_config.d/*.conf matched no files
debug1: /etc/ssh/ssh_config line 21: Applying options for *
debug1: Connecting to 172.16.0.234 [172.16.0.234] port 22.
<<<<HANGS HERE>>>>


admin@Xorplus:~$ sudo iptables -L
Chain INPUT (policy ACCEPT)
target     prot opt source               destination
ACCEPT     all  --  anywhere             anywhere
DROP       tcp  --  anywhere             anywhere             multiport dports ssh,telnet,http-alt
DROP       udp  --  anywhere             anywhere             multiport dports snmp
REJECT     tcp  --  anywhere             anywhere             tcp dpt:ssh flags:FIN,SYN,RST,ACK/SYN #conn src/32 > 20 reject-with icmp-port-unreachable
REJECT     tcp  --  anywhere             anywhere             tcp dpt:ssh state NEW recent: UPDATE seconds: 60 hit_count: 20 TTL-Match name: SSH side: source mask: 255.255.255.255 reject-with icmp-port-unreachable
ACCEPT     tcp  --  anywhere             anywhere             tcp dpt:ssh state NEW recent: SET name: SSH side: source mask: 255.255.255.255

Chain FORWARD (policy ACCEPT)
target     prot opt source               destination

Chain OUTPUT (policy ACCEPT)
target     prot opt source               destination
admin@Xorplus:~$


admin@Xorplus:~$ sudo iptables -F
admin@Xorplus:~$ sudo iptables -L
Chain INPUT (policy ACCEPT)
target     prot opt source               destination

Chain FORWARD (policy ACCEPT)
target     prot opt source               destination

Chain OUTPUT (policy ACCEPT)
target     prot opt source               destination

$ \ssh admin@172.16.0.234
admin@172.16.0.234's password:

Last login: Fri Jan 19 02:57:31 2001 from 10.10.50.100
Synchronizing configuration...OK.
Welcome to PICOS on Xorplus
admin@Xorplus>

OK now.



I am no checking why or how the iptables rules had been applied.


--







现在每次build将upload一个打包文件，位置与image同目录，命令类似，
每个8G, 压缩的话特别费CPU,所以只打包，以后可能去掉 '.a'之类的文件，只保留最小所需，可能会减小。

目前的内容是原先xorp/pica/ovs的debug文件，加上对应的.libs目录。
如果内容有增删建议，请告诉我。


请测试一下是否符合release的要求。如果有方便的简单测试方法，我可以在build打包之前加入测试。






我今天解开了debug.tar看了一下，.o和.a文件是不需要了，占去了太多的空间，可以去掉。

另外，请在build脚本里面检查一下，如果一个commit的build在daily里面已经生成，不要再build了。不然，会造成一些困扰，比如，QA测试了一个daily下的build，我copy到release目录下面的可能是新生成的build。







----

Hello Kevin,

Please see my comments in line.

Thanks.

Best regards,
Tom Jia (贾彦民)



From: Kevin Kwon <kevin_kwon@edge-core.com>
Sent: Thursday, January 19, 2023 9:14 AM
To: Henry Pan <henry.pan@pica8.com>; Tom Jia <tom.jia@pica8.com>
Subject: RE: Authentication on PicOS == > for Korea Security Certification

Hi.. Tom and Henry!

Thank you for your reply.


1.	“libpam-pwquality” Package
  if it is installed, I will use “remember” option to prevent same password with previous like below
sudo apt-get -y install libpam-pwquality
sudo vi /etc/pam.d/common-password
# here are the per-package modules (the "Primary" block)
password        requisite                       pam_pwquality.so retry=3 minlen=8 minclass=3
password        [success=1 default=ignore]      pam_unix.so obscure use_authtok try_first_pass sha512 remember=5

 [Tom] It should be OK to get libpam-pwquality packaged into PICOS Linux rootfs. Will test this case as you mentioned.

2.	SNMP Password Algorithm
•	As you said, PicOS using the SNMP key encryption to “customized base64 algorithm”.
•	Can you change it to “general SHA256” for every password encryption algorithm such as user, SNMP,…?
•	Is there any specific reason to use “customized base64 algorithm” for SNMP or “MD5” for user password?

[Tom]  Please note what I'm saying is that the keys which are not passwords are encrypted by customized base64 algorithm as following:
>   set protocols snmp v3 usm-user test authentication-key "M1E9dGVzdHRlc3Q=ZEdW"
>   set protocols snmp v3 usm-user test privacy-key "QT09cGljYThwaWNhOA==Y0ds"

In PICOS code, the plaintext of the keys, such as the plaintext privacy-key "pica8pica8" ("QT09cGljYThwaWNhOA==Y0ds") will be used by SNMP module to encode/decode the encrypted data of the SNMP session by the configured symmetric encryption algorithm (privacy-mode).


admin@PICOS# set protocols snmp v3 usm-user test privacy-mode
Possible completions:
  3des                            Encrypt the SNMP PDU with the 3DESEDE algorithm
  aes128                          Encrypt the SNMP PDU with the 128bits AES algorithm
  des                             Encrypt the SNMP PDU with the DES algorithm



 Therefore, the encrypted text of keys in the configuration commands, such as "QT09cGljYThwaWNhOA==Y0ds", musted be converted to the plaintext "pica8pica8". That is the reason why SHA256/SHA512 cannot be used to encrypt these keys because the encrypted hash text with SHA256/SHA512 has no way to be converted to the plaintext.

Have a good day!
KevinKwon

From: Henry Pan <henry.pan@pica8.com>
Sent: Tuesday, January 17, 2023 5:55 PM
To: Tom Jia <tom.jia@pica8.com>; Kevin Kwon <kevin_kwon@edge-core.com>
Subject: Re: Authentication on PicOS == > for Korea Security Certification

[WARNING!!] This email originated from outside of the organization. Do not click links or open attachments unless you can confirm the sender and know the content is safe.
*********************************************************************************
Let me include Kevin into the loop for discussion.

Kevin, Tom has some explaination to your question.  Can you take a look and let us know it make sense?

With Best Regard

Henry PanAPAC BD/Sales/Operation
Pica8, Inc.

From: Kevin Kwon <kevin_kwon@edge-core.com>
Date: Monday, January 16, 2023 at 7:58 AM
To: Henry Pan <henry.pan@pica8.com>
Subject: RE: Authentication on PicOS == > for Korea Security Certification
Hi. Henry!

Sorry for late reply.

I asked four to proceed the CC (Korea Security Certification) like below
And, 1 and 2 is accepted ?
How about to support one of 3 & 4 ? not both.

1.        Install additional Linux Package (libpam-pwquality) for Authentication

[Tom] Yes, we can integrate libpam-pwquality into Linux package. As you know, we don't use the functionalities of libpam-pwquality In current PICOS code because it is not available in PICOS package. We would like to know customer's application scenarios and understand how to use libpam-pwquality.

2.        User Password Encryption
3.        SNMPv3 keys (authentication-key, privacy-key)  encryption

4.        SNMPv3 of OVS Mode keys (authentication-key, privacy-key)  encryption

[Tom] The hash encryption algorithms cannot be applied to this scenarios (#3 and #4) as the case of user passwd. Let's me use privacy-key as an example.

In the following case, I configured "pica8pica8" to the privacy-key. It's the plaintext "pica8pica8" of the privacy-key that will be used to encode and decode the data  encrypted by aes128 in the snmp session. Therefore, we transformed the plaintext "pica8pica8" into "QT09cGljYThwaWNhOA==Y0ds" based on customized base64 algorithm. And then this encrypted privacy-key "QT09cGljYThwaWNhOA==Y0ds" can be converted plaintext and applied to snmp when we load this configuration to PICOS.

admin@PICOS# show protocols snmp |display set
    set protocols snmp v3 usm-user test privacy-mode "aes128"
    set protocols snmp v3 usm-user test privacy-key "QT09cGljYThwaWNhOA==Y0ds"


To Global Business with PICA8, is there any countries are asking to get CC Certification ?
Only Korea is asking it?

Thank you!
KevinKwon


Have a good day!
KevinKwon







It is no problem to secure the login passwd with SHA256 or SHA512. That would need a little bit effort. In current PICOS implememtion, MD5 is supported.

set system login user test authentication plain-text-password "$1$.0LHwd73$muTBik.CuDqJrTOmMkAhD1"

In case of SNMPv3 authentication-key/privacy-key, we can present their SHA hash values of the configured plaintext if execute CLI command "show|display set".

set protocols snmp v3 usm-user test authentication-mode "sha"
set protocols snmp v3 usm-user test authentication-key "$9......................."
set protocols snmp v3 usm-user test privacy-mode "des"
set protocols snmp v3 usm-user test privacy-key "$9....................................."

Because the hash value cannot be converted back to the configured plaintext, these set commands cannot be copied and applied to other switches.

Copy to @Hai Vo-Dinh for reviewing.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Kevin Kwon <kevin_kwon@edge-core.com>
Sent: Thursday, March 2, 2023 6:50 PM
To: Tom Jia <tom.jia@pica8.com>; Henry Pan <henry.pan@pica8.com>; Iris Rong <iris.rong@pica8.com>; Vic Lan <vic.lan@pica8.com>; Aaron Shang <aaron.shang@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: Lin Du <lin.du@pica8.com>
Subject: RE: Authentication on PicOS == > for Korea Security Certification

Hi.. Tom.

I got the Juniper JUNOS information from friend to show you.

As you see, they are using more strong encryption than “SHA256”. Can we support like this?






----

OK, let's only do cosmetic changes.
I think that should be enough for not showing any pica8/picos in screen outputs.


________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Tuesday, June 20, 2023 01:31
To: Aaron Shang; Niraj Jain
Cc: Hai Vo-Dinh
Subject: Re: DLink prioritized list of OEM customization requests

Aaron,

Let’s NOT make the assumption “We do it once, then we benefit from this when having other similar cases.”

I think Niraj has proposed to do cosmetic changes (by not showing the script name) instead of the file name changes. Can we do that?

James


From: Aaron Shang <aaron.shang@pica8.com>
Date: Monday, June 19, 2023 at 10:24 AM
To: James Liao <james.liao@pica8.com>, Niraj Jain <niraj.jain@pica8.com>
Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Re: DLink prioritized list of OEM customization requests
It's hard to estimate the efforts, it may be one week, or two weeks. That would be a test-and-trial process, with lots of potential failures to be fixed. Some issues might be only be found at runtime.
Anyway, that can be done. We do it once, then we benefit from this when having other similar cases.

________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Thursday, June 15, 2023 00:10
To: Niraj Jain; Aaron Shang
Cc: Hai Vo-Dinh
Subject: Re: DLink prioritized list of OEM customization requests

Did we commit to phase 2? The scope is too big and too vague.

From: Niraj Jain <niraj.jain@pica8.com>
Date: Wednesday, June 14, 2023 at 9:07 AM
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>, James Liao <james.liao@pica8.com>
Subject: Re: DLink prioritized list of OEM customization requests
Aaron,
DLink is asking for timeline on Phase 2.  What do you think is reasonable if we defer #6?

Niraj

________________________________
From: Aaron Shang <aaron.shang@pica8.com>
Sent: Tuesday, June 13, 2023 8:31:51 PM
To: Niraj Jain <niraj.jain@pica8.com>
Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>; James Liao <james.liao@pica8.com>
Subject: Re: DLink prioritized list of OEM customization requests


This week can be OK, these are simple changes.

________________________________________
From: Niraj Jain <niraj.jain@pica8.com>
Sent: Wednesday, June 14, 2023 04:24
To: Aaron Shang
Cc: Hai Vo-Dinh; James Liao
Subject: Re: DLink prioritized list of OEM customization requests

Thanks Aaron.  This looks like a good plan - I will review more deeply against their priority list and let you know if I have any questions.  How soon do you think we can deliver Phase1?

Niraj

On 6/13/23, 10:06 AM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

    Hi, Niraj/Hai

    Please check whether the plan can be OK.

    ====
    Proposal of changes for OEM.

    Part them into Phase 1 and Phase 2 according to priority and needed efforts.

    1. Default login credentials are used for the first login.

    Example

        Username: admin
        Password : admin

    Solution: By OEM framework.
    Stage: Phase 1.

    2. Create unique credentials specifically for shell access, separate from the login credentials used for the operating system.

    Example for shell access

        Username "root"
        password "D!ink$"

    Solution: Support this feature in login code, and then enable protection via OEM framework.
    Stage: Phase 2.

    3. Not to show occurrence of "picos" during firmware upgrade/bootup.

    Solution: Change module to neutral naming, such as `system` startup, etc.
    Stage: Phase 1.

    4. OEM to rename SNMP Private MIB

    Solution: Support this in OVS code, and then enable protection via OEM framework.
    Stage: Phase 1 - Hopefully.

    5. Default STM share mode is 5, suggested it should be 3.

    Solution: OEM framework.
    Stage: Phase 1

    (This one can actually be done by configuration. If the change is wanted, OEM framework can do it, easily.)

    6. Use neutral naming for file/command names. Such as changing pica_startup to nos_startup

    Solution: Change in code.
    Stage: Phase 2. Lot of Risks. Not all can be committed easily. Needs many efforts.


    ________________________________________
    From: Niraj Jain <niraj.jain@pica8.com>
    Sent: Wednesday, June 14, 2023 00:58
    To: Aaron Shang
    Cc: Hai Vo-Dinh; James Liao
    Subject: Re: DLink prioritized list of OEM customization requests

    Thanks!!

    Niraj
    ________________________________
    From: Aaron Shang <aaron.shang@pica8.com>
    Sent: Tuesday, June 13, 2023 9:45:37 AM
    To: Niraj Jain <niraj.jain@pica8.com>
    Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>; James Liao <james.liao@pica8.com>
    Subject: Re: DLink prioritized list of OEM customization requests

    Hi, Niraj,

    I am so sorry that I missed this mail.

    > I am assuming these lines are printed for diagnostic purposes, in order to show the modules that have been executed, and we don’t want to suppress them?
    > Will you change the name of the actual module, or just map it to a different name for display?

    That's for showing the startup status/progress, it's better to keep them instead of suppressing them.
    That's done by changing the actual module. The changing is easy.

    > If we must change it in the code for all users, and its not possible to do it by OEM packaging, my preference would be to:
    >                - replace "picos" by one of the following, highest preference first:
    >                               - "picos" > "system"

    I agree with this one, changing appearances of `picos` to `system`.

    >>> ## The correct hardware model should be DXS_F3610-54S instead of AS5835_54X.￼
    >>    Solution:
    >>    This might be caused by upgrade.
    >>   Replied them today to do a new installation to see whether the expected text can be displayed.
    > NJ> Please clarify – I am not sure what you mean

    The fix had been released to EC, and they verified the fix being OK.

    It's not caused by upgrade. The root cause is they OEMed eeprom, but not CPLD.
    Some HW model displaying had been using result from CPLD. The fix hard coded 5835 to use eeprom for HW model.


    As for other items, I will sum up a proposal for changes in one day or two.



----




Added my comments James wireguard implementation looks good but ensure limitations described (1 instance, 8 key/pairs peers - per switch) are acceptable to Whole Foods, Verizon, Orange, etc... - will that be enough? Or if not if that's all we can do, can they make that work?

Also as noted, IPSec and Wireguard are not mutually exclusive. IPSec by itself does not necessitate the need for Wireguard and should be able to be configured separately from Wireguard.

Wireguard does use IPSec or shares some base components and thus one does dictate the need for the other, but not vice versa.

Additionally why not add MACSEC as it essentially uses all the same components and process and kill 3 birds with one stone perverbially :)

Other then above, pretty awesome progress and excited to have this as part of our solution!!! We can reallllly market it too!

Kind Regards,
Neal

Neal Trieber, CISSP
Sr. Sales Engineer, Americas
M: 301-928-6756


From: Hai Vo-Dinh <hai.vodinh@pica8.com>
Sent: Friday, May 26, 2023 3:57:07 PM
To: James Liao <james.liao@pica8.com>; Neal Trieber <neal.trieber@pica8.com>; Achint Sehgal <achint.sehgal@pica8.com>
Cc: Ben Moore <ben.moore@goborderless.io>; Zach Hill <zach.hill@pica8.com>; Yachal Chen <yachal.chen@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Subject: Re: [High priority] IPSEC review

James,

I'm reviewing now.

Hai

From: James Liao <james.liao@pica8.com>
Sent: Friday, May 26, 2023 12:54 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>; Neal Trieber <neal.trieber@pica8.com>; Achint Sehgal <achint.sehgal@pica8.com>
Cc: Ben Moore <ben.moore@goborderless.io>; Zach Hill <zach.hill@pica8.com>; Yachal Chen <yachal.chen@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Subject: [High priority] IPSEC review

Hai, Neal, Achint,

I need your help to do a fast-round review of the IPSEC functions. This is a feature requested by Verizon, Whole Food, and Orange. We need to make sure the design is acceptable to these early adopters. Orange is asking us to make a proposal that can deliver IPsec TODAY. Ideally, I would like to get commitment from Verizon and Whole Food as well.

I have been working with Yachal and Aaron on the planning of this feature. I need all three of you to review the RFE and PDD. Once you approve the design, I plan to share the PDD with Orange by next Monday.

RFE - https://goborderless.atlassian.net/wiki/spaces/PIC/pages/80642063/IPSEC+RFE
PDD - https://goborderless.atlassian.net/wiki/spaces/PIC/pages/89784321/IPSEC+Product+Design+Document


Ben, Zach,

This is FYI. Your input is always welcome.

Thanks,
James




----




Team,

It was great to have a chance to come together for our All-Hands meetings a few weeks ago where we highlighted our accomplishments, summarized our performance against OKRs and re-emphasize our areas of forward focus.

Increasingly as an ELT, the concept of ‘go slow to go fast’ comes up.  Pragmatically, we’ve been running at breakneck speed across the company but resisting the urge to come to fundamental conclusions too quickly.  Rather, we work to practice HYPAL as a team: having an operating hypothesis and working to test it as quickly as possible to then solidify more fundamental decisions.

In combination with our company-level and individual OKRs, it allows us to experiment, take risks, but keep us experimenting in the direction of our goals.

As a result of this, we are at a point as a company where we can continue to streamline and even narrow our focus.

While the ‘why’ remains the same, we will continue to get more and more focused on the ‘what’ and ‘how’ we execute toward both our long-term strategy and near-term objectives.

As a reminder, our Q2 focus:



I look forward to sharing some additional refinements on this focus at our next get together for our mid-quarter ‘fire side chat’ format discussion—which will be held in early June.

With that, I also want to use this communication to highlight functional level quarter-to-date progress every few weeks as well.


Org	Summary
NA Sales	•	Re-engaging partners and kicking off relationship building and joint marketing efforts. Initially in the US and Europe.
•	Top of funnel growth remains strong, on track to produce more opportunities and pipeline $ in Q2 than Q1.
ROW Sales	•	Expanded the Japan Soltec business. Closed the fourth order in 2 quarters.
•	On track of DLINK business development to closing the 2nd PO.
People	•	Launched Guide to Life @ Borderless V1 in US with ROW to follow
•	Successful Q1 Leadership offsite
•	Successful Q1 All Team meeting
Operations	•	Stood up Weekly Metrics Review operating rhythm to evaluate KPI’s for the sales team and generate insights and action items on a weekly basis
•	Transitioned all key finance/account work streams to our new external finance team, Denali. They are now processing all PO’s, payroll, etc
•	Held first Board meeting using new “Rhythms of the Business’ (RoB) process and received positive feedback from the Board of Directors
Product	•	Launched Limited Private Preview (LPP) of Borderless Console!
•	LPP Commitment from Verizon, Tier4, Steward Healthcare, Lockheed Martin, and University of Rhode Island
•	Onboarded Tier4
•	Partner engagement with Edgecore and Akamai
•	Launched PicOS 4.4.0 integrating FRR 8.4.2
•	Launched AmpCon 1.11.1
•	Met with China Engineering Leadership
•	Launched Jira for all engineering and product.
•	Entire company onboarded into Confluence
Marketing	•	Briefed leading industry analyst Futuriom
•	Held Webinar - How to Make the Business Case for Network Disaggregation on April 19
Support	•	New http://ticket.pica8.com page is live for customers
•	New Zendesk Form collecting data that will help us create better automation and documentation is live
•	An account with TSANet has been successfully set up, enabling secure collaboration with partners like Dell
1.	Email address TSANet@pica8.com was created for effective communication from Dell
2.	Pica8 Support can reach Dell Support directly via https://pica8.connect.tsanet.org/#/
•	Successful phone porting to Zendesk and set up of a new greeting (voicemail recording)
1.	Thanks to Elizabeth for her assistance in recording the Voicemail
Cloud Engineering	•	Valerie joined us as Principal Software Engineer on 2023-05-08.
•	Launched Borderless NetDevOps platform private preview on 2023-04-12!
•	Smoothly onboarded Tier4 as our first private preview customer on 2023-05-04!
NOS Engineering	•	Made major PicOS release 4.4.0 for EVPN total solution and Verizon Medium-Site features.
•	Completed virtual lab launch with PICOS-V 4.3.2 EVPN features.
•	Made major AmpCon release 1.11.1 for security enhancement

We have much going on, and much to do.  Please ensure our individual and collective focus on the goals outlined above.

Onward and Upward!

Brad






	This message was sent from outside the company by someone with a display name matching a user in your organization. Please DO NOT CLICK OR OPEN ANY LINKS OR ATTACHMENTS unless you recognize the source of this email CLICK 'FORWARD' to see the full email HEADER and ensure it is a pica8.com email! Please contact James or Neal if you have any questions.
 	James Liao 已建立頁面



	NetWeb Enablement Problem


Business Case
This was a problem we have encountered when we enabled NetWeb’s new platform, which NetWeb OEMed from Edgecore. No hardware change or software porting changes. They have changed the model name in the EEPROM and we need to change our installer to allow PICOS installation on the new model name. However, the first attempt of installation fails in the partitioning action.
Root Cause Analysis
Vic found the root cause. It's a PicOS bug. The number for increasing partitions had been set to "2" instead of the expected "3". This is a very old bug that has existed since the first commit into the git repo when tracing the commit history.
But why didn't we find the issue during testing?
Because reproducing the issue has some dependencies, such as existing partitions and arrangements. In the dozens of installation tests I had taken, I only ran into the issue once.
So why didn't the bug occur after all these years, but happened just now? That's because of changes to components in recent versions. We use `gdisk` to create and label partitions because earlier versions of `fdisk` were not good at dealing with GPT tables.
`gdisk` would automatically adjust the numbers of the last partition, which was the bug in our case. That fix saved us. But these batches of 7326 runs recent ONIE versions, whose embedded `busybox` contains a later version of `gdisk`. The behavior changed so that it won't adjust the wrong numbers, it will fail and quit.
That sounds like the right way. Thus, the bug now finally became a tricky bug. At first, we excluded image building issues by installing the image onto different models. Then I suspected the partition table might be weird (GPT with embedded protective MBR, PMBR) so the installer cannot detect and deal with it well. But in the previous troubleshooting sessions, I could manually adjust and label partitions, extract our NOS image to the target, and adjust drivers/templates/boot-loaders to boot.
So we narrowed down the issue to the partitioning part in the installer scripts. We will fix the bug in all needed branches tomorrow morning (diff would be two lines of changing 2 to 3).
Lessons Learned
•	Current test coverage is not enough
•	Corner cases should be covered in some means, for example, lots of combinations of media and partition types
•	Code review hooks before merging
•	Possible to automate installing tests using QEMU/VM.

 	檢視頁面
•
 	新增留言
•
 	新增回應



🔔 隨時隨地獲取通知並留言。下載適用於 iOS 或 Android 的 Confluence Cloud




停止追蹤空間
•
管理通知













	This message was sent from outside the company by someone with a display name matching a user in your organization. Please DO NOT CLICK OR OPEN ANY LINKS OR ATTACHMENTS unless you recognize the source of this email CLICK 'FORWARD' to see the full email HEADER and ensure it is a pica8.com email! Please contact James or Neal if you have any questions.
 	James Liao 已建立頁面



	IPSEC on PICOS


Coincidentally, several potential customers made the same requests to add IPSEC to PICOS. Some requirements are vague, but some are very specific.
•	(March, 2023) Whole Foods requested to install Wireguard on the PICOS switches so that they could remove the need of deploying a VM (to run Wireguard) or a server to their stores.
•	(April, 2023) Zeroeyes requested to have a IPsec tunnel to the switches.
•	(April, 2023) Orange Telecom (Egypt, Campus Network) asked for an IPsec tunnel from a WAN device to a public IP address, which is in a public cloud (AWS or Azure).
•	(May, 2023) Verizon Router project, which requires IPSEC connectivity to their central servers but also MPLS and some edge gateway functions.
Other side notes of related discussion.
•	None of them requested high speed. Orange said they needed the performance around 700Mbps. Whole Foods were ok with 500Mbps.
•
Architecture
IPSEC is not a natural fit to network switches because the network ASIC usually does not support such acceleration. Most of the IPSEC functions are implemented through CPU, with sometimes offload helps from NICs.
However, with more open source projects of mature VPN Gateway, many enterprise Netops are open to replace their legacy hardware-based VPN gateways with these open-source VPN gateways. However, deploying these software on dedicated servers (or VMs) is a big hassle and it is difficult to maintain those servers.
In this case, it is reasonable to attempt to run these gateways on the PICOS switches. In order to do that, we need to solve some architectural challenges.
1.	CPU to ASIC traffic - the biggest challenge of this type of application is how to send the packets between the CPU and ASIC. If we do it through SDK (ie. over PCI-E), the performance is as low as 50Mbps. However, if we send the traffic through NICs, we can get the performance to more than 2Gbps.
2.	Application compatibility - Not all software are click-and-run. Some software, such as Wireguard, actually requires recompilation with some options to make it compatible.
3.	Security - not all software are secured. While users might make their choice of the application, PICOS should minimize the vulnerability of the unqualified software.
4.	CPU usage protection - while it is good to use CPU for tasks like IPSEC, we need to avoid the risks where PICOS cannot get enough CPU cycle to process protocols.
To address these challenges, we have done a prototype of new architecture.
https://pica8com.sharepoint.com/SitePages/PicOS with Docker.aspx
Next Step

 	檢視頁面
•
 	新增留言
•
 	新增回應



🔔 隨時隨地獲取通知並留言。下載適用於 iOS 或 Android 的 Confluence Cloud




停止追蹤空間
•
管理通知














Team,

It’s been a productive two weeks since my last note.

Of particular note, there are two major accomplishments that tie directly to our OKRs and overall company strategy that I would like to highlight.

Cloud Services Platform Launch:

First, the cloud services engineering team, after a very aggressive and high burn 3-week sprint, demoed for the ELT the largely completed 1. 0 demo of our Cloud Services platform, code name “Blue Jay”.  For those that haven’t seen it, we plan to demo it for the broader team at the All Hands in April.

This push kept us on schedule to meet our internal private preview launch by end of Q1 with first customer engagements targeted for April 5th.    Great job by Mike C., Amit, Josh, Robert, Nate, Ben and Gus, along with lots of support from James, Yachal and the rest of the Palo Alto team in achieving this milestone.

This work puts us in a position to garner critical customer feedback to refine our forward roadmap and support our public preview in mid-Q2, with GA launch in Q3 per our OKRs.

Further, we believe this makes us unique in the market in offering the foundation of an ‘edge-core-cloud’ connected infrastructure platform that builds on our leading Access layer via an Open NOS architecture thru PicOS.

We believe this launch process will validate the ‘better together’ platform value proposition of PicOS + Blue Jay (and follow-on cloud-enhanced applications).  Blue Jay will also interoperate with Sonic which should provide us the largest possible customer engagement TAM to solve their Access, Provisioning, Management and Visibility needs with a long-term roadmap to follow.

More on initial private preview customer feedback in coming weeks.

Major Recurring Revenue (Subscription) Win at D-link:

While the above ties to our top OKR, along with our first of 3 areas of current quarter focus (i.e. launching additional layers of product value), we also contributed to our top OKR and our second quarter focused initiative with our win at D-link.

In addition to representing a large ($150K) ‘land’ deal with a customer that has a very large ‘expand’ potential for follow-on orders, it signifies our first large recurring revenue (in this case subscription) deal.  The team achieved this within 1 quarter of launch of the program which is all the more exciting.

We believe this win, along with some smaller deals executed and some far larger in the pipeline, serve as strong affirmation of the market’s willingness to consume PicOS (in many instances AmpCon) + our strong support capabilities on a ‘recurring basis’.  Blue Jay should further bolster the ability to add to our initial subscription bundle and eventually offer consumption-based services.

Great job by Niraj, Vishal, James, Sudhanshu, Neal, James and team in securing this strategic win.

These proof points, along with successful customer engagement with Blue Jay, establish a very strong basis for our major fundraising plans in the second half of the year.

Preparation for Lead Gen Engine Launch:

Our third and final current quarter focus, ‘building a repeatable and scalable lead generation engine’ is beginning to ramp in earnest after a tremendous amount of work throughout Q1 to prepare for launch.

The launch of Borderless, the re-launch of the Pica8 website in style, content and design (to better optimize for lead-gen), along with an initial (and on-going) heavy lift on collateral development has positioned us for meaningful new customer acquisition heading into Q2.

Demonstration of this capability is a MUST for both our revenue scaling, and demonstration of our overall operating model for fundraising.  Many of you may be asked to contribute to content development over coming weeks and months, so please prioritize this work if asked.  There is very likely a high ROI on these efforts.

Even prior to this launch, we have begun promising engagements representing substantial revenue pipeline with high quality logos such as Whole Foods, Boeing, the FDA, and NASA (through Penguin).   We are seeing new high-quality logos by the week.

We now need to substantially expand the scale and predictability of our top of funnel pipeline as we launch our systematic lead-gen ‘machine’ over the next month.

To summarize our three 1H’22 quarterly initiatives that map to our overall 2023 annual OKRs:

1.	Launch Cloud Services Platform (private preview thru public)
2.	Demonstrate and Scale recurring revenue products and services
3.	Demonstrate and Scale a lead-gen ‘machine’ to support current and future predictable revenue growth scaling

‘Short on Time, not Opportunity’:

An area of most urgent need, priority, and focus comes back to a quote I share frequently: “We are short on time, not on opportunity”.  The second part of the quote is the foundational reason we are all here.  There is a massive opportunity for us (which I’ll describe in a coming bi-weekly email and in our end of Q1 All Team Meeting in April).

However, like all growth stage companies, we have a limited set of resources to pursue this opportunity.  Most limited is our allocation of time.

At a practical level, this requires all of us to focus DAILY on what we accomplish.  I personally make a list of what I need to get done early in the morning when I wake up and review it at the end of each day.

I’d ask each of the members of the team to do much the same, in whatever fashion works best.  Ensuring that your list ties to your 2023 goals that ladder to the overall company OKRs.  We’ve invested heavily of management time, in technology, and of company time to ensure clarity of these goals.  If for some reason, you’re unclear, please ask your manager, functional leader, or even me for clarification.

Also at a practical level, this focus on daily execution is particularly important when it comes to engaging with our customers.  We must continue to lead our customers more than follow.  We must anticipate their needs, their challenges, their internal dynamics, etc. to ensure we are achieving our highest possible engagement and win rate at the greatest possible speed.

The concepts of ‘well they’ll tell me when and what they want, and we don’t want to push’ or ‘well, it’s not a big deal if it pushes to next quarter’ are extremely detrimental to the time-based achievements we are targeting in 2023 and that feed our 2H’23 financing plans.

To close, we are on an exciting journey with a great, and expanding team.  Let’s continue to communicate and run together to build on the foundation that is forming this first part of the year.

Onward and Upward!

Brad






	This message was sent from outside the company by someone with a display name matching a user in your organization. Please DO NOT CLICK OR OPEN ANY LINKS OR ATTACHMENTS unless you recognize the source of this email CLICK 'FORWARD' to see the full email HEADER and ensure it is a pica8.com email! Please contact James or Neal if you have any questions.
 	James Liao 已建立頁面



	IPSEC Product Design Document


Coincidentally, several potential customers made the same requests to add IPsec to PICOS. None of them requested high speed. Orange said they needed the performance no more than 150Mbps. Whole Foods were ok with 500Mbps.
Architecture
IPSEC is not a natural fit for network switches because the network ASIC usually does not support such acceleration. Most of the IPSEC functions are implemented through CPU, with sometimes offload helps from NICs.
However, with more open source projects of mature VPN Gateway, many enterprise NetOps are open to replacing their legacy hardware-based VPN gateways with these open-source VPN gateways. However, deploying this software on dedicated servers (or VMs) is a big hassle, and it is difficult to maintain those servers.
In this case, it is reasonable to attempt to run these gateways on the PICOS switches. In order to do that, we need to solve some architectural challenges.
1.	CPU to ASIC traffic - the biggest challenge of this type of application is how to send the packets between the CPU and ASIC. If we do it through SDK (i.e. over PCI-E), the performance is as low as 50Mbps. However, if we send the traffic through NICs, we can get the performance to more than 2Gbps.
2.	Application compatibility - Not all software is click-and-run. Some software, such as WireGuard, actually requires recompilation with some options to make it compatible.
3.	Security - not all software is secured. While users might make their choice of the application, PICOS should minimize the vulnerability of the unqualified software.
4.	CPU usage protection - while it is good to use CPU for tasks like IPSEC, we need to avoid the risks where PICOS cannot get enough CPU cycles to process protocols.
To address these challenges, we have done a prototype of new architecture.
https://pica8com.sharepoint.com/SitePages/PicOS with Docker.aspx
Next Step
1.	The first step is to enable Wireguard on PICOS Debian. If it is difficult to enable Wireguard, we will consider pfsense or OpenSSL.
2.	We need to evaluate the security vulnerability of enabling the Wireguard kernel module. Without enabling Wireguard, we need to ensure there is no vulnerability impact to PICOS.
3.	Once Wireguard can work on PICOS Debian, we need to run a baseline performance to ensure PICOS can sustain 1Gbps of IPSEC traffic without impacting the PICOS stability. Since IPSEC will likely to be deployed in the branch office, we need to test this with enterprise campus use case (MLAG, VRRP, with 100 MAC attached)
4.	After #3, we can try Wireguard on Docker over PICOS. Without Docker, we will need to own the IPSEC source code and support. If we can enable Docker, we can enable Wireguard, Pfsense and Palo Alto Network without owning the IPSEC functions.
TO tidy up
•	issue: inverse host lookup failed: Unknown host
•	issue: nft failure
•	checking:
o	root@PICOS:/etc/wireguard# wg
interface: wg0
public key: XDmRPqtF24672IgUMZThjGzciAEq8BNeg5fC9rNfGx8=
private key: (hidden)
listening port: 51871
peer: zXiz+dyqW9l+2YOh6jMHMuUtjSpY3UIzxixK9BZDm1A=
preshared key: (hidden)
endpoint: 10.10.51.145:51902
allowed ips: 10.0.0.2/32, fdc9:281f:4d7:9ee9::2/128
latest handshake: 54 seconds ago
transfer: 582.02 KiB received, 53.96 KiB sent
•	issue: files list file for package 'wireguard-tools' missing; assuming package has no files currently installed
o	Done. Force reinstall/add into repo
o	apt install --reninstall wireguard-tools
o	admin@PICOS:~$ dpkg -L bin/wg
•	issue: module auto loading
o	Done. admin@PICOS:~$ lsmod|grep wireguard
wireguard 94208 0
libchacha20poly1305 16384 1 wireguard
libblake2s 16384 1 wireguard
curve25519_x86_64 36864 1 wireguard
libcurve25519_generic 49152 2 curve25519_x86_64,wireguard
•	issue: scp * admin@10.0.0.1: port 22: Connection timed out
o	Should be interface listening binding issue
•	issue: sendmsg: Required key not available
o	Done.

 	檢視頁面
•
 	新增留言
•
 	新增回應



🔔 隨時隨地獲取通知並留言。下載適用於 iOS 或 Android 的 Confluence Cloud




停止追蹤空間
•
管理通知














Aaron,

This is not a typical use case, so not super urgent. Just want to see if you know this tool at all.

The Borderless engineering team is working on the next generation of agent code, which will require a keyring for secured connection to the cloud. They are trying GnuPG2.

On our PICOS 4.3.2.2, they can
1.	Did “sudo apt update” without problems (after removing some lines in the apt source list).
2.	After that, they did “sudo apt-install gnugp2”. It failed.
3.	After that, all “sudo apt update” failed. It looks like the certificate is polluted.

Want to get your opinions whether gnugp2 is something supposed to work on PICOS?

James







Welcome Ash!

Hey Team,
I'm Ash de Choudens (pronounced dee-show-denz). I am stoked to join Pica8! I have a background in HR and recruiting and have also enjoyed supporting C Suites as an executive assistant.
I've spent most of my career in the tech industry and I love working for startups because I get to wear multiple hats while learning and experiencing so much more. I genuinely enjoy what I do and it's my goal to get employees to feel the same way. I am looking forward to rolling up my sleeves and doing some impactful work here while getting to know all of you!
Speaking of getting to know each other, here are some facts about me: I play in metal bands. I have 2 dogs and a TikTok famous cockatiel. My fiancé and I go antique shopping almost every weekend and one of my favorite antiques we own is an unopened bottle of Clark Stanley's "Snake Oil" from the 1880's.

In my role, I will be supporting Brad, many of the operational needs of the Seattle office and Jamie in the recruiting and on-boarding process.  Really, stewarding the overall employee experience here at Borderless.

Can't wait to meet everyone!

Cheers,
Ash






Hi, Hai,

Just in case you had not get the past efforts. What is sad is the fact that we did not do these checking regularly for each commit or each build due to performance impact, complexity, of infrastructure issues.

## Static checking

For static check, we had used [gcov with gcc](https://gcc.gnu.org/onlinedocs/gcc/gcov/introduction-to-gcov.html), to detect counts of times each statement in a program is executed.

We can know at one time how many lines of code had been gone through for executing.

If needed, we can integrate [cppcheck](https://github.com/danmar/cppcheck) or https://fbinfer.com/ .

We can also try [clang-analyzer](https://clang-analyzer.llvm.org/), but we had not tried whether the current code can build with Clang.

To check AmpCon, we can try [MyPy](http://mypy-lang.org/), [Pylint](https://github.com/PyCQA/pylint/), or [PyFlakes](https://github.com/PyCQA/pyflakes).

## Dynamic check

For dynamic check, we had used [ASAN](https://github.com/google/sanitizers)

At some point, we had tried [valgrind](https://valgrind.org/), and [gperftools](https://github.com/gperftools/gperftools).

We had [local repo](http://10.10.50.50/repo/gperftools) to link into some needed modules in our build.

To do dynamic checking, needed libraries or tools must be built into images. Performance had to be sacrificed much.
We can generate DEBUG variant for each build at regular bases.

## Security checking

We had evaluated nessus for penetration and vulnerability scanning.







________________________________________
From: Mike Cheng <mike.cheng@pica8.com>
Sent: Wednesday, November 2, 2022 02:24
To: Mike Cheng
Subject: Engineering Organization Announcement - Welcome Amit Saurav, Sr. Principal Software Engineer

[pica8-all@ on BCC]

Hi folks,

I am excited to announce our very first member of the Seattle engineering team, Amit Saurav. Given the early days of our Cloud offering, Amit's work will likely include rapid prototyping, building foundational services, designing our overall architecture, as well as launching products. In his own words,

Hello Team!

I am Amit Saurav, super excited to be joining the Engineering team here in Seattle! Prior to this role, I worked at Snap for more than 6 years, rearchitecting their messaging backend service and laying down the foundations for service mesh that powers all new services at Snap. Prior to that, I was at Amazon for 7+ years working on various different teams from Display Advertising, to Website Platform, to AWS Marketplace and ending with Treasure Truck. During the course of my work experience, I have found myself progressively gravitating towards the lowermost layers of Computer Science, storage and compute being my most recent focus before I left Snap. Networking will push me deeper in the stack and I cannot wait to get into the nitty gritty!

I live in Sammamish with my wife and 2 kids (9 and 7). My wife has been working for Amazon for the last 5 years and it feels like Amazon never left our household! I have lived in the PNW for 13+ years and as any typical PNW would tell you, me and my family love the outdoors :) We all bike and run as a family during weekends and when I am by myself, I love to challenge myself with marathons, half marathons and full-day bike rides. If you are looking for a Seattle area running/biking buddy, I am game!

Thank you,
Amit

Please join me in welcoming Amit to the team!

Mike






----



## For build

I had been using 172.16.0.161 for testing builds in the PA lab.

During the time that 172.16.0.125 failed, I also used this for BJ proxy traffic.

I had mirrored all working files from this 161 to 172.16.0.70.
So there would be two build hosts working.

I will set up Gitlab CI/CD for automatic building on main and release branch commits.
If possible, continuous testing CI can be added using PA switch boxes, after we go through OK here.

The major issue is to transfer the build container images, which had been so big in size.

The solution should using build from Dockerfile in PA lab. It needs only about 2 minutes to run a same function image there.
But that doesn't work in BJ, which might never succeed due to the great wall sometimes.
So in BJ, we will run local container image registry for quick bootstrap.
And the size should be reduced from current 13GB to about 2GB for performances.

## For proxy

For proxy purpose, I had also prepared a v2ray clone on 68.
So later this can work as load balance or live fail-safe takeover.
This task needs no much CPU or memory.

## For Git mirror

This needs much storage and CPU.
In BJ lab, it's a 40 core server with 14TB storage.
One instance backup without artifacts/uploads would take about 60GB.

The current BJ instance is 700GB with some DB/repo backup and small uploads, without counting artifacts.

But I assume the load would be low in PA lab, so CPU can be OK.
Only multiple git processes consumes much CPU.

I had set up DNS resolving in BJ DNS as such:

    172.16.0.60 git
    172.16.0.68 bjit
    172.16.0.70 build70
    172.16.0.161 build161

In previous Gitlab releases, there had been instances mirror/syncing deployment choice.
But now that disappears.

So I first transfers one instance export to PA, then load it to the new setup.
The transfer is running. Perhaps two days can be OK if the 60GB transfer will not be broken.

After first import, later I can set up syncing only selected repos such as the main PICOS/AMPCON repo.
That would be less traffic and can resume on failure.

I will give you the login info when finished.
They should be the same to accessing the BJ instance.
I need to set push permission so that only you can commit/push to the PA instance and then sync back to BJ.
If not possible, that would be only one READ-ONLY mirror.

I had also set up mail server on this Git instance so it can really work.

I will finish running them this week.





----



Delivery has failed to these recipients or groups:
aaron@thepro.xyz (aaron@thepro.xyz)
Your message wasn't delivered. Despite repeated attempts to deliver your message, the recipient's email system refused to accept a connection from your email system.
Contact the recipient by some other means (by phone, for example) and ask them to tell their email admin that it appears that their email system is refusing connections from your email server. Give them the error details shown below. It's likely that the recipient's email admin is the only one who can fix this problem.
For Email Admins
No connection could be made because the target computer actively refused it. This usually results from trying to connect to a service that is inactive on the remote host - that is, one with no server application running. For more information and tips to fix this issue see this article: https://go.microsoft.com/fwlink/?LinkId=389361






Diagnostic information for administrators:
Generating server: CY4PR12MB1639.namprd12.prod.outlook.com
Receiving server: CY4PR12MB1639.namprd12.prod.outlook.com
aaron@thepro.xyz
7/30/2022 6:09:39 AM - Server at CY4PR12MB1639.namprd12.prod.outlook.com returned '550 5.4.316 Message expired, connection refused(Socket error code 10061)'
7/30/2022 5:59:25 AM - Server at thepro.xyz (218.240.159.78) returned '450 4.4.316 Connection refused [Message=Socket error code 10061] [LastAttemptedServerName=thepro.xyz] [LastAttemptedIP=218.240.159.78:25] [BN1NAM02FT047.eop-nam02.prod.protection.outlook.com](Socket error code 10061)'
Original message headers:
Received: from DM4PR12MB6351.namprd12.prod.outlook.com (2603:10b6:8:a2::6) by
 CY4PR12MB1639.namprd12.prod.outlook.com (2603:10b6:910:f::21) with Microsoft
 SMTP Server (version=TLS1_2, cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id
 15.20.5458.21; Fri, 29 Jul 2022 18:07:19 +0000
ARC-Seal: i=1; a=rsa-sha256; s=arcselector9901; d=microsoft.com; cv=none;
 b=Mt4aCewM4RHCyoD95PqSgVlwAjNytdI4aMV1ONPkypPLcsGsWlHX4Jv31UQsQEo4Cw/fRu73DJuqeX/zKEMfRrVSrvWSdtwk3ZduZqnW/zs2454blwHQyX3Up1m9GxwYtWJoweNdExY66GSveTlgfXhQHg46K6IwLkv4sQkwZRPiR1RzeZmLDg57+clIFfrpW4CzTgfqxm6zxOl0CHVzfRm3KRmV7GweW/zwo62q8pxSIWmA17hW578gVKjwK+iDKYHQaW4hd7uKXKchoA2xoYXm4xODk+PV10GIzTM1MyslTam/aNv/R5N4zmW7Wil8DsMbkmyszr5TCNd6ZvkcYA==
ARC-Message-Signature: i=1; a=rsa-sha256; c=relaxed/relaxed; d=microsoft.com;
 s=arcselector9901;
 h=From:Date:Subject:Message-ID:Content-Type:MIME-Version:X-MS-Exchange-AntiSpam-MessageData-ChunkCount:X-MS-Exchange-AntiSpam-MessageData-0:X-MS-Exchange-AntiSpam-MessageData-1;
 bh=pkPv3aK8dLeKvRH/BJpEy1KzDzezhB4QlqEX/Uw0dE4=;
 b=ACrScZHFQixr3ULXE9ghHEl+6VVA1UCz85yDezLNTowIym/KoK+QqXCiQ8EVOIaxf3nNwKAuR5jBo+UGa5ORZjElfh+9ugdk679zsDcAFB+vqUL45fkMhpHQ1OG9FvvuTdYeiwDw4xkXwfXJ9BjBUtJTSsTl45tSIxks0AMbnkGt/7u8hXaT6T69ZEGhTnbspiwyAwGWVvkmbgx5JVI9vlXNCF7EXFJLqFlL1GUehZxTmwCHNu8lP/Ldtkk45SU1bkHyfa+wur0y18a+87LJRbzUaiSE7KrkUa0fSmaNYbijlZo9lcwWwquvfrNWGiKOyM1Lnvflm3SxotkHlHYoig==
ARC-Authentication-Results: i=1; mx.microsoft.com 1; spf=pass
 smtp.mailfrom=pica8.com; dmarc=pass action=none header.from=pica8.com;
 dkim=pass header.d=pica8.com; arc=none
DKIM-Signature: v=1; a=rsa-sha256; c=relaxed/relaxed; d=pica8.com;
 s=selector1;
 h=From:Date:Subject:Message-ID:Content-Type:MIME-Version:X-MS-Exchange-SenderADCheck;
 bh=pkPv3aK8dLeKvRH/BJpEy1KzDzezhB4QlqEX/Uw0dE4=;
 b=P5sdoH1JCI1HHOToV1GLPZ0wotNnph9SBRVibjmRRQDtMd+2UIQYlMVTix8ILTLAS0P2Q1cxcjSR7Cs4nwMlI/W7tUT00LPPntf4MZRdo+AwTL1vOMR55sdshOH0rwx5nKPAPo+I+zWGTj++gMzKPkEyDjMeIeM2LC5DLKmBHQ0=
Received: from SN6PR12MB2671.namprd12.prod.outlook.com (2603:10b6:805:75::15)
 by DM4PR12MB6351.namprd12.prod.outlook.com (2603:10b6:8:a2::6) with Microsoft
 SMTP Server (version=TLS1_2, cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id
 15.20.5482.10; Fri, 29 Jul 2022 06:07:10 +0000
Received: from SN6PR12MB2671.namprd12.prod.outlook.com
 ([fe80::8d0d:792e:e85b:c122]) by SN6PR12MB2671.namprd12.prod.outlook.com
 ([fe80::8d0d:792e:e85b:c122%7]) with mapi id 15.20.5482.012; Fri, 29 Jul 2022
 06:07:10 +0000
From: Aaron Shang <aaron.shang@pica8.com>
To: "aaron@thepro.xyz" <aaron@thepro.xyz>
Subject: Fw: <Leon help>Re: credential for PROJECTS site - FW: AmpCon 1.8.1
 release
Thread-Topic: <Leon help>Re: credential for PROJECTS site - FW: AmpCon 1.8.1
 release
Thread-Index: AQHYoXBzVT7a5aeGNke84z+gvzsfpK2SMuzAgAFGWJ2AAWaofA==
Date: Fri, 29 Jul 2022 06:07:10 +0000
Message-ID: <SN6PR12MB2671CC3806EE6CCA592BFF13B8999@SN6PR12MB2671.namprd12.prod.outlook.com>
References: <SN6PR12MB2671A93958CF540E9192B14CB8979@SN6PR12MB2671.namprd12.prod.outlook.com>
 <DS7PR12MB60466390BF9FC3619FEF0AD5DD979@DS7PR12MB6046.namprd12.prod.outlook.com>
 <SN6PR12MB2671D32D94DD9E46B254698FB8969@SN6PR12MB2671.namprd12.prod.outlook.com>
In-Reply-To: <SN6PR12MB2671D32D94DD9E46B254698FB8969@SN6PR12MB2671.namprd12.prod.outlook.com>
Accept-Language: en-US
Content-Language: en-US
X-MS-Has-Attach:
X-MS-TNEF-Correlator:
msip_labels:
authentication-results: dkim=none (message not signed)
 header.d=none;dmarc=none action=none header.from=pica8.com;
x-ms-publictraffictype: Email
x-ms-office365-filtering-correlation-id: 3cf661c9-2da8-4f13-39bb-08da712892d8
x-ms-traffictypediagnostic: DM4PR12MB6351:EE_|CY4PR12MB1639:EE_
x-ms-exchange-senderadcheck: 1
x-ms-exchange-antispam-relay: 0
x-microsoft-antispam: BCL:0;
x-microsoft-antispam-message-info: rJPKvLdVW9Uj9VWw/JHW0thP0xhzG9YYh+WnbrDUKgctveLXAgGngluCFd7AQWGmvqfjCpg8EjLWiucDobsrGyDaWjVWp8w7XA2LebYBzcXUwUKTz5qT5I2qdhSL/0NRZQ2ZHksqHu043faGIzi0nUVRTZoyqCb5+g+wwXVsEp6mGjeflRQ+L9ctwVJWoXNwdorv4ioN6XlmCvquPk9t+xBmZk8E/5rWZ3GkuEmsms8O3NwqTUf1260vPWFcScwq+5lwfomWZL/3nQAgtWPRwToM3kxki/TeZhZZ2IaEyoQYbt3j3Rg5ap7tPLAmomESqMToKTMMVAK+95IiA95ytYAMvsrH5W9MuSq3uQDJp8eVo5bfijWIdVmFlwA2d9ulULsbiIsrCUz4RnySehy4LgI0mE2Hj8LdIiYM1+7anAWYa4qRd1OnmliWshD/EBdTmRruugeQtG3YYPo5aZVsPyMAmsm+yEIMK2E2bM5vrzMC9A3CidSv4TRuvTehYahpGnGm6qeG07Dd58U0qj0q3kzUD1AZTkOYytYf/85xX29S2nHt93W6nGkkiiS/VvVOyaSDdoSp9cIybHZ7K+9dfzt/TV6d/ikid7Bmp1P0bdPHlVrvi6l2ZqaWkThJkBSZZDZMeTkB0IoMmjTAWe6ZEIJlvGQqbJhZl7cOydfE1tPQdIN8qRclnJp7eVzxdxVfwWMLppx3kt1trD0KiQoAdLjCFKypq3oFb/qp9zxxNaNZcYNWYOvRHAicAEA0Dq+bnIyq6QR2iQAqna8M1OwKSJiRZ8A7dZ80fg4h/MGC7KsyBYGM6iG8MLuTcK3d5sHM5QapLvw/9XA3MTrLBzjL4pdnT8eGV8rPANy+n8AlBk4ua7iqpj0kKJw08p8UL2sXaqp9bnOEIRMRhvGXdEj2Fw==
x-forefront-antispam-report: CIP:255.255.255.255;CTRY:;LANG:en;SCL:1;SRV:;IPV:NLI;SFV:NSPM;H:SN6PR12MB2671.namprd12.prod.outlook.com;PTR:;CAT:NONE;SFS:(13230016)(6019001)(136003)(39830400003)(346002)(366004)(396003)(376002)(269900001)(66446008)(38070700005)(122000001)(66946007)(316002)(8676002)(76116006)(91956017)(66476007)(66556008)(64756008)(38100700002)(6916009)(55016003)(6506007)(2906002)(53546011)(71200400001)(7696005)(9686003)(26005)(41300700001)(52536014)(49410200001)(5660300002)(86362001)(83380400001)(966005)(186003)(33656002)(8936002)(44832011)(478600001)(586874003)(10721665004);DIR:OUT;SFP:1501;
x-ms-exchange-antispam-messagedata-chunkcount: 1
x-ms-exchange-antispam-messagedata-0: =?gb2312?B?R3J3SXU0ejFzLzJIdXdtTzZiaUg5U0gyRHFJSTkyYTdONHhxeitsQTNOTGVO?=
 =?gb2312?B?a0JPS2hJbi95bnJ5ZkQrUE1KeVZwajNiRzNuQ2xZNFZ5OFZMSGNwSlNKZzhD?=
 =?gb2312?B?WWkyRTJBaXc0YjdteDdYM2pubmxOb2lLczQ4dCs5YTU4Y25vb21SZ21MRTM5?=
 =?gb2312?B?VmFjRGhxS25SQm1zRmhOK2xRZzhwTEs2VE9BeGEydXFlMk5ZTnFOMThldkF0?=
 =?gb2312?B?ZnlBbG1uWk9wcEJnd083N1BCYzFCYlNPa0hUdUp3aldOQ3BIMFQ1Zm5Zd3Iy?=
 =?gb2312?B?Snh0MjNWTWpGR2F3STlGcUJObndINENnM1BnNnZZWXNJS05WNkJyb0YxdDVU?=
 =?gb2312?B?T2puR01iaU5PbzN1WjJpczFob0dmVlpiMkZNWjRYMHlUeG1mNjRXeEZvNE9W?=
 =?gb2312?B?YnlpQXM5aURzblZ4K1BsdHNjVkpteDEvM0NyRFYxY0dEOE1BTEVlSjQxWCtp?=
 =?gb2312?B?UkpCN1ZBL0dvelJXWHE3eUVEeXh0c2JoNUpXd3h5bnNjNkNaekpJZDgwUVRy?=
 =?gb2312?B?V1dSNHk3eFFWQ01aWXlUQWFFRTlGNjVad05iQkp0c2hiT0w5TURwdW1rZFpB?=
 =?gb2312?B?d3ZKOVBaVDNqR2pFTXNHcHNpck9iOEJKTklIc0c1NWcyYkpKdTdaRWE3MnBI?=
 =?gb2312?B?WHhrSjNnWFVFWEMxKy9VUU9SRjlpODhJNlJ1czJzZGk3UnliSXlnS1ZWeS8x?=
 =?gb2312?B?eVVya3dUbG5nb0dOQ2gvT3hia1dPTDdtNjkyazlNUjFxU1lhWngwNVNLUVRm?=
 =?gb2312?B?R05nSm1qalVPMVJRQS85QzlCRlZtancvZWhlNlFCRldGaVh1ZDFMeW5IaG1G?=
 =?gb2312?B?cnFMM3VyeTFRd0xjSldmQUdpSXhCVVJWRmcxNHBLL3RLRys4WWRQcXdnWm9K?=
 =?gb2312?B?STh5b3F0VTZuclVRc0V0YUV2dXordEJHNE1qM29KR0Y5VUk4bUZOMDZmNW5H?=
 =?gb2312?B?YTZWS29yMVNrRnBEdUhtOFpUTTdiUFV2SFJ4UzNFRUlGek9HbjU2dkhlS3Vw?=
 =?gb2312?B?NlE5K3B0ODZWeU5ob0lrUzF3b2NvdFNsUExsVTd3YzlHNGVKOEJJRVozR1Rp?=
 =?gb2312?B?RXNjWGEwd2J3T1FEMGdBR0IyTG5lMXVYNnM0V2x0RFNTeEpMRzU0M2RtRERj?=
 =?gb2312?B?YXJRQnpWeFBHdzVJQWp6RW5aVDRXZlJMRWNEV053RzhIa3A5V1Z5KzdLYllZ?=
 =?gb2312?B?ZEJiTzlWMmJoWUUvVWZVNHVhSEwralVwY000SzBnaHJPTXM5Wkc2eFlQc1gv?=
 =?gb2312?B?TWVZZWg2QitwSDk0ZWdIdmx5RE1obUpsR1pvaGk4NG9SSFZRRVU5TUFDLzd4?=
 =?gb2312?B?dHo4TVc5VEg0VHYvTXpXckVMbDZrcXFodTRINTFTdDFlRlk2NlE1Tmt1NmV4?=
 =?gb2312?B?S2thc1RLZnNEdkNTeGZib1F3Mi9vY01UOFpua3R2Z3U3dmhUNVp4dVpSNGdE?=
 =?gb2312?B?U3paQ00yMmxKRXp4d1plNXJ0cldJbnJqWEZzdlMyMmZhUXN2YjJoZHdReXA5?=
 =?gb2312?B?TGdyNGQ3VGVuRndZTWpxY0ljbU9nOW5MblQ0NXphVytWV3c3dmZMb1RUbFFr?=
 =?gb2312?B?SjFTSmUvOW9UclNiVXVUQitrVFk5VXlCUXpGOXJkZEJTUTlhNVVrRi8vRUox?=
 =?gb2312?B?MnZqd0QwVmdSSUEyZ2Zwcm84Ry9OK05ObmNnVURxRUROSUZFSGc3ZUYrM0I1?=
 =?gb2312?B?ckhUWUN4S0dYMm52dWhUU25Pc2IyeVE5K0R4dlR2NXE4cVZYL3N6eTV0QlBD?=
 =?gb2312?B?SG5US2RBMVNZcmNFSmh0bEJIMjhVaG03WDJIaTFHTWhkckJnZWEzZWROU21i?=
 =?gb2312?B?Y1B4QS95ekIwWkNDUHo2TU1SQlBwU1ZBVENjVU9lWVArMWhpWHZVVGtDTTgw?=
 =?gb2312?B?bGEwZm9WWmlvWFAzN1FZOUN1Zy9WZ3lzWHRsTDcvTlUvNll0SFVENHM1REta?=
 =?gb2312?B?TE9tOFpvWU5ZSEUyMEZKVFpuOWdVSG5WSVNmQUVhVkt1UVpRTVJra0crZXgx?=
 =?gb2312?B?T2RpeTNhajh5NkRpTkxRYmxJL0tpR0pUZ1JYQ29MNGNheGRiWS94R2dNNW9t?=
 =?gb2312?B?cDZoL2JBYXowd0RMNWsxQklyOTFkTUVrQjl0Sy8vOFFCVmF0b3d3MW4zYVBT?=
 =?gb2312?Q?t1tIqXmcIQMysimFTWg5qsfDc?=
Content-Type: text/plain; charset="gb2312"
Content-Transfer-Encoding: base64
MIME-Version: 1.0
X-MS-Exchange-CrossTenant-AuthAs: Internal
X-MS-Exchange-CrossTenant-AuthSource: SN6PR12MB2671.namprd12.prod.outlook.com
X-MS-Exchange-CrossTenant-Network-Message-Id: 3cf661c9-2da8-4f13-39bb-08da712892d8
X-MS-Exchange-CrossTenant-originalarrivaltime: 29 Jul 2022 06:07:10.1996
 (UTC)
X-MS-Exchange-CrossTenant-fromentityheader: Hosted
X-MS-Exchange-CrossTenant-id: 1649697f-e494-4b71-8227-3f383d0979ad
X-MS-Exchange-CrossTenant-mailboxtype: HOSTED
X-MS-Exchange-CrossTenant-userprincipalname: aLKULlrygzj8QERROhVxHi9lPka+5drgUzLZ/mDPRRjR3Smc181hc9c2xL17Bb96NxZT1zVdGhyAlaaFyUH3KA==
X-MS-Exchange-Transport-CrossTenantHeadersStamped: DM4PR12MB6351
Return-Path: aaron.shang@pica8.com
X-OriginatorOrg: pica8.com





----





That's good ideas.

Here we can discuss the last tricky part later.
Some design won't need to be so complicated.
We need not use the same for proxy and VPN. The proxies require not go to Palo Alto.

My measure about current connections:
- Peak of BJ lab to the fastest BJ local official Debian mirror is 5MiB; (I can easily reach 20MiB at home to this site.)
- File transfer with Google Drive via PA proxy is about 20KiB;
- Image fetching from PA lab server is about 100KiB (With initial speed about 1.5MiB, then falling down soon.);

________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Saturday, May 7, 2022 06:37
To: Aaron Shang; Yachal Chen
Cc: Lin Du; Mikel Tang
Subject: Cloud interconnection prototype

Aaron,

I see your comment about slow internet connections to US (or general cloud). Yachal and I have been working on an future concept of multi-campus interconnections. Maybe we can try this between Palo Alto and Beijing (and even Nanjing in the future).

The concept is to use a VM in the cloud, instead of VPN between the two sites, to connect multiple campus together. We did an experiment a while back and validated the following assumption. (Feel free to correct me if the assumption is wrong).


  1.  We have 300Mb/50Mb (download/upload speed)  internet connections at Palo Alto. We have 100Mb/50Mb (?) in Beijing.
  2.  However, when we connect the two sites with VPN, we usually only can get 1-5Mbps between the two sites.
  3.  Using the VPN as the proxy to access public cloud is even slower, because the traffic needs to go to the Palo Alto office and then go out again.

In our concept design, we can set up a VM in AWS China and another VM in Google San Jose. The traffic goes VPN from BJ to AWS China, and then AWS to Google, and then Google to Palo Alto. If we run the Proxy server in Google, the performance from Beijing to Internet should go up to at least 50Mbps.

In Yachal’s previous prototype, we use FRR in the VMs. IN the future, we want to use PICOS-V in the VMs. The VPN connection can be first simulated through a VM in local server or a Chrome box.

The tricky part is to design the network on both sides. We will need to partition the Beijing network into two subnets, one with the default gateway at the cloud proxy and the other with the default gateway locally in Beijing. In this way, all servers (or laptops) in the Cloud-Proxy subnet can have efficient route to the internet.

Does this make sense?

James






	This message was sent from outside the company by someone with a display name matching a user in your organization. Please DO NOT CLICK OR OPEN ANY LINKS OR ATTACHMENTS unless you recognize the source of this email CLICK 'FORWARD' to see the full email HEADER and ensure it is a pica8.com email! Please contact James or Neal if you have any questions.
Leon Li commented:
•
1.	We will separate the image management function. Plan to put it in “Settings” -> “Images Management” (new created menu item).
•
2.	In “Image Management”, we support to add / delete images.
o	Add images: It will support to upload local PicOS image and download with HTTP/HTTPS URL. And it will have a record in database to get the version, revision and platform from image file name.
o	Delete images:
It will delete the record and the image at the same time.
•
3.	After the “Image Management” support, the way to select image version in “Settings” -> “Add Switch Model”-> “Deployed image path” & “Deployed ONIE image”. Plan to show a modal for user to select the already uploaded image.
•
4.	Need to support 2.x.x tar.gz upgrade image.
•
5.	Task need to be done when provide hypervisor image:
	Package with default images for all platform (x86, 4610, N3000, N3100)
	Add default image for each support hardware model if user never configure it.
	Convert current upload images to image management.
•
6.	Tasks need to be done in AmpCon upgrade:
	Package with default images for all platform (x86, 4610, N3000, N3100)
	Add default image for each support hardware model
—
View it on GitLab.
You're receiving this email because of your account on 10.10.50.50. If you'd like to receive fewer emails, you can unsubscribe from this thread or adjust your notification settings.






Hi Tim,

Thanks for the notes. It will be helpful in future.

Best
Mani


On Mar 29, 2022, at 7:26 PM, Tim Yi <tim.yi@pica8.com> wrote:

Hi Mani,

I created a systemd service for GNS3, /etc/systemd/system/gns3.service. And I run “sudo systemctl enable gns3” and “sudo systemctl start gns3”.
The issue is no gns3 service after gns3 installed. We need to create it by manual.
BTW, the recommend way will create gns3 service in “gns3-remote-install.sh”.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Wednesday, March 30, 2022 10:04 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3


Hi Tim,

Thanks much for detailed notes on how to install GNS3.

I looked at my VM and tried GNS3 client on my MAC Pro. Looks like the server issue is fixed. Did you fix it? What change did you make yesterday to make it work?

My next step: I’m waiting for new OVA (for PicOS-V) from Lisa.

Best,
Mani

From: Tim Yi <tim.yi@pica8.com>
Date: Tuesday, March 29, 2022 at 12:02 AM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

There are serval ways to install a GNS3 server on Ubuntu.

1.	[Recommend] A fast way is to run these commands as root:
cd /tmp
curl https://raw.githubusercontent.com/GNS3/gns3-server/master/scripts/remote-install.sh > gns3-remote-install.sh
bash gns3-remote-install.sh

2.	Run apt to install gns3 as these:
sudo add-apt-repository ppa:gns3/ppa
sudo apt update
sudo apt install gns3-gui gns3-server

3.	Run pip3 to install gns3 as these:
sudo pip3 install gns3-server
sudo pip3 install gns3-gui
sudo apt install python3-pyqt5.QtSvg python3-pyqt5.qtwebsockets dynamips

For the last two ways, GNS3 server doesn’t startup with boot.
We need to create a systemd service for GNS3:
sudo vi /etc/systemd/system/gns3.service
Copy and paste the following parameters to this blank file:
[Unit]
Description=GNS3 server

[Service]
ExecStart=/usr/bin/gns3server

[Install]
WantedBy=multi-user.target
Save and exit (:x) Vim editor. Enable and start the created service:
sudo systemctl enable gns3
sudo systemctl start gns3

Now check to see if the service is properly working for all ways:
sudo systemctl status gns3

Check to see if the gns3 server is listening 3080 on localhost or 0.0.0.0:
netstat -anp | grep 3080
tcp        0      0 0.0.0.0:3080            0.0.0.0:*               LISTEN      1346/python


Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Tim Yi
Sent: Tuesday, March 29, 2022 12:38 PM
To: Mani Subramanian <mani.subramanian@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

I can access by ESXI web.
If I fix GNS3 server, I will tell you.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 11:17 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim, Tom,


Here are the access details:

Username: pica8-lab
Password:pica8pica8
IP: 192.168.42.231

You need to be on customer-config VPN. I have attached the VPN here.

Another way to access the GNS3 is via ESXi console:

URL: https://172.16.0.222/ui/#/login
User name: root
Password: pica8pa

Select GNS3-231 console.

I have also added user gns3 to the VM. Password I pica8pica8.

I have done installation from following directory
pica8-lab@gns3-picosv-demo-231:~$ pwd
/home/pica8-lab

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ pwd
/home/pica8-lab/.config/GNS3/2.2
pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ ls
gns3_controller.conf  gns3_gui.conf  gns3_gui.log  gns3_gui.pid  gns3_server.conf  gns3_server.log
gns3_server.conf file is located here….

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ more gns3_server.conf
[Server]
path = /usr/local/bin/gns3server
ubridge_path = /usr/bin/ubridge
host = 0.0.0.0
port = 3080
images_path = /home/pica8-lab/GNS3/images
projects_path = /home/pica8-lab/GNS3/projects
appliances_path = /home/pica8-lab/GNS3/appliances
additional_images_paths =
symbols_path = /home/pica8-lab/GNS3/symbols
configs_path = /home/pica8-lab/GNS3/configs
report_errors = True
auto_start = True
allow_console_from_anywhere = False
auth = False
user = admin
password =
protocol = http
console_start_port_range = 5000
console_end_port_range = 10000
udp_start_port_range = 10000
udp_end_port_range = 20000

Let me know whether you are able to access the server.

Please note down the step you undertake to resolve the issue. It will help me to train SEs.

Thanks,
Mani

From: Tim Yi <tim.yi@pica8.com>
Date: Monday, March 28, 2022 at 7:36 PM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

Please see https://pypi.org/project/gns3-server/  to add gns3 service.
And to change “host = localhost” in the conf.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 10:27 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim,

Service is not running.

Mar 23 22:01:18 gns3-picosv-demo-231 systemd[1]: Starting System Logging Service...
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]: imuxsock: Acquired UNIX socket '/run/systemd/journal/syslog' (fd 3) from systemd.  [v8.32.0]
Mar 23 22:01:19 gns3-picosv-demo-231 systemd[1]: Started System Logging Service.
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]: rsyslogd's groupid changed to 106
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]: rsyslogd's userid changed to 102
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]:  [origin software="rsyslogd" swVersion="8.32.0" x-pid="1407" x-info="http://www.rsyslog.com"] start
Mar 24 00:09:07 gns3-picosv-demo-231 rsyslogd[1407]:  [origin software="rsyslogd" swVersion="8.32.0" x-pid="1407" x-info="http://www.rsyslog.com"] rsyslogd was HUPed

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ sudo systemctl status gns3.service
Unit gns3.service could not be found.

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ more gns3_server.conf
[Server]
path = /usr/local/bin/gns3server
ubridge_path = /usr/bin/ubridge
host = localhost
port = 3080
images_path = /home/pica8-lab/GNS3/images
projects_path = /home/pica8-lab/GNS3/projects
appliances_path = /home/pica8-lab/GNS3/appliances
additional_images_paths =
symbols_path = /home/pica8-lab/GNS3/symbols
configs_path = /home/pica8-lab/GNS3/configs
report_errors = True
auto_start = True
allow_console_from_anywhere = False
auth = True
user = admin
password = GBSKMjLO7hS6xw1G83FPjmAamiwx4T4CMnLUCztZ4VsA9O56g8DI1cQ26tBVoURL
protocol = http
console_start_port_range = 5000
console_end_port_range = 10000
udp_start_port_range = 10000
udp_end_port_range = 20000

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ sudo systemctl start gns3.service
Failed to start gns3.service: Unit gns3.service not found.
pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ sudo systemctl start gns3
Failed to start gns3.service: Unit gns3.service not found.

What am I missing? I did not see any notes to start the server deamon.

Thanks,
Mani
From: Tim Yi <tim.yi@pica8.com>
Date: Monday, March 28, 2022 at 7:15 PM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

The GNS3 server only listens on local 127.0.0.1:3080.
So remote host cannot access port 3080.
Try to restart GNS3 service to listen on 0.0.0.0:3080.
If restart doesn’t work, please check the GNS3 configuration.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 10:05 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim,

Here are the info from GNS3:

TCP connection using port 3080 looks fine.
pica8-lab@gns3-picosv-demo-231:~$ netstat -antp | grep 3080
(Not all processes could be identified, non-owned process info
will not be shown, you would have to be root to see it all.)
tcp        0      0 127.0.0.1:3080          0.0.0.0:*               LISTEN      3161/python3
tcp        0      0 127.0.0.1:3080          127.0.0.1:51472         ESTABLISHED 3161/python3
tcp        0      0 127.0.0.1:51472         127.0.0.1:3080          ESTABLISHED 3161/python3
tcp6       0      0 ::1:3080                :::*                    LISTEN      3161/python3
tcp6       0      0 ::1:3080                ::1:57486               ESTABLISHED 3161/python3
tcp6       0      0 ::1:57486               ::1:3080                ESTABLISHED 3147/python3

This is default IP Tables in Ubuntu:
pica8-lab@gns3-picosv-demo-231:~$ sudo iptables -L
[sudo] password for pica8-lab:
Chain INPUT (policy ACCEPT)
target     prot opt source               destination
ACCEPT     udp  --  anywhere             anywhere             udp dpt:domain
ACCEPT     tcp  --  anywhere             anywhere             tcp dpt:domain
ACCEPT     udp  --  anywhere             anywhere             udp dpt:bootps
ACCEPT     tcp  --  anywhere             anywhere             tcp dpt:bootps

Chain FORWARD (policy ACCEPT)
target     prot opt source               destination
ACCEPT     all  --  anywhere             192.168.122.0/24     ctstate RELATED,ESTABLISHED
ACCEPT     all  --  192.168.122.0/24     anywhere
ACCEPT     all  --  anywhere             anywhere
REJECT     all  --  anywhere             anywhere             reject-with icmp-port-unreachable
REJECT     all  --  anywhere             anywhere             reject-with icmp-port-unreachable

Chain OUTPUT (policy ACCEPT)
target     prot opt source               destination
ACCEPT     udp  --  anywhere             anywhere             udp dpt:bootpc


What do I need to do?

Thanks,
Mani
From: Tim Yi <tim.yi@pica8.com>
Date: Monday, March 28, 2022 at 6:44 PM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

It seems connecting 192.168.42.231’s port 3080 failed.
Please check firewall configuration in GNS3 VM.
Make sure the URL http://192.168.42.231:3080 can be accessed by browser on your MAC.

And I see that you have installed gns3-server by both “apt install” and “pip3 install”. I think one is enough.
Please check if gns3-server is running and listening TCP port 3080.


Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 6:25 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim,

I followed your notes.

I’m attaching output of the errors I’m getting.

When I click OK in step 5, I get the error.

I’m able to SSH into GNS3 VM. From there I can ping any of the servers on my network fine. I’m also able to ping yahoo.com fine from SSH section. GNS3 VM to others servers and Internet – connection is fine. But I’m not able to progress beyond step #5. How to debug this?

Tonight after 8 PM I will be online. I will ping you. If you can help me go past this problem, it will help.

Thanks,
Mani

From: Tim Yi <tim.yi@pica8.com>
Date: Tuesday, March 22, 2022 at 8:18 PM
To: Aaron Shang <aaron.shang@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

First, install a GNS3 client on your computer following https://gns3.com/software/download

If you have installed GNS3 server on a Ubuntu VM, please check if your computer can access the Ubuntu VM through its IP address.
You can access the URL: http://a.b.c.d:3080 by web browser. (if VM's IP address is a.b.c.d)

If your computer cannot access, maybe you need follow this guide:
    https://docs.gns3.com/docs/getting-started/installation/esxi
This guide is to install the GNS3 VM on ESXI. GNS3 VM has Ubuntu preinstalled with GNS3 and preconfigured.

If the URL can be accessed, then go to configure GNS3 client on your computer:
1.	Configure remote main server. (If you use GNS3 VM, maybe skip this)
MENU: [Edit] --> [Preferences]


2.	Import PICOS-V template







3.	Edit template





Finally, save your setting, and new a project to build your topology.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

-----Original Message-----
From: Aaron Shang
Sent: Wednesday, March 23, 2022 8:31 AM
To: Mani Subramanian <mani.subramanian@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>; Tim Yi <tim.yi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Here in China, all google  / youtube URL had been blocked, so I cannot check them.

Since you installed ths OS, the vmware part should be not needed.

We installed Ubuntu on bare metal, not VMM. That should be better.

To be frank, I had no more experiences further on GNS3. You can refer to the official GNS3 docs. Or Tim can help on picos-v instances.

________________________________________
From: Mani Subramanian <mani.subramanian@pica8.com>
Sent: Wednesday, March 23, 2022 06:55
To: Aaron Shang
Cc: Tom Jia; Lisa Pi
Subject: Re: Need to consult you setting up GNS3

Hi Aaron,

First I installed a Ubuntu-18 VM on ESXi 6.5 server/

Then I installed GNS3 on top of it using the following instructions:
sudo add-apt-repository ppa:gns3/ppa
    sudo apt update
    sudo apt install gns3-gui gns3-server

Now I like to add three PicOS-V VMs in GNS3.

How do I do this?

Do I need to follow this part of the GNS3 document?
VMware ESXi#

VMware ESXi is for advanced users only and is not covered by this document.

    Video: https://www.youtube.com/watch?v=0T9YZssqDyE
    Video: https://www.youtube.com/watch?v=s7CkW9DNS3E

I'm not clear. Let me know.

Thanks,
Mani
On 3/17/22, 6:20 PM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

    Following this link.

    https://docs.gns3.com/docs/getting-started/installation/linux/

    You can install gns3 from ppa.

    sudo add-apt-repository ppa:gns3/ppa
    sudo apt update
    sudo apt install gns3-gui gns3-server

    Or directly from pypi.

    pip3 install gns3-server
    pip3 install gns3-gui

    In case you had no pip before.

    sudo apt install -y python3-pip qemu-kvm qemu-utils libvirt-clients libvirt-daemon-system virtinst wireshark apt-transport-https ca-certificates curl gnupg2


    Or you can find a host and I can set that up, in case of any handy trouble shootings.

    ________________________________________
    From: Aaron Shang <aaron.shang@pica8.com>
    Sent: Thursday, March 17, 2022 18:54
    To: Mani Subramanian; Lisa Pi; Tim Yi
    Cc: Tom Jia; Lin Du
    Subject: Re: Need to consult you setting up GNS3

    Hi, Mani,

    Yachal may guide you how to set the server up there. We had just followed the official get-started and starting from download an installation there.

    ________________________________________
    From: Mani Subramanian <mani.subramanian@pica8.com>
   Sent: Thursday, March 17, 2022 11:34
    To: Lisa Pi; Tim Yi; Aaron Shang
    Cc: Tom Jia; Lin Du
    Subject: Re: Need to consult you setting up GNS3

    Thanks Lisa. I will checkout your setup when I find time.

    Aaron, Meanwhile I also like to get started on setting up a testbed I outlined in the email below. Can you provide me steps on how to do it? Specially info on creating a Base Linux Ubuntu VM and creating GNS3 on top of it to create 3 PicOS-V VM I mentioned below.

    Thanks,
    Mani

    From: Lisa Pi <lisa.pi@pica8.com>
    Date: Wednesday, March 16, 2022 at 8:02 PM
    To: Mani Subramanian <mani.subramanian@pica8.com>, Tim Yi <tim.yi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
    Cc: Lisa Pi <lisa.pi@pica8.com>, Tom Jia <tom.jia@pica8.com>, Lin Du <lin.du@pica8.com>
    Subject: Re: Need to consult you setting up GNS3

    Hi， Mani

    1: You can use web browser access http://10.10.50.58:3080;


    Or use GNS3 client 2.2.21 with configuration in attachment.
    I have a project is test-picos-v, now there are on the 4.2.2.1 image, and I'm testing bgp,ospf.
    You can use switch “PICOS-V 4.2.1” in a new project, or I create a new project for you to demo mlag.

    2: For GNS3 setup, please  consult Tim or Aaron.

    Thanks
    ________________________________
    Lisa.Pi@pica8.com

    From: Mani Subramanian<mailto:mani.subramanian@pica8.com>
    Date: 2022-03-17 07:08
    To: Lisa Pi<mailto:lisa.pi@pica8.com>
    CC: Tom Jia<mailto:tom.jia@pica8.com>
    Subject: Need to consult you setting up GNS3
    Hi Lisa,

    I need to use a GNS3 setup with few PicOS-V VMs for demo. I heard you have one. Is it something I can leverage? Will you be able to share?

    Alternatively - better option for me is to setup a GNS3 testbed here in PA  with 3 PicOS-V VMs with MLAG setup as shown below for demo.



    [cid:image001.png@01D83975.2F42BF50]

    I have an ESXi server. I can create an Ubuntu VM or CentOS VM. Let me know which OS do you  recommend? Is 48GB memory and 100GB disk space good enough?

    If you provide me steps on how to create GNS3 setup, it will be helpful.

    1.      Setup Linux based VM

    2.      On top how to download and setup GNS3

    3.      How to create 3 VMs inside GNS3 for above topology.

    Any info or notes on how to create the GNS3 testt setup  will help me.

    Thanks,
    Mani








Hi Tim,

Thanks for the notes. It will be helpful in future.

Best
Mani


On Mar 29, 2022, at 7:26 PM, Tim Yi <tim.yi@pica8.com> wrote:

Hi Mani,

I created a systemd service for GNS3, /etc/systemd/system/gns3.service. And I run “sudo systemctl enable gns3” and “sudo systemctl start gns3”.
The issue is no gns3 service after gns3 installed. We need to create it by manual.
BTW, the recommend way will create gns3 service in “gns3-remote-install.sh”.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Wednesday, March 30, 2022 10:04 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3


Hi Tim,

Thanks much for detailed notes on how to install GNS3.

I looked at my VM and tried GNS3 client on my MAC Pro. Looks like the server issue is fixed. Did you fix it? What change did you make yesterday to make it work?

My next step: I’m waiting for new OVA (for PicOS-V) from Lisa.

Best,
Mani

From: Tim Yi <tim.yi@pica8.com>
Date: Tuesday, March 29, 2022 at 12:02 AM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

There are serval ways to install a GNS3 server on Ubuntu.

1.	[Recommend] A fast way is to run these commands as root:
cd /tmp
curl https://raw.githubusercontent.com/GNS3/gns3-server/master/scripts/remote-install.sh > gns3-remote-install.sh
bash gns3-remote-install.sh

2.	Run apt to install gns3 as these:
sudo add-apt-repository ppa:gns3/ppa
sudo apt update
sudo apt install gns3-gui gns3-server

3.	Run pip3 to install gns3 as these:
sudo pip3 install gns3-server
sudo pip3 install gns3-gui
sudo apt install python3-pyqt5.QtSvg python3-pyqt5.qtwebsockets dynamips

For the last two ways, GNS3 server doesn’t startup with boot.
We need to create a systemd service for GNS3:
sudo vi /etc/systemd/system/gns3.service
Copy and paste the following parameters to this blank file:
[Unit]
Description=GNS3 server

[Service]
ExecStart=/usr/bin/gns3server

[Install]
WantedBy=multi-user.target
Save and exit (:x) Vim editor. Enable and start the created service:
sudo systemctl enable gns3
sudo systemctl start gns3

Now check to see if the service is properly working for all ways:
sudo systemctl status gns3

Check to see if the gns3 server is listening 3080 on localhost or 0.0.0.0:
netstat -anp | grep 3080
tcp        0      0 0.0.0.0:3080            0.0.0.0:*               LISTEN      1346/python


Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Tim Yi
Sent: Tuesday, March 29, 2022 12:38 PM
To: Mani Subramanian <mani.subramanian@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

I can access by ESXI web.
If I fix GNS3 server, I will tell you.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 11:17 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim, Tom,


Here are the access details:

Username: pica8-lab
Password:pica8pica8
IP: 192.168.42.231

You need to be on customer-config VPN. I have attached the VPN here.

Another way to access the GNS3 is via ESXi console:

URL: https://172.16.0.222/ui/#/login
User name: root
Password: pica8pa

Select GNS3-231 console.

I have also added user gns3 to the VM. Password I pica8pica8.

I have done installation from following directory
pica8-lab@gns3-picosv-demo-231:~$ pwd
/home/pica8-lab

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ pwd
/home/pica8-lab/.config/GNS3/2.2
pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ ls
gns3_controller.conf  gns3_gui.conf  gns3_gui.log  gns3_gui.pid  gns3_server.conf  gns3_server.log
gns3_server.conf file is located here….

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ more gns3_server.conf
[Server]
path = /usr/local/bin/gns3server
ubridge_path = /usr/bin/ubridge
host = 0.0.0.0
port = 3080
images_path = /home/pica8-lab/GNS3/images
projects_path = /home/pica8-lab/GNS3/projects
appliances_path = /home/pica8-lab/GNS3/appliances
additional_images_paths =
symbols_path = /home/pica8-lab/GNS3/symbols
configs_path = /home/pica8-lab/GNS3/configs
report_errors = True
auto_start = True
allow_console_from_anywhere = False
auth = False
user = admin
password =
protocol = http
console_start_port_range = 5000
console_end_port_range = 10000
udp_start_port_range = 10000
udp_end_port_range = 20000

Let me know whether you are able to access the server.

Please note down the step you undertake to resolve the issue. It will help me to train SEs.

Thanks,
Mani

From: Tim Yi <tim.yi@pica8.com>
Date: Monday, March 28, 2022 at 7:36 PM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

Please see https://pypi.org/project/gns3-server/  to add gns3 service.
And to change “host = localhost” in the conf.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 10:27 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim,

Service is not running.

Mar 23 22:01:18 gns3-picosv-demo-231 systemd[1]: Starting System Logging Service...
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]: imuxsock: Acquired UNIX socket '/run/systemd/journal/syslog' (fd 3) from systemd.  [v8.32.0]
Mar 23 22:01:19 gns3-picosv-demo-231 systemd[1]: Started System Logging Service.
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]: rsyslogd's groupid changed to 106
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]: rsyslogd's userid changed to 102
Mar 23 22:01:19 gns3-picosv-demo-231 rsyslogd[1407]:  [origin software="rsyslogd" swVersion="8.32.0" x-pid="1407" x-info="http://www.rsyslog.com"] start
Mar 24 00:09:07 gns3-picosv-demo-231 rsyslogd[1407]:  [origin software="rsyslogd" swVersion="8.32.0" x-pid="1407" x-info="http://www.rsyslog.com"] rsyslogd was HUPed

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ sudo systemctl status gns3.service
Unit gns3.service could not be found.

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ more gns3_server.conf
[Server]
path = /usr/local/bin/gns3server
ubridge_path = /usr/bin/ubridge
host = localhost
port = 3080
images_path = /home/pica8-lab/GNS3/images
projects_path = /home/pica8-lab/GNS3/projects
appliances_path = /home/pica8-lab/GNS3/appliances
additional_images_paths =
symbols_path = /home/pica8-lab/GNS3/symbols
configs_path = /home/pica8-lab/GNS3/configs
report_errors = True
auto_start = True
allow_console_from_anywhere = False
auth = True
user = admin
password = GBSKMjLO7hS6xw1G83FPjmAamiwx4T4CMnLUCztZ4VsA9O56g8DI1cQ26tBVoURL
protocol = http
console_start_port_range = 5000
console_end_port_range = 10000
udp_start_port_range = 10000
udp_end_port_range = 20000

pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ sudo systemctl start gns3.service
Failed to start gns3.service: Unit gns3.service not found.
pica8-lab@gns3-picosv-demo-231:~/.config/GNS3/2.2$ sudo systemctl start gns3
Failed to start gns3.service: Unit gns3.service not found.

What am I missing? I did not see any notes to start the server deamon.

Thanks,
Mani
From: Tim Yi <tim.yi@pica8.com>
Date: Monday, March 28, 2022 at 7:15 PM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

The GNS3 server only listens on local 127.0.0.1:3080.
So remote host cannot access port 3080.
Try to restart GNS3 service to listen on 0.0.0.0:3080.
If restart doesn’t work, please check the GNS3 configuration.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 10:05 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim,

Here are the info from GNS3:

TCP connection using port 3080 looks fine.
pica8-lab@gns3-picosv-demo-231:~$ netstat -antp | grep 3080
(Not all processes could be identified, non-owned process info
will not be shown, you would have to be root to see it all.)
tcp        0      0 127.0.0.1:3080          0.0.0.0:*               LISTEN      3161/python3
tcp        0      0 127.0.0.1:3080          127.0.0.1:51472         ESTABLISHED 3161/python3
tcp        0      0 127.0.0.1:51472         127.0.0.1:3080          ESTABLISHED 3161/python3
tcp6       0      0 ::1:3080                :::*                    LISTEN      3161/python3
tcp6       0      0 ::1:3080                ::1:57486               ESTABLISHED 3161/python3
tcp6       0      0 ::1:57486               ::1:3080                ESTABLISHED 3147/python3

This is default IP Tables in Ubuntu:
pica8-lab@gns3-picosv-demo-231:~$ sudo iptables -L
[sudo] password for pica8-lab:
Chain INPUT (policy ACCEPT)
target     prot opt source               destination
ACCEPT     udp  --  anywhere             anywhere             udp dpt:domain
ACCEPT     tcp  --  anywhere             anywhere             tcp dpt:domain
ACCEPT     udp  --  anywhere             anywhere             udp dpt:bootps
ACCEPT     tcp  --  anywhere             anywhere             tcp dpt:bootps

Chain FORWARD (policy ACCEPT)
target     prot opt source               destination
ACCEPT     all  --  anywhere             192.168.122.0/24     ctstate RELATED,ESTABLISHED
ACCEPT     all  --  192.168.122.0/24     anywhere
ACCEPT     all  --  anywhere             anywhere
REJECT     all  --  anywhere             anywhere             reject-with icmp-port-unreachable
REJECT     all  --  anywhere             anywhere             reject-with icmp-port-unreachable

Chain OUTPUT (policy ACCEPT)
target     prot opt source               destination
ACCEPT     udp  --  anywhere             anywhere             udp dpt:bootpc


What do I need to do?

Thanks,
Mani
From: Tim Yi <tim.yi@pica8.com>
Date: Monday, March 28, 2022 at 6:44 PM
To: Mani Subramanian <mani.subramanian@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

It seems connecting 192.168.42.231’s port 3080 failed.
Please check firewall configuration in GNS3 VM.
Make sure the URL http://192.168.42.231:3080 can be accessed by browser on your MAC.

And I see that you have installed gns3-server by both “apt install” and “pip3 install”. I think one is enough.
Please check if gns3-server is running and listening TCP port 3080.


Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

From: Mani Subramanian
Sent: Tuesday, March 29, 2022 6:25 AM
To: Tim Yi <tim.yi@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Hi Tim,

I followed your notes.

I’m attaching output of the errors I’m getting.

When I click OK in step 5, I get the error.

I’m able to SSH into GNS3 VM. From there I can ping any of the servers on my network fine. I’m also able to ping yahoo.com fine from SSH section. GNS3 VM to others servers and Internet – connection is fine. But I’m not able to progress beyond step #5. How to debug this?

Tonight after 8 PM I will be online. I will ping you. If you can help me go past this problem, it will help.

Thanks,
Mani

From: Tim Yi <tim.yi@pica8.com>
Date: Tuesday, March 22, 2022 at 8:18 PM
To: Aaron Shang <aaron.shang@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, Lisa Pi <lisa.pi@pica8.com>
Subject: RE: Need to consult you setting up GNS3

Hi Mani,

First, install a GNS3 client on your computer following https://gns3.com/software/download

If you have installed GNS3 server on a Ubuntu VM, please check if your computer can access the Ubuntu VM through its IP address.
You can access the URL: http://a.b.c.d:3080 by web browser. (if VM's IP address is a.b.c.d)

If your computer cannot access, maybe you need follow this guide:
    https://docs.gns3.com/docs/getting-started/installation/esxi
This guide is to install the GNS3 VM on ESXI. GNS3 VM has Ubuntu preinstalled with GNS3 and preconfigured.

If the URL can be accessed, then go to configure GNS3 client on your computer:
1.	Configure remote main server. (If you use GNS3 VM, maybe skip this)
MENU: [Edit] --> [Preferences]


2.	Import PICOS-V template







3.	Edit template





Finally, save your setting, and new a project to build your topology.

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com  |  www.pica8.com

-----Original Message-----
From: Aaron Shang
Sent: Wednesday, March 23, 2022 8:31 AM
To: Mani Subramanian <mani.subramanian@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lisa Pi <lisa.pi@pica8.com>; Tim Yi <tim.yi@pica8.com>
Subject: Re: Need to consult you setting up GNS3

Here in China, all google  / youtube URL had been blocked, so I cannot check them.

Since you installed ths OS, the vmware part should be not needed.

We installed Ubuntu on bare metal, not VMM. That should be better.

To be frank, I had no more experiences further on GNS3. You can refer to the official GNS3 docs. Or Tim can help on picos-v instances.

________________________________________
From: Mani Subramanian <mani.subramanian@pica8.com>
Sent: Wednesday, March 23, 2022 06:55
To: Aaron Shang
Cc: Tom Jia; Lisa Pi
Subject: Re: Need to consult you setting up GNS3

Hi Aaron,

First I installed a Ubuntu-18 VM on ESXi 6.5 server/

Then I installed GNS3 on top of it using the following instructions:
sudo add-apt-repository ppa:gns3/ppa
    sudo apt update
    sudo apt install gns3-gui gns3-server

Now I like to add three PicOS-V VMs in GNS3.

How do I do this?

Do I need to follow this part of the GNS3 document?
VMware ESXi#

VMware ESXi is for advanced users only and is not covered by this document.

    Video: https://www.youtube.com/watch?v=0T9YZssqDyE
    Video: https://www.youtube.com/watch?v=s7CkW9DNS3E

I'm not clear. Let me know.

Thanks,
Mani
On 3/17/22, 6:20 PM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

    Following this link.

    https://docs.gns3.com/docs/getting-started/installation/linux/

    You can install gns3 from ppa.

    sudo add-apt-repository ppa:gns3/ppa
    sudo apt update
    sudo apt install gns3-gui gns3-server

    Or directly from pypi.

    pip3 install gns3-server
    pip3 install gns3-gui

    In case you had no pip before.

    sudo apt install -y python3-pip qemu-kvm qemu-utils libvirt-clients libvirt-daemon-system virtinst wireshark apt-transport-https ca-certificates curl gnupg2


    Or you can find a host and I can set that up, in case of any handy trouble shootings.

    ________________________________________
    From: Aaron Shang <aaron.shang@pica8.com>
    Sent: Thursday, March 17, 2022 18:54
    To: Mani Subramanian; Lisa Pi; Tim Yi
    Cc: Tom Jia; Lin Du
    Subject: Re: Need to consult you setting up GNS3

    Hi, Mani,

    Yachal may guide you how to set the server up there. We had just followed the official get-started and starting from download an installation there.

    ________________________________________
    From: Mani Subramanian <mani.subramanian@pica8.com>
   Sent: Thursday, March 17, 2022 11:34
    To: Lisa Pi; Tim Yi; Aaron Shang
    Cc: Tom Jia; Lin Du
    Subject: Re: Need to consult you setting up GNS3

    Thanks Lisa. I will checkout your setup when I find time.

    Aaron, Meanwhile I also like to get started on setting up a testbed I outlined in the email below. Can you provide me steps on how to do it? Specially info on creating a Base Linux Ubuntu VM and creating GNS3 on top of it to create 3 PicOS-V VM I mentioned below.

    Thanks,
    Mani

    From: Lisa Pi <lisa.pi@pica8.com>
    Date: Wednesday, March 16, 2022 at 8:02 PM
    To: Mani Subramanian <mani.subramanian@pica8.com>, Tim Yi <tim.yi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
    Cc: Lisa Pi <lisa.pi@pica8.com>, Tom Jia <tom.jia@pica8.com>, Lin Du <lin.du@pica8.com>
    Subject: Re: Need to consult you setting up GNS3

    Hi， Mani

    1: You can use web browser access http://10.10.50.58:3080;


    Or use GNS3 client 2.2.21 with configuration in attachment.
    I have a project is test-picos-v, now there are on the 4.2.2.1 image, and I'm testing bgp,ospf.
    You can use switch “PICOS-V 4.2.1” in a new project, or I create a new project for you to demo mlag.

    2: For GNS3 setup, please  consult Tim or Aaron.

    Thanks
    ________________________________
    Lisa.Pi@pica8.com

    From: Mani Subramanian<mailto:mani.subramanian@pica8.com>
    Date: 2022-03-17 07:08
    To: Lisa Pi<mailto:lisa.pi@pica8.com>
    CC: Tom Jia<mailto:tom.jia@pica8.com>
    Subject: Need to consult you setting up GNS3
    Hi Lisa,

    I need to use a GNS3 setup with few PicOS-V VMs for demo. I heard you have one. Is it something I can leverage? Will you be able to share?

    Alternatively - better option for me is to setup a GNS3 testbed here in PA  with 3 PicOS-V VMs with MLAG setup as shown below for demo.



    [cid:image001.png@01D83975.2F42BF50]

    I have an ESXi server. I can create an Ubuntu VM or CentOS VM. Let me know which OS do you  recommend? Is 48GB memory and 100GB disk space good enough?

    If you provide me steps on how to create GNS3 setup, it will be helpful.

    1.      Setup Linux based VM

    2.      On top how to download and setup GNS3

    3.      How to create 3 VMs inside GNS3 for above topology.

    Any info or notes on how to create the GNS3 testt setup  will help me.

    Thanks,
    Mani








Hi, Mike, and the team,

This is Aaron from Engineering.
I had created Gitlab accounts for you and the Seattle team(of To: field), please try to see whether you can access.

If you know someone else who hope to access the engineering services here, please let me know to set up accounts.


Because @pica8.com mail server is now rejecting mails sent from our lab, you can not get mail notifications via @pica8.com mailbox.

So I have to reset passwords for you to login, instead of you reset that according to URL sent from initial Gitlab account generating.
I will send the passwords to you in separate mails.
You can log in using the mailbox I used for creating your accounts (I got from our HIBOB), or you can also log in using the part of that mailbox before the `@`.

If any of you need help on access or account resetting, please let me know.



I am not sure whether the @goborderless.io mailbox can receive these mails.
If yes, that would be good news, then we can use them as possible.




Basic info
========

It's a free Gitlab-ee on-premise instance from the official omnibus deb package running Debian 12 on a 32GB RAM Xeon E5-2650.

The server access is code.pica8.local resolving to 10.10.50.50 by internal DNS, no SSL access.
So you can access by:
http://10.10.50.50/

A login is needed to access even public repo.

Repo structure as below.

Group repo is the legacy group, holding main picos code:
http://10.10.50.50/repo/pica8

Group pica8
  http://10.10.50.50/pica8
holds internal repos, such as boxowner, knowledge-base, and picos-v.

Group pub
  http://10.10.50.50/pub
holds internal maintained repo, such as:
frr, gnxi, kea, libyang, gnmi, pcre2, onl, yocto, etc.

Group solution
  http://10.10.50.50/solution
holds solution related repo, such as packetfence, ampcon, ansible modules, and code for https://license.pica8.com/.

The repos are too large to be hosted in clouds, considering access speed.
If you require quick access in Seattle, I can help set up pushing mirrors there.

The large size also made some CPU intensive git processing slow in response.

A history re-writing is needed to remove deleted history files to greatly reduce repo size.
Or I had tried `gitee` hosting which is very fast, while it has fewer features.

--
Aaron





For testing only. You can add VMs there, but the Mem/CPU/Storage are very limited on this PC.


vSphere  = (lots of) ESXi + vCenter Servers

vSphere Client connects to vSphere to manage ESXis and vCenter Servers.


Refer to :
https://docs.vmware.com/tw/VMware-vSphere/index.html

VMware vSphere 是 VMware 的虛擬化平台，可將資料中心轉換為彙總的運算基礎結構，其中包括 CPU、儲存區和網路資源。vSphere 會將這些基礎結構當作一個統一的作業環境來管理，並為您提供工具來管理加入該環境的資料中心。

vSphere 的兩個核心元件是 ESXi 和 vCenter Server。ESXi 是一個虛擬化平台，您可在其中建立和執行虛擬機器及虛擬應用裝置。vCenter Server 是一項服務，您可透過該服務來管理網路中連線的多個主機並為主機資源建立集區。



The installation info.

## ESXi 8.0

https://10.10.50.45/

login/password:
root
Pica8.com

If enabled SSH in the above web UI, the SSH login/password are the same.

## vCenter Server Management

https://10.10.50.138:5480/

login/password:
root
Pica8.com

## vSphere client

https://10.10.50.138

login/password:
administrator@pica8.local
Pica8.com

The login is not able to be changed.


The ESXi install iso:

http://10.10.50.10/files/incoming/vmware/VMware-VMvisor-Installer-8.0-20513097.x86_64.iso













Tracing route to sni1gl.wpc.sigmacdn.net [152.195.19.97]
over a maximum of 30 hops:

  1     1 ms    <1 ms     1 ms  192.168.1.1
  2     4 ms    41 ms     3 ms  218.240.160.9
  3     *        *       10 ms  10.99.99.2
  4     4 ms     7 ms     4 ms  114.247.25.209
  5     8 ms     5 ms     6 ms  61.148.31.69
  6     *        *        *     Request timed out.
  7     2 ms     3 ms     4 ms  125.33.186.77
  8     6 ms     6 ms     6 ms  219.158.5.154
  9    11 ms    12 ms    12 ms  219.158.16.70
 10   156 ms   149 ms   156 ms  219.158.100.26
 11   256 ms   256 ms   255 ms  213.248.71.89
 12   242 ms   241 ms   240 ms  62.115.125.160
 13   242 ms   245 ms   241 ms  62.115.155.87
 14   240 ms   241 ms   240 ms  152.195.84.141
 15   257 ms   255 ms   256 ms  152.195.19.97

Trace complete.

C:\Users\kevin>tracert -d office.com

Tracing route to office.com [13.107.6.156]
over a maximum of 30 hops:

  1     1 ms    <1 ms    <1 ms  192.168.1.1
  2     3 ms     3 ms     3 ms  218.240.160.9
  3     *        *        *     Request timed out.
  4     3 ms     5 ms     5 ms  114.247.25.209
  5    39 ms     5 ms    19 ms  61.148.31.69
  6     9 ms     6 ms     6 ms  61.149.203.1
  7     4 ms    12 ms     3 ms  202.96.12.33
  8     *        *        *     Request timed out.
  9    28 ms    31 ms    29 ms  219.158.113.110
 10    31 ms    28 ms    28 ms  219.158.113.137
 11    58 ms    58 ms    59 ms  219.158.112.254
 12    59 ms    63 ms    59 ms  219.158.45.170
 13    57 ms    57 ms    61 ms  104.44.238.130
 14    57 ms    57 ms    57 ms  104.44.236.176
 15     *        *        *     Request timed out.
 16     *        *        *     Request timed out.
 17     *        *        *     Request timed out.
 18     *        *        *     Request timed out.
 19    55 ms    69 ms    54 ms  13.107.6.156

Trace complete.



________________________________________
From: Aaron Shang <aaron.shang@pica8.com>
Sent: Thursday, March 30, 2023 09:55
To: Aaron Shang
Subject: RE: Microsoft 365 security: You have messages in quarantine






Tracing route to csp.pica8.com [52.9.50.114]
over a maximum of 30 hops:

  1     1 ms     3 ms     2 ms  192.168.1.1
  2     4 ms     5 ms     3 ms  218.240.160.9
  3     *       10 ms     5 ms  10.99.99.2
  4     4 ms     6 ms     4 ms  114.247.25.209
  5     4 ms     3 ms     1 ms  61.148.31.69
  6     *        *        *     Request timed out.
  7     3 ms     6 ms     5 ms  124.65.194.29
  8    10 ms     7 ms    10 ms  219.158.5.146
  9    11 ms     5 ms     4 ms  219.158.16.82
 10   152 ms   157 ms   156 ms  219.158.98.18
 11   153 ms   152 ms   152 ms  219.158.43.6
 12     *        *        *     Request timed out.
 13     *        *        *     Request timed out.
 14     *        *        *     Request timed out.
 15     *        *        *     Request timed out.
 16     *        *        *     Request timed out.
 17     *        *        *     Request timed out.
 18     *        *        *     Request timed out.
 19     *        *        *     Request timed out.
 20     *        *        *     Request timed out.
 21     *        *        *     Request timed out.
 22     *        *        *     Request timed out.
 23     *        *        *     Request timed out.
 24     *        *        *     Request timed out.
 25     *        *        *     Request timed out.
 26     *        *        *     Request timed out.
 27     *        *        *     Request timed out.
 28     *        *        *     Request timed out.
 29     *        *        *     Request timed out.
 30     *        *        *     Request timed out.

Trace complete.




Tracing route to sni1gl.wpc.sigmacdn.net [152.195.19.97]
over a maximum of 30 hops:

  1     1 ms    <1 ms     1 ms  192.168.1.1
  2     4 ms    41 ms     3 ms  218.240.160.9
  3     *        *       10 ms  10.99.99.2
  4     4 ms     7 ms     4 ms  114.247.25.209
  5     8 ms     5 ms     6 ms  61.148.31.69
  6     *        *        *     Request timed out.
  7     2 ms     3 ms     4 ms  125.33.186.77
  8     6 ms     6 ms     6 ms  219.158.5.154
  9    11 ms    12 ms    12 ms  219.158.16.70
 10   156 ms   149 ms   156 ms  219.158.100.26
 11   256 ms   256 ms   255 ms  213.248.71.89
 12   242 ms   241 ms   240 ms  62.115.125.160
 13   242 ms   245 ms   241 ms  62.115.155.87
 14   240 ms   241 ms   240 ms  152.195.84.141
 15   257 ms   255 ms   256 ms  152.195.19.97

Trace complete.

C:\Users\kevin>tracert -d office.com

Tracing route to office.com [13.107.6.156]
over a maximum of 30 hops:

  1     1 ms    <1 ms    <1 ms  192.168.1.1
  2     3 ms     3 ms     3 ms  218.240.160.9
  3     *        *        *     Request timed out.
  4     3 ms     5 ms     5 ms  114.247.25.209
  5    39 ms     5 ms    19 ms  61.148.31.69
  6     9 ms     6 ms     6 ms  61.149.203.1
  7     4 ms    12 ms     3 ms  202.96.12.33
  8     *        *        *     Request timed out.
  9    28 ms    31 ms    29 ms  219.158.113.110
 10    31 ms    28 ms    28 ms  219.158.113.137
 11    58 ms    58 ms    59 ms  219.158.112.254
 12    59 ms    63 ms    59 ms  219.158.45.170
 13    57 ms    57 ms    61 ms  104.44.238.130
 14    57 ms    57 ms    57 ms  104.44.236.176
 15     *        *        *     Request timed out.
 16     *        *        *     Request timed out.
 17     *        *        *     Request timed out.
 18     *        *        *     Request timed out.
 19    55 ms    69 ms    54 ms  13.107.6.156

Trace complete.








Hi, welcome,

I had created account with login/passwd:

achint.sehgal@pica8.com
/
achint.sehgal@pica8.com

on:
http://10.10.50.11/bugs/

And login/passwd:
achint.sehgal@pica8.com
/
"checksum hello-world"          <--- I reset the passwd to the left string because the login init mail was rejected.

on
http://10.10.50.50/

Suggest to use this Gitlab instance to track issues for projects besides picos.


Please let me know if you have login or usage issues.

________________________________________
From: Tom Jia <tom.jia@pica8.com>
Sent: Friday, April 14, 2023 03:03
To: Achint Sehgal; Aaron Shang
Subject: Bugzilla Account for Achint

Hi Aaron,

Could you please create a Bugzilla account for Achint?

Hi Achint,

If you are available today, I would like to show you how we are using Bugzilla track the issues of PICOS?

Thanks.

________________________________
Best regards,
Tom Jia (贾彦民)







________________________________________
From: Microsoft Audio Conferencing <maccount@microsoft.com>
Sent: Saturday, March 11, 2023 08:35
To: Aaron Shang
Subject: You now have Audio Conferencing for Microsoft Teams – Here is your dial-in information and PIN

–
You now have Audio Conferencing for Microsoft Teams – Here is your dial-in information and PIN
–
–

Office 365 Audio Conferencing has been turned on for your account. With Audio Conferencing, you and your meeting participants can join by phone.

        Name:
        Account:                aaron.shang@pica8.com

Your Audio Conferencing information

Here are the credentials that you and your meeting participants can use to join by phone. This information will be added to any Microsoft Teams meetings you create. To join a meeting by phone, dial the conference phone number and enter the conference ID.

        Conference phone number:                +86 (40) 08191087

Note: You can get additional phone numbers by clicking the “Find a local number” link in your meeting invites.

Your Audio Conferencing PIN

As the meeting organizer, you’ll need to enter your PIN to start your meeting when you’re the first person to join and you join by phone. As with any PIN, keep it confidential. You can reset your PIN via the reset PIN link that is included in your meeting invites or by contacting your Office 365 admin.

        Audio Conferencing PIN:                 61279

–
–

This is an automatically generated service communication. For more information, please contact your administrator.

–







________________________________________
From: Brad Bullington <brad.bullington@pica8.com>
Sent: Saturday, March 11, 2023 08:39
To: Pica8 All
Cc: Jamie Kuhnhausen
Subject: CEO COMMUNICATION: FIRST BI-WEEKLY COMPANY UPDATE

Team,

Introduction:

It is with excitement that I reach out with the first of what will be an on-going update email from me, occurring regularly every two weeks. The goal is to supplement other forums and meetings and provide an overall narrative on the developments at the company.

Along with this will be some key functional highlights to keep everyone aware of a balance of our activities, successes, and challenges. Examples will include: achievement of overall goals; interim results; developments in areas of people / team and culture; customer engagement and wins; market trends, conditions and updates; product launches and feedback; and overall operations of the company.

A Critical Focus: Team

However, for my first email, I want to start with: TEAM.  Along with customers, it’s at the core of everything we do, particularly as a software company.

Our people, and how we work together as a team, are essentially our product, our lifeblood.

This has been an intense focus of mine since joining the company.  In fact, it was a key reason I joined. The team that James built here is formidable. The amount of accomplishment in terms of product, customers acquired, and revenue for a (historically, but we are changing that :-)) non-recurring revenue model company were impressive.

Beyond the results, the ‘can do’, ‘get it done today’ culture that accompanied it was as impressive. And, “how” we get work done, is equally as important to the work we do.

We have a strong set of core values that provides structure as we work toward our big goals and scale for growth. This month, we kick off a new learning series called “Lean In Learning”. The topic for March will be “Living our Core Values” - we’ll discuss how we collectively and visibly live our company values every day. Look for an invite coming soon.

I relish how welcoming our team and culture are. Keep that up, as it becomes harder to maintain as we scale but even more critical to our success.

Like any team in pursuit of goals in a dynamic environment, there is always an opportunity and necessity to evolve. We are well down the path to this as well.

In the past two quarters, we have added 14 new members to the team!

We have added a range of new skills and expanded capacity in areas of existing skill. Examples include new skills in cloud services development and PLG-focused product management, lead generation, mid-market and Enterprise Sales.

We have also implemented systems (tech stack: Slack, Jira, Confluence) and processes (Rhythms of the Business ‘RoB’s’) to both streamline and enable scaling of the business moving forward and required to meet our 2023 Goals and OKRs.

OKRs:  ‘The Scoreboard For Results:

OKRs are where the rubber meets the road between our people, culture, processes and efforts.  We use them as the core of our weekly ELT meetings and as a basis for reporting to the Board.

Following Q1 ‘close’, we will use them to broadly and frequently communicate with the team.  We’ll plan to do a review as part of an all hands following each quarter, with a written update on how we are tracking mid-quarter.

Here is a snapshot of our annual OKR’s as a company for 2023.

[Timeline  Description automatically generated with low confidence]

Borderless.io Launch:

Yesterday was also another major milestone for the company with our launch of the Borderless.io brand.  To re-summarize for those that were not able to attend the preview meeting or receive a briefing from their functional leader:


  *   There are NO changes in reporting, business process or roles related to this launch
  *   Over the next ~90 days, we will more fully integrate the Pica8 and Borderless brands
  *   The driver behind this effort is a combination of re-branding around our expanding offering (to include cloud solutions and layers of value beyond ‘Access”) as well as refreshing our brand and positioning in advance of a major 2H’23 fundraise

If you have any questions about which brand you are supporting in this interim period, please reach out to either your functional leader, Jamie Kuhnhausen or me.

Fundraising:

Also exciting was the close of an insider-led fundraise.  The majority of all investors and all of our major investors took their full pro-rata*.  In the case of our largest investor, VantagePoint Capital Partners, they took a super pro-rata amount.  This exhibits very strong support from our investor base as we scale and diversify our business, targeting a large raise in the 2H’23.

To close, we have made substantial progress over the past several quarters against our key objectives and OKRs.  We’re looking forward to doing a detailed review of our key metrics for Q1 at the next All Team Meeting in early April.

In the meantime, to continue to refine execution, there are three key areas of focus for the team:


  1.  Launch and scale our new lead generation engine—this is tied to all ‘5 P’s’: Product (continue to advance and support our core Picos and Ampcon offerings), Pricing (leverage our new ‘lower first cost’ subscription pricing model launched in Q1) Promotion (promote the refresh of Pica8 and launch of Borderless to engage the market and customers), Placement (continue to refine and expand our gtm relationships, partner thru direct), Partners (execute on 1-2 key strategic partnerships in Q2)
  2.  Refine and scale our GTM organization and selling motions
  3.  Launch Borderless 1.0 ‘private preview’ by end of Q1

We’ll continue to report out on progress vs. goals in the forums mentioned above and through this regular email communication.

As always, the ELT and I appreciate everyone’s continued efforts, and are celebrating the successes we’re having.  I ALSO WANT TO HEAR FROM YOU, whether seeking clarifications on any of the above, or thoughts on opportunities, challenges and improvement areas, and wins to highlight as we travel this journey together.

Onward and Upward!

Brad


*Pro rata gives current investors a right (but not an obligation) to participate in future funding rounds.






________________________________________
From: Zoneson Chen <zoneson@gmail.com>
Sent: Thursday, March 2, 2023 10:16
To: Aaron Shang
Subject: Re: thank you for the card and all of your kind words

This message was sent from outside the company by someone with a display name matching a user in your organization. Please DO NOT CLICK OR OPEN ANY LINKS OR ATTACHMENTS unless you recognize the source of this email CLICK 'FORWARD' to see the full email HEADER and ensure it is a pica8.com email! Please contact James or Neal if you have any questions.
Aaron,

The pleasure is all mine having the opportunity to work with you and BJ team. We old men have more patience than you young men because our responses are slower.

Thank you for your greetings! Wish you and your family the best!

Sincerely,

Zoneson




On Wed, Mar 1, 2023 at 5:21 PM Aaron Shang <aaron.shang@pica8.com<mailto:aaron.shang@pica8.com>> wrote:
Hi, Zonezon,

看到歡送您退休的照片，在安享榮休之際，我特別感受到很榮幸與您共事數載，非常感謝過去工作中您的耐心與寬容，衷心希望您在未來新的生活安樂而激動人心！

--
Aaron

________________________________________
From: James Liao <james.liao@pica8.com<mailto:james.liao@pica8.com>>
Sent: Wednesday, March 1, 2023 09:08
To: Lin Du; Tom Jia; Mikel Tang; Aaron Shang; Daisy Zhao; Iris Rong; Lisa Pi; Tong Zhang; Tracy Yang; Tim Yi; Leon Li
Subject: FW: thank you for the card and all of your kind words

I am not sure whether I should send to all our China team, but I think some of you already know. Zoneson retired today after 12 years in Pica8. I am sure he will come back visit from time to time, but officially he has retired.

James

From: Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>
Date: Tuesday, February 28, 2023 at 2:01 AM
To: Pica8 USA <pica8-us@pica8.com<mailto:pica8-us@pica8.com>>
Subject: thank you for the card and all of your kind words
Dear colleagues,

As I prepare to move on to my next phase, I wanted to take a moment to express my gratitude for the wonderful experiences and memories we have shared together. It has been an honor and a privilege to work in Pica8.

Please feel free to reach out to me anytime at my personal email address, zoneson@gmail.com<mailto:zoneson@gmail.com><mailto:zoneson@gmail.com<mailto:zoneson@gmail.com>>, or by phone at 408-828-6593. I am always here.

Sincerely,

Zoneson






I think 4.3.1.5 had fixed the /tmp full issue, since we had done several measures for that, including fixed the root cause.

Here are my notes till now on this issue, for your info and possible future engineering references.


# Look into the 100% full /tmp issue

## Root cause

- /tmp/log/{frr,system}_commands.log had been re-created but pica/lib/{system,frr}_backend_task.cc keep writing logs to the old files.
- Thus pica_sif kept the opened file descriptions of the old file so the FS cannot reclaim space.

## What had been done

- no log from pica/lib/system_backend_task.cc and pica/lib/frr_backend_task.cc
    - That fixed the root cause

- no compress
    - That is not the root cause, compressing happens as stream totally in RAM, not related to the tmpfs part.
    - Better to add compress back, since compressing log files can save lots of space, while compressing log files won't exhause CPU/ram

- expand /tmp tmpfs to 256MB on x86
    - That can be good to avoid /tmp exhausting, so the change should be kept.

- Use systemd timer to control timely log rotation.
    - logrotate changed from being run by cron to systemd timers, but the timer had never been enabled before.
    - Actually the rotation was done by triggering one run for each line of logging, as in /etc/rsyslog.conf.

## What to do next

- add back compress, reason listed above
- use system journal/syslog utility which will handle logging properly, by running as daemon to deal with logging requests with std levels and tags.
- refine picos rsyslog config, see other issues below
- refine logrotate config, see other issues below

## Other issues: possible other issues?

- We are also trying to detect whether rsyslog/message would make /tmp full, from the same root cause.
- Currently that won't happen, because each line of logging will trigger one restart of syslog daemon.
- Thes restarts consume a lot of system resources.

## Other issues: improper picos rsyslog usage

In /etc/rsyslog.conf

    $outchannel mychannel,/tmp/log/messages,5242880,/pica/bin/logrotate.sh

That means each line of logging will trigger one execution of that sh script.

Look at the content of this
logrotate.sh

    /usr/sbin/logrotate -v /etc/logrotate.conf

That means it will run once logrotate for each logging no matter the size and time interval configured.

Also it will restart once rsyslog daemon.

    systemctl kill -s HUP rsyslog.service

All in all, these steps for each line of logging are to resource exhausting.

We should NOT call logrotate for each line of logging as in /etc/rsyslog.conf.
I guess the line was added to solve log rotating issue. The root cause of logrotate failure to run was its change from being run by cron to systemd timers and the timer had never been enabled before.

## Other issues: better logrotate config

- Add option notifempty
    - That is Not rotating if file is empty, as what would be usually expected

- Add option missingok
    - That is Not creating file is not existing, as what would be usually expected

- use option copytruncate, not create
    - That can avoid the root cause of the full /tmp issue

       create
              Immediately after rotation (before the postrotate script is run) the log file is created (with the same name as the log file just rotated).

       copytruncate
              Truncate the original log file to zero size in place after creating a copy, instead of moving the old log file and optionally creating a new one.  It can be used when some program cannot be told to close its logfile  and
              thus  might  continue writing (appending) to the previous log file forever.  Note that there is a very small time slice between copying the file and truncating it, so some logging data might be lost.  When this option is
              used, the create option will have no effect, as the old log file stays in place.

## Trouble shootings

Force rotate:

    sudo /usr/sbin/logrotate -vf /etc/logrotate.conf

The size of system_commands.log is kept 0, though it is expected to take logs.

We noticed the inode changes before and after the log rotation.

```sh
$ ls -li system_commands.log*
84 -rw-rw-r-- 1 root xorp  0 Dec 27 00:11 system_commands.log
85 -rw-rw-r-- 1 root xorp 20 Dec 27 00:04 system_commands.log.1.gz
```

After the log rotation.

```sh
$ ls -li system_commands.log*
91 -rw-rw-r-- 1 root xorp  0 Dec 27 00:11 system_commands.log
92 -rw-rw-r-- 1 root xorp 20 Dec 27 00:04 system_commands.log.1.gz
```

We also noticed the fact the /tmp is 100% full, but the accumulative size of /tmp is only a couple of KB including the hidden files.
So we can know some files existing there in the FS but not showing in `du` results.

Let's search for missed files.

```sh
admin@CORE01:/tmp/log$ sudo lsof -F sn0 | tr -d '\000' | grep deleted | sed 's/^[a-z]*\([0-9]*\)n/\1 /' | sort -n

f12s51777536n/tmp/log/system_commands.log.2 (deleted)
f12s51777536n/tmp/log/system_commands.log.2 (deleted)
f12s51777536n/tmp/log/system_commands.log.2 (deleted)
f39s167n/tmp/log/frr_commands.log.2 (deleted)
f39s167n/tmp/log/frr_commands.log.2 (deleted)
f63s167n/tmp/log/frr_commands.log.2 (deleted)
f63s167n/tmp/log/frr_commands.log.2 (deleted)
f63s167n/tmp/log/frr_commands.log.2 (deleted)
```

Let's see what processes are holding these deleted files.

```sh
admin@CORE01:/tmp/log$ sudo  lsof | egrep "deleted|COMMAND"
COMMAND       PID  TID TASKCMD     FD    SIZE/OFF       NODE NAME
pica_sif      827                  63u        167         23 /tmp/log/frr_commands.log.2 (deleted)
pica_sif      827                  12u   51777536         35 /tmp/log/system_commands.log.2 (deleted)
pica_sif      827 1072 pica_sif    63u        167         23 /tmp/log/frr_commands.log.2 (deleted)
pica_sif      827 1072 pica_sif    12u   51777536         35 /tmp/log/system_commands.log.2 (deleted)
pica_sif      827 2502 pica_sif    63u        167         23 /tmp/log/frr_commands.log.2 (deleted)
pica_sif      827 2502 pica_sif    12u   51777536         35 /tmp/log/system_commands.log.2 (deleted)

xorp_vrrp     043                  39u        167         23 /tmp/log/frr_commands.log.2 (deleted)
xorp_vrrp     043 2140 xorp_vrrp   39u        167         23 /tmp/log/frr_commands.log.2 (deleted)
```

Unlinked files are removed from FS, and resources are freed for reallocation but deletion must wait until all processes that have opened it finish accessing it.

```sh
admin@CORE01:/tmp/log$ sudo lsof -nP +L1
COMMAND    PID USER   FD   TYPE DEVICE SIZE/OFF NLINK NODE NAME
pica_sif   827 root   63u   REG   0,28      167     0   23 /tmp/log/frr_commands.log.2 (deleted)
pica_sif   827 root   12u   REG   0,28 51777536     0   35 /tmp/log/system_commands.log.2 (deleted)
xorp_vrrp  043 root   39u   REG   0,28      167     0   23 /tmp/log/frr_commands.log.2 (deleted)

admin@CORE01:/tmp/log$ sudo find /proc/*/fd -ls | grep  '(deleted)'
 25069353      0 lrwx------   1 root     root           64 Dec 29 03:35 /proc/043/fd/39 -> /tmp/log/frr_commands.log.2\ (deleted)
 25065680      0 lrwx------   1 root     root           64 Dec 29 03:35 /proc/827/fd/63 -> /tmp/log/frr_commands.log.2\ (deleted)
 25065729      0 lrwx------   1 root     root           64 Dec 29 03:35 /proc/827/fd/12 -> /tmp/log/system_commands.log.2\ (deleted)
```

Processes pica_sif and xorp_vrrp continue to output to the old files but the file won't be accessible from FS.

We can access contents of these files unlinked from FS by FD.

```sh
admin@CORE01:/tmp/log$ sudo tail /proc/827/fd/12
bridge fdb del 22:00:00:01:83:02 dev ae1 vlan 220 master static
bridge fdb del 22:00:00:01:83:04 dev ae1 vlan 220 master static
bridge fdb del 22:00:00:01:83:07 dev ae1 vlan 220 master static
bridge fdb del 22:00:00:01:83:08 dev ae1 vlan 220 master static
bridge fdb append 22:00:00:01:83:0d dev ae1 vlan 220 master static
bridge fdb append 22:00:00:01:83:0e dev ae1 vlan 220 master static
bridge fdb del 22:00:00:01:83:0b dev ae1 vlan 220 master static
bridge fdb del 22:00:00:01:83:0d dev ae1 vlan 220 master static
bridge fdb del 22:00:00:01:83:0e dev ae1 vlan 220 master static
```

The existing files that log contents are expected to output had been changed to new ones.

```sh
admin@CORE01:/tmp/log$ ll -i system_commands.log* frr_commands.log*
67 -rw-rw-r-- 1 root xorp 0 Dec 29 02:54 frr_commands.log
64 -rw-rw-r-- 1 root xorp 0 Dec 29 02:51 frr_commands.log.1

68 -rw-rw-r-- 1 root xorp 0 Dec 29 02:54 system_commands.log
65 -rw-rw-r-- 1 root xorp 0 Dec 29 02:51 system_commands.log.1
```

- The space is physically freed only if there are no links left.

```sh
admin@CORE01:/tmp/log$ df /tmp
Filesystem     1K-blocks    Used Available Use% Mounted on
tmpfs              51200   51200         0 100% /tmp

admin@CORE01:/tmp/log$ ps afux | grep pica_sif
root         827 74.5  2.2 549964 372076 ?       Rl   Dec28 298:08 pica_sif

admin@CORE01:/tmp/log$ sudo kill -HUP $(pidof pica_sif)

admin@CORE01:/tmp/log$ df /tmp
Filesystem     1K-blocks  Used Available Use% Mounted on
tmpfs              51200   652     50548   2% /tmp
```


________________________________________
From: Angela Hung <angela.hung@pica8.com>
Sent: Thursday, December 29, 2022 02:52
To: Iris Rong; Aaron Shang; Tom Jia; Lin Du; Zoneson Chen; Hai Vo-Dinh
Subject: Re: [OPENGLOBE❗Action to take urgently❗] Access layer instability issue at Scientific Police - [Action to take critical issue]

Hi Iris,

Great to know that you can reproduce this in BJ lab. Customer didn’t complain the 4.3.1.5 so far. We must make sure 4.3.1.5 really address this issue. I’m sure BJ will take care of this since this issue is reproducible now. 😊

--Angela
From: Iris Rong <iris.rong@pica8.com>
Date: Tuesday, December 27, 2022 at 11:46 PM
To: Angela Hung <angela.hung@pica8.com>, Aaron Shang <aaron.shang@pica8.com>, Tom Jia <tom.jia@pica8.com>, Lin Du <lin.du@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: 回复: [OPENGLOBE❗Action to take urgently❗] Access layer instability issue at Scientific Police - [Action to take critical issue]
Hi Angela,

We can reproduce /tmp Use% is 100% issue on 4.3.1.3/4059de736c in BJ lab. I load core01/core02/SW2B00 configurations on 7312/7312/4610, when the mlag status is ESTABLISHED I send max arp packets (source-ip different) to mlag port, the both 7312 will learn max mac address and dynamic arp in mac table and arp table, and after about 1 hour I found /tmp is 100%. When I test on 4.3.1.5 this issue cannot reproduce. Aaron is still looking it now.

admin@CORE01:/tmp/log$ sudo du -ah /tmp
0       /tmp/systemd-private-759b1b0c1023484f83ae2db0134c442d-ntp.service-kAv7mi/tmp
0       /tmp/systemd-private-759b1b0c1023484f83ae2db0134c442d-ntp.service-kAv7mi
0       /tmp/systemd-private-759b1b0c1023484f83ae2db0134c442d-systemd-logind.service-mu6uif/tmp
0       /tmp/systemd-private-759b1b0c1023484f83ae2db0134c442d-systemd-logind.service-mu6uif
0       /tmp/.Test-unix
0       /tmp/.font-unix
0       /tmp/.XIM-unix
0       /tmp/.ICE-unix
0       /tmp/.X11-unix
0       /tmp/system/radius_live_servers
0       /tmp/system/lockmgr
4.0K    /tmp/system/radius_enable_accounting
4.0K    /tmp/system/tac_timeout
4.0K    /tmp/system/tac_enable_accounting
4.0K    /tmp/system/tac_enable_authorization
0       /tmp/system/cpuusage
16K     /tmp/system
0       /tmp/snmp
4.0K    /tmp/run/logrotate.status
0       /tmp/run/sif_ready
0       /tmp/run/rtrmgr_ready
0       /tmp/run/lcmgr.xovs
4.0K    /tmp/run/vlan_interfaces
0       /tmp/run/frr_exec.lock
0       /tmp/run/hwmon/pwm
0       /tmp/run/hwmon/fan_present
0       /tmp/run/hwmon/fan_fault
0       /tmp/run/hwmon/fan5
0       /tmp/run/hwmon/fan4
0       /tmp/run/hwmon/fan3
0       /tmp/run/hwmon/fan2
0       /tmp/run/hwmon/fan1
0       /tmp/run/hwmon/fan0
0       /tmp/run/hwmon/temp2
0       /tmp/run/hwmon/temp1
0       /tmp/run/hwmon/temp0
4.0K    /tmp/run/hwmon/fanr_num
4.0K    /tmp/run/hwmon/fan_num
4.0K    /tmp/run/hwmon/flow_dir
12K     /tmp/run/hwmon
20K     /tmp/run
40K     /tmp/log/messages
144K    /tmp/log/messages.1
8.0K    /tmp/log/messages.2.gz
8.0K    /tmp/log/messages.3.gz
8.0K    /tmp/log/messages.4.gz
800K    /tmp/log/system_commands.log.1.gz
0       /tmp/log/system_commands.log
4.0K    /tmp/log/lcmgr_l2msg
8.0K    /tmp/log/rx_packets
484K    /tmp/log/rx_packets.old
8.0K    /tmp/log/frr_commands.log.1.gz
0       /tmp/log/frr_commands.log
12K     /tmp/log/plc_cfg_bcm.soc
0       /tmp/log/lighttpd
1.5M    /tmp/log
1.6M    /tmp
admin@CORE01:/tmp/log$
admin@CORE01:/tmp/log$ df
Filesystem     1K-blocks   Used Available Use% Mounted on
udev             8184728      0   8184728   0% /dev
tmpfs            1637976 152308   1485668  10% /run
/dev/sdb5        1998672 731388   1162428  39% /
tmpfs            8189868      0   8189868   0% /dev/shm
tmpfs               5120      0      5120   0% /run/lock
tmpfs              51200  51200         0 100% /tmp
/dev/sdb7        3265564   5860   3090492   1% /udata

Thanks
Iris







________________________________________
From: Brad Bullington <brad.bullington@pica8.com>
Sent: Tuesday, December 13, 2022 02:23
To: Pica8 All
Subject: CEO ANNOUNCEMENT: Organization Update: Zach Hill, VP Sales

Team,

It is with enthusiasm that I share the most recent addition to the executive team: Zach Hill, Vice President, Sales.

Initially reporting to Zach will be all US Sales (Enterprise and Mid-Market), US SEs, and our to-be-developed Customer Success organization. We plan to significantly expand headcount in these functions across 2023.

Zach comes to Pica8 with more than 20 years of enterprise sales experience. Much of his career has been in go-to-market leadership roles at startup security technology companies, most recently as the CRO of Airgap Networks, and other stops where he built the go-to-market functions at container security company NeuVector (acquired by SUSE), digital security training firm MediaPRO (acquired by KnowBe4), and cyber threat intelligence and investigation platform provider DomainTools.

This intersection of successful growth stage gtm development, and deep experience in selling SaaS products and services into security and networking, are directly applicable to our current and future areas of focus.

On a persona note, when not grinding away on the sales pipeline, Zach enjoys spending time with his family (wife and two boys, 6 & 10) skiing, camping, and doing anything outdoors.  On the rare occasions he finds time alone, he can be found in his shop doing woodworking projects.

Please help me welcome Zach to the team.

Best,
Brad





in case it's useful for you,

系统时间是boot时刻从主版得到的时间然后以epoch计数的，保持不变。
用户接口的时间都是特定timezone的localtime, 所以对于取得给定的以localtime表达的未来时间，
转化为系统时间即可得到距离目前的绝对值。
时间转换应该是根据tzset， 或者getenv得到的TZ, libc转换函数会计入zone的信息，包括夏令时。

还可以参考

https://cplusplus.com/reference/ctime/

https://en.cppreference.com/w/cpp/chrono/duration

https://cplusplus.com/reference/chrono/

https://en.cppreference.com/w/cpp/chrono/time_point








________________________________________
From: Brad Bullington <brad.bullington@pica8.com>
Sent: Thursday, September 8, 2022 04:32
To: Pica8 All
Subject: CEO ANNOUNCEMENT: New Member of Executive Team, Jamie Kuhnhausen, VP of People & Culture

Team,



I am excited to announce the newest member of the executive team, who will be leading People & Culture initiatives for the company, Jamie Kuhnhausen.



Jamie joins us with a deep background in helping to build and scale HR and culture programs for growing companies from seed stage to IPO. She most recently led the global People team at CommerceIQ, and prior to that Ideoclick and Slalom Consulting. Her priorities for the remainder of H2 will include creating programs that bring our culture to life, allow us to hire at scale, and create an employee experience that is unique to Pica8!



Jamie and her husband Quinn are recent "empty nesters". So, when she is not busy building world-class people programs, you can find her and her husband, along with puppy Keanu, traveling, exploring, and discovering new adventure spots.



Please join me in welcoming Jamie to the team.



Best,
Brad






________________________________________
From: Microsoft Outlook <MicrosoftExchange329e71ec88ae4615bbc36ab6ce41109e@pica8com.onmicrosoft.com>
Sent: Thursday, August 11, 2022 15:24
To: Aaron Shang
Subject: Undeliverable: Fw: Re: test workplace aao

[https://products.office.com/en-us/CMSImages/Office365Logo_Orange.png?version=b8d100a9-0a8b-8e6a-88e1-ef488fee0470]
Your message to aaron@ashang.org couldn't be delivered.
aaron wasn't found at ashang.org.
aaron.shang     Office 365      aaron
Action Required                 Recipient
Unknown To address

How to Fix It
The address may be misspelled or may not exist. Try one or more of the following:

  *   Send the message again following these steps: In Outlook, open this non-delivery report (NDR) and choose Send Again from the Report ribbon. In Outlook on the web, select this NDR, then select the link "To send this message again, click here." Then delete and retype the entire recipient address. If prompted with an Auto-Complete List suggestion don't select it. After typing the complete address, click Send.
  *   Contact the recipient (by phone, for example) to check that the address exists and is correct.
  *   The recipient may have set up email forwarding to an incorrect address. Ask them to check that any forwarding they've set up is working correctly.
  *   Clear the recipient Auto-Complete List in Outlook or Outlook on the web by following the steps in this article: Fix email delivery issues for error code 5.1.1 in Office 365<https://go.microsoft.com/fwlink/?LinkId=389363>, and then send the message again. Retype the entire recipient address before selecting Send.

If the problem continues, forward this message to your email admin. If you're an email admin, refer to the More Info for Email Admins section below.

Was this helpful? Send feedback to Microsoft<https://go.microsoft.com/fwlink/?LinkId=525920>.
________________________________

More Info for Email Admins
Status code: 550 5.1.1

This error occurs because the sender sent a message to an email address outside of Office 365, but the address is incorrect or doesn't exist at the destination domain. The error is reported by the recipient domain's email server, but most often it must be fixed by the person who sent the message. If the steps in the How to Fix It section above don't fix the problem, and you're the email admin for the recipient, try one or more of the following:

The email address exists and is correct - Confirm that the recipient address exists, is correct, and is accepting messages.

Synchronize your directories - If you have a hybrid environment and are using directory synchronization make sure the recipient's email address is synced correctly in both Office 365 and in your on-premises directory.

Errant forwarding rule - Check for forwarding rules that aren't behaving as expected. Forwarding can be set up by an admin via mail flow rules or mailbox forwarding address settings, or by the recipient via the Inbox Rules feature.

Mail flow settings and MX records are not correct - Misconfigured mail flow or MX record settings can cause this error. Check your Office 365 mail flow settings to make sure your domain and any mail flow connectors are set up correctly. Also, work with your domain registrar to make sure the MX records for your domain are configured correctly.

For more information and additional tips to fix this issue, see Fix email delivery issues for error code 550 5.1.1 in Office 365<https://go.microsoft.com/fwlink/?LinkId=389363>.

Original Message Details
Created Date:   8/11/2022 7:24:12 AM
Sender Address: aaron.shang@pica8.com
Recipient Address:      aaron@ashang.org
Subject:        Fw: Re: test workplace aao

Error Details
Reported error: 550-5.1.1 The email account that you tried to reach does not exist. Please try 550-5.1.1 double-checking the recipient's email address for typos or 550-5.1.1 unnecessary spaces. Learn more at 550 5.1.1 https://support.google.com/mail/?p=NoSuchUser cd1-20020a170906b34100b007304be795c7si5019153ejb.390 - gsmtp
DSN generated by:       DM6PR12MB4124.namprd12.prod.outlook.com

Message Hops
HOP     TIME (UTC)      FROM    TO      WITH    RELAY TIME
1       8/11/2022
7:24:12 AM      BN7PR12MB2660.namprd12.prod.outlook.com BN7PR12MB2660.namprd12.prod.outlook.com mapi    *
2       8/11/2022
7:24:12 AM      BN7PR12MB2660.namprd12.prod.outlook.com DM6PR12MB4124.namprd12.prod.outlook.com Microsoft SMTP Server (version=TLS1_2, cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384)    *

Original Message Headers

ARC-Seal: i=1; a=rsa-sha256; s=arcselector9901; d=microsoft.com; cv=none;
 b=MQXQCa5zETz38/YvTVVEvvdvqNmRhEQInKi9sHxx0txENygLllDaeE3DrTqQVPz6M7DT5Sw5n6wNgbj4Jpg5UxZIaa5mB3JM68jH+XFLxlkISfGvBIkSKlhpa9t0s64+XOE/qoXZeGnJgrLcXfk0Bq5dJjgtZPd+BxYK0HRHmZXaQBqPFqFvP7F90UTYnJMJz02nOrTdf8EPCHy4jiSIuhucJLJ+bXtCgHZ/DsmR8e/SmnR55LX8dQB23QBVa9Zh5mYODjlQGkkBTGuCMfBdAtg7LdFf6UefbYCiUgxg+RTzqX1vmiEkvB/o8ea5bCSsZxqRQrPspkG2x3LYwhHXlg==
ARC-Message-Signature: i=1; a=rsa-sha256; c=relaxed/relaxed; d=microsoft.com;
 s=arcselector9901;
 h=From:Date:Subject:Message-ID:Content-Type:MIME-Version:X-MS-Exchange-AntiSpam-MessageData-ChunkCount:X-MS-Exchange-AntiSpam-MessageData-0:X-MS-Exchange-AntiSpam-MessageData-1;
 bh=nvC49t9i6599mnGC6g7WMjpGQVpCVJcAHXXCyEBQQwk=;
 b=FCw0A85VQ28bNEEZX2VBZAFKdotApBZNxT6Q5+2yVpZjQz7XToaJlMJmuNYdGzX/+at4bO3N4PwVinjr2A7XUXujaCju4DxTvYpAidRwWh2KzuezH/aLV/U6mWstelawnFfPorn36aPmjTf3ZqPExeLDgiB1SF/eSBZOFcLjPJJeXtSndY/0s4IF0l6tp7HiXt/ocY8f6DLQeRJjR9Psm1Jn19zS6GBYoG3/GwJJ+bTM6nScT/6LN/g8mNalKpWyiEX1XOjKRkuhFYxWCtzi3snual+NxwPMrGP8TXJcyepQLEQjq3JwNvonnHpjW88Esrvo81pnm+pMFEjsjRhIlg==
ARC-Authentication-Results: i=1; mx.microsoft.com 1; spf=pass
 smtp.mailfrom=pica8.com; dmarc=pass action=none header.from=pica8.com;
 dkim=pass header.d=pica8.com; arc=none
DKIM-Signature: v=1; a=rsa-sha256; c=relaxed/relaxed; d=pica8.com;
 s=selector1;
 h=From:Date:Subject:Message-ID:Content-Type:MIME-Version:X-MS-Exchange-SenderADCheck;
 bh=nvC49t9i6599mnGC6g7WMjpGQVpCVJcAHXXCyEBQQwk=;
 b=AEoag+mpdIOahtsEyxJFPbQZN6w2dq1ueF76DPK/Q6NvJvpfcgtXdMeBz1QPUget6m64V+gdQivxUK2lFky26Km97TK8P0Nbxtb/yHPZHkVsSK5flRZxTHgsgVxTo4qMFs430Rlcfp+joPcZX9v2LCpMBxKuP5gtHOh7ko5v5fg=
Received: from BN7PR12MB2660.namprd12.prod.outlook.com (2603:10b6:408:29::26)
 by DM6PR12MB4124.namprd12.prod.outlook.com (2603:10b6:5:221::20) with
 Microsoft SMTP Server (version=TLS1_2,
 cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id 15.20.5525.11; Thu, 11 Aug
 2022 07:24:12 +0000
Received: from BN7PR12MB2660.namprd12.prod.outlook.com
 ([fe80::6945:60ed:b958:6151]) by BN7PR12MB2660.namprd12.prod.outlook.com
 ([fe80::6945:60ed:b958:6151%5]) with mapi id 15.20.5504.021; Thu, 11 Aug 2022
 07:24:12 +0000
From: Aaron Shang <aaron.shang@pica8.com>
To: Aaron Shang <aaron@ashang.org>
Subject: Fw: Re: test workplace aao
Thread-Topic: Re: test workplace aao
Thread-Index: AQHYrVNa7DqRQSQai02bFuc28/XuCg==
Date: Thu, 11 Aug 2022 07:24:12 +0000
Message-ID: <BN7PR12MB2660250FAECE7EFDB4A67F28B8649@BN7PR12MB2660.namprd12.prod.outlook.com>
References: <5D5D0487-D772-43FC-8C7E-7EFF6FCB519F@contoso.com>
 <DS7PR12MB61422CA3FF966AD3D9FA250CC39C9@DS7PR12MB6142.namprd12.prod.outlook.com>
 <MN0PR12MB61505760E117E41A4E0CD367C09C9@MN0PR12MB6150.namprd12.prod.outlook.com>
 <SN6PR12MB26717CC0FE827F1F0CB9DF11B89E9@SN6PR12MB2671.namprd12.prod.outlook.com>
 <BN7PR12MB26604DE1868746BAD5CD6104B8649@BN7PR12MB2660.namprd12.prod.outlook.com>
 <753f61b4-546c-4f9a-967c-43464e181745@DM6PR12MB4124.namprd12.prod.outlook.com>
In-Reply-To: <753f61b4-546c-4f9a-967c-43464e181745@DM6PR12MB4124.namprd12.prod.outlook.com>
Accept-Language: en-US
Content-Language: en-US
X-MS-Has-Attach: yes
X-MS-TNEF-Correlator:
msip_labels:
authentication-results: dkim=none (message not signed)
 header.d=none;dmarc=none action=none header.from=pica8.com;
x-ms-publictraffictype: Email
x-ms-office365-filtering-correlation-id: eaea6def-5887-4cb4-dbf9-08da7b6a7d46
x-ms-traffictypediagnostic: DM6PR12MB4124:EE_
x-ms-exchange-senderadcheck: 1
x-ms-exchange-antispam-relay: 0
x-microsoft-antispam: BCL:0;
x-microsoft-antispam-message-info: C/Ql3E6atSkmY66pzf+6HdR9ebLsjUk4h6vOrh76Dr9utEgKlrA0hyDmvA6uPq4IinSVhkadKAeWEI4NFhvp7TMqH5X32Y9iLOlH1nmmTKkHcZoV89sKdOVOI/oYjXBPuQ2c8piWr+rbbKoyOW0J0iQOf3IIjoj0gga+8ic1oML0Q6zdMrSW92OQKazhdo6n3cmbFAcOprpOeWvZBfhEBlGJkVXivtbRex0CfFUZuMMeW5MNXQVrbnL7JGT7rGsjxdFt1Xy+KcWybsgGNeVAAr5yv6ea35lWkP/JG02QED5vhnIZg6Dy338+8bfjHaIvfqpge1919m80pxQk9UYNA2K9hAl0gDxl84Cja3LLcSOrbGLGXn0YomPfOWysL9WtxIavJQo0UDMj8DqL86OH1R/ZT6NAuEYIhzpf1Yd6uNbaseIGeI+JSW7sc24qgqZPcI6M2BWyhly9i7P2hSa4/Z2pnGNFKlT7+Nf6HaEXON6iN5WEFj6hK9hemkRu56E0R0ujk25wdTQ7M2FYx92cWfo3AXIryPH0br9YuTuLVzh0U9fmJbYwLDxr+hWmkOZ3sYG8F/dsDCQmdzBPZZB1YQVBm+SNCmul82XsEySd7AdoWNhUkibRy/iSOk1oAOJ3OpugpmMbADrKEeEeBe+8rVfXNZwDIvRvWoPuSwvwYKHQbIcTvOaOhC+0omAv4jNbOMEO6u3aOCc6L45SlJ04XH5f2EnnKecux4uuoeJYHkIKcTqkYwNobH3oQfTNhJdEM8JoXQX6LkB/mz9LJ2ukat+sVpPgCkw2l1YbjQKi0cBi9z+8KREDTNO+Wi+TueihLFuM0Ihbi1MYarkaDtbxaycQPDFQixptLSEm9MLQtLA=
x-forefront-antispam-report: CIP:255.255.255.255;CTRY:;LANG:en;SCL:1;SRV:;IPV:NLI;SFV:NSPM;H:BN7PR12MB2660.namprd12.prod.outlook.com;PTR:;CAT:NONE;SFS:(13230016)(346002)(376002)(396003)(39830400003)(136003)(366004)(6916009)(71200400001)(41300700001)(9686003)(26005)(186003)(45080400002)(30864003)(2906002)(33656002)(66556008)(66476007)(122000001)(99936003)(8676002)(64756008)(66446008)(66946007)(44832011)(91956017)(38100700002)(316002)(86362001)(19627235002)(966005)(6506007)(53546011)(7696005)(52230400001)(478600001)(83380400001)(8936002)(5660300002)(55016003)(52536014)(38070700005)(76116006)(586874003);DIR:OUT;SFP:1102;
x-ms-exchange-antispam-messagedata-chunkcount: 1
x-ms-exchange-antispam-messagedata-0: =?iso-8859-1?Q?i11SzfUWPSGnsqwWxo3kYdV41ssaobs7nHKgnXyGTCcKjjIkpQ42C+iaGf?=
 =?iso-8859-1?Q?kzMZT6k5JJJLcvBug77hINDPioLofUJRkZhT5VyGyW3MXqm6xdR+doTPY9?=
 =?iso-8859-1?Q?gCRSrBMHU+WSubaNYrl6Ju8fvrO8wdjvQUGp7gnpxTemH5WA91LZ5bU8LP?=
 =?iso-8859-1?Q?VO2HfeAI3kJq3UQhlxWJ9ssdIRuPKPHTrLU7P/NL853WE+RXmI3FFS1Zo6?=
 =?iso-8859-1?Q?oRtPCbPwgVW40ol5lQabkYQDumnTngZ1SmFeWrA7Z8n80oBOgJ5QubqgAh?=
 =?iso-8859-1?Q?Ljk9+Dc2O84mU/sNiFJb68siJM3Jr8ycHW19StiYyC9WvhF9RzPkJR+j+N?=
 =?iso-8859-1?Q?IkX94S7KNacRAwxdGdSXMoF/MLtjZLqgMFsVIdoAdJaaKwoZtna2j7sXH6?=
 =?iso-8859-1?Q?yDK/T4yVqDwMowOqiR2vMTeQqyhoYfYVsAWAXUVTXAKh9dQTzwt2QZjriY?=
 =?iso-8859-1?Q?q34V9SvqRbh/FNcX4oKThX8zIdJQqwwm/pLk5sFf9naPFAOmqLFiOv7rNg?=
 =?iso-8859-1?Q?ZX+GLnY7TuPLwcgQEfEFXaSK32SieXDJwHCiIHToss0Jr765aQgRIJAuEJ?=
 =?iso-8859-1?Q?GSNyPJqIrpBfTazsTpyYf6/tLSu+j2RD/YGBBojVBC6LGwA+VmPTQxuH1h?=
 =?iso-8859-1?Q?MENjOv8p835oD7vRtNR41wc9sNcPqrQBu3P4iwQiwsCQREmYXz+8vR3/iq?=
 =?iso-8859-1?Q?ZTE9ph/XG5c0q4aduV5mLlEvlhWtABqTcvlnJEKjfGDu8gCGvQjllqbPbF?=
 =?iso-8859-1?Q?NzlcaAbuX7ffuVy8dY63ozeYSPSKxmKmU/wqB4AcmFfWkg/qy3UEhvf+sY?=
 =?iso-8859-1?Q?kKwswVDAXixcdCxMqcmWaTsOXHYd+Vde2B45aaU6UcjA19SaOIpwxBjr/2?=
 =?iso-8859-1?Q?nR0qebREcbP9FVaxcV9QgYafTg/1Hjlrc0GRDJQpKN0HJ8uWwdZPFr1L7O?=
 =?iso-8859-1?Q?6Gpl+ejWSZQcoHnKHaCa2G3gG4lTCZPRQT+q5bVcE6GwG3G2f2xxjl0HFt?=
 =?iso-8859-1?Q?B1qFrqafEoL/60baHwmazDSCYXVjdmJYHzcuTgMqs0LhC7R1IhCR7Lg1Na?=
 =?iso-8859-1?Q?XAyvut7xvqBPS05PMDCO0qQYMsc5PR09w9+f9iHc05+V3VomL7Sdr5OVxY?=
 =?iso-8859-1?Q?xu6/HMCkaOv9oBCUBBZuHWi+y/qzPwZTtaBBBLgftS7vGKEQ7/1eA2c+Ly?=
 =?iso-8859-1?Q?ceGenkTOrrAGtWBSu/w3NVn8W6nlHapTEb//Ilq3JLB9nZSkFSezMKpPJX?=
 =?iso-8859-1?Q?r9pWA/RUway6GY75L7+C0dzkKnsmgBRM583/Zbv3XMHJIsOKevucpVQP6K?=
 =?iso-8859-1?Q?o3FrYYLH3sGEOr62RQL5q7xFM6eXQ2rfXKPIGLFO+uGnPAw3On1nAVp7mO?=
 =?iso-8859-1?Q?HdKcOa/uFL7NOcSSi88aQDXDnTCCPPSJC4EV5P6HF5u+jZMexsRV8jetnw?=
 =?iso-8859-1?Q?2Io4LaqcyRnbqhaggnnoQHYeGbaTEROSvbkZVjRVWZK916l2cg0mdz1Vy6?=
 =?iso-8859-1?Q?nRKhVZNmbRZteq/geD6aFjkU92kh6/K80OuXj/eHNZhZFiop//W/bUewwN?=
 =?iso-8859-1?Q?KbrZ0q/VmdKbKFdNcU/9zePhGtJCNV1ZlBS08OsDIz3XIPw6KKDQmjSuKF?=
 =?iso-8859-1?Q?epFxqUsbsVw9ROGxivoJ2A/vq3TOp+Zaiq?=
Content-Type: multipart/mixed;
        boundary="_002_BN7PR12MB2660250FAECE7EFDB4A67F28B8649BN7PR12MB2660namp_"
MIME-Version: 1.0
X-OriginatorOrg: pica8.com
X-MS-Exchange-CrossTenant-AuthAs: Internal
X-MS-Exchange-CrossTenant-AuthSource: BN7PR12MB2660.namprd12.prod.outlook.com
X-MS-Exchange-CrossTenant-Network-Message-Id: eaea6def-5887-4cb4-dbf9-08da7b6a7d46
X-MS-Exchange-CrossTenant-originalarrivaltime: 11 Aug 2022 07:24:12.4579
 (UTC)
X-MS-Exchange-CrossTenant-fromentityheader: Hosted
X-MS-Exchange-CrossTenant-id: 1649697f-e494-4b71-8227-3f383d0979ad
X-MS-Exchange-CrossTenant-mailboxtype: HOSTED
X-MS-Exchange-CrossTenant-userprincipalname: HkMq3qPsHbpf5bQqbU62Rrqjtmd0K5inoUWICvL0tp0fKpjn1OOHIVfoW3AO2e4STWijw3ypoCE7i2mGQJW57A==
X-MS-Exchange-Transport-CrossTenantHeadersStamped: DM6PR12MB4124








________________________________________
From: Brad Bullington <brad.bullington@pica8.com>
Sent: Wednesday, August 3, 2022 08:58
To: Pica8 All
Subject: CEO ANNOUNCEMENT: BEN MOORE, NEW VP of PLM

Team,

As referenced in recent town halls, I’m excited to announce the newest member of the executive team, who will be heading PLM for the company, Ben Moore.

Ben joins us from AWS, where over seven years, he led product, business development, and Go-To-Market efforts of cloud services in areas covering IoT, CX, AR / VR, and data center.

Ben will own product, product management, and product and technical marketing across all of Pica8’s current and future offerings. Prior to AWS, Ben held a series of product and GTM-focused roles in the machine-to-machine (M2M) powered wireless infrastructure space.

Reporting to Ben will be Hai and Mani. To allow ramp focus, given our aggressive focus on incubating and launching our cloud service capabilities, Hai and Mani will continue to report to James for 30 days before transitioning to Ben.

When not building world-class cloud services and teams, you’ll find Ben battling the trout populations of the Pacific Northwest with his fly fishing rod or camping with his family with a glass of great northwest wine in hand.

Please join me in welcoming Ben to the team.









---------- 转发的邮件 ----------
发件人：Ferry Fan <ferry.fan@pica8.com>
日期：2022年7月19日 14:24
主题：Re: 回复： Can you help me add docker permissions on 10.10.50.20?
收件人：Aaron Shang <aaron.shang@pica8.com>
抄送：

I often used is paramiko, ncclient, pygnmi, thanks.


ferry.fan@pica8.com

发件人： Aaron Shang
发送时间： 2022-07-19 11:50
收件人： Ferry Fan
主题： 回复： Can you help me add docker permissions on 10.10.50.20?
perhaps i can install these popular modules via pip globally on all hosts, or you can suggest often used packages/ modules
发件人：Ferry Fan <ferry.fan@pica8.com>
日期：2022年7月19日 09:38
主题：Can you help me add docker permissions on 10.10.50.20?
收件人：Aaron Shang <aaron.shang@pica8.com>

I need to run python scripts for a long time on 10.10.50.20, but I have some modules that need to be downloaded, so I want to use docker to do it.


ferry.fan@pica8.com






Mark of submodules

Hi,

In builds after May, you can check the marks of submodules in the running OS:

admin@D-LinkOS:~$ cat /.system.lock
BUILD:           1685656869
FRR:             0a577fff89
LINUX:           7acb64ea1f


Here, FRR/LINUX gave the 10 bytes of SHA1 of their repo, BUILD is the time stamp of picos building.
$ date -d @"1685656869"
Fri 02 Jun 2023 06:01:09 AM CST


The SHA1 of picos release and also the build variant can be seen from version checking:

Linux System Version/Revision: 4.4.0.1/dec0be5c01-dlink


If needed, we can add the marks into the showing of version too:


admin@D-LinkOS:~$ version
Copyright (C) 2009-2023 D-Link (India) Ltd.
===================================
Hardware Model                : AS7712_32X
Linux System Version/Revision : 4.4.0.1/dec0be5c01-dlink
Linux System Released Date    : 06/01/2023
L2/L3 Version/Revision        : 4.4.0.1/dec0be5c01-dlink
L2/L3 Released Date           : 06/01/2023
OVS/OF Version/Revision       : 4.4.0.1/dec0be5c01-dlink
OVS/OF Released Date          : 06/01/2023


If you would like a better naming or location of contents of them, please tell Tom.






Hi, James,

I agree with you. I will look into any means for that. We had also noticed the same output from cumulus instances.

________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Friday, February 25, 2022 11:55
To: Aaron Shang; Tom Jia; Zoneson Chen; Vic Lan
Cc: TAC
Subject: Re: <Tom help>FW: Issues in Ampcon 1.5.1

For SMB, these "warnings" might be ignored. However, for enterprises, they ALWAYS pay attention to these details. Is there a way we add a "dumb driver" to catch these interrupts?

We should have a QA process to review all booting logs before we release a new platform.

On 2/24/22, 6:58 PM, "Aaron Shang" <aaron.shang@pica8.com> wrote:



    These NMI messages are normal and reasonable, the lines showed that NMI was received but the kernel didn't have a registered processor to deal with it.

    NMI (Non-Maskable Interrupts) are interrupts that cannot be turned off and ignored. They are always used for something really, really important.

    In the past, we had efforts to hack the kernel just for squashing them, only finding that we cannot entirely cover that.


    BTW, I think these kinds of output should be avoided:

            app[line:230] cannot concatenate 'str' and 'NoneType' objects

    ________________________________________
    From: Tom Jia <tom.jia@pica8.com>
    Sent: Friday, February 25, 2022 08:42
    To: Zoneson Chen; Aaron Shang; Vic Lan
    Cc: TAC
    Subject: Re: <Tom help>FW: Issues in Ampcon 1.5.1

    Aaron, Vic,

    Would you please take a look?

    I think the output of "dmesg" would be helpful to understand the context if it is available.

    Thanks.

    ________________________________
    Best regards,
    Tom Jia (贾彦民)


    ________________________________
    From: Zoneson Chen <zoneson.chen@pica8.com>
    Sent: Friday, February 25, 2022 4:57 AM
    To: Tom Jia <tom.jia@pica8.com>
    Cc: TAC <tac@pica8.com>
    Subject: <Tom help>FW: Issues in Ampcon 1.5.1


    Tom,



    Would you mind checking which initialization functions report the following messages in Danny’s mail? The hardware model is AS4630 and PICOS is 4.2.1. What do they complain?



      Booting `PICOS-4.2.1'



    Loading, please wait...

    [   13.628099] Uhhuh. NMI received for unknown reason 3d on CPU 0.

    [   13.628100] Do you have a strange power saving mode enabled?

    [   13.628101] Dazed and confused, but trying to continue

    [   15.750601] Uhhuh. NMI received for unknown reason 2d on CPU 0.

    [   15.750602] Do you have a strange power saving mode enabled?

    [   15.750603] Dazed and confused, but trying to continue

    [   17.702173] picos-pre.sh[433]: Auto Provisioning Tool - checking updates ....

    [   17.838019] picos-pre.sh[433]: Tftp Server found: 10.10.224.16

    [   17.848099] picos-pre.sh[433]: Script file name found: boot\\x64\\wdsnbp.com



    Thanks,



    Zoneson

    From: James Liao <james.liao@pica8.com>
    Date: Thursday, February 24, 2022 at 12:00 PM
    To: Danny Tsai <Danny.Tsai@ablspacesystems.com>, Lance Gallardo <lance.gallardo@pica8.com>, Neal Trieber <neal.trieber@pica8.com>, support@pica8.com <support@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
    Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>, Yachal Chen <yachal.chen@pica8.com>
    Subject: Re: Issues in Ampcon 1.5.1

    Danny,



    Thank you for bringing this to our attention.



    Issue #1 – our support team will look into this and get back to you with an explanation in two days.

    Issue #2 – we will add a verification logic in AmpCon to automatically correct the clock issue in AmpCon 1.6.0.

    Issue #3 – we will add a configuration option in AmpCon to allow users to change the VPN range in AmpCon 1.6.0.

    Issue #4 – EVPN multi-homing (type 1 and 4) are in our roadmap for Q3/Q4. Before EVPN multi-homing is available, we suggest users to use MLAG+EVPN on TOR. Our SE team can work with you on the detailed design.



    Thanks again for providing us these valuable inputs. Please feel free to let me know if we can help more.



    Thanks,

    James



    James Liao

    CTO and Co-founder

    (650) 575-3665



    From: Danny Tsai <Danny.Tsai@ablspacesystems.com>
    Date: Thursday, February 24, 2022 at 2:24 AM
    To: Lance Gallardo <lance.gallardo@pica8.com>, Neal Trieber <neal.trieber@pica8.com>, "support@pica8.com" <support@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
    Subject: RE: Broken Import Switch Process - Ampcon 1.5.1



    4 Issues Brought up in the Process of Onboarding switches to AMPCON  that is an issue for me:    Would the support team be able to help?



      1.  Minor: Strange startup message on EdgeCore AS4630-54PE in the beginning, it appears to be cosmetic. But I am not sure…  it is strange.   Why does it show this?

      Booting `PICOS-4.2.1'



    Loading, please wait...

    [   13.628099] Uhhuh. NMI received for unknown reason 3d on CPU 0.

    [   13.628100] Do you have a strange power saving mode enabled?

    [   13.628101] Dazed and confused, but trying to continue

    [   15.750601] Uhhuh. NMI received for unknown reason 2d on CPU 0.

    [   15.750602] Do you have a strange power saving mode enabled?

    [   15.750603] Dazed and confused, but trying to continue

    [   17.702173] picos-pre.sh[433]: Auto Provisioning Tool - checking updates ....

    [   17.838019] picos-pre.sh[433]: Tftp Server found: 10.10.224.16

    [   17.848099] picos-pre.sh[433]: Script file name found: boot\\x64\\wdsnbp.com



      1.  Major:   When attempting to IMPORT switch brand new out of the box for EdgeCore AS4630-54PE switch, only management interface is connected to network via DHCP and has connectivity to AmpCon + Internet.  Unable to IMPORT successfully due to VPN tunnel problem.      This was FIXED by manually setting clock OR adding NTP configuration.   Is there a way to perform this on the script startup process BEFORE starting OVPN daemon?

    ==> messages <==

    Feb 23 2022 23:15:43 Xorplus ovpn-client daemon.err : TLS Error: TLS key negotiation failed to occur within 60 seconds (check your network connectivity)

    Feb 23 2022 23:15:43 Xorplus ovpn-client daemon.err : TLS Error: TLS handshake failed

    Feb 23 2022 23:16:13 Xorplus  user.warning : [Auto-deploy]Download failed: [Errno socket error] [Errno 110] Connection timed out

    Feb 23 2022 23:16:23 Xorplus  user.warning : [Auto-deploy]Try to enable VPN

    Feb 23 2022 23:16:23 Xorplus  user.warning : [Auto-deploy]

    Download URL: https://10.201.6.25:443/management/vpn/463054PE2105026/client.conf

    Feb 23 2022 23:18:23 Xorplus ovpn-client daemon.warning : WARNING: No server certificate verification method has been enabled.  See http://openvpn.net/howto.html#mitm for more info.

    Feb 23 2022 23:18:23 Xorplus ovpn-client daemon.warning : NOTE: the current --script-security setting may allow this configuration to call user-defined scripts

    Feb 23 2022 23:18:32 Xorplus  user.warning : [Auto-deploy]Download failed: [Errno socket error] [Errno 110] Connection timed out

    Feb 23 2022 23:18:42 Xorplus  user.warning : [Auto-deploy]Try to enable VPN

    Feb 23 2022 23:18:42 Xorplus  user.warning : [Auto-deploy]

    Download URL: https://10.201.6.25:443/management/vpn/463054PE2105026/client.conf

    Feb 23 2022 23:19:23 Xorplus ovpn-client daemon.err : TLS Error: TLS key negotiation failed to occur within 60 seconds (check your network connectivity)

    Feb 23 2022 23:19:23 Xorplus ovpn-client daemon.err : TLS Error: TLS handshake failed

    Feb 23 2022 23:20:51 Xorplus  user.warning : [Auto-deploy]Download failed: [Errno socket error] [Errno 110] Connection timed out



      1.  Major Issue:   The OVPN tunnel from SWITCH to AMPCON uses network 10.8.0.0 /20.   I actually HAVE this network in production IN-USE.  Is there a way I can select this network myself instead of AMPCON using this private IP space?  I cannot communicate to a remote branch site with 10.8.0.0/22 range with AMPCON.   It is overlapping with  my production network.   Can this be fixed by allowing manual networks for OVPN tunnel creation to switches?

    [root@crp-laxpramp01 automation]# ifconfig

    ens160: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500

            inet 10.225.6.25  netmask 255.255.255.0  broadcast 10.225.6.255

            inet6 fe80::f31d:c711:3886:3640  prefixlen 64  scopeid 0x20<link>

            ether 00:50:56:8d:64:3c  txqueuelen 1000  (Ethernet)

            RX packets 2329701  bytes 698250744 (665.9 MiB)

            RX errors 0  dropped 430768  overruns 0  frame 0

            TX packets 83444  bytes 402207960 (383.5 MiB)

            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0



    lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536

            inet 127.0.0.1  netmask 255.0.0.0

            inet6 ::1  prefixlen 128  scopeid 0x10<host>

            loop  txqueuelen 1000  (Local Loopback)

            RX packets 3507980  bytes 1054976451 (1006.1 MiB)

            RX errors 0  dropped 0  overruns 0  frame 0

            TX packets 3507980  bytes 1054976451 (1006.1 MiB)

            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0



    tun0: flags=4305<UP,POINTOPOINT,RUNNING,NOARP,MULTICAST>  mtu 1500

            inet 10.8.0.1  netmask 255.255.255.255  destination 10.8.0.2

            inet6 fe80::c349:3596:7755:3bd6  prefixlen 64  scopeid 0x20<link>

            unspec 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  txqueuelen 100  (UNSPEC)

            RX packets 2187  bytes 661496 (645.9 KiB)

            RX errors 0  dropped 0  overruns 0  frame 0

            TX packets 759  bytes 71362 (69.6 KiB)

            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0



    [root@crp-laxpramp01 automation]# netstat -nr

    Kernel IP routing table

    Destination     Gateway         Genmask         Flags   MSS Window  irtt Iface

    0.0.0.0         10.225.6.1      0.0.0.0         UG        0 0          0 ens160

    10.8.0.0        10.8.0.2        255.255.240.0   UG        0 0          0 tun0

    10.8.0.2        0.0.0.0         255.255.255.255 UH        0 0          0 tun0

    10.225.6.0      0.0.0.0         255.255.255.0   U         0 0          0 ens160

    [root@crp-laxpramp01 automation]#



      1.  VXLAN ESI EVPN route type-4 generated in BGP for loop prevention in active/active multihoming environment.

    How does PICA8 address this issue?   I currently have a Juniper QFX environment with EVPN BGP control-plane for VXLAN learning and for LACP multihomed devices, it is able to create an ESI route-type 4 to avoid loops.      What is the best way to mitigate this issue when dual homing to non-VXLAN L2 switch southbound?  As described in this document: https://blogs.cisco.com/datacenter/detecting-and-mitigating-loops-in-vxlan-networks   -- Cisco has virtual-vPC and OAM methods, Juniper has the ability to generate ESI type-4 and Ethernet OAM as well.   Arista has the solution of using MC-LAG.    How does PICA8 address this loop issue, I am unable to find any documents where an designated forwarder is elected for an active/active multi-homing setup in VXLAN topology.



    Thank you for addressing each of my concerns and issues.



    Danny Tsai
    ABL Space Systems
    Network Architect
    C: (310)648-4046
    225 Oregon St
    El Segundo, CA 90245









    From: Danny Tsai
    Sent: Tuesday, February 22, 2022 6:13 PM
    To: Lance Gallardo <lance.gallardo@pica8.com>; Neal Trieber <neal.trieber@pica8.com>; support@pica8.com
    Subject: RE: Broken Import Switch Process - Ampcon 1.5.1



    Lance, Neal, and Zoneson --- License pool association issue with AMPCON is fixed!    Thank you very much for resolving the problem with AMPCON connecting to license portal.

    All user accounts work properly.   I’ve tested danny_tsai and also abl_space.   Both is working successfully.



    Danny Tsai
    ABL Space Systems
    Network Architect
    C: (310)648-4046
    225 Oregon St
    El Segundo, CA 90245







    From: Danny Tsai
    Sent: Tuesday, February 22, 2022 3:02 PM
    To: Lance Gallardo <lance.gallardo@pica8.com<mailto:lance.gallardo@pica8.com>>; Neal Trieber <neal.trieber@pica8.com<mailto:neal.trieber@pica8.com>>; support@pica8.com<mailto:support@pica8.com>
    Subject: Broken Import Switch Process - Ampcon 1.5.1



    Attaching automation.log data text file



    Credentials are valid – checked and correct.

    Please see python error in the log file.



    Please advise on how to resolve. Thanks.



    Danny Tsai
    ABL Space Systems
    Network Architect
    C: (310)648-4046
    225 Oregon St
    El Segundo, CA 90245





    2022-02-22 14:48:05,949 ERROR 679 140022504793920 utils[line:148] dtadmin import vpn switch ip:10.201.2.75 status:[error]

    2022-02-22 14:48:05,959 ERROR 679 140022504793920 wsgi[line:374] 500 GET /rma/manual/vpn/import/10.201.2.75 (10.201.2.65) 2382.78ms

    2022-02-22 14:48:39,129 ERROR 679 140022504793920 utils[line:319] error in update db license count cannot concatenate 'str' and 'NoneType' objects

    TypeError: cannot concatenate 'str' and 'NoneType' objects

    2022-02-22 14:49:24,843 ERROR 679 140022504793920 app[line:230] cannot concatenate 'str' and 'NoneType' objects

    TypeError: cannot concatenate 'str' and 'NoneType' objects

    2022-02-22 14:49:24,844 ERROR 679 140022504793920 wsgi[line:374] 500 GET /rma/manual/vpn/import/10.201.2.75 (10.201.2.65) 2356.79ms

    2022-02-22 14:53:19,899 ERROR 679 140022504793920 app[line:230] cannot concatenate 'str' and 'NoneType' objects

    TypeError: cannot concatenate 'str' and 'NoneType' objects

    2022-02-22 14:53:19,903 ERROR 679 140022504793920 wsgi[line:374] 500 GET /rma/manual/vpn/import/10.201.2.75 (10.201.2.65) 2872.04ms






----



I had used to load vmdk files into my VirtualBox, then export them as ova files for standard virtual disk usages elsewhere.

Although this means is heavy, it works well for me. And it has also command line tool for this kind job.

________________________________________
From: Lisa Pi <lisa.pi@pica8.com>
Sent: Wednesday, March 30, 2022 13:17
To: Mani Subramanian
Cc: Lisa Pi; Yachal Chen; Lin Du; Tim Yi; Aaron Shang; Tom Jia; James Liao
Subject: Re: Re: Converting PicOS-V image from qcow2 to off format

Hi, Mani

1:  I can not access the ESXi server 6.5 via browser sucessfully.
The ESXi server are 5.5 and 6.0 on BJ lab, we don't have ESXi 6.5.
If I create a new va with 5 network cards as before, you still encounter the problem of cards mapping error.

2: Can you ask Yachal for help or create a new VM and and then generating a ova on your ESXi server?

Run for VM ESXI:
       Need an additional convert using “vmkfstools” in ESXI server:
vmkfstools -i picos-v.vmdk -d thin out-picos-v.vmdk
       Create a new virtual machine and select out-picos-v.vmdk as the existing disk



[cid:_Foxmail.1@a6d41e7b-d3f6-f001-5367-a924c0dbb82e]

Thanks
________________________________
Lisa.Pi@pica8.com

From: Mani Subramanian<mailto:mani.subramanian@pica8.com>
Date: 2022-03-30 11:24
To: Lisa Pi<mailto:lisa.pi@pica8.com>
CC: Yachal Chen<mailto:yachal.chen@pica8.com>; Lin Du<mailto:lin.du@pica8.com>; Tim Yi<mailto:tim.yi@pica8.com>; Aaron Shang<mailto:aaron.shang@pica8.com>; Tom Jia<mailto:tom.jia@pica8.com>; James Liao<mailto:james.liao@pica8.com>
Subject: Re: Converting PicOS-V image from qcow2 to off format

URL: https://172.16.0.222/

In the above URL you can see an imported OVA VM with string  “231” in name. If you edit settings to add ports, it will now allow.

Mani

From: Mani Subramanian <mani.subramanian@pica8.com>
Date: Tuesday, March 29, 2022 at 8:18 PM
To: Lisa Pi <lisa.pi@pica8.com>
Cc: Yachal Chen <yachal.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Tim Yi <tim.yi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>, Tom Jia <tom.jia@pica8.com>, James Liao <james.liao@pica8.com>
Subject: Re: Converting PicOS-V image from qcow2 to off format

Hi Lisa,

I access the ESXi server 6.5 via browser with URL URL: https://172.16.0.222/

After you create an OVA, OVA can only be imported. It does not allow me add any ports.

Yachal suggested you use my setup to create an image.

Last image you gave works perfectly with OOB port eth0. In addition to that if you add four ports (for data), it will help me.

Currently I’m stuck. Please consult Yachal or team there and come up with an OVA with one OOB port 4 data ports.

Provide me the image before end of your day today.

Thanks,
Mani
From: Lisa Pi <lisa.pi@pica8.com>
Date: Tuesday, March 29, 2022 at 6:16 PM
To: Mani Subramanian <mani.subramanian@pica8.com>
Cc: Lisa Pi <lisa.pi@pica8.com>, Yachal Chen <yachal.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Tim Yi <tim.yi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>, Tom Jia <tom.jia@pica8.com>
Subject: Re: Re: Converting PicOS-V image from qcow2 to off format

Hi,Mani

I don't know what kind of software you use.
I used vSphere 6.0, it can modify the VM settings and then adding new network adapters for the VM.
[cid:_Foxmail.1@907807cd-5231-d403-4b08-f6063062ad6e]


Thanks
________________________________
Lisa.Pi@pica8.com

From: Mani Subramanian<mailto:mani.subramanian@pica8.com>
Date: 2022-03-30 03:06
To: Lisa Pi<mailto:lisa.pi@pica8.com>
CC: Yachal Chen<mailto:yachal.chen@pica8.com>; Lin Du<mailto:lin.du@pica8.com>; Tim Yi<mailto:tim.yi@pica8.com>; Aaron Shang<mailto:aaron.shang@pica8.com>; Tom Jia<mailto:tom.jia@pica8.com>
Subject: Re: Converting PicOS-V image from qcow2 to off format
Hi Lisa,

If OVA is built with only one port, OVA does not allow the user to add ports after OVA is imported.

I talked with Yachal on how to resolve this issue. Yachal suggests you use my ESXi server to create the OVA image.

I will provide you credentials. Here is access info:

URL: https://172.16.0.222/
User ID: root
Password: pica8pa

I suggest you create an OVA image using 5 ports – One for OOB, and 4 ports for Data.
For OOB you can select 192.168.42.0 network. Data ports SDN-LAB-XXX (Kingfisher, Albatross, Pelican and Ostrich)

I’m also attaching SE Lab VPN (Leon is familiar with it in case you need any info).

Please create an OVA  image and provide it to me before end of your Wednesday using the ESXI server in PA as BJ server is not suitable to create right image.

Thanks,
Mani

From: Lisa Pi <lisa.pi@pica8.com>
Date: Monday, March 28, 2022 at 8:27 PM
To: Mani Subramanian <mani.subramanian@pica8.com>
Cc: Lisa Pi <lisa.pi@pica8.com>, Yachal Chen <yachal.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Tim Yi <tim.yi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Subject: Re: Re: Converting PicOS-V image from qcow2 to off format

Hi, Mani

My environment is not multi network card, so I can't see your problem.
I don't know whether this is the behavior of the server system.

I have an idea: By default, the ova has one VM network card for eth0.
When the customers need more data ports to data network, they need add the network card by themself.
Do you think it's ok?

I create a new ova, it has only one network card.
lpi@dev22:/tftp/picos-v/images$
lpi@dev22:/tftp/picos-v/images$ ls -lt
total 3093812
-rwxrwxrwx 1 lpi    lpi    271535616 Mar 29 11:22 picos-4.2.1-019ad0ef74-x86v.ova


Thanks
________________________________
Lisa.Pi@pica8.com

From: Mani Subramanian<mailto:mani.subramanian@pica8.com>
Date: 2022-03-29 02:52
To: Lisa Pi<mailto:lisa.pi@pica8.com>
CC: Yachal Chen<mailto:yachal.chen@pica8.com>; Lin Du<mailto:lin.du@pica8.com>; Tim Yi<mailto:tim.yi@pica8.com>; Aaron Shang<mailto:aaron.shang@pica8.com>
Subject: Re: Converting PicOS-V image from qcow2 to off format
Hi Lisa,

Thanks for working on this and delivering the image.

Image has one problem.

Here is the summary.

I imported OVA file after setting the NIC interfaces for VM. I mapped OOB eth0 to SE network and data ports to data network. After installation OOB interface did not work. Reason: eth0 is mapped to Network Adapter 2, 3, 4, and 5 instead of 1.

[Graphical user interface, application, table Description automatically generated]

I changed the Network adapter setting to the following. It works but mapping of ports is not correct. OOB port is mapped to data ports and data port is mapped to OOB port.




[Graphical user interface, application, table Description automatically generated]

This needs to be corrected. Users will always select the first port for OOB and next N ports for data.

Originally, I selected the following:
SE network for OOB NIC and 1G links I selected data network. It did not work.
I need to re-configure IG NIC cards to SE network and OOB NIC to data network. This works, but not correct mapping.

Please correct this issue and provide me a new image.

Thanks,
Mani

From: Lisa Pi <lisa.pi@pica8.com>
Date: Monday, March 28, 2022 at 3:00 AM
To: Mani Subramanian <mani.subramanian@pica8.com>
Cc: Lisa Pi <lisa.pi@pica8.com>, Yachal Chen <yachal.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Tim Yi <tim.yi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Subject: Re: Re: Converting PicOS-V image from qcow2 to off format

Hi,  Mani

1: Tim helps me to find the issue. I have create a new ova of picos-v.
lpi@dev22:/tftp/picos-v/images$ ls -lt
total 3093700
-rwxrwxrwx 1 lpi    lpi    271417856 Mar 28 17:58 picos-4.2.1-019ad0ef74-x86v.ova
-rwxr-xr-x 1 tim.yi tim.yi       910 Feb  9 11:24 convert.sh
-rw-r--r-- 1 tim.yi tim.yi 846921728 Feb  9 11:02 picos-4.2.1-019ad0ef74-x86v.vmdk
-rw-r--r-- 1 build  build  847118336 Jan 27 15:56 picos-4.2.1-019ad0ef74-x86v.qcow2
-rwxr-xr-x 1 build  build  218188703 Jan 27 15:13 onie-installer-picos-4.2.1-019ad0ef74-x86v.bin
-rw-r--r-- 1 build  build  807927808 Nov 30 14:49 picos-4.1.0-picos-v-cc2cffc049-x86v.qcow2
-rwxr-xr-x 1 build  build  215618463 Nov 30 14:46 onie-installer-picos-4.1.0-picos-v-cc2cffc049-x86v.bin

2: You can change the VM's network adapter type to "E1000".
[cid:_Foxmail.1@2256252c-2f6e-61a8-fc8a-0deeb15843bd]

[cid:_Foxmail.1@2fe0d16d-e884-8bff-36ce-2ba6b12905dd]

Thanks
________________________________
Lisa.Pi@pica8.com

From: Lisa.Pi@pica8.com<mailto:Lisa.Pi@pica8.com>
Date: 2022-03-28 16:02
To: tim.yi<mailto:tim.yi@pica8.com>; Aaron Shang<mailto:aaron.shang@pica8.com>
CC: lisa.pi<mailto:Lisa.Pi@pica8.com>; Yachal Chen<mailto:yachal.chen@pica8.com>; ''ldu''<mailto:ldu@pica8.com>; Mani Subramanian<mailto:mani.subramanian@pica8.com>
Subject: Re: RE: Converting PicOS-V image from qcow2 to off format
Hi, Tim and Aaron

I still need your or Aaron's help.
I have changed the VM network card to VM Network group and then rebooting the VM: the vmnic1 is mapping the server's management.
But now on Picos-V system, the eth0 port also can not find.
What I don't understand is it the other ports corresponding to eth0 on picos-v?
[cid:_Foxmail.1@c2e84eae-94d4-b5d1-6631-9ee344758c6d]
[cid:_Foxmail.1@fbdb7df4-9b3c-4585-8ad1-8ca585a6ca50]


Thanks
________________________________
Lisa.Pi@pica8.com

From: Tim Yi<mailto:tim.yi@pica8.com>
Date: 2022-03-28 11:33
To: Lisa Pi<mailto:lisa.pi@pica8.com>; Mani Subramanian<mailto:mani.subramanian@pica8.com>
CC: Yachal Chen<mailto:yachal.chen@pica8.com>; Lin Du<mailto:lin.du@pica8.com>
Subject: RE: FW: Converting PicOS-V image from qcow2 to off format
I’m not familiar with this.
Maybe you can follow this guide:
https://docs.vmware.com/en/VMware-vSphere/6.5/com.vmware.vsphere.vm_admin.doc/GUID-E6857A76-AE4B-492B-A9A7-1EE94601F8F3.html

Thanks,
Tim Yi
Pica8, Inc.
tyi@pica8.com<mailto:tyi@pica8.com>  |  www.pica8.com<http://www.pica8.com/>

From: Lisa Pi
Sent: Monday, March 28, 2022 9:20 AM
To: Mani Subramanian <mani.subramanian@pica8.com>; Tim Yi <tim.yi@pica8.com>
Cc: Lisa Pi <lisa.pi@pica8.com>; Yachal Chen <yachal.chen@pica8.com>; Lin Du <lin.du@pica8.com>
Subject: Re: FW: Converting PicOS-V image from qcow2 to off format

Hi, Tim

Before creating the ova, I added four network card for the VM. But it can not work, is it caused by the 10.10.50.44 is not a multi network card server?
If it goes to a server that supports multiple network cards, is it will work normally?
Can you help me?

[cid:_Foxmail.1@0c2edeec-506d-3bb0-5a78-f219aaaf501a]

Thanks
________________________________
Lisa.Pi@pica8.com<mailto:Lisa.Pi@pica8.com>

From: Mani Subramanian<mailto:mani.subramanian@pica8.com>
Date: 2022-03-26 03:40
To: Lisa Pi<mailto:lisa.pi@pica8.com>
CC: Yachal Chen<mailto:yachal.chen@pica8.com>
Subject: FW: Converting PicOS-V image from qcow2 to off format
Hi Lisa,

I used the OVA file Yachal provided (link given below) me on a ESXi server 6.5. My goal was  to run PicOS-V VM on ESXi server.

I imported OVA. First thing I need to do – I need to configure OOB eth0. It says no eth0 found. Can you please verify this in BJ and fix the issue?

[Text Description automatically generated]

Once you fix it, please provide me an OVA image with link (or image in dev22) for PicOS-V version 4.2.1 that will work as VM on ESXi server 6.5. If you can provide this working OVA  image  on your Monday it will be helpful.

Thanks,
Mani

From: Yachal Chen <yachal.chen@pica8.com<mailto:yachal.chen@pica8.com>>
Date: Monday, March 14, 2022 at 5:54 PM
To: Mani Subramanian <mani.subramanian@pica8.com<mailto:mani.subramanian@pica8.com>>
Cc: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com<mailto:Sasikumar.puthiyaveedu@pica8.com>>
Subject: Re: Converting PicOS-V image from qcow2 to off format

You can download the OVA file in http://172.16.0.44/picos/picos-v/v4.2.1/

From: Mani Subramanian <mani.subramanian@pica8.com<mailto:mani.subramanian@pica8.com>>
Date: Monday, March 14, 2022 at 5:01 PM
To: Yachal Chen <yachal.chen@pica8.com<mailto:yachal.chen@pica8.com>>
Cc: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com<mailto:Sasikumar.puthiyaveedu@pica8.com>>
Subject: Re: Converting PicOS-V image from qcow2 to off format

Here is the screenshot on ESXi server:

[cid:_Foxmail.1@e11dd2a7-b5bc-511a-8f9f-644d2016f9a1]

Thanks,
Mani

From: Mani Subramanian <mani.subramanian@pica8.com<mailto:mani.subramanian@pica8.com>>
Date: Monday, March 14, 2022 at 4:54 PM
To: Yachal Chen <yachal.chen@pica8.com<mailto:yachal.chen@pica8.com>>
Cc: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com<mailto:Sasikumar.puthiyaveedu@pica8.com>>
Subject: Converting PicOS-V image from qcow2 to off format

Hi Yachal,

I did the following so far on my Linux machine:

1.      Identify CPU family on the server: more /proc/cpuinfo
2.      Install qemu Tool in Linux Server: sudo apt-get install qemu-system
3.      SCP the image: $ scp picos-4.2.1-019ad0ef74-x86v.qcow2 pica8-lab@192.168.42.71:/home/pica8-lab/picos-v/<mailto:pica8-lab@192.168.42.71:/home/pica8-lab/picos-v/>
4.      Convert the image using following command:
qemu-img convert -f qcow2 -O vmdk picos-4.2.1-019ad0ef74-x86v.qcow2 picos-4.2.1-019ad0ef74-x86v.vmdk

pica8-lab@SE_Lab_Tools:~/picos-v$ ls -l picos-4.2.1-019ad0ef74-x86v.vmdk
-rw-r--r-- 1 pica8-lab pica8-lab 846921728 Mar 14 11:20 picos-4.2.1-019ad0ef74-x86v.vmdk

I successfully converted the qcow2 image to vmdk format.

Our Lab VSphere needs both ovf file and vmdk file

To covert to ovf file I downloaded ovftool on my Unbuntu server
5.      sudo /bin/sh VMware-ovftool-3.5.0-1274719-lin.x86_64.bundle

I do not know how to covert the VMDK file to ovf. I tried few commands and it fails.

pica8-lab@SE_Lab_Tools:~/picos-v$ ovftool picos-4.2.1-019ad0ef74-x86v.vmdk picos-4.2.1-019ad0ef74-x86v.ovf
Opening OVF source: picos-4.2.1-019ad0ef74-x86v.vmdk
Error: Failed to open OVF descriptor
Completed with errors

Let me know how to get both ovf file and vmdk files.

Thanks,
Mani




----




Seems good news.
We only need to let browsers know that this cert is endorsed by CAs, even it is not accessing a website.
From the IBM link given by Leon, it provided the pem/cert and let users import them.
We can look into this means as a backup plan.

________________________________________
From: Leon Li <leon.li@pica8.com>
Sent: Monday, March 28, 2022 14:05
To: James Liao; Aaron Shang
Cc: Lin Du
Subject: RE: 回复: Internal pre-release for AmpCon 1.6.0

James & Aaron,

If user does not have a fixed domain name and use IP address for visit,
Even the it is signed with a trust chain, it will still have the issue since the certificate "common name" is still not able to pass the check.

A new finding is that this issue only happened in MAC OS now,
today we test it with latest Chrome 99.0.4844.84 in both MAC & Windows 11, it works with the old behavior for Win11.
After we put the certificate in trust chain in MAC OS, it will show the "continue" button in Chrome instead of only showing error.

We will check to see if it can be fixed with generating the key & certificate with more security params.

Thanks,
Leon

-----Original Message-----
From: James Liao <james.liao@pica8.com>
Sent: Monday, March 28, 2022 1:55 PM
To: Aaron Shang <aaron.shang@pica8.com>; Leon Li <leon.li@pica8.com>
Cc: Lin Du <lin.du@pica8.com>
Subject: Re: 回复: Internal pre-release for AmpCon 1.6.0

We used letsencrypt before. This is basically for web site to self-certificate and it requires a fixed domain name to certify. Our AmpCon is a software running inside an organization (not in cloud). Does the same certification process apply?

James

On 3/27/22, 10:50 PM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

    Hi, James,

    The best means is to use CA cert ones, instead of self certified ones without trust chain.

    We can use this one,
    https://letsencrypt.org/

    We only need a bot to refresh the cert files every 3 months.

    ________________________________________
    From: James Liao <james.liao@pica8.com>
    Sent: Saturday, March 26, 2022 09:17
    To: Leon Li
    Cc: Lin Du; Aaron Shang
    Subject: RE: 回复: Internal pre-release for AmpCon 1.6.0

    Aaron, do you know how to handle this? Don't worry if you don't. I can ask Neal in that case.


    -------- Original message --------
    From: Leon Li <leon.li@pica8.com>
    Date: 3/25/22 6:15 PM (GMT-08:00)
    To: James Liao <james.liao@pica8.com>
    Cc: Lin Du <lin.du@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
    Subject: 回复: Internal pre-release for AmpCon 1.6.0

    James，

    Okay, I will be responsible to write the documnet on how to generate a self-signed certificate, how to replace in AmpCon server and how to load it to Chrome as trusted certificate.

    However, still what we can generate is a self-signed certificate, if Chrome keeps having this behavior accrording to the security concern. (in before they rollback the behavior since too many complains in 2020)
    I think we can show the steps to accept self-signed certificate in Chrome, and that is how IBM handle with this issue  (https://www.ibm.com/docs/en/cloud-private/3.2.x?topic=console-cannot-access-management-macos-catalina)
    Or we need to check Chrome to see which type of the self-signed certificate (key length / encryption algorithm/ SSL TLS version /whether the certificate should be in trusted list) can make Chrome show "Continue to visit" in Advance dropdowns.

    Thanks,
    Leon
    ________________________________
    发件人: James Liao <james.liao@pica8.com>
    发送时间: 2022年3月26日 4:57
    收件人: Leon Li <leon.li@pica8.com>
    抄送: Lin Du <lin.du@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
    主题: Re: Internal pre-release for AmpCon 1.6.0


    Leon, Aaron,



    We need to learn and document how to build the certificate into AmpCon. Can Leon write this up in our knowledge base so we don’t repeat the same problem?



    Thanks,
    james



    From: Leon Li <leon.li@pica8.com>
    Date: Friday, March 25, 2022 at 12:07 AM
    To: James Liao <james.liao@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>
    Cc: Niraj Jain <niraj.jain@pica8.com>, Yachal Chen <yachal.chen@pica8.com>, Kelly LeBlanc <kelly.leblanc@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
    Subject: RE: Internal pre-release for AmpCon 1.6.0



    Hi all,



    Update the certificate visit issue here



    Actually we do not update anything with the private/public key or certificate in any upgrade. (you can compare the keys / certs under /usr/share/automation/server/server_keys/)

    It is a security enforcement in latest release Chrome and I can not reproduce it in latest windows version (99.0.4844.82, I can not find 99.0.4844.83 in windows platform).



    And I found this issue is wildly existing with the self-signed certificate application.

    It requires to accept the given certificate as a safe one (please refer to the steps to accept the certificate)

    Otherwise you can upload your own valid keys and certificate under /usr/share/automation/server/server_keys/.

    https://www.ibm.com/docs/en/cloud-private/3.2.x?topic=console-cannot-access-management-macos-catalina

    https://peacocksoftware.com/blog/make-chrome-auto-accept-your-self-signed-certificate



    BTW, Neal just told me a wizard magic trick way to bypass this check:

    Type "thisisunsafe" and hit enter on that page, then you will be able to visit that page in Chrome.





    Thanks,

    Leon

    From: Leon Li <leon.li@pica8.com>
    Sent: Friday, March 25, 2022 7:44 AM
    To: James Liao <james.liao@pica8.com>; Mani Subramanian <mani.subramanian@pica8.com>
    Cc: Niraj Jain <niraj.jain@pica8.com>; Yachal Chen <yachal.chen@pica8.com>; Kelly LeBlanc <kelly.leblanc@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
    Subject: 回复: Internal pre-release for AmpCon 1.6.0



    James，



    A self-signed SSL certificate has been installed in AmpCon web server.

    I think it is the new behavior of Chrome to prevent the bypass of the invalid self-signed cert.

    (in before, user has the option to continue the visit)

    https://support.google.com/chrome/thread/10551759/net-err-cert-invalid-website-sent-scrambled-credentials-self-signed-certificate?hl=en

    NET::ERR_CERT_INVALID website sent scrambled credentials Self-signed Certificate - Google<https://support.google.com/chrome/thread/10551759/net-err-cert-invalid-website-sent-scrambled-credentials-self-signed-certificate?hl=en>

    This help content & information General Help Center experience. Search. Clear search

    support.google.com

    I do not think we have a change with the private/public key or cert file.

    Anyway we will try to reproduce that it the Chrome.



    Thanks,

    Leon



    ________________________________

    发件人: James Liao <james.liao@pica8.com<mailto:james.liao@pica8.com>>
    发送时间: 2022年3月25日 7:35
    收件人: Mani Subramanian <mani.subramanian@pica8.com<mailto:mani.subramanian@pica8.com>>; Leon Li <leon.li@pica8.com<mailto:leon.li@pica8.com>>
    抄送: Niraj Jain <niraj.jain@pica8.com<mailto:niraj.jain@pica8.com>>; Yachal Chen <yachal.chen@pica8.com<mailto:yachal.chen@pica8.com>>; Kelly LeBlanc <kelly.leblanc@pica8.com<mailto:kelly.leblanc@pica8.com>>; Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com<mailto:Sasikumar.puthiyaveedu@pica8.com>>
    主题: Re: Internal pre-release for AmpCon 1.6.0



    Mani,



    The screenshot indicates the web site (or the AmpCon server) is not installed with SSL certificate. Have you installed the certificate before? By the way, it would be good to work with Yachal before you send the question to Leon. You would have gotten faster response time.



    James



    From: Mani Subramanian <mani.subramanian@pica8.com<mailto:mani.subramanian@pica8.com>>
    Date: Thursday, March 24, 2022 at 4:20 PM
    To: Leon Li <leon.li@pica8.com<mailto:leon.li@pica8.com>>
    Cc: Niraj Jain <niraj.jain@pica8.com<mailto:niraj.jain@pica8.com>>, Yachal Chen <yachal.chen@pica8.com<mailto:yachal.chen@pica8.com>>, James Liao <james.liao@pica8.com<mailto:james.liao@pica8.com>>, Kelly LeBlanc <kelly.leblanc@pica8.com<mailto:kelly.leblanc@pica8.com>>, Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>, Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com<mailto:Sasikumar.puthiyaveedu@pica8.com>>
    Subject: Re: Internal pre-release for AmpCon 1.6.0



    Hi Leon,



    Today I upgraded my AmpCon from 1.5.1 to 1.6.0. Upgrade went fine.



    Here is the summary of the issue:



    1.       After the upgrade AmpCon login page was not working in Chrome.

    2.       Before the upgrade AmpCon 1.5.1 Login page worked fine with Chrome.

    3.       After the upgrade, Chrome Browser works fine with competitors products’ web server applications like ClearPass, and ISE

    4.       After the upgrade, AmpCon login page works fine with Firefox Browser version 98.0.2





    [Graphical user interface  Description automatically generated]



    Thanks,

    Mani



    From: Leon Li <leon.li@pica8.com<mailto:leon.li@pica8.com>>
    Date: Thursday, March 17, 2022 at 8:01 AM
    To: James Liao <james.liao@pica8.com<mailto:james.liao@pica8.com>>, Yachal Chen <yachal.chen@pica8.com<mailto:yachal.chen@pica8.com>>
    Cc: Mani Subramanian <mani.subramanian@pica8.com<mailto:mani.subramanian@pica8.com>>, Niraj Jain <niraj.jain@pica8.com<mailto:niraj.jain@pica8.com>>
    Subject: Internal pre-release for AmpCon 1.6.0



    Hi James and Yachal,



    As discussed before, the AmpCon 1.6.0 internal release is ready in dev22

    You can find it here:

    leon.li@dev22:/tftp/build/release/ampcon_release_1.6.0_pre$<mailto:leon.li@dev22:/tftp/build/release/ampcon_release_1.6.0_pre$> ls -ltr

    total 478504

    -rw-r--r-- 1 build build 143278006 Mar 17 22:24 ampcon-update-1.6.0-dev-6a4adb95fa.tar.gz

    -rw-r--r-- 1 build build 346699636 Mar 17 22:28 ampcon-picos-v-1.6.0-dev-6a4adb95fa.tar.gz



    In AmpCon 1.6.0, we mainly support AmpCon APIs and internal Picos-V for generated config verification.

    Please check the details in attachment zip files which includes the guidance, document and test result document.



    For AmpCon APIs, we also provide the APIs collection export JSON from an API test tool named “Postman”,

    It will help with our QA test and on the other hand it will be a good way for us to show the end users how to use these APIs instead of just looking for the APIs doc.



    And here is the status updates:

    1.     As we required for OVA, OVF, QCOW2 VM format support, we need to verify whether the internal Picos-V can work in other VM software (VirtualBox …)

    Currently we only test it in VMware ESXi 7.0 (BJ office has ESXi 5.5 but that server does not support hardware virtualization, which means it can not install the QEMU in a VM.)

    2.     We meet a problem with generate the OVA, OVF files generated from remote tonight.

    Will update the OVA, OVF and QCOW2 later.



    Please let me know if any problems.



    Thanks,

    Leon







----






I don't think copying the encrypted hashes a good idea, even we don't think about security concerns.
The CLI, the web interface, the telnet/ssh connection, the clipboard, the buffer, all means might intercept the string to make them false.

BTW, and the hashing methods had been improving with time, so it's not proper to use a fixed scheme.

E.g., the case Tom gave is the deprecated `md5crypt`(with leading $1$SALT$) hashing, which we had fixed to current `sha512crypt`(with leading $6$SALT$) according to customer request.
And in Debian 12, the hashing had been a better `yescrypt` (with leading $y$SALT$)


Refer also to `man 5 crypt` page: https://man.cx/crypt(5)





________________________________________
From: Tom Jia <tom.jia@pica8.com>
Sent: Friday, March 18, 2022 10:54
To: Zoneson Chen; Vic Lan; Aaron Shang
Cc: TAC; plm@pica8.com
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes

Hi Zoneson,

In fact, the scenario in case of password is much tricky.

On one switch, in beginning, set the password to such as "pica8".

set system login user test authentication plain-text-password pica8

When execute cli command "show | display set", the output will look like,

 set system login user test authentication plain-text-password "$1$ZDH77ruH$rB.cx7uV.CsmuDttK6E8K0"

encrypted-password to be added is a different config node from plain-text-password. Therefore, the configured value "pica8" on plain-text-password cannot be encrypted and go to encrypted-password because a value of a config node can only be changed from a user or a remote client program such Ampcon. Additionally, the plain text "pica8" should not be in the output of "show | display set" because that will cause security concern from customers such as Verizon.

In this case, customer can copy the encrypted password from the output of "show | display set",

set system login user test authentication plain-text-password "$1$ZDH77ruH$rB.cx7uV.CsmuDttK6E8K0"

and then configure it on another switch,

set system login user test authentication encrypted-password "$1$ZDH77ruH$rB.cx7uV.CsmuDttK6E8K0".

I am not sure if I state it clearly.

From my understanding, the password should not be allowed to be copied from one switch to another switch. Password should be set explicitly. Anyway, customer is customer. If it is a must-have, we need to work it out.

Thanks.

________________________________
Best regards,
Tom Jia (贾彦民)


________________________________
From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Friday, March 18, 2022 9:30 AM
To: Tom Jia <tom.jia@pica8.com>; Vic Lan <vic.lan@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: TAC <tac@pica8.com>; plm@pica8.com <plm@pica8.com>
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes


Tom,



Thank you for the prompt answers! Your proposal looks good to me.



I assume that this is the scenario:



  1.  Set password by using:

# set system login user <username> authentication plain-text-password <password>



  1.  Display password as:

set system login user <username> authentication encrypted-password <encrypted-password>



  1.  Copy and paste password to another PICOS switch as:

# set system login user <username> authentication encrypted-password <encrypted-password>



Are my understandings correct?



Thanks,



Zoneson







From: Tom Jia <tom.jia@pica8.com>
Date: Thursday, March 17, 2022 at 5:53 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Vic Lan <vic.lan@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: TAC <tac@pica8.com>, plm@pica8.com <plm@pica8.com>
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes

Hi Zoneson,



For the reversible keys, it will be no problem to accept encrypted or plaint text in the cli command because we can recognize an encrypted key based on our encryption algorithm.



In case of unreversible password such as the login user, we have to add an extra cli command such as,



set system login user <username> authentication encrypted-password <password>



And then customer can copy the encrypted password to this command if s/he want to set the same password on a different switch in this way.



Thanks.

________________________________

Best regards,

Tom Jia (贾彦民)



________________________________

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Friday, March 18, 2022 12:33 AM
To: Tom Jia <tom.jia@pica8.com>
Cc: TAC <tac@pica8.com>; plm@pica8.com <plm@pica8.com>
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes



Tom,



Sasi submitted bug#14185 for AT&T. ABL Space has the same request. We need to re-address this issue again. Their requests are not only to those keys reversible, but also to those not reversible such as <password> in the following CLI:



# set system login user <username> authentication plain-text-password <password>



Thanks,



Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Thursday, February 17, 2022 at 9:50 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: TAC <tac@pica8.com>, plm@pica8.com <plm@pica8.com>
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes

Hi Zoneson,



I understood your point.



My concern is that we would have 2 duplicate nodes in the config tree for the same configurable value. We need to manage the priority or conflict between these 2 nodes. For example, based on the current CLI mechanism, if md5 is dispatched to ospf first and then hashed-md5 is dispatched to ospf later, hashed-md5 will override md5. Anyway, we can do it even it is a little bit complicated.



It looks that it's our pica8 team that help customers convert configuration from 3.x to 4.x. If that is the case, alternatively, I can provide a python script to resolve this problem. Please let me know your conversion procedure.



Thanks.

________________________________

Best regards,

Tom Jia (贾彦民)



________________________________

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Friday, February 18, 2022 1:17 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TAC <tac@pica8.com>; plm@pica8.com <plm@pica8.com>
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes



HI Tom,



I did not explain my proposal (different from Dotto-one but the idea is similar) in the previous mail well. I will give another try since it is important to us  to build a mechanism to customers to upgrade PICOS from 3.x to 4.x automatically.



Today (2.x, 3.x & 4.x), we hash (the mechanism could be base64 or others) the entered plain-text when customers set the password or key and save the hashed-text to configuration file (/pica/config/pica_startup.boot). PICOS knows how to convert the hashed-text back to plain-text.



Taking the following CLI set command as an example, here is what customer entered:



set protocols ospf interface vlan3525 message-digest-key 1 md5 d0tt00spf



My suggestion is:



  1.  There are no changes to the existing CLI commands. Customers still sets the password/key by using the plain-text.
  2.  In the version which supports this suggestion, the CLI command knows that it is hashed-text and know to convert it to plain-text if the key word is hashed-md5 (you may have a better name):



set protocols ospf interface vlan3525 message-digest-key 1 hashed-md5 "M0JtZDB0dDAwc3BmWkRC"



Of course, the key word ‘md5’ can be changed to ‘hashed-md5’ in /pica/config/pica_startup.boot after commit.



Personally, I think that it is a simple change to engineering team. But it will make auto upgrade from 3.x to 4.x possible.



Thanks,



Zoneson



From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Sunday, February 13, 2022 at 8:05 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: TAC <tac@pica8.com>, plm@pica8.com <plm@pica8.com>
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes

Tom,



Add PLM team.



Thank you for the explanation!



I do not think that we are able to do anything on the existing versions.



In the future versions, I would like to propose to add an option to CLI for those password/key with hashed text, such as:



# set protocols bgp neighbor [IPv4 | IPv6] [password | hashed-pw] <text>

# set system login user <text> authentication [plain-text-password | hashed-pw] <text>



It could make things easier to customers to upgrade from 3.x to 4.x.



Thanks,



Zoneson



From: Tom Jia <tom.jia@pica8.com>
Date: Sunday, February 13, 2022 at 6:03 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: TAC <tac@pica8.com>
Subject: Re: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes

Hello Zoneson,



Sorry for late response.



Basically, the plaintext input is converted to a string of base64 code with a small trick which is used to recognize the converted base64 codes for the purpose of upgrade. For example, In this case, the original input "d0tt00spf" (ospf message-digest-key md5) is converted to "M0JtZDB0dDAwc3BmWkRC". I don't think it is necessary to let customers know this mechanism for some kind of security concern.



[cid:a1294a0d-dbaa-4f0c-a65a-7197bfe28d38]



if reset this this md5 config node with below set command,



set protocols ospf interface vlan3525 message-digest-key 1 md5 "M0JtZDB0dDAwc3BmWkRC"



PICOS CLI will view "M0JtZDB0dDAwc3BmWkRC" as the original plaintext.



As customer mentioned, it is no problem if this converted base64 code is in pica_startup.boot. In fact, it is the converted base64 code that is restored in pica_startup.boot.



Additionally, I don't think it is a good idea to have multiple ways to configure the same parameter. That would be much confusing & complicated to keep the consistency between the different configurations.



Please let me know if any further question.



Thanks.

________________________________

Best regards,

Tom Jia (贾彦民)



________________________________

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Saturday, February 12, 2022 6:26 AM
To: Tom Jia <tom.jia@pica8.com>
Cc: TAC <tac@pica8.com>
Subject: <Tom help>FW: v4.2.1 configuration import of OSPF MD5 hashes



Tom,



Here is Ian’s suggestion. Is it feasible?



Thanks,



Zoneson



From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Friday, February 11, 2022 at 2:24 PM
To: Ian MacDonald <ian@dotto-one.com>
Cc: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>, support@pica8.com <support@pica8.com>, Mansoor Zabihollahi <mansoor.zabihollahi@dotto-one.com>
Subject: Re: v4.2.1 configuration import of OSPF MD5 hashes

Ian,



Thank you for informing us what you find! I will forward your mail to the engineering team to consider it.



Thanks,



Zoneson



From: Ian MacDonald <ian@dotto-one.com>
Date: Friday, February 11, 2022 at 2:02 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>, support@pica8.com <support@pica8.com>, Mansoor Zabihollahi <mansoor.zabihollahi@dotto-one.com>
Subject: Re: v4.2.1 configuration import of OSPF MD5 hashes

Zoneson,



Currently the output value from display set can be copied into a pica_startup.boot and will work.  So the hash value, even though it is not the actual key or plaintext value, functions to authenticate OSPF when provided to PICOS.  It is not the actual MD5 hash used by OSPF, so it could not be transported to another router and used.   It is a reproducible hash, but not a value directly acceptable by an OSPF daemon.



Assuming my understanding is correct, I would suggest then that the current input mechanism be modified with an additional parameter to indicate the input value is the original md5 hash/passphrase vs the picos secret.



    set protocols ospf interface vlan3525 message-digest-key 1 picos "M0JtZDB0dDAwc3BmWkRC"

    set protocols ospf interface vlan3525 message-digest-key 1 md5 "ffb1eaa0c5ccce148dfda680551d397d"



You might allow a third plaintext input option for migration compatibility, noting there may be other cases like ours moving from plaintext and have not generated an MD5 equivalent yet.



Only the picos secret would be shown during display set (similar to current implementation).



set protocols ospf interface vlan3525 message-digest-key 1 picos "M0JtZDB0dDAwc3BmWkRC"



This allows the configuration to be re-comittable and used in scripts, backups, etc. consistent with the rest of the configuration.



Ian



On Fri, Feb 11, 2022 at 4:17 PM Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>> wrote:

Hi Ian,



In some companies, some of the admins have the read-only privilege. These companies do not want those read-only admins know the entered plaintext of the passwords or keys. It is what I meant the security concern.



I have asked our engineering team whether there exists a way to work around it.



Thanks,



Zoneson



From: Ian MacDonald <ian@dotto-one.com<mailto:ian@dotto-one.com>>
Date: Friday, February 11, 2022 at 12:12 PM
To: Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>
Cc: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com<mailto:Sasikumar.puthiyaveedu@pica8.com>>, support@pica8.com<mailto:support@pica8.com> <support@pica8.com<mailto:support@pica8.com>>, Mansoor Zabihollahi <mansoor.zabihollahi@dotto-one.com<mailto:mansoor.zabihollahi@dotto-one.com>>
Subject: Re: v4.2.1 configuration import of OSPF MD5 hashes

Zoneson,



I am not sure I understand what the security and implementation goals are.



Currently all our devices generate the same hash value from the input passphrase (previously a plaintext password), and the resulting hash can be cut n paste to any device, and it works as a valid key.



So I assume the hash is just to obfuscate the original passphrase,  not to prevent re-use of a shared configuration export from a privileged superuser.   - > Maybe this is where we are incorrect in our assumptions.



The issue we see is that the hash value output by display set is not accepted as-is.  It becomes modified when re-committed.



We would expect to be able to deploy a valid hash using the set command, but currently it requires inputting the original plaintext keyphrase to get the same hash value.



We think there probably needs to be a separate input method for either the original passphrase vs the resulting hash so that the display set configuration can be re-deployed without modification.



Another observation is that the hash length appears to be able to change.   Our initial conversion of our plaintext password generated this 20 character MD5 hash, show below.



    set protocols ospf interface vlan3525 message-digest-key 1 md5 "M0JtZDB0dDAwc3BmWkRC"



If we simply paste it back into the cli and re-commit, it then generates the following 36 character MD5 hash.



    set protocols ospf interface vlan3525 message-digest-key 1 md5 "a009TTBKdFpEQjBkREF3YzNCbVdrUkM=VFRC"



I hope that helps clarify,



cheers,
Ian



On Fri, Feb 11, 2022 at 2:04 PM Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>> wrote:

Hi Ian,



We kept the password (including OSPF MD5 key) in plaintext in configuration file in early versions. It causes security concerns to some customers. It is the reason to show the hash value instead of the original entered plaintext.



It is also my main concern on implementing the program to convert configurations from 2.x to 3.x.



I will discuss it with engineering team and see whether there exists a way to resolve it.



Thanks,



Zoneson





From: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com<mailto:Sasikumar.puthiyaveedu@pica8.com>>
Date: Friday, February 11, 2022 at 10:37 AM
To: Ian MacDonald <ian@dotto-one.com<mailto:ian@dotto-one.com>>, support@pica8.com<mailto:support@pica8.com> <support@pica8.com<mailto:support@pica8.com>>
Subject: Re: v4.2.1 configuration import of OSPF MD5 hashes

Hi Ian,

Thank you for contacting Pica8 Support. We will check the issue you reported and get back to you.



Regards,

Sasi





From: Ian MacDonald <ian@dotto-one.com<mailto:ian@dotto-one.com>>
Date: Friday, February 11, 2022 at 9:51 AM
To: "support@pica8.com<mailto:support@pica8.com>" <support@pica8.com<mailto:support@pica8.com>>
Subject: v4.2.1 configuration import of OSPF MD5 hashes



Hello Pica8,



We noticed that in v4.2.1 OSPF configuration, there is a configuration node that can not be

consistently re-applied after export via display set



The result is that any automation or backup or deployment of running OSPF configuration using display set output results in a change to MD5 keys.



See the following set of command as an example, where we

a) View the running configuration

b) Re-apply the running configuration

c) Resulting in a different running configuration



Repeating the process, continues to generate new hash values.



Normally we would expect a 'duplicate value' message to indicate the MD5 has being applied matches the existing one, but even still, we were not expecting it to generate a new hash value.



It seems message-digest-key command only accepts string passphrase values, but sets an md5 hash value using the same syntax in the display set output.



Because of this, if you do not know the seed value for the hash, you can not copy, compare or backup the running configuration via the cli in a reliable manner.



cheers,
Ian



admin@SUM-CORE# show protocols ospf | display set
    set protocols ospf redistribute connected route-map "dirconnected"
    set protocols ospf interface vlan3525 area "0.0.0.1"
    set protocols ospf interface vlan3525 authentication message-digest
    set protocols ospf interface vlan3525 message-digest-key 1 md5 "M0JtZDB0dDAwc3BmWkRC"
    set protocols ospf interface vlan3525 network "point-to-point"

admin@SUM-CORE#     set protocols ospf interface vlan3525 message-digest-key 1 md5 "M0JtZDB0dDAwc3BmWkRC"
admin@SUM-CORE# commit check
Commit check OK.
admin@SUM-CORE# commit
Commit OK.
admin@SUM-CORE# show protocols ospf | display set
    set protocols ospf redistribute connected route-map "dirconnected"
    set protocols ospf interface vlan3525 area "0.0.0.1"
    set protocols ospf interface vlan3525 authentication message-digest
    set protocols ospf interface vlan3525 message-digest-key 1 md5 "a009TTBKdFpEQjBkREF3YzNCbVdrUkM=VFRC"
    set protocols ospf interface vlan3525 network "point-to-point"






----




带有行号的：


=================================================================
==19217==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 96 byte(s) in 3 object(s) allocated from:
    #0 0x7f025a5ac330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7f025a497b60 in execute_command(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::list<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&, bool, bool) (/pica/lib/libxorp.so.0+0x31b60)

Direct leak of 24 byte(s) in 1 object(s) allocated from:
    #0 0x7f025a5add30 in operator new(unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xead30)
    #1 0x5622ecba88b7 in __gnu_cxx::new_allocator<std::_List_node<unsigned int> >::allocate(unsigned long, void const*) /usr/include/c++/8/ext/new_allocator.h:111
    #2 0x5622ecba88b7 in std::allocator_traits<std::allocator<std::_List_node<unsigned int> > >::allocate(std::allocator<std::_List_node<unsigned int> >&, unsigned long) /usr/include/c++/8/bits/alloc_traits.h:436
    #3 0x5622ecba88b7 in std::__cxx11::_List_base<unsigned int, std::allocator<unsigned int> >::_M_get_node() /usr/include/c++/8/bits/stl_list.h:450
    #4 0x5622ecba88b7 in std::_List_node<unsigned int>* std::__cxx11::list<unsigned int, std::allocator<unsigned int> >::_M_create_node<unsigned int const&>(unsigned int const&) /usr/include/c++/8/bits/stl_list.h:642
    #5 0x5622ecba88b7 in void std::__cxx11::list<unsigned int, std::allocator<unsigned int> >::_M_insert<unsigned int const&>(std::_List_iterator<unsigned int>, unsigned int const&) /usr/include/c++/8/bits/stl_list.h:1903
    #6 0x5622ecba88b7 in std::__cxx11::list<unsigned int, std::allocator<unsigned int> >::push_back(unsigned int const&) /usr/include/c++/8/bits/stl_list.h:1220
    #7 0x5622ecba88b7 in L3InterfaceIdMgr::recycle_vlan_intf_id(unsigned int) /home/aaron/merge/pica/sif/siftree.cc:355
    #8 0x5622ecc866a1 in SifTree::recycle_intf_id(unsigned int const&) /home/aaron/merge/pica/sif/siftree.hh:894
    #9 0x5622ecc866a1 in SifTreeVif::~SifTreeVif() /home/aaron/merge/pica/sif/siftree.cc:13013
    #10 0x5622ecc866a1 in SifTreeVif::~SifTreeVif() /home/aaron/merge/pica/sif/siftree.cc:12997
    #11 0x5622ecc86cf0 in SifTreeVif::~SifTreeVif() /home/aaron/merge/pica/sif/siftree.cc:13014
    #12 0x5622ecbafcc7 in SifTree::clear() /home/aaron/merge/pica/sif/siftree.cc:660
    #13 0x5622ecbae879 in SifTree::~SifTree() /home/aaron/merge/pica/sif/siftree.cc:622
    #14 0x5622ec9f5fda in SifConfig::~SifConfig() /home/aaron/merge/pica/sif/sifconfig.cc:110
    #15 0x5622ecb40eee in SifNode::~SifNode() /home/aaron/merge/pica/sif/sif_node.cc:83
    #16 0x5622ecd51f07 in XrlSifNode::~XrlSifNode() /home/aaron/merge/pica/sif/xrl_sif_node.cc:55
    #17 0x5622ec9eeecb in sif_main /home/aaron/merge/pica/sif/pica_sif.cc:141
    #18 0x5622ec9c1299 in main /home/aaron/merge/pica/sif/pica_sif.cc:223
    #19 0x7f0257d4a09a in __libc_start_main ../csu/libc-start.c:308

SUMMARY: AddressSanitizer: 120 byte(s) leaked in 4 allocation(s).

________________________________________
From: Aaron Shang <aaron.shang@pica8.com>
Sent: Wednesday, February 23, 2022 16:19
To: Daisy Zhao; Jessie Xu
Cc: Lin Du; Iris Rong
Subject: Re: 只check sif的build请试一下


有个小问题，能否有更多信息我继续试


admin@Xorplus:/pica/bin/sif$ sudo /pica/bin/xorp_rtrmgr -v

在ctrl-C
时候：

[ 15950  +182 ../../xorp/libxorp/task.hh ~XorpTask ] XorpTask destructor 0x7f5e88f2b830, n = (nil)
[ 15950  +182 ../../xorp/libxorp/task.hh ~XorpTask ] XorpTask destructor 0x7f5e88f2b828, n = (nil)
[ 15950  +182 ../../xorp/libxorp/task.hh ~XorpTask ] XorpTask destructor 0x7f5e88f2b820, n = (nil)
[ 15950  +182 ../../xorp/libxorp/task.hh ~XorpTask ] XorpTask destructor 0x7f5e88efb090, n = (nil)
[udld]Received UDLD packet from an unconfigured port te-1/1/13 which only just might be removed
There are no pending changes.

iptables: No chain/target/match by that name.
ip6tables: No chain/target/match by that name.
iptables: No chain/target/match by that name.
ip6tables: No chain/target/match by that name.
[udld]Received UDLD packet from an unconfigured port te-1/1/7 which only just might be removed
info_init: mp 1/35, port_type 1, sfp_idx 36, sfp_bus 0
pica_port_module_info_init: mp 1/36, port_type 1, sfp_idx 37, sfp_bus 0
pica_port_module_info_init: mp 1/37, port_type 1, sfp_idx 38, sfp_bus 0
pica_port_module_info_init: mp 1/38, port_type 1, sfp_idx 39, sfp_bus 0
pica_port_module_info_init: mp 1/39, port_type 1, sfp_idx 40, sfp_bus 0
pica_port_module_info_init: mp 1/40, port_type 1, sfp_idx 41, sfp_bus 0
pica_port_module_info_init: mp 1/41, port_type 1, sfp_idx 42, sfp_bus 0
pica_port_module_info_init: mp 1/42, port_type 1, sfp_idx 43, sfp_bus 0
pica_port_module_info_init: mp 1/43, port_type 1, sfp_idx 44, sfp_bus 0
pica_port_module_info_init: mp 1/44, port_type 1, sfp_idx 45, sfp_bus 0
pica_port_module_info_init: mp 1/45, port_type 1, sfp_idx 46, sfp_bus 0
pica_port_module_info_init: mp 1/46, port_type 1, sfp_idx 47, sfp_bus 0
pica_port_module_info_init: mp 1/47, port_type 1, sfp_idx 48, sfp_bus 0
pica_port_module_info_init: mp 1/48, port_type 2, sfp_idx 49, sfp_bus 0
pica_port_module_info_init: mp 1/52, port_type 2, sfp_idx 50, sfp_bus 0
pica_port_module_info_init: mp 1/56, port_type 2, sfp_idx 51, sfp_bus 0
pica_port_module_info_init: mp 1/60, port_type 2, sfp_idx 52, sfp_bus 0
pica_port_module_info_init: mp 1/64, port_type 2, sfp_idx 53, sfp_bus 0
pica_port_module_info_init: mp 1/68, port_type 2, sfp_idx 54, sfp_bus 0
picasdk_phy_ctrl_attach


[RTRMGR]Can't validate stop of process ip
[SIF]Failed to apply the L3 action (action number:5, vrf:0)
[MPLS]MplsRouter destroyed

=================================================
==15643==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 96 byte(s) in 3 object(s) allocated from:
    #0 0x7fb13570d330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7fb1355f8b60 in execute_command(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::list<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&, bool, bool) (/pica/lib/libxorp.so.0+0x31b60)

Direct leak of 24 byte(s) in 1 object(s) allocated from:
    #0 0x7fb13570ed30 in operator new(unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xead30)
    #1 0x56111ebde8b7  (/pica/bin/sif/pica_sif+0x4118b7)
    #2 0x56111ecbc6a1  (/pica/bin/sif/pica_sif+0x4ef6a1)
    #3 0x56111ecbccf0  (/pica/bin/sif/pica_sif+0x4efcf0)
    #4 0x56111ebe5cc7  (/pica/bin/sif/pica_sif+0x418cc7)
    #5 0x56111ebe4879  (/pica/bin/sif/pica_sif+0x417879)
    #6 0x56111ea2bfda  (/pica/bin/sif/pica_sif+0x25efda)
    #7 0x56111eb76eee  (/pica/bin/sif/pica_sif+0x3a9eee)
    #8 0x56111ed87f07  (/pica/bin/sif/pica_sif+0x5baf07)
    #9 0x56111ea24ecb  (/pica/bin/sif/pica_sif+0x257ecb)
    #10 0x56111e9f7299  (/pica/bin/sif/pica_sif+0x22a299)
    #11 0x7fb132eab09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

SUMMARY: AddressSanitizer: 120 byte(s) leaked in 4 allocation(s).

admin@Xorplus:/pica/bin/sif$
admin@Xorplus:/pica/bin/sif$

________________________________________
From: Aaron Shang <aaron.shang@pica8.com>
Sent: Wednesday, February 23, 2022 14:38
To: Iris Rong
Cc: Lin Du
Subject: Re: 只check sif的build请试一下

http://10.10.50.22/build/pica_sif

这个加了2个额外的check选项，麻烦覆盖原来的文件测一下结果

________________________________________
From: Aaron Shang <aaron.shang@pica8.com>
Sent: Wednesday, February 23, 2022 13:18
To: Iris Rong
Cc: Lin Du
Subject: Re: 只check sif的build请试一下


这是pvlan那个分支最后的build

http://10.10.50.22/build/daily/x86/onie-installer-picos-9.8.7-pvlan-bug14043-9410e0cb59-x86.bin

其他的在这个目录下，搜pvlan, 结尾x86.bin不带其他后缀的就是不oem的

http://10.10.50.22/build/daily/x86/

现在我们不release的build只保留20天的

________________________________________
From: Aaron Shang <aaron.shang@pica8.com>
Sent: Wednesday, February 23, 2022 13:06
To: Iris Rong
Cc: Lin Du
Subject: 只check sif的build请试一下

http://10.10.50.22/build/daily/x86/onie-installer-picos-9.8.7-231bb84fb1-x86.bin

我下午争取build一个调用栈层数加大的版本试试






Happy new year, James,

Yes, you are right on all these points.
And I had been looking into #3 as you stated. I don't think we totally have no way to control the packets. We must find some means this way or that way.


I think you can continue with your initial Distributed Network Services plan.

________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Tuesday, January 4, 2022 08:20
To: Aaron Shang
Cc: Lin Du
Subject: Docker on PICOS

Aaron,

Happy new year. In 2022, I want to put more time into the new infrastructure, Docker Applications on PICOS. As far as I remember,

  1.  We are able to run Docker on the same Linux with PICOS.
  2.  We can control the CPU utilization of the Docker application
  3.  However, we don’t have a way to control the rate of the ingress packets to CPU, which consumes the CPU in the kernel process.

Are these three still true?

I think we need to continue working on #3, but in the meantime I need to start planning of the applications. If you have any idea, please let me know.

Thanks,
James







To change NIC speed, one easy way is to use ethtool command which had been in our x86/arm ROOTFS.

    ethtool -s eth0 speed 100 duplex full autoneg off

    ethtool -s eth0 speed 10

When setting the autoneg off, the transfer speed will lower to about 5MB/s.

When setting the speed to 10, the transfer speed will lower to about 1MB/s.

When setting the speed to a large value beyond the NIC capacity, the NIC will be down.

When setting the speed to a large value such as 12345678 not supported by the NIC, the NIC will be down, or has no impact which depends on different driver.


Another means to limit NIC speed is using CLI rate-limit command.

Both would incur packet drops.


Next, I will have Vivien to test packet drop when compiling a gcc package which will cause high CPU utilizing in a couple of hours.

As the plan B you mentioned, I will look into easy ways to limit NIC buffer.

________________________________________
From: James Liao (Pica8 Projects) <application@teamwork.com>
Sent: Wednesday, December 22, 2021 05:35
To: Aaron Shang
Subject: (PDLC) Re: Task: Enable Inband NICs of AS4630 (R&D) (Cards)

===== WRITE YOUR REPLY ABOVE THIS LINE =====
[http://s3.amazonaws.com/TWFiles/376314/siteLogo/tf_69D9F41F-9ACB-E25F-59CAD900D9E43AA6.pica8_logo_nobg.png]
Dec 21
13:35

Dec 21 13:35

James Liao commented on this task<https://projects.pica8.com/tasks/24563362?c=9388806>
@aarons Do we have any new findings on this?

Dec 16
15:13

Dec 16 15:13

James Liao commented
@vivieny @aarons I had a call with Lin on this subject and learned more details, which helped me to understand where our disconnection is.


  1.  Basically, the CPU threshold (10%, 20%, 50%) we describe here is the threshold of the Docker's usage, which is the user mode CPU utilization. Even when we put CPU threshold at 1%, as long as we don't run application, the 2Gbps traffic can still get to CPU, because it is only burning the kernel CPU cycle, but not Docker.
  2.  In this case, the 2Gbps of traffic consumes certain CPU. Since the traffic is processed in batches, we are seeing spikes of CPU utilization from Linux kernel, sometimes as high as 70%. This is where we have concerns.
  3.  It is not clear whether the spikes of CPU utilization impacts the PICOS operation. My guess is it does not, but there is no way to validate this until we collect enough data from the field in the future.
  4.  To control the CPU spikes, we have a couple of choices,
     *   Since the CPU utilization is dominated by the inbound traffic, we can provide a configuration to do speed limit on the ASIC port. This forces ASIC to drop packets when the egress buffer (to CPU) is full.
     *   Another way to limit the CPU cycle is to reduce the buffer size of the CPU NICs in the kernel space. This is a plan-B workaround because the buffer size cannot be dynamically set.

Dec 14
23:08

Dec 14 23:08

James Liao commented

Vivien,

Thanks for the data. I don’t understand (2) and (4), which seem to be counter intuitive. I don’t understand how we can control the CPU at 10% but still achieve the same throughput as the CPU at 70%. There must be some discrepancy that I have overlooked.

James

Dec 14
22:30

Dec 14 22:30

Vivien Yin commented
Hi James, sorry for late reply. Because Aaron is s till looking to see if it needs to be perfected.
And according my test:
1. If we don’t set the CPU threshold, we can drive 2Gbps traffic to CPU but the CPU consumption will be 73%-76%. Correct?
<Vivien>Yes, because speed of me-1/1/1 and me-1/1/2 have 2Gbps in total. According to my test, if the CPU threshold is not set,
the max cpu cansumption is about 75%,maybe less cpu cansumptionis needed. The "Actual cpu consume value1" and "Actual cpu consume value2" in the table are the random value which is choosen when I check the cpu consume.

2. If we set the CPU threshold (between 10% and 50%), the CPU consumption will be controlled. However, in these cases, there must be packet drop. Correct?
<Vivien>No, it's right that the Cpu threshold work well. But about 2Gbps traffic to cpu in these cases, there will have no drop packets. Only greater than 2Gbps packets is driven to cpu, there will have packet drop.

3. If (2) is true, each Gbps of traffic should consume about 35% of CPU. Correct?
<Vivien>If the CPU threshold is not set, 1Gbps will consume max cpu about 35%.

4. If (3) is true, when we drive 940Mbps of traffic to CPU at 10% threshold, we must have seen packet loss. Correct?
<Vivien>No, if we drive traffic 940Mbps of traffic to CPU at 10% threshold, will have no drop packets.

Dec 10
10:01

Dec 10 10:01

James Liao commented

Vivien,

Just want to make sure I interpret your numbers correctly.

  1.  If we don’t set the CPU threshold, we can drive 2Gbps traffic to CPU but the CPU consumption will be 73%-76%. Correct?
  2.  If we set the CPU threshold (between 10% and 50%), the CPU consumption will be controlled. However, in these cases, there must be packet drop. Correct?
  3.  If (2) is true, each Gbps of traffic should consume about 35% of CPU. Correct?
  4.  If (3) is true, when we drive 940Mbps of traffic to CPU at 10% threshold, we must have seen packet loss. Correct?

I am not questioning. Just try to get my math work out.

Dec 10
00:42

Dec 10 00:42

Vivien Yin commented
Hi James, sorry for driving 3Gbps of packets but 2Gbps is ok, because the max speed of eth1(me-1/1/1) is 1G. And I have tested it. The new result is following table2.
Table2:

About 2Gbps packets to cpu port, and the cpu consume is following.

Theoretical cpu threshold value

Actual cpu consume value1

Actual cpu consume value2

Without cpu threshold value

75.97%

73.77%

10%

9.11%

9.59%

20%

20.23%

17.50%

30%

30.28%

29.81%

40%

36.02%

35.08%

50%

50.62%

48.88%

Dec 09
23:06

Dec 09 23:06

James Liao commented

Vivien, Is it possible to run another tests? Can you drive 3Gbps of packets and see how much CPU it costs? I would like to get a sense of the CPU utilization per Gbps.


This email has been limited to the 6 most recent comments. View all comments<https://projects.pica8.com/tasks/24563362?c=9388806>

(#24563362)
Task Details

Due Date: Not set

Priority: Not set

Board Column:   CONCEPT (PLM)

Assigned To: Lin Du

Assigned By: James Liao

View Task: Enable Inband NICs of AS4630 (R&D)<https://projects.pica8.com/tasks/24563362#comment9388806>

Task List: Cards<https://projects.pica8.com/tasklists/1932615>

Task Description:


AS4630 comes with two 10GE NICs connecting to the Broadcom Trident-3 ASIC. We need to implement two things

  1.  A way (preferred CLI) to enable the two ASIC ports - this implies we need to come up with the naming of the ports. By default the ports should be disabled.
  2.  A way to enable the two NICs - this can be done through Linux commands or as a side-effect of enabling the ASIC ports in step #1.

The use case of these two ports are to run applications, such as Wireshark or DPI in a Docker container through the two inband NICs.

Project Details

Project: PDLC<https://projects.pica8.com/projects/194478>

Company: PICA8

Copied To: Lin Du, Aaron Shang

Not interested?: Stop receiving comments on this task<https://projects.pica8.com/ufen?uid=2921EE66CAC4A14A33551DAF3B33A8D21EA2FA01107E6EFF5014783A4EE390F4>

YOU CAN POST A REPLY TO THIS MESSAGE BY REPLYING TO THIS EMAIL.
P.S. Just in case: You can reset your password by clicking here<https://projects.pica8.com/forgot_password>
Reply to: tw.10.39756889.554@replies.teamwork.com







The fact exists. You also had my emails from your spam box because I am sending of them from my own mail server but with my From: field as @pica8.com one.

I think this guy had been using scripts to scan commercial domains and send out such kind of emails if the scan result is like the one of pica8.com.

The issue with pica8.com domain exists. Dmarc is another layer of protection based on spf/dkim, so end readers and their mail servers can know how to deal with emails that seemed sending from pica8.com.

Enforcing the policy needs some careful configurations, so our mails from pica8.com would not be rejected of be put into spam.

You can do it yourself  by adding TXT records to your dnsmadeeasy.com settings.

You can refer these links:

https://support.google.com/a/answer/2466580

https://docs.microsoft.com/en-us/microsoft-365/security/office-365-security/use-dmarc-to-validate-email

________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Monday, December 13, 2021 06:53
To: Aaron Shang
Cc: Yachal Chen
Subject: FW: Vulnerabilities in your site

Aaron,

This seems to be DNS oriented risk. This guy wants to ask for ransom, but I need to make sure it is worthwhile to do anything with him.

James

From: Harry style <harrystyleofficial.135@gmail.com>
Date: Sunday, December 12, 2021 at 1:50 PM
To: "support@pica8.com" <support@pica8.com>
Subject: Re: Vulnerabilities in your site

Hello,


Is there any update on this bug? I'm hoping to receive a bounty reward for responsible disclosure once your team has validated the issue.

I will be waiting for your response.

Kind Regards.

On Fri, Dec 10, 2021 at 11:53 PM Harry style <harrystyleofficial.135@gmail.com<mailto:harrystyleofficial.135@gmail.com>> wrote:
Hello Team,

As an Ethical Hacker I found some Vulnerabilities in your site few of them are as follows.


DESCRIPTION:
I just sent a forged email to my email address that appears to originate from  support@pica8.com<mailto:+support@pica8.com> I was able to do this because of the following :

DMARC record lookup and validation for    pica8.com<mailto:+bi@bio4analytics.com>

 “No DMARC Record found”
And/ OR
"DMARC Quarantine/Reject policy not enabled"

Fix:
1) Publish DMARC Record.  (If not already Published)
2)Enable DMARC Quarantine/Reject policy
3)Your DMARC record should look like
"v=DMARC1; p=reject; sp=none; pct=100; ri=86400; rua=mailto:info@domain.com<mailto:info@domain.com>"

And
As I have seen the SPF and TXT record for the      <mailto:+ember.to>  <mailto:+openbravo.com>      <mailto:+novoco.com>                      pica8.com<mailto:+bi@bio4analytics.com>          which is :

Found v=spf1 record for  <mailto:+alldone.io>   pica8.com<mailto:+pica8.com>   :
v=spf1 include:_spf.google.com<http://spf.google.com/> ~all

so valid record will look like :

Found v=spf1 record for  <mailto:+alldone.io>       pica8.com<mailto:+pica8.com>                                                                         :


v=spf1 include:_spf.google.com<http://spf.google.com/> -all

What's the issue :

What’s the issue: as u can see in the article difference between softfail and hardfail you should be using fail as Hardfail as it doesn’t allow anyone to send spoofed emails from your domains, In current SPF record you should replace (?) or
(~) with (-) at last before all , - is strict which prevents all spoofed emails except if you are sending

You can validate by testing yourself over here: mxtoolbox.com<http://mxtoolbox.com/>

This is useful in phishing, and this type of vulnerability is newsworthy (http://bits.blogs.nytimes.com/2015/04/09/sendgrid-email-breach-was-used-to-attack-coinbase-a-bitcoin-exchange/

https://medium.com/@hotbit/official-statement-notices-of-counterfeit-email-listing-hotbit-io-d1d240005d35

This can be done using any php mailer tool like this ,

<?php
$to = "VICTIM@example.com<mailto:VICTIM@example.com>";
$subject = "Password Change";
$txt = "Change your password by visiting here - [VIRUS LINK HERE]l";
$headers = "From: support@pica8.com<mailto:+support@pica8.com>";
mail($to,$subject,$txt,$headers);
?>

IMPACT:
Due to this vulnerability, any hacker can send a forged email to your customers using your domain .Thus, getting sensitive information of your customers like login details, downloading a virus/malware etc.

Also When an attacker sends an email to your customers asking them to change their password. The customer, after seeing the mail, might consider the mail as legit and falls for the trap.

In doing this the attacker can take them to his website where certain JavaScript is executed which steals the customer's session id and password.

The results can be more dangerous and impactful.

A study shows why DMARC and SPF are crucial:

 1) $1.6 million on average is what one single spear phishing attack costs for organizations
 2) $500 million every year is scammed by phishing attacks
 3) Just 3% of all users will report phishing emails to their management
 4) More than 400 businesses are targeted by BEC scams every day
 5) 76% of organizations have reported that they have been victim of a phishing attack.
 6) 1 in 3 companies have been victims of CEO fraud emails
 7) 70% of all global emails is malicious
 8) Fake invoice messages are the #1 type of phishing lure

You can find the SPF fix over here : https://www.digitalocean.com/community/tutorials/how-to-use-an-spf-record-to-prevent-spoofing-improve-e-mail-reliability


For DMARC record :   https://easydmarc.com/blog/how-to-fix-no-dmarc-record-found/

and DMARC policy here:  https://support.rackspace.com/how-to/create-a-dmarc-policy/

Let me know if you need me to send a forged email.

Note: I am expecting a bounty for this responsible disclosure and I would like to report more in the future.

Regards,
 Harry style

Snapshots
[cid:image001.png@01D7EF67.FD87BBC0]
[cid:image002.png@01D7EF67.FD87BBC0]






All of us are using that for daily usage, every commit, every build.

AmpCon development and tracking are also actually happening on that.

If you are worried about the availability, GitLab has the mirror feature that we can run main instance here in BJ and run the mirroring/shadow in cloud. The mirroring can be bidirectional in every 5 minutes. We can have a pilot.

The repo storage is the main concern. Here we have about 100GB repo  without counting backup. But I can try to split only the  main repos which can be less that 50GB.

________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Friday, December 10, 2021 09:52
To: Aaron Shang
Subject: Re: gNMI for interface counter data

Aaron,

Besides the project management, does 10.10.50.50 also handle other engineering functions? I want to evaluate the impact to the engineering team if we move it to the cloud? (ie. a new server)

Besides you, does anyone else use this server right now?

I think it is a great idea to move to this Gitlab server since most of the users are engineering, PLM, and TAC. There are a couple of other guys like Niraj or Don, but I think they don't mind using a new system. The question now is whether it is worthwhile to change?  (We are paying $50 per month for PDLC, which is about the same as an Amazon server).

James

On 12/9/21, 5:25 PM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

    You can try again.

    Found that account had been deactivated due to long time no login, then activated just now.

    Gitlab support all kinds of SSO, such as LDAP, OmniAuth/Oauth/OpenID.

    ________________________________________
    From: James Liao <james.liao@pica8.com>
    Sent: Friday, December 10, 2021 03:06
    To: Aaron Shang
    Subject: Re: gNMI for interface counter data

    Aaron,

    I tried to reset the password on 10.10.50.50, but I don't think I have any account registered. (See attached) This is probably the first challenge for our system. Is it possible we can use our SSO for the project site? (I am aware our current PDLC is not using SSO either. Something I want to fix in the future)

    James




Update, good news.

I tried with enabling kernel option CONFIG_CFS_BANDWIDTH=y, to support cgroup Limit CPU CFS (Completely Fair Scheduler).

That made docker CPU usage limitation work.

I will further help design availability/stability cases for stress docker service limitation to keep picos in good status.


________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Wednesday, December 1, 2021 08:30
To: Aaron Shang
Cc: Lin Du
Subject: Re: (PDLC) Re: Task: PicOS Docker enablement (R&D) (Cards)

I don't need a try. I know virtual box would "work", but probably cannot be a product.

I rather use Docker if we can control the CPU utilization. At this point, it is impossible to ask EdgeCore to change the CPU, and it is not likely we can create a product by leaving the risk of freezing PICOS open. So, the question gets down to "how do we protect PICOS CPU share in Docker"? If the answer is we cannot protect PICOS in this type of Intel Atom CPU, what is our option?

James





Update:

Seems this Atom CPU is not able to support this resource limit feature. :

admin@Xorplus:/udata/$ sudo docker update --cpus "0.4" c4f17034c822
Error response from daemon: NanoCPUs can not be set, as your kernel does not support CPU cfs period/quota or the cgroup is not mounted

admin@Xorplus:/udata$ sudo docker run -it --cpus "0.4" hello-world
docker: Error response from daemon: NanoCPUs can not be set, as your kernel does not support CPU cfs period/quota or the cgroup is not mounted.

admin@Xorplus:/udata$ sudo docker run -it --cpus "2" hello-world
docker: Error response from daemon: NanoCPUs can not be set, as your kernel does not support CPU cfs period/quota or the cgroup is not mounted.

But the limitation works on my PC.


I will continue to investigate the possible solution. It might be due to kernel config lacking of something ( somewhat possible, but not optimistic) or due to cgroup option(less possible).
admin@Xorplus:/udata$ mount | grep cgroup
tmpfs on /sys/fs/cgroup type tmpfs (ro,nosuid,nodev,noexec,mode=755)
cgroup2 on /sys/fs/cgroup/unified type cgroup2 (rw,nosuid,nodev,noexec,relatime,nsdelegate)
cgroup on /sys/fs/cgroup/systemd type cgroup (rw,nosuid,nodev,noexec,relatime,xattr,name=systemd)
cgroup on /sys/fs/cgroup/hugetlb type cgroup (rw,nosuid,nodev,noexec,relatime,hugetlb)
cgroup on /sys/fs/cgroup/freezer type cgroup (rw,nosuid,nodev,noexec,relatime,freezer)
cgroup on /sys/fs/cgroup/pids type cgroup (rw,nosuid,nodev,noexec,relatime,pids)
cgroup on /sys/fs/cgroup/devices type cgroup (rw,nosuid,nodev,noexec,relatime,devices)
cgroup on /sys/fs/cgroup/memory type cgroup (rw,nosuid,nodev,noexec,relatime,memory)
cgroup on /sys/fs/cgroup/cpuset type cgroup (rw,nosuid,nodev,noexec,relatime,cpuset)
cgroup on /sys/fs/cgroup/cpu,cpuacct type cgroup (rw,nosuid,nodev,noexec,relatime,cpu,cpuacct)
cgroup on /sys/fs/cgroup/blkio type cgroup (rw,nosuid,nodev,noexec,relatime,blkio)
cgroup on /sys/fs/cgroup/perf_event type cgroup (rw,nosuid,nodev,noexec,relatime,perf_event)


________________________________________
From: Aaron Shang
Sent: Wednesday, November 24, 2021 18:28
To: James Liao
Cc: Lin Du
Subject: Re: (PDLC) Re: Task: PicOS Docker enablement (R&D) (Cards)


On 11/24/21 1:54 PM, James Liao wrote:
I see what you mean. Do you know if we can assign PicOS to 2 cores and Docker container to another 2 cores?



That can be done by using `taskset` when starting the processes.

That will bind processes to assigned cores. But that cannot prevent scheduler from scheduling other tasks to these assigned cores.


Or is there a way we can limit Docker to like 40% of CPU?


Of course. We can set the maximum CPU usage such as 40% for any docker container at the starting time or update at any running time.

That's the desired and reliable means to do docker service limitation.



From: Aaron Shang <aaron.shang@pica8.com><mailto:aaron.shang@pica8.com>
Date: Tuesday, November 23, 2021 at 9:51 PM
To: James Liao <james.liao@pica8.com><mailto:james.liao@pica8.com>
Subject: Re: (PDLC) Re: Task: PicOS Docker enablement (R&D) (Cards)




I mean, we can run simple service easily, such as run a hello-world.

But when I run an CPU intensive app, such as our picos build debian docker, the load is so high that the CLI has no response.



Say this is out during the picos building in this docker in current 4630. It is not the highest. Note this 4630 has only one CPU of 4 core Atom.


admin@Xorplus> show system uptime
 05:32:31 up  3:39,  8 users,  load average: 8.50, 7.81, 4.78





This case is an extreme one. So for normal app, we can see that 4630 can run docker in parallel with PICOS.




On 11/24/21 10:28 AM, James Liao wrote:
Aaron,

Can you elaborate this statement “The performance depends on service type. I had run our picos build docker, the system soon became non-responsive.”?

From: "Aaron Shang (Pica8 Projects)" <application@teamwork.com><mailto:application@teamwork.com>
Reply-To: Pica8 Projects <tw.10.39348239.440@replies.teamwork.com><mailto:tw.10.39348239.440@replies.teamwork.com>
Date: Tuesday, November 23, 2021 at 6:26 PM
To: James Liao <james.liao@pica8.com><mailto:james.liao@pica8.com>
Subject: (PDLC) Re: Task: PicOS Docker enablement (R&D) (Cards)

===== WRITE YOUR REPLY ABOVE THIS LINE =====
[http://s3.amazonaws.com/TWFiles/376314/siteLogo/tf_69D9F41F-9ACB-E25F-59CAD900D9E43AA6.pica8_logo_nobg.png]
Nov 23
18:26

Nov 23 18:26

Aaron Shang commented on this task<https://projects.pica8.com/tasks/24526842?c=9298730>

I can confirm the docker can work on picos switches.

I took use of 7712 because that's the only box I can find not occupied.

Now I tried to borrow one 4630( both in regular testing environment) and I can run docker services on this 4630 well.

Nov 23
07:50

Nov 23 07:50

James Liao commented
@aarons We really need to create a formal document on this. Just trading email will not generate meaningful result. I was assuming by your previous message that Docker can work, but apparently it was a misunderstanding.

Furthermore, my statement that Docker is only required on switch AS4630 apparently did not get through either. I will create a draft of the document so you can add more details into it.

Nov 23
02:46

Nov 23 02:46

Aaron Shang commented

I had run several docker services on one 7712 running picos.

The performance depends on service type. I had run our picos build docker, the system soon became non-responsive.

Also the space is a major issue. Our picos build docker image is about 8GB. The default picos install will use partition 4 and 5 for rootfs and upgrade. I used the remained 50GB on this 7712 for docker overlay fs.
For low end models, there is no such storage. So only very lightweight docker services can be possible.
If we want to promote this feature, we have to warn about the possible performance penalty and storage usage.

Nov 22
19:39

Nov 22 19:39

James Liao commented
@aarons I suppose your update confirms we can run Docker in parallel to PicOS? In that case, we can close this R&D case. The next step is to create another PDLC task so we can enable the inband NICs of AS4630.

Please confirm whether we have all we need to enable Docker and add if we know any risks of enabling it.

Nov 22
00:41

Nov 22 00:41

Aaron Shang commented

I would list contents step by step.

Space issue (NOTE not to break picos upgrade)

By default docker runs aufs in /var/lib. If there is space limit issue, symbol-link it to another larger disk:



    sudo mv /var/lib/docker /home/docker

    sudo ln -sf /home/docker /var/lib/docker

What to run as docker service

Let's try one by one.

Run another FRR instance as docker service
Wireshark, possible?
NPB, Firewall, DPI, Identify control
Kubernates for orchestrating
PicOS as one of the Docker service?

In the long run, it is desirable. Docker can deal with L3 networking. How to deal with L2? TODO.
(#24526842)
Task Details

Due Date: Not set

Priority: Not set

Board Column:   CONCEPT (PLM)

Assigned To: Aaron Shang

Assigned By: James Liao

View Task: PicOS Docker enablement (R&D)<https://projects.pica8.com/tasks/24526842#comment9298730>

Task List: Cards<https://projects.pica8.com/tasklists/1932615>

Task Description:

This is an R&D project to prepare an application environment on an AmpCon switch. The goal is to enable 3-party software such as WireShark, DPI, Identity Control, etc as part of the access infrastructure.

One design consideration is the disk space. PicOS requires two partitions for upgrade consideration. Each partition is designed to hold only the PicOS image. By adding Docker, we need to find ways for additional disk storage.

Project Details

Project: PDLC<https://projects.pica8.com/projects/194478>

Company: PICA8

Copied To: James Liao

Not interested?: Stop receiving comments on this task<https://projects.pica8.com/ufen?uid=F9274DCB0A2FFA80D0F0F324EE1D1526D50637F156AB883DEE2E8289829CF470>
YOU CAN POST A REPLY TO THIS MESSAGE BY REPLYING TO THIS EMAIL.
P.S. Just in case: You can reset your password by clicking here<https://projects.pica8.com/forgot_password>
Reply to: tw.10.39348239.440@replies.teamwork.com<mailto:tw.10.39348239.440@replies.teamwork.com>






Hi, Zonezon, James,

Currently these accounts are from the default Debian rootfs. We had not done any fine tuning yet.
Most of them are for common tradition, such as using 'games' to own installed game packages, 'man' to own manpages and man-db, 'lp' for printer related jobs, 'news' for NNTP messages, etc.
To be the security paranoid these accounts can be removed, especially for dedicated OS like PICOS.

Actually these accounts are disabled now. You can check the /etc/shadow file, only 'admin' and 'operator' can be used to login. Others should be disabled.
The second filed with '*' means being disabled, '!' means locked.

Even some accounts can be enabled by setting a passwd, by default most of them are assigned /bin/false or /*bin/nologin to block logins.

For the accounts aforementioned:
    root, daemon, sync, and guest.

root is necessary although it is now usually disabled in most distributions.
guest is used for our AAA mapped users now. The actual login shell is /pica/bin/pica_sh.
the other 2 can be removed.

As for this one:
    logger:x:1002:1000:,,,:/home/logger:/bin/bash

I cannot find the release version of this system. We don't have this account in our rootfs, at least not in current master.
If it's not added by the user, it must be cracked. :(


I think we can safely remove these accounts at a quick glance:
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin


www-data is used by default for our web GUI. We didn't customize this even it is easy, and suggested.
    www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin

I think we can use 'admin' for web GUI due to the logic for that.


I am not sure now about these accounts, more tests are needed:
    nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
    ntp:x:100:103::/home/ntp:/bin/false
    radvd:x:101:65534::/var/run/radvd:/bin/false
    messagebus:x:103:105::/var/run/dbus:/bin/false

nobody user and group usually used for no-login accounts. This can be removed. But I think we had used that somewhere for some issue workarounds.
I need further investigate on this.
ntp and radvd are used for NTP and package radvd. Maybe removing them is not good idea. I need to test more.
For dbus, we can remove dbus because we are not a Desktop OS. But by a controversial design in systemd, if dbus is not installed, root privilege is needed during querying system statuses. We later added this package additionally to remove many cases of calling sudo. It can be negotiated.


These accounts should be kept:
    sshd:x:104:65534::/var/run/sshd:/usr/sbin/nologin
    systemd-timesync:x:105:109:systemd Time Synchronization,,,:/run/systemd:/bin/false
    systemd-network:x:106:110:systemd Network Management,,,:/run/systemd/netif:/bin/false
    systemd-resolve:x:107:111:systemd Resolver,,,:/run/systemd/resolve:/bin/false
    systemd-bus-proxy:x:108:112:systemd Bus Proxy,,,:/run/systemd:/bin/false

ssh daemon listens as root privilege but will at once switchs by fork to non-privileged sshd user after login for security design.
Other systemd users should keep systemd default design to reduce future maintenance.



Later you can directly send to me in CC for any system, Linux, or security concerns.


Suggested change:
- To remove all the unnecessary accounts, to the paranoid.


________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Saturday, November 13, 2021 00:13
To: Zoneson Chen; Aaron Shang
Cc: Tom Jia; TACinternal
Subject: Re: 1092 AA10G54AC - Undocumented User Accounts / Backdoors

Aaron,

Can you give Zoneson a quick analysis on this? And suggest whether we need to make any change?

James

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Friday, November 12, 2021 at 7:58 AM
To: Michael Walker <michael.walker@garlandtechnology.com>
Cc: "support@pica8.com" <support@pica8.com>, Jon McCoy <jon.mccoy@garlandtechnology.com>, Jerry Dillard <jerry.dillard@garlandtechnology.com>
Subject: Re: 1092 AA10G54AC - Undocumented User Accounts / Backdoors

Michael,

I am sorry that I do not receive a concrete answer from engineering team yet.

Thanks,

Zoneson

From: Michael Walker <michael.walker@garlandtechnology.com>
Date: Friday, November 12, 2021 at 6:46 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: support@pica8.com <support@pica8.com>, Jon McCoy <jon.mccoy@garlandtechnology.com>, Jerry Dillard <jerry.dillard@garlandtechnology.com>
Subject: Re: 1092 AA10G54AC - Undocumented User Accounts / Backdoors
Zoneson,

Have you an update for this issue?


Regards,
Michael Walker
Garland Technology
Technical Support Manager


On Wed, Nov 10, 2021 at 4:15 PM Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>> wrote:
Hi Michael,

I will consult with engineering team about this issue. Some of them are used by PICOS internally even though some could be removed. I assume that they can not be used to login except admin.

Thanks,

Zoneson
From: Michael Walker <michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>>
Date: Wednesday, November 10, 2021 at 1:55 PM
To: support@pica8.com<mailto:support@pica8.com> <support@pica8.com<mailto:support@pica8.com>>, Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>, Jon McCoy <jon.mccoy@garlandtechnology.com<mailto:jon.mccoy@garlandtechnology.com>>, Jerry Dillard <jerry.dillard@garlandtechnology.com<mailto:jerry.dillard@garlandtechnology.com>>
Subject: 1092 AA10G54AC - Undocumented User Accounts / Backdoors
Zoneson,

Garland has a customer that has an AA10G54AC to perform proof of concept testing on. One of their requirements is that the AA10G54AC cannot have any backdoors or undocumented user accounts.

Our customer has reported that when performing a cat on the /etc/passwd file he got the output below. In addition to the Admin, operator, and logger accounts there is also root, daemon, sync, and guest. Please provide an explanation of these accounts. How can we remove these accounts or render them inoperative?


admin@OVS:/etc$ cat passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
ntp:x:100:103::/home/ntp:/bin/false
radvd:x:101:65534::/var/run/radvd:/bin/false
messagebus:x:103:105::/var/run/dbus:/bin/false
sshd:x:104:65534::/var/run/sshd:/usr/sbin/nologin
systemd-timesync:x:105:109:systemd Time Synchronization,,,:/run/systemd:/bin/false
systemd-network:x:106:110:systemd Network Management,,,:/run/systemd/netif:/bin/false
systemd-resolve:x:107:111:systemd Resolver,,,:/run/systemd/resolve:/bin/false
systemd-bus-proxy:x:108:112:systemd Bus Proxy,,,:/run/systemd:/bin/false
admin:x:1000:1:admin,,,:/home/admin:/bin/bash
operator:x:1001:14:pica8,,,:/home/operator:/bin/bash
guest:x:65524:65534::/tmp:/usr/bin/guest.sh
logger:x:1002:1000:,,,:/home/logger:/bin/bashadmin@OVS:/etc$


Regards,
Michael Walker
Technical Support Manager, Garland Technology
+1-716-242-8500 Main<tel:+1-716-242-8500+Main> | +1-716-242-8491 Direct<tel:+1-716-242-8491+Direct>
michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>
https://www.garlandtechnology.com<https://www.garlandtechnology.com/support>
https://www.garlandtechnology.com/blog/how-data-diode-taps-improve-security-monitoring







The support from OpenSSL includes 4096 bit keys.


$ openssl enc -list
$ openssl ciphers
$ openssl dgst -list
$ openssl list -digest-algorithms
$ openssl list -cipher-algorithms
$ openssl list -public-key-algorithms
$ openssl list -public-key-methods


Quote also from ssh-keygen manaul:

     -b bits
             Specifies the number of bits in the key to create.  For RSA keys, the minimum size is 1024 bits and the default is
             3072 bits.  Generally, 3072 bits is considered sufficient.  DSA keys must be exactly 1024 bits as specified by FIPS
             186-2.  For ECDSA keys, the -b flag determines the key length by selecting from one of three elliptic curve sizes:
             256, 384 or 521 bits.  Attempting to use bit lengths other than these three values for ECDSA keys will fail.  ECDSA-
             SK, Ed25519 and Ed25519-SK keys have a fixed length and the -b flag will be ignored.


RSA key is one kind of commonly used key types among (rsa, dsa, ecdsa and ed25519).
Each type is used as pairs.

BTW, please guide customers not to use obsolete command "sudo service picos restart", which is provided by a helper layer and is not guaranteed in the future.
I thinks we can document that as the right way "sudo systemctl restart picos". The kind of "sudo /etc/init.d/picos restart" is also not guaranteed.

________________________________________
From: Leon Li <leon.li@pica8.com>
Sent: Wednesday, November 10, 2021 09:40
To: Mikel Tang; Zoneson Chen; Aaron Shang
Cc: tac
Subject: RE: <Mikel help>FW: Case 1072 Question about Self-signed certificate for AA

Hi Zoneson,

I will check and let you know once I finished the test.
Will get back to you next Monday at the latest.

Leon,
Thanks
From: Mikel Tang <mikel.tang@pica8.com>
Sent: Wednesday, November 10, 2021 9:19 AM
To: Zoneson Chen <zoneson.chen@pica8.com>; Leon Li <leon.li@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: tac <tac@pica8.com>
Subject: RE: <Mikel help>FW: Case 1072 Question about Self-signed certificate for AA

Hi Zoneson,

I also don’t know if openssl supports the key size 4096 bits, I will ask the engineering team to help confirm it. Add Leon & Aaron in the loop.

Hi Leon & Aaron

Would you mind helping to confirm whether openssl supports the key size 4096 bits in the 3.2.1.8 version?

Thanks

Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com<mailto:mikel.tang@pica8.com>  |  www.pica8.com<http://www.pica8.com/>

From: Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>
Sent: Wednesday, November 10, 2021 7:18 AM
To: Mikel Tang <mikel.tang@pica8.com<mailto:mikel.tang@pica8.com>>
Cc: tac <tac@pica8.com<mailto:tac@pica8.com>>
Subject: <Mikel help>FW: Case 1072 Question about Self-signed certificate for AA

Mikel,

The hardware model is as5812 and PICOS is 3.2.1.8. Does its openssl support the key size 4096 bits?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>
Date: Tuesday, November 9, 2021 at 12:36 PM
To: Michael Walker <michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>>
Cc: support@pica8.com<mailto:support@pica8.com> <support@pica8.com<mailto:support@pica8.com>>, Jon McCoy <jon.mccoy@garlandtechnology.com<mailto:jon.mccoy@garlandtechnology.com>>, Jerry Dillard <jerry.dillard@garlandtechnology.com<mailto:jerry.dillard@garlandtechnology.com>>
Subject: Re: Case 1072 Question about Self-signed certificate for AA
Hi Michael,

Thank you for providing us the steps what the customer did! Is it possible to use a browser on another host to check whether it is accepted?

I will follow the steps and see whether I can reproduce it.

I will check with engineering team whether PICOS/NPB accepts key size 4096 bits.

Thanks,

Zoneson

From: Michael Walker <michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>>
Date: Tuesday, November 9, 2021 at 11:56 AM
To: Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>
Cc: support@pica8.com<mailto:support@pica8.com> <support@pica8.com<mailto:support@pica8.com>>, Jon McCoy <jon.mccoy@garlandtechnology.com<mailto:jon.mccoy@garlandtechnology.com>>, Jerry Dillard <jerry.dillard@garlandtechnology.com<mailto:jerry.dillard@garlandtechnology.com>>
Subject: Re: Case 1072 Question about Self-signed certificate for AA
Zoneson,

Thank you for your quick response. Please see my comments in red next to your questions.

[https://ssl.gstatic.com/ui/v1/icons/mail/profile_mask2.png]
Zoneson Chen
12:31 PM (50 minutes ago)
[https://mail.google.com/mail/u/0/images/cleardot.gif]Reply
[https://mail.google.com/mail/u/0/images/cleardot.gif]
to me, support@pica8.com<mailto:support@pica8.com>, Jon, Jerry
[https://mail.google.com/mail/u/0/images/cleardot.gif]
Hi Michael,

May we know how your customer installed the SSL certificate? After browsing the Web, https://cheapsslsecurity.com/blog/how-to-install-ssl-certificate-on-lighttpd-server/ provides the instructions how to install SSL certificate to Lighttpd server. I will test it and let you know the result.

Honestly, we do not know how to clean up the changes if we do not know what your customer did. The steps you provide do not help since it only clears the OVS configurations, not SSL.

The steps the customer performed are as follows:

1) Log into the AA10G54AC
2) Select Device Settings
3) Select Web Server Settings
4) Enable HTTPS
5) Paste the SSL certificate; Certificate first then the key under the certificate.
6) Error message generated "Fail to Configure Web Server Settings configure Webserver Fail:invalid PEM file."

The steps above are based on the User Guide (see page 44). The steps have been successfully tested in our lab.

[cid:image001.png@01D7D617.03BF75B0]

The customer has not been able to log into the GUI using either http or https since this occurred.  Please note that in our lab I have been able to generate this message by pasting the key first then the certificate. In our lab I was kicked out of the GUI after getting the error message then after a few minutes able to log in. When troubleshooting with the customer last night we tried logging in using Firefox and Google Chrome. In both web browsers we cleared the cache and cookies and passwords but that did not work. In Google Chrome, we opened a tab in Incognito Mode as well and that did not work. We did a reboot after that. The problem remains.


Would deleting the pem certificate disable HTTPS?


For your second question, my understanding is that the RSA key contains CRT parameters but not private key.
Follow up questions, are there any restrictions on key size? I understand that the size can be 2048 or 4096. The default is 2048. Will the AA10G54Ac accept a key that is 4096 bytes? I ask because my customer purchased the SSL certificate and there is concern about the size as the potential problem.


 Is it possible that the browser does not connect to the Internet and fails due to being unable to be verified?
The customer can connect to the internet.


Thanks,
Zoneson

Thank you for your help.


Regards,
Michael Walker
Garland Technology
Technical Support Manager


On Tue, Nov 9, 2021 at 12:31 PM Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>> wrote:
Hi Michael,

May we know how your customer installing the SSL certificate? After browsing the Web, https://cheapsslsecurity.com/blog/how-to-install-ssl-certificate-on-lighttpd-server/ provides the instructions how to install SSL certificate to Lighttpd server. I will test it and let you the result.

Honestly, we do not know how to calean up the changes if we do not know what your customer did. The steps you provide do not help since it only clears the OVS configurations, not SSL.

For your second question, my understanding is that the RSA key contains CRT parameter but not private key. Is it possible that the browser does not connect to Internet and fails due to unable to be verified?

Thanks,

Zoneson


From: Michael Walker <michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>>
Date: Tuesday, November 9, 2021 at 7:45 AM
To: support@pica8.com<mailto:support@pica8.com> <support@pica8.com<mailto:support@pica8.com>>, Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>
Cc: Jon McCoy <jon.mccoy@garlandtechnology.com<mailto:jon.mccoy@garlandtechnology.com>>, Jerry Dillard <jerry.dillard@garlandtechnology.com<mailto:jerry.dillard@garlandtechnology.com>>
Subject: Case 1072 Question about Self-signed certificate for AA
Zoneson and Support,

I need Pica8's assistance to recover a customer's AA10G54AC. Our customer loaded a SSL certificate that generated an error message (I do not have a screenshot of the error message). Now the customer is unable to log in via the GUI using http or https. They can log in via the console. The AA10G54AC (AS5812_54x) is on firmware 3.2.1.8-4c6b5d8949.

The AA10G54AC has been rebooted and that did not resolve the issue.

I have considered restoring factory defaults by using the MOP below but I do not know if it will disable the web server allowing http login. Please advise.

Restore to Factory Default
admin@OVS$ cd /ovs
admin@OVS$ sudo rm -r *.db
admin@OVS$ sudo service picos restart

If the above procedure is not the proper way to reset the web server settings can you provide the correct steps using the console (SSH)?


A second question (originated from my customer) about the key. What is the difference between a Private Key and RSA Private Key? When they attempted to load a pem file with a RSA Private Key it failed. When they used a different certificate with a key that said Private Key it worked.


Regards,
Michael Walker
Technical Support Manager, Garland Technology
+1-716-242-8500 Main<tel:+1-716-242-8500+Main> | +1-716-242-8491 Direct<tel:+1-716-242-8491+Direct>
michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>
https://www.garlandtechnology.com<https://www.garlandtechnology.com/support>
https://www.garlandtechnology.com/blog/how-data-diode-taps-improve-security-monitoring






One is kept running shipped LEDE, an OpenWrt distribution.

Most of commercial routers and many mid-to-low end switches run some modified OpenWrt system.

You can try playing with it before we reinstall some Linux on that:

http://10.10.50.191/

root:pica8pica8

Another one is running ubuntu  21.04

ssh pica8:pica8@10.10.50.137


The vendor provided another model when I complained large box size of this hp t620.
You can also have a look:

http://item.taobao.com/item.htm?id=650033127376

It is celeron j1900:
https://ark.intel.com/content/www/us/en/ark/products/78867/intel-celeron-processor-j1900-2m-cache-up-to-2-42-ghz.html

--
Aaron






Should be caused by using 32-bit counter for OID sysUpTime


SNMPv2/v3 defaults to be 64-bit counter, SNMPv1 only supports 32-bit counter.


$ python -c "print(100*60*60*24*498)"
4302720000

$ python -c "print(2**32)"
4294967296


sysUpTime

              "The time (in hundredths of a second) since the
                      network management portion of the system was last
                      re-initialized."



https://www.alvestrand.no/objectid/1.3.6.1.2.1.1.3.html

# Solutions

1. Restart snmpd within 497 days.





2. Try to modify snmpd options as:

    OPTIONS="-LS0-2d -Lf /dev/null -p /var/run/snmpd.pid"

Current options look like: "-LSid"




On 8/19/21 10:03 AM, Mikel Tang wrote:
snmpd generates the messages when "uptime" exceeds 32 bit integer





How to know which port is on which NIC


Go to console:

    ssh pica8:pica8pica8@10.10.50.58


Run

    sudo ethtool --identify eno4

Then the 2 lights would keep blinking .... Ctrl+C to abort ....


FYI:


On- board PIC card:
01:00.0 Ethernet controller: Broadcom Inc. and subsidiaries NetXtreme BCM5720 Gigabit Ethernet PCIe
01:00.1 Ethernet controller: Broadcom Inc. and subsidiaries NetXtreme BCM5720 Gigabit Ethernet PCIe
02:00.0 Ethernet controller: Broadcom Inc. and subsidiaries NetXtreme BCM5720 Gigabit Ethernet PCIe
02:00.1 Ethernet controller: Broadcom Inc. and subsidiaries NetXtreme BCM5720 Gigabit Ethernet PCIe

PCI Slot 1:
06:00.0 Ethernet controller: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller (rev 07)
07:00.0 Ethernet controller: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller (rev 07)
08:00.0 Ethernet controller: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller (rev 07)
09:00.0 Ethernet controller: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller (rev 07)
Integrated:
43:00.0 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)
43:00.1 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)
43:00.2 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)
43:00.3 Ethernet controller: Intel Corporation I350 Gigabit Network Connection (rev 01)


1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host
       valid_lft forever preferred_lft forever

2: enp6s0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:40:7e brd ff:ff:ff:ff:ff:ff
    inet6 fe80::1efd:8ff:fe70:407e/64 scope link
       valid_lft forever preferred_lft forever
3: enp7s0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:40:7f brd ff:ff:ff:ff:ff:ff
    inet6 fe80::1efd:8ff:fe70:407f/64 scope link
       valid_lft forever preferred_lft forever
4: enp8s0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:40:80 brd ff:ff:ff:ff:ff:ff
5: enp9s0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc pfifo_fast state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:40:81 brd ff:ff:ff:ff:ff:ff

Built-in:
6: eno1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
    link/ether b8:2a:72:db:5d:06 brd ff:ff:ff:ff:ff:ff
    inet 10.10.50.58/24 brd 10.10.50.255 scope global dynamic eno1
       valid_lft 42663sec preferred_lft 42663sec
    inet6 fe80::ba2a:72ff:fedb:5d06/64 scope link
       valid_lft forever preferred_lft forever
7: eno2: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether b8:2a:72:db:5d:07 brd ff:ff:ff:ff:ff:ff
8: eno3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
    link/ether b8:2a:72:db:5d:08 brd ff:ff:ff:ff:ff:ff
    inet6 fe80::ba2a:72ff:fedb:5d08/64 scope link
       valid_lft forever preferred_lft forever
9: eno4: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether b8:2a:72:db:5d:09 brd ff:ff:ff:ff:ff:ff

10: enp67s0f0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:12:18 brd ff:ff:ff:ff:ff:ff
11: enp67s0f1: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:12:19 brd ff:ff:ff:ff:ff:ff
12: enp67s0f2: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:12:1a brd ff:ff:ff:ff:ff:ff
13: enp67s0f3: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 1c:fd:08:70:12:1b brd ff:ff:ff:ff:ff:ff

14: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:54:96:b9:8d brd ff:ff:ff:ff:ff:ff
    inet 172.17.0.1/16 brd 172.17.255.255 scope global docker0
       valid_lft forever preferred_lft forever

Through this docker0 docker bridge, hundreds of docker instances can also be run with its own nic for each.

The `enXXXX` naming is the new Linux kernel naming scheme for PCI devices, en is for Ethernet, wl is for wireless LAN.

You can force to change them by using special udev rules, but that is not suggested due to unpredictable issues.


Scheme	Description	Example
1 	Device names incorporate firmware or BIOS-provided index numbers for onboard devices. If this information is not available or applicable, udev uses scheme 2. 	eno1
2 	Device names incorporate firmware or BIOS-provided PCI Express (PCIe) hot plug slot index numbers. If this information is not available or applicable, udev uses scheme 3. 	ens1
3 	Device names incorporate the physical location of the connector of the hardware. If this information is not available or applicable, udev uses scheme 5. 	enp2s0
4 	Device names incorporate the MAC address. Red Hat Enterprise Linux does not use this scheme by default, but administrators can optionally use it. 	enx525400d5e0fb
5 	The traditional unpredictable kernel naming scheme. If udev cannot apply any of the other schemes, the device manager uses this scheme. 	eth0









If there is existing one, it's good to have the URL or access location.



I had been using ansible for a long time to maintain boxes and servers here for util installation and keeping hosts sync.

For potential use case of this project, I assume this type of workflow:

http://10.10.50.50/solution/automation/-/blob/master/server/deploy_switch.py#L465


    pica_sh -c "configure;execute /home/admin/auto.config;commit"

Or

    pica_sh -- -c "configure exclusive;load override /pica/bin/pica_default.boot;load merge CONFIG-FILE;commit"


--
Aaron

From: James Liao <james.liao@pica8.com>
Sent: Tuesday, July 7, 2020 14:19
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Yachal Chen <yachal.chen@pica8.com>; Lin Du <lin.du@pica8.com>
Subject: Ansible project?

Aaron,

I see your update on the Ansible PDLC task. Are you still having issues in running Ansible on PICOS? We have a training video, made by Mani, to show how to run Ansible to automate PICOS tasks. Do you need the video?

James






All these commands are needed if they want to use new longer size keys for each algorithms.
The files in my examples are using the existing default location, and prompts whether to override the existing ones.

On N30/N31 series with squashfs, these files can not be saved on flash.
So in this case, another location of permanent storage of new generated keys might be a choice. Then the `sshd_config` must be changed to use new key locations, and restarting of sshd is needed then. The connected sessions would keep running without break.



That can be done via an ssh session. The connected session would keep running.
That will take effect next time connections be created.
No restart of SSHD is needed, since no sshd_config had been changed.
But since the keys had been changed, the next time when the session is connected from the same host, there would be fingerprint change prompt to highlight possible MITM attact.





--
Aaron

From: Hai Vo-Dinh <hai.vodinh@pica8.com>
Sent: Wednesday, July 8, 2020 10:39
To: Aaron Shang <aaron.shang@pica8.com>; Niraj Jain <niraj.jain@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>; plm@pica8.com <plm@pica8.com>; TACinternal <tacinternal@pica8.com>
Subject: RE: open vulnerabilities - 3.6.3

Hi Aaron,

In the three examples that you gave, Infosys would just need to pick one?  Or would they need to do all three.

For example, if Infosys choose RSA 4096, then they would just have to issue this command on each of the switches, right?

# ssh-keygen -N '' -f /etc/ssh/ssh_host_rsa_key -t rsa -b 4096

I also have the following questions:
1.	Can they do this via an ssh session?
2.	After they issue the command above, the ssh client will not be kicked off?
3.	What will they need to do to have the new key take effect?
a.	Will they need to restart sshd for the new key to take effect,
b.	or is there a command to get sshd to use the new key without restarting?
4.	Do they have to do anything else? Save anything?
5.	On the N3000 Series switches with NAND flash, do they have to do anything special to have the new key saved?  Will they need to issue the “copy running_config startup_config”

Please respond ASAP, as Infosys will ask for this tonight.

Thanks a lot,
Hai

From: Aaron Shang <aaron.shang@pica8.com>
Sent: Tuesday, July 7, 2020 11:31 AM
To: Niraj Jain <niraj.jain@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; plm@pica8.com; TACinternal <tacinternal@pica8.com>
Subject: Re: open vulnerabilities - 3.6.3


That can be done by re-generating the keys, using the same name as in sshd_config, while without touching contents of sshd_config file.

The following are to generate the strong enough available keys within the system.


# ssh-keygen -N '' -f /etc/ssh/ssh_host_dsa_key -t dsa

Generating public/private dsa key pair.
Your identification has been saved in /etc/ssh/ssh_host_dsa_key
Your public key has been saved in /etc/ssh/ssh_host_dsa_key.pub
The key fingerprint is:
SHA256:IlN+4Yu88qaPvQY+A5aNCzXBzuwPa1JsRe3LA4kg9JU root@picos
The key's randomart image is:
+---[DSA 1024]----+
|.o   o.          |
|o + oE.          |
|.= = o. .        |
|  B +o.. .       |
| + *ooo.S        |
|. @ o+++ .       |
| = B .o..        |
|. + *oo.         |
| o  oX*.         |
+----[SHA256]-----+

# ssh-keygen -l -f /etc/ssh/ssh_host_dsa_key
1024 SHA256:dfEvBdOraYekXoxuMxeZHKRQqurK5sd+GybNg9PZViE root@picos (DSA)


# ssh-keygen -N '' -f /etc/ssh/ssh_host_rsa_key -t rsa -b 4096
Generating public/private rsa key pair.
/etc/ssh/ssh_host_rsa_key already exists.
Overwrite (y/n)? y
Your identification has been saved in /etc/ssh/ssh_host_rsa_key
Your public key has been saved in /etc/ssh/ssh_host_rsa_key.pub
The key fingerprint is:
SHA256:bLmp3jpMm5l89NYIcTUjlxH7KvjJ44WuGbnSLM8LC9g root@picos
The key's randomart image is:
+---[RSA 4096]----+
|            o+   |
|          . *.   |
|           +.o   |
|       ....  .   |
|        So    .  |
|   o  ..o= . .   |
|  . E+.O*oooo    |
|     .@*+B=+.    |
|     .=BO=*.     |
+----[SHA256]-----+

# ssh-keygen -l -f /etc/ssh/ssh_host_rsa_key
4096 SHA256:bLmp3jpMm5l89NYIcTUjlxH7KvjJ44WuGbnSLM8LC9g root@picos (RSA)

# ssh-keygen -N '' -f /etc/ssh/ssh_host_ed25519_key -t ed25519
Generating public/private ed25519 key pair.
/etc/ssh/ssh_host_ed25519_key already exists.
Overwrite (y/n)? y
Your identification has been saved in /etc/ssh/ssh_host_ed25519_key
Your public key has been saved in /etc/ssh/ssh_host_ed25519_key.pub
The key fingerprint is:
SHA256:Ir6+VwKMlJ3KYhmipDowDpdgcasuqdENvmRL1lLn07Y root@picos
The key's randomart image is:
+--[ED25519 256]--+
| ..+ .           |
|o++ +            |
|*+o*             |
|BoB o            |
|*=. o.o S        |
|+= * +.o.        |
|+oO + ooo        |
|o* + ..o .       |
|. o.+o  E        |
+----[SHA256]-----+

# ssh-keygen -l -f /etc/ssh/ssh_host_ed25519_key
256 SHA256:Ir6+VwKMlJ3KYhmipDowDpdgcasuqdENvmRL1lLn07Y root@picos (ED25519)

# ssh-keygen -N '' -f /etc/ssh/ssh_host_ecdsa_key -t ecdsa -b 521
Generating public/private ecdsa key pair.
/etc/ssh/ssh_host_ecdsa_key already exists.
Overwrite (y/n)? y
Your identification has been saved in /etc/ssh/ssh_host_ecdsa_key
Your public key has been saved in /etc/ssh/ssh_host_ecdsa_key.pub
The key fingerprint is:
SHA256:OjlUe7lH7gC5i0UQKO+hZHLaElu2eFYJEdvOfRRU32o root@picos
The key's randomart image is:
+---[ECDSA 521]---+
|  oo ...o..      |
|  oo.  . . . .   |
|  .+... o   . .  |
|o *o=. + o . .   |
| & =o.o S o E    |
|= * .. = + =     |
| +    = o o o    |
|       = . +     |
|      . .   .    |
+----[SHA256]-----+

# ssh-keygen -l -f /etc/ssh/ssh_host_ecdsa_key
521 SHA256:OjlUe7lH7gC5i0UQKO+hZHLaElu2eFYJEdvOfRRU32o root@picos (ECDSA)



BTW, actually we had security issue from the beginning: we keep using the same keys at the time initiating the rootfs. The correct means is to generate them for each new install.
I planned to fix that soon. There had been customers from Berlin complained this before.


--
Aaron

From: Niraj Jain <niraj.jain@pica8.com>
Sent: Tuesday, July 7, 2020 13:31
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Re: open vulnerabilities - 3.6.3

Aaron,
We shared this information with Infosys last week.  They would like to move forward with the fix for the SSH key length.  Please let me know how we can achieve this on their current installation, which is running PICOS 3.6.3.

Thanks,
Niraj

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 1, 2020 at 9:08 AM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>, Tom Jia <tom.jia@pica8.com>, Lin Du <lin.du@pica8.com>
Cc: Niraj Jain <niraj.jain@pica8.com>
Subject: Re: open vulnerabilities - 3.6.3


For openssh-server release:

3.6.x          : 6.7p1-5

2.x:             : 6.6p1-4

We always keep latest available official security patches updated for our releases.

In all 3.x, the latest is 6.7p1-5+deb8u8, I will ensure lasted patches into releases. It can be expected as only increasing the last bit: 6.7p1-5+deb8uX.

In all 2.x, the latest was 6.6p1-4~bpo70+1, which was backported from Debian 8, and ceased to update after 2018.

Debian 7 security updates ended regular patches in April 2016, ended LTS in May 2018, ended commercial service in June 2020.
Debian 8 security updates ended regular patches in June 2018, ended LTS in June 2020, with no commercial service committed.
See:
https://wiki.debian.org/LTS


As for the mentioned Solutions, the releases can meet in Debian 10 : 7.9p1-10

If we want to manually upgrade to 7.x on current 3.x(Debian 8), it may work but in most cases that would break other parts of the OS.


----

For the higher level issue: SSH Server Public Key Too Small

DSA keys and RSA keys shorter than 2048 bits are considered vulnerable. It is recommended to install a RSA public key length of at least 2048 bits or greater, or to switch to ECDSA or EdDSA.


The OS can provide or support a large range of key length as capabilities and the actual length is decided according to server-client negaciotion.

Of cause we can limit only key length longer than 2048 enabled in OS.

I will try to set only RSA 2048+, ed25519, ecdsa sha2 nistp256 keys in PICOS 3.x.


--
Aaron

From: Hai Vo-Dinh <hai.vodinh@pica8.com>
Sent: Wednesday, July 1, 2020 13:23
To: Aaron Shang <aaron.shang@pica8.com>; Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>
Cc: Niraj Jain <niraj.jain@pica8.com>
Subject: FW: open vulnerabilities - 3.6.3

Hi Aaron,

Would you please review the result of the scan by Infosys.  They are all OpenSSH related.  Please let us know how we would address these.  What version of OpenSSH are we currently at in 3.6.2?

Thanks,
Hai

From: Vibin Venugopal <Vibin_Venugopal@infosys.com>
Sent: Tuesday, June 30, 2020 5:05 AM
To: Niraj Jain <niraj.jain@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Santhosh Byreddy <santhosh.byreddy@infosys.com>; Ashwin Shetty <ashwin.shetty@infosys.com>
Subject: open vulnerabilities - 3.6.3

Hi Niraj/Hai,

Attached are the vulnerabilities detected by our security audit team.
We need to get this fixed urgently.

This needs to be fixed before we can go live.

Regards,
Vibin Venugopal
+91 8884417717








Since Mikel got the root cause, I found that adding line

        session    optional   pam_motd.so

to ANY one of file

    common-auth

Or

    common-account

in dir /etc/pam.d, can solve the issue.


I will file a bug to Vic/Ryan to decide which file to add the pam_motd line, they made the tacacs part.

We also need to add cases to cover banner showing for tacacs auth situations. 🙂


Tong, I will file a bug with SQA assigned to you.




--
Aaron

From: Mikel Tang <mikel.tang@pica8.com>
Sent: Thursday, July 2, 2020 14:27
To: Zoneson Chen <zoneson.chen@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: RE: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Zoneson,

I have confirmed that this issue will occur if TACACS is configured, the below configuration from Garigill:
    aaa {
        tacacs-plus {
            disable: false
            authorization: true
            accounting: true
            key: "keystring"
            port-number: 49
            auth-type: "ascii"
            timeout: 5
        }
        radius {
            authorization {
                disable: true
            }
            accounting {
                disable: true
            }
        }
        local {
            disable: false
        }
        local-auth-fallback {
            disable: false
        }
}

Thanks

Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 2:19 PM
To: Aaron Shang <aaron.shang@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Aaron,

In this case, the banner has been saved in PICOS configuration file and /etc/motd correctly. The strange thing is that login does not show the banner.

According to your description about pam_motd, I thought that PICOS would use pam in some condition. It looks like that it is my misunderstanding. This misunderstanding makes me thinking whether it relates to TACACS.

Thanks,

Zoneson



From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 1, 2020 at 11:01 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi, Zoneson,

I think it is rare case for dynamic file flushed the /etc/motd contents.

I checked our releases, the pam_motd module has no options `motd=` added.

Another source of dynamic motd contents would be generated by `/etc/update-motd*` scripts in many modern systems.
But in our releases, we did not include these scripts.


So only /etc/motd would be showed, if pam_motd module had not been disabled in /etc/pam.d/ssh or /etc/pam.d/login.



--
Aaron

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 13:45
To: Aaron Shang <aaron.shang@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Aaron,

Does the system switch to dynamic motd whenever TACACS has been enabled? If it is not TACACS, how to switch motd to dynamic?

Mikel,

Would you mind helping to verify it if Aaron confirms that TACACS will change login from static motd to dynamic motd?

Thanks,

Zoneson

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 1, 2020 at 10:29 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi, Zoneson,

Please ignore that if it doesn't exist, they are generated for dynamic motd contents.


By default, motd file is
/etc/motd

That default file can be changed by using `MOTD_FILE' option in /etc/login.defs:
#MOTD_FILE      /etc/motd:/usr/lib/news/news-motd

In systems using PAM, that login.defs option would not work. Instead, an option to pam_motd.so as `motd=/run/motd.dynamic` would append the contents after default motd file contents.

The dynamic contents will update each time motd is started.
But it is OK without the file.



--
Aaron

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 12:30
To: Aaron Shang <aaron.shang@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Aaron,

I could not find /var/run/motd.d* in v3.6.2. Would you mind double checking it?

admin@hopkinslabsdn2-lcs:/var/run$ ls
blkid            lighttpd          rsyslogd.pid        sshd.pid    usermap
crond.pid     lock               run                         systemd     utmp
crond.reboot  log             sendsigs.omit.d  tmpfiles.d  xorp_rtrmgr.pid
initctl       network            shm                        udev
initramfs     openvpn       sshd                       user

Thanks,

Zoneson

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 1, 2020 at 8:10 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Since that happened only in 1 out of 4 instances, it should be single case issue.


       The contents of /etc/motd are displayed by pam_motd(8) after a successful login but just before it executes the login shell.

The following settings will impact the motd showing.

Please check them all.


----
This controls moth showing for SSH connection.
Commenting that line will disable showing.

    /etc/pam.d/sshd
    #    session    optional     pam_motd.so # [1]



----
This controls moth showing for console login:
Commenting that line will disable showing.

    /etc/pam.d/login
    #session    optional   pam_motd.so
----
These files control the contents for showing:
/var/run/motd.d*

--
Aaron

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 09:35
To: Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Mikel,

We instructed Dinesh to configure login banner as:

$ cli -c 'configure; set system login announcement "
By pressing any key, you are entering property owned by Cargill,
Incorporated or its affiliated companies (Cargill). If you are
ot an authorized user of the Cargill Network, you should leave it
immediately. Access to and use of the Cargill Network, including any
software which may be accessed through such Network, are governed by
the policies and procedures implemented by Cargill, which may be
changed by Cargill at any time. Cargill expressly reserves the right
to access, monitor, read, copy, print and/or disclose any e-mail,
electronic files or other computer records created, received and/or
stored through your use of the Cargill Network.
"; commit; exit'

For some reason, one of the switches (one out of four) does not show the banner. According to Dinesh, the banner was saved in the PICOS configuration file and /etc/motd. Here are my suspicions, but the problem is caused by them.

1.      The banner exceeds the size of the PICOS buffer.
a.       I double the message and could not cause the problem.
2.      There exist special characters.
a.       I added “~!@#$%^&*()_+ `-=}[]:<>?,./|”, but it is fine.
b.      CLI fails by complaining, \ and single and double quotations. They are right.
3.      I suspected that the motd function has been disabled accidently, but it looks like that I cannot change it.
a.       $ sudo systemctl start dotd

It looks like that it is controlled by /pica/bin/system/pica_login process. It looks like that there are no bugs related to it. Have you met it before?

Would you mind asking developers whether they know it and how to resolve it? Does reboot resolve it?

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 1:50 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

Find the attachment from sdn2-lcs

Thanks,
Dinesh Kolan

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Wednesday, July 01, 2020 3:41 PM
To: DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>; Mani Subramanian <mani.subramanian@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: support@pica8.com
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Dinesh,

I could not reproduce this problem so far!

Would you mind forwarding this /etc/motd to us to verify it?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Wednesday, July 1, 2020 at 12:25 PM
To: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch

Hi Dinesh,

/etc/motd looks fine to me! We will do more tests to verify it and let you know how to resolve it!

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 12:20 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

I have changed the banner to multiple line banner and now find the requested output. Other switches have the same output but still working fine.

Let me know what should I be trying to get this working.



Thanks,
Dinesh Kolan

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Wednesday, July 01, 2020 1:59 PM
To: DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>; Mani Subramanian <mani.subramanian@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Hi Dinesh,

I do not know what caused this problem. According to my understanding, PICOS announcement mechanism is based on Linux “message of the day”.

Would you mind providing us the outputs of the following commands?

1.      $ ls -l /etc/motd
2.      $ cat /etc/motd

Potentially, we need to remove /etc/motd and reboot the system to make it working properly.

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 8:18 AM
To: Mani Subramanian <mani.subramanian@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

Team,

I was able to add multiple line banner from shell and saw it at login on 3 switches but not on the sdn2-lcs. Switch sdn2-lcs isn’t displaying a banner even if it’s a single line configured from the config mode. Multiple lines when added, its showing up in the running configuration but not displaying at the login. See below output. Also attaching the tech-support file.



Thanks,
Dinesh Kolan

From: DINESH KOLAN (CRGL-THIRDPARTY.COM)
Sent: Tuesday, June 30, 2020 6:05 PM
To: 'Mani Subramanian' <mani.subramanian@pica8.com>; 'Zoneson Chen' <zoneson.chen@pica8.com>; 'Jeff Herman' <jeff.herman@pica8.com>; 'Hai Vo-Dinh' <hai.vodinh@pica8.com>
Subject: RE: Cargill: UDLD troubleshooting

Find the attached UDLD logs file. Let me know if you find anything related to why the interfaces were UDLD disabled.

Thanks,
Dinesh Kolan

From: DINESH KOLAN (CRGL-THIRDPARTY.COM)
Sent: Tuesday, June 30, 2020 3:17 PM
To: Mani Subramanian <mani.subramanian@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: DHCP relay troubleshooting meeting follow-up

Mani,

Find the attached logs after making the below changes.

•         OSPF export policy is still not clear and I did not get that error this time when I replicated the below scenario.
•         I still have the UDLD enabled globally. You suggested to disable the UDLD on the peer-links. What if we actually want to monitor them too?
•         We have setups at some sites with just single switch active as both L3 and also the access switch. How to setup the DHCP snooping in that case?
•         How to add a login banner with multiple lines?
•         There was always a login user “admin”. Can’t this be used when the TACACS+ fails? I don’t see this user info in the configuration.
o    But have seen an user profile names “operator” with read-only class. When can this be used and what is the password set for it? The configuration showed plan-text encrypted
o    Are the custom local login credentials different from the default eth0/console credentials?

Thanks,
Dinesh Kolan

From: Mani Subramanian <mani.subramanian@pica8.com>
Sent: Monday, June 29, 2020 4:27 PM
To: Zoneson Chen <zoneson.chen@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Subject: Re: Cargill: DHCP relay troubleshooting meeting follow-up


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Hi Dinesh,

During last Friday meeting we noticed few problems and you had few questions on OSPF. I’m addressing the problems and your OSPF questions in this email. We have analyzed the output file you have emailed us on Friday.

Please update the Spine switch configuration based on following recommendations and test. After the configuration changes, email us the latest config for spine and leaf switches. Also please send us output for mlag consistency-parameter summary CLI on both spine switches.

I will set up a follow-up call tomorrow Jun 30 at 4 PM CST. We will check whether all features you have configured are working properly.

1.      Uplink configuration (link connected to  Cisco router):
In our PVST design if a VLAN is not configured with PVST it is put in the blocking state by default.   Since this is a host port (not connected to another spanning tree bridge), there is no need to configure spanning tree on this port. Vlan21 is blocked on this port if PVST is not configured, so we need to enable manual-forwarding on this port, in item b given below.

a.       Remove pvst config on vlan 21 ( other vlans such as  22) as follows on both spines: delete protocols spanning-tree pvst vlan 21
b.      Configure forwarding port for Rapid-PVST+ mode on both spines as follows:
set protocols spanning-tree pvst interface te-1/1/11 manual-forwarding true

2.      MLAG consistency check CLI data and configuration corrections needed:
Last week you have executed the CLI show mlag consistency-parameter summary and provided us the data. We have found few MLAG configuration problems. Please correct the following problems:
a.      Configure same spanning tree parameters on both spine switches: Bridge priority need to be consistent between the two spines, as the two nodes are virtualized as one switch.  In fact, all parameters must be the same. Please correct this part of configuration.
b.      Remove DHCP snooping configuration in Spines: Typically our customers configure DHCP relay on L3 interfaces and DHCP snooping on L2 interfaces. Currently either DHCP snooping or DHCP relay can be configured on MLAG in spine switches. Configuring both DHCP snooping and DHCP relay on the spines is currently not supported.

Hence remove DHCP snooping configuration in the Spines.
3.      OSPF CLI related questions:
a.       set policy policy-statement connected-nw then CLI is configured. Does the default accept or reject? Default is accept.
b.      set policy policy-statement connected-nw then accept  CLI. Does this include only OSPF routes or does it include both OSPF and static routes?  This policy configuration only affect external routes configured above this CLI  (BGP, RIP, Static, connected, etc.). It includes routes external to OSPF.

4.      OSPF restart CLIs similar to Cisco IOS: Do you have a command to restart OSPF process similar to executing the following commands under Cisco IOS OSPF config: shut and no shut.

We do not have a similar mechanism in PICOS. However, the same effect can be achieved in PICOS by deleting the OSPF configuration and rollback the change. To do this issue the following CLI commands:

delete protocols ospf4
commit
rollback 1
commit

5.      OSPF related issue: We noticed the following OSPF error during our meeting:
Command failed: create_term failed: PolicyException from line 55 of policy_statement.cc: Term already present in position: 4294967298 4294967299

We tried to reproduce the problem  in our lab unsuccessfully. We took the following steps:


admin@P8 # set protocols static route 0.0.0.0/0 next-hop 10.31.83.98
admin@P8 # commit
admin@P8 # set policy policy-statement connected-nw term 3 from protocol "static"
admin@P8 # set policy policy-statement connected-nw term 3 then accept
admin@P8 # commit
admin@P8 # delete policy policy-statement connected-nw term 3

If you can reproduce the problem, provide us the steps. Run the following CLI: set policy traceoptions flag all disable false, trigger the problem and  provide us the associated logs.

Thanks,
Mani

Mani Subramanian
Pica8, Inc.
Mobile:   +1 408 203 0287
E :  mani.subramanian@pica8.com | I:  www.pica8.com


From: mani.subramanian@pica8.com
When: 1:00 PM - 2:00 PM June 26, 2020
Subject: Cargill: DHCP relay troubleshooting
Location: Webex


Hi Dinesh,


https://meetings.webex.com/collabs/#/meetings/detail?uuid=M60DD4U0SAD1D68MFDYIDT99PP-50V7&rnd=232620.37068



Best,
Mani




Hi, Zoneson,

I think it is rare case for dynamic file flushed the /etc/motd contents.

I checked our releases, the pam_motd module has no options `motd=` added.

Another source of dynamic motd contents would be generated by `/etc/update-motd*` scripts in many modern systems.
But in our releases, we did not include these scripts.


So only /etc/motd would be showed, if pam_motd module had not been disabled in /etc/pam.d/ssh or /etc/pam.d/login.



--
Aaron

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 13:45
To: Aaron Shang <aaron.shang@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Aaron,

Does the system switch to dynamic motd whenever TACACS has been enabled? If it is not TACACS, how to switch motd to dynamic?

Mikel,

Would you mind helping to verify it if Aaron confirms that TACACS will change login from static motd to dynamic motd?

Thanks,

Zoneson

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 1, 2020 at 10:29 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi, Zoneson,

Please ignore that if it doesn't exist, they are generated for dynamic motd contents.


By default, motd file is
/etc/motd

That default file can be changed by using `MOTD_FILE' option in /etc/login.defs:
#MOTD_FILE      /etc/motd:/usr/lib/news/news-motd

In systems using PAM, that login.defs option would not work. Instead, an option to pam_motd.so as `motd=/run/motd.dynamic` would append the contents after default motd file contents.

The dynamic contents will update each time motd is started.
But it is OK without the file.



--
Aaron

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 12:30
To: Aaron Shang <aaron.shang@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Aaron,

I could not find /var/run/motd.d* in v3.6.2. Would you mind double checking it?

admin@hopkinslabsdn2-lcs:/var/run$ ls
blkid            lighttpd          rsyslogd.pid        sshd.pid    usermap
crond.pid     lock               run                         systemd     utmp
crond.reboot  log             sendsigs.omit.d  tmpfiles.d  xorp_rtrmgr.pid
initctl       network            shm                        udev
initramfs     openvpn       sshd                       user

Thanks,

Zoneson

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 1, 2020 at 8:10 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Since that happened only in 1 out of 4 instances, it should be single case issue.


       The contents of /etc/motd are displayed by pam_motd(8) after a successful login but just before it executes the login shell.

The following settings will impact the motd showing.

Please check them all.


----
This controls moth showing for SSH connection.
Commenting that line will disable showing.

    /etc/pam.d/sshd
    #    session    optional     pam_motd.so # [1]



----
This controls moth showing for console login:
Commenting that line will disable showing.

    /etc/pam.d/login
    #session    optional   pam_motd.so
----
These files control the contents for showing:
/var/run/motd.d*

--
Aaron

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 09:35
To: Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Mikel,

We instructed Dinesh to configure login banner as:

$ cli -c 'configure; set system login announcement "
By pressing any key, you are entering property owned by Cargill,
Incorporated or its affiliated companies (Cargill). If you are
ot an authorized user of the Cargill Network, you should leave it
immediately. Access to and use of the Cargill Network, including any
software which may be accessed through such Network, are governed by
the policies and procedures implemented by Cargill, which may be
changed by Cargill at any time. Cargill expressly reserves the right
to access, monitor, read, copy, print and/or disclose any e-mail,
electronic files or other computer records created, received and/or
stored through your use of the Cargill Network.
"; commit; exit'

For some reason, one of the switches (one out of four) does not show the banner. According to Dinesh, the banner was saved in the PICOS configuration file and /etc/motd. Here are my suspicions, but the problem is caused by them.

1.	The banner exceeds the size of the PICOS buffer.
a.	I double the message and could not cause the problem.
2.	There exist special characters.
a.	I added “~!@#$%^&*()_+ `-=}[]:<>?,./|”, but it is fine.
b.	CLI fails by complaining, \ and single and double quotations. They are right.
3.	I suspected that the motd function has been disabled accidently, but it looks like that I cannot change it.
a.	$ sudo systemctl start dotd

It looks like that it is controlled by /pica/bin/system/pica_login process. It looks like that there are no bugs related to it. Have you met it before?

Would you mind asking developers whether they know it and how to resolve it? Does reboot resolve it?

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 1:50 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

Find the attachment from sdn2-lcs

Thanks,
Dinesh Kolan

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Wednesday, July 01, 2020 3:41 PM
To: DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>; Mani Subramanian <mani.subramanian@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: support@pica8.com
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Dinesh,

I could not reproduce this problem so far!

Would you mind forwarding this /etc/motd to us to verify it?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Wednesday, July 1, 2020 at 12:25 PM
To: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch

Hi Dinesh,

/etc/motd looks fine to me! We will do more tests to verify it and let you know how to resolve it!

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 12:20 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

I have changed the banner to multiple line banner and now find the requested output. Other switches have the same output but still working fine.

Let me know what should I be trying to get this working.



Thanks,
Dinesh Kolan

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Wednesday, July 01, 2020 1:59 PM
To: DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>; Mani Subramanian <mani.subramanian@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Hi Dinesh,

I do not know what caused this problem. According to my understanding, PICOS announcement mechanism is based on Linux “message of the day”.

Would you mind providing us the outputs of the following commands?

1.	$ ls -l /etc/motd
2.	$ cat /etc/motd

Potentially, we need to remove /etc/motd and reboot the system to make it working properly.

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 8:18 AM
To: Mani Subramanian <mani.subramanian@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

Team,

I was able to add multiple line banner from shell and saw it at login on 3 switches but not on the sdn2-lcs. Switch sdn2-lcs isn’t displaying a banner even if it’s a single line configured from the config mode. Multiple lines when added, its showing up in the running configuration but not displaying at the login. See below output. Also attaching the tech-support file.



Thanks,
Dinesh Kolan

From: DINESH KOLAN (CRGL-THIRDPARTY.COM)
Sent: Tuesday, June 30, 2020 6:05 PM
To: 'Mani Subramanian' <mani.subramanian@pica8.com>; 'Zoneson Chen' <zoneson.chen@pica8.com>; 'Jeff Herman' <jeff.herman@pica8.com>; 'Hai Vo-Dinh' <hai.vodinh@pica8.com>
Subject: RE: Cargill: UDLD troubleshooting

Find the attached UDLD logs file. Let me know if you find anything related to why the interfaces were UDLD disabled.

Thanks,
Dinesh Kolan

From: DINESH KOLAN (CRGL-THIRDPARTY.COM)
Sent: Tuesday, June 30, 2020 3:17 PM
To: Mani Subramanian <mani.subramanian@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: DHCP relay troubleshooting meeting follow-up

Mani,

Find the attached logs after making the below changes.

•	OSPF export policy is still not clear and I did not get that error this time when I replicated the below scenario.
•	I still have the UDLD enabled globally. You suggested to disable the UDLD on the peer-links. What if we actually want to monitor them too?
•	We have setups at some sites with just single switch active as both L3 and also the access switch. How to setup the DHCP snooping in that case?
•	How to add a login banner with multiple lines?
•	There was always a login user “admin”. Can’t this be used when the TACACS+ fails? I don’t see this user info in the configuration.
o	But have seen an user profile names “operator” with read-only class. When can this be used and what is the password set for it? The configuration showed plan-text encrypted
o	Are the custom local login credentials different from the default eth0/console credentials?

Thanks,
Dinesh Kolan

From: Mani Subramanian <mani.subramanian@pica8.com>
Sent: Monday, June 29, 2020 4:27 PM
To: Zoneson Chen <zoneson.chen@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Subject: Re: Cargill: DHCP relay troubleshooting meeting follow-up


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Hi Dinesh,

During last Friday meeting we noticed few problems and you had few questions on OSPF. I’m addressing the problems and your OSPF questions in this email. We have analyzed the output file you have emailed us on Friday.

Please update the Spine switch configuration based on following recommendations and test. After the configuration changes, email us the latest config for spine and leaf switches. Also please send us output for mlag consistency-parameter summary CLI on both spine switches.

I will set up a follow-up call tomorrow Jun 30 at 4 PM CST. We will check whether all features you have configured are working properly.

1.	Uplink configuration (link connected to  Cisco router):
In our PVST design if a VLAN is not configured with PVST it is put in the blocking state by default.   Since this is a host port (not connected to another spanning tree bridge), there is no need to configure spanning tree on this port. Vlan21 is blocked on this port if PVST is not configured, so we need to enable manual-forwarding on this port, in item b given below.

a.	Remove pvst config on vlan 21 ( other vlans such as  22) as follows on both spines: delete protocols spanning-tree pvst vlan 21
b.	Configure forwarding port for Rapid-PVST+ mode on both spines as follows:
set protocols spanning-tree pvst interface te-1/1/11 manual-forwarding true

2.	MLAG consistency check CLI data and configuration corrections needed:
Last week you have executed the CLI show mlag consistency-parameter summary and provided us the data. We have found few MLAG configuration problems. Please correct the following problems:
a.	Configure same spanning tree parameters on both spine switches: Bridge priority need to be consistent between the two spines, as the two nodes are virtualized as one switch.  In fact, all parameters must be the same. Please correct this part of configuration.
b.	Remove DHCP snooping configuration in Spines: Typically our customers configure DHCP relay on L3 interfaces and DHCP snooping on L2 interfaces. Currently either DHCP snooping or DHCP relay can be configured on MLAG in spine switches. Configuring both DHCP snooping and DHCP relay on the spines is currently not supported.

Hence remove DHCP snooping configuration in the Spines.
3.	OSPF CLI related questions:
a.	set policy policy-statement connected-nw then CLI is configured. Does the default accept or reject? Default is accept.
b.	set policy policy-statement connected-nw then accept  CLI. Does this include only OSPF routes or does it include both OSPF and static routes?  This policy configuration only affect external routes configured above this CLI  (BGP, RIP, Static, connected, etc.). It includes routes external to OSPF.

4.	OSPF restart CLIs similar to Cisco IOS: Do you have a command to restart OSPF process similar to executing the following commands under Cisco IOS OSPF config: shut and no shut.

We do not have a similar mechanism in PICOS. However, the same effect can be achieved in PICOS by deleting the OSPF configuration and rollback the change. To do this issue the following CLI commands:

delete protocols ospf4
commit
rollback 1
commit

5.	OSPF related issue: We noticed the following OSPF error during our meeting:
Command failed: create_term failed: PolicyException from line 55 of policy_statement.cc: Term already present in position: 4294967298 4294967299

We tried to reproduce the problem  in our lab unsuccessfully. We took the following steps:


admin@P8 # set protocols static route 0.0.0.0/0 next-hop 10.31.83.98
admin@P8 # commit
admin@P8 # set policy policy-statement connected-nw term 3 from protocol "static"
admin@P8 # set policy policy-statement connected-nw term 3 then accept
admin@P8 # commit
admin@P8 # delete policy policy-statement connected-nw term 3

If you can reproduce the problem, provide us the steps. Run the following CLI: set policy traceoptions flag all disable false, trigger the problem and  provide us the associated logs.

Thanks,
Mani

Mani Subramanian
Pica8, Inc.
Mobile:   +1 408 203 0287
E :  mani.subramanian@pica8.com | I:  www.pica8.com


From: mani.subramanian@pica8.com
When: 1:00 PM - 2:00 PM June 26, 2020
Subject: Cargill: DHCP relay troubleshooting
Location: Webex


Hi Dinesh,


https://meetings.webex.com/collabs/#/meetings/detail?uuid=M60DD4U0SAD1D68MFDYIDT99PP-50V7&rnd=232620.37068



Best,
Mani





Since that happened only in 1 out of 4 instances, it should be single case issue.


       The contents of /etc/motd are displayed by pam_motd(8) after a successful login but just before it executes the login shell.

The following settings will impact the motd showing.

Please check them all.


----
This controls moth showing for SSH connection.
Commenting that line will disable showing.

    /etc/pam.d/sshd
    #    session    optional     pam_motd.so # [1]



----
This controls moth showing for console login:
Commenting that line will disable showing.

    /etc/pam.d/login
    #session    optional   pam_motd.so
----
These files control the contents for showing:
/var/run/motd.d*

--
Aaron

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, July 2, 2020 09:35
To: Mikel Tang <mikel.tang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: <Mikel help>FW: Cargill: Login announcement (Banner) not showing up for one switch

Hi Mikel,

We instructed Dinesh to configure login banner as:

$ cli -c 'configure; set system login announcement "
By pressing any key, you are entering property owned by Cargill,
Incorporated or its affiliated companies (Cargill). If you are
ot an authorized user of the Cargill Network, you should leave it
immediately. Access to and use of the Cargill Network, including any
software which may be accessed through such Network, are governed by
the policies and procedures implemented by Cargill, which may be
changed by Cargill at any time. Cargill expressly reserves the right
to access, monitor, read, copy, print and/or disclose any e-mail,
electronic files or other computer records created, received and/or
stored through your use of the Cargill Network.
"; commit; exit'

For some reason, one of the switches (one out of four) does not show the banner. According to Dinesh, the banner was saved in the PICOS configuration file and /etc/motd. Here are my suspicions, but the problem is caused by them.

1.	The banner exceeds the size of the PICOS buffer.
a.	I double the message and could not cause the problem.
2.	There exist special characters.
a.	I added “~!@#$%^&*()_+ `-=}[]:<>?,./|”, but it is fine.
b.	CLI fails by complaining, \ and single and double quotations. They are right.
3.	I suspected that the motd function has been disabled accidently, but it looks like that I cannot change it.
a.	$ sudo systemctl start dotd

It looks like that it is controlled by /pica/bin/system/pica_login process. It looks like that there are no bugs related to it. Have you met it before?

Would you mind asking developers whether they know it and how to resolve it? Does reboot resolve it?

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 1:50 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

Find the attachment from sdn2-lcs

Thanks,
Dinesh Kolan

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Wednesday, July 01, 2020 3:41 PM
To: DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>; Mani Subramanian <mani.subramanian@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: support@pica8.com
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Dinesh,

I could not reproduce this problem so far!

Would you mind forwarding this /etc/motd to us to verify it?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Wednesday, July 1, 2020 at 12:25 PM
To: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch

Hi Dinesh,

/etc/motd looks fine to me! We will do more tests to verify it and let you know how to resolve it!

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 12:20 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Mani Subramanian <mani.subramanian@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

I have changed the banner to multiple line banner and now find the requested output. Other switches have the same output but still working fine.

Let me know what should I be trying to get this working.



Thanks,
Dinesh Kolan

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Wednesday, July 01, 2020 1:59 PM
To: DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>; Mani Subramanian <mani.subramanian@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Re: Cargill: Login announcement (Banner) not showing up for one switch


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Hi Dinesh,

I do not know what caused this problem. According to my understanding, PICOS announcement mechanism is based on Linux “message of the day”.

Would you mind providing us the outputs of the following commands?

1.	$ ls -l /etc/motd
2.	$ cat /etc/motd

Potentially, we need to remove /etc/motd and reboot the system to make it working properly.

Thanks,

Zoneson

From: "DINESH KOLAN (CRGL-THIRDPARTY.COM)" <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Date: Wednesday, July 1, 2020 at 8:18 AM
To: Mani Subramanian <mani.subramanian@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Jeff Herman <jeff.herman@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: Login announcement (Banner) not showing up for one switch

Team,

I was able to add multiple line banner from shell and saw it at login on 3 switches but not on the sdn2-lcs. Switch sdn2-lcs isn’t displaying a banner even if it’s a single line configured from the config mode. Multiple lines when added, its showing up in the running configuration but not displaying at the login. See below output. Also attaching the tech-support file.



Thanks,
Dinesh Kolan

From: DINESH KOLAN (CRGL-THIRDPARTY.COM)
Sent: Tuesday, June 30, 2020 6:05 PM
To: 'Mani Subramanian' <mani.subramanian@pica8.com>; 'Zoneson Chen' <zoneson.chen@pica8.com>; 'Jeff Herman' <jeff.herman@pica8.com>; 'Hai Vo-Dinh' <hai.vodinh@pica8.com>
Subject: RE: Cargill: UDLD troubleshooting

Find the attached UDLD logs file. Let me know if you find anything related to why the interfaces were UDLD disabled.

Thanks,
Dinesh Kolan

From: DINESH KOLAN (CRGL-THIRDPARTY.COM)
Sent: Tuesday, June 30, 2020 3:17 PM
To: Mani Subramanian <mani.subramanian@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: RE: Cargill: DHCP relay troubleshooting meeting follow-up

Mani,

Find the attached logs after making the below changes.

•	OSPF export policy is still not clear and I did not get that error this time when I replicated the below scenario.
•	I still have the UDLD enabled globally. You suggested to disable the UDLD on the peer-links. What if we actually want to monitor them too?
•	We have setups at some sites with just single switch active as both L3 and also the access switch. How to setup the DHCP snooping in that case?
•	How to add a login banner with multiple lines?
•	There was always a login user “admin”. Can’t this be used when the TACACS+ fails? I don’t see this user info in the configuration.
o	But have seen an user profile names “operator” with read-only class. When can this be used and what is the password set for it? The configuration showed plan-text encrypted
o	Are the custom local login credentials different from the default eth0/console credentials?

Thanks,
Dinesh Kolan

From: Mani Subramanian <mani.subramanian@pica8.com>
Sent: Monday, June 29, 2020 4:27 PM
To: Zoneson Chen <zoneson.chen@pica8.com>; Jeff Herman <jeff.herman@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; DINESH KOLAN (CRGL-THIRDPARTY.COM) <DINESH_KOLAN@CRGL-THIRDPARTY.COM>
Subject: Re: Cargill: DHCP relay troubleshooting meeting follow-up


[EXTERNAL] This email came from outside of Cargill. Do not click links or open attachments unless you recognize the sender. If you suspect this is spam, send this email as an attachment to spam@cargill.com
Hi Dinesh,

During last Friday meeting we noticed few problems and you had few questions on OSPF. I’m addressing the problems and your OSPF questions in this email. We have analyzed the output file you have emailed us on Friday.

Please update the Spine switch configuration based on following recommendations and test. After the configuration changes, email us the latest config for spine and leaf switches. Also please send us output for mlag consistency-parameter summary CLI on both spine switches.

I will set up a follow-up call tomorrow Jun 30 at 4 PM CST. We will check whether all features you have configured are working properly.

1.	Uplink configuration (link connected to  Cisco router):
In our PVST design if a VLAN is not configured with PVST it is put in the blocking state by default.   Since this is a host port (not connected to another spanning tree bridge), there is no need to configure spanning tree on this port. Vlan21 is blocked on this port if PVST is not configured, so we need to enable manual-forwarding on this port, in item b given below.

a.	Remove pvst config on vlan 21 ( other vlans such as  22) as follows on both spines: delete protocols spanning-tree pvst vlan 21
b.	Configure forwarding port for Rapid-PVST+ mode on both spines as follows:
set protocols spanning-tree pvst interface te-1/1/11 manual-forwarding true

2.	MLAG consistency check CLI data and configuration corrections needed:
Last week you have executed the CLI show mlag consistency-parameter summary and provided us the data. We have found few MLAG configuration problems. Please correct the following problems:
a.	Configure same spanning tree parameters on both spine switches: Bridge priority need to be consistent between the two spines, as the two nodes are virtualized as one switch.  In fact, all parameters must be the same. Please correct this part of configuration.
b.	Remove DHCP snooping configuration in Spines: Typically our customers configure DHCP relay on L3 interfaces and DHCP snooping on L2 interfaces. Currently either DHCP snooping or DHCP relay can be configured on MLAG in spine switches. Configuring both DHCP snooping and DHCP relay on the spines is currently not supported.

Hence remove DHCP snooping configuration in the Spines.
3.	OSPF CLI related questions:
a.	set policy policy-statement connected-nw then CLI is configured. Does the default accept or reject? Default is accept.
b.	set policy policy-statement connected-nw then accept  CLI. Does this include only OSPF routes or does it include both OSPF and static routes?  This policy configuration only affect external routes configured above this CLI  (BGP, RIP, Static, connected, etc.). It includes routes external to OSPF.

4.	OSPF restart CLIs similar to Cisco IOS: Do you have a command to restart OSPF process similar to executing the following commands under Cisco IOS OSPF config: shut and no shut.

We do not have a similar mechanism in PICOS. However, the same effect can be achieved in PICOS by deleting the OSPF configuration and rollback the change. To do this issue the following CLI commands:

delete protocols ospf4
commit
rollback 1
commit

5.	OSPF related issue: We noticed the following OSPF error during our meeting:
Command failed: create_term failed: PolicyException from line 55 of policy_statement.cc: Term already present in position: 4294967298 4294967299

We tried to reproduce the problem  in our lab unsuccessfully. We took the following steps:


admin@P8 # set protocols static route 0.0.0.0/0 next-hop 10.31.83.98
admin@P8 # commit
admin@P8 # set policy policy-statement connected-nw term 3 from protocol "static"
admin@P8 # set policy policy-statement connected-nw term 3 then accept
admin@P8 # commit
admin@P8 # delete policy policy-statement connected-nw term 3

If you can reproduce the problem, provide us the steps. Run the following CLI: set policy traceoptions flag all disable false, trigger the problem and  provide us the associated logs.

Thanks,
Mani

Mani Subramanian
Pica8, Inc.
Mobile:   +1 408 203 0287
E :  mani.subramanian@pica8.com | I:  www.pica8.com


From: mani.subramanian@pica8.com
When: 1:00 PM - 2:00 PM June 26, 2020
Subject: Cargill: DHCP relay troubleshooting
Location: Webex


Hi Dinesh,


https://meetings.webex.com/collabs/#/meetings/detail?uuid=M60DD4U0SAD1D68MFDYIDT99PP-50V7&rnd=232620.37068



Best,
Mani






I checked the settings in our boxes, that had been disabled long before.

In standard Linux, it is default standard to log all access

    auth,authpriv.*                 /var/log/auth.log

log lines like:

Jun 29 11:04:18 vrf20 sshd[24820]: Accepted publickey for build from 10.10.50.18 port 55672 ssh2: RSA SHA256:RFoUpgCRlieq2KlqTkdxi6HyRLGjsIeER+y26GQMcos
Jun 29 11:04:18 vrf20 sshd[24820]: pam_unix(sshd:session): session opened for user build by (uid=0)
Jun 29 11:04:18 vrf20 systemd-logind[763]: New session 2103 of user build.
Jun 29 11:04:40 vrf20 sshd[24826]: Received disconnect from 10.10.50.18 port 55672:11: disconnected by user
Jun 29 11:04:40 vrf20 sshd[24826]: Disconnected from user build 10.10.50.18 port 55672
Jun 29 11:04:40 vrf20 sshd[24820]: pam_unix(sshd:session): session closed for user build
Jun 29 11:04:40 vrf20 systemd-logind[763]: Session 2103 logged out. Waiting for processes to exit.
Jun 29 11:04:40 vrf20 systemd-logind[763]: Removed session 2103.
Jun 29 11:04:41 vrf20 su: pam_unix(su-l:session): session closed for user build
Jun 29 11:16:01 vrf20 sshd[25416]: Accepted password for admin from 10.10.51.184 port 44605 ssh2
Jun 29 11:16:01 vrf20 sshd[25416]: pam_unix(sshd:session): session opened for user admin by (uid=0)
Jun 29 11:16:01 vrf20 sshd[25422]: Received disconnect from 10.10.51.184 port 44605:11: disconnected by user
Jun 29 11:16:01 vrf20 sshd[25422]: Disconnected from user admin 10.10.51.184 port 44605
Jun 29 11:16:01 vrf20 sshd[25416]: pam_unix(sshd:session): session closed for user admin

--
Aaron

From: Niraj Jain <niraj.jain@pica8.com>
Sent: Monday, June 29, 2020 08:16
To: Aaron Shang <aaron.shang@pica8.com>
Cc: plm@pica8.com <plm@pica8.com>
Subject: Re: Couple of questions

Aaron,
Thanks for the info.  I will share will Dell and come back to you if further clarification is needed.

One question: you mention that IP tracking is done by system logging.  Can it be turned off?

Niraj

From: Aaron Shang <aaron.shang@pica8.com>
Date: Sunday, June 28, 2020 at 3:03 AM
To: Niraj Jain <niraj.jain@pica8.com>
Cc: "plm@pica8.com" <plm@pica8.com>
Subject: Re: Couple of questions

Hi, Niraj,

As of the questions, here are my answers:

> ssh daemon (protocol version 2) must have ed25519 host keys or at least support rsa4096-bit host keys; Hostkeys should be external

We can support ssh protocol version 2, ed25519 host keys, rsa4096-bit host keys;
  But by `Hostkeys should be external`, I had no idea of the exact meaning.
  In the system, Hostkey files can be assigned. So I think we can support specific hostkey files.

> Source can be reloaded  (Cipher for ssh daemon must be configurable to state of the art technology)

  By this, I think it means the config file `sshd_config` can be reloaded. The answer is yes.
  SSH related CLI config options take effects by reloading the config changes.
  Now PICOS only allows 3 strong Ciphers. It can be tuned from requests.
    # Only allow strong Ciphers; Nowaday SSH clients all support these
    Ciphers aes128-ctr,aes192-ctr,aes256-ctr

    ^^^^This was made due to certain past requests from the customer, and can be reviewed later.


> Hash quality of the passwords in the configuration (e.g. enable or Radius PSKs) must be configurable; it must be possible to get one Adopt hash value in the configuration

All SSH server configuration can be configurable; Only a few are exposed via CLI;
  Others can be done by adding to CLI if we take the efforts.
  Hash qualities can be configured, different hash means can be selected.
  RADIUS can be done by adding PAM modules.
  By PSK, if it would be WPA2-PSK; we had no experience implementing them onto PICOS.
  By PSK, if it is like normal password method, that is the default.

> Telnet and other unneeded services (e.g. web service etc.) must be switchable

Telnet services is not available in 3.x due to its plain text transfer
  Other services can be disabled or enabled.


Here are notes for support after I went through the config example.

- ip tracking;
It is done by system logging. The log might be prone to rotating.
If permanent storage is desired, to configure a remote syslog server and further process is expected.

- Other services like ntp, radius, snmp, dhcp, etc., can be adjusted, but not all have CLI.

I am not an expert on cisco switching config rules, so please involve the team if we need to review on a larger scale here.





Hi, Niraj,

As of the questions, here are my answers:

> ssh daemon (protocol version 2) must have ed25519 host keys or at least support rsa4096-bit host keys; Hostkeys should be external

We can support ssh protocol version 2, ed25519 host keys, rsa4096-bit host keys;
  But by `Hostkeys should be external`, I had no idea of the exact meaning.
  In the system, Hostkey files can be assigned. So I think we can support specific hostkey files.

> Source can be reloaded  (Cipher for ssh daemon must be configurable to state of the art technology)

  By this, I think it means the config file `sshd_config` can be reloaded. The answer is yes.
  SSH related CLI config options take effects by reloading the config changes.
  Now PICOS only allows 3 strong Ciphers. It can be tuned from requests.
    # Only allow strong Ciphers; Nowaday SSH clients all support these
    Ciphers aes128-ctr,aes192-ctr,aes256-ctr

    ^^^^This was made due to certain past requests from the customer, and can be reviewed later.


> Hash quality of the passwords in the configuration (e.g. enable or Radius PSKs) must be configurable; it must be possible to get one Adopt hash value in the configuration

All SSH server configuration can be configurable; Only a few are exposed via CLI;
  Others can be done by adding to CLI if we take the efforts.
  Hash qualities can be configured, different hash means can be selected.
  RADIUS can be done by adding PAM modules.
  By PSK, if it would be WPA2-PSK; we had no experience implementing them onto PICOS.
  By PSK, if it is like normal password method, that is the default.

> Telnet and other unneeded services (e.g. web service etc.) must be switchable

Telnet services is not available in 3.x due to its plain text transfer
  Other services can be disabled or enabled.


Here are notes for support after I went through the config example.

- ip tracking;
It is done by system logging. The log might be prone to rotating.
If permanent storage is desired, to configure a remote syslog server and further process is expected.

- Other services like ntp, radius, snmp, dhcp, etc., can be adjusted, but not all have CLI.

I am not an expert on cisco switching config rules, so please involve the team if we need to review on a larger scale here.




Hi, Zoneson, Daisy,


I checked the extracted two images, found the older one contains some contents for vrf.
Although I am not sure why they impacts the behavor of iptables, I think that is not expected.


I will in the future ensure a totally clean build for release images, although the time consuming would be much longer.

Sorry for the issue.

Zonezon, this is the one which is copied to dev22 later after you fetched to the shipping host.

    -rwxr-xr-x 1 build build 220758943 Jun  6 04:15 /build/daily/x86/onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin


Here is the latest 3.7.0 image, with prompt of 5 seconds menu selection for shell during ONIE install.

    -rwxr-xr-x 1 build build 221311903 Jun  9 01:30 /build/daily/x86/onie-installer-picos-3.7.0-9602644dea-x86.bin




====

The `old` one is the image zonezon got, the `new` one is the current one.



diff -x.git -urN new/pica/xrl/targets/login.xrls old/pica/xrl/targets/login.xrls
--- new/pica/xrl/targets/login.xrls     2020-06-06 03:13:40.000000000 +0800
+++ old/pica/xrl/targets/login.xrls     2020-06-05 03:09:02.000000000 +0800
@@ -660,6 +660,11 @@
 finder://login/login/0.1/delete_dns_server_ipv6?server_ip:ipv6

 /**
+ *  set management services vrf
+ */
+finder://login/login/0.1/set_mgmt_services_vrf?vrf:txt
+
+/**
  *  set management port vrf
  */
 finder://login/login/0.1/set_management_inf_vrf?ifname:txt&vrf:txt
diff -x.git -urN new/pica/xrl/targets/sif.xrls old/pica/xrl/targets/sif.xrls
--- new/pica/xrl/targets/sif.xrls       2020-06-06 03:13:40.000000000 +0800
+++ old/pica/xrl/targets/sif.xrls       2020-06-05 03:09:02.000000000 +0800
@@ -257,12 +257,7 @@
 /**
  *  set port duplex
  */
-finder://sif/switch_port_config/0.1/set_port_duplex?tid:u32&ifname:txt&duplex:txt
-
-/**
- *  delete port duplex
- */
-finder://sif/switch_port_config/0.1/delete_port_duplex?tid:u32&ifname:txt
+finder://sif/switch_port_config/0.1/set_port_duplex?tid:u32&ifname:txt&duplex:u32

 /**
  *  get port duplex
diff -x.git -urN new/pica/xrl/targets/snmp.xrls old/pica/xrl/targets/snmp.xrls
--- new/pica/xrl/targets/snmp.xrls      2020-06-06 03:13:40.000000000 +0800
+++ old/pica/xrl/targets/snmp.xrls      2020-06-05 03:09:02.000000000 +0800
@@ -2161,6 +2161,13 @@
 finder://snmp/snmp_config/0.1/update_mstp_cist_port_entry_list?port_number_list:list&port_uptime_list:list&port_admin_path_cost_list:list&port_designated_root_priority_list:list&port_designated_root_mac_list:list&port_tc_ack_vec:binary&port_hello_time_list:list&port_admin_edge_port_vec:binary&port_oper_edge_port_vec:binary&port_mac_enabled_vec:binary&port_mac_operational_vec:binary&port_restricted_role_vec:binary&port_restricted_tcn_vec:binary&port_role_list:list&port_disputed_vec:binary&port_cist_regional_root_priority_list:list&port_cist_regional_root_mac_list:list&port_cist_path_cost_list:list&port_protocol_migration_vec:binary&port_enable_rx_bpdu_vec:binary&port_enable_tx_bpdu_vec:binary

 /**
+ *  Set vrf used on SNMP
+ *
+ *  @param vrf vrf configured in switch.
+ */
+finder://snmp/snmp_config/0.1/set_vrf?vrf:txt
+
+/**
  *  available log level: fatal error warning info trace
  */
 finder://snmp/log/0.1/set_logging_level?level:txt



--
Aaron

From: Aaron Shang <aaron.shang@pica8.com>
Sent: Tuesday, June 9, 2020 18:40
To: Daisy Zhao <daisy.zhao@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Tong Zhang <tong.zhang@pica8.com>; Leon Li <leon.li@pica8.com>
Cc: Lin Du <lin.du@pica8.com>; James Liao <james.liao@pica8.com>; Tom Jia <tom.jia@pica8.com>; Chail Wang <chail.wang@pica8.com>
Subject: Re: Re: Latest 3.7.0 builds -- iptables rules rejecting ssh connections

Hi, Zoneson, Daisy,

I found the size of the image changed a few KB.
That might be caused by my another running of building from another server, because of concern to ensure the result in time.


This one in zoneson's dir was from the first build.

$ \ssh admin@172.16.0.44 ls -l /usr/home/admin/zoneson/releases/3.7.0/onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin
Password for admin@shipping:
-rwxr-xr-x  1 admin  admin  221260703 Jun  5 10:05 /usr/home/admin/zoneson/releases/3.7.0/onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin


The current one was OK after Tong/Daisy tried in BJ lab.

$ \ssh dev22 ls -ltr /build/daily/x86/onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin
-rwxr-xr-x 1 build build 220758943 Jun  6 04:15 /build/daily/x86/onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin



I am now extracting the two files to see whether there is delta causing the issue.




--
Aaron

From: Daisy Zhao <daisy.zhao@pica8.com>
Sent: Tuesday, June 9, 2020 18:25
To: Zoneson Chen <zoneson.chen@pica8.com>; Tong Zhang <tong.zhang@pica8.com>
Cc: Lin Du <lin.du@pica8.com>; James Liao <james.liao@pica8.com>; Aaron Shang <aaron.shang@pica8.com>; Tom Jia <tom.jia@pica8.com>; Chail Wang <chail.wang@pica8.com>
Subject: Re: Re: Latest 3.7.0 builds -- iptables rules rejecting ssh connections

Hi zoneson
your image size is different with what we used.
where did you get the image?

-rwxr-xr-x  1 admin  admin  221260703 Jun  5 10:05 onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin
-rwxr-xr-x 1 build build 220758943 Jun  6 04:15 onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin


daisy.zhao@pica8.com

From: Zoneson Chen
Date: 2020-06-09 16:43
To: Daisy Zhao; Tong Zhang
CC: Lin Du; James Liao; Aaron Shang; Tom Jia; Chail Wang
Subject: Re: Latest 3.7.0 builds -- iptables rules rejecting ssh connections
Hi Daisy,

I can reproduce it again. It is the 3.7.0 released by Aaron instead of the development version you used in your test.

It is running 3.7.0 now and you can try to ssh it (172.16.0234). if you want to reproduce it, do the following steps:

1.	Rollback to 3.5.11.
2.	Copy the released 3.7.0:
a.	$ cd /cftmp
b.	$ sudo scp admin@172.16.0.44:/home/admin/zoneson/releases/3.7.0/*x86* .
3.	Upgrade.

Thanks,

Zoneson



admin@Xorplus:~$ ifconfig eth0
eth0      Link encap:Ethernet  HWaddr a8:2b:b5:0d:93:34
          inet addr:172.16.0.234  Bcast:172.16.0.255  Mask:255.255.255.0
          inet6 addr: 2603:3024:1852:40e3:aa2b:b5ff:fe0d:9334/64 Scope:Global
          inet6 addr: fe80::aa2b:b5ff:fe0d:9334/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:354 errors:0 dropped:0 overruns:0 frame:0
          TX packets:20 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:46362 (45.2 KiB)  TX bytes:4504 (4.3 KiB)
          Memory:dff40000-dff5ffff

admin@Xorplus:~$ sudo iptables -L -v -n
Chain INPUT (policy ACCEPT 739 packets, 117K bytes)
pkts bytes target     prot opt in     out     source               destination
12316 2123K ACCEPT     all  --  lo     *       0.0.0.0/0            0.0.0.0/0
   59  8820 DROP       tcp  --  !mgmt-vrf *       0.0.0.0/0            0.0.0.0/0            multiport dports 22,23,8080
    0     0 DROP       udp  --  !mgmt-vrf *       0.0.0.0/0            0.0.0.0/0            multiport dports 161
    0     0 REJECT     tcp  --  *      *       0.0.0.0/0            0.0.0.0/0            tcp dpt:22 flags:0x17/0x02 #conn src/32 > 20 reject-with icmp-port-unreachable
    0     0 REJECT     tcp  --  *      *       0.0.0.0/0            0.0.0.0/0            tcp dpt:22 state NEW recent: UPDATE seconds: 60 hit_count: 20 TTL-Match name: SSH side: source mask: 255.255.255.255 reject-with icmp-port-unreachable
    0     0 ACCEPT     tcp  --  *      *       0.0.0.0/0            0.0.0.0/0            tcp dpt:22 state NEW recent: SET name: SSH side: source mask: 255.255.255.255

Chain FORWARD (policy ACCEPT 0 packets, 0 bytes)
pkts bytes target     prot opt in     out     source               destination

Chain OUTPUT (policy ACCEPT 9783 packets, 1675K bytes)
pkts bytes target     prot opt in     out     source               destination
admin@Xorplus:~$ version
Copyright (C) 2009-2020 Pica8, Inc.
===================================
Hardware Model                : AS5812_54X
Linux System Version/Revision : 3.7.0/5e8d6f7f5d
Linux System Released Date    : 06/05/2020
L2/L3 Version/Revision        : 3.7.0/5e8d6f7f5d
L2/L3 Released Date           : 06/05/2020
OVS/OF Version/Revision       : 3.7.0/5e8d6f7f5d
OVS/OF Released Date          : 06/05/2020
From: Daisy Zhao <daisy.zhao@pica8.com>
Date: Monday, June 8, 2020 at 10:18 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Tong Zhang <tong.zhang@pica8.com>
Cc: Lin Du <lin.du@pica8.com>, James Liao <james.liao@pica8.com>, Aaron Shang <aaron.shang@pica8.com>, Tom Jia <tom.jia@pica8.com>, Chail Wang <chail.wang@pica8.com>
Subject: Re: Re: Latest 3.7.0 builds -- iptables rules rejecting ssh connections

Hi Zoneson
What is the reproduce step.
Upgrade from 3.5.11 to 3.7.0?
Only 5812?


daisy.zhao@pica8.com

From: Zoneson Chen
Date: 2020-06-09 11:11
To: Tong Zhang
CC: Lin Du; James Liao; Aaron Shang; Daisy Zhao; Tom Jia; Chail Wang
Subject: Re: Latest 3.7.0 builds -- iptables rules rejecting ssh connections
Tong,

Thank you for the hint! But this one is out-of-band port, eth0.

admin@Xorplus:~$ ifconfig eth0
eth0      Link encap:Ethernet  HWaddr a8:2b:b5:0d:93:34
          inet addr:172.16.0.234  Bcast:172.16.0.255  Mask:255.255.255.0
          inet6 addr: 2603:3024:1852:40e3:aa2b:b5ff:fe0d:9334/64 Scope:Global
          inet6 addr: fe80::aa2b:b5ff:fe0d:9334/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:4874 errors:0 dropped:0 overruns:0 frame:0
          TX packets:40 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:635782 (620.8 KiB)  TX bytes:7772 (7.5 KiB)
          Memory:dff40000-dff5ffff

Thanks,

Zoneson

From: Tong Zhang <tong.zhang@pica8.com>
Date: Monday, June 8, 2020 at 8:01 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: Lin Du <lin.du@pica8.com>, James Liao <james.liao@pica8.com>, Aaron Shang <aaron.shang@pica8.com>, Daisy Zhao <daisy.zhao@pica8.com>, Tom Jia <tom.jia@pica8.com>, Chail Wang <chail.wang@pica8.com>
Subject: Re: Re: Latest 3.7.0 builds -- iptables rules rejecting ssh connections

Hi Zoneson，
      iptables rules rejecting ssh connections is because inband isn't enabled.
     "set system inband enable true" command can enable ssh connection through inband port.


tong.zhang@pica8.com

From: Aaron Shang
Date: 2020-06-09 10:20
To: Daisy Zhao; Tom Jia; Tong Zhang; Chail Wang
CC: Lin Du; Zoneson Chen; James Liao
Subject: Re: Latest 3.7.0 builds -- iptables rules rejecting ssh connections

Commits in doubt:

http://10.10.50.50/repo/pica8/commit/6dfbe4bbd3df40eb6c973bfdd3d02f8ab2db546b


commit 6dfbe4bbd3df40eb6c973bfdd3d02f8ab2db546b
Author: chail.wang <chail.wang@pica8.local>
Date:   Wed May 27 11:27:34 2020 +0800

    Login/fea/sflow support vrf rollback.



--
Aaron


From: Aaron Shang <aaron.shang@pica8.com>
Sent: Tuesday, June 9, 2020 10:17
To: Daisy Zhao <daisy.zhao@pica8.com>; Tom Jia <tom.jia@pica8.com>; Tong Zhang <tong.zhang@pica8.com>; Chail Wang <chail.wang@pica8.com>
Cc: Lin Du <lin.du@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>
Subject: Re: Latest 3.7.0 builds

Daisy,


Please refer to my records of iptables chains.

Also cc to Tong, Iris,


If possible, we should cover these basic functions such as ssh connection or iptables rules into regression cases.








--
Aaron


From: Aaron Shang <aaron.shang@pica8.com>
Sent: Tuesday, June 9, 2020 09:26
To: James Liao <james.liao@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>
Subject: Re: Latest 3.7.0 builds

Root cause can be seen from iptables rules to drop ssh connections.


$ ssh admin@172.16.0.234
OpenSSH_8.2p1 Debian-4, OpenSSL 1.1.1g  21 Apr 2020
debug1: Reading configuration data /home/aaron/.ssh/config
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: /etc/ssh/ssh_config line 19: include /etc/ssh/ssh_config.d/*.conf matched no files
debug1: /etc/ssh/ssh_config line 21: Applying options for *
debug1: Connecting to 172.16.0.234 [172.16.0.234] port 22.
<<<<HANGS HERE>>>>


admin@Xorplus:~$ sudo iptables -L
Chain INPUT (policy ACCEPT)
target     prot opt source               destination
ACCEPT     all  --  anywhere             anywhere
DROP       tcp  --  anywhere             anywhere             multiport dports ssh,telnet,http-alt
DROP       udp  --  anywhere             anywhere             multiport dports snmp
REJECT     tcp  --  anywhere             anywhere             tcp dpt:ssh flags:FIN,SYN,RST,ACK/SYN #conn src/32 > 20 reject-with icmp-port-unreachable
REJECT     tcp  --  anywhere             anywhere             tcp dpt:ssh state NEW recent: UPDATE seconds: 60 hit_count: 20 TTL-Match name: SSH side: source mask: 255.255.255.255 reject-with icmp-port-unreachable
ACCEPT     tcp  --  anywhere             anywhere             tcp dpt:ssh state NEW recent: SET name: SSH side: source mask: 255.255.255.255

Chain FORWARD (policy ACCEPT)
target     prot opt source               destination

Chain OUTPUT (policy ACCEPT)
target     prot opt source               destination
admin@Xorplus:~$


admin@Xorplus:~$ sudo iptables -F
admin@Xorplus:~$ sudo iptables -L
Chain INPUT (policy ACCEPT)
target     prot opt source               destination

Chain FORWARD (policy ACCEPT)
target     prot opt source               destination

Chain OUTPUT (policy ACCEPT)
target     prot opt source               destination

$ \ssh admin@172.16.0.234
admin@172.16.0.234's password:

Last login: Fri Jan 19 02:57:31 2001 from 10.10.50.100
Synchronizing configuration...OK.
Welcome to PICOS on Xorplus
admin@Xorplus>

OK now.



I am no checking why or how the iptables rules had been applied.


--
Aaron

From: James Liao <james.liao@pica8.com>
Sent: Tuesday, June 9, 2020 02:39
To: Zoneson Chen <zoneson.chen@pica8.com>; Aaron Shang <aaron.shang@pica8.com>; Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>
Subject: Re: Latest 3.7.0 builds

Aaron, Tom,

Please brief me on the root cause when the problem is identified.

James

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Monday, June 8, 2020 at 8:41 AM
To: Aaron Shang <aaron.shang@pica8.com>, Tom Jia <tom.jia@pica8.com>, Lin Du <lin.du@pica8.com>, James Liao <james.liao@pica8.com>
Subject: Re: Latest 3.7.0 builds

Hi Aaron,

Thank you for informing us the new build! It works fine on as4610, but I experience a problem on as5812. I am able to ping the switch, but ssh fails. It is upgraded from 3.5.11 and only enables LLDP.

It can be reached:

$ telnet 172.16.0.19 7004

Thanks,

Zoneson
P.S. switch status and ping/ssh performed from remote:

1.	Switch status
admin@Xorplus:~$ version
Copyright (C) 2009-2020 Pica8, Inc.
===================================
Hardware Model                : AS5812_54X
Linux System Version/Revision : 3.7.0/5e8d6f7f5d
Linux System Released Date    : 06/05/2020
L2/L3 Version/Revision        : 3.7.0/5e8d6f7f5d
L2/L3 Released Date           : 06/05/2020
OVS/OF Version/Revision       : 3.7.0/5e8d6f7f5d
OVS/OF Released Date          : 06/05/2020

admin@Xorplus:~$ ps aux |grep ssh
root       635  0.0  0.0  55184  5324 ?        Ss   17:03   0:00 /usr/sbin/sshd -D
admin     1619  0.0  0.0  11132  1036 ttyS1    S+   17:05   0:00 grep ssh
admin@Xorplus:~$ ifconfig eth0
eth0      Link encap:Ethernet  HWaddr a8:2b:b5:0d:93:34
          inet addr:172.16.0.234  Bcast:172.16.0.255  Mask:255.255.255.0
          inet6 addr: 2603:3024:1852:40e3:aa2b:b5ff:fe0d:9334/64 Scope:Global
          inet6 addr: fe80::aa2b:b5ff:fe0d:9334/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:1092 errors:0 dropped:0 overruns:0 frame:0
          TX packets:29 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:141325 (138.0 KiB)  TX bytes:6682 (6.5 KiB)
          Memory:dff40000-dff5ffff

2.	Remote fuctions
admin@shipping ~ $ ssh admin@172.16.0.234
ssh: connect to host 172.16.0.234 port 22: Operation timed out
admin@shipping ~ $ ping 172.16.0.234
PING 172.16.0.234 (172.16.0.234): 56 data bytes
64 bytes from 172.16.0.234: icmp_seq=0 ttl=64 time=0.705 ms
64 bytes from 172.16.0.234: icmp_seq=1 ttl=64 time=0.364 ms
^C
--- 172.16.0.234 ping statistics ---
2 packets transmitted, 2 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 0.364/0.534/0.705/0.171 ms

From: Aaron Shang <aaron.shang@pica8.com>
Date: Friday, June 5, 2020 at 8:44 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, Tom Jia <tom.jia@pica8.com>, Lin Du <lin.du@pica8.com>, James Liao <james.liao@pica8.com>
Subject: Latest 3.7.0 builds

Hi,

You can try the latest images on 3.7.0,

X86 had been in one image;

ARM images remain seperate, because actually it is one ARMEL ARCH family but 3 sub-ARCH CPUs(different mach dir under linux/arch/arm/).
And some of them are using squashfs.

$ \ssh dev22 ls -ltr /build/daily/*/*3.7.0-5e8d6f7f5d*bin
-rwxr-xr-x 1 build build 221260703 Jun  5 22:15 /build/daily/x86/onie-installer-picos-3.7.0-5e8d6f7f5d-x86.bin
-rwxr-xr-x 1 build build 202480543 Jun  5 19:53 /build/daily/as4610/onie-installer-picos-3.7.0-5e8d6f7f5d-as4610.bin
-rwxr-xr-x 1 build build 203228063 Jun  5 21:24 /build/daily/n3000/onie-installer-picos-3.7.0-5e8d6f7f5d-n3000.bin
-rwxr-xr-x 1 build build 202920863 Jun  5 22:48 /build/daily/n3100/onie-installer-picos-3.7.0-5e8d6f7f5d-n3100.bin


--
Aaron







Got.

Will work with Tim for a refined design.

I can understand from Linux perspective. Originally the way to limit what users can do or not do something rely on user/group permission. Later xattr, EA(extended attributes) like means applied onto file system layer. Then complex DAC/MAC had been designed for higher security requirements, which had been the subjects of my PhD thesis. Currently SELinux and AppArmor can work for some audit and Accounting purpose. But still that is not the same to what the device vendors radius/tacacs+ protocol AAA.
Interactive commands in itself can not limit user hehavior; in fact, it is low in efficiency.
Non-Interactive mode in itself can not add security; in fact, it only fits into existing accounting.

Our focus would be AAA on Ansible, to find possible means for that.
--
Aaron


From: James Liao <james.liao@pica8.com>
Sent: Friday, June 5, 2020 23:26
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Yachal Chen <yachal.chen@pica8.com>
Subject: Ansible support

Aaron,

I saw you have added many comments on PDLC. It is hard to drive a design in that conversation model. The best way to do is to comment on the document (add Q&A or just insert comments). That at least we can collect questions and converge.

You probably have missed the most critical point in my document. “We have Ansible modules, but PICOS is not capable to support Ansible”. Just giving Ansible modules is NOT enough. Customers need TACACS AAA on Ansible, and we cannot support that in Linux.

Yachal’s suggestion of driving SSH non-interactive through picos_cli, which he did a prototype and it did not work. It requires Linux support (through TACACS AAA) to enable Ansible.

I know the document might not be easy to understand from Linux’s perspective. If possible, can you sit down with Tim to see if you two together can understand what we are trying to accomplish?
Thanks,
James








There is only one time/date, i.e. RTC, set by `hwclock` or `date -s`, or ntpdate, or ntpd, or any means of capable time setting facilities.
That is the system time.

There can be different time-zones for each user, i.e. set from each $TZ in case users work from different time zones.
There is one default timezone, i.e./etc/localtime, linked to zoneinfo db.

The time zone is for user experience. Users may get knowledge of the local time by simple calculating UTC/GMT plus the zone offset.


To set time zone, accurate string must be provided, such as `America/Los_Angeles`.
To our consensus, it has to be result of selection, rather than manual input, to reduce issues.
So we use system function for the selection.
The loop there is provided by that in-built system function, which we must not modify or intercept.

The time output is from RTC/hwclock, which is not related to time zone.
I think it OK because the setup is not done till now.

After the setup, you noticed the time is expected, because ntpdate/ntp set the synced time. They takes a while during syncing with external ntp servers.

Currently we collect all input first then do the setup, to not break user input sequence.
If the waiting time can be endured, we can rearrange the time syncing before the time zone setting.


Anyway, it is up to your decisions.

--
Aaron


From: Tom Jia <tom.jia@pica8.com>
Sent: Thursday, June 4, 2020 10:35
To: Mani Subramanian <mani.subramanian@pica8.com>; Lisa Pi <lisa.pi@pica8.com>; Niraj Jain <niraj.jain@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Tim Yi <tim.yi@pica8.com>; Don DeRisi <don.derisi@pica8.com>; Lin Du <lin.du@pica8.com>; plm@pica8.com <plm@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Re: 回复: Re: VZ AmpCon OVA testing - Issues for Upgrade - detail - troubleshoot

Forwarded to Aaron.
Thanks.

Best regards,
Tom Jia (贾彦民)







It resolves to `10...`, which is a private subnet, perhaps resolved by DELL intranet.



http://artifactory.force10networks.com/list/onie-release/dellemc_s5200_c3538/3.40.1.1-6/246/
Resolving artifactory.force10networks.com (artifactory.force10networks.com)... 10.156.170.204
Connecting to artifactory.force10networks.com (artifactory.force10networks.com)|10.156.170.204|:80...



--
Aaron

From: Vic Lan <vic.lan@pica8.com>
Sent: Wednesday, June 3, 2020 09:57
To: Lin Du <lin.du@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Subject: //Fwd: FW: PICA8 : 3.6.2 : S52XX - ONIE crash issue

Hi Lin,
这些链接对我们不可用，我和aaron都不能下载。


-------- Forwarded Message --------
Subject: 	FW: PICA8 : 3.6.2 : S52XX - ONIE crash issue
Date: 	Tue, 2 Jun 2020 18:32:41 +0800
From: 	Lin Du <lin.du@pica8.com>

To: 	Vic Lan <vic.lan@pica8.com>


Download link

From: Amarnath_Devendran@Dell.com [mailto:Amarnath_Devendran@Dell.com]
Sent: Monday, June 1, 2020 4:09 PM
To: Zoneson Chen; Mikel Tang; support@pica8.com
Cc: Rajeev.Puppala@dell.com; Jeevan.Krishna@dell.com
Subject: RE: PICA8 : 3.6.2 : S52XX - ONIE crash issue

Dell Customer Communication - Confidential

Hi Zoneson Chen,
     Apologize for the delay in response. PFA of 3.40.1.1-6 release notes as per your request. By the way can you please share us the bug-id for our reference and tracking purpose.

Thanks,

Amarnath Devendran
Software Engineer 1, Software Engineering.
Dell EMC | ISG Networking R&D
Mobile  +91 9003284939
Extension 4051602

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, May 28, 2020 11:41 AM
To: Mikel Tang; Devendran, Amarnath; support@pica8.com
Cc: Hai Vo-Dinh; Puppala, Rajeev; Krishna, Jeevan; RoshniA, Almah; K, Shanmugasiva; Thirumalai, Karthikeyan
Subject: Re: PICA8 : 3.6.2 : S52XX - ONIE crash issue

[EXTERNAL EMAIL]
Hi Amarnath,

Do you have the ONIE 3.40.1.1-6 release notes? It may help us figure out why onie un-install PICOS causes GRUB problems.

Thanks,

Zoneson


From: Mikel Tang <mikel.tang@pica8.com>
Date: Wednesday, May 27, 2020 at 10:39 PM
To: "Amarnath_Devendran@Dell.com" <Amarnath_Devendran@Dell.com>, Zoneson Chen <zoneson.chen@pica8.com>, "support@pica8.com" <support@pica8.com>
Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>, "Rajeev.Puppala@dell.com" <Rajeev.Puppala@dell.com>, "Jeevan.Krishna@dell.com" <Jeevan.Krishna@dell.com>, "Almah.Roshni@dell.com" <Almah.Roshni@dell.com>, "Shanmugasiva.K@dell.com" <Shanmugasiva.K@dell.com>, "Karthikeyan.Thirumal@Dell.com" <Karthikeyan.Thirumal@Dell.com>
Subject: RE: PICA8 : 3.6.2 : S52XX - ONIE crash issue

Hi Amarnath

We haven't figured out the root cause of the issue.
We need to get this old ONIE version and install it, and then try to reproduce again to analyze the difference between the two versions.

Thanks

Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: Amarnath_Devendran@Dell.com <Amarnath_Devendran@Dell.com>
Sent: Thursday, May 28, 2020 12:41 PM
To: Zoneson Chen <zoneson.chen@pica8.com>; support@pica8.com
Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>; Rajeev.Puppala@dell.com; Jeevan.Krishna@dell.com; Almah.Roshni@dell.com; Shanmugasiva.K@dell.com; Karthikeyan.Thirumal@Dell.com
Subject: RE: PICA8 : 3.6.2 : S52XX - ONIE crash issue

Dell Customer Communication - Confidential

Hi ,
  Thanks for considering the issue. Please provide the bug id for the same.

Thanks,
Amarnath D.
From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Thursday, May 28, 2020 1:07 AM
To: Devendran, Amarnath; support@pica8.com
Cc: Hai Vo-Dinh; Puppala, Rajeev; Krishna, Jeevan; RoshniA, Almah; K, Shanmugasiva; Thirumalai, Karthikeyan
Subject: Re: PICA8 : 3.6.2 : S52XX - ONIE crash issue

[EXTERNAL EMAIL]
Hi Amarnath,

I am sorry for the late response. We can reproduce this issue by upgrading the switch from an old ONIE version to a new ONIE version. But we cannot reproduce it by installing the new version via USB.

We will study the GRUB differences due to two different installation approaches. Will let you know when we have the ideas.

Thanks,

Zoneson



From: "Amarnath_Devendran@Dell.com" <Amarnath_Devendran@Dell.com>
Date: Tuesday, May 26, 2020 at 2:53 AM
To: "support@pica8.com" <support@pica8.com>
Cc: Hai Vo-Dinh <hai.vodinh@pica8.com>, "Rajeev.Puppala@dell.com" <Rajeev.Puppala@dell.com>, "Jeevan.Krishna@dell.com" <Jeevan.Krishna@dell.com>, "Almah.Roshni@dell.com" <Almah.Roshni@dell.com>, "Shanmugasiva.K@dell.com" <Shanmugasiva.K@dell.com>, "Karthikeyan.Thirumal@Dell.com" <Karthikeyan.Thirumal@Dell.com>
Subject: PICA8 : 3.6.2 : S52XX - ONIE crash issue

Dell Customer Communication - Confidential

Hi Team,

  Issue faced during PICA8 3.6.2 OS validation :
  On installing PICA8 3.6.2 and on uninstallation , ONIE prompt cannot be entered and device hangs in GRUB. Issue observed in S5224F,S5248F,S5212F and S5296F. PFA attachments respectively.
  Image Version  :

Components	Version
ONIE(n-1)	3.40.1.1-5
ONIE(n)	3.40.1.1-6
PICA8 (n-1)	3.6.1.1
PICA8 (n)	3.6.2
BIOS	3.40.0.9-10
CPLD Verison	CPU : 0.6
 	SLAVE :1.0

  Description :
  1 ) Downgraded ONIE to 3.40.1.1-5.(Successful)
  2) Installed PICA8 OS 3.6.2 and uninstalled.(Successful)
  3) Upgraded ONIE to 3.40.1.1-6.(Successful)
  4)  Installed PICA8 OS 3.6.2 and uninstalled.(ONIE prompt cannot be entered and device hangs in GRUB).

NOTE : PICA 3.6.2 still exists in partition and device is bootable to PICA8 3.6.2

Thanks,
Amarnath Devendran
Software Engineer 1, Software Engineering.
Dell EMC | ISG Networking R&D
Mobile  +91 9003284939
Extension 4051602








Actually I may concern more, say the use cases below:
•	admin@Xorplus:~$ curl -O https://dell.com/example/path/to/some/nice/config/file

curl: (6) Could not resolve host: dell.com
•	admin@Xorplus:~$ sudo apt install ntopng tshark
Err http://deb.debian.org jessie Release.gpg
  Could not resolve 'deb.debian.org'
Err http://security.debian.org jessie/updates Release.gpg
  Could not resolve 'security.debian.org'
Err http://deb.debian.org jessie-updates Release.gpg
  Could not resolve 'deb.debian.org'
admin@Xorplus:~$ sudo ip vrf exec mgmt-vrf apt update
Get:1 http://security.debian.org jessie/updates InRelease [44.9 kB]
Ign http://deb.debian.org jessie InRelease
Get:2 http://deb.debian.org jessie-updates InRelease [16.3 kB]
Get:3 http://security.debian.org jessie/updates/main amd64 Packages [769 kB]
Get:4 http://deb.debian.org jessie Release.gpg [1652 B]
...
•	admin@Xorplus:~$ sudo ntpdate pool.ntp.org
Error resolving pool.ntp.org: Name or service not known (-2)
 1 Jan 01:24:00 ntpdate[1551]: Can't find host pool.ntp.org: Name or service not known (-2)
 1 Jan 01:24:00 ntpdate[1551]: no servers can be used, exiting
admin@Xorplus:~$ sudo ip vrf exec mgmt-vrf ntpdate pool.ntp.org
admin@Xorplus:~$ sudo ip vrf exec mgmt-vrf ntpdate pool.ntp.org
21 May 07:17:59 ntpdate[1553]: step time server 119.28.183.184 offset 611733200.768653 sec


They failed even in name resolver (in glibc) while users get no knowledge from output.

Of course, those are not issues for VRF aware users or admin well-educated from our guides.

So I think that would be better if there is some output pointing to possible VRF setup, or there is one default interface outwards.
Thus not only the SELECTed ssh/scp/ping/traceroute can be blessed, rather the whole world can work as usual with common sense.

--
Aaron


From: James Liao <james.liao@pica8.com>
Date: Wednesday, May 20, 2020 at 8:14 AM
To: Aaron Shang <aaron.shang@pica8.com>, Mikel Tang <mikel.tang@pica8.com>, Yachal Chen <yachal.chen@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>, TACinternal <tacinternal@pica8.com>
Subject: Re: Management VRF

Aaron, thanks for showing this. This is what I am concerned of.

Hai,

This was my concern – the behavior change will hit our customers by surprise. We could have done a little more to make the product more mature, but if we always stop at 90%, we always look like a beta code.
1.       I need PLM to work with engineering to at least guarantee the CLI does not have the same surprise.
2.       This is the behavior of Linux prompt, which is less impactful. However, it still does not make sense. Apparently, the Linux tools assume a default VRF, what is our default VRF? Why is it not defined as mgmt-vrf?

These are devils in the details. Even if it is a lot of work to  make it look right, I need engineering to bring it to PLM for trade-off evaluation.

Lastly, to all QA and Development, WE OWN THE PRODUCT QUALITY TOGETHER. IF WE DO NOT CARE ABOUT QUALITY, WE WILL NOT WIN. If you see any design that you have concerns, please talk to Lin. If you are not convinced with the answer, please bring it to ME.

Aaron, thanks for bringing this up. I am not sure what is the right behavior, but I am glad that you show this to PLM.

James

From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, May 20, 2020 at 2:07 AM
To: Mikel Tang <mikel.tang@pica8.com>, Yachal Chen <yachal.chen@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>, TACinternal <tacinternal@pica8.com>
Subject: Re: Management VRF

I got a new image installed via onie, then after login I want to check the connection, without any other actions.

Do you think it acceptable?

admin@Xorplus:~$ ping 10.10.50.50
connect: Network is unreachable

admin@Xorplus:~$ sudo ip vrf exec mgmt-vrf ping 10.10.50.50
PING 10.10.50.50 (10.10.50.50) 56(84) bytes of data.
64 bytes from 10.10.50.50: icmp_seq=1 ttl=63 time=0.210 ms
.
.
.


--
Aaron

From: Mikel Tang <mikel.tang@pica8.com>
Sent: Wednesday, May 20, 2020 09:43
To: Yachal Chen <yachal.chen@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; TACinternal <tacinternal@pica8.com>
Subject: RE: Management VRF

Hai,

I also don't know any customers who use VRF.

Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: Yachal Chen <yachal.chen@pica8.com>
Sent: Wednesday, May 20, 2020 9:09 AM
To: Zoneson Chen <zoneson.chen@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; TACinternal <tacinternal@pica8.com>
Subject: RE: Management VRF

No


From: Zoneson Chen
Sent: Tuesday, May 19, 2020 6:05 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>; TACinternal <tacinternal@pica8.com>
Subject: Re: Management VRF

Hai,

I do not know any customer who uses VRF yet. Do you know whether Boingo will use it?

Thanks,

Zoneson

From: Hai Vo-Dinh <hai.vodinh@pica8.com>
Date: Tuesday, May 19, 2020 at 5:35 PM
To: TACinternal <tacinternal@pica8.com>
Subject: Management VRF

TAC team,

Do you know of any customer who currently has management VRF configured in their network?  Aside from the OEM such as Lenovo.

Thanks,
Hai

--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
O: (833) 888-7422 x203
M: (408) 389-9422
hai.vodinh@pica8.com










By design googlefonts is a cached mechanism, so it can usually keep working once loaded until the cache is cleared.


For your curiosity, you can try our Gitlab setup which has lightweight built-in project tracking basics.
Let me know if you had trouble logging in. Found you had login `jliao` there and just updated the mail as james.liao@pica8.com

http://10.10.50.50/pica8/picos/-/boards

--
Aaron

From: James Liao <james.liao@pica8.com>
Sent: Tuesday, April 21, 2020 10:13
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Lin Du <lin.du@pica8.com>
Subject: Re: PDLC (teamworks) site

This is a big problem. Even if you have worked around it, other teams still have the same problem. If Googlefonts is a dead end, I need to find a different product management solution.

From: Aaron Shang <aaron.shang@pica8.com>
Date: Monday, April 20, 2020 at 6:22 PM
To: James Liao <james.liao@pica8.com>
Cc: Lin Du <lin.du@pica8.com>
Subject: Re: PDLC (teamworks) site

Last morning Tom gave me a shadowsocks proxy that can help. It's OK now.

I also troubleshot the root cause and found them:
•	The site uses googlefonts for frontend UI, which is blocked here.
•	Lots of its assets are using AWS s3, which is also not always accessible.
So both Chrome and Firefox have the same result.

Anyway, I can access now via that ShadowSocks tunnel.


--
Aaron

From: James Liao <james.liao@pica8.com>
Sent: Monday, April 20, 2020 08:07
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Lin Du <lin.du@pica8.com>
Subject: PDLC (teamworks) site

Aaron,

Can you give me a little more details on how the Teamworks site does not work for you?

1.	Did it ever work?
2.	Is it password problem?
3.	Did you try different web browser or different desktop/laptop?

I need to get it to work for you. The more clues you can give me, the faster I can pinpoint the root cause.

James







./glim.sh
Found partition with label 'GLIM' : /dev/sdc1
Found block device where to install GRUB2 : /dev/sdc
Found mount point for filesystem : /mnt
Install for EFI in addition to standard BIOS? (Y/n) y
Ready to install GLIM. Continue? (Y/n) y
Running grub2-install --target=i386-pc --boot-directory=/mnt/boot /dev/sdc (with sudo) ...
Installing for i386-pc platform.
Installation finished. No error reported.
Running grub2-install --target=x86_64-efi --efi-directory=/mnt --removable --boot-directory=/mnt/boot /dev/sdc (with sudo) ...
Installing for x86_64-efi platform.
grub2-install: error: /mnt doesn't look like an EFI partition.
ERROR: grub2-install returned with an error exit status.


--
Aaron

From: Vincent Wu <vincent.wu@pica8.com>
Sent: Friday, January 3, 2020 17:06
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>; Lin Du <lin.du@pica8.com>; arch <arch@pica8.com>
Subject: FRR design doc updated

Hi All,
I have updated this design doc. Please have a review and let me know the commets. Thanks!

Regards,
Vincent




    for i in wim.fu; do echo -e "$i\n$i\n" | sudo pdbedit -a -u $i -t; done







--
Aaron

From: Niraj Jain <niraj.jain@pica8.com>
Sent: Tuesday, December 24, 2019 19:23
To: JitendraKumar.Gupta@Dell.com <JitendraKumar.Gupta@Dell.com>; Sandeep.R@dell.com <Sandeep.R@dell.com>; Raghavendra.S1@dell.com <Raghavendra.S1@dell.com>
Cc: Naim.Khan@dell.com <Naim.Khan@dell.com>; Ravi.Gutta@dell.com <Ravi.Gutta@dell.com>; Sandeep.Hn@dell.com <Sandeep.Hn@dell.com>; Sarthak.Das@Dell.com <Sarthak.Das@Dell.com>; Bill.Putorti@dell.com <Bill.Putorti@dell.com>; Toshiaki.Sakabe@dell.com <Toshiaki.Sakabe@dell.com>; Shankar.S@Dell.com <Shankar.S@Dell.com>; support@pica8.com <support@pica8.com>
Subject: Re: Need clarifications on Infosys query

Hi Sandeep,
Here is a more detailed reply.  I am also including the Pica8 Support team in this email, to keep everyone on the same page.

First, I have worked with Steve Atwell in Global Partner Relations to setup coordinated partner support.  The procedures for handling incidents, opening tickets, and escalation are outlined in the attached document, which is updated periodically.  In case there are any questions about the process, please direct them to me.

As you identified below, the customers should be able to contact their local Dell TAC and open a case.  The Dell team will initiate basic queries and screen for hardware issues, if any.  Any software problems will be relayed to Pica8 Support, best done by opening a ticket on the Pica8 Support Portal at the appropriate priority level (Priority 3 is used for Standard or Normal incidents);  If an email is sent to Support@pica8.com identifying the customer name and priority in the subject line, a ticket will be opened automatically.

Once a case is opened, status will be updated continuously in accordance with incident severity level, and will be available to Dell TAC personnel by accessing the ticket online.  Pica8 TAC will work directly with customer contact(s) (identified in the ticket) to investigate and follow up on the problem diagnosis and resolution.

Pica8 provides 24x7 Support to enterprise customers on platinum support, out of our respective support centers depending on time of day.  Phone support is available, while preferred method of contact is email or opening a ticket through the support portal.  Urgent incidents occurring during IST working hours will be handled by our Beijing TAC, where Mikel Tang is the designated contact for Infosys, and Incidents after 9 pm IST will mostly likely be picked up by our USA TAC where Nirmal Karia is the designated contact.

Prior to the Infosys installation, we are planning to provide a basic remote training session on Pica8’s OS to the India TAC, followed by participation of selected TAC personnel in the all day hands-on training session onsite at Infosys during the installation and go live.  This should cover items 4 and 5 in your questions below.

Please let me know if you have additional questions.

Regards,
Niraj


Niraj Jain
COO

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
M: +1 408 802 0105
niraj@pica8.com  |  www.pica8.com
Follow us on Twitter




From: "JitendraKumar.Gupta@Dell.com" <JitendraKumar.Gupta@Dell.com>
Date: Monday, December 23, 2019 at 6:11 AM
To: "Sandeep.R@dell.com" <Sandeep.R@dell.com>, "Raghavendra.S1@dell.com" <Raghavendra.S1@dell.com>, Niraj Jain <niraj.jain@pica8.com>
Cc: "Naim.Khan@dell.com" <Naim.Khan@dell.com>, "Ravi.Gutta@dell.com" <Ravi.Gutta@dell.com>, "Sandeep.Hn@dell.com" <Sandeep.Hn@dell.com>, "Sarthak.Das@Dell.com" <Sarthak.Das@Dell.com>, "Bill.Putorti@dell.com" <Bill.Putorti@dell.com>, "Toshiaki.Sakabe@dell.com" <Toshiaki.Sakabe@dell.com>, "Shankar.S@Dell.com" <Shankar.S@Dell.com>
Subject: RE: FW: Need clarifications on Infosys query

Hi Sandeep – Introducing with Niraj Jain @ COO , PICA 8 ... If required let us have  a quick call over India specific support structure for PICA8 clients early morning before North America closes for Christmas / New year holidays.

Hi Niraj - Sandeep leads our Networking TAC support team based out of Bangalore...Sandeep can be reached at +91- 98452-8795

From: R, Sandeep <Sandeep_R@Dell.com>
Sent: Monday, December 23, 2019 7:22 PM
To: S1, Raghavendra; Gupta, JitendraKumar
Cc: Khan, Naim; Gutta, Ravi; HN, Sandeep; Das, Sarthak; Putorti, Bill; Sakabe, Toshiaki; Subramanian, Shankar
Subject: RE: FW: Need clarifications on Infosys query

Hello Jitendra,

Thanks for your call and explaining the order in detail and I am in agreement to the support that’s been asked.

The plan that I have for support is as below.

If it’s a hardware problem, we are 100% confident of supporting it to any level. The question is only when the problem turns out to be a OS / configuration.
I have opened a test ticket with PICA8 to see the connectivity between PICA8 TAC and DellEMC TAC.
Once I get a response to my ticket, the road would be clear for DellEMC to open a ticket directly with PICA8 TAC on behalf of customer.

I will wait today evening for their response and connect with you or Raghu for further discussion.

Few other points that I would need clarification are
1.	Is PICA8 support 24/7.
2.	Will PICA8 TAC follow with customer for troubleshooting or will DellEMC TAC has to work with customer with instructions. I would prefer if PICA8 TAC take responsibility of working with customer directly once DellEMC TAC logs an incident.
3.	Escalations matrix to PICA8 TAC.
4.	What all are the requirements that we need to capture from OS level before reaching out to PICA8 and the commands to execute it
5.	Does DellEMC TAC get basic level of understanding of PICA8.

Regards,
Sandeep R






个人业绩、能力、贡献等基本情况

负责产品核心操作系统的架构设计，安全监察，组件精简，以及相关的代码审阅走查、团队协作支持。
负责每日研发测试所需基础设施与工具的设计、运维、检察，性能改进。
协助推进研发测试与发布支持等项目管理细节的协调与优化。
负责核心产品的每日构建，协助保障产品生命周期的构建、验证、定制、发布以及调试、支持维护等。

--
Aaron

From: Aaron Shang <aaron.shang@pica8.com>
Sent: Friday, November 22, 2019 18:56
To: Celine Wang <celine.wang@pica8.com>
Subject: Re: 北京市工作居住证续签

请看是否合适

申请报告，个人陈述
商青华，男，41岁（1978年5月3日）。本人于2001年12月31日于山东大学计算机软件与理论专业毕业，获得硕士研究生毕业证书（证书编号：00184764，发证时间：2001年12月31日），并获得硕士学位证书（证书编号：104223010606，发证时间：2001年12月31日），学历认证报告编号：1042 2120 0102 0063 2。2002年9月至2008年7月于中国科学院软件研究所计算机软件与理论专业学习，获得博士研究生结业证书（证书编号： 0000142，发证时间：2008年7月1日），学历认证报告编号：8000 1120 0801 0900 09。
本人现在于北京品科技术有限公司工作，从事高端互联网络路由与交换设备核心操作系统方面的研发，公司属于美国加州创业公司Pica8于2009年在北京设立的常设研发机构，以提供十多年的先进软件系统的研发服务。在此之前本人自2002年3月开始于中科院软件所的基础软件国家工程中心等部门工作，并在2002年至2008年于中国科学院大学研究生院参加计算机软件与理论专业博士课程学习，同时在软件研究所先后承担过多个高安全等级操作系统方面国家不同课题的研究与工程项目。
本人现在从事的产品属于互联网络核心的路由与交换设备，是保障互联网络稳定高效与安全运行的骨干设备，公司产品属于目前国际领先的软件定义网络项目，具有先进的可编程、大规模网络设备的管理与接口。日常从事的具体职责在设备底层核心的操作系统部分，为上层路由与交换协议的运转提供坚实的基础系统，提供丰富接口与部分核心功能，并从总体上保障整个系统的安全与访问控制。
作为核心员工，本人担任系统架构师职务，负责产品核心操作系统的架构设计，包括系统中各组件的选型调研，同类功能组件的评测选择，以及保持其数量与占用空间的足够精简，并维护所有组件的恰当更新与定制；负责系统安全监察与增强，定期检查重要安全威胁与漏洞的报告、漏洞分析与评级、安全补丁与测试；负责系统整体性能与稳定，设计性能评测，克服潜在的性能瓶颈，提供最优的性能改进；负责相关部分的代码审阅，组织进行必要的检查点与执行代码走查；负责团队协作系统与工具的选择、构建、运行与支持，保证高效的基础工具运行。同时注意追踪同类产品方向的主流技术发展趋势，保持技术方案、框架、依赖库等选择的最优化，以及保持良好的研发及部署生态，以提高开发效率，减少过时技术的维护成本。
此外本人还负责整个团队日常研发与测试工作所需的代码基础设施与工具的设计、运维、检察，性能改进，采用最优秀的代码仓库托管与协作系统，提供全生命周期的先进的分支管理、自动构建、自动测试、持续集成、持续部署，缺陷追踪，用例覆盖以及基本的项目管理功能。还负责核心产品的每日构建，协助保障产品生命周期的构建、验证、定制，以尽可能自动的方式，提供清晰的产品发布以及调试、支持维护等所需的产出。日常通过与各团队的沟通协调，协助推进研发、测试与发布方面的支持，以及其他项目管理的诸多细节的完成与优化。
在过去的工作和生活中，本人遵纪守法，按章纳税，为首都的建设与发展积极作出应有的贡献，也积极参加各部门组织的社会活动以及所在工会的文体与职工权益保障活动，同时也受到了北京市的公共安全与其他管理部门以及人力资源和社会保障部门的很多协助，三年前申请通过的北京市工作居住证，给了我和家庭很多的权益保障，在各方面有助于工作与生活的安心与便利。在此期满申请续签之际，希人社局能够继续给予许可，以方便于后续的工作与家人教育便利和发展，望负责审核的同志批准为盼，如顺利通过，当万分感激。






Hi, Niraj,

I guess the cause might be that your browser forced HTTP to HTTPS while 10.10.50.50 had been running a self-certed HTTPS service on 443 port.

I just stopped and disabled that HTTPS. So you can please try to connect without forcing a HTTPS(default port 443) link.

If still not OK, please take a screenshot of the browser tab, and your outout from running:

    $ curl -I 10.10.50.50


I don't think it was due to VPN. Since you can access PA lab, you should also be able to access 10.10.50.50 section LAN.




________________________________________
From: Niraj Jain <niraj.jain@pica8.com>
Sent: Friday, October 29, 2021 08:34
To: Aaron Shang
Subject: Re: Account was created for you

Aaron,
I already tried that and I just get a spinning wheel - nothing happens.  I assuming this is because the git server is inside your network, and I have to setup a VPN connection first?  In that case, I will also need VPN credentials unless I can use my existing Pica8 SSO credentials.

Please clarify.

Niraj

On 10/28/21, 1:28 AM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

    How about "request a new one"?


    If I reset a new one, you had to change to another. So please try request one first, if not OK I will reset one then.

    ________________________________________
    From: Niraj Jain <niraj.jain@pica8.com>
    Sent: Thursday, October 28, 2021 15:00
    To: Aaron Shang
    Subject: FW: Account was created for you

    Aaron,
    I did not activate it in time.  Could you please trigger a new password link?

    Thanks,
    Niraj

    From: Pica8 Gitlab <git@pica8.local>
    Reply-To: Pica8 Gitlab <git@pica8.local>
    Date: Wednesday, October 20, 2021 at 7:13 AM
    To: Niraj Jain <niraj.jain@pica8.com>
    Subject: Account was created for you


    Hi Niraj Jain!

    The Administrator created an account for you. Now you are a member of the company GitLab application.

    login.......................................... niraj.jain@pica8.com

    Click here to set your password<http://10.10.50.50/users/password/edit?reset_password_token=xyuNZ1zcAYEU119SYw-z>

    This link is valid for 2 days. After it expires, you can request a new one<http://10.10.50.50/users/password/new?user_email=niraj.jain%40pica8.com>.

    —
    View it on GitLab<http://10.10.50.50/niraj.jain>.
    You're receiving this email because of your account on 10.10.50.50. If you'd like to receive fewer emails, you can adjust your notification settings.






----



如需要自行编译可以以build运行：

        /home/build/make-image 2.11.25.2 as4610






Hi, Vic,

Do you now is there any quick commands to operate on LEDs?


--
Aaron

From: Greg Michaels <Greg.Michaels@pica8.com>
Sent: Wednesday, January 22, 2020 03:36
To: support@pica8.com <support@pica8.com>
Subject: Question

Support,

Is there a command in the CLI or Linux that can turn off all interface LEDs, however you would enable one to show a field tech which port to connect a device; this would not disrupt the traffic on the data-plane/switch operation, this would just be an indicator as a visual indicator.

CCSD asked for this. Not a high priority, just very cool enhancement to have!









For the keys, you may need to add the public keys from deb archives as below:

sudo apt-key adv --recv-keys --keyserver keys.gnupg.net KEYS


In this case, please try this:

sudo apt-key adv --recv-keys --keyserver keys.gnupg.net 7638D0442B90D010 9D6D8F6BC857C906


For the pica8 packages lines, since there were no those releases, you can safely comment out the line by adding a `#` at the beginning of that line:
#deb .... packages.pica8.com ...



--
Aaron

From: david.liu2@verizon.com <david.liu2@verizon.com>
Sent: Thursday, November 28, 2019 03:28
To: Aaron Shang <aaron.shang@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; support@pica8.com <support@pica8.com>
Subject: Re: [E] Re: Apt-get update error

Hi Arron,

Added & got the following, please take a look, thx

David

root@TB2-DC1-FB1$apt-get update
Ign http://packages.pica8.com as5812_54x Release.gpg
Ign http://packages.pica8.com as5812_54x Release
Err http://packages.pica8.com as5812_54x/v2.11.3.vzsdn.3 amd64 Packages
  301  Moved Permanently
Ign http://packages.pica8.com as5812_54x/v2.11.3.vzsdn.3 Translation-en
Hit http://archive.debian.org wheezy Release.gpg
Ign http://security.debian.org wheezy/updates Release.gpg
Ign http://http.debian.net wheezy Release.gpg
Get:1 http://archive.debian.org wheezy/updates Release.gpg [1601 B]
Ign http://security.debian.org wheezy/updates Release
Hit http://archive.debian.org wheezy Release
Ign http://http.debian.net wheezy-updates Release.gpg
Hit http://archive.debian.org wheezy/updates Release
W: There is no public key available for the following key IDs:
7638D0442B90D010
W: There is no public key available for the following key IDs:
9D6D8F6BC857C906
E: Release file for http://archive.debian.org/debian-security/dists/wheezy/updates/Release is expired (invalid since 231d 4h 25min 31s). Updates for this repository will not be applied.
root@TB2-DC1-FB1$cat sources.list
#deb http://ftp.debian.org/debian stable main
#deb http://http.debian.net/debian wheezy-backports main
#deb http://ftp.debian.org/debian wheezy main
#deb http://ftp.debian.org/debian unstable main

deb http://http.debian.net/debian wheezy main
deb-src http://http.debian.net/debian wheezy main

deb http://http.debian.net/debian wheezy-updates main
deb-src http://http.debian.net/debian wheezy-updates main

deb http://security.debian.org/ wheezy/updates main
deb-src http://security.debian.org/ wheezy/updates main
deb http://packages.pica8.com/pica8/ as5812_54x v2.11.3.vzsdn.3
#deb http://archive.debian.org/debian/ wheezy main contrib
deb http://archive.debian.org/debian wheezy main non-free contrib
deb http://archive.debian.org/debian-security wheezy/updates main non-free contrib
root@TB2-DC1-FB1$

From: Aaron Shang <aaron.shang@pica8.com>
Date: Tuesday, November 26, 2019 at 4:45 PM
To: "Liu, David Damin" <david.liu2@one.verizon.com>, Zoneson Chen <zoneson.chen@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [E] Re: Apt-get update error


The official Debian 7/8 repo had been archived due to end of normal life cycle.
Although there would be no security updates, users can still install existing released packages by pointing to http://archive.debian.org/ in /etc/apt/sources.list

    deb http://archive.debian.org/debian wheezy main non-free contrib
    deb http://archive.debian.org/debian-security wheezy/updates main non-free contrib


Please try like above lines. It works for me on Debian 7/8 ( wheezy / jessie) on our boxes.


--
Aaron

From: david.liu2@verizon.com <david.liu2@verizon.com>
Sent: Wednesday, November 27, 2019 02:44
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Subject: Re: [E] Re: Apt-get update error

Hi Zoneson and Aaron,

Thanks, any help would be great

David

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Tuesday, November 26, 2019 at 10:41 AM
To: "Liu, David Damin" <david.liu2@one.verizon.com>
Cc: Tom Jia <tom.jia@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Subject: [E] Re: Apt-get update error

Hi David,

I am sorry that Debian 7 support has reached its end-of-life last year. Add Aaron who may be able to help.

Thanks,

Zoneson

From: "david.liu2@verizon.com" <david.liu2@verizon.com>
Date: Tuesday, November 26, 2019 at 9:35 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Subject: Apt-get update error

Hi Zoneson,

Trying to update apt-get to install some Debian packages, but received following error, please help, thanks

David

root@TB2-DC1-FB1$apt-get update
Ign http://packages.pica8.com as5812_54x Release.gpg
Ign http://packages.pica8.com as5812_54x Release
Err http://packages.pica8.com as5812_54x/v2.11.3.vzsdn.3 amd64 Packages
  301  Moved Permanently
Ign http://packages.pica8.com as5812_54x/v2.11.3.vzsdn.3 Translation-en
Ign http://security.debian.org wheezy/updates Release.gpg
Ign http://security.debian.org wheezy/updates Release
Err http://security.debian.org wheezy/updates/main Sources
  404  Not Found [IP: 151.101.40.204 80]
Err http://security.debian.org wheezy/updates/main amd64 Packages
  404  Not Found [IP: 151.101.40.204 80]
Ign http://security.debian.org wheezy/updates/main Translation-en
Ign http://http.debian.net wheezy Release.gpg
Ign http://ftp.debian.org wheezy Release.gpg
Ign http://http.debian.net wheezy-updates Release.gpg
Ign http://http.debian.net wheezy-backports Release.gpg
Ign http://http.debian.net wheezy Release
Ign http://ftp.debian.org wheezy Release
Ign http://http.debian.net wheezy-updates Release
Ign http://http.debian.net wheezy-backports Release
Err http://http.debian.net wheezy/main Sources

Err http://http.debian.net wheezy/main amd64 Packages

Err http://http.debian.net wheezy-updates/main Sources

Err http://http.debian.net wheezy-updates/main amd64 Packages

Err http://ftp.debian.org wheezy/main amd64 Packages
  404  Not Found [IP: 130.89.148.12 80]
Err http://http.debian.net wheezy-backports/main amd64 Packages

Ign http://ftp.debian.org wheezy/main Translation-en
Err http://http.debian.net wheezy/main Sources

Err http://http.debian.net wheezy/main amd64 Packages

Err http://http.debian.net wheezy-updates/main Sources

Err http://http.debian.net wheezy-updates/main amd64 Packages

Err http://http.debian.net wheezy-backports/main amd64 Packages

Err http://http.debian.net wheezy/main Sources

Err http://http.debian.net wheezy/main amd64 Packages

Err http://http.debian.net wheezy-updates/main Sources

Err http://http.debian.net wheezy-updates/main amd64 Packages

Err http://http.debian.net wheezy-backports/main amd64 Packages

Err http://http.debian.net wheezy/main Sources

Err http://http.debian.net wheezy/main amd64 Packages

Err http://http.debian.net wheezy-updates/main Sources

Err http://http.debian.net wheezy-updates/main amd64 Packages

Err http://http.debian.net wheezy-backports/main amd64 Packages

Err http://http.debian.net wheezy/main Sources
  404  Not Found [IP: 151.101.40.204 80]
Err http://http.debian.net wheezy/main amd64 Packages
  404  Not Found [IP: 151.101.40.204 80]
Ign http://http.debian.net wheezy/main Translation-en
Err http://http.debian.net wheezy-updates/main Sources
  404  Not Found [IP: 151.101.40.204 80]
Err http://http.debian.net wheezy-updates/main amd64 Packages
  404  Not Found [IP: 151.101.40.204 80]
Ign http://http.debian.net wheezy-updates/main Translation-en
Err http://http.debian.net wheezy-backports/main amd64 Packages
  404  Not Found [IP: 151.101.40.204 80]
Ign http://http.debian.net wheezy-backports/main Translation-en
W: Failed to fetch http://packages.pica8.com/pica8/dists/as5812_54x/v2.11.3.vzsdn.3/binary-amd64/Packages  301  Moved Permanently

W: Failed to fetch http://security.debian.org/dists/wheezy/updates/main/source/Sources  404  Not Found [IP: 151.101.40.204 80]

W: Failed to fetch http://security.debian.org/dists/wheezy/updates/main/binary-amd64/Packages  404  Not Found [IP: 151.101.40.204 80]

W: Failed to fetch http://http.debian.net/debian/dists/wheezy/main/source/Sources  404  Not Found [IP: 151.101.40.204 80]

W: Failed to fetch http://http.debian.net/debian/dists/wheezy/main/binary-amd64/Packages  404  Not Found [IP: 151.101.40.204 80]

W: Failed to fetch http://ftp.debian.org/debian/dists/wheezy/main/binary-amd64/Packages  404  Not Found [IP: 130.89.148.12 80]

W: Failed to fetch http://http.debian.net/debian/dists/wheezy-updates/main/source/Sources  404  Not Found [IP: 151.101.40.204 80]

W: Failed to fetch http://http.debian.net/debian/dists/wheezy-updates/main/binary-amd64/Packages  404  Not Found [IP: 151.101.40.204 80]

W: Failed to fetch http://http.debian.net/debian/dists/wheezy-backports/main/binary-amd64/Packages  404  Not Found [IP: 151.101.40.204 80]

E: Some index files failed to download. They have been ignored, or old ones used instead.







Here is an old proposal, just for your info, related to ONIE automation.

If we provide the best image packages, there should be least efforts for users to configure DHCP / bootp etc. options.



tl;dr:


Release picos images as compressed package, which contains the onie file that meets onie auto-discover spec, also with checksums.

Users just put the unpacked onie files into their comfortable location, then ONIE can discover that and proceed automatically.

The ONIE files could be `.bin` files for ONIE version after 2017.8, or without `.bin` extension for legacy compatibility.

    picos-<model>-<release_version>-<build_id>.zip

    picos-<model>-<release_version>-<build_id>.bin.zip

Examples.

    ├───onie-installer-dellemc_s4000_c2338
    ├───onie-installer-dellemc_s4000_c2338.md5
    ├───onie-installer-dellemc_s4000_c2338.sha512

    ├picos-s4000-3.2.1-ac3a4c0867.bin.zip
    ├───onie-installer-dellemc_s4000_c2338.bin
    ├───onie-installer-dellemc_s4000_c2338.bin.md5
    ├───onie-installer-dellemc_s4000_c2338.bin.sha512



----


Proposal to rename image to comply with ONIE spec.

# Purpose
Our images are ONIE format and targeted to be used in all ONIE-compliant hardware.

ONIE by design will detect default file names for automatic install and upgrade.

# What name can ONIE discover

According to current official spec, ONIE searches for the following default names in order.

    onie-installer-<arch>-<vendor>_<machine>-r<machine_revision>
    onie-installer-<arch>-<vendor>_<machine>
    onie-installer-<vendor>_<machine>
    onie-installer-<cpu_arch>-<switch_silicon_vendor>
    onie-installer-<arch>
    onie-installer

If an installer is successfully found, but the installer fails, ONIE moves on to the next in order.

In the case of ONIE self-update mode, the file name prefix is onie-updater instead of onie-installer.

I had tried images of the above names, all can be discovered and correctly installed.

# Why not with the `.bin` extension

From ONIE release after 2017.8, the above names with a `.bin` extension can also be recognized.

But as I checked, the latest box we had in lab in of 2017.4 ONIE build.

None of them can detect any of the above with `.bin` suffix added in my test.

If all boxes have the ONIE release after 2017.8, `.bin` file would be the best.

# Compatibility consideration
- Old ONIE can NOT recognize `.bin` extension
- Upgrade script in old 2.x PICOS release hard coded `.bin` for detecting upgrade package.

So to meet with the hard coded detection, and if we really do not want to give up upgrade from 2.x to 3.x, we can provide zip package that contains the `.bin` extension form, together with the zip containing the ones without the `.bin`.

Thus we would guide users:

**NOTE**
- If you want to upgrade, you should use the `.bin` package.
- If you are doing new install and not sure which package to use, please use the one WITHOUT `.bin` in case old ONIE release not able to recognize `.bin` extension.

So the provided package looks like the following.
The only difference of the contents is the file names.
- picos-s4000-3.2.1-ac3a4c0867.zip
- picos-s4000-3.2.1-c3a4c0867.bin.zip

    ├picos-s4000-3.2.1-ac3a4c0867.zip
    ├───onie-installer-dellemc_s4000_c2338
    ├───onie-installer-dellemc_s4000_c2338.md5
    ├───onie-installer-dellemc_s4000_c2338.sha512

    ├picos-s4000-3.2.1-ac3a4c0867.bin.zip
    ├───onie-installer-dellemc_s4000_c2338.bin
    ├───onie-installer-dellemc_s4000_c2338.bin.md5
    ├───onie-installer-dellemc_s4000_c2338.bin.sha512

That also benefit OEM variant name and name sharing scheme, because neither of these names can be recognized by ONIE.

# What name is proposed for PICOS releases

- ONIE image, with check sums

    onie-installer-<vendor>_<machine>

    onie-installer-<vendor>_<machine>.md5

    onie-installer-<vendor>_<machine>.sha512

- Release package

    picos-<model>-<release_version>-<build_id>.zip

    picos-<model>-<release_version>-<build_id>.bin.zip

We should package them into a more readable name, like versions,

- picos-s4100-3.6.5.zip
- picos-s4100-3.6.5-garland.zip

Or with build ID as

- picos-s4100-3.6.5-garland-63b9bda101.zip

Or using commercial product names

- picos-Z9100-ON-3.8.7-63b9bda101.zip
- picos-S4128F-ON-3.8.7-63b9bda101.zip

Or with OEM variant name as

- picos-HPE_AL_6921X-3.8.7-30f3897332.zip
- picos-HPE_AL_6960-3.8.7-30f3897332.zip

NOTE, one release version MUST be mapped only to one build id (git commit SHA1 in our repo).

Only this way, the release can be controlled, and tracked.

# How to deal with OEM OS variants, product naming and name sharing
As shown above as example, we can express them in package names containing ONIE spec-compliant image.

The commercial name such as S4128F-ON or name sharing such as HPE_AL_6921X had been stored in `/sys/class/swmon/hwinfo/product_name` and reflected into `/etc/picos/branding` for consistent run time usage.

# Why using this and why not other names

For the first one

    onie-installer-<arch>-<vendor>_<machine>-r<machine_revision>

The last machine revision field is easily prone to change. And the change is controlled by vendor.
We should avoid maintenance efforts.

For another candidate

    onie-installer-<arch>-<vendor>_<machine>

The `arch` part would be puzzling by names of x86, x86_64, amd64, arm, armel, ppc, powerpc, etc.

And once `vendor_machine` is given, the `arch` can also be clear, exact one.

And in near future, changes can be expected in industry for the `arch` part. Linux kernel had renamed x86_64 to x86 for 64 bit x86, amd64 had been a long time common usage for that in many Linux systems.

Even as planned in future releases, we might combine image building to one round for each of x86 and arm arch, the images with these ONIE names can be generated during the one build round.

As for the others, they are too generic and may refer to lots of models.

    onie-installer-<cpu_arch>-<switch_silicon_vendor>
    onie-installer-<arch>
    onie-installer

And the switch_silicon_vendor form can only be recognized after ONIE 2015 releases, while many of current boxes were ONIE releases before that.

# How to decide these fields

The `vendor_machine` field can be decided from ONIE console, with onie-sysinfo command options:

    -m
        ONIE machine string

Example.

    ONIE:/ # onie-sysinfo -m
    dell_z9100_c2538

    ONIE:/ # onie-sysinfo -m
    dellemc_s4100_c2338

- `arch` is fixed as one of these 3:
    - arm
    - powerpc
    - x86_64

NOTE: Names as ppc, armel, amd64, or x86, did not work here as in my test.

- `vendor_machine` is a string for vendor and model.
    - This ONIE machine string can be read from `onie-sysinfo -m`.
    - Here machine is the model.

NOTE: Changing the machine to any form of commercial off-the-shelf name like S4048ON,S4128F-ON,Z9100-ON did not work.

# What is valid for the strings
The above definitions place some restrictions on the valid characters allowed for the `ARCH`, `VENDOR` and `MODEL` strings.

- VENDOR - cannot contain _ (underscore) or - (hyphen) characters
- MODEL - cannot contain - (hyphen) character. _ (underscore) is OK
- ARCH - cannot contain _ (underscore) or - (hyphen) characters

NOTE: The above on ARCH line might be typo of spec, actually x86_64 is the name in spec, while it contain underscore.

# Example valid names

I had tried the following names, in order of choice.

- onie-installer-x86_64-dellemc_s4100_c2338
- onie-installer-dellemc_s4100_c2338
- onie-installer-x86_64
- onie-installer

The proposed one is

- onie-installer-dellemc_s4100_c2338

# How to deal with the release version and build id
- Release version will be decided by the link path of directory name, seen as in

    https://www.pica8.com/picos-releases/

- If required, package the ONIE file into ZIP file with version and build id in name.

# What need to do

- Document the change for 3.x releases; If required by customers, for 2.x future releases too.
- Make the change in normal and OEM variant build scripts.

# Reference

- https://opencomputeproject.github.io/onie/design-spec/discovery.html

# Current status
- None of the current naming can be detected by ONIE for what ONIE is initiated for OS install automation.
- It is not consistent in different releases and OEM remix builds.

Example of current names, none of which can be ONIE spec compliant.

    /tftp/build/release/garland/2.11.1.npb.7/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-7220fec.bin
    /tftp/build/release/garland/2.11.1.npb.3/as5812_54x/onie-installer-amd64-as5812_54x-PICOS-2.11.npb.3-9e9ae8f.bin
    /tftp/build/release/garland/2.11.1.npb.6/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-402b880.bin
    /tftp/build/release/garland/2.11.16.npb.2/onie-installer-amd64-as7712_32x-PICOS-2.11.16-npb-7107deb.bin
    /tftp/build/release/garland/2.11.1.npb.5/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-698db9b.bin
    /tftp/build/release/garland/2.11.16.npb.3/onie-installer-amd64-as7712_32x-PICOS-2.11.16-npb-3d57b6d.bin
    /tftp/build/release/2.9.1/luxartech-npb/onie-installer-x86-dcs7032q28-NpbOS-2.9.1-ad4256e.bin
    /tftp/build/release/luxartech/100gnpb/2.9.2.10/onie-installer-x86-dcs7032q28-NpbOS-2.9.2.10-b4ea382.bin
    /tftp/build/release/luxartech/100gnpb/onie-installer-x86-dcs7032q28-NpbOS-2.9.2.7-a068838.bin
    /tftp/build/release/2.9.1.2/luxartech-npb/onie-installer-x86-dcs7032q28-NpbOS-2.9.1-e9c9eaf.bin
    /tftp/build/daily/n3100/onie-installer-picos-n3100-3.2.1-63b9bda101.bin
    /tftp/build/daily/z9264/onie-installer-picos-z9264-3.2.1-aa3d58f.bin
    /tftp/build/daily/as7726_32x/onie-installer-picos-as7726_32x-3.2.1-63b9bda101.bin
    /tftp/build/daily/ag9032/onie-installer-picos-ag9032-3.2.1-aa3d58f.bin
    /tftp/build/daily/as5812_54t/onie-installer-picos-as5812_54t-3.2.1-63b9bda101.bin
    /tftp/build/daily/z9100/onie-installer-picos-z9100-3.2.1-63b9bda101.bin
    /tftp/build/daily/as5712_54x/onie-installer-picos-as5712_54x-3.2.1-aa3d58f.bin
    /tftp/build/daily/s4100/onie-installer-picos-s4100-3.2.1-63b9bda101.bin
    /tftp/build/daily/n3000/onie-installer-picos-n3000-3.2.1-72fc38d19e.bin
    /tftp/build/release/2.11.5/ag9032/onie-installer-x86-ag9032-picos-2.11.5-ec90458.bin
    /tftp/build/release/2.11.5/as5812_54t/onie-installer-x86-accton_as5812_54t-picos-2.11.5-ec90458.bin
    /tftp/build/release/2.11.5/as5712_54x/onie-installer-x86-accton_as5712_54x-picos-2.11.5-ec90458.bin
    /tftp/build/release/2.11.5/as7312_54x/onie-installer-x86-accton_as7312_54x-picos-2.11.5-ec90458.bin
    /tftp/build/release/2.9.2.5/HPE_AL_6921T/onie-installer-x86-HPE_AL_6921T-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/arctica4806xp/onie-installer-x86-penguin_arctica4806xp-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/as5812_54x/onie-installer-x86-accton_as5812_54x-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/HPE_AL_6940/onie-installer-x86-HPE_AL_6940-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/as6712_32x/onie-installer-x86-HP6712-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/HPE_AL_6920/onie-installer-x86-HPE_AL_6920-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/as5812_54t/onie-installer-x86-accton_as5812_54t-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/z9100/onie-installer-x86-DELL_z9100-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/HPE_AL_6921X/onie-installer-x86-HPE_AL_6921X-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/HPE_AL_6960/onie-installer-x86-HPE_AL_6960-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/HP6712/onie-installer-x86-HP6712-picos-2.9.2.5-30f7332.bin
    /tftp/build/release/2.9.2.5/as5712_54x/onie-installer-x86-accton_as5712_54x-picos-2.9.2.5-30f7332.bin

----

The following methods are tried in this order:

    Statically configured (passed from boot loader)
    Local file systems (USB for example)
    Exact URLs from DHCPv4
    Inexact URLs based on DHCP responses
    IPv6 neighbors
    TFTP waterfall

--
Aaron







产品选择
宽带速率

套餐合约期

选择付款方式
在线支付


订单金额
￥2664
输入联系信息
联系人
商青华
联系电话
(优选北京联通手机号码)
17611261571
是否需要受理明细

是否需要发票
发票

接收邮箱
aaronshang@gmail.com
是否接收活动推送

立即下单

 我已阅读并同意 《北京联通公众宽带产品业务须知》
提示:请阅读后再勾选,最终受理内容以实际办理业务为准。
20180517-BJ-01

中国联通客户入网服务协议
甲方： 客户

通信运营企业（乙方）：中国联合网络通信有限公司北京市分公司

根据《中华人民共和国合同法》、《中华人民共和国电信条例》及其他有关法律、法规的规定，在平等、自愿、公平、诚实信用的基础上，甲乙双方就移动电话、固定电话及相关数据通信业务入网服务（以下简称通信服务）的有关事宜协商订立本协议。

第一条 入网要求

1.1 甲方办理入网、变更、退网手续时，应提交以下登记资料：

1.1.1 个人客户：提交本人有效身份证件原件，有效身份证件包括居民身份证、港澳居民往来内地通行证、台湾居民往来大陆通行证、外国公民护照等。根据国家实名登记要求，个人客户办理新入网业务需严格审核人证一致，不得委托他人办理。利用个人临时身份证件原件办理的，须同时提供公安部门出具的身份证领取凭证、身份信息辅助证件（驾照、医保卡或户口本等），不得委托他人办理。持个人临时身份证原件办理业务的客户仅可办理除新入网以外的其他类业务。

1.1.2 单位客户：提交加盖公章的单位介绍信、营业执照或事业单位法人证书或社会团体法人登记证书或组织机构代码证的原件、使用人或责任人有效身份证件原件、经办人有效身份证件原件等。

1.2 甲方应保证登记资料真实、有效、准确、完整，并对乙方核实登记资料的行为予以配合。登记资料如有变化，甲方应及时通知乙方变更。

1.3 甲方应使用获得国家入网许可的通信终端，且该终端应具有与甲方申请开通的通信服务相匹配的功能。如无法支持所选服务，甲方应自行承担后果，并向乙方全额支付其所选服务的全部费用

1.4 甲方申请开通后付费通信服务的，如户籍所在地、居住所在地（以有效身份证件或居住证载明的住址为准）或法定住所地（以营业执照或组织机构代码证等载明的单位住所为准）不在北京，应按照乙方要求缴纳保证金或由北京市市民、单位提供担保。

1.4.1甲方选择缴纳保证金的，应按照乙方要求缴纳符合规定金额的保证金。

1.4.2甲方选择北京市市民、单位提供担保的，由北京市市民或具有合法主体资格的单位提供连带责任保证担保。担保人应到乙方营业网点办理担保手续，如实填写担保资料并签字、盖章（单位担保时须加盖单位公章）。甲方需要变更担保人或担保方式的，应提供符合乙方要求的新的担保人或缴纳保证金。

第二条 费用缴纳

2.1乙方应按照公布的计费周期、资费标准、缴费期限等规定向甲方收取各项通信费用。甲方应按时足额缴纳各项通信费用。

2.2 乙方公告调整资费标准的，甲方自公告确定的新资费标准生效日起一个计费周期内未提出异议的，视为甲方同意，本协议继续履行；甲方提出异议的，双方应协商解决方案。

2.3 甲方应根据通信服务种类不同，以预付费或后付费方式缴纳通信费用。

2.3.1 甲方为预付费用户的，除双方另有约定外，应在账户预存金额，并在账户余额不足以支付拟消费的通信费用时及时充值。

2.3.2 甲方为后付费用户的，应在每月  3  日至   当月最后一   日缴纳上月通信费用。甲方未按时足额缴纳通信费用的，每日应按照欠缴金额3‰的标准支付违约金（因乙方原因导致甲方不能缴费的除外）

2.3.3 甲方账户余额不足或欠费的，乙方有权限制、暂停为甲方提供除缴费以外的其他通信服务。

2.3.4 乙方应在甲方充值或缴清欠费和违约金后的  24  小时内恢复通信服务。因余额不足或欠费被限制或暂停通信服务满60日，甲方仍未充值或缴清欠费和违约金的，乙方有权终止通信服务。

2.4 甲方定制由乙方代收费的第三方服务的，乙方可按照服务提供方公布的资费标准向甲方收取费用。甲方对代收费用有异议的，应与服务提供方协商解决，并可要求乙方提供必要协助。

2.5 甲方通信终端中软件运行、升级产生的费用，由甲方自行承担。

第三条 通信服务

3.1 网络服务

3.1.1 乙方应按照国家标准或行业标准，以其网络和设施依甲方申请提供迅速、准确、安全、方便的通信服务，并依法保障甲方的通信自由和通信秘密。

3.1.2 甲方在乙方承诺范围内申请开通默认服务以外的其他通信服务的，应按照乙方规定办理相应手续。乙方应在承诺时限内开通服务（双方另有约定的除外），否则应采取费用减免等方式对甲方予以补偿。

3.1.3甲方申请开通国际或港澳台漫游服务的，乙方可根据甲方信用评级情况要求甲方缴纳一定金额的预付款。其中国际漫游服务只能在乙方签订有自动漫游协议的国家或地区的电信运营商网络覆盖范围内享有。

3.1.4 甲方申请固定电话新装、移装的，乙方应在承诺时限内（城市最长25日，农村最长30日）开通；因乙方原因未按时开通的，乙方应每日按照收取费用金额1%的标准支付违约金。

3.1.5 甲方申告通信服务障碍的，乙方应自接到申告之时起及时（固定电话城镇48小时、农村72小时内；移动电话48小时内；互联网接入设备12小时内）修复或调通；不能如期修复或调通的，乙方应及时通知甲方，并减免障碍期间的相关通信费用，但因甲方原因导致通信服务障碍的除外。

3.1.6 甲方申请暂停、停止某项通信服务的，乙方应在承诺时限内（最长不超过受理后24小时）暂停或停止。乙方未按时暂停或停止的，甲方不承担因该项服务发生的通信费用。

3.1.7 乙方对终止通信服务的电话号码应至少冻结90日后，方可重新投入使用。

3.1.8 甲方申请办理过户手续的，应先缴清通信费用和违约金（如有），并持过户双方有效证件办理过户手续。

3.1.9 因乙方过错导致甲方通信服务在正常使用中被限制、暂停、终止且销号未满90日的，乙方应在甲方申告核实后立即恢复，并采取费用减免等方式对甲方予以补偿；销号超过90日且已重新分配给其他客户使用的，双方应协商解决方案。

3.1.10 由于工程施工、网络调整、码号割接等非甲方原因需变更甲方电话号码的，乙方应至少提前45日通知甲方，并至少提前15日告知甲方新的电话号码；如需变更电话后四位号码的，应允许甲方在一定范围内免费选择新号。电话号码变更实施日起至少45日内，乙方应向甲方的所有来电客户播放改号提示音。

3.2 客户服务

3.2.1甲方可通过乙方客服电话  10010  、官方网站  www.10010.com   了解、咨询关于网络情况、业务知识、服务内容及各类临时性活动等信息。

3.2.2乙方对甲方的通信费用原始数据应至少保存5个月，并向甲方免费提供通信费用详细清单查询。对甲方在通信费用方面的问题，乙方应明确解答、核实；经核实确属多收费用的，乙方应返还多收费用。

3.2.3甲方以自助方式定制需缴纳月功能费的通信服务的，乙方对原始定制凭证应至少保存5个月；甲方对定制开通有异议的，应在此期间向乙方提出。乙方擅自开通需缴纳月功能费的通信服务的，不得向甲方收取相应通信费用。

3.2.4乙方应以短信、电话等方式向甲方提示通信费用、数据流量等使用情况和采取限制、暂停、终止服务等技术措施的情况，但甲方不得以乙方未提示或未及时提示而拒绝缴纳通信费用和违约金。

3.2.5乙方应向甲方提供火警119、匪警110、医疗急救120、交通事故报警122电话及乙方客服电话的免费通话服务并保障通话线路畅通，且不受甲方是否账户余额不足或欠费的影响。

3.2.6甲方个人信息是指以电子或者其他方式记录的能够单独或者与其他信息结合识别甲方身份或者反映甲方活动情况的各种信息。乙方严格按照《中华人民共和国网络安全法》等法律法规的相关要求，对其在提供服务过程中收集、使用的甲方个人信息履行保护义务。在甲方使用乙方提供的服务时，乙方依据法律法规、监管政策和本协议约定收集、存储、使用、披露和保护甲方的个人信息。

3.2.7甲方理解并同意，乙方可以通过业务受理系统登记、纸质返档，通过网络接收、读取并记录等方式，以提供服务为目的，在业务活动中收集、使用甲方提供的和甲方使用服务过程中形成的个人信息。甲方同意乙方可以为向甲方提供服务、改进和完善服务、提供个性化或定制化产品与服务、评估服务中的促销与推广活动效果、软件认证或升级等目的使用个人信息，乙方有权依法对包含甲方在内的整体用户数据进行分析并加以利用，以便于为甲方提供更好服务。

3.2.8甲方理解并同意乙方将收集的甲方个人信息共享给乙方关联公司在其业务目的和范围内使用；甲方亦同意乙方为履行、改善和改进乙方在本协议项下的服务之目的将收集的必要的甲方个人信息共享给乙方的授权合作伙伴。除前述明确约定情形外，未经甲方同意，乙方不向其他第三方提供甲方个人信息。

3.2.9甲方本人持有效证件可通过自有营业厅或乙方指定的其他渠道，对其个人信息进行查询、更正。

3.2.10乙方依法保证甲方的信息资料安全、通信自由和通信秘密。乙方对甲方的身份信息和通信信息依法负有保密义务，并应采取技术措施和其他必要措施确保信息安全，防止信息泄露、丢失。在发生或可能发生信息泄露、丢失的情况时，应立即采取补救措施。因乙方原因导致甲方信息泄露的，乙方应承担相应法律责任。但以下情形不应视为乙方违反本条约定：（1）因追缴欠费需要，向第三方机构和征信机构提供用户个人相应信息及欠费信息的；（2）为向甲方提供更好的服务，通过短信、彩信、wappush、电话、电子邮件、信函、微博、微信等方式向甲方发送业务服务信息或进行互动沟通的；（3）司法、行政机关依法要求乙方提供协助与配合，乙方应给予协助与配合的；（4）出于国家安全、国防安全、公共安全、公共卫生和重大公共利益目的而未经授权的披露行为；（5）出于维护甲方或其他个人生命、财产等重大合法权益但又难以得到甲方同意的；（6）法律法规另有规定的。

3.2.11 双方约定有协议履行期限或资费标准执行期限的，乙方应在期限届满前以短信、电话等方式提示甲方是否办理续期手续以及期限届满后的可能后果。

第四条 风险控制

4.1甲方应保证入网、变更登记资料真实有效、准确完整，并有义务配合乙方对登记资料进行查验。甲方登记资料如有变更，应主动办理变更手续。因甲方提供的客户资料不详、不实或变更后未及时通知乙方等原因，使乙方无法向甲方提供服务或甲方无法享受到乙方提供的相关服务，乙方无需向甲方承担任何责任。如乙方发现因甲方登记资料失实或者甲方未配合及时更正，乙方有权限制、暂停、终止甲方服务，且乙方无需向甲方承担任何责任。

4.2电话号码、通信卡、通信终端丢失或被盗用的，甲方应及时拨打乙方客服电话或到乙方营业网点办理暂停通信服务、修改服务密码等手续，并向公安机关报案。

4.3 甲方授权他人使用电话号码、通信卡、通信终端的，自行承担相应后果。

4.4 甲方可自行设置和清除   USIM/SIM   卡的个人密码 (PIN )，初始 PIN 是 1234 。连续三次输入错误密码时将会锁卡；发生锁卡时，甲方不得自行解锁，而应携带入网时所用有效身份证件到乙方营业网点解锁。因甲方操作不当导致通信卡损坏或永久性锁死的，甲方应承担换卡所需相关费用。

4.5服务密码是甲方办理通信服务的重要凭证，除另有约定或说明外，凡使用服务密码定制、变更或终止通信服务的行为均视为甲方行为或经甲方授权的行为。入网后甲方应立即修改初始服务密码，并妥善保管自设服务密码。如因甲方原因导致服务密码泄露或为他人获取的，甲方自行承担相应后果，但乙方应协助甲方调查情况。

4.6 乙方发现甲方出现异常巨额通信费用的，应及时向甲方核实，在权限范围内采取限制、暂停通信服务等技术措施，并积极协助甲方调查情况。甲方申告通信费用异常增长的，乙方应积极协助查询，并按照甲方要求采取限制、暂停通信服务等技术措施。异常巨额通信费用，是指突然出现超过甲方此前3个月平均通信费用5倍以上的费用。

4.7 甲方未缴通信费用达到乙方规定的风险控制额度（信用额度）时，乙方应通过短信、电话等方式告知甲方。甲方应按照乙方要求及时缴纳通信费用；甲方未及时缴纳的，乙方有权暂停通信服务（本款暂停服务不受约定缴费期限的限制）。

4.8甲方使用固网及宽带业务时，未经有关部门批准许可，不得自行更改其使用性质，不得开设各类服务站点，不得利用计算机互联网络进行任何经营性服务活动，否则乙方有权停止服务，依法追缴各项费用和违约金，并不承担任何责任。

4.9 甲方所办理的数据业务下行速率标称值仅为乙方提供的数据业务下行速率最高值，乙方不能保证在任何情况下均能达到标称值，甲方对此表示知悉并认可。

4.10乙方对甲方的移动电话网络数据流量实行封顶限制。甲方当月的移动电话网络数据流量达到或超出封顶额度时，乙方应暂停甲方当月网络服务。甲方可当月申请恢复服务或待次月自动恢复服务。

4.11乙方按照现有技术标准为甲方提供通信服务，但乙方无法控制第三方利用各种手段从事违法行为等情况的发生，如因第三方的恶意行为造成甲方的损失，乙方对此将不承担相关责任。

4.12甲方发布违法信息、违反公序良俗内容的信息，或未经接收客户同意大量发布商业广告等其他骚扰信息、拨打骚扰电话等不当行为，以及利用乙方提供的服务从事违法犯罪活动的，乙方有权依据行业主管部门、有关行政、司法机关的指令、客户等第三方举报或投诉，以及乙方制定的为保障公众利益的规范，关闭甲方信息发送功能，或暂停直至终止服务，由此造成的后果由甲方承担。

第五条 终止通信服务

5.1 甲方申告终止通信服务的，应在缴清通信费用及违约金（如有）后办理退网手续，账户余额应退还甲方，双方另有约定的除外。

5.2 甲方选择银行等机构以代扣代缴等方式支付通信费用的，应在办理退网手续前到银行等代扣代缴机构先行办理终止代扣代缴等手续。

5.3 除本协议另有约定外，有下列情形之一的，乙方有权单方终止通信服务，并追究甲方违约责任：

5.3.1甲方入网时提供的担保人违反保证条款或有确切证据证明担保人无能力履行保证责任，且甲方未能提供新的担保人或缴纳保证金的；

5.3.2甲方擅自改变通信服务使用性质或私自转让、出租通信服务资源的；

5.3.3甲方有其他严重违反法律、法规、规章行为的。

5.4 申告终止通信服务前或被终止通信服务后，甲方应及时修改与手机号码绑定的其他服务账号信息或财产信息、个人信息，否则应自行承担相应后果；给乙方或他人造成损失的，还应承担赔偿责任。

第六条 不可抗力

因不可抗力不能履行协议的，根据不可抗力的影响部分或全部免除责任。受影响一方应及时通知对方并在合理期限内提供证明。不可抗力是指自然灾害、战争、骚乱、恐怖主义、罢工、政府行为、国家法律法规或规章变动等不能预见、不能避免并不能克服的客观情况。

第七条 网络升级

乙方基于国家通信产业政策对网络进行整体换代升级而导致本协议无法继续履行的，应提前60日告知甲方，并提出合理解决方案。甲方可就解决方案与乙方协商；未能协商达成一致的，本协议终止。

第八条 争议解决方式

本协议项下发生的争议，双方可协商解决；协商不成的，甲方可向电信管理部门或消费者协会等有关部门投诉；也可采取以下第   1  种方式解决争议：1.向有管辖权的人民法院提起诉讼；2.向   /    仲裁委员会申请仲裁。

第九条 其他

甲方办理各类服务所签署的表单、协议等，以及乙方在本协议约定外以公告等书面形式公开做出的服务承诺，自动成为本协议组成部分，但加重甲方责任、排除甲方主要权利或免除乙方责任的除外。乙方公开做出的服务承诺低于本协议约定标准的，以本协议为准。

第十条：补充说明

10.1甲方欲将业务号码过户时，应先交清所有费用，过户时须由双方持有效身份证件原件办理。

10.2对于非乙方原因不具备开通条件的，在乙方告知甲方后，本协议自动终止，乙方退还甲方已交纳费用。

10.3甲方选定的号码，乙方开通后方可使用。

10.4有下列情形之一的，乙方有权单方解除协议，收回号码或账号、终止服务，并保留追究甲方违约责任的权利：

10.4.1甲方提供的有效身份证件不实;

10.4.2甲方欠费停机后（含欠费停机当月）3个月内仍未交清通信费用和违约金的;

10.4.3业务（服务）超过约定有效期的；

10.4.4预付费产品在约定期限内未激活的；

10.4.5 违规外呼、呼叫频次异常的。

10.5因技术进步等原因导致本协议（部分或全部）无法继续履行的，乙方保留对电信业务（服务）做出调整的权利，调整前乙方应至少提前60日发布公告并提出相应解决方案。甲方可就解决方案与乙方协商，但不得要求乙方继续履行本协议。

第十一条 协议生效

本协议一式两份，甲乙双方各执一份，自业务受理之日起生效，有效期一年。到期时，若双方均无异议，本协议自动顺延。

为本次受理业务，甲方还已充分、完整阅读并理解其作为本协议附加协议(须知、承诺函)所述全部条款及条件。

□ 中国联通客户移网业务优惠活动业务协议

□ 北京联通移动业务靓号使用承诺函

□ 中国联通客户沃家庭融合业务协议

□ 北京联通公众宽带产品业务须知

□ 中国联通客户智慧沃家融合业务协议

□ 中国联通携号转品牌业务客户须知（后转预）

□ 中国联通携号转品牌业务客户须知（预转后）

□ 北京联通光快线+产品登记单与协议

中国联合网络通信有限公司北京市分公司

协议版本号：20180517-BJ-01

中国联通用户隐私政策
中国联通（下面称为“我们”）非常重视用户的隐私和个人信息保护，致力于维持您对我们的信任。我们承诺采取相应的安全保护措施来保护您的个人信息。请在使用我们的移动业务、宽带业务、固话业务、融合业务、IDC服务、ICT服务、云计算服务、大数据服务、物联网服务等各项产品或服务（以下统称“我们的产品或服务”）前，仔细阅读并了解《中国联通用户隐私政策》（“本隐私政策”）。

您在使用我们的产品或服务时，我们需要按照实名制等国家法律法规及监管政策的相关要求收集、存储、使用、共享您的信息，以及向您提供服务及提升服务质量，我们希望通过本隐私政策向您说明：在您使用我们的产品或服务时，我们会收集哪些数据、为什么收集这些数据、会利用这些数据做什么以及我们如何保护这些数据。

本隐私政策与您所使用的我们的产品或服务息息相关，对于您行使个人权利及保护您的个人信息至关重要，请您在使用我们的产品或服务前认真阅读并充分理解本政策所写明的内容。

阅读过程中，如您对我们的隐私政策及服务条款的内容有任何疑问，请联系我们。一旦您开始使用我们的产品或服务，即表示您已经理解并同意本隐私政策全部内容。您使用或在我们更新本隐私政策后（我们会及时提示您更新的情况）继续使用我们的产品或服务，即意味着您同意本隐私政策(含更新版本)内容，并且同意我们按照本隐私政策收集、使用、保存和共享您的相关信息。

本隐私政策包含以下内容：

我们如何收集和使用您的个人信息；

我们如何使用 Cookie 和同类技术；

我们如何共享、转让、公开披露您的个人信息；

我们如何保护您的个人信息；

我们如何处理儿童的个人信息；

您的个人信息如何在全球范围转移；

本政策如何更新；

您的权利；

如何联系我们。

一、我们如何收集和使用个人信息

个人信息是指以电子或者其他方式记录的能够单独或者与其他信息结合识别特定自然人身份或者反映特定自然人活动情况的各种信息。

（一）我们仅会出于本政策所述的以下目的，收集和使用您的个人信息：

1.用户登记的个人身份信息

根据《电话用户真实身份信息登记规定》（工业和信息化部令第25号），您在办理入网手续时须向我们出示有效证件、提供真实身份信息；同时，为了验证该类信息的准确性和完整性，我们会将您提供的信息与合法存有您信息的机构（政府机关、事业单位、商业机构）进行验证核对；通过核验后，我们将通过识别仪、高拍仪、纸质/电子表单等方式对您的个人身份信息进行登记，拍照或在线视频留存办理手续。留存的个人身份信息主要包括：个人身份及网络身份标识鉴权信息[包括但不限于个人用户姓名、有效通信联系方式、有效证件类型及号码、证件登记信息（如地址等）、装机地址、交费账号、电子邮箱、拍照人像、服务账号及密码、密码保护答案、办理的业务等]。如您拒绝提供个人有效证件及真实信息，将无法办理入网手续，无法使用我们的产品或服务。

2.使用服务过程中自主上传产生的服务数据

您在使用我们的产品或服务过程中会上传和产生的服务数据，包括但不限于通话内容、短信/彩信、邮件信息、通讯录、好友/群组列表、网盘存储内容、发布内容等，这些服务数据由您自主选择上传产生，我们只提供相关设备存储，我们不使用相关信息内容，您可以凭借服务账号及密码等网络身份鉴权后浏览查阅。

3.使用我们的产品或服务过程中产生的日志信息

为了确保您能正常使用我们的服务，并实现计费收费准确等目的，在您使用通信和互联网信息服务过程中我们通过基站、交换机、终端等自动采集产生的日志信息[包括但不限于订购信息、服务详单（通话费详单、点对点短信和点对点彩信费详单、增值业务费详单、手机上网流量费详单、无线上网卡流量费详单、宽带上网详单、WLAN流量费详单、查询记录、上网记录、网购记录等）、使用记录、消费信息、账单、位置信息、终端信息等]。订购信息主要为用户使用通信服务和互联网服务时签订的入网/变更/终止等各类登记资料、协议或合同，以及订购套餐、增值业务等信息。消费信息主要为账单信息、缴费信息、欠费信息、账户余额变动信息、账户信息、信用额度等综合级账务信息。终端信息主要为硬件型号、设备MAC地址、操作系统类型、软件列表唯一设备识别码（如IMEI/android ID/IDFA/OPENUDID/GUID、SIM卡IMSI信息等在内的描述个人设备基本情况的信息。个人上网记录包括网站浏览记录、软件使用记录、点击记录等信息。位置信息包括基站定位信息、经纬度等信息。

4.为共同向您提供产品服务或改进产品服务的质量或出于对产品服务安全性的考量等合理需要，我们可能按照相关法律法规及监管政策的要求或经过您的授权从关联公司、合作伙伴及其他受信任的第三方接收您的个人信息及其他信息。例如当您通过我们关联公司、业务合作伙伴网站订购我们的产品，您向其提供的预订信息可能会转交给我们，以便我们处理您的订单。

5.在采集过程中，我们将严格遵守相关法律法规及监管政策，不采集任何法律法规及监管政策禁止采集的信息。

6.您了解并同意，以下情形中我们使用个人信息无需征得您的授权同意：

（1）与国家安全、国防安全有关的；

（2）与公共安全、公共卫生、重大公共利益有关的；

（3）与犯罪侦查、起诉、审判和判决执行等有关的；

（4）出于维护个人信息主体或其他个人的生命、财产等重大合法权益但又很难得到本人同意的；

（5）所收集的个人信息是个人信息主体自行向社会公众公开的；

（6）从合法公开披露的信息中收集的您的个人信息的，如合法的新闻报道、政府信息公开等渠道；

（7）根据您的要求签订和履行合同所必需的；

（8）用于维护所提供的产品或服务的安全稳定运行所必需的，例如发现、处置产品或服务的故障；

（9）法律法规及监管政策规定的其他情形。

（二）为向您提供服务及改善服务质量，在遵守国家法律法规及监管政策的前提下，我们可能将收集到的您的个人信息用于以下目的：

1.为您提供服务

（1）在我们提供服务时，用于身份验证、客户服务、安全防范、诈骗监测、存档和备份用途，确保我们向您提供的产品和服务的安全性；

（2）通过信息数据分析，帮助我们设计为您提供更好感知的新服务，改善我们现有服务；

（3）根据国家相关要求，用于旨在推进政府管理、加强社会治理、改善社会民生、建立诚信体系等目的的服务；

（4）使我们更加了解您如何使用我们的服务，从而针对性地满足您的个性化需求，例如语言设定、位置设定、个性化的帮助服务和指示，或对您和其他使用我们服务的用户做出其他方面的回应；

（5）用于向您提供个性化或定制化产品和服务，例如向您展现或推荐相关程度更高信息流或者推广信息结果。如您不希望收到这些信息，可以按照我们的相关提示取消订阅；

（6）评估我们服务中的广告和其他促销及推广活动的效果，并加以改善；

（7）软件认证或管理软件升级；

（8）邀请您参与有关我们产品和服务的调查。

2.您了解并同意，我们可以通过技术手段对您的个人信息数据进行去标识化处理，去标识化处理的信息将无法识别个人主体。在此情况下我们有权使用已经去标识化的信息，并在符合相关法律法规及监管政策的前提下，我们有权对包括您的个人信息在内的用户数据库进行整体化分析和利用。

3.当我们要将信息用于本政策未载明的其它用途时，会事先征求您的同意。

二、我们如何使用 Cookie 和同类技术

（一）为确保网站正常运转，我们会在您的计算机或移动设备上存储名为 Cookie的小数据文件。Cookie通常包含标识符、站点名称以及一些号码和字符。借助于Cookie，网站能够存储您的偏好或购物篮内的商品等数据。

我们不会将Cookie用于本政策所述目的之外的任何用途。您可根据自己的偏好管理或删除Cookie。有关详情，请参见AboutCookies.org。您可以清除计算机上保存的所有Cookie，大部分网络浏览器都设有阻止Cookie的功能。但如果您这么做，则需要在每一次访问我们的网站时亲自更改用户设置。

（二）除Cookie外，我们还有可能会在网站上使用网站信标和像素标签等其他同类技术。例如，我们向您发送的电子邮件可能含有链接至我们网站内容的点击 URL。如果您点击该链接，我们则会跟踪此次点击，帮助我们了解您的产品或服务偏好并改善客户服务。网站信标通常是一种嵌入到网站或电子邮件中的透明图像。借助于电子邮件中的像素标签，我们能够获知电子邮件是否被打开。如果您不希望自己的活动以这种方式被追踪，则可以随时从我们的寄信名单中退订。

（三）很多网络浏览器均设有“Do Not Track”（请勿追踪）功能，该功能可向网站发布“Do Not Track”请求。目前，主要互联网标准组织尚未设立相关政策来规定网站应如何应对此类请求。但如果您的浏览器启用了“Do Not Track”，那么我们的所有网站都会尊重您的选择。

三、我们如何共享、转让和公开披露个人信息

（一）共享

我们不会与中国联通以外的任何公司、组织和个人分享您的个人信息，但以下情况除外：

1.在获取明确同意的情况下共享：获得您的明确同意后，我们会与其他方共享您的个人信息。

2.我们可能会根据法律法规及监管政策要求，或按政府主管部门的强制性要求，对外共享您的个人信息。

3.您授权银行、征信机构等第三方向我们查询、采集您在中国联通的信息，或者我们会在法律法规及监管政策允许范围内及您对第三方的授权范围内向第三方共享您的信息，我们会依据与第三方的约定、对个人信息来源的合法性进行确认后，在符合法律法规及监管政策的前提下，使用您的这些个人信息。

4.与我们的关联公司共享：您的个人信息可能会与我们的关联公司共享。我们只会共享必要的个人信息，且受本隐私政策中所声明目的的约束。关联公司如要改变个人信息的处理目的，将再次征求您的授权同意。

我们的关联公司包括中国联通现在或将来控制、受控制或与其处于共同控制下的任何公司、机构以及上述公司或机构的合法继承人。其中“控制”是指直接或间接地拥有影响所提及公司管理的能力，无论是通过所有权、有投票权的股份、合同或其他被人民法院认定的方式。

5.与授权合作伙伴共享：仅为实现本政策中声明的目的，我们的某些服务将由授权合作伙伴提供。我们可能会与合作伙伴共享您的某些个人信息，以提供更好的客户服务和用户体验。例如，在您通过我们的网站购买商品或订购业务时，我们必须与物流服务提供商共享您的个人信息才能安排送货，或者安排合作伙伴提供服务。我们仅会出于合法、正当、必要、特定、明确的目的共享您的个人信息，并且只会共享提供服务所必要的个人信息。我们的合作伙伴无权将共享的个人信息用于任何其他用途。

目前，我们的授权合作伙伴包括以下【三】大类型：

（1）供应商、服务提供商和其他合作伙伴。我们将信息发送给支持我们业务的供应商、服务提供商和其他合作伙伴，这些支持包括提供技术基础设施服务、分析我们服务的使用方式、衡量广告和服务的有效性、提供客户服务、支付便利或进行学术研究和调查。

（2）第三方商家。我们必须将您的订单信息与交易有关的必要信息与第三方商家共享来实现您向其购买商品或服务的需求，并促使其可以完成后续的售后服务。

（3）广告、分析服务类的授权合作伙伴。除非得到您的许可，否则我们不会将您的个人身份信息（指可以识别您身份的信息，例如姓名或电子邮箱，通过这些信息可以联系到您或识别您的身份）与提供广告、分析服务的合作伙伴分享。但我们可能会将使用您的信息而形成的用户画像与提供广告、分析服务的合作伙伴共享，以帮助在不识别您个人的前提下提升广告及服务信息的有效触达率。

对我们与之共享个人信息的公司、组织和个人，我们会与其签署相应的保密协定，要求他们按照我们的说明、隐私政策以及其他任何相关的保密和安全措施来处理个人信息。

（二）转让

我们不会将您的个人信息转让给任何公司、组织和个人，但以下情况除外：

1.在获取明确同意的情况下转让：获得您的明确同意后，我们会向其他方转让您的个人信息；

2.在涉及合并、收购或破产清算时，如涉及到个人信息转让，我们会要求新的持有您个人信息的公司、组织继续受此隐私政策的约束，否则我们将要求该公司、组织重新向您征求授权同意；

3.符合与您签署的相关协议或其他的法律法规文件约定所提供。

（三）公开披露

我们仅会在以下情况下，公开披露您的个人信息：

1.获得您明确同意后；

2.基于法律的披露：在法律、法律程序、诉讼或政府主管部门强制性要求的情况下，我们可能会公开披露您的个人信息。

四、我们如何保护您的个人信息

（一）我们承诺将严格按照国家有关规定做好用户信息安全防护工作。为保障您的信息安全，我们会使用必要安全技术及配套的管理体系来防止您的信息被泄露、毁损或者丢失。同时我们已设立用户信息保护责任部门，建立相关内控制度，对可能接触到您信息的工作人员采取最小够用授权原则；不断对工作人员培训相关法律法规、隐私政策和安全意识，对工作人员处理您的信息的行为进行系统监控。我们每年会接受相关国家机构的信息安全检查。

（二）您须承诺妥善保存登录的账户、密码等信息，由于您的原因造成账户密码的泄露产生的后果由您承担。为防止信息泄露，我们将采取防泄漏、反爬虫等技术手段，限制频繁查询您的信息等异常操作行为，以防止账号密码泄露或他人冒用身份造成您产生不良行为记录或者您的信息泄露。

（三）由于技术水平限制及可能存在的各种恶意手段，有可能因我们可控范围外的因素而出现安全问题。在发生个人信息安全事件后，我们将按照相关法律法规及监管政策的要求，及时向您告知，难以逐一告知个人信息主体时，我们会采取合理、有效的方式发布公告。同时，我们还将按照监管部门要求，主动上报个人信息安全事件的处置情况。

五、我们如何处理儿童的个人信息

（一）我们非常重视对未成年人个人信息的保护。我们将根据国家相关法律法规及监管政策的规定保护未成年人的个人信息。

（二）对于经父母或法定监护人同意而收集未成年人个人信息的情况，我们只会在受到法律允许、父母或监护人明确同意或者保护未成年人所必要的情况下使用或公开披露此信息。

（三）如果我们发现自己在未事先获得可证实的父母或法定监护人同意的情况下收集了未成年人的个人信息，会设法尽快删除相关数据。

六、 您的个人信息如何在全球范围转移

原则上，我们在中华人民共和国境内收集和产生的个人信息，将存储在中华人民共和国境内。如果需要将您的个人信息转移到境外，我们将另行获得您的授权同意，在此情况下我们会依据本政策以使您的个人信息得到足够的保护。

七、本政策如何更新

我们的隐私政策可能变更。未经您明确同意，我们不会削减您按照本隐私政策所应享有的权利。基于为给您提供更好的服务以及随着电信业务的发展或法律法规及监管政策变化，我们可能会适时对本政策进行更新。由于我们的用户较多，如本政策发生重大变更，我们将以推送通知、发送邮件、信函、电话或者在中国联通官方网站发布公告的方式来通知您。若您在本政策修订后继续使用我们的产品或服务，这表示您已充分阅读、理解并愿意受修订后的本政策约束。

八、您的权利

（一）您可前往中国联通当地营业厅、拨打10010客服热线、访问https://www.10010.cn网上营业厅、使用手机营业厅APP等多种方式，查询您的个人信息或修改您的个人资料。

（二）您在注销账户后，您该账户内的所有信息将被清空，我们将不会再收集、使用或共享与该账户相关的个人信息，但之前的信息我们仍需按照监管政策的时间进行保存，且在该依法保存的时间内有权机关仍有权依法查询。

（三）对于您关于用户个人信息的合理请求，我们原则上不收取费用，但对多次重复、超出合理限度的请求，我们将视情收取一定成本费用。对于那些无端重复、需要过多技术手段、给他人合法权益带来风险或者非常不切实际的请求，我们可能会予以拒绝。在以下情形中，按照法律法规及监管政策要求，我们将无法响应您的请求：

1.与国家安全、国防安全直接相关的；

2.与公共安全、公共卫生、重大公共利益直接相关的；

3.与犯罪侦查、起诉、审判和判决执行等直接相关的；

4.有充分证据表明您存在主观恶意或滥用权利的；

5.响应您的请求将导致您或其他个人、组织的合法权益受到严重损害的；

6.涉及商业秘密的。

九、如何联系我们

如您对本隐私政策或您个人信息的相关事宜有任何问题、意见或建议，您可前往中国联通当地营业厅、拨打10010客服热线、访问https://www.10010.cn网上营业厅、使用手机营业厅APP等多种方式与我们联系。一般情况下，我们将在三十天内回复。如果您对我们的回复不满意，您还可以向相关监管部门进行投诉或举报。

北京联通公众宽带产品业务须知
1.公众宽带产品面向北京地区具备开通条件的小区内住户开放。

2.新装宽带产品一次性安装费用为300元，趸交付费及参加趸交优惠活动客户免收。

3.公众宽带产品的接入速率均指下行速率。具体上下行速率如下表：

产品速率
下行速率(bps)
上行速率(bps)
接入方式
4M
4M
1M
ADSL
200M
200M
30M
FTTH
300M
300M
30M
FTTH
500M
500M
30M
FTTH
600M
600M
30M
FTTH
1000M
1000M
30M
FTTH
4.铜线宽带接入客户（包括FTTB、ADSL、VDSL接入方式），北京联通将打开速率限制，最高实际速率以客户线路可达为准。

5.100M及以上产品将存在一定的网络自耗，可能不能完全达到其理论下行速率。

6.客户有权在北京联通提供的宽带产品业务范围内进行产品变更。其中不涉及施工的速率变更自业务受理当日起生效，如产品速率变更涉及施工，则自竣工当日起生效。变更后资费自竣工后次月生效。

7.客户应妥善保管宽带接入账号、密码。因客户保管不善致使接入账号和密码等安全信息被他人盗用并造成损失的，由客户承担全部责任。

8.公众宽带不限时包月200M及以上产品客户通过同一接入账号最多可同时使用6台终端（不含路由器、具备WIFI功能的个人手机等智能终端。以下相同）接入互联网，200M（不含）以下产品客户通过同一接入账号最多可同时使用4台终端，限时包月产品客户通过同一接入账号最多可使用1台终端接入互联网。当客户接入互联网的终端数目超过了上述约定，北京联通公司不保证通信质量并有权中止提供宽带接入服务。

9.北京联通公众宽带产品仅限家庭客户非经营性使用。客户不得在未经北京联通许可的前提下私自改变其申请的宽带产品使用性质。一经发现，北京联通公司有权终止提供宽带服务。

10.客户应当妥善保管并使用北京联通为其提供使用的终端设备。未经北京联通同意，客户不得将该设备转借﹑出租﹑出售或赠与他人，也不得将上述设备用于非北京联通提供的业务中，一经发现，北京联通公司有权终止提供宽带服务。撤机时， 客户须向北京联通归还该设备并保证设备的完好可用或者向北京联通公司全额支付已领用的设备费用（MODEM/家庭网关200元/个；ONU/HGU光网络终端整机300元/套，其中终端主机275元/台，电源适配器15元/个，网络连接线10元/根；IPTV机顶盒整机200元/套，其中机顶盒主机155元/台，遥控器30元/个，电源适配器15元/个）；设备保修期内（MODEM/家庭网关为一年，ONU/HGU/IPTV机顶盒/智能家庭网关为三年）维保由北京联通负责，因客户使用不当造成设备损坏除外。超过维保期或设备升级产生的费用将由客户自行承担。

11.客户使用的接入终端设备（包括但不限于MODEM/家庭网关、ONU/HGU/IPTV机顶盒、个人电脑、具备WIFI功能的个人智能终端等）所产生的电费，由客户自行承担。

12.北京联通计费系统依据客户断网记录进行相应计费处理。如遇客户产生跨计费周期上网记录时则北京联通按月末日24时切割客户此次上网的上网时长和上网费用，且分别计入当月及次月。

13.公众宽带产品安装竣工当月按天计费，不限时包月产品按月租费/当月天数*实际使用天数收取该月费用；限时包月产品按月租费/当月天数*实际使用天数收取月租费，如有超时费则单独收取；趸交产品按趸交优惠月资费/当月天数*实际使用天数收取该月费用。客户须确保于竣工次月的月末日前进行缴费。客户未按期缴纳宽带业务费用的，视为违约。北京联通有权按照《中华人民共和国电信条例》规定，暂停宽带接入服务，并收取业务暂停费用；对于暂停服务后60日内仍未交纳费用的，有权终止提供宽带接入服务；北京联通有权按照客户所欠费用每日加收3‰的违约金（从逾期之日起算）。

14.客户使用宽带业务上网时须遵守国家相应的互联网管理法规，如违反国家的法律法规，北京联通有权停止提供服务并进行撤机。

15.限时包月客户办理撤机手续的，自撤机手续办理之日起宽带账号不可使用，办理撤机手续当月，月租费按天收取，收取规则同安装竣工当月计费规则。不限时包月/趸交客户办理撤机手续的，自撤机手续办理次月起，宽带账号不可使用，办理撤机手续当月，月租费按天收取，收取规则同安装竣工当月计费规则。

16.办理公众宽带产品的客户同意接受北京联通提供的宽带电子媒体信息（宽带信息推送服务）。

17.办理趸交付费及趸交优惠活动客户须知：

（1）趸交付费指一次性缴纳半年及以上宽带月租费，并办理趸交手续的付费方式。

（2）新装宽带办理趸交付费客户，自装机竣工次月开始计算趸交期。

（3）变更为趸交付费的客户，从申请变更后的次月开始计算趸交期。

（4）趸交费用仅包含客户宽带月租费。

（5）客户在趸交优惠期内不再享受同期的其他宽带优惠政策。

（6）趸交未到期，提前终止趸交的，需将已享受的优惠补交至北京联通（即：按同速率不限时包月产品补交已使用月租费并补交已享受优惠的一次性费用）。

（7）客户可在趸交到期前任何时间办理续趸手续。趸交期最后1个月未办理续趸手续的客户，自趸交期结束的次月起，北京联通会自动将客户的业务资费变为客户所选速率对应的不限时包月标准资费。如客户不想使用该档资费，请在趸缴期最后一个月前办理资费变更等手续。

（8）固话和宽带使用同一线路（或办理了沃家庭4G版、光宽带流量王套餐）的宽带趸交客户，在趸缴期内，由于客户该宽带关联的固定电话/IPTV/移网手机号产品欠费停机的，宽带使用功能继续保留，趸交款月费正常计费，直至趸交款消费完毕；客户需自行缴纳固定电话/IPTV/移网手机号产品的欠费。

（9）客户在趸交期内，不能进行付费方式等业务的办理。

18.本业务须知自客户签字之日起生效。

客户/经办人签字：

   年   月   日
--
Aaron






I figured out some easy to implement changes, applicable also for future releases:
•	Make deb packages meeting required version
•	To show also deb package version when showing current component versions
•	Remove showing version splashing when launching CLI, this is from very old `xorp` dir configure.ac only, hard to maintain
•	Construct deb package version number at build time from release branch number, without changing top dir configure.ac each time.


--
Aaron

From: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Sent: Thursday, November 14, 2019 07:05
To: Nirmal Karia <Nirmal.Karia@pica8.com>; Leon Li <leon.li@pica8.com>; Tom Jia <tom.jia@pica8.com>; Aaron Shang <aaron.shang@pica8.com>
Cc: Lisa Pi <lisa.pi@pica8.com>; support@pica8.com <support@pica8.com>
Subject: Re: Splitting Ports

Leon, please take this opportunity to add the .deb upgrade workflow as an extension to switch upgrade URL workflow.

If the URL ends in a .deb then you know you are fetching a Debian package as compared to .bin when fetching a full image.

Also the Debian package release number should be bumped to 3.2.1.2 and we need to start showing the Debian package versions separate from the base PICOS release version. It’s not only the NPB package, but also the other 3 Debian packages that make up the release, linux, common, ovs; xorplus is not relevant for NPB.

Tom, the show version and similar linux and and CLI commands also need to show the other package versions installed on the system now that we allow for modular upgrades in 3.x. Please work with Aaron on the best way to achieve this.

--
/Sharad



From: Nirmal Karia <Nirmal.Karia@pica8.com>
Date: Wednesday, November 13, 2019 at 14:41
To: Leon Li <leon.li@pica8.com>, Tom Jia <tom.jia@pica8.com>
Cc: Lisa Pi <lisa.pi@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: Splitting Ports

Hi Leon,

Can you generate a patch release with the bug fix for 7816 right now and than add this fix for all further npb releases. Customer is not comfortable with adding the fix via deb packages.

Thanks,
Nirmal

From: Leon Li <leon.li@pica8.com>
Sent: Tuesday, November 12, 2019 11:01 PM
To: Nirmal Karia <Nirmal.Karia@pica8.com>; Tom Jia <tom.jia@pica8.com>
Cc: Lisa Pi <lisa.pi@pica8.com>; support@pica8.com <support@pica8.com>
Subject: 回复: Splitting Ports

Hi Nirmal,

This is a bug in 3.2.1.1 release and we have fixed it today.

We support to give an NPB Debian package for updating here, so please follow these steps to do the update.
1.     Suggest to save the NPB configuration first if any ASIC / Device Settings configuration has been done before .
2.     Scp the deb package to switch and manually execute “sudo dpkg -i picos-npb-3.2.1.1-64d139f4be.deb”.  (3.2.1.1 can not scp from outside into switch, please do the scp in switch)
3.     Reboot the switch.
4.     Using Web to reload the saved configuration file if necessary.
5.     Try to test the breakout function.

Here is the Debian package path:
leon.li@dev22:/tftp/build/release/garland/3.2.1.1$ ls -lt
total 787296
-rw-r--r-- 1 build build    766304 Nov 13 14:55 picos-npb-3.2.1.1-64d139f4be.deb

So please help us verify the breakout function before given to customers.
And let me know if it is necessary to do a fresh build for new images.

Thanks

发件人: Nirmal Karia <Nirmal.Karia@pica8.com>
发送时间: 2019年11月13日 9:43
收件人: Leon Li <leon.li@pica8.com>; Tom Jia <tom.jia@pica8.com>
抄送: Lisa Pi <lisa.pi@pica8.com>; support@pica8.com
主题: Fw: Splitting Ports

Hi Leon/Lisa,

I have a problem with the AS7816-64X FW 3.2.1.1. When try to split port or try and remove one of the original ports I receive an error message. Please verify. I have a customer that found this and I need to provide a response. Once you try to remove or add a port the and click saves changes. It displays below error and the GUI is stuck. I need to refresh the page.



Removing 1 port error message


Adding an additional port error message.


Thanks,
Nirmal







弗兰克 · 富里迪的作品《知识分子都到哪里去了


国王与我
迦陵先生

菡萏結香詩教成 百年吟誦此中興

先師未讓前朝士 弟子因承魏晉風


袁生按：葉老生於六月，花月屬荷，乳名小蓮，最喜稼軒。
其弟子無數，最得先生遺風者當屬香港 「劉少雄」，但喜東坡。
時七十秊己亥歲荷月既望宋州袁子卿於睢陽

--
Aaron






________________________________________
From: Brad Bullington <brad.bullington@pica8.com>
Sent: Thursday, November 11, 2021 07:48
To: James Liao; Pica8 All
Subject: Re: Welcome Brad Bullington, new CEO of Pica8

James,

Thank you for the thoughtful introduction.  I’m looking forward to partnering with you and the rest of the team to help Pica8 achieve its compelling full potential.

I also look forward to meeting the team over the coming days and weeks.

Best,
Brad

From: James Liao <james.liao@pica8.com>
Date: Wednesday, November 10, 2021 at 8:34 AM
To: Pica8 All <pica8-all@pica8.com>
Subject: Welcome Brad Bullington, new CEO of Pica8

Dear Pica8 Team,

I am excited to announce that Brad Bullington is joining Pica8 as our new CEO.

With our Series-C financing, we have been working hard to accelerate Pica8’s growth and path toward being a great company. Our first goal is to recruit the key executives required to continue to grow our revenues, expand our roadmap, execute key partnerships and raise additional capital. Recently, we recruited Mike and Kelly as our CRO and CMO, and subsequently ramped up the marketing and sales team.

The next step in our plan is to triple our revenue in 2022 and to raise a large Series-D to support our continued expansion. This requires experience in raising capital, engaging and managing venture capitalist and growing a startup into a much larger and mature company. Through the board’s connection, I have been working with Brad on the company position and execution for the past 6 months. Now with the revenue traction increasing with our investments in Sales and Marketing, we feel it is the right time for Brad to join as the CEO.

Brad comes with strong experience both as an operating CEO and as a venture investor.  He raised more than $100M from VCs at his last company. In the last 20 years, Brad not only has worked as an independent board member in many companies, but also personally grew a startup  from $10M to $100M in revenue, with hundreds of employees and thousands of partner employees worldwide.  This company achieved a large successful exit in an extremely competitive industry. I know his experience will help Pica8 to migrate through our next several phases of growth.

As for me, I will still be with the company, partnering with Brad and focusing more on product planning and management, along with raising the profile of the company with the outside world, including key strategic partners and analysts. I am always the co-founder of Pica8, whether my title is CTO or CEO. I am working with the whole executive team, including Brad, to bring Pica8 to the success we all know it can be.

Please join me in welcoming Brad on board and I look forward to the exciting future of Pica8.

James







Corner issue happen for those users using PICOS as a normal Debian OS if we are paranoid to remain minimum accounts.
The in some cases may have to manually create users they needed.
But I don't think it a major issue.

Better designed packages will detect and add needed users in post-inst script during install, such as ssh/ntp/radvd.

Some syslog package may also add 'syslog' user.
The previous mail included a 'logger' user. This might be added by some syslog package. But the login shell should be /bin/false;, using bash makes it suspicious.

________________________________________
From: Aaron Shang <aaron.shang@pica8.com>
Sent: Saturday, November 13, 2021 17:31
To: James Liao; Zoneson Chen
Cc: Tom Jia; TACinternal
Subject: Re: 1092 AA10G54AC - Undocumented User Accounts / Backdoors

Hi, Zonezon, James,

Currently these accounts are from the default Debian rootfs. We had not done any fine tuning yet.
Most of them are for common tradition, such as using 'games' to own installed game packages, 'man' to own manpages and man-db, 'lp' for printer related jobs, 'news' for NNTP messages, etc.
To be the security paranoid these accounts can be removed, especially for dedicated OS like PICOS.

Actually these accounts are disabled now. You can check the /etc/shadow file, only 'admin' and 'operator' can be used to login. Others should be disabled.
The second filed with '*' means being disabled, '!' means locked.

Even some accounts can be enabled by setting a passwd, by default most of them are assigned /bin/false or /*bin/nologin to block logins.

For the accounts aforementioned:
    root, daemon, sync, and guest.

root is necessary although it is now usually disabled in most distributions.
guest is used for our AAA mapped users now. The actual login shell is /pica/bin/pica_sh.
the other 2 can be removed.

As for this one:
    logger:x:1002:1000:,,,:/home/logger:/bin/bash

I cannot find the release version of this system. We don't have this account in our rootfs, at least not in current master.
If it's not added by the user, it must be cracked. :(


I think we can safely remove these accounts at a quick glance:
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin


www-data is used by default for our web GUI. We didn't customize this even it is easy, and suggested.
    www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin

I think we can use 'admin' for web GUI due to the logic for that.


I am not sure now about these accounts, more tests are needed:
    nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
    ntp:x:100:103::/home/ntp:/bin/false
    radvd:x:101:65534::/var/run/radvd:/bin/false
    messagebus:x:103:105::/var/run/dbus:/bin/false

nobody user and group usually used for no-login accounts. This can be removed. But I think we had used that somewhere for some issue workarounds.
I need further investigate on this.
ntp and radvd are used for NTP and package radvd. Maybe removing them is not good idea. I need to test more.
For dbus, we can remove dbus because we are not a Desktop OS. But by a controversial design in systemd, if dbus is not installed, root privilege is needed during querying system statuses. We later added this package additionally to remove many cases of calling sudo. It can be negotiated.


These accounts should be kept:
    sshd:x:104:65534::/var/run/sshd:/usr/sbin/nologin
    systemd-timesync:x:105:109:systemd Time Synchronization,,,:/run/systemd:/bin/false
    systemd-network:x:106:110:systemd Network Management,,,:/run/systemd/netif:/bin/false
    systemd-resolve:x:107:111:systemd Resolver,,,:/run/systemd/resolve:/bin/false
    systemd-bus-proxy:x:108:112:systemd Bus Proxy,,,:/run/systemd:/bin/false

ssh daemon listens as root privilege but will at once switchs by fork to non-privileged sshd user after login for security design.
Other systemd users should keep systemd default design to reduce future maintenance.



Later you can directly send to me in CC for any system, Linux, or security concerns.


Suggested change:
- To remove all the unnecessary accounts, to the paranoid.


________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Saturday, November 13, 2021 00:13
To: Zoneson Chen; Aaron Shang
Cc: Tom Jia; TACinternal
Subject: Re: 1092 AA10G54AC - Undocumented User Accounts / Backdoors

Aaron,

Can you give Zoneson a quick analysis on this? And suggest whether we need to make any change?

James

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Friday, November 12, 2021 at 7:58 AM
To: Michael Walker <michael.walker@garlandtechnology.com>
Cc: "support@pica8.com" <support@pica8.com>, Jon McCoy <jon.mccoy@garlandtechnology.com>, Jerry Dillard <jerry.dillard@garlandtechnology.com>
Subject: Re: 1092 AA10G54AC - Undocumented User Accounts / Backdoors

Michael,

I am sorry that I do not receive a concrete answer from engineering team yet.

Thanks,

Zoneson

From: Michael Walker <michael.walker@garlandtechnology.com>
Date: Friday, November 12, 2021 at 6:46 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: support@pica8.com <support@pica8.com>, Jon McCoy <jon.mccoy@garlandtechnology.com>, Jerry Dillard <jerry.dillard@garlandtechnology.com>
Subject: Re: 1092 AA10G54AC - Undocumented User Accounts / Backdoors
Zoneson,

Have you an update for this issue?


Regards,
Michael Walker
Garland Technology
Technical Support Manager


On Wed, Nov 10, 2021 at 4:15 PM Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>> wrote:
Hi Michael,

I will consult with engineering team about this issue. Some of them are used by PICOS internally even though some could be removed. I assume that they can not be used to login except admin.

Thanks,

Zoneson
From: Michael Walker <michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>>
Date: Wednesday, November 10, 2021 at 1:55 PM
To: support@pica8.com<mailto:support@pica8.com> <support@pica8.com<mailto:support@pica8.com>>, Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>, Jon McCoy <jon.mccoy@garlandtechnology.com<mailto:jon.mccoy@garlandtechnology.com>>, Jerry Dillard <jerry.dillard@garlandtechnology.com<mailto:jerry.dillard@garlandtechnology.com>>
Subject: 1092 AA10G54AC - Undocumented User Accounts / Backdoors
Zoneson,

Garland has a customer that has an AA10G54AC to perform proof of concept testing on. One of their requirements is that the AA10G54AC cannot have any backdoors or undocumented user accounts.

Our customer has reported that when performing a cat on the /etc/passwd file he got the output below. In addition to the Admin, operator, and logger accounts there is also root, daemon, sync, and guest. Please provide an explanation of these accounts. How can we remove these accounts or render them inoperative?


admin@OVS:/etc$ cat passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
ntp:x:100:103::/home/ntp:/bin/false
radvd:x:101:65534::/var/run/radvd:/bin/false
messagebus:x:103:105::/var/run/dbus:/bin/false
sshd:x:104:65534::/var/run/sshd:/usr/sbin/nologin
systemd-timesync:x:105:109:systemd Time Synchronization,,,:/run/systemd:/bin/false
systemd-network:x:106:110:systemd Network Management,,,:/run/systemd/netif:/bin/false
systemd-resolve:x:107:111:systemd Resolver,,,:/run/systemd/resolve:/bin/false
systemd-bus-proxy:x:108:112:systemd Bus Proxy,,,:/run/systemd:/bin/false
admin:x:1000:1:admin,,,:/home/admin:/bin/bash
operator:x:1001:14:pica8,,,:/home/operator:/bin/bash
guest:x:65524:65534::/tmp:/usr/bin/guest.sh
logger:x:1002:1000:,,,:/home/logger:/bin/bashadmin@OVS:/etc$


Regards,
Michael Walker
Technical Support Manager, Garland Technology
+1-716-242-8500 Main<tel:+1-716-242-8500+Main> | +1-716-242-8491 Direct<tel:+1-716-242-8491+Direct>
michael.walker@garlandtechnology.com<mailto:michael.walker@garlandtechnology.com>
https://www.garlandtechnology.com<https://www.garlandtechnology.com/support>
https://www.garlandtechnology.com/blog/how-data-diode-taps-improve-security-monitoring







The space needed for docker is mainly the overlayfs/aufs.

I had an example here. Our dev24 server had a very tiny root '/' and I had no easy way to expand that because lots of us are using that.

By default docker runs aufs in /var/lib. So I just symbol-link it the another larger disk:

lrwxrwxrwx 1 root root 13 Sep 27  2016 /var/lib/docker -> /home/docker//

That works fine for years. Hope that case can help you.

So you can make use of other partitions and try the above linking solution.



________________________________________
From: James Liao <james.liao@pica8.com>
Sent: Friday, November 19, 2021 05:17
To: Aaron Shang
Cc: Lin Du
Subject: Re: Special project - Research of Docker/Kubernetics on PicOS

Just talked to Zoneson. We had a customer who requested to have a docker at PicOS, so Zoneson had tried it. It worked, BUT Docker is taking up a lot of space at the PicOS partition (which seems to be a wrong place to install Docker).

Zoneson wants to give a friendly heads-up that we need to find ways to use the non-PicOS partition for installation. J

James

On 11/18/21, 11:22 AM, "James Liao" <james.liao@pica8.com> wrote:

    Aaron,

    Somehow your reply falls into my junk mail. This has never happened before since you are using Pica8's domain name. Anyway, in the future, if you don't see my reply or acknowledgement, feel free to check with me.

    Your answers make sense. For the next step, I would like to ask the followings.

    1. I will create a PDLC task and I need you to add a one-page "idea" as a document attached to the task. The "idea" document just needs one diagram of the structure (ie. PicOS running in parallel to Docker) and a list of bullet points to highlight the thinking and decisions made.

    2. I would like to propose to run your "trial" and "error" on AS4630, which comes with Intel CPU and could be our potential flagship access switches within the next 12 months.

    (Feel free to copy my points into your document, which is meant for "paper trail").

    James

    On 11/17/21, 5:05 PM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

        Hi, James,

        On Thu, Nov 18, 2021 at 07:13:56AM +0800, James Liao wrote:
        >Aaron,
        >I would like to initialize a conversation with you on the possibility of using
        >Docker/Kubernetics on PicOS.
        >
        >The reason behind this potential project is there are many applications, such
        >as NPB, Firewall, or Identify control, that can be run on the switch CPU.
        >Ideally, we want to use Docker or Kubernetics to provide application protection
        >and remove the system dependency.

        That's what I had long thought to propose, esp. with more edge and powerful
        computing nodes working as switches.

        >In this case, I have the following questions.
        >
        > 1. Do you have time to work on this research in parallel to your daily work?

        I can manage that.

        > 2. Assuming you have time, what would the architecture looks like?
        >     a. Do we prefer Docker or Kubernetics?

        Docker is one of and also the first popular containers, while K8s is one
        of the orchestrating systems coming out late but now becoming
        dominating due to its excellence and active community.

        Docker can be used as one of the supported containers for k8s.
        For single or few node cases, Docker can be used.
        For scaling or consistent managing of instances, k8s would assist a
        lot just as what Ansible playbooks help automation tasks.

        >     b. Do we run Docker in parallel to PicOS? Or do we want PicOS as one of
        >        the Docker service?

        It would help us a lot if running PicOS as one docker service, referring
        to what we are doing on VM. But PicOS has L2 dependencies.

        L3 only solutions, such as FRR, can easily run as a container.
        So in the beginning, I would like that to run in parallel to PicOS.
        Later we can leverage it to make PicOS container-wise as much as we can.

        > 3. What is the risk and consideration factors for different choices?

        Basically, there is no risk. Running docker services in parallel to
        PicOS is just easy to start with.

        > 4. Evaluation of the required time and resource.

        I think I can make some tests by trial and error to have a better
        practice. That can be expected to be done in December.

        I would consult with and involve solution team, Leon/Yachal/Tim when
        needed.

        >Copying Lin as well in case you have concern about your assignment.
        >
        >Thanks,
        >
        >James
        >

        --
        Aaron









BTW,
Do we have existing infrastructure that can be used as LDAP service? If so we can have SSO like ID portal to manage account only in one instance, or we can set up 389 or freeIPA mirror in each site.

Such as:
https://www.port389.org/

https://www.freeipa.org/

--
Aaron










________________________________________
From: Kelly LeBlanc <kelly.leblanc@pica8.com>
Sent: Friday, November 19, 2021 00:02
To: Pica8 All
Subject: Press Release: Pica8 Appoints Brad Bullington as Chief Executive Officer

Hi Team,

Today we announced our appointment of Brad as Pica8’s CEO.

https://www.pica8.com/news/press-releases/pica8-appoints-brad-bullington-as-chief-executive-officer/

Welcome to the team, Brad!

Pica8 Appoints Brad Bullington as Chief Executive Officer

Key Executive Team Addition to Drive Pica8’s Growth as a Global Leader in Enterprise Networking Software


Palo Alto, Calif., November 18, 2021 – Pica8, a leading innovator in enterprise networking software, today announced the appointment of Brad Bullington as Chief Executive Officer (CEO). Bullington’s addition further expands Pica8’s executive leadership team following the company’s recent close of a Series-C financing, raising more than $20M. This new capital will accelerate the company’s aggressive development and commercialization of products that provide enterprise customers a software alternative to costly, and complex hardware-first solutions from legacy providers Cisco, Juniper and Arista. Bullington succeeds James Liao, Pica8’s Founder who will continue as a key member of the executive team, transitioning to Chief Technology Officer (CTO).

Bullington joins Pica8 with extensive enterprise technology experience, both as an operating CEO and as a venture investor, with a strong track record of success building new markets and scaling a range of new technology platforms. During his tenure, including as CEO, at Bridgelux, Bullington drove aggressive revenue growth--10X to $100M--in four years. He led over $100M of capital formation and architected the successful execution of transformative technology development and go-to-market partnerships with global industry leaders, including Toshiba and Chevron on the path to an industry leading exit.

Previously, Bullington held a range of senior leadership roles in product, strategic marketing and corporate development at Seagate and Maxtor, driving significant paradigm shifts in the traditional data center through storage and compute virtualization.  These technology and business model innovations evolved to enable the buildout and scaling of a broad range of both cloud, and edge-centric applications for global-scale enterprises.

Bullington is also an active investor, advisor, and board member for a range of venture-backed companies, including several delivering Software-as-a-Service (SaaS), through Q6 Capital, which he co-founded.

“Brad brings a unique combination of growth company CEO and venture capital experience that will help drive Pica8 into its next phase of expansion,” said Mike Splinter, Pica8’s Lead Board Member and Chairman of NASDQ. “Our appointment of Brad further broadens Pica8’s executive team to capitalize on Pica8’s leadership position as the innovation leader in enterprise networking software.”

“We built Pica8 to be the leader in enterprise networking with a mission to make customers’ lives easy by applying high-end networking software on open networking platforms,” said James Liao, Founder and CTO for Pica8. “I look forward to working with Brad and the Pica8 team to continue to deliver solutions that change our customers’ thinking about how they deploy and run the network, for the better.”

“I am honored to join Pica8 as CEO to further drive and expand upon the market opportunity and success that the team has built,” said Brad Bullington, CEO for Pica8. “I look forward to our continued growth through expansion of our products, customer base and partnership positions as the global industry leader in enterprise networking software.”

About Pica8
Pica8 is the industry’s open networking software alternative to Cisco, Juniper and Arista for the enterprise. Pica8’s AmpCon• Network Controller for centralized management and automation and PicOS• Software Switches for networking and security have successfully replaced Cisco DNA Center and Catalyst Switches and competing Juniper and Arista solutions for campus, data center and distributed site networks within Fortune 500 enterprises. Pica8 software is deployed at over 1,000 customers in over 40 countries. For more information, visit www.pica8.com<http://www.pica8.com>

Media Contact
Kelly LeBlanc, Chief Marketing Officer, Pica8
kelly.leblanc@pica8.com

Best regards,
Kelly

Kelly LeBlanc
Chief Marketing Officer

Pica8, Inc.
1032 Elwell Court, Suite 105<x-apple-data-detectors://1/0>
Palo Alto, CA. 94303<x-apple-data-detectors://1/0>
M: +1.408.596.0682<tel:+1.925.212.7009>
E: kelly.leblanc@pica8.com<mailto:kelly.leblanc@pica8.com>






We did tried 4.x on 2.x before.

I also recalled that the kernel config does not enable KVM on as4610.

If you want have a try, please be sure to check that since the KVM kernel config is needed to run that.
To have a quick check, run

    $ zgrep -i ^CONFIG_KVM /proc/config.gz

If you can find some lines containing similar output of KVM, then you may continue.

CONFIG_KVM_MMIO=y
CONFIG_KVM_ASYNC_PF=y
CONFIG_KVM_VFIO=y
CONFIG_KVM_GENERIC_DIRTYLOG_READ_PROTECT=y
CONFIG_KVM_COMPAT=y
CONFIG_KVM=m
CONFIG_KVM_INTEL=m
CONFIG_KVM_AMD=m




 https://www.comparitech.com/net-admin/nessus-vs-openvas/

 https://www.comparitech.com/net-admin/nessus-vs-openvas/

 https://www.comparitech.com/author/tim_keary/






原来outlook 无法区分inline，请注意

--
Aaron

From: Aaron Shang <aaron.shang@pica8.com>
Sent: Monday, May 20, 2019 17:18
To: Iris Rong
Cc: Aaron Shang; Tracy Yang; Tom Jia; Daisy Zhao; Mikel Tang; Yachal Chen; George Guo; Richard Zhang; Frank Zhang; Vic Lan; Tong Zhang; Lin Du; Mandy Ding; Tim Yi; 'sqa'
Subject: Re: 答复: PICOS Debian package user guide

On Mon, May 20, 2019 at 04:56:17PM +0800, Iris Rong wrote:
>   > 1， Debian安装之前的版本必须是master(3.2) 版本(是通过onie install或upgrade更换的版本)；如果debian 安装前是2.11 的版本是否会有报错？

不支持在2.x版本执行deb相关操作。

>   > 2， 测试时安装顺序为：‘picos-linux’-> ‘picos-vasic’-> ‘picos-utils’-> ‘picos-xorplus’or ‘picos-ovs’；如果没有按顺序安装，是否需要测试？

必须按这个依赖顺序操作。不需要测试其他安装顺序。

>   > 3， 安装完成后查看是否image是否被更换：dpkg -l | grep picos-；l2l3和ovs是否能够正常工作；

应该列出的为新安装的版本。应该正常工作。

>   > 4， 带配置安装，检查配置是否丢失；

应该不会丢失配置。

>   > 5， 安装过程中在CLI 和/tmp/log/message不应出现err和fail信息；

应该不出现错误信息。空间不足会报错之类除外。

>   > 6， 安装platform不匹配的image, 安装时应提示错误；

应该提示。

>   > 7， 若卸载安装包，重新安装后l2l3和ovs是否能够正常工作： sudo apt remove * ， eg. sudo apt remove picos-utils

可以进行这步操作。但要保证对比之前和之后的包状态相同，不能卸载了3个包，再安装2个包，然后对比。

不要执行卸载通配符。那样会卸载很多。

因为包安装的post操作从来没有维护过，目前只有pre检查部分有测试。这部分需要进一步更新上。





Iris, Tracy,

验证安装是否成功。
这个其实是查询包状态，如果用户有卸载，默认的remove不会清除配置文件，所以是rc状态。
这里两个i表示正常，第一个是包已经安装，第二个是安装相关依赖与配置操作都完成。

admin@Xorplus:~$ dpkg -l | grep picos-
ii  picos-linux
ii  picos-ovs
ii  picos-utils
ii  picos-vasic
ii  picos-xorplus


卸载操作如下。
但我们不建议作卸载，这样系统就是原始的一个小Linux系统了。
用户非要这么作，根本上也阻拦不住，既然admin可以sudo，那么我们设定Required标志也是可以修改的。


admin@Xorplus:~$ sudo apt remove picos-utils
Reading package lists... Done
Building dependency tree
Reading state information... Done
The following packages will be REMOVED:
  picos-utils
0 upgraded, 0 newly installed, 1 to remove and 0 not upgraded.
After this operation, 0 B of additional disk space will be used.
Do you want to continue? [Y/n]
admin@Xorplus:~$


注意，卸载操作会卸载掉依赖于这个包的所有包，直接依赖或者间接依赖都会。


--
Aaron

From: Aaron Shang
Sent: Monday, May 20, 2019 09:55
To: Tracy Yang; Tom Jia; Daisy Zhao; tim; Mikel Tang; Yachal Chen; George Guo; Richard Zhang; Iris Rong; Frank Zhang; Vic Lan; Tong Zhang; Lin Du; Mandy Ding
Subject: Re: PICOS Debian package user guide


Updated some words.

Please give your review feedback for further refinements.


简单说明：
•	现在dpkg部分可以工作，可以单个进行包的安装。计划到3.3版本加入apt的部分，即用户通过apt update后自动获得并升级必要的升级包。
•	现在有5个包，如果卸载，则系统基本上是一个无PICOS的Linux系统，这时候安装，则需要手动确认安装包提供的型号是否匹配设备。如果这5个包没有被卸载过，则认为是一个upgrade操作，系统有型号信息，自动匹配，无需确认。
•	因N3000、N3100系列无存储，squashfs无法完成安装操作。所以无法支持此类设备。
•	5个包存在依赖关系，需要先安装被依赖的包

# Overview

PICOS packages had been provided from release 3.2 to let users upgrade some of available components manually, or reinstall PICOS components in cases some of them had been broken.

Note:
•	Some devices that lack of permanent storage media, and the system is running in versatile RAM over squashfs layers. So these models can not install additional packages due to the limitation, such as n3000/n3100 series.
•	Some PICOS component package would depend on other parts, so the depended ones should be installed if they does not exist on the system.

# How to use
When new releases of PICOS components had been made available to fix urgent issues, existing users can get the packages from PICOS support team.

For example, the package users get might be `picos-xorplus-s4100-3.2.3-9dc8d94.deb` saved in the working directory.

To install the package, the following command is OK:

    sudo dpkg -i picos-xorplus-s4100-3.2.3-9dc8d94.deb

If PICOS components had been removed from the running Linux system, that would be a new installation instead of upgrade, so users need to confirm the model compatibility manually by input `Yes` or `Y` at the prompt `Are you sure the model is MODEL (yes/no)?`

After the upgrade or installation finished, you need to reboot the box to have the new packages take effects.

# Available PICOS packages

- picos-linux
  - PICOS Linux Kernel, drivers and switching ASIC kernel modules.

- picos-vasic
  - PICOS VASIC and line card management libraries and utilities
  - Depend on picos-linux


- picos-xorplus
  - PICOS Layer 2 and Layer 3 software package
  - Depend on picos-vasic, picos-utils

- picos-ovs
  - PICOS OVS package
  - `picos-ovs` will have its own lib to access peripheral (such as FAN and PSU and LED) via sysfs
  - Depend on picos-vasic, picos-utils

- picos-utils
  - PICOS common utilities and configuration files
  - System config files, systemd units
  - Common utility such as ZTP/diag






Hi, architects and PLM members,

Here I hope to have you involved in talk about a proposal to rename image to comply with ONIE spec.

The requirement was from issues and requests of enterprise customers and industry standards.


# Purpose
Our images are ONIE format and targeted to be used in all ONIE-compliant hardware.

ONIE by design will detect default file names for automatic install and upgrade.

# What name can ONIE discover

According to current official spec, ONIE searches for the following default names in order.

    onie-installer-<arch>-<vendor>_<machine>-r<machine_revision>
    onie-installer-<arch>-<vendor>_<machine>
    onie-installer-<vendor>_<machine>
    onie-installer-<cpu_arch>-<switch_silicon_vendor>
    onie-installer-<arch>
    onie-installer

If an installer is successfully found, but the installer fails, ONIE moves on to the next in order.

In the case of ONIE self-update mode, the file name prefix is onie-updater instead of onie-installer.

I had tried images of the above names, all can be discovered and correctly installed.

# Why not with the `.bin` extension

From ONIE release after 2017.8, the above names with a `.bin` extension can also be recognized.
But as I checked, the latest box we had in lab in of 2017.4 ONIE build.
None of them can detect any of the above with `.bin` suffix added in my test.

If all boxes have the ONIE release after 2017.8, `.bin` file would be the best.

# What name is proposed for PICOS image

    onie-installer-<arch>-<vendor>_<machine>

Examples:

    /path/to/release/3.2.3/luxartech-npb/onie-installer-x86_64-dellemc_s40110_c2338
    /path/to/release/3.3.4/luxartech-npb/onie-installer-x86_64-dell_z9100_c2538
    /path/to/release/3.6.5/garland/onie-installer-x86_64-dellemc_s40110_c2338

Or packaged them like

    onie-installer-x86_64-dellemc_s40110_c2338-picos-3.6.5-garland.zip

Or with build ID as

    onie-installer-x86_64-dellemc_s40110_c2338-picos-3.6.5-garland-63b9bda101.zip


In fact, one release version MUST be mapped only to one build id (i.e. commit SHA1 in our repo).
Only this way, the release can be controlled, and tracked.


# Why not other names

For the first one

    onie-installer-<arch>-<vendor>_<machine>-r<machine_revision>

The last machine revision field is easily prone to change. And the change is controlled by vendor.
We should avoid maintenance efforts.

As for the others, they are too generic and may refer to lots of models.

    onie-installer-<vendor>_<machine>
    onie-installer-<cpu_arch>-<switch_silicon_vendor>
    onie-installer-<arch>
    onie-installer

And the switch_silicon_vendor form can only be recognized after ONIE 2015 releases, while many of current boxes were ONIE releases before that.

# How to decide these fields

As we would use <arch> and <vendor>_<machine> fields, we can get them from ONIE console, with onie-sysinfo command options:

        -m
                ONIE machine string

        -c
                ONIE CPU architecture

Example.

    ONIE:/ # onie-sysinfo -m
    dell_z9100_c2538

    ONIE:/ # onie-sysinfo -c
    x86_64


- <arch> is fixed as one of these 3:

    arm
    powerpc
    x86_64

NOTE: Names as ppc, armel, amd64, or x86, did not work here.

- <vendor>_<machine> is a string for vendor and model.

    This ONIE machine string can be read from `onie-sysinfo -m`.
    Here machine is the model.

NOTE: Changing the machine to any form of commercial off-the-shelf name like S4048ON,S4128F-ON,Z9100-ON did not work.


# What is valid for the strings
The above definitions place some restrictions on the valid characters allowed for the <ARCH>, <VENDOR> and <MODEL> strings.

    VENDOR - cannot contain _ (underscore) or - (hyphen) characters
    MODEL - cannot contain - (hyphen) character. _ (underscore) is OK
    ARCH - cannot contain _ (underscore) or - (hyphen) characters

# Example valid names

I had tried the following names, in order of choice.

    onie-installer-x86_64-dellemc_s4100_c2338
    onie-installer-dellemc_s4100_c2338
    onie-installer-x86_64
    onie-installer

The first one is the proposed one.

# How to deal with the release version and build id

- Release version will be decided by the link path of directory name, seen as in

    https://www.pica8.com/picos-releases/

- If required, package the ONIE file into ZIP file with version and build id in name.

# What need to do

- Document the change for 3.x releases; If required by customers, for 2.x future releases too.
- Make the change in build scripts.


# Reference

- https://opencomputeproject.github.io/onie/design-spec/discovery.html




Current status:
•	None of the current naming can be detected by ONIE for what ONIE is initiated for OS install automation.
•	It is not consistent in different releases and OEM remix builds.
Example of current names.
/tftp/build/release/garland/2.11.1.npb.7/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-7220fec.bin
/tftp/build/release/garland/2.11.1.npb.3/as5812_54x/onie-installer-amd64-as5812_54x-PICOS-2.11.npb.3-9e9ae8f.bin
/tftp/build/release/garland/2.11.1.npb.6/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-402b880.bin
/tftp/build/release/garland/2.11.16.npb.2/onie-installer-amd64-as7712_32x-PICOS-2.11.16-npb-7107deb.bin
/tftp/build/release/garland/2.11.1.npb.5/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-698db9b.bin
/tftp/build/release/garland/2.11.16.npb.3/onie-installer-amd64-as7712_32x-PICOS-2.11.16-npb-3d57b6d.bin
/tftp/build/release/2.9.1/luxartech-npb/onie-installer-x86-dcs7032q28-NpbOS-2.9.1-ad4256e.bin
/tftp/build/release/luxartech/100gnpb/2.9.2.10/onie-installer-x86-dcs7032q28-NpbOS-2.9.2.10-b4ea382.bin
/tftp/build/release/luxartech/100gnpb/onie-installer-x86-dcs7032q28-NpbOS-2.9.2.7-a068838.bin
/tftp/build/release/2.9.1.2/luxartech-npb/onie-installer-x86-dcs7032q28-NpbOS-2.9.1-e9c9eaf.bin
/tftp/build/daily/onie-installer-picos-s4100-3.2.1-63b9bda101.bin
/tftp/build/daily/n3100/onie-installer-picos-n3100-3.2.1-63b9bda101.bin
/tftp/build/daily/onie-installer-picos-z9264-3.2.1-63b9bda101.bin
/tftp/build/daily/z9264/onie-installer-picos-z9264-3.2.1-aa3d58f.bin
/tftp/build/daily/onie-installer-picos-n3100-3.2.1-63b9bda101.bin
/tftp/build/daily/as7726_32x/onie-installer-picos-as7726_32x-3.2.1-63b9bda101.bin
/tftp/build/daily/ag9032/onie-installer-picos-ag9032-3.2.1-aa3d58f.bin
/tftp/build/daily/as5812_54t/onie-installer-picos-as5812_54t-3.2.1-63b9bda101.bin
/tftp/build/daily/z9100/onie-installer-picos-z9100-3.2.1-63b9bda101.bin
/tftp/build/daily/as5712_54x/onie-installer-picos-as5712_54x-3.2.1-aa3d58f.bin
/tftp/build/daily/s4100/onie-installer-picos-s4100-3.2.1-63b9bda101.bin
/tftp/build/daily/n3000/onie-installer-picos-n3000-3.2.1-72fc38d19e.bin




On 2019-06-19 10:21, Lin Du wrote:
+ Aaron

Check the current naming difference with ONIE definition and provide the change for PLM to confirm.

Looks First Data got this issue when installed their system with USB.

Lin

From: Lin Du [mailto:ldu@pica8.local]
Sent: Wednesday, June 19, 2019 9:16 AM
To: iris.rong@pica8.local
Cc: tom.jia@pica8.local; vic.lan@pica8.local; mikel.tang@pica8.local
Subject: the USB installation testing

Iris,
Please have the team to check if our released images could be get installed automatically under ONIE with the image on USB disk instead of downloading manually.
Thanks,
Lin



--
Aaron







Added @Vic Lan, who is the owner of ONIE install and upgrade, and more experienced in this topic.

I revised the proposal and made some updates.
•	Updated typo in name examples I had given, the name should be dellemc_s4100_c2338
o	ONIE:/ # onie-sysinfo -m
dellemc_s4100_c2338
•	Revised proposed names, changed the candidate as
o	onie-installer-<vendor>_<machine>
•	Added consideration of OEM OS variants and name sharing of same model
•	Added why <arch> is not reliable.
So please refer to the refined copy attached.

Purpose
Our images are ONIE format and targeted to be used in all ONIE-compliant hardware.
ONIE by design will detect default file names for automatic install and upgrade.
What name can ONIE discover
According to current official spec, ONIE searches for the following default names in order.
onie-installer-<arch>-<vendor>_<machine>-r<machine_revision>
onie-installer-<arch>-<vendor>_<machine>
onie-installer-<vendor>_<machine>
onie-installer-<cpu_arch>-<switch_silicon_vendor>
onie-installer-<arch>
onie-installer
If an installer is successfully found, but the installer fails, ONIE moves on to the next in order.
In the case of ONIE self-update mode, the file name prefix is onie-updater instead of onie-installer.
I had tried images of the above names, all can be discovered and correctly installed.
Why not with the .bin extension
From ONIE release after 2017.8, the above names with a .bin extension can also be recognized.
But as I checked, the latest box we had in lab in of 2017.4 ONIE build.
None of them can detect any of the above with .bin suffix added in my test.
If all boxes have the ONIE release after 2017.8, .bin file would be the best.
What name is proposed for PICOS image
onie-installer-<vendor>_<machine>
Examples:
•	/path/to/release/3.2.3/luxartech-npb/onie-installer-dellemc_s4100_c2338
•	/path/to/release/3.3.4/luxartech-npb/onie-installer-dell_z9100_c2538
•	/path/to/release/3.6.5/garland/onie-installer-dellemc_s4100_c2338
We should package them into a more readable name, like versions,
•	onie-installer-picos-3.6.5-s4100.zip
•	onie-installer-picos-3.6.5-s4100-garland.zip
Or with build ID as
•	onie-installer-picos-3.8.7-garland-s4100-63b9bda101.zip
Or using commercial product names
•	onie-installer-picos-3.8.7-Z9100-ON-63b9bda101.zip
•	onie-installer-picos-3.8.7-S4128F-ON-63b9bda101.zip
Or with OEM variant name as
•	onie-installer-picos-3.2.5-HPE_AL_6921X-30f3897332.zip
•	onie-installer-picos-3.2.5-HPE_AL_6960-30f3897332.zip
NOTE, one release version MUST be mapped only to one build id (i.e. commit SHA1 in our repo).
Only this way, the release can be controlled, and tracked.
How to deal with OEM OS variants, product naming and name sharing
As shown above as example, we can express them in package names containing ONIE spec-compliant image.

The commercial name such as S4128F-ON or name sharing such as HPE_AL_6921X had been stored in `/sys/class/swmon/hwinfo/product_name` and reflected into `/etc/picos/branding` for consistent run time usage.

Why using this and why not other names
For the first one
onie-installer-<arch>-<vendor>_<machine>-r<machine_revision>
The last machine revision field is easily prone to change. And the change is controlled by vendor. We should avoid maintenance efforts.
For another candidate
onie-installer-<arch>-<vendor>_<machine>
The arch part would be puzzling by names of x86, x86_64, amd64, arm, armel, ppc, powerpc, etc.
And once vendor_machine is given, the arch can also be clear, exact one.
And in near future, changes can be expected in industry for the arch part. Linux kernel had renamed x86_64 to x86 for 64 bit x86, amd64 had been a long time common usage for that in many Linux systems.
Even as planned in future releases, we might combine image building to one round for each of x86 and arm arch, the images with these ONIE names can be generated during the one build round.
As for the others, they are too generic and may refer to lots of models.
onie-installer-<cpu_arch>-<switch_silicon_vendor>
onie-installer-<arch>
onie-installer
And the switch_silicon_vendor form can only be recognized after ONIE 2015 releases, while many of current boxes were ONIE releases before that.
How to decide these fields
The vendor_machine field can be decided from ONIE console, with onie-sysinfo command options:
-m
    ONIE machine string
Example.
ONIE:/ # onie-sysinfo -m
dell_z9100_c2538

ONIE:/ # onie-sysinfo -m
dellemc_s4100_c2338
•	arch is fixed as one of these 3:
o	arm
o	powerpc
o	x86_64
NOTE: Names as ppc, armel, amd64, or x86, did not work here as in my test.
•	vendor_machine is a string for vendor and model.
o	This ONIE machine string can be read from onie-sysinfo -m.
o	Here machine is the model.
NOTE: Changing the machine to any form of commercial off-the-shelf name like S4048ON,S4128F-ON,Z9100-ON did not work.
What is valid for the strings
The above definitions place some restrictions on the valid characters allowed for the ARCH, VENDOR and MODEL strings.
•	VENDOR - cannot contain _ (underscore) or - (hyphen) characters
•	MODEL - cannot contain - (hyphen) character. _ (underscore) is OK
•	ARCH - cannot contain _ (underscore) or - (hyphen) characters
NOTE: The above on ARCH line might be typo of spec, actually x86_64 is the name in spec, while it contain underscore.
Example valid names
I had tried the following names, in order of choice.
•	onie-installer-x86_64-dellemc_s4100_c2338
•	onie-installer-dellemc_s4100_c2338
•	onie-installer-x86_64
•	onie-installer
The proposed one is
•	onie-installer-dellemc_s4100_c2338
How to deal with the release version and build id
•	Release version will be decided by the link path of directory name, seen as in
https://www.pica8.com/picos-releases/
•	If required, package the ONIE file into ZIP file with version and build id in name.
What need to do
•	Document the change for 3.x releases; If required by customers, for 2.x future releases too.
•	Make the change in normal and OEM variant build scripts.
Reference
•	https://opencomputeproject.github.io/onie/design-spec/discovery.html
Current status
•	None of the current naming can be detected by ONIE for what ONIE is initiated for OS install automation.
•	It is not consistent in different releases and OEM remix builds.
Example of current names, none of which can be ONIE spec compliant.
/tftp/build/release/garland/2.11.1.npb.7/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-7220fec.bin
/tftp/build/release/garland/2.11.1.npb.3/as5812_54x/onie-installer-amd64-as5812_54x-PICOS-2.11.npb.3-9e9ae8f.bin
/tftp/build/release/garland/2.11.1.npb.6/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-402b880.bin
/tftp/build/release/garland/2.11.16.npb.2/onie-installer-amd64-as7712_32x-PICOS-2.11.16-npb-7107deb.bin
/tftp/build/release/garland/2.11.1.npb.5/onie-installer-amd64-as7712_32x-PICOS-2.11-hotfix-npb-698db9b.bin
/tftp/build/release/garland/2.11.16.npb.3/onie-installer-amd64-as7712_32x-PICOS-2.11.16-npb-3d57b6d.bin
/tftp/build/release/2.9.1/luxartech-npb/onie-installer-x86-dcs7032q28-NpbOS-2.9.1-ad4256e.bin
/tftp/build/release/luxartech/100gnpb/2.9.2.10/onie-installer-x86-dcs7032q28-NpbOS-2.9.2.10-b4ea382.bin
/tftp/build/release/luxartech/100gnpb/onie-installer-x86-dcs7032q28-NpbOS-2.9.2.7-a068838.bin
/tftp/build/release/2.9.1.2/luxartech-npb/onie-installer-x86-dcs7032q28-NpbOS-2.9.1-e9c9eaf.bin
/tftp/build/daily/n3100/onie-installer-picos-n3100-3.2.1-63b9bda101.bin
/tftp/build/daily/z9264/onie-installer-picos-z9264-3.2.1-aa3d58f.bin
/tftp/build/daily/as7726_32x/onie-installer-picos-as7726_32x-3.2.1-63b9bda101.bin
/tftp/build/daily/ag9032/onie-installer-picos-ag9032-3.2.1-aa3d58f.bin
/tftp/build/daily/as5812_54t/onie-installer-picos-as5812_54t-3.2.1-63b9bda101.bin
/tftp/build/daily/z9100/onie-installer-picos-z9100-3.2.1-63b9bda101.bin
/tftp/build/daily/as5712_54x/onie-installer-picos-as5712_54x-3.2.1-aa3d58f.bin
/tftp/build/daily/s4100/onie-installer-picos-s4100-3.2.1-63b9bda101.bin
/tftp/build/daily/n3000/onie-installer-picos-n3000-3.2.1-72fc38d19e.bin
/tftp/build/release/2.11.5/ag9032/onie-installer-x86-ag9032-picos-2.11.5-ec90458.bin
/tftp/build/release/2.11.5/as5812_54t/onie-installer-x86-accton_as5812_54t-picos-2.11.5-ec90458.bin
/tftp/build/release/2.11.5/as5712_54x/onie-installer-x86-accton_as5712_54x-picos-2.11.5-ec90458.bin
/tftp/build/release/2.11.5/as7312_54x/onie-installer-x86-accton_as7312_54x-picos-2.11.5-ec90458.bin
/tftp/build/release/2.9.2.5/HPE_AL_6921T/onie-installer-x86-HPE_AL_6921T-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/arctica4806xp/onie-installer-x86-penguin_arctica4806xp-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/as5812_54x/onie-installer-x86-accton_as5812_54x-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/HPE_AL_6940/onie-installer-x86-HPE_AL_6940-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/as6712_32x/onie-installer-x86-HP6712-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/HPE_AL_6920/onie-installer-x86-HPE_AL_6920-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/as5812_54t/onie-installer-x86-accton_as5812_54t-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/z9100/onie-installer-x86-DELL_z9100-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/HPE_AL_6921X/onie-installer-x86-HPE_AL_6921X-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/HPE_AL_6960/onie-installer-x86-HPE_AL_6960-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/HP6712/onie-installer-x86-HP6712-picos-2.9.2.5-30f7332.bin
/tftp/build/release/2.9.2.5/as5712_54x/onie-installer-x86-accton_as5712_54x-picos-2.9.2.5-30f7332.bin



--
Aaron







Thanks to Lin's hard work trouble shooting the wierd root cause.

Vic and I had been going on to have a fix.

The defining of
CONFIG_VIRT_CPU_ACCOUNTING_NATIVE
is only applicable to PPC64, i.e. that is not select-able before enabling PPC64.
But 5101 is not PPC64.

In later kernels, the issue should be avoided by changing of accounting by all u64 around the issue point

    ./kernel/sched/cputime.c:       stime = scale_stime(stime, rtime, stime + utime);

Vic is continuing on this.


--
Aaron

From: Sharad Ahlawat
Sent: Wednesday, June 19, 2019 00:40
To: Lin Du
Cc: arch; plm@pica8.com
Subject: Re: 5101 kernel crash on Luxartech

Thanks for sharing this Lin.

So all our 32bit 2.11.x switches, including at Verizon have this issue?

If not and this is related to OVS’s usage of the CPU accounting, then we should be addressing that rather than changing a Linux Kernel definition which would have other consequences.

--
/Sharad


From: Lin Du <lin.du@pica8.com>
Date: Tuesday, June 18, 2019 at 00:11
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
Cc: Mikel Tang <mikel.tang@pica8.com>
Subject: FW: 5101 kernel crash on Luxartech

Sharad, Hai, Zoneson,
There are 4 switches rebooted in the past month on Luxartech site.
The switches are P-5101, which have run for about 600 days.
The dumped message help us to isolate the failed point.

The issue will be triggered when the OVS process consumes 2^32 Jiffies CPU time, including user space and kernel space CPU usage.
The average CPU usage is usually around 10-15% for all applications and kernel system components, including ovs-vswitchd process.

2^32 = 4,294,967,296 Jiffies = 4,294,967.296 seconds = 49.710 days

The above running time could be mapped to the system up running time by dividing the process average CPU usage rate, for example 8% for ovs-vswitchd.
49.710 days/ 8% =  621 days.

This issue only happens on 32 bits platforms and with calling getrusage() frequently to get the process resource usage data.
So it doesn’t occur on L2/L3 running environment(no getruage called), and not happening on 64 bits machine as well.

Thanks,
Lin


From: Lin Du
Sent: Tuesday, June 18, 2019 2:23 PM
To: Mikel Tang; Richard Zhang; Aaron Shang; Tom Jia; Vic Lan; Tim Yi; Wim Fu
Cc: Iris Rong
Subject: RE: 5101 内核抛出异常

Aaron,
Enable CONFIG_VIRT_CPU_ACCOUNTING_NATIVE on kernel configuration, which will make the system time as u64 instead of 32 bits long type.
No other code change is needed.

This happens on 32 bits CPU only, powerpc and arm are the two platforms will be impacted by the process CPU time overflow issue.

###
19 #ifndef CONFIG_VIRT_CPU_ACCOUNTING_NATIVE
20 #include <asm-generic/cputime.h>
21 #ifdef __KERNEL__
22 static inline void setup_cputime_one_jiffy(void) { }
23 #endif
24 #else
25
26 #include <linux/types.h>
27 #include <linux/time.h>
28 #include <asm/div64.h>
29 #include <asm/time.h>
30 #include <asm/param.h>
31
32 typedef u64 __nocast cputime_t;
33 typedef u64 __nocast cputime64_t;
###

Here is the related piece of codes extracted from kernel/sched/cputime.h

###
556 static void cputime_adjust(struct task_cputime *curr,
557                            struct cputime *prev,
558                            cputime_t *ut, cputime_t *st)
559 {
560         cputime_t rtime, stime, utime;
561
562         /*
563          * Tick based cputime accounting depend on random scheduling
564          * timeslices of a task to be interrupted or not by the timer.
565          * Depending on these circumstances, the number of these interrupts
566          * may be over or under-optimistic, matching the real user and system
567          * cputime with a variable precision.
568          *
569          * Fix this by scaling these tick based values against the total
570          * runtime accounted by the CFS scheduler.
571          */
572         rtime = nsecs_to_cputime(curr->sum_exec_runtime);
573
574         /*
575          * Update userspace visible utime/stime values only if actual execution
576          * time is bigger than already exported. Note that can happen, that we
577          * provided bigger values due to scaling inaccuracy on big numbers.
578          */
579         if (prev->stime + prev->utime >= rtime)
580                 goto out;
581
582         stime = curr->stime;
583         utime = curr->utime;
584
585         if (utime == 0) {
586                 stime = rtime;
587         } else if (stime == 0) {
588                 utime = rtime;
589         } else {
590                 cputime_t total = stime + utime;
591
592                 stime = scale_stime((__force u64)stime,
593                                     (__force u64)rtime, (__force u64)total);
594                 utime = rtime - stime;
595         }

Here is failed case:
Total = stime + utime, which is equal to 2^32. Since it is a 32 bits long type integer(cputime_t), its actual value is zero after overflow truncated.

So the codes crashed at:
548         scaled = div_u64((u64) (u32) stime * (u64) (u32) rtime, (u32)total);

Adding the above kernel option should resolve this issue.
Thanks,

Lin

From: Lin Du
Sent: Monday, June 17, 2019 8:19 PM
To: Mikel Tang; Richard Zhang; Aaron Shang; Tom Jia; Vic Lan; Tim Yi; Wim Fu
Cc: iris.rong@pica8.com
Subject: RE: 5101 内核抛出异常

Mikel,
这个问题基本定位出来了。
把下面黄色的部分修改为（u64）total, 就应该解决此问题。 把64位的数截断位32位，导致值为0，除法异常。
Total 的值为0xXXXXXXXX00000000值时候就触发此问题。也就总的运行时间超过2^32微秒（Jiffies）的时候，就有可能出现。
应该是kernel的bug。


static cputime_t scale_stime(u64 stime, u64 rtime, u64 total)
513 {
514         u64 scaled;
515
516         for (;;) {
517                 /* Make sure "rtime" is the bigger of stime/rtime */
518                 if (stime > rtime)
519                         swap(rtime, stime);
520
521                 /* Make sure 'total' fits in 32 bits */
522                 if (total >> 32)
523                         goto drop_precision;
524
525                 /* Does rtime (and thus stime) fit in 32 bits? */
526                 if (!(rtime >> 32))
527                         break;
528
529                 /* Can we just balance rtime/stime rather than dropping bits? */
530                 if (stime >> 31)
531                         goto drop_precision;
532
533                 /* We can grow stime and shrink rtime and try to make them both fit */
534                 stime <<= 1;
535                 rtime >>= 1;
536                 continue;
537
538 drop_precision:
539                 /* We drop from rtime, it has more bits than stime */
540                 rtime >>= 1;
541                 total >>= 1;
542         }
543
544         /*
545          * Make sure gcc understands that this is a 32x32->64 multiply,
546          * followed by a 64/32->64 divide.
547          */
548         scaled = div_u64((u64) (u32) stime * (u64) (u32) rtime, (u32)total);
549         return (__force cputime_t) scaled;
550 }

Thanks,
Lin






Wu Haijun.

Pros:
•	Broad working history in many Linux system areas across different layers, and with hands-on work on some individual tech points.
•	Work experience with what we would need for current and future work, such as test framework and automation.
•	Good at expressing ideas and communication.
•	Trouble shooting and prototype building experiences.

Cons:
•	Some minor wrong concepts, such as `Implement NTP and 1588.` as liberal copy from resume, but he did not know what the number 1588 is for, whether or not it is RFC id.
o	https://en.wikipedia.org/wiki/Precision_Time_Protocol
•	Failed to summarize of some points in his resume, such as ANCP, TWAMP.


Conclusion:
•	Recommended.





Mentioning aes might be mixing encryption with cryptographic hash, which is used in our scenario.

Cryptographic hash is secure in a long run using SHA512, i think.

--
Aaron

From: Aaron Shang
Sent: Wednesday, June 12, 2019 17:55
To: Andrew Lissitz; Sharad Ahlawat; Hai Vo-Dinh; Tom Jia; Zoneson Chen
Cc: TACinternal
Subject: Re: <Tom help>FW: VZ - Picos encryption - Is it Scrypt or SHA 256?

One easy means to improve security is to do key stretching by using or rounds options. That adds no additional efforts over current system. Although I had never seen such deployments.

--
Aaron

From: Aaron Shang
Sent: Wednesday, June 12, 2019 17:46
To: Andrew Lissitz; Sharad Ahlawat; Hai Vo-Dinh; Tom Jia; Zoneson Chen
Cc: TACinternal
Subject: Re: <Tom help>FW: VZ - Picos encryption - Is it Scrypt or SHA 256?

Hi, all,

I had no idea now on how to do aes-256 for shadow.

In Linux, the shadow encryption is provided by glibc, which now only supports the algo as Sharad had listed.

aes-256 can be provided from openssl, but not possible now for shadow.

From 3.x on, the shadow is SHA512, which is the highest possible algo known for shadow keys.




The current issue is also as Sharad pointed out that the user `operator` had the same pre-defined value for all instances.

The best means to fix this issue, is to request users to set one at first time of login as what the `admin` user does now.


--
Aaron






dhcpd -t -cf /path/to/dhcpd.conf






说明一下前面的变化，未来的变化，和这样的issue

这个error的根源是比较version串到xgs-后面robo的r比4f56的4要greater
这个是临时的变化，可以忽略。


前面的变化：
上周，这个warning应该有可能继续，也就是可以安装低版本的包，
现在不能继续变error，是因为为免随便卸载而提升了importance level


未来的变化：
•	不再支持同一个版本安装升级，因为SHA变化不能作为比较的串，那个串无法比较版本高低
•	那么为了测试，应该用版本高的，比如，用3.2.0.1或3.2.1往3.2.0上安装
o	我会专门拉一个分支用于测试包升级：master-picos-deb-upgrade-test
•	按照与Sharad达成的结论，限制minor位及以上跨版本升级，就3.3.x的不允许往3.2.x安装。
•	picos-vasic的版本采用其他PICOS的release，即遵循现在的3.2.0等。
•	master分支的版本使用next-release作为version，以便于测试升级. 9.8.7已经不再使用
o	 比如，现在master分支的版本是3.2.0，待3.2.0分支branch out以后，则master的version变为3.3.0



Comment # 20 on bug 10866 from Sophia Sun
issue10:
admin@Xorplus:~$
admin@Xorplus:~$
admin@Xorplus:~$
admin@Xorplus:~$
admin@Xorplus:~$ sudo dpkg -i picos-xorplus-as5712_54x-3.2.0-4f56650.deb
(Reading database ... 17417 files and directories currently installed.)
Preparing to unpack picos-xorplus-as5712_54x-3.2.0-4f56650.deb ...
Unpacking picos-xorplus (3.2.0-4f56650) over (3.2.0-4f56650) ...
dpkg: warning: package picos-xorplus contained list as info file
dpkg: dependency problems prevent configuration of picos-xorplus:
picos-xorplus depends on picos-vasic (>= 6.5.15-xgs-robo); however:
Version of picos-vasic on system is 6.5.15-xgs-4f56650.
dpkg: error processing package picos-xorplus (--install):
dependency problems - leaving unconfigured
Errors were encountered while processing:
picos-xorplus

You are receiving this mail because:
•	You are on the CC list for the bug.





These dangerous commands, for your info.


--
Aaron

From: Aaron Shang
Sent: Wednesday, March 27, 2019 10:20
To: Lisa Pi
Cc: Engineering
Subject: Keep git working dir clean

Lisa,

To save clone time due to the huge size of current repo, you can use these practices for building.

These are dangerous actions, only for building, not recommended for daily working.



Get the latest changes:

    git fetch --all


Clean all local changes for files that had been in git repo:

    git reset --hard

[This is dangerous that you will lost your changes if you had not committed them in git.]



Clean all local changes for files that had been in git repo, also DROP local commits:

    git reset --hard origin/BRANCH_NAME


[This is dangerous that you will lost your commits that you had not pushed out to remote repo.]







Clean all local files that had NOT been in git repo:



    git clean -dfx

[This is dangerous that you will lost your work if you had not add them in git.]


--
Aaron





Actually the MD5 and SHA512 passwords can co-exist in same shadow file, identified by the field after the account name.
`$1` means MD5, `$6` means SHA-512, `$5` for SHA-256.


See also the following output.

$ man 3 crypt
...

       If  salt  is  a  character  string starting with the characters "$id$" followed by a string optionally terminated by "$", then the
       result has the form:

              $id$salt$encrypted

       id identifies the encryption method used instead of DES and this then determines how the rest of the  password  string  is  inter‐
       preted.  The following values of id are supported:

              ID  | Method
              ─────────────────────────────────────────────────────────
              1   | MD5
              2a  | Blowfish (not in mainline glibc; added in some
                  | Linux distributions)
              5   | SHA-256 (since glibc 2.7)
              6   | SHA-512 (since glibc 2.7)

       Thus,  $5$salt$encrypted  and  $6$salt$encrypted contain the password encrypted with, respectively, functions based on SHA-256 and
       SHA-512.

       "salt" stands for the up to 16 characters following "$id$" in the salt.  The "encrypted" part of the password string is the actual
       computed password.  The size of this string is fixed:

       MD5     | 22 characters
       SHA-256 | 43 characters
       SHA-512 | 86 characters

       The  characters in "salt" and "encrypted" are drawn from the set [a-zA-Z0-9./].  In the MD5 and SHA implementations the entire key
       is significant (instead of only the first 8 bytes in DES).



--
Aaron

From: James Liao
Sent: Monday, February 11, 2019 9:01:09 AM
To: Yachal Chen; Aaron Shang
Subject: Re: PO for TMAX cloud

Aaron,

If we change from MD5 to SHA512, will there be any backward compatibility issue?

James

From: James Liao <james.liao@pica8.com>
Date: Friday, February 8, 2019 at 4:10 PM
To: Yachal Chen <yachal.chen@pica8.com>
Cc: Henry Pan <henry.pan@pica8.com>
Subject: Re: PO for TMAX cloud

Yachal,

Can you help me to check with the engineering team on the following questions from Henry? (focus on the yellow highlight)

Please do NOT ask engineering to make any changes. This is part of a bunch of requests from Korea. We either change them all, or we don’t waste our time.

James

2. Account Description
a) Account optimize and Password security
-      Basically, PicOS has below accounts.
-      But, only "admin” and “operator” are used.
-      I think some account is not necessary for PicOS running.
-      Would you please optimize those accounts?

-      In the "/etc/shadow", the admin's password is created by "MD5” not "SHA512” by default. It is not acceptable.
-      It much be changed to "SHA512” by fault. Also, it is much better for account security in PicOS

4.  SNMP v3
-      SNMP v3 is required. (please confirm with engineering)

5.  HTTPS
-      Currently, PicOS is supporting HTTP.
-      But, HTTPS is required for more secure.







Go through these requirements one by one inline.


Almost all can be done by tuning SSHD or PAM settings. Vic had been working on similar requirements before.


  To reduce change in your original package, I have negotiated with them to support the "post script” if anyone want to set more strong security.
Aaron: These can be like the `rc.local` kind of systemd units.

  you can generate it whatever you can such as script or app…  but, it will be needed some interactive with users.
                     Aaron: CLI interfaces to achieve these changes seems complicated. Or we tell them which systemd units to edit then they can put changes there.

  Here is what should do it
  Every password/electronic signatures are save with  “SHA512”
Aaron: These can be done via pam module parameters.

  Password complexity
  Input by user, the password min length should be set
  Input by user, the password max length should be set
  The Password complexity such as lowercase, uppercase, digit and special character
It can be get input by user and set the "lcredit", "ucredit", "dcredit” and "ocredit”

Aaron: These can be done via PAM module parameters.


  Login fail and limit to connect
  User can set the login fail count
  User can set the connection limitation when login fail occurred

  Session timeout
User can set the session timeout time


Aaron: SSHD config can help in some login policy. PAM module parameters may also help. Both needs investigation and testing. If both fails the requirement, well tuned iptables rules can do so. We had tested similar requirements before from Mikel's input.



  User can set the how many session can connected by each group such as "xorp" “xorp-operator “


Aaron: Never thought about this kind of scenarios. Needs to investigate SSHD or PAM options.



  Set the password for “root” account


Aaron: This can be set easily. Allowing root passwd login also needs enabling in sshd config.


  Remove sudo "no password” of xorp group in “/etc/sudoers”
If anyone need to get "root” authority by "sudo” command, the root password must be required.

            Aaron: This can be done easily.




--
Aaron








Didn't send that out before this.
I made a list for each month which is easier. But spent more time for weekly numbers.

In the past year, the most active branches are 3.1.0 and 2.11-hotfix branches.

For several months, `master` branch was not active, because we stopped most commits there due to some messed commits both for 2.x and 3.x. `master` will restore its role from next week, as baseline for future 3.x releases.


You may noticed there were several times of dozens of millions of lines added, that were introductions of SDK codes.
We planned to hold them in separate repo to improve git performance and the byproduct is reflecting our team commits more accurate.

These didn't show changes in KERNEL, which is in another separate repo for clearly sync with upstream bug fixes.
But the changes were almost merely kernel config changes, in very limited lines.
----





, I think we can ignore this fix.


Why?
•	The issue is in RDS module.
    The RDS (Reliable Datagram Sockets) protocol provides reliable, sequenced delivery of datagrams over Infiniband or TCP.


This is therefore only exploitable on systems that actually use rds.

I do not think we used this.


Please feed back your comments.


Summary:

    The Linux Kernel is prone to a race-condition vulnerability.
    An attacker can exploit this issue to cause denial of service and execute arbitrary code.
    Linux kernel versions prior to 5.0.8 are vulnerable.

Status:
•	Debian
o	It is included in Linux 4.19.37-1 in Debian 10 buster and sid, not fixed in other previous releases.
•	Linux
o	It is fixed in release 4.14.112 from LTS linux-4.14.y branch
o	It was first fixed after release v5.0.8
o	It was committed and tagged v5.2-rc1 and v5.1-rc4
	https://github.com/torvalds/linux/commit/cb66ddd156203daefb8d71158036b27b0e2caf63



--
Aaron








https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=928989


On our LTS branch, there had been no this fix:

https://cdn.kernel.org/pub/linux/kernel/v4.x/ChangeLog-4.14.119


So we can wait for say 4.14.120 and rebase on that HEAD. Currently we had reached 4.14.88.


To watch, we can tracking 4.14.y.

https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/log/net/rds/tcp.c?h=linux-4.14.y


From the fix, we can see that is one line change on condition judge, we can try it if we do not want to wait.

https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=cb66ddd156203daefb8d71158036b27b0e2caf63



I had not read through the exploit scenario and severeness, to see if we can wait for 4.14 back port.




维特根斯坦曾说的：“我语言的极限就是我世界的极限。”

Roaring?
tina wang
爱死你最后一句话。从10年前工作接触站长，发现我们一个特点：无论互联网app还是网红、明星，推崇最大性价比做大流量，不管真假好坏，然后一定要想尽办法变现。low的东西，不去提高质量，而去下沉找更low的audience，或者low的手段欺诈，屡试不爽

Amazing Grace
作为一名媒体人，特别同意假张所说：“对内容生产者和制作者来说，Netflix最大的启示和鼓舞就是，这仍然是一个内容为王的时代，好内容在任何时候都不会过时。而且有了互联网，传播变得更加容易，好内容一定会被发现，也更有希望积攒起海量的用户……只要认真做的东西，就不会被辜负。” 就如假张滴文章就不会被辜负只要我们不低估我们的读者或观众








System.out.println("点个在看吧！");
console.log("点个在看吧！");
print("点个在看吧！");
printf("点个在看吧！\n");
cout << "点个在看吧！" << endl;
Console.WriteLine("点个在看吧！");
Response.Write("点个在看吧！");
alert("点个在看吧！")
echo "点个在好看吧！"

这个电路做了短路处理了，在线路上有大电流，会起火，
一般廉价的电动车用铅酸电池，或者低端锂电池，充电器也用廉价材料，
而电动车上很多塑料皮革，容易燃烧起那些黑烟，
合格的充电器至少有满充后断电的检测，还有过流保护，
北京有些小区有集中的支付宝扫码充电的桩，

前一阵小区发放了烟雾报警器，测试很灵敏，我们赶紧装在家里充电的地方了，
还要注意充电的线路负载，不用不好的插排和电线



--
Aaron









As for the questions here:
1.	/etc/shadow
•	If I set the “SHA512” for password, it is saved on “/etc/shadow”.
•	Question #1) do you know how many Byte is used for “salt key”?
•	Question #2) is it “fixed” or “random”?
•	Please refer this web page https://patrickmn.com/security/storing-passwords-securely/

In current shadow system, the salt key is 8 characters.

The value is random generated each time with shadow password, the length is fixed as 8 characters.





--
Aaron


From: Yachal Chen
Sent: Tuesday, February 19, 2019 13:43
To: kgi@in4a.co.kr; Henry Pan; Aaron Shang
Subject: RE: password and upgrade

Forget forward to aaron

Yachal Chen
Pica8, Inc.
ychen@pica8.com   |  www.pica8.com

From: Yachal Chen
Sent: Monday, February 18, 2019 9:21 PM
To: 'kgi@in4a.co.kr' <kgi@in4a.co.kr>; Henry Pan <henry.pan@pica8.com>
Subject: RE: password and upgrade

Hi, Kevin,

1.	I forwarded your question to aaron maybe he can answer you
2.	In upgrade script, it is fixed check with md5, if you need changed to SHA512, we need temporarily build a new image. Can you just work around it by hide the md5 checking in upgrade script?  I think you can mannul modify the upgrade script by yourself to skip any md5 checking. The script is located in  “/usr/sbin/upgrade “

Thanks
Yachal Chen
Pica8, Inc.
ychen@pica8.com   |  www.pica8.com

From: kgi@in4a.co.kr [mailto:kgi@in4a.co.kr]
Sent: Monday, February 18, 2019 4:22 AM
To: Yachal Chen <yachal.chen@pica8.com>; Henry Pan <henry.pan@pica8.com>
Subject: password and upgrade

Dear Yachal!

Hi..
I have two questions about password and upgrade.

1.	/etc/shadow
•	If I set the “SHA512” for password, it is saved on “/etc/shadow”.
•	Question #1) do you know how many Byte is used for “salt key”?
•	Question #2) is it “fixed” or “random”?
•	Please refer this web page https://patrickmn.com/security/storing-passwords-securely/

2.	“upgrade” command
•	When I run the “upgrade” command, it is check the “MD5” hash first.
•	Question #3) How can I change it from “MD5” to “SHA512”?
•	Would you please send the “update” file after change it to “SHA512”?

Thank you!
Kevin










I had checked our kernel config, that the two options had both been enabled.

    CONFIG_CRYPTO_SHA256=y

    CONFIG_CRYPTO_AES=y

I can make aes256 connection.

admin@XorPlus:~$ sudo openvpn --config client.ovpn --cipher aes256
Mon Jan  3 18:12:22 2000 OpenVPN 2.2.1 arm-linux-gnueabi [SSL] [LZO2] [EPOLL] [PKCS11] [eurephia] [MH] [PF_INET6] [IPv6 payload 20110424-2 (2.2RC2)] built on Jun 22 2017
Mon Jan  3 18:12:22 2000 IMPORTANT: OpenVPN's default port number is now 1194, based on an official port number assignment by IANA.  OpenVPN 2.0-beta16 and earlier used 5000 as the default port.
Mon Jan  3 18:12:22 2000 NOTE: OpenVPN 2.1 requires '--script-security 2' or higher to call user-defined scripts or executables
Mon Jan  3 18:12:22 2000 TUN/TAP device tun0 opened
Mon Jan  3 18:12:22 2000 do_ifconfig, tt->ipv6=0, tt->did_ifconfig_ipv6_setup=0
Mon Jan  3 18:12:22 2000 /sbin/ifconfig tun0 10.8.0.2 pointopoint 10.8.0.1 mtu 1500
Mon Jan  3 18:12:22 2000 UDPv4 link local (bound): [undef]
Mon Jan  3 18:12:22 2000 UDPv4 link remote: [AF_INET]10.10.50.24:1194
Mon Jan  3 18:12:32 2000 Peer Connection Initiated with [AF_INET]10.10.50.24:1194
Mon Jan  3 18:12:33 2000 Initialization Sequence Completed
Mon Jan  3 18:21:46 2000 event_wait : Interrupted system call (code=4)
Mon Jan  3 18:21:46 2000 /sbin/ifconfig tun0 0.0.0.0
Mon Jan  3 18:21:46 2000 SIGINT[hard,] received, process exiting




Sorry for being late.

--
Aaron

From: Nirmal Karia
Sent: Thursday, October 11, 2018 3:45:24 AM
To: Aaron Shang
Cc: Zoneson Chen; Sharad Ahlawat
Subject: Fw: Install OPenvpn

Hi Arron,

Can you please look into this when you have time . I have a customer on hold on.

Appreciate your help and time.

Thanks,
Nirmal


From: Nirmal Karia
Sent: Tuesday, October 9, 2018 1:40 PM
To: Aaron Shang
Cc: Sharad Ahlawat; Zoneson Chen
Subject: Re: Install OPenvpn

Hi Arron,

I can successfully install OpenVPN. Can you please check what encryption modules are supported by kernel.
The customer is keen on using SHA256?

I checked the ls /proc/crypto file I only found aes128. Can you confirm if we can use AES-256 for openvpn.

Thanks,
Nirmal

From: Aaron Shang
Sent: Sunday, October 7, 2018 8:35:02 PM
To: Nirmal Karia
Cc: Sharad Ahlawat; Zoneson Chen
Subject: Re: Install OPenvpn

Hi, Nirmal,

I do not know why that box was in an unstable status.

Here are my steps and it can be OK to run `openvpn` after the install.


      sudo apt-get update
      sudo apt-get install -f
      sudo apt-get install openvpn


If there were prompts that show:

    openvpn: error while loading shared libraries: liblzo2.so.2: cannot open shared object file: No such file or directory
Please reinstall the lib:

      sudo apt-get install --reinstall liblzo2-2




--
Aaron

From: Nirmal Karia
Sent: Monday, October 8, 2018 1:37:11 AM
To: Aaron Shang
Cc: Sharad Ahlawat; Zoneson Chen
Subject: Re: Install OPenvpn

Hi aaron,

-f does not work.
You can access the device if you have time
Telnet 172.16.0.21 7042

Nirmal


Sent from my iPhone

On Oct 7, 2018, at 8:06 AM, Aaron Shang <aaron.shang@pica8.com> wrote:
You may try

    sudo apt-get -f install

But that might not work.

It showed that `openvpn` depends on new version of libc, but our box had difficulties upgrading to new version of libc.


I had no access of boxes now. I would try and update you 9 hours later.




--
Aaron

From: Nirmal Karia
Sent: Sunday, October 7, 2018 2:37:51 AM
To: Aaron Shang
Cc: Sharad Ahlawat; Zoneson Chen
Subject: Install OPenvpn

Hi Aaron,

We are facing issue installing openVPN on our switch. We are getting following errors Can you please share your inputs.

admin@XorPlus:/home$ sudo apt-get install openvpn
Reading package lists... Done
Building dependency tree
Reading state information... Done
openvpn is already the newest version.
You might want to run 'apt-get -f install' to correct these:
The following packages have unmet dependencies:
 libc-bin : Depends: libc6 (> 2.19) but 2.13-38+deb7u12 is to be installed
 libc6 : Depends: libc-bin (= 2.13-38+deb7u12) but 2.19-18+deb8u10 is to be installed
 openvpn : Depends: liblzo2-2 but it is not going to be installed
E: Unmet dependencies. Try 'apt-get -f install' with no packages (or specify a solution).
admin@XorPlus:/home$


admin@XorPlus:/home$ version
Copyright (C) 2009-2018 Pica8, Inc
===================================
Hardware Model                : as4610_54p
Linux System Version/Revision : 2.11.12/cde663e
Linux System Released Date    : 09/28/2018
L2/L3 Version/Revision        : 2.11.12/cde663e
L2/L3 Released Date           : 09/28/2018
OVS/OF Version/Revision       : 2.11.12/cde663e
OVS/OF Released Date          : 09/28/2018



Thanks,
Nirmal










Yes, that's the expected behavior.

The server can also respond requests from other clients.


We can adjust output according to exact requirements, perpaps make it CLI options.


Thanks for the efforts.

--
Aaron

From: Elijah Ai
Sent: Tuesday, July 17, 2018 5:51:15 PM
To: Aaron Shang; Mikel Tang
Cc: Lin Du
Subject: Re: Re: Another reference implementation of TWAPM

It works at last, the data collection looks as follows:


Kindly,
Elijah

elijah.ai@pica8.com

From: Aaron Shang
Date: 2018-07-17 17:39
To: Elijah Ai; Mikel Tang
CC: Lin Du
Subject: Re: Another reference implementation of TWAPM

To run `server`, some CAPabilities are needed.

To set that CAP permision, `setcap` is needed, which is in package `libcap2-bin`.


    sudo apt update
    sudo apt-get update
    sudo apt-get install libcap2-bin
    sudo setcap 'cap_net_bind_service=+ep' ./server
    ./server -p 50862

The official port for OWAMP/TWAMP protocol is a reserved number 862, here we use a larger number to use without root priviledge.



--
Aaron

From: Aaron Shang
Sent: Tuesday, July 17, 2018 5:01:17 PM
To: Elijah Ai; Mikel Tang
Cc: Lin Du
Subject: Another reference implementation of TWAPM

Hi, Elijah, Mikel,

Here is another reference implementation of TWAPM protocol.

I built that for x86, so you can test on x86 boxes, using the generated `client` and `server` respectively.


Also the README.md can tell you details, as well as the `./client -h` and `./secer -h`.



You can get that from:

scp -r 10.10.50.22:/srv/twamp-protocol/ ./

Or,

http://10.10.50.22/twamp-protocol/





--
Aaron







Lisa,

Richard is trying to bring up the 100Gbps NIC, and possibly help your testing using `iperf` etc.



--
Aaron

From: Lisa Pi
Sent: Tuesday, July 3, 2018 11:09:19 AM
To: Tom Jia; Zoneson Chen; Iris Rong; Tim Yi; Leon Li
Cc: Lisa Pi; TACinternal
Subject: Re: Re: <Tom Jia help>FW: [Ticket#2018060765000107] TX discard issue

Hi, Tom and Zoneson

1)  About this issue, I tried to reproduce last week. Our conclusion is that when the ingress has 10Gbps of traffic, it will appear the hash asymmetric possibility cause packets discard.
2)  According to customer the trafic is 500mbps average, maybe it has some burst trafics at a certain moment, it will cause Tx discard.
By default on 7712, the "egress-shared-queue-ratio" is 33%, we can ask customer to reset the value to maximum value.
If Tx discard is improved, it may be temporarily solved the issue on their env.

(1) By default, show the buffer seting:
admin@OVS$ovs-vsctl show-egress-shared-queue-ratio
Egress shared queue state:
queue uc enable mc enable shared ratio (uc) shared ratio (mc)
----------------------------------------------------------------------
0 true true 33% 33%
1 true true 33% 33%
2 true true 33% 33%
3 true true 33% 33%
4 true true 33% 33%
5 true true 33% 33%
6 true true 33% 33%
7 true true 33% 33%
admin@OVS$
admin@OVS$version
Copyright (C) 2009-2018 Pica8, Inc.
===================================
Hardware Model : as7712_32x
Linux System Version/Revision : 2.11.1.npb.5/3dd2216
Linux System Released Date : 06/15/2018
L2/L3 Version/Revision : 2.11.1.npb.5/3dd2216
L2/L3 Released Date : 06/15/2018
OVS/OF Version/Revision : 2.11.1.npb.5/3dd2216
OVS/OF Released Date : 06/15/2018


(2) Reset all qeue's the buffer command:
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 0 100
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 1 100
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 2 100
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 3 100
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 4 100
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 5 100
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 6 100
admin@OVS$ovs-vsctl set-egress-shared-queue-ratio 7 100
admin@OVS$ovs-vsctl show-egress-shared-queue-ratio
Egress shared queue state:
queue uc enable mc enable shared ratio (uc) shared ratio (mc)
----------------------------------------------------------------------
0 true true 100% 100%
1 true true 100% 100%
2 true true 100% 100%
3 true true 100% 100%
4 true true 100% 100%
5 true true 100% 100%
6 true true 100% 100%
7 true true 100% 100%
admin@OVS$


The form is buffer testing on OVS mode according to qa:




Thanks

Lisa.Pi@pica8.com

From: Tom Jia
Date: 2018-07-03 10:19
To: Zoneson Chen; Lisa Pi; Iris Rong; Tim Yi; Leon Li
CC: TACinternal
Subject: Re: <Tom Jia help>FW: [Ticket#2018060765000107] TX discard issue
Understandable.
Hi Lisa, could you please reproduce it?

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen
Sent: Tuesday, July 3, 2018 10:15:01 AM
To: Tom Jia
Cc: TACinternal
Subject: <Tom Jia help>FW: [Ticket#2018060765000107] TX discard issue

Hi Tom,

Would you mind helping identify this problem? It sounds like that is a common breakout issue not specific to NPB.

Palo Alto Lab could not generate the burst case. Here is the report from Greg:

40G in --> 40G out  OK
40G in --> 4x25G out OK
40G in --> 4x10G  Issue

In his case, the 10G ports will discard the packets when 2 x 40G in and 8 x 10G out.

Thanks,

Zoneson
From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Monday, July 2, 2018 at 7:03 PM
To: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Greg,

Thank you for this information! I do not know the overhead on hashing. You could be right that it is due to burst. I will ask engineering team to take a look.

Thanks,

Zoneson

From: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Date: Monday, July 2, 2018 at 6:54 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Hi Zoneson,

One additional detail that may help, mistakenly I had set the 4x10G port to 4x25G and did not see the TX discards.
40G in --> 40G out  OK
40G in --> 4x25G out OK
40G in --> 4x10G  Issue

Do you know how much overhead is required to hash on sip, dip, src port & dst_port? maybe even though the traffic is 500mbps average, their are bursts?

Thanks,
   Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.




On Mon, Jul 2, 2018 at 3:16 PM, Greg Zemlin <greg.zemlin@garlandtechnology.com> wrote:
Hi Zoneson,

Please see the attached file for the tests on this issue. The setup was simplified and I have attached the config file used on the last test.  basically 2X 40G ingress port going to 2 separate 4X10G breakout ports.  If the ports are in breakout mode they always show TX Discards.  If the 40G ingress is going to a 40G egress(non-breakout) Not TX discards are shown.  Please feel free to give me a call and we can discuss this in more detail (970)310-8023.  The total ingress traffic is roughly 520Mbps, half on each of the two ingress ports.

Thanks,
   Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.




On Mon, Jul 2, 2018 at 8:35 AM, Greg Zemlin <greg.zemlin@garlandtechnology.com> wrote:
Hi Zoneson,

Just wanted to follow up with you, the testing was delayed until today.  I will provide the outputs and test results this evening.

Thanks,
    Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.




On Thu, Jun 28, 2018 at 7:59 AM, Greg Zemlin <greg.zemlin@garlandtechnology.com> wrote:
Hi Zoneson,
Thanks for the information, we will perform this tomorrow.
Thanks,
   Greg

On Wed, Jun 27, 2018 at 7:03 PM Zoneson Chen <zoneson.chen@pica8.com> wrote:
Hi Greg,

Sharad informs me that you will go to customer site tomorrow. Would you mind asking this customer performs the following steps?

1.	Clear the counters:
a.	$ ovs-appctl bridge/clear-counts br0
2.	Start the test which will generate the packets discarded.
3.	Forward us the outputs of the following command:
a.	$ ovs-ofctl dump-ports br0
4.	If it is possible, we would like to ask this customer performing the same test by removing the cables from the breakout ports:
a.	5.1, 5.2, 5.3, 5.4, 6.1, 6.2, 6.3, and 6.4
b.	Set the above ports to ON in UP Mode of Port Settings page.
c.	Clear the port statistics.
d.	Start the same test and see whether there still exist packets dropped.
e.	If yes, provide us the outputs of “ovs-ofctl dump-ports br0” too.

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Wednesday, June 20, 2018 at 2:01 PM

To: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Greg,

I can reproduce the discard only if I redirect the breakout traffic back to the ingress port 1 and port 2. Then, it will cause the egress exceeds the bandwidth of the breakout ports (10G). But it is different from what your customer claims.

Thanks,

Zoneson

From: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Date: Wednesday, June 20, 2018 at 10:14 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Hi Zoneson,

This is what I though initially as well, but they claim they are only sending the traffic at 500Mbps.  Any other thoughts on how to resolve this?

Thanks,
   Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.




On Wed, Jun 20, 2018 at 9:49 AM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Hi Greg,

I can use tcpreplay to generate the traffic hundred times based on the PCAP files to the switch, but I still could not reproduce it. I am pretty confident that the discard counts are not caused by configuration and data. I suspect that it might be caused by overload to the 10G ports.

Thanks,

Zoneson

From: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Date: Wednesday, June 20, 2018 at 9:02 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Hi Zoneson,

Just checking in to see if you have been able to replicate this yet?

Thanks,
     Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.




On Tue, Jun 19, 2018 at 6:55 AM, Greg Zemlin <greg.zemlin@garlandtechnology.com> wrote:
Hi Zoneson,

Thanks,  yes traffic is only sent in Ports 1 and 2.  please let me know what your findings are.

Thanks,
    Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.




On Mon, Jun 18, 2018 at 7:04 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Hi Greg,

I just realize that these two PCAP files are used to generate the packets to ports xe-1/1/1.1 and xe-1/1/2.1. I will redo the tests.

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Monday, June 18, 2018 at 6:51 PM

To: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Hi Greg,

I am sorry to inform you that I could not reproduce it in 2.11.1.npb.5/698db9b and 2.11.1.npb.5/3dd2216 (which is most current released version with high CPU utilization fixes). I will ask engineering team to help.

I took a look of the PCAP files. Are they traffic captured at the end of the breakout ports (port 0 and 1). I could not figure out what are packets dropped from them.

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Monday, June 18, 2018 at 9:58 AM
To: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Greg,

Thank you for the configuration and pcap files! We will try to reproduce and let you know what we find.

Thanks,

Zoneson

From: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Date: Monday, June 18, 2018 at 9:53 AM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Hi Zoneson,

Please see the attached PCAP file.

Thanks,
   Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.




On Mon, Jun 18, 2018 at 7:21 AM, Greg Zemlin <greg.zemlin@garlandtechnology.com> wrote:
Hi Zoneson,
Attached is the configuration file from our customer, I have also requested information on the traffic they are sending.  Do you have any updates from your side?

Thanks,
   Greg



  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to CiscoLIVE Orlando? Visit our booth for live demos and contact us to set up a meeting at the show.




On Tue, Jun 12, 2018 at 9:22 AM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Hi Greg,

I am sorry to inform you that we are still unable to reproduce this TX Discard problem. Engineering team would like to know:

1.	Are EPG1 (5.1, 5.2, 5.3, 5.4) and EPG2 (6.1, 6.2, 6.3, 6.4) breakout to 4 x 10G?
2.	Are the following configurations correct?
VPG1 - 2 & 3
VPG2 - 1 & 4
loopback:  3 & 4

Is it possible to provide us the configuration file? It might be easier to reproduce the problem since the way we configure could be different from the real case.

Thanks,

Zoneson

From: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Date: Friday, June 8, 2018 at 10:08 PM

To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

This issue is 7712

On Fri, Jun 8, 2018 at 10:06 PM Zoneson Chen <zoneson.chen@pica8.com> wrote:
Greg,

I assume that the hardware is as7712, isn’t it?

Thanks,

Zoneson

From: Greg Zemlin <greg.zemlin@garlandtechnology.com>
Date: Friday, June 8, 2018 at 9:50 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>

Subject: Re: [Ticket#2018060765000107] TX discard issue

Hi Zoneson,

These are two separate instances, the previous config is for the gui crash issue. this system is at a customer site but the configuration is:

VPG1 - 2 & 3
VPG2 - 1 & 4
EPG1 - 5.1, 5.2, 5.3, 5.4
EPG2 - 6.1, 6.2, 6.3, 6.4
loopback:  3 & 4
Mapping:
sequence 1 Ingress 1  egress VPG1  Filter default action default
sequence 2 Ingress 2  egress VPG2  Filter default action default
sequence 3 Ingress 3  egress EPG1  Filter default action default
sequence 4 Ingress 4  egress EPG1  Filter default action default

Ports 1,2,3,4 are forced to 40G

Thanks,
    Greg






Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com










Going to CiscoLIVE Orlando? Visit our booth for live demos and contact us to set up a meeting at the show.




On Fri, Jun 8, 2018 at 9:39 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Hi Greg,

We could not figure out where may go wrong yet. Would you mind forwarding us the configuration file to reproduce it?

The previous configuration file you sent us does not have the loopback configuration.

Thanks,

Zoneson

From: PICA8 Support <otrs.support@pica8.com>
Organization: PICA8
Date: Friday, June 8, 2018 at 1:07 AM
To: "greg.zemlin@garlandtechnology.com" <greg.zemlin@garlandtechnology.com>
Cc: "support@pica8.com" <support@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Nirmal Karia <Nirmal.Karia@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Subject: Re: [Ticket#2018060765000107] TX discard issue

Hi Greg ,

Thank you for contacting Pica8 support.
We will analyze the information that you have provided, and we will get back to you soon as possible.
.
Best regards,

PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (650) 614 5838
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

06/07/2018 23:16 - Greg Zemlin wrote:
Hi Support,

We have a 32x100G system onsite with a customer and we are seeing considerable TX Discards, please see the attached counter log.

The ingress traffic is coming from a loopback port on the system end the egress is  a 4x10G Breakout.  We are running <1Gbps of traffic so it is not an issue with over-subscription.  Can you please advise on what could be causing this.

Thanks,
   Greg


Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com

Going to CiscoLIVE Orlando? Visit our booth for live demos and contact us to set up a meeting at the show.

--

  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com



Going to CiscoLIVE Orlando? Visit our booth for live demos and contact us to set up a meeting at the show.









--

  		Greg Zemlin
Product Manager, Garland Technology
(716) 242-8500 | (970) 310-8023
greg.zemlin@garlandtechnology.com

GarlandTechnology.com


Going to RSA Singapore? Visit our booth to talk with our TAP IT team and contact us to set up a meeting at the show.












More explanations.


TLS support was done through package libgnutls in PICOS.

Package `openssl` is needed for some of higher security algorithm strength mentioned in Q 4.

It is suggested to add the package into ROOTFS from now on.



Usually 2048 bits can be supported.

3072 bits is OK, based on the following output.

admin@Xorplus:~$ ssh-keygen -b 3072
Generating public/private rsa key pair.
Enter file in which to save the key (/home/admin/.ssh/id_rsa):
Created directory '/home/admin/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /home/admin/.ssh/id_rsa.
Your public key has been saved in /home/admin/.ssh/id_rsa.pub.
The key fingerprint is:
31:fe:c8:72:20:93:ea:be:cc:92:66:bd:12:91:32:14 admin@Xorplus
The key's randomart image is:
+--[ RSA 3072]----+
| E.              |
| .               |
|. .     o        |
|oo   . . o       |
|... + . S        |
| . . o o o       |
| .+   . + .      |
|oB .   o         |
|ooBo.            |
+-----------------+

admin@Xorplus:~$ version
Copyright (C) 2009-2018 Pica8, Inc.
===================================
Hardware Model                : HPE AL 6921-54T
Linux System Version/Revision : 2.11.7-AS7726/ef61694
Linux System Released Date    : 06/29/2018
L2/L3 Version/Revision        : 2.11.7-AS7726/ef61694
L2/L3 Released Date           : 06/29/2018
OVS/OF Version/Revision       : 2.11.7-AS7726/ef61694
OVS/OF Released Date          : 06/29/2018





--
Aaron

From: Aaron Shang
Sent: Monday, July 2, 2018 3:26:57 PM
To: Mikel Tang; Lin Du; Tom Jia
Subject: Re: Questions for PicOS features

Hi, Mikel,

I am not expert on crypto or cipher topics, I am trying my best to answer these highlighted questions below.

================
Answer for Q 4.
It can support algorithm security strength up to 2048 bits generally, or higher.
- It supports Hash SHA 224/256/384/512 etc.
- It supports SEED, ARIA-128/192/256.
- It supports public key RSA 2048, and even higher.
- It supports electronic signatures such as RSA-PSS-2048/3072, and ECDSA suites.
    - For Korean K series standards, most should be supported referencing relative AES or RSA suites.
- SHA-1 is possible.

112 bits is supported.



================
Answer for Q 6.

XMPPoverTLS is specified in XMPP protocol.
Addtional XMPP implementations are needed to support that.
Recent XMPP implementations usually supports that.



================
Answer for Q 8.

TLS 1.2 (RFC5246) is supported.
TLS support is up to 1.3 in current PICOS.



--
Aaron

From: Mikel Tang
Sent: Monday, July 2, 2018 1:40:40 PM
To: Aaron Shang; Lin Du; Tom Jia
Subject: RE: Questions for PicOS features

Hi  Aaron,

Please help me to look at if the following highlights are supported.

1.    Is it possbile to adjust password minimum lengths?
2.    After authentication failure 5 times (default less than 5 times) is it support to device access limitation feature on specific times (default over 5 mins.)?
3.    When authentication failure is it possible to adjust device access limiation time by administrator?
4.    Can it fulfill up authentication and hash algorithm security strength like 112 bits level?
e.g)
- Hash (SHA-224/256/384/512 Etc.)
- Symmetric-key algorithm (SEED,ARIA-128/192/256 Etc.)
- Publickey password (RSA2048 Etc.)
- Electronic signature (RSA-PSS-2048/3072,ECDSA/EC-KCDSA(B-233,B-283,K-233,K-283,P-224,P-256), KCDSA-(2048,224)/(2048,256) Etc.)
* SHA-1 is possible ?

5.    Is it support for over IEEE Std 802.1X-2010?
6.    Is it support for XMPP or XMPPoverTLS?
7.    Is it support connection session count limitation or only one account permit function for concurrent connection session when connecting remote access?
8.    Can it available for over TLS 1.2 (RFC 5246) if it support TLS protocol ?
9.    Is it support audit logging feature by itself without RADIUS server?

Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: Kim, Jee Hoon (Pointnext CSC Korea) <jeehoon.kim@hpe.com>
Sent: Monday, July 2, 2018 11:36 AM
To: Don DeRisi <don.derisi@pica8.com>; support@pica8.com
Cc: Kim, Tae Hong <th.kim@hpe.com>
Subject: RE: Questions for PicOS features

Hi, Don
Many thanks !

Best Regards,

Jee-Hoon Kim
HPEN/Aruba Technical Support Specialist/Chajang
APJ
HPE Pointnext

jeehoon.kim@hpe.com
+82 1588 0142  Office

Seoul, Republic Of Korea
hpe.com/pointnext


From: Don DeRisi [mailto:don.derisi@pica8.com]
Sent: Monday, July 02, 2018 11:51 AM
To: Kim, Jee Hoon (Pointnext CSC Korea) <jeehoon.kim@hpe.com>; support@pica8.com
Cc: Kim, Tae Hong <th.kim@hpe.com>
Subject: Re: Questions for PicOS features

Hello Jee Hoon,

Thanks for the contact on these questions.

l'll engage support team right away to answer as possible or to ask for clarification needed.

Standby for updates.

Don


From: Kim, Jee Hoon (Pointnext CSC Korea) <jeehoon.kim@hpe.com>
Sent: Sunday, July 1, 2018 8:50 PM
To: Don DeRisi
Cc: Kim, Tae Hong
Subject: Questions for PicOS features

Dear Don

I have a few of questions for PicOS features. (We’re checking the features on the HPE Altoline switches (6900,6921,6941 models.)
Could you let me know the answers for these below questions please?

1.    Is it possbile to adjust password minimum lengths?
2.    After authentication failure 5 times (default less than 5 times) is it support to device access limitation feature on specific times (default over 5 mins.)?
3.    When authentication failure is it possible to adjust device access limiation time by administrator?
4.    Can it fulfill up authentication and hash algorithm security strength like 112 bits level?
e.g)
- Hash (SHA-224/256/384/512 Etc.)
- Symmetric-key algorithm (SEED,ARIA-128/192/256 Etc.)
- Publickey password (RSA2048 Etc.)
- Electronic signature (RSA-PSS-2048/3072,ECDSA/EC-KCDSA(B-233,B-283,K-233,K-283,P-224,P-256), KCDSA-(2048,224)/(2048,256) Etc.)
* SHA-1 is possible ?

5.    Is it support for over IEEE Std 802.1X-2010?
6.    Is it support for XMPP or XMPPoverTLS?
7.    Is it support connection session count limitation or only one account permit function for concurrent connection session when connecting remote access?
8.    Can it available for over TLS 1.2 (RFC 5246) if it support TLS protocol ?
9.    Is it support audit logging feature by itself without RADIUS server?


Best Regards,

Jee-Hoon Kim
HPEN/Aruba Technical Support Specialist/Chajang
APJ
HPE Pointnext

jeehoon.kim@hpe.com
+82 1588 0142  Office

Seoul, Republic Of Korea
hpe.com/pointnext










Hi, Mikel,

I am not expert on crypto or cipher topics, I am trying my best to answer these highlighted questions below.

================
Answer for Q 4.
It can support algorithm security strength up to 2048 bits generally, or higher.
- It supports Hash SHA 224/256/384/512 etc.
- It supports SEED, ARIA-128/192/256.
- It supports public key RSA 2048, and even higher.
- It supports electronic signatures such as RSA-PSS-2048/3072, and ECDSA suites.
    - For Korean K series standards, most should be supported referencing relative AES or RSA suites.
- SHA-1 is possible.

112 bits is supported.



================
Answer for Q 6.

XMPPoverTLS is specified in XMPP protocol.
Addtional XMPP implementations are needed to support that.
Recent XMPP implementations usually supports that.



================
Answer for Q 8.

TLS 1.2 (RFC5246) is supported.
TLS support is up to 1.3 in current PICOS.



--
Aaron

From: Mikel Tang
Sent: Monday, July 2, 2018 1:40:40 PM
To: Aaron Shang; Lin Du; Tom Jia
Subject: RE: Questions for PicOS features

Hi  Aaron,

Please help me to look at if the following highlights are supported.

1.    Is it possbile to adjust password minimum lengths?
2.    After authentication failure 5 times (default less than 5 times) is it support to device access limitation feature on specific times (default over 5 mins.)?
3.    When authentication failure is it possible to adjust device access limiation time by administrator?
4.    Can it fulfill up authentication and hash algorithm security strength like 112 bits level?
e.g)
- Hash (SHA-224/256/384/512 Etc.)
- Symmetric-key algorithm (SEED,ARIA-128/192/256 Etc.)
- Publickey password (RSA2048 Etc.)
- Electronic signature (RSA-PSS-2048/3072,ECDSA/EC-KCDSA(B-233,B-283,K-233,K-283,P-224,P-256), KCDSA-(2048,224)/(2048,256) Etc.)
* SHA-1 is possible ?

5.    Is it support for over IEEE Std 802.1X-2010?
6.    Is it support for XMPP or XMPPoverTLS?
7.    Is it support connection session count limitation or only one account permit function for concurrent connection session when connecting remote access?
8.    Can it available for over TLS 1.2 (RFC 5246) if it support TLS protocol ?
9.    Is it support audit logging feature by itself without RADIUS server?

Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: Kim, Jee Hoon (Pointnext CSC Korea) <jeehoon.kim@hpe.com>
Sent: Monday, July 2, 2018 11:36 AM
To: Don DeRisi <don.derisi@pica8.com>; support@pica8.com
Cc: Kim, Tae Hong <th.kim@hpe.com>
Subject: RE: Questions for PicOS features

Hi, Don
Many thanks !

Best Regards,

Jee-Hoon Kim
HPEN/Aruba Technical Support Specialist/Chajang
APJ
HPE Pointnext

jeehoon.kim@hpe.com
+82 1588 0142  Office

Seoul, Republic Of Korea
hpe.com/pointnext


From: Don DeRisi [mailto:don.derisi@pica8.com]
Sent: Monday, July 02, 2018 11:51 AM
To: Kim, Jee Hoon (Pointnext CSC Korea) <jeehoon.kim@hpe.com>; support@pica8.com
Cc: Kim, Tae Hong <th.kim@hpe.com>
Subject: Re: Questions for PicOS features

Hello Jee Hoon,

Thanks for the contact on these questions.

l'll engage support team right away to answer as possible or to ask for clarification needed.

Standby for updates.

Don


From: Kim, Jee Hoon (Pointnext CSC Korea) <jeehoon.kim@hpe.com>
Sent: Sunday, July 1, 2018 8:50 PM
To: Don DeRisi
Cc: Kim, Tae Hong
Subject: Questions for PicOS features

Dear Don

I have a few of questions for PicOS features. (We’re checking the features on the HPE Altoline switches (6900,6921,6941 models.)
Could you let me know the answers for these below questions please?

1.    Is it possbile to adjust password minimum lengths?
2.    After authentication failure 5 times (default less than 5 times) is it support to device access limitation feature on specific times (default over 5 mins.)?
3.    When authentication failure is it possible to adjust device access limiation time by administrator?
4.    Can it fulfill up authentication and hash algorithm security strength like 112 bits level?
e.g)
- Hash (SHA-224/256/384/512 Etc.)
- Symmetric-key algorithm (SEED,ARIA-128/192/256 Etc.)
- Publickey password (RSA2048 Etc.)
- Electronic signature (RSA-PSS-2048/3072,ECDSA/EC-KCDSA(B-233,B-283,K-233,K-283,P-224,P-256), KCDSA-(2048,224)/(2048,256) Etc.)
* SHA-1 is possible ?

5.    Is it support for over IEEE Std 802.1X-2010?
6.    Is it support for XMPP or XMPPoverTLS?
7.    Is it support connection session count limitation or only one account permit function for concurrent connection session when connecting remote access?
8.    Can it available for over TLS 1.2 (RFC 5246) if it support TLS protocol ?
9.    Is it support audit logging feature by itself without RADIUS server?


Best Regards,

Jee-Hoon Kim
HPEN/Aruba Technical Support Specialist/Chajang
APJ
HPE Pointnext

jeehoon.kim@hpe.com
+82 1588 0142  Office

Seoul, Republic Of Korea
hpe.com/pointnext












https://www.rackaid.com/blog/how-to-block-ssh-brute-force-attacks/






George/Jacob,

Can you figure out simple means to read or even control the interface/register? Like what i2c-tools can do?




发件人: Lu Wei <luwei11@mail.ustc.edu.cn>
发送时间: Tuesday, April 24, 2018 2:40:53 PM
收件人: '小龙'
抄送: Aaron Shang; George Guo; Jacob Wang; support@pica8.com
主题: 答复: 回复：RE: 技术支持请求：PICA8-P5101设备 i2c-tools软件安装

Mikel Tang，您好！

先说一下我们的使用需求：我们需要在Pica8的10GB光口上插上SFP+光模块，光模块的型号是Finisar Tunable SFP+ FTLX6672MCC。这个光模块提供一个2-wired serial interface，可以用来读写其寄存器内部信息，从而对光模块的中心频率等进行配置以及对光模块的功率等信息进行读取。之前，我们想到的解决方案是，在PICA8上安装i2c-tools，通过它来识别这个2-wire serial interface，从而进行寄存器的读写操作。但是，如前面我们咨询的邮件里有提到，安装时会出现很多系统错误信息，导致无法安装成功。除了要识别这个2-wired serial interface之外，我们还希望能够在Pica8上运行我们自己定义的脚本，编程语言是C，需要Pica8有相应的编译器，因为我们在做实验的过程中发现，Pica8无法编译。

简而言之，我们的需求有两个：
1.	实现对Pica8光端口上的SFP+提供的2-wire serial interface进行访问，需要安装的软件可能是i2c-tools，但不局限这个工具，只要能实现这个功能即可。
2.	实现在Pice8上编译一些简单的C脚本，需要相应的编译器。

祝好，
卢薇


发件人: 小龙 [mailto:11277319@qq.com]
发送时间: 2018年4月24日 14:06
收件人: luwei11 <luwei11@mail.ustc.edu.cn>
抄送: Aaron Shang <aaron.shang@pica8.com>; George Guo <george.guo@pica8.com>; Jacob Wang <jacob.wang@pica8.com>; support <support@pica8.com>
主题: 回复：RE: 技术支持请求：PICA8-P5101设备 i2c-tools软件安装


卢薇，

请将需要的工具列出来，厂家工程师寻求其他途径帮你解决！



------------------ 原始邮件 ------------------
发件人: "Lin Du"<lin.du@pica8.com>;
发送时间: 2018年4月24日(星期二) 上午10:49
收件人: "Mikel Tang"<mikel.tang@pica8.com>;"小龙"<11277319@qq.com>;"support@pica8.com"<support@pica8.com>;
抄送: "Aaron Shang"<aaron.shang@pica8.com>; "George Guo"<george.guo@pica8.com>; "Jacob Wang"<jacob.wang@pica8.com>;
主题: RE: 技术支持请求：PICA8-P5101设备 i2c-tools软件安装

王先生，您好！
加上开发的技术人员，把您需要的工具列出来。我们看看有没有别的途径进行安装。
谢谢！

Lin

From: Mikel Tang
Sent: Tuesday, April 24, 2018 9:39 AM
To: 小龙; support@pica8.com
Subject: RE: 技术支持请求：PICA8-P5101设备 i2c-tools软件安装

Hi 王晓龙

由于P5101的CPU是PowerPCSpe，而 powerpcspe不再受到Debian官方源的支持，所以最新的apt source list将不起作用。
在当前新的安装”deb”使用”xz”，而Debian “wheezy”系统不支持。
PicOS需要等待后续版本更新到新的Debian才能支持，在当前没有版本支持使用最新的apt sourc 安装i2c-tools.

Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: 小龙 <11277319@qq.com>
Sent: Monday, April 23, 2018 11:36 PM
To: support@pica8.com
Subject: 技术支持请求：PICA8-P5101设备 i2c-tools软件安装


您好，

我方于2017年采购贵司P5101设备，参考设备手册，在安装i2c-tools 软件时，系统提示错误

附设备信息、系统信息及dpkg版本、i2c-tools信息、系统报信息截图

望能尽快给予回复，

并提供一位技术工程师联系方式，以便推动问题的快速解决，

谢谢

王晓龙13311270270










As for the list you summed up:
1.	The file system (flash file system, etc)    <- We used UBI on low end devices that had no flash controllers (3132, 3048). UBI FS support had been in Linux kernel, so in our system, no additional effort is needed. The action `mount` is OK due to kernel FS support. The manipulation of UBI is done in RAM disk, which had added package `mtd-utils` to included all needed ubi operations. ONIE had built-in mtd-utils, so ONIE can support all ubi operations. They are all GPL.
2.	Security packages, including SSHd, DHCPd, Telnetd, etc.  <- `telnetd` is not installed after 3.x since 3.0. We had no `dhcpd` running on the boxes. DHCP client is on boxes as most Linux distros would have, in our case, the package is `isc-dhcp-client` plus `isc-dhcp-common`. Also as most Linux distros would have, we used `openssh-server` and `openssh-client` packages to provide SSH server and client. They are of BSD and similar ISC license.
3.	TACACS  <- For this, we used package `pam_tacplus`, GPL. Also lib `libpam-radius-auth` is used for RADIUS. GPL.
4.	NAC – 802.1x    <- This is done using `packetfence`, license is GPL. packetfence itself is so huge collection of various modules. We did not integrate that with PICOS image.
5.	Netconf  <- We used `libnetconf` for lib, and some client / server code from an old project called `netopeer`. The license is BSD+GPL. They had been very difficult to maintain. Hope to replace.
6.	SNMPd  <- We used `net-snmp` package for OVS, which is a long time mixed license, basically BSD. But we included `agent++` and `snmp++` in `pica` code, for which I can not easily determine the license.


So, the special list to mention at the time being is:

- mtd-utils               GPL
- libpam-radius-auth      GPL; with pica8 changes for AAA support.
- pam_tacplus             GPL; with pica8 changes for AAA support.
- openssh                 BSD+ISC; with pica8 changes for AAA support.
- shadow                  BSD like; with pica8 changes only for serial console login during AAA.
- isc-dhcp                ISC
- packetfence             GPL; with pica8 added modules to support PICOS boxes, pushed upstream for review, and they accepted to integrate into their next major releases.
- netconf/libnetconf      BSD+GPL; with pica8 deep changes.
- net-snmp                BSD+GPL
- agent++/snmp++          License not determined; with pica8 changes.


I will sum up as complete as possible a list later.

But most of the modules are from Debian releases without our changes, listing of them is of no significant meaning.

Here is the list in form of deb packages in current 3.1.0 ROOTFS.

acl
adduser
apt
apt-transport-https
apt-utils
base-files
base-passwd
bash
bsdmainutils
bsdutils
ca-certificates
coreutils
cpio
cron
curl
dash
debconf
debian-archive-keyring
debianutils
diffutils
dmidecode
dmsetup
dpkg
e2fslibs:amd64
e2fsprogs
ethtool
file
findutils
gcc-4.9-base:amd64
gdisk
gnupg
gpgv
grep
groff-base
gzip
hostname
i2c-tools
ifupdown
init
init-system-helpers
initscripts
insserv
iproute2
iptables
iputils-ping
isc-dhcp-client
isc-dhcp-common
kmod
krb5-locales
less
libacl1:amd64
libalgorithm-c3-perl
libapt-inst1.5:amd64
libapt-pkg4.12:amd64
libarchive-extract-perl
libatomic1:amd64
libattr1:amd64
libaudit-common
libaudit1:amd64
libblkid1:amd64
libboost-iostreams1.55.0:amd64
libbsd0:amd64
libbz2-1.0:amd64
libc-bin
libc6:amd64
libcap2:amd64
libcap2-bin
libcgi-fast-perl
libcgi-pm-perl
libclass-c3-perl
libclass-c3-xs-perl
libcomerr2:amd64
libcpan-meta-perl
libcryptsetup4:amd64
libcurl3:amd64
libcurl3-gnutls:amd64
libdaemon0:amd64
libdata-optlist-perl
libdata-section-perl
libdb5.3:amd64
libdebconfclient0:amd64
libdevmapper1.02.1:amd64
libdns-export100
libedit2:amd64
libestr0
libexpat1:amd64
libfam0
libfcgi-perl
libffi6:amd64
libgcc1:amd64
libgcrypt20:amd64
libgdbm3:amd64
libgmp10:amd64
libgnutls-deb0-28:amd64
libgnutls-openssl27:amd64
libgpg-error0:amd64
libgssapi-krb5-2:amd64
libhogweed2:amd64
libicu52:amd64
libidn11:amd64
libirs-export91
libisc-export95
libisccfg-export90
libjson-c2:amd64
libk5crypto3:amd64
libkeyutils1:amd64
libkmod2:amd64
libkrb5-3:amd64
libkrb5support0:amd64
libldap-2.4-2:amd64
liblocale-gettext-perl
liblockfile-bin
liblockfile1:amd64
liblog-message-perl
liblog-message-simple-perl
liblogging-stdlog0:amd64
liblognorm1:amd64
liblzma5:amd64
libmagic1:amd64
libmnl0:amd64
libmodule-build-perl
libmodule-pluggable-perl
libmodule-signature-perl
libmount1:amd64
libmro-compat-perl
libncurses5:amd64
libncursesw5:amd64
libnetfilter-acct1:amd64
libnettle4:amd64
libnewt0.52:amd64
libnfnetlink0:amd64
libopts25:amd64
libp11-kit0:amd64
libpackage-constants-perl
libpam-modules:amd64
libpam-modules-bin
libpam-radius-auth
libpam-runtime
libpam-tacplus
libpam0g:amd64
libparams-util-perl
libparted2:amd64
libpcap0.8:amd64
libpci3:amd64
libpcre3:amd64
libpipeline1:amd64
libpod-latex-perl
libpod-readme-perl
libpopt0:amd64
libprocps3:amd64
libpsl0:amd64
libpython-stdlib:amd64
libpython2.7-minimal:amd64
libpython2.7-stdlib:amd64
libreadline6:amd64
libregexp-common-perl
librtmp1:amd64
libsasl2-2:amd64
libsasl2-modules:amd64
libsasl2-modules-db:amd64
libselinux1:amd64
libsemanage-common
libsemanage1:amd64
libsepol1:amd64
libsigc++-2.0-0c2a:amd64
libslang2:amd64
libsmartcols1:amd64
libsoftware-license-perl
libsqlite3-0:amd64
libss2:amd64
libssh2-1:amd64
libssl1.0.0:amd64
libstdc++6:amd64
libsub-exporter-perl
libsub-install-perl
libsystemd0:amd64
libtasn1-6:amd64
libterm-readkey-perl
libterm-readline-perl-perl
libterm-ui-perl
libtext-charwidth-perl
libtext-iconv-perl
libtext-soundex-perl
libtext-template-perl
libtext-wrapi18n-perl
libtinfo5:amd64
libudev1:amd64
libusb-0.1-4:amd64
libustr-1.0-1:amd64
libuuid1:amd64
libwrap0:amd64
libx86-1:amd64
libxau6:amd64
libxcb1:amd64
libxdmcp6:amd64
libxml2:amd64
libxslt1.1:amd64
libxtables10
lighttpd
lockfile-progs
login
logrotate
lsb-base
man-db
manpages
mawk
mime-support
mount
multiarch-support
nano
ncurses-base
ncurses-bin
ncurses-term
net-tools
netbase
netcat-traditional
nfacct
ntp
ntpdate
openssh-client
openssh-server
openssh-sftp-server
openssl
parted
passwd
pciutils
perl
perl-base
perl-modules
procps
python
python-minimal
python-pam
python2.7
python2.7-minimal
radvd
read-edid
readline-common
rsyslog
sed
sensible-utils
sgml-base
spawn-fcgi
startpar
sudo
systemd
systemd-sysv
sysv-rc
sysvinit-utils
tar
tcpdump
traceroute
tzdata
udev
util-linux
vim-common
vim-tiny
wget
whiptail
xml-core
zlib1g:amd64






--
Aaron


From: James Liao
Sent: Tuesday, January 8, 2019 07:10
To: Aaron Shang
Cc: Lin Du; Yachal Chen
Subject: Open source modules we have leveraged?

Aaron,

Do you have a list of 3rd party (or open source) modules that we have leveraged in PICOS?

As far as I remember, we used at least the following.
1.	The file system (flash file system, etc)
2.	Security packages, including SSHd, DHCPd, Telnetd, etc.
3.	TACACS
4.	NAC – 802.1x
5.	Netconf
6.	SNMPd

Thanks,
James







    git fetch -a -p                 # Fetch latest remote changes

    git pull --rebase --recurse-submodules
                                    # Sync repo, and all submodules







There had been a strong trend on monitoring using modern means such as prometheus.

This might be a good point to differentiate, and solution team had been doing some means of dashboard type of work that can be integrated with this.

Prometheus is a powerful time-series monitoring service, providing a flexible
platform for monitoring.

Prometheus works by periodically connecting to data sources and collecting their
performance metrics via the various exporters. To view and work with the monitoring data, you can either
connect directly to Prometheus or utilize a dashboard tool like Grafana.

https://prometheus.io/





A `delay` patch from azure sonic may help.


https://github.com/Azure/sonic-linux-kernel/blob/9ce82be612023bf73093b231e98c69c7c4bb1ea0/patch/driver-i2c-bus-intel-ismt-add-delay-param.patch


--
Aaron

From: Aaron Shang
Sent: Friday, December 7, 2018 1:30:14 PM
To: Tom Jia; Jacob Wang; Richard Zhang; George Guo
Subject: Re: 请帮忙检查Luxartech 版本打印Linux kernel error信息

Seems a driver issue, perhaps from fan i2c smbus.
See:

    i2c i2c-1: new_device: Instantiated device 24c02 at 0x57
    i2c i2c-2: Failed to register i2c client as7712_32x_fan at 0x66 (-16)
@George Guo

Please have a look.


--
Aaron

From: Tom Jia
Sent: Friday, December 7, 2018 1:23:09 PM
To: Jacob Wang; Aaron Shang; Richard Zhang
Subject: Fw: 请帮忙检查Luxartech 版本打印Linux kernel error信息




Best regards,
Tom Jia (贾彦民)



From: Mikel Tang
Sent: Friday, December 7, 2018 11:33 AM
To: Tom Jia; George Guo
Cc: William Long; Lin Du
Subject: 请帮忙检查Luxartech 版本打印Linux kernel error信息

Hi Tom & George,

在7712交换机上，自动打印如下错误信息，请帮忙分析原因
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out
ismt_smbus 0000:00:13.0: completion wait timed out



Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com











1) 可以保证；保证是由git clean做到的。

2) 可以不rm，类比不必重新安装一台新环境。

3) git clean可以保证。


--
Aaron

From: Lisa Pi
Sent: Sunday, November 25, 2018 5:42:02 PM
To: Aaron Shang
Cc: Lisa Pi; Daisy Zhao; George Guo; Iris Rong; Lin Du; Tim Yi; Tom Jia; Tong Zhang; Yachal Chen
Subject: Re: Build changes in 3.1.0

Hi, aaron

还有结果问题需要明确下：
1) 你给出的步骤是没有clone过仓库更没有编译的情况，若是我这边的脚本编译每次从clone开始是比较耗时的，
按照你给的步骤编译过一次之后，能否下次不重新clone仓库，而且像之前的方式，每次编译前，step1: 进入到指定目录  step2: git clean  step3:  git pull  step4: 进入docker编译环境   step5: ./build.sh  xx；这样的步骤能否确保编译的image是一个干净完整的

2) ./run.sh启动的docker编译环境：目前服务器上有删除的机制吗，比如一段时间之后会删除掉？我看现在16的服务器上有几个月之前。
   若是没有清除机制，我这边自动编译的脚本可能还需要考虑每次启动一个docker环境之后最后stop掉然rm掉

3）若是仅有一个仓库编译所有平台，前一个和后一个的编译，只是需要git clean就可以保证彼此不受影响吗？还是需要其他的操作，来确保一个仓库编译所有平台比如不受干扰




Thanks

Lisa.Pi@pica8.com

From: Aaron Shang
Date: 2018-11-23 22:01
To: Lisa Pi
CC: Aaron Shang; Daisy Zhao; George Guo; Iris Rong; Lin Du; Lisa Pi; Tim Yi; Tom Jia; Tong Zhang; Yachal Chen
Subject: Build changes in 3.1.0


    git clone --recursive git@code/pica8 mybuild3
    cd mybuild3
    git checkout 3.1.0
    git submodule update --init
    cd linux
    git checkout linux-4.14.y
    cd ..
    ./run.sh  # Enter Docker
    ./build.sh s4048 # Run this in Docker, the second parameter is BOX name as listed in `/os-dev/`




--
Aaron








 Hi, Hai,

I am not expert on crypto, just make some efforts to be of some help.
After one day of reading fips and ssh docs, wikipedia, rfcs and cryptography basics, I gained a bit of knowledge not to mess about hash and cipher modes, key strength and length.
I tried my best to fill in the empty cells.
Hope that would be no major mistakes.



Cryptology Services	Authentication algorithms	Key lengths
cipher-auth	AES	128,192,256
cipher-auth	chacha20-poly1305	256
cipher	3des-cbc	128,256
cipher	blowfish-cbc	128,256
cipher	cast128-cbc	128,256
cipher	arcfour	128,256
cipher	aes-cbc	128,192,256
cipher	rijndael-cbc@lysator.liu.se	128,256
cipher	aes-ctr	128,192,256
cipher	aes128-gcm@openssh.com	128
cipher	aes256-gcm@openssh.com	256
Key Exchange	curve25519-sha256@libssh.org	256
Key Exchange	ecdh-sha2-nistp256	256
Key Exchange	ecdh-sha2-nistp384	384
Key Exchange	ecdh-sha2-nistp521	521
Key Exchange	diffie-hellman-group-exchange-sha256	256
Key Exchange	diffie-hellman-group-exchange-sha1	variable
Key Exchange	diffie-hellman-group14-sha1	2048
key	ssh-ed25519	256
key	ssh-ed25519-cert-v01@openssh.com	128,256
key	ssh-rsa	1024,2048
key	ssh-dss	1024
key	ecdsa-sha2-nistp256	256
key	ecdsa-sha2-nistp384	384
key	ecdsa-sha2-nistp521	521
key	ssh-rsa-cert-v01@openssh.com	128,256
key	ssh-dss-cert-v01@openssh.com	128,256
key	ecdsa-sha2-nistp256-cert-v01@openssh.com	256
key	ecdsa-sha2-nistp384-cert-v01@openssh.com	384
key	ecdsa-sha2-nistp521-cert-v01@openssh.com	521
key-plain	ssh-ed25519	256
key-plain	ssh-rsa	1024,2048
key-plain	ssh-dss	1024
key-plain	ecdsa-sha2-nistp256	256
key-plain	ecdsa-sha2-nistp384	384
key-plain	ecdsa-sha2-nistp521	521
key-cert	ssh-ed25519-cert-v01@openssh.com	256
key-cert	ssh-rsa-cert-v01@openssh.com	1024,2048
key-cert	ssh-dss-cert-v01@openssh.com	1024
key-cert	ecdsa-sha2-nistp256-cert-v01@openssh.com	256
key-cert	ecdsa-sha2-nistp384-cert-v01@openssh.com	384
key-cert	ecdsa-sha2-nistp521-cert-v01@openssh.com	521
mac	hmac-sha1	160
mac	hmac-sha1-96	96
mac	hmac-sha2-256	256
mac	hmac-sha2-512	512
mac	hmac-md5	128
mac	hmac-md5-96	96
mac	hmac-ripemd160	160
mac	hmac-ripemd160@openssh.com	160
mac	umac-64@openssh.com	64
mac	umac-128@openssh.com	128
mac	hmac-sha1-etm@openssh.com	160
mac	hmac-sha1-96-etm@openssh.com	96
mac	hmac-sha2-256-etm@openssh.com	256
mac	hmac-sha2-512-etm@openssh.com	512
mac	hmac-md5-etm@openssh.com	128
mac	hmac-md5-96-etm@openssh.com	96
mac	hmac-ripemd160-etm@openssh.com	160
mac	umac-64-etm@openssh.com	64
mac	umac-128-etm@openssh.com	128


--
Aaron

From: Hai Vo-Dinh
Sent: Saturday, November 3, 2018 12:49:07 PM
To: Aaron Shang
Cc: Tom Jia
Subject: Re: Key length information

These are the ones:

Authentication algorithms	Key lengths







ssh-ed25519-cert-v01@openssh.com

ssh-rsa-cert-v01@openssh.com

ssh-dss-cert-v01@openssh.com

ssh-ed25519

ssh-rsa

ssh-dss

ssh-ed25519-cert-v01@openssh.com

ssh-rsa-cert-v01@openssh.com

ssh-dss-cert-v01@openssh.com

hmac-sha1
hmac-md5
hmac-sha1-etm@openssh.com

hmac-md5-etm@openssh.com


Thanks,
Hai

From: Hai Vo-Dinh <hai.vodinh@pica8.com>
Date: Friday, November 2, 2018 at 9:47 PM
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Tom Jia <tom.jia@pica8.com>
Subject: Key length information

Hi Aaron,

I really need your help filling out an import encryption form for Lenovo.  The key length column (col J) have some rows that are blank because I have trouble finding the information.  Would you please help fill those out, and also review the information that I have filled out in that column.

Thanks a lot,
Hai


--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
O: (833) 888-7422 x203
M: (408) 389-9422
hai.vodinh@pica8.com









I agree with these 3 change requests, which SHOULD be there for security concern.


Let's first meet Samsung urgent requirement for their variant builds.

Then we enable them in `master` and future releases.


I created tasks to track the changes below.

    http://code/pica8/picos/issues/138

    http://code/pica8/picos/issues/139


For the permission of /etc and log files, we can change that.


For the password encryption changed to SHA512, we need two changes.

First is to change `/etc/login.defs` to enable SHA512:

    ENCRYPT_METHOD SHA512

The second change is in `/etc/pam.d/common-password` to include sha512 in line of pam_unix module.

    # The "sha512" option enables salted SHA512 passwords.  Without this option,
    password    required      pam_unix.so sha512

To verify, add a new user and check the /etc/shadow file.

If the MD5 is used for crypt, the first field after user name is $1.

    tester1:$1$SMzOkj1v$G3Mh9eE1MvTO7LbHOk53u1:17835:0:99999:7:::


$6 means SHA512 is used for crypt

    tester2:$6$9mR1dryO$nPSxynk.KhYpZAg.DfV9MdBZ9O1TrNF0FdKhfmLonTRwcAa3LQCPw8SoG4OWoGNFGLm4V7MojEuX.QVMtuanM.:17835:0:99999:7:::


--
Aaron

From: Tom Jia
Sent: Wednesday, October 31, 2018 9:22:07 AM
To: James Liao; Elijah Ai; Aaron Shang; Hai Vo-Dinh; plm@pica8.com
Cc: Lin Du
Subject: Re: System Log file ownership and Encryption -- TMAX CC Certification

Hi Aaron, could you please help follow up?
Thanks.

Best regards,
Tom Jia (贾彦民)


From: James Liao
Sent: Tuesday, October 30, 2018 10:54:00 PM
To: Elijah Ai; Tom Jia
Cc: support@pica8.com
Subject: Re: System Log file ownership and Encryption -- TMAX CC Certification

Tom, Elijah,

These need to be documented and reviewed by the PLM. For example, the password encryption might have backward compatibility issue. It is okay to suggest, but let PLM decide.

James

From: Elijah Ai <elijah.ai@pica8.com>
Date: Monday, October 29, 2018 at 11:50 PM
To: Tom Jia <tom.jia@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: RE: System Log file ownership and Encryption -- TMAX CC Certification

Hi Tom,

According to our Korean clients, there are some requests that should be included in the new version of PicOS(AS4610):
1. The default password encryption is SHA512 instead of MD5,
2. System file under /etc should have the same ownership as those in normal Ubuntu linux("664" to "600").
3. The system log file should also be the same ownership as those in normal Ubuntu linux("775" to "640").
Please refer to bug 9971 and 9973.

Best regards,
Elijah


elijah.ai@pica8.com



From: kgi@in4a.co.kr
Date: 2018-10-29 21:25
To: 'Elijah Ai'; support@pica8.com
CC: 'Henry Pan'; plm@pica8.com
Subject: RE: RE: System Log file ownership and Encryption -- TMAX CC Certification
Dear Elijah!

Thank you for your reply!

1.     Would you please give the BETA version of PicOS 3.x ASAP?
2.     I want the installation image which is configured SHA512 by default
3.     Please asked to PLM when it will be supported.
4.     4&5, it should be fixed and approved ASAP. when it is fixed, please send the installation binary.

Best Regards!
Kevin

From: Elijah Ai [mailto:elijah.ai@pica8.com]
Sent: Monday, October 29, 2018 7:14 PM
To: kgi@in4a.co.kr; support@pica8.com
Cc: Henry Pan <henry.pan@pica8.com>; plm@pica8.com
Subject: Re: RE: System Log file ownership and Encryption -- TMAX CC Certification

Hi Kevin,

Here are my answer to the questions:

1.  Debian8 will be used after PicaOS 3.1, according our plan, I think it will be available until the first quater of next year.

2.  Yes, MD5 is default option. You can manually in the file: /etc/pam.d/common-auth like below:

you can find more information with this link:
http://www.linux-pam.org/Linux-PAM-html/sag-pam_unix.html

3.  Currently we don't have plan for SNMP v3, but I will send the request to our plm.

4&5.   For this two questions, I will file a bug to our engineer team for further solution.

Best regards,
Elijah



elijah.ai@pica8.com



From: kgi@in4a.co.kr
Date: 2018-10-28 14:39
To: support@pica8.com
CC: 'Henry Pan'; plm@pica8.com
Subject: RE: System Log file ownership and Encryption -- TMAX CC Certification
Dear Support!

Hi.. I have several questions about PicOS OVS Mode.

1.    When the PicOS is supporting "pam_pwquality.so" by Debian8?
Because "pam_cracklib.so" has some bug to set password.

2.    “SHA512” for encryption by default instead of “MD5”
Would you please sent the “SHA512” for password encryption by default? In current implementation, PicOS is set to “MD5”.

3.    SNMP v3 on OVS mode
Would you please let me know when SMVP v3 will be supported on OVS mode?

4.    Ownership for system
Some system files are set to “664” which means everyone can read those files.

But, normal Ubuntu Linux has “600”.
Would you please change the ownership for system on PicOS?


5.    System Log’s ownership
The PicOS’s Log files has “775” ownership like below. So, every user can read it.

But, normal Ubuntu linux has “640” ownership.
Would you please change this ownership on PicOS next version?



Best Regards!
Kevin

From: Mikel Tang [mailto:mikel.tang@pica8.com]
Sent: Monday, October 08, 2018 7:44 PM
To: kgi@in4a.co.kr; support@pica8.com
Cc: Henry Pan <henry.pan@pica8.com>
Subject: RE: System Log file ownership and Encryption -- TMAX CC Certification

Hi Kevin,

1．  Yes, the “chmod 770 messages” command can only change it temporarily. If you want to change it permanently.
I will ask our engineering team to see if there is any way and let me know.

2.    From your description it seems that rsyslog uses TLS encryption whether meet customer needs, If yes, please visit the following link:
        https://www.rsyslog.com/doc/tls_cert_ca.html

Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: kgi@in4a.co.kr <kgi@in4a.co.kr>
Sent: Monday, October 8, 2018 4:15 PM
To: Mikel Tang <mikel.tang@pica8.com>; support@pica8.com
Cc: Henry Pan <henry.pan@pica8.com>
Subject: RE: System Log file ownership and Encryption -- TMAX CC Certification

Dear Mikel!

Please see my additional questions in-line.

Kevin

From: Mikel Tang [mailto:mikel.tang@pica8.com]
Sent: Monday, October 08, 2018 5:00 PM
To: kgi@in4a.co.kr; support@pica8.com
Cc: Henry Pan <henry.pan@pica8.com>
Subject: RE: System Log file ownership and Encryption -- TMAX CC Certification

Hi Kevin,

Question #1)
How can I change it to see only owner and xorp group users?
$ sudo chmod 770 messages
       -rwxrwx--- 1 root xorp      0 Aug 29 08:09 messages

The the owner can read from, write to, or execute the file and any member of the file's owning group xorp may read write
and execute the file any other user cannot access the file.
  Kevin
When I change the mode for “messages” file, there are two issues are expected.
One, when the switch is reboot, the mode will be roll back to original ownership.
Two, when the log is migrated to messages.1, the messages.1 has also ownership issue.
Also, I am not sure the “messages” are keep same ownership or not.
I think we have to set something in syslog configuration to change ownership.


Question #2)
How can I set to encrypt the messages file?
We do not recommend that you encrypt this log file, It may cause the PicOS system to fail to write the log to this file.
If these messages file must be encrypt, there is a tool called GPG which allows you encrypt files.For more details please visit the following link.
     https://linuxconfig.org/how-to-encrypt-and-decrypt-individual-files-with-gpg

  Kevin
The Encryption is required to send the log to “SYSLOG SERVER”.
It is not needed to encrypt it in local. (as I know most system is working like this)
So, I want to know how can the log is encrypted when it is sent to others such as “Log server”.


Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: kgi@in4a.co.kr <kgi@in4a.co.kr>
Sent: Monday, October 8, 2018 3:41 PM
To: support@pica8.com
Cc: Mikel Tang <mikel.tang@pica8.com>; Henry Pan <henry.pan@pica8.com>
Subject: RE: System Log file ownership and Encryption -- TMAX CC Certification

Dear Support!

Hi..
Would you please below email and update to me?

Thank you!
Kevin

From: kgi@in4a.co.kr [mailto:kgi@in4a.co.kr]
Sent: Monday, October 01, 2018 4:28 PM
To: 'support@pica8.com' <support@pica8.com>
Cc: 'Mikel Tang' <mikel.tang@pica8.com>; 'Henry Pan' <henry.pan@pica8.com>
Subject: System Log file ownership and Encryption -- TMAX CC Certification

Dear Support!

Hi..

Question #1)
Current PicOS is set to show everyone can see(read) the System Logs like below.
How can I change it to see only owner and xorp group users?



Question #2)
How can I set to encrypt the messages file?

Thank you!
Kevin









I tried minicom connecting to our 2.x boxes, verified that the workaround is OK.

But the sequence in minicom that triggers the oom-killer is just `Ctrl-A then F`, which is serial break that kernel also responses.




--
Aaron

From: Zoneson Chen
Sent: Friday, October 26, 2018 11:53:24 PM
To: Aaron Shang; Tom Jia; Tim Yi; Richard Zhang; Jacob Wang
Cc: TACinternal
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands

Aaron,

Thank you for the proposed solution and testing! We can base your proposal to perform the rest testing. If it works, we will propose it as a workaround to Cray.

Thanks,

Zoneson

From: Aaron Shang <aaron.shang@pica8.com>
Date: Friday, October 26, 2018 at 8:49 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, Tom Jia <tom.jia@pica8.com>, Tim Yi <tim.yi@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Jacob Wang <jacob.wang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands

I had tried on my notebook.

When SysRq is enabled, and Alt-SysRq-F is pressed, from `dmesg` there logged:

        sysrq: SysRq : Manual OOM execution
        Purging GPU memory, 203 pages freed, 42588 pages still pinned.

When SysRq is disabled, pressing the magic keys would leave log as

        sysrq: SysRq : This sysrq operation is disabled.


So the solution works here.



I had managed to connect a USB--D-sub+D-sub--console cable between my computer and boxes, and tried efforts to reproduce the workaround using minicom sequences.

Let me report when I make them running and finish that testing.



----

BTW, my previous comments were not complete, or had some misleading words.

According my further investigations on the running systems on hand, I think we SHOULD disable oom-killer in later releases.

The facts are that most distros disable the oom-killer.

Although default Linux kernel config is to enable all SysRq functions, some distributions changed that kernel config, and changed the behavior elsewhere.

On some Debian releases, the SysRq value is 438, which means:
```
  2 =   0x2 - enable control of console logging level
  4 =   0x4 - enable control of keyboard (SAK, unraw)
 16 =  0x10 - enable sync command
 32 =  0x20 - enable remount read-only
128 =  0x80 - allow reboot/poweroff
256 = 0x100 - allow nicing of all RT tasks
```

On Ubuntu 18.04, the default value is 0x01b6, which is also 438.

    $ grep SYSRQ_DEFAULT /boot/config-4.15.0-38-generic
    CONFIG_MAGIC_SYSRQ_DEFAULT_ENABLE=0x01b6


But the latest `procps` package on Debian/Ubuntu set the value as 176.
The reason is for security concern, not to let is possible to debug mem dump or crash screen lock, etc.

```
 16 =  0x10 - enable sync command
 32 =  0x20 - enable remount read-only
128 =  0x80 - allow reboot/poweroff
```

On latest Debian 9.5 and Ubuntu 18.04, the value is 176.



On latest Fedora, the kernel default is changed to 0.
```
$ grep SYSRQ_DEFAULT /boot/config-4.18.13-100.fc27.x86_64
CONFIG_MAGIC_SYSRQ_DEFAULT_ENABLE=0x0
```

But the package `systemd` set that value to 16, to only enable sync.



Since this had been designed for urgent rescue usage, 176 can be a nice value.




--
Aaron

From: Zoneson Chen
Sent: Friday, October 26, 2018 2:29:15 PM
To: Tom Jia; Aaron Shang; Tim Yi; Richard Zhang; Jacob Wang
Cc: TACinternal
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands

Tom,

Would you mind asking SQA to give the suggestion a try? Does user has to do it again after reboot/power cycle?

Thanks,

Zoneson








That is working as designed, enabled in all systems, just like they deal with `Ctrl-Alt-Del` combination.

OS should work so to accept these key combinations for disaster recovery.

They should not use `Ctrl-A, then F, then f` sequence in minicom.
These sequences are not one combination; pressing them at the same time would not work.

These THREE exact sequence will trigger, in turn:
    Ctrl-A:    Start a minicom command; Here `Ctrl-A` is one combination, not a sequence.
    then F:   Send break over serial console;
    then f:    Send a call to kernel oom killer to kill a memory hog process, but do not panic if nothing can be killed.

`Ctrl-A, then F` sequence in minicom, equeals to `ALT-SysRq` combination in keyboard interaction.



If they really want that sequence, they have to disable kernel SysRq using this command:

    # echo 0 >/proc/sys/kernel/sysrq

Please see more here:

https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/Documentation/admin-guide/sysrq.rst


For example, when I use `tmux` and launch `minicom` within, and I pressed `Ctrl-A`, then Z in order to show help in minicom.
But the result is that my `tmux` would quit. Because it response first.

I should NOT change minicom behavior, because I am not able to change remote minicom, and I had lots of hosts running minicom.

I SHOULD change my `Ctrl-A` behavior to `Ctrl-B` in `tmux`.

The above solved my issue with tmux against minicom, like their issue with minicom against switches.


--
Aaron

From: Zoneson Chen
Sent: Friday, October 26, 2018 9:30:15 AM
To: Aaron Shang; Tim Yi; Tom Jia; Richard Zhang; Jacob Wang
Cc: TACinternal
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands

Aaron,

It is really a good news that Cray identifies the ctrl sequence to cause the problem! I have filed bug# 9963 for this problem.

Thanks,

Zoneson


From: Aaron Shang <aaron.shang@pica8.com>
Date: Thursday, October 25, 2018 at 5:25 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Tim Yi <tim.yi@pica8.com>, Tom Jia <tom.jia@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Jacob Wang <jacob.wang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands


Glad to see it was found caused by minicom ctrl sequences, just as it says, anything that can possibly happen, does.

Maybe we should evaluate the impacts to disable SysRq response in system to cope with complex environments.


--
Aaron

From: Zoneson Chen
Sent: Friday, October 26, 2018 4:53:04 AM
To: Aaron Shang; Tim Yi; Tom Jia; Richard Zhang; Jacob Wang
Cc: TACinternal
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands

Hi Aaron,

Thank you for the answers! They are really helpful!

Thanks,

Zoneson

From: Aaron Shang <aaron.shang@pica8.com>
Date: Thursday, October 25, 2018 at 2:20 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, Tim Yi <tim.yi@pica8.com>, Tom Jia <tom.jia@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Jacob Wang <jacob.wang@pica8.com>
Cc: TACinternal <tacinternal@pica8.com>
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands

Hi, Zoenson,

The answer is no.

That indicates the memory zone available to allocation requests from kernel buddy info, although not all zones can be used to fulfill.

From previous logs, there showed some ovs process used 400MB+ memory, which seemed a bit to be abnormal. But that is not sure.

I did not noticed something would trigger oom-killer regularly in our system.
The possibility of serial break or alt-sysrq magic sequences which causes oom-killer exists, but should be rare.

We currently lack of stress tests to verify long term stability of the system, so we are not able to exclude abnormal behaviors caused by time lasting high load such as fragmentation or other possible complex combinations.
Running valgrind or like profiling against some of our components should be helpful to add our confidence.


--
Aaron

From: Zoneson Chen
Sent: Thursday, October 25, 2018 10:05:19 AM
To: Tim Yi; Tom Jia; Aaron Shang; Richard Zhang; Jacob Wang
Cc: TACinternal
Subject: Re: <Aaron help>FW: [Ticket#2018101065000012] 2.10.2.1 hangs with ovs-vsctl commands

Hi Aaron,

Do the following error messages indicate that memory has been used up to ~14G? Here is the sample I mean:

a.	Oct 20 2018 14:07:55 XorPlus kern.warning :Normal: 139*4kB (UEM) 62*8kB (UEM) 46*16kB (UEM) 15*32kB (UEM) 2*64kB (UE) 1*128kB (U) 1*256kB (M) 1*512kB (E) 1*1024kB (E) 3*2048kB (UEM) 3460*4096kB (MR) = 14182620kB

Thanks,

Zoenson






 I am now fixing issues on building of several remaining x86 boxes.
In order of priority, ag5648, as7312_54x,as7816_64x.


Summary of  current status.


ARM: Done
    Boxes with images done:
        ag6248c
        as4610

PowerPC: Done
    Boxes with images done:
        pronto3922
        pronto5101

X86 images:
    Boxes with images done:
        z9100
        ag9032
        s4048
        as5812_54x
        as5812_54t
        as6812_32x
        as6712_32x  [NOT in PLM 3.1.0 candidate list; deprecated by 6812 TD2]
        as7712_32x

    Boxes without images, some efforts needed for migration:
        ag5648          [To fix on migration issues] [High Priority. PLM 3.1.0]
        as7816_64x   [To fix on migration issues] [NOT in PLM 3.1.0 candidate list]
        as7312_54x   [To fix on migration issues] [High Priority. PLM 3.1.0]
        as5712_54x   [To fix on migration issues] [NOT in PLM 3.1.0 candidate list; deprecated by 5812 TD2]
        ag7648          [Totally same to s4048, to reuse s4048 build with variant model re-branding] [NOT in PLM 3.1.0]


PowerPC64: Not migrated.
        The only box is msh8920. Much more efforts would be needed rootfs had not been migrated, plus kernel/driver adaption.

Notes
        ag7648 is totally the same to s4048. So it is suggested to use OEM to reuse s4048 build with differentiation on model only.


Referenced PLM list of 3.1.0 release candidates.
        3922
        5101
        AS4610
        AS5812
        AS7312      [Not done]
        AS4610
        AS5812
        AS6812
        AS7712
        AG5648      [Not done]
        AG9032
        S4048
        S9100
        MSH8920    [Not done]
Other boxes that had been remaining in `master`, but not migrated into 3.1.0.
        N3048 [High Priority. DELL partnership products.]

Other boxes that had NOT been in `master`, but of HIGH Prio into 3.1.0.
        N3048 [High Priority. DELL partnership products.]
        N3132 [High Priority. DELL partnership products.]
        S4148 [High Priority. DELL partnership products.]




--
Aaron

From: Lin Du
Sent: Tuesday, October 9, 2018 11:02:14 AM
To: Aaron Shang; George Guo; Daisy Zhao
Cc: Tom Jia; Richard Zhang; Jacob Wang; Vic Lan; Barton Song
Subject: FW: (Product Development Life Cycle) Re: Task: PICOS 3.1 (Cards)

Aaron, George,
We are preparing for getting 3.1 out with updated kernel/rootfs/installation/upgrade and static VRF.
1.       Please build all images supported for the current 3.1 - Aaron
2.       and do some unit testing for driver/installation as well - George
3.       provide the x86/arm/ppc images for regression team – Aaron, George
If need help from L2/L3 team for checking VRF merging, please free to ash Daisy directly.
Thanks,
Lin


From: Hai Vo-Dinh (PICA8 Partner Portal) [mailto:application@teamwork.com]
Sent: Tuesday, October 09, 2018 9:34 AM
To: Lin Du
Subject: (Product Development Life Cycle) Re: Task: PICOS 3.1 (Cards)

===== WRITE YOUR REPLY ABOVE THIS LINE =====

Oct 08
18:34	Oct 08 18:34
Hai Vo-Dinh commented on this task
1. update PICOS 3.1 specs
2. Move to QA phase
3. Provide time line for beta release

Jul 25
16:47	Jul 25 16:47
James Liao commented
Can we update the plan for PICOS 3.1? As far as I can tell, the contents are
1. VRF (phase 1.0 and phase 1.1) - key feature
2. Linux upgrade to 4.14 kernel
3. Unified fan control and temperature sensors

Unless we have other tasks to add to 3.1, we should plan the time and put together the test plan. PLM should lead this planning.

Jul 09
10:24	Jul 09 10:24
James Liao commented
The VRF project is moving forward. We need to start the release plan for 3.1. This release will require full regression and manual tests.

Jun 18
18:31	Jun 18 18:31
Niraj Jain commented
Sharad: For Kontron, we will keep 64 bit unsupported rootFS; kernel will need to be updated with latest fixes.

Jun 18
17:09	Jun 18 17:09
Niraj Jain commented
We should discuss in PDLC today and also get a status update on 3.1

Jun 05
20:05	Jun 05 20:05
Tom Jia commented
An unstable Debian (64-bit) is used in 2.11.x Kontron/MSH8920 code. In 3.1.0, we plan to replace it with the LTS version - Debian 8.8 which does work on MSH8920 platform.
•	Cons
o	it is 32-bit.
•	Pros
o	It would save much maintaining effort to keep all support platforms with one version of rootfs.
o	Can use 3rd tools and application via such as apt-get
Kernel will not be changed in 3.1.0 - 4.14.43 (64-bit).
Please let us know what is your thought or concern.

Jun 05
14:11	Jun 05 14:11
James Liao commented
Functional Spec of 3.1
https://pica8com.sharepoint.com/:w:/r/sites/Engineering/_layouts/15/doc2.aspx?sourcedoc=%7B3928C6AC-1DA9-44E6-939B-DADCE8EB4FB1%7D&file=Linux-Enhancement-Requirement-PicOS-3.1-final-version-of-Engineer-side%20(hv1)-20180418.docx&action=default&mobileredirect=true


This email has been limited to the 6 most recent comments. View all comments


(#9480304)
Task Details
Due Date: Not set
Priority: High
Tags: Alert R_3.1
Board Column:   PLANNING FS/Resourcing
Assigned To: Anyone
Assigned By: Hai Vo-Dinh
View Task: PICOS 3.1
Task List: Cards
Task Description:
The purpose for this card is to track the overall status of PICOS 3.1
Project Details
Project: Product Development Life Cycle
Company: PICA8
Copied To: Sharad Ahlawat, Niraj Jain, James Liao, Lin Du, Tom Jia
Not interested?: Stop receiving comments on this task
YOU CAN POST A REPLY TO THIS MESSAGE BY REPLYING TO THIS EMAIL.
P.S. Just in case: You can reset your password by clicking here
Reply to: tw.10.19336136.507@replies.teamwork.com






Hi, Sharad,

Also shocked by the fact.

We have to take the policy seriously.

I had not touched the firewall settings before. Louis here had been in charge of that and acted as interface for firewall vendor.

Hi, Louis, please verify the rules carefully to avoid potential damages.
Strict, whitelist policy is preferred.


On Tue, Apr 10, 2018 at 1:24 AM, Sharad Ahlawat <Sharad.Ahlawat@pica8.com> wrote:
> Aaron, saw your email on the botnet issue to engineering and that prompted
> me to add a block policy on the firewall. But the policies applied on the
> firewalls gave me a shock; we had policy rules there that permitted any zone
> to talk to any zone, essentially opening up the entire infrastructure to the
> internet. It seemed like the policies were randomly added to just make
> things work as there were multiple overlapping policies and in the wrong
> order.
>
>
>
> In any case, I cleaned up the policies now. As a result, there may be
> connectivity issues experienced, so please let me know of those and I will
> make the appropriate policy changes.
>
>
>
> --
>
> /Sharad





mSATA should use standard SATA driver.

eUSB needs some adapter, perhaps be eMMC, ATA, CF, etc. and appears as USB Mass Storage device using USB drivers.


--
Aaron

From: Lin Du
Sent: Thursday, March 29, 2018 5:18:39 PM
To: Aaron Shang; George Guo; Jacob Wang; Vic Lan; Richard Zhang; Barton Song
Subject: RE: eUSB to mSATA

Any difference to drivers or applications?

From: Aaron Shang
Sent: Thursday, March 29, 2018 5:14 PM
To: Lin Du; George Guo; Jacob Wang; Vic Lan; Richard Zhang; Barton Song
Subject: Re: eUSB to mSATA


eUSB is embedded USB.

mSATA is mini SATA.

    eUSB needs special controller, without standard spec.


mSATA is part of SATA over Mini PCI Express.

mSATA is meant for mass storage, like SSD.




However, mSATA had been phased out by M.2 spec. Most new devices are M2 interface.

mSATA is an old solution, with many drawbacks and bus / interface compatibility issue.






https://en.wikipedia.org/wiki/PCI_Express#MSATA

https://www.micron.com/support/faqs/products/managed-nand/eusb

The embedded universal serial bus (eUSB) is a NAND flash-based memory solution that is compliant with the USB industry standards.



https://en.wikipedia.org/wiki/M.2
M.2, formerly known as the Next Generation Form Factor (NGFF),


--
Aaron

From: Lin Du
Sent: Thursday, March 29, 2018 4:32:09 PM
To: Aaron Shang; George Guo; Jacob Wang; Vic Lan; Richard Zhang; Barton Song
Subject: FW: eUSB to mSATA

Does anyone know the difference between eUSB and mSATA?

From: shenf_wu@edge-core.com [mailto:shenf_wu@edge-core.com]
Sent: Thursday, March 29, 2018 3:57 PM
To: Henry Pan
Cc: Lin Du
Subject: eUSB to mSATA
Importance: High

Hi Henry/Lin,

We are planning enlarge the flash size from 8G eUSB to 32G mSATA.
The ONIE will modify to support mSATA and please try to download the test image at https://accdrive.accton.com.tw/my/personal/shenf_wu/_layouts/15/start.aspx#/Documents/Forms/All.aspx?RootFolder=%2Fmy%2Fpersonal%2Fshenf%5Fwu%2FDocuments%2F%E8%88%87%E6%89%80%E6%9C%89%E4%BA%BA%E5%85%B1%E7%94%A8&FolderCTID=0x01200026137568118F014B9752311C244F2DEE&View=%7BACAF96E3%2DF389%2D47BF%2DA13B%2DEC2660A01334%7D&InitialTabId=Ribbon%2ERead&VisibilityContext=WSSTabPersistence

Those image is only for verify and there will be some process needs to be taken before ECN.
So, let you verify the change in advance.

Best regards,
Sam Wu
Open Networking Division, Edgecore Networks Corporation
Tel : +886 3 563 8888 # 3581
Fax: +886 3 668 6111
Mail : shenf_wu@edge-core.com
Web: www.edge-core.com








Here are answers to the two questions.

I removed `support@pica8.com` because I don't know how to properly reply.
So please Don or Zoneson judge what to include.



----

On the messages about sandbox user _apt missing

The 8920 box is PPC64 and had been using the unstable/sid release of rootfs, so there might be some buggy packages there.

Newer `apt` would try to use a sandbox user `_apt` to do some work, so it would warn when there is no such user.

`apt-transport-https` is now a dummy transitional package for https support, with https support had been in the new `apt` package.

To install the `apt-transport-https` would upgrade the `apt` package, during the process, the sandbox user `_apt` would be added.

    postinst- adduser --force-badname --system --home /nonexistent  \
    postinst:     --no-create-home --quiet _apt || true


So, there would be no complaints any more about the missing user.

The above changes had all been in Debian 8.

----

On the error of missing `update-inetd`.

This version of telnetd still makes use of `xinetd`, and uses `update-inetd`.

Package `update-inetd` had been removed after Debian 8.

And with introduction of `systemd`, most `xinetd` services had been using systemd services.

To solve the mentioned issue, a workaround is to manuely install `update-inetd`.

First, try to install via apt:

    sudo apt install update-inetd

That would not succeed due to previous `telnetd` errors, which might cause the packaging system in bad inconsistent status.
But that would fetch the `deb` package for us.
So,

    cd /var/cache/apt/archives/

    sudo dpkg-deb -R update-inetd_4.44_all.deb  ./bardir

    cd bardir/

    sudo cp -af usr/s* /usr/

Then we can have a working `update-inetd`. Then we continue `sudo apt install --reinstall telnetd`

That will install `telnetd` success.

You may run one or more times `sudo dpkg --configure -a` if the packaging system is in bad status.



--
Aaron


From: Yan Adam <Yan.Adam@kontron.com>
Sent: Thursday, April 12, 2018 09:12
To: support@pica8.com
Cc: Don DeRisi; Hai Vo-Dinh
Subject: MSH8920/PicOS "apt update" not working

Good day Pica8 team!

As discussed briefly with Hai in our conference call today, here is a report concerning the "apt" package tool not working in either MSH8920/2.9.3.9 or 2.11.0.0

In 2.11.0.0 I get:
admin@MSH8920:H1$ sudo apt-get update
Get:2 http://deb.debian.org/debian-ports unstable InRelease [42.4 kB]
Ign:2 http://deb.debian.org/debian-ports unstable InRelease
Get:3 http://deb.debian.org/debian-ports unstable/main ppc64 Packages [20.9 MB]
Get:4 http://deb.debian.org/debian-ports unstable/main all Packages [8800 kB]
Reading package lists... Done
W: No sandbox user '_apt' on the system, can not drop privileges
E: The method driver /usr/lib/apt/methods/https could not be found.
N: Is the package apt-transport-https installed?
W: GPG error: http://deb.debian.org/debian-ports unstable InRelease: The following signatures couldn't be verified because the public key is not available: NO_PUBKEY 06AED62430CB581C
W: The repository 'http://deb.debian.org/debian-ports unstable InRelease' is not signed.
N: Data from such a repository can't be authenticated and is therefore potentially dangerous to use.
N: See apt-secure(8) manpage for repository creation and user configuration details.

Follows is, for reference, what I've done to get around this:
After a little digging I found out that the keys were getting deprecated early 2018 so I downloaded the .deb as suggested following https://packages.debian.org/sid/debian-ports-archive-keyring. Installing it lead to another "strange" error:
admin@MSH8920:H1$ sudo dpkg -i debian-ports-archive-keyring_2018.01.05_all.deb
(Reading database ... 22729 files and directories currently installed.)
Preparing to unpack debian-ports-archive-keyring_2018.01.05_all.deb ...
Unpacking debian-ports-archive-keyring (2018.01.05) over (2016.02.01) ...
dpkg: dependency problems prevent configuration of debian-ports-archive-keyring:
debian-ports-archive-keyring depends on apt; however:
  Package apt is not configured yet.

dpkg: error processing package debian-ports-archive-keyring (--install):
dependency problems - leaving unconfigured
Errors were encountered while processing:
debian-ports-archive-keyring

So I unpacked (sudo dpkg-deb -R debian-ports-archive-keyring_2018.01.05_all.deb ./foodir) and installed (sudo apt-key add ./foodir /etc/apt/trusted.gpg.d/debian-ports-archive-2018.gpg), I still got this message:
admin@MSH8920:H1$ sudo apt update
Get:2 http://deb.debian.org/debian-ports unstable InRelease [42.4 kB]
Get:3 http://deb.debian.org/debian-ports unstable/main ppc64 Packages [21.2 MB]
Get:4 http://deb.debian.org/debian-ports unstable/main all Packages [8916 kB]
Reading package lists... Done
W: No sandbox user '_apt' on the system, can not drop privileges
E: The method driver /usr/lib/apt/methods/https could not be found.
N: Is the package apt-transport-https installed?

I was successful installing nevertheless, for example this got me a working python prompt:
sudo apt install python2.7-minimal

I realized the https messages concern the https://www.pica8.com/pica8 source. But I was able to stop getting that error by doing:
sudo apt install apt-transport-https

Two remaing issues/questions:
1-was were there messages about sandbox user _apt missing and why did installing apt-transport-https apparently make them go away
2-messages concerning telnetd during the configuration phase of apt install… For example:
Setting up telnetd (0.17-40+b2) ...
/var/lib/dpkg/info/telnetd.postinst: 8: /var/lib/dpkg/info/telnetd.postinst: update-inetd: not found
dpkg: error processing package telnetd (--configure):
subprocess installed post-installation script returned error exit status 127


Yan Adam
Concepteur en Intégration de Solutions
Solutions Integration Designer
Kontron – An S&T Company
4555, rue Ambroise-Lafortune | Boisbriand (Québec) J7H 0A4 | Canada
T/P: +1 450 437 4661 x2266
yan.adam@kontron.com

Website | Blog | Twitter | LinkedIn | YouTube | Facebook
Kontron Canada Inc.
En ouvrant ce courriel, vous acceptez la politique de Kontron relative aux communications électroniques.
By opening this email you are agreeing to Kontron's Electronic Communications Policy.








By `libssh`, we mean `libssh-4`.
It is 0.5.4-1+deb7u3 in Debian 7.
It can be at most 0.5.4-3~bpo70+1 via Debian 7 backports.
It can only be 0.6.3-4+deb8u2 in Debian 8.
In Debian 9, it is 0.7.3-2.
It can be up to 0.8.0 via Debian 9 backports.

We did not provide that as a package in picos, because the netconf implementation we used need at least 0.6.4.
So we had to manually provide a 0.7.1 in 2.x.

Basically that can be upgraded to 0.7.3.

We can use 0.7.3 or 0.8 in 3.x according to building dependency.



By `libssl`, we usually mean `openssl`.



--
Aaron


From: Hai Vo-Dinh
Sent: Wednesday, March 28, 2018 14:30
To: Aaron Shang; Lin Du; George Guo; Richard Zhang; Tom Jia; Sharad Ahlawat
Cc: Zoneson Chen
Subject: Re: Cloudistics/Lenovo security patch

Hi Aaron,

I’m sorry, I left out libssh (not libc) as another package that Cloudistics would like to update.  Would you please check to find out if we can update libssh also? Then I can ask Cloudistics if we can do a build with just the packages that make sense to update.  No need to worry about lighttpd since they will disable it with a config change.

Thanks,
Hai

From: Aaron Shang <aaron.shang@pica8.com>
Date: Tuesday, March 27, 2018 at 7:45 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>, Lin Du <lin.du@pica8.com>, George Guo <george.guo@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Tom Jia <tom.jia@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Cc: Zoneson Chen <zoneson.chen@pica8.com>
Subject: Re: Cloudistics/Lenovo security patch

These are the version list of the mentioned packages in our 2.x/3.x releases.

Please check whether the latest possible upgrade version can meet the requirements, or can we agree to a compromise.
(I guess YES for ntp, openssh, openssl, perhaps NO for lighttpd, iptables.)


BTW, 26 April 2016
was the Security support END date for Debian 7.
Debian 8 can have regular Security support for all packages until May 2018.
Their 2 year prolonged LTS can only support a few selected packages by sponsorship.


lighttpd
2.x    lighttpd/1.4.33-devel-13227
3.x    1.4.35-4+deb8u1
Debian 9:    1.4.45-1
Latest:         1.4.49-1
The 2.x build is done manually, so we can upgrade to certain latest lighttpd release.
The latest Debian 7 can only upgrade to 1.4.31-4+deb7u5, which is even lower than our manual build.


iptables
2.x    1.4.14-3.1
3.x    1.4.21-2+b1
Debian 9:    1.6.0
Latest:         1.6.2-2
The latest Debian 7 can only upgrade to 1.4.14-3.1, which is the same to current one.


ntp
2.x    4.2.6.p5+dfsg-2
3.x    4.2.6.p5+dfsg-7+deb8u2
Debian 9:    4.2.8p10+dfsg-3+deb9u2
Latest:         4.2.8p11
The latest Debian 7 can only upgrade to 4.2.6.p5+dfsg-2+deb7u4, which fixed severe vulnerabilities, as the 4th patch.


openssh
2.x    6.0p1-4
3.x    6.7p1-5+deb8u4
Debian 9:    7.4p1-10+deb9u3
Latest:         7.6p1-2
The latest Debian 7 can only upgrade to 6.0p1-4+deb7u7, which fixed severe vulnerabilities, as the 7th patch.

openssl
2.x    1.0.1g-2
3.x    1.0.1t-1+deb8u7
Debian 9:    1.1.0f-3+deb9u1
Latest:         1.1.0g-1
The latest Debian 7 can only upgrade to 1.0.1t-1+deb7u3, which fixed severe vulnerabilities, as the 3rd patch.


--
Aaron

From: Hai Vo-Dinh
Sent: Wednesday, March 28, 2018 9:27:14 AM
To: Lin Du; Aaron Shang; George Guo; Richard Zhang; Tom Jia
Cc: Zoneson Chen
Subject: Re: Cloudistics/Lenovo security patch

Tom,
Based on the discussion that we had last time, the proposal is to replace the 5 modules,   and release a special branch of the 2.11.x image for the AS5812 only for Cloudistics.
Thanks,
Hai

From: Tom Jia
Sent: Tuesday, March 27, 2018 6:12:29 PM
To: Hai Vo-Dinh; Lin Du; Aaron Shang; George Guo; Richard Zhang
Cc: Zoneson Chen
Subject: Re: Cloudistics/Lenovo security patch

Hello Hai,

It is great to have a well defined scope of the security requirement from Cloudistics. Let me add Linux platform guys.
Aaron, per our previous discussion with Hai, could you please evaluate if we could have a solution based on the current 2.11.x code? Or else we have to use incoming 3.1 code to address customer's security concern.

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Hai Vo-Dinh
Sent: Wednesday, March 28, 2018 2:44:03 AM
To: Tom Jia; Lin Du
Cc: Zoneson Chen
Subject: Cloudistics/Lenovo security patch

Hi Tom,

Would you please update us on the Cloudistics/Lenovo Security patch, where we would replace the following libraries: openssh, openssh, libc, libssh, ntp?

The only hardware platform that Cloudistics in concerned with is the Edge-core AS5812-54X.

Thanks,
Hai







Got.

Just had wondered why that guy could get the support@ mails.




Sorry to make you worried.

I would give up replying from Gmail.



There had been basically two reasons,

1. Speed.

The contents load very, fairly slow there, either in Outlook client, or in office.com web interface, although various means / themes had been tried, even using their Beta UI.

Only the headers can show at first, then after several minutes, contents of FIRST (Newest) mail would appear.

If you delete batch of mails by checking the tiny boxes before each mail, then you can see the numbers changing one by one in number of seconds.

No such issue in Google mail or my G Suite / Google app.



2. Reading / Working experiences.

The thread/conversation had always been (almost) a mess, hard to judge the referenced part or orders.

The contents can not be easily included as indented or as preceded by `>>  ` signs rendering by most readers.

In Google mail, that's nice.



Actually I had no bias towards companies, only the experiences matters. ;)



--
Aaron


From: Sharad Ahlawat
Sent: Thursday, March 15, 2018 14:06
To: James Liao; Aaron Shang; Zoneson Chen; Lin Du
Subject: Re: [Ticket#2018012765000016] PicOS 2.11.0 beta is ready to download

Nope - Panagiotis is being constantly copied on that support thread and I guess is not interested in seeing these emails and wants out.

Aaron, the OTRS support system has been setup in an interesting way. The support mailing list - includes otrs.support - a mailbox that is accessed by the OTRS server and emails are read from it over IMAP - emails are sent out from this AWS instance using the proxy APIs of our Microsoft account pica8com. Direct responses to otrs.support are also copied duplicated to TACinternal.

BTW, I have been meaning to ask you about this, you need to figure out a way to stop using gmail for office emails - we don't want google analyzing all PICA8 communication. What is the reason that you have to use Gmail? We can switch over to Google Business Account if you dislike Microsoft :)

--
/Sharad







hi, andrew,

thanks a lot for sharing!

today is the last day of our national holidays, and most of us would be back on duties in a couple of days, a heavy traffic would be expected in all means of transportations.

it is called Spring festival, traditionally marking the start of a new year of farming.

due to huge imbalance caused by national policy, resources and thus talents, opportunities are usually occupied by several major cities. remote work is not a choice, even for it and web businesses. almost half of working forces in China have to be away from their elder generations, even their own children and family.

there are many rites, customs, and conventional foods across chinese speaking natives, however the focus is family reunion and good wishes for a prosperous coming year.


hope you had enjoyed the celebrations and foods there.


btw, the flags hung in your photo is that of republic of China, which had ruled China for about 40 years before 1949 then moved to taiwan, replaced by peoples` republic of china in mainland.
although under different administration, we share same speaking language and culture.




--
Aaron
在 2018年2月19日 12:43，Andrew Lissitz <andrew.lissitz@pica8.com>写道：
<pls forward as needed!>

Hey team,

I went to NYC Chinatown this weekend to celebrate the Chinese New Year, and I had a great time.  I stayed at the Beekman hotel, in case you want an amazing hotel (5-star) in the financial district!  This hotel really is amazing, but that is another story!

In Chinatown, I especially loved the MOCA, very educational and really gives insights and history to the enormous influence China has had on America; all of it was very interesting.  We probably walked 3 miles, tasting and seeing all the sights.  I took only a few pics, and this video … I ate a lot of amazing food as well, tea too!  The original eggroll is here, can you believe it!!!  lol.  So many people were there, and there are more celebrations coming up next weekend as well!  Without a doubt, this will be a great year!

I had my friend record me wishing you all a happy New Year!  This video is for you!  Please have a fantastic year with many many more fantastic years to come!

Kindest Regards,
Andrew








FYI,

The Beijing team is running around a Gitlab setup, which has also a ticket/issue board that automatically updates according to involved issue/milestone/release status change.
https://docs.gitlab.com/ee/user/project/issue_board.html

But it can only be accessed now from internal with hostname `code` or `code.pica8.local` mapped to 10.10.50.50.


You can try with user name `build` and passwd `pica8build`, such as project status:

http://code/pica8/picos/boards

http://code/pica8/picos/milestones



Some features had been actively used, some not.



About Gitlab:
https://about.gitlab.com
 	GitLab - The leading product for integrated software ...
about.gitlab.com
“GitLab is the leading integrated product for modern software development. Connecting issue management, version control, code review, CI, CD, and monitoring into a ...



--
Aaron


From: Niraj Jain
Sent: Wednesday, January 31, 2018 04:59
To: sales@pica8.com; support@pica8.com; plm@pica8.com
Cc: mkt; James Liao; Lin Du; Sharad Ahlawat
Subject: PDLC Process - Continuous Improvement - PERs

Team,
Based on the discussion and dialogue over the last few weeks, I am making a few changes to how we manage the new incoming requirements (RFE/PER) in the PDLC process:
•	Any questions about features/capabilities/documentation in current shipping product should be directed to Support
o	Based on the reply from Support, it should be possible to determine if you are dealing with a bug or missing feature
•	Bug fixes should be handled through Support, asking for a Bugzilla ticket to be opened after the bug has been verified
o	PLM will set priorities on bugs after review with Sales/SE teams and consult with Engineering for inclusion in upcoming releases
•	PERs should be focused on feature additions/enhancements and not bug fixes
o	As much as possible, PERs should include information about customer and use cases
•	PERs will go through Sales review and prioritization before being taken up by PLM for insertion into PDLC
o	Sales review should be conducted by the respective account/territory managers, working together with the SE team
o	Multiple PERs may be consolidated or restructured as an outcome of the review and prioritization process
o	PLM will wait for Sales signoff (can be on the same project card) before picking up the card for action
•	Once PERs are taken up for action, the associated card(s) may be moved over to the PDLC section as backlog items
o	All PDLC contents are visible to Sales (read only) at pdlc.pica8.com – see screenshot attached
•	If the initiator wants to update/add to an existing PER, they can add a link to it in its current location or request that it be returned to the PER section

Questions/comments welcome!

Niraj Jain
COO

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
M: +1 408 802 0105
niraj@pica8.com  |  www.pica8.com
Pica8
www.pica8.com
Pica8's 100G Software provides networks with greater capacity to handle data traffic and improve flexibility and efficiency while lowering the overall cost.


Follow us on Twitter









To minimize the result list of un-patched vulnerabilities, we have two solutions.

Solution 1: To maintain the daemon `unattended-upgrades`, that will handle the security fixes automatically from official Debian release.

To do that, we need to enable the security sources:

    deb http://security.debian.org/ stretch/updates main contrib non-free


Solution 2: Upgrade our Debian base to latest fixes during our each release.

I prefer this one, because we can cover due regression tests for our release, and have our shipped boxes less uncontrolled.




--
Aaron

From: Hai Vo-Dinh
Sent: Saturday, January 27, 2018 4:21:30 AM
To: Aaron Shang; Lin Du; plm@pica8.com
Subject: FW: Go To Market Security Strategy

FYI.  Below are the security scan results from Lenovo.  Apparently, we will need a significant amount of patching.

Hai

From: Branislav Meandzija <bmeandzija@lenovo.com>
Date: Thursday, January 25, 2018 at 2:30 PM
To: Joe Digiovanni <joe.Digiovanni@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Renata Lai4 <rlai4@lenovo.com>, Adam Guo <guoyh2@lenovo.com>, Atul Tambe <atambe@lenovo.com>
Subject: RE: Go To Market Security Strategy

Hi Guys,

We have run a number of packages on the PicaOS 3.0 list Hai shared through Protecode. Attached are the list of packages we analyzed so far (the word file; the packages checked are marked yellow), and the CVS score sorted list of vulnerabilities in the second file attached.

All vulnerabilities marked Orange are a show stopper for us at the SSRB.  Once we go through all the packages on your list we will try to further analyze the critical vulnerabilities  with regards to whether there are any architectural remedies for preventing them from becoming exploits in our switches.

You can help us in any or all of the following ways:
1.	Upgrading the vulnerable packages.
2.	 Provide an early boot install image of PicaOS 3.0, so we can run that through Protecode without going package by package.
3.	Providing your own thoughts on architectural remedies for the listed vulnerabilities.

Regards,

Branislav

From: Branislav Meandzija
Sent: Tuesday, January 23, 2018 2:17 PM
To: 'Joe Digiovanni' <joe.Digiovanni@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; Atul Tambe <atambe@lenovo.com>
Cc: Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: RE: Go To Market Security Strategy

Great!

Branislav

From: Joe Digiovanni [mailto:joe.Digiovanni@pica8.com]
Sent: Tuesday, January 23, 2018 1:52 PM
To: Branislav Meandzija <bmeandzija@lenovo.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; Atul Tambe <atambe@lenovo.com>
Cc: Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

Hello Branislav,

Yes we are.

Best,

Joe Digiovanni
Business Development
Pica8, Inc.
Mobile:   +1 650 823 1038
E :  joe@pica8.com  | I:  www.pica8.com

From: Branislav Meandzija <bmeandzija@lenovo.com>
Sent: Tuesday, January 23, 2018 10:18:38 AM
To: Joe Digiovanni; Hai Vo-Dinh; Atul Tambe
Cc: Renata Lai4; Adam Guo
Subject: RE: Go To Market Security Strategy

Hi Joe,

So you are using backported Linux kernel 4.14 to Debian 8.9 or 10?  That will definitely help a lot. We will change our vulnerability assessment accordingly.

Regards,

Branislav

From: Joe Digiovanni [mailto:joe.Digiovanni@pica8.com]
Sent: Tuesday, January 23, 2018 9:35 AM
To: Branislav Meandzija <bmeandzija@lenovo.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; Atul Tambe <atambe@lenovo.com>
Cc: Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

Hello Branislav,

For R3, we will be using linux kernel 4.14 LTS, not kernel 3.14.  So if the vulnerabilities has to do with the kernel version 3.14 or some kernel version earlier than 4.14, than those may not be an issue.

Can Lenovo do the scan with linux kernel 4.14 and Debian 8.9 or 8.10?

Thanks,

Joe Digiovanni
Business Development
Pica8, Inc.
Mobile:   +1 650 823 1038
E :  joe@pica8.com  | I:  www.pica8.com

From: Branislav Meandzija <bmeandzija@lenovo.com>
Sent: Monday, January 22, 2018 5:28:10 PM
To: Hai Vo-Dinh; Atul Tambe; Joe Digiovanni
Cc: Renata Lai4; Adam Guo
Subject: RE: Go To Market Security Strategy

Hi Hai,

Debian 8 (Linux Kernel 3.14.x) has a number of critical vulnerabilities which are fixed in Debian 9, like:

Date 2017-08-29 – CVSS v2 Base Score: 10.0 - CVSS v3 Base Score: 9.8
CVSS v2 vector: AV:N/AC:L/Au:N:/C:C/I:C/A:C

CVSS v3 vector: AV:N/AC:L/PR:N/UI:N/S:U/C:H/I:H/A:H

The __skb_flow_dissect function in net/core/flow_dissector.c in the Linux kernel before 4.3 does not ensure that n_proto, ip_proto, and thoff are initialized, which allows remote attackers to cause a denial of service (system crash) or possibly execute arbitrary code via a single crafted MPLS packet.

How do we defend against something like the above or similar spirit attack? Do you have some type of analysis that can help us argue the case for  security strength of Pica)S 3.0?

Regards,

Branislav
From: Hai Vo-Dinh [mailto:hai.vodinh@pica8.com]
Sent: Friday, January 19, 2018 4:16 PM
To: Atul Tambe <atambe@lenovo.com>; Branislav Meandzija <bmeandzija@lenovo.com>; Joe Digiovanni <joe.Digiovanni@pica8.com>
Cc: Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

We will go to Debian 9 in the 2020 time frame  since Debian 8 LTS will end then.

Regards,
Hai

--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
M: +1.408.389.9422
hai.vodinh@pica8.com
www.pica8.com



From: Atul Tambe <atambe@lenovo.com>
Date: Friday, January 19, 2018 at 3:56 PM
To: Branislav Meandzija <bmeandzija@lenovo.com>, Joe Digiovanni <joe.Digiovanni@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Renata Lai4 <rlai4@lenovo.com>, Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

So does it mean that you would never go to Debian 9 or better in future?
BR.
- Atul
(408) 316 4436
*Sent from Mobile*


On Fri, Jan 19, 2018 at 3:52 PM -0800, "Hai Vo-Dinh" <hai.vodinh@pica8.com> wrote:
Hi Atul,

That is correct.  We are specifically choosing Debian 8.x because of the requirement to support customers with PPC64.  Debian 9 dropped support for PPC64 CPU architecture.

Regards,
Hai

--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
M: +1.408.389.9422
hai.vodinh@pica8.com
www.pica8.com



From: Atul Tambe <atambe@lenovo.com>
Date: Friday, January 19, 2018 at 3:47 PM
To: Branislav Meandzija <bmeandzija@lenovo.com>, Joe Digiovanni <joe.Digiovanni@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Renata Lai4 <rlai4@lenovo.com>, Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

Wait...sometime ago, early January,  you mentioned to us in an email that you recommended PicOS 3.0 which you said  would go to Debian 9 and Kernel 4.14 and help with security vulnerabilities we found in your current code.
So now, we are getting a different answer... is that correct?
BR.
- Atul
(408) 316 4436
*Sent from Mobile*


On Fri, Jan 19, 2018 at 3:43 PM -0800, "Hai Vo-Dinh" <hai.vodinh@pica8.com> wrote:
Branislav,

We have decided to go with Debian 8 as we have customer with PPC64.

Regards,
Hai

--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
M: +1.408.389.9422
hai.vodinh@pica8.com
www.pica8.com



From: Branislav Meandzija <bmeandzija@lenovo.com>
Date: Friday, January 19, 2018 at 3:41 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>, Joe Digiovanni <joe.Digiovanni@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>, Renata Lai4 <rlai4@lenovo.com>, Adam Guo <guoyh2@lenovo.com>
Subject: RE: Go To Market Security Strategy

Hi Hai,

We are in the process of  putting together a package with the components you listed, so we can run a scan on it. Have a question in the meantime. Most of components are Debian 8 and not Debian 9. Have you decided to go with Debian 8 for PicOS 3.0? Would it take more time to go with Debian 9 if necessary?

Regards,

Branislav



From: Branislav Meandzija
Sent: Thursday, January 18, 2018 2:33 PM
To: 'Hai Vo-Dinh' <hai.vodinh@pica8.com>; Joe Digiovanni <joe.Digiovanni@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>; Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: RE: Go To Market Security Strategy

Hi Hai,

Great. We’ll check for vulnerabilities.

Regards,

Branislav

From: Hai Vo-Dinh [mailto:hai.vodinh@pica8.com]
Sent: Thursday, January 18, 2018 1:39 PM
To: Branislav Meandzija <bmeandzija@lenovo.com>; Joe Digiovanni <joe.Digiovanni@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>; Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

Hi Branislav,

Please see attached for the tentative list of the packages to be included in PICOS 3.0.  The review is substantially done, but not 100% completed yet, so there might be some late changes.

Regards,
Hai

From: Branislav Meandzija <bmeandzija@lenovo.com>
Sent: Wednesday, January 17, 2018 3:00:55 PM
To: Hai Vo-Dinh; Joe Digiovanni
Cc: Atul Tambe; Renata Lai4; Adam Guo
Subject: RE: Go To Market Security Strategy

Hi Hai,

Any progress son the 3.0 package list?

Regards,

Branislav

From: Branislav Meandzija
Sent: Thursday, January 11, 2018 10:49 AM
To: 'Hai Vo-Dinh' <hai.vodinh@pica8.com>; Joe Digiovanni <joe.Digiovanni@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>; Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: RE: Go To Market Security Strategy

Great, thanks.

Branislav

From: Hai Vo-Dinh [mailto:hai.vodinh@pica8.com]
Sent: Thursday, January 11, 2018 10:45 AM
To: Branislav Meandzija <bmeandzija@lenovo.com>; Joe Digiovanni <joe.Digiovanni@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>; Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

Hi Branislav,

We will send you the list of all packages to be included in 3.0.  The list is being finalized currently, and we should have it early next week.

Regards,
Hai

--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
M: +1.408.389.9422
hai.vodinh@pica8.com
www.pica8.com



From: Branislav Meandzija <bmeandzija@lenovo.com>
Date: Thursday, January 11, 2018 at 10:01 AM
To: Joe Digiovanni <joe.Digiovanni@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>, Renata Lai4 <rlai4@lenovo.com>, Adam Guo <guoyh2@lenovo.com>
Subject: RE: Go To Market Security Strategy

Hi Joe,

Assuming your team is working hard on 3.0, would it be possible to get a version as soon as possible which we can run through our scan to determine early any potential issues. Or if that is not possible, just send a list of all the packages and versions included in 3.0. That way, we may have a fighting chance to develop on the existing version and drop in 3.0, and quickly approve the new set-up before release?

Regards,

Branislav

From: Branislav Meandzija
Sent: Tuesday, January 9, 2018 3:21 PM
To: 'Joe Digiovanni' <joe.Digiovanni@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>; Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: RE: Go To Market Security Strategy

Hi Joe,

I was hoping for something like you propose to do. I would think that should be possible but it highly depends on the timeline.

Atul,

Can you please comment?


Thanks,

Branislav

From: Joe Digiovanni [mailto:joe.Digiovanni@pica8.com]
Sent: Tuesday, January 9, 2018 3:18 PM
To: Branislav Meandzija <bmeandzija@lenovo.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Atul Tambe <atambe@lenovo.com>; Renata Lai4 <rlai4@lenovo.com>; Adam Guo <guoyh2@lenovo.com>
Subject: Re: Go To Market Security Strategy

Hello Branislav,

We will be addressing all of these concerns in PicOS 3.0.

I am still waiting for a delivery date on this.

Can you continue development using the current PicOS version?

Then, when 3.0 is available, you can simply update. Would this work?

Thanks,

Joe Digiovanni
Business Development
Pica8, Inc.
Mobile:   +1 650 823 1038
E :  joe@pica8.com  | I:  www.pica8.com


From: Branislav Meandzija <bmeandzija@lenovo.com>
Sent: Friday, January 5, 2018 5:14 PM
To: Hai Vo-Dinh
Cc: Atul Tambe; Joe Digiovanni; Renata Lai4; Adam Guo
Subject: Go To Market Security Strategy

Hi Hai,

We need to figure out to what extent the PicaOS8 vulnerabilities are protected from becoming exploits by deployment security architecture. As previously mentioned, the Lenovo SSRB relies on the  Common Vulnerability Scoring System and determines that at least any critical and major vulnerabilities need to be fixed. It is very likely that we will have to fix all of those to actually pass the SSRB towards a release. So, no fixes will likely mean no product!!!

The only way we can get exceptions for critical/major vulnerabilities is to provide a good argument that the vulnerabilities cannot become exploits when PicOS is used under the following conditions because ….

I do not see that this is the case for most of the major vulnerabilities with  the reasoning of “Since the vulnerable points are the management port, or the inband management interface, the best practices are typically ACL rules on the switches that would only allow access from jumphosts or “secure admin workstation” (SAW). ….”  as an admin can inadvertently enable an exploit through the admin connection, a malicious lower level admin can escalate his privileges, or man-in-the middle attacks exploiting crypto protocol weakness vulnerabilities become possible, etc.

We live in a security panicked world where we just learned almost any computing device is vulnerable. So, high security standards are an important feature that currently sells product.  Continuously updating software with fixes is a  common requirement.

So, can you please help me with rock-solid arguments for why each and every critical/major vulnerabilities of PicOS cannot become exploits. If this is not possible lets rush out PicOS 3.0 and hope that it has no critical/major vulnerabilities that can be xploited.

Regards,

Branislav





One more point about LTS.

Debian LTS is not like Ubuntu LTS or Kernel LTS. Ubuntu or Kernel LTS has official commitment.

Debian official support for Debian 8 (Jessie) will come to end on May 2018.

Debian LTS is now only by a special team sponsored by a company, to extend two more years, but without expected same patch level as official release.

--
Aaron

From: Lin Du
Sent: Wednesday, January 10, 2018 10:53:56 AM
To: Sharad Ahlawat; Hai Vo-Dinh; Niraj Jain
Cc: Aaron Shang
Subject: RE: PPC64 with Debian 9

Sharad,
The current two platforms, P3922 and P5101 can only work with Debian 8.0.
The x86 and ARM platforms should be easily migrated to Debian 9.0 without too much effort.

As to the second item, it is not suggested to work with Yocto, which is an embedded system, not fit for white box environment. Lots of effort is needed for maintaining the 3rd party packages, which don’t add any value to our product.  On the other hand, ONL/big switch and cumulus are all based on Debian release. The simple reason is Debain has rich CPU arch support than anyone else.  Systemd is the same case, it is the default bootup management service for the main Linux releases, including Debian , Fedora, Ubuntu and others. Technically, old init bootup can be easily kept. The extra burden is to hold our own package servers. That is the same case as Yocto since most applications may not work well with the old initd in future.

The PPC will disappear from white box market since no many vendors use it anymore. ARM CPU is embedded into the low end chips by default and high end ASIC needs for computing power, x86 is preferable.
From development side, Debian 8.0 or 9.0 are all fine. Debian 9.0 may need more time to test it since the new toolchain is used.
Thanks,

Lin

From: Sharad Ahlawat
Sent: Wednesday, January 10, 2018 12:42 AM
To: Lin Du; Hai Vo-Dinh; Niraj Jain
Cc: Aaron Shang
Subject: Re: PPC64 with Debian 9

Thanks Lin, I realized the same during the call.

https://www.powerpc-notebook.org/2016/11/debian-9-and-powerpc/ - this is the note referring to Debian's decision to discontinue PPC support

https://wiki.debian.org/LTS - Debian 8 is LTS supported till April 2020

So, what's engineering's Distro recommendation for 3.0?

1.	PPC on Debian 8 and all other platforms on Debian 9?

2.	Another distro like Yocto, NetBSD etc?

3.	Stick with Debian 8 and revisit this topic in 2020?

--
/Sharad


From: Lin Du <lin.du@pica8.com>
Date: Monday, January 8, 2018 at 19:28
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>, Niraj Jain <niraj.jain@pica8.com>
Cc: Aaron Shang <aaron.shang@pica8.com>
Subject: PPC64 with Debian 9

Sharad, Hai,
The Debian supported CPU page, https://www.debian.org/releases/stable/i386/ch02s01.html.en

Power Systems	ppc64el	IBM POWER8 or newer machines

Ppc64el is little endian while Kontron PPC64 is big endian.

Debain 9.0 doesn’t support PPC/PPC P2020/PPC64 big endian.
Thanks,

Lin







Yes, it is not excessive for our code, because the ROOTFS is so obsoleted.
So, that is not surprising to see the numbers.


--
Aaron

From: Hai Vo-Dinh
Sent: Thursday, January 4, 2018 9:07:13 AM
To: Aaron Shang; Tom Jia
Cc: Lin Du
Subject: RE: Pic OS - security vulnerability - Protecode scan

Hi Aaron,

Is it normal for the Protecode scan to find so many vulnerabilities?  It seems very excessive to me for our code to have almost 800 critical/major vulnerabilities.

Thanks,
Hai

From: Hai Vo-Dinh
Sent: Wednesday, January 3, 2018 3:10 PM
To: Aaron Shang <aaron.shang@pica8.com>; Tom Jia <tom.jia@pica8.com>
Cc: Lin Du <lin.du@pica8.com>
Subject: FW: Pic OS - security vulnerability - Protecode scan

Hi Aaron,

Would you please go through the vulnerabilities that the Lenovo protecode scan exposed and let me know what the issues are, and how we would deal with them?  What kind of code scan do we do internally?

Thanks,
Hai

From: Joe Digiovanni
Sent: Thursday, December 21, 2017 1:05 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Fw: Pic OS - security vulnerability - Protecode scan

Hello Hai,

The Lenovo team has some questions...

Can you and the team please look into Renata's questions below and respond to me?

Thanks,

Joe Digiovanni
Business Development
Pica8, Inc.
Mobile:   +1 650 823 1038
E :  joe@pica8.com  | I:  www.pica8.com


From: Renata Lai4 <rlai4@lenovo.com>
Sent: Thursday, December 21, 2017 2:49 AM
To: Joe Digiovanni
Cc: Diana Romero; Heidi Griffin; Atul Tambe; Branislav Meandzija; Adam Guo
Subject: Pic OS - security vulnerability - Protecode scan

Hi Joe,

We have discussed about the security vulnerability scan on Pic OS and Lenovo has done ProteCode scan on Edgecore switch AS5812-54x
There are some key open source components are with critical and major vulnerabilities (see csv file)You can find the details of each vulnerability by using the CVE number to search on web.
Lenovo would like to understand how PICA8 address the security issues and there are further questions listed below.
Please feedback and let Lenovo know if you have further questions.

1.          Is PICA8 aware that the open source components (linux kernel, ) are out of date and newer version will have less security vulnerabilities?
2.          Has PICA8 done any security patches to the opensource components?
3.          What does it take (time, money?) to get the following key vulnerable components upgraded or patched
   linux_kernal v3.16.7
   tcpdump 4.3.0
   openssl 1.01.1e
   glibc 2.13
   ntp 4.2.6p5
   curl 7.43.0
   ncurses 5.9-10



Best regards,

Renata Lai
TPM
Networking System Development
Lenovo TDC
rlai4@lenovo.com
Ph: +886-2-8170-7387
VoIP: 3287387
Mobile:+886-919936126






I had gone through the vulnerabilities reported by Protecode scan.

We understood the issues, and the vulnerabilities.

To deal with them, it is not optimistic in a short time.

Vulnerabilities had been found the fixed almost in daily bases for a giant system composed by hundreds of utilities and libraries.
So it is always best practice to apply official security patches immediately after released.

For new deployments of our products, it is suggested to prefer our 3.0+ releases, because that is based on higher releases of Debian, which would be on active security support for a long time.

For the current released products, Debian 7 ROOTFS was used, which would go to end of life even after extended LTS efforts in 4 months.
These security upgrading is true for ARM/X86 boxes. For PPC boxes, there had been never security support from the beginning.

If one component of the version included in Debian 7 was released 2010 and built in 2013 in the initial Debian 7 repo, then on our boxes, its built time should be still 2013 instead of the image building time of last week.
There would be security releases if the vulnerability was deemed critical by Debian.

OpenSSH is one example. dozens of vulnerabilities had been found and related fixes had been release in the past 3 years.
We had none of them.

Even with the existing security support, our ROOTFS had never applied any of the patches, because our ROOTFS had been maintained in binary mode and no upgrades had been done.

Actually we did not do scans internally. This kind of scan can be got by following Debian Security Advisory because that is the base of our ROOTFS. All their CVEs would be exactly listed in each announcement.
Protecode has an actively maintained proprietary database to track open source project vulnerabilities, also they had public available part of their tools.


So here comes the conclusion.
- For 3.0+ releases, we must strictly follow Debian stable release, either in binary or better built from source code.
    - Thus we always have latest security fixes.
- For releases before 3.0, we can deal with vulnerabilities by upgrading the ROOTFS to latest Debian 7.
    - But that still lacks latest security fixes in current stable Debian. Only very critical patches would be included by the LTS project.
    - Works for ARM/X86 boxes.
    - For PPC boxes, this may not work because of its not being actively maintained.
- We need to apply internal scan using available scan tools.

--
Aaron

From: Hai Vo-Dinh
Sent: Thursday, January 4, 2018 7:09:56 AM
To: Aaron Shang; Tom Jia
Cc: Lin Du
Subject: FW: Pic OS - security vulnerability - Protecode scan

Hi Aaron,

Would you please go through the vulnerabilities that the Lenovo protecode scan exposed and let me know what the issues are, and how we would deal with them?  What kind of code scan do we do internally?

Thanks,
Hai

From: Joe Digiovanni
Sent: Thursday, December 21, 2017 1:05 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Fw: Pic OS - security vulnerability - Protecode scan

Hello Hai,

The Lenovo team has some questions...

Can you and the team please look into Renata's questions below and respond to me?

Thanks,

Joe Digiovanni
Business Development
Pica8, Inc.
Mobile:   +1 650 823 1038
E :  joe@pica8.com  | I:  www.pica8.com


From: Renata Lai4 <rlai4@lenovo.com>
Sent: Thursday, December 21, 2017 2:49 AM
To: Joe Digiovanni
Cc: Diana Romero; Heidi Griffin; Atul Tambe; Branislav Meandzija; Adam Guo
Subject: Pic OS - security vulnerability - Protecode scan

Hi Joe,

We have discussed about the security vulnerability scan on Pic OS and Lenovo has done ProteCode scan on Edgecore switch AS5812-54x
There are some key open source components are with critical and major vulnerabilities (see csv file)You can find the details of each vulnerability by using the CVE number to search on web.
Lenovo would like to understand how PICA8 address the security issues and there are further questions listed below.
Please feedback and let Lenovo know if you have further questions.

1.          Is PICA8 aware that the open source components (linux kernel, ) are out of date and newer version will have less security vulnerabilities?
2.          Has PICA8 done any security patches to the opensource components?
3.          What does it take (time, money?) to get the following key vulnerable components upgraded or patched
   linux_kernal v3.16.7
   tcpdump 4.3.0
   openssl 1.01.1e
   glibc 2.13
   ntp 4.2.6p5
   curl 7.43.0
   ncurses 5.9-10



Best regards,

Renata Lai
TPM
Networking System Development
Lenovo TDC
rlai4@lenovo.com
Ph: +886-2-8170-7387
VoIP: 3287387
Mobile:+886-919936126






Some facts about Debian support on our powerpcspe boxes, and msh8920 box, which is a QorIQ e5500 core 64bit PowerPC chip.

(If not identified as e500v2, then the e500 is v1.)

To use the best Debian support on msh8920 box, we had to try the 32 bit release, and either stay on Debian 8, or use unofficial ports for Debian 9.


## Debian support for PPC/PowerPC

- powerpc
  - Official in Debian 7 (Obsolete Stable)
  - Official in Debian 8 (Obsolete Stable)
  - Un-Official in Debian 9 (Stable)
- ppc64el
  - Official in Debian 8 (Old Stable)
  - Official in Debian 9 (Stable)
- ppc64
  - Never Official in Debian, only as unstable/experimental/unreleased ports
- powerpcspe
  - Never Official in Debian, only as unstable/experimental/unreleased ports


### Debian Long Term Support Deadline

Debian 7 to May 2018

Debian 8 to April 2020

Debian 9 to June 2022

### ppc64

The Debian/PowerPC64 (ppc64) port project is active for supporting
Big-endian 64-bit PowerPC CPUs as follows:

```
PowerPC 970/970FX/970MP/970GX, Cell BE and PowerXCell 8i (PPE only),
POWER4/4+, POWER5/5+, POWER6/6+, POWER7/7+, POWER8, POWER9, PowerPC A2,
Xenon, PA6T, PowerPC e5500, PowerPC e6500.
```

## Naming

- ppc_4xx = AMCC 4xx processors without FPU
- ppc_4xxFP = AMCC 4xx processors with FPU (440EP, 440EPx)
- ppc_6xx = PowerPC processors based on 60x cores with FPU
    - This includes support for MPC5xxx, 7xx, 82xx, 83xx and P40xx processors.
- ppc_74xx = 74xx processors
    - This includes support for MPC86xx processors.
- ppc_8xx = MPC8xx processors without FPU
- ppc_85xx = MPC85xx processors (without FPU, but with a SPE)
- ppc_85xxDP = MPC8544 and similar processors using a e500v2 core (without FPU, but with a V.2 SPE); this includes the P10xx and P20xx QorIQ processors, too.
- ppc64 = 64 bit Power Architecture processors with FPU (for example, PA6T)


## QorIQ
The QorIQ P Series processors are based on Power Architecture e500 or e5500 cores.

- P10xx series, P2010 and P2020 on the e500v2 core
- P204x, P30xx and P40xx on the e500mc core
- P50xx on the e5500 core.

QorIQ /ˈkɔːr.aɪ.kjuː/ is a brand of Power Architecture-based communications microprocessors from NXP Semiconductors (formerly Freescale). It is the evolutionary step from the PowerQUICC platform and will be built around one or more Power Architecture e500mc cores and come in five different product platforms, P1, P2, P3, P4 and P5, segmented by performance and functionality. The platform keeps software compatibility with older PowerPC products such as the PowerQUICC platform. In 2012 Freescale announced ARM based QorIQ offerings beginning in 2013.


## P2
- P2010 Includes one 1.2 GHz core
- P2020 Includes two 1.2 GHz cores, with shared L2 cache


## e500v1

- Support for the SPE (Signal Processing Engine) extensions. The integer register file is extended to a width of 64-bits. The non-SPE instructions only access and write to the low 32-bits. However the SIMD SPE instructions read and write from the full 64-bits. These extensions overlap with the string and AltiVec instructions.
- Support for SPESFP (Single Precision Embedded Scalar Floating Point). This is a new floating point unit that is distinct from the classic FPU, the latter of which is lacking in e500v1 and e500v2. SPESFP uses the integer register file. It is not completely IEEE754 compliant.

## e500v2

Key improvements in the e500v2 over the e500v1 include:

- Increase from 32-bit (4 GiB) to 36-bit (64 GiB) physical address space. This change means that e500v2-based devices often use a more advanced board support package (BSP) than e500v1-based devices, as various peripheral units have moved to physical addresses higher than 4 GiB.
- Addition of 1 GiB and 4 GiB variable-page sizes
- Addition of DPESFP (double-precision embedded scalar floating point) support. Building on top of SPESFP, these instructions access both halves of the 64-bit integer register.
- Doubling in size and associativity of the MMU's second-level 4K-page array (from 256-entry 2-way to 512-entry 4-way)
- Increase from 3 to 5 maximum outstanding data cache misses
- Addition of the Alternate Time Base for cycle-granularity timestamps

## e500mc

Freescale introduced the e500mc in the QorIQ family of chips in June 2008. The e500mc has the following features:

- PowerISA v.2.06, which includes hypervisor and virtualization functionality for embedded platforms.
- The "classic" floating-point unit has been reinstated.
- SPE, SPESFP, and DPESFP are all removed, and the integer register file is back to 32 bits.
- Support anything from two to more than 32 cores (not necessarily the same type of cores) on a single chip.
- Supports the CoreNet communications fabric for connecting cores and datapath accelerators.
- e500mc cores have private L2 caches but typically share other facilities like L3 caches, memory controllers, application specific acceleration cores, I/O and such.

## e5500
A 64-bit evolution of the e500mc core is called the e5500 core and was introduced in 2010.


## PowerPC SPE

"PowerPC SPE" refers to the "Signal Processing Engine" hardware present on low-power 32-bit FreeScale and IBM "e500" cores. If you wish to run Debian on a PS3 or other IBM-Cell-based system, you should instead use the standard powerpc port. The "SPE" in the "powerpcspe" architecture does not refer to the "Synergistic Processing Element" units on IBM Cell microprocessors, although both are PowerPC variants. See also http://lists.debian.org/debian-devel/2011/06/msg00592.html


--
Aaron

From: Lin Du
Sent: Tuesday, January 2, 2018 3:08:40 PM
To: Tom Jia
Cc: George Guo; Aaron Shang
Subject: The Kontron stable rootfs support

Tom,
The current rootfs for Kontron PPC64 is a non-stable version.
This should be changed to a stable version from long term.
Please add this task into the list.
Thanks,
Lin







As for the US export control, our boxes should be safe.

We had not used higher level cryptography.

--
Aaron

From: Hai Vo-Dinh
Sent: Friday, December 29, 2017 8:54:47 AM
To: Aaron Shang; Tom Jia; Lin Du; Mikel Tang
Subject: RE: Help with encryption question from Lenovo

Hi Aaron,

I’m not requesting any of these at all.  This is only to respond to questions from Lenovo, a potential OEM customer, having to do with US government requirements for exporting products that uses encryption technology.

We just need to declare if we have apps, tools, libraries, etc… that can perform encryption function for data-in-transit, and data-at-rest.

Thanks,
Hai

From: Aaron Shang
Sent: Thursday, December 28, 2017 4:49 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>; Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Subject: Re: Help with encryption question from Lenovo


The notion "data at rest” may be infinite for a system.

For, password, currently that is salted MD5 hashes. Advanced algorithms had been available, but need additional libraries, utilities, PAM modules, etc.

Currently the Linux drives and volumes were not encrypted.

If we are requested to do that, much efforts should be planned.
For drive encryption, a boot time passwd is needed, the boot progress would be affected a log.
For volume encryption, the mount time passwd is challenged. User land utility is easy to deploy. Operations of that in our apps might be added if the encrypted volume is needed during I/O.

Passwd algorithm change needs corresponding utilities or libs, such as bluefish, SHA512, etc.
For drive encryption, media and bios/boot-loader support is needed.
For volume encryption, the most usually used is ecryptfs-mount-private by ecryptfs-utils. There are also other inferior solutions available.

--
Aaron

From: Hai Vo-Dinh
Sent: Thursday, December 28, 2017 4:41:54 PM
To: Aaron Shang; Tom Jia; Lin Du; Mikel Tang
Subject: RE: Help with encryption question from Lenovo

Hi Aaron,

Would you please also tell me if we do also encryption of “data at rest” (password, credentials, linux drive/volume)? If we do, which package does that.

Thank you,
Hai

From: Hai Vo-Dinh
Sent: Thursday, December 28, 2017 12:37 AM
To: Aaron Shang <aaron.shang@pica8.com>; Tom Jia <tom.jia@pica8.com>; Lin Du <lin.du@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Subject: RE: Help with encryption question from Lenovo

Aaron,

Thank you very much for your help.

Hai

From: Aaron Shang
Sent: Thursday, December 28, 2017 12:32 AM
To: Tom Jia <tom.jia@pica8.com>; Hai Vo-Dinh <hai.vodinh@pica8.com>; Lin Du <lin.du@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Subject: Re: Help with encryption question from Lenovo


Yes, we support SCP and SFTP via included openssh.

We do not support FTPS, which is a rarely used file service now and needs many special configurations.

All algorithms used in openssh had been standard, not proprietary.

Please be noted, that the box can be connected via `telnet` which was requested by many legacy users as legacy router/switch feature.
The transit over telnet is not encrypted. That would be plain text, and can be sniffed.

And, another possible weakness is the web access. If users would to manage via the web page, it is by default HTTP, not HTTPS.
However, HTTP is also vulnerable for transfer, only base64 conversion is used, which can be easily decoded if attackers sniffed that.



--
Aaron

From: Tom Jia
Sent: Thursday, December 28, 2017 3:34:45 PM
To: Hai Vo-Dinh; Lin Du; Mikel Tang; Aaron Shang
Subject: Re: Help with encryption question from Lenovo

Hello Mikel, Aaron,

Could you please help answer Hai's question?

Thanks.

Best regards,
Tom Jia (贾彦民)



From: Hai Vo-Dinh
Sent: Thursday, December 28, 2017 3:10 PM
To: Lin Du; Tom Jia
Subject: RE: Help with encryption question from Lenovo

Hi Lin, Tom,

Do we support SCP, FTPS, SFTP?

Thanks,
Hai

From: Hai Vo-Dinh
Sent: Wednesday, December 27, 2017 10:44 PM
To: Lin Du <lin.du@pica8.com>; Tom Jia <tom.jia@pica8.com>
Subject: Help with encryption question from Lenovo

Hi Lin, Tom,

I would appreciate your help in answering the urgent questions relating to encryption below from Lenovo:

Do you encrypt “data in Transit”” or passwords and credentials?
Hai: We do encrypt “data in Transit” for openssh session, do we encrypt “data in transit” for any other application?
Would you please confirm that we also encrypt passwords and other credentials.

What encryption algorithms are used beyond what you describe with respect to Linux? Standard or proprietary?
Hai: Does the system perform any other encryption function other than openssh?

Thank you,
Hai









Hi, Hai,

The following are algorithms used for SSH on our boxes.

# cipher-auth
aes128-gcm@openssh.com
aes256-gcm@openssh.com
chacha20-poly1305@openssh.com
# cipher
3des-cbc
blowfish-cbc
cast128-cbc
arcfour
arcfour128
arcfour256
aes128-cbc
aes192-cbc
aes256-cbc
rijndael-cbc@lysator.liu.se
aes128-ctr
aes192-ctr
aes256-ctr
aes128-gcm@openssh.com
aes256-gcm@openssh.com
chacha20-poly1305@openssh.com

# kex
curve25519-sha256@libssh.org
ecdh-sha2-nistp256
ecdh-sha2-nistp384
ecdh-sha2-nistp521
diffie-hellman-group-exchange-sha256
diffie-hellman-group-exchange-sha1
diffie-hellman-group14-sha1

# key
ssh-ed25519
ssh-ed25519-cert-v01@openssh.com
ssh-rsa
ssh-dss
ecdsa-sha2-nistp256
ecdsa-sha2-nistp384
ecdsa-sha2-nistp521
ssh-rsa-cert-v01@openssh.com
ssh-dss-cert-v01@openssh.com
ecdsa-sha2-nistp256-cert-v01@openssh.com
ecdsa-sha2-nistp384-cert-v01@openssh.com
ecdsa-sha2-nistp521-cert-v01@openssh.com

# key-plain
ssh-ed25519
ssh-rsa
ssh-dss
ecdsa-sha2-nistp256
ecdsa-sha2-nistp384
ecdsa-sha2-nistp521

# key-cert
ssh-ed25519-cert-v01@openssh.com
ssh-rsa-cert-v01@openssh.com
ssh-dss-cert-v01@openssh.com
ecdsa-sha2-nistp256-cert-v01@openssh.com
ecdsa-sha2-nistp384-cert-v01@openssh.com
ecdsa-sha2-nistp521-cert-v01@openssh.com

# mac
hmac-sha1
hmac-sha1-96
hmac-sha2-256
hmac-sha2-512
hmac-md5
hmac-md5-96
hmac-ripemd160
hmac-ripemd160@openssh.com
umac-64@openssh.com
umac-128@openssh.com
hmac-sha1-etm@openssh.com
hmac-sha1-96-etm@openssh.com
hmac-sha2-256-etm@openssh.com
hmac-sha2-512-etm@openssh.com
hmac-md5-etm@openssh.com
hmac-md5-96-etm@openssh.com
hmac-ripemd160-etm@openssh.com
umac-64-etm@openssh.com
umac-128-etm@openssh.com

--
Aaron

From: Hai Vo-Dinh
Sent: Monday, January 22, 2018 1:53:14 PM
To: Aaron Shang
Subject: Ssh encryption algorithm

Hi Aaron,
Lenovo is asking for the specific algorithm(s) we are using for ssh, and secure file transfer protocol. Would you please let me know?
Thanks,
Hai





Hi, all,
Let's review and have comments for that.


# Branch naming

## Next stage branch naming
During the process towards 3.0, I suggest the following branch naming arrangements.

- Use 3-dev as main baseline,
    - Merging current `master-system-vrf`, refering `master-system-3.0`

- Use `2.11-` or possible future release prefix for baseline not applicable as 3.x

- If no further commits to 2.x branches, lock `master` for couple of weeks (~10), then use `master` for future main baseline.

## Special naming rules
- To comply with Debian package build naming rules
    - Start with a digit
    - Contains no underscore.
- Better include the referred issue number in naming
    - Such as 2.11-ovs-bug6789, 3.0-vrf-iproute2



# Git workflow
There are lots of conflicts during our merging into baseline in the past several months.

Here is the best practice for co-working workflow.
- `merge` only happens onto baseline, such as master, or release branches such as 2.11.0, 2.10.1-hotfix.
- To sync from baseline, use `git rebase baseline`, not `git merge`
    - On working branch, do `git rebase master` or `git rebase 2-dev`, or `git rebase 2.11-maint`, etc.
    - To merge commits into baseline, do `git merge some-branch` on `baseline` branch
- To sync working branch with co-workers, use `git pull --rebase`, instead of `git pull`.



--
Aaron






In the previous steps, `ar` extracted the data.tar.xz, then `tar` extracted that contents into `usr/` / ` etc/` under current working dir. You can check that `usr/bin/openssl`.
(Without the leading slash `/`, because we are working for a ppc binary in current dir)

Then from P5101, do a `scp -r` using root user like this:
    scp -r your-name@your-linux-pc:/path/to/the-working-dir/usr /
    scp -r your-name@your-linux-pc:/path/to/the-working-dir/etc /



That should help, please have a try.



--
Aaron

From: 陈庄洋 <chenzhuangyang@zettakit.com>
Sent: Friday, January 19, 2018 5:49:51 PM
To: Aaron Shang; support@pica8.com
Subject: Re: P-5101 install openssl

Hi Aaron,

1.
    There is no openssl in the /usr/bin/ folder

2.
    The output of echo $PATH
    /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/ovs/bin:/ovs/sbin:/pica/bin:/ovs/snmp/bin:/ovs/snmp/sbin

BR,

ZHUANGYANG


------------------ Original ------------------
From:  "Aaron Shang"<aaron.shang@pica8.com>;
Date:  Fri, Jan 19, 2018 05:42 PM
To:  "陈庄洋"<chenzhuangyang@zettakit.com>; "support@pica8.com"<support@pica8.com>;
Subject:  Re: P-5101 install openssl

Hi, Zhuangyang,

It seemed the openssl was still not at the proper location.

To make sure the openssl had been copied there, can you show the results of the following command?:

1.
    which openssl

If OK, it should show:

/usr/bin/openssl

2.
     echo $PATH

If OK, the above path `/usr/bin` should be in the result.

Please have a check, using the same user you run OVS commands, I guess that should be root user.


--
Aaron

From: 陈庄洋 <chenzhuangyang@zettakit.com>
Sent: Friday, January 19, 2018 5:19:59 PM
To: support@pica8.com
Subject: P-5101 install openssl

Hi,

I use P-5101, a PowerPCspe CPU device. And it meets the requirement "Trident-II Series switch"

I want to connection P-5101 with OpenDaylight controller, then could use Open vSwitch Database management protocol to deploy and manage VXLANs on VTEPs.

I follow the OVSDB configuration guide[1], and failed to install openssl.

Under Aaron's help, I did these steps.

1. verified two deb file DID store in /var/cache/apt/archives

2. copy two deb files to another Linux device via scp

3. ar x libssl1.1_1.1.0g-2_powerpcspe.deb


4. tar Jvxf data.tar.xz

5. ar x openssl_1.1.0g-2_powerpcspe.deb

6. tar Jvxf data.tar.xz

7. copy two new generated folder(/usr, /etc) from Linux device to P-5101 via scp

However, I failed in "ovs-pki init --force" and "ovs-pki req+sign pica8". The ovs-pki.log indicates:

/ovs/bin/ovs-pki: 302: /ovs/bin/ovs-pki: openssl: not found
/ovs/bin/ovs-pki: 448: /ovs/bin/ovs-pki: openssl: not found

Moreover, when I tried "sudo apt-get install openssl", the display is:

WARNING: The following packages cannot be authenticated!
  libssl1.1 openssl
Authentication warning overridden.
E: /var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb not a valid DEB package.
E: Prior errors apply to /var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb
E: Prior errors apply to /var/cache/apt/archives/openssl_1.1.0g-2_powerpcspe.deb
debconf: apt-extracttemplates failed: No such file or directory
dpkg-deb: error: archive '/var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb' contains not understood data member control.tar.xz, giving up
dpkg: error processing /var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb (--unpack):
subprocess dpkg-deb --control returned error exit status 2
dpkg-deb: error: archive '/var/cache/apt/archives/openssl_1.1.0g-2_powerpcspe.deb' contains not understood data member control.tar.xz, giving up
dpkg: error processing /var/cache/apt/archives/openssl_1.1.0g-2_powerpcspe.deb (--unpack):
subprocess dpkg-deb --control returned error exit status 2
Errors were encountered while processing:
/var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb
/var/cache/apt/archives/openssl_1.1.0g-2_powerpcspe.deb
E: Sub-process /usr/bin/dpkg returned an error code (1)

How cloud I solve this?

BR,

ZHUANGYANG

[1]. http://www.pica8.com/wp-content/uploads/2015/09/v2.9/html/picos-routing-and-switching-configuration-guide/#8194744






Hi, Zhuangyang,


You'd better send/reply questions to support mailbox
support@pica8.com

By that way, you would get more quickly reply because that is connected to our Knowledge Base system where history records of similar question/answers had been constructed.

Also, more guys with various expertise such as OVS or OFCONFIG can reply there, thus make answers much timely.


Thanks.


--
Aaron

From: Aaron Shang
Sent: Thursday, January 18, 2018 12:51:45 PM
To: Lin Du; 陈庄洋; support@pica8.com
Subject: Re: Install openssl on Pica8 device

Hi,

We had no available P5101 with 2.9 release now.

But you can try the following means.

Make sure the following lines are into /etc/apt/sources.list
```
deb http://ftp.de.debian.org/debian-ports/ sid main
deb http://ftp.de.debian.org/debian-ports/ unstable main
deb http://ftp.de.debian.org/debian-ports/ unreleased main
```

Then

    apt-get update

Then query whether the package is available or not:

    apt-cache search openssl|grep openssl

Then install using

    apt-get install openssl


Usually that would work, then you can stop here.

----

When I was trying on another powerpcspe box, I failed because currently the upstream ( apt sources)  had been using the XZ compressing for packaging.
While the system only support GZ decompressing. We had no means to upgrade the underlying system now.

A manual install did not help.

````
dpkg -i /var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb
dpkg-deb: error: archive '/var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb' contains not understood data member control.tar.xz, giving up
dpkg: error processing /var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb (--install):
 subprocess dpkg-deb --control returned error exit status 2
Errors were encountered while processing:
 /var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb
````


But you can try following my steps.

Copy the two fetched deb files to other Linux systems (a PC named `shang` hereafter,) that have `ar` command.

scp /var/cache/apt/archives/libssl1.1_1.1.0g-2_powerpcspe.deb /var/cache/apt/archives/openssl_1.1.0g-2_powerpcspe.deb aaron@shang:work/

Then on the Linux system, say, working on empty dir `/home/aaron/work/`


  ar x libssl1.1_1.1.0g-2_powerpcspe.deb

  tar Jvxf data.tar.xz

  ar x openssl_1.1.0g-2_powerpcspe.deb

  tar Jvxf data.tar.xz


Then go back onto P5101:

scp -r aaron@shang:work/usr/ /usr/
scp -r aaron@shang:work/etc/ /etc/

That worked for me on another ppc box. Really hope you can also success so.

But I am not sure whether that would impact other upper level app.


Please let me know if you meet issues.



You can also add me on WeChat, searching for id `aaronshang`, so we can work out using Voice, or paste more command line trouble shootings.





--
Aaron

From: Lin Du
Sent: Thursday, January 18, 2018 11:17:44 AM
To: 陈庄洋; support@pica8.com
Cc: Aaron Shang
Subject: RE: Install openssl on Pica8 device

Zhuangyang,
Aaron will take a look of your issue.

Aaron,
Please check the failure reason on 2.9.

Thanks,
Lin

From: 陈庄洋 [mailto:chenzhuangyang@zettakit.com]
Sent: Thursday, January 18, 2018 11:06 AM
To: support@pica8.com
Subject: Install openssl on Pica8 device

Hi

I follow the OVSDB vTep configuration guide[1] setup the P-5101.

And I need to Install openssl on P-5101.

Then I noticed "apt-get" does not work with the system version 2.9.

Any solution? Or I could install openssl from other available 3rd party apt repo.

BR,
ZHUANGYANG

[1].http://www.pica8.com/wp-content/uploads/2015/09/v2.9/html/picos-routing-and-switching-configuration-guide/#8194744




Just fyi.

More and more customers would require to install 3rd party packages.

So in the future, a standard maintainable Debian base is a must to meet these kinds of requests.



--
Aaron


From: Zoneson Chen
Sent: Tuesday, December 26, 2017 10:46
To: Lin Du; Hai Vo-Dinh; plm@pica8.com
Cc: support@pica8.com
Subject: Re: <PLM help>Re: [Ticket#2017113065000047] FW: Pica 8 ToR update servers

Lin and Hai,

Thank you for your replies!

PicOS does not include OpenSSL. It is the reason why Adtran needs to install it. Due to missing OpenSSL, they are unable to build SSL connection to Controller. Even though there are no repositories supporting OpenSSL on the current PPC rootfs, we should build one for those customers who need the secured connection to Controller.

Here are the answers to Hai’s questions:

- Does adtran have active support contract?  If they do, why do they need to get packages from the open source community?
<zc> No.
- Even if they have active support contrac, do we even support customers loading any packages they desire on to the switch? I think we do since it’s linux, but do we have to be involved? i.e. do we need to actively support these activities?  Do we need to be responsible for making sure that this would work when they do?  I’m not sure.  I think our position should be that they are welcome to do it, but they can’t expect us to help when they run into trouble.
<zc> OpenSSL is an exception from other packages.
- If the issue is they need to update to a particular version of the OpenSSL package, I’m not sure that we would support them updating the package on their own, since there may be dependencies issues with the new version.
 <zc> Adtran only asks for a version of OpenSSL working.

Thanks,

Zoneson

From: Lin Du <lin.du@pica8.com>
Date: Sunday, December 24, 2017 at 5:27 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, "plm@pica8.com" <plm@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: RE: <PLM help>Re: [Ticket#2017113065000047] FW: Pica 8 ToR update servers

Hai, Zoneson,
The current rootfs for PPC SPE is based on a non-stable branch of the Debian release, which is not maintained accordingly. All other platforms are based on stable versions.
In 3.0 branch, the non-stable rootfs are upgraded Debian 8.0 or 7.0, so users can do installation without limitation.
Thanks,
Lin

From: Hai Vo-Dinh
Sent: Sunday, December 24, 2017 2:53 PM
To: Zoneson Chen; plm@pica8.com
Cc: support@pica8.com
Subject: Re: <PLM help>Re: [Ticket#2017113065000047] FW: Pica 8 ToR update servers

Hi Zoneson,

I’m not sure why the customer would need to install OpenSSL: I believe that PICOS already have OpenSSL library installed, as we use ssh to access the switches, and ssh uses the OpenSSL library.  Also, Cloudistics raised a security vulnerability with OpenSSL so I’m pretty sure that the OpenSSL package is already part of our debian linux distribution.

My other question is regarding our support policies:
- Does adtran have active support contract?  If they do, why do they need to get packages from the open source community?
- Even if they have active support contrac, do we even support customers loading any packages they desire on to the switch? I think we do since it’s linux, but do we have to be involved? i.e. do we need to actively support these activities?  Do we need to be responsible for making sure that this would work when they do?  I’m not sure.  I think our position should be that they are welcome to do it, but they can’t expect us to help when they run into trouble.
- If the issue is they need to update to a particular version of the OpenSSL package, I’m not sure that we would support them updating the package on their own, since there may be dependencies issues with the new version.

Thanks,
Hai

--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
M: +1.408.389.9422
hai.vodinh@pica8.com
www.pica8.com



From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Friday, December 22, 2017 at 4:27 PM
To: "plm@pica8.com" <plm@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: <PLM help>Re: [Ticket#2017113065000047] FW: Pica 8 ToR update servers

Mikel,

Thank you for your helps!

Dear PLM team,

Is it a major problem? If customer is not able to install OpenSSL, they are unable to create an SSL connection with the controller. In this case, we should build the OpenSSL for customers who has the needs.

Thanks,

Zoneson


From: Mikel Tang <mikel.tang@pica8.com>
Date: Thursday, December 21, 2017 at 11:36 PM
To: PICA8 Support <otrs.support@pica8.com>, "THOMAS.WOOD@adtran.com" <THOMAS.WOOD@adtran.com>
Cc: "jeff.wells@adtran.com" <jeff.wells@adtran.com>, "THOM.ROSE@adtran.com" <THOM.ROSE@adtran.com>, "support@pica8.com" <support@pica8.com>
Subject: RE: [Ticket#2017113065000047] FW: Pica 8 ToR update servers

Hi THOMAS

I am sorry to inform you that there is no PicOS new version to support the update of this OpenSSL.

As for update sources, you can use the official one.
     deb http://ftp.de.debian.org/debian-ports/ sid main

Since the CPU of the P5101 is powerpcspe, as powerpcspe is not supported by Debian official any more, the `sid` only source won't work.
The reason is that current `deb` packaging is using `xz`, while it is not supported on `wheezy` systems.

Thanks
Mikel Tang
Pica8, Inc.
mikel.tang@pica8.com  |  www.pica8.com

From: PICA8 Support
Sent: Friday, December 22, 2017 2:11 PM
To: THOMAS.WOOD@adtran.com
Cc: jeff.wells@adtran.com; THOM.ROSE@adtran.com; support@pica8.com
Subject: Re: [Ticket#2017113065000047] FW: Pica 8 ToR update servers

Hi THOMAS,

I am really sorry that I miss your requests since your replies do not reach me! Please add support@pica8.com in order to reach my email address. We will correct this setting in order to resolve this problem in the future.

I will check whether the newer PicOS versions have the update server which supports openssl.

Thanks,

Zoneson



PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

12/07/2017 18:29 - THOMAS WOOD wrote:
Good afternoon, Zoneson,

I was wondering if you had any updates on the Pica 8 update servers. We're still unable to install new packages or update our top of rack switches.

Thanks,

Tom Wood
 Co-op


Office: 256.963.6240
Mobile: 256.783.6091
Email: thomas.wood@adtran.com
Web: www.adtran.com

ADTRAN
901 Explorer Boulevard
Huntsville, AL 35806 – USA

From: THOMAS WOOD
Sent: Thursday, November 30, 2017 1:50 PM
To: Zoneson Chen
Subject: RE: [Ticket#2017113065000047] Pica 8 ToR update servers


Thank you for the quick response, Zoneson,

Here is the information on the Pica8 I'm using:

admin@PicOS-OVS$version
Copyright (C) 2009-2016 Pica8, Inc.
===================================
Hardware Model                : P5101
Linux System Version/Revision : 2.7.2/7977d40
Linux System Released Date    : 07/06/2016
L2/L3 Version/Revision        : 2.7.2/7977d40
L2/L3 Released Date           : 07/06/2016
OVS/OF Version/Revision       : 2.7.2/7977d40
OVS/OF Released Date          : 07/06/2016


Tom Wood
 Co-op


Office: 256.963.6240
Mobile: 256.783.6091
Email: thomas.wood@adtran.com
Web: www.adtran.com

ADTRAN
901 Explorer Boulevard
Huntsville, AL 35806 – USA

From: Zoneson Chen [otrs.support@pica8.com]
Sent: Thursday, November 30, 2017 1:26 PM
To: THOMAS WOOD
Cc: support@pica8.com
Subject: Re: [Ticket#2017113065000047] Pica 8 ToR update servers


Hi THOMAS,

Would you mind providing us the hardware model and PicOS version of the switch? I am sorry that the maintainer of antcom.de stops supporting the following repository :
deb http://www.antcom.de/powerpcspe/ unstable main

Thanks,

Zoneson


PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

11/30/2017 16:46 - THOMAS WOOD wrote:
Good morning,

I'm reaching out because I'm unable to update my Pica 8 or install openssl. In the past, we've used the following servers in the past (/etc/apt/sources.list)

deb http://ftp.de.debian.org/debian-ports/ sid main
deb http://www.antcom.de/powerpcspe/ unstable main

However, the antcom.de is no longer in service and I wondering if you had any suggested servers that would be acceptable to use in its place?

Thanks,


Tom Wood
 Co-op


Office: 256.963.6240
Mobile: 256.783.6091
Email: thomas.wood@adtran.com
Web: www.adtran.com

ADTRAN
901 Explorer Boulevard
Huntsville, AL 35806 – USA






At the time being, systemd should be the best in terms of boot up timing, modular services, and ease of operations.


As for the mentioned `unity`, it's only released by Ubuntu for many versions.
Ubuntu occupies at the best about 1/3 of Linux share, there are choices like Debian, Red Hat, Centos, Fedora, SuSE, and Gentoo.
Unity is only shipped on Desktop releases, while most Linux share are of servers.
So the death of unity can not be compared to systemd, which is to be almost 100% for servers, desktops, nextbooks, and increasing embedded systems and handheld devices.

BTW, I had been using Ubuntu for years almost all day long, but the first thing I start a new installation is to remove that ugly unity. ;)


Sure we have much to do on the change. We had upgraded the scripts, the startup service restructuring.
We need more work on documentation and customer communication. Actually most of the changes are not facing end users.

--
Aaron

From: Sharad Ahlawat
Sent: Friday, December 15, 2017 9:24:54 AM
To: Aaron Shang; George Guo
Cc: Lin Du; Tom Jia; Richard Zhang; Jacob Wang; Vic Lan; Barton Song
Subject: Re: another article in support of Devuan

Interesting read :)

I don't believe any technology/solution is better or worse and I have no technology religion, but for a given requirement there is always one best fit.

So as a NOS vendor what do we care about:

Boot up time - we will always have slow CPUs
Memory utilization - we will always have less memory than average desktops
Minimal services - we do not need any unnecessary plug and play features, increasing the feature set will lead to more maintenance patching and testing
Modular services - resetting or restarting a service should not require restarting half the services on the switch
Ease of operations - PICOS should not require Linux Gurus to operate or support our switches

Please add more to this list ...

For the above criteria, the sysvinit system seems to be a better fit.

Another business concern is the cost of moving to a new init system. The cost involves engineers going through the systemd learning curve, upgrading test scripts, documentation, customer communication, managing disruptions with partner integrations, and integrating our NOS services into a new model. We may eventually have to incur this cost if systemd does not die like unity, but at this time we have many more critical features required for business continuity; if there is no business then all this does not matter :)

--
/Sharad


From: Aaron Shang <aaron.shang@pica8.com>
Date: Thursday, December 14, 2017 at 01:00
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, George Guo <george.guo@pica8.com>
Cc: Lin Du <lin.du@pica8.com>, Tom Jia <tom.jia@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Jacob Wang <jacob.wang@pica8.com>, Vic Lan <vic.lan@pica8.com>, Barton Song <barton.song@pica8.com>
Subject: Re: another article in support of Devuan


Of course systemd had initiated the epic war.


## Cons of systemd

- It breaks the Unix philosophy of `Make each program do one thing well`, or KISS principle.
  - It is overly complex, and tries to dominate everything.
  - Oh, there is also lots of Unix philosophies. Although most were great.

- It has lots of features, and integrates lots of components
  - journald for event logging,
  - logind for user logins,
  - networkd for configuration of network interfaces
    - Oh, it even supports VXLAN natively. Really necessary there? Perhaps not bad.
  - tmpfiles for creation and clean-up of temporary files and directories,
  - timedated for time-related settings, such as the system time, system time zone
  - udevd for /dev directory and all user space actions when adding/removing devices, including firmware loading
    - picos can not work without udev now.

- It breaks Unix philosophy that everything is file, introducing many binary files such as logfiles.

- And lots more critics...


## Situation

Systemd had been complex, error-prone, and unstable. Now it is still complex, but not so error-prone, not so unstable.

During the post 7 years, systemd had been actively evolving, and became the init system de facto.

Despite all the quarrels, it had been becoming solid, efficient, and somewhat, beautiful.

Now almost all main Linux distros (Perhaps targeted at 99% users) had been using systemd as default init now.

We can tune our product not using it in favor of sysvinit, but in the near future it is expected the annoyances maintaining that.

Actually, you can not log in default Debian desktop release without systemd, because its Gnome login relies on systemd. (Nowadays much more users tend not to choose Gnome.)

There might be no solid reason not to choose systemd, or choose sysvinit.



Among all the init systems I had managed, to name a few, sysvinit, init-ng, Upstart, OpenRC, even daemontools, `systemd` is the best ever.

KISS or `Do one thing only and do it well` philosophy is good, but a benevolent dictator for system or an entry point to trouble shooting the system is not bad as well.


Lets quote a comment on this holy flame war. (Oh, obviously there seems a winner this time.)

https://linux.slashdot.org/comments.pl?sid=11463149&cid=55714431
Does Systemd Makes Linux Complex, Error-Prone, and Unstable? - Slashdot
linux.slashdot.org
Systemd is nothing but a thinly-veiled plot by Vladimir Putin and Beyonce to import illegal German Nazi immigrants over the border from Mexico who will then corner the market in kimchi and implement Sharia law!!!

FYI, the dungeon of systemd.




--
Aaron

From: Sharad Ahlawat
Sent: Monday, December 11, 2017 2:03:01 PM
To: Aaron Shang; George Guo
Cc: Lin Du; Tom Jia
Subject: another article in support of Devuan

https://blog.ungleich.ch/en-us/cms/blog/2017/12/10/the-importance-of-devuan/

and its /. comments - https://linux.slashdot.org/story/17/12/11/0049245/does-systemd-makes-linux-complex-error-prone-and-unstable

but we are better off using Debian and replacing systemd with sysvinit

--
/Sharad






Of course systemd had initiated the epic war.


## Cons of systemd

- It breaks the Unix philosophy of `Make each program do one thing well`, or KISS principle.
  - It is overly complex, and tries to dominate everything.
  - Oh, there is also lots of Unix philosophies. Although most were great.

- It has lots of features, and integrates lots of components
  - journald for event logging,
  - logind for user logins,
  - networkd for configuration of network interfaces
    - Oh, it even supports VXLAN natively. Really necessary there? Perhaps not bad.
  - tmpfiles for creation and clean-up of temporary files and directories,
  - timedated for time-related settings, such as the system time, system time zone
  - udevd for /dev directory and all user space actions when adding/removing devices, including firmware loading
    - picos can not work without udev now.

- It breaks Unix philosophy that everything is file, introducing many binary files such as logfiles.

- And lots more critics...


## Situation

Systemd had been complex, error-prone, and unstable. Now it is still complex, but not so error-prone, not so unstable.

During the post 7 years, systemd had been actively evolving, and became the init system de facto.

Despite all the quarrels, it had been becoming solid, efficient, and somewhat, beautiful.

Now almost all main Linux distros (Perhaps targeted at 99% users) had been using systemd as default init now.

We can tune our product not using it in favor of sysvinit, but in the near future it is expected the annoyances maintaining that.

Actually, you can not log in default Debian desktop release without systemd, because its Gnome login relies on systemd. (Nowadays much more users tend not to choose Gnome.)

There might be no solid reason not to choose systemd, or choose sysvinit.



Among all the init systems I had managed, to name a few, sysvinit, init-ng, Upstart, OpenRC, even daemontools, `systemd` is the best ever.

KISS or `Do one thing only and do it well` philosophy is good, but a benevolent dictator for system or an entry point to trouble shooting the system is not bad as well.


Lets quote a comment on this holy flame war. (Oh, obviously there seems a winner this time.)

https://linux.slashdot.org/comments.pl?sid=11463149&cid=55714431
Does Systemd Makes Linux Complex, Error-Prone, and Unstable? - Slashdot
linux.slashdot.org
Systemd is nothing but a thinly-veiled plot by Vladimir Putin and Beyonce to import illegal German Nazi immigrants over the border from Mexico who will then corner the market in kimchi and implement Sharia law!!!

FYI, the dungeon of systemd.




--
Aaron

From: Sharad Ahlawat
Sent: Monday, December 11, 2017 2:03:01 PM
To: Aaron Shang; George Guo
Cc: Lin Du; Tom Jia
Subject: another article in support of Devuan

https://blog.ungleich.ch/en-us/cms/blog/2017/12/10/the-importance-of-devuan/

and its /. comments - https://linux.slashdot.org/story/17/12/11/0049245/does-systemd-makes-linux-complex-error-prone-and-unstable

but we are better off using Debian and replacing systemd with sysvinit

--
/Sharad







Hi, Hai,

I had created the tar ball file at:
http://dev/src/picos-rootfs-src.tar

http://dev/src/

--
Aaron

From: Hai Vo-Dinh
Sent: Wednesday, December 13, 2017 4:31:57 PM
To: Zoneson Chen; Aaron Shang
Cc: Lin Du; Tom Jia; George Guo; Richard Zhang; Jacob Wang; Vic Lan; Barton Song
Subject: Re: Pica8 OSA

Hi Aaron,
Please make a tar of the debian Linux source code.  We have to make that available instead of the binaries.
Thanks,
Hai
From: Aaron Shang
Sent: Tuesday, December 12, 7:12 PM
Subject: Re: Pica8 OSA
To: Hai Vo-Dinh, Zoneson Chen
Cc: Lin Du, Tom Jia, George Guo, Richard Zhang, Jacob Wang, Vic Lan, Barton Song


Hi, Hai,
Yes, current product was built using binaries of Debian release, not from directly from its source code.
If we want, we can make a tar of them.
You can get the package list on boxes using command `dpkg -l`.
We can collect src files of these packages using a script from Debian server.
examples:
https://packages.debian.org/stable/libs/libcurl3
https://packages.debian.org/stable/admin/apt
https://packages.debian.org/stable/net/nftables

Actually, we maintained a local mirror for them, so the collecting can be done instantly if we need.


In next major releases, we planned to build from src to achieve easy maintenance of the ROOTFS.
Usually only one time building is needed for one major release build.


--
Aaron
From: Hai Vo-Dinh
Sent: Monday, December 11, 2017 2:27:26 PM
To: Aaron Shang; Zoneson Chen
Cc: Lin Du; Tom Jia
Subject: RE: Pica8 OSA

Hi Aaron,

You mean that our product is built using binaries of a Debian release ROOTFS, not the source code of that?  Could we make a tar of the source code of that binaries, if we wanted to?

Thanks,
Hai

From: Aaron Shang
Sent: Sunday, December 10, 2017 8:41 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>
Cc: Lin Du <lin.du@pica8.com>; Tom Jia <tom.jia@pica8.com>
Subject: Re: Pica8 OSA


Hi, Hai,

I made a tar ball from the rootfs for boxes that stordis releases were used.

http://dev/src/


Please help find a proper web portal path for that, if you guys think that OK.



But as you can see that tar ball contains only the binaries of a Debian release ROOTFS, which our product had been based on.

The source code means only exist as Debian upstream sources where the Debian releases were built on.

Such as binaries from:
https://packages.debian.org/stable/

And sources from:
https://packages.debian.org/source/wheezy/




I also put a tar ball from our building of the rootfs, kernel, and images.
But I doubt that is what was expected.





--
Aaron
From: Hai Vo-Dinh
Sent: Sunday, December 10, 2017 5:33:37 AM
To: Aaron Shang; Zoneson Chen
Cc: Lin Du; Tom Jia
Subject: FW: Pica8 OSA

Hi Aaron,

Would you please also create a tar ball, similar to the others for the debbian linux distribution and make it available to Zoneson?

Zoneson,
Would you please post it, once available, same as for the other open source software.

Thanks,
Hai



From: Waldemar Scheck [mailto:Waldemar.Scheck@stordis.com]
Sent: Friday, December 8, 2017 11:12 AM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Fwd: Pica8 OSA

....I see them on Monday. Would be gread if that could be done today.
Viele Grüße / Best regards,
Waldemar Scheck

Von meinem iPhone gesendet
Anfang der weitergeleiteten E Mail:
Von: <Lars.Waechtler@rohde-schwarz.com>
Datum: 8. Dezember 2017 um 15:10:25 MEZ
An: <hai.vodinh@pica8.com>
Kopie: Harsha Vardhan <harsha.vardhan@stordis.com>, Joe Digiovanni <joe.Digiovanni@pica8.com>, Waldemar Scheck <waldemar.scheck@stordis.com>
Betreff: Re: Pica8 OSA
Hi Hai,
unfortunately this is what we also need. To fulfill the requirements of the licenses, especially the GPL ones, you and also we have to deliver the whole source code of open source software what we distribute, independent if you or we sell it or not. In the worst case we loos the right to use this software or we have to pay a huge contract penalty to the copyright holder which is each individual developer who has committed some thing into the software. For some individuals this is a new business model. They had committed some lines to the Linux kernel or other GPL tools and now they bring companies to court and reap money form this companies.
I'm sorry but I have to request this source code from you since you are distributing it.

Mit freundlichen Grüßen / Kind Regards
Lars Waechtler
----
Lars Waechtler
R&D
R&S Cybersecurity ipoque GmbH
Augustusplatz 9, D-04109 Leipzig
Phone: + 49 341 59403 140
Email: lars.waechtler@rohde-schwarz.com
Internet: www.ipoque.com
Trade register Amtsgericht Leipzig HRB21462
Gesellschaft mit beschränkter Haftung (GmbH)
Dirk Czepluch - Managing Director


From:        Hai Vo-Dinh <hai.vodinh@pica8.com>
To:        Joe Digiovanni <joe.Digiovanni@pica8.com>, Waldemar Scheck <waldemar.scheck@stordis.com>, Harsha Vardhan <harsha.vardhan@stordis.com>, "lars.waechtler@rohde-schwarz.com" <lars.waechtler@rohde-schwarz.com>
Date:        07.12.2017 18:31
Subject:        Re: Pica8 OSA


Hi Lars,
That is not available currently.  We can look to make that available also.  Let me check with our team.
Best regards,
Hai
From: Lars.Waechtler@rohde-schwarz.com <Lars.Waechtler@rohde-schwarz.com>
Sent: Thursday, December 7, 2017 4:59:03 AM
To: Hai Vo-Dinh; Joe Digiovanni; Waldemar Scheck; Harsha Vardhan
Subject: Pica8 OSA

Dear Gentleman,
thank you for the call from Tuesday. Today I had the chance to look into your protal to obtain the open source components and I'm not sure if I have access to the whole archive but I just see the following packages:
libnetconf
pam_radius
pam_tacplus
What I also expect to see are the sources form the underlying Linux system. Do I just haven't the right access rights or didn't you provide this packages?
Mit freundlichen Grüßen / Kind Regards
Lars Waechtler
----
Lars Waechtler
R&D
R&S Cybersecurity ipoque GmbH
Augustusplatz 9, D-04109 Leipzig
Phone: + 49 341 59403 140
Email: lars.waechtler@rohde-schwarz.com
Internet: www.ipoque.com
Trade register Amtsgericht Leipzig HRB21462
Gesellschaft mit beschränkter Haftung (GmbH)
Dirk Czepluch - Managing Director







昵称为dev的机器陆续出现了些问题,现在说明一下情况.从简单到复杂.
首先是邮件系统下午出现能发不能收状况, Richard在6点左右重启后恢复正常,
原因不明, 猜测是排队组件出现过问题.
另一个问题是DNS解析故障. 经dig排查,目前DNS系统内网解析正常, 但出外网解析
53端口被拒绝,原因不明,导致DNS请求超时, 指定外网dns则dig正常.
因此请大家在问题解决前先自行设置DNS,这样内部解析会有问题,
主要是code,请在自己的hosts文件将其解析到10.10.50.50
下面是推荐使用的DNS, 不在这个列表中的慎用,如某些isp的还有某114的.
nameserver  8.8.8.8 # Google Open DNS
nameserver  208.67.222.222  # OpenDNS, also 208.67.220.220
nameserver  77.88.8.8   # Yandex
nameserver  216.146.36.36 # Dyn
nameserver  89.36.220.220 # OpenNic
nameserver  64.6.64.6   # Verisign
nameserver  119.29.29.29    # Public DNS+ by DNSPod, Tencent
nameserver  223.5.5.5 # AliDNS, also 223.6.6.6

最复杂的一个问题是上周Tracy遇到Chrome访问bugzilla问题,在我和Leon机器上复现.
故障是强制跳转https.但是Firefox没问题.各种排除,如reset
cookie,都未解决.服务器并没有启用任何https.

Leon提到HSTS的提示,但服务器没有启用STS字段.

后经Mikel/Tim/Leon追踪问题,终于真相大白.简述如下.
IANA于2012年后开放了很多gTLD,现在有1528个,其中Google申请了110多个,包括我们的dev,这也相安无事.
之后RFC6797的HSTS发布并得到了主流浏览器的支持,以及陆续有进入preload.
https://en.wikipedia.org/wiki/HTTP_Strict_Transport_Security

但是上周的Chrome升级到v63,将其拥有的gTLD加入preload的HSTS列表,
于是,这个版本及以后的Chrome访问我们的dev就强行跳转https了.

还好我们的code不在现在gTLD里面,但是codes在哦.
https://en.wikipedia.org/wiki/List_of_Internet_top-level_domains

https://en.wikipedia.org/wiki/.local

其实,我们并未使用dev作为domain name,只是hostname,
最初dev的fqdn是dev.pica8.org,后来James要走了要去做开源社区,我们就启用了pica8.local域名,.local是RFC6762保留的域名.

所以我们的dev只是个昵称,同时指向这个机器的还有www/web/git/trac/mail/dns/ns1/ftp等等,他们都是.pica8.local前面的部分.

但是历史上,很多配置都是不带pica8.local这个domain的,
全部fqdn后需要改很多地方,全输入也麻烦些.

怎么解决dev的访问问题?
1. 不用63及以上的Chrome,
   或使用firefox/opera.但是相信他们也会陆续加入gtld到preload,只是时间问题.
2. 换域名, 如mikel/tim建议 - 待测试. 我建议用code:9000来取代.
3. 加HTTPS支持.
   我试过certbot用Letsencrypt,但是这个要求域名能公开解析,显然我们内部域名不能解析,pica8.org倒是很好的选择,那样我们发出的邮件也可以配置SPF/DKIM后不被reject了.

后面会尝试Hotel本地HTTPS试试, 如果OK最好.







Hi, Hai,

Yes, current product was built using binaries of Debian release, not from directly from its source code.

If we want, we can make a tar of them.

You can get the package list on boxes using command `dpkg -l`.

We can collect src files of these packages using a script from Debian server.

examples:
https://packages.debian.org/stable/libs/libcurl3
https://packages.debian.org/stable/admin/apt
https://packages.debian.org/stable/net/nftables


Actually, we maintained a local mirror for them, so the collecting can be done instantly if we need.



In next major releases, we planned to build from src to achieve easy maintenance of the ROOTFS.
Usually only one time building is needed for one major release build.



--
Aaron

From: Hai Vo-Dinh
Sent: Monday, December 11, 2017 2:27:26 PM
To: Aaron Shang; Zoneson Chen
Cc: Lin Du; Tom Jia
Subject: RE: Pica8 OSA

Hi Aaron,

You mean that our product is built using binaries of a Debian release ROOTFS, not the source code of that?  Could we make a tar of the source code of that binaries, if we wanted to?

Thanks,
Hai

From: Aaron Shang
Sent: Sunday, December 10, 2017 8:41 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>
Cc: Lin Du <lin.du@pica8.com>; Tom Jia <tom.jia@pica8.com>
Subject: Re: Pica8 OSA


Hi, Hai,

I made a tar ball from the rootfs for boxes that stordis releases were used.

http://dev/src/


Please help find a proper web portal path for that, if you guys think that OK.



But as you can see that tar ball contains only the binaries of a Debian release ROOTFS, which our product had been based on.

The source code means only exist as Debian upstream sources where the Debian releases were built on.

Such as binaries from:
https://packages.debian.org/stable/

And sources from:
https://packages.debian.org/source/wheezy/




I also put a tar ball from our building of the rootfs, kernel, and images.
But I doubt that is what was expected.





--
Aaron

From: Hai Vo-Dinh
Sent: Sunday, December 10, 2017 5:33:37 AM
To: Aaron Shang; Zoneson Chen
Cc: Lin Du; Tom Jia
Subject: FW: Pica8 OSA

Hi Aaron,

Would you please also create a tar ball, similar to the others for the debbian linux distribution and make it available to Zoneson?

Zoneson,
Would you please post it, once available, same as for the other open source software.

Thanks,
Hai



From: Waldemar Scheck [mailto:Waldemar.Scheck@stordis.com]
Sent: Friday, December 8, 2017 11:12 AM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>
Subject: Fwd: Pica8 OSA

....I see them on Monday. Would be gread if that could be done today.
Viele Grüße / Best regards,
Waldemar Scheck

Von meinem iPhone gesendet

Anfang der weitergeleiteten E Mail:
Von: <Lars.Waechtler@rohde-schwarz.com>
Datum: 8. Dezember 2017 um 15:10:25 MEZ
An: <hai.vodinh@pica8.com>
Kopie: Harsha Vardhan <harsha.vardhan@stordis.com>, Joe Digiovanni <joe.Digiovanni@pica8.com>, Waldemar Scheck <waldemar.scheck@stordis.com>
Betreff: Re: Pica8 OSA
Hi Hai,

unfortunately this is what we also need. To fulfill the requirements of the licenses, especially the GPL ones, you and also we have to deliver the whole source code of open source software what we distribute, independent if you or we sell it or not. In the worst case we loos the right to use this software or we have to pay a huge contract penalty to the copyright holder which is each individual developer who has committed some thing into the software. For some individuals this is a new business model. They had committed some lines to the Linux kernel or other GPL tools and now they bring companies to court and reap money form this companies.
I'm sorry but I have to request this source code from you since you are distributing it.


Mit freundlichen Grüßen / Kind Regards

Lars Waechtler

----

Lars Waechtler
R&D

R&S Cybersecurity ipoque GmbH
Augustusplatz 9, D-04109 Leipzig
Phone: + 49 341 59403 140
Email: lars.waechtler@rohde-schwarz.com
Internet: www.ipoque.com

Trade register Amtsgericht Leipzig HRB21462
Gesellschaft mit beschränkter Haftung (GmbH)
Dirk Czepluch - Managing Director



From:        Hai Vo-Dinh <hai.vodinh@pica8.com>
To:        Joe Digiovanni <joe.Digiovanni@pica8.com>, Waldemar Scheck <waldemar.scheck@stordis.com>, Harsha Vardhan <harsha.vardhan@stordis.com>, "lars.waechtler@rohde-schwarz.com" <lars.waechtler@rohde-schwarz.com>
Date:        07.12.2017 18:31
Subject:        Re: Pica8 OSA




Hi Lars,

That is not available currently.  We can look to make that available also.  Let me check with our team.

Best regards,
Hai


From: Lars.Waechtler@rohde-schwarz.com <Lars.Waechtler@rohde-schwarz.com>
Sent: Thursday, December 7, 2017 4:59:03 AM
To: Hai Vo-Dinh; Joe Digiovanni; Waldemar Scheck; Harsha Vardhan
Subject: Pica8 OSA

Dear Gentleman,

thank you for the call from Tuesday. Today I had the chance to look into your protal to obtain the open source components and I'm not sure if I have access to the whole archive but I just see the following packages:
libnetconf
pam_radius
pam_tacplus

What I also expect to see are the sources form the underlying Linux system. Do I just haven't the right access rights or didn't you provide this packages?

Mit freundlichen Grüßen / Kind Regards

Lars Waechtler

----

Lars Waechtler
R&D

R&S Cybersecurity ipoque GmbH
Augustusplatz 9, D-04109 Leipzig
Phone: + 49 341 59403 140
Email: lars.waechtler@rohde-schwarz.com
Internet: www.ipoque.com

Trade register Amtsgericht Leipzig HRB21462
Gesellschaft mit beschränkter Haftung (GmbH)
Dirk Czepluch - Managing Director






Hi, Chung,

下面的链接是BJ Lab部分成员已经习惯使用的文档系统的例子.

链接都是本地解析, `code`解析到10.10.50.50. 如果您用本地网络, 应该已经自行解析OK啦.

如需登錄, 您的用戶名和密碼都應該是最初的 chung.liang/chung.liang

當然, 大部分文檔依然比較原始.


文檔放在`pica8/kb`這個repo, 原意爲 Knowledge Base :)
http://code/pica8/kb/tree/master

具體文檔在這個目錄:
http://code/pica8/kb/tree/master/docs

George Guo 負責的Linux組維護的文檔比較積極, 所有設計文檔都在此:
http://code/pica8/kb/tree/master/docs/linux-system

一例:
http://code/pica8/kb/blob/master/docs/linux-system/sysfs-interface.md
http://code/pica8/kb/blob/master/docs/linux-system/upgrade-design-spec.md



他們都是在本地以自己最喜歡的編輯器(多數是vim啦)編輯, 也可以在線編輯, 例如:
http://code/pica8/kb/edit/master/docs/linux-system/upgrade-design-msh8920.md


每一次變更, 都很觸發自動的文檔系統的build, HTML格式化的結果現在位於:
http://code:9000/kb/

比如:
http://code:9000/kb/box-info/

http://code:9000/kb/linux-system/sysfs-interface/
http://code:9000/kb/linux-system/upgrade-design-spec/
http://code:9000/kb/device-assignment/
http://code:9000/kb/linux-system/fhs-compliance/
http://code:9000/kb/linux-system/oem-config-interface/

以及:
http://code:9000/kb/team/

點擊右上角可以在線編輯, 如:
http://code/pica8/kb/edit/master/docs/team.md


--
Aaron






Also put a copy here for revise:
http://code/pica8/kb/blob/master/docs/alibaba.md



阿里需求：
- 编译用户态c程序及其依赖开源库到picos运行

阿里方希望介绍的内容：
- picos架构与功能模块
- 如何进入Linux shell
- 与标准Linux系统开发的差异
- 如何建立开发环境，编译用户态组件
- 如何打包image

阿里联络邮箱：
xingxing.sxx@alibaba-inc.com


基于以上提纲，拟介绍如下。请各位review，特别是标FIXME部分：





- picos架构与功能模块
picos基于标准Linux开发，现在基于Debian发行版wheezy，next major release would be based on Jessie/(FIXME:Stretch?)

  - picos-linux: kernel image and modules
  - picos-ovs: openvswitch functional components
  - picos-tools: picos support app, diag, upgrade/install, otp/ztp
  - picos-switching: picos main switching/routing system (即现在的pica目录. FIXME:现在deb包还是暂以xorp命名)
  - picos-sdk: 支持bcm/mvl/cvm等芯片厂商的ASIC控制管理功能 (生成bde内核模块. FIXME:与打包的关系？)
  - GUI interface (FIXME: 这一块没有独立出来，要不要提及？)

- 如何进入Linux shell

  - 在CLI模式以start shell sh
  - 在启动时候选择(FIXME: 请填入确切的选项)

- 与标准Linux系统开发的差异
  - picos为标准Linux系统，与标准Linux系统开发相同
  - 考虑到发行版程序与库依赖，建议以picos release的版本进行调试

- 如何建立开发环境，编译用户态组件
  - 需要针对不同的CPU架构部署对应的编译环境，如ARM/PowerPC环境
  - pica8会提供一个标准docker image，用户拿到后import/load 到自己的docker engine/registry环境即可run (FIXME: 请Richard按需修订细节)
  - for picos 2.x releases
      - 使用基于wheezy的debian开发环境，采用debian官方交叉编译工具链
      - 函数库维持在debian 7的基准
      - 可以通过镜像和容器的方式提供
      - 对x86_64和arm支持较好

  - for picos 3.x releases
      - 使用基于jessie的debian开发环境，采用debian官方交叉编译工具链
      - 具备较新、较全面的函数库支撑
      - 可以通过镜像和容器的方式提供
      - 对各个硬件架构支持都很好



- 如何打包image (FIXME: 如有不确切，请George订正)
  - 目前打包格式为shar, 即标准的 self-extracting shell archive，a `/bin/sh` archive including tar ball load.
    - 此shar即符合ONIE标准的自解压执行文件，文件名以`.bin`结尾。
    - 以及一个rootfs的tar ball，即此shar的有效load部分
    - next major release打包格式统一为shar
  - 会生成组成picos的数个标准deb包，但未经完整QA验证。
  - 建议用户应用(and possible dependencies)打包为标准deb格式以便管理、调试、升级等




--
Aaron








On Nov 8, 2017, at 6:21 PM, Aaron Shang <aaron.shang@pica8.com> wrote:


Interfacing networking within Openstack?

Like the ones linked below?


https://cumulusnetworks.com/blog/openstack-with-cumulus-in-the-cloud/
 	OpenStack now featured in Cumulus in the Cloud - Cumulus Networks Blog
cumulusnetworks.com
We are thrilled to announce you can now test out OpenStack with Cumulus in the Cloud. Launch the environment that works for you and see our tech in action.



https://cumulusnetworks.com/networking-solutions/openstack/
 	OpenStack and Cumulus Linux | Cumulus Networks
cumulusnetworks.com
Learn how you can plan, design and deploy an OpenStack cloud using Cumulus Linux for lower TCO, increased efficiency and a better data center network.




--
Aaron

From: Sudhir Modali
Sent: Thursday, November 9, 2017 8:22:57 AM
To: Lin Du
Cc: Tom Jia; Aaron Shang; George Guo; Ali Amjad
Subject: Re: Cloud based service delivery

hello all,

wanted to follow-up on this to figure if we can some progress?

i currently have a few things i am considering…
1. RYU to demonstrate filtering capabilities based on UDF. ideally the RYU controller can be in an AWS with a secure SSL connection to a remote switch
2. Openstack + ODL with VxLAN = i understand from Yachal that it might be quite complex to host the entire Openstack in the cloud, but i believe for a demo it might be ok..

i have to build something by next week and was wondering if its possible to get some help on this…

thanks,

Sudhir Modali
Director PLM





Hi, Hai,

Confirmed with George, the iptables limit was not included in the patch.
So we can leave out explanation about that to end users this time.

The reason was that the iptables change was not gone through thorough test.
Maybe it will be in next major releases, but we should have L2/L3 application team evaluate the performance impacts of iptables rules.

--
Aaron

From: Aaron Shang
Sent: Tuesday, October 31, 2017 8:03:31 AM
To: George Guo; Vic Lan
Cc: Lin Du; Tom Jia; Lisa Pi; Richard Zhang; Hai Vo-Dinh; Yachal Chen; Mikel Tang; Iris Rong; Alan Yu
Subject: Re: [Cloudistics] About the security patch release

Hi, George,

That had been verified, right?

Did we have automation for iptables rules?



From: Hai Vo-Dinh
Sent: Tuesday, October 31, 2017 06:16
To: Aaron Shang
Cc: Lin Du; Tom Jia; George Guo; Vic Lan; Lisa Pi; Richard Zhang
Subject: Re: [Cloudistics] About the security patch release

HI Aaron,

Thank you for your explanation.  Please confirm that the iptables limit were included in the patch.

Thanks,
Hai


--
Hai Vo-Dinh
Director PLM
Pica8, Inc.
M: +1.408.389.9422
hai.vodinh@pica8.com
www.pica8.com



From: Aaron Shang <aaron.shang@pica8.com>
Date: Sunday, October 29, 2017 at 5:31 PM
To: Hai Vo-Dinh <hai.vodinh@pica8.com>
Cc: Lin Du <lin.du@pica8.com>, Tom Jia <tom.jia@pica8.com>, George Guo <george.guo@pica8.com>, Vic Lan <vic.lan@pica8.com>, Lisa Pi <lisa.pi@pica8.com>, Richard Zhang <richard.zhang@pica8.com>
Subject: Re: [Cloudistics] About the security patch release




SSH

The mitigation (add option 'UseRoaming no' to the client ssh_config file) can be done without a patch release, as a simple /etc/ssh_config change.

The patch release just added the line in the `/etc/ssh_config` file.




NTP

NTP runs on our boxes both as a server and a client to sync that server.

The mitigation was to limit NTP server features, by configuring the ntp.conf.

The mitigations included in the patch release:
## Mitigation
- Configure ntp.conf
    - Restrict `noquery` to disable access to mode 6 and 7 query packets which includes `monlist`.

Yes, the mitigation can be done as a config change, without a patch release.
A reload of NTP service is needed to reflect the server config change.

The iptables limit applies for both server and client, to filter out unsolicited flow.
George had verified that, and can add details if I understood wrong.
It acts only to avoid being DDoS victims, it can be left out in user documents.


--
Aaron




From: Hai Vo-Dinh
Sent: Friday, October 27, 2017 3:07 PM
Subject: [Cloudistics] About the security patch release

Hello Aaron,

We have a few questions for the mitigations in patch release (2.7.2S6) to address the vulnerabilities.

SSH
We understand that the vulnerability is with the openssh client, not the server.  We will explain to customer that If an admin is logged into the switch and wants to run an openssh client, that is an intentional act in a controlled environment, and we don't expect that openssh client would be use much from the switch.

Question:   Can the mitigation that you suggested (add option 'UseRoaming no' to the client ssh_config file) be done without a patch release, as a simple config change?   If not, please explain what was done in the patch release for SSH as more than the config.

NTP
We understand the NTP vulnerability is for the NTP server, not client.  We will find out if Cloudistics runs NTP as a server in their compute product.   (of course client is needed).
The mitigation was to limit NTP to client mode only, by configuring the ntp.conf to specify client mode only.

Which of the mitigation you suggested below are included in the patch release?
## Mitigation
- Configure ntp.conf
    - Disable monitoring function by adding `disable monitor`, or
    - Restrict `noquery` will disable access to mode 6 and 7 query packets which includes `monlist`.
    - Configure to only client mode with `restrict default ignore`.
Resulted lines as below.
# Only as a basic NTP client
restrict default kod nomodify notrap nopeer noquery
restrict -6 default kod nomodify notrap nopeer noquery
# allow NTP messages from the loopback address
restrict 127.0.0.1
restrict -6 ::1

- Use `iptables` to limit responding to external requests
The resulting rules may read like below.
-A INPUT -s 0/0 -d 0/0 -p udp --source-port 123:123 -m state --state ESTABLISHED -j ACCEPT
-A OUTPUT -s 0/0 -d 0/0 -p udp --destination-port 123:123 -m state --state NEW,ESTABLISHED -j ACCEPT

Question:   Can the mitigation you suggested be done as a config change, without a patch release?
If not, please give details of what was done in the patch release for SSH as more than the config.

Question – is the iptables limit needed if NTP is limited to run as client only?   If not required, we prefer to leave it out.

Btw, thank you for the thoroughness in researching the vulnerabilities.

Regards,
Hai









--
Aaron


From: Lin Du
Sent: Friday, October 20, 2017 09:22
To: Sharad Ahlawat; Hai Vo-Dinh; Don DeRisi; Aaron Shang
Cc: James Liao; Niraj Jain
Subject: RE: 802.1.x sources on the internet

Sharad, Hai,
OK, please help to list the needed features of 802.1X so as to add it together at once.
Except for the VLAN assignment, is there any other features wanted?
Thanks,
Lin

From: Sharad Ahlawat
Sent: Friday, October 20, 2017 2:03 AM
To: Lin Du; Hai Vo-Dinh; Don DeRisi; Aaron Shang
Cc: James Liao; Niraj Jain
Subject: Re: 802.1.x sources on the internet

Hi, Lin,

Seems the 802.1x Authenticator's ACL and VLAN assignment capability is implemented in the hostap library - http://w1.fi/cgit/hostap/tree/src/ap/ieee802_11_auth.c?id=2272f5aada92cd81a02743c3d04de4667cee3efb

I would prefer that rather than swapping out just the 802.1x packet processing code lets investigate incorporating the full functionality provided by the framework. Attached is a use-case document for additional context around the requirement.

--
/Sharad


From: Lin Du <lin.du@pica8.com>
Date: Wednesday, October 18, 2017 at 23:28
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>, Don DeRisi <don.derisi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: James Liao <james.liao@pica8.com>, Niraj Jain <niraj.jain@pica8.com>
Subject: RE: 802.1.x sources on the internet

Sharad,
OK, will not hurry for this fixing.
The current 802.1X works at port level, not user-ACL. The guest VLAN or failed VLAN can be added easily at port level.
The open codes may not include these options.
Thanks,
Lin

From: Sharad Ahlawat
Sent: Thursday, October 19, 2017 11:11 AM
To: Lin Du; Hai Vo-Dinh; Don DeRisi; Aaron Shang
Cc: James Liao; Niraj Jain
Subject: Re: 802.1.x sources on the internet

Lin,

Does the selected version provide us per user Dynamic VLAN assignment in addition to per-user ACLs?

For campus networks, we anyway need to overhaul our security features but we don't need to do it in a hurried manner and introduce instability. BUT let's wait and see what Hai and Don come back with after presenting these findings to Kontron.

--
/Sharad


From: Lin Du <lin.du@pica8.com>
Date: Wednesday, October 18, 2017 at 19:59
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, Hai Vo-Dinh <hai.vodinh@pica8.com>, Don DeRisi <don.derisi@pica8.com>, Aaron Shang <aaron.shang@pica8.com>
Cc: James Liao <james.liao@pica8.com>, Niraj Jain <niraj.jain@pica8.com>
Subject: RE: 802.1.x sources on the internet

Sharad, Hai,
The team are working toward migrating to WPA_Supplicant with BSD license.
Do we have to continue the task?
Thanks,
Lin

From: Sharad Ahlawat
Sent: Thursday, October 19, 2017 10:50 AM
To: Hai Vo-Dinh; Don DeRisi; Lin Du; Aaron Shang
Cc: James Liao; Niraj Jain
Subject: 802.1.x sources on the internet

Our code - http://code/repo/pica8/tree/master/pica/dot1x

This is part of the RealTek driver available from:
https://sourceforge.net/projects/rtl819x/files/?source=navbar
https://osdn.net/projects/sfnet_rtl819x/
rtl819x-SDK-v3.4.9.3-full-package/rtl819x/users/auth/src/

These drivers are bundled with Linux.
https://wiki.debian.org/rtl819x
https://wireless.wiki.kernel.org/en/users/drivers/rtl819x


Canadian TELUS CPE uses this code:
https://github.com/jameshilliard/WECB-TELUS-GPL-0.16.2.5/tree/04491f299ec826ea0ac2fd117653fef68dab9573/rtl819x/users/auth/include
https://github.com/jameshilliard/WECB-TELUS-GPL-0.16.2.5/tree/04491f299ec826ea0ac2fd117653fef68dab9573
http://opensource.actiontec.com/wcb3000x.html
http://opensource.actiontec.com - The software source code provided here is subject to  Version 2 of the GPL or other GPL or LGPL licenses which are all included in the download and are available below and also at  "http://www.gnu.org/licenses/"and as such, the software source code is distributed WITHOUT ANY WARRANTY and subject to the copyrights of the authors.

and many other Open source projects on the Internet.

So, I don't believe we have a critical issue on our hands.

--
/Sharad





Vul 1/2:

ntp的,这个就可以了:
https://isc.sans.edu/forums/diary/NTP+reflection+attack/17300/

改下ntp.conf





Vul 3:
涉及3个CVE, 其中两个Debian给出config的解决, 或者升级到openssh的u3的包:
https://www.debian.org/security/2016/dsa-3446
more:
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=810984


第三个CVE, 上游(openssh官方)都不认可, debian也没理会
http://www.cvedetails.com/cve/CVE-2016-8858





--
Aaron

From: George Guo
Sent: Friday, October 13, 2017 2:02:45 PM
To: Aaron Shang; Lin Du; Jacob Wang; Vic Lan; Barton Song
Cc: Richard Zhang; Tom Jia
Subject: 答复: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Hi all
Ntp settings in rc.iptables(both 2.7.3 and later versions) below:
os-dev/s4048/rootfs-debian/etc/rc.iptables
$IPTABLES -A INPUT -p udp --dport 123 -j ACCEPT

in /etc/ntp.conf
2.7.3:
restrict 127.0.0.1
restrict -6 ::1

later versions:
restrict default kod nomodify notrap nopeer noquery
restrict -6 default kod nomodify notrap nopeer noquery
restrict 127.0.0.1
restrict -6 ::1


this link is the test I did yesterday:
http://code/pica8/system-team/issues/127

the result:
our switch as ntp client did not receive any packages from attackers.
Having discussed with Aaron, we suspect customer could not use our switch to test, only use the same ntp version to test.

George
Thanks!


发件人: Aaron Shang
发送时间: 2017年10月13日 9:15
收件人: Lin Du; George Guo; Jacob Wang; Vic Lan; Barton Song
抄送: Richard Zhang; Tom Jia
主题: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Nirmal is using the latest ntp package from Debian, that should not work.

George/Jacob, could you try change the INPUT to OUTPUT to have a try?
Or, tweak reasonable ntp patterns?


 os-dev/s4048/rootfs-debian/etc/rc.iptables
$IPTABLES -A INPUT -p udp --dport 123 -j ACCEPT




--
Aaron

From: Lin Du
Sent: Friday, October 13, 2017 9:03:25 AM
To: George Guo; Jacob Wang; Vic Lan; Barton Song
Cc: Aaron Shang; Richard Zhang; Tom Jia
Subject: FW: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

This is the update done by Nirmal. Looks not work.

From: Nirmal Karia
Sent: Thursday, October 12, 2017 11:43 AM
To: Aaron Shang; Sharad Ahlawat; Tom Jia; Zoneson Chen
Cc: support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Hi Sharad,

I get the following errors when i install ntp

root@XorPlus$dpkg -i ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb
Selecting previously unselected package ntpdate.
(Reading database ... 28546 files and directories currently installed.)
Unpacking ntpdate (from ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb) ...
dpkg: dependency problems prevent configuration of ntpdate:
 ntpdate depends on libc6 (>= 2.17); however:
  Version of libc6:amd64 on system is 2.13-38+deb7u12.
 ntpdate depends on libssl1.1 (>= 1.1.0); however:
  Package libssl1.1 is not installed.

dpkg: error processing ntpdate (--install):
 dependency problems - leaving unconfigured
Processing triggers for man-db ...
/usr/bin/mandb: can't create index cache /var/cache/man/ru/5616: No such file or directory
Errors were encountered while processing:
 ntpdate

So i install the libc6 and lib1ssl package an below is the output looks like ntp is install is not installed.

admin@XorPlus$sudo dpkg -i ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb
(Reading database ... 26419 files and directories currently installed.)
Preparing to replace ntpdate 1:4.2.8p10+dfsg-3+deb9u1 (using ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb) ...
Unpacking replacement ntpdate ...
Setting up ntpdate (1:4.2.8p10+dfsg-3+deb9u1) ...
Processing triggers for man-db ...
admin@XorPlus$


Thanks,
Nirmal



From: Aaron Shang
Sent: Wednesday, October 11, 2017 7:43:52 PM
To: Sharad Ahlawat; Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Understand now the situation about my `internal` notion. ;)

Past experiences inferred that upgrading single packages might break our L2/3 app due to low level dependencies.

Our Debian 7 based products only has libc6 2.13, while newer ntp and openssh all require libc6 (>= 2.17). The result may depend on luck.



--
Aaron

From: Sharad Ahlawat
Sent: Thursday, October 12, 2017 10:09:08 AM
To: Aaron Shang; Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Thanks for the detailed response Aaron.

Security vulnerability issues need a quick fix from us. ( within a week )

Enterprises do not buy the old internal usage argument anymore. With so many security related hacks, there are now strong audit requirements that force them to keep their systems up to date. Also in Couldistics/Kontron/Bluewhale case, these are multi-tenant environments and the attack surfaces are internal now, that is if there is any internal/external concept anymore. BTW Kontron's customer are service providers deploying our switches on their internet facing edge.

I see the following options:
1.	Disable service or apply iptable filters to block ports. Given the two services here, this is not an option.
2.	copy .deb files for ntp and ssh to the switch and dpkg install.
3.	if the dpkg install does not work due to configuration or other dependencies build new patch image with integrated packages.

Nirmal is testing out option 2 so we should have results for that soon.

--
/Sharad


From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, October 11, 2017 at 19:06
To: Tom Jia <tom.jia@pica8.com>, George Guo <george.guo@pica8.com>, Lin Du <lin.du@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Sudhir Modali <sudhir.modali@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
Cc: "plm@pica8.com" <plm@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2


BTW, since 4 months had passed after Debian 9 Stretch had been the current stable release, we had no solid reason to start our base (mainly rootfs) for next major release on an obsolete Debian 8.

So, basically I prefer to base next major release with at least Debian 9.2.
That would get security fixes from future 9.x releases.

Current stable releases will receive official support for about 3 years with update for major security or usability fixes.
If we had reason to continue using that after it reaches end of life time, we can continue support using `backporting` to about 2 more years.

--
Aaron

From: Aaron Shang
Sent: Thursday, October 12, 2017 9:48:08 AM
To: Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2


First, if our products are expected to be used internally, the info leakage and DoS attack risk is low.


About these 3 vulnerabilities, 2 is in ntpd, 1 is openssh.

Solutions:
1.      We only use ntpd in client mode, not ntpd server mode, so we can replace ntpd with `ntpdate` or other NTP server implementations such as BSD's ntpd, etc.
2.      If the above is not easy, upgrade that ntpd to a later release.
3.      if the above two choices are not easy, change ntp.conf to disable attack possibilities.
4.      for openssh, upgrade to a new release.


These 2 impacted apps had no relation to kernel, they are in ROOTFS.

In obsolete release Debian 8.9 ROOTFS, openssh is 6.7p1, which fixed the issue.

In current stable release Debian 9.2 ROOTFS, openssh is 7.2p2, which fixed the issue.


In obsolete release Debian 8.9 ROOTFS, ntpd is 4.2.6p5, which still before the 4.2.7 release that fixed the mentioned issue.

In current stable release Debian 9.2 ROOTFS, ntpd is 4.2.8p8, which fixed the issue.

At the time being, it is not easy to upgrade the packages in released versions.

To mitigate the customer concern, these are the proposals.
1.      Release a patch version, which disable ntp.conf items to avoid risk.
2.      Guide users to do so if a patch is not a choice.
3.      Next step, to replace ntp as server.
4.      If the replace is not a choice, upgrade the packages.

For our current released products, the package upgrade is not easy due to the fact that it is Debian 7.

As to package upgrade, ROOTFS should be in line with current stable release.
Current stable releases can get security fixes timely in the life cycle.
(i.e., Debian 9 Stretch after June 2017.)

Obsolete releases can only get very critical fixes now and then.
Debian 8 Jessie is obsoleted since July 2017 after 3 years of `current stable` life cycle.
Debian 8 Jessie still had not been provided of the fixed ntp package.

--
Aaron

From: Tom Jia
Sent: Thursday, October 12, 2017 9:06:53 AM
To: Aaron Shang; George Guo
Subject: Fw: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

FYI...
Thanks.

Best regards,
Tom Jia (贾彦民)



From: Sudhir Modali
Sent: Thursday, October 12, 2017 5:15 AM
To: Zoneson Chen
Cc: plm@pica8.com; Lin Du; TACinternal
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

hi Zoneson,
the newer kernel is in QA. the new kernel will not be available in this calendar year. it maybe available by Q1 2017.
i have requested engineering to look into these and we maybe able to include it in our package by default..

does that help?

Sudhir Modali
Director PLM
Pica8, Inc.
M: +1.408.455.0757
sudhir.modali@pica8.com
www.pica8.com
Follow us on Twitter




On Oct 11, 2017, at 1:58 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:

Hi Sudhir and Lin,

I asked Nirmal to install (sudo apt-get install …) the most current compatible NTP and OPEN-SSH on 2.9.2.5. According to Nirmal, they are the same versions in PicOS 2.9.2.5.

It looks like that the newer versions are only in newer Linux kernel version. Will you inform us what will be our plan to resolve them?

Thanks,

Zoneson

From: Pica8 Support <otrs.support@pica8.com>
Organization: Pica8
Date: Wednesday, October 11, 2017 at 1:21 PM
To: "jerome.ajot@cloudistics.com" <jerome.ajot@cloudistics.com>
Cc: Don DeRisi <don.derisi@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Hi Jerome,

Thank you for informing us the vulnerabilities! I will inform PLM and engineering team about them and we will let you know how to address them later.

Thanks,

Zoneson



PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

10/11/2017 19:22 - Jerome Ajot wrote:
Hello,

During a penetration testing of our product which used Pica8 v2.7.2 on a S4048, the security team found the following issues. Could you please provide guidance on how to remediate those security issues?

Finding ID: 17000
Name: Network Time Protocol (NTP) Mode 6 Vulnerable to amplification attack
Description:
We observe that there is a publicly known vulnerability in NTP version 6 which could allow a remote attacker to conduct DoS attack on a targeted system.
Affected Parameter: 123-udp
Technical Impact:
The remote NTP server responds to mode 6 queries. Devices that respond to these queries have the potential to be used in NTP amplification attacks. An unauthenticated, remote attacker could potentially exploit this, via a specially crafted mode 6 query, to cause a reflected denial of service condition.
Proposed Remediation:
As all versions of ntpd prior to 4.2.7 are vulnerable by default, the simplest recommended course of action is to upgrade all versions of ntpd that are publically accessible to at least 4.2.7. However, in cases where it is not possible to upgrade the version of the service, it is possible to disable the monitor functionality in earlier versions of the software.
To disable “monlist” functionality on a public-facing NTP server that cannot
restrict default kod nomodify notrap nopeer noquery
restrict -6 default kod nomodify notrap nopeer noquery
restrict 127.0.0.1
restrict -6 ::1
For Reference:
https://www.us-cert.gov/ncas/alerts/TA14-013A
https://kb.vmware.com/selfservice/microsites/search.do?language=en_US&cmd=displayKC&externalId=2070193


Finding ID: 17002
Name:   Network Time Protocol NTP Vulnerable to monlist Command Enabled DoS
Description:
We found that there is a publicly known vulnerability in NTP version which could allow a remote attacker to conduct DoSattack on a targeted system.
Affected Parameter: 123-udp
Technical Impact:
The version of ntpd running on the remote host has the 'monlist' command enabled. This command returns a list of recent hosts that have connected to the service. However, it is affected by a denial of service vulnerability in ntp_request.c that allows an unauthenticated, remote attacker to saturate network traffic to a specificIPaddressby usingforged REQ_MON_GETLIST or REQ_MON_GETLIST_1 requests.
Furthermore, an attacker can exploit this issue to conduct reconnaissance or distributed denial of service (DDoS) attacks.
Proposed Remediation:
If using NTP from the Network Time Protocol Project, upgrade to NTP version 4.2.7-p26 or later. Alternatively, add 'disable monitor' to the ntp.conf configuration file and restart the service. Otherwise, limit access to the affected service to trusted hosts, or contact the vendor for a fix.


Finding ID: 16934
Name:   Using Component with Known Vulnerabilities - OpenSSH 6.0p1
Description:
We found that there is a publicly known vulnerability in OpenSSH version 6.0p1 which could allow a remote attacker to conduct Information leakage and DoSattack on a targeted system.
For Vulnerability Confirmation:
http:// www.cvedetails.com/vulnerability-list/vendor_id-97/ product_id- 585/ version_id-188824/ year-2016/ Openbsd-Openssh-6.0.html
CVEs: CVE-2016-8858, CVE-2016-0778, CVE-2016-0777
Affected Parameter: 22
Technical Impact:
Using this vulnerability an attacker can gain Information Leakage which allows remote servers to obtain sensitive information from process memory by requesting transmission of an entire buffer, as demonstrated by reading a private key.
Proposed Remediation:
It is recommended to use the latest version.
For Vulnerability Patch: https://www.openssh.com/






Nirmal is using the latest ntp package from Debian, that should not work.

George/Jacob, could you try change the INPUT to OUTPUT to have a try?
Or, tweak reasonable ntp patterns?


 os-dev/s4048/rootfs-debian/etc/rc.iptables
$IPTABLES -A INPUT -p udp --dport 123 -j ACCEPT




--
Aaron

From: Lin Du
Sent: Friday, October 13, 2017 9:03:25 AM
To: George Guo; Jacob Wang; Vic Lan; Barton Song
Cc: Aaron Shang; Richard Zhang; Tom Jia
Subject: FW: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

This is the update done by Nirmal. Looks not work.

From: Nirmal Karia
Sent: Thursday, October 12, 2017 11:43 AM
To: Aaron Shang; Sharad Ahlawat; Tom Jia; Zoneson Chen
Cc: support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Hi Sharad,

I get the following errors when i install ntp

root@XorPlus$dpkg -i ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb
Selecting previously unselected package ntpdate.
(Reading database ... 28546 files and directories currently installed.)
Unpacking ntpdate (from ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb) ...
dpkg: dependency problems prevent configuration of ntpdate:
 ntpdate depends on libc6 (>= 2.17); however:
  Version of libc6:amd64 on system is 2.13-38+deb7u12.
 ntpdate depends on libssl1.1 (>= 1.1.0); however:
  Package libssl1.1 is not installed.

dpkg: error processing ntpdate (--install):
 dependency problems - leaving unconfigured
Processing triggers for man-db ...
/usr/bin/mandb: can't create index cache /var/cache/man/ru/5616: No such file or directory
Errors were encountered while processing:
 ntpdate

So i install the libc6 and lib1ssl package an below is the output looks like ntp is install is not installed.

admin@XorPlus$sudo dpkg -i ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb
(Reading database ... 26419 files and directories currently installed.)
Preparing to replace ntpdate 1:4.2.8p10+dfsg-3+deb9u1 (using ntpdate_4.2.8p10+dfsg-3+deb9u1_amd64.deb) ...
Unpacking replacement ntpdate ...
Setting up ntpdate (1:4.2.8p10+dfsg-3+deb9u1) ...
Processing triggers for man-db ...
admin@XorPlus$


Thanks,
Nirmal



From: Aaron Shang
Sent: Wednesday, October 11, 2017 7:43:52 PM
To: Sharad Ahlawat; Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Understand now the situation about my `internal` notion. ;)

Past experiences inferred that upgrading single packages might break our L2/3 app due to low level dependencies.

Our Debian 7 based products only has libc6 2.13, while newer ntp and openssh all require libc6 (>= 2.17). The result may depend on luck.



--
Aaron

From: Sharad Ahlawat
Sent: Thursday, October 12, 2017 10:09:08 AM
To: Aaron Shang; Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Thanks for the detailed response Aaron.

Security vulnerability issues need a quick fix from us. ( within a week )

Enterprises do not buy the old internal usage argument anymore. With so many security related hacks, there are now strong audit requirements that force them to keep their systems up to date. Also in Couldistics/Kontron/Bluewhale case, these are multi-tenant environments and the attack surfaces are internal now, that is if there is any internal/external concept anymore. BTW Kontron's customer are service providers deploying our switches on their internet facing edge.

I see the following options:
1.	Disable service or apply iptable filters to block ports. Given the two services here, this is not an option.
2.	copy .deb files for ntp and ssh to the switch and dpkg install.
3.	if the dpkg install does not work due to configuration or other dependencies build new patch image with integrated packages.

Nirmal is testing out option 2 so we should have results for that soon.

--
/Sharad


From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, October 11, 2017 at 19:06
To: Tom Jia <tom.jia@pica8.com>, George Guo <george.guo@pica8.com>, Lin Du <lin.du@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Sudhir Modali <sudhir.modali@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
Cc: "plm@pica8.com" <plm@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2


BTW, since 4 months had passed after Debian 9 Stretch had been the current stable release, we had no solid reason to start our base (mainly rootfs) for next major release on an obsolete Debian 8.

So, basically I prefer to base next major release with at least Debian 9.2.
That would get security fixes from future 9.x releases.

Current stable releases will receive official support for about 3 years with update for major security or usability fixes.
If we had reason to continue using that after it reaches end of life time, we can continue support using `backporting` to about 2 more years.

--
Aaron

From: Aaron Shang
Sent: Thursday, October 12, 2017 9:48:08 AM
To: Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2


First, if our products are expected to be used internally, the info leakage and DoS attack risk is low.


About these 3 vulnerabilities, 2 is in ntpd, 1 is openssh.

Solutions:
1.      We only use ntpd in client mode, not ntpd server mode, so we can replace ntpd with `ntpdate` or other NTP server implementations such as BSD's ntpd, etc.
2.      If the above is not easy, upgrade that ntpd to a later release.
3.      if the above two choices are not easy, change ntp.conf to disable attack possibilities.
4.      for openssh, upgrade to a new release.


These 2 impacted apps had no relation to kernel, they are in ROOTFS.

In obsolete release Debian 8.9 ROOTFS, openssh is 6.7p1, which fixed the issue.

In current stable release Debian 9.2 ROOTFS, openssh is 7.2p2, which fixed the issue.


In obsolete release Debian 8.9 ROOTFS, ntpd is 4.2.6p5, which still before the 4.2.7 release that fixed the mentioned issue.

In current stable release Debian 9.2 ROOTFS, ntpd is 4.2.8p8, which fixed the issue.

At the time being, it is not easy to upgrade the packages in released versions.

To mitigate the customer concern, these are the proposals.
1.      Release a patch version, which disable ntp.conf items to avoid risk.
2.      Guide users to do so if a patch is not a choice.
3.      Next step, to replace ntp as server.
4.      If the replace is not a choice, upgrade the packages.

For our current released products, the package upgrade is not easy due to the fact that it is Debian 7.

As to package upgrade, ROOTFS should be in line with current stable release.
Current stable releases can get security fixes timely in the life cycle.
(i.e., Debian 9 Stretch after June 2017.)

Obsolete releases can only get very critical fixes now and then.
Debian 8 Jessie is obsoleted since July 2017 after 3 years of `current stable` life cycle.
Debian 8 Jessie still had not been provided of the fixed ntp package.

--
Aaron

From: Tom Jia
Sent: Thursday, October 12, 2017 9:06:53 AM
To: Aaron Shang; George Guo
Subject: Fw: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

FYI...
Thanks.

Best regards,
Tom Jia (贾彦民)



From: Sudhir Modali
Sent: Thursday, October 12, 2017 5:15 AM
To: Zoneson Chen
Cc: plm@pica8.com; Lin Du; TACinternal
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

hi Zoneson,
the newer kernel is in QA. the new kernel will not be available in this calendar year. it maybe available by Q1 2017.
i have requested engineering to look into these and we maybe able to include it in our package by default..

does that help?

Sudhir Modali
Director PLM
Pica8, Inc.
M: +1.408.455.0757
sudhir.modali@pica8.com
www.pica8.com
Follow us on Twitter




On Oct 11, 2017, at 1:58 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:

Hi Sudhir and Lin,

I asked Nirmal to install (sudo apt-get install …) the most current compatible NTP and OPEN-SSH on 2.9.2.5. According to Nirmal, they are the same versions in PicOS 2.9.2.5.

It looks like that the newer versions are only in newer Linux kernel version. Will you inform us what will be our plan to resolve them?

Thanks,

Zoneson

From: Pica8 Support <otrs.support@pica8.com>
Organization: Pica8
Date: Wednesday, October 11, 2017 at 1:21 PM
To: "jerome.ajot@cloudistics.com" <jerome.ajot@cloudistics.com>
Cc: Don DeRisi <don.derisi@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Hi Jerome,

Thank you for informing us the vulnerabilities! I will inform PLM and engineering team about them and we will let you know how to address them later.

Thanks,

Zoneson



PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

10/11/2017 19:22 - Jerome Ajot wrote:
Hello,

During a penetration testing of our product which used Pica8 v2.7.2 on a S4048, the security team found the following issues. Could you please provide guidance on how to remediate those security issues?

Finding ID: 17000
Name: Network Time Protocol (NTP) Mode 6 Vulnerable to amplification attack
Description:
We observe that there is a publicly known vulnerability in NTP version 6 which could allow a remote attacker to conduct DoS attack on a targeted system.
Affected Parameter: 123-udp
Technical Impact:
The remote NTP server responds to mode 6 queries. Devices that respond to these queries have the potential to be used in NTP amplification attacks. An unauthenticated, remote attacker could potentially exploit this, via a specially crafted mode 6 query, to cause a reflected denial of service condition.
Proposed Remediation:
As all versions of ntpd prior to 4.2.7 are vulnerable by default, the simplest recommended course of action is to upgrade all versions of ntpd that are publically accessible to at least 4.2.7. However, in cases where it is not possible to upgrade the version of the service, it is possible to disable the monitor functionality in earlier versions of the software.
To disable “monlist” functionality on a public-facing NTP server that cannot
restrict default kod nomodify notrap nopeer noquery
restrict -6 default kod nomodify notrap nopeer noquery
restrict 127.0.0.1
restrict -6 ::1
For Reference:
https://www.us-cert.gov/ncas/alerts/TA14-013A
https://kb.vmware.com/selfservice/microsites/search.do?language=en_US&cmd=displayKC&externalId=2070193


Finding ID: 17002
Name:   Network Time Protocol NTP Vulnerable to monlist Command Enabled DoS
Description:
We found that there is a publicly known vulnerability in NTP version which could allow a remote attacker to conduct DoSattack on a targeted system.
Affected Parameter: 123-udp
Technical Impact:
The version of ntpd running on the remote host has the 'monlist' command enabled. This command returns a list of recent hosts that have connected to the service. However, it is affected by a denial of service vulnerability in ntp_request.c that allows an unauthenticated, remote attacker to saturate network traffic to a specificIPaddressby usingforged REQ_MON_GETLIST or REQ_MON_GETLIST_1 requests.
Furthermore, an attacker can exploit this issue to conduct reconnaissance or distributed denial of service (DDoS) attacks.
Proposed Remediation:
If using NTP from the Network Time Protocol Project, upgrade to NTP version 4.2.7-p26 or later. Alternatively, add 'disable monitor' to the ntp.conf configuration file and restart the service. Otherwise, limit access to the affected service to trusted hosts, or contact the vendor for a fix.


Finding ID: 16934
Name:   Using Component with Known Vulnerabilities - OpenSSH 6.0p1
Description:
We found that there is a publicly known vulnerability in OpenSSH version 6.0p1 which could allow a remote attacker to conduct Information leakage and DoSattack on a targeted system.
For Vulnerability Confirmation:
http:// www.cvedetails.com/vulnerability-list/vendor_id-97/ product_id- 585/ version_id-188824/ year-2016/ Openbsd-Openssh-6.0.html
CVEs: CVE-2016-8858, CVE-2016-0778, CVE-2016-0777
Affected Parameter: 22
Technical Impact:
Using this vulnerability an attacker can gain Information Leakage which allows remote servers to obtain sensitive information from process memory by requesting transmission of an entire buffer, as demonstrated by reading a private key.
Proposed Remediation:
It is recommended to use the latest version.
For Vulnerability Patch: https://www.openssh.com/






Understand now the situation about my `internal` notion. ;)

Past experiences inferred that upgrading single packages might break our L2/3 app due to low level dependencies.

Our Debian 7 based products only has libc6 2.13, while newer ntp and openssh all require libc6 (>= 2.17). The result may depend on luck.



--
Aaron

From: Sharad Ahlawat
Sent: Thursday, October 12, 2017 10:09:08 AM
To: Aaron Shang; Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Thanks for the detailed response Aaron.

Security vulnerability issues need a quick fix from us. ( within a week )

Enterprises do not buy the old internal usage argument anymore. With so many security related hacks, there are now strong audit requirements that force them to keep their systems up to date. Also in Couldistics/Kontron/Bluewhale case, these are multi-tenant environments and the attack surfaces are internal now, that is if there is any internal/external concept anymore. BTW Kontron's customer are service providers deploying our switches on their internet facing edge.

I see the following options:
1.	Disable service or apply iptable filters to block ports. Given the two services here, this is not an option.
2.	copy .deb files for ntp and ssh to the switch and dpkg install.
3.	if the dpkg install does not work due to configuration or other dependencies build new patch image with integrated packages.

Nirmal is testing out option 2 so we should have results for that soon.

--
/Sharad


From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, October 11, 2017 at 19:06
To: Tom Jia <tom.jia@pica8.com>, George Guo <george.guo@pica8.com>, Lin Du <lin.du@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, Sudhir Modali <sudhir.modali@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>
Cc: "plm@pica8.com" <plm@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2


BTW, since 4 months had passed after Debian 9 Stretch had been the current stable release, we had no solid reason to start our base (mainly rootfs) for next major release on an obsolete Debian 8.

So, basically I prefer to base next major release with at least Debian 9.2.
That would get security fixes from future 9.x releases.

Current stable releases will receive official support for about 3 years with update for major security or usability fixes.
If we had reason to continue using that after it reaches end of life time, we can continue support using `backporting` to about 2 more years.

--
Aaron

From: Aaron Shang
Sent: Thursday, October 12, 2017 9:48:08 AM
To: Tom Jia; George Guo; Lin Du; Richard Zhang; Sudhir Modali; Zoneson Chen
Cc: plm@pica8.com; support@pica8.com
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2


First, if our products are expected to be used internally, the info leakage and DoS attack risk is low.


About these 3 vulnerabilities, 2 is in ntpd, 1 is openssh.

Solutions:
1.	We only use ntpd in client mode, not ntpd server mode, so we can replace ntpd with `ntpdate` or other NTP server implementations such as BSD's ntpd, etc.
2.	If the above is not easy, upgrade that ntpd to a later release.
3.	if the above two choices are not easy, change ntp.conf to disable attack possibilities.
4.	for openssh, upgrade to a new release.


These 2 impacted apps had no relation to kernel, they are in ROOTFS.

In obsolete release Debian 8.9 ROOTFS, openssh is 6.7p1, which fixed the issue.

In current stable release Debian 9.2 ROOTFS, openssh is 7.2p2, which fixed the issue.


In obsolete release Debian 8.9 ROOTFS, ntpd is 4.2.6p5, which still before the 4.2.7 release that fixed the mentioned issue.

In current stable release Debian 9.2 ROOTFS, ntpd is 4.2.8p8, which fixed the issue.

At the time being, it is not easy to upgrade the packages in released versions.

To mitigate the customer concern, these are the proposals.
1.	Release a patch version, which disable ntp.conf items to avoid risk.
2.	Guide users to do so if a patch is not a choice.
3.	Next step, to replace ntp as server.
4.	If the replace is not a choice, upgrade the packages.

For our current released products, the package upgrade is not easy due to the fact that it is Debian 7.

As to package upgrade, ROOTFS should be in line with current stable release.
Current stable releases can get security fixes timely in the life cycle.
(i.e., Debian 9 Stretch after June 2017.)

Obsolete releases can only get very critical fixes now and then.
Debian 8 Jessie is obsoleted since July 2017 after 3 years of `current stable` life cycle.
Debian 8 Jessie still had not been provided of the fixed ntp package.

--
Aaron

From: Tom Jia
Sent: Thursday, October 12, 2017 9:06:53 AM
To: Aaron Shang; George Guo
Subject: Fw: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

FYI...
Thanks.

Best regards,
Tom Jia (贾彦民)



From: Sudhir Modali
Sent: Thursday, October 12, 2017 5:15 AM
To: Zoneson Chen
Cc: plm@pica8.com; Lin Du; TACinternal
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

hi Zoneson,
the newer kernel is in QA. the new kernel will not be available in this calendar year. it maybe available by Q1 2017.
i have requested engineering to look into these and we maybe able to include it in our package by default..

does that help?

Sudhir Modali
Director PLM
Pica8, Inc.
M: +1.408.455.0757
sudhir.modali@pica8.com
www.pica8.com
Follow us on Twitter




On Oct 11, 2017, at 1:58 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:

Hi Sudhir and Lin,

I asked Nirmal to install (sudo apt-get install …) the most current compatible NTP and OPEN-SSH on 2.9.2.5. According to Nirmal, they are the same versions in PicOS 2.9.2.5.

It looks like that the newer versions are only in newer Linux kernel version. Will you inform us what will be our plan to resolve them?

Thanks,

Zoneson

From: Pica8 Support <otrs.support@pica8.com>
Organization: Pica8
Date: Wednesday, October 11, 2017 at 1:21 PM
To: "jerome.ajot@cloudistics.com" <jerome.ajot@cloudistics.com>
Cc: Don DeRisi <don.derisi@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017101165000049] Security scan reports on PicOS 2.7.2

Hi Jerome,

Thank you for informing us the vulnerabilities! I will inform PLM and engineering team about them and we will let you know how to address them later.

Thanks,

Zoneson



PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

10/11/2017 19:22 - Jerome Ajot wrote:
Hello,

During a penetration testing of our product which used Pica8 v2.7.2 on a S4048, the security team found the following issues. Could you please provide guidance on how to remediate those security issues?

Finding ID: 17000
Name: Network Time Protocol (NTP) Mode 6 Vulnerable to amplification attack
Description:
We observe that there is a publicly known vulnerability in NTP version 6 which could allow a remote attacker to conduct DoS attack on a targeted system.
Affected Parameter: 123-udp
Technical Impact:
The remote NTP server responds to mode 6 queries. Devices that respond to these queries have the potential to be used in NTP amplification attacks. An unauthenticated, remote attacker could potentially exploit this, via a specially crafted mode 6 query, to cause a reflected denial of service condition.
Proposed Remediation:
As all versions of ntpd prior to 4.2.7 are vulnerable by default, the simplest recommended course of action is to upgrade all versions of ntpd that are publically accessible to at least 4.2.7. However, in cases where it is not possible to upgrade the version of the service, it is possible to disable the monitor functionality in earlier versions of the software.
To disable “monlist” functionality on a public-facing NTP server that cannot
restrict default kod nomodify notrap nopeer noquery
restrict -6 default kod nomodify notrap nopeer noquery
restrict 127.0.0.1
restrict -6 ::1
For Reference:
https://www.us-cert.gov/ncas/alerts/TA14-013A
https://kb.vmware.com/selfservice/microsites/search.do?language=en_US&cmd=displayKC&externalId=2070193


Finding ID: 17002
Name:   Network Time Protocol NTP Vulnerable to monlist Command Enabled DoS
Description:
We found that there is a publicly known vulnerability in NTP version which could allow a remote attacker to conduct DoSattack on a targeted system.
Affected Parameter: 123-udp
Technical Impact:
The version of ntpd running on the remote host has the 'monlist' command enabled. This command returns a list of recent hosts that have connected to the service. However, it is affected by a denial of service vulnerability in ntp_request.c that allows an unauthenticated, remote attacker to saturate network traffic to a specificIPaddressby usingforged REQ_MON_GETLIST or REQ_MON_GETLIST_1 requests.
Furthermore, an attacker can exploit this issue to conduct reconnaissance or distributed denial of service (DDoS) attacks.
Proposed Remediation:
If using NTP from the Network Time Protocol Project, upgrade to NTP version 4.2.7-p26 or later. Alternatively, add 'disable monitor' to the ntp.conf configuration file and restart the service. Otherwise, limit access to the affected service to trusted hosts, or contact the vendor for a fix.


Finding ID: 16934
Name:   Using Component with Known Vulnerabilities - OpenSSH 6.0p1
Description:
We found that there is a publicly known vulnerability in OpenSSH version 6.0p1 which could allow a remote attacker to conduct Information leakage and DoSattack on a targeted system.
For Vulnerability Confirmation:
http:// www.cvedetails.com/vulnerability-list/vendor_id-97/ product_id- 585/ version_id-188824/ year-2016/ Openbsd-Openssh-6.0.html
CVEs: CVE-2016-8858, CVE-2016-0778, CVE-2016-0777
Affected Parameter: 22
Technical Impact:
Using this vulnerability an attacker can gain Information Leakage which allows remote servers to obtain sensitive information from process memory by requesting transmission of an entire buffer, as demonstrated by reading a private key.
Proposed Remediation:
It is recommended to use the latest version.
For Vulnerability Patch: https://www.openssh.com/





Welcome Chung,

- Email chung.liang@pica8.local, with IMAP port 143 and SMTP port 25 at 10.10.50.10
- Git account is chung.liang at Gitlab http://code which resolves to 10.10.50.50
- Bugzilla account is chung.liang@pica8.local at http://dev/bugs/ at 10.10.50.10
- Bugzilla is expected to retire in favor of Gitlab, with modern design and performance.
- If you have Gmail or Google App account, you can use that for easier mail access

- Passwd are all chung.liang


Debian 7 Wheezy had been keeping us (also customers) difficult to use up to date services and utilities.

We had been tried hard to migrate to Debian 8 Jessie, but frustrated a lot by PowerPC SPE support and some not so good old system decisions.

We are trying ONL building in hope to help ease the migration these weeks.

--
Aaron

From: Sharad Ahlawat
Sent: Wednesday, September 6, 2017 4:17:57 AM
To: Aaron Shang
Cc: Chung Liang
Subject: Re: PICOS Build environment

Hi, Aaron,

Could you please create the Engineering accounts (email, git) for Chung. Thanks.

We both will start tackling this task of building an environment here this week. The Debian 7 Wheezy system dependency is leading me down creating a KVM build environment on our build server :).

/Sharad

From: Aaron Shang <aaron.shang@pica8.com>
Date: Monday, August 14, 2017 at 15:58
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Subject: Re: PICOS Build environment


Due to our lack of standalone toolchain for x86 products, current x86 build can only work on a Debian 7 Wheezy system.



--
Aaron

From: Aaron Shang
Sent: Monday, August 14, 2017 6:28:10 PM
To: Sharad Ahlawat
Cc: Tom Jia; Engineering; System; support@pica8.com
Subject: Re: PICOS Build environment

Please follow the following.

Let me know if issues happen, then I would update notes in
http://code/pica8/kb/blob/master/docs/build.md


## Basic build steps
http://code/pica8/kb/blob/master/docs/build.md#image-build-instructions

BOX=as6712_32x
&& make -C os-dev/${BOX} BCM_SDK_ALL PICA8=1 BRANCH=${BRANCH} \
&& ./build-${BOX}.sh \
&& ./build-ovs ${BOX} \
&& make -C os-dev/${BOX}



### Refer to build.sh
http://code/repo/pica8/blob/master/build.sh#32


## Needed packages

sudo apt-get install git build-essential pkg-config libssl-dev libtool-bin libtool automake autoconf libxslt1-dev libxml2-dev libcurl4-gnutls-dev bc fakeroot zip

Refer to:
- http://code/pica8/kb/blob/master/docs/build.md#prerequisites


## Main code repo
- http://code/repo/pica8/


## Toolchain
You also need toolchain, for SDK: /opt/eldk4.2, for others: /opt/eldk-5.3

You can rsync one copy from any BJ servers.



--
Aaron

From: Sharad Ahlawat
Sent: Saturday, August 12, 2017 10:41:07 AM
To: Aaron Shang
Cc: Tom Jia
Subject: PICOS Build environment

Hi, Aaron,

I would like to be able to build PICOS images for a few platforms locally. Could you please share any documentation on setting up a build server, in terms of packages, dependencies and compile instructions so I can at least build the Tomahawk, 5712, and 4610 images.

Thanks.
--
/Sharad







Please follow the following.

Let me know if issues happen, then I would update notes in
http://code/pica8/kb/blob/master/docs/build.md


## Basic build steps
http://code/pica8/kb/blob/master/docs/build.md#image-build-instructions

BOX=as6712_32x
&& make -C os-dev/${BOX} BCM_SDK_ALL PICA8=1 BRANCH=${BRANCH} \
&& ./build-${BOX}.sh \
&& ./build-ovs ${BOX} \
&& make -C os-dev/${BOX}



### Refer to build.sh
http://code/repo/pica8/blob/master/build.sh#32


## Needed packages

sudo apt-get install git build-essential pkg-config libssl-dev libtool-bin libtool automake autoconf libxslt1-dev libxml2-dev libcurl4-gnutls-dev bc fakeroot zip

Refer to:
- http://code/pica8/kb/blob/master/docs/build.md#prerequisites


## Main code repo
- http://code/repo/pica8/


## Toolchain
You also need toolchain, for SDK: /opt/eldk4.2, for others: /opt/eldk-5.3

You can rsync one copy from any BJ servers.



--
Aaron

From: Sharad Ahlawat
Sent: Saturday, August 12, 2017 10:41:07 AM
To: Aaron Shang
Cc: Tom Jia
Subject: PICOS Build environment

Hi, Aaron,

I would like to be able to build PICOS images for a few platforms locally. Could you please share any documentation on setting up a build server, in terms of packages, dependencies and compile instructions so I can at least build the Tomahawk, 5712, and 4610 images.

Thanks.
--
/Sharad






- At the top center of their home page, it shows: Brocade SDN Controller is now Lumina SDN Controller, and, "through its acquisition of assets associated with the SDN Controller product family from Brocade"
- Our Solution team will serve as what their NetDev Services team do
- We are to integrate current efforts to something what Lumina called Flow Manager






----
Quotes followed,
From:
    https://www.luminanetworks.com/press-release-lumina-networks-enters-sdn-market/?v=1c2903397d88

SAN JOSE, Calif.—Aug. 7, 2017—Lumina Networks, Inc. launched today in the software-defined networking (SDN) market, through its acquisition of assets associated with the SDN Controller product family from Brocade Communications Systems, Inc.  Along with a leading SDN Controller solution, powered by OpenDaylight™, Lumina brings a talented team of network software engineers and existing customer engagements with some of the world’s largest service providers. Offering the Lumina SDN Controller, applications and Network Development (NetDev) Services, Lumina is the catalyst that brings open software networking out of the lab and into production networks.
.
.
.

Lumina also offers NetDev Services to help organizations transform their network engineering and operations team. The NetDev Services team at Lumina works with customers to jointly develop production systems using agile methods to prototype and speed through proof-of-concept and pilot phases. Lumina NetDev Services builds solutions using Lumina, open source tools or competitive products.  The company’s methodologies enable customer teams to become self-sufficient in developing and managing their new open source platforms.

.
.
.

Lumina’s product portfolio includes:
•	Lumina SDN Controller: A fully tested, documented and quality-assured edition of OpenDaylight, that provides a common open platform to control the network and manage its nodes.
•	Lumina Flow Manager: A controller-based application that enables more simplified and sophisticated traffic engineering of the network with advanced algorithms such as path-computation for efficient traffic flows.
•	Lumina Zero Touch Installer: A controller-based application that provides initialization of devices, such as virtual CPE, with the correct software image and configuration automatically.




--
Aaron

From: James Liao
Sent: Tuesday, August 8, 2017 11:27:37 PM
To: Dan Tuchler; Sharad Ahlawat; newsfeed
Subject: Re: Brocade's ODL Controller

This looks like a spin-off from Broadcom, who probably gave the IP (open source expertise) to whoever is willing to go to the new company.

From: Dan Tuchler <dan.tuchler@pica8.com>
Date: Tuesday, August 8, 2017 at 8:07 AM
To: James Liao <james.liao@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, newsfeed <newsfeed@pica8.com>
Subject: Re: Brocade's ODL Controller

Is this the corpse buying a coffin or is it the coffin buying a corpse ??


From: James Liao <james.liao@pica8.com>
Date: Tuesday, August 8, 2017 at 7:33 AM
To: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, newsfeed <newsfeed@pica8.com>
Subject: Re: Brocade's ODL Controller

I hope this team can find funding. Verizon signed multi-year contracts with Brocade in 2016 for professional service (around 10 people). That is probably their biggest guaranteed income for the next a couple of years.

James

From: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Date: Tuesday, August 8, 2017 at 7:17 AM
To: newsfeed <newsfeed@pica8.com>
Subject: Brocade's ODL Controller

https://www.luminanetworks.com/?v=7516fd43adaa

I expected Verizon to buy this.
--
/Sharad





就是把配置任务,逐条组成一个叫playbook的yml文件, Ansible会执行之, 底层的SSH鉴权/握手/连接等, Ansible会处理.

你们列出步骤,我写个框架, 然后把这几个最常用的配置任务的步骤填进去.然后我们测试一下.可能的话,提交到Ansible的共享仓库.

很简短,比如Cumulus的:
安装License的:
http://docs.ansible.com/ansible/latest/cl_license_module.html
接口策略的:
http://docs.ansible.com/ansible/latest/cl_interface_policy_module.html
安装Image的:
http://docs.ansible.com/ansible/latest/cl_img_install_module.html



--
Aaron

From: Aaron Shang
Sent: Friday, September 1, 2017 10:11:22 AM
To: Lin Du; Ben Zuo; Bert Yang
Cc: Tom Jia; Jeff Wang; Tim Yi; Clark Lee; Richard Zhang; Lisa Pi
Subject: Re: Feature Request

Jeff, Tim,

Then we need your efforts to provide some example or useful modules for popular operating tasks.

Hope we can make it and verify it well before Sep 6 as Phil mentioned to present on the NetDevOps day.

Can anybody sum up about 5 items of most popular configuration tasks for these instruction playbooks?



--
Aaron

From: Aaron Shang
Sent: Friday, September 1, 2017 10:07:50 AM
To: Lin Du; Ben Zuo; Bert Yang
Cc: Tom Jia; Jeff Wang; Tim Yi; Clark Lee; Richard Zhang
Subject: Re: Feature Request


According to my experience on DevOps utilities such as Ansible, Puppet, Salt, Rex and Chef, Ansible is the best of them.
Although Puppet was the oldest, Ansible has overwhelming advantage over Puppet.
To enable Puppet, we had to install agent on our box, while we need nothing to do to support Ansible (Because we had sshd on boxes).

Ansible itself is basically a whole set of wrapper for all kinds of SSH connection and actions.
Ansible runs instructions one by one organized into what they call `playbooks`.
Also its module design enables various plugins for different purposes to use without further efforts.

As Phil of Edgecore mentioned, we can author and contribute playbooks for using PICOS to Ansible modules.

That would help promote Pica8 brand, such as what Cumulus had shared to Ansible:
- http://docs.ansible.com/ansible/latest/cl_license_module.html
- http://docs.ansible.com/ansible/latest/cl_interface_policy_module.html
- http://docs.ansible.com/ansible/latest/cl_img_install_module.html


Actually we had Ansible playbooks in our github repo before, https://github.com/pica8

But that was very obsolete and primitive, I removed that public repo in order to save Pica8 brand image.


--
Aaron

From: Lin Du
Sent: Friday, September 1, 2017 9:30:37 AM
To: Ben Zuo; Bert Yang; Aaron Shang
Cc: Tom Jia; Jeff Wang; Tim Yi; Clark Lee
Subject: FW: Feature Request

Ben,
Our partner needs the ansible support for PicOS.
Please check if it is possible.
Thanks,
Lin

From: Phil Huang [mailto:phil_huang@edge-core.com]
Sent: Friday, September 01, 2017 9:09 AM
To: Lin Du
Cc: Henry Pan
Subject: Re: Feature Request

Hi 杜林,

我替你們想了一下

For L2/L3
picos_config
picos_command => similar like engineer who can input command as well

For OVS
picos_ovs_db => manage ovs db
picos_bridge => manage each ovs bridge

其他看你們有沒有想要細分的

http://docs.ansible.com/ansible/latest/list_of_network_modules.html

可以參考一下各家範例

謝謝

--
Open Networking Solution Engineer
Open Networking Business Unit
Edgecore Networks Corporation

Mail: phil_huang@edge-core.com
Tel: +886-3-563-8888 Ext: 3585
http://blog.pichuang.com.tw


From: Lin Du <lin.du@pica8.com>
Date: Friday, 1 September 2017 at 08:28
To: phil_huang 黃秉鈞 <phil_huang@edge-core.com>
Cc: Henry Pan <henry.pan@pica8.com>
Subject: RE: Feature Request

Phil,
Thanks a lot.
No problem, since PicOS is based on standard Debian Linux, Ansible can be easily enabled on PicOS.
Actually the Ansible is used when installing PicOS Neutron plugin when integrating with OpenStack.
Is there any special Ansible feature needed?
Thanks,
Lin

From: Phil Huang [mailto:phil_huang@edge-core.com]
Sent: Wednesday, August 30, 2017 10:32 PM
To: Lin Du
Cc: Henry Pan
Subject: Re: Feature Request

不好意思，我按到送出

呈上封信末，我下週會在 DevOpsDay Taipei 提 NetDevOps 的概念出來講，案例會使用 cumulus 跟 pica8 + Ansible 的應用，但實際上你們並沒有具備 ansible network module，所以如果您在這段時間 (~9/6) 考慮覺得該弄，我就會在演講上說未來features 會支援ansible network module.

謝謝


--
Open Networking Solution Engineer
Open Networking Business Unit
Edgecore Networks Corporation

Mail: phil_huang@edge-core.com
Tel: +886-3-563-8888 Ext: 3585
http://blog.pichuang.com.tw


From: phil_huang 黃秉鈞 <phil_huang@edge-core.com>
Date: Wednesday, 30 August 2017 at 22:29
To: Lin Du <lin.du@pica8.com>
Cc: "henry.pan@pica8.com" <henry.pan@pica8.com>
Subject: Feature Request

Dear 杜林,

好久不見，我是先前在杭州阿里巴巴有跟您見面過的 Edgecore Phil Huang。

最近國外趨勢對於 DevOps 越來越盛行，多數都有投技術資源在 Configuration Management Tool (Ansible, Puppet, …etc) 上，實行 NetDevOps 的目標，連 Cisco 都為了做datacenter automation  出了本書[1]

目前 NetDevOps依我現在看到最大的風向是以 Ansible (>2.3) 為最大宗，以現在來講 CumulusLinux 是提倡 NetDevOps 最用力的公司，但主軸是選 puppet，副選ansible

而其他家公司 (Cisco, Juniper, BigSwitch,….etc) 則是選擇 Ansible 為主[1]，目前共有 250+ 以上的模組可供大家使用


我個人建議

貴司可以投入R&D 資源於此，並送回 Ansible repository，以獲得 PicaOS + Ansible = NetDevOps (or automation SDN) 的行銷術語

另提供我個人貢獻經驗，Ansible Network Module是依循 OpenSource 的做法在做貢獻，所以只要有github使用經驗跟知道 ansible unit test 寫法的人就可以撰寫了

BTW,

我下週會在 DevOpsDay Taipei 提 NetDevOps 的概念出來講，案例會使用

謝謝

[1]: Programming and Automating Cisco Networks: A guide to network programmability and automation in the data center, campus, and WAN (Networking Technology)
[2]: http://docs.ansible.com/ansible/latest/list_of_network_modules.html

--
Open Networking Solution Engineer
Open Networking Business Unit
Edgecore Networks Corporation

Mail: phil_huang@edge-core.com
Tel: +886-3-563-8888 Ext: 3585
http://blog.pichuang.com.tw






According to my experience on DevOps utilities such as Ansible, Puppet, Salt, Rex and Chef, Ansible is the best of them.
Although Puppet was the oldest, Ansible has overwhelming advantage over Puppet.
To enable Puppet, we had to install agent on our box, while we need nothing to do to support Ansible (Because we had sshd on boxes).

Ansible itself is basically a whole set of wrapper for all kinds of SSH connection and actions.
Ansible runs instructions one by one organized into what they call `playbooks`.
Also its module design enables various plugins for different purposes to use without further efforts.

As Phil of Edgecore mentioned, we can author and contribute playbooks for using PICOS to Ansible modules.

That would help promote Pica8 brand, such as what Cumulus had shared to Ansible:
- http://docs.ansible.com/ansible/latest/cl_license_module.html
- http://docs.ansible.com/ansible/latest/cl_interface_policy_module.html
- http://docs.ansible.com/ansible/latest/cl_img_install_module.html


Actually we had Ansible playbooks in our github repo before, https://github.com/pica8

But that was very obsolete and primitive, I removed that public repo in order to save Pica8 brand image.


--
Aaron

From: Lin Du
Sent: Friday, September 1, 2017 9:30:37 AM
To: Ben Zuo; Bert Yang; Aaron Shang
Cc: Tom Jia; Jeff Wang; Tim Yi; Clark Lee
Subject: FW: Feature Request

Ben,
Our partner needs the ansible support for PicOS.
Please check if it is possible.
Thanks,
Lin

From: Phil Huang [mailto:phil_huang@edge-core.com]
Sent: Friday, September 01, 2017 9:09 AM
To: Lin Du
Cc: Henry Pan
Subject: Re: Feature Request

Hi 杜林,

我替你們想了一下

For L2/L3
picos_config
picos_command => similar like engineer who can input command as well

For OVS
picos_ovs_db => manage ovs db
picos_bridge => manage each ovs bridge

其他看你們有沒有想要細分的

http://docs.ansible.com/ansible/latest/list_of_network_modules.html

可以參考一下各家範例

謝謝

--
Open Networking Solution Engineer
Open Networking Business Unit
Edgecore Networks Corporation

Mail: phil_huang@edge-core.com
Tel: +886-3-563-8888 Ext: 3585
http://blog.pichuang.com.tw


From: Lin Du <lin.du@pica8.com>
Date: Friday, 1 September 2017 at 08:28
To: phil_huang 黃秉鈞 <phil_huang@edge-core.com>
Cc: Henry Pan <henry.pan@pica8.com>
Subject: RE: Feature Request

Phil,
Thanks a lot.
No problem, since PicOS is based on standard Debian Linux, Ansible can be easily enabled on PicOS.
Actually the Ansible is used when installing PicOS Neutron plugin when integrating with OpenStack.
Is there any special Ansible feature needed?
Thanks,
Lin

From: Phil Huang [mailto:phil_huang@edge-core.com]
Sent: Wednesday, August 30, 2017 10:32 PM
To: Lin Du
Cc: Henry Pan
Subject: Re: Feature Request

不好意思，我按到送出

呈上封信末，我下週會在 DevOpsDay Taipei 提 NetDevOps 的概念出來講，案例會使用 cumulus 跟 pica8 + Ansible 的應用，但實際上你們並沒有具備 ansible network module，所以如果您在這段時間 (~9/6) 考慮覺得該弄，我就會在演講上說未來features 會支援ansible network module.

謝謝


--
Open Networking Solution Engineer
Open Networking Business Unit
Edgecore Networks Corporation

Mail: phil_huang@edge-core.com
Tel: +886-3-563-8888 Ext: 3585
http://blog.pichuang.com.tw


From: phil_huang 黃秉鈞 <phil_huang@edge-core.com>
Date: Wednesday, 30 August 2017 at 22:29
To: Lin Du <lin.du@pica8.com>
Cc: "henry.pan@pica8.com" <henry.pan@pica8.com>
Subject: Feature Request

Dear 杜林,

好久不見，我是先前在杭州阿里巴巴有跟您見面過的 Edgecore Phil Huang。

最近國外趨勢對於 DevOps 越來越盛行，多數都有投技術資源在 Configuration Management Tool (Ansible, Puppet, …etc) 上，實行 NetDevOps 的目標，連 Cisco 都為了做datacenter automation  出了本書[1]

目前 NetDevOps依我現在看到最大的風向是以 Ansible (>2.3) 為最大宗，以現在來講 CumulusLinux 是提倡 NetDevOps 最用力的公司，但主軸是選 puppet，副選ansible

而其他家公司 (Cisco, Juniper, BigSwitch,….etc) 則是選擇 Ansible 為主[1]，目前共有 250+ 以上的模組可供大家使用


我個人建議

貴司可以投入R&D 資源於此，並送回 Ansible repository，以獲得 PicaOS + Ansible = NetDevOps (or automation SDN) 的行銷術語

另提供我個人貢獻經驗，Ansible Network Module是依循 OpenSource 的做法在做貢獻，所以只要有github使用經驗跟知道 ansible unit test 寫法的人就可以撰寫了

BTW,

我下週會在 DevOpsDay Taipei 提 NetDevOps 的概念出來講，案例會使用

謝謝

[1]: Programming and Automating Cisco Networks: A guide to network programmability and automation in the data center, campus, and WAN (Networking Technology)
[2]: http://docs.ansible.com/ansible/latest/list_of_network_modules.html

--
Open Networking Solution Engineer
Open Networking Business Unit
Edgecore Networks Corporation

Mail: phil_huang@edge-core.com
Tel: +886-3-563-8888 Ext: 3585
http://blog.pichuang.com.tw







The Debian releases cycle is as below:

   stable <- testing <- unstable <- experimental <- unreleased

The PPC64 port is made of status `unstable - experimental - unreleased`.
So it can be called at the best as `unstable`, i.e. always code named `sid`.
We can even NOT call it Debian 10, which is code named `Buster`, currently in `testing` release.


Usually a package goes into testing after about 2 years of unstable, then enters `stable` after near another 2 years. If maintained well, the progress can be accelerated.


The current `stable ` release is coded `stretch`, numbered as Debian 9, latest is 9.1.

The `oldstable ` release is coded `jessie`, numbered as Debian 8.
  - Our planned 3.0 branch is to be based on Debian 8.8. (Latest is 8.9)

The `oldoldstable ` release is coded `wheezy`, numbered as Debian 7.
  - Our released system were on that branch, except PowerPC SPE is a mix of `experimental - unreleased`


Only `stable` and `oldstable` releases got maintained and assured updates.
At the time being, it is Debian 8 and 9, i.e. code named Jessie and Stretch.


We are now to investigate how to merge msh8920 fsl building into main building means to reduce maintenance efforts.


--
Aaron


From: Tom Jia
Sent: Friday, August 4, 2017 10:15
To: Sharad Ahlawat; Lin Du; Yachal Chen; Peter Xia; Aaron Shang; Jacob Wang
Cc: James Liao; Niraj Jain; Don DeRisi
Subject: Re: MSH8920/PicOS "reboot" command is not

Hello Sharad,
By talking with Peter and Jacob, there is an unstable Debian distribution of PPC64 which is used on Kontron MSH8920 so far.
https://buildd.debian.org/status/architecture.php?a=ppc64&suite=unstable
And the diag system provided by Kontron is generated by yocto. That's the reason why we build PicOS for Kontron MSH8920 by means of yocto.

To add restriction to system commands such as reboot and poweroff, we have 2 options,
 #1) Reset the permission of these kind of commands based on the current yocto-generated PicOS rootfs
 #2) Move MSH8920 to the unstable debian distribution

#1 is much easier. We can get it done quickly.

#2 needs 1 week to prepare the build if no blocking issue of compatibility. And still need 1 week for QA regression test. As a side effect, apt-get will work if we move MSH8920 to debian distribution.

Please let me know what's your thought.

Thanks.





Test what this is for? ;) 😉

From: System
Sent: Wednesday, August 2, 2017 1:20:27 PM
To: System
Subject: The new System group is ready

Welcome to the System group.
Use the group to share ideas, files, and important dates.


Start a conversation


Read group conversations or start your own.


Add to the team site


Start sharing and collaborating on content in SharePoint.



Share files


View, edit, and share all group files, including email attachments.


Connect your apps


Connect apps like Twitter and Trello to stay current with information and updates your team cares about.

Get the Groups app on your phone and stay connected.









Answer should be NO.

The packages are managed by Yocto project.
Kontron only configure the package content list and toolchain parameters in their released BSP/SDK, or perhaps done by FreeScale.

--
Aaron

From: James Liao
Sent: Thursday, July 20, 2017 11:13:33 AM
To: Sharad Ahlawat; Aaron Shang; Tom Jia; Zoneson Chen; support@pica8.com; Richard Zhang; George Guo; Jacob Wang
Subject: Re: <Mikel help>Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Sharad,

My mail flied across yours in the air. As far as I know, once Kontron goes Yocto, Kontron would have to host all packages on their own repository?

James

From: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Date: Wednesday, July 19, 2017 at 8:09 PM
To: Aaron Shang <aaron.shang@pica8.com>, Tom Jia <tom.jia@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, "support@pica8.com" <support@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, George Guo <george.guo@pica8.com>, Jacob Wang <jacob.wang@pica8.com>
Subject: Re: <Mikel help>Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Thanks for nicely summarizing the issue Aaron.

We do need to have apt work properly. Our OEM customers may also choose to deliver their own packages through their managed repositories, so the infra needs to work.

Just like the 8911 we need to have sources.list point to the right repositories so customers can deploy available apps.

Customer's will be made aware that installing packages from public repositories is not a "contractually" supported operation, but we will assist them on a case by case basis.

--
/Sharad


From: Aaron Shang <aaron.shang@pica8.com>
Date: Wednesday, July 19, 2017 at 19:58
To: Tom Jia <tom.jia@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, "support@pica8.com" <support@pica8.com>, Richard Zhang <richard.zhang@pica8.com>, George Guo <george.guo@pica8.com>, Jacob Wang <jacob.wang@pica8.com>
Subject: Re: <Mikel help>Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken


To meet what the customer need, we should add at least these items:
- `apt` and dependency packages to 8920 ROOTFS
- ppc64 sources.list


msh8920 as the first ppc64 box is special in ROOTFS, generated from freescale yocto packaging system and toolchain.

The above two items were not tried and tested.

@Jacob Wang
Do you think that possible?



Or, if the Kontron user only want one certain package, we can add it into ROOTFS:
- by selecting from ~3000 yocto official packages if included there.
- or, if not in yocto packages, by building from src using the freescale yocto toolchain.





--
Aaron

From: Tom Jia
Sent: Thursday, July 20, 2017 8:50:00 AM
To: Zoneson Chen; support@pica8.com; Aaron Shang; Richard Zhang
Subject: Re: <Mikel help>Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Add Aaron and Richard.
Aaron, Richard,
Could you please help explain the reason why apt-get doesn't work so far with yocto build on MSH8920 and how to get it work?
Thanks.

Best regards,
Tom Jia (贾彦民)



From: Zoneson Chen
Sent: Thursday, July 20, 2017 8:36 AM
To: support@pica8.com
Subject: <Mikel help>Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Mikel,

Would you mind helping to verify it?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Wednesday, July 19, 2017 at 5:34 PM
To: "Yan.Adam@kontron.com" <Yan.Adam@kontron.com>
Cc: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, "Stephane.Martin@kontron.com" <Stephane.Martin@kontron.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Hi Yan,

I am sorry for the late response! I do not have the MSH8920 in our lab and cannot verify it for you. I will ask my colleague in BJ to verify it for you.

Thanks,

Zoneson

From: Pica8 Support <otrs.support@pica8.com>
Organization: Pica8
Date: Monday, July 17, 2017 at 7:32 AM
To: "Yan.Adam@kontron.com" <Yan.Adam@kontron.com>
Cc: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, "Stephane.Martin@kontron.com" <Stephane.Martin@kontron.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Hi Yan Adam,

Thank you for contacting Pica8 support.
We will analyze the information that you have provided, and we will get back to you soon as possible.

Best regards,



PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

07/17/2017 14:30 - Yan Adam wrote:
Hello,

With MSH8920/PicOS 2.9.3/9e706f5, it is not possible to use "apt-get update" or "apt-get install".

admin@Xorplus$sudo apt-get update
E: The method driver /usr/lib/apt/methods/http could not be found.

And the /etc/apt/sources.list file does not point to any active repository. The only entry is:
deb http://packages.pica8.com/pica8/ msh8920 v2.9.3

Adding the same entry I have on a MSH8911/PicOS 2.7.1S1 does not change the behavior:
deb http://antcom.de/powerpcspe/ unstable main

Thank you,
Yan Adam
Kontron
4555, rue Ambroise-Lafortune | Boisbriand (Québec) J7H 0A4 | Canada
T/P: +1 450 437 5682
yan.adam@kontron.com

Website | Blog | Twitter | LinkedIn | YouTube | Facebook


Kontron Canada Inc.
En ouvrant ce courriel, vous acceptez la politique de Kontron relative aux communications électroniques.
By opening this email you are agreeing to Kontron's Electronic Communications Policy.







To meet what the customer need, we should add at least these items:
- `apt` and dependency packages to 8920 ROOTFS
- ppc64 sources.list


msh8920 as the first ppc64 box is special in ROOTFS, generated from freescale yocto packaging system and toolchain.

The above two items were not tried and tested.

@Jacob Wang
Do you think that possible?



Or, if the Kontron user only want one certain package, we can add it into ROOTFS:
- by selecting from ~3000 yocto official packages if included there.
- or, if not in yocto packages, by building from src using the freescale yocto toolchain.





--
Aaron

From: Tom Jia
Sent: Thursday, July 20, 2017 8:50:00 AM
To: Zoneson Chen; support@pica8.com; Aaron Shang; Richard Zhang
Subject: Re: <Mikel help>Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Add Aaron and Richard.
Aaron, Richard,
Could you please help explain the reason why apt-get doesn't work so far with yocto build on MSH8920 and how to get it work?
Thanks.

Best regards,
Tom Jia (贾彦民)



From: Zoneson Chen
Sent: Thursday, July 20, 2017 8:36 AM
To: support@pica8.com
Subject: <Mikel help>Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Mikel,

Would you mind helping to verify it?

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Wednesday, July 19, 2017 at 5:34 PM
To: "Yan.Adam@kontron.com" <Yan.Adam@kontron.com>
Cc: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, "Stephane.Martin@kontron.com" <Stephane.Martin@kontron.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Hi Yan,

I am sorry for the late response! I do not have the MSH8920 in our lab and cannot verify it for you. I will ask my colleague in BJ to verify it for you.

Thanks,

Zoneson

From: Pica8 Support <otrs.support@pica8.com>
Organization: Pica8
Date: Monday, July 17, 2017 at 7:32 AM
To: "Yan.Adam@kontron.com" <Yan.Adam@kontron.com>
Cc: Sharad Ahlawat <Sharad.Ahlawat@pica8.com>, "Stephane.Martin@kontron.com" <Stephane.Martin@kontron.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017071765000026] MSH8920/PicOS apt-get broken

Hi Yan Adam,

Thank you for contacting Pica8 support.
We will analyze the information that you have provided, and we will get back to you soon as possible.

Best regards,



PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us

07/17/2017 14:30 - Yan Adam wrote:
Hello,

With MSH8920/PicOS 2.9.3/9e706f5, it is not possible to use "apt-get update" or "apt-get install".

admin@Xorplus$sudo apt-get update
E: The method driver /usr/lib/apt/methods/http could not be found.

And the /etc/apt/sources.list file does not point to any active repository. The only entry is:
deb http://packages.pica8.com/pica8/ msh8920 v2.9.3

Adding the same entry I have on a MSH8911/PicOS 2.7.1S1 does not change the behavior:
deb http://antcom.de/powerpcspe/ unstable main

Thank you,
Yan Adam
Kontron
4555, rue Ambroise-Lafortune | Boisbriand (Québec) J7H 0A4 | Canada
T/P: +1 450 437 5682
yan.adam@kontron.com

Website | Blog | Twitter | LinkedIn | YouTube | Facebook


Kontron Canada Inc.
En ouvrant ce courriel, vous acceptez la politique de Kontron relative aux communications électroniques.
By opening this email you are agreeing to Kontron's Electronic Communications Policy.




No. 1 root cause for trouble shooting should be battery outage.

Another possibility is that our zoneinfo might be not proper.

There also is reason caused by wrong TZ setting methods.


The `ntpdate` or `hwclock` only set the clock, while `TZ` is done by linking a zoneinfo to /etc/localtime.

So, `/etc/localtime` is ALWAYS a symbol link.

Thus, the `cp` of zoneinfo to that link is only to override the previous linked zone target.





Quote:
// The method that the customer used to set the local time by issuing: 'cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime'


--
Aaron

From: Lin Du
Sent: Wednesday, July 12, 2017 12:01:54 PM
To: Vic Lan
Cc: George Guo; Aaron Shang
Subject: FW: [Ticket#2017070665000056] switch time zone is reset after switch reset

FYI

From: Zoneson Chen
Sent: Wednesday, July 12, 2017 10:38 AM
To: Henry Fung
Cc: support@pica8.com
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

Hi Henry,

I am sorry for the wrong information on the previous mail (Date: Tuesday, July 11, 2017 at 5:45 PM). My mistake was caused by rebooting the switch into L2/L3 mode and the local time is reset to UTC due to no timezone configured.

Honestly, we still do not know what is the customer’s real problem. According to your description, it is due to there are no commands to set timezone. But we suspect that it is caused by hardware clock, not timezone setup since the customer’s approach to set local time is fine.

Here is our suggestion to set /etc/localtime by using symbolic link:

$ sudo rm /etc/localtime
$ sudo ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

The reason is because the symbolic link is easier to see that it has been overwritten. Otherwise, it needs to do the diff (diff /etc/localtime /usr/share/localzone/Asia/ShangHai) to know whether it has been overwritten.

If our suspicion on hardware clock is correct, here are the suggestions how to reset the hardware clock:

1.	There exists Internet connection:
$ sudo ntpdate pool.ntp.org
$ sudo hwclock -w -u

2.	There are no Internet connection:
$ sudo hwclock --set –date=”2017-07-1x xx:xx:xx” --utc

Thanks,

Zoneson

From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Tuesday, July 11, 2017 at 5:45 PM
To: Henry Fung <henry.fung@luxartech.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

Hi Henry,

I can reproduce the timezone problem on 5101 now. After reboot, system resets the symbolic link of /etc/localtime to /usr/share/zoneinfo/UTC. Is it what customer reports?

Thanks,

Zoneson

From: Henry Fung <henry.fung@luxartech.com>
Date: Tuesday, July 11, 2017 at 4:19 PM
To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

Is this the solution in the long run that once they follow your instructions that they will have the timezone, time, and timestamps correct even after a switch reboot?
Have you tested it out?
We have stressed the customer lately due to our unusual bugs. I don't want to ask them to do something as much as possible.
We'd better be sure this is the working, long-term solution.


Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com

On Tue, Jul 11, 2017 at 3:39 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Henry,

Thank you the information! Since the customer set the time zone correctly, I highly suspect that the problem is caused by setting wrong in the hardware clock. If the switch has the Internet connection, would you mind asking him to issue the following commands to reset the hardware clock?

$ sudo ntpdate pool.ntp.org
$ sudo hwclock -w -u

If there are no Internet connection, they have to set it manually. First, they need to know the UTC time and set it manually to hardware clock:

$ sudo hwclock --set –date=”2017-07-1x xx:xx:xx” --utc

Here, x is UTC date and time. Please let us know if you have any concerns.

Thanks,

Zoneson

From: Henry Fung <henry.fung@luxartech.com>
Date: Tuesday, July 11, 2017 at 10:06 AM

To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

The problem that after switch reboot the time zone setting became ineffective was reported on 5101.


Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com

On Tue, Jul 11, 2017 at 9:55 AM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Hi Henry,

Engineering team can reproduce the problem on 3922 and will work on it. According to our tests, 5101 and Tomahawk do not have this problem.

The method that the customer used to set the local time by issuing: 'cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime', is correct. Do they complain the local time on 5101 or Tomahawk? If they do, it could be caused by setting the wrong time in the hardware clock.

Thanks,

Zoneson


From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Monday, July 10, 2017 at 3:11 PM
To: James Liao <james.liao@pica8.com>, Simon Yang <simon.yang@pica8.com>, Henry Fung <henry.fung@luxartech.com>

Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

Hi Henry,

Would you mind checking RTC in 3922’s /var/log/report_diag.log and seeing whether it is correct?

According to my tests, it shows correct date in /var/log/report_diag.log but not shell “date”. The /var/log/report_diag.log in one of our Lab 3922 is enclosed. It looks like that 3922 Linux initialization process does not read RTC to set the time.

Does customer complain 3922 only or including 5101 and Tomahawk?

Thanks,

Zoneson


From: James Liao <james.liao@pica8.com>
Date: Saturday, July 8, 2017 at 11:59 PM
To: Simon Yang <simon.yang@pica8.com>, Henry Fung <henry.fung@luxartech.com>
Cc: Zoneson Chen <zoneson.chen@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

Have we seen similar problem before? If we have a P-3922 on the side, can you check if there is a Lithium battery inside?

From: Simon Yang <simon.yang@pica8.com>
Date: Saturday, July 8, 2017 at 11:50 PM
To: James Liao <james.liao@pica8.com>, Henry Fung <henry.fung@luxartech.com>
Cc: Zoneson Chen <zoneson.chen@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: RE: [Ticket#2017070665000056] switch time zone is reset after switch reset

Yes, we have several switches in our lab that are more than 3 year old.

From: James Liao
Sent: Saturday, July 8, 2017 2:45 PM
To: Henry Fung <henry.fung@luxartech.com>
Cc: Zoneson Chen <zoneson.chen@pica8.com>; support@pica8.com
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

There should be a system info CLI to show the manufacturing date. If the system is 3 years old, we might need to replace the battery. I will check with Simon to see if we have seen similar problem in our lab.

James

From: Henry Fung <henry.fung@luxartech.com>
Date: Saturday, July 8, 2017 at 2:33 PM
To: James Liao <james.liao@pica8.com>
Cc: Zoneson Chen <zoneson.chen@pica8.com>, "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

James,
The symptoms you described are observed in my lab.
Thanks.



Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com

On Fri, Jul 7, 2017 at 5:48 PM, James Liao <james.liao@pica8.com> wrote:
Henry,

It is quite possible the Lithium battery on your 3922 is dead. You can easily validate this by soft reset the 3922. If soft reset does not reset the clock but hard reset (power cycle) does, it is most likely the Lithium.

James

From: Henry Fung <henry.fung@luxartech.com>
Date: Friday, July 7, 2017 at 5:21 PM

To: Zoneson Chen <zoneson.chen@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

I just noticed that my 3922 time was reset after s/w upgrade. My Tomahawk kept its time after s/w upgrade.

admin@PicOS-OVS$date
Fri Jan  2 02:59:15 UTC 1970
admin@PicOS-OVS$date
Fri Jan  2 02:59:26 UTC 1970
admin@PicOS-OVS$version
Copyright (C) 2009-2017 Luxar Tech, Inc.
===================================
Hardware Model                : LTN2013
Linux System Version/Revision : 2.9.1.6/5e22146
Linux System Released Date    : 07/05/2017
L2/L3 Version/Revision        : 2.9.1.6/5e22146
L2/L3 Released Date           : 07/05/2017
OVS/OF Version/Revision       : 2.9.1.6/5e22146
OVS/OF Released Date          : 07/05/2017



Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com

On Fri, Jul 7, 2017 at 11:17 AM, Henry Fung <henry.fung@luxartech.com> wrote:
The customer used 'cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime'.
I'd like to say that the customer would care about achieving the goal (able to use local time to correlate timestamped logs). You may recommend a reasonable mechanism that works for them. Note that the issue is whatever was done became ineffective after switch reset.
Whatever was done is less important; a working solution is being sought here.
Thanks.


Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com

On Thu, Jul 6, 2017 at 10:24 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Henry,

We would like to know the time difference between the hardware clock and the local time.

I can understand that you do not want to bother this customer. Would you mind letting us know how the customer set his timezone? We will try to reproduce it in our Lab.

Thanks,

Zoneson

From: Henry Fung <henry.fung@luxartech.com>
Date: Thursday, July 6, 2017 at 8:29 PM
To: Zoneson Chen <zoneson.chen@pica8.com>

Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

Zoneson,
Why do you need output from me?
The problems happened in customer sites. I do not think I will bother them with this problem.
I have 3922 and Tomahawk in my lab, loaded with 2.9  and 2.8. I think you have them too.


Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com

On Thu, Jul 6, 2017 at 7:32 PM, Zoneson Chen <zoneson.chen@pica8.com> wrote:
Hi Henry,

After internal discussions, we suspect that the root could be caused by the time set in hardware clock. Would you mind providing us the following outputs?

1.	In a PicOS switch:
a.	$ hwclock  --show
b.	$ ls -l /etc/localtime
2.	In a Linux which has the correct local time:
a.	$ date

Thanks,

Zoneson
From: Zoneson Chen <zoneson.chen@pica8.com>
Date: Thursday, July 6, 2017 at 3:07 PM
To: Henry Fung <henry.fung@luxartech.com>

Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

Hi Henry,

I have filed bug#7799 to keep track of your request for enhancement.

Thanks,

Zoneson

From: Henry Fung <henry.fung@luxartech.com>
Date: Thursday, July 6, 2017 at 11:10 AM
To: Pica8 Support <otrs.support@pica8.com>
Cc: "support@pica8.com" <support@pica8.com>
Subject: Re: [Ticket#2017070665000056] switch time zone is reset after switch reset

We have reported it verbally months ago. This is my official reporting to make sure that the problem has been addressed or will be addressed.
The customer needs to be able to configure timezone and time properly. If there is no configuration for that, please add such a provision.


Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com

On Thu, Jul 6, 2017 at 10:54 AM, Zoneson Chen <otrs.support@pica8.com> wrote:
Hi Henry,

Do you have the original emails about this problem? I could not find it in Bugzilla. I could not find the information how to set up the timezone in OVS mode either.

In L2/L3, CLI sets up the symbolic link between /etc/localtime and the target time zone.

Thanks,

Zoneson


PICA8 WHITE BOX SDN
Support Team

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
Pica8 Worldwide Support - (888) 742 2122
Support Email: support@pica8.com
Sales inquiries: http://www.pica8.com/company/contact-us


07/06/2017 16:45 - Henry Fung wrote:
Our customer has reported a problem in LNOS 2.6.5 which was discovered months ago.
The set time zone config became ineffective after switch reset.
The corresponding log message timestamps also went wrong because of the problem.
Please confirm that the time config and time zone config are preserved after switch reset beyond 2.6.5.

Henry Fung, PhD
————————————————
Luxar Tech Inc.
VP of Networking Products
42840 Christy St, Fremont, CA 94538
Email: henry.fung@luxartech.com










https://debconf17.debconf.org/talks/110/





This talk focuses on a journey to build a Debian-based network operating system distribution for data center networking hardware. While Linux networking has been deployed and accelerated by hardware on servers, hypervisors and network processors for decades, data center networking hardware has run on closed operating systems and software since the very first computer networks were created. By riding a new wave of open networking hardware, Linux has been gaining a lot of new ground in data center networks. Network hardware and software disaggregation has opened the doors to leverage and extend existing Linux platforms and ecosystems to new data center networking features. In this talk I will show how Linux networking can be accelerated with an open networking hardware switch. A greater part of this journey has been to make a Linux network operating system distribution synonymous to a server operating system distribution. The examples in the talk are from Cumulus Linux, a Debian derivative.
This talk will cover:
•	A brief overview of open hardware and ONIE, the Open Networking Install Environment
•	Hardware networking features
•	The latest in Linux kernel networking and hardware offloaded to network switches
•	The latest in the Linux networking user-space and ecosystem




--
Aaron






Our netconf should be from this project:

https://github.com/CESNET/netopeer/tree/master/server

I.e. the server part of project:
https://github.com/CESNET/netopeer

With libnetconf from:
https://github.com/CESNET/libnetconf

It had been called libnetconf1 after current active libnetconf2.


This is the new ref project:
https://github.com/CESNET/Netopeer2

The new lib:
https://github.com/CESNET/libnetconf2


This is a PHP web UI for netconf, using libnetconf2 now replacing original using of libnetconf:
https://github.com/CESNET/Netopeer-GUI


This is also an active project:
https://github.com/CESNET/libyang



Local mirror repos without regular sync:

http://code/repo/libnetconf2


http://code/repo/libyang

http://code/repo/Netopeer2


pyang is a YANG validator, transformator and code generator, written in python. It can be used to validate YANG modules for correctness, to transform YANG modules into other formats, and to generate code from the modules.
http://code/repo/pyang

a simple NETCONF client in Go:
http://code/repo/go-netconf



--
Aaron

From: Lin Du
Sent: Saturday, June 24, 2017 6:37:10 PM
To: Aaron Shang; Peter Xia
Cc: Clark Lee
Subject: libnetconf building


Searched out the crosscompile commands for libnetconf.

https://groups.google.com/forum/#!searchin/netopeer/libnetconf%7Csort:relevance/netopeer/5fno0rNP_LY/YfY0SFxh8DUJ


Hi, Radek,

I have successfully compiled newest libnetconf in the cross-compile manner in following steps:
1. ./configure --disable-libssh2 --host=powerpc-my-linux-gnu --with-sysroot=/var/powerpc-my-linux-gnu --prefix=/root/libnetconf-dependency/target/libnetconf
2. make
3. make install

You can specify your cross compiling header and third party libraries using --with-sysroot, the compiler will find the headers and depending libraries from this directory.
And you should also specify the --host option to say which compiler you want to use, so  powerpc-my-linux-gnu-gcc/powerpc-my-linux-gnu-ld/...should be in the PATH environment variable.
And also you may have to compile some additional libraries in the cross compiling manner if your compiling environment does not have this library, in my case, I have these additional libraries compiled:
zlib-1.2.8
libxml2-2.9.1
libxslt-1.1.28
curl-7.37.1

And there is a problem in the source code for src/netconf_internal.h:
the header files included should have a dependency on ENABLE_TLS compiling macro, it should be something like this:
#ifdef ENABLE_TLS
#include <openssl/bio.h>
#include <openssl/ssl.h>
#endif

with this compiling macro, you won't get the following complaint:
[root@localhost libnetconf]# make
./libtool --tag=CC --quiet --mode=compile powerpc-broadcom-linux-gnu-gcc -Wall -I/usr/include/libxml2 -I/usr/include/libxml2  -O3 -fvisibility=hidden -pthread -DNC_WORKINGDIR_PATH=\"//var/lib/libnetconf/\" -DSETBIT=0  -DRCSID=\""released as version 0.8.0"\" -DDISABLE_LIBSSH -I/root/libnetconf/src  -fPIC -c src/callbacks.c -o .obj/src/callbacks.lo
In file included from src/callbacks.c:53:0:
src/netconf_internal.h:52:25: fatal error: openssl/bio.h: No such file or directory
compilation terminated.
make: *** [.obj/src/callbacks.lo] Error 1






To upgrade our shipped boxes to latest security patches, such as kernel 3.16.43-2, here is a short howto.


- Go to our rootfs
- chroot into it, qemu is used for multiple platforms
- update&&upgrade
- build, fix, test
- test, test, test

- package as a whole and release.




--
Aaron

From: Aaron Shang
Sent: Monday, June 5, 2017 9:24:27 AM
To: Sharad Ahlawat; George Guo
Cc: Tom Jia; Lin Du; Niraj Jain; James Liao
Subject: Re: Cadence of upgrading distribution packages

Yes, that's a big known issue.



Debian is famous in slow cadence in upgrading main component versions.

But latest upgrades would apply latest patches. For example, latest Debian 8 Jessie would upgrade kernel to 3.16.43-2, whenever the original installed Jessie is 8.0, 8.2, or 8.5.



The problem was in our side.

The rootfs in our boxes was not `built` out, instead it was a `live` system at some very old point.

It's `live`, but living not able to upgrade.

I had tried to upgrade, only to fail the picos to start, which depends exactly on a very old GLIBC version to work. Any upgrade of kernel or basic utils would also upgrade glibc and make the GLIBC range higher than ours.


The whole rootfs in this living system was not able to upgrade components such as kernel, like usual in normal Linux distros.
We had to `chroot` into the rootfs, make maintenance, then package the rootfs as a whole.

Anyway, that was terrible.


The root cause was that the build had to rely on an exact old Debian system, where nobody dare to upgrade after my upgrade failed.

There were no stable toolchain to ensure the build can be OK anywher with that toolchain.


Richard, Jacob and I had been working to solve this long-term tricky issue.


But our efforts via Yocto would give up the ability to upgrade as standard Debian system, which was highlighted in our published whitepaper.


Ideas to make use of Debian build system to build our delivery in form of upgrade-capable picos-kernel, picos-ovs, picos-utils, picos-config, picos-base, etc. were not finally decided.


We had been discussing actively over this during the past weeks.


--
Aaron


From: Sharad Ahlawat
Sent: Monday, June 5, 2017 01:19
To: George Guo; Aaron Shang
Cc: Tom Jia; Lin Du; Niraj Jain; James Liao
Subject: Cadence of upgrading distribution packages

George, Aaron,

What is our cadence of updating our Linux distribution?

pica8@Pica8-test-primary:~$ uname -a
Linux Pica8-test-primary 3.16.7-ckt11 #1 SMP Wed May 31 14:24:24 CST 2017 x86_64 GNU/Linux
pica8@Pica8-test-primary:~$

The latest patched kernel is 3.16.43 - https://www.kernel.org - 3.16.7 is three years old - this will not pass security certification with enterprise customers and they will not deploy.


What is our cadence of upgrading our Debian distribution packages? An apt-get update show quite a few outdated packages on the latest build. There should not be so many updated on an old stable distribution.

--
Thanks,
Sharad






Yes, that's a big known issue.



Debian is famous in slow cadence in upgrading main component versions.

But latest upgrades would apply latest patches. For example, latest Debian 8 Jessie would upgrade kernel to 3.16.43-2, whenever the original installed Jessie is 8.0, 8.2, or 8.5.



The problem was in our side.

The rootfs in our boxes was not `built` out, instead it was a `live` system at some very old point.

It's `live`, but living not able to upgrade.

I had tried to upgrade, only to fail the picos to start, which depends exactly on a very old GLIBC version to work. Any upgrade of kernel or basic utils would also upgrade glibc and make the GLIBC range higher than ours.


The whole rootfs in this living system was not able to upgrade components such as kernel, like usual in normal Linux distros.
We had to `chroot` into the rootfs, make maintenance, then package the rootfs as a whole.

Anyway, that was terrible.


The root cause was that the build had to rely on an exact old Debian system, where nobody dare to upgrade after my upgrade failed.

There were no stable toolchain to ensure the build can be OK anywher with that toolchain.


Richard, Jacob and I had been working to solve this long-term tricky issue.


But our efforts via Yocto would give up the ability to upgrade as standard Debian system, which was highlighted in our published whitepaper.


Ideas to make use of Debian build system to build our delivery in form of upgrade-capable picos-kernel, picos-ovs, picos-utils, picos-config, picos-base, etc. were not finally decided.


We had been discussing actively over this during the past weeks.


--
Aaron


From: Sharad Ahlawat
Sent: Monday, June 5, 2017 01:19
To: George Guo; Aaron Shang
Cc: Tom Jia; Lin Du; Niraj Jain; James Liao
Subject: Cadence of upgrading distribution packages

George, Aaron,

What is our cadence of updating our Linux distribution?

pica8@Pica8-test-primary:~$ uname -a
Linux Pica8-test-primary 3.16.7-ckt11 #1 SMP Wed May 31 14:24:24 CST 2017 x86_64 GNU/Linux
pica8@Pica8-test-primary:~$

The latest patched kernel is 3.16.43 - https://www.kernel.org - 3.16.7 is three years old - this will not pass security certification with enterprise customers and they will not deploy.


What is our cadence of upgrading our Debian distribution packages? An apt-get update show quite a few outdated packages on the latest build. There should not be so many updated on an old stable distribution.

--
Thanks,
Sharad





A quick list of candidate NICs with current built-in dpdk support:
http://dpdk.org/doc/nics




--
Aaron

From: Dan Tuchler
Sent: Wednesday, May 10, 2017 1:40:31 PM
To: Aaron Shang; Lin Du; Clark Lee; Jeff Wang; Tim Yi; Tom Jia
Cc: George Guo; Mikel Tang; Iris Rong; Tong Zhang; Lisa Pi; Allerson Yao; Bert Yang; Alan Yu; plm@pica8.com; Sharad Ahlawat; Yachal Chen
Subject: Re: Hardware Roadmap

Hi Aaron, thanks for the feedback.

I’m copying in some key technical minds from the Palo Alto side (Sharad, Sudhir, Yachal).

Some comments:

- I’d really like to go to containers, but from talking to customers, their concern is that 3rd party code will not be ready in container form for some time. Right now several functions are available as VMs, but even those are not very mature or stable.
- VMware is a no-go – too expensive when you factor in the management plane
- ARM is definitely getting momentum, but I think we are still focusing our efforts on Intel, and leveraging code dev. across platforms. So we are using that assumption for now. If engineering decides at some point that our future direction should be ARM, that would be a big decision for the company.

Actions needed:
PLM / Dan:
- customer use cases
- some examples of code we’d like to run
- what does Inventec have figured out so far
Eng:
- can a VM environment and PicOS run in the same Intel CPU? What does the architecture look like? Any difficult challenges ?
- what’s a good Intel processor to recommend – combination of decent performance, some crypto support, and low cost
- what NIC should we recommend? DPDK capable, 4 x 1G, low cost – anything else to spec?

Please keep the great feedback coming!

- Dan


From: Aaron Shang <aaron.shang@pica8.com>
Date: Tuesday, May 9, 2017 at 8:00 PM
To: Lin Du <lin.du@pica8.com>, Clark Lee <clark.li@pica8.com>, Jeff Wang <jeff.wang@pica8.com>, Tim Yi <tim.yi@pica8.com>, Tom Jia <tom.jia@pica8.com>
Cc: George Guo <george.guo@pica8.com>, Mikel Tang <mikel.tang@pica8.com>, Iris Rong <iris.rong@pica8.com>, Tong Zhang <tong.zhang@pica8.com>, Lisa Pi <lisa.pi@pica8.com>, Allerson Yao <allerson.yao@pica8.com>, Bert Yang <bert.yang@pica8.com>, Alan Yu <alan.yu@pica8.com>, "plm@pica8.com" <plm@pica8.com>
Subject: Re: Hardware Roadmap


Comments:
- KVM VMs are high perf VM compared to others
  - But still heavier than container
  - Need overhead for "Loading, monitoring, management of VMs"
- It is of no major efforts to "repackage the code Run their code in VM"
- Container(lxc, rkt, or docker) advantage over KVM
  - High perf than KVM, isolate env but sharing host capability, not exclusive
  - Native kernel long time support. KVM needs kernel config enabled (although easy)
  - Easier to maintain, update, deploy; More lightweight.
  - Native management and control interface. KVM needs libvirt/oVirt/Qemu, etc.

As an education, we can:
  - summarize all customer needs into typical use cases,
  - set up live interactive online demo,
    - based on current solutions.

On CPU architecture:
- dpdk support includes ATOM, ARM.
  - Crypto: http://dpdk.org/doc/guides/cryptodevs/

- ARMv8 has good native aes/cipher/crypto support
  - AES encrypt/decrypt and SHA-1/SHA-2 hashing instructions, etc.
  - https://en.wikipedia.org/wiki/Comparison_of_ARMv8-A_cores



Several links:
- App layer, SW/HW
  - https://en.wikipedia.org/wiki/6WIND
  - https://en.wikipedia.org/wiki/Tilera
  - http://www.mellanox.com/page/npu_multicore_overview


--
Aaron

From: Lin Du
Sent: Thursday, May 4, 2017 4:24:58 PM
To: Clark Lee; Jeff Wang; Tim Yi; Tom Jia
Cc: Aaron Shang; George Guo; Mikel Tang; Iris Rong; Tong Zhang; Lisa Pi; Allerson Yao; Bert Yang; Alan Yu
Subject: FW: Hardware Roadmap

FYI

From: Dan Tuchler
Sent: Thursday, May 04, 2017 10:49 AM
To: Lin Du; Tom Jia
Subject: Hardware Roadmap

Lin and Tom,

Attached is a deck I’ve created to collect some of the upcoming hardware requirements. This is based on our strategy for enterprise access / campus, plus any opportunities we know about, plus an on-going requirement to keep up with the newest ASICs.  Here’s the short version (pg. 17 of the deck) –

?	Branch office and Campus LAN switches – to support multi-vendor statement
•       2 versions (48 ports, PoE+ | non-PoE), Delta
•       4 versions (24 | 48 ports, PoE+ | non-PoE), Inventec
•       Add 2.5G to the mix – for Wave 2
?	Branch extension – larger CPU for SD-WAN or light NFV
•       1 version from Inventec
•       Port KVM & supporting tools to this platform
?	2.5Gbps Campus LAN future, including Telus
•       24port x 2.5G switch – Hurricane3MG
?	High-end, performance leadership
•       Maverick – 48 x 10 + 4 x 100 – later
•       Tomahawk – 48 x 25 + 6 x 100 – later
•       Tomahawk2 – 64 x 100G
?	This is too much – so now we have to make some choices . . . .

I’ve also attached a one-page diagram for discussing our next-gen branch product. The intent is to get more money per branch – by replacing the switch and also the router or SD-WAN box. We will consider talking with some of the SD-WAN companies. (but – not Viptela!)

Action requested:
- look through the deck, share it as needed, provide feedback
- look at the next gen diagram and get some discussions going and give me some feedback

thanks,

- Dan









About efforts to "repackage the code", or "Run code in VM or Container":
- Same efforts for packaging to standard formats, `deb`, `rpm`, `ipkg`
- Easier to debug and deploy with container
- VM needs efforts to install and run the generated packages.
- Yocto provides native container output, if no distro is preferred.


--
Aaron


From: Aaron Shang
Sent: Wednesday, May 10, 2017 11:00
To: Lin Du; Clark Lee; Jeff Wang; Tim Yi; Tom Jia
Cc: George Guo; Mikel Tang; Iris Rong; Tong Zhang; Lisa Pi; Allerson Yao; Bert Yang; Alan Yu; plm@pica8.com
Subject: Re: Hardware Roadmap


Comments:
- KVM VMs are high perf VM compared to others
  - But still heavier than container
  - Need overhead for "Loading, monitoring, management of VMs"


- Container(lxc, rkt, or docker) advantage over KVM
  - High perf than KVM, isolate env but sharing host capability, not exclusive
  - Native kernel long time support. KVM needs kernel config enabled (although easy)
  - Easier to maintain, update, deploy; More lightweight.
  - Native management and control interface. KVM needs libvirt/oVirt/Qemu, etc.

As an education, we can:
  - summarize all customer needs into typical use cases,
  - set up live interactive online demo,
    - based on current solutions.

On CPU architecture:
- dpdk support includes ATOM, ARM.
  - Crypto: http://dpdk.org/doc/guides/cryptodevs/

- ARMv8 has good native aes/cipher/crypto support
  - AES encrypt/decrypt and SHA-1/SHA-2 hashing instructions, etc.
  - https://en.wikipedia.org/wiki/Comparison_of_ARMv8-A_cores



Several links:
- App layer, SW/HW
  - https://en.wikipedia.org/wiki/6WIND
  - https://en.wikipedia.org/wiki/Tilera
  - http://www.mellanox.com/page/npu_multicore_overview


--
Aaron

From: Lin Du
Sent: Thursday, May 4, 2017 4:24:58 PM
To: Clark Lee; Jeff Wang; Tim Yi; Tom Jia
Cc: Aaron Shang; George Guo; Mikel Tang; Iris Rong; Tong Zhang; Lisa Pi; Allerson Yao; Bert Yang; Alan Yu
Subject: FW: Hardware Roadmap

FYI

From: Dan Tuchler
Sent: Thursday, May 04, 2017 10:49 AM
To: Lin Du; Tom Jia
Subject: Hardware Roadmap

Lin and Tom,

Attached is a deck I’ve created to collect some of the upcoming hardware requirements. This is based on our strategy for enterprise access / campus, plus any opportunities we know about, plus an on-going requirement to keep up with the newest ASICs.  Here’s the short version (pg. 17 of the deck) –

	Branch office and Campus LAN switches – to support multi-vendor statement
•       2 versions (48 ports, PoE+ | non-PoE), Delta
•       4 versions (24 | 48 ports, PoE+ | non-PoE), Inventec
•       Add 2.5G to the mix – for Wave 2
	Branch extension – larger CPU for SD-WAN or light NFV
•       1 version from Inventec
•       Port KVM & supporting tools to this platform
	2.5Gbps Campus LAN future, including Telus
•       24port x 2.5G switch – Hurricane3MG
	High-end, performance leadership
•       Maverick – 48 x 10 + 4 x 100 – later
•       Tomahawk – 48 x 25 + 6 x 100 – later
•       Tomahawk2 – 64 x 100G
	This is too much – so now we have to make some choices . . . .

I’ve also attached a one-page diagram for discussing our next-gen branch product. The intent is to get more money per branch – by replacing the switch and also the router or SD-WAN box. We will consider talking with some of the SD-WAN companies. (but – not Viptela!)

Action requested:
- look through the deck, share it as needed, provide feedback
- look at the next gen diagram and get some discussions going and give me some feedback

thanks,

- Dan







Comments:
- KVM VMs are high perf VM compared to others
  - But still heavier than container
  - Need overhead for "Loading, monitoring, management of VMs"
- It is of no major efforts to "repackage the code Run their code in VM"
- Container(lxc, rkt, or docker) advantage over KVM
  - High perf than KVM, isolate env but sharing host capability, not exclusive
  - Native kernel long time support. KVM needs kernel config enabled (although easy)
  - Easier to maintain, update, deploy; More lightweight.
  - Native management and control interface. KVM needs libvirt/oVirt/Qemu, etc.

As an education, we can:
  - summarize all customer needs into typical use cases,
  - set up live interactive online demo,
    - based on current solutions.

On CPU architecture:
- dpdk support includes ATOM, ARM.
  - Crypto: http://dpdk.org/doc/guides/cryptodevs/

- ARMv8 has good native aes/cipher/crypto support
  - AES encrypt/decrypt and SHA-1/SHA-2 hashing instructions, etc.
  - https://en.wikipedia.org/wiki/Comparison_of_ARMv8-A_cores



Several links:
- App layer, SW/HW
  - https://en.wikipedia.org/wiki/6WIND
  - https://en.wikipedia.org/wiki/Tilera
  - http://www.mellanox.com/page/npu_multicore_overview


--
Aaron

From: Lin Du
Sent: Thursday, May 4, 2017 4:24:58 PM
To: Clark Lee; Jeff Wang; Tim Yi; Tom Jia
Cc: Aaron Shang; George Guo; Mikel Tang; Iris Rong; Tong Zhang; Lisa Pi; Allerson Yao; Bert Yang; Alan Yu
Subject: FW: Hardware Roadmap

FYI

From: Dan Tuchler
Sent: Thursday, May 04, 2017 10:49 AM
To: Lin Du; Tom Jia
Subject: Hardware Roadmap

Lin and Tom,

Attached is a deck I’ve created to collect some of the upcoming hardware requirements. This is based on our strategy for enterprise access / campus, plus any opportunities we know about, plus an on-going requirement to keep up with the newest ASICs.  Here’s the short version (pg. 17 of the deck) –

?	Branch office and Campus LAN switches – to support multi-vendor statement
•       2 versions (48 ports, PoE+ | non-PoE), Delta
•       4 versions (24 | 48 ports, PoE+ | non-PoE), Inventec
•       Add 2.5G to the mix – for Wave 2
?	Branch extension – larger CPU for SD-WAN or light NFV
•       1 version from Inventec
•       Port KVM & supporting tools to this platform
?	2.5Gbps Campus LAN future, including Telus
•       24port x 2.5G switch – Hurricane3MG
?	High-end, performance leadership
•       Maverick – 48 x 10 + 4 x 100 – later
•       Tomahawk – 48 x 25 + 6 x 100 – later
•       Tomahawk2 – 64 x 100G
?	This is too much – so now we have to make some choices . . . .

I’ve also attached a one-page diagram for discussing our next-gen branch product. The intent is to get more money per branch – by replacing the switch and also the router or SD-WAN box. We will consider talking with some of the SD-WAN companies. (but – not Viptela!)

Action requested:
- look through the deck, share it as needed, provide feedback
- look at the next gen diagram and get some discussions going and give me some feedback

thanks,


o



The following are some of Beijing Lab name resolving for your info:

10.10.50.10 dev dev.pica8.local
10.10.50.10 pop pop3 imap smtp mail mail.pica8.local
10.10.50.22 mirror mirror.pica8.local
10.10.50.22 mirrors mirrors.pica8.local
10.10.50.50 code code.pica8.local

You can try this for bugzilla:
http://dev/bugs/

If not resolving, please use IP 10.10.50.10



Now in Beijing we HAVE to maintain a local mail system, JUST because @pica8.com would reject all internal mails.


We can retire that if @pica8.com can receive internal mails like what Gmail does.


I myself uses Google Cloud App as my own domain and mail system, that works well to receive internal mails, such as my mail as@ashang.org can get mails from as@pica8.local




--
Aaron


From: Aaron Shang
Sent: Wednesday, April 26, 2017 10:50
To: Don DeRisi; Sharad Ahlawat; Zoneson Chen; Lin Du; Clark Lee
Subject: Re: Bugzilla account please


Hi, Don,



Root cause is that the pica8.com SMTP reject mails from our Beijing lab IP.



If you have Gmail, please try that. Gmail always works to receive our
internal mail because Gmail can judge.






Now your login:
don.derisi@pica8.com

Passwd:
dondon


Please try and tell me if not OK.













--
Aaron

From: Don DeRisi
Sent: Wednesday, April 26, 2017 4:31:01 AM
To: Sharad Ahlawat; Zoneson Chen; Aaron Shang; Lin Du
Subject: RE: Bugzilla account please

Hi,   In Dec 2015 I did not get a login.   Maybe I just did general browsing with this info:
>>> Then, you can browse 10.10.50.11 and Bugzilla by clicking Bugzilla icon.

I had sslvpn account.    No other credentials.
>>>username:don  passwd:dondon

Aaron or Lin, please set me up for a Bugzilla account.   More info below.   THANKS

Regards,
Don

From: Sharad Ahlawat
Sent: Tuesday, April 25, 2017 4:25 PM
To: Don DeRisi; Zoneson Chen
Cc: Aaron Shang; Lin Du
Subject: Re: Bugzilla account please

Your bugzilla account access does not change based on VPN method. Did you have bugzilla access in the past? If so, you may have emails archived from Aaron or Lin with your user credentials. If not then these are the guys to send an email to for granting access. Aaron Shang <aaron.shang@pica8.com>; Lin Du <lin.du@pica8.com>

--
Thanks,
Sharad


From: Don DeRisi <don.derisi@pica8.com>
Date: Tuesday, April 25, 2017 at 1:20 PM
To: Zoneson Chen <zoneson.chen@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Subject: FW: Bugzilla account please

Hi, I tried this  you may contact the maintainer of this Bugzilla installation at bugzilla@pica8.local.
but that email not working.
Who would be contact for getting Bugzilla account?     (My prior was based upon SSLVPN Hillstone network access; now using OpenVPN setup)

Don
-------------
Hi,

I am working with Sharad on Verizon and other accounts.

I am able to reach Bugzilla Main page - http://dev/bugs/
but I was not able to create credentials to login.  I tried "Open a New Account", but no email received after completing request.

Can you have this setup manually?
email = don.derisi@pica8.com

THANKS

Regards,
Don

Don DeRisi
Business Development

Pica8, Inc.
1032 Elwell Court, Suite 105
Palo Alto, CA. 94303
M: +1 914 843 0801
don@pica8.com  |   www.pica8.com
Follow us on Twitter











Notes:
- Main player should be Cumulus
- Led by Linkedin.
- Includes lots of network component providers and web companies
- 19 refers to EIA 19-inch rack
- Running Cumulus Linux
  - https://cumulusnetworks.com/learn/web-scale-networking-resources/solution-briefs/Solution-Overview-Open19-Cumulus.pdf
Open19 and Cumulus Linux
cumulusnetworks.com
Open19 and Cumulus Linux INCREASE EFFICIENCY WITH A FULLY INTEROPERABLE NETWORK STACK SOLUTION OVERVIEW — OPEN19 + CUMULUS® LINUX® Open19 Built on the principles ...


More:
- Some thing like our Kontron boxes
- Cisco had been making similar solution before
- Inspur, a Chinese gov supported server HW/SW company was in their list
- Product concept seems good; Tech side not new.



--
Aaron

From: Sharad Ahlawat
Sent: Wednesday, April 19, 2017 10:44:22 AM
To: newsfeed
Subject: Open19

http://www.open19.org






Compared to VM, container is fairly light in resource consuming, which share and reuse all resource of host OS, instead of creating other whole guest OSes.

Typical example can be Kontron boxes, which add much more server like CPU/RAM power on switches.
Thus potential customers can directly deploy networking App there without needs of other servers.



--
Aaron

From: James Liao
Sent: Friday, March 17, 2017 1:07:26 PM
To: Aaron Shang; newsfeed
Subject: Re: Arista Introduces Containerized Software for Cloud Networking

Aaron,

What is the benefit of running NOS on a container in the switch? I know it sounds fancy, but it is similar to VM, anyway. The main challenge is whether the ASIC/CPU CMOS channel can be efficient for the applications running in the container. Right?

James

From: Aaron Shang <aaron.shang@pica8.com>
Date: Friday, March 17, 2017 at 10:35 AM
To: newsfeed <newsfeed@pica8.com>
Subject: Arista Introduces Containerized Software for Cloud Networking



EOS Disaggregation with White-Box Ecosystem
> Arista customers can utilize cEOS in tandem with industry standard white box hardware and enable a wide array of tools and applications from the container ecosystem. This marks the first software offering of EOS for white box switches and servers. Arista cEOS is available and supported by Arista on disaggregated hardware from a broad vendor ecosystem.





Many customers had been asking to try similar scenarios.






https://www.arista.com/en/company/news/press-release/2918-pr-20170307
Arista Introduces Containerized Software for Cloud Networking
www.arista.com
Arista cEOS Endorsed by Broadcom, Hewlett Packard Enterprise and Microsoft Azure Networking SANTA CLARA, Calif.,--March 7, 2017 -- Arista Networks (NYSE:ANET) today announced Containerized EOS (containerized Extensible Operating System) to support a





--
Aaron







EOS Disaggregation with White-Box Ecosystem
> Arista customers can utilize cEOS in tandem with industry standard white box hardware and enable a wide array of tools and applications from the container ecosystem. This marks the first software offering of EOS for white box switches and servers. Arista cEOS is available and supported by Arista on disaggregated hardware from a broad vendor ecosystem.





Many customers had been asking to try similar scenarios.






https://www.arista.com/en/company/news/press-release/2918-pr-20170307
Arista Introduces Containerized Software for Cloud Networking
www.arista.com
Arista cEOS Endorsed by Broadcom, Hewlett Packard Enterprise and Microsoft Azure Networking SANTA CLARA, Calif.,--March 7, 2017 -- Arista Networks (NYSE:ANET) today announced Containerized EOS (containerized Extensible Operating System) to support a





--
Aaron







The sync had been started to your `ptp` dir using `rsync` from a clean working dir, which can resume anywhere it stopped.

That is not a good case, because the total size would be much more.


The repo side is too huge to complete one clone without break in such a low speed connection.

We are trying to make the repo a reasonable size.
At least 5.5GB out of the current 10GB repo is binary `.so/a` files which should be moved out, but we need to work with SDK team on that.


Maybe a local mirror repo can be better, but it's very hard to keep them in good sync.

I will try some means for a maintainable mirror repo.


--
Aaron

From: Rajaram Gurumurthy
Sent: Saturday, September 24, 2016 8:27:01 AM
To: Lin Du
Cc: Aaron Shang
Subject: RE: the PTP development branch

Thank you, Lin !
The clone operation that I had started this morning didn’t succeed either.

Linux server details (hosted on VM):
172.16.0.219      (rajaram/root)

Please clone master into this folder:
/home/rajaram/git/ptp

Regards,
Rajaram

From: Lin Du
Sent: Friday, September 23, 2016 4:59 PM
To: Rajaram Gurumurthy <rajaram.gurumurthy@pica8.com>
Cc: Aaron Shang <aaron.shang@pica8.com>
Subject: 回复: the PTP development branch

Raj,
please provide the VM access info so Aaron can help sync the codes to your local machine.
thanks,
Lin

PICA8， Inc.


-------- 原始邮件 --------
主题：RE: the PTP development branch
发件人：Rajaram Gurumurthy
收件人：Lin Du
抄送：

Lin,

I’m unable to complete the clone operation into my local VM for the past two days. I tried three times so far. As of now the bandwidth is a mere 5Kbps, and the clone has been stalled once again. It had been running since yesterday morning.

Could you please check what is causing this bandwidth issue, and help resolve it. I will try to initiate a clone again over the weekend.

Regards,
Rajaram

From: Aaron Shang
Sent: Wednesday, September 21, 2016 1:40 AM
To: Rajaram Gurumurthy <rajaram.gurumurthy@pica8.com>
Cc: Lin Du <lin.du@pica8.com>
Subject: Re: the PTP development branch


The branch had been there.

I had finished the build, OK.


And you can always create branches and push out if you like.




--
Aaron

From: Rajaram Gurumurthy
Sent: Wednesday, September 21, 2016 2:38:44 AM
To: Aaron Shang
Cc: Lin Du
Subject: RE: the PTP development branch

Hi Aaron,

Please create a branch from master named as picos_ptp - from a clean build point.
Thanks !

Regards,
Rajaram

From: Lin Du
Sent: Monday, September 19, 2016 9:59 PM
To: Rajaram Gurumurthy <rajaram.gurumurthy@pica8.com>
Cc: Aaron Shang <aaron.shang@pica8.com>; Dan Tuchler <dan.tuchler@pica8.com>
Subject: the PTP development branch

Raj,
Aaron can help creating a new branch for PTP development. It will be merged to master branch after it is fully tested.
Just send an request to Aaron, and he will create it for you and let you know how to check out/in the codes accordingly.
Thanks,
Lin


No virus found in this message.
Checked by AVG - www.avg.com
Version: 2016.0.7797 / Virus Database: 4656/13048 - Release Date: 09/19/16

No virus found in this message.
Checked by AVG - www.avg.com
Version: 2016.0.7797 / Virus Database: 4656/13054 - Release Date: 09/20/16

No virus found in this message.
Checked by AVG - www.avg.com
Version: 2016.0.7797 / Virus Database: 4656/13065 - Release Date: 09/22/16




The branch had been there.

I had finished the build, OK.


And you can always create branches and push out if you like.




--
Aaron

From: Rajaram Gurumurthy
Sent: Wednesday, September 21, 2016 2:38:44 AM
To: Aaron Shang
Cc: Lin Du
Subject: RE: the PTP development branch

Hi Aaron,

Please create a branch from master named as picos_ptp - from a clean build point.
Thanks !

Regards,
Rajaram

From: Lin Du
Sent: Monday, September 19, 2016 9:59 PM
To: Rajaram Gurumurthy <rajaram.gurumurthy@pica8.com>
Cc: Aaron Shang <aaron.shang@pica8.com>; Dan Tuchler <dan.tuchler@pica8.com>
Subject: the PTP development branch

Raj,
Aaron can help creating a new branch for PTP development. It will be merged to master branch after it is fully tested.
Just send an request to Aaron, and he will create it for you and let you know how to check out/in the codes accordingly.
Thanks,
Lin


No virus found in this message.
Checked by AVG - www.avg.com
Version: 2016.0.7797 / Virus Database: 4656/13048 - Release Date: 09/19/16




Tried password pronto or pica8 for root, but all failed.




Seems the `sudo` had something wrong.


louis@Pica203:~/shadowsocks$ sudo make install
Sorry, try again.
Sorry, try again.
Sorry, try again.
sudo: 3 incorrect password attempts


Perhaps the pam module for sudo was configured wrong by mistake.


If you can get root access, can you help remove the two `auth` lines in this file?


/etc/pam.d/sudo
#%PAM-1.0

auth       required   pam_env.so readenv=1 user_readenv=0
auth       required   pam_env.so readenv=1 envfile=/etc/default/locale user_readenv=0
@include common-auth
@include common-account
@include common-session-noninteractive



Thanks.


--
Aaron

From: Simon Yang
Sent: Wednesday, September 21, 2016 10:15:26 AM
To: Louis Zhang; Zoneson Chen; Aaron Shang
Subject: RE: 翻墙方法

Hi Louis,

Your account louis is in sudoer group.

The root account passwd should be pronto or pica8, if that was set.

Thanks,
Simon

From: Louis Zhang
Sent: Tuesday, September 20, 2016 7:00 PM
To: Simon Yang; Zoneson Chen; Aaron Shang
Subject: 答复: 翻墙方法

Simon，so sorry！
Can you tell me the root account，someone  need to use it to pack some service.

发件人: Simon Yang
发送时间: 2016年9月14日 11:04
收件人: Louis Zhang; Zoneson Chen; Aaron Shang
主题: RE: 翻墙方法

Hi Louis,

Sorry for the late reply. I have configured a server with Ubuntu 12.04.5 LTS at 172.16.0.203, and added an account for you. User name and password are louis/louis.

Please login using either ssh or telnet, and check if this server meets your requirement.

Thanks,
Simon

From: Louis Zhang
Sent: Monday, September 12, 2016 8:04 PM
To: Zoneson Chen; Aaron Shang
Cc: Simon Yang
Subject: 答复: 翻墙方法

Zoneson，还是之前的要求，可否能给一台不常用的能上外网的linux机器 ，并告诉我用户名和密码。谢谢！

发件人: Zoneson Chen
发送时间: 2016年9月6日 12:35
收件人: Louis Zhang; Aaron Shang
抄送: Simon Yang
主题: Re: 翻墙方法

Louis and Aaron,

Today (9/5) is US holiday.

I have asked Simon to provide you a VM. So you can install the packages on the VM.

We have 5 public IP addresses (50.197.177.177 - 50.197.177.181). I can allocate 50.197.177.181 for this purpose.

Thanks,

Zoneson

From: Louis Zhang <louis.zhang@pica8.com>
Date: Monday, September 5, 2016 at 6:28 PM
To: Aaron Shang <aaron.shang@pica8.com>
Cc: Zoneson Chen <zoneson.chen@pica8.com>
Subject: 翻墙方法

Aaron，zoneson可能请假了，麻烦你将翻墙需要准备的内容或条件详细描述一下（最好是方法），看美国那边是否满足以及北京这边怎么配合，谢谢！！！

best regards
Louis
--------------------------------------------------
Beijing Pinke Technology Co., Ltd. 5F, Junma Office Building #2, Zhongguancun Nanyitiao Haidian, Beijing .







The code is from Ira Chen, hosted now here:
  http://code.pica8.local/repo/license-server


See files:

  http://code.pica8.local/repo/license-server/tree/master


I never dig into them.






Seems that had been in our main repo:

  http://code.pica8.local/repo/pica8/tree/master/pica/license

  http://code.pica8.local/repo/pica8/tree/master/pica/lib


--
Aaron

________________________________________
From: Lin Du
Sent: Wednesday, August 31, 2016 9:35 AM
To: Tom Jia; James Liao; Zoneson Chen; Tony Du; Leon Li; Aaron Shang
Cc: Yachal Chen; George Guo; Sudhir Modali
Subject: RE: site license design

Tom,
Please provide the old interface as well.
Make sure the old system can work properly.

BTW, the RPC call is in out git server. Aaron know the codes where it is.
Thanks,
Lin

From: Tom Jia
Sent: Wednesday, August 31, 2016 2:30 PM
To: Lin Du; James Liao; Zoneson Chen; Tony Du; Leon Li
Cc: Yachal Chen; George Guo; Sudhir Modali
Subject: Re: site license design


Add Leon in this loop.

Following the previous implementation, I would like to define the schema of new site license as below json object,

{

    "Type": "1GE",

    "Feature":[1, 2,4],

    "Mode":"site",

    "Site Name":"XXXXXXX",

    "id":"0x01F04 ",

    "Expire Date":"2020-10-28",

    "Serials":[8FF03489C01, 8FF03489C02, 8FF03489C03, 8FF03489C04]

}

Let me know if any question.



In addtion, please provide the RPC APIs to access encryption to encrypt the site license file if use Lin's solution.



Thanks.



________________________________
Best regards,
Tom Jia (贾彦民)

________________________________
From: Lin Du
Sent: Wednesday, August 31, 2016 2:03:56 PM
To: James Liao; Zoneson Chen; Tony Du
Cc: Yachal Chen; George Guo; Tom Jia; Sudhir Modali
Subject: site license design


James,

We consider to use the old private key so make the code maintain easier.

Previously, the encryption server is only accessible by portal IP address. The US office IP address will be added so the key encryption can be called from the office directly.



Old license checking will continue to work as before.

Thanks,

Lin



From: James Liao
Sent: Wednesday, August 31, 2016 11:32 AM
To: Lin Du; Zoneson Chen; Tony Du
Cc: Yachal Chen; George Guo; Tom Jia
Subject: Re: ONIE USB installation to HPE AL 6900 for Mezocliq



Engineering team,



Please review the attached spec. Let me know if you have any question.



James





From: Lin Du <lin.du@pica8.com<mailto:lin.du@pica8.com>>
Date: Tuesday, August 30, 2016 at 7:45 PM
To: Zoneson Chen <zoneson.chen@pica8.com<mailto:zoneson.chen@pica8.com>>, Tony Du <tony.du@pica8.com<mailto:tony.du@pica8.com>>, James Liao <james.liao@pica8.com<mailto:james.liao@pica8.com>>
Cc: Yachal Chen <yachal.chen@pica8.com<mailto:yachal.chen@pica8.com>>, George Guo <george.guo@pica8.com<mailto:george.guo@pica8.com>>, Tom Jia <tom.jia@pica8.com<mailto:tom.jia@pica8.com>>
Subject: RE: ONIE USB installation to HPE AL 6900 for Mezocliq



+ James



James, please update the site license solution to the team.

Thanks,

Lin



From: Zoneson Chen
Sent: Wednesday, August 31, 2016 10:38 AM
To: Tony Du
Cc: Yachal Chen; Lin Du; George Guo; Tom Jia
Subject: ONIE USB installation to HPE AL 6900 for Mezocliq



Tony,



Would you mind adding the ONIE USB installation to HPE AL 6900 for Mezocliq release, 2.6.5S4?



Mezocliq only needs this ONIE USB installation for HPE AL 6900. When TOR has been installed by USB, they can use Ethernet via TOR to install HPE AL 6920.



If it is possible, would you mind generating a version to allow them to test? They also like to test site license based on the following serial numbers.



10G = TW50HCS01D

10G = TW50HCS00S

10G = TW50HCS01M

10G = TW50HCS01F

1G = TW5AHF500T

1G = TW5AHF500P



Thanks,



Zoneson








This collaboration actually took few efforts.

Because we had done a `dcs7032q28` before, which is 100G box,

The model of this time, renamed `D6254QS`, is 10G box.

See:
    http://productline.inventec.com/switch/



The reason why it seemingly took much time was the team resource had been all put on the 2.7.3 release, which had many changes in sysinfo. The resource on that would be worthwhile.

Also because of the lack of confirming business situation from Inventec, we didn't spare much effort on that project at the begining.






As lesson learnt, I think we can tidy up major of our release in SDK form, which contains mainly binary code with a few APIs needed.

Thus vendors can build image by themselves, and do the debugging.

Thus the eco-system can be accelerated a lot.

Also, from feedback on the SDK, we can improve our code base from external large scale testings.



--
Aaron

________________________________________
From: James Liao
Sent: Saturday, August 20, 2016 4:48 PM
To: Aaron Shang; Lin Du; support@pica8.com
Subject: Re: Means to send images to Inventec

Aaron,

We should learn from this collaboration to decide
1. Is it worthwhile to do such a collaboration?
2. What can we improve to accelerate the porting and protect our own IP?


The release process is not complicated. We should notify them this is a milestone, and we will take over from here to generate a beta image 2.7.3S1 for Inventec, which Inventec can use to do demo (Sales department can provide them demo licenses). We will enter QA process after they secure the customers. Zoneson will handle the beta-release process to Inventec.

James

On 8/19/16, 11:56 PM, "Aaron Shang" <aaron.shang@pica8.com> wrote:

>Lin,
>
>
>We had provided Gitlab private code repo to co-work with Inventec.
>
>The image building was our task, since we didn't share more code to them.
>
>
>Now after a new image was built OK with crash issue fixed, how can we share this image to them for testing?
>
>Should we use the FTP server?
>If so, then please create one account for them to access.
>
>
>Also, since the old engineering account had been shared with many sides, the password should be changed and share only with limited group of users.
>Any user accessing that account can get all packages. Many of our code can be extracted from the binary packages.
>That's a risk, anyway.
>
>
>--
>Aaron
>





Onie supports HTTP.

So let's use that as reliable means of transfer.

Examples:

http://10.10.50.16/tftpboot/build/release/2.9.1/luxartech-fabric/

http://10.10.50.16/tftpboot/build/release/2.9.1/luxartech-npb/




--
Aaron

From: Tom Jia
Sent: Thursday, May 11, 2017 9:20:24 AM
To: Zoneson Chen; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat; George Guo; Aaron Shang; Jacob Wang; Vic Lan
Subject: Re: Ready - 2.9.1 Beta Release

George, Aaron,
Could you please take a look?
Many thanks.


Best regards,
Tom Jia (贾彦民)



From: Zoneson Chen
Sent: Thursday, May 11, 2017 2:25 AM
To: Tom Jia; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat
Subject: Re: Ready - 2.9.1 Beta Release

Tom,

Thank you for releasing 2.9.1.2!

AS4610-54p always reports the following error message after restarting PicOS service:

iproc_smb_data_send:Send: iproc-smb1 Error in transaction 2 to device xac, exiting
I filed bug#7490 for it.

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, May 9, 2017 at 2:23 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, "plm@pica8.com" <plm@pica8.com>, Lin Du <lin.du@pica8.com>, Frank Zhang <frank.zhang@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Subject: Re: Ready - 2.9.1 Beta Release

Hello Zoneson,
I copied the 2.9.1.2/e9c9eaf code to @10.10.50.16:/tftpboot/build/release/2.9.1.2. The new code fixed #7472, a severe regression.

Bug#7472 - Fail to set "Static IP" in picos_boot

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Tom Jia
Sent: Wednesday, May 3, 2017 4:50:36 PM
To: Zoneson Chen; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat
Subject: Re: Ready - 2.9.1 Beta Release

Hi Zoneson,
I updated the 2.9.1 code @10.10.50.16:/tftpboot/build/release/2.9.1.1 (7d75835). Certainly, the packet loss issue on AS5812 was fixed. For ease of tracking, I renumbered the version of the new code - 2.9.1.1. Let me know if any concern.
Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen
Sent: Friday, April 28, 2017 11:14:27 PM
To: Tom Jia; plm@pica8.com; Lin Du; Frank Zhang
Subject: Re: Ready - 2.9.1 Beta Release

Tom,

Thank you for the heads up!

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Friday, April 28, 2017 at 4:07 AM
To: "plm@pica8.com" <plm@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Frank Zhang <frank.zhang@pica8.com>
Subject: Re: Ready - 2.9.1 Beta Release

Hello Zoneson,
An issue caused by the new feature - queue buffer enhancement -  was found on AS5812.  It can be reproduced as following steps:

    - reset speed of 2 ports
    - receive 10mbps traffic from the 2 ingress ports
    - forward the traffic out of one single port
    - result - packet loss on ingress ports

The issue only happens on AS5812. Frank found the root cause and fixed it. I will update the 2.9.1 code after the build is ready.

Thanks.

Best regards,
Tom Jia (贾彦民)



From: Tom Jia
Sent: Thursday, April 27, 2017 6:20 PM
To: plm@pica8.com; Zoneson Chen; Sharad Ahlawat; support@pica8.com; Lin Du
Subject: Ready - 2.9.1 Beta Release

Dear PLM,
I copied 2.9.1 beta code here @10.10.50.16:/tftpboot/build/release/2.9.1 (Commit ID: ad4256e). Please help review 2.9.1 release notes at,
http://10.10.50.11/notes/index.php?version=PicOS+2.9.1
Please note, #7110 only happens on LuxarTech fabric version of 2.9.1 release.
And additionally, all features and bug fixes of 2.9.0, which is a specific AS4610 release for Verizon-ITNUC, are also added to 2.9.1 except
    - #7142, Verizon-ITNUC customization behavior, enter cli by default
    - #6584, upgrade2, will support on 3.0.0
Have more details at 2.9.0 release notes at,
http://10.10.50.11/notes/index.php?version=PicOS+2.9.0

Hi Sharad,
I know you are looking forward to 100G-NPB version of 2.9.1 for LuxarTech, which is ready here @10.10.50.16:/tftpboot/build/release/2.9.1/luxartech-npb. You have already got configuration document from Lisa. As you know, UDF matching is also added to 2.9.1 100G-NPB version.

Certainly, we never forgot LuxarTech Fabric version of 2.9.1 which is here @10.10.50.16:/tftpboot/build/release/2.9.1/luxartech-fabric. I would like to use Iris's test plan to explain the special features of LuxarTech fabric version as attached spreadsheet.

Thanks.

Best regards,
Tom Jia (贾彦民)






438k lines of patch.
18MiB in size.

Usually patches of dozen of lines, no more than hundreds, are sustainable, and make senses.

Splitting them would make maintenance and trouble-shooting easier, esp. you need to patch one after another...




--
Aaron

From: Aaron Shang
Sent: Thursday, May 11, 2017 9:33:02 AM
To: Tom Jia; Zoneson Chen; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat; George Guo; Jacob Wang; Vic Lan
Subject: Re: Ready - 2.9.1 Beta Release

Please check:

os-dev/linux-kernel/kernel-patch/linux-3.16-as4610.patch:+static int iproc_smb_data_send(struct i2c_adapter *adapter,
os-dev/linux-kernel/kernel-patch/linux-3.16-as4610.patch:+        rc = iproc_smb_data_send(i2c_adap, addr, &info);
os-dev/linux-kernel/kernel-patch/linux-3.16-as4610.patch:+          rc = iproc_smb_data_send(i2c_adap, addr, &info);




Anyway, a patch of    438402   lines is awesome/terrible...


--
Aaron

From: Tom Jia
Sent: Thursday, May 11, 2017 9:20:24 AM
To: Zoneson Chen; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat; George Guo; Aaron Shang; Jacob Wang; Vic Lan
Subject: Re: Ready - 2.9.1 Beta Release

George, Aaron,
Could you please take a look?
Many thanks.


Best regards,
Tom Jia (贾彦民)



From: Zoneson Chen
Sent: Thursday, May 11, 2017 2:25 AM
To: Tom Jia; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat
Subject: Re: Ready - 2.9.1 Beta Release

Tom,

Thank you for releasing 2.9.1.2!

AS4610-54p always reports the following error message after restarting PicOS service:

iproc_smb_data_send:Send: iproc-smb1 Error in transaction 2 to device xac, exiting
I filed bug#7490 for it.

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, May 9, 2017 at 2:23 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, "plm@pica8.com" <plm@pica8.com>, Lin Du <lin.du@pica8.com>, Frank Zhang <frank.zhang@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Subject: Re: Ready - 2.9.1 Beta Release

Hello Zoneson,
I copied the 2.9.1.2/e9c9eaf code to @10.10.50.16:/tftpboot/build/release/2.9.1.2. The new code fixed #7472, a severe regression.

Bug#7472 - Fail to set "Static IP" in picos_boot

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Tom Jia
Sent: Wednesday, May 3, 2017 4:50:36 PM
To: Zoneson Chen; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat
Subject: Re: Ready - 2.9.1 Beta Release

Hi Zoneson,
I updated the 2.9.1 code @10.10.50.16:/tftpboot/build/release/2.9.1.1 (7d75835). Certainly, the packet loss issue on AS5812 was fixed. For ease of tracking, I renumbered the version of the new code - 2.9.1.1. Let me know if any concern.
Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen
Sent: Friday, April 28, 2017 11:14:27 PM
To: Tom Jia; plm@pica8.com; Lin Du; Frank Zhang
Subject: Re: Ready - 2.9.1 Beta Release

Tom,

Thank you for the heads up!

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Friday, April 28, 2017 at 4:07 AM
To: "plm@pica8.com" <plm@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Frank Zhang <frank.zhang@pica8.com>
Subject: Re: Ready - 2.9.1 Beta Release

Hello Zoneson,
An issue caused by the new feature - queue buffer enhancement -  was found on AS5812.  It can be reproduced as following steps:

    - reset speed of 2 ports
    - receive 10mbps traffic from the 2 ingress ports
    - forward the traffic out of one single port
    - result - packet loss on ingress ports

The issue only happens on AS5812. Frank found the root cause and fixed it. I will update the 2.9.1 code after the build is ready.

Thanks.

Best regards,
Tom Jia (贾彦民)



From: Tom Jia
Sent: Thursday, April 27, 2017 6:20 PM
To: plm@pica8.com; Zoneson Chen; Sharad Ahlawat; support@pica8.com; Lin Du
Subject: Ready - 2.9.1 Beta Release

Dear PLM,
I copied 2.9.1 beta code here @10.10.50.16:/tftpboot/build/release/2.9.1 (Commit ID: ad4256e). Please help review 2.9.1 release notes at,
http://10.10.50.11/notes/index.php?version=PicOS+2.9.1
Please note, #7110 only happens on LuxarTech fabric version of 2.9.1 release.
And additionally, all features and bug fixes of 2.9.0, which is a specific AS4610 release for Verizon-ITNUC, are also added to 2.9.1 except
    - #7142, Verizon-ITNUC customization behavior, enter cli by default
    - #6584, upgrade2, will support on 3.0.0
Have more details at 2.9.0 release notes at,
http://10.10.50.11/notes/index.php?version=PicOS+2.9.0

Hi Sharad,
I know you are looking forward to 100G-NPB version of 2.9.1 for LuxarTech, which is ready here @10.10.50.16:/tftpboot/build/release/2.9.1/luxartech-npb. You have already got configuration document from Lisa. As you know, UDF matching is also added to 2.9.1 100G-NPB version.

Certainly, we never forgot LuxarTech Fabric version of 2.9.1 which is here @10.10.50.16:/tftpboot/build/release/2.9.1/luxartech-fabric. I would like to use Iris's test plan to explain the special features of LuxarTech fabric version as attached spreadsheet.

Thanks.

Best regards,
Tom Jia (贾彦民)






Please check:

os-dev/linux-kernel/kernel-patch/linux-3.16-as4610.patch:+static int iproc_smb_data_send(struct i2c_adapter *adapter,
os-dev/linux-kernel/kernel-patch/linux-3.16-as4610.patch:+        rc = iproc_smb_data_send(i2c_adap, addr, &info);
os-dev/linux-kernel/kernel-patch/linux-3.16-as4610.patch:+          rc = iproc_smb_data_send(i2c_adap, addr, &info);




Anyway, a patch of    438402   lines is awesome/terrible...


--
Aaron

From: Tom Jia
Sent: Thursday, May 11, 2017 9:20:24 AM
To: Zoneson Chen; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat; George Guo; Aaron Shang; Jacob Wang; Vic Lan
Subject: Re: Ready - 2.9.1 Beta Release

George, Aaron,
Could you please take a look?
Many thanks.


Best regards,
Tom Jia (贾彦民)



From: Zoneson Chen
Sent: Thursday, May 11, 2017 2:25 AM
To: Tom Jia; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat
Subject: Re: Ready - 2.9.1 Beta Release

Tom,

Thank you for releasing 2.9.1.2!

AS4610-54p always reports the following error message after restarting PicOS service:

iproc_smb_data_send:Send: iproc-smb1 Error in transaction 2 to device xac, exiting
I filed bug#7490 for it.

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Tuesday, May 9, 2017 at 2:23 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, "plm@pica8.com" <plm@pica8.com>, Lin Du <lin.du@pica8.com>, Frank Zhang <frank.zhang@pica8.com>, Sharad Ahlawat <Sharad.Ahlawat@pica8.com>
Subject: Re: Ready - 2.9.1 Beta Release

Hello Zoneson,
I copied the 2.9.1.2/e9c9eaf code to @10.10.50.16:/tftpboot/build/release/2.9.1.2. The new code fixed #7472, a severe regression.

Bug#7472 - Fail to set "Static IP" in picos_boot

Thanks.

Best regards,
Tom Jia (贾彦民)


From: Tom Jia
Sent: Wednesday, May 3, 2017 4:50:36 PM
To: Zoneson Chen; plm@pica8.com; Lin Du; Frank Zhang; Sharad Ahlawat
Subject: Re: Ready - 2.9.1 Beta Release

Hi Zoneson,
I updated the 2.9.1 code @10.10.50.16:/tftpboot/build/release/2.9.1.1 (7d75835). Certainly, the packet loss issue on AS5812 was fixed. For ease of tracking, I renumbered the version of the new code - 2.9.1.1. Let me know if any concern.
Thanks.

Best regards,
Tom Jia (贾彦民)


From: Zoneson Chen
Sent: Friday, April 28, 2017 11:14:27 PM
To: Tom Jia; plm@pica8.com; Lin Du; Frank Zhang
Subject: Re: Ready - 2.9.1 Beta Release

Tom,

Thank you for the heads up!

Thanks,

Zoneson

From: Tom Jia <tom.jia@pica8.com>
Date: Friday, April 28, 2017 at 4:07 AM
To: "plm@pica8.com" <plm@pica8.com>, Zoneson Chen <zoneson.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Frank Zhang <frank.zhang@pica8.com>
Subject: Re: Ready - 2.9.1 Beta Release

Hello Zoneson,
An issue caused by the new feature - queue buffer enhancement -  was found on AS5812.  It can be reproduced as following steps:

    - reset speed of 2 ports
    - receive 10mbps traffic from the 2 ingress ports
    - forward the traffic out of one single port
    - result - packet loss on ingress ports

The issue only happens on AS5812. Frank found the root cause and fixed it. I will update the 2.9.1 code after the build is ready.

Thanks.

Best regards,
Tom Jia (贾彦民)



From: Tom Jia
Sent: Thursday, April 27, 2017 6:20 PM
To: plm@pica8.com; Zoneson Chen; Sharad Ahlawat; support@pica8.com; Lin Du
Subject: Ready - 2.9.1 Beta Release

Dear PLM,
I copied 2.9.1 beta code here @10.10.50.16:/tftpboot/build/release/2.9.1 (Commit ID: ad4256e). Please help review 2.9.1 release notes at,
http://10.10.50.11/notes/index.php?version=PicOS+2.9.1
Please note, #7110 only happens on LuxarTech fabric version of 2.9.1 release.
And additionally, all features and bug fixes of 2.9.0, which is a specific AS4610 release for Verizon-ITNUC, are also added to 2.9.1 except
    - #7142, Verizon-ITNUC customization behavior, enter cli by default
    - #6584, upgrade2, will support on 3.0.0
Have more details at 2.9.0 release notes at,
http://10.10.50.11/notes/index.php?version=PicOS+2.9.0

Hi Sharad,
I know you are looking forward to 100G-NPB version of 2.9.1 for LuxarTech, which is ready here @10.10.50.16:/tftpboot/build/release/2.9.1/luxartech-npb. You have already got configuration document from Lisa. As you know, UDF matching is also added to 2.9.1 100G-NPB version.

Certainly, we never forgot LuxarTech Fabric version of 2.9.1 which is here @10.10.50.16:/tftpboot/build/release/2.9.1/luxartech-fabric. I would like to use Iris's test plan to explain the special features of LuxarTech fabric version as attached spreadsheet.

Thanks.

Best regards,
Tom Jia (贾彦民)





