package main

import "fmt"

func solve(n int) {
	currCap := 0
	maxCap := 0
	for range n {
		var a, b int
		fmt.Scan(&a, &b)
		currCap -= a
		currCap += b
		maxCap = max(maxCap, currCap)
	}
	fmt.Println(maxCap)
}
func main() {
	var n int
	fmt.Scan(&n)
	solve(n)
}
