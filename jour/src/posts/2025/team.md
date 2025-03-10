
---
title: TEAM
date: 2025-03-03
---

业务：
1. 适配多款不同配置规格设备Linux内核多系统功能的开发，完成软件编码开发任务，达成开发目标。
2. 负责交换机产品Linux内核多系统功能BUG修复与版本发布，完成软件功能优化，提高产品品质。
3. 完成项目所需的PAM LDAP、IPsec VPN、image 定制等方面的工程支持。
4. 开发基础设施与版本构建/发布/提测的容器化、自动化。
5. ROOTFS的裁剪/优化，以及分析多类型/多版本供应。
6. 实现MIPS/ARM机型适配的内核编译/裁剪/启动等支持工作。完成软件开发需求，达成设备适配等季度开发目标。
7. 通过软件定制流程，负责客户产品软件定制需求分析，输出定制需求解决方案，实现需求落地。
8. 负责客户复杂产品软需求与问题处理，输出问题解决方案。

团队：
1.团队成员分工合理，积极推进负责模块的功能实现与问题修复。
2.提升团队成员的工作满意度和创造力，解决问题的能力，每个人都能在工作中成长。

----

进行全面的专项的安全检测、渗透攻击等验证和防护。
研发很注重安全实践，最新的release会best effort保证基本安全，对release时间很久的版本尚不能保证及时的安全补丁更新。
对于客户提出的安全隐患问题和对近期评分很高的（cve 8-10）的安全事件我们会及时给出响应、攻击缓解方案。
我们可以接受接受外部安全检测，-- 但是，结果可能会有安全隐患，检测结果很差则影响商誉。
我们无法提供产品的安全验证报告。 缺乏 没有资源和验证系统。


## shirley

commit的时候怎么做胡扯检查吗？

