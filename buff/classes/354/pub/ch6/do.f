C gcc -o do do.f -lgfortran && ./do
      program main
      do 10 i=1,5
      print *,i
 10   continue
C would iterate once in old FORTRAN
      do 20 i=6,5
      print *,i
 20   continue
      end
