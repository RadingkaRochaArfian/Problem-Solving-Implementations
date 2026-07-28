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
	var x, y, z int64
	scan(&x, &y, &z)
	a := (x & y)
	b := (x & z)
	c := (y & z)
	if a == b && b == c {
		printf("YES\n")
	} else {
		printf("No\n")
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
