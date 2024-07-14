/*
 * K&R C chapter 1 exercise 24, pg 34
 *
 * Write a program to check a C program for rudimentary syntax errors
 * like unbalanced parenthesis, brackets, and braces. Dont' forget
 * about quotes, both single and double, escape sequences, and
 * comments. (This program is hard if done in full generality.)
 *
 * Inspiration is taken from the C Answer Book pg 35-37.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int comments = 0;
int parens = 0;    // global counter for parenthesis ()
int brackets = 0; // global counter for brackets []
int braces = 0;   // global counter for braces {}
int lines = 0; //
int characters = 0; //

int find_end_comment(void);  // function to walk through a /* */ comment
int find_end_line(void); // function to walk through a //
int deal_with_quotes(int c); // deal with various quotes.
int my_getchar(void); // a wrapper on getchar
void count_text(int c); // deal with regular text.
void check_negative(void);
void summarize(void); // count all the code to see that we have matched items.

int main(){
    int c,d = 0; // general purpose char

    c = my_getchar();
    while (c  != EOF){
        // Start by looking for comments
        if (c == '/'){
            d = my_getchar();
            switch(d) {
            case '/':
                d=find_end_line();
                break;
            case '*':
                d=find_end_comment();
                break;
            case EOF: // if we had an EOF already we have a problem.
                break;
            default:
                count_text(d);
            }
        } else if (c == '\'' || c == '"' ){
            d = deal_with_quotes(c);
        } else
            count_text(c);
        if (d != EOF) {
            c = my_getchar();
        } else {
            c = d;
        }
        check_negative();
    }

    // ok see if our counts are all 0;
    summarize();
    return 0;
}

int find_end_comment(void){
    int pre_c, now_c; // the previous and now character read in
    extern int comments;
    comments = 1;
    now_c = my_getchar();
    pre_c = now_c;
    now_c = my_getchar();

    while (( (char) pre_c != '*' || (char) now_c != '/') && (now_c !=EOF)){
        // we are still in long form comment.
        pre_c = now_c;
        now_c = my_getchar();
    }
    if (now_c != EOF)
	comments=0;
    return now_c;
}

// Go from now until we either reach the end of the line of a newline.
int find_end_line(void){
    int now_c;
    now_c = my_getchar();
    while (((char) now_c != '\n') && (now_c != EOF)){
        now_c = my_getchar();
    }
    return now_c;
}

int deal_with_quotes(int c){
    int d = 0; 
    while((d = my_getchar()) != c){
        if (d == '\\'){
            my_getchar(); // ignore escape sequences
        }
        if (d == EOF) break; // break out of while loop.
    }
    return d;
}

void count_text(int c){
    extern int parens, brackets, braces;

    switch(c){
    case '(':
        parens++;
        break;
    case ')':
        parens--;
        break;
    case '[':
        brackets++;
        break;
    case ']':
        brackets--;
        break;
    case '{':
        braces++;
        break;
    case '}':
        braces--;
        break;
    default:
        break;
    }
    return;
}

void check_negative(void){
    extern int parens, brackets, braces;
    extern int lines;
    if (parens < 0 ){
        printf("Unbalanced right parenthesis ). Possibly on line %d\n", lines);
	parens = 0;
    }
    if (brackets < 0 ){
        printf("Unbalanced right brackets ]. Possibly on line %d\n", lines);
	brackets = 0;
    }
    if (braces < 0 ) {
        printf("Unbalanced right braces }. Possibly on line %d\n", lines);
	braces = 0;
    }
    return;
}

void summarize(void){
    extern int parens, brackets, braces;
    extern int lines, characters;
    if (comments != 0)
	printf("File ended inside of comment. \n");
    if (parens > 0 )
        printf("Unbalanced left parenthesis (.\n");
    if (brackets > 0 )
        printf("Unbalanced left brackets [.\n");
    if (braces > 0 )
        printf("Unbalanced left braces {.\n");
    printf("We found %d characters and %d lines.\n",characters, lines);
    return;
}

int my_getchar(void){
    extern int lines, characters;
    int c=0;
    c = getchar();
    characters++;
    if (c == '\n')
        lines++;
    return c;
}
