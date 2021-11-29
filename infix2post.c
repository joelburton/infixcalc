/* $Id: infix2post.c,v 1.4 1988/10/17 07:14:14 burton Exp burton $ */

#include <stdio.h>
#include "calc.h"

/* queue for output expr */
char out[100];

/* converts infix expression to postfix. */
int main(argc, argv)
char argc;
char *argv[];
{
    infix(argv[1], out);
    puts(out);
    return 0;
}
