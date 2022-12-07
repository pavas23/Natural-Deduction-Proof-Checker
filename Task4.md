## ImplicationElimination

## Algorithm

>
> - The statements in the proof are taken as input which are to be verified for Implication Elimination 
> - We initially find the index of slash and index of Implication symbol
> - We check whether the rule is implies elimination or not by verifying that index of implication symbol is less than length of proof and store elements in a string named ```result``` until slash is reached.
> - Follwing it, We find Line Numbers.
> - First line number is the implies statement in the above proof lines and second line number corresponds to the left Part in the implies statement.
> - As the line numbers can be more than single digit also, so we store the first line number in a string named ```stringlineNumber1``` and other line number in a string named ```stringlineNumber2```, as they both are in string data type we convert them to integer using ```stoi``` function.
> - Find the left part and right part of the implies statement.
> - Elements are pushed in stack in reverse order.
> - The Part  before the > symbol  is iterated while top element of stack is not '>'. If top element of stack is '(' then store them in the leftpart string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - We also need to check for multiple brackets if left part contains multiple brackets and has '>' symbol before the actual '>' so we count the number of opening brackets.
> - Now we remove '>' symbol
> - And similar to the left part string, we add elements to right part string until stack is empty.
> - Now match the left part of the implies statement with the statement given by ```stringlineNumber2```.
> - We find the part of the givenLeftPart before the slash and make newGivenLeftPart string.
> - If leftpart obtained from implies statement is same as the newGivenLeftPart string and If result is same as right part, then true is returned and if any of above conditions fail, we return false. <br><br>

## Time Complexity

> In this algorithm we are traversing once over all the elements present in the string so time complexity will be ```O(n)```.

## Space Complexity

> As we are making stack of size n so space complexity will be ```O(n)```.