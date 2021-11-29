/* $Id: postfix.c,v 1.3 1988/10/17 07:13:13 burton Exp burton $ */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int math(op, a, b)
char op;
int a, b;
{
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        printf("bad op: %c\n", op);
        exit(1);
    }
}

/* process postfix expn and returns int evaluation. */
int postfix(expn)
char *expn;
{
    int a, b;
    /* working stack & pointer into it. */
    char stack[STACK_SIZE];
    char *sp = stack;

    for (; *expn != '\0'; expn++) {
        if (isdigit(*expn)) {
            *sp++ = *expn - '0';
        } else {
            b = *--sp;
            a = *--sp;
            *sp++ = math(*expn, a, b);
        }
    }
    return *--sp;
}
