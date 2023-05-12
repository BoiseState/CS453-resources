C gcc -o computedgoto computedgoto.f -lgfortran && ./computedgoto
      program main
      integer inx
      inx=2
      goto (10,20,30,40) inx
      print *,"none"
      goto 100
 10   print *,"ten"
      goto 100
 20   print *,"twenty"
      goto 100
 30   print *,"thirty"
      goto 100
 40   print *,"forty"
      goto 100
 100  end
