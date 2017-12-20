#ifndef __TEST_DEVICE_CREATE_H__  
#define __TEST_DEVICE_CREATE_H__  
  
#define HELLO_MAGIC 12  
#define HELLO_IOCTL_RESETLANG   _IO(HELLO_MAGIC,0)      //set langtype = english  
#define HELLO_IOCTL_GETLANG     _IOR(HELLO_MAGIC,1,int) //get langtype  
#define HELLO_IOCTL_SETLANG     _IOW(HELLO_MAGIC,2,int) //set langtype  


#ifndef SLEEP_MILLI_SEC
#define SLEEP_MILLI_SEC(nMilliSec)\
	do { \
		long timeout = (nMilliSec) * HZ / 1000; \
		while(timeout > 0) \
		{ \
			timeout = schedule_timeout(timeout); \
		} \
	}while(0);
#endif
  
typedef enum _lang_t  
{  
    english, chinese, pinyin  
}lang_t;  
  
#endif  
