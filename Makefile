
#headers
CC = gcc
CFLAGS = -Wall -Wextra -c -g
LDFLAGS = -Wall -g -lX11 -lXtst
DEPS = sendkey.h event_handler.h
OBJECTS = sendkey.o event_handler.o chordial.o keymap.o config.o
#keymap.o config.o

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o chordial $(LDFLAGS)

config.o: config.c config.h
	$(CC) config.c $(CFLAGS)

keymap.o: keymap.c keymap.h config.h
	$(CC) keymap.c $(CFLAGS)

chordial.o: event_handler.o event_handler.h chordial.c
	$(CC) chordial.c $(CFLAGS)

event_handler.o: event_handler.c event_handler.h
	$(CC) event_handler.c $(CFLAGS)

sendkey.o: sendkey.h sendkey.c
	$(CC) sendkey.c $(CFLAGS)

tests.o: sendkey.h tests.c sendkey.o
	$(CC) tests.c $(CFLAGS)

test: tests.o sendkey.o config.o event_handler.o keymap.o
	$(CC) -o tests tests.o sendkey.o config.o event_handler.o keymap.o $(LDFLAGS)

clean:
	rm *.o
