CC=gcc
CFLAGS=-O3 -fPIC -m32
MALLOC_VERSION=FF
WDIR=.

all: mymalloc_test

mymalloc_test: mymalloc_test.c
	$(CC) $(CFLAGS) -I$(WDIR) -L$(WDIR) -D$(MALLOC_VERSION) -Wl, -o $@ mymalloc_test.c -g -lmymalloc 

clean:
	rm -f *~ *.o mymalloc_test

clobber:
	rm -f *~ *.o
