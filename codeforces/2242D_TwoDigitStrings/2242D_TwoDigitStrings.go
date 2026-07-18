package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var s1, s2 string
	scan(&s1, &s2)
	size1 := len(s1)
	size2 := len(s2)
	prefix1 := make([]int, size1+1)
	prefix2 := make([]int, size2+1)
	for i := range size1 {
		prefix1[i+1] = (prefix1[i] + int(s1[i]-'0')) % 10
	}
	for i := range size2 {
		prefix2[i+1] = (prefix2[i] + int(s2[i]-'0')) % 10
	}
	if prefix1[size1] != prefix2[size2] {
		printf("%d\n", -1)
		return
	}
	dp := make([][]int, size1+1)
	for i := range dp {
		dp[i] = make([]int, size2+1)
	}
	for i := range dp {
		for j := range dp[i] {
			if i < size1 {
				dp[i+1][j] = int(math.Max(float64(dp[i+1][j]), float64(dp[i][j])))
			}
			if j < size2 {
				dp[i][j+1] = int(math.Max(float64(dp[i][j+1]), float64(dp[i][j])))
			}
			if i < size1 && j < size2 && prefix1[i] == prefix2[j] {
				dp[i+1][j+1] = int(math.Max(float64(dp[i+1][j+1]), float64(dp[i][j]+1)))
			}
		}
	}
	printf("%d\n", dp[size1][size2])
}
func main() {
	defer writer.Flush()
	var t int
	scan(&t)
	for range t {
		solve()
	}
}
