package main

import "fmt"

func solve(n int, s string) {
	cntA := 0
	cntD := 0
	for i := range n {
		if s[i] == 'A' {
			cntA++
		} else {
			cntD++
		}
	}
	if cntA > cntD {
		fmt.Println("Anton")
	} else if cntA == cntD {
		fmt.Println("Friendship")
	} else {
		fmt.Println("Danik")
	}
}
func main() {
	var n int
	var s string
	fmt.Scan(&n, &s)
	solve(n, s)
}
