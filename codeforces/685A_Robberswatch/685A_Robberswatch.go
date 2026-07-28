package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n, m int64
	scan(&n, &m)
	ln1, ln2 := 1, 1
	for i := int64(7); i < n; i *= 7 {
		ln1++
	}
	for i := int64(7); i < m; i *= 7 {
		ln2++
	}
	if ln1+ln2 > 7 {
		printf("0\n")
		return
	}
	ans := int64(0)
	for i := range n {
		for j := range m {
			hole := make([]int, 7)
			a, b := i, j
			for range ln1 {
				hole[a%7]++
				a /= 7
			}
			for range ln2 {
				hole[b%7]++
				b /= 7
			}
			mxVal := slices.Max(hole)
			if mxVal == 1 {
				ans++
			}
		}
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
