

# CUDA 计算中，PTX（Parallel Thread Execution）和 SASS（Streaming Assembly）是两种不同层次的低级编程方式，分别对应 虚拟 ISA 和 实际硬件 ISA。直接编写 PTX 或 SASS 代码可以让开发者更精细地优化 CUDA 程序，但同时也增加了开发难度。

PTX 是一种 NVIDIA 的中间表示（IR），类似于 LLVM IR。CUDA 代码编译时，首先会生成 PTX 代码，然后再由 JIT 编译器（Just-In-Time Compiler） 进一步转换为 SASS 代码（硬件指令）。
PTX 的特点

    硬件无关：PTX 是一种 抽象指令集，不直接绑定特定 GPU 架构。
    可移植性强：同一份 PTX 代码可以在不同的 GPU 架构上运行。
    类似汇编，但更高级：支持寄存器、线程管理、内存操作等，但仍然比 SASS 代码易读易写。

PTX 代码示例

下面是一个简单的 PTX 代码示例，实现 C = A + B：

.version 7.0     // PTX 版本
.target sm_70    // 目标架构（例如 Volta）
.address_size 64 // 64 位指针

.visible .entry vector_add(
    .param .u64 A,
    .param .u64 B,
    .param .u64 C
) {
    .reg .b32 r1, r2, r3;

    ld.param.u64 %rd1, [A];  // 读取 A 数组地址
    ld.param.u64 %rd2, [B];  // 读取 B 数组地址
    ld.param.u64 %rd3, [C];  // 读取 C 数组地址

    mov.u32 r1, %tid.x;      // 获取当前线程索引
    mul.wide.u32 %rd4, r1, 4; // 计算数组偏移量

    add.u64 %rd5, %rd1, %rd4; // 计算 A[i] 地址
    add.u64 %rd6, %rd2, %rd4; // 计算 B[i] 地址
    add.u64 %rd7, %rd3, %rd4; // 计算 C[i] 地址

    ld.global.u32 r2, [%rd5]; // 读取 A[i]
    ld.global.u32 r3, [%rd6]; // 读取 B[i]

    add.u32 r2, r2, r3;       // A[i] + B[i]
    st.global.u32 [%rd7], r2; // 存储结果 C[i]

    ret;
}

PTX 代码的用途

    优化 CUDA 代码：PTX 提供比 CUDA C++ 更低级的控制，可以优化寄存器、访存等操作。
    兼容不同 GPU：PTX 代码可以运行在不同架构的 GPU 上，而 SASS 需要为每个 GPU 重新编译。
    查看编译优化效果：使用 nvcc -ptx 选项可以查看 CUDA 代码转换后的 PTX 代码，帮助理解 GPU 编译器的优化行为。

2. SASS（Streaming Assembly）—— 硬件 ISA

SASS 是 NVIDIA GPU 的 实际指令集，直接由 GPU 硬件执行。PTX 代码在运行时会被 JIT（Just-In-Time）编译 转换成 SASS 指令，或者在 nvcc 编译时通过 -arch 选项直接编译为 SASS 代码。
SASS 的特点

    与具体 GPU 架构绑定：不同的 GPU 架构（如 sm_70、sm_80）有不同的 SASS 指令集。
    更低级、更高效：相比 PTX，SASS 代码更接近底层硬件，能实现最优化的性能。
    手写难度大：SASS 代码直接操作寄存器、访存、执行单元等，手动编写非常复杂。

SASS 代码示例

SASS 代码通常通过 cuobjdump 提取，例如：

        /*0000*/ MOV R1, c[0x0][0x28] ;
        /*0008*/ SHL R1, R1, 0x2 ;
        /*0010*/ MOV R2, c[0x0][0x2c] ;
        /*0018*/ MOV R3, c[0x0][0x30] ;
        /*0020*/ IADD R4, R2, R1 ;
        /*0028*/ IADD R5, R3, R1 ;
        /*0030*/ LDG.E R6, [R4] ;
        /*0038*/ LDG.E R7, [R5] ;
        /*0040*/ IADD R6, R6, R7 ;
        /*0048*/ MOV R8, c[0x0][0x34] ;
        /*0050*/ IADD R9, R8, R1 ;
        /*0058*/ STG.E [R9], R6 ;

    这段代码与 PTX 示例类似，完成 C = A + B 计算。
    MOV、SHL、IADD 等指令直接对应 GPU 硬件执行的操作。

如何查看 SASS 代码

编译 CUDA 代码后，可以使用 cuobjdump 提取 SASS：

nvcc -arch=sm_70 -cubin mykernel.cu
cuobjdump -sass mykernel.cubin

这样可以看到 GPU 最终执行的 SASS 指令，帮助进行 深度优化。
3. 直接编写 PTX / SASS 的应用场景

直接编写 PTX 或 SASS 代码适用于以下场景：

    极致优化：
        需要对 寄存器使用、指令调度、访存模式 进行手动优化。
        例如：编写高效的 GEMM（矩阵乘法）核心代码。

    分析 CUDA 编译器优化：
        查看 PTX / SASS 代码，理解 nvcc 如何优化 CUDA 代码。
        例如：分析 nvcc -ptx 生成的代码，检查内存对齐、指令调度等优化行为。

    研究 NVIDIA GPU 硬件架构：
        研究新架构（如 Ampere、Hopper）的指令集、寄存器布局。
        例如：分析 cuobjdump -sass 输出的指令，研究 warp 执行模型。

    开发特殊用途的 GPU 程序：
        例如，编写 自定义线程调度、异常处理、内存管理 代码。
        在某些情况下，PTX 可用于创建 JIT 动态代码生成（类似于 LLVM JIT）。




PTX / SASS 直接编程 vs. CUDA C++
特性	CUDA C++	PTX	SASS
代码层级	高级语言	中间汇编	硬件汇编
硬件依赖性	低（可移植）	适配多架构	绑定特定 GPU
易读性	易读易写	较难	非常复杂
优化能力	受 nvcc 限制	可手动优化	可极致优化
调试工具支持	强	部分支持	较少支持
主要用途	常规开发	代码优化	深度调优
5. 结论

    PTX 编程 提供比 CUDA C++ 更低级的控制能力，但仍具有 架构无关性，适用于 性能优化和研究 GPU 编译。
    SASS 编程 直接面向 GPU 硬件，可实现 极限性能优化，但代价是 极高的开发难度。
    实际开发中，通常结合 CUDA C++ + PTX 分析，而 SASS 主要用于 反汇编调试和极端优化。

如果你的目标是优化 CUDA 代码，可以 先查看 PTX 代码，再决定是否需要深入 SASS 级别优化！ 🚀


# NVIDIA CUDA for Linux
## System Requirements

<ul>
<li>CUDA兼容GPU</li>
<li>支持的Linux系统和gcc编译器及工具链</li>
<li>NVIDIA CUDA 工具集<a href="http://www.nvidia.com/content/cuda/cuda-downloads.html">http://www.nvidia.com/content/cuda/cuda-downloads.html</a></li>
</ul>

## Pre-install

### Verify CUDA-Capable GPU

```shell
lspci | grep -i nvidia(update-pciids)
```

如果你的显卡在这个列表上:<a href="http://www.nvidia.com/object/cuda_gpus.html">http://www.nvidia.com/object/cuda_gpus.html</a>，那么你的GPU就是CUDA兼容的。

<ul>
<li>检查系统具有支持的Linux版本</li>
<li>检查系统安装了gcc</li>
<li>下载NVIDIA CUDA Toolkit</li>
<li>安装NVIDIA CUDA Toolkit</li>
<li>测试安装的软件运行正常并且可以与硬件通讯</li>
</ul>

## Install

```shell
wget 'http://developer.download.nvidia.com/compute/cuda/repos/rhel7/x86_64/cuda-repo-rhel7-8.0.44-1.x86_64.rpm'
sudo rpm -i cuda-repo-rhel7-8.0.44-1.x86_64.rpm
sudo yum clean all
sudo yum install cuda
```


# CUDA toolkit and cuDNN libraries

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define N 10000000
#define MAX_ERR 1e-6

void vector_add(float *out, float *a, float *b, int n) {
    for(int i = 0; i < n; i++){
        out[i] = a[i] + b[i];
    }
}

int main(){
    float *a, *b, *out;

    // Allocate memory
    a   = (float*)malloc(sizeof(float) * N);
    b   = (float*)malloc(sizeof(float) * N);
    out = (float*)malloc(sizeof(float) * N);

    // Initialize array
    for(int i = 0; i < N; i++){
        a[i] = 1.0f;
        b[i] = 2.0f;
    }

    // Main function
    vector_add(out, a, b, N);

    // Verification
    for(int i = 0; i < N; i++){
        assert(fabs(out[i] - a[i] - b[i]) < MAX_ERR);
    }

    printf("out[0] = %f\n", out[0]);
    printf("PASSED\n");
}
```

```sh
$ gcc vector-add.c

$ ./a.out
out[0] = 3.000000
PASSED

$ nvcc vector-add.cu

$ ./a.out
a.out: vector-add.cu:35: int main(): Assertion `fabs(out[i] - a[i] - b[i]) < MAX_ERR' failed.
Aborted (core dumped)
```

