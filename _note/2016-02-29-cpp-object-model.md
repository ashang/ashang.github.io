---
title: "Cpp Object Model"
date: 2021-06-07T17:34:22+08:00
Description: ""
Categories: ""
draft: true
---



C++在布局以及存取时间上主要的额外负担是由virtual引起的，包括：
1. virtual function机制，用以支持一个有效率的“执行期间绑定”
2. virtual base class 用以实现“多次出现在继承体系中的base class，只有一个单一而被共享的实例”
另外，derived class和base class之间的转换也会有一些额外负担


nonstatic data members被置于每一个class object之内，static data members则被存放在个别的class object之外。static 和nonstatic function members也被放在个别的class object之外，virtual functions则以两个步骤支持：
1. 每一个class 产生出一堆指向virtual functions 的指针，放在表格之中。这个表格被称为virtual table(vtbl), 也就是我们常说的虚函数表指针
2. 每一个class object被安插一个指针(vptr)，指向相关的virtual table，vptr的设定和重置都由每一个class的constructor, destructor, copy assignment运算符自动完成。 每一个class所关联的type_info object(用以支持runtime type identification， RTTI)也是经由virtual table被指出来，通常放在表格的第一个slot。


关于继承：
C++采用的继承模型并不运用任何间接性：base class subobject的data members被直接放置于derived class object当中。这提供了对 base class member 最紧凑且最有效率的存取。缺点就是base class的任何改变，都使得“所有用到此base class 或其derived class” 之objects 必须重新编译

virtual base class 的原始模型是在class object中为“每一个有关的virtual base class”加上一个指针。其他演化出来的模型要么就是导入一个virtual base class table，要么就是扩充原有的virtual table, 以便维护每一个virtual base class 的位置


C++中，凡处于同一个access section的数据，必定保证以其声明顺序出现在内存布局当中，然而，被放置在多个access section中的各笔数据，排列顺序就不一定了。同理，base classes和derived classes的data members的布局也没有谁先谁后的强制规定


