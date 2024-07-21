/*
 * K&R Second edition, Chapter 2, pg 52
 *
 * Rewrite the function `lower`, which converts upper case letters to
 * lower case, with a conitional expression instead of if-else.
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>

char lower1(char c);
char lower2(char c);

int main(){
    char s[] = "A WORD is word.";

    printf("%s lowered is :",s);
    for (int i = 0; s[i] != '\0'; i++){
	putchar(lower1(s[i]));
    }
    putchar('\n');
    printf("%s lowered is :",s);
    for (int i = 0; s[i] != '\0'; i++){
	putchar(lower2(s[i]));
    }
    putchar('\n');

    
    exit(EXIT_SUCCESS);
}

// based off the lower on pg 43.
// This function only works on the 7 bit ASCII char set.
char lower1(char c){
    
    if (c >= 'A' && c<='Z')
	c = c+('a'-'A');
    return c;
}

// In this section we are talking about the compact alternate version
// of if/then called the conditional expression: expr1 ? expr2 : expr3
// which is basically a if expr1 then expr2 else expr3
char lower2(char c){
    c = (c >= 'A' && c <= 'Z') ? c + ('a'-'A') : c;
    return c;
}
