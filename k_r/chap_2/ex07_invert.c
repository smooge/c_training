/*
 * K&R Second edition, Chapter 2 pg 49 exercise 2-7
 *
 * Write a function setbits(x,p,n,y) that returns x with the n bits
 * that begin at position p set to the rightmost n bits of y, leaving
 * the other bits unchanged.
 *
 * This section is titled bitwise operators and goes into a short set
 * of instructions on `^ | & << >> ~`. It comes with one routine
 * getbits which I will include in this sample as it better explains
 * what setbits should look like.
 *
 */

#include <stdio.h>
#include <stdlib.h>


unsigned int getbits( unsigned int x, int p, int n );
unsigned int invert( unsigned int x, int p, int n );

int main(){

    unsigned int x = 0;
    unsigned int y = ~x;
    unsigned int z = 0;
    int p = 16;
    int n = 0;

    
    printf("Let us get some bits.\n");
    printf(" X starts off at %x\n",x);
    printf(" Y is %x\n",y);
    for (n=0; n<=p;n++){
	z=getbits(y,p,n);
	printf(" * %x bits at position %x of %x is %x\n",n,p,y,z);
    }

    printf("Now let us invert some bits.\n");
    printf(" X starts off at %x\n",x);
    printf(" Y is %x\n",y);

    for (n=0; n<=p;n++){
	z = invert(x,p,n);
	printf(" * invert %x bits at position %x of %x makes it %x\n",n,p,x,z);
	z = invert(y,p,n);
	printf(" * invert %x bits at position %x of %x makes it %x\n",n,p,y,z);
    }
    
    exit(EXIT_SUCCESS);
}

// getbits: get n bits from position p
unsigned int getbits( unsigned int x, int p, int n ){
    unsigned int mask = (unsigned int) 0;
    int move = 0;
    // comments from text in book
    move = ( p + 1 - n); // x >> (p+1-n) moves the field to the right
			 // end of the word. 

    // ~mask is all 1-bits;
    // ~mask << n shifts it n bits to the left and leaves zeros in the
    // rightmost n bits. A second ~ complements that and converts all
    // the 0's to 1s for a mask.
    mask = ~(~mask << n );

    // now we right shift x by move bits and mask off via mask
    // & finishes off the job.    
    return ( x >> move ) & mask;
}

unsigned int invert(unsigned int x, int p, int n){
    unsigned int mask = (unsigned int) 0;
    int move = 0;
    unsigned int z =  (unsigned int) 0;
    // comments from text in book
    move = ( p + 1 - n); // x >> (p+1-n) moves the field to the right
			 // end of the word. 

    // ~mask is all 1-bits;
    // ~mask << n shifts it n bits to the left and leaves zeros in the
    // rightmost n bits. A second ~ complements that and converts all
    // the 0's to 1s for a mask.
    mask = ~(~mask << n );

    z = x ^ (mask << move);
    return z;
}
