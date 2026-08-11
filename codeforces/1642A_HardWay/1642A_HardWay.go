package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var a, b, c, d, e, f int64
	scan(&a, &b, &c, &d, &e, &f)
	ans := float64(0)
	if b == d && f < b {
		ans = math.Abs(float64(a - c))
	} else if b == f && d < b {
		ans = math.Abs(float64(a - e))
	} else if d == f && b < d {
		ans = math.Abs(float64(c - e))
	}
	printf("%f\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
