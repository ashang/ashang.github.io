
Type Erasure（类型擦除） 是 C++ 中的一种技术，它允许我们在 不显式声明具体类型 的情况下，存储和操作不同类型的对象。它的核心思想是：

    用一个通用的接口（抽象层）来封装具体类型，使得外部代码可以无视（擦除）对象的原始类型，而仍然可以进行操作。

Type Erasure 在 泛型编程、回调函数、面向对象设计 中被广泛使用，例如 std::function、std::any、std::unique_ptr、std::shared_ptr 等。
1. 直接用模板 vs. Type Erasure

先来看 没有 Type Erasure 时的泛型代码：

template <typename T>
void callFunction(T func) {
    func();
}

void hello() { std::cout << "Hello, World!" << std::endl; }

int main() {
    callFunction(hello); // 只能接受特定类型的 T
}

问题

    callFunction 只能在编译时知道具体类型，而不能在运行时存储不同类型的函数。
    如果想要存储 hello 和一个 lambda，就需要额外的模板实例化。

Type Erasure 解决这个问题！
2. 使用 std::function 进行 Type Erasure

std::function 就是 类型擦除 的一个典型例子，它允许存储 不同类型的可调用对象（普通函数、Lambda、成员函数等）：

#include <iostream>
#include <functional>

void hello() { std::cout << "Hello, World!" << std::endl; }

int main() {
    std::function<void()> func = hello; // 类型擦除
    func(); // 仍然可以调用
}

为什么 std::function 具有 Type Erasure？

    std::function<void()> 隐藏了具体的函数类型。
    func 可以存储不同的 函数、Lambda、函数对象。
    我们无需关心 hello 的具体类型，它可以是 任何兼容 void() 形式的可调用对象。

更复杂的情况

#include <iostream>
#include <functional>

void hello() { std::cout << "Hello, World!" << std::endl; }

int main() {
    std::function<void()> func1 = hello;
    std::function<void()> func2 = []() { std::cout << "Lambda Function" << std::endl; };

    func1();
    func2();
}

输出

Hello, World!
Lambda Function

Type Erasure 让 func1 和 func2 无视底层的具体类型，而可以统一存储和调用。
3. std::any - 泛型数据存储的 Type Erasure

如果你需要存储 不同类型的值，可以使用 std::any：

#include <iostream>
#include <any>

int main() {
    std::any value = 42; // 存储 int
    std::cout << std::any_cast<int>(value) << std::endl;

    value = std::string("Hello"); // 存储 string
    std::cout << std::any_cast<std::string>(value) << std::endl;
}

特点

    std::any 擦除了具体的类型信息，但仍然可以存储和检索不同的值。
    std::any_cast<T>(value) 用于 安全地取回 原来的类型。

4. Type Erasure 的核心原理

Type Erasure 主要利用 多态（虚函数） 和 类型封装（PImpl 设计模式）：

    定义一个通用的基类（抽象层） 来隐藏具体类型。
    使用指针或 std::unique_ptr 存储不同类型的对象。
    提供一个虚函数接口 来执行操作，而不依赖具体的类型。

手写一个 std::function 的简化版

#include <iostream>
#include <memory>

class CallableBase {
public:
    virtual void call() = 0; // 纯虚函数
    virtual ~CallableBase() = default;
};

template <typename T>
class Callable : public CallableBase {
    T func;
public:
    Callable(T f) : func(f) {}
    void call() override { func(); }
};

class FunctionWrapper {
    std::unique_ptr<CallableBase> callable;
public:
    template <typename T>
    FunctionWrapper(T func) : callable(std::make_unique<Callable<T>>(func)) {}

    void operator()() { callable->call(); }
};

void hello() { std::cout << "Hello, World!" << std::endl; }

int main() {
    FunctionWrapper func = hello;
    func(); // 调用被擦除的函数
}

分析

    CallableBase 是抽象基类，用虚函数 call() 统一调用接口。
    Callable<T> 是具体实现，存储不同类型的可调用对象。
    FunctionWrapper 是对外接口，提供一个 operator() 让用户直接调用。

结果

Hello, World!

这本质上就是 std::function 背后的 Type Erasure 机制！
5. Type Erasure 的优缺点
优点

✅ 更灵活：允许在 运行时 处理不同类型的对象，而不仅仅是编译时。
✅ 减少模板膨胀：不像模板，Type Erasure 不会为每种类型生成新代码。
✅ 更强的抽象性：隐藏具体类型，提供统一的接口（如 std::function、std::any）。
缺点

❌ 有运行时开销：由于使用了 动态分配（new）和虚函数，运行时可能比直接使用模板稍慢。
❌ 丢失类型信息：存储到 std::any 之后，无法直接知道原始类型（需要 std::any_cast）。
❌ 不适合高性能场景：如果你的代码 需要极致性能（如嵌入式、游戏引擎），可能要避免 Type Erasure。
6. 什么时候应该使用 Type Erasure？

✅ 需要存储不同类型的对象（如 std::any）。
✅ 需要统一回调接口（如 std::function）。
✅ 希望减少模板膨胀（减少代码生成，提高编译速度）。
✅ 希望提高可维护性（隐藏底层类型，提供统一 API）。

