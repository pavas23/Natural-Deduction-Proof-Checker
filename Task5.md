## ModusTollens

## Algorithm
>
> - We start by finding the index of MT.
> - We check whether the rule is Modus Tollens or not by verifying that index of MT symbol is less than length of proof and store elements till index of MT symbol is reached in a string named ```result```.
> - Then find the line number now in which premises for MT are present.
> - We now find the left and right parts of the implication statement.
> - Find index of slash in Implies statement and push the elements in stack in reverse order until the index of slash in Implies statement is found.
> - The Part  before the '>' symbol  is iterated while top element of stack is not '>'. If top element of stack is '(' then store them in the leftpart string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - We also need to check for multiple brackets if left part contains multiple brackets and has '+' symbol before the actual '+' so we count the number of opening brackets.
> - Now we remove '>' symbol
> - And similar to the left part string, we add elements to right part string until stack is empty.
> - We now find the ```~Ψ``` give by lineNumber2 as implies statement is of the form ```Φ>Ψ```.
> - We store new Negation of Right part in a string which stores the negation of right part we got from lineNumber 2 until the occurence of slash in negation of right part.
> - we add ```'~'``` to the right part string.
> - Now if right Part string after adding ```~``` symbol is same as the string corresponding to ```lineNumber2``` means premises are present then we add ```~``` to leftPart and check whether it is equal to result given in proof string. <br><br>

## Time Complexity

> In this algorithm we are traversing once over all the elements present in the string so time complexity will be ```O(n)```.

## Space Complexity

> As we are making stack of size n so space complexity will be ```O(n)```.