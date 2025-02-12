---
title: ""
permalink: "/about/"
layout: page
mathjax: true
---

support for equations, with just `mathjax: true` in the page.

<script type="math/tex; mode=display">f^{(n)}(z) = \frac{n !}{2 \pi i} \int_{C}\! \frac{f(\zeta)}{(\zeta - z)^{n+1}} \mathrm{d}\zeta</script>

[5]: https://github.com/niklasbuschmann/contrast/issues/28

I'll mention this uses the [Liquid][6] templating system so I can find the
documentation later when I need it.

[6]: https://shopify.dev/docs/themes/liquid/reference

{% comment %}
         1         2         3         4         5         6         7         8
12345678901234567890123456789012345678901234567890123456789012345678901234567890
{% endcomment %}


- https://mozillagfx.wordpress.com/2021/10/30/switching-the-linux-graphics-stack-from-glx-to-egl/
- https://doc.rust-lang.org/nightly/nomicon/
- https://rust-unofficial.github.io/too-many-lists/

https://hacks.mozilla.org/2022/06/everything-is-broken-shipping-rust-minidump-at-mozilla/

https://hacks.mozilla.org/2022/06/fuzzing-rust-minidump-for-embarrassment-and-crashes/

https://gankra.github.io/blah/rust-lifetimes-and-collections/

https://hacks.mozilla.org/2022/05/improved-process-isolation-in-firefox-100/


3996

commit/7497a834527f54d1e7005bb854239261466711b5

https://snapcraft.io/microk8s

cd3d7b19fd9fbd54730216bcfe846793650a9084

cd9822006ec76225f21f7f3fb5bf506019c4a87c

75ca440042d0e91c36b5d4fe780a49f37b0778a6

fcaf35356bd8691ca30651e561db723b21bff054

8c2af954ff8538f4677c5f6052af6ca5b8b4e255


https://wiki.archlinux.org/index.php/Multiboot_USB_drive#Configuring_GRUB

https://github.com/ashang/vagrant-vbguest

81269c0694fd32462357d3461f5ed01fd0b4e4ac

https://www.voyax.me/posts/95b9b99d/

http://www.cplusplus.com/reference/

http://www.cplusplus.com/articles/E3wTURfi/

http://www.cplusplus.com/articles/y807M4Gy/

http://www.cplusplus.com/articles/Lz86b7Xj/

http://www.cplusplus.com/articles/jLzyhbRD/

http://www.cplusplus.com/articles/z6vU7k9E/

http://www.cplusplus.com/articles/j3wTURfi/

http://www.cplusplus.com/articles/Gw6AC542/

https://www.youtube.com/watch?v=1PJix23IeF8

https://code.visualstudio.com/docs/setup/linux#_visual-studio-code-is-unable-to-watch-for-file-changes-in-this-large-workspace-error-enospc

https://gohugo.io/getting-started/directory-structure/

https://en.wikipedia.org/wiki/Buddy_(software)

https://gohugo.io/content-management/static-files/

https://gohugo.io/getting-started/usage/

https://support.mozilla.org/en-US/kb/refresh-firefox-reset-add-ons-and-settings?redirectlocale=en-US&redirectslug=reset-firefox-easily-fix-most-problems

https://gohugo.io/hugo-pipes/introduction/

https://gohugo.io/content-management/sections/

deploy:

     type: git

     repo: https://github.com/xx/zz
     branch: master


npm install hexo-deployer-git --save

https://go.kieran.top/post/45/

https://en.wikipedia.org/wiki/PMAC_(cryptography)

    在导航栏添加点东西
        例如我添加了一个更新日志的模块。
        在主题的配置文件中，menu添加一栏：Board: /board。
        然后在source中添加一个board，即对应上面的名字。然后再创建一个index.md，里面可以写你想写的内容。
        在主题的hueman/langulages/zh-CN.yml中的index适当的位置加：board: '更新日志'，位置和名字是你自己设定。
        重新部署，然后就OK了
    在侧边栏添加点东西
        回到你的主题的配置文件中，找到widgets一栏，在你要添加的位置处添加一条你自定义的名称。例如我的叫communiation且放在了第二行。
        在上面所提到的zh-CN.yml文件中找到sidebar一栏，添加communiation: '你要设的名称'。
        在hueman/layout/widget中添加一个communiation.ejs,填入模板

    <% if (site.posts.length) { %>
        <div class="widget-wrap widget-list">
            <h3 class="widget-title"><%= __('sidebar.communiation') %></h3>
            <div class="widget">
                <!--这里添加你要写的内容-->
            </div>
        </div>
    <% } %>

