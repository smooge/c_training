/*
 * K&R Second Edition, Chapter 2, pg 49 exercise 2-6
 *
 * Write a function `rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int rightrot( unsigned int x, int n );

int main(){

    unsigned int x = 1;
    unsigned int y = ~x;
    unsigned int z = 524288+131072+32768+8192+2048+512+128+32+8+2;
    int n = 0;

    
    printf("Lets look at our starting numbers.\n");
    printf(" X is %x\n",x);
    printf(" Y is %x\n",y);
    printf(" Z is %x\n",z);
    for (n=0; n<=32;n++){
	printf(" * Rotate X %x bits you get %x\n",n,rightrot(x,n));
	printf(" * Rotate Y %x bits you get %x\n",n,rightrot(y,n));
	printf(" * Rotate Z %x bits you get %x\n",n,rightrot(z,n));
    }

    exit(EXIT_SUCCESS);
}

unsigned int rightrot( unsigned int x, int n){
    // Use the way we figured out how to get number of bits in
    // exercise 1.
    const int NUMBITS = (sizeof(int)*CHAR_BIT)-1;

    unsigned int right_bit = (unsigned int) 0;

    // easiest way to do this is take the right most bit and move it
    // to the end.
    while (n-- > 0){
	right_bit = ( x & 1 ) << NUMBITS; // get right most bit and move it to
				  // the left by NUMBITS
	x = x >> 1; // move us one to the right.
	x = x | right_bit; // or the two together and get what we want
    }
    return x;
}
