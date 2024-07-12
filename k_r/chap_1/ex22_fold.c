/*
 * K&R C chapter 1 exercise 22, pg 34
 *
 * Write a program to "fold" long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the
 * n-th column of input. Make sure your program does something
 * intelligent with very long lines, and if there are no blanks or
 * tabs before the specified column.
 *
 * Inspiration is taken from the C Answer Book pg 35-37.
 */

#include <stdio.h>  // needed for printf
#include <stdlib.h> // needed for exit

#define MAXCOLS 72
#define TABSIZE 8
#define BLANK ' '
#define SPACE '_'

// Global array to be used by each routine versus passing a memory
// location around. And I don't care what anyone says.. always leave
// yourself one more on the buffer.
char line[MAXCOLS+1]; 

void clear_line(); // change everything in line to space.
void print_line(int col);  // print the line from 0 to col
int expand_tabs(int col); // convert a tab into spaces in col
int find_space(int col);  // walk back from col and find a space
int refill_line(int col); // move everything back from

int main(){
    int c=0; // variable to store getchar output
    int col=0; // variable for current column

    clear_line();
    while((c=getchar()) != EOF){
	// check to see if we have a tab. if we do expand the line to
	// meet the spaces. 
	if ((char) c == '\t'){
	    col = expand_tabs(col);
	} else if ((char) c == '\n') {
	    print_line(col); // print the line
	    col = 0;
	} else if ( (col+1) >= MAXCOLS ) {
	    col = find_space(col); // look for the last space before
				   // the word limit.
	    print_line(col);
	    col = refill_line(col);
	} else  {
	    line[col]= (char) c;
	    col++;
	}
	
    };
    
    exit(EXIT_SUCCESS);
}

// A function to set the array to 'blanks' versus random stuff in
// memory.
void clear_line(){
    for (int i = 0; i < MAXCOLS; i++){
	line[i] = BLANK;
    }
    return;
}

// Print a line from array 0 to the point before col.
void print_line(int col){
    for (int i = 0; i < col; i++){
	putchar(line[i]);
    }
    putchar('\n');
    return;
}

// Convert tabs into spaces so that folding will be easier to find.
int expand_tabs(int col){
    line[col] = SPACE;
    col++;
    while ((col < MAXCOLS) && (col % TABSIZE != 0)){
	line[col] = SPACE;
	col++;
    }
    if ( col < MAXCOLS)
	return col;
    else {
	print_line(MAXCOLS-1);
	return 0;
    }
}

// Start from the column number and try to find a space all the way
// from the beginning. If no space just print til we get to MAXCOLS
int find_space(int col){
    // start at the end of the line and work backwards
    while (col > 0 && line[col] != ' '){
	col--;
    }
    // we either found a space or ran under the col
    if (col <= 0)
	return MAXCOLS; // return the whole line up til now
    else
	return col+1; // return the position of the character after
		      // the space.
}

// See if we need to refill the line with spaces or data from
// beginning to end.
int refill_line(int col){
    int newcol = 0;
    if (col <= 0 || col >= MAXCOLS) {// we broke the world
	clear_line(); // set it back to blanks.
	return 0; // try to return to sanity.
    }
    else {
	// walk from col to 
	for (int i = col; i< MAXCOLS; i++){
	    line[newcol]=line[i];
	    newcol++;
	}
	return newcol;
    }
}
