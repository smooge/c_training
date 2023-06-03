/*
  Program from K&R 2nd edition pg 16. Meant to copy input to output.
 */

#include <stdio.h>  // needed for printf
#include <stdlib.h> // needed for exit

int main(){
    int c; // character to be manipulated
    c = getchar();
    while (c != EOF) {
	putchar(c);
	c = getchar();
    }
    exit(0);
}
