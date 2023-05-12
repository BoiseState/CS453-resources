#!/bin/gprolog --consult-file

% see: ./pub/plp-code/11_logic/exmp_1135_36/sorting.pl
% see 3rd ed: 567, for an append version of perm

% Now, consider the problem of sorting an array of numbers.
% 
% The input is $a$, a zero-origin array of size $n$ containing
% numbers to sort, at indices 0, 1, $\cdots$, $m-1$, where $m
% \le n$.
% 
% The output is $b$, a zero-origin array of size $m$ such
% that:
% 
% \[
%     \mathit{sort}(a,b,m) \equiv
%     \mathit{perm}(a,b,m) \wedge \mathit{ord}(b,m)
% \]
% 
% \[
%     \mathit{ord}(a,n) \equiv
%     ( \forall i \in \{1,\cdots,n-1\} \mid a[i-1] \le a[i] )
% \]
% 
% \[
%     \mathit{perm}(a,b,n) \equiv
%     (
%         \forall i \in \{0,\cdots,n-1\} \mid
%         \mathit{cnt}(a[i],a,n)=\mathit{cnt}(a[i],b,n)
%     )
% \]
% 
% \[
%     \mathit{cnt}(v,a,n) \equiv
%     \sum_{i=0}^{n-1}
%         \left\{
%           \begin{array}{ll}
%             1 & \mbox{if $a[i]=v$} \\
%             0 & \mbox{otherwise}
%           \end{array}
%         \right.
% \]
% 

srt(A, B) :- perm(A, B), ord(B).

% The definition of cnt/3 will not "work backwards"
% because Prolog arithmetic (is/2) will not work backwards.
% Thus, perm/3 cannot produce permutations, only check them.

perm([], []).
perm(A, [H|T]) :- rmone(H, A, R), perm(R, T).

rmone(V, [V|T], T).
rmone(V, [H|T], [H|R]) :- V\==H, rmone(V, T, R).

%perm(A, B) :- perm(A, A, B), perm(B, A, B).		  

perm([], _, _).
perm([H|T], A, B) :- perm(T, A, B), cnt(H, A, N), cnt(H, B, N).

ord([]).
ord([_|[]]).
ord([I|[J|T]]) :- I=<J, ord([J|T]).

cnt(_, [], 0).
cnt(V, [H|T], N) :- cnt(V, T, R), (V=H -> N is 1+R; N is R).

seq([5,6,1,8,3,7]).

%main :- seq(A), cnt(8, A, N), write(N), nl, halt.
%main :- cnt(2, A, 3), write(A), nl, halt.
%main :- seq(A), ord(A), halt.
%main :- seq(A), perm(A, B), write(B), nl, halt.
%main :- rm(3,[1,3,1,3],B), write(B), nl, halt.
main :- seq(A), srt(A, B), write(B), nl, halt.

:- initialization(main).
