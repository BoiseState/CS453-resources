#!/bin/gprolog --consult-file

:- include('data.pl').

earlytime(time(Hour, Minute)) :- Hour=<8, Minute=<59.

early(Person) :- free(Person, slot(Time, _)),
                 earlytime(Time).

main :- findall(Person, early(Person), People),
        write(People), nl, halt.

:- initialization(main).
