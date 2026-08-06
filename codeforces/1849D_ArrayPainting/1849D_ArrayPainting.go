package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n int
	scan(&n)
	arr := make([]int, n)
	for i := range n {
		scan(&arr[i])
	}
	ans := 0
	l := 0
	for l < n {
		r := l + 1
		hasTwo := false
		hasMiddleZero := false
		for r < n {
			if r-1 > l && arr[r-1] == 0 {
				hasMiddleZero = true
			}
			if arr[r] == 2 {
				hasTwo = true
			}
			good := (!hasMiddleZero) && (hasTwo || arr[l] != 0 || arr[r] != 0)
			if !good {
				break
			}
			r++
		}
		l = r
		ans++
	}
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