比如配置了ldap现在不让再配置tacacs
互斥检查
嗯嗯
在rtrmgr 做
需要存一下，然后拿出来比


    aaa {
        ldap {
            disable: bool = true;
            uri: txt = "";  /* ldap://sso.example.net:xxx, or ldaps://sso.example.net:yyy */
            uri: txt = "";              /* ldap[s]://<domain.tld|ipv4|ipv6>[:port] */
            base: txt = "";
            binddn: txt = "";
            bindpw: txt = "";
            filter-passwd: txt = "";
            filter-group: txt = "";
            */
            vrf: txt;
        }



git submodule update --init --recursive


why need to clean if tp changed


## workspace


http://10.37.2.200:8083/workspace/#/pc


登录的用户名/密码是 : bjtest / 123456


http://10.37.2.200:8083/workspace/doc/help//default_auto.htm

\
直接用域账号登录即可（初次登录会重启，这个是正常现象），


账号：bj01 到  bj10
密码都是：123456


## Assets

GD-DZ-006210	显示器	27英寸2K显示器	13ms01t0am0901	HKC	北京	领用	商青华	FS004183

GD-DZ-006542	显示器	27英寸2K显示器		HKC	北京	领用	商青华	FS004183



网络限制
目前的可以访问的网段如下，也可以看下是否还有遗漏或者需要修改的
10.37.2.1-254
10.50.0.1-10.50.255.254
10.10.50.1-254
10.37.16.10
10.36.16.115
10.36.16.199
10.36.16.194
10.37.16.20
10.36.16.100
10.10.81.1-254
10.36.244.1-254
10.56.20.1-254
10.56.30.1-254
10.10.51.1-254
10.10.53.1-254



深圳市飞速创新技术股份有限公司       
FS.COM Limited
深圳市南山区粤海街道大冲社区华润置地大厦C座1903-1904
Room 1903-1904, Tower C, China Resources Land Building, Dachong Community, Yuehai Street, Nanshan District, Shenzhen
李粤湘15616161809
飞速创新通信技术（上海）有限公司    
FS Innovation (Shanghai) Co., Ltd 
上海市静安区新闸路668号上海利园办公楼1201单元
Room 1201 ,Lee Gardens,668,688 Xinzha Road,Shanghai , the PRC
陶雪洁13818411761
飞速创新通信技术（北京）有限公司      
FS Innovation (Beijing) Co., Ltd
北京市海淀区知春路63号51号楼二层202-205室
Room 202-205,2nd floor,  #63 Zhichunlu Road, Haidian District, Beijing
王燕 15801291126

飞速创新通信技术（南京）有限公司      
FS Innovation (Nanjing) Co., Ltd
江苏省南京市雨花台区软件大道170-1号天溯科技园1栋102室
Room 102, Tower #1,Tiansu Science park, #170-1 Ruanjianyuan road, Yuhuatai District, Nanjing
李明     15701238920


深圳市飞速创新技术股份有限公司       
FS.COM Limited
深圳市南山区粤海街道大冲社区华润置地大厦C座1903-1904
Room 1903-1904, Tower C, China Resources Land Building, Dachong Community, Yuehai Street, Nanshan District, Shenzhen
李粤湘15616161809
飞速创新通信技术（上海）有限公司    
FS Innovation (Shanghai) Co., Ltd 
上海市静安区新闸路668号上海利园办公楼1201单元
Room 1201 ,Lee Gardens,668,688 Xinzha Road,Shanghai , the PRC
陶雪洁13818411761
飞速创新通信技术（北京）有限公司      
FS Innovation (Beijing) Co., Ltd
北京市海淀区知春路63号51号楼二层202-205室
Room 202-205,2nd floor,  #63 Zhichunlu Road, Haidian District, Beijing
王燕 15801291126

飞速创新通信技术（南京）有限公司      
FS Innovation (Nanjing) Co., Ltd
江苏省南京市雨花台区软件大道170-1号天溯科技园1栋102室
Room 102, Tower #1,Tiansu Science park, #170-1 Ruanjianyuan road, Yuhuatai District, Nanjing
李明     15701238920


请联系IT的 邓靖 Dennis Deng 和 张涛 Nikola Zhang。如果北京用户达限，可走南京。

NJ / BJ / WH VPN IP:

61.132.57.166
113.57.199.56
218.240.159.78

Port:
4433建议用武汉 VPN，账号密码即公司域邮箱账号



## OpenWifi




1、目前工作中遇到的问题是什么？是否需要支持和帮助
对整个PICOS系统运转流程不是很透彻，除了自己熟悉的模块，遇到其他问题无法对症下药，好在能在云文档找到相应的解决办法。组内同事都非常厉害，遇到问题就直接询问了，不是很需要额外的支持和帮助。
2、工作中存在哪些不足？
心急！这是我个人最大的问题，在这两个月下来，我主要参与的就是syslog模块的学习和相应bug修复。每次对于测试提交给我的bug，我一般都能在两天内解决。但在解决完成前，过于急切验证自己的解决结果，总是在这一阶段出现了许多不该出现的错误。虽然这并不影响最终结果，但是浪费了许多不必要的时间。
例如在修改bug17624时，已经得出了好的修改方案，急于编包验证，出现了几个失误：第一次编包，编译了s3000系列的包，然而此bug只在除3000以外的系列出现；第二次编包，将代码修改错误，此时正好将代码修改的更简洁，却在if中少写了一个括号，导致编译失败。这两个错误虽然影响不大，但浪费了大量时间。
3、下阶段的工作规划
首先，继续解决syslog模块上未来会出现的问题，这个模块学习了两个月，相较于其他部分这里会熟悉些。
其次，参与组内的mips研发工作，当然，核心内容还是在syslog这一模块
最后，学习新的知识：TIP OpenWifi
4、在试用期的感受
首先我必须要肯定的一点是：FS的带教制度非常好，我的带教也非常负责优秀。在我业务初期，能及时帮我指出我要如何去解决问题的方向，而不是直接告诉我解决问题的答案，让我自己找到合适的解决方法。当我在一个问题死磕不下时，也能提出相当有建设性的意见。这些对我的提升都很大，让我在处理业务上有了很多方法。相较于同一批入职的同事，自我感觉我的工作能力是要比一部分人要好很多。
其次是组内氛围好，虽然我们Linux组被分为驱动和内核，但日常工作生活还是在一起。我作为新人，遇到问题找任何一位组内同事，都能耐心帮我解答。为了锻炼业务能力，在他们解决bug的同时，还时常带上我，让我一起参与解决。
最后工作环境很舒适。在工作之余使用茶水间各种原材料调制饮品，也成为了我工作期间的乐趣。
5、对于部门工作流程、工作分工有哪些建议
我建议部门基础学习内容还需添加，虽然我们每个组各有分工，处理的代码文件也不相同，但我还是希望以后的新员工都能共同学习这几个文件：shell文件，tp文件，cc文件。这样对于整个picos系统运行更容易理解。
6、其他
今年软件研发部搬到创新天地是迟早，并且是确定的事吗。
我现在学习的sonic、TIP OpenWifi将会如何接入我们公司现在的系统呢。
7、直接上级根据谈话情况总结执行情况。

----




基于近期战略指引，为实现“通过打造统一的软件控制平台，实现底层统一管理，推动多产品销售和客户复购，巩固商业成功的核心——复购驱动增长”的商业成功目标，结合我司内部业务情况，同时调研参考新华三产研体系运转逻辑，在PBG各BU负责人、软件体系核心负责人以及各BU HRBP的共同思考与探讨下，共同初步梳理优化完善PBG核心组织运转逻辑及架构模式。现基于现阶段产出内容进行一期汇报，重点汇报【组织架构运转模式】、【核心角色职能】、【关键负责人匹配落位】、【团队配置初步规划】，进行一轮对齐。

一、架构核心导向
1、瞄准业务三层架构与商业成功
顶层：瞄准商业成功——Ampcon软件平台实现平台化、产品化、商业化，形成核心技术的积累与复用
中间层：产品化过程——根据软件平台、产品硬件、封装适配等需求，明确分工，形成小团队作战
基础层：优化统一与持续选代——公共平台部门，建立统一的产品化标准、软件标准等
2、小团队化与责任分工，目标对齐，指标唯一且聚焦，责任到人

二、架构核心优化调整点
1、新增【Ampcon PBU】部门，面向市场和客户，通过AMPCON产品的规划、分析，将Ampcon推向市场，更好实现商业成功
2、新增【软件产品开发部】部门，下设【交换机】、【无线AP】、【光网络】等产品线方向的【软件封装团队】【产品适配】团队，分别负责软件的裁剪封装，和SDK&驱动的开发与适配（下设小小组进行细化分工管理），同时虚线进入PBU/PDT，与PBU/PDT团队共同协同与开展工作
3、原交换机测试团队分工细化，拆分为【数据中心测试团队】和【园区网测试团队】，实体归属BU，实现基于经营单元责任到人，同时横向设立交换机测试整体负责人，有利于整体交换机测试规范、标准及人员发展评估具备一定统一性
4、优化原【软件研发部】，更新调整为【软件平台部】，进一步明确作为技术突破支撑的平台定位，解决统一性问题，并下设【交换/路由平台】、【无线平台】、【光传输平台】组织，确保基于不同领域的协议与技术功能特性，进行技术研究与支撑。同时，下设【交换机平台测试】组织，确保平台交付的协议的稳定与可靠性
5、优化并健全【PBU/PDT】产品线虚实团队及运作模式。
①新增相关角色。以数据中心和园区网为例，在原【产品经理】团队基础上，新增【硬件团队】、以及虚线进入的相关团队——【软件封装团队】【产品适配团队】【软件维护团队】【产品市场代表】【工业设计代表】，形成在纵向围绕PDT产品经营单元业绩增长，在横向实现各个职能专业方向拉通的矩阵式、小团队化高效作战组织
②产品品类进一步责任到人。在PDT品类基础上，进一步细分产品品类并到责任小组/责任人，确保瞄准品类增长，进行责任夯实，并为未来品类精细化运作深耕以及产品经理团队扩充与人才孵化提供有力支撑
6、新增【自动化测试部】平台部门，负责针对平台测试与产品测试提供自动化测试技术支撑
三、核心角色及职责
【Ampcon PBU】相关角色
①产品经理（Ampcon）：为AMPCON产品推向市场的成功负责，包括AMPCON产品的规划、分析、产品从0-1全生命周期
②软件架构师（Ampcon）：负责统筹平台架构的研发，版本发布的进度与质量
③软件开发工程师：负责Ampcon产品的软件设计，开发，维护，自测试工作
④UX设计师：负责产品的UX设计与UI设计
⑤测试工程师：负责保障AMPCON产品的质量，包括产品的功能、性能、用户体验等
【各个PBU/PDT】相关角色
①产品经理：为产品的商业成功负责，包括产品的规划、分析以及产品从0-1全生命周期
②硬件工程师：负责产品的硬件标准定义，包括风扇、电源、设备结构、关键元器件等
③工业设计（代表）-虚线：通过用户需求洞察和设计创新，确保产品的外观、体验在市场竞争中具备竞争力
④产品市场（代表）-虚线：负责行业趋势、客户需求、竞品信息，并对供应链资源整合分析，并引入合格供应商
⑤软件封装-协议工程师-虚线：负责对综合平台软件协议进行的裁剪，封装
软件封装-Linux内核工程师-虚线：负责为软件包提供适合的内核版本，并对Linux内核进行裁剪
⑦产品适配-SDK工程师：负责SDK的开发、适配与维护
产品适配-驱动工程师-虚线：负责驱动的开发、适配与维护
⑧软件维护-协议工程师-虚线：负责对软件进行维护与定制
【软件平台部】相关角色
①软件首席架构师：负责统筹平台架构的研发，版本发布的进度与质量
②软件架构师：负责相关板块的架构设计与开发管理工作
③嵌入式开发工程师（协议）：负责平台代码的开发
④测试工程师（平台测试）：负责平台协议测试

四、团队配置计划
1、关键人才引入需求初步对齐
【PBU】
数据中心交换机硬件工程师（L4-L5）
园区网交换机硬件工程师（L4-L5）
光模块硬件工程师（L3-L4）
【软件产品开发部】
光网络-系统架构师（L4-L5）
无线AP-系统架构师2名（L4-L5）：已在录用流程中
【软件平台部】
 无线平台-管理协议-系统架构师（L4-L5）
光传输平台-光层协议-系统架构师（L4-L5）
2、产品经理内部选拔培养
基于当前存在产品经理岗位人员短缺及负责人兼任多职的现状，明确培养思路，搭建产品经理人才梯队

五、下一步计划
1、基于组织运作模式，进一步细化团队人才配置需求，明确编制规划与人力投入
2、进一步审视优化关键负责人落位情况，基于最新职务职级进行匹配校验
3、各个小团队成员匹配落位，各就各位责任明确，并与最新职务职级进行匹配校验，并结合岗位需求，导出晋升需求，实施开展培训与认证工作
4、进一步梳理明确关键人才需求与画像，推进人才引入工作
5、推进考核与激励相关工作

以上为基于近期战略会议，输出的一期组织架构优化进展资料，请Daniel指导与对齐，在确认相关运转逻辑与思路后将我们进一步完善并细化补充相关内容，并同步开展相关人才工作



## 24Q4

交换机	"SDK芯片适配组
Linux驱动开发组@付文明@兰晓伟"	800G AI、园区平台适配	"1. N9600-64OD
2. EX3400-24TP
3. Q3适配未发布平台"	"10月：
修复td4适配高优先级问题；
推进园区s3000机型和mips机型适配；

11月：
修复重要功能问题，发布td4基础版本；
完成s3000机型适配和mips机型适配；

12月：
升级hsdk，完成th4和th5基础适配版本；
完成s3000裁剪和分支合并；"	×	"TD4已发布ESS版本，问题修复完成度85%；
TH4已适配基础功能，问题修复完成度75%；
TH5已适配基础功能，问题修复完成度75%；
园区s3000机型已完成发布，问题修复完成度95%；
园区mips机型已完成适配，led问题已解决；"	"TD4的IPMC，igmp-snooping，qinq，pfc-watchdog等功能尚未完成；
TH4还有一些bug没有解决；
TH5的roce功能还有部分没有完成；
园区s3270机型还需要进一步裁剪；"	"sdk升级HSDK，代码接口和功能实现有发生较大变化，需要解决的问题较多；
高性能机器和测试仪器资源较少，导致很多问题不能并行处理；
核心开发人力不足，部分功能需要从0开始研究，相对影响进度；
s3000机型内存较小，系统和代码需要裁剪部分较多，对功能和稳定性可能会产生影响；"	"完成hsdk和ltsw相关培训，在首个ltsw的机型开发完成后，其余机型开发难度会相应降低；
使用hsdk模拟器完成部分逻辑表和脚本测试，提高并行进度；
对于可以复用机器的情况，尽量复用以提高开发测试环境利用率；
增强对初级开发人员的培训，模块化分工提高学习和开发效率；
加强代码审核，持续优化代码，提高系统运行效率和稳定性；"													


"工作总结
PicOS: 
      1. 数据中心特性完成mLAG + EVPN的主要开发任务，以及EVPN MultiHoming场景下VPLAG的优化、以及EVPN其它问题的修复，实现MPLS L3 VPN及ECMP功能支持。
      2. 园区增加了端口的各种拆分模式，支持1分2、1分4、及1分8等不同模式，以及永久POE、OVS POE功能的扩展。以及DHCP、ND Inspection、INBAND ZTP相关特性，以及WEB功能的优化、完善。跨季度的堆叠功能的设计、架构优化、更新开发任务，预计在Q1完成开发任务，在Q2开始测试工作。
      3. AI无损网络特性开发的开发。
      4. 以及TD4、TH5芯片的支持。

Ampcon:
      1. AmpCon-DC：完成Linux网卡纳管相关业务实现，完成Telemetry 系统信息/ARP/MAC相关信息获取 + 监控告警信息，完成DLB相关配置+监控功能，根据规划推进Underlay配置自动化下发功能（对标Juniper Apstra）
      2. AmpCon-Campus：完成Telemetry 系统信息/ARP/MAC相关信息获取 + 监控告警信息，初步完成AmpCon 2.x版本AWS云端部署并通过OpenVPN打通NAT完成纳管，根据规划推进配置自动化下发功能（对标Juniper Mist）
      3. AmpCon-T：完成FMT设备主控板+5款业务板纳管，与光传输产品+供应商对接细节功能实现，对不支持的功能提出对应要求，推动项目进行

流程制度： 
1 初期部门接入需求分析不够仔细，导致很多需求边分析边设计边开发，致使质量与进度都有所不足。在Q4中完成了IPD相关研发流程的建设，并在目前开展项目中试跑，
从接受需求->分析需求->需求确定->研发设计->代码开发/自测试->测试 形成标准的流程执行， 并对相关技术评审会议进行开展， 从流程质量的角度提高相关项目管理的能力
2 针对Q3的绩效初步进行了绩效数据化的实施， 数据化结果与客观观察的工作表现成正相关。
3 完成了培训课程设计与考试
下一步继续深化流程体系的建设， 并把培养策略更加标准化且更加深化基于目标结果的培养"				



## SOP

不来：
切到onie rescue模式，blkid 找到PicOS分区（比如/dev/sda5)，mount /dev/sda5 /mnt;
然后将/mnt/etc/nos-start-mode 内容改为"xorp_defaultcli=false“;
再reboot后ssh登录就会直接进入shell，此时再systemctl stop picos-monitor防止monitor重启box。
看看/tmp/log/messages报错信息。


