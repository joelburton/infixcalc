# $Id: test.sh,v 1.1 1988/10/17 06:22:32 burton Exp burton $

# Tests for Infix and postfix calculator assignment CS102.
# W. Joel Burton : E-mail: thatboy@edu!harvard!husc

TESTS="
1+2
1+2-3*4+5
(1+2-3)*4+5
(1+2)-3*(4+5)
"

for t in $TESTS
do
	us=`./calc $t`
	them=`echo $t | bc`
	if ! test $us = $them 
	then
		echo $t: $us != $them
		exit 1
	fi
done
