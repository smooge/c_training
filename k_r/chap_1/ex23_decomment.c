/*
 * K&R C chapter 1 exercise 23, pg 34
 *
 * Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly. C
 * comments do not nest. 
 * Inspiration is taken from the C Answer Book pg 38-39.
 * Comments are classic C comments and C++
 */

#include <stdio.h>
#include <stdlib.h>

void find_end_comment(void);
void find_end_line(void);
void look_for_comment(int c);
void deal_with_quotes(int c);

int main(){
    int now_c = 0;


    printf("/* Here is a mostly decommented file. */\n");
    while (( now_c = getchar()) != EOF ){
	look_for_comment(now_c);
    }
    return 0;
}

// Go from now until we either reach the end of the line of a newline.
void find_end_line(void){
    int now_c;
    now_c = getchar();
    while (((char) now_c != '\n') && (now_c != EOF)){
	now_c = getchar();
    }
    putchar('\n');
    return;
}

void find_end_comment(void){
    int pre_c, now_c; // the previous and now character read in
    now_c = getchar();
    pre_c = now_c;
    now_c = getchar();

    while ( (char) pre_c != '*' || (char) now_c != '/'){
	// we are still in long form comment.
	pre_c = now_c;
	now_c = getchar();
    }
}

void look_for_comment(int now_c){
    int next_c;

    // ok are we possibly in a comment
    if (now_c=='/'){
	next_c = getchar();
	if (next_c == EOF) {
	    printf("Misparsed file\n");
	    exit(1);
	} else if (next_c == '*') { // we have a long comment
	    find_end_comment();
	} else if (next_c == '/') { // we have eol comment
	    find_end_line();
	} else {
	    putchar(now_c);
	    putchar(next_c);
	}
    } else if ( now_c == '"' || now_c == '\'' ) {
	deal_with_quotes(now_c);
    } else {
	putchar(now_c);
    }
    return;
}

// we have to deal with comments inside of strings as they should not
// be removed.
void deal_with_quotes(int old_c){
    int new_c;

    putchar(old_c);
    while ((new_c = getchar()) != old_c){
	putchar(new_c);
	if (new_c == '\\')
	    putchar(getchar());
    }
    putchar(new_c);
    return;
}
