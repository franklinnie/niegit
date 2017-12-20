
#include <linux/security.h>


#include <linux/init.h>

#include <linux/module.h>

#include <linux/gfp.h>
#include <linux/mm.h>

#include <linux/slab.h>
#include <linux/mm_types.h>

#include <linux/range.h>

char *mem_spvm = NULL;
struct kmem_cache *my_cachep = NULL;

static int __init __kmem_cache_create_init(void);

static void __exit __kmem_cache_create_exit(void);




int __init __kmem_cache_create_init(void)
{
	my_cachep = kmem_cache_ceate("my_cahce", 32,SLAB_HWCACHE_ALIGN,NULL);
	if(my_cachep)
		printk("cache size is %d\n", kmem_cache_size(my_cachep));	

	return 0;
}

void __kmem_cache_create_exit(void)
{
	if(my_cachep)
		kmem_cache_destory(my_cachep);

	printk("exit\n");
		
}

module_init(__kmem_cache_create_init);
module_exit(__kmem_cache_create_exit);
