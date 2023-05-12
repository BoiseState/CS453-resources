      program main
C     by default, "sum" is an intrinsic function
      external sum
      integer sum
      integer seq(6)
      data seq/5,6,1,8,3,7/
      print *,sum(seq,6)
      return
      end

      integer function sum(seq,n)
      integer seq(*)
      integer n
      sum=0
      do 10 i=1,n
         sum=sum+seq(i)
 10   continue
      return
      end

