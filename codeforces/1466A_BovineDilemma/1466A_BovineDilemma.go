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
	set := make([]bool, 50)
	arr := make([]int, n)
	for i := range n {
		scan(&arr[i])
	}
	for i := range n {
		for j := i + 1; j < n; j++ {
			diff := arr[i] - arr[j]
			diff = (diff ^ (diff >> 31) - (diff >> 31))
			set[diff] = true
		}
	}
	ans := 0
	for i := range set {
		if set[i] {
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
