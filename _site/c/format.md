%title C++的格式化

[首页](../../../index "wikilink") - [C/C++](../index "wikilink") -
[C++](index "wikilink")

## C++的格式化

-----

带参数的操作子（\`setw\`、\`setfill\`等）在\`<iomanip>\`中声明，而无参数的操作子（\`left\`、\`boolalpha\`等）在\`<ios>\`中声明

如果记不住该包含哪个头文件，可以将它们全部包含进来，无非就是编译时需要花的时间多一些，无其他副作用

控制输出既可以使用标准库的\`操作子\`，也可以使用\`std::cout\`输出流对象的\`成员函数\`

比如\`std::cout.fill('\*')\`与\`std::setfill('\*')\`功用相同，\`std::cout.width(6)\`与\`std::setw(6)\`功用一致

-----

\`std::setw()\`：指定输出的宽度。  
\`std::cout \<\< std::setw(3) \<\< 2012 \<\< '\\n';\`

\`std::setfill()\`：指定填充字符，在设置下一个不同的填充字符之前不会失效。  
\`std::cout \<\< std::setfill('\*') \<\< std::setw(2) \<\< 2012 \<\<
'\\n';\`

\`std::left\`和\`std::right\`：控制输出左对齐或右对齐，在设置下一个不同的对齐方式之前不会失效。  
\`std::cout \<\< std::left \<\< std::setw(2) \<\< 2012 \<\<
'\\n';\`

-----

\`std::boolalpha\`：严格按\`true\`或\`false\`对布尔型数据进行输入输出，就连大小写都必须一致

\`std::noboolalpha\`：这是默认的输入输出形式，用非零数字代表\`true\`，\`0\`代表\`false\`，只接受数字，不接受字符

-----

<red>date</red> : 2012-02-19、2012-02-22

-----
