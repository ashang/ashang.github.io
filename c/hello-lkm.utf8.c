/*  
 *  helloworld.c - Demonstrating the module_init() and module_exit() macros.
 *  This is preferred over using init_module() and cleanup_module().
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

static int __init helloworld_init(void)
{
	printk(KERN_INFO "Hello, world\n");
	return 0;
}

static void __exit helloworld_exit(void)
{
	printk(KERN_INFO "Goodbye, world\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);

/*

Makefile :

obj-m += helloworld.o

all:
	make ARCH=arm CROSS_COMPILE=arm-xilinx-linux-gnueabi- -C /home/xilinx/working/linux-xlnx M=$(shell pwd) modules

clean:
	make ARCH=arm CROSS_COMPILE=arm-xilinx-linux-gnueabi- -C /home/xilinx/working/linux-xlnx M=$(shell pwd) clean

*/
