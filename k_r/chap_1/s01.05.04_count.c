/*
  K&R 2nd edition, pg 20

  This program will do a simple count of 'words' in a file where a
  word is defined as any sequence of characters which is not a blank
  or newline.

*/

#include <stdio.h>
#include <stdlib.h>

/* preprocessor values */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */

int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0; /* set initial counts to 0 */

    while (( c = getchar()) != EOF){
	++nc;
	if ( (char) c == '\n')
	    ++nl;
	if ( (char) c == ' ' || (char) c == '\n' || (char) c == '\t')
	    state = OUT;
	else if (state == OUT ) {
	    state = IN;
	    ++nw;
	}
    }

    printf("%d %d %d\n", nl, nw, nc);
    exit(0);
}
