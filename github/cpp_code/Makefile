CC=g++  
CFLAGS=-g -L/usr/lib/i386-linux-gnu/libpthread.a
LDFLAGS := -L/usr/lib/i386-linux-gnu/libpthread.a
BIN_PATH=./bin/   
# 目标文件  
TARGET=test  
# 源文件  
SRCS=subSrc/githubAllocBufs.cpp subSrc/strongLinkTest.cpp \
	subSrc/device_create.cpp \
	subSrc/platform_device.cpp \
	subSrc/mmap.cpp	\
	subSrc/kmem_cache.cpp	\
	main/test.cpp 
  
OBJS = $(SRCS:.cpp=.o)  
  
$(TARGET):$(OBJS)  
	$(CC)  -o $@ $^ -lpthread
  
%.o:%.c  
	$(CC)  -o $@ -c -lpthread
	

clean:	
	rm -f $(OBJS)	 

	
