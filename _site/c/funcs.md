%title 常用库函数

[首页](../../../index "wikilink") - [C/C++](../index "wikilink") -
[C](index "wikilink")

## 常用库函数

-----

### 基本输入输出

\`getchar\`：从标准输入流获取一个字符并返回，返回\`int\`型。\`char ch =
getchar();\`

\`putchar\`：向标准输出流输出一个字符并返回该字符的\`int\`值。\`putchar(ch);\`

\`fprintf\`：向预定义流输出格式化字符串，第一个参数为流的名字，写成\`stdout\`就相当于\`printf\`。\`fprintf(stdout,
"%s, 你好", name);\`

\`sprintf\`：向指定的字符串缓冲区输出格式化内容，第一个参数为缓冲区的名字。\`sprintf(buffer, "$s, 你好",
name);\`

\`fprintf\`和\`sprintf\`具有细微的差别，两者的返回值都是输出字符的个数

-----

### 字符串相关

\`gets\`：从标准输入流获取一个字符串，成功返回该字符串，失败返回\`NULL\`。\`char str\[10\];
gets(str);\`

\`puts\`：向标准输出流输出字符串，自带换行，失败返回\`EOF\`。\`char str\[\] = "Ruchee";
puts(str);\`

\`strcat\`：字符串连接函数，将字符串\`2\`连接到字符串\`1\`的后面，返回字符串\`1\`的首地址，需要包含\`string.h\`。\`strcat(str1,
str2);\`

\`strcpy\`：字符串拷贝函数，将字符串或常量拷贝到字符数组\`1\`中，返回字符数组\`1\`的首地址，需要包含\`string.h\`。\`strcpy(str1,
str2);\`

\`strcmp\`：字符串比较函数，等于返回\`0\`，前大于后返回非负值，前小于后返回负值，需要包含\`string.h\`。\`strcmp(str1,
str2);\`

\`strlen\`：字符串长度统计函数，不包括结束标志\`\\0\`，需要包含\`string.h\`。\`int len =
strlen(str);\`

|

<center>

\`strlen\`与\`sizeof\`辨异

</center>

| | \`strlen\`是函数，统计的字符数不包括字符串结束标志 | |
\`sizeof\`是运算符，不是函数，统计的字符串包括了字符串结束标志
| | 对于\`char str\[10\] = "Ruchee"\`，\`strlen(str) == 6\`，而\`sizeof(str)
== 10\` |

-----

<red>date</red> : 2012-01-29

-----
