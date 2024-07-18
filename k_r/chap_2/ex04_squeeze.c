/*
 * K&R 2nd edition, chapter 2, exercise 2-4, pg 48
 *
 * Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches and character in string s2.
 *
 * For this I will implement the squeeze from page 47, and then
 * implement its larger version as squash.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

void squeeze(char s[], int c);
void squash(char s1[], char s2[]);

int main(){

    char c = 'x';
    char s[50];
    char s1[50];
    char s2[10] = "qbx.";
    const char *tmp = "The quick brown fox jumped over the lazy dog.";

    // copy this string into our test arrays
    strlcpy(s,tmp,sizeof s);
    strlcpy(s1,tmp,sizeof s);
    printf("We will squash %c out of \"%s\"\n",c,s);
    squeeze(s,c);
    printf("We now have \"%s\"\n",s);
    printf("We will squash %s out of \"%s\"\n",s2,s1);
    squash(s1,s2);
    printf("We now have \"%s\"\n",s1);
    exit(EXIT_SUCCESS);
}

// Taken from page 47 this routine will remove the character c from
// the string s.
void squeeze(char s[], int c){
    int i = 0;
    int j = 0;
    for (i = j = 0; s[i] !='\0'; i++){
	if (s[i] !=c)
	    s[j++] = s[i];
    }
    s[j] = '\0'; // close off the string.
}

void squash(char s1[],  char s2[]){
    int k = 0;
    char c = 0;
    // Loop through s2
    for (int i = 0; s2[i] != '\0'; i++){
	c = s2[i];
	k = 0;
	// use same logic from squeeze with different counters
	for (int j=0; s1[j] !='\0'; j++){
	    if (s1[j] !=c)
		s1[k++] = s1[j];
	}
	s1[k] = '\0'; // close off the string.
    }
}

