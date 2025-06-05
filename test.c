#include <stdio.h>

/* This is a standard comment */

int main() {
    printf("Hello, world!\n"); /* Print greeting */
    
    /* Comment before declaration */
    int x = 42;  /* Variable x initialized */

    char *str = "This is not a comment: /* not a real comment */";
    
    char ch = '/';  /* A char with slash */
    char *quote = "String with escaped quote: \\\" and a slash: /";

    /*
    Multi-line comment
    still going...
    done now.
    */

    int a = 5;  /* nested? /* inner */ still outer */

    /* Unclosed comment
    int b = 10;

    printf("This line is inside what looks like a comment\n");

    return 0;
}
