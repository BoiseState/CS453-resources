#!/bin/gprolog --consult-file

gcd(A, A, A).
gcd(A, B, G) :- B > A, C is B-A, gcd(C, A, G).
gcd(A, B, G) :- A > B, C is A-B, gcd(C, B, G).

main :- gcd(15, 25, G), write('gcd(15,25,G)='), write(G), nl, halt.

:- initialization(main).
