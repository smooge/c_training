/* 
 * Program from K&R 2nd edition pg 24-25. Meant to show how functions
 * are to be set up and compiled in a C program. 
 */

#include <stdio.h>
#include <stdlib.h>

/* In K&R you generally declare all functions first and then define
 * them afterwards. In Later C this is not needed anymore and can
 * cause warnings or errors. Use a static before the declaration
 * removes that warning but also means it can't be used outside of
 * this program. 
 */
static int power(int base, int nth);

int main(){
    int i;

    printf("%d %d %d\n", -1, power(2,-1), power(-3,-1));
    for (i=0; i<=10; i++){
	printf("%d %d %d\n", i, power(2,i), power(-3,i));
    }
    
    exit(EXIT_SUCCESS);
}

/* power: raise base to n-th power: n>=0 */
int power (int base, int nth){
    int i,p = 1;
    for (i = 1; i<=nth; i++){
	p = p * base;
    }
    return p;
}
