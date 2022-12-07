## ConjunctionElimination

## Algorithm
>
> - We check whether it has a conjuction elimination rule or not by checking if the 'e' appears at an index which is less than the length of proof string.
> - Then we store the proof part before the slash in a string named ```result```.
> - We then find whether the elimination is of type 1 or type 2 by typecasting the char to int and subtracting 48 which is the ascii value of '0'.
> - Followed by finding the line number and match the result from the proof lines.
> - As the line number can contain more than one digit so we store it in a string named ```stringlineNumber``` and convert it to integer using ```stoi``` function.
> - Make two different strings for left part occuring  before '^' and right part occuring after '^' in the original line corresponding to the index given by ```stringlineNumber```.
> - Make object of stack class for finding the left and right parts.
> - Now we push the elements in the stack in reverse order from a string named ```conjunctionLine``` which is the line on which ConjunctionElimination rule is applied. 
> - The Part  before the ^ symbol  is iterated while top element of stack is not '^'. If top element of stack is '(' then store them in the leftpart string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - We also need to check for multiple brackets if left part contains multiple brackets and has '^' symbol before the actual '^' so we count the number of opening brackets.
> - Now we remove '^' symbol
> - And similar to the left part string, we add elements to right part string until the stack is empty.
> - We use coniditional statement and return true if leftPart string is same as ```result``` for type ```1``` Conjunction Elimination else false is returned and return true if rightPart is equal to result for Conjunction Elimination of type ```2``` else fasle is returned. <br><br>

## Time Complexity

> In this algorithm we are traversing once over all the elements present in the string so time complexity will be ```O(n)```.

## Space Complexity

> As we are making stack of size n so space complexity will be ```O(n)```.