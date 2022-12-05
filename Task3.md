## ConjunctionElimination

## Algorithm
>
> - Initially we store the result in a string
> - We check whether it has a conjuction elimination rule or not
> - We then find whether the elimination is of type 1 or type 2
> - Followed by finding the line number and match the result from the proof lines
> - Make two different strings for left part occuring  before '^' and right part occuring after '^'
> - Make object of stack class
> - We now push the elements in conjunction line elements until the index of slash(we find index of slash prior to this) to stack
> - The Part  before the ^ symbol  is iterated while top element of stack is'nt '^'. If top element of stack is '(' then store them in the leftpart string and pop it out from stack until the top element becomes ')', else just add top element of stack to left string and then pop it from stack.
> - Now we remove '^' symbol
> - And similar to the left part string, we add elements to right part string.
> - We use coniditional statement and return true if leftpart string is same as result for type 1 Conjunction Elimination else false is returned and return true if right part is equal to result for Conjunction Elimination of type 2 else fasle is returned.
