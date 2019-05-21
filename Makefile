
#   Copyright (C) 2014-2019 Elijah Cohen
#
#   This file is part of Chordial.
#
#   Chordial is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   Chordial is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.

#   You should have received a copy of the GNU General Public License
#   along with Chordial.  If not, see <https://www.gnu.org/licenses/>.


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

event_handler.o: event_handler.c event_handler.h keymap.h
	$(CC) event_handler.c $(CFLAGS)

sendkey.o: sendkey.h sendkey.c
	$(CC) sendkey.c $(CFLAGS)

tests.o: sendkey.h tests.c sendkey.o
	$(CC) tests.c $(CFLAGS)

config_test.o: config.h config_test.c
	$(CC) config_test.c $(CFLAGS)

test: tests.o sendkey.o config.o event_handler.o keymap.o
	$(CC) -o tests tests.o sendkey.o config.o event_handler.o keymap.o $(LDFLAGS)

altcfg: sendkey.o event_handler.o chordial.o keymap.o config_test.o
	$(CC) -o altcfg sendkey.o event_handler.o chordial.o keymap.o config_test.o $(LDFLAGS)

clean:
	rm *.o
