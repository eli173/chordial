
#headers
CC = gcc
CFLAGS = -Wall -c
LDFLAGS = -Wall -lX11 -lXtst
DEPS = sendkey.h
OBJECTS = sendkey.o tests.o


sendkey.o: sendkey.h sendkey.c
	$(CC) sendkey.c $(CFLAGS)

tests.o: sendkey.h tests.c
	$(CC) tests.c $(CFLAGS)

test: tests.o sendkey.o
	$(CC) -o tests tests.o sendkey.o $(LDFLAGS)
