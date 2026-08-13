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
	ans := int64(0)
	arr := []int64{}
	for range n {
		var a, b int64
		scan(&a, &b)
		width := min(a, b)
		height := max(a, b)
		ans += width
		arr = append(arr, height)
	}
	ans *= 2
	arr = append(arr, 0)
	slices.Sort(arr)
	slices.Reverse(arr)
	ans += arr[0]
	for i := 0; i+1 < n+1; i++ {
		ans += (arr[i] - arr[i+1])
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