qsfp为例：
./build.sh --driver as9716_32d  <= 得到各个ko文件
在盒子上：（替换/usr/lib/modules/5.10.23/extra/qsfp.ko）
rmmod qsfp
把ko文件替换/usr/lib/modules/5.10.23/extra/qsfp.ko
modprobe qsfp <= 使用新的ko文件
查看SYSFS文件：
/sys/class/swmon/


驱动框架代码路径：
os-dev/drivers/swmon/
跟驱动相关的内核代码路径：
linux/drivers/hwmon


光模块SFF（SFP/QSFP）
MONITOR（FAN控制、内存监控、CPU监控、文件监控等）
TCA1116 （主要用于S3000系列）
CTRL: POE reset/enable
RBOOT安装、升级、ONIE安装、
PicOS启动失败问题、phy reset问题、
紧急bug fix
姚博凯
FAN
SENSOR
MONITOR（进程控制等）
system-diag
rboot mkimg.sh （Makefile及image构建）
某些DHCP问题
RBOOT安装、升级、ONIE安装、PicOS启动失败问题、
紧急bug fix

杨俊豪

LED
PSU/PMBUS
SWMON
LICENSE
TACACS+（NSS/OPENSSH）
USB monitor （仅仅DELL某几个盒子）
升级、ONIE安装、配置丢失问题、LICENSE问题、合成image（x86/x86h/s3000）问题

