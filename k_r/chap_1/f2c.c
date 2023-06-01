/*
  Sample Fahrenheit to Celsius from K&R C 2nd edition Book.
  Page 9
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int fahr, celsius;
    int lower,upper, step;

    lower = 0;   // Lower limit of temperature table
    upper = 550; // Upper limit
    step = 20;

    fahr = lower;
    printf("Fahrenheit to Celsius Conversion\n");
    while (fahr <= upper) {
	celsius = 5 * ( fahr-32) / 9;
	printf("%d\t=>\t%d\n",fahr,celsius);
	fahr = fahr + step;
    }
    exit(0);
}
