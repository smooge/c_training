/*
 * K&R Second edition, Chapter 2 pg 49 exercise 2-6
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
unsigned int setbits( unsigned int x, int p, int n, unsigned int y );

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

    printf("Now let us set some bits.\n");
    printf(" X starts off at %x\n",x);
    printf(" Y is %x\n",y);

    for (n=0; n<=p;n++){
	z = setbits(x,p,n,y);
	printf(" * %x bits at position %x of %x makes it %x\n",n,p,x,z);
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

// This one broke me so I am deriving the answer from the version
// printed in The C Answer Book Chapter 2, pg 51. The version they
// give is a 1-liner but I needed to break its logic down long form to
// make sure I GOT masking.

unsigned int setbits( unsigned int x, int p, int n, unsigned int y ){
    unsigned int mask1 = (unsigned int) 0;
    unsigned int mask2 = (unsigned int) 0;
    int move = 0;

    // this code is mainly needed because I want to walk through these
    // steps and possibly look at original versions in case of
    // debugging. 
    unsigned int x1 =  (unsigned int) 0;
    unsigned int y1 =  (unsigned int) 0;
    unsigned int z =  (unsigned int) 0;
    
    // ~mask is all 1-bits
    // ~mask << n shifts it n bits to the left and leaves zeros in the
    // rightmost n bits. A second ~ complements that and converts all
    // the 0's to 1s for a mask.
    mask1 = ~(~mask1 << n);
    // mask2 is the opposite of mask1 and flips 1's and 0's to
    // opposite. 
    mask2 = ~(mask1);

    move = (p+1-n);  // x >> (p+1-n) moves the field to the right
    
    // shifts these n 1 bits to position p and
    mask1 = (mask1 << move);
    // shifts these n 1 bits to position p
    mask2 = (mask2 << move);

    // we AND x with mask2 to clear the n bits of x at position p.
    x1 = x & mask2;

    //  we AND y with mask1 to select the rightmost n bits of y at
    //  position p. 
    y1 = y & mask1;

    // we OR x1 and y1 to set the n bits of x to the rightmost n bits
    // of y.
    z = x1 | y1;

    // we return this.
    return z;
}
