{ fpc -ounion-disc union-disc.p && ./union-disc }

program Union;
type
   Kind	= (chr,int);
   T	= record
	     case knd:Kind of
	       chr: (c:char);
	       int: (i:integer);
	  end;
var
   v: T;
begin
   v.knd:=chr;
   v.c:='a';
   { ... }
   case v.knd of 
     chr: begin write('v.c='); writeln(v.c) end;
     int: begin write('v.i='); writeln(v.i) end
   end
end.
