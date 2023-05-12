notin(_, []).
notin(V, [H|T]) :- V \= H, notin(V, T).

in(V, [V|_]).
in(V, [_|T]) :- in(V, T).

set([]).
set([H|T]) :- notin(H, T), set(T).

has([], _).
has([H|T], L) :- in(H, L), has(T, L).

uniq(L, U) :- has(L, U), has(U, L), set(U).
