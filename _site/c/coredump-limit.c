#include <stdlib.h>
#include <sys/resource.h>

int main(int argc, char **argv)
{
    // Get the hard and soft limit from command line
    struct rlimit new = {atoi(argv[1]), atoi(argv[1])};

    // Create some memory so as to beef up the core file size
    void *p = malloc(10 * 1024 * 1024);

    if (!p)
        return 1;

    if (setrlimit(RLIMIT_CORE, &new)) // Set the hard and soft limit
        return 2;                     // for core files produced by this
                                      // process

    while (1);

    free(p);
    return 0;
}

/*
https://stackoverflow.com/a/31916826/4387991

The implementation of core dumping can be found in `fs/binfmt_elf.c`.  I'll follow the code in 3.12 and above (it changed with [commit 9b56d5438](http://kernel.opensuse.org/cgit/kernel/commit/?id=9b56d54380adb5fef71f687109bbd6f8413d694f)) but the logic is very similar.

The code initially decides how much to dump of a VMA (virtual memory area) in `vma_dump_size`.  For an anonymous VMA such as the `brk` heap, it returns the full size of the VMA.  During this step, the core limit is not involved.

The first phase of writing the core dump then writes a `PT_LOAD` header for each VMA.  This is basically a pointer that says where to find the data in the remainder of the ELF file.  The actual data is written by a `for` loop, and is actually a second phase.

During the second phase, `elf_core_dump` repeatedly calls `get_dump_page` to get a `struct page` pointer for each page of the program address space that has to be dumped. `get_dump_page` is a common utility function found in `mm/gup.c`.  The comment to `get_dump_page` is helpful:

     * Returns NULL on any kind of failure - a hole must then be inserted into
     * the corefile, to preserve alignment with its headers; and also returns
     * NULL wherever the ZERO_PAGE, or an anonymous pte_none, has been found -
     * allowing a hole to be left in the corefile to save diskspace.

and in fact `elf_core_dump` calls a function in `fs/coredump.c` ( `dump_seek` in your kernel, `dump_skip` in 3.12+) if `get_dump_page` returns `NULL`.  This function calls lseek to leave a hole in the dump (actually since this is the kernel it calls `file->f_op->llseek` directly on a `struct file` pointer).  __The main difference is that `dump_seek` was indeed not obeying the ulimit, while the newer `dump_skip` does.__

As to why the second program has the weird behavior, it's probably because of ASLR (address space randomization).  Which VMA is truncated depends on the relative order of the VMAs, which is random.  You could try disabling it with

    echo 0 | sudo tee /proc/sys/kernel/randomize_va_space

and see if your results are more homogeneous.  To reenable ASLR, use

    echo 2 | sudo tee /proc/sys/kernel/randomize_va_space

*/
