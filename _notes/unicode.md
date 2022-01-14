---
title: utf-8 and unicode
date: 2010-10-29 10:24:06+00:00
tags:
- utf-8
---

## grep utf-8 contents

If your locale is some utf-8, then just grep.

If not utf-8 locale, then make a change:

<blockquote>$ iconv -f utf-8 -t your_current_locale < your_utf-8_target_file -o new_file_as_your_locale</blockquote>

## Unicode 的编码空间

Unicode只是一个符号集,只规定符号二进制代码,没有规定二进制如何存储.

Unicode定义了所有符号的二进制形式，也就是符号如何在计算机内部存储的，而且每个符号规定都必须使用两个字节来表示，也就是用16位二进制去代表一个符号，这样就导致了一个问题，英文编码的空间浪费，因为在ANSI中的符号都是一个字节来表示的

UTF-32 采用四个字节来表示，对应于 UCS-4。

对于多个字节的表示，需要确定字节的顺序（高低位），于是引入 BOM（Byte Order Mask）。UTF-16 的大端序（Big Endian）的表示形式为 U+FEFF，小端序（Little Endian）为 U+FFFE。此 BOM 出现在文件的最开始。


Unicode 编码范围是：U+0000 到 U+10FFFF，
17 个平面

这个范围对应的是 21-bit 的编码空间(code space)。

10FFFF 换算成 bit 就是 1 0000 1111 1111 1111 1111（21 位）

## UTF

UTF-8 是一种变长的编码方式。使用1~4个字节表示一个符号，根据不同的符号而变化字节长度。

如果一个字节的第一位是0，则这个字节单独就是一个字符；如果第一位是1，则连续有多少个1，就表示当前字符占用多少个字节。

"严"字的Unicode码是4E25，UTF-8编码是E4B8A5

4E25的二进制位 0100,1110,0010,0101

1110xxxx 10xxxxxx 10xxxxxx。组合起来为 1110,0100,1011,1000,1010,0101  =E4B8A5

 “备” 的 UTF-32 大端序编码为 U+5907，01011001 00000111

UTF-8 需要三个字节，将 01011001 00000111 分成 4 个 x，6 个 y 和 6 个 z，
即 0101 100100 000111，分别写入到 1110xxxx 10yyyyyy 10zzzzzz中，
得到11100101 10100100 10000111，其十六进制数为0xE5 A4 87。




128 个 ASCII 字符（Unicode 范围由 U+0000 至 U+007F）只需一个字节，带有变音符号的拉丁文、希腊文、西里尔字母、亚美尼亚语、希伯来文、阿拉伯文、叙利亚文及马尔代夫语（Unicode 范围由 U+0080 至 U+07FF）需要二个字节，其他基本多文种平面（BMP）中的字符使用三个字节，其他 Unicode 辅助平面的字符使用四字节编码。

UTF（Unicode Transformation Format）。常见的UTF格式有：UTF-7, UTF-7.5, UTF-8,UTF-16, 以及 UTF-32。

8代表是以8位二进制为单位来传输符号的，但是这样又导致了一个问题，虽然UTF-8可以使用一个字节来表示ANSI下的符号，但是对于其它类似汉语的符号，得需要两个字节来表示，所以计算机不知道如何去截取一个符号，也就是一个符号对应的二进制的截取开始位置和截取结束位置。所以为了解决Unicode下的ANSI符号的空间浪费和网络传输下如何截取字符的问题，UTF规定：如果一个符号只占一个字节，那么这个8位字节的第一位就为0。如果为两个字节，那么规定第一个字节的前两位都为1，然后第一个字节的第三位为0，第二个字节的前两位为10，然后如果是三个字节的话，那么第一个字节的前三位为111，第四位为0，剩余的两个字节的前两位都为10。按照这样的算法去思考一个中文字符的UTF-8是怎么表示的：一个中文字符需要两个字节来表示，两个字节一共是16位，那么UTF-8下，两个字节是不够的，因为两个字节下，第一个字节已经占据了三位：110，然后剩余的一个字节占据了两位：10，现在就只剩下8位，与Unicode下的两个字节，16位去表示任意一个字符是相悖的，也就是Unicode下的16位减去UTF-8下的8位=8位，刚好差了一个字节的空间，所以就使用三个字节去表示非ANSI字符：三个字节下，一共是24位，第一个字节头四位是：1110，后两个字节的前两位都是：10，那么24位-8位=16位，刚好两个字节去表示Unicode下的任意一个非ANSI字符。

## Unicode 编码格式表示

根据 Unicode 5 层模型的定义，我们可以选择不同的编码格式来完成 Unicode 编码集和最终编码的映射，比如 UTF-8，UTF-16，UTF-32。

