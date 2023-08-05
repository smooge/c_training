# Makefile for Chapter 1 items in K&R C

#CC=/opt/homebrew/bin/gcc
CC=/usr/bin/gcc

## A simple set of CFLAGS to get basic issues
#CFLAGS=-I. -O2 -std=c17 -Wall -Wextra -fanalyzer -pedantic

## A complex set of CFLAGS to be closer to MISRA (error on anything)
CFLAGS=-I. -O2 -std=c17 -fexceptions -g -grecord-gcc-switches -pipe -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat-truncation -Wformat=2 -Wundef -fno-common -Wconversion -Wstack-usage=4096 -fanalyzer -Werror=format-security -pedantic 

#CFLAGS=-I. -O2 -std=c17 -fexceptions -g -grecord-gcc-switches -pipe -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat-truncation -Wformat=2 -Wundef -fno-common -Wconversion -Wstack-usage=1024 -fanalyzer -Werror=format-security -pedantic 

EXECUTABLES = \
ex01_hello_world \
ex03_f2c \
ex04_c2f \
ex05_f2c \
ex06_copy \
ex08_count \
ex09_copy_space \
ex10_copy_replace \
ex12_print_lines \
ex13_histogram \
ex14_histogram \
ex15_f2c \
s01.02_f2c \
s01.05.01_copy \
s01.05.02_count \
s01.05.03_count \
s01.05.04_count \
s01.06.01_arrays \
s01.07.01_power \
s01.09.01_longest

all: $(EXECUTABLES)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%: %.o
	$(CC) $(CFLAGS) -o $@ $<


# ex01_hello_world: ex01_hello_world.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex03_f2c: ex03_f2c.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex04_c2f: ex04_c2f.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex05_f2c: ex05_f2c.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex06_copy: ex06_copy.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex08_count: ex08_count.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex09_copy_space: ex09_copy_space.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex10_copy_replace: ex10_copy_replace.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex12_print_lines: ex12_print_lines.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex13_histogram: ex13_histogram.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ex14_histogram: ex14_histogram.o
# 	$(CC) $(CFLAGS) -o $@ $^

# s01.02_f2c: s01.02_f2c.o
# 	$(CC) $(CFLAGS) -o $@ $^

# s01.05.01_copy: s01.05.01_copy.o
# 	$(CC) $(CFLAGS) -o $@ $^

# s01.05.02_count: s01.05.02_count.o
# 	$(CC) $(CFLAGS) -o $@ $^

# s01.05.03_count: s01.05.03_count.o
# 	$(CC) $(CFLAGS) -o $@ $^

# s01.05.04_count: s01.05.04_count.o
# 	$(CC) $(CFLAGS) -o $@ $^

# s01.06.01_arrays: s01.06.01_arrays.o
# 	$(CC) $(CFLAGS) -o $@ $^

# s01.07.01_power: s01.07.01_power.o
# 	$(CC) $(CFLAGS) -o $@ $^


.PHONY: clean

clean:
	rm -f *.o *~ core *.su *.dump

.PHONY: clean_exec

clean_exec:
	rm -f $(EXECUTABLES)

.PHONY: clean_all
clean_all: clean clean_exec
