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
	var s string
	scan(&n, &s)
	x, y := 0, 0
	for i := range s {
		switch s[i] {
		case 'U':
			y++
		case 'R':
			x++
		case 'L':
			x--
		case 'D':
			y--
		}
		if x == y && x == 1 {
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
