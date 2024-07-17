/*
  Exercise 02-01 from K&R 2nd edition pg. 37

  Write a program to determine the ranges of char, short, int and long
  variables, both signed and unsigned, by printing appropriate values
  from standard headers and by direct computation. Harder if you
  compute them: determine the ranges of the various floating point
  values.

  Variables to be used are taken from:
    https://en.wikipedia.org/wiki/C_data_types
  
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void print_values(char c[], signed long long int smin, signed long long int smax, unsigned long long int umin, unsigned long long int umax);

int main(){
    printf("==== Lets print out values of built in types ====\n\n");
    // Char
    printf("A char is defined to have  %d bits\n", CHAR_BIT);
    print_values("short", CHAR_MIN, CHAR_MAX, 0, UCHAR_MAX);

    // Short
    printf("A short is defined to have  %lu bits\n", sizeof(short)*CHAR_BIT);
    print_values("short", SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);

    // Int
    printf("An integer is defined to have  %lu bits\n", sizeof(int)*CHAR_BIT);
    print_values("integer", INT_MIN, INT_MAX, 0, UINT_MAX);

    // Long
    printf("A long is defined to have  %lu bits\n", sizeof(long)*CHAR_BIT);
    print_values("integer", LONG_MIN, LONG_MAX, 0, ULONG_MAX);

    // Long Long
    printf("A long-long is defined to have  %lu bits\n", sizeof(long long)*CHAR_BIT);
    print_values("integer", LLONG_MIN, LLONG_MAX, 0, ULLONG_MAX);

    // Float
    printf("A float is defined to have  %lu bits\n", sizeof(float)*CHAR_BIT);
    printf("A float's minimum is %g\n",FLT_MIN);
    printf("A float's true minimum is %g\n",FLT_TRUE_MIN);
    printf("A float's maximum is %g\n",FLT_MAX);
    printf("\n");

    // Double
    printf("A double is defined to have  %lu bits\n", sizeof(double)*CHAR_BIT);
    printf("A double's minimum is %g\n",DBL_MIN);
    printf("A double's true minimum is %g\n",DBL_TRUE_MIN);
    printf("A double's maximum is %g\n",DBL_MAX);
    printf("\n");

    // Long Double
    printf("A long double is defined to have  %lu bits\n", sizeof(long double)*CHAR_BIT);

    
    exit(EXIT_SUCCESS);
}

void print_values(char c[], signed long long int smin, signed long long int smax, unsigned long long int umin, unsigned long long int umax){
    // Signed 
    printf("Signed %s minimum: %lld\n", c, smin);
    printf("Signed %s maximum: %lld\n", c, smax);
    // Unsigned
    printf("Unsigned %s minimum: %llu\n", c, umin);
    printf("Unsigned %s maximum: %llu\n", c, umax);
    printf("\n");

    
}
