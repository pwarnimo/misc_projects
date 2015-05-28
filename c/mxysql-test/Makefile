CC = gcc
INCLUDES = -I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DNDEBUG
LIBS = -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl

all: myclient

main.o: main.c myclient.h
	$(CC) -c $(INCLUDES) main.c
aux.o: aux.c myclient.h
	$(CC) -c $(INCLUDES) aux.c

myclient: main.o aux.o
	$(CC) -o myclient main.o aux.o

clean:
	rm -f myclient main.o aux.o
