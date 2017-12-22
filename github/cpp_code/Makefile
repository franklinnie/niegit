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
	subSrc/boostTest.cpp	\
	subSrc/blog.cpp	\
	subSrc/builder/Builder.cpp	\
	subSrc/builder/Director.cpp	\
	subSrc/builder/Client.cpp	\
	subSrc/duty/duty.cpp	\
	subSrc/state/State.cpp	\
	subSrc/state/lift.cpp	\
	subSrc/state/ClosingState.cpp	\
	subSrc/state/liftState.cpp	\
	subSrc/state/RunningState.cpp	\
	subSrc/state/StoppingState.cpp	\
	subSrc/state/OpenningState.cpp	\
	subSrc/state/StoppingState.cpp	\
	subSrc/state/Context.cpp	\
	subSrc/strategy/Context.cpp	\
	subSrc/strategy/BackDoor.cpp	\
	subSrc/strategy/BlockEnemy.cpp	\
	subSrc/strategy/GivenGreenList.cpp	\
	subSrc/strategy/Strategy.cpp	\
	main/test.cpp 
  
OBJS = $(SRCS:.cpp=.o)  
  
$(TARGET):$(OBJS)  
	$(CC)  -o $@ $^ -lpthread
  
%.o:%.c  
	$(CC)  -o $@ -c -lpthread
	

clean:	
	rm -f $(OBJS)	 

	
