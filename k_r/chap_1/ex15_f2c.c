/*
  K&R 2nd edition, pg 27 exercise 15

  Rewrite the temperature program from section 01.02 to use a function
  for the conversion.

*/

#define LOWER -40
#define UPPER 300
#define STEP  20

#include <stdio.h>
#include <stdlib.h>

static double f2c(double fahren);
static double c2f(double celsius);

int main(){
    int fahr, celsius = 0;

    printf("Fahrenheit to Celsius Conversion\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP )
	printf("%3d\t=>\t%6.1f\n",fahr,f2c((double) fahr));
   
    printf("Celsius to Fahrenheit Conversion\n");
    for (celsius = LOWER; celsius <= UPPER; celsius += STEP )
	printf("%3d\t=>\t%6.1f\n",celsius,c2f((double) celsius));
    exit(EXIT_SUCCESS);
}

double f2c(double fahren){
    double celsius = 0.0;
    celsius = (5.0/9.0)*( fahren - 32.0);
    return celsius;
}

double c2f(double celsius){
    double fahren = 0.0;
    fahren = ((9.0/5.0)*celsius) + 32.0;
    return fahren;
}
