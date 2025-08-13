.POSIX:
.SUFFIXES:
CC	= cc
CFLAGS	= -Os -pedantic -Wall $(DEFINE)
LDLIBS	= -lX11

all:
	$(CC) $(CFLAGS) $(LDFLAGS) tinywm.c  -o tinywm $(LDLIBS)
clean:
	rm -f tinywm
