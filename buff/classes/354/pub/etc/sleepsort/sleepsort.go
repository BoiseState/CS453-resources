// go build sleepsort.go && ./sleepsort

package main

import . "fmt"
import . "time"

func sleep(c chan int, i int) {
	Sleep(Duration(i)*Second)
	c<-i
}

func main() {
    seq:=[]int{5,6,1,8,3,7}
    c:=make(chan int)
	for _,i:=range seq {
		go sleep(c,i)
	}
	for i:=range seq {
		seq[i]=<-c
	}
    Printf("%d\n",seq)
}