9. 添加RSS

    先安装rss相关插件：npm i hexo-generator-feed
    在你的项目的_config.yml配置文件下找到Extensions添加如下内容：
    # Extensions #插件和主题 ## Plugins: https://hexo.io/plugins/ ## Themes: https://hexo.io/themes/ #RSS订阅 plugin: - hexo-generator-feed #Feed Atom feed: type: atom path: atom.xml limit: 20
    进入到你的主题的配置文件下，找到你的放rss的位置，添加/atom.xml即可。

    http://lewis.suclub.cn/2018/08/08/improve-github-clone-speed/

    http://haojen.github.io/2016/07/30/%E4%B8%BA%E8%87%AA%E7%94%B1%E4%B9%8B%E5%9C%B0/

    https://www.voyax.me/posts/95b9b99d/
    https://jaredforsyth.com/hexo-admin/

    https://hexo.io/docs/setup

    https://help.github.com/articles/using-a-custom-domain-with-github-pages/

    https://help.github.com/articles/creating-a-custom-404-page-for-your-github-pages-site/

    https://github.com/ashang/atbb/blob/master/_config.yml

    https://console.cloud.tencent.com/domain/manage/thepro.xyz/basicinfo

    https://github.com/ashang/ashang.github.io/blob/master/404.html

    https://en.wikipedia.org/wiki/CBC-MAC

    https://en.wikipedia.org/wiki/One-key_MAC

    10.10.50.11/bugs/show_bug.cgi?id=9674
    https://developer.mozilla.org/en-US/docs/Mozilla/Developer_guide/Source_Code


spine	Tells whether the switch is a spine switch (default) or an edge switch.  Note:  if the switch is an edge switch (spine mode is disabled), then the rest of the fields are meaningless.
Stand-alone Woven switches are always configured in spine mode; Woven switches are configured in edge mode only when they are stacked together into a fabric.


--- auto ssh key ---
ssh-keygen -t rsa
append id_rsa.pub to svnserver's .ssh/authorized_keys
eval `ssh-agent`
ssh-add id_rsa


--- ipfix ---
http://dev1/twiki/bin/view/Main/vinaypidathalaLeftBar
http://dev1/twiki/bin/view/Main/IpFixDev

bug candicates

--- fabric card ip ---
127.1.2.68 ~

--- line card ip ---
127.1.2.128 ~


dot1sPort[66].newInfoMist


10e0f370 S dot1sInstanceMap


vsp_channel_info[5].lagSvlansInBin

0x115e28d8



hapiEFX1000LagAddRemoveLagFromSVlans

hapiEFX1000LagAddRemoveLagFromSVlans -> hapiEFX1000LagAddLagToVlanHw -> hapiEFX1000LagAddLagToSVlan
                                                             -+-> hapiEFX1000LagAddRemoveLagFromSVlans
                                                             +-> hapiEFX1000DevmapInsertLagSvlanList


hapiEFX1000LagAddRemoveLagFromVlans -> hapiEFX1000LagAddRemoveLagFromSVlans -> hapiEFX1000LagAddLagToVlanHw



PortPartTbl


dabbrev-expand


make all_os


00 00 00 11 11 11
00 00 00 22 22 22
00 00 00 33 33 33
00 00 00 44 44 44