UTF-8, 16, 32 有啥区别？
不同的编码格式最大的区别在于它们的 code unit（编码单位）不同。

UTF-8，编码单位 = 8-bit

UTF-16，编码单位 = 16-bit

UTF-32，编码单位 = 32-bit

1 UTF-32 = 2 UTF-16 = 4 UTF-8。

UTF-8 可以用 1-4 个编码单位来做映射，而 UTF-16 只能用 1-2 个编码单位来完成，UTF-32 必须要用 1 个编码单位，所以从空间使用的效率来讲， UTF-8 最好~

Each character will then be represented either as a sequence of one to four 8-bit bytes, one or two 16-bit code units, or a single 32-bit code unit.

不同 UTF 格式之间的区别总结


最大码位和最小码位都一样（所以才能方便转换）；
码元（code unit）不同；
字节顺序（Byte Order）有点区别（这个概念等下讲）；
每个字符的最小编码字节数各有不同，最大编码字节数全部是 4 Byte。
2. UTF & UCS
1. UTF 是什么？
Unicode transformation format (UTF) - 通用转换格式。

它是一种算法映射，让每个 Unicode 的码位都可以被映射成为一个独一无二的字节序列（byte sequence）。

注意：这里的码位不包括 Surrogate Code Point - 代理码位（这个概念之后讲）。

A Unicode transformation format (UTF) is an algorithmic mapping from every Unicode code point (except surrogate code points) to a unique byte sequence.

UCS 是什么？
这是一个和 UTF 类似的概念，基本可以互换。

The ISO/IEC 10646 standard uses the term “UCS transformation format” for UTF; the two terms are merely synonyms for the same concept.

2. 可逆性（lossless round tripping）
每个 Unicode 编码后的字符序列都可以再解码还原成原来的字符，所以 UTF 必须要把所有的码位（除了代理码位）都能映射成独一无二的字节序列。这包括了保留码位（reserved/unassigned code points）以及 66 个内部使用字符（noncharacters）。

A “noncharacter” is a code point that is permanently reserved in the Unicode Standard for internal use.

内部使用字符包括 U+FFFE 和 U+FFFF。

Each UTF is reversible, thus every UTF supports lossless round tripping: mapping from any Unicode coded character sequence S to a sequence of bytes and back will produce S again. To ensure round tripping, a UTF mapping must map all code points (except surrogate code points) to unique byte sequences. This includes reserved (unassigned) code points and the 66 noncharacters (including U+FFFE and U+FFFF).

3. UTF-16
前身是一个已经过时的 UCS-2 标准（这个标准无法编码所有的 Unicode 字符）；

UCS-2 用 16-bit 编码了 Plane 0 的所有字符，UTF-16 采用了所有的 UCS-2 的 2 Byte 字符编码，然后用 4 Byte 对 UCS-2 无法编码的字符（其他 Plane 的字符）进行了编码。

只要 UCS-2 没有对保留的区间（U+D800-U+DFFF）进行编码，就是有效的 UTF-16 编码。

UTF-16 只用 2 Byte 或 4 Byte 来编码。

UTF-16
用一个单独的 16-bit 码元来编码最常用的 63k 个字符。

用一对 16-bit 码元（surrogate）来编码剩下 1M 比较少用到的字符。

4. Byte Order 是什么？
刚才看这张图的时候，大家是不是和我一样，被这个 Byte Order 搞糊涂了？



我的发现
UTF-8 不涉及这个概念；
UTF-16 和 32 都有两个变体 - BE 和 LE；
BE 是 big-endian 的缩写
LE 是 little-endian 的缩写
BE 和 LE 都属于 Byte Order Mark；
In the table indicates that the byte order is determined by a byte order mark, if present at the beginning of the data stream, otherwise it is big-endian.

Byte Order Mark
BOM 是在 data stream 开头的一个 Unicode 字符，用来标记字节顺序和编码格式（是否为 Unicode）。

endian 是什么意思？
超过 1 Byte 的数据类型可以用两种方式储存在电脑里，MSB(most significant byte) 在最前面，或者 MSB 在最后。
MSB 在前的就是 big-endian
MSB 在后面的就是 Little-endian
在数据交换的时候，为了告诉接收信息的那方，当前信息的储存方式到底是 MSB 在前还是 MSB 在后，我们需要用一个 BOM 作为标识，这个字符的唯一作用就是告诉接收信息的那一方，在处理信息之前需要知道数据的顺序。
由于 UTF-8 是基于字节的，它没有这个问题（只有超过 1 Byte 的才需要），所以 UTF-8 不需要 BOM，它的字符顺序永远是一致的，没有 LE,BE 这种变体。
但是 UTF-8 不需要 BOM 不代表它不可以有 BOM，如果你想的话，我们也可以给 UTF-8 加个专门用来告诉别人，我是 UTF-8 的 BOM（这个 BOM 跟 MSB 无关）
比如下面这张图里面，我们可以看到，BE 的标识是 FE FF，而 LE 的标识是 FF FE
UTF-8 的标识方式是 EF。


