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
	var a, b, x, y int
	scan(&a, &b, &x, &y)
	if a > b {
		if a^1 == b {
			printf("%d\n", y)
		} else {
			printf("-1\n")
		}
		return
	}
	d := (b - a)
	ceil := (d + 1) / 2
	floor := d / 2
	ans := 0
	if a%2 == 0 {
		ans = (ceil * min(x, y)) + (floor * x)
	} else {
		ans = (floor * min(x, y)) + (ceil * x)
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
