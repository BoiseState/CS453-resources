#!/bin/gprolog --consult-file

:- include('data.pl').

person(Person) :- free(Person,_).

main :- findall(Person, person(Person), People),
        write(People), nl, halt.

:- initialization(main).