Data types longer than a byte can be stored in computer memory with the most significant byte (MSB) first or last. The former is called big-endian, the latter little-endian. When data is exchanged, bytes that appear in the “correct” order on the sending system may appear to be out of order on the receiving system. In that situation, a BOM would look like 0xFFFE which is a noncharacter, allowing the receiving system to apply byte reversal before processing the data. UTF-8 is byte oriented and therefore does not have that issue. Nevertheless, an initial BOM might be useful to identify the datastream as UTF-8.

UTF-8 加了 BOM 会造成什么问题呢？
有些信息接收方是不需要收到这个 BOM 的，假如你加了，反而会让接收方变糊涂……

UTF-8 can contain a BOM. However, it makes no difference as to the endianness of the byte stream. UTF-8 always has the same byte order. An initial BOM is only used as a signature — an indication that an otherwise unmarked text file is in UTF-8. Note that some recipients of UTF-8 encoded data do not expect a BOM. Where UTF-8 is used transparently in 8-bit environments, the use of a BOM will interfere with any protocol or file format that expects specific ASCII characters at the beginning, such as the use of “#!” of at the beginning of Unix shell scripts.

BOM 符号假如出现在一个字符流的中间（而不是开头）咋办？
假设你在字符流的中间看到了 U+FEFF 这个 BOM，你可以选择：

当做 ZWNBSP (ZERO WIDTH NON-BREAKING SPACE) 处理 - 假如要支持老系统
当做不支持的字符处理 - 假如你做的是一个新标记语言（markup language）/新数据协议（data protocol）
ZWNBSP
假如你的字符流最前面有个 BOM，那么你的 ZWNBSP 应该怎么表示？

U+2060 WORD JOINER
https://en.wikipedia.org/wiki/Word_joiner

假如你的数据没有 BOM，那要怎么表示 LE 和 BE 呢？
用 tag。

UTF-16BE - big-endian UTF-16
UTF-16LE - little-endian UTF-16
假如有 BOM，就用 UTF-16 作为 tag。

什么时候应该用不需要 BOM 的协议？
当数据有类型的时候（比如数据库里面的一个字段），BOM 就不需要了。

当文本数据被标记成带有 LE, BE 的格式（如 UTF-16BE），BOM 是不允许存在的，所有的 U+FEFF 都会被当成 ZWNBSP 来处理。

不当使用 BOM 会浪费空间（毕竟是一个 Byte），还会让字符串的连接（concatenation）变得很复杂（只保留开头的 BOM），甚至会影响数据的相等性比较（假如两个 string，看起来一样，一个带有 BOM，一个不带 BOM，它们就不是 binary-equal 的）

如何处理 BOM？
一些协议可能规定必须要 BOM，那你就用；
一些协议可能规定 BOM 只需要在没有 tag 的数据里面存在，那么：
假如数据流是文本，不确定编码方式，BOM 可以用来做一个编码格式的标记，告诉对方这是 Unicode
假如数据流是文本，但是不确定是哪种 endian，那么 BOM 可以用来作为一个 endian 版本的标识，如果没有 BOM，默认是 big-endian。
有些基于字节的协议需要在文件开头看到 ASCII 字符，假如我们用的是 UTF-8，就千万别用 BOM（因为它不是一个 ASCII 字符）；
当你知道数据流的类型时（比如 Unicode BE，Unicode LE），那么就不需要 BOM 了，尤其是当数据流已经有 BE,LE 这样的 tag 时，千万别用 BOM。
5. 还是搞不懂 BOM？
12345
上面这串数字，你是从左到右读，还是从右到左读。

从左到右：12345 -> 这是 big-endian

从右到左：54321 -> 这是 little-endian

MSB 就是你第一个看到的字符，LSB 就是你最后一个看到的字符。

https://whatis.techtarget.com/definition/most-significant-bit-or-byte

big-endian
12345 这串数字里面，MSB 是 1，LSB 是 5。

little-endian
12345 这串数字里面，MSB 是 5，LSB 是 5。

BOM
告诉你这串数字应该用 big-endian 读，还是用 little-endian 读。

6. 结语
这篇文章主要讲了：

