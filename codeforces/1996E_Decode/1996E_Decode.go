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

const MOD = 1e9 + 7

func solve() {
	var s string
	scan(&s)
	n := len(s)
	arr := []int{}
	for i := range s {
		x := int(s[i] - '0')
		if x == 0 {
			x = -1
		}
		arr = append(arr, x)
	}
	psum := []int{}
	psum = append(psum, 0)
	for i := range arr {
		sum := psum[i] + arr[i]
		psum = append(psum, sum)
	}
	cnt := make(map[int]int)
	ans := 0
	for i := range psum {
		ans = (ans + (n-i+1)*cnt[psum[i]]) % MOD
		cnt[psum[i]] = (cnt[psum[i]] + (i + 1)) % MOD
	}
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int
	scan(&t)
	for range t {
		solve()
	}
}
