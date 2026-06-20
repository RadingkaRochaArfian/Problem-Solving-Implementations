package main

import (
	"fmt"
)

func main() {
	var x int64
	fmt.Scan(&x)
	solve(x)
}
func solve(x int64) {
	m1 := x / 2
	m2 := x / 3
	m3 := x / 5
	m4 := x / 7
	m5 := x / (2 * 3)
	m6 := x / (2 * 5)
	m7 := x / (2 * 7)
	m8 := x / (3 * 5)
	m9 := x / (3 * 7)
	m10 := x / (5 * 7)
	m11 := x / (2 * 3 * 5)
	m12 := x / (2 * 3 * 7)
	m13 := x / (2 * 5 * 7)
	m14 := x / (3 * 5 * 7)
	m15 := x / (2 * 3 * 5 * 7)
	ans := x - m1 - m2 - m3 - m4 + m5 + m6 + m7 + m8 + m9 + m10 - m11 - m12 - m13 - m14 + m15
	fmt.Println(ans)
}
