package main

import (
	"fmt"
	"strconv"
)

const MAX = 9003

func stillSame(s string) bool {
	chars := []rune(s)
	for i := range chars {
		c := chars[i]
		for j := i + 1; j < len(chars); j++ {
			if c == chars[j] {
				return true
			}
		}
	}
	return false
}
func solve(s string) {
	for i := range MAX {
		if stillSame(s) || (i == 0 && !stillSame(s)) {
			num, _ := strconv.Atoi(s)
			num++
			s = strconv.Itoa(num)
		} else {
			break
		}
	}
	fmt.Println(s)
}
func main() {
	var s string
	fmt.Scan(&s)
	solve(s)
}
