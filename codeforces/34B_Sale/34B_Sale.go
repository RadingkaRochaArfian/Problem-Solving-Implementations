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
	var n, m int
	scan(&n, &m)
	arr := []int{}
	for range n {
		var x int
		scan(&x)
		arr = append(arr, x)
	}
	slices.Sort(arr)
	ans := 0
	for i := range n {
		temp := ans - arr[i]
		if temp > ans && m != 0 {
			ans = temp
			m--
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
