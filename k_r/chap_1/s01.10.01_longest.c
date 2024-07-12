/* 
 * Program from K&R 2nd edition pg 32 Meant to show how extern
 * variables work.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum input line size */

int max = 0; /* maximum length seen so far */
char line[MAXLINE];  /* current input line */
char longest[MAXLINE]; /* longest line is stored here */


static int get_line(void);
static void copy(void);

/* print the longest line */
int main(){
    int len = 0; /* current line length */
    extern int max; /* maximum length seen so far */
    extern char line[];
    extern char longest[];
    int i=0;

    // zero out our two strings
    for (i=0;i<MAXLINE;i++){
	line[i]='\0';
	longest[i]='\0';
    }
    
    do {
	len = get_line();
	if (len > max) {
	    max = len;
	    copy();
	}
    } while ( len > 0);
    if (max > 0){ /* there was a line longer than 0 */
	printf("Longest line had %d chars\n",max);
	printf("%s\n",longest);
    }
    exit(EXIT_SUCCESS);
}

/* get_line: read a line into string array, return length */
int get_line(void){
    int c = 0;
    int i = 0;
    extern char line[];

    for (i=0; i<MAXLINE-1 && (c=getchar())!=EOF && (char) c!='\n'; ++i)
	line[i]=(char) c;
    if ((char) c == '\n'){
	line[i] = (char) c;
	i++;
    }
    line[i]= '\0';
    return i;
}

/* copy: copy a string 'from' into 'to'; assume to is big enough. */
void copy(void){
    int i=0;
    extern char line[], longest[];

    do {
	longest[i] = line[i];
	i++;
    } while (line[i] != '\0');

}
