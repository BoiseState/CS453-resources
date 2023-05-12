{ fpc -owith with.p  && ./with }

program Range;
type
   T = record 
      a: record
	 b: record
	    c1: char;
	    c2: char;
	 end;	
      end;	
   end;
var
   v: T;
begin
   with v.a.b do begin
      c1:='a';
      c2:='b';
      writeln(c1);
      writeln(c2);
   end
end.
