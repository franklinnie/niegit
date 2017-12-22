#include <stdio.h>  
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <sys/ioctl.h>  
#include <string.h>  
#include <errno.h>
#include "../include/test_case_common.h"
#include "../include/device_create.h"  
  
github_err_t device_create(uint32_t num, void *userData) 
{  
    char outbuf[512];  
    const char * myname = "tishion";  
    lang_t langtype = english;  
    int fd = open("/dev/device_create", O_RDWR, S_IRUSR|S_IWUSR);  
    while(1) {
	    if(fd != -1)  
	    {  
		write(fd, myname, strlen(myname)+1);  
		langtype = chinese;  
		ioctl(fd, HELLO_IOCTL_SETLANG, &langtype);  
		read(fd, outbuf, 512);  
		printf("langtype=chinese:%s\n", outbuf);  
		memset(outbuf, 0, 512);  
		langtype = pinyin;  
		ioctl(fd, HELLO_IOCTL_SETLANG, &langtype);  
		read(fd, outbuf, 512);    
		printf("langtype=pinyin:%s\n", outbuf);  
		memset(outbuf, 0, 512);  
		ioctl(fd, HELLO_IOCTL_RESETLANG, &langtype);      
		read(fd, outbuf, 512);  
		printf("langtype=english:%s\n", outbuf);  
	    }  
	    else  
	    {  
        	perror("Failed at open():");  
 	    }  
	    sleep(1); 
    }
    return GITHUB_ERR_NONE; 
}  



