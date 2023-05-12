// Pascal sum program

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
begin
   sum:=0;
   for i:=lo to hi do
      sum:=sum+seq[i]
end;

begin
   writeln(sum(seq))
end.
