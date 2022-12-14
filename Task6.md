## Future Scope

> Throughout the course of this assignment, we were only required to perform the operations:
> -  1) Premise Rule
> -  2) Conjunction Introduction and Elimination
> -  3) Disjunction Introduction
> -  4) Implication Elimination
> -  5) Modus Tollens <br><br>

>
> - These rules form the base for verification and validation of natural deduction proofs, as they are used in almost every proof. However, these are not the only rules which are used. More commonly used rules include Contradictions, Or Eliminations, Assumptions and Implies Introduction.
> - The main issue is to tackle the scope of certain assumptions.
> - We are working under the assumption that a rule that starts with an “assumption” for example the implies introduction rule is used as soon as the scope or the “box” of that rule ends. Hence if an implies introduction box is from lines 5 to 10, we assume its being used in line 11. Hence, when we encounter this rule, we will check the aforementioned box for the validity of the box in its entirety, i.e. whether it follows the definition of the implies introduction rule.
> - As soon as we encounter such a rule, another condition comes into play that lines proved inside the “box” cannot be used outside the box. Hence once we determine what the scope of the box is we invalidate any proof that uses the lines within that scope outside the same.
> - The rules used within a scope of the box will be checked in a line by line basis in a normal fashion where any assumption will in essence behave as a premise. Nested assumptions will give rise to mini scopes under a larger scope which will be dealt with in the same way mentioned.
> - Coming onto the double negation rule, we would take the reference line and check whether the given string is the double negation of the referenced string
> - A contradiction is one of the most useful proof techniques. A rule of not elimination gives rise to a contradiction which we can check in a normal fashion by using the inputted reference lines and checking if they are the negations of each other. This same contradiction can be used in the following line for Rule of Bottom Elimination, i.e. can lead to any statement and can be verified.
> - Using tautologies (Law of excluded middle) is a useful addition in proof rules and can be verified by truth value assignment to the statement and verifying whether the used statement is in-fact a tautology.
> - Therefore, it is not outside the scope of our knowledge to implement the other proof rules. With sufficient effort we can come up with a full-fledged proof of natural deduction checker application similar to ones set up by Kansas university and other colleges by extension of this CS F214 assignment. <br><br><br>

