


       -flto[=n]
           This option runs the standard link-time optimizer.  When
           invoked with source code, it generates GIMPLE (one of
           GCC's internal representations) and writes it to special
           ELF sections in the object file.  When the object files
           are linked together, all the function bodies are read
           from these ELF sections and instantiated as if they had
           been part of the same translation unit.

           To use the link-time optimizer, -flto and optimization
           options should be specified at compile time and during
           the final link.  It is recommended that you compile all
           the files participating in the same link with the same
           options and also specify those options at link time.
           For example:

                   gcc -c -O2 -flto foo.c
                   gcc -c -O2 -flto bar.c
                   gcc -o myprog -flto -O2 foo.o bar.o

           The first two invocations to GCC save a bytecode
           representation of GIMPLE into special ELF sections
           inside foo.o and bar.o.  The final invocation reads the
           GIMPLE bytecode from foo.o and bar.o, merges the two
           files into a single internal image, and compiles the
           result as usual.  Since both foo.o and bar.o are merged
           into a single image, this causes all the interprocedural
           analyses and optimizations in GCC to work across the two
           files as if they were a single one.  This means, for
           example, that the inliner is able to inline functions in
           bar.o into functions in foo.o and vice-versa.

           Another (simpler) way to enable link-time optimization
           is:

                   gcc -o myprog -flto -O2 foo.c bar.c

           The above generates bytecode for foo.c and bar.c, merges
           them together into a single GIMPLE representation and
           optimizes them as usual to produce myprog.

           The important thing to keep in mind is that to enable
           link-time optimizations you need to use the GCC driver
           to perform the link step.  GCC automatically performs
           link-time optimization if any of the objects involved
           were compiled with the -flto command-line option.  You
           can always override the automatic decision to do link-
           time optimization by passing -fno-lto to the link
           command.




           To make whole program optimization effective, it is
           necessary to make certain whole program assumptions.
           The compiler needs to know what functions and variables
           can be accessed by libraries and runtime outside of the
           link-time optimized unit.  When supported by the linker,
           the linker plugin (see -fuse-linker-plugin) passes
           information to the compiler about used and externally
           visible symbols.  When the linker plugin is not
           available, -fwhole-program should be used to allow the
           compiler to make these assumptions, which leads to more
           aggressive optimization decisions.

           When a file is compiled with -flto without
           -fuse-linker-plugin, the generated object file is larger
           than a regular object file because it contains GIMPLE
           bytecodes and the usual final code (see
           -ffat-lto-objects).  This means that object files with
           LTO information can be linked as normal object files; if
           -fno-lto is passed to the linker, no interprocedural
           optimizations are applied.  Note that when
           -fno-fat-lto-objects is enabled the compile stage is
           faster but you cannot perform a regular, non-LTO link on
           them.

           When producing the final binary, GCC only applies link-
           time optimizations to those files that contain bytecode.
           Therefore, you can mix and match object files and
           libraries with GIMPLE bytecodes and final object code.
           GCC automatically selects which files to optimize in LTO
           mode and which files to link without further processing.

           Generally, options specified at link time override those
           specified at compile time, although in some cases GCC
           attempts to infer link-time options from the settings
           used to compile the input files.

           If you do not specify an optimization level option -O at
           link time, then GCC uses the highest optimization level
           used when compiling the object files.  Note that it is
           generally ineffective to specify an optimization level
           option only at link time and not at compile time, for
           two reasons.  First, compiling without optimization
           suppresses compiler passes that gather information
           needed for effective optimization at link time.  Second,
           some early optimization passes can be performed only at
           compile time and not at link time.

...
