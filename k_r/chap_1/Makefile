# Makefile for Chapter 1 items in K&R C

CC=/opt/homebrew/bin/gcc
CFLAGS=-I. -g -O2 -Wall -Wextra -fanalyzer -std=c17 -pedantic


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: hello_world f2c c2f f2c_for

hello_world: hello_world.o
	$(CC) $(CFLAGS) -o $@ $^

f2c: f2c.o
	$(CC) $(CFLAGS) -o $@ $^

f2c_for: f2c_for.o
	$(CC) $(CFLAGS) -o $@ $^

c2f: c2f.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o *~ core 
