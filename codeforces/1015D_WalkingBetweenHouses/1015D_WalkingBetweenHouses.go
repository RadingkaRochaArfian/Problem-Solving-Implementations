package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve(n, k, s int64) {
	if k > s || k*(n-1) < s {
		printf("NO\n")
		return
	}
	printf("YES\n")
	pos := int64(1)
	for range k {
		dist := int64(math.Min(float64(n-1), float64(s-k+1)))
		if pos-dist > 0 {
			pos -= dist
		} else {
			pos += dist
		}
		k--
		s -= dist
		printf("%d ", pos)
	}
	printf("\n")
}
func main() {
	defer writer.Flush()
	var n, k, s int64
	scan(&n, &k, &s)
	solve(n, k, s)
}
