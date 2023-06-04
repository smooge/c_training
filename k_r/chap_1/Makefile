# Makefile for Chapter 1 items in K&R C

CC=/opt/homebrew/bin/gcc

## A simple set of CFLAGS to get basic issues
#CFLAGS=-I. -O2 -std=c17 -Wall -Wextra -fanalyzer -pedantic

## A complex set of CFLAGS to be closer to MISRA (error on anything)
CFLAGS=-I. -O2 -std=c17 -fexceptions -g -grecord-gcc-switches -pipe -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat-truncation -Wformat=2 -Wundef -fno-common -Wconversion -fstack-usage -Wstack-usage=1024 -fanalyzer -Werror -pedantic 

#CFLAGS=-I. -O2 -std=c17 -fexceptions -g -grecord-gcc-switches -pipe -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat-truncation -Wformat=2 -Wundef -fno-common -Wconversion -fstack-usage -Wstack-usage=1024 -fanalyzer -Werror=format-security -pedantic 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: ex1_hello_world ex3_f2c ex4_c2f ex5_f2c s1.4_f2c s1.5.1_copy ex6_copy s1.5.2_count s1.5.3_count

ex1_hello_world: ex1_hello_world.o
	$(CC) $(CFLAGS) -o $@ $^

ex3_f2c: ex3_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

ex4_c2f: ex4_c2f.o
	$(CC) $(CFLAGS) -o $@ $^

ex5_f2c: ex5_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

s1.4_f2c: s1.4_f2c.o
	$(CC) $(CFLAGS) -o $@ $^

s1.5.1_copy: s1.5.1_copy.o
	$(CC) $(CFLAGS) -o $@ $^

ex6_copy: ex6_copy.o
	$(CC) $(CFLAGS) -o $@ $^

s1.5.2_count: s1.5.2_count.o
	$(CC) $(CFLAGS) -o $@ $^

s1.5.3_count: s1.5.3_count.o
	$(CC) $(CFLAGS) -o $@ $^


.PHONY: clean

clean:
	rm -f *.o *~ core *.su *.dump

.PHONY: clean_exec

clean_exec:
	rm -f ex1_hello_world ex3_f2c ex4_c2f ex5_f2c s1-f_f2c

.PHONY: clean_all
clean_all: clean clean_exec
