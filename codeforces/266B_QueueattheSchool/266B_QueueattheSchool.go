package main

import (
	"fmt"
)

func solve(n, t int) {
	var s string
	fmt.Scan(&s)
	arr := []byte(s)
	for range t {
		for j := 0; j < n-1; j++ {
			if arr[j] == 'B' && arr[j+1] == 'G' {
				arr[j] = 'G'
				arr[j+1] = 'B'
				j++
			}
		}
	}
	fmt.Printf("%s\n", arr)
}
func main() {
	var n, t int
	fmt.Scan(&n, &t)
	solve(n, t)
}
