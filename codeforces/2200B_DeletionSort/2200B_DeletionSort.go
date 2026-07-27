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
	nonDesc := true
	for i := range n - 1 {
		if arr[i] > arr[i+1] {
			nonDesc = false
		}
	}
	if nonDesc {
		printf("%d\n", n)
	} else {
		printf("%d\n", 1)
	}
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
