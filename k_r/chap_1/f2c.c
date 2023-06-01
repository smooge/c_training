/*
  Sample Fahrenheit to Celsius from K&R C 2nd edition Book.
  Initial program is on pg 9 and this will update it to pg 12
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    float fahr, celsius;
    int lower,upper, step;

    lower = -40;   // Lower limit of temperature table
    upper = 460; // Upper limit
    step = 20;

    fahr = lower;
    printf("Fahrenheit to Celsius Conversion\n");
    while (fahr <= upper) {
	celsius = 5.0 * ( fahr-32.0) / 9.0;
	printf("%3.0f\t=>\t%6.1f\n",fahr,celsius);
	fahr = fahr + step;
    }
    exit(0);
}
