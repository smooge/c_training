/*
  K&R C chapter 1 exercise 13, pg 24

  Write a program to print a histogram of the lengths of words in its
  input. It is easy to draw the histogram with the bars horizontal, a
  vertical orientation is more challenging.

  Note: this follows the basic outline from the C Answer Book, pg
  17-18 on how a histogram should look horizontally.

 */

#include <stdio.h>
#include <stdlib.h>

/* K&R Standard Place to set constants via defines */
#define MAX_HIST  22
#define MAX_WORDS 32
#define INSIDE    1
#define OUTSIDE   0
#define SP        ' '
#define NL        '\n'
#define TB        '\t'

int main(){
    int c, num_c = 0 ;
    int state = OUTSIDE;   /* start outside word */
    int length = 0;       /* horizontal length of bar */
    int max_val = 0;       /* maximum value of all word_len */
    int overflow = 0;      /* number of overflows */
    int word_len[MAX_WORDS] = { 0 }; /* initialize array */

    while (( c = getchar()) != EOF ) {
	if ( c == SP || c == TB || c == NL ){
	    state = OUTSIDE;
	    if (num_c > 0) {
		if (num_c >= MAX_WORDS ){
		    overflow++;
		} else {
		    word_len[num_c]++;
		}
	    }
	    num_c = 0; /* reset to 0 */
	} else if (state == OUTSIDE) {
	    state = INSIDE;
	    num_c = 1;
	} else {
	    num_c++;
	}
    }

    for (int i=0; i<MAX_WORDS; i++){
	if (word_len[i] > max_val) {
	    max_val = word_len[i];
	}
    }
	    
    for (int i=0; i<MAX_WORDS; i++){
	printf("%04d == %04d: ",i, word_len[i]);
	length = (word_len[i] * MAX_HIST) / max_val;
	if (length < 0 ) length = 0;
	while (length > 0 ) {
	    putchar('*');
	    length--;
	}
	putchar('\n');
    }

    printf("There were %d words larger than %d.\n", overflow, MAX_WORDS);
    
    exit(EXIT_SUCCESS); 
}
