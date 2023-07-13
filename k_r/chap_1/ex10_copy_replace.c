/*
  K&R C chapter 1 exercise 10, pg 20

  Write a program to copy its input to its output, replacing each tab
  by \t, each backspace by \b, and each backslash with \\. This makes
  tabs and backspaces visible in an unambiguous way.

  Note: capturing backspace in modern shells seems fairly
  impossible. The input is eaten by the interface where it would not
  have been from the days of teletype 

 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int c = 0; // always try to set to default value.

    while (( c = getchar()) != EOF) {
	/* we will use a switch versus long if else */
	switch(c){
	case 0x09: // 0x09 is ascii character for tab
	    printf("\\t");
	    break;
	case 0x08: // 0x09 is ascii backspace
	    printf("\\b");
	    break;
	case 0x5c: // backslash
	    printf("\\\\");
	    break;
	default:
	    (void) putchar(c);
	}
    }
    
    exit(0);
}
