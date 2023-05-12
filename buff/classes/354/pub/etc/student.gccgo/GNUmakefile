prog:=main

# -fno-require-return-statement

%.pkg: %.go
	gccgo -g -c $(filter %.go,$^)

$(prog):
	gccgo -g -o $@ *.o

person.pkg:
main.pkg: person.pkg
$(prog): main.pkg

person.pkg: student.go

test: $(prog)
	./$^

clean:
	rm -f $(prog) *.o
