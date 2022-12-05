## DisjunctionIntroduction

## Algorithm
>
> - The statements in the proof are taken as inout which are to be verified for Conjnction(AND) Introduction
> - Make two different strings for left part occuring  before '^' and right part occuring after '^'
> - Make stack for storing the proof of conjunctionIntroduction
> - Push the proof in reverse order in stack
> - The  leftPart is before the '+' symbol and is iterated while top element of stack is'nt '+'. If top element of stack is '(' then store them in the leftpart string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - After this, we pop out '^' symbol
> - And now for the right part, pop out until stack is not empty
> - We now checke whether its i1 or i2
> - We now find the index where line numbers are present
> - As line1 and line2 are initially characters so we typecast to int and subtract 48 which is ascii value of 0
> - Now both left and right part should be present in premise

## PARGIIII DO FROM HERE, IG THERE ARE SOME ERRORS HERE IN THE COMMENTS U HAVE WRITTEN, KINDLY LOOK AFTER IT
