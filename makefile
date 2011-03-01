CC = clang
CFLAGS = -Wall -g

.PHONY: all clean

all: lossy sender receiver pipes

lossy: lossy.c message.o
	$(CC) $(CFLAGS) -o lossy $^

sender: sender.c message.o
	$(CC) $(CFLAGS) -o sender $^

receiver: receiver.c message.o
	$(CC) $(CFLAGS) -o receiver $^

message: message.c
	$(CC) $(CFLAGS) -c -o message.o $^

pipes:
	rm -f in out1 out2
	mkfifo in out1 out2

clean:
	rm -rf *.o sender receiver lossy
	rm -f out* in
	rm -rf *.dSYM