陈文磊
EEPROM/HWINFO
CTRL-DEV
WATCHDOG
INITRD（主要用于upgrade）
save_config
eth0/ethX/uDev/DHCP
NSS/OPENSSH
升级、ONIE安装、配置丢失问题、管理口丢IP（DHCP相关）和丢路由问题


朱帅
BUTTON
RTC/NTP
RADIUS（NSS/OPENSSH）
picos_boot
pca954x
pca964x（用于N8560-64C）
syslog
core(ulimit机制)
RTC/NTP/date/timezone时间问题、
升级、ONIE安装

张博伟
CPLD
FPGA
ko/CFG机制（用于N8560系列）
buildroot（主要用于S3000系列）
user bde/kernel bde驱动
北京盒子相关问题

通用部分
ONIE安装
升级(upgrade/upgrade2/nos-rollback/nos-boot-mode）
BUILD/MAKE image
rboot安装
近期（2024Q4）：
升级和ONIE安装问题：陈文磊和杨俊豪
rboot安装问题：姚博凯和肖龙飞

待定部分

1）DHCP、ZTP、SYSTEMD、IPROUTE2、NFT/NETFILTER；
2）内核选项裁剪、内核PATCH、ARM驱动的DTS；
3）MTD驱动、NIC驱动、I2C驱动、PCI驱动、USB驱动；
4）GRUB、UEFI、UBOOT；



- Rick Zhong (rick.zhong@pica8.com,仲昭勇)

He got his BA degree on Computer Science and Technology from Nankai University.

Before joining in Pica8, Rick worked in Spirent, Nokia Siemens and Huawei for more than ten years.

- Chen Ji (chen.ji@pica8.com,冀宸)joined our L2/L3 team as software engineer today.

He got his BA degree on Electronic science and Technology from Northwest University.

Before joining in Pica8,Chen worked in Ericsson for several years and worked in Beijing institute of Hangzhou Huasan Communication Technology Co.LTD for short time.

- Ivan Li(Ivan.li@pica8.com,李步骖)
Ivan graduated this year. He got his BA degree on Information Engineering and got his MS degree on Optical Engineering from Zhejiang
University.

- Richard Zhang(Richard.zhang@pica8.com,张立强)
Richard got his BA degree on Materials Science and Engineering from Northwestern Polytechnical University.
Richard has rich experience in Linux and Project Management.

- Leo Fan(Leo.fan@pica8.com,樊立鹏)
Leo got his MS degree on Communication and Information System from Nanjing University of Posts and Telecommunications last year.
Before joining in Pica8,Leo worked in ZTE.

- Eagle Yang(Eagle.yang@pica8.com,杨丹)
Eagle got his BA degree on Electronic Information Engineering from Capital Normal University.
Before joining in Pica8, Eagle worked in opzoon and had much work experience in switch SDK.

- Charlie Liu(Charlie.liu@pica8.com,刘风展)
He will work with sales team and engineering team together to promote products.
He reports to Henry directly.
He got his BA degree on Foreign Trade English from Beijing International Studies University.
Before joining in Pica8,Charlie worked in IT relevant industry for 10 years.
 2 years experience on technical support and 8 years experience on marketing.

- Pillar Li(Pillar.li@pica8.com,李金栋)
He got his BA degree on Network Engineering from North China Institute of Science and Technology.
 Before joining in Pica8,Pillar had 4 years experience on QA.

- Tracy Yang(Tracy.yang@pica8.com,杨学彬)
She will work with QA team and engineering team together to write technical document.
She got her BA degree on Statistics from Nankai University and MS degree on Control Science and Engineering from
Harbin Institute of Technology.
Before joining in Pica8, Tracy worked in Huawei for more than 5 years and another 1 year  experience  on
network security.

- Wayne Zhang(wayne.zhang@pica8.com,张伟)
He got his BA degree on Electronic and Information from Shandong University of Technology.
Before joining in Pica8,Wayne had 3 years experience on routing protocol.

- Eileen Wang (Eileen.wang@pica8.com,王琪)
She got her BA degree on Computer science and Technology from Jilin Agricultural University this year.

- Sarah Lee (Sarah.lee@pica8.com，李平)
She got her BA degree on Computer Application from Beijing Normal University and got her MS degree on the same
major from Wuhan Communication Command College.
Before joining in Pica8, Sarah worked in Communications Regiment of the headquarters of the legionary department
as communications test engineer for more than 10 years and worked as civil servant for 6 years.

- Chail Wang(Chail.wang@pica8.com,王晓飞)
He got his MS degree on Electronics and Communication Engineering from Wuhan University of Technology.
Before joining in Pica8,Chail worked in communications industry as a soft engineer and was familiar with SDN.

- Fiona Chen(Fiona.chen@pica8.com,陈丰琴)
She is a postgraduate student on Computer Science and Technology of Southwest Jiaotong University.
She will work in Pica8 for several months as intern.

- Ryan Liu(ryan.liu@pica8.com,刘瑞)
Ryan got his BA degree on Information and Computing Science from Nanjing University of Aeronautics and Astronautics.
Before joining in Pica8,Ryan worked in ZTE.

- Daisy Zhao(daisy.zhao@pica8.com,赵洋)
Daisy got her MS degree on Communication Engineering from Beijing University of Posts and Telecommunications.
Before joining in Pica8, Daisy worked in Ericsson and Nortel Networks.

- Ben.Zuo(Ben.zuo@pica8.com,左建威)
Ben got his BA degree on Computer Networks from Xidian University.
Before joining in Pica8, Ben worked in Raisecom on Opendaylight.

- Ali Amjad(ali.amjad@pica8.com,阿里)
Ali got one MS degree on Computer Science from IMS Hayatabad Peshawar and another MS degree on Computer Networks from University of Peshawar.
Ali got his PHD degree on Computer Applied Technology from Harbin Engineering University in China.
Ali also got CCNA certificate.
He can speak well in Chinese, English and Arabic.
Before joining in Pica8, he worked in China Telecom as technical support engineer in Shanghai City.

- Mike Kou(mike.kou@pica8.com,寇石)
Mike got his MS degree on Communication Engineering from Newcastle University at the end of last year.

- Andrew Zhao(Andrew.zhao@pica8.com <mailto:Andrew.zhao@pica8.com>,赵明寰)
Andrew got Master of Science from Tufts last year.
Before joining in Pica8, Andrew worked in the USA.

- Andy.He(Andy.he@pica8.com,何志业)joined our ASIC/SDK team today.
Andy got his BA degree on Computer Science and Technology from Northeast Normal University.
Before joining in Pica8,Andy worked in ZTE.

- Elijah Ai (Elijah.ai@pica8.com,艾浩宇)
He got his MS degree on Electronic Engineering from Delft University of Technology this year.
Before joining in Pica8,Elijah worked in Huawei in Amsterdam as an intern for several months.

- Jacky Jiang(jacky.jiang@pica8.com,姜英龙)joined our solution team as senior software engineer this Monday.
He got his BA degree and MS degree both on Communication Engineering from Beijing University of Posts and Telecommunications.
Before joining in Pica8,Jacky worked in Dell for several years.

Name | Name in Chinese | Tel
--- | --- | ---
Lin Du | 杜林 | 13910589821
Celine(Yan) Wang | 王燕 | 15801291126
Yachal (YongQiang) Chen | 陈永千 | 15010060911
Jeff （JiaFu) Wang | 王家富 | 13810222044
Sophia （YaFei）Sun | 孙亚非 | 18510924726
Shirley （LiPing）Guo | 郭丽平 | 18600693349
Mandy (Min)Ding | 丁敏 | 13681143225
Vivien（Na) Yin | 尹娜 | 15822832792
Sunny(Lingling)Wang | 王玲玲 | 15652805110
Cary (Hai) Yang | 杨海 | 13811035336
George (DongTai) Guo | 郭东太 | 18601907259
Jim(Xiao) Shen | 沈肖 | 13520705762
Jack(ZhiHan) Li | 李治涵 | 13641037913
Jacob(JunLing) Wang | 王俊岭 | 18511580584
Kevin（ChengWei) Yang | 杨成伟 | 15301183828
Joyce(JiaoJiao) Zhao | 赵娇娇 | 13720007319
Tong(tong)Zhang | 张彤 | 18500136703
leon(ming)li  | 李明 | 15701238920
Dorie(donglin)pan | 潘冬琳 | 18201667199
Wim(wenming)Fu | 付文明 | 18701431208
Louis(jintao)Zhang | 张金涛 | 13439708506
Thomas | 黄鹏涛 |  13220120731
Louie | 龙雨 | 13261979365
Aaron | 商青华 | 17076461606
Owen | 洪国栋 | 15510982829
Frank | 张志春 | 18687082367
Rudy | 徐虹 | 15201107018
Ali | 阿里 | 13671548709

