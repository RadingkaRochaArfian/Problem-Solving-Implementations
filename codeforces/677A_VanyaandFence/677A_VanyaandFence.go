package main

import "fmt"

func solve(n, h int) {
	count := 0
	for range n {
		var x int
		fmt.Scan(&x)
		if x > h {
			count += 2
		} else {
			count++
		}
	}
	fmt.Println(count)
}
func main() {
	var n, h int
	fmt.Scan(&n, &h)
	solve(n, h)
}
