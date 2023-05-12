#!/bin/gprolog --consult-file

% Guiseppe Peano arithmetic [1890]
add(0, M, M).
add(s(M), N, s(G)) :- add(M, N, G).

div(G, G).
div(N, G) :- add(M, G, N), div(M, G).

gcd(A, B, G) :- div(A, G), div(B, G).

num5(s(s(s(s(s(0)))))).
num5(N)  :- N=s(s(s(s(s(0))))).
num8(N)  :- N=s(s(s(s(s(s(s(s(0)))))))).
num12(N) :- N=s(s(s(s(s(s(s(s(s(s(s(s(0)))))))))))).
num15(N) :- N=s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(0))))))))))))))).
num25(N) :- N=s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(0))))))))))))))))))))))))).

main :- num15(A), num25(B), gcd(A, B, G),
	write('gcd(15,25,G)='), write(G), nl, halt.

% backwards
% main :- num25(B), num5(G), gcd(A, B, G),
% 	write('gcd(A,25,5)='), write(A), nl, halt.

:- initialization(main).
