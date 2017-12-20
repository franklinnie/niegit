
 #include <linux/init.h>  
#include  <linux/miscdevice.h>  
 #include <linux/delay.h>  
 #include <linux/kernel.h>  

 #include <linux/mm.h>  
 #include <linux/fs.h>  
 #include <linux/types.h>  
 #include <linux/delay.h>  
 #include <linux/moduleparam.h>  
 #include <linux/slab.h>  
 #include <linux/errno.h>  
 #include <linux/ioctl.h>  
 #include <linux/cdev.h>  
 #include <linux/string.h>  
 #include <linux/list.h>  
 #include <linux/pci.h>  
 #include <linux/gpio.h>  
#include <linux/uaccess.h>
 #include <linux/module.h>     
   
 #define DEVICE_NAME "mymap"  
   
#define misc_case  
#define MEM_CLEAR 1  
#define MEM_ENTER 2
static unsigned char array[10]={0,1,2,3,4,5,6,7,8,9};  
static unsigned char *buffer;  

static char writeBuffer[64]; 
static char readBuffer[64]; 

#define mem_pool_SIZE 0x100
struct mem_pool_dev                                       
{                                                          
  struct cdev cdev;             /*cdev结构体*/                         
  unsigned char mem[mem_pool_SIZE]; /*全局内存*/          
}; 

  
static int my_ioctl(/*struct inode *inodep,*/ struct file *filp, unsigned  
  int cmd, unsigned long arg);  

  
   
 static int my_open(struct inode *inode, struct file *file)  
 {  
     return 0;  
 }  
   
static int my_read(struct inode *inode, struct file *file)  
{
    struct file *fp; 
    mm_segment_t fs; 
    loff_t pos; 
    printk("read enter\n"); 
    fp = filp_open("/home/nie/kernel_file", O_RDWR | O_CREAT, 0644); 
    if (IS_ERR(fp)) { 
        printk("create file error\n"); 
        return -1; 
    } 
    fs = get_fs(); 
    set_fs(KERNEL_DS); 
    pos = 0;
    vfs_read(fp, readBuffer, sizeof(readBuffer), &pos); 
    printk("read: %s\n", readBuffer); 
    filp_close(fp, NULL); 
    set_fs(fs); 	
    return 0;
}

static int my_write(struct inode *inode, struct file *file)  
{
    struct file *fp; 
    mm_segment_t fs; 
    loff_t pos; 
    printk("write enter\n"); 
    fp = filp_open("/home/nie/kernel_file", O_RDWR | O_CREAT, 0644); 
    if (IS_ERR(fp)) { 
        printk("create file error\n"); 
        return -1; 
    } 
    fs = get_fs(); 
    set_fs(KERNEL_DS); 
    pos = 0; 
    static int count;
    count++;	
    sprintf(writeBuffer, "%s %d %s", "This is the", count, "time to write");
    vfs_write(fp, writeBuffer, sizeof(writeBuffer), &pos);  
    filp_close(fp, NULL); 
    set_fs(fs); 	
    return 0;
}
   
 static int my_map(struct file *filp, struct vm_area_struct *vma)  
 {      
     unsigned long page;  
     unsigned char i;  
     unsigned long start = (unsigned long)vma->vm_start;  
     unsigned long end =  (unsigned long)vma->vm_end;  
     unsigned long size = (unsigned long)(vma->vm_end - vma->vm_start); 

     printk("start end size : 0x%x 0x%x %d\r\n", start, end, size);	
     printk("unsigned long is %d\r\n", sizeof(unsigned long)); 
   
     //得到物理地址  
     page = virt_to_phys(buffer);    
     printk("page is 0x%p %s %d \r\n", page, __func__, __LINE__);	  
     //将用户空间的一个vma虚拟内存区映射到以page开始的一段连续物理页面上  
     if(remap_pfn_range(vma,start,page>>PAGE_SHIFT,size,PAGE_SHARED))//第三个参数是页帧号，由物理地址右移PAGE_SHIFT得到  
         return -1;  
   
     //往该内存写10字节数据  
     for(i=0;i<10;i++)  
         buffer[i] = array[i];  
       
     return 0;  
 }  
 
/* ioctl设备控制函数 */  
int my_ioctl(/*struct inode *inodep, */struct file *filp, unsigned  
  int cmd, unsigned long arg)  
{  
    /*获得设备结构体指针*/  
  struct mem_pool_dev *dev = filp->private_data;  
  printk("my_ioctl enter cmd %d\n", cmd);
  switch (cmd)  
  {  
    case MEM_CLEAR:  
      //memset(dev->mem, 0, 10);        
      printk( "mem_pool is set to zero\n");  
      break;  
    case MEM_ENTER:
      printk("mem enter from ioctl\n");	
      break;	
    default:  
      printk("cmd is error\n");  
      return  - EINVAL;  
  }  
  return 0;  
}    
   
 static struct file_operations dev_fops = {  
     .owner    = THIS_MODULE,  
     .open    = my_open,  
     .mmap   = my_map,  
     .read   = my_read,
     .write  = my_write,
     .unlocked_ioctl = my_ioctl		
 };  
 
#ifdef misc_case  
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
     //内存分配  
     buffer = (unsigned char *)kmalloc(PAGE_SIZE,GFP_KERNEL);  
     //将该段内存设置为保留  
     SetPageReserved(virt_to_page(buffer));  
   
     return ret;  
 }  
   
   
static void __exit dev_exit(void)  
 {  
     //注销设备  
     misc_deregister(&misc);  
     //清除保留  
     ClearPageReserved(virt_to_page(buffer));  
     //释放内存  
     kfree(buffer);  
 }  
 #endif  
   
 module_init(dev_init);  
 module_exit(dev_exit);  
 MODULE_LICENSE("GPL");  
 MODULE_AUTHOR("niegg");  
