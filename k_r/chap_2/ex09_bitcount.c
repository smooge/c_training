/*
 * K&R Second Edition, Chapter 2, pg 51 exercise 2-9
 *
 * In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1 bit in x. Explain why. Use this observation to write a
 * faster version of bit-count.
 *
 * The reason requires understanding what a 'two-s complement' number
 * system means.  A one's complement system seems to be that the
 * negative numbers are the bit reverse of the positive so you have in
 * a 4 bit system.
 * 0000 = +0 / 1111 = -0
 * 0001 = +1 / 1110 = -1
 * 0010 = +2 / 1101 = -2
 * 0011 = +3 / 1100 = -3
 * 0100 = +4 / 1011 = -4
 *
 * A two's complement system instead uses just the left most bit to
 * indicate the sign of a number:
 * 0000 = 0 /
 * 0001 = 1 / 1111 = -1
 * 0010 = 2 / 1110 = -2
 * 0011 = 3 / 1101 = -3
 * 0100 = 4 / 1100 = -4
 * 0101 = 5 / 1011 = -5
 * 0110 = 6 / 1010 = -6
 * 0111 = 7 / 1001 = -7
 *          / 1000 = -8
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
