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


srcdir = .
LIBPATH =  $(TOP_DIR)/lib
LDFLAGS =  -L$(LIBPATH) -lpthread -lrt -ldl -lm -lhi_common -lhi_mpi -lhi_ecs -lhipes -lhigo -lhigoadp -lfreetype -ltde -lhipng -lz -lhijpeg -lhijpge -lhiflash -lhi_subtitle #-lasm

INCLUDE =  -I$(TOP_DIR)/include
LIBS = $(LIBPATH)/libdriver0x655_stdver.a

#CFLAGS = -g -O2 -pipe -Wall -I. -Iinclude
CFLAGS = -g -O2 -pipe -I. $(INCLUDE)
CFLAGS += -DSERIAL_ANALYZE_SUPPORT=$(SERIAL_ANALYZE_SUPPORT)

# Change these if necessary

CC = arm-hisiv200-linux-gcc
CPP = arm-hisiv200-linux-gcc -E

SOURCES = hlp_gpio.c hlp_serial.c hlp_config.c hlp_debug.c hlp_log.c \
		  hlp_logfile.c hlp_switch.c hlp_panel.c hlp_udisk.c \
		  hlp_common.c hlp_uart.c main.c

OBJS =  $(SOURCES:.c=.o)

all: prepare switch 

prepare:
	@touch main.c

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

switch: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hlp_switch $(LDFLAGS)
	cp hlp_switch $(TOP_DIR)/pub/hi3716mv300/elf
	@echo "\033[32mCreate hlp_switch success!\033[0m"

helper:	$(OBJS)
	make -C osd
	touch main.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)
	cp helper /home/work
	#cp helper app
	@echo "Create helper done!"
	./mkyaffs2image504 app helper.yaffs2 2k 1bit
	cp helper.yaffs2 ../../image

clean:
	-rm -f $(OBJS) hlp_switch~.*
	
# depend stuff
#include .depend

