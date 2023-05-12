C     gcc -o aliasing aliasing.f -lgfortran && ./aliasing

      program main
          integer x,y
          equivalence (x,y)
          x=123
          print *,y
          call suba
          call subb
      end

      subroutine suba
          common a,b,c
          a=1
          b=2
          c=3
      end
      
      subroutine subb
          common d,e,f
          print *,d+e+f
      end    
