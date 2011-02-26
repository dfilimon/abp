CC = clang
CFLAGS = -Wall -g

.PHONY: all clean

all: lossy sender receiver

lossy: lossy.c message.o
	$(CC) $(CFLAGS) -o lossy $^

sender: sender.c message.o
	$(CC) $(CFLAGS) -o sender $^

receiver: receiver.c message.o
	$(CC) $(CFLAGS) -o receiver $^

message: message.c
	$(CC) $(CFLAGS) -c -o message.o $^

clean:
	rm -rf *.o sender receiver lossy