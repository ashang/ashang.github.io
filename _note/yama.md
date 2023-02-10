---
title: CONFIG_SECURITY_YAMA
tags: Tale
---

CONFIG_SECURITY_YAMA
selects Yama, which extends DAC support with additional system-wide security settings beyond regular Linux discretionary access controls. Currently available is ptrace scope restriction. Like capabilities, this security module stacks with other LSMs. Further information can be found in Documentation/admin-guide/LSM/Yama.rst.


config SECURITY_YAMA
	bool "Yama support"
	depends on SECURITY
	default n
	help
	  This selects Yama, which extends DAC support with additional
	  system-wide security settings beyond regular Linux discretionary
	  access controls. Currently available is ptrace scope restriction.
	  Like capabilities, this security module stacks with other LSMs.
	  Further information can be found in
	  Documentation/admin-guide/LSM/Yama.rst.


https://www.kernel.org/doc/html/v4.15/admin-guide/LSM/Yama.html


https://man7.org/linux/man-pages/man2/ptrace.2.html


