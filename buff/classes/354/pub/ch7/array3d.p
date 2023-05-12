{ fpc -oarray3d array3d.p && ./array3d }

program Array3D;
const
   l1 = 1; u1=3; { lower/upper bounds }
   l2 = 4; u2=6; { lower/upper bounds }
   l3 = 7; u3=9; { lower/upper bounds }
type
   Base	= integer;
var
   a: array[l1..u1] of array[l2..u2] of array[l3..u3] of Base;
   b: array[l1..u1, l2..u2, l3..u3] of Base;
   d1,d2,d3 : integer; { dimension sizes (in previous-dimension elements) }
   s1,s2,s3 : integer; { element sizes (in base-type elements) } 
   i,j,k: integer;     { indices }				 
   c: integer;	       { dope-vector bias}
begin
   d1:=u1-l1+1;
   d2:=u2-l2+1;
   d3:=u3-l3+1;

   s3:=SizeOf(Base);   { 2 bytes }
   s2:=d3*s3;
   s1:=d2*s2;

   i:=2; j:=5; k:=8;
   writeln(PtrUInt(@a[i,j,k])-PtrUInt(@a));
   writeln(PtrUInt(@b[i][j][k])-PtrUInt(@b));

   { use some compile-time constants }
   writeln((i-l1)*s1
	  +(j-l2)*s2
	  +(k-l3)*s3);
   
   { use another compile-time constant }
   c:=l1*s1+l2*s2+l3*s3;
   writeln(i*s1+j*s2+k*s3-c);
end.
