{ fpc -obadloop badloop.p && ./badloop }

program Sum;
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
   i:range;
   x:range;
begin
   sum:=0;
   x:=hi;
   for i:=lo to x do begin
      {i:=x;}
      {x:=lo;}
      sum:=sum+seq[i]
   end
end;

begin
   writeln(sum(seq))
end.
