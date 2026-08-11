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
	var w, d, h, a, b, f, g int
	scan(&w, &d, &h, &a, &b, &f, &g)
	diff := int(math.Abs(float64(a - f)))
	ans := diff + h + b + g
	ans = min(ans, (d-b)+diff+h+(d-g))
	diff = int(math.Abs(float64(b - g)))
	ans = min(ans, a+diff+h+f)
	ans = min(ans, (w-a)+diff+h+(w-f))
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
