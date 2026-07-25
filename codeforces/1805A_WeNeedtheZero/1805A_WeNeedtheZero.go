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
	totalXor := 0
	for range n {
		var x int
		scan(&x)
		arr = append(arr, x)
		totalXor ^= x
	}
	if n%2 == 0 && totalXor != 0 {
		printf("-1\n")
		return
	}
	printf("%d\n", totalXor)
}
func main() {
	defer writer.Flush()
	var t int
	scan(&t)
	for range t {
		solve()
	}
}
