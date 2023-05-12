#!/bin/gprolog --consult-file

% This program shows how to "unit test" a predicate, named foo.
% The first foo fact prevents an "existence_error".
% The second foo fact models the predicate under test,
% which might evaluate to true or false, 

foo :- false.
%foo :- true.

main :- (foo,
	 write('foo is true');
	 write('foo is not true')),
	nl, halt.

:- initialization(main).
