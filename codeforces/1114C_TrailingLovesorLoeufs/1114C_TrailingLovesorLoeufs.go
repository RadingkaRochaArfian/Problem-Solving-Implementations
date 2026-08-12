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
	var n, b int64
	scan(&n, &b)
	cntB := int64(0)
	for b%2 == 0 {
		b /= 2
		cntB++
	}
	ans := int64(math.MaxInt64)
	if cntB > 0 {
		ans = min(ans, countFact(n, 2)/cntB)
	}
	for i := int64(3); i*i <= b; i += 2 {
		cntB = 0
		for b%i == 0 {
			b /= i
			cntB++
		}
		if cntB == 0 {
			continue
		}
		ans = min(ans, countFact(n, i)/cntB)
	}
	if b > 1 {
		ans = min(ans, countFact(n, b))
	}
	printf("%d\n", ans)
}
func countFact(n, i int64) int64 {
	cnt := int64(0)
	for n >= i {
		n /= i
		cnt += n
	}
	return cnt
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
