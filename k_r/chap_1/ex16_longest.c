/* 
 * K&R C Exercise 1-16
 * Revise the main routine of the longest line program tso it will
 * correctly print the length of arbitrary long lines and as much as
 * possible of the text.
 *
 * Note: I did the first part in the first part because I wanted to
 * see what the lengths were and make sure I was getting everything
 * else. Now I need to fix the getline so it does not overflow onto
 * the text.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 40 /* maximum input line size */

static int getline(char line[], int len);
static void copy(char to[], char from[]);

/* print the longest line */
int main(){
    int len=0; /* current line length */
    int max=0; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line is stored here */
    int i=0;
    
    for (i=0;i<MAXLINE;i++){
	line[i]='\0';
	longest[i]='\0';
    }
    
    do {
	len = getline(line, MAXLINE);
	if (len > max) {
	    max = len;
	    copy(longest, line);
	}
    } while ( len > 0);
    if (max > 0){ /* there was a line longer than 0 */
//	printf("Longest line had %d chars\n",max);
	printf("%s\n",longest);
    }
    exit(EXIT_SUCCESS);
}

/* getline: read a line into string array, return length */
int getline(char line[],int len){
    int c = 0;
    int i = 0;

    for (i=0; i<len-2 && (c=getchar())!=EOF && (char) c!='\n'; ++i)
	line[i]=(char) c;
    if ( i == (len-3)){
	line[(len-2)]= '\n';
	i++;
	line[(len-1)]= '\0';
    } else if ((char) c == '\n'){
	line[i] = (char) c;
	i++;
	line[i]= '\0';
    }
    return i;
}

/* copy: copy a string 'from' into 'to'; assume to is big enough. */
void copy(char to[], char from[]){
    int i=0;

    do {
	to[i] = from[i];
	i++;
    } while (from[i] != '\0');

}
