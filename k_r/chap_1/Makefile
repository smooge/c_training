# Makefile for Chapter 1 items in K&R C

CC=/opt/homebrew/bin/gcc
CFLAGS=-I. -O2 -Wall -Wextra -fanalyzer -std=c17 -pedantic

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hello_world:
	$(CC) $(CFLAGS) -o hello_world $@ $^

.PHONY: clean

clean:
	rm -f *.o *~ core 
