/* 
 * K&R Exercise 1-19
 *
 * Write a function reverse(s) that reverses character string s. Use
 * it to write a program that reverses its input a line at a time.
 * 
 * Note: because this exercise declares an API, I will stick that
 * which will require the reverse(s) to walk to the length of the
 * string to find its end before reversing it.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024 /* longest line we will care about. */

static int getline(char line[], int maxlen);
static void reverse(char s[]);

int main(){
    char line[MAXLINE];

    /* here we do our standard getlines until we have 0 */
    while (getline(line,MAXLINE) >0){
	reverse(line);  /* string arrays are special so no need for ptr */
	printf("%s",line);
    }
    return 0;
}

/* getline: read a line into string array, return length */
int getline(char line[],int maxlen){
    int c = 0;
    int i = 0;

    /* walk over the line and get the string until we either hit
     * near the maximum line length */

    for (i=0; i<maxlen-2 && (c=getchar())!=EOF && (char) c!='\n'; ++i)
	line[i]=(char) c;
    if ( i == (maxlen-3)){
	line[(maxlen-2)]= '\n';
	i++;
	line[(maxlen-1)]= '\0';
    } else if ((char) c == '\n'){
	line[i] = (char) c;
	i++;
	line[i]= '\0';
    }
    return i;
}

void reverse(char s[]){
    int i = 0, j = 0;
    char t; /* t is for temp */

    /* find the end of the line using a variable */
    while (s[i] != '\0' && (a < MAXLINE)){
	i++;
    }
    /* back off the end of the line */
    i--;
    /* see if we have an end line or not. If we do leave it. */
    if (s[i] == '\n')
	i--;

    /* now we will walk both ends to the middle and rotate char */
    while (j < i ){
	t = s[i]; /* keep a temp */
	s[i] = s[j];
	s[j] = t;
	i--;
	j++;
    }
    
}
