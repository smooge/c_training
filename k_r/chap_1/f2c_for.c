/*
  K&R 2nd edition, pg 13 for example.
  Program to use a for loop to do similar work as f2c.
*/

#include <stdio.h>
main(){
    int fahr;
    printf("Fahrenheit to Celsius Conversion\n");
    for (fahr = 0; fahr <= 300; fahr +=20 )
	printf("%3d\t=>\t%6.1f\n",fahr,(5.0/9.0)*(fahr-32));

}
