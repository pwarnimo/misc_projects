obj-m += Hello.o

KDIR = /usr/src/linux-headers-3.19.0-39-generic


all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order
