/*
 * K&R Second Edition, Chapter 2, pg 51 exercise 2-9
 *
 * 
 * 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int bitcount1( unsigned int x);
int bitcount2( unsigned int x);

int main(){

    unsigned int x = 1;
    unsigned int y = ~x;
    unsigned int z = 524288+131072+32768+8192+2048+512+128+32+8+2;
    
    printf("Lets look at our starting numbers.\n");
    printf(" X is %x and has %x bits\n",x, bitcount1(x));
    printf(" Y is %x and has %x bits\n",y, bitcount1(y));
    printf(" Z is %x and has %x bits\n",z, bitcount1(z));
    printf(" X is %x and has %x bits\n",x, bitcount2(x));
    printf(" Y is %x and has %x bits\n",y, bitcount2(y));
    printf(" Z is %x and has %x bits\n",z, bitcount2(z));

    exit(EXIT_SUCCESS);
}

// This is taken directly from pg 50 of K&R C
int bitcount1(unsigned int x){
    int bits = 0;
    for (; x != 0; x>>= 1){
	if (x & 1)
	    bits++;
    }
    return bits;
}

// This is taken directly from pg 50 of K&R C
int bitcount2(unsigned int x){
    int bits = 0;
    // this combines the test and the move of bits.
    for (; x != 0; x &= x-1){
	    bits++;
    }
    return bits;
}
