package main

import "fmt"

func solve(a, m int) {
	for range 20 {
		if a%m == 0 {
			fmt.Println("Yes")
			return
		}
		a += a % m
	}
	fmt.Println("No")
}
func main() {
	var a, m int
	fmt.Scan(&a, &m)
	solve(a, m)
}
