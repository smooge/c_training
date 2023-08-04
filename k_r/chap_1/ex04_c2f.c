/*
  K&R C 2nd edition pg 13 Exercise 1-4.
  Write a program to print the corresponding Celsius to Farenheit table.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    double fahr, celsius;
    int lower,upper, step;

    lower = -40;   // Lower limit of temperature table
    upper = 240; // Upper limit
    step = 20;

    celsius = (double) lower;
    printf("Celsius to Fahrenheit Conversion\n");
    while (celsius <= (double) upper) {
	fahr = (( 9.0 / 5.0 ) * celsius ) +32.0;
	printf("%3.0f\t=>\t%6.1f\n",celsius,fahr);
	celsius = celsius + (double) step;
    }
    exit(EXIT_SUCCESS);
}
