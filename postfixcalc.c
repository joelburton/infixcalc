/* $Id: postfixcalc.c,v 1.2 1988/10/17 07:11:18 burton Exp burton $ */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/* calculates postfix expression. */
int main(argc, argv)
int argc;
char *argv[];
{
    printf("%d\n", postfix(argv[1]));
    exit(0);
}
