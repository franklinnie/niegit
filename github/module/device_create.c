#include <linux/module.h>  
#include <linux/init.h>  
#include <linux/kernel.h>  
#include <linux/fs.h>  
#include <linux/uaccess.h>  
#include <linux/semaphore.h>  
#include <linux/cdev.h>  
#include <linux/device.h>  
#include <linux/ioctl.h>  
#include <linux/slab.h>  
#include <linux/errno.h>  
#include <linux/string.h>  
#include <linux/spinlock.h>
#include <linux/spinlock_types.h>
#include <linux/kthread.h>


#include "test_device_create.h"  
  
#define MAJOR_NUM 250  
#define MINOR_NUM 0  
#define IN_BUF_LEN 256  
#define OUT_BUF_LEN 512  
  
MODULE_AUTHOR("Tishion");  
MODULE_DESCRIPTION("Hello_mod driver by tishion");  
  
static struct class * hello_class;  
static struct cdev hello_cdev;  
static dev_t devnum = 0;  
static char * modname = "devie_create";  
static char * devicename = "device_create";  
static char * classname = "device_create";  
  
static int open_count = 0;  
static struct semaphore sem;  

static DEFINE_SPINLOCK(spin);

static char * inbuffer = NULL;  
static char * outbuffer = NULL;  
static lang_t langtype;  

static struct task_struct * MyThread = NULL;
  
static int hello_mod_open(struct inode *, struct file *);  
static int hello_mod_release(struct inode *, struct file *);  
static ssize_t hello_mod_read(struct file *, char *, size_t, loff_t *);  
static ssize_t hello_mod_write(struct file *, const char *, size_t, loff_t *);  
static int hello_mod_ioctl(struct inode *, struct file *, unsigned int, unsigned long);  
  
struct file_operations hello_mod_fops =   
{  
    .owner = THIS_MODULE,  
    .open = hello_mod_open,  
    .read = hello_mod_read,  
    .write = hello_mod_write,  
    .compat_ioctl = hello_mod_ioctl,  
    .release = hello_mod_release,  
};  

static int MyPrintk(void *data)
{
	char *mydata = kmalloc(strlen(data)+1,GFP_KERNEL);
	memset(mydata,'\0',strlen(data)+1);
	strncpy(mydata,data,strlen(data));
	while(!kthread_should_stop())
	{
		SLEEP_MILLI_SEC(1000);
		printk("knernel thread device_create data %s\n",mydata);
	}
	kfree(mydata);
	return 0;
}
  
