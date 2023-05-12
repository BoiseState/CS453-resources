package main

import . "fmt"

var seq=[]int{5,6,1,8,3,7}

func sum(c chan int) {
	s:=0
	for _,v:=range seq {
		s+=v
	}
	c<-s
}

func main() {
    c:=make(chan int)
    go sum(c)
	Printf("%d\n",<-c)
}

