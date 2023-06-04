/*
  Program from K&R 2nd edition pg 16. Meant to copy input to output.
 */

#include <stdio.h>  // needed for printf
#include <stdlib.h> // needed for exit

int main(){
    int c; // character to be manipulated
    while ((c = getchar()) != EOF) {
	putchar(c);
    }
    printf("%d - at EOF\n", c);
    printf("%d is EOF\n", EOF);
    exit(0);
}
