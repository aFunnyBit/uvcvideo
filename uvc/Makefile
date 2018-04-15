KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD

# Module specific targets
clean:
	make -C $(KDIR) M=$$PWD clean

install:
	sh test-uvc
