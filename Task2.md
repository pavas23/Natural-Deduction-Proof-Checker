## DisjunctionIntroduction

## Algorithm
>
> - The statements in the proof are taken as input which are to be verified for Disjunction(OR) Introduction
> - Make two different strings for left part occuring  before '+' and right part occuring after '+'
> - Make stack for storing the proof of disjunctionIntroduction rule.
> - Push the proof line in reverse order in stack
> - The  leftPart is before the '+' symbol and is iterated while top element of stack is not '+'. If top element of stack is '(' then store them in the ```leftpart``` string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - We also need to check for multiple brackets if left part contains multiple brackets and has '+' symbol before the actual '+' so we count the number of opening brackets.
> - After this, we pop out '+' symbol
> - And now for the right part string, pop out until stack is not empty
> - We now check whether it is i1 or i2 i.e 'OR' introduction 1 or 'OR' introduction 2.
> - We now find the index where line number is present
> - As the line number can contain more than one digit so we store it in a string named ```stringlineNumber``` and convert it to integer using ```stoi``` function.
> - Now if the type of disjunction introduction is 1 then left part should match with the proof line corresponding to the line number entered, else if it is type 2 then right part should match with the proof line corresponding to the line entered in the proof statement.
> - If the above thing matches then function returns true otherwise it will return boolean false. <br><br>

## Time Complexity

> In this algorithm we are traversing once over all the elements present in the string so time complexity will be ```O(n)```.

## Space Complexity

> As we are making stack of size n so space complexity will be ```O(n)```.