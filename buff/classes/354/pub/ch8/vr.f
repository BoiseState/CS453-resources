C gcc -o vr vr.f -lgfortran && ./vr
C due to MacLennan[1987], Exercise 2.13
      program main
      integer i
      i=2
      call foo(i,i,j)
      print *,i,j
      end

      subroutine foo(x,y,z)
      integer x,y,z
      x=1
      z=x+y
      end
