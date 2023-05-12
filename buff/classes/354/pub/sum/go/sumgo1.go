package main

import . "fmt"

func main() {
    seq:=[]int{5,6,1,8,3,7}
	f:=func (c chan int) {
		s:=0
		for _,v:=range seq {
			s+=v
		}
		c<-s
	}
    c:=make(chan int)
    go f(c)
	Printf("%d\n",<-c)
}

