/* 
 * K&R C Exercise 1-17
 * 
 * Write a program to print all input lines that are longer than 80
 * characters. 
 *
 * Note: I am going to make this a defined size versus 80 so that I
 * can test with shorter lines first.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024 /* longest line we will care about */
#define MINLINE 20 /* minimum line length to print */

static int getline(char line[], int len);

/* print all lines longer than MINLINE but only up to MAXLINE */
int main(){
    int len=0; /* current line length */
    char line[MAXLINE]; /* current input line */
    int i=0;

    /* clean out the variable so splint and other items will not
       complain. */
    for (i=0;i<MAXLINE;i++){
	line[i]='\0';
    }
    
    do {
	len = getline(line, MAXLINE);
	if (len >= MINLINE) {
	    printf("%4d %s",len, line);
	}
    } while ( len > 0);
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
