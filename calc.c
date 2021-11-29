/* $Id: calc.c,v 1.2 1988/10/17 07:13:32 burton Exp burton $ */

#include <stdio.h>
#include "calc.h"

/* calculates infix expression. */
int main(argc, argv)
int argc;
char *argv[];
{
    /* queue for building up postfix expn. */
    char out[100];

    infix(argv[1], out);
    printf("%d\n", postfix(out));
    return 0;
}
