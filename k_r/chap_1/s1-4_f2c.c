/*
  K&R 2nd edition, pg 13 for example.
  Program to use a for loop to do similar work as f2c.

  Add in a reverse loop to go from 300 to 0.
*/

#define LOWER -40
#define UPPER 300
#define STEP  20

#include <stdio.h>
int main(){
    int fahr;

    printf("Fahrenheit to Celsius Conversion\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP )
	printf("%3d\t=>\t%6.1f\n",fahr,(5.0/9.0)*(fahr-32));
   
    printf("\nReverse Fahrenheit to Celsius Conversion\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP )
	printf("%3d\t=>\t%6.1f\n",fahr,(5.0/9.0)*(fahr-32));

}
