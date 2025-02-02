---
title: kernel irq
#type: post
#private: true
date: 2010-08-04T21:05:05-05:00
updated: 2020-08-04T21:05:05-05:00
tags: ["kernel"]
---


Interrupt options	 Next
Name
noirqdebug — Disable unhandled interrupt detection.

Description
By default, the kernel attempts to detect and disable unhandled interrupt sources because they can cause problems with the responsiveness of the rest of the kernel if left unchecked. This option will disable this logic.


irqfixup — Basic fix to interrupt problems.

Description
When an interrupt is not handled, search all known interrupt handlers for it. This is intended to get systems with badly broken firmware running.


irqpoll — Extended fix to interrupt problems.

When an interrupt is not handled, search all known interrupt handlers for it and also check all handlers on each timer interrupt. This is intended to get systems with badly broken firmware running.




QEMU has an educational device called edu that generates interrupts, and is perfect to explore this.

https://github.com/cirosantilli/linux-kernel-module-cheat





