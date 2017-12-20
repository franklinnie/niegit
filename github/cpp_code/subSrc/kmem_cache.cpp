#include <unistd.h>  
 #include <stdio.h>  
 #include <stdlib.h>  
 #include <string.h>  
 #include <fcntl.h>  
 #include <linux/fb.h>  
 #include <sys/mman.h>  
 #include <sys/ioctl.h>  
#include <fcntl.h>   
#include <stdint.h>
#include "../include/test_case_common.h"   
 #define PAGE_SIZE 4096  

static int fd;

void kmem_cache(uint32_t num, void *userData);
static github_err_t kmem_cache_create(uint32_t num, void *userData);
static github_err_t kmem_cache_destrory(uint32_t num, void *userData);  
   
github_err_t kmem_cache_create(uint32_t num, void *userData) 
{  
     
     int i;  

     int arg = 0;
     //打开设备  
     fd = open("/dev/kmem_cache_create",O_RDWR);  
     if(fd < 0)  
     {  
         printf("open fail\n");  
         return GITHUB_ERR_NONE;   
     }  
   
     printf("ioctrl 1 is to be done\n");

     if(ioctl(fd, 1, &arg) < 0 ) {
	printf("ioctl failed\n");
     }
      
     return GITHUB_ERR_NONE; 
}  

github_err_t kmem_cache_destrory(uint32_t num, void *userData) 
{  
     //int fd;  
     int i;  
 
     int arg = 0;
     //打开设备  
     //fd = open("/dev/kmem_cache_create",O_RDWR);  
     if(fd < 0)  
     {  
         printf("open fail\n");  
         return GITHUB_ERR_NONE;   
     }  
   
     printf("ioctrl 2 is to be done\n");	
     if(ioctl(fd, 2, &arg) < 0 ) {
	printf("ioctl failed\n");
     }
    
    
     return GITHUB_ERR_NONE; 
}  

void kmem_cache(uint32_t num, void *userData) 
{  
     kmem_cache_create(0, NULL); 	
     kmem_cache_destrory(0, NULL);    
     return; 
}  





