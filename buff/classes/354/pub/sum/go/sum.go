// Go sum program

package main

import . "fmt"

func sum(seq []int) (s int) {
    for _,v:=range seq {
        s+=v
    }
	return
}

func main() {
    seq:=[]int{5,6,1,8,3,7}
	Printf("%d\n",sum(seq))
}

