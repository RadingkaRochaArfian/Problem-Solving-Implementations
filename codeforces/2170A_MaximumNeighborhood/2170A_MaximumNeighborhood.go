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
	var n int64
	scan(&n)
	var ans int64
	switch n {
	case 1:
		ans = 1
	case 2:
		ans = 9
	case 3:
		ans = 29
	case 4:
		ans = 56
	default:
		mxRow := int64(n * (n - 1))
		ans = (mxRow) + (mxRow - 1) + (mxRow - 2) + (mxRow - (n + 1)) + (mxRow + (n - 1))
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
