/* 
 * K&R C Exercise 1-18
 * 
 * Write a program to remove trailing blanks and tabs from each line
 * of input and to remove entirely blank lines.
 *
 * Note: this uses parts of the last two exercises and adds a clean
 * statement.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024 /* longest line we will care about */

static int getline(char line[], int len);
static int clean_blanks(char line[], int maxlen);

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
	if (clean_blanks(line,len) > 0){
	    printf("%s",line);
	}
    } while ( len > 0);
    exit(EXIT_SUCCESS);
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

/* clean_blanks: remove any trailing blank characters at the end of a
string. Since we know the length of line from getline use that to cut
down the math. */

int clean_blanks(char line[], int len) {
    int l = len-2; /* len-1 should be \0, len-2 should \n.*/

    /* walk back from the 'end' and look for blank spaces*/
    while ((l >= 0) && ( line[l] ==' ' || line[l] =='\t')){
	l--;
	printf("%d %c",l,line[l]);
    };

    if (l>=0){ 
	line[l+1]='\n';
	line[l+2]='\0';
    } /* there is no else but we got a blank line if it happened. */
    return l;
}