Name | Email
--- | ---
aaron | aaron.shang@pica8.local
alan | alan.yu@pica8.local
allerson | allerson.yao@pica8.local
barton | barton.song@pica8.local
cary | cary.yang@pica8.local
clark | cli@pica8.local
ldu | ldu@pica8.local
dorie | dorie.pan@pica8.local
frank | frank.zhang@pica8.local
george | george.guo@pica8.local
iris | irong@pica8.local
jacob | jacob.wang@pica8.local
jason.liang | jason.liang.yang@pica8.local
jack | jli@pica8.local
johannes | johannes.leng@pica8.local
jim | jshen@pica8.local
jeff | jwang@pica8.local
jessie | jxu@pica8.local
kevin | kevin.yang@pica8.local
leon | leon.li@pica8.local
louie | louie.long@pica8.local
lisa | lpi@pica8.local
mandy | mandy.ding@pica8.local
matt | matt.he@pica8.local
mikel | mtang@pica8.local
owen | owen.hong@pica8.local
peter | peter.xia@pica8.local
ryan | ryan.xu@pica8.local
sam | sam.gang@pica8.local
shirley | shirley.guo@pica8.local
sophia | sophia.sun@pica8.local
sunny | sunny.wang@pica8.local
tony | tdu@pica8.local
thomas | thomas.huang@pica8.local
tom | tjia@pica8.local
tong | tong.zhang@pica8.local
tim | tyi@pica8.local
vic | vic.lan@pica8.local
vivien | vivien.yin@pica8.local
wim | wim.fu@pica8.local
yachal | ychen@pica8.local



