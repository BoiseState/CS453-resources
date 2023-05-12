C gcc -Wall -g -o format format.f -lgfortran && ./format

      PROGRAM MAIN
      I=123
      D=3.14
      PRINT 10,I,D
 10   FORMAT (I7, ' FOO ', F7.4)
      END

