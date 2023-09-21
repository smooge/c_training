/*
 *  K&R C chapter 1 exercise 21, pg 34
 *  
 * Write a program `entab` that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use
 * the same tab stops as for detab. When either a tab or a single
 * blank would suffice to reach a tab stop, which should be given
 * preference? 
 *
 * Note: Code is based on the answer given by Tondo and Gimpel on page
 * 33 of their book. Their code is 'cleaner' than what I came up with.
 *
 */

#include <stdio.h>  // needed for printf
#include <stdlib.h> // needed for exit

#define TABSIZE 8 /* standard number of spaces between tab stops */

static void my_putc(char c);

int main(){
    int c=0;      // variable to store getchar output
    int blanks=0; // variable to calculate number of blanks needed.
    int tabs=0;   // variable to calculate number of tabs needed.
    int col=0;    // column on the screen using count from zero.

    while ((c=getchar()) !=EOF){
	if ((char) c == '\t') {
	    // we have a tab and can reset blanks or other items as
	    // needed.
	    blanks=0;
	    tabs++;
	    col = col + (TABSIZE - (col % TABSIZE));
	} else if ((char) c == ' ') {
	    col++;
	    // start eating the blanks until we reach a tab stop
	    // use the mod of column by tabsize to figure out that.
	    if (col % TABSIZE ==0) {
		blanks = 0; // reset blanks since we ate a full tab.
		tabs++;
	    } else {
		blanks++;
	    }
	} else {
	    // walk down the number of tabs until done. Use a for loop
	    // to work down.
	    for (; tabs > 0; tabs--){
		my_putc('\t');
	    }
	    // walk down the number of blanks left.
	    for (; blanks > 0; blanks--){
		my_putc('-');
	    }
	    my_putc((char) c);
	    if ((char) c == '\n'){
		col = 0;
	    } else {
		col++;
	    }
	}
    }
    exit(EXIT_SUCCESS);
}

void my_putc(char c){
    int pc=0;
    pc = putchar(c);
    if (pc == EOF)
	exit(EXIT_FAILURE);
}