1、目前工作中遇到的问题是什么？是否需要支持和帮助？
目前在工作期间没有遇上特别困难的问题，不需要额外的支持和帮助，遇到问题组内同事都能共同探讨一起解决。
2、工作中存在的不足有哪些
首先就是输出文档太少，虽然解决的bug很多，但是许多bug都没有对应的输出文档，因此我具体的工作成果很难体现出来。这样既没有做到总结，也无法为其他人传授经验。不过最近又在多写文档，有时候确实这样效率会更高。其次就是总结能力差，现在同其他同事进行讨论，因为表述原因会导致信息误解或者难以理解，一定程度上影响了工作效率。
3、下阶段的工作规划
首先，在Q1季度结束前，修复目前能够复现的所有bug，并输出相对应的文档；其次，主动去学习内核其他模块，现在打算先从picos下的dhcp模块开始学习；另外，协作完成控制转发syslog远程服务器level的开发；最后，与团队一起完成更多任务，整理更多内核基础知识并分享。
4、在试用期的感受
在第二阶段我明显感受到与组内其他成员的合作正在加强，在这期间，和刘格如、吴工一起完成repo仓库的开发。和潘艳乐一起完成dhcp性能的测试。这期间，不仅提高了工作效率，而且还能从她们的工作方式中汲取许多优点。例如：潘艳乐在任务开始前会有一个清晰的执行流程，刘格如在执行任务时能找出潜在的问题。另外由协议新同事组织的分享会，也能每周学习到许多知识点。像LAG、GRE协议等
5、对于部门工作流程、工作分工有哪些建议
我希望我们有机会参与到更多项目的开发，进行更多的学习。虽然可能达不到精通，但也对某一方面有所了解。我感觉吴工平时会比我们忙很多，如果可以，希望能帮他分担一些任务，同时我自己也会学习更多技能。
6、其他方面
我打算五月份劳动节结束后回校准备毕业答辩，请假一个月，我需要提前准备什么材料？
7、直接上级根据谈话情况总结执行情况

$ openssl ciphers -v 'HIGH'

## lzk

完成dhcpsnooping的json show命令，为web页面端提供相应数据

目前已陆续完成bgp,ospf,dhcp6,rip等模块中新增功能特性的对应yang文件开发，为picos提供相应功能支持

https://mah2eds8ab.feishu.cn/docx/NagLd3Kf8oFmS8xzBzQcyJsPnsc

netconf相关下发流程方法以及对应工具使用​
203%

对相应yang文件进行修改和重新编写​
203%
Upload Log
Customer Service
What's New
Keyboard Shortcuts
​a
使用lnctool工具生成模块对应所需验证文件

对相应yang文件进行修改和重新编写​
203%
Upload Log
Customer Service
What's New
Keyboard Shortcuts
​a

在交换机上使用netconf进行下发自测
