---
author: aaronshang
comments: true
date: 2010-10-29 10:55:24+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/29/read-process-status/
slug: read-process-status
title: read process status
wordpress_id: 43
tags:
- process
- status
---

read process status


read:
/proc/pid/stat


See:
psmisc/prtstat.c

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
