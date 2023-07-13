## How do you test the example program from Section 1.5.4? 

My testing was fairly simple. I used the Unix wc program as an example
and fed various text files through it. I then used this count program
and checked that the numbers of lines characters and words matched the
count.

## What kinds of input are most likely to uncover bugs if there are any?

To test the limits of the program, I would use a simple text file, then
add a file with UTF-8 characters in it, and then feed the program to
itself. Each of them would uncover a different set of problems.
