package main

import "fmt"

func solve(s string) {
	cnt := int64(0)
	for i := range s {
		if s[i] == '4' || s[i] == '7' {
			cnt++
		}
	}
	if cnt == 4 || cnt == 7 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
func main() {
	var s string
	fmt.Scan(&s)
	solve(s)
}
