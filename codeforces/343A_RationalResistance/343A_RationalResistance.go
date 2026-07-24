package main

import (
	"bufio"
	"fmt"
	"os"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func findItGcd(a, b int64) int64 {
	it := int64(0)
	for b != 0 {
		it += a / b
		a, b = b, (a % b)
	}
	return it
}
func solve(a, b int64) {
	if a < b {
		a, b = b, a
	}
	it := findItGcd(a, b)
	printf("%d\n", it)
}
func main() {
	defer writer.Flush()
	var a, b int64
	scan(&a, &b)
	solve(a, b)
}
