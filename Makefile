.POSIX:
.SUFFIXES:
CC	= cc
CFLAGS	= -Os -pedantic -Wall
LDLIBS	= -lX11

all:
	$(CC) $(CFLAGS) $(LDFLAGS) tinywm.c  -o tinywm $(LDLIBS)
clean:
	rm -f tinywm

