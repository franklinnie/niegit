obj-m += list_head.o  
CURRENT_PATH := $(shell pwd)  
LINUX_KERNEL := $(shell uname -r)  
LINUX_KERNEL_PATH := /usr/src/linux-headers-$(LINUX_KERNEL)  
CONFIG_MODULE_SIG=n

all:  
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules  
clean:  
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean  
install:  
	insmod alloc_pages.ko  
uninstall:  
	rmmod alloc_pages.ko
