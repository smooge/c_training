/*
  Program for section 1.5.3 of K&R 2nd edition. Count characters until
  it reaches a end of file marker.
 */

#include <stdio.h>  // needed for getchar
#include <stdlib.h> // needed for exit

int main() {
    /*
      K&$ moved to float for large numbers, but 64 bit systems have a
      sizable number to work with.
     */
    unsigned long nc = 0; // initialize at declaration

    /* K&R suggested a for loop in their second example. This crammed
       a lot into the one line which can make maintenance horrible.
    */
    while ( getchar() != EOF ){
	++nc;
    }
    printf("%lu\n", nc); // Unsigned long use lu for printing.
    exit(0);
}
