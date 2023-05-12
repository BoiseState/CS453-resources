#!/bin/gprolog --consult-file

:- include('data.pl').
:- include('uniq.pl').

person(Person) :- free(Person, _).

main :- findall(Person, person(Person), People),
        uniq(People, Uniq),
        write(Uniq), nl, halt.

:- initialization(main).
