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
	for i := range n - 1 {
		if 2*min(arr[i], arr[i+1]) > max(arr[i], arr[i+1]) {
			printf("YES\n")
			return
		}
	}
	printf("NO\n")
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
