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
   
   
github_err_t mmap_user(uint32_t num, void *userData) 
{  
     int fd;  
     int i;  
     unsigned char *p_map;  
     char readBuffer[128] = {0};  
     int arg = 0;
     //打开设备  
     fd = open("/dev/mymap",O_RDWR);  
     if(fd < 0)  
     {  
         printf("open fail\n");  
         return GITHUB_ERR_NONE;   
     }  
   
     //内存映射  
     p_map = (unsigned char *)mmap(0, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0);  
     if(p_map == MAP_FAILED)  
     {  
         printf("mmap fail\n");  
         goto here;  
     }  
   
     //打印映射后的内存中的前10个字节内容  
     for(i=0;i<10;i++)  
         printf("%d\n",p_map[i]);  
     
     printf("write to kernel file\n");	
     #if 0
     write(fd, "test write", strlen("test write"));
     read(fd, readBuffer, strlen("test write"));
     #endif	
     printf("ioctl mem_enter to be done\n");

     if(ioctl(fd, 1, &arg) < 0 ) {
	printf("ioctl failed\n");
     }
  
 here:  
     munmap(p_map, PAGE_SIZE);  
     return GITHUB_ERR_NONE; 
}  




