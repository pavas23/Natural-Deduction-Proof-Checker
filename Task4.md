## ImplicationElimination

## Algorithm

>
> - The statements in the proof are taken as inout which are to be verified for Implication Elimination 
> - We initially find the index of slash and index of Implication symbol
> - We check whether the rule is implies elimination or not by verifying that index of implication symbol is less than length of proof and store elements till index of implication symbol is result string.
> - Follwing it, We find the Index of Line Numbers
> - First line number is the implies statement in the above proof lines and second line number corresponds to the phi in the implies statement
> - Find the left part and right part of the implies statement
> - Elements are pushed in stack in reverse order
> - The Part  before the > symbol  is iterated while top element of stack is'nt '>'. If top element of stack is '(' then store them in the leftpart string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - Now we remove '>' symbol
> - And similar to the left part string, we add elements to right part string.
> - Now match the left part of the implies statement with the statement in the given line number 2
> - We find the part of the given LeftPart before the slash and make newGivenLeftPart string.
> - If leftpart is same as the newGivenLeftPart string and If result is same as right part, then true is returned and if any of above both conditions fail, we return false.