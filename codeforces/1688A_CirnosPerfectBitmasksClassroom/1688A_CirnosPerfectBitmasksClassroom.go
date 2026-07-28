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
	var x int64
	scan(&x)
	mnBit := x & (-x)
	for mnBit^x == 0 || mnBit&x == 0 {
		mnBit++
	}
	printf("%d\n", mnBit)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
