package main

import "fmt"

func solve(n int) {
	s := "EASY"
	for range n {
		var x int
		fmt.Scan(&x)
		if x == 1 {
			s = "HARD"
		}
	}
	fmt.Println(s)
}
func main() {
	var n int
	fmt.Scan(&n)
	solve(n)
}
