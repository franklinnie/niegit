#include <linux/slab.h>

#include <linux/init.h>

#include <linux/module.h>

static int __init kmalloc_init(void);

static void __exit kmalloc_exit(void);


int __init kmalloc_init(void)
{
	printk("init exter\n");
	int *p = NULL;
        *p = 0; 
	return 0;
}

void __exit kmalloc_exit(void)
{
	return;
}

module_init(kmalloc_init);
module_exit(kmalloc_exit);
