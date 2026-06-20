package main

import (
	"C"
	"fmt"
	"strings"
)

func main() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)
	solve(n, s)
}
func solve(n int, s string) {
	arr_best := strings.Repeat("9", n)
	for i := range n {
		arr_shifted := s[i:] + s[:i]
		firstDigit := int(arr_shifted[0] - '0')
		add := (10 - firstDigit) % 10
		arrResult := make([]byte, n)
		for j := range n {
			digit := int(arr_shifted[j] - '0')
			newDigit := (digit + add) % 10
			arrResult[j] = byte(newDigit + '0')
		}
		resultStr := string(arrResult)
		if resultStr < arr_best {
			arr_best = resultStr
		}
	}
	fmt.Println(arr_best)
}
