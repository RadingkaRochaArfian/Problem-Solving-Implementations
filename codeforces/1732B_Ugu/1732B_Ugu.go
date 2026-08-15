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
	var s []byte
	scan(&n, &s)
	diff := 0
	for i := range n - 1 {
		if s[i] != s[i+1] {
			diff++
		}
	}
	ans := 0
	if s[0] == '0' {
		ans = max(ans, diff-1)
	} else {
		ans = max(ans, diff)
	}
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
