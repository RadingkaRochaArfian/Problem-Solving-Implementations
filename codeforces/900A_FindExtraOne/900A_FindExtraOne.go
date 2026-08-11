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
	right := 0
	left := 0
	for range n {
		var x, y int64
		scan(&x, &y)
		if x > 0 {
			right++
		} else {
			left++
		}
	}
	if right < 2 || left < 2 {
		printf("Yes\n")
	} else {
		printf("No\n")
	}
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
