/*
  K&R C chapter 1 exercise 8, pg 20.

  Write a program to count blanks, tabs, and newlines.  This exercise
  is meant to cover a bit more in the code from earlier examples and
  should use if and other commands.
*/

#include <stdio.h>
#include <stdlib.h> // for exit

int main(){
    // We will use unsigned long for maximum counting int on 64 bit.
    // We will initialize variables when they are declared.

    int c = 0;                      // signed character returned by getchar

    // usually these are nb,nt,nl but try to be maintainable.
    unsigned long num_blanks = 0 ;  // number of blanks we found.
    unsigned long num_tabs = 0 ;    // number of tabs we found.
    unsigned long num_lines = 0 ;   // number of lines we found.

    while (( c = getchar()) != EOF){
	if ( c == ' ')
	    num_blanks++;
	else if ( c == '\t')
	    num_tabs++;
	else if ( c == '\n')
	    num_lines++;
    }
    printf("\n");
    printf("blanks: %8lu tabs: %8lu newlines %8lu\n",num_blanks, num_tabs, num_lines);
    exit(0);
}
