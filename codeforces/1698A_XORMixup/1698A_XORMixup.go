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
	arr := []int{}
	for range n {
		var x int
		scan(&x)
		arr = append(arr, x)
	}
	ans := -1
	for i := range n {
		xorSum := 0
		for j := range n {
			if j == i {
				continue
			}
			xorSum ^= arr[j]
		}
		if xorSum == arr[i] {
			ans = arr[i]
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
