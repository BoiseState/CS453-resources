{ fpc -oclosure1 closure1.p && ./closure1 }

{$modeswitch nestedprocvars}

program Closure;

procedure g(procedure ff);
var i:integer;
begin
   i:=2; { late/shallow }
   ff;
end;

procedure closure;
var i:integer;
   procedure f;
   begin
      writeln(i);
   end;
begin
   i:=1;  { early/deep }
   g(@f); { the @ is non-standard }
end;

begin
   closure;
end.
