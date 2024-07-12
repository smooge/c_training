/*
 * K&R C chapter 1 exercise 22, pg 34
 *
 * Write a program to "fold" long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the
 * n-th column of input. Make sure your program does something
 * intelligent with very long lines, and if there are no blanks or
 * tabs before the specified column.
 */

#include <stdio.h>  // needed for printf
#include <stdlib.h> // needed for exit

#define MAXTABS 72
#define TABSIZE 8



int main(){
    int c=0; // variable to store getchar output
    int col; // variable for current column

    exit(EXIT_SUCCESS);
}
