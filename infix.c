/* $Id: infix.c,v 1.8 1988/10/17 07:13:38 burton Exp burton $ */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* stack for operators & ptr into it*/
char op_stack[100];
char *sp = op_stack;

/* precedence for operator: higher is better */
int prec(op)
char op;
{
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        printf("bad op at %c\n", op);
        exit(1);
    }
}

/* process operator: add to op stack and/or out queue. */
char *handle_op(token, out)
char token;
char *out;
{
    int op_prec;

    /* "(": put "("" on stack to find when hits ")". */
    if (token == '(') {
        *sp++ = '(';
    }

    /* ")": pop and do work up til last "("". */
    else if (token == ')') {
        while (*--sp != '(') {
            *out++ = *sp;
        }
    }

    /* other operator: do stacked higher-prec work. */
    else {
        op_prec = prec(token);
        while (sp > op_stack &&
               *(sp - 1) != '(' && prec(*(sp - 1)) >= op_prec) {
            *out++ = *--sp;
        }
        *sp++ = token;
    }

    return out;
}

/* given infix expn and out buffer, fill buffer with postfix expn */
void infix(expn, out)
char *expn, *out;
{
    int len = strlen(expn);
    int i;
    for (i = 0; i < len; i++) {
        char token = expn[i];
        if (isdigit(token)) *out++ = token;
        else out = handle_op(token, out);
    }
    while (sp > op_stack) {
        *out++ = *--sp;
    }
    *out = '\0';
}
