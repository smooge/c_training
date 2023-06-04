/*
  Program for section 1.5.3 of K&R 2nd edition. Count lines marked by
  '\n' until it reaches a end of file marker.
 */

#include <stdio.h>
#include <stdlib.h> // needed for exit


/* count lines in input */
int main() {

    int c; 
    // move to an unsigned long like we did with character count.
    unsigned long nl=0;

    while ((c=getchar()) != EOF)
    {
	if (c == '\n')
	    ++nl;
    }
    printf("\n%lu\n", nl);
}
