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
	var n int
	scan(&n)
	arr := make([]int, n)
	for i := range n {
		scan(&arr[i])
	}
	mx := slices.Max(arr)
	curr := arr[n-1]
	ans := 0
	for i := n - 2; i >= 0; i-- {
		if arr[i] > curr {
			curr = arr[i]
			ans++
		}
		if arr[i] == mx {
			break
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
