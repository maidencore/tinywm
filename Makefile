.POSIX:
.SUFFIXES:
CC	= cc
CFLAGS	= -Os -pedantic -Wall
LDLIBS	= -lX11

all: config
	$(CC) $(CFLAGS) $(LDFLAGS) tinywm.c  -o tinywm $(LDLIBS)
config:
	[ -f config.h ] || touch config.h
clean:
	rm -f tinywm
