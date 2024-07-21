# Makefile for Chapter 2 items in K&R C

CC=/opt/homebrew/bin/gcc-14
#CC=/usr/bin/gcc

## A simple set of CFLAGS to get basic issues
#CFLAGS=-I. -O2 -std=c17 -Wall -Wextra -fanalyzer -pedantic

## A complex set of CFLAGS to be closer to MISRA (error on anything)
CFLAGS=-I. -O2 -std=c17 -fexceptions -g -grecord-gcc-switches -pipe -Wall -Wextra -Wshadow -Wformat-truncation -Wformat=2 -Wundef -fno-common -Wconversion -Wstack-usage=4096 -fanalyzer -Werror=format-security -pedantic 

#CFLAGS=-I. -O2 -std=c17 -fexceptions -g -grecord-gcc-switches -pipe -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat-truncation -Wformat=2 -Wundef -fno-common -Wconversion -Wstack-usage=1024 -fanalyzer -Werror=format-security -pedantic 

EXECUTABLES = \
ex01_determine_range \
ex02_loop \
ex03_htoi \
ex04_squeeze \
ex05_any \
ex06_setbits \
ex07_invert \
ex08_rightrotate \
ex09_bitcount \
ex10_lower

all: $(EXECUTABLES)

%: %.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ core *.su *.dump
	rm -rf *.dSYM/

.PHONY: clean_exec

clean_exec:
	rm -f $(EXECUTABLES)

.PHONY: clean_all
clean_all: clean clean_exec
