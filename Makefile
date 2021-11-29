# $Id: Makefile,v 1.6 1988/10/17 07:11:18 burton Exp burton $

# Infix and postfix calculator assignment CS102.
# W. Joel Burton : E-mail: thatboy@edu!harvard!husc
#
# Must be run with GNU Project's make on SunOS.
# Doesn't work on VAX/VMS, but you can build with
#   cc -o calc calc.c postfix.c infix.c

CC = gcc
CFLAGS = -Wall
# uncomment to use GNU debugger
# CFLAGS = -Wall -g

calc:: infix.o postfix.o calc.o
postfixcalc:: postfix.o postfixcalc.o
infix2post:: infix.o infix2post.o

all: postfixcalc infix2post calc

test: calc
	sh test.sh
tar: clean
	tar cf code.tar *
clean:
	rm -f calc postfixcalc infixcalc *.o *~ code.tar
