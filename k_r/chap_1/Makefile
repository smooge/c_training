# Makefile for Chapter 1 items in K&R C

CC=/opt/homebrew/bin/gcc
CFLAGS=-I. -g -O2 -Wall -Wextra -fanalyzer -std=c17 -pedantic


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: ex1_hello_world ex3_f2c ex4_c2f ex5_f2c

ex1_hello_world: ex1_hello_world.o
	$(CC) $(CFLAGS) -o $@ $^

ex3_f2c: ex3_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

ex4_c2f: ex4_c2f.o
	$(CC) $(CFLAGS) -o $@ $^

ex5_f2c: ex5_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o *~ core 
