/* gccgo -g -o lambda lambda.go && ./lambda */

package main

import ("fmt")

type F func(a int) int

func main() {
    var f F=func(a int) int { return a+1 }
    fmt.Printf("%d\n",f(123))
}

