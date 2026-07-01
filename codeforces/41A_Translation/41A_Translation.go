package main

import "fmt"

func solve(s, t string) {
	n := len(s)
	m := len(t)
	if n != m {
		fmt.Println("NO")
		return
	}
	j := 0
	for i := n - 1; i >= 0; i-- {
		if t[j] != s[i] {
			fmt.Println("NO")
			return
		}
		j++
	}
	fmt.Println("YES")
}
func main() {
	var s, t string
	fmt.Scan(&s, &t)
	solve(s, t)
}
