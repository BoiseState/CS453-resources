#!/bin/gprolog --consult-file

% Guiseppe Peano arithmetic [1890]
add(0, M, M).
add(s(M), N, s(G)) :- add(M, N, G).

lt(0, s(_)).
lt(s(M), s(N)) :- lt(M, N).

div(G, G).
div(N, s(G)) :- lt(s(G), N), add(M, s(G), N), div(M, s(G)).

cd(A, B, G) :- div(A, G), div(B, G).

max(D, [], D).
max(D, [H|T], G) :- lt(D, H) -> max(H, T, G); max(D, T, G).

gcd(A, B, G) :- findall(CD, cd(A,B,CD), CDS), max(0, CDS, G).

num8(N)  :- N=s(s(s(s(s(s(s(s(0)))))))).
num12(N) :- N=s(s(s(s(s(s(s(s(s(s(s(s(0)))))))))))).
num15(N) :- N=s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(0))))))))))))))).
num25(N) :- N=s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(0))))))))))))))))))))))))).

main :- num15(A), num25(B), gcd(A, B, G),
	write('gcd(15,25,G)='), write(G), nl, halt.

:- initialization(main).
