/*
$ cc sqlite3.c -lsqlite3

$ clang -lsqlite3 sqlite3.c

$ cc -lsqlite3 sqlite3.c
/usr/bin/ld: /tmp/ccJJj9SP.o: in function `main':
sqlite3.c:(.text+0x9): undefined reference to `sqlite3_libversion'
collect2: error: ld returned 1 exit status
*/


#include <sqlite3.h>
#include <stdio.h>

int main()
{
    printf("%s\n", sqlite3_libversion());
    return 0;
}


/*
$ nm
0000000000404038 B __bss_start
0000000000404038 b completed.8060
0000000000404028 D __data_start
0000000000404028 W data_start
0000000000401090 t deregister_tm_clones
0000000000401080 T _dl_relocate_static_pie
0000000000401100 t __do_global_dtors_aux
0000000000403e08 d __do_global_dtors_aux_fini_array_entry
0000000000404030 D __dso_handle
0000000000403e10 d _DYNAMIC
0000000000404038 D _edata
0000000000404040 B _end
00000000004011f8 T _fini
0000000000401130 t frame_dummy
0000000000403e00 d __frame_dummy_init_array_entry
000000000040212c r __FRAME_END__
0000000000404000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
0000000000402008 r __GNU_EH_FRAME_HDR
0000000000401000 T _init
0000000000403e08 d __init_array_end
0000000000403e00 d __init_array_start
0000000000402000 R _IO_stdin_used
00000000004011f0 T __libc_csu_fini
0000000000401180 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000401140 T main
                 U printf@@GLIBC_2.2.5
00000000004010c0 t register_tm_clones
                 U sqlite3_libversion
0000000000401050 T _start
0000000000404038 D __TMC_END__

*/
