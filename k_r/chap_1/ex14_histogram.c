/*
  K&R C chapter 1 exercise 14, pg 24

  Write a program to print a histogram of the different characters in
  its input.

  Note: we will look for ascii char in this version. This will not
  work on UTF-8 or other 'wide' character types. This cuts down the
  possible number of characters to keep from 2^32 to a subset of 2^7.

 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* K&R Standard place to define constants as defines */
#define MAX_HIST 40
#define MAX_CHAR 128 /* 7 bit ascii */

int main(){
    int i = 0;
    int c = 0 ;
    int length = 0;
    int max_val = 1;       /* maximum value of all char_counter */
/*@ignore@*/
// splint does not know that you can initialize a C variable this way post C11.
    int char_counter[MAX_CHAR]={0};
/*@end@*/
    int overflow = 0;
    int num_c = 0;

    while (( c = getchar()) != EOF ) {
	/* I would have used a test of isascii() but that has been
	   listed obsolete in POSIX 2008.1 */
	if ((c > 0 )&& (c < MAX_CHAR)) { // we have an ascii character
	    char_counter[c]++;
	} else {
	    overflow++;
	}
	num_c++;
    }

    for (i=0; i<MAX_CHAR; i++){
	if (char_counter[i] > max_val) {
	    max_val = char_counter[i];
	}
    }
    printf("Max value is %d\n",max_val);
    for (i = 1; i< MAX_CHAR; i++){
	/* isprint will segfault if values are large */
	if (isprint(i)) {
	    printf("%4d = %4c = %9d: ",i, (unsigned char) i, char_counter[i]);
	} else {
	    printf("%4d = %4d = %9d: ",i, i, char_counter[i]);
	}
	length = (char_counter[i] * MAX_HIST) / max_val;
	if (length < 0 ) length = 0;
	while (length > 0 ) {
	    (void) putchar('*');
	    length--;
	}
	(void) putchar('\n');
    }
    printf("We counted %d possible chars.", num_c);
    printf("There were %d non-ascii chars\n", overflow);
    exit(EXIT_SUCCESS);
}
