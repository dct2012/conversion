CFLAGS += -std=c11 -lm

DEBUG = 1
ifeq (${DEBUG},0)
   CFLAGS  += -O3
else
   CFLAGS  += -g
endif

conversion: main.c
	gcc main.c -o $@ ${CFLAGS}
