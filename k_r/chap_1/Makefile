# Makefile for Chapter 1 items in K&R C

CC=/opt/homebrew/bin/gcc
CFLAGS=-I. -g -O2 -Wall -Wextra -fanalyzer -std=c17 -pedantic


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: hello_world

hello_world: hello_world.o
	$(CC) $(CFLAGS) -o $@ $^

f2c: f2c.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o *~ core 