Figure 13-3 is an example Bridged Local Area Network, chosen to illustrate MSTP calculations rather than
as an example of a common or desirable physical topology. Figure 13-3 is the same network showing
Bridges and LANs with better CIST spanning tree priorities higher on the page, and including CIST priority
vectors, port roles, and MST Regions. In this example:
a) Bridge 0.42 has been chosen as the CIST Root because it has the best (numerically the lowest)
Bridge Identifier of all the bridges in the network.
b) Bridges 0.57 and 2.83 are in the same MST Region (1) as 0.42, because they have the same MST
Configuration Identifier as the latter. Because they are in the same MST Region as the CIST Root,
their External Root Path Cost is 0, and their CIST Regional Root is the CIST Root.
c) LANs A, B, C, and D are in Region 1 because a Region 1 MST Bridge is the CIST Designated
Bridge for those LANs and there are no attached STP Bridges. LAN E is not in a Region (or is in a
Region by itself, which is an equivalent view) because it is attached to Bridge 0.53, which is not an
MST Bridge.
d) Bridges 0.77, 0.65, 0.97, 0.86, 3.84, and 3.72 are in the same MST Region (2) because they all have
the same MST Configuration Identifier, and are all interconnected by LANs for which one of them is
the CIST Designated Bridge.
e) Bridge 0.86 is the CIST Regional Root for Region 2 because it is has the lowest External Root Path
Cost through a Boundary Port.
f) LAN N is in Region 2 because its CIST Designated Bridge is in Region 2. Frames assigned to different
MSTIDs may reach N from Bridge 0.86 (for example) by either Bridge 0.65 or Bridge 3.72, even
though Bridges 0.94 and 0.69 with MST Configuration Identifiers that differ from those for the
Bridges in Region 2 are attached to this shared LAN.
g) Bridges 0.94 and 0.69 are in different Regions, even though they have the same MST Configuration
Identifier, because the LAN that connects them (N) is in a different Region
h) Bridge 0.65 has been chosen as the MSTI Regional Root because it has the best (numerically the
lowest) Bridge Identifier of all the bridges in the Region for this MSTI.
i) The connectivity between the whole of Region 2 and Region 1 is provided through a single Bridge
Port, the Master Port on Bridge 0.86. This port was selected for this role because it is the CIST Root
Port on the CIST Regional Root for the Region (see Figure 13-3).
j) The connectivity between the whole of Region 2 and LANs and Bridges outside the Region for the
MSTI is the same as that for the CIST. This connectivity is similar to that which might result by
replacing the entire Region by a single SST Bridge. The Region has a single Root Port (this port is
the Master Port for each MSTI) and a number of Designated Ports.

# Cpp Notes

## loop

在多重循环中，如果有可能，应当将最长的循环放在最内层，最短的循环放在最外层，以减少CPU跨切循环层的次数。
如果循环体内存在逻辑判断，并且循环次数很大，宜将逻辑判断移到循环体的外面。
建议for语句的循环控制变量的取值采用“半开半闭区间”写法

## function

### Args

如果参数是指针，且仅做输入用，则应在类型前加const，以防止该指针在函数体内被意外修改。


在函数体的“入口处”，对参数的有效性进行检查。
在函数体的“出口处”，对return语句的正确性和效率进行检查。

## Memory

在栈上创建。在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。
从堆上分配，亦称动态内存分配。程序在运行的时候用malloc或new申请任意多少的内存，程序员自己负责在何时用free或delete释放内存。动态内存的生存期由我们决定，使用非常灵活，但问题也最多。

5.3 对策
- 用malloc或new申请内存之后，应该立即检查指针值是否为NULL。防止使用指针值为NULL的内存。
- 不要忘记为数组和动态内存赋初值。防止将未被初始化的内存作为右值使用。
- 避免数组或指针的下标越界，特别要当心发生“多1”或者“少1”操作。
- 动态内存的申请与释放必须配对，防止内存泄漏。
- 用free或delete释放了内存之后，立即将指针设置为NULL，防止产生“野指针”。
5.4 free 和 delete 把指针怎么啦？
- 它们只是把指针所指的内存给释放掉，但并没有把指针本身干掉。
- 指针p被free以后其地址仍然不变（非NULL），只是该地址对应的内存是垃圾，p成了“野指针”。如果此时不把p设置为NULL，会让人误以为p是个合法的指针。
- 如果程序比较长，我们有时记不住p所指的内存是否已经被释放，在继续使用p之前，通常会用语句if (p != NULL)进行防错处理。很遗憾，此时if语句起不到防错作用，因为即便p不是NULL指针，它也不指向合法的内存块。 “野指针”示例
5.5 动态内存会被自动释放吗？示例
- 指针消亡了，并不表示它所指的内存会被自动释放。
- 内存被释放了，并不表示指针会消亡或者成了NULL指针。


指针p被free或者delete之后，没有置为NULL，让人误以为p是个合法的指针。

5.7 有了malloc/free 为什么还要new/delete
- Malloc/free 是库函数，new/delete是运算符。
- 光用maloc/free无法满足动态对象的要求。对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。由于malloc/free是库函数而不是运算符，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加于malloc/free。因此C++语言需要一个能完成动态内存分配和初始化工作的运算符new，以及一个能完成清理与释放内存工作的运算符delete。

## Style

源文件使用 .cc 扩展名.

不要使用匈牙利命名法

将所有警告(warnings)当作错误(errors)处理.

不应该使用异常




## Refs

