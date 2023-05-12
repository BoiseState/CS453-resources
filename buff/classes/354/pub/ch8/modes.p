{ fpc -omodes modes.p && ./modes }

program Modes;

type intptr=^integer;
var
   x,y:integer;
   z:intptr;

procedure p(a:integer; var b:integer; c:intptr);
begin
   a:=11;
   b:=12;
   c^:=13;
end;

begin
   x:=1;
   y:=2;
   new(z);
   z^:=3;
   p(x,y,z);
   writeln('x=',x,' y=',y,' z=',z^);
end.
