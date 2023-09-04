#include <linux/module.h>
#include <linux/slab.h>
#include <linux/jiffies.h>
#include <linux/err.h>
#include <linux/mutex.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/stat.h>
#include <linux/string.h>

struct mutex lock;

int __init swctrl_init(void)
{

    struct mutex *p = &lock;
        mutex_init(p);

    memset(p, 0, sizeof (struct mutex));
    mutex_lock(p);
    mutex_unlock(p);
        return 0;

}

void __exit swctrl_exit(void)
{
}

module_init(swctrl_init);
module_exit(swctrl_exit);

MODULE_LICENSE("GPL");

