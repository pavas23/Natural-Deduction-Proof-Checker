## ModusTollens

## Algorithm
>
> - We start by finding the index of MT
> - We check whether the rule is Modus Tollens or not by verifying that index of MT symbol is less than length of proof and store elements till index of MT symbol is result string.
> - The find the line number now in which premises for MT are present
> - We now find the left and right parts of the implication statement
> - Find index of slash in Implies statement and push the elements in stack in reverse order until the index of slash in Implies statement we have found.
> - The Part  before the > symbol  is iterated while top element of stack is'nt '>'. If top element of stack is '(' then store them in the leftpart string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - Now we remove '>' symbol
> - And similar to the left part string, we add elements to right part string.
> - We now find the ~psi give by lineNumber 2
> - We store new Negation of Right part in a string which stores the negation of right part we got from lineNumber 2 until the occurence of slash is negation of right part.
> - we add '~' to the right part string and to left part string in new respective strings
> - If the string having new negation of right part and new negation of left part is exactly same as right part of string with added suffix of '~' and left part of string with added suffix of '~' respectively, then true is returned. If any of abv conditions fail, then false is returned.