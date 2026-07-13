package main

import (
	"bufio"
	"fmt"
	"os"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func sumDigits(num int64) int64 {
	var sum int64 = 0
	for num > 0 {
		sum += num % 10
		num /= 10
	}
	return sum
}
func findLowest(n, s int64) (int64, bool) {
	var ans int64 = 0
	if n-sumDigits(n) < s {
		return ans, false
	}
	var low int64 = 1
	high := n
	for low <= high {
		mid := low + (high-low)/2
		if mid-sumDigits(mid) >= s {
			ans = mid
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return ans, true
}
func solve(n, s int64) {
	lowest, found := findLowest(n, s)
	if found {
		printf("%d\n", n-lowest+1)
	} else {
		printf("%d\n", lowest)
	}
}
func main() {
	defer writer.Flush()
	var n, s int64
	scan(&n, &s)
	solve(n, s)
}
