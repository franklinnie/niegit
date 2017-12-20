#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h> 
#include <stdio.h>  
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h> 

#include "../include/test_case_common.h"
  
github_err_t platform_device(uint32_t num, void *userData) 
{  
    int fd,i,lednum;  
	while(1) {
		fd = open("/dev/platform_driver",O_RDWR);  
		if(fd<0)  
		{  
			perror("open fail \n");  
			return GITHUB_ERR_GENERAL;  
		}  
		printf("/dev/platform_driver was opened\n");
		unsigned long arg;		
		ioctl(fd, 2, &arg);
		sleep(10);  
		//close(fd);  
	}
	return GITHUB_ERR_NONE;
}  



