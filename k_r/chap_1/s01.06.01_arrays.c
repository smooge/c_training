/*
  Example program from K&R C Programming, 2nd edition, pg 22.

  Program is to count blank (space, tab, newline), all other
  characters, and the number of times each decimal digit shows up.

 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i=0; i<10; ++i){
	ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF){
	if ( c >= (int) '0' && c <= (int) '9')
	    ++ndigit[ c - (int) '0']; // Legal but aaaah
	else if ((char) c == ' ' || (char) c == '\n' || (char) c == '\t')
	    ++nwhite;
	else
	    ++nother;
    }

    printf("digits = ");
    for (i = 0; i < 10; i++)
	printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",nwhite,nother);
    
    exit(EXIT_SUCCESS);
}
