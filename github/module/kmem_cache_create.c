#include <linux/module.h>  
#include <linux/init.h>  
#include <linux/kernel.h>   
#include <linux/mm.h>  
#include <linux/errno.h>  
#include <linux/slab.h>  
#include <linux/gfp.h>  
#include <linux/ioctl.h> 
#include  <linux/miscdevice.h>  

#define KMEM_CACHE_CREATE 1
#define KMEM_CACHE_DESTRORY 2
#define DEVICE_NAME "kmem_cache_create"
  
struct slab_test{  
    int val;  
};  
  
static int n;  
struct kmem_cache *test_cachep = NULL;  
struct slab_test *object1 = NULL, *object2 = NULL;  
  
void slab_ctor(void *cachep){  
    printk("slab_ctor is called! object %d has been inited!\n", n);  
    n++;  
}  
  
  
static int slab_test_init(void){  
    printk("slab test module init\n");  
    n = 0;  
    test_cachep = kmem_cache_create("slab_test_cachep", sizeof(struct slab_test), 0, /*SLAB_HWCACHE_ALIGN*/4, slab_ctor);  
    if(!test_cachep)  
        return -ENOMEM;  
    object1 = kmem_cache_alloc(test_cachep, GFP_KERNEL);  
    if(!object1)  
        return -ENOMEM;  
    else  
        printk("object one has been created!\n");  
    object2 = kmem_cache_alloc(test_cachep, GFP_KERNEL);  
    if(!object2)  
        return -ENOMEM;  
    else  
        printk("object two has been created!\n");  
    return 0;  
}  
  
static void slab_test_exit(void){  
    printk("slab test module exit\n");  
    kmem_cache_free(test_cachep, object1);  
    kmem_cache_free(test_cachep, object2);  
    if(test_cachep)  
        kmem_cache_destroy(test_cachep);  
}  

int my_ioctl(/*struct inode *inodep, */struct file *filp, unsigned  
  int cmd, unsigned long arg)  
{  
    /*获得设备结构体指针*/  
  struct mem_pool_dev *dev = filp->private_data;  
  printk("my_ioctl enter cmd %d\n", cmd);
  switch (cmd)  
  {  
    case KMEM_CACHE_CREATE:            
      printk( "slab create: kmem_cache_create\n"); 
      slab_test_init();        	 
      break;  
    case KMEM_CACHE_DESTRORY:
      printk("slab destrory: kmem_cache_destrory\n");
      slab_test_exit(); 	
      break;	
    default:  
      printk("cmd is error\n");  
      return  - EINVAL;  
  }  
  return 0;  
}    
   
 static struct file_operations dev_fops = {  
     .owner    = THIS_MODULE,
     
     .unlocked_ioctl = my_ioctl		
 };  


 static struct miscdevice misc = {  
     .minor = MISC_DYNAMIC_MINOR,  
     .name = DEVICE_NAME,  
     .fops = &dev_fops,  
 };  
   
   
 static int __init dev_init(void)  
 {  
     int ret;      
   
     //注册混杂设备  
     ret = misc_register(&misc);  
       
     return ret;  
 }  
   
   
static void __exit dev_exit(void)  
 {  
     //注销设备  
     misc_deregister(&misc);     	  
 }  
 

module_init(dev_init);  
module_exit(dev_exit);  
MODULE_LICENSE("GPL");  
MODULE_AUTHOR("niegg");  
MODULE_DESCRIPTION("slab test module");  





