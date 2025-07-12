#include <stdio.h>

/* This is a block comment
   that spans multiple lines */

int main() {
    printf("Hello, world!\n"); /* Print a message to the user */

    int x = 5; /* Initialize x */
    int y = 10; /* Initialize y */

    /* This is a multi-line comment
    that looks like it might contain
    /* nested comments */ which are not valid in standard C */

    printf("This is not a comment: /* hello */\n"); /* This is a real comment */

    /* Comment at end of file with no newline */
    return 0;
} /* Final comment */
