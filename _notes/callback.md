









同步回调是 立即执行的，在主函数完成之前就执行：

#include <iostream>

// 回调函数，打印一条消息
void printMessage() {
    std::cout << "Hello from callback!" << std::endl;
}

// 一个执行回调的函数
void executeCallback(void (*callback)()) {
    std::cout << "Executing callback..." << std::endl;
    callback(); // 这里调用了传入的回调函数
    std::cout << "Callback execution finished." << std::endl;
}

int main() {
    executeCallback(printMessage);
    return 0;
}

输出：

Executing callback...
Hello from callback!
Callback execution finished.

这里 printMessage 作为 回调函数 传递给 executeCallback，在 executeCallback 内部调用。



异步回调

异步回调是 稍后执行的，通常用于 事件处理、定时任务、多线程或网络请求。

在 C++ 中，可以用 std::function + std::thread 实现：

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

// 定义一个回调类型
using Callback = std::function<void(int)>;

// 模拟异步操作
void asyncTask(int value, Callback callback) {
    std::cout << "Task started..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时操作
    callback(value * 2); // 调用回调，并传递计算结果
}

int main() {
    // 定义回调函数
    Callback myCallback = [](int result) {
        std::cout << "Callback received result: " << result << std::endl;
    };

    // 创建线程，执行异步任务
    std::thread t(asyncTask, 10, myCallback);
    t.detach(); // 让线程独立运行

    std::cout << "Main thread is free to do other things..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3)); // 等待任务完成
    return 0;
}


常用 std::function 或者 function pointer 传递回调函数。

## 使用函数指针传递回调
原理

函数指针是最简单、最直接的回调机制，它存储 一个普通函数的地址 并在适当的时候调用。
示例

#include <iostream>

// 定义一个回调函数类型
typedef void (*CallbackFunc)(int);

// 处理数据并调用回调
void processData(int data, CallbackFunc callback) {
    std::cout << "Processing data: " << data << std::endl;
    callback(data * 2);  // 执行回调
}

// 具体的回调函数
void myCallback(int result) {
    std::cout << "Callback received result: " << result << std::endl;
}

int main() {
    processData(10, myCallback);
    return 0;
}


## 优点

    高效：调用开销低，适用于性能关键的场景。
    简单：不依赖 C++ 标准库，适合 C 语言风格的代码。

缺点

    无法绑定成员函数：函数指针 只能指向静态函数或全局函数，无法直接绑定到类的成员函数。
    无法捕获上下文：函数指针 无法存储状态，不能使用 Lambda 捕获变量。

2. 使用 std::function 传递回调
原理

std::function 是一个 通用的可调用对象包装器，它可以存储 普通函数、Lambda、绑定成员函数。
示例

#include <iostream>
#include <functional>

// 处理数据并调用回调
void processData(int data, std::function<void(int)> callback) {
    std::cout << "Processing data: " << data << std::endl;
    callback(data * 2);
}

// 具体的回调函数
void myCallback(int result) {
    std::cout << "Callback received result: " << result << std::endl;
}

int main() {
    // 1. 传递普通函数
    processData(10, myCallback);

    // 2. 传递 Lambda
    processData(20, [](int res) {
        std::cout << "Lambda callback received result: " << res << std::endl;
    });

    return 0;
}

输出：

Processing data: 10
Callback received result: 20
Processing data: 20
Lambda callback received result: 40

优点

    支持 Lambda：允许传递 Lambda 表达式，可以捕获外部变量。
    支持成员函数：可以绑定类的成员函数并传递 this 指针。
    更通用：可以存储各种可调用对象（普通函数、Lambda、std::bind 绑定的函数等）。

缺点

    性能开销：std::function 是 类型擦除（type-erased） 的，可调用对象的存储和调用略有开销。
    需要 C++11 及以上：早期的 C++ 版本（C++03 及之前）不支持。




## 绑定类成员函数
使用 std::function 绑定成员函数

#include <iostream>
#include <functional>

class Processor {
public:
    void handleCallback(int result) {
        std::cout << "Class member received result: " << result << std::endl;
    }

    void start() {
        std::function<void(int)> callback = std::bind(&Processor::handleCallback, this, std::placeholders::_1);
        processData(10, callback);
    }

    static void processData(int data, std::function<void(int)> callback) {
        std::cout << "Processing data: " << data << std::endl;
        callback(data * 2);
    }
};

int main() {
    Processor p;
    p.start();
    return 0;
}

输出：

Processing data: 10
Class member received result: 20

    std::bind(&Processor::handleCallback, this, std::placeholders::_1) 绑定成员函数，使 this 作为第一个参数传递。
    std::function<void(int)> 可以存储这个绑定的可调用对象。

使用函数指针绑定成员函数

如果要用 函数指针 绑定类的成员函数，就需要 静态成员函数 或 全局函数 作为中介：

#include <iostream>

class Processor {
public:
    static void handleCallback(int result) {
        std::cout << "Static member received result: " << result << std::endl;
    }

    static void processData(int data, void (*callback)(int)) {
        std::cout << "Processing data: " << data << std::endl;
        callback(data * 2);
    }
};

int main() {
    Processor::processData(10, Processor::handleCallback);
    return 0;
}

但这种方式 无法访问 this 指针，不适用于非静态成员函数。


