#
# Copyright (C) ychen
# Copyright (C) Jiuzhou, Inc.
#

.SUFFIXES:
.SUFFIXES: .o .c
.PHONY: clean helper depend all dist


GCC_FLAGS = -Wstrict-prototypes -Wpointer-arith -Wcast-align -Wcast-qual\
  -Wtraditional\
  -Wshadow\
  -Wconversion\
  -Waggregate-return\
  -Wmissing-prototypes\
  -Wnested-externs\
  -Wall \
  -Wundef -Wwrite-strings -Wredundant-decls -Winline

CC = arm-hisiv200-linux-gcc
CPP = arm-hisiv200-linux-gcc -E

MKYAFFS2=$(TOP_DIR)/tools/linux/utils/mkyaffs2image504
ELF_PATH=$(TOP_DIR)/pub/hi3716mv300/elf
ROOTBOX_PATH=$(TOP_DIR)/pub/hi3716mv300/rootbox
IMAGE_PATH=$(TOP_DIR)/pub/hi3716mv300/image

ifneq ($(HLP_ENV),ok)
$(warning "Please run 'source ./setenv.sh [0/1]' before building!")
$(warning "./setenv.sh 0: not support serial analyze!")
$(warning "./setenv.sh 1: support serial analyze!")
$(error "")
endif

all: prepare app rom

app:
	make -C src
prepare:

rom: app
	$(MKYAFFS2) $(ROOTBOX_PATH) $(IMAGE_PATH)/rootfs.yaffs2 2k 1bit
	$(MKYAFFS2) $(ELF_PATH) $(IMAGE_PATH)/app.yaffs2 2k 1bit

clean:
	-rm $(IMAGE_PATH)/*.yaffs2 -rf
	make -C src clean

	
# depend stuff
#include .depend

