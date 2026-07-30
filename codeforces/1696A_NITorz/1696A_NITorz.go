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
	var n, z int64
	scan(&n, &z)
	arr := make([]int64, n)
	for i := range n {
		scan(&arr[i])
	}
	mx := int64(0)
	for i := range n {
		mx = max(mx, (arr[i] | z))
	}
	printf("%d\n", mx)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
