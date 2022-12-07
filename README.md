
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

### Screenshots

<img width="584" alt="Logic1111" src="https://user-images.githubusercontent.com/97559428/205979908-fd1fa78f-0bb8-47c2-86aa-623d601ac990.png">


## Authors

- [Pavas Garg](https://www.github.com/pavas23)
- [Saksham Bajaj](https://github.com/SakshamBajaj18)
- [Murari Karthik](https://github.com/Murari-Karthik)
- [Amit Kolasani](https://github.com/AmitKolasani)
