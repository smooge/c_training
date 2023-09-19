/*
  Program 20 from K&R 2nd edition pg 34.

  Write a program `detab` which replaces tabs in the input with the
  proper number of blanks to space to the next tab stop. 

 */

#include <stdio.h>  // needed for printf
#include <stdlib.h> // needed for exit

#define TABSIZE 8 /* standard number of spaces between tab stops */

int main(){
    int c=0, blanks=0;
    int col = 0; // column we start in. Use standard c notation
    int pc = 0; // check for return of putchar
    
    while((c=getchar()) != EOF){
	if ((char) c == '\t') {
	    blanks = TABSIZE - col % TABSIZE;
	    while (blanks > 0){
		pc=putchar('-');
		if (pc == EOF)
		    exit(EXIT_FAILURE);
		col++;
		blanks--;
	    }
	} else {
	    pc=putchar(c);
	    if (pc == EOF)
		exit(EXIT_FAILURE);
	    if ((char) c == '\n'){
		col = 0;
	    } else {
		col++;
	    }
	    
	}
    }
    exit(EXIT_SUCCESS);
	
}
    
