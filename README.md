
## Natural-Deduction-Proof-Checker
2-1, CS-F214, Logic in CS Assignment II. We have to make
 a framework to check the
proof of ```natural deduction``` in Propositional Logic/ Predicate Logic.

### Allowed Proof Rules
- Premise
- AND introduction/elimination
- OR introduction
- IMPLIES elimination
- MT

### Definitions
<statement> ::= p | ¬p | ¬(<statement>) | (<statement> ∧ <statement>) | (<statement> ∨ <statement>) |
(<statement> → <statement>)
<rule> ::= ∧i | ∧e1 | ∧e2 | ∨i1 | ∨i2 | →e |P

### Input
First line:
n (number of statements)
Next n lines:
<statement>/< rule >[ /line1[ /line2 ] ] (parameter in [] is optional whose existence will be determined
by < rule > )

### Output
Valid Proof (or) Invalid Proof

### Assumptions
1. Line number starts from 1.
2. <statement> should be ```perfectly parenthesized```, e.g. ((a ∧ b) ∧ c) is valid, (a ∧ b) ∧ c is invalid, ((a ∧
b)) is invalid, (a ∧ b) is valid, (a ∧ b ∧ c) is invalid, p is valid, (p) is invalid.
3. ¬ can be succeeded by a literal or ‘(‘ only.


