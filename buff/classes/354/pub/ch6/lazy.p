{ fpc -gl -olazy lazy.p && ./lazy }

{$rangechecks on}
{$B+}

program Lazy;
const
   lo=1;
   hi=6;
type
   range=lo..hi;
   arr=array[range] of integer;
var
   seq:arr=(5,6,1,8,3,7);

function sum(var seq:arr): integer;
var
   i:integer;
begin
   sum:=0;
   i:=lo;
   while (i<=hi) and (seq[i]<>0) do begin
      sum:=sum+seq[i];
      i:=i+1
   end
end;

begin
   writeln(sum(seq))
end.
