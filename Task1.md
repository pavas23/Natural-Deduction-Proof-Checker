## ConjunctionIntroduction

## Algorithm
>
> - The statements in the proof are taken as input which are to be verified for Conjunction(AND) Introduction
> - Make two different strings for left part occuring  before '^' and right part occuring after '^'
> - Make stack for storing the proof line of conjunctionIntroduction
> - Push the proof in reverse order in stack
> - The  leftPart is before the ^ symbol and is iterated while top element of stack is not '^'. If top element of stack is '(' then store them in the leftpart of string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - We also need to check for multiple brackets if left part contains multiple brackets and has '^' symbol before the actual '^' so we count the number of opening brackets
> - After this, we pop out '^' symbol
> - And now for the right part,store the remaining elements of stack in rightPart string and pop out until stack is not empty
> - We now need to find the index where line numbers are present
> - As the line numbers can be more than single digit also, so we store the first line number in a string named ```stringlineNumber1``` and other line number in a string named ```stringlineNumber2```, as they both are in string datatype we convert them to integer using ```stoi``` function.
> - Now both left and right part should be present in one of the proofLines array.
> - If now the original left and right part is equal to the corresponding left and right string obtained then boolean true is returned, otherwise false <br><br>
> 

## Time Complexity

> In this algorithm we are traversing once over all the elements present in the string so time complexity will be ```O(n)```.

## Space Complexity

> As we are making stack of size n so space complexity will be ```O(n)```