- https://google.github.io/styleguide/cppguide.html
- http://www.gnu.org/prep/standards/standards.html
- https://isocpp.org/wiki/faq
- Kernighan & Ritchie, The C Programming Language
- Linden, Expert C Programming
- Andrew & Koening, C Traps and Pitfalls
- Steve Maguire, Write Clean Code
- Steve McConnell, Code Complete, Second Edition

## Q&A

太多变量定义为register，怎么处理？

## Env

```shell
$ cpp -v /dev/null -o /dev/null
Using built-in specs.
COLLECT_GCC=cpp
Target: x86_64-pc-linux-gnu
Configured with: /build/gcc/src/gcc/configure --prefix=/usr --libdir=/usr/lib --libexecdir=/usr/lib --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=https://bugs.archlinux.org/ --enable-languages=c,c++,ada,fortran,go,lto,objc,obj-c++,d --with-isl --with-linker-hash-style=gnu --with-system-zlib --enable-__cxa_atexit --enable-cet=auto --enable-checking=release --enable-clocale=gnu --enable-default-pie --enable-default-ssp --enable-gnu-indirect-function --enable-gnu-unique-object --enable-install-libiberty --enable-linker-build-id --enable-lto --enable-multilib --enable-plugin --enable-shared --enable-threads=posix --disable-libssp --disable-libstdcxx-pch --disable-libunwind-exceptions --disable-werror gdc_include_dir=/usr/include/dlang/gdc
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 11.1.0 (GCC)
COLLECT_GCC_OPTIONS='-E' '-v' '-o' '/dev/null' '-mtune=generic' '-march=x86-64' '-dumpdir' '/dev/'
 /usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/cc1 -E -quiet -v /dev/null -o /dev/null -mtune=generic -march=x86-64 -dumpdir /dev/ -dumpbase null
ignoring nonexistent directory "/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/../../../../x86_64-pc-linux-gnu/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/include
 /usr/local/include
 /usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/include-fixed
 /usr/include
End of search list.
COMPILER_PATH=/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/:/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/
LIBRARY_PATH=/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/../../../../lib/:/lib/../lib/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-E' '-v' '-o' '/dev/null' '-mtune=generic' '-march=x86-64' '-dumpdir' '/dev/'
```

## const

const 常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型安
全检查。而对后者只进行字符替换，没有类型安全检查，并且在字符替换可能会出错。

不能在类声明中初始化 const 数据成员。以下用法是错误的，因为类的对象未被创
建时，编译器不知道 SIZE 的值是什么。
class A
{…
const int SIZE = 100; // 错误，企图在类声明中初始化 const 数据成员
int array[SIZE];
// 错误，未知的 SIZE
};
const 数据成员的初始化只能在类构造函数的初始化表中进行，例如
class A
{…
A(int size);
// 构造函数
const int SIZE ;
};
A::A(int size) : SIZE(size)
// 构造函数的初始化表
{
…
}
Aa(100); // 对象 a 的 SIZE 值为 100
Ab(200); // 对象 b 的 SIZE 值为 200
怎样才能建立在整个类中都恒定的常量呢？别指望 const 数据成员了，应该用类中
的枚举常量来实现。例如
class A
{…
enum { SIZE1 = 100, SIZE2 = 200}; // 枚举常量
int array1[SIZE1];
int array2[SIZE2];
};
枚举常量不会占用对象的存储空间，它们在编译时被全部求值。枚举常量的缺点是：
它的隐含数据类型是整数，其最大值有限，且不能表示浮点数（如 PI=3.14159）

const 只能让编译器被修饰的对象当做只读变量，而非编译期的真正意义的常量进行处理。与 #define 的符号常量（字面量）相比，只读变量受到了一些限制，例如不能作 case 的标号。




## Func

C 语言中，函数的参数和返回值的传递方式
有两种：值传递（pass by value）和指针传递（pass by pointer）。C++ 语言中多了引用
传递（pass by reference）。由于引用传递的性质象指针传递，而使用方式却象值传递，
初学者常常迷惑不解，容易引起混乱，

形式上， C 语言函数参数只按值传递。所谓的指针传递是按值传递的一种，只是传递参数的类型是指针而已。

   指针是自动变量，在退出所在的块作用域被自动释放时。



参数的书写要完整，不要贪图省事只写参数的类型而省略参数名字。
如果函数没有参数，则用 void 填充。

如果参数是指针，且仅作输入用，则应在类型前加 const，以防止该
指针在函数体内被意外修改。

如果输入参数以值传递的方式传递对象，则宜改用“const &”方式
来传递，这样可以省去临时对象的构造和析构过程，从而提高效率。

## No Coke