Unicode 和 UTF-8, UTF-16, UTF-32 的关系（后面三个是不同的实现方式）；
Unicode 的编码空间（21 bit，还记得这个是怎么算的吗？）；
Unicode 对可逆性（lossless round tripping）的要求；
UTF 和 UCS （UTF-16 的前身是 UCS-2）；
UCS-2 是纯粹的 16-bit 编码，但是后来发现 16-bit 还是不够覆盖所有的字符，于是催生了 Plane（平面）以及 UTF-16 这些新概念；
UTF-16 和 UTF-32 都是超过 1 Byte 的编码，所以需要 Byte Order 这个概念，本质是由于人们有两种不同的阅读顺序（MSB 在最左边还是最右边）；
MSB 在最左边，就是 Big-endian，也是默认的阅读方式（从左到右）；

## BOM

字符的顺序是怎么样的（BE 还是 LE），保证字符可以被正确地处理；

UTF-16 LE，以 0xFF FE 开始。
UTF-16 BE，以 0xFE FF 开始。
Windows 下的 UTF-8 编码会有 BOM，即在文件的开始有 0xEF BB BF。
一般的 UTF-8 编码是没有 BOM 的。

unicode 65279 ZERO WIDTH NO-BREAK SPACE is
FEFF

FFFE在UCS中是不存在的字符，所以不应该出现在实际传输中。

UCS规范建议我们在传输字节流前，先传输字符"ZERO WIDTH NO-BREAK SPACE" FEFF。
这样如果接收者收到FEFF，就表明这个字节流是Big-Endian的；
如果收到FFFE，就表明这个字节流是Little-Endian的。

字符"ZERO WIDTH NO-BREAK SPACE"又被称作BOM。

UTF-8不需要BOM来表明字节顺序，但可以用BOM来表明编码方式。

字符"ZERO WIDTH NO-BREAK SPACE"的UTF-8编码是EF BB BF。所以如果接收者收到以EF BB BF开头的字节流，就知道这是UTF-8编码了。

UTF-8编码的文件中，BOM占三个字节。

UTF-8 EF BB BF is FEFF

## GB2312就是使用两字节表示一个汉字,一共$2^8$ * $2^8$ = 65536个

ISO 2022等同于欧洲标准组织（ECMA）的ECMA-35。中国国标GB 2312、日本工业规格JIS X 0202（旧称JIS C 6228）及韩国工业规格KS X 1004（旧称KS C 5620）均遵从ISO 2022。

ISO 2022

在一种字符编码下表示属于多个字符集的字符；
表示大字符集；
兼容7比特信道，即使是8比特编码字符集。
ISO 2022使用“转义符串”（Escape sequence）指出随后的字符属于哪个字符集。这些字符集在ISO登记，并遵循ISO 2022标准规定的模式。转义符串由1个“ESC”字符（0x1B），再由两至三个字串组成。此标记代表它后面的字符，属于下表字符集的文字。对于一个字符集，如果上下文可以判明是哪种字符集，也可以不通过转义序列来明确指出是哪种字符集。实际上，ISO-8859-1就宣布不需要定义它的转义序列。


但是字符集只有6000来个

$ python -c "print(u'\u9c7c')"

## JVM中对char是使用UTF-16编码的。使用UTF-16的好处是大部分字符都能以固定两个字节存储，但是这样的坏处就是对于英文字符存储就造成浪费，但是为了解决这个问题，Java9以后对字符串做了优化，对于字符串里面都是拉丁字母或者ASCII码中的字符，不使用UTF-16编码存储，而是使用byte存储，这样可以省一部分空间。

## ，MySQL的“utf8”实际上不是真正的UTF-8。

“utf8”只支持每个字符最多三个字节，而真正的UTF-8是每个字符最多四个字节。

MySQL一直没有修复这个bug，他们在2010年发布了一个叫作“utf8mb4”的字符集，绕过了这个问题。

当然，他们并没有对新的字符集广而告之（可能是因为这个bug让他们觉得很尴尬），以致于现在网络上仍然在建议开发者使用“utf8”，但这些建议都是错误的。

简单概括如下：

1.MySQL的“utf8mb4”是真正的“UTF-8”。

2.MySQL的“utf8”是一种“专属的编码”，它能够编码的Unicode字符并不多。

我要在这里澄清一下：所有在使用“utf8”的MySQL和MariaDB用户都应该改用“utf8mb4”，永远都不要再使用“utf8”。


MySQL从4.1版本开始支持UTF-8，也就是2003年，而今天使用的UTF-8标准（RFC 3629）是随后才出现的。

旧版的UTF-8标准（RFC 2279）最多支持每个字符6个字节。2002年3月28日，MySQL开发者在第一个MySQL 4.1预览版中使用了RFC 2279。

同年9月，他们对MySQL源代码进行了一次调整：“UTF8现在最多只支持3个字节的序列”。

## emoji符号占4个字节



