{ fpc -ounion-free union-free.p && ./union-free }

program Union;
type
   Kind	= (chr,int);
   T	= record
	     case Kind of
	       chr: (c:char);
	       int: (i:integer);
	  end;
var
   v: T;
begin
   v.c:='a';
   { ... }
   write('v.c='); writeln(v.c);
   write('v.i='); writeln(v.i);
end.
