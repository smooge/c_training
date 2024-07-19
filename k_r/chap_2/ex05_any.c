/*
 * K&R 2nd edition, chapter 2, exercise 2-5, pg 48
 *
 * Wrie the function any(s1,s2) which returns the first location in
 * the string s1 where any character from the string s2 occurs or -1
 * if s1 contains no characters from s2. (The standard library
 * function strpbrk does the same job but returns a pointer to the
 * location.)
 *
 * For this I will implement the squeeze from page 47, and then
 * implement its larger version as squash.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

int any(char s1[], char s2[]);

int main(){
    int where = 0;
    char s1[50];
    char s2[10] = ".zxq"; // reverse order of noncommon letters
    char s3[10] = "?ZXQ"; // characters we shouldnt find.
    const char *tmp = "The quick brown fox jumped over the lazy dog.";

    // copy this string into our test arrays
    strlcpy(s1,tmp,sizeof s1);

    printf("We are looking for any character in %s in the string\n  \"%s\"\n",s2,s1);
    where = any(s1,s2);
    if (where >= 0 )
	printf("We found %c at location %d\n",s1[where],where);
    else
	printf("We did not find any characters\n");
    printf("We are now looking for any character in %s in the string\n  \"%s\"\n",s3,s1);
    where = any(s1,s3);
    if (where >= 0 )
	printf("We found %c at location %d\n",s1[where],where);
    else
	printf("We did not find any characters\n");
    
    exit(EXIT_SUCCESS);
}

// Function will search through the string s2 for characters and try
// to find the 'first' one in the string.
int any(char s1[], char s2[]){
    int ret = -1; // assume we found nothing
    int i = 0;
    int j = 0;
    for (i=0; s2[i] != '\0' && ret == -1 ; i++){
	j=0;
	while (s1[j] != s2[i] && s1[j] != '\0')
	    j++;
	if (s1[j] != '\0')
	    ret = j;
    }
    return ret;
}