static int hello_mod_open(struct inode *inode, struct file *pfile)  
{  
    printk("+hello_mod_open()!\n");  
    spin_lock(&spin);  
    if(open_count)  
    {  
        spin_unlock(&spin);  
        return -EBUSY;  
    }  
    open_count++;  
    spin_unlock(&spin);  
    printk("-hello_mod_open()!\n");  
    return 0;  
}  
static int hello_mod_release(struct inode *inode, struct file *pfile)  
{  
    printk("+hello_mod_release()!\n");  
    open_count--;  
    printk("-hello_mod_release()!\n");  
    return 0;  
}  
static ssize_t hello_mod_read(struct file *pfile, char *user_buf, size_t len, loff_t *off)  
{  
    printk("+hello_mod_read()!\n");  
  
    if(down_interruptible(&sem))  
    {  
        return -ERESTARTSYS;   
    }  
    memset(outbuffer, 0, OUT_BUF_LEN);  
    printk("    +switch()\n");  
    switch(langtype)  
    {  
        case english:  
            printk(">in case: english\n");  
            sprintf(outbuffer, "Hello! %s.", inbuffer);  
            break;  
        case chinese:  
            printk(">in case: chinese\n");  
            sprintf(outbuffer, "你好！ %s.", inbuffer);  
            break;  
        case pinyin:  
            printk(">in case: pinyin\n");  
            sprintf(outbuffer, "ni hao! %s.", inbuffer);  
            break;  
        default:  
            printk(">in case: default\n");  
            break;  
    }  
    printk("-switch()\n");  
    if(copy_to_user(user_buf, outbuffer, len))  
    {  
        up(&sem);  
        return -EFAULT;  
    }  
    up(&sem);  
    printk("-hello_mod_read()!\n");  
    return 0;  
}  
static ssize_t hello_mod_write(struct file *pfile, const char *user_buf, size_t len, loff_t *off)  
{  
    printk("+hello_mod_write()!\n");  
    if(down_interruptible(&sem))  
    {  
        return -ERESTARTSYS;  
    }  
    if(len > IN_BUF_LEN)  
    {  
        printk("Out of input buffer\n");  
        return -ERESTARTSYS;  
    }  
    if(copy_from_user(inbuffer, user_buf, len))  
    {  
        up(&sem);  
        return -EFAULT;  
    }  
    up(&sem);     
    printk("-hello_mod_write()!\n");  
    return 0;  
}  
static int hello_mod_ioctl(struct inode *inode, struct file *pfile, unsigned int cmd, unsigned long arg)  
{  
    int err = 0;  
    printk("+hello_mod_ioctl()!\n");  
    printk("+switch()\n");  
    switch(cmd)  
    {  
        case HELLO_IOCTL_RESETLANG:  
            printk(">in case: HELLO_IOCTL_RESETLANG\n");  
            langtype = english;  
            break;  
        case HELLO_IOCTL_GETLANG:  
            printk(">in case: HELLO_IOCTL_GETLANG\n");  
            err = copy_to_user((int *)arg, &langtype, sizeof(int));  
            break;  
        case HELLO_IOCTL_SETLANG:  
            printk(">in case: HELLO_IOCTL_SETLANG\n");  
            err = copy_from_user(&langtype,(int *)arg, sizeof(int));  
            break;  
        default:  
            printk(">in case: default\n");  
            err = ENOTSUPP;  
            break;  
    }  
    printk("-switch()\n");  
    printk("-hello_mod_ioctl()!\n");  
    return err;  
}  
static int __init hello_mod_init(void)  
{  
    int result;  
    printk("+hello_mod_init()!\n");  

    devnum = MKDEV(MAJOR_NUM, MINOR_NUM);  
    result = register_chrdev_region(devnum, 1, modname);  
  
    if(result < 0)  
    {  
        printk("hello_mod : can't get major number!\n");  
        return result;  
    }     
  
    cdev_init(&hello_cdev, &hello_mod_fops);  
    hello_cdev.owner = THIS_MODULE;  
    hello_cdev.ops = &hello_mod_fops;  
    result = cdev_add(&hello_cdev, devnum, 1);  
    if(result)  
        printk("Failed at cdev_add()\n");  
    hello_class = class_create(THIS_MODULE, classname);  
    if(IS_ERR(hello_class))  
    {  
        printk("Failed at class_create().Please exec [mknod] before operate the device\n");  
    }  
    else  
    {  
        device_create(hello_class, NULL, devnum,NULL, devicename);  
    }  
  
    open_count = 0;  
    langtype = english;  
    inbuffer = (char *)kmalloc(IN_BUF_LEN, GFP_KERNEL);  
    outbuffer = (char *)kmalloc(OUT_BUF_LEN, GFP_KERNEL);  
    sema_init(&sem,1);    
    printk("-device_create_init()!\n");  

    MyThread = kthread_run(MyPrintk,"kernel thread device_create","kernel thread device_create");
    return 0;  
}  
  
static void __exit hello_mod_exit(void)  
{  
    printk("+device_create_exit!\n");  
    kfree(inbuffer);  
    kfree(outbuffer);  
    cdev_del(&hello_cdev);  
    device_destroy(hello_class, devnum);  
    class_destroy(hello_class);  
    unregister_chrdev_region(devnum, 1);  
    printk("-device_create_exit!\n");  

    if(MyThread) {
	printk("stop kernel thread device_create\n");
	kthread_stop(MyThread);
    }
    return ;  
}  
  
module_init(hello_mod_init);  
module_exit(hello_mod_exit);  
MODULE_LICENSE("GPL");  

 
