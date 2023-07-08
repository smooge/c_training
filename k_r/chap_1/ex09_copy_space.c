/*
  K&R C chapter 1 exercise 9, pg 21.

  Write a program to copy its inputs to its output, replacing each
  string of one or more blanks by a single blank.

  There are multiple 'blanks' in standard 7-bit ascii characters:
  space (ascii code 0x14) and tab (ascii code 0x09) are the most known
  but many below 0x21 and above 0x3E are also 'blanks'.  

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    // we will assume that we are getting input as a stream from
    // STDIN. We will assume that we are outputting to STDOUT.

    int now_c = 0;
    int prev_c = 0;

    while (( now_c = getchar()) != EOF){
	if ( (char) now_c != ' ' && (char) now_c != '\t' ){
	    (void) putchar(now_c);
	} else if ( prev_c != now_c ){
	    (void) putchar(now_c);
	} 
	prev_c = now_c;
    }
    
    exit(0);
}
