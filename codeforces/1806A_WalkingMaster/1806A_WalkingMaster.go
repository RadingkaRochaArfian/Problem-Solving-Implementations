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
	var a, b, c, d int64
	scan(&a, &b, &c, &d)
	ans := int64(0)
	if d < b || (c-d) > (a-b) {
		ans = -1
	} else {
		up := (d - b)
		left := a + up - c
		ans = up + left
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
