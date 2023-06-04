/*
  Program for section 1.5.3 of K&R 2nd edition. Count characters until
  it reaches a end of file marker.
 */

#include <stdio.h>  // needed for getchar
#include <stdlib.h> // needed for exit

int main() {
    double nc;

    for (nc=0; getchar() != EOF; ++nc)
	;
    printf("%f\n", nc);
    exit(0);
}
