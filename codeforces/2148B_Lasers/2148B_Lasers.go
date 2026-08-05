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
	var n, m, x, y int64
	scan(&n, &m, &x, &y)
	arrH := make([]int64, n)
	arrV := make([]int64, m)
	ans := int64(0)
	for i := range n {
		scan(&arrH[i])
		if arrH[i] <= y {
			ans++
		}
	}
	for i := range m {
		scan(&arrV[i])
		if arrV[i] <= x {
			ans++
		}
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
