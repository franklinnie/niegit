
#include <linux/security.h>


#include <linux/init.h>

#include <linux/module.h>

#include <linux/gfp.h>
#include <linux/mm.h>

#include <linux/slab.h>
#include <linux/mm_types.h>

#include <linux/range.h>


struct page *pages = NULL;

static int __init __get_free_pages_init(void);

static void __get_free_pages_exit(void);

unsigned long addr;
unsigned long addr_mm;
char *addr_zero = NULL;


int __init __get_free_pages_init(void)
{

#if 0
	struct mm_struct *mm;
	struct vm_area_struct *vma;

	mm = current->mm;
	addr_mm = current->mm->map->vm_next->vm_start + 1;
	printk("addr_mm is 0x%p\n", addr_mm);	
	vma = find_vma(current->mm, addr_mm );
	if( !vma ) {
		printk("vma->start = 0x%p\n", vma->vm_start);
		printk("vma->end = 0x%p\n", vma->vm_end);
	} else {
		printk("find vma failed\n");
	}
#endif
	addr = __get_free_pages(GFP_KERNEL, 1);
	if( !addr ) {
		printk("get free page is not ok\n");
		return -1;
	}
	else {
		printk("__get_free_pages successfully! , addr = 0x%lx\n",addr);
	}

	addr_zero = (char *)get_zeroed_page(GFP_KERNEL); 
	printk("get aeroed pages is %p\n", addr_zero);

	pages = alloc_pages(GFP_KERNEL,1);
	if( !pages ) {
		printk("alloc_pages is not ok\n");
		return -1;
	} else {
		printk("alloc pages 0x%p\n", pages);
	}
	

	return 0;
}

void __get_free_pages_exit(void)
{
	if( addr) {
		free_pages(addr, 1);
		printk("free_get_free_pages ok!\n");
	}

	if( pages) {
		free_pages(pages, 1);
		printk("free_alloc_pages ok!\n");
	}

	if( addr_zero ) {
		free_pages((unsigned long)addr_zero, 1 );
		printk("free get zeroed pages\n");
	}
	printk("exit\n");
		
}

module_init(__get_free_pages_init);
module_exit(__get_free_pages_exit);
