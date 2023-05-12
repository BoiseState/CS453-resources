{ fpc -ooverload overload.p && ./overload }

program Overload;
function fact(x:integer): integer;
begin
   if x=0 then
      fact:=1
   else
      fact:=x*fact(x-1)
end;
begin
   writeln(fact(3));
   writeln(3.14)
end.
