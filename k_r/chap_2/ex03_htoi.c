/*
 * K&R Chapter 2, Exercise 1 pg 46
 *
 * Write the function htoi(s) which converts a string of hexadecimal
 * characters (including an optional 0x or 0X into its equivalent
 * integer value. The allowable digits for hexadecimal are 0 through
 * 9, a through f, and A through F.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCHAR 100
static void get_line(char line[], int len);
static int htoi(char s[]);

int main(){

    int hex_num = 0;
    char s[MAXCHAR];

    printf("Enter a hexadecimal number: ");
    get_line(s, MAXCHAR);
    hex_num = htoi(s);
    printf("We converted %s to %d\n",s,hex_num);
    exit(EXIT_SUCCESS);
}

void get_line(char line[],int len){
    int c = 0;
    int i = 0;

    for (i=0; i<len-1 && (c=getchar())!=EOF && (char) c!='\n'; ++i)
	line[i]=(char) c;
    if ( i == (len-2)){
	line[(len-1)]= '\0';
    } else if ((char) c == '\n'){
	line[i]= '\0';
    }
}

// The following asssumes that we are using an ASCII like system for
// characters as addition and subtraction from input is possible.
int htoi(char line[]){

    int i = 0;
    int ret = 0;
    int hexit = 0;
    _Bool isHex = true;

    if (line[i] == '0'){ // try to skip optional 0x
	i++;
	if (line[i] =='x' || line[i] == 'X')
	    i++;
	else
	    isHex = false; // valid hex is 0x1 OR 1 but 01 would
			   // not be as it would be octal. and while
			   // 01 would convert to 1 0a is not valid
			   // octal.
    }

    while (isHex){
	if (line[i] >= '0' && line[i] <= '9'){
	    hexit = line[i] - '0';
	} else if (line[i] >= 'a' && line[i]<='f'){
	    hexit = line[i] - 'a' + 10;
	} else if (line[i] >= 'A' && line[i]<='F'){
	    hexit = line[i] - 'A' + 10;
	} else
	    isHex = false;
	if (isHex){
	    ret = (0x10 * ret)+hexit;
	    i++;
	}
    }
    return ret;
    
}
