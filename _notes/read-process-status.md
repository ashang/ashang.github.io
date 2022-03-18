---
date: 2018-08-22
tags:
- process
- status
---

Read process status

```
$ cat /proc/pid/stat
```

See psmisc/prtstat.c

```c
210 static void print_stat(const int pid, const opt_type options)
211 {
212   char *pathname;
213   char buf[BUFSIZ];
214   char *bptr;
215   FILE *fp;
216
217   struct proc_info *pr;
218   pr = malloc(sizeof(struct proc_info));
219
220   if ( (asprintf(&pathname, "/proc/%d/stat",(int)pid)) < 0) {
221     perror(_("asprintf in print_stat failed.\n"));
222     exit(1);
223   }
```
