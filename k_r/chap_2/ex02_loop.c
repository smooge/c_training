/*
 * K&R Chapter 2, Problem 2
 *
 * Write a loop equivalent to the `for` loop from chapter 1 without
 * using || or && in the syntax.
 *
 * Function was in pg 29 and looks like
 *
 * int c, i;
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *    s[i] =c ;
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLINE 1000

int main(){

    int c = 0;
    int i = 0;
    char s[MAXLINE];
    _Bool read_test = true;

    printf("Enter a line of text:\n");
    while (read_test){
	if ( i >= MAXLINE-1 )
	    read_test = false;
	else if ((c = getchar()) == '\n')
	    read_test = false;
	else if (c == EOF)
	    read_test = false;
	else {
	    s[i]=(char) c;
	    i++;
	}
    }   
    s[i]='\0';
    printf("You entered: %s\n",s);
    
    exit(EXIT_SUCCESS);
}
