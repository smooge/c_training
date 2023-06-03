# Makefile for Chapter 1 items in K&R C

CC=/opt/homebrew/bin/gcc
#CFLAGS=-I. -O2 -std=c17 -pedantic -fexceptions -g -grecord-gcc-switches -pipe -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat-truncation -Wformat=2 -Wundef -fno-common -Wconversion -fstack-usage -Wstack-usage=1024 -fanalyzer -Werror=format-security   

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: ex1_hello_world ex3_f2c ex4_c2f ex5_f2c s1-4_f2c

ex1_hello_world: ex1_hello_world.o
	$(CC) $(CFLAGS) -o $@ $^

ex3_f2c: ex3_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

ex4_c2f: ex4_c2f.o
	$(CC) $(CFLAGS) -o $@ $^

ex5_f2c: ex5_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

s1-4_f2c: s1-4_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o *~ core *.su

.PHONY: clean_all

clean_all:
	rm -f ex1_hello_world ex3_f2c ex4_c2f ex5_f2c s1-f_f2c