```
$ nvprof a.out
======== Warning: CUDA device error, GPU profiling skipped
a.out: vector-add.cu:51: int main(): Assertion `fabs(out[i] - a[i] - b[i]) < MAX_ERR' failed.
======== Error: Application received signal 134
```

nsight-systems-target nvidia-cuda-dev nvidia-cuda-toolkit nvidia-profiler nvidia-utils-510


The toolkit includes GPU-accelerated libraries, debugging and optimization tools, a C/C++ compiler, and a runtime library to deploy your application.


流处理器(SM)的概念，并且说过SM是gpu的计算单元，而线程是执行在SM上的并行代码。CUDA也有不同的版本，从1.0开始到现在的7.5，每个版本都会有一些新特性。CUDA是基于C语言的扩展，例如扩展了一些限定符device、shared等，从3.0开始也支持c++编程，从7.0开始支持c++11。

在安装CUDA的时候，会安装三个大的组件[1]，分别是NVIDIA驱动、toolkit和samples。驱动用来控制gpu硬件，toolkit里面包括nvcc编译器、Nsight调试工具(支持Eclipse和VS，linux用cuda-gdb)、分析和调试工具和函数库。samples或者说SDK，里面包括很多样例程序包括查询设备、带宽测试等等。


## Runtime API vs Driver API

在写cuda程序时，除了自己写的kernel函数，常常会调用cuda接口函数，最常见的就是全局内存分配函数cudaMalloc()，这里分配的内存暂且理解为gpu硬件参数上的显存。然而在某种情况下可能会看到另外一个函数cuMemAlloc()，这两个函数本质上完成的功能是一样的，都是在分配全局内存，但却属于两套接口，分别为Runtime API和Driver API。下图是cuda软件层的一些组件，实际上在cuda的软件层面，Runtime比Driver API更高级，封装的更好，在Runtime之上就是封装的更好的cuFFT等库。这两个库的函数都是能直接调用的，但Driver API相对于Runtime对底层硬件驱动的控制会更直接更方便，比如对context的控制[2]，Driver API调用硬件速度实际上比Runtime也快不了多少。不过Driver API向后兼容支持老版本的，这点Runtime就做不到，7.0的版本代码可能在6.5上就跑不了。大部分的功能两组API都有对应的实现，一般基于Driver API的开头会是cu，而基于Runtime API的开头是cuda，但基于Driver API来写程序会比Runtime API要复杂，虽然功能上差别不大，但是使用Runtime API和更高级的库函数就已经足够了。



## --gpu-architecture/-arch和--gpu-code/-code，它们的目标是为了让gpu代码能够兼容多种架构的gpu，它们的取值范围是一样的包括compute_10/compute_11/…/compute_30/compute_35/sm_10/sm_11/…/sm_30/sm_35，这些取值范围的意义实际上是指gpu的计算能力，或者是SM的版本，一般表示的是1.0/2.0/3.5这样的，具体体现在之前讲过的kepler/fermi的不同架构，所以两者实际含义是一样的(这里看[5]上表达应该是两者等价，但是为什么要搞两个，统一叫计算能力不行吗…)。而这里两个编译选项都要选择计算能力/sm版本，这是因为nvcc最后生成的可执行文件可以同时存在多个版本(对应compute_10/…/compute_35等)的kernel函数，这多个版本就通过这两个编译选项确定。这两个编译选项使得中间会生成的ptx文本文件和cubin二进制文件，它们指定了最后生成的可执行文件中可以满足的版本要求，即通过-arch指定ptx将来可以生成怎么样的版本(可以看成针对一个虚拟的gpu)，而-code参数是指当前就要生成的二进制的版本(可以想象成一个真实的GPU)，当前和将来的意思是指，最后生成的可执行文件中一个部分是马上就能在gpu上执行，而如果gpu硬件版本不支持这个能够马上执行的部分，那么显卡驱动会重新根据ptx指定的版本再生成一个能够执行的可执行版本，来满足这个gpu的硬件需求。它们的版本信息会先嵌入fatbin文件中，再通过fatbin与host代码编译生成的中间结果链接成最后的目标文件，这是针对一个.cu源文件生成一个.o文件，再将不同.o链接成可执行文件，那么这个可执行文件中就包含了多个版本的信息。假如取–arch=compute_10 –code=sm_13，在最后的可执行文件中，就有一个可以直接执行1.3的版本，假如此时gpu计算能力只有1.0，那么驱动会再次编译生成1.0版本的可执行文件，这个新的可执行文件就能在计算能力只有1.0的机器上运行了，从而通过这样的方式可以兼容不同计算能力的gpu。需要注意的是code的版本要高于arch。

显然这里有一个问题，一般而言生成的c++可执行程序就直接执行了，不会再有编译的过程，但是cuda不一样，它有一个机制叫做just-in-time(JIT，运行时编译)，为了满足两种执行cuda程序的方式。第一种就是直接执行cubin版本，第二种就是显卡驱动通过JIT在运行的时候根据ptx版本再次编译生成可执行文件。

NVCC实际上调用了很多工具来完成编译步骤(建议先看看[5]中完善的流程图)。在编译一个.cu源文件时，当输入下面的指令后，执行程序就会将整个编译过程都打印出来。cuda的整个编译流程分成两个分支，分支1预处理device代码并进行编译生成cubin或者ptx，然后整合到二进制文件fatbin中，分支2预处理host代码，再和fatbin一起生成目标文件。

nvcc --cuda test.cu -keep --dryrun

针对打印出来的每个过程中生成的文件做一个简单的分析，test.cu初始化一个runtime的硬件查询对象cudaDeviceProp，然后打印共享内存的大小。这里打印出来的内容只截取了每条命令的部分，主要给出中间的生成文件。

//打印信息
gcc -D__CUDA_ARCH__=200 -E -x c++ ... -o "test.cpp1.ii" "test.cu"

上面这一步是device代码预处理，它将一些定义好的枚举变量(例如cudaError)、struct(例如cuda的数据类型float4)、静态内联函数、extern “c++”和extern的函数、还重新定义了std命名空间、函数模板等内容写在main函数之前。

cudafe ... --gen_c_file_name "test.cudafe1.c" --gen_device_file_name "test.cudafe1.gpu" ...

这一步test.cpp1.ii被cudafe切分成了c/c++ host代码和.gpu结尾的device代码，其中main函数还是在.c结尾的文件中。

gcc -D__CUDA_ARCH__=200 -E -x c ... -o "test.cpp2.i" "test.cudafe1.gpu"
cudafe ... --gen_c_file_name "test.cudafe2.c" ... --gen_device_file_name "test.cudafe2.gpu"
gcc -D__CUDA_ARCH__=200 -E -x c ... -o "test.cpp3.i" "test.cudafe2.gpu"
filehash -s "test.cpp3.i" > "test.hash"
gcc -E -x c++ ... -o "test.cpp4.ii" "test.cu"
cudafe++ ... --gen_c_file_name "test.cudafe1.cpp" --stub_file_name "test.cudafe1.stub.c"

上面这段生成的test.cpp4.ii是在对host代码进行预处理，前面几行内容直接看文件有点看不出来，希望以后能够把这段补充起来。

cicc  -arch compute_20 ... --orig_src_file_name "test.cu" "test.cpp3.i" -o "test.ptx"
----------------
test.ptx:
    .version 4.1
    .target sm_20
    .address_size 64
----------------
test.cpp1.ii
    ".../include/sm_11_atomic_functions.h"
    ...
    ".../include/sm_12_atomic_functions.h"
    ...
    ".../include/sm_35_atomic_functions.h"

test.ptx文件中只记录了三行编译信息，可以看出对应了上面提到指定ptx的版本，以后可以根据这个版本再进行编译。实际上在host c++代码即每一个test.cpp*文件中，都包含了所有版本的SM头文件，从而可以调用每一种版本的函数进行编译。

ptxas -arch=sm_20 -m64  "test.ptx" -o "test.sm_20.cubin"

这一步叫做PTX离线编译，主要的目的是为了将代码编译成一个确定的计算能力和SM版本，对应的版本信息保存在cubin中。

fatbinary --create="test.fatbin" ... "file=test.sm_20.cubin" ... "file=test.ptx" --embedded-fatbin="test.fatbin.c" --cuda

这一步叫PTX在线编译，是将cubin和ptx中的版本信息保存在fatbin中。这里针对一个.cu源文件，调用系统的gcc/g++将host代码和fatbin编译成对应的目标文件。最后用c++编译器将目标文件链接起来生成可执行文件。



CUDA Toolkit由以下组件组成：

    Compiler: CUDA-C和CUDA-C++编译器NVCC位于bin/目录中。它建立在NVVM优化器之上，而NVVM优化器本身构建在LLVM编译器基础结构之上。希望开发人员可以使用nvm/目录下的Compiler SDK来直接针对NVVM进行开发。
    Tools: 提供一些像profiler,debuggers等工具，这些工具可以从bin/目录中获取
    Libraries: 下面列出的部分科学库和实用程序库可以在lib/目录中使用(Windows上的DLL位于bin/中)，它们的接口在include/目录中可获取。
    		- cudart: CUDA Runtime
    		- cudadevrt: CUDA device runtime
    		- cupti: CUDA  profiling tools interface
    		- nvml: NVIDIA management library
    		- nvrtc: CUDA runtime compilation
    		- cublas: BLAS (Basic Linear Algebra Subprograms，基础线性代数程序集)
    		- cublas_device: BLAS kernel interface
    		- ...
    CUDA Samples: 演示如何使用各种CUDA和library API的代码示例。可在Linux和Mac上的samples/目录中获得，Windows上的路径是C：\ProgramData\NVIDIA Corporation\CUDA Samples中。在Linux和Mac上，samples/目录是只读的，如果要对它们进行修改，则必须将这些示例复制到另一个位置。


这个在前面已经介绍了，nvcc其实就是CUDA的编译器,可以从CUDA Toolkit的/bin目录中获取,类似于gcc就是c语言的编译器。由于程序是要经过编译器编程成可执行的二进制文件，而cuda程序有两种代码，一种是运行在cpu上的host代码，一种是运行在gpu上的device代码，所以nvcc编译器要保证两部分代码能够编译成二进制文件在不同的机器上执行。nvcc涉及到的文件后缀及相关意义如下表


nvidia-smi

nvidia-smi全程是NVIDIA  System Management Interface ，它是一个基于前面介绍过的NVIDIA Management Library(NVML)构建的命令行实用工具，旨在帮助管理和监控NVIDIA GPU设备。
nvcc和nvidia-smi显示的CUDA版本不同？

在我们实验室的服务器上nvcc --version显示的结果如下：

nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2018 NVIDIA Corporation
Built on Tue_Jun_12_23:07:04_CDT_2018
Cuda compilation tools, release 9.2, V9.2.148



nvcc的CUDA 版本是9.2，而nvidia-smi的CUDA版本是10.0。很奇怪的是有时候绝大多数情况代码也能整成跑起来，stackoverflow上的一个解释如下：

CUDA有两个主要的API：runtime(运行时) API和driver API。这两个API都有对应的CUDA版本（如9.2和10.0等）。

    用于支持driver API的必要文件(如libcuda.so)是由GPU driver installer安装的。nvidia-smi就属于这一类API。
    用于支持runtime API的必要文件(如libcudart.so以及nvcc)是由CUDA Toolkit installer安装的。（CUDA Toolkit Installer有时可能会集成了GPU driver Installer）。nvcc是与CUDA Toolkit一起安装的CUDA compiler-driver tool，它只知道它自身构建时的CUDA runtime版本。它不知道安装了什么版本的GPU driver，甚至不知道是否安装了GPU driver。

综上，如果driver API和runtime API的CUDA版本不一致可能是因为你使用的是单独的GPU driver installer，而不是CUDA Toolkit installer里的GPU driver installer。
runtime和driver API区别

下图很清楚的展示前面提到的各种概念之间的关系，其中runtime和driver API在很多情况非常相似，也就是说用起来的效果是等价的，但是你不能混合使用这两个API，因为二者是互斥的。也就是说在开发过程中，你只能选择其中一种API。简单理解二者的区别就是：runtime是更高级的封装，开发人员用起来更方便，而driver API更接近底层，速度可能会更快。

两种API详细的区别如下：

    复杂性
    		- runtime API通过提供隐式初始化、上下文管理和模块管理来简化设备代码管理。这使得代码更简单，但也缺乏驱动程序API所具有的控制级别。
    		- 相比之下，driver API提供了更细粒度的控制，特别是在上下文和模块加载方面。实现内核启动要复杂得多，因为执行配置和内核参数必须用显式函数调用指定。
    控制
    		- 对于runtime API，其在运行时，所有内核都在初始化期间自动加载，并在程序运行期间保持加载状态。
    		- 而使用driver API，可以只加载当前需要的模块，甚至动态地重新加载模块。driver API也是语言独立的，因为它只处理cubin对象。
    上下文管理
    上下文管理可以通过driver API完成，但是在runtime API中不公开。相反，runtime API自己决定为线程使用哪个上下文:
    	- 如果一个上下文通过driver API成为调用线程的当前上下文，runtime将使用它，
    	- 如果没有这样的上下文，它将使用“主上下文(primary context)”。

主上下文会根据需要创建，每个设备每个进程一个上下文，并进行引用计数，然后在没有更多的引用时销毁它们。在一个进程中，所有runtime API的用户都将共享主上下文，除非上下文已成为每个线程的当前上下文。runtime使用的上下文，即当前上下文或主上下文，可以用cudaDeviceSynchronize()同步，也可以用cudaDeviceReset()销毁。

但是，将runtime API与主上下文一起使用会有tradeoff。例如，对于那些需要给较大的软件包写插件的开发者来说者会带来不少麻烦，因为如果所有的插件都在同一个进程中运行，它们将共享一个上下文，但可能无法相互通信。也就是说，如果其中一个在完成所有CUDA工作后调用cudaDeviceReset()，其他插件将失败，因为它们使用的上下文在它们不知情的情况下被破坏。为了避免这个问题，CUDA clients可以使用driver API来创建和设置当前上下文，然后使用runtime API来处理它。但是，上下文可能会消耗大量的资源，比如设备内存、额外的主机线程和设备上上下文切换的性能成本。当将driver API与基于runtime API(如cuBLAS或cuFFT)构建的库一起使用时，这种runtime-driver上下文共享非常重要。



    参考Linux中PATH、 LIBRARY_PATH、 LD_LIBRARY_PATH的区别

PATH

PATH是可执行文件路径，是三个中我们最常接触到的，因为我们命令行中的每句能运行的命令，如ls、top、ps等，都是系统通过PATH找到了这个命令执行文件的所在位置，再run这个命令（可执行文件）。 比如说，在用户的目录~/mycode/下有一个bin文件夹，里面放了有可执行的二进制文件、shell脚本等。如果想要在任意目录下都能运行上述bin文件夹的可执行文件，那么只需要把这个bin的路径添加到PATH即可，方法如下：

# vim ~/.bashrc
PATH=$PATH:~/mycode/bin

LIBRARY_PATH和LD_LIBRARY_PATH

这两个路径可以放在一起讨论，

    LIBRARY_PATH是程序编译期间查找动态链接库时指定查找共享库的路径
    LD_LIBRARY_PATH是程序加载运行期间查找动态链接库时指定除了系统默认路径之外的其他路径

两者的共同点是库，库是这两个路径和PATH路径的区别，PATH是可执行文件。

两者的差异点是使用时间不一样。一个是编译期，对应的是开发阶段，如gcc编译；一个是加载运行期，对应的是程序已交付的使用阶段。

配置方法也是类似：

export  LD_LIBRARY_PATH=LD_LIBRARY_PATH:XXXX



建议选择使用 .run 文件安装，因为使用 .deb可能会将已经安装的较新的显卡驱动替换。
cuda 安装

进入到放置 cuda_9.0.176_384.81_linux.run 的目录：

sudo chmod +x cuda_9.0.176_384.81_linux.run # 为 cuda_9.0.176_384.81_linux.run 添加可执行权限
./cuda_9.0.176_384.81_linux.run # 安装 cuda_9.0.176_384.81_linux.run




$ lspci -k | grep -A 2 -E "(VGA|3D)"
01:00.0 VGA compatible controller: NVIDIA Corporation GF119 [NVS 310] (rev a1)
        Subsystem: NVIDIA Corporation GF119 [NVS 310]
        Kernel modules: nvidiafb, nouveau
# W32.4 0811 17:34:28  aaron@dev12:/home/barn/cuda
$

nvidia-settings -q all | grep SLIMode







ERROR: NVIDIA driver is not loaded


Command 'nvcc' not found, but can be installed with:
sudo apt install nvidia-cuda-toolkit


$ nvcc -V
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2021 NVIDIA Corporation
Built on Thu_Nov_18_09:45:30_PST_2021
Cuda compilation tools, release 11.5, V11.5.119
Build cuda_11.5.r11.5/compiler.30672275_0

## cudnn，针对深度卷积神经网络的加速库。

cudnn

这个其实就是一个专门为深度学习计算设计的软件库，里面提供了很多专门的计算函数，如卷积等。从上图也可以看到，还有很多其他的软件库和中间件，包括实现c++ STL的thrust、实现gpu版本blas的cublas、实现快速傅里叶变换的cuFFT、实现稀疏矩阵运算操作的cuSparse以及实现深度学习网络加速的cuDNN等等，具体细节可参阅GPU-Accelerated Libraries



## nvidia-visual-profiler

nvidia-visual-profiler




CUDA（Compute Unified Device Architecture，统一计算架构[1]）是由英伟达NVIDIA所推出的一种整合技术，是该公司对于GPGPU的正式名称。透过这个技术，使用者可利用NVIDIA的GPU进行图像处理之外的运算，亦是首次可以利用GPU作为C-编译器的开发环境。CUDA 开发套件（CUDA Toolkit ）只能将自家的CUDA C-语言（对OpenCL只有链接的功能[2]），也就是执行于GPU的部分编译成PTX中间语言或是特定NVIDIA GPU架构的机器码（NVIDIA 官方称为 "device code"）；而执行于中央处理器部分的C / C++程式码（NVIDIA 官方称为 "host code"）仍依赖于外部的编译器



UDA底层是以C/C++为主，并以使用“NVCC”——NVIDIA基于LLVM的C/C++编译器介面来进行编译，但程式师也可以使用编译器指令（如OpenACC）以及多种程式设计语言扩展对CUDA平台进行操作。

CUDA平台还支援其它计算介面，如Khronos Group的OpenCL，Microsoft的DirectCompute，以及C++AMP。也可以透过其他语言如 Python，Perl，Java，Ruby，Lua，Haskell，MATLAB，IDL及Mathematica 的介面间接调用CUDA。


在GPUs（GPGPU）上使用图形APIs进行传统通用计算，CUDA技术有下列几个优点：[8]

    分散读取——代码可以从记忆体的任意位址读取

        统一虚拟记忆体（Unified Memory, 从 CUDA 6.0 开始）—— 将所有 CPU 和 GPU 的内存置于统一管理的虚拟记忆体空间下。

            共用记忆体（Global Memory）—— 存取快速的区域，使之在多个执行绪间共用，有效频宽比纹理记忆体（Texture Memory）更大。

                与GPU之间更快的下载与回读

                    全面支持整型与位操作，包括整型纹理查找





## Install

### Install The latest CUDA Toolkit

```
sudo apt install system76-cuda-latest
```

### Switch between different versions:

```
sudo update-alternatives --config cuda
```

To verify installation, run this command to see the current version of the CUDA compiler:

```
nvcc -V
```

You can also check the version of the installer and patches installed with this command:

```
cat /usr/lib/cuda/version.txt
```

## Not running Pop!_OS?

The previous instructions will work with Pop!_OS out of the box but for Ubuntu and other Debian derivatives the following commands will need to be ran first:

```
sudo echo "deb http://apt.pop-os.org/proprietary bionic main" | sudo tee -a /etc/apt/sources.list.d/pop-proprietary.list
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-key 204DD8AEC33A7AFF
sudo apt update
```

*These packages have been tested with the System76 NVIDIA driver only.

The following [article](https://support.system76.com/articles/system76-driver/) will go over installing the System76 NVIDIA driver.
9.1


支持CUDA的产品有
1、Tesla：用于技术和科学计算
2、Quadro：用于专业可视化
3、NVS：用于商务多屏演示
4、GeForce 和 TITAN：用于游戏娱乐
5、Jetson：用于边缘测AI自主机器


【Tesla】系列产品全部由nVidia原厂设计和生产，产品品质和服务更有保障，而且官方明确定义该类产品适用于数据中心和高性能计算场景，简单的说就是服务器专用系列。从材料和驱动上都对科学计算以及人工智能训练和推理做了相应的优化。
另外，还加入了ECC内存纠错功能，这点是在GeForce系列中没有的。
【GeForce】系列本来针对的是个人用户桌面环境的娱乐使用的，就是游戏影音。该系列产品的设计本就不适合高强度、长时间的工作，而且对于程序和驱动方面的优化也只是针对游戏方面的。在其用户使用协议中也申明了，不能安装在服务器上使用，否则将失去维保和支持。
但是很多企业和个人也用该系列的某些产品做人工智能研发，因为相比专业的Tesla卡，同等计算能力的情况下，这个更便宜。



【TITAN】系列，官方列表把TITAN和GeForce放在了同一个列表中，所以我认为二者的定位应该是差不多的。但是为什么nVidia官方又推荐研究人员、开发人员和创作者使用TITAN RTX呢。我感觉这就像他每一代新产品发布的时候都说“这是世界上最先进的GPU”一样。


用最新的RTX 3090，性价比应该是更高的。因为RTX 3090采用了最新的Ampere架构，CUDA核心和显存带宽远比RTX TITAN高出近1倍，计算精度性能这方面没找到相关的数据，但是根据这个架构，这个配置，也不可能低到哪里去。最重要的是，官方给的价格，RTX 3090比RTX TITAN便宜了1000美刀，京东上的价格，二者也相差3-5k。



【Quadro】系列，为什么不选它呢，因为老黄准备把这个系列取消了，变成RTX A系列。这个系列的显卡定义是专业图形工作站使用的，简单的说就是绘图，制作，设计等到这类的专业性很强的场景使用的，比如我们熟悉的Adobe全家桶，3DMAX，CAD等这类的软件，而且该类显卡的驱动还在某些专业软件上做过针对性的优化。
虽然它的性能也很不错了，但是根据设计，它的应用场景同样不适合服务器这种7*24h的高负荷且需要足够的稳定性的场景。而且和GeForce差不多性能的情况下，价格却比GeForce贵出去很多。所以我认为用它来做深度学习训练，有些不太合适。
【Jetson】系列，这个东西被设计成基于arm架构的AI运算模块，功耗很低，10W-30W左右，所以更适合运用在边缘计算场景下。




nVidia显卡架构是“Tesla（特斯拉）→Fermi（费米） → Kepler（开普勒） → Maxwell（麦克斯韦） → Pascal（帕斯卡） → Volta（伏特） → Turing（图灵） → Amper（安培）





    Tesla（特斯拉）: 市面已经没有相关显卡
        Fermi（费米）：GeForce 400, 500, 600, GT-630
            Kepler（开普勒）：Tesla K40/K80, GeForce 700, GT-730
                Maxwell（麦克斯韦尔）: Tesla/Quadro M series GeForce 900, GTX-970
                    Pascal（帕斯卡）: Tesla p100,GTX 1080, GTX 1070, GTX 1060
                        Votal（伏打）: Tesla V100, GTX 1180
                            Turing（图灵）: T4,GTX 1660 Ti, RTX 2060
                                Ampere（安培）: A100








    Tesla（特斯拉）: 市面已经没有相关显卡
    Fermi（费米）：GeForce 400, 500, 600, GT-630
    Kepler（开普勒）：Tesla K40/K80, GeForce 700, GT-730
    Maxwell（麦克斯韦尔）: Tesla/Quadro M series GeForce 900, GTX-970
    Pascal（帕斯卡）: Tesla p100,GTX 1080, GTX 1070, GTX 1060
    Votal（伏打）: Tesla V100, GTX 1180
    Turing（图灵）: T4,GTX 1660 Ti, RTX 2060
    Ampere（安培）: A100



Tesla（特斯拉）本来是第一代架构，现在发展为数据中心专用GPU型号代名词了




wget https://developer.download.nvidia.com/compute/cuda/11.7.1/local_installers/cuda-repo-debian11-11-7-local_11.7.1-515.65.01-1_amd64.debsudo dpkg -i cuda-repo-debian11-11-7-local_11.7.1-515.65.01-1_amd64.debsudo cp /var/cuda-repo-debian11-11-7-local/cuda-*-keyring.gpg /usr/share/keyrings/sudo add-apt-repository contribsudo apt-get updatesudo apt-get -y install cuda






Installation Instructions:

wget https://developer.download.nvidia.com/compute/cuda/11.7.1/local_installers/cuda-repo-debian11-11-7-local_11.7.1-515.65.01-1_amd64.debsudo dpkg -i cuda-repo-debian11-11-7-local_11.7.1-515.65.01-1_amd64.debsudo cp /var/cuda-repo-debian11-11-7-local/cuda-*-keyring.gpg /usr/share/keyrings/sudo add-apt-repository contribsudo apt-get updatesudo apt-get -y install cuda




Installation Instructions:


wget https://developer.download.nvidia.com/compute/cuda/11.7.1/local_installers/cuda-repo-debian11-11-7-local_11.7.1-515.65.01-1_amd64.debsudo dpkg -i cuda-repo-debian11-11-7-local_11.7.1-515.65.01-1_amd64.debsudo cp /var/cuda-repo-debian11-11-7-local/cuda-*-keyring.gpg /usr/share/keyrings/sudo add-apt-repository contribsudo apt-get updatesudo apt-get -y install cuda


The CUDA Toolkit contains Open-Source Software. The source code can be found here.





cuda toolkit是一个开发套件，cuda新版本会加入新的硬件特性，用于更好的为新硬件进行开发。由于cuda toolkit是向后兼容的，所以旧版本开发的kernel代码在cuda toolkit新版本上一般是可以运行的。

cuda core一般指的是硬件核心，cuda core上也是有版本区分，但是叫做“计算能力(compute capability )"。


cuda capability版本，这个是和gpu架构相关，主要指示一些硬件上的特性（GPU指令集）。

驱动则是连接上面两者的桥梁。

cuda capability、驱动、cuda库，这三者会在一定范围内相互兼容，主要还是取决于新特性在老架构上的实现难度。同样的，驱动版本也会制约cuda版本







GeForce RTX 3080 with CUDA capability sm_86 is not compatible with the current PyTorch installation. The current PyTorch install supports CUDA capabilities sm_37 sm_50 sm_60 sm_61 sm_70 sm_75 compute_37.

CUDA capability sm_86：算力8.6
上面表面上是说PyTorch，实际上是PyTorch依赖的CUDA版本的问题
翻译一下就是：RTX 3080的算力是8.6，但是当前的PyTorch依赖的CUDA版本支持的算力只有3.7、5.0、6.0、6.1、7.0、7.5及3.7以下






A CUDA application binary (with one or more GPU kernels) can contain the compiled GPU code in two forms, binary cubin objects and forward-compatible PTX assembly for each kernel. Both cubin and PTX are generated for a certain target compute capability. A cubin generated for a certain compute capability is supported to run on any GPU with the same major revision and same or higher minor revision of compute capability. For example, a cubin generated for compute capability 7.0 is supported to run on a GPU with compute capability 7.5, however a cubin generated for compute capability 7.5 is not supported to run on a GPU with compute capability 7.0, and a cubin generated with compute capability 7.x is not supported to run on a GPU with compute capability 8.x

翻译一下就是：
算力7.0的显卡可以在支持最高算力7.5的CUDA版本下运行，但是算力7.5的显卡不可以在支持最高算力7.0的CUDA版本下运行
同理算力8.x的显卡不可以在支持最高算力7.x的CUDA版本下运行





The base installer is available for download below.

Base Installer
Installation Instructions:

wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-ubuntu2204.pinsudo mv cuda-ubuntu2204.pin /etc/apt/preferences.d/cuda-repository-pin-600wget https://developer.download.nvidia.com/compute/cuda/11.7.1/local_installers/cuda-repo-ubuntu2204-11-7-local_11.7.1-515.65.01-1_amd64.debsudo dpkg -i cuda-repo-ubuntu2204-11-7-local_11.7.1-515.65.01-1_amd64.debsudo cp /var/cuda-repo-ubuntu2204-11-7-local/cuda-*-keyring.gpg /usr/share/keyrings/sudo apt-get updatesudo apt-get -y install cuda



## CUDA Toolkit 11.7 Update 1 Downloads

Installation Instructions:

wget https://developer.download.nvidia.com/compute/cuda/11.7.1/local_installers/cuda_11.7.1_515.65.01_linux.runsudo sh cuda_11.7.1_515.65.01_linux.run


::::::::::::::
CUDA-Algorithm.md
::::::::::::::
# Stream Compaction
* [Stream Compaction on GPU - Efficient implementation - CUDA](http://www.davidespataro.it/cuda-stream-compaction-efficient-implementation/)
* [CUDA stream compaction algorithm](https://stackoverflow.com/questions/34059753/cuda-stream-compaction-algorithm)
* [Improving the Efficiency of Compact/Scatter in CUDA](https://stackoverflow.com/questions/28924161/improving-the-efficiency-of-compact-scatter-in-cuda)
* https://github.com/knotman90/cuStreamComp/blob/master/src/cuCompactor.cuh
* https://github.com/Aman-Sachan-asach/CUDA-Stream-Compaction

* https://github.com/cudpp/cudpp/blob/master/src/cudpp/kernel/compact_kernel.cuh
* https://github.com/cudpp/cudpp/blob/master/src/cudpp/app/compact_app.cu
* https://github.com/cudpp/cudpp/blob/master/src/cudpp/kernel/compact_kernel.cuh

# Histogram
* [About warp voting function](https://stackoverflow.com/questions/10557254/about-warp-voting-function)

# Bilinear interpolation
* [Bilinear interpolation with nvidia CUDA C](http://mkaczanowski.com/bilinear-interpolation-with-nvidia-cuda-c/)
* [Bilinear interpolation in C/C++ and CUDA](https://stackoverflow.com/questions/21128731/bilinear-interpolation-in-c-c-and-cuda)
* [Result mismatch in Image re-sizing using Bi-Linear Interpolation](https://stackoverflow.com/questions/15312615/result-mismatch-in-image-re-sizing-using-bi-linear-interpolation)
* [Understanding texture's linear filtering in cuda](https://stackoverflow.com/questions/8674185/understanding-textures-linear-filtering-in-cuda)::::::::::::::
CUDA-Code-Snippets.md
::::::::::::::
# Error Handling

```c
#define CHECK(call) { \
 cudaError_t err; \
 if ( (err = (call)) != cudaSuccess) { \
 fprintf(stderr, "Got error %s at %s:%d\n", cudaGetErrorString(err), \
 __FILE__, __LINE__); \
 exit(1); \
 } \
}
```

```c
template< typename T >
void check(T result, char const *const func, const char *const file, int const line)
{
    if (result)
    {
        fprintf(stderr, "CUDA error at %s:%d code=%d(%s) \"%s\" \n",
                file, line, static_cast<unsigned int>(result), _cudaGetErrorEnum(result), func);
        DEVICE_RESET
        // Make sure we call CUDA Device Reset before exiting
        exit(EXIT_FAILURE);
    }
}

#ifdef __DRIVER_TYPES_H__
// This will output the proper CUDA error strings in the event that a CUDA host call returns an error
#define checkCudaErrors(val)           check ( (val), #val, __FILE__, __LINE__ )

// This will output the proper error string when calling cudaGetLastError
#define getLastCudaError(msg)      __getLastCudaError (msg, __FILE__, __LINE__)

inline void __getLastCudaError(const char *errorMessage, const char *file, const int line)
{
    cudaError_t err = cudaGetLastError();

    if (cudaSuccess != err)
    {
        fprintf(stderr, "%s(%i) : getLastCudaError() CUDA error : %s : (%d) %s.\n",
                file, line, errorMessage, (int)err, cudaGetErrorString(err));
        DEVICE_RESET
        exit(EXIT_FAILURE);
    }
}
#endif
```

* [CUDA编程中的错误处理](http://notes.maxwi.com/2017/03/29/cuda-error-handle/)

* [How to debug kernel throwing an exception?](https://devtalk.nvidia.com/default/topic/545591/how-to-debug-kernel-throwing-an-exception-/)
* [Error handling in CUDA kernels](https://devtalk.nvidia.com/default/topic/495403/error-handling-in-cuda-kernels/)
```cpp
// Macro to catch CUDA errors in kernel launches
#define CHECK_LAUNCH_ERROR()                                          \
do {                                                                  \
    /* Check synchronous errors, i.e. pre-launch */                   \
    cudaError_t err = cudaGetLastError();                             \
    if (cudaSuccess != err) {                                         \
        fprintf (stderr, "Cuda error in file '%s' in line %i : %s.\n",\
                 __FILE__, __LINE__, cudaGetErrorString(err) );       \
        exit(EXIT_FAILURE);                                           \
    }                                                                 \
    /* Check asynchronous errors, i.e. kernel failed (ULF) */         \
    err = cudaThreadSynchronize();                                    \
    if (cudaSuccess != err) {                                         \
        fprintf (stderr, "Cuda error in file '%s' in line %i : %s.\n",\
                 __FILE__, __LINE__, cudaGetErrorString( err) );      \
        exit(EXIT_FAILURE);                                           \
    }                                                                 \
} while (0)
```

* [How to do error checking in CUDA](https://codeyarns.com/2011/03/02/how-to-do-error-checking-in-cuda/)

```cpp
// Define this to turn on error checking
#define CUDA_ERROR_CHECK

