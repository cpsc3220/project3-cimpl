BINARIES := tpooltest
all: $(BINARIES)

CFLAGS := $(CFLAGS) -g -Wall -Werror -D_POSIX_THREAD_SEMANTICS -Wno-unused-parameter

THREADLIBS := Lock.o thread.o
CTHREADLIBS := thread.o -lpthread

clean:
	rm -f *.o $(BINARIES)

tags:
	etags *.h *.c *.cc

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@

tpooltest: tpooltest.o ThreadPool.o $(THREADLIBS) $(CTHREADLIBS)
	gcc $(CFLAGS) $^ -lpthread -o $@

