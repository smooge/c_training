/*
  Program for section 1.5.3 of K&R 2nd edition. Count characters until
  it reaches a end of file marker.
 */

#include <stdio.h>  // needed for getchar
#include <stdlib.h> // needed for exit

main() {
    long nc;

    nc = 0;
    while (getchar() != EOF)
	++nc;
    printf("%ld\n", nc);
    exit(0);
}
