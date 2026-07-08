package main

import "fmt"

func solve(n int64) {
	ans := (n + 1) / 2
	if n%2 == 1 {
		ans = -ans
	}
	fmt.Println(ans)
}
func main() {
	var n int64
	fmt.Scan(&n)
	solve(n)
}
