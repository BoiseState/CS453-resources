{ fpc -oclosure2 closure2.p && ./closure2 }

{$modeswitch nestedprocvars}

program Closure;
var fff : procedure is nested;

procedure main;
var i:integer;

   procedure g(procedure ff);
   begin
      fff:=ff;
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
      fff;
   end;

begin
   closure;
   i:=2;  { late/shallow }
   fff;
end;

begin
   main;
   fff;
end.

