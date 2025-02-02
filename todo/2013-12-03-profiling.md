
# valgrind

We usually do not want to profile 10 minutes of slow startup time under Valgrind and want to profile our program when it is doing some task.

So this is what I recommend. Run program first:

valgrind --tool=callgrind --dump-instr=yes -v --instr-atstart=no ./binary > tmp
Now when it works and we want to start profiling we should run in another window:

callgrind_control -i on
This turns profiling on. To turn it off and stop whole task we might use:

callgrind_control -k
Now we have some files named callgrind.out.* in current directory. To see profiling results use:

kcachegrind callgrind.out.*
I recommend in next window to click on "Self" column header, otherwise it shows that "main()" is most time consuming task. "Self" shows how much each function itself took time, not together with dependents.






valgrind --tool=callgrind ./(Your binary)
It will generate a file called callgrind.out.x. You can then use kcachegrind
tool to read this file. It will give you a graphical analysis of things with
results like which lines cost how much.

Gprof2Dot for an amazing alternative way to visualize the output. ./gprof2dot.py
-f callgrind callgrind.out.x | dot -Tsvg -o output.svg

----

# gperf

Be sure to add -pg to compilation before profiling:

cc -o myprog myprog.c utils.c -g -pg



# kernel perf

Newer kernels (e.g. the latest Ubuntu kernels) come with the new 'perf' tools (apt-get install linux-tools) AKA perf_events.

These come with classic sampling profilers (man-page) as well as the awesome timechart!

The important thing is that these tools can be system profiling and not just process profiling - they can show the interaction between threads, processes and the kernel and let you understand the scheduling and I/O dependencies between processes.



# https://github.com/jrfonseca/gprof2dot


Linux perf
perf record -g -- /path/to/your/executable
perf script | c++filt | gprof2dot.py -f perf | dot -Tpng -o output.png

oprofile
opcontrol --callgraph=16
opcontrol --start
/path/to/your/executable arg1 arg2
opcontrol --stop
opcontrol --dump
opreport -cgf | gprof2dot.py -f oprofile | dot -Tpng -o output.png


# https://github.com/gperftools/gperftools
