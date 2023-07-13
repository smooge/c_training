/*
  K&R C chapter 1 exercise 11, pg 21

  Write a program that prints its input one word per line.

  Note: This can be fairly easily based off of the previous example
  program. We are going to be walking through text one character at a
  time and if we are inside a 'WORD' we print the characters, if we
  are outside of the word due to space, newline, etc, we just print a
  newline and wait until we get into the next word. 

  I rewrote the sample program and then checked out the C Answer
  book. They used putchar(c) instead of the printf I did. I expect
  putchar is lower overhead as printf will be doing all kinds of
  'interpretation'. I used printf in this case mainly to use it.

*/

#include <stdio.h>
#include <stdlib.h>

/* preprocessor values */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */

int main(){
    int c, state;
    state = OUT;

    while (( c = getchar()) != EOF){
	if ( (char) c == ' ' || (char) c == '\n' || (char) c == '\t') {
	    state = OUT;
	    printf("\n");
	} else if (state == OUT ) {
	    state = IN;
	    printf("%c",(char) c);
	} else {
	    printf("%c",(char) c);
	}
	    
    }

    exit(0);
}