#define CudaSafeCall( err ) __cudaSafeCall( err, __FILE__, __LINE__ )
#define CudaCheckError()    __cudaCheckError( __FILE__, __LINE__ )

inline void __cudaSafeCall( cudaError err, const char *file, const int line )
{
#ifdef CUDA_ERROR_CHECK
    if ( cudaSuccess != err )
    {
        fprintf( stderr, "cudaSafeCall() failed at %s:%i : %s\n",
                 file, line, cudaGetErrorString( err ) );
        exit( -1 );
    }
#endif

    return;
}

inline void __cudaCheckError( const char *file, const int line )
{
#ifdef CUDA_ERROR_CHECK
    cudaError err = cudaGetLastError();
    if ( cudaSuccess != err )
    {
        fprintf( stderr, "cudaCheckError() failed at %s:%i : %s\n",
                 file, line, cudaGetErrorString( err ) );
        exit( -1 );
    }

    // More careful checking. However, this will affect performance.
    // Comment away if needed.
    err = cudaDeviceSynchronize();
    if( cudaSuccess != err )
    {
        fprintf( stderr, "cudaCheckError() with sync failed at %s:%i : %s\n",
                 file, line, cudaGetErrorString( err ) );
        exit( -1 );
    }
#endif

    return;
}
```

* [CUDA::Minimal and Error Handling](http://blogs.perl.org/users/david_mertens/2011/07/cudaminimal-and-error-handling.html)

---
* [How to Query Device Properties and Handle Errors in CUDA C/C++](https://devblogs.nvidia.com/parallelforall/how-query-device-properties-and-handle-errors-cuda-cc/)

```cpp
saxpy<<<(N+255)/256, 256>>>(N, 2.0, d_x, d_y);
cudaError_t errSync  = cudaGetLastError();
cudaError_t errAsync = cudaDeviceSynchronize();
if (errSync != cudaSuccess)
  printf("Sync kernel error: %s\n", cudaGetErrorString(errSync);
if (errAsync != cudaSuccess)
  printf("Async kernel error: %s\n", cudaGetErrorString(errAsync);
```

# Timer
```cpp
#ifndef __GPU_TIMER_H__
#define __GPU_TIMER_H__

struct GpuTimer
{
      cudaEvent_t start;
      cudaEvent_t stop;

      GpuTimer()
      {
            cudaEventCreate(&start);
            cudaEventCreate(&stop);
      }

      ~GpuTimer()
      {
            cudaEventDestroy(start);
            cudaEventDestroy(stop);
      }

      void Start()
      {
            cudaEventRecord(start, 0);
      }

      void Stop()
      {
            cudaEventRecord(stop, 0);
      }

      float Elapsed()
      {
            float elapsed;
            cudaEventSynchronize(stop);
            cudaEventElapsedTime(&elapsed, start, stop);
            return elapsed;
      }
};

#endif  /* __GPU_TIMER_H__ */
```

* https://stackoverflow.com/questions/7876624/timing-cuda-operations
* https://github.com/thrust/thrust/blob/master/examples/include/timer.h

# Smart Pointer
* [Bringing CUDA into the year 2011: C++11 smart pointers with CUDA, CUB, nccl, streams, and CUDA Unified Memory Management with CUB and CUBLAS](https://ernestyalumni.wordpress.com/2017/09/28/bringing-cuda-into-the-year-2011-c11-smart-pointers-with-cuda-cub-nccl-streams-and-cuda-unified-memory-management-with-cub-and-cublas/#more-747)

* [Is there a CUDA smart pointer?](https://stackoverflow.com/questions/16509414/is-there-a-cuda-smart-pointer)
* https://github.com/dzitkowskik/CUDA-smart-pointers
* [Use of unique_ptr and cudaMalloc](https://stackoverflow.com/questions/47383386/use-of-unique-ptr-and-cudamalloc)
* https://github.com/BaderLab/ecuda/blob/master/include/ecuda/ptr/unique_ptr.hpp

```cpp
#include <cuda.h>
#include <cuda_runtime.h>

#define CUDA_CHECK(call) \
    do { \
        cudaError_t error; \
        if ((error = (call)) != cudaSuccess) {\
            fprintf(stderr, "CUDA error %s at %s:%d\n", cudaGetErrorString(error), __FILE__, __LINE__); \
            exit(1); \
        } \
    } while (0)


template <typename T, typename Deleter>
using unique_ptr_temp = std::unique_ptr<T, Deleter>;

// template <typename T>
// void device_ptr_deleter(T* ptr)
// {
//     CUDA_CHECK(cudaFree(ptr));
// }
//
// template <typename T>
// void host_ptr_deleter(T* ptr)
// {
//     CUDA_CHECK(cudaFreeHost(ptr));
// }

template <typename T>
struct device_ptr_deleter {
    void operator()(T* ptr) {
        CUDA_CHECK(cudaFree(ptr));
    }
};

template <typename T>
struct host_ptr_deleter {
    void operator()(T* ptr) {
        CUDA_CHECK(cudaFreeHost(ptr));
    }
};

template <typename T>
// using unique_ptr_device = unique_ptr_temp<T, decltype(device_ptr_deleter<T>)>;
// using unique_ptr_device = std::unique_ptr<T[], decltype(device_ptr_deleter<T>)>;
using unique_ptr_device = std::unique_ptr<T[], device_ptr_deleter<T>>;

template <typename T>
// using unique_ptr_host = unique_ptr_temp<T, decltype(host_ptr_deleter<T>)>;
// using unique_ptr_host = std::unique_ptr<T[], decltype(host_ptr_deleter<T>)>;
using unique_ptr_host = std::unique_ptr<T[], host_ptr_deleter<T>>;
```

# Interesting repos
* https://github.com/NervanaSystems/maxas
* https://github.com/jkehne/cuda-malloc-hook
* https://github.com/jkehne/GPUswap
* https://github.com/canonizer/libgpuvm::::::::::::::
CUDA-Handbook-Notes.md
::::::::::::::
# Chap. 5 Memory

### 5.2.11 Atomic Operations

```
class cudaSpinlock {
  public:
    cudaSpinlock(int *p);
    void acquire();
    void release();
  private:
    int *m_p;
};

inline __device__
cudaSpinlock::cudaSpinlock(int *p)
{
  m_p = p;
}

inline __device__ void
cudaSpinlock::acquire()
{
  while (atomicCAS(m_p, 0, 1));
}

inline __device__ void
cudaSpinlock::release()
{
  atomicExch(m_p, 0);
}
```


# Chap. 8 Streaming Multiprocessors
## 8.1 Memory
### 8.1.3 Global Memory

> Because atomic operations are implemented using hardware in the GPU’s integrated memory controller, they do not work across the PCI Express bus and thus do not work correctly on device memory pointers that correspond to host memory or peer memory.

### 8.1.5 Shared Memory
#### Atomics in Shared Memory
LDSLK (load shared with lock) instruction



# Chap. 12 Reduction
## Overview
## Two-Pass Reduction

> When writing warp synchronous code, the `volatile` keyword must be used for the pointers into shared memory. Otherwise, the compiler may introduce optimizations that change the order of memory operations and the code will not work correctly.

## Single-Pass Reduction

The `__threadfence()` causes all threads in the block to wait until any pending memory transactions have been posted to device memory. When `__threadfence()` is executed, writes to global memory are visible to all threads, not just the calling thread or threads in the block.

## Reduction with Atomics
## Arbitrary Block Sizes
## Reduction Using Arbitrary Data Types

```cpp
template<class T>
struct SharedMemory
{
    __device__ inline operator       T*()
    {
        extern __shared__ int __smem[];
        return (T*) (void *) __smem;
    }
    __device__ inline operator const T*() const
    {
        extern __shared__ int __smem[];
        return (T*) (void *) __smem;
    }
};
```

> a specialization of the `SharedMemory` template must be declared; otherwise, the compiler will generate the following error:

> ```
> Error: Unaligned memory accesses not supported
> ```

我个人喜欢的方式：

```cpp
extern __shared__ int __smemInt[];
extern __shared__ T __smemT[];
```

## Predicate Reduction

**WARP-LEVEL PRIMITIVES**

```cpp
int __ballot( int p );
```

`__ballot()` evaluates a condition for all threads in the warp and returns a 32-bit word, where each bit gives the condition for the corresponding thread in the warp. Since `__ballot()` broadcasts its result to every thread in the warp, it is effectively a reduction across the warp.

See [Warp Vote Functions](http://docs.nvidia.com/cuda/cuda-c-programming-guide/#warp-vote-functions)

```cpp
int __popc( int i );
```

`__popc` returns the number of set bits in the input word.

```cpp
int __syncthreads_count( int p );
```

`__syncthreads_count` waits until all warps in the threadblock have arrived, then broad- casts to all threads in the block the number of threads for which the input condition was true. (SM 2.0)

## Warp Reduction with Shuffle

> Kepler added shuffle instructions that enable data interchange between threads within a warp without staging the data through shared memory. Although these instructions execute with the same latency as shared memory, they have the benefit of doing the exchange without performing both a read and a write, and they can reduce shared memory usage.

# Chap. 13 Scan

**Scan / prefix scan / prefix sum / parallel prefix sum** is used as a building block for:
* • Radix sort
* • Quick sort
* • Stream compaction and stream splitting
* • Sparse matrix-vector multiplication
* • Minimum spanning tree construction
* • Computation of summed area tables

## Overview

prefix dependency

Blelloch's two-pass algorithm

```
upsweep(a, N)
for d from 0 to (lg N) - 1
    in parallel for i from 0 to N - 1 by 2^(d+1)
        a[i + 2^(d+1) - 1] += a[i + 2^(d-1)]
```

```
downsweep(a, N)
    a[N - 1] = 0
    for d from (lg N) - 1 downto 0
        in parallel for i from 0 to N - 1 by 2^(d+1)
            t := a[i + 2^d - 1]
            a[i + 2^d - 1] = a[i + 2^(d+1) - 1]
            a[i + 2^(d+1) - 1] += t
```

## Scan and Circuit Design

* Brent-Kung circuit
* Sklansky (minimum-depth) circuit
* Kogge-Stone circuit

## CUDA Implementations

### Scan-then-fan (recursive)

4N global memory operations: The initial scan performs one read and one write, and then the fan performs another read and write.

### Reduce-then-scan (recursive)

3N global memory operations: The initial reduction pass performs one read per element, and then the scan performs another read and a write.

### Two-level reduce-then-scan

// TODO

## Warp Scans
warp scan modeled on the Kogge-Stone circuit (work-inefficient)

```cpp
template<class T>
inline __device__ T
scanWarp( volatile T *sPartials )
{
    const int tid = threadIdx.x;
    const int lane = tid & 31;
    if ( lane >=  1 ) sPartials[0] += sPartials[- 1];
    if ( lane >=  2 ) sPartials[0] += sPartials[- 2];
    if ( lane >=  4 ) sPartials[0] += sPartials[- 4];
    if ( lane >=  8 ) sPartials[0] += sPartials[- 8];
    if ( lane >= 16 ) sPartials[0] += sPartials[-16];
    return sPartials[0];
}
```

### ZERO PADDING

去掉判断语句，但会增加shared memory大小

### TEMPLATED FORMULATIONS

```cpp
template<bool bZeroPad>
inline __device__ int
scanSharedIndex( int tid )
{
    if ( bZeroPad ) {
        const int warp = tid >> 5;
        const int lane = tid & 31;
        return 49 * warp + 16 + lane;
    }
    else {
        return tid;
    }
}

template<typename T, bool bZeroPad>
inline __device__ __host__ int
scanSharedMemory( int numThreads )
{
    if ( bZeroPad ) {
        const int warpcount = numThreads>>5;
        return (49 * warpcount + 16)*sizeof(T);
    }
    else {
        return numThreads*sizeof(T);
    }
}

template<class T, bool bZeroPadded>
inline __device__ T
scanWarp( volatile T *sPartials )
{
    T t = sPartials[0];
    if ( bZeroPadded ) {
        t += sPartials[- 1]; sPartials[0] = t;
        t += sPartials[- 2]; sPartials[0] = t;
        t += sPartials[- 4]; sPartials[0] = t;
        t += sPartials[- 8]; sPartials[0] = t;
        t += sPartials[-16]; sPartials[0] = t;
    }
    else {
        const int tid = threadIdx.x;
        const int lane = tid & 31;
        if ( lane >=  1 ) { t += sPartials[- 1]; sPartials[0] = t; }
        if ( lane >=  2 ) { t += sPartials[- 2]; sPartials[0] = t; }
        if ( lane >=  4 ) { t += sPartials[- 4]; sPartials[0] = t; }
        if ( lane >=  8 ) { t += sPartials[- 8]; sPartials[0] = t; }
        if ( lane >= 16 ) { t += sPartials[-16]; sPartials[0] = t; }
    }
    return t;
}
```

### WARP SHUFFLE

```cpp
// implemented in inline PTX, because the compiler does not emit efficient code to deal with the predicate returned by the shuffle instruction.
__device__ __forceinline__
int
scanWarpShuffle_step(int partial, int offset)
{
    int result;
    asm(
            "{.reg .u32 r0;"
            ".reg .pred p;"
            "shfl.up.b32 r0|p, %1, %2, 0;"
            "@p add.u32 r0, r0, %3;"
            "mov.u32 %0, r0;}"
            : "=r"(result) : "r"(partial), "r"(offset), "r"(partial));
    return result;
}

// The template parameter is an integer, and typically the value 5 is passed because 5 is the base 2 logarithm of the warp size of 32.
template <int levels>
__device__ __forceinline__
int
scanWarpShuffle(int mysum)
{
    for(int i = 0; i < levels; ++i)
        mysum = scanWarpShuffle_step(mysum, 1 << i);
    return mysum;
}
```

```cpp
template <int logBlockSize>
__device__ int
scanBlockShuffle(int val, const unsigned int idx)
{
    const unsigned int lane   = idx & 31;
    const unsigned int warpid = idx >> 5;
    __shared__ int sPartials[32];

    // Intra-warp scan in each warp
    val = scanWarpShuffle<5>(val);

    // Collect per-warp results
    if (lane == 31) sPartials[warpid] = val;
    __syncthreads();

    // Use first warp to scan per-warp results
    if (warpid == 0) {
        int t = sPartials[lane];
        t = scanWarpShuffle<logBlockSize-5>( t );
        sPartials[lane] = t;
    }
    __syncthreads();

    // Add scanned base sum for final result
    if (warpid > 0) {
        val += sPartials[warpid - 1];
    }
    return val;
}
```

### INSTRUCTION COUNTS

* Use `cuobjdump` to disassemble.
* the `SSY/.S` instruction pairs push and pop the divergence stack
* `__syncthreads()` compiles to `BAR.SYNC` instructions in SASS.

## Stream Compaction

// TODO

# Chap. 14 N-Body





::::::::::::::
CUDA-Install.md
::::::::::::::
* [NVIDIA Accelerated Linux Graphics Driver README and Installation Guide](http://us.download.nvidia.com/XFree86/Linux-x86_64/381.22/README/index.html)


* [Installing and testing CUDA in Ubuntu 14.04](https://askubuntu.com/questions/451672/installing-and-testing-cuda-in-ubuntu-14-04)
* [How can I install CUDA on Ubuntu 16.04?](https://askubuntu.com/questions/799184/how-can-i-install-cuda-on-ubuntu-16-04)
* [How to install NVIDIA.run?](https://askubuntu.com/questions/149206/how-to-install-nvidia-run)
* [Ubuntu 16.04 安装英伟达（Nvidia）显卡驱动](https://gist.github.com/dangbiao1991/7825db1d17df9231f4101f034ecd5a2b)
* [Ubuntu 16.04 安装 CUDA Toolkit 7.5](https://gist.github.com/dangbiao1991/2c895917ea888ce33af8c1c72444b7bf)
* [Ubuntu 16.04 nvidia安装](http://www.cnblogs.com/MimiSnowing/p/5655054.html)

# Driver List
* https://www.nvidia.com/Download/Find.aspx?lang=en-us

# Trouble shooting
## The system is running in low-graphics mode
* [Ubuntu更新出现 The system is running in low-graphics mode解决](http://blog.sina.com.cn/s/blog_66439a3e0101bnce.html)

## The driver installation is unable to locate the kernel source. Please make sure that the kernel source packages are installed and set up correctly. If you know that the kernel source packages are installed and set up correctly, you may pass the location of the kernel source with the '--kernel-source-path' flag.

```
sudo yum install epel-release
yum install --enablerepo=epel dkms
```

* https://stackoverflow.com/questions/38016466/installing-cuda-7-5-on-centos-7-unable-to-locate-the-kernel-source

## PAM authentication failed, cannot start X server

`/etc/pam.d/xserver`:

```
#%PAM-1.0
auth sufficient pam_rootok.so
#auth required pam_console.so
auth sufficient pam_permit.so
account sufficient pam_permit.so
session optional pam_keyinit.so force revoke
```

* [[SOLVED] CentOS 6.4: Cannot run startx as non-root user](https://www.centos.org/forums/viewtopic.php?t=4743)
* [PAM authentication failed, cannot start X server](https://listman.redhat.com/archives/pam-list/2001-December/msg00069.html)

## kernel: NVRM: API mismatch
* [解决Driver/library version mismatch](https://comzyh.com/blog/archives/967/)
### CentOS

```
yum erase kmod-nvidia nvidia-x11-drv
yum install kmod-nvidia nvidia-x11-drv
```

* http://centosfaq.org/centos/nvidia-error/

## NVIDIA(0): Failed to initialize the nvidia kernel module
* [(EE) NVIDIA(0): Failed to initialize the nvidia kernel module](https://www.linuxquestions.org/questions/slackware-14/ee-nvidia-0-failed-to-initialize-the-nvidia-kernel-module-250076/)

## nvidia-drm-priv.h linux/fence.h not found
* [375.39 has compile errors on Fedora 25 running 4.10.10 kernel targeting GTX1070](https://devtalk.nvidia.com/default/topic/1005455/375-39-has-compile-errors-on-fedora-25-running-4-10-10-kernel-targeting-gtx1070/)
* [Linux 4.9-git(rc1) - 375.10 build errors](https://devtalk.nvidia.com/default/topic/972761/linux-4-9-git-rc1-375-10-build-errors/)
* https://github.com/negativo17/nvidia-driver/issues/19#issuecomment-294179636
* [Unable to install Nvidia driver *linux-x86_64-378.13 on kernel 4.10.10-200.fc25.x86_64](https://devtalk.nvidia.com/default/topic/1005246/linux/unable-to-install-nvidia-driver-linux-x86_64-378-13-on-kernel-4-10-10-200-fc25-x86_64/)
* https://pleiades.ucsc.edu/hyades/DKMS_on_CentOS_7

* [Unable to install driver 375.66 on CentOS 7](https://devtalk.nvidia.com/default/topic/1012901/unable-to-install-driver-375-66-on-centos-7/?offset=5)
* [Heads up: 375.26 build breaks after recent commits to kernel](https://devtalk.nvidia.com/default/topic/982667/heads-up-375-26-build-breaks-after-recent-commits-to-kernel/)
* http://rglinuxtech.com/?p=1834
* [Nvidia proprietary driver compile fail on kernels >4.9.x - patch.](https://forums-archive.eveonline.com/default.aspx?g=posts&t=510830)



* [CUDA 8 downgrades the driver 384.59 to 375.26](https://devtalk.nvidia.com/default/topic/1021752/cuda-setup-and-installation/cuda-8-downgrades-the-driver-384-59-to-375-26/)

## NVRM: RmInitAdapter failed
* [NVRM: RmInitAdapter failed](https://stackoverflow.com/questions/46107222/nvrm-rminitadapter-failed)
* [NVRM: RmInitAdapter failed! with Gigabyte GTX 750 on Kubuntu and Arch](https://devtalk.nvidia.com/default/topic/776693/nvrm-rminitadapter-failed-with-gigabyte-gtx-750-on-kubuntu-and-arch/)
* [GTX 1080 Throwing Bad TLP PCIe Bus Errors](https://forums.geforce.com/default/topic/957456/geforce-drivers/gtx-1080-throwing-bad-tlp-pcie-bus-errors/post/4969345/#4969345)

## [Debian]Can't locate InstallUtils.pm in @INC (you may need to install the InstallUtils module)
* [Can't locate InstallUtils.pm in @INC](https://devtalk.nvidia.com/default/topic/983777/cuda-setup-and-installation/can-t-locate-installutils-pm-in-inc/)
* [CUDA 8.0 on Debian](https://devtalk.nvidia.com/default/topic/968656/cuda-8-0-on-debian/)
* [Install CUDA on Debian](https://devtalk.nvidia.com/default/topic/992023/install-cuda-on-debian/)

```
unpack .run file ./cuda*.run –tar mxvf
copy InstallUtils.pm to /usr/lib/x86_64-linux-gnu/perl-base
export $PERL5LIB
```

## [Debian, gcc6, CUDA8] Unsupported compiler
* [CUDA incompatible with my gcc version](https://stackoverflow.com/questions/6622454/cuda-incompatible-with-my-gcc-version)
* https://www.udacity.com/wiki/cs344/troubleshoot-gcc47

```
sudo update-alternatives --install /usr/bin/gcc gcc /usr/local/bin/gcc-5.4.0 60 --slave /usr/bin/g++ g++ /usr/local/bin/g++-5.4.0
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 40 --slave /usr/bin/g++ g++ /usr/bin/g++-6
sudo update-alternatives --config gcc
```

## PREEMPT_RT kernel

* [[!] Real Time Kernel On Nvidia Jetson TX2](http://www.numerickly.com/2018/12/30/real-time-kernel-on-nvidia-jetson-tx2/)
* [[!] Building a real-time kernel for the Nvidia Jetson TK1](https://www.jann.cc/2015/05/18/peempt_rt_for_the_nvidia_jetson_tk1.html)
* [Realtime Preemption](https://elinux.org/Realtime_Preemption)
* [Real-time GPU computing with RT PREEMPT](https://elinux.org/Real-time_GPU_computing_with_RT_PREEMPT)

* https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=883793

* https://www.concurrent-rt.com/products/gpu-workbench/
* https://rt.wiki.kernel.org/index.php/RT_NvidiaGraphicsDriver
* https://www.cs.unc.edu/~anderson/projects/rtgpu.html

* https://github.com/ApolloAuto/apollo/issues/1872
* [ubuntu14.04下安装apollo-kernel和N卡驱动.md](https://note.youdao.com/ynoteshare1/index.html?id=f1f44a10594d9134281b917e3923a3e4&type=note#/)
* [Nvidia 340.107 and real-time kernel](https://www.linuxquestions.org/questions/slackware-14/nvidia-340-107-and-real-time-kernel-4175645485/)
* [the better distro kernel](https://liquorix.net/)
* [Linux realtime kernel + NVIDIA drivers](https://forum.level1techs.com/t/linux-realtime-kernel-nvidia-drivers/137427)
* [Problem installing Nvidia driver on a real time kernel](https://forum.linuxcnc.org/38-general-linuxcnc-questions/36176-problem-installing-nvidia-driver-on-a-real-time-kernel)
* https://www.quora.com/Is-anyone-using-GPUs-for-real-time-computer-vision-or-image-processing

* [NVidia Driver 295.20 and the RT-Preempt Patch](http://www.clemensrabe.com/linux/nvidia-driver-295-20-and-the-rt-preempt-patch)

* https://devtalk.nvidia.com/default/topic/1045608/jetson-agx-xavier/xavier-preempt-rt-patch/
* https://devtalk.nvidia.com/default/topic/777636/simply-impossible-to-use-an-nvidia-card-on-a-real-time-kernel-no-musician-can-use-nvidia-/
* https://devtalk.nvidia.com/default/topic/1042378/jetson-agx-xavier/preempt-rt-patch-on-jetson-kernel/
* https://devtalk.nvidia.com/default/topic/1030560/jetson-tx2/how-can-i-take-a-preempt_rt-patch-to-kernel-on-tx2-/


* https://github.com/christianjann/L4T_PREEMPT_RT
* https://github.com/kozyilmaz/nvidia-jetson-rt


* [HOWTO setup Linux with PREEMPT_RT properly](https://wiki.linuxfoundation.org/realtime/documentation/howto/applications/preemptrt_setup)
* [HOWTO build a simple RT application](https://wiki.linuxfoundation.org/realtime/documentation/howto/applications/application_base)
* [Scheduling - Policy and Priority](https://wiki.linuxfoundation.org/realtime/documentation/technical_basics/sched_policy_prio/start)
* [Memory for Real-time Applications](https://wiki.linuxfoundation.org/realtime/documentation/howto/applications/memory#memory_locking)

### archlinux
* https://aur.archlinux.org/packages/linux-rt/
* https://aur.archlinux.org/packages/nvidia-rt/
* [[RESOLVED] linux-rt > linux-rt-lts > nvidia-rt > nvidia-rt-lts](https://bbs.archlinux.org/viewtopic.php?id=226516)
* [nvidia-dkms not working along with linux-rt](https://bbs.archlinux.org/viewtopic.php?id=222958)
* [linux-rt and NVIDIA](https://bbs.archlinux.org/viewtopic.php?id=135164)

### manjaro
* https://github.com/manjaro/packages-community/issues/367
* https://github.com/manjaro/packages-community/issues/195

### gentoo
* [Real Time preemption patched kernel and NVIDIA drivers](https://forums.gentoo.org/viewtopic-t-814331-start-0.html)

### apollo
* https://github.com/ApolloAuto/apollo-kernel

* https://github.com/torvalds/linux/blob/master/kernel/sched/sched.h
* https://github.com/torvalds/linux/blob/master/kernel/sched/completion.c::::::::::::::
CUDA-Library.md
::::::::::::::
# Thrust
* https://docs.nvidia.com/cuda/thrust/index.html
* [Part B - CUDA Programming Model: Thrust](https://scs.senecac.on.ca/~gpu610/pages/content/cudat.html)

* [GPU PROGRAMMING WITH THRUST TEMPLATE LIBRARY](https://nusit.nus.edu.sg/technus/hpc/gpu-programming-thrust-template-library/)

## Debug
* https://github.com/thrust/thrust/wiki/Debugging

## CUDA stream
```
thrust::cuda::par.on(stream)
```
* [Getting CUDA Thrust to use a CUDA stream of your choice](https://stackoverflow.com/questions/24368197/getting-cuda-thrust-to-use-a-cuda-stream-of-your-choice)
* [Thrust and streams](https://devtalk.nvidia.com/default/topic/1023642/thrust-and-streams/)
* https://thrust.github.io/doc/group__execution__policies.html
* https://github.com/thrust/thrust/blob/master/examples/cuda/simple_cuda_streams.cu


## vector
* [Array of vectors using Thrust](https://stackoverflow.com/questions/12406948/array-of-vectors-using-thrust)
* [Is it possible to use thrust::device_vector and thrust::fill for 2D arrays using thrust library in CUDA](https://stackoverflow.com/questions/15682254/is-it-possible-to-use-thrustdevice-vector-and-thrustfill-for-2d-arrays-using)
* [how to cast a 2-dimensional thrust::device_vector<thrust::device_vector<int>> to raw pointer](https://stackoverflow.com/questions/38056472/how-to-cast-a-2-dimensional-thrustdevice-vectorthrustdevice-vectorint-to)

### `host_vector`
* [difference between thrust::host_vector and std::vector?](https://groups.google.com/forum/#!topic/thrust-users/siFgi6m2o24)

## `counting_iterator`
* https://thrust.github.io/doc/classthrust_1_1counting__iterator.html
* [Purpose and usage of counting_iterators in CUDA Thrust library](https://stackoverflow.com/questions/18705190/purpose-and-usage-of-counting-iterators-in-cuda-thrust-library)

## Trouble-shooting

### `thrust::raw_reference_cast`
Not needed in CUDA-8 thrust (1.8.1)

### `thrust::max_element` crash
* [Cuda Thrust min_element crashes](https://stackoverflow.com/questions/36608199/cuda-thrust-min-element-crashes)
* https://github.com/thrust/thrust/issues/776

### 1.9.x: `STATIC_ASSERTION_FAILURE`
* https://github.com/thrust/thrust/issues/526

# NPP
* [NVIDIA NPP](http://www.cnblogs.com/hlwfirst/articles/5003576.html)
* https://stackoverflow.com/questions/12422498/arent-npp-functions-completely-optimized
* [NPP Dilate and Erode functions' examples](https://devtalk.nvidia.com/default/topic/488237/npp-dilate-and-erode-functions-39-examples/)
* [Morphological Operations with CUDA](https://devtalk.nvidia.com/default/topic/457951/morphological-operations-with-cuda/?offset=5)
* [nppiErode_8u_C1R from NPP library](https://devtalk.nvidia.com/default/topic/486980/nppierode_8u_c1r-from-npp-library/)
## stream
* [Cuda, two streams created by a NPP function](https://stackoverflow.com/questions/39202436/cuda-two-streams-created-by-a-npp-function)
## example
* https://github.com/jbmulligan/quip/blob/30c22dd7b9f29f9debbdd3a600665439029070b8/libsrc/cuda/cuda_npp.cpp

# CUB
* http://nvlabs.github.io/cub/
* https://github.com/NVlabs/cub

# cuFFT
## cufftPlan2d
* [4.1: cufftPlan2d(): X & Y params reversed?](https://devtalk.nvidia.com/default/topic/508501/4-1-cufftplan2d-x-38-y-params-reversed-/)
* [cufftPlan2d exception](https://stackoverflow.com/questions/19424113/cufftplan2d-exception)
* https://stackoverflow.com/questions/5529212/cuda-cufftplan2d-plan-size-question

## spRadix kernel1Mem
* https://stackoverflow.com/questions/35488348/cuda-cufft-api-behavior-in-concurrent-streams

## Error Handling
* [CUFFT error handling](https://devtalk.nvidia.com/default/topic/542160/cufft-error-handling/)
* https://stackoverflow.com/questions/16267149/cufft-error-handling
* https://stackoverflow.com/questions/20847021/cufft-how-to-calculate-the-fft-when-the-input-is-a-pitched-array

## Half Precision FP16
* [Unexpectedly low performance of cuFFT with half floating point (FP16)](https://devtalk.nvidia.com/default/topic/1014402/unexpectedly-low-performance-of-cufft-with-half-floating-point-fp16-/)
* [[!] Half precision cuFFT Transforms](https://devtalk.nvidia.com/default/topic/974803/half-precision-cufft-transforms/)
### Sample code
* https://github.com/murphy17/YipLab-HoloDeconv/blob/master/src/main.cu
* https://github.com/mpicbg-scicomp/gearshifft/blob/bfa433497cee48243f96040c44b4ec2eb0b2a201/inc/libraries/cufft/cufft.hpp

## Error Handling
```cpp
// cuFFT API errors
static const char *_cudaGetErrorEnum(cufftResult error)
{
    switch (error)
    {
        case CUFFT_SUCCESS:
            return "CUFFT_SUCCESS";

        case CUFFT_INVALID_PLAN:
            return "CUFFT_INVALID_PLAN";

        case CUFFT_ALLOC_FAILED:
            return "CUFFT_ALLOC_FAILED";

        case CUFFT_INVALID_TYPE:
            return "CUFFT_INVALID_TYPE";

        case CUFFT_INVALID_VALUE:
            return "CUFFT_INVALID_VALUE";

        case CUFFT_INTERNAL_ERROR:
            return "CUFFT_INTERNAL_ERROR";

        case CUFFT_EXEC_FAILED:
            return "CUFFT_EXEC_FAILED";

        case CUFFT_SETUP_FAILED:
            return "CUFFT_SETUP_FAILED";

        case CUFFT_INVALID_SIZE:
            return "CUFFT_INVALID_SIZE";

        case CUFFT_UNALIGNED_DATA:
            return "CUFFT_UNALIGNED_DATA";

        case CUFFT_INCOMPLETE_PARAMETER_LIST:
            return "CUFFT_INCOMPLETE_PARAMETER_LIST";

        case CUFFT_INVALID_DEVICE:
            return "CUFFT_INVALID_DEVICE";

        case CUFFT_PARSE_ERROR:
            return "CUFFT_PARSE_ERROR";

        case CUFFT_NO_WORKSPACE:
            return "CUFFT_NO_WORKSPACE";

        case CUFFT_NOT_IMPLEMENTED:
            return "CUFFT_NOT_IMPLEMENTED";

        case CUFFT_LICENSE_ERROR:
            return "CUFFT_LICENSE_ERROR";

        case CUFFT_NOT_SUPPORTED:
            return "CUFFT_NOT_SUPPORTED";
    }

    return "<unknown>";
}

#define CUFFT_SAFE_CALL(call) { \
    cufftResult_t err; \
    if ((err = (call)) != CUFFT_SUCCESS) { \
        fprintf(stderr, "Got error %d:%s at %s:%d\n", err, _cudaGetErrorEnum(err), \
                __FILE__, __LINE__); \
        exit(1); \
    } \
}
```

* [Error String for cufft?](https://devtalk.nvidia.com/default/topic/490138/error-string-for-cufft-/)
* https://stackoverflow.com/questions/16267149/cufft-error-handling
* [CUFFT error handling](https://devtalk.nvidia.com/default/topic/542160/cufft-error-handling/)

# `cuDPP`
* http://cudpp.github.io/

# `CuDNN`
* https://docs.nvidia.com/deeplearning/sdk/cudnn-developer-guide/index.html

-----
> `CUDNN_CONVOLUTION_FWD_PREFER_FASTEST`
>
> In this configuration, the routine `cudnnGetConvolutionForwardAlgorithm()` will return the fastest algorithm regardless how much workspace is needed to execute it.
>
> `CUDNN_CONVOLUTION_FWD_SPECIFY_​WORKSPACE_LIMIT`
>
> In this configuration, the routine `cudnnGetConvolutionForwardAlgorithm()` will return the fastest algorithm that fits within the memory limit that the user provided.

> `CUDNN_STATUS_EXECUTION_FAILED`
>
> The GPU program failed to execute. This is usually caused by a failure to launch some cuDNN kernel on the GPU, which can occur for multiple reasons.
>
> To correct: check that the hardware, an appropriate version of the driver, and the cuDNN library are correctly installed.
>
> Otherwise, this may indicate a internal error/bug in the library.

-----

* [How to verify CuDNN installation?](https://stackoverflow.com/questions/31326015/how-to-verify-cudnn-installation)

* [Convolutions with cuDNN](http://www.goldsborough.me/cuda/ml/cudnn/c++/2017/10/01/14-37-23-convolutions_with_cudnn/)
* [Choosing Convolution Algo in cuDNN v2](https://devtalk.nvidia.com/default/topic/820974/choosing-convolution-algo-in-cudnn-v2/)


* https://github.com/tensorflow/tensorflow/issues/8928

* [Accelerate Machine Learning with the cuDNN Deep Neural Network Library](https://devblogs.nvidia.com/accelerate-machine-learning-cudnn-deep-neural-network-library/)


* [CUDNN学习笔记（1）](https://yq.aliyun.com/articles/497073?spm=a2c4e.11153940.blogcont497077.16.32ed11a3iJ2oBr)
* [CUDNN学习笔记（2）](https://yq.aliyun.com/articles/497075?spm=a2c4e.11153940.blogcont497073.18.58e9e481qyrcRn)
* [CUDNN学习笔记（3）](https://yq.aliyun.com/articles/497076?spm=a2c4e.11153940.blogcont497075.10.67336e01U1t9AK)
* [CUDNN学习笔记（4）](https://yq.aliyun.com/articles/497077?spm=a2c4e.11153940.blogcont497076.18.70b768a4WPQfeA)

## status == CUDNN_STATUS_SUCCESS (4 vs. 0)  CUDNN_STATUS_INTERNAL_ERROR


# CUTLASS
https://github.com/NVIDIA/cutlass


# NVTX
* [CUDA Pro Tip: Generate Custom Application Profile Timelines with NVTX](https://devblogs.nvidia.com/cuda-pro-tip-generate-custom-application-profile-timelines-nvtx/)
* [CUDA Pro Tip: Profiling MPI Applications](https://devblogs.nvidia.com/cuda-pro-tip-profiling-mpi-applications/)

# NVML
* [Increase Performance with GPU Boost and K80 Autoboost](https://devblogs.nvidia.com/increase-performance-gpu-boost-k80-autoboost/)


# TensorRT
* [TensorRT简介](https://blog.csdn.net/fengbingchun/article/details/78469551?locationNum=6&fps=1)
* https://developer.nvidia.com/tensorrt

* [Deploying Deep Neural Networks with NVIDIA TensorRT](https://devblogs.nvidia.com/deploying-deep-learning-nvidia-tensorrt/)


* [TensorRT 3.0在Jetson TX2部署实战](https://zhuanlan.zhihu.com/p/36207779)
* [高性能深度学习支持引擎实战——TensorRT](https://yq.aliyun.com/articles/580307?utm_content=m_46063)
* [入门必读！一堂来自NVIDIA的深度学习公开课](http://baijiahao.baidu.com/s?id=1562762102523402&wfr=spider&for=pc)


# static link CUDA libs

* [How to link host code with a static CUDA library after separable compilation?](https://stackoverflow.com/questions/16289086/how-to-link-host-code-with-a-static-cuda-library-after-separable-compilation)

cuDNN静态链接CMake范例：
```
target_link_libraries(${OUTPUT_LIBRARY_NAME}
    dl
    rt
    pthread
    /usr/local/cuda/lib64/libcurand_static.a
    /usr/local/cuda/lib64/libcublas_static.a
    /usr/local/cuda/lib64/libcudnn_static.a
    /usr/local/cuda/lib64/libculibos.a
    /usr/local/cuda/lib64/libcudart_static.a
    )
```


## undefined reference to `culibosInit'
* `culibos`
* [CUDNN Static Linking Error](https://devtalk.nvidia.com/default/topic/1032775/cuda-programming-and-performance/cudnn-static-linking-error/post/5254368/)

## undefined reference to `shm_unlink' / undefined reference to `shm_open'
* `-lrt`
* [undefined reference 'shm_open', already add -lrt flag here](https://stackoverflow.com/questions/9923495/undefined-reference-shm-open-already-add-lrt-flag-here)
## undefined reference to `__cudaUnregisterFatBinary'
* `libcudart_static.a`在其他CUDA lib后面链接
* [CUDA 6.0 Linking error: undefined reference to `__cudaUnregisterFatBinary'](https://stackoverflow.com/questions/23936170/cuda-6-0-linking-error-undefined-reference-to-cudaunregisterfatbinary)
## undefined reference to `dlopen'
* `-ldl`
* [How do I deal with “undefined reference to dlopen” errors while compiling and using OpenFST on Ubuntu?](https://askubuntu.com/questions/454443/how-do-i-deal-with-undefined-reference-to-dlopen-errors-while-compiling-and-us)
* [Linux c++ error: undefined reference to 'dlopen'](https://stackoverflow.com/questions/956640/linux-c-error-undefined-reference-to-dlopen)::::::::::::::
CUDA-Memory.md
::::::::::::::
# Device Memory Spaces

| Memory     |  Location | on/off chip  Cached | Access | Scope                 |   Lifetime       |
| -------    |  -------  | ---------           | ------ | -----                 |   --------       |
| Register   |  On       | n/a                 |   R/W  |  1 thread             |   Thread         |
| Local      |  Off      | Yes                 |   R/W  |  1 thread             |   Thread         |
| Shared     |  On       | n/a                 |   R/W  |  All threads in block |   Block          |
| Global     |  Off      | †                   |   R/W  |  All threads + host   |   Host allocation|
| Constant   |  Off      | Yes                 |   R    |  All threads + host   |   Host allocation|
| Texture    |  Off      | Yes                 |   R    |  All threads + host   |   Host allocation|

-----

* [CUDA and pointers to pointers](https://codeofhonour.blogspot.jp/2014/10/cuda-and-pointers-to-pointers.html)

* [How is CUDA memory managed?](https://stackoverflow.com/questions/8684770/how-is-cuda-memory-managed)

## Texture Memory

* [Texture Memory in CUDA | What is Texture Memory in CUDA programming](https://cuda-programming.blogspot.jp/2013/02/texture-memory-in-cuda-what-is-texture.html)

-----------------------
### When to Use Texture Memory in CUDA

* If you update your data rarely but read it often...especially if there tends to be some kind of spatial locality to the read access pattern...
* * i.e. nearby threads access nearby locations in the texture
* * especially if the precise read access pattern is difficult to predict
* Also, you need to use texture memory in order to visualize your data using the graphics pipeline

### When Not to Use Texture Memory in CUDA

* We should not use texture memory when we read our input data exactly once after update it.

-----------------------

* [cudaChannelFormatDesc () in CUDA | How to use cudaChannelFormatDesc in CUDA](https://cuda-programming.blogspot.jp/2013/02/cudachannelformatdesc-in-cuda-how-to.html)

* [Do cudaBindTextureToArray and cudaUnbindTexture break GPU-CPU concurrency?](https://stackoverflow.com/questions/16168905/do-cudabindtexturetoarray-and-cudaunbindtexture-break-gpu-cpu-concurrency)

* [Combining texture memory Unified Memory in CUDA 6](https://stackoverflow.com/questions/24672523/combining-texture-memory-unified-memory-in-cuda-6)
* [Converting array to texture representation](https://stackoverflow.com/questions/27586173/converting-array-to-texture-representation/27586872)

* [CUDA streams, texture binding and async memcpy](https://stackoverflow.com/questions/12411896/cuda-streams-texture-binding-and-async-memcpy)
## Texture Object
-----

* [CUDA Pro Tip: Kepler Texture Objects Improve Performance and Flexibility](https://devblogs.nvidia.com/cuda-pro-tip-kepler-texture-objects-improve-performance-and-flexibility/)
> * There is no need to know at compile time which textures will be used at run time, which enables much more dynamic execution and flexible programming
> * texture objects only need to be instantiated once, and are not subject to the hardware limit of 128 texture references, so there is no need to continuously bind and unbind them. Using texture objects, the overhead of binding (up to 1 μs) and unbinding (up to 0.5 μs) textures is eliminated. What is not commonly known is that each outstanding texture reference that is bound when a kernel is launched incurs added launch latency—up to 0.5 μs per texture reference. This launch overhead persists even if the outstanding bound textures are not even referenced by the kernel. Again, using texture objects instead of texture references completely removes this overhead.

-----

* [Texture reference parameter in kernel function](https://devtalk.nvidia.com/default/topic/393184/texture-reference-parameter-in-kernel-function/)
* [Is there a workaround to the inflexible use of texture references in CUDA](https://stackoverflow.com/questions/9710813/is-there-a-workaround-to-the-inflexible-use-of-texture-references-in-cuda)

# Host Memory
## Pinned memory

* Host memory that is essentially from virtual memory
* OS guarantees the page-locked memory will never be <del>paged</del> swapped out, which means it’s always in physical memory.
* Also called Page-locked memory

-----

* https://en.wikipedia.org/wiki/CUDA_Pinned_memory
* [Why is CUDA pinned memory so fast?](https://stackoverflow.com/questions/5736968/why-is-cuda-pinned-memory-so-fast)
* [Advantages/Disadvantages of using pinned memory](https://devtalk.nvidia.com/default/topic/767368/advantages-disadvantages-of-using-pinned-memory-/)
* [Is CUDA pinned memory zero-copy?](https://stackoverflow.com/questions/21611252/is-cuda-pinned-memory-zero-copy)
* [When to use cudaHostRegister() and cudaHostAlloc()? What is the meaning of “Pinned or page-locked” memory? Which are the equivalent in OpenCL?](https://stackoverflow.com/questions/39454465/when-to-use-cudahostregister-and-cudahostalloc-what-is-the-meaning-of-pinn)
* [cuda的Pinned Memory（分页锁定内存）](http://blog.csdn.net/zhangpinghao/article/details/21046435)

* [Is cudaHostRegister equivalent to mlock() system call?](https://stackoverflow.com/questions/10648849/is-cudahostregister-equivalent-to-mlock-system-call)


* [cudaMemcpy too slow](https://stackoverflow.com/questions/7430003/cudamemcpy-too-slow)

* [[!] Choosing Between Pinned and Non-Pinned Memory](https://www.cs.virginia.edu/~mwb7w/cuda_support/pinned_tradeoff.html)


* [`cudaHostAlloc`](http://horacio9573.no-ip.org/cuda/group__CUDART__MEMORY_g15a3871f15f8c38f5b7190946845758c.html)

### Max pinned memory size
* [How To Increase Ulimit Values in Redhat Linux ?](https://www.unixarena.com/2013/12/how-to-increase-ulimit-values-in-redhat.html)
* [Pinned memory limit](https://devtalk.nvidia.com/default/topic/883675/cuda-programming-and-performance/pinned-memory-limit/1)
* [CUDA and pinned (page locked) memory not page locked at all?](https://stackoverflow.com/questions/26888890/cuda-and-pinned-page-locked-memory-not-page-locked-at-all)


## Mapped memory
* The page-locked host memory can be mapped into the address space of the device using flag `cudaHostAllocMapped`
* Hardware may not support this function
* * Using `cudaGetDeviceProperties` to check the canMapHostMemory property

* Advantages:
* * No explicit memory copy.
* * Can perform read/write concurrently

* Disadvantages:
* * GPU and CPU can write the same address simultaneously
* * Atomic functions cannot guarantee for CPU concurrent writes

-----

* [(cuda) Zero-copy memory and Unified Virtual Addressing (UVA)](http://sett.com/gpgpu/cuda-zero-copy-memory-and-unified-virtual-addressing-uva)
* [CPU memory access latency of data allocated with malloc() vs. cudaHostAlloc() on Tegra TK1](https://stackoverflow.com/questions/27972491/cpu-memory-access-latency-of-data-allocated-with-malloc-vs-cudahostalloc-on)
* [Pinned memory slows CPU computation](https://devtalk.nvidia.com/default/topic/908507/pinned-memory-slows-cpu-computation/)
* [Does CUDA mapped memory take up GPU RAM?](https://stackoverflow.com/questions/25060433/does-cuda-mapped-memory-take-up-gpu-ram)
* Use [`cudaMemGetInfo`](https://www.cs.cmu.edu/afs/cs/academic/class/15668-s11/www/cuda-doc/html/group__CUDART__MEMORY_gd5d6772f4b2f3355078ecd6059e6aa74.html) to query device memory.
* [Default Pinned Memory Vs Zero-Copy Memory](https://stackoverflow.com/questions/5209214/default-pinned-memory-vs-zero-copy-memory)

-----

* [零复制(Zero Copy)(零拷贝内存)](https://www.jianshu.com/p/831edc17cd0d)

## Write-combining memory
* Pinned memory is allocated as cacheable by default
* When allocated as write-combining memory, it frees up L1 and L2 cache resource usage.

* Advantage and disadvantage
* * Write-combining memory is not snooped during transfers across bus, which can improve transfer performance by up to 40%
* * Reading from write-combining memory from host is slow, which should in general be used for memory that the host only write to.

-----

* [Write combining](https://en.wikipedia.org/wiki/Write_combining)
* [Write Combining Buffer对代码性能的影响](http://peg.hengtiansoft.com/article/write-combining-bufferdui-dai-ma-xing-neng-de-ying-xiang/)
* [Write Combined Memory How it enhences performance?](https://devtalk.nvidia.com/default/topic/462781/write-combined-memory-how-it-enhences-performance-/)
* [Write-Combining memory can slow down your application?](https://devtalk.nvidia.com/default/topic/456724/write-combining-memory-can-slow-down-your-application-/)
* [When should I prefer write-combined CUDA-allocated mapped host memory?](https://stackoverflow.com/questions/35977061/when-should-i-prefer-write-combined-cuda-allocated-mapped-host-memory)

## Unified Memory

* https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-unified-memory-programming-hd

-----

* [Unified Memory for CUDA Beginners](https://devblogs.nvidia.com/parallelforall/unified-memory-cuda-beginners/)

> Pascal GPUs such as the NVIDIA Titan X and the NVIDIA Tesla P100 are the first GPUs to include the Page Migration Engine, which is hardware support for Unified Memory page faulting and migration

> On systems with pre-Pascal GPUs like the Tesla K80, calling `cudaMallocManaged()` allocates size bytes of managed memory on the **GPU device** that is active when the call is made. Internally, the driver also sets up page table entries for all pages covered by the allocation, so that the system knows that the pages are resident on that GPU.

> On Pascal and later GPUs, managed memory may not be physically allocated when `cudaMallocManaged()` returns; it may only be populated on access (or prefetching). In other words, pages and page table entries may not be created until they are accessed by the GPU or the CPU. The pages can migrate to any processor’s memory at any time, and the driver employs heuristics to maintain data locality and prevent excessive page faults.

> The kernel launches without any migration overhead, and when it accesses any absent pages, the GPU stalls execution of the accessing threads, and the Page Migration Engine migrates the pages to the device before resuming the threads.

Use Unified Memory prefetching to move the data to the GPU after initializing it: `cudaMemPrefetchAsync()`

> Simultaneous access to managed memory from the CPU and GPUs of compute capability lower than 6.0 is not possible. This is because pre-Pascal GPUs lack hardware page faulting, so coherence can’t be guaranteed. On these GPUs, an access from the CPU while a kernel is running will cause a segmentation fault.

> On Pascal and later GPUs, the CPU and the GPU can simultaneously access managed memory, since they can both handle page faults; however, it is up to the application developer to ensure there are no race conditions caused by simultaneous accesses.

> Calling `cudaDeviceSynchronize()` after the kernel launch ensures that the kernel runs to completion before the CPU tries to read the results from the managed memory pointer. Otherwise, the CPU may read invalid data (on Pascal and later), or get a segmentation fault (on pre-Pascal GPUs).

-----

* [CUDA 8 Features Revealed](https://devblogs.nvidia.com/parallelforall/cuda-8-features-revealed/)

> Memory page faulting support in GP100 is a crucial new feature that provides more seamless Unified Memory functionality. Combined with the system-wide virtual address space, page faulting provides several benefits. First, page faulting means that the CUDA system software doesn’t need to synchronize all managed memory allocations to the GPU before each kernel launch. If a kernel running on the GPU accesses a page that is not resident in its memory, it faults, allowing the page to be automatically migrated to the GPU memory on-demand. Alternatively, the page may be mapped into the GPU address space for access over the PCIe or NVLink interconnects (mapping on access can sometimes be faster than migration). Note that Unified Memory is system-wide: GPUs (and CPUs) can fault on and migrate memory pages either from CPU memory or from the memory of other GPUs in the system.

> With the new page fault mechanism, global data coherency is guaranteed with Unified Memory. This means that with GP100, the CPUs and GPUs can access Unified Memory allocations simultaneously. This was illegal on Kepler and Maxwell GPUs, because coherence could not be guaranteed if the CPU accessed a Unified Memory allocation while a GPU kernel was active. Note, as with any parallel application, developers need to ensure correct synchronization to avoid data hazards between processors.

-----

* [Does CudaMallocManaged allocate memory on the device?](https://stackoverflow.com/questions/36778089/does-cudamallocmanaged-allocate-memory-on-the-device)
* [Is “cudaMallocManaged” slower than “cudaMalloc”?](https://stackoverflow.com/questions/21986542/is-cudamallocmanaged-slower-than-cudamalloc)

-----

* [Managed Memory: Belated Comments on Implementation](http://www.cudahandbook.com/2017/08/managed-memory-belated-comments-on-implementation/)
* [Managed Memory and Segmentation](http://www.cudahandbook.com/2017/08/managed-memory-and-segmentation/)

-----

> * Issues related to “transfer/execution overlap”:
> * * Pages from managed allocations touched by CPU migrated back to GPU before any kernel launch
> * * * Consequence: there is no kernel execution/data transfer overlap in that stream
> * * * Overlap possible with UM but just like before it requires multiple kernels in separate streams
> * * * * Enabled by the fact that a managed allocation can be specific to a stream
> * * * * Allows one to control which allocations are synchronized on specific kernel launches, enables concurrency

如果有足够的active warp，Unified Memory可以overlap data transfer和kernel execution。

-----

* [unified-memory-on-pascal-and-volta](http://on-demand.gputechconf.com/gtc/2017/presentation/s7285-nikolay-sakharnykh-unified-memory-on-pascal-and-volta.pdf)

>  When Is This Helpful?
> * When it doesn’t matter how data moves to a processor
> 1) Quick and dirty algorithm prototyping
> 2) Iterative process with lots of data reuse, migration cost can be amortized
> 3) Simplify application debugging
> * When it’s difficult to isolate the working set
> 1) Irregular or dynamic data structures, unpredictable access
> 2) Data partitioning between multiple processors


> Memory Oversubscription
> * When you have large dataset and not enough physical memory
> * Moving pieces by hand is error-prone and requires tuning for memory size
> * Better to run slowly than get fail with out-of-memory error
> * You can actually get high performance with Unified Memory!


> System-Wide Atomics with Exclusive Access
> * GPUs are very good at handling atomics from thousands of threads
> * Makes sense to utilize atomics between GPUs or between CPU and GPU


> The Unified Memory driver is doing intelligent things under the hood:
> * Prefetching: migrate pages proactively to reduce number of faults
> * Thrashing mitigation: heuristics to avoid frequent migration of shared pages
> * Eviction: what pages to evict when we need to make the room for new ones


> DRIVER PREFETCHING
> * GPU architecture supports different page sizes
> * Contiguous pages up to a larger page size are promoted to the larger size
> * Driver prefetches whole regions if pages are accessed densely


> ANTI-THRASHING POLICY
> * Processors share the same page and frequently read or write to it


> EVICTION ALGORITHM
> * Driver keeps a single list of physical chunks of GPU memory
> * Chunks from the front of the list are evicted first (LRU)
> * A chunk is considered “in use” when it is fully-populated or migrated


```cpp
// Similar to move_pages() in Linux
cudaMemPrefetchAsync(ptr, size, processor, stream)
// Similar to madvise() in Linux
cudaMemAdvise(ptr, size, advice, processor)
```


> Page Granularity Overhead
* `cudaMallocManaged` alignment: 512B on Pascal/Volta, 4KB on Kepler/Maxwell
* * Too many small allocations will use up many pages
* `cudaMallocManaged` memory is moved at system page granularity
* * For small allocations more data could be moved than necessary
* Solution: use cached allocator or memory pools

-----

* [THE FUTURE OF UNIFIED MEMORY](http://www.danielwong.org/classes/_media/csee217_f17/unifiedmemory.pdf)

> READ DUPLICATION
> `cudaMemAdviseSetReadMostly`

```cpp
// Use when data is mostly read and occasionally written to

init_data(data, N);
cudaMemAdvise(data, N, cudaMemAdviseSetReadMostly, myGpuId);
// Read-only copy will be created on GPU page fault
mykernel<<<...>>>(data, N);
// CPU reads will not page fault
use_data(data, N);
```

```cpp
// Prefetching creates read-duplicated copy of data and avoids page faults
// Note: writes are allowed but will generate page fault and remapping


init_data(data, N);
cudaMemAdvise(data, N, cudaMemAdviseSetReadMostly, myGpuId);
// Read-only copy will be created during prefetch
cudaMemPrefetchAsync(data, N, myGpuId, cudaStreamLegacy);
// GPU reads will not page fault
mykernel<<<...>>>(data, N);
// CPU reads will not page fault
use_data(data, N);
```



> DIRECT MAPPING
* `cudaMemAdviseSetPreferredLocation`
* * Set preferred location to avoid migrations
* * First access will page fault and establish mapping
* `cudaMemAdviseSetAccessedBy`
* * Pre-map data to avoid page faults
* * First access will not page fault
* * Actual data location can be anywhere

-----

* [Maximizing Unified Memory Performance in CUDA](https://devblogs.nvidia.com/maximizing-unified-memory-performance-cuda/)

-----

* [Beyond GPU Memory Limits with Unified Memory on Pascal](https://devblogs.nvidia.com/beyond-gpu-memory-limits-unified-memory-pascal/)

-----

* [Unified Memory on Tesla P100 with CUDA 8.0](http://www.acceleware.com/blog/Unified-Memory-on-Tesla-P100-with-CUDA-8.0)

-----

* [Why is NVIDIA Pascal GPUs slow on running CUDA Kernels when using cudaMallocManaged](https://stackoverflow.com/questions/39782746/why-is-nvidia-pascal-gpus-slow-on-running-cuda-kernels-when-using-cudamallocmana)
* [Speed of Pascal CUDA8 1080Ti unified memory](https://stackoverflow.com/questions/43768717/speed-of-pascal-cuda8-1080ti-unified-memory)

* [CUDA学习（一百零二）](https://yq.aliyun.com/articles/494861)


# CUDA Array
* [CUDA Array in CUDA | How to use CUDA Array in CUDA](https://cuda-programming.blogspot.jp/2013/02/cuda-array-in-cuda-how-to-use-cuda.html)
* [[!] cudaArray vs. device pointer](https://stackoverflow.com/questions/14450029/cudaarray-vs-device-pointer)
* [cudaMallocPitch and cudaMemcpy2D](https://stackoverflow.com/questions/35771430/cudamallocpitch-and-cudamemcpy2d)

# memcpy
* [Does cuda memcpy from host to host perform synchronization?](https://stackoverflow.com/questions/22430446/does-cuda-memcpy-from-host-to-host-perform-synchronization)
* [Better or the same: CPU memcpy() vs device cudaMemcpy() on pinned, mapped memory in CUDA?](https://stackoverflow.com/questions/12453677/better-or-the-same-cpu-memcpy-vs-device-cudamemcpy-on-pinned-mapped-memory)
* [Poor Memcpy Performance Copying To Pinned Memory On Host](https://devtalk.nvidia.com/default/topic/719289/poor-memcpy-performance-copying-to-pinned-memory-on-host/?offset=13)

## `cudaMemcpy2D`
* [cuda之二维数组的高效内存管理（cudaMallocPitch/cudaMemcpy2D）](https://my.oschina.net/zzw922cn/blog/648189)
* [GPU和CPU中二维数组的转换与应用（cudaMallocPitch与cudaMemcpy2D的用法](http://johnwaindinger.lofter.com/post/3a7245_2a83f9e)

## cudaMemcpyDefault
* [Caffe中的底层数学计算函数](https://xmfbit.github.io/2017/03/08/mathfunctions-in-caffe/)
* [CUDA学习（九十九）](https://yq.aliyun.com/articles/494858)


# Shared Memory Bank Conflict
## 32-Bit Strided Access
```c
extern __shared__ float shared[];
float data = shared[BaseIndex + s * tid];
```

# smart pointer
* [Is there a CUDA smart pointer?](https://stackoverflow.com/questions/16509414/is-there-a-cuda-smart-pointer)
* https://github.com/dzitkowskik/CUDA-smart-pointers
* [How to check where pointers lead](https://devtalk.nvidia.com/default/topic/410771/how-to-check-where-pointers-lead/)

# `cudaMemset`
* [Is cudaMemset actually "asynchronous"?](https://devtalk.nvidia.com/default/topic/908431/cuda-programming-and-performance/is-cudamemset-actually-quot-asynchronous-quot-/)
* ["unspecified launch failure" but "No CUDA-MEMCHECK"](https://devtalk.nvidia.com/default/topic/908210/?comment=4772387)

# Memory fence
* https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#memory-fence-functions
* [CUDA __threadfence()](https://stackoverflow.com/questions/5232689/cuda-threadfence/5233737#5233737)
* [cuda threadfence](https://stackoverflow.com/questions/11570789/cuda-threadfence)::::::::::::::
CUDA-Reading-List.md
::::::::::::::
* http://docs.nvidia.com/cuda/cuda-c-best-practices-guide
* http://www.gpucomputers.com/
* http://www.icl.utk.edu/~mgates3/docs/cuda.html
* https://people.maths.ox.ac.uk/gilesm/cuda/
* https://github.com/LitLeo/OpenCUDA
* https://github.com/eyalroz/cuda-api-wrappers/

* https://devblogs.nvidia.com/tag/cudacasts/

* https://github.com/bryancatanzaro/trove


# nvidia devblogs reading list
* https://devblogs.nvidia.com/parallelforall/tag/linear-algebra/
* https://devblogs.nvidia.com/parallelforall/tag/parallel-programming/
* https://github.com/parallel-forall/code-samples

# Performance Measure
* [How to Implement Performance Metrics in CUDA C/C++](https://devblogs.nvidia.com/parallelforall/how-implement-performance-metrics-cuda-cc/)

> A problem with using host-device synchronization points, such as `cudaDeviceSynchronize()`, is that they stall the GPU pipeline.
>
> # Memory Bandwidth
>
> ## THEORETICAL BANDWIDTH
>
> Theoretical bandwidth can be calculated using hardware specifications available in the product literature. For example, the Tesla M2050 GPU uses DDR (double data rate) RAM with a memory clock rate of 1,546 MHz and a 384-bit wide memory interface. Using these data items, the peak theoretical memory bandwidth of the Tesla M2050 is 148 GB/sec, as computed in the following.
>
> BW_Theoretical = 1546 * 10^6 * (384/8) * 2 / 10^9 = 148 GB/s
>
> In this calculation, we convert the memory clock rate to Hz, multiply it by the interface width (divided by 8, to convert bits to bytes) and multiply by 2 due to the double data rate. Finally, we divide by 109 to convert the result to GB/s.
>
> ## EFFECTIVE BANDWIDTH
>
> We calculate effective bandwidth by timing specific program activities and by knowing how our program accesses data. We use the following equation.
>
> BW_Effective = (R_B + W_B) / (t * 10^9)
>
> Here, BW_Effective is the effective bandwidth in units of GB/s, R_B is the number of bytes read per kernel, W_B is the number of bytes written per kernel, and t is the elapsed time given in seconds.
>
> # Computational Throughput
>
> A common measure of computational throughput is GFLOP/s, which stands for “Giga-FLoating-point OPerations per second”, where Giga is that prefix for 10^9.

----

# Dynamic Parallelism
* [Adaptive Parallel Computation with CUDA Dynamic Parallelism](https://devblogs.nvidia.com/introduction-cuda-dynamic-parallelism/)
* [CUDA Dynamic Parallelism API and Principles](https://devblogs.nvidia.com/cuda-dynamic-parallelism-api-principles/)

> A child grid inherits from the parent grid certain attributes and limits, such as the L1 cache / shared memory configuration and stack size.

> Grids launched with dynamic parallelism are fully nested. This means that child grids always complete before the parent grids that launch them, even if there is no explicit synchronization

```cpp
void threadBlockDeviceSynchronize(void) {
  __syncthreads();
  if(threadIdx.x == 0) {
    cudaDeviceSynchronize();
  }
  __syncthreads();
}
```

> This means that if the parent writes to a location, and then launches a child grid, the child is guaranteed to see the value actually written by the parent. Similarly, if the child writes a memory location, and the parent performs synchronization, the parent is guaranteed to see the value written by the child. This also means that if several child grids are executed sequentially (for example in the same stream), then any writes performed by earlier child grids are seen by child grids started later, even if no synchronization has occurred between them.

> Note that the view of global memory is not consistent when the kernel launch construct is executed.
_To avoid race conditions, memory which can be read by the child should not be written by the parent after kernel launch but before explicit synchronization._

> Passing Pointers to Child Grids

| Can be passed | Cannot be passed |
 ------------- | -------------
| * global memory (incl. `__device__` variables and malloc’ed memory) | * shared memory (`__shared__` variables) |
| * zero-copy host memory | * local memory (incl. stack variables) |
| * constant memory (inherited and not writeable) | |

> Recursion Depth and Device Limits
>
> * _nesting depth_, which is the deepest nesting level of recursive grid launches, with kernels launched from the host having depth 0;
> * _synchronization depth_, which is the deepest nesting level at which cudaDeviceSynchronize() is called.

* [A CUDA Dynamic Parallelism Case Study: PANDA](https://devblogs.nvidia.com/a-cuda-dynamic-parallelism-case-study-panda/)




# C++11
* https://devblogs.nvidia.com/parallelforall/tag/c11/
* https://github.com/klmr/cpp11-range/

# thrust
* https://github.com/thrust/thrust

# review #
* http://stackoverflow.com/tags/cuda/info
* http://stackoverflow.com/questions/1958320/interview-questions-on-cuda-programming

# warp #
* http://stackoverflow.com/questions/10460742/how-do-cuda-blocks-warps-threads-map-onto-cuda-cores

# memory #
## bank conflict ##
* http://stackoverflow.com/questions/3843032/why-arent-there-bank-conflicts-in-global-memory-for-cuda-opencl
* http://stackoverflow.com/questions/3841877/what-is-a-bank-conflict-doing-cuda-opencl-programming
* [CUDA SHARED MEMORY](http://www.cnblogs.com/1024incn/p/4605502.html)
* [GPU 共享内存bank冲突(shared memory bank conflicts)](https://www.findhao.net/easycoding/1784)

# sgemm ##
* [[!] NervanaSystems wiki](https://github.com/NervanaSystems/maxas/wiki/SGEMM)
* https://github.com/xldrx/maxas.wiki.fixed/blob/master/SGEMM.md


* [GPU编程之进击的优化系列二--GPU矩阵乘法优化技术](https://yq.aliyun.com/articles/512495?spm=a2c4e.11153959.0.0.6f526086Bo5BLr)


# Examples
## Gaussian Blur
* [高斯滤波/高斯平滑/高斯模糊的实现及其快速算法(Gaussian Filter, Gaussian Smooth, Gaussian Blur, Fast implementation)](http://blog.csdn.net/mulinb/article/details/7328279)
* [GPU Recursive Filtering](https://github.com/andmax/gpufilter)

# error-checking #
* http://stackoverflow.com/questions/14038589/what-is-the-canonical-way-to-check-for-errors-using-the-cuda-runtime-api
* http://cuda.it168.com/a2011/1221/1292/000001292129.shtml

# matrix multiplication #
* http://www.es.ele.tue.nl/~mwijtvliet/5KK73/?page=mmcuda
* http://stackoverflow.com/questions/9244747/cuda-matrix-multiplication-write-to-wrong-memory-location
* http://stackoverflow.com/questions/9250897/dynamic-matrix-multiplication-with-cuda

# CUDA and OpenGL #
* http://blog.csdn.net/ruby97/article/details/8851403
* http://stackoverflow.com/questions/6481123/cuda-and-opengl-interop
* http://www.nvidia.com/content/gtc/documents/1055_gtc09.pdf
* http://www.seas.upenn.edu/~cis565/LECTURES/Lecture3.pdf

* https://www.olcf.ornl.gov/wp-content/uploads/2013/02/GPU_Opt_Fund-CW1.pdf

# Fermi Architecture #
* https://cinwell.wordpress.com/2013/09/06/overview-of-gpu-architecture-fermi-based/

# cuDNN
* [Optimizing Recurrent Neural Networks in cuDNN 5](https://devblogs.nvidia.com/parallelforall/optimizing-recurrent-neural-networks-cudnn-5/)
* [How to know which cuDNN version one should use?](https://stackoverflow.com/questions/33760192/how-to-know-which-cudnn-version-one-should-use)

# restrict
* [CUDA Pro Tip: Optimize for Pointer Aliasing](https://devblogs.nvidia.com/parallelforall/cuda-pro-tip-optimize-pointer-aliasing/)::::::::::::::
CUDA-Tools.md
::::::::::::::
# `cuda-memcheck`
## cannot find mem leaks
https://docs.nvidia.com/cuda/cuda-memcheck/index.html#leak-checking

> For an accurate leak checking summary to be generated, the application's CUDA context must be destroyed at the end. This can be done explicitly by calling `cuCtxDestroy()` in applications using the CUDA driver API, or by calling `cudaDeviceReset()` in applications programmed against the CUDA run time API.
>
> The `--leak-check full` option must be specified to enable leak checking.

* [How to use cuda memcheck](http://jasonjuang.blogspot.com/2014/10/how-to-use-cuda-memcheck.html)

* [What is the role of cudaDeviceReset() in Cuda](https://stackoverflow.com/questions/36012289/what-is-the-role-of-cudadevicereset-in-cuda)

## nvprof and Nsight Visual Studio Edition are not being run simultaneously

```
    Internal Memcheck Error: Memcheck failed initialization
    as some other tools is currently attached. Please make
    sure that nvprof and Nsight Visual Studio Edition are
    not being run simultaneously
```

```
unset CUDA_INJECTION32_PATH
unset CUDA_INJECTION64_PATH
```

* [JCuda Debugging](http://www.jcuda.org/debugging/Debugging.html#Troubleshooting)
* https://stackoverflow.com/questions/19323560/internal-memcheck-error-memcheck-failed-initialization-as-profiler-is-attached

## Unspecified launch failure

* [错误：Unspecified launch failure](http://bbs.gpuworld.cn/thread-10739-1-1.html)
* [cudaMemcpyAsync()从device向host拷贝数据的时候报错](http://bbs.gpuworld.cn/forum.php?mod=viewthread&tid=9584&fromuid=1)
* http://docs.nvidia.com/gameworks/content/developertools/desktop/timeout_detection_recovery.htm
* https://stackoverflow.com/questions/13177214/disabling-tdr-for-cuda-in-windows-8

# `nvprof`
```
nvprof --events all --metrics all <your application>
```

* [CUDA Pro Tip: nvprof is Your Handy Universal GPU Profiler](https://devblogs.nvidia.com/parallelforall/cuda-pro-tip-nvprof-your-handy-universal-gpu-profiler/)

# `nvcc`

-----

* https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/index.html


![cuda-compilation-from-cu-to-executable](https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/graphics/cuda-compilation-from-cu-to-executable.png)


> `--default-stream {legacy|null|per-thread} (-default-stream)`

## 4.2.7. Options for Steering GPU Code Generation

> `--gpu-architecture arch (-arch)`
> Specify the name of the class of NVIDIA virtual GPU architecture for which the CUDA input files must be compiled.

> `--gpu-code code,... (-code)`
> Specify the name of the NVIDIA GPU to assemble and optimize PTX for.
> During runtime, such embedded PTX code is dynamically compiled by the CUDA runtime system if no binary load image is found for the current GPU.

## 5. GPU Compilation

> The virtual architecture should always be chosen as low as possible, thereby maximizing the actual GPUs to run on. The real architecture should be chosen as high as possible (assuming that this always generates better code), but this is only possible with knowledge of the actual GPUs on which the application is expected to run.

![](https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/graphics/virtual-architectures.png)

### 5.6.1. Just-in-Time Compilation

![](https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/graphics/just-in-time-compilation.png)

> The disadvantage of just in time compilation is increased application startup delay, but this can be alleviated by letting the CUDA driver use a compilation cache which is persistent over multiple runs of the applications.


### GPU Feature List

<table cellpadding="4" cellspacing="0" summary="" class="table" frame="border" border="1" rules="all">
<tbody class="tbody">
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">sm_30</samp> and <samp class="ph codeph">sm_32</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">
<p class="p">Basic features</p>
<p class="p">+ Kepler support</p>
<p class="p">+ Unified memory programming</p>
</td>
</tr>
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">sm_35</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Dynamic parallelism support</td>
</tr>
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">sm_50</samp>, <samp class="ph codeph">sm_52</samp>, and
<samp class="ph codeph">sm_53</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Maxwell support</td>
</tr>
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">sm_60</samp>, <samp class="ph codeph">sm_61</samp>, and
<samp class="ph codeph">sm_62</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Pascal support</td>
</tr>
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">sm_70</samp> and <samp class="ph codeph">sm_72</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Volta support</td>
</tr>
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">sm_75</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Turing support</td>
</tr>
</tbody>
</table>

### Virtual Architecture Feature List

<table cellpadding="4" cellspacing="0" summary="" class="table" frame="border" border="1" rules="all">
<tbody class="tbody">
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">compute_30</samp> and <samp class="ph codeph">compute_32</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">
<p class="p">Basic features</p>
<p class="p">+ Kepler support</p>
<p class="p">+ Unified memory programming</p>
</td>
</tr>
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">compute_35</samp></td>
<td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Dynamic parallelism support</td>
</tr>
<tr class="row">
<td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">compute_50</samp>,
  <samp class="ph codeph">compute_52</samp>, and
  <samp class="ph codeph">compute_53</samp></td>
  <td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Maxwell support</td>
  </tr>
  <tr class="row">
  <td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">compute_60</samp>,
  <samp class="ph codeph">compute_61</samp>, and
  <samp class="ph codeph">compute_62</samp></td>
  <td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Pascal support</td>
  </tr>
  <tr class="row">
  <td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">compute_70</samp> and <samp class="ph codeph">compute_72</samp></td>
  <td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Volta support</td>
  </tr>
  <tr class="row">
  <td class="entry" valign="top" width="25%" rowspan="1" colspan="1"><samp class="ph codeph">compute_75</samp></td>
  <td class="entry" valign="top" width="75%" rowspan="1" colspan="1">+ Turing support</td>
  </tr>
 </tbody>
</table>

## 6. Using Separate Compilation in CUDA

![](https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/graphics/nvcc-options-for-separate-compilation.png)

> Note that only static libraries are supported by the device linker.

## Printing Code Generation Statistics

`--resource-usage`


-----


* [NVCC compilation options for generating the best code (using JIT)](https://stackoverflow.com/questions/23949928/nvcc-compilation-options-for-generating-the-best-code-using-jit)

## Compute Capacibility
* [Does 'code=sm_X' embed only binary (cubin) code, or also PTX code, or both?](https://stackoverflow.com/questions/26232500/does-code-sm-x-embed-only-binary-cubin-code-or-also-ptx-code-or-both/26238964#26238964)
* [CUDA: How to use -arch and -code and SM vs COMPUTE](https://stackoverflow.com/questions/35656294/cuda-how-to-use-arch-and-code-and-sm-vs-compute)
* [What is the purpose of using multiple “arch” flags in Nvidia's NVCC compiler?](https://stackoverflow.com/questions/17599189/what-is-the-purpose-of-using-multiple-arch-flags-in-nvidias-nvcc-compiler)

### The 'compute_20', 'sm_20', and 'sm_21' architectures are deprecated, and may be removed in a future release
* https://devtalk.nvidia.com/default/topic/995286/nvcc-compiler-warning-compute_20-/?offset=6
* https://stackoverflow.com/questions/42382987/nvcc-warning-in-cuda-8-0

## `-use-fast-math`
* [Does -use-fast-math option translate SP multiplications to intrinsics?](https://stackoverflow.com/questions/11507440/does-use-fast-math-option-translate-sp-multiplications-to-intrinsics)

## `--default-stream per-thread`
* http://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/index.html#options-for-steering-cuda-compilation
* https://github.com/BVLC/caffe/pull/2077
* [Concurrency about default stream](https://devtalk.nvidia.com/default/topic/820443/concurrency-about-default-stream/)
* [How to enable CUDA 7.0+ per-thread default stream in Visual Studio 2013?](https://stackoverflow.com/questions/34259948/how-to-enable-cuda-7-0-per-thread-default-stream-in-visual-studio-2013)
### `cudaStreamPerThread`
* [CUDA stream per-thread and library behaviour](https://stackoverflow.com/questions/46244238/cuda-stream-per-thread-and-library-behaviour)
* [3. Stream synchronization behavior](http://docs.nvidia.com/cuda/cuda-driver-api/stream-sync-behavior.html)
* [CUDA per-thread and cudnn behaviour](https://devtalk.nvidia.com/default/topic/1023965/cuda-per-thread-and-cudnn-behaviour/)

## relocation R_X86_64_32 against `.bss' can not be used when making a shared object; recompile with -fPIC
* https://github.com/nrc-cnrc/EGSnrc/issues/129

* https://github.com/colmap/colmap/issues/186
```
# In CMakeLists.txt:
list(APPEND CUDA_NVCC_FLAGS "--compiler-options -fPIC")
```

* [“relocation R_X86_64_32S against ” linking Error](https://stackoverflow.com/questions/19768267/relocation-r-x86-64-32s-against-linking-error)

## maxrregcount
* [慎用 maxrregcount](https://www.cnblogs.com/xingzifei/p/7482454.html)
* [Limiting register usage in CUDA: __launch_bounds__ vs maxrregcount](https://stackoverflow.com/questions/44704506/limiting-register-usage-in-cuda-launch-bounds-vs-maxrregcount)

## `-Xcompiler`
* [nvcc test.cu -std=c++11 -Xcompiler "-std=c++14"](https://devtalk.nvidia.com/default/topic/985604/cuda-programming-and-performance/nvcc-test-cu-std-c-11-xcompiler-quot-std-c-14-quot-/)


# `cuobjdump` `nvdisasm` `nvprune`
* https://docs.nvidia.com/cuda/cuda-binary-utilities/index.html

# `nvidia-xconfig`
* [X server on NVIDIA card with no screen](https://superuser.com/questions/1278256/x-server-on-nvidia-card-with-no-screen)


# `NSight`
* https://stackoverflow.com/questions/16272368/cuda-perfomance-profiling-with-nvidia-nsight-in-vs2010-nvreport-report-file
* [NVIDIA® Nsight™ Development Platform, Visual Studio Edition 4.7 User Guide: Memory Transactions](http://docs.nvidia.com/gameworks/content/developertools/desktop/analysis/report/cudaexperiments/sourcelevel/memorytransactions.htm)
* [Use the Memory Checker](http://docs.nvidia.com/gameworks/content/developertools/desktop/nsight/use_memory_checker.htm)
## Application received signal 139
* Uncheck "Enable concurrent kernel profiling". [NSight Profiler Signal 139](https://stackoverflow.com/questions/14363314/nsight-profiler-signal-139)
## org.eclipse.swt.SWTException.: Failed to execute runnable (java.long.OutOfMemoryError: Java heap space)
* [Out of memory during profiling](https://devtalk.nvidia.com/default/topic/523764/nsight-eclipse-edition/out-of-memory-during-profiling/)
* [JVM内存的设置（解决eclipse下out of memory问题）](http://blog.csdn.net/SJF0115/article/details/8889201)


# `nvidia-smi`
* [Where can I find nvidia-smi.exe utility](https://devtalk.nvidia.com/default/topic/488454/where-can-i-find-nvidia-smi-exe-utility/)
* [Useful nvidia-smi Queries](http://nvidia.custhelp.com/app/answers/detail/a_id/3751/~/useful-nvidia-smi-queries)

* [nvidia-smi: Control Your GPUs](https://www.microway.com/hpc-tech-tips/nvidia-smi_control-your-gpus/)

* [Using multi-threaded programs with multiple GPUs in EXCLUSIVE_PROCESS compute mode](https://devtalk.nvidia.com/default/topic/764384/using-multi-threaded-programs-with-multiple-gpus-in-exclusive_process-compute-mode/)
* [How to prevent two CUDA programs from interfering](https://stackoverflow.com/questions/13900078/how-to-prevent-two-cuda-programs-from-interfering)
* [https://stackoverflow.com/questions/31731535/switch-cuda-compute-mode-to-default-mode](https://stackoverflow.com/questions/31731535/switch-cuda-compute-mode-to-default-mode)

```
nvidia-smi  --query | grep 'Compute Mode'
sudo nvidia-smi -c $i
# i=0 Default
# i=1 Exclusive_Thread
# i=2 Prohibited
# i=3 Exclusive_Process
```

* [How can I flush GPU memory using CUDA (physical reset is unavailable)](https://stackoverflow.com/questions/15197286/how-can-i-flush-gpu-memory-using-cuda-physical-reset-is-unavailable)
```
sudo fuser -v /dev/nvidia*
```

* [Reset driver without rebooting on linux](https://devtalk.nvidia.com/default/topic/902781/reset-driver-without-rebooting-on-linux/?offset=1)
* [11 GB of GPU RAM used, and no process listed by nvidia-smi](https://devtalk.nvidia.com/default/topic/958159/11-gb-of-gpu-ram-used-and-no-process-listed-by-nvidia-smi/)

* [nvidia-smi "Type" field meaning](https://devtalk.nvidia.com/default/topic/897562/linux/nvidia-smi-quot-type-quot-field-meaning/)

# NVML
* [Increase Performance with GPU Boost and K80 Autoboost](https://devblogs.nvidia.com/increase-performance-gpu-boost-k80-autoboost/)
* [CUDA Pro Tip: Increase Application Performance with NVIDIA GPU Boost](https://devblogs.nvidia.com/cuda-pro-tip-increase-application-performance-nvidia-gpu-boost/)
* [GPU Boost on Tesla K40 GPUs](http://acceleware.com/blog/gpu-boost-nvidias-tesla-k40-gpus)

# monitor
* [GPU usage monitoring (CUDA)](https://unix.stackexchange.com/questions/38560/gpu-usage-monitoring-cuda)::::::::::::::
CUDA.md
::::::::::::::
# Assembly
## Compute Cache
* [CUDA Pro Tip: Understand Fat Binaries and JIT Caching](https://devblogs.nvidia.com/cuda-pro-tip-understand-fat-binaries-jit-caching/)
* [NVIDIA Cache by NVIDIA](http://shouldicleanit.com/apps/nvidia-cache)
## FMAD
* [FMAD on CUDA](https://codeyarns.com/2012/05/12/fmad-on-cuda/)
* https://stackoverflow.com/questions/12011708/fmad-false-gives-good-performance

# context switch
* https://stackoverflow.com/questions/24254975/measure-the-overhead-of-context-switching-in-gpu
* https://stackoverflow.com/questions/6605581/what-is-the-context-switching-mechanism-in-gpu

# Header
* [Difference between cuda.h, cuda_runtime.h, cuda_runtime_api.h](https://stackoverflow.com/questions/6302695/difference-between-cuda-h-cuda-runtime-h-cuda-runtime-api-h)
* [How to properly link cuda header file with device functions?](https://stackoverflow.com/questions/24459495/how-to-properly-link-cuda-header-file-with-device-functions)

# intrinsic
* [intrinsic math functions for float2, float4](https://devtalk.nvidia.com/default/topic/371108/intrinsic-math-functions-for-float2-float4/)
* [SIMD intrinsics - are they usable on gpus?](https://stackoverflow.com/questions/14959065/simd-intrinsics-are-they-usable-on-gpus)
* [Can CUDA use SIMD extensions?](https://stackoverflow.com/questions/5238743/can-cuda-use-simd-extensions)
* [Performance in CUDA](https://stackoverflow.com/questions/13611261/performance-in-cuda)


# `printf`
* https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#formatted-output
* [printf inside CUDA __global__ function](https://stackoverflow.com/questions/2173771/printf-inside-cuda-global-function)


# Math API
* [Integer min/max in CUDA](https://stackoverflow.com/questions/29978155/integer-min-max-in-cuda)
## type conversion
* [Fastest way to convert float4 to uchar4? Texture conversion](https://devtalk.nvidia.com/default/topic/465003/fastest-way-to-convert-float4-to-uchar4-texture-conversion/)


* [Accessing float4/int4 elements using a loop in CUDA](https://stackoverflow.com/questions/9044139/accessing-float4-int4-elements-using-a-loop-in-cuda)

```cpp
typedef union {
    float4 vec;
    float a[4];
} U4;

U4 u;

for (int i = 0; i < 4; ++i) u.a[i] = ...;
```


## sqrt
* [sqrt(), sqrtf() and use_fast_math](https://devtalk.nvidia.com/default/topic/817571/sqrt-sqrtf-and-use_fast_math/)
* [Performance of sqrt in CUDA](http://supercomputingblog.com/cuda/performance-of-sqrt-in-cuda/)
## Half Precision FP16
* [Float16 and Quantized Int8 Type](https://github.com/Xreki/Xreki.github.io/blob/master/multi_data_types_in_dl_framework/ppt/float16_and_quantized_type.md)
* [Can anyone provide sample code demonstrating the use of 16 bit floating point in cuda?](https://stackoverflow.com/questions/32735292/can-anyone-provide-sample-code-demonstrating-the-use-of-16-bit-floating-point-in)
* [How FP32 and FP16 units are implemented in GP100 GPU's](https://devtalk.nvidia.com/default/topic/1001191/how-fp32-and-fp16-units-are-implemented-in-gp100-gpus/)
* [fp16 support in cuda thrust](https://stackoverflow.com/questions/36196829/fp16-support-in-cuda-thrust)
## error: identifier not found
* [error when trying to use half (fp16)](https://devtalk.nvidia.com/default/topic/883897/error-when-trying-to-use-half-fp16-/)
* [(github nccl) Undefined identifiers in all_reduce.cu](https://github.com/NVIDIA/nccl/issues/9)
* [CUDA compilation error: __hmul and __hneg are undefined](https://stackoverflow.com/questions/44215043/cuda-compilation-error-hmul-and-hneg-are-undefined)
### error: class "__half2" has no member "y"
* https://stackoverflow.com/questions/37133128/use-of-half2-in-cuda
* https://stackoverflow.com/questions/43120062/cuda-cublas-and-half-precision-data-types

## `__umul24`
* https://stackoverflow.com/questions/5544355/cuda-umul24-function-useful-or-not
* [__umul24](http://datamining.xmu.edu.cn/documentation/cuda4.1/group__CUDA__MATH__INTRINSIC__INT_g2b1446551e854d164e3d4aae25f94a3f.html)

# CUDA Stream
* [GPU Pro Tip: CUDA 7 Streams Simplify Concurrency](https://devblogs.nvidia.com/gpu-pro-tip-cuda-7-streams-simplify-concurrency/)
* [Is there a maximum number of streams in CUDA?](https://stackoverflow.com/questions/3565793/is-there-a-maximum-number-of-streams-in-cuda)

* [The behavior of stream 0 (default) and other streams](https://stackoverflow.com/questions/18443205/the-behavior-of-stream-0-default-and-other-streams)
* [Get rid of busy waiting during asynchronous cuda stream executions](https://stackoverflow.com/questions/5107265/get-rid-of-busy-waiting-during-asynchronous-cuda-stream-executions)

* [3. Stream synchronization behavior](http://docs.nvidia.com/cuda/cuda-runtime-api/stream-sync-behavior.html#stream-sync-behavior)

* [Does CPU waits for DEVICE to let it finish its kernel execution…?](https://stackoverflow.com/questions/12639552/does-cpu-waits-for-device-to-let-it-finish-its-kernel-execution)
## dependency
* [cudaStreamWaitEvent does not seem to wait](https://stackoverflow.com/questions/15501699/cudastreamwaitevent-does-not-seem-to-wait)
* [Wait for event in subsequent stream](https://stackoverflow.com/questions/27146253/wait-for-event-in-subsequent-stream)
* [CUDA并发相关（流并发、主机设备并发）](http://blog.csdn.net/LIYUAN123ZHOUHUI/article/details/53842384)
* [CUDA ---- Stream and Event](http://www.cnblogs.com/1024incn/p/5891051.html)

* [【GPU编程系列之三】cuda stream和event相关内容](http://chenrudan.github.io/blog/2015/07/22/cudastream.html)

* [Concurrency of CUDA default stream with created streams](https://stackoverflow.com/questions/13331995/concurrency-of-cuda-default-stream-with-created-streams/29058674#29058674)

## `cudaStreamAddCallback`
* http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#stream-callbacks
* [cuda streams: callback not getting called after stream execution](https://stackoverflow.com/questions/29566346/cuda-streams-callback-not-getting-called-after-stream-execution)
* [CUDA Example: Stream Callbacks](http://www.stephenconover.com/cuda-example-stream-callbacks/)
* [how can I use cudaStreamAddCallback() with a class member method?](https://stackoverflow.com/questions/17943295/how-can-i-use-cudastreamaddcallback-with-a-class-member-method)
* https://github.com/sarvex/multicore/blob/fb6ce5e6814c1b63044e4a40573de8ad687e6a4b/Chapter6_GPU/memcpyTestCallback.cu
* [Why does cudaStreamAddCallback serialize kernel execution and break concurrency?](https://devtalk.nvidia.com/default/topic/822942/why-does-cudastreamaddcallback-serialize-kernel-execution-and-break-concurrency-/?offset=9)


# vectorization
* [CUDA Pro Tip: Increase Performance with Vectorized Memory Access](https://devblogs.nvidia.com/parallelforall/cuda-pro-tip-increase-performance-with-vectorized-memory-access/)

> In almost all cases vectorized loads are preferable to scalar loads. Note however that using vectorized loads increases register pressure and reduces overall parallelism. So if you have a kernel that is already register limited or has very low parallelism, you may want to stick to scalar loads. Also, as discussed earlier, if your pointer is not aligned or your data type size in bytes is not a power of two you cannot use vectorized loads.

* [How can I load the 128 bit data the fastest and with compatibility both GPU (CUDA C++) and with CPU (C++)?](https://stackoverflow.com/questions/12046797/how-can-i-load-the-128-bit-data-the-fastest-and-with-compatibility-both-gpu-cud)
* [Efficiency of CUDA vector types (float2, float3, float4)](https://stackoverflow.com/questions/26676806/efficiency-of-cuda-vector-types-float2-float3-float4)
* [Are there advantages to using the CUDA vector types?](https://stackoverflow.com/questions/12340384/are-there-advantages-to-using-the-cuda-vector-types)
* [Why are CUDA vector types (int4, float4) faster?](https://stackoverflow.com/questions/31447619/why-are-cuda-vector-types-int4-float4-faster)
* [Vector operations in cuda?](https://devtalk.nvidia.com/default/topic/370615/vector-operations-in-cuda-/)
* [How to properly cast a global memory array using the uint4 vector in CUDA to increase memory throughput?](https://stackoverflow.com/questions/13102205/how-to-properly-cast-a-global-memory-array-using-the-uint4-vector-in-cuda-to-inc)

# Macro
* [where can I find the macro](https://devtalk.nvidia.com/default/topic/526448/where-can-i-find-the-macro/?offset=2)

# Atomic

-----

* [CUDA Pro Tip: Optimized Filtering with Warp-Aggregated Atomics](https://devblogs.nvidia.com/cuda-pro-tip-optimized-filtering-warp-aggregated-atomics/)

> CUDA 9 NVCC compiler now performs warp aggregation for atomics automatically in many cases, so you can get higher performance with no extra effort.

> One way to improve filtering performance is to use shared memory atomics.

> Another approach is to first use a parallel prefix sum to compute the output index of each element.

## Warp-Aggregated Atomics

1. Threads in the warp elect a leader thread.
1. Threads in the warp compute the total atomic increment for the warp.
1. The leader thread performs an atomic add to compute the offset for the warp.
1. The leader thread broadcasts the offset to all other threads in the warp.
1. Each thread adds its own index within the warp to the warp offset to get its position in the output array.




-----

* [GPU Pro Tip: Fast Histograms Using Shared Atomics on Maxwell](https://devblogs.nvidia.com/parallelforall/gpu-pro-tip-fast-histograms-using-shared-atomics-maxwell/)

-----

* [Voting and Shuffling to Optimize Atomic Operations](https://devblogs.nvidia.com/voting-and-shuffling-optimize-atomic-operations/)

-----


* [atomicAdd and shared memory issue Running the histogram code from "Cuda by example" book.](https://devtalk.nvidia.com/default/topic/496823/atomicadd-and-shared-memory-issue-running-the-histogram-code-from-34-cuda-by-example-34-book-/)
* [Atomic Operations and Low-Wait Algorithms in CUDA](http://www.drdobbs.com/parallel/atomic-operations-and-low-wait-algorithm/240160177)
* [CUDA Pro Tip: Optimized Filtering with Warp-Aggregated Atomics](https://devblogs.nvidia.com/parallelforall/cuda-pro-tip-optimized-filtering-warp-aggregated-atomics/)
* [gist: sleeepyjack/cuda_atomic_agg_inc.cuh](https://gist.github.com/sleeepyjack/9ff972b93e630a3a218b60a9744cb289)
* [How does warp work with atomic operation?](https://stackoverflow.com/questions/20726299/how-does-warp-work-with-atomic-operation)

* [How to use atomicCAS for multiple variables with conditionals in CUDA](https://stackoverflow.com/questions/19363066/how-to-use-atomiccas-for-multiple-variables-with-conditionals-in-cuda)



* [CUDA atomic operation performance in different scenarios](https://stackoverflow.com/questions/22367238/cuda-atomic-operation-performance-in-different-scenarios)
* [Worse atomic performance in shared than global memory](https://devtalk.nvidia.com/default/topic/1020637/worse-atomic-performance-in-shared-than-global-memory/)
* [How much faster are atomicAdd() operations to __shared__ on SM >= 5X?](https://devtalk.nvidia.com/default/topic/1025528/how-much-faster-are-atomicadd-operations-to-__shared__-on-sm-gt-5x-/)

# Warp-level Primitives
* https://docs.nvidia.com/cuda/cuda-c-programming-guide/#warp-vote-functions
* https://docs.nvidia.com/cuda/cuda-c-programming-guide/#warp-shuffle-functions

-----

* [Using CUDA Warp-Level Primitives](https://devblogs.nvidia.com/using-cuda-warp-level-primitives/)

* In a SIMD architecture, each instruction applies the same operation in parallel across many data elements. SIMD is typically implemented using processors with vector registers and execution units; a scalar thread issues vector instructions that execute in SIMD fashion.
* In a SIMT architecture, rather than a single thread issuing vector instructions applied to data vectors, multiple threads issue common instructions to arbitrary data.

```
#define FULL_MASK 0xffffffff
for (int offset = 16; offset > 0; offset /= 2)
    val += __shfl_down_sync(FULL_MASK, val, offset);
```

> For a thread at lane **X** in the warp, `__shfl_down_sync(FULL_MASK, val, offset)` gets the value of the `val` variable from the thread at lane **X+offset** of the same warp.

## Synchronized Data Exchange

## Active Mask Query

`__activemask()`

## Warp Synchronization

```
void __syncwarp(unsigned mask=0xffffffff);
```

> The `__syncwarp()` primitive causes the executing thread to wait until all threads specified in mask have executed a `__syncwarp()` (with the same mask) before resuming execution. It also provides a memory fence to allow threads to communicate via memory before and after calling the primitive.

> Make sure that `__syncwarp()` separates shared memory reads and writes to avoid race conditions.

## Opportunistic Warp-level Programming

## Implicit Warp-Synchronous Programming is Unsafe

## Update Legacy Warp-Level Programming




-----

# Cooperative Groups

-----

* https://docs.nvidia.com/cuda/cuda-c-programming-guide/#cooperative-groups

C.2.4. Coalesced Groups

> In CUDA’s SIMT architecture, at the hardware level the multiprocessor executes threads in groups of 32 called warps. If there exists a data-dependent conditional branch in the application code such that threads within a warp diverge, then the warp serially executes each branch disabling threads not on that path. The threads that remain active on the path are referred to as coalesced.

C.2.5.1. Discovery Pattern

```
{
    unsigned int writemask = __activemask();
    unsigned int total = __popc(writemask);
    unsigned int prefix = __popc(writemask & __lanemask_lt());
    // Find the lowest-numbered active lane
    int elected_lane = __ffs(writemask) - 1;
    int base_offset = 0;
    if (prefix == 0) {
        base_offset = atomicAdd(p, total);
    }
    base_offset = __shfl_sync(writemask, base_offset, elected_lane);
    int thread_offset = prefix + base_offset;
    return thread_offset;
}
```

```
{
    cg::coalesced_group g = cg::coalesced_threads();
    int prev;
    if (g.thread_rank() == 0) {
        prev = atomicAdd(p, g.size());
    }
    prev = g.thread_rank() + g.shfl(prev, 0);
    return prev;
}
```


-----

* [CUDA 9 Features Revealed: Volta, Cooperative Groups and More](https://devblogs.nvidia.com/cuda-9-features-revealed/)

-----

* [Cooperative Groups: Flexible CUDA Thread Programming](https://devblogs.nvidia.com/cooperative-groups/)

## Discovering Thread Concurrency

```
coalesced_group active = coalesced_threads();
```

> Keep in mind that since threads from different warps are never coalesced, the largest group that `coalesced_threads()` can return is a full warp.


-----


# Mutex / Lock
* [Cuda atomics change flag](https://stackoverflow.com/questions/18963293/cuda-atomics-change-flag/)
* [Try to use lock and unlock in CUDA](https://devtalk.nvidia.com/default/topic/1014009/cuda-programming-and-performance/try-to-use-lock-and-unlock-in-cuda/)
* [CUDA, mutex and atomicCAS()](https://stackoverflow.com/questions/21341495/cuda-mutex-and-atomiccas)
* [Lock reading/writing for rows in two dimension array in global memory](https://stackoverflow.com/questions/37113675/lock-reading-writing-for-rows-in-two-dimension-array-in-global-memory)
* [Implementing a critical section in CUDA](https://stackoverflow.com/questions/2021019/implementing-a-critical-section-in-cuda)
* [Atomic float operations. especially add](https://devtalk.nvidia.com/default/topic/391295/cuda-programming-and-performance/atomic-float-operations-especially-add/)
* [atomic read or write](https://devtalk.nvidia.com/default/topic/413970/atomic-read-or-write/)

# `cudaSetDeviceFlags`
* [Correct place to use cudaSetDeviceFlags?](https://stackoverflow.com/questions/47175958/correct-place-to-use-cudasetdeviceflags)


# CUDA Launch
* [CUDA: Forgetting kernel launch configuration does not result in NVCC compiler warning or error](https://stackoverflow.com/questions/44285347/cuda-forgetting-kernel-launch-configuration-does-not-result-in-nvcc-compiler-wa)
* [CUDA kernel launch parameters explained right?](https://stackoverflow.com/questions/19240658/cuda-kernel-launch-parameters-explained-right)

## `__cudaRegisterFatBinary`
* [what are the parameters for __cudaRegisterFatBinary and __cudaRegisterFunction functions?](https://stackoverflow.com/questions/6392407/what-are-the-parameters-for-cudaregisterfatbinary-and-cudaregisterfunction-f)




# Trouble-shooting
## code=4(cudaErrorLaunchFailure) "cudaFreeHost"
* https://stackoverflow.com/questions/6153035/cuda-fails-when-freeing-memory-after-kernel-execution-error
## “invalid argument” error when starting kernel
* https://stackoverflow.com/questions/34340527/cuda-invalid-argument-error-when-starting-kernel

block size超过限制大小

* https://stackoverflow.com/questions/13994799/cuda-invalid-argument-error-on-second-kernel

## Driver/library version mismatch
* [NVIDIA NVML Driver/library version mismatch](https://stackoverflow.com/questions/43022843/nvidia-nvml-driver-library-version-mismatch)


## misaligned address
* https://stackoverflow.com/questions/37323053/misaligned-address-in-cuda
* https://stackoverflow.com/questions/12778949/cuda-memory-alignment
* https://en.cppreference.com/w/cpp/language/alignas
* [CUDA Runtime API error 74: misaligned address](https://devtalk.nvidia.com/default/topic/975906/cuda-runtime-api-error-74-misaligned-address/)



## error : argument of type "cudaStream_t" is incompatible with parameter of type "size_t"
```
// correct
kernel<<< blocks, threads, bytes, streamID >>>();
// wrong
kernel<<< blocks, threads, streamID >>>();
```
* [Calling Cuda Kernel as arguement to another function Passing Kernel As arguement](https://devtalk.nvidia.com/default/topic/517279/calling-cuda-kernel-as-arguement-to-another-function-passing-kernel-as-arguement/)

## cudaErrorInvalidValue
memcpy: 非法地址

* [cudaMemcpy returns invalid value](https://devtalk.nvidia.com/default/topic/817979/cudamemcpy-returns-invalid-value/)
* https://stackoverflow.com/questions/3079880/cuda-cudamemcpy-returns-cudaerrorinvalidvalue-for-device-array

## clamp
* https://stackoverflow.com/questions/5883358/clamping-short-to-unsigned-char

## Template

* [CUDA C++: Using a template function which calls a template kernel](https://stackoverflow.com/questions/31705764/cuda-c-using-a-template-function-which-calls-a-template-kernel)
* [Problem when calling template CUDA kernel](https://stackoverflow.com/questions/6342220/problem-when-calling-template-cuda-kernel)
* [How to run templatized global function cuda templates](https://devtalk.nvidia.com/default/topic/368554/how-to-run-templatized-global-function-cuda-templates/)
* [forcing template compilation in CUDA C](https://devtalk.nvidia.com/default/topic/490971/forcing-template-compilation-in-cuda-c/)

* [template cuda kernel function cannot be called in another template function on vs2013](https://devtalk.nvidia.com/default/topic/890246/template-cuda-kernel-function-cannot-be-called-in-another-template-function-on-vs2013/?offset=8)
* [Unresolved externals in CUDA expression template library under Visual Studio 2010](https://devtalk.nvidia.com/default/topic/536793/unresolved-externals-in-cuda-expression-template-library-under-visual-studio-2010/)

* [calling templated CUDA kernels from a .cpp file](https://stackoverflow.com/questions/19387009/calling-templated-cuda-kernels-from-a-cpp-file)

```cpp
// kernel.cu
template <class T>
__global__ void kernel_axpy(T* x, T* y, int len) { ... }

void axpy(float* x, float* y, int len){ kernel_axpy<<<...>>>(x,y,len); }
void axpy(double* x, double* y, int len){ kernel_axpy<<<...>>>(x,y,len); }

// axpy.h

extern void axpy(float* x, float* y, int len);
extern void axpy(double* x, double* y, int len);

template <class T> void cpp_axpy(T* x, T* y, int len) { std::cerr<<"Not implemented.\n"<<std::endl; }
template <> void cpp_axpy<float>(float* x, float* y, int len) { axpy(x,y,len); }
template <> void cpp_axpy<double>(double* x, double* y, int len) { axpy(x,y,len); }

// main.cpp

#include "axpy.h"

...
{
    axpy(xx,yy,length);
    cpp_axpy<double>(xxx,yyy,lll);
}
...
```

* [CUDA: Template Kernels](https://codeyarns.com/2011/03/14/cuda-template-kernels/)
* [CUDA: Device Function in Header File](https://codeyarns.com/2011/03/15/cuda-device-function-in-header-file/)

## extern "C"
* [how solve [extern "C" template]?](https://devtalk.nvidia.com/default/topic/404006/how-solve-extern-quot-c-quot-template-/)
* [How to make CUDA object file with C linkage?](https://stackoverflow.com/questions/13992446/how-to-make-cuda-object-file-with-c-linkage)
* [Is extern “C” no longer needed anymore in cuda? [closed]](https://stackoverflow.com/questions/27756187/is-extern-c-no-longer-needed-anymore-in-cuda)
* [Compiling C and CUDA code Problems linking CUDA code and C code](https://devtalk.nvidia.com/default/topic/506228/compiling-c-and-cuda-code-problems-linking-cuda-code-and-c-code/)
* [CUDA学习笔记2](http://blog.sina.com.cn/s/blog_675662490100i86b.html)
* [CUDA ，extern "C" --NVCC编译器的问题， whole program compilation与separate compilation](http://blog.sina.com.cn/s/blog_98740ded0101joow.html)
* [Noob Q: How to extern c function?](https://devtalk.nvidia.com/default/topic/381962/cuda-programming-and-performance/noob-q-how-to-extern-c-function-/)

## constant: identifier undefined in device code
* [[!]host float constant usage in a kernel in CUDA](https://stackoverflow.com/questions/15004955/host-float-constant-usage-in-a-kernel-in-cuda)
* [How can I use static const members in CUDA?](https://stackoverflow.com/questions/29112305/how-can-i-use-static-const-members-in-cuda)
* [CUDA - Using __constant__ variables and cudaMemcpyFromSymbol](https://stackoverflow.com/questions/35110540/cuda-using-constant-variables-and-cudamemcpyfromsymbol)
* [__constant__ memory which is device-side only (avoiding cudaMemcpyToSymbol)](https://devtalk.nvidia.com/default/topic/1014292/cuda-programming-and-performance/__constant__-memory-which-is-device-side-only-avoiding-cudamemcpytosymbol-/)

## `Program hit cudaErrorCudartUnloading (error 29) due to "driver shutting down" on CUDA API call to cudaFree.`

### related bug reports
* https://github.com/BVLC/caffe/issues/6281
* [cudaErrorCudartUnloading (error 29) due to “driver shutting down”](https://stackoverflow.com/questions/40979060/cudaerrorcudartunloading-error-29-due-to-driver-shutting-down)
* https://github.com/opencv/opencv/issues/7816

* [出现这个错误是在程序成功运行之后出现的，也就是说，所有的功能可以正常实现，最后报了这个错误。经过不断尝试，找到原因由于加载模型时。这些变量定义全局变量，导致上面的问题。详细原因暂时没有思路。](https://blog.csdn.net/jobbofhe/article/details/79386160)

* [Trace for function name from the output of cuda-memcheck](https://php.wekeepcoding.com/article/14472884/Trace+for+function+name+from+the+output+of+cuda-memcheck)

* https://github.com/NVlabs/SASSI/issues/4

-----

* [freeing kernel memory leaked by nvidia driver](https://superuser.com/questions/1062929/freeing-kernel-memory-leaked-by-nvidia-driver)

* [Ubuntu挂起后cuda和GPU不能使用，运行a = mx.nd.array([1,2,3], mx.gpu())就报错e == cudaErrorCudartUnloading，必须重启，有人遇到过吗？](https://discuss.gluon.ai/t/topic/3340)

* [cudaError_t 77 : "an illegal memory access was encountered" returned from 'cudaFree(p.first.pointer)'](https://groups.google.com/forum/#!topic/kaldi-help/czhQcr-PV-E)

### CUDA APIs within destructor

* [When cuda driver will be unloaded in cuda program?](https://devtalk.nvidia.com/default/topic/922654/when-cuda-driver-will-be-unloaded-in-cuda-program-/)

* [cuda call fails in destructor](https://stackoverflow.com/questions/35815597/cuda-call-fails-in-destructor)
> From _community wiki_
>
> Your code is unknowingly relying on undefined behaviour (the order of destruction of translation unit objects) and there is no real workaround other than to explicitly control and lifespan of objects containing CUDA runtime API calls in their destructor, or simply avoid using those API calls in destructors altogether.
>
> In detail:
>
> The CUDA front end invoked by nvcc silently adds a lot of boilerplate code and translation unit scope objects which perform CUDA context setup and teardown. That code must run before any API calls which rely on a CUDA context can be executed. If your object containing CUDA runtime API calls in its destructor invokes the API after the context is torn down, your code may fail with a runtime error. C++ doesn't define the order of destruction when objects fall out of scope. Your singleton or object needs to be destroyed before the CUDA context is torn down, but there is no guarantee that will occur. This is effectively undefined behaviour.

> From _Robert Crovella_
>
> The placement of CUDA calls in a global object outside of main scope will lead to problematic behavior. See [here](https://stackoverflow.com/questions/24869167/trouble-launching-cuda-kernels-from-static-initialization-code). Although that description mostly focuses on kernel calls in such a class/object, the hazard applies to any CUDA call, as you have discovered.
>
> To be clear, I should have said "The placement of CUDA calls in constructors and destructors of a global object outside of main scope will lead to problematic behavior. " Use of CUDA in other class methods may be possible (assuming e.g these methods don't get called by constructors/destructors, etc.)

* [Trouble launching CUDA kernels from static initialization code](https://stackoverflow.com/questions/24869167/trouble-launching-cuda-kernels-from-static-initialization-code/24883665#24883665)

> From _talonmies_
>
> There is an internally generated routine (__cudaRegisterFatBinary) which must be run to load and register kernels, textures and statically defined device symbols contained in the fatbin payload of any runtime API program with the CUDA driver API before the kernel can be called without error.

* [Cuda Run time library unload](https://devtalk.nvidia.com/default/topic/1019780/?comment=5191690)
> For instance, can I have my class maintain certain variables/handles that will force cuda run time library to stay loaded.
>
> No. It is a bad design practice to put calls to the CUDA runtime API in constructors that may run before main and destructors that may run after main.


* [Proper use of cudaDeviceReset()](https://stackoverflow.com/questions/11608350/proper-use-of-cudadevicereset)

-----

* [Global static destructors called when a dynamic library is unloaded?](http://compgroups.net/comp.lang.c++.moderated/global-static-destructors-called-when/363808)
* [CUDA: Why is it not possible to define static global member functions?](https://stackoverflow.com/questions/18551859/cuda-why-is-it-not-possible-to-define-static-global-member-functions)
* [Why is there no support for static class members?](https://devtalk.nvidia.com/default/topic/573203/why-is-there-no-support-for-static-class-members-/?offset=4)

## loaded shared lib
* /lib64/libcuda.so
* /lib64/libnvidia-fatbinaryloader.so


## Solutions

### Do not call CUDA API in dctor of static/global classes
* [CUDA de-initialization](https://github.com/kaldi-asr/kaldi/issues/2178)

### skip checking `cudaErrorCudartUnloading`
* https://github.com/arrayfire/arrayfire/pull/170

### Have a seperate de-initialisation / finalize method which calls CUDA API

* [CUDA streams destruction and CudaDeviceReset](https://stackoverflow.com/questions/16979982/cuda-streams-destruction-and-cudadevicereset/16982503?noredirect=1#comment24536013_16982503)
> From _talonmies_
>
> The obvious answer is don't put CUDA API calls in the destructor. In your class you have an explicit intialisation method not called through the constructor, so why not have an explicit de-initialisation method as well? That way scope becomes a non-issue


* https://github.com/apache/incubator-mxnet/issues/4219
* * `MXNotifyShutdown` (https://github.com/apache/incubator-mxnet/blob/master/src/c_api/c_api.cc)


### register exit function after CUDA driver is loaded

```cpp
int gpu_num;
cudaError_t err = cudaGetDeviceCount(&gpu_num);

std::atexit([](){
    // Call CUDA APIs to clean up
});
```




## CUDA error 10 "invalid device ordinal" (when using `cudaMemAdvise`)

* [How to specify GPU id for cudaMemAdviseSetPreferredLocation](https://stackoverflow.com/questions/41058748/how-to-specify-gpu-id-for-cudamemadvisesetpreferredlocation)
```
int device_id = 0, result = 0;
cudaDeviceGetAttribute (&result, cudaDevAttrConcurrentManagedAccess, device_id);
if (result) {
    // Call cudaMemAdvise
}
```

## an illegal memory access was encountered
* https://github.com/nicehash/nheqminer/issues/223
* https://github.com/BVLC/caffe/issues/4169
* https://github.com/NVIDIA/caffe/issues/226
* https://github.com/my89/SituationCrf/issues/3
* https://github.com/BVLC/caffe/issues/2417
* https://github.com/BVLC/caffe/issues/5058

* https://github.com/BVLC/caffe/issues/6345
> this error has been reported several times, usually being resolved as the GPU's fault, not Caffe's.


* [Illegal Memory Access on cudaDeviceSynchronize](https://stackoverflow.com/questions/28289312/illegal-memory-access-on-cudadevicesynchronize)
* [Unspecified launch failure on Memcpy](https://stackoverflow.com/questions/27277365/unspecified-launch-failure-on-memcpy/27278218?s=1|0.3183#27278218)


------
* https://github.com/ethereum-mining/ethminer/issues/72
> From rizwansarwar
>
> Some more information, depending on your driver version, you get different crash error. So at I got 381.22 driver version, I got illegal memory error, but at 375.66 I get unspecified launch failure.

> From derubm
>
> Illegal memory access error is in case of Nvidia cards happen due to having a card running on max overclocked memory on Power state 2. When your miner does switch to P0 state for whatever reason, memory gets an additional 200 mhz and can (or will) get unstable, which causes this error.

> From [GPU Performance State Interface](https://docs.nvidia.com/gameworks/content/gameworkslibrary/coresdk/nvapi/group__gpupstate.html)
>
>             P-States are GPU active/executing performance capability states.
>             They range from P0 to P15, with P0 being the highest performance state,
>             and P15 being the lowest performance state. Each P-State, if available,
>             maps to a performance level. Not all P-States are available on a given system.
>             The definition of each P-States are currently as follow:
>             - P0/P1 - Maximum 3D performance
>             - P2/P3 - Balanced 3D performance-power
>             - P8 - Basic HD video playback
>             - P10 - DVD playback
>             - P12 - Minimum idle power consumption


* [XID Errors](https://docs.nvidia.com/deploy/xid-errors/index.html)
* https://github.com/NVIDIA/nvidia-docker/wiki/CUDA#requirements

* https://github.com/ethereum-mining/ethminer/issues/128
* https://github.com/ethereum-mining/ethminer/issues/94

> GTX1060 +150/+500/65%TDP @ 23-24MHs
>
> 1. Try Update Drivers.
> Download and install the latests.
>
> 2. Try Update Ethminer.
> Download (or beter build) the latest.
>
> 3. Try use -U for CUDA devices.
> CUDA Hardware Test Launch Command:
> ethminer -RH -U -S eu1.ethermine.org:4444 -FS us1.ethermine.org:4444 -O 0x7013275311fc37ccc1e40193D75086293eCb43A4.issue128
>
> 4. Try to change P2 State and Power managment mode.
> You can use NVidiaProfileInspectorDmW.
> For the best mining hashrate choose from sector "5 - Common":
>
> CUDA - Force P2 State (Set to "Off")
> Power managment mode (Set to "Prefer maximum performance")
>
> 5. Try Tweak Win10.
> You can use Windows10MiningTweaksDmW (#695).
>
> 6. Try Optimize/Overclock GPUs.
> You can use MSI Afterburner for GPU OverClock/Optimize.
>
> 7. Try use a WatchDog
> You can use ETHminerWatchDogDmW (#735).


* [NVRM Xid error 59 with Kepler card (CUDA) on 4th PCIe 3.0 port](https://devtalk.nvidia.com/default/topic/524306/nvrm-xid-error-59-with-kepler-card-cuda-on-4th-pcie-3-0-port/)

* [How to Squeeze Some Extra Performance Mining Ethereum on Nvidia](https://cryptomining-blog.com/7341-how-to-squeeze-some-extra-performance-mining-ethereum-on-nvidia/)
* [nvidia-smi GPU performance measure does not make sense](https://stackoverflow.com/questions/30663524/nvidia-smi-gpu-performance-measure-does-not-make-sense)
* [nvidia-smi Volatile GPU-Utilization explanation?](https://stackoverflow.com/questions/40937894/nvidia-smi-volatile-gpu-utilization-explanation/40938696#40938696)


* [Frequent compositor crashes with 384+](https://devtalk.nvidia.com/default/topic/1025550/frequent-compositor-crashes-with-384-/)
* [GTX 970 with KDE/KWIN :NVRM: Xid (PCI:0000:01:00): 31, Ch 00000028, engmask 0000...](https://devtalk.nvidia.com/default/topic/1025701/linux/gtx-970-with-kde-kwin-nvrm-xid-pci-0000-01-00-31-ch-00000028-engmask-0000-/1)

## NVRM Xid Graphics SM Warp Exception on : MMU Fault
* [Error: Graphics SM Warp Exception on (GPC 1, TPC 0): Out Of Range Address (Xid 13/Xid 43)](https://devtalk.nvidia.com/default/topic/987301/error-graphics-sm-warp-exception-on-gpc-1-tpc-0-out-of-range-address-xid-13-xid-43-/?offset=1)

## `CUDNN_STATUS_MAPPING_ERROR`
* https://github.com/keras-team/keras/issues/2124
* https://github.com/chainer/chainer/issues/3060
* [Check failed: status == CUBLAS_STATUS_SUCCESS (11 vs. 0) CUBLAS_STATUS_MAPPING_ERROR](http://www.voidcn.com/article/p-dgxzrrrl-nh.html)

## `CUDNN_STATUS_EXECUTION_FAILED`
* https://github.com/BVLC/caffe/issues/2197

## warning: Cuda API error detected: cudaMemcpy returned (0xb)
* [cudaGetLastError returned (0xb)](https://stackoverflow.com/questions/22360493/cudagetlasterror-returned-0xb)


## Profiling

### nsys

nsys nvprof a.out

### nvvp

```sh
nvprof log: /home/aaron/nvvp_workspace/.metadata/.plugins/com.nvidia.viper/launch/0/nvprof_356448.log
======== Warning: CUDA device error, GPU profiling skipped
======== Error: Application received signal 139
```

### nvprof

nvprof --unified-memory-profiling off

nvprof had been replaced by nsys.

It is recommended to use next-generation tools NVIDIA Nsight Systems for GPU and CPU sampling and tracing and NVIDIA Nsight Compute for GPU kernel profiling. The new tools still offer the same profiling / optimization / deployment workflow.




```sh
$ nsys-ui a.out
QApplication: invalid style override 'gtk' passed, ignoring it.
        Available styles: Windows, Fusion
QApplication: invalid style override 'gtk' passed, ignoring it.
        Available styles: Windows, Fusion
OpenGL version: "4.5 (Compatibility Profile) Mesa 22.0.5"
QApplication: invalid style override 'gtk' passed, ignoring it.
        Available styles: Windows, Fusion
Cannot mix incompatible Qt library (5.15.3) with this library (5.15.2)
```


```
$ nvcc vector-add.cu
vector-add.cu(44): error: unrecognized preprocessing directive

1 error detected in the compilation of "vector-add.cu".

$ ./a.out
terminate called after throwing an instance of 'std::runtime_error'
  what():  cudaDeviceSynchronize() error( cudaErrorSystemDriverMismatch): system has unsupported display driver / cuda driver combination main.cu:32
Aborted
```

```
$ ./a.out
terminate called after throwing an instance of 'std::runtime_error'
  what():  cudaDeviceSynchronize() error( cudaErrorNoDevice): no CUDA-capable device is detected main.cu:32
Aborted (core dumped)

$ nvprof ./a.out
======== Warning: CUDA device error, GPU profiling skipped
terminate called after throwing an instance of 'std::runtime_error'
  what():  cudaDeviceSynchronize() error( cudaErrorNoDevice): no CUDA-capable device is detected main.cu:32
======== Error: Application received signal 134

$ nsight-sys a.out
QApplication: invalid style override 'gtk' passed, ignoring it.
        Available styles: Windows, Fusion
QApplication: invalid style override 'gtk' passed, ignoring it.
        Available styles: Windows, Fusion
OpenGL version: "4.5 (Compatibility Profile) Mesa 22.0.5"
QApplication: invalid style override 'gtk' passed, ignoring it.
        Available styles: Windows, Fusion
Cannot mix incompatible Qt library (5.15.3) with this library (5.15.2)
```

Signal 139

In nsight, go to Profile Configurations and then the Profiler tab. Uncheck "Enable concurrent kernel profiling"



```sh
$ nvcc -V
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2021 NVIDIA Corporation
Built on Thu_Nov_18_09:45:30_PST_2021
Cuda compilation tools, release 11.5, V11.5.119
Build cuda_11.5.r11.5/compiler.30672275_0

$ nvprof -V
nvprof: NVIDIA (R) Cuda command line profiler
Copyright (c) 2012 - 2021 NVIDIA Corporation
Release version 11.5.114 (21)
```
```
```
```
terminate called after throwing an instance of 'std::runtime_error'
  what():  cudaDeviceSynchronize() error( cudaErrorNoDevice): no CUDA-capable device is detected main.cu:32
nvprof log: /home/aaron/nvvp_workspace/.metadata/.plugins/com.nvidia.viper/launch/0/nvprof_505411.log
======== Warning: CUDA device error, GPU profiling skipped
======== Error: Application received signal 134
```
```
```
```

  // Wait for GPU to finish before accessing on host
  cudaDeviceSynchronize();


$ nvcc even-easier.cu
even-easier.cu(30): error: kernel launch from __device__ or __global__ functions requires separate compilation mode

even-easier.cu(30): error: a host function call cannot be configured

even-easier.cu(40): warning #20096-D: address of a host variable "std::cout" cannot be directly taken in a device function

2 errors detected in the compilation of "even-easier.cu".

```


PTX (Parallel Thread Execution) 和 SASS (Streaming Assembler) 是NVIDIA为其GPU架构设计的两种低级汇编语言，主要用于CUDA编程模型。理解直接使用PTX或SASS进行编程需要对GPU架构及其实现细节有一定的了解。
PTX

PTX是一种中间表示（Intermediate Representation, IR）形式的汇编语言，它不是直接由硬件执行的语言，而是被CUDA编译器用来生成最终能被GPU执行的机器码（SASS）。PTX代码提供了一定程度的抽象，隐藏了一些底层硬件的具体细节，使得它比SASS更易于编写和移植。尽管如此，它仍允许程序员编写非常接近硬件的代码，从而优化性能。

    优点: 更高的可移植性，因为PTX代码可以在不同代际的NVIDIA GPU上运行（尽管可能需要重新编译为针对特定架构优化的SASS代码）。
    缺点: 与直接用SASS编写相比，性能优化的空间较小。

SASS

SASS是实际由GPU执行的低级汇编语言。每个NVIDIA GPU微架构版本都有其对应的SASS指令集，这意味着SASS代码通常不具备跨架构的可移植性。编写SASS代码要求对目标GPU架构有深入的理解，包括其寄存器文件、线程块调度、内存层次结构等。

    优点: 能够实现最大程度的性能优化，因为它允许程序员精确控制计算资源的使用。
    缺点: 缺乏可移植性，且开发难度大，需要深入了解特定的GPU架构。

直接编程

直接使用PTX或SASS进行编程意味着你需要手动编写这些低级语言的代码，而不是依赖于高级语言如C++与CUDA C/C++提供的抽象。这通常用于以下场景：

    当你需要极致的性能，并愿意投入时间去优化代码。
    在尝试探索新的算法实现时，需要对硬件行为有更精细的控制。
    进行学术研究或实验，需要绕过一些高层次抽象以观察基础硬件特性。




    LVDS（Low-Voltage Differential Signaling，低电压差分信号）接口进行降频操作。LVDS通常用于连接笔记本电脑或一些显示器中的LCD面板。当设置为1时，意味着允许在不需要高性能显示输出的情况下降低LVDS接口的工作频率以节省电力。这对于延长笔记本电脑的电池寿命特别有用。

i915.i915_enable_fbc=1：

    FBC代表Framebuffer Compression（帧缓冲压缩）。当启用（设置为1）时，这个特性会尝试通过压缩帧缓冲区的内容来减少内存带宽使用和功耗。这对于提高系统能效是有益的，特别是在移动设备上。需要注意的是，并非所有硬件都支持FBC，而且在某些情况下，开启此功能可能会引起显示问题。

i915.i915_enable_rc6=1：

    RC6指的是Intel GPU的一种电源管理状态，允许GPU在空闲时进入深度睡眠模式以节省电量。数字1表示启用该功能。更高级别的RC状态（如RC6+）可以提供更深程度的电源节省，但可能不被所有系统支持或者在某些情况下可能导致兼容性问题




PTX（Parallel Thread Execution）和SASS（Streaming Assembly）是与英伟达GPU编程相关的两种不同层级的指令集，它们在GPU编程中扮演着不同的角色。以下是对PTX和SASS直接编程的理解：
PTX编程

    定义：PTX是一种低级并行线程执行虚拟机和指令集架构（ISA），是CUDA编程模型中的中间表示

。它类似于LLVM中的IR（Intermediate Representation），连接了高级编程语言（如CUDA C++）和底层硬件指令（SASS）
。
特点：

    接近硬件但具有灵活性：PTX运行在接近汇编语言的层级，允许开发者进行细粒度的优化，如寄存器分配和线程/线程束级别的调整

。
硬件无关性：PTX可以被看作是“CUDA IR”，它在一定程度上与GPU的具体硬件架构无关，便于在不同的GPU平台上进行优化

    。

应用场景：PTX通常用于需要极致性能优化的场景，例如高性能计算和深度学习中的某些关键算法。例如，DeepSeek团队通过直接操作PTX层，实现了寄存器重分配、线程束重组和内存访问优化，从而显著提高了算法效率

    。

SASS编程

    定义：SASS是GPU的机器码，是PTX代码经过进一步编译后生成的，直接对应GPU硬件的指令

。
特点：

    硬件相关性：SASS与具体的GPU硬件架构紧密相关，针对特定的GPU型号进行优化。这意味着SASS代码的可移植性较差，但能够充分利用特定硬件的特性

。
复杂性：SASS代码通常难以理解和维护，因为它非常接近硬件层面，涉及到复杂的指令集和硬件细节

    。

应用场景：SASS编程通常用于对性能要求极高且需要针对特定硬件进行优化的场景。例如，在某些需要极致性能的科学计算或深度学习任务中，开发者可能会直接编写或优化SASS代码

    。

PTX与SASS的对比

    抽象层级：PTX是高级语言和硬件指令之间的中间层，相对更抽象；而SASS是硬件的机器码，是最底层的指令集

。
可移植性：PTX具有一定的硬件无关性，便于在不同的GPU架构上进行优化；SASS则与特定的GPU硬件紧密相关，可移植性较差
。
开发难度：PTX编程相对更易于理解和开发，因为它提供了更高级的抽象；而SASS编程则非常复杂，需要开发者深入了解GPU硬件架构
。
性能优化：虽然PTX允许进行细粒度的优化，但SASS提供了更直接的硬件控制，能够实现更极致的性能优化

    。

直接编程的理解
直接编程通常指的是直接与硬件交互的编程方式
。在GPU编程中，直接编程可以理解为直接操作PTX或SASS层级的代码，而不是使用高级语言（如CUDA）。这种方式能够更直接地控制硬件资源，实现更高效的性能优化。例如，DeepSeek团队通过直接操作PTX层，对GPU的寄存器分配、线程束重组和内存访问进行优化，从而显著提高了算法效率。



