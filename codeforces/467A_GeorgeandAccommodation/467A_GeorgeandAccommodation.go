package main

import (
	"fmt"
	"math"
)

func solve(n int) {
	count := 0
	for range n {
		var a, b int
		fmt.Scan(&a, &b)
		ans := math.Abs(float64(a - b))
		if ans >= 2 {
			count++
		}
	}
	fmt.Println(count)
}
func main() {
	var n int
	fmt.Scan(&n)
	solve(n)
